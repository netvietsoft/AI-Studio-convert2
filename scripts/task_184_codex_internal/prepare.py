"""Pin the 141 original PT_LOAD/FDE bodies and copy the prior analyzed project."""

from __future__ import annotations

import hashlib
import json
import shutil
import sys
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile

from common import (AGENT, FENCE, LEASE, ORIGINAL_PROJECT, OWN_PROJECT, REPORT,
                    ROOT, SCRIPTS, SOURCE, SOURCE_SHA, STANDARD, STANDARD_SHA,
                    TARGETS, TARGETS_SHA, TASK, TASK_SHA, atomic_bytes, guard,
                    now, sha, write_json)


def original_project_files() -> dict[str, str]:
    return {str(p.relative_to(ORIGINAL_PROJECT)).replace("\\", "/"): sha(p)
            for p in sorted(ORIGINAL_PROJECT.rglob("*")) if p.is_file()}


def main() -> None:
    guard()
    if REPORT.exists() or OWN_PROJECT.exists():
        raise RuntimeError("TASK_184 already prepared; no duplicate project copy")
    manifest = json.loads(TARGETS.read_text(encoding="utf-8"))
    targets = manifest["targets"]
    if len(targets) != 141 or manifest["selected_count"] != 141:
        raise RuntimeError("141-target manifest count changed")
    source = SOURCE.read_bytes()
    if hashlib.sha256(source).hexdigest() != SOURCE_SHA:
        raise RuntimeError("original SO changed")

    # The existing, previously audited decoder handles PT_GNU_EH_FRAME/FDE+CIE.
    # Record its exact script hashes in this task's source index.
    prior_scripts = ROOT / "scripts/task_174_codex_exports"
    sys.path.insert(0, str(prior_scripts))
    from unwind import parse_unwind  # type: ignore

    unwind = parse_unwind(source)
    fde_by_va = {rec["function_va"]: rec for rec in unwind["records"]}
    if unwind["fde_table_count"] != 1027 or len(fde_by_va) != 1027:
        raise RuntimeError("original SO FDE table changed/ambiguous")
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        if elf["e_machine"] != "EM_AARCH64":
            raise RuntimeError("not AArch64")
        dynsym = elf.get_section_by_name(".dynsym")
        if dynsym is None:
            raise RuntimeError(".dynsym absent")
        exports = {int(sym["st_value"]) for sym in dynsym.iter_symbols()
                   if sym["st_info"]["type"] == "STT_FUNC"
                   and sym["st_shndx"] != "SHN_UNDEF"
                   and int(sym["st_size"]) > 0 and int(sym["st_value"]) != 0}
        if len(exports) != 886:
            raise RuntimeError("export VA census changed")
        exec_loads = [seg for seg in elf.iter_segments()
                      if seg["p_type"] == "PT_LOAD" and (int(seg["p_flags"]) & 1)]

    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    decoder.skipdata = True
    rows = []
    assembly = []
    aggregate = bytearray()
    seen = set()
    for index, target in enumerate(targets, 1):
        va = int(target["elf_va"], 16)
        size = int(target["size_bytes"])
        offset = int(target["file_offset"], 16)
        expected = target["body_sha256"]
        if va in seen or va in exports or size < 4 or size % 4 or offset < 0:
            raise RuntimeError(f"invalid/duplicate/export target {index}: {va:#x}")
        seen.add(va)
        fde = fde_by_va.get(va)
        if fde is None or fde["function_size"] != size or fde["body_file_offset"] != offset:
            raise RuntimeError(f"FDE range mismatch at target {index}")
        if not fde["body_complete_in_input"] or fde["retained_body_sha256"] != expected:
            raise RuntimeError(f"FDE byte identity mismatch at target {index}")
        load = next((seg for seg in exec_loads
                     if int(seg["p_vaddr"]) <= va and va + size <= int(seg["p_vaddr"]) + int(seg["p_filesz"])
                     and offset == int(seg["p_offset"]) + va - int(seg["p_vaddr"])), None)
        if load is None:
            raise RuntimeError(f"original executable PT_LOAD mapping absent at {va:#x}")
        body = source[offset:offset + size]
        if len(body) != size or hashlib.sha256(body).hexdigest() != expected:
            raise RuntimeError(f"original body SHA mismatch at {va:#x}")
        instructions = list(decoder.disasm(body, va))
        if sum(ins.size for ins in instructions) != size or len(instructions) != target["instruction_slots"]:
            raise RuntimeError(f"source instruction coverage mismatch at {va:#x}")
        aggregate.extend(body)
        row = {"index": index, "elf_va": target["elf_va"], "size_bytes": size,
               "file_offset": target["file_offset"], "body_sha256": expected,
               "fde_index": fde["index"], "fde_offset": fde["fde_offset"],
               "fde_va": f"0x{fde['fde_va']:x}", "cie_offset": fde["cie_offset"],
               "pt_load_file_offset": int(load["p_offset"]),
               "instruction_count": len(instructions), "blob_offset": len(aggregate) - size,
               "capstone_skipdata": sum(ins.mnemonic == ".byte" for ins in instructions)}
        rows.append(row)
        assembly.append(json.dumps({"index": index, "elf_va": target["elf_va"],
                                    "body_sha256": expected,
                                    "instructions": [{"va": f"0x{ins.address:x}",
                                                      "word_le": body[ins.address - va:ins.address - va + 4].hex(),
                                                      "mnemonic": ins.mnemonic, "operands": ins.op_str}
                                                     for ins in instructions]}, separators=(",", ":")))
    for left, right in zip(rows, rows[1:]):
        if int(left["elf_va"], 16) + left["size_bytes"] > int(right["elf_va"], 16):
            raise RuntimeError("FDE candidate overlap")
    if len(aggregate) != 30644 or sum(r["instruction_count"] for r in rows) != 7661:
        raise RuntimeError("target aggregate size/slots changed")

    report_source = REPORT / "source"
    atomic_bytes(report_source / "source_bodies.bin", bytes(aggregate))
    atomic_bytes(report_source / "assembly.ndjson", ("\n".join(assembly) + "\n").encode("utf-8"))
    write_json(report_source / "source_index.json", {
        "schema": "task184-source-candidates-v1", "generated_at": now(),
        "classification": manifest["classification"], "candidate_count": len(rows),
        "source_path": str(SOURCE), "source_sha256": SOURCE_SHA, "source_file_bytes": len(source),
        "target_manifest_sha256": TARGETS_SHA, "fde_table_count": unwind["fde_table_count"],
        "defined_nonzero_export_vas": len(exports), "original_pt_load_bodies_verified": len(rows),
        "aggregate_body_bytes": len(aggregate), "aggregate_body_sha256": hashlib.sha256(aggregate).hexdigest(),
        "assembly_sha256": sha(report_source / "assembly.ndjson"),
        "unwind_parser_script_sha256": sha(prior_scripts / "unwind.py"),
        "elf_parser_script_sha256": sha(prior_scripts / "forensic.py"),
        "rows": rows,
    })
    for chunk in range(3):
        subset = rows[chunk * 47:(chunk + 1) * 47]
        if len(subset) != 47:
            raise RuntimeError("unexpected chunk size")
        content = "".join(f"{r['index']}\t{r['elf_va']}\t{r['size_bytes']}\t{r['body_sha256']}\t{r['file_offset']}\n"
                          for r in subset)
        atomic_bytes(REPORT / f"ghidra/chunk_{chunk + 1:02d}/targets.tsv", content.encode("utf-8"))

    before = original_project_files()
    if len(before) < 5 or not (ORIGINAL_PROJECT / "Task158.gpr").is_file():
        raise RuntimeError("original analyzed Ghidra project incomplete")
    guard()
    OWN_PROJECT.parent.mkdir(parents=True, exist_ok=True)
    shutil.copytree(ORIGINAL_PROJECT, OWN_PROJECT)
    (OWN_PROJECT / "Task158.gpr").rename(OWN_PROJECT / "Task184.gpr")
    (OWN_PROJECT / "Task158.rep").rename(OWN_PROJECT / "Task184.rep")
    after = original_project_files()
    copied = {str(p.relative_to(OWN_PROJECT)).replace("\\", "/"): sha(p)
              for p in sorted(OWN_PROJECT.rglob("*")) if p.is_file()}
    normalized = {(name.replace("Task158", "Task184", 1)): digest for name, digest in before.items()}
    if before != after or normalized != copied:
        raise RuntimeError("project copy byte identity mismatch or original changed")
    write_json(REPORT / "project_copy_receipt.json", {
        "source_project": str(ORIGINAL_PROJECT), "owned_project": str(OWN_PROJECT),
        "program_name": "libVERenderer.so", "fresh_imports": 0,
        "original_unchanged": before == after, "copy_file_count": len(copied),
        "copied_byte_hashes": copied,
    })
    atomic_bytes(REPORT / "00_AUDIT_INDEX.md", (
        "# TASK_184 R1 audit index\n\n"
        f"Canonical fully read: `{STANDARD}` SHA-256 `{STANDARD_SHA}`.\n\n"
        f"Exact task `{TASK}` SHA-256 `{TASK_SHA}`; targets `{TARGETS}` SHA-256 `{TARGETS_SHA}`.\n\n"
        f"Actor `{AGENT}`, lease `{LEASE}`, fence `{FENCE}`. Original SO `{SOURCE}` SHA-256 `{SOURCE_SHA}`.\n\n"
        "This is static, source-byte-backed research on 141 unwind FDE candidate starts absent from "
        "defined nonzero .dynsym STT_FUNC export starts. An FDE is not proof of a complete function "
        "boundary or behavior. Original SO and analyzed TASK_158 project remain read-only. "
        "Source/PT_LOAD/FDE/body/assembly evidence is under `source/`; per-candidate Ghidra "
        "evidence and raw commands/logs are under `ghidra/`. No product or device PASS claim.\n"
    ).encode("utf-8"))
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_184", "revision": 1,
              "status": "SOURCE_AND_PROJECT_VERIFIED", "generated_at": now(),
              "lease_id": LEASE, "fencing_token": FENCE, "candidate_count": 141,
              "original_bodies_rehashed": 141, "original_fdes_confirmed": 141,
              "project_copy_verified": True, "ghidra_processes_started": 0})
    print(json.dumps({"candidate_count": len(rows), "aggregate_bytes": len(aggregate),
                      "project_files_copied": len(copied), "fresh_imports": 0}))


if __name__ == "__main__":
    main()
