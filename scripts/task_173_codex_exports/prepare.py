"""Verify two original FFmpeg exports and copy the accepted analyzed project."""

from __future__ import annotations

import hashlib
import json
import shutil
import sys
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile

from common import (AGENT_ID, FENCE, LEASE_ID, REPORT, ROOT, SCRATCH,
                    SOURCE_DIR, STANDARD, STANDARD_SHA, TASK_SHA,
                    atomic_bytes, check_lease, now, sha256, write_json)

SOURCE_SHA = "d8df8c5cb7a6b5a7eb771782d74a38e0b8d3cfacd1fbef1ae67a96171e3325c9"
PRIOR_COMPLETE_SHA = "03c9e94b2363ca7108d9c78ea5f1d602a6e1c7dbe5ba2aa335443cf651772e20"
TARGETS = (
    (2283, 0x658fe8, 736, "x264_8_deblock_h_luma_intra_neon",
     "94017dc1deb91f10d8a4fd18f131f5d7741d0512c73c533de6d9845fbe095cee", 9),
    (2330, 0x65aea8, 232, "x264_8_frame_init_lowres_core_neon",
     "0b7e289d57ad0368923c5a802869b755b47eb70e43ff290fcd1096388ca46439", 10),
)


def original_body(elf: ELFFile, source: Path, va: int, size: int) -> tuple[bytes, int]:
    for segment in elf.iter_segments():
        if segment["p_type"] != "PT_LOAD":
            continue
        start = int(segment["p_vaddr"])
        length = int(segment["p_filesz"])
        if start <= va and va + size <= start + length:
            offset = int(segment["p_offset"]) + va - start
            with source.open("rb") as stream:
                stream.seek(offset)
                body = stream.read(size)
            if len(body) != size:
                raise RuntimeError("short mapped source body")
            return body, offset
    raise RuntimeError(f"PT_LOAD mapping missing for 0x{va:x}+{size}")


def main() -> None:
    check_lease()
    if REPORT.exists() or (SCRATCH / "ghidra_project").exists():
        raise RuntimeError("TASK_173 output or project copy already exists")
    source = SOURCE_DIR / "libffmpeg.so"
    prior = ROOT / "RULES/REPORT/TASK_170_REPORT_R1"
    if sha256(source) != SOURCE_SHA or sha256(prior / "COMPLETE.json") != PRIOR_COMPLETE_SHA:
        raise RuntimeError("source/prior accepted report identity changed")
    previous_index = json.loads((prior / "libffmpeg.so/target_index.json").read_text(encoding="utf-8"))
    if previous_index["unique_export_vas"] != 2461 or previous_index["source_sha256"] != SOURCE_SHA:
        raise RuntimeError("prior source census changed")
    source_rows = []
    with source.open("rb") as stream:
        elf = ELFFile(stream)
        if elf["e_machine"] != "EM_AARCH64":
            raise RuntimeError("source architecture changed")
        symbols = elf.get_section_by_name(".dynsym")
        by_va = {int(s["st_value"]): s for s in symbols.iter_symbols()
                 if s["st_info"]["type"] == "STT_FUNC" and s["st_shndx"] != "SHN_UNDEF"
                 and int(s["st_size"]) > 0 and int(s["st_value"]) > 0}
        if len(by_va) != 2461:
            raise RuntimeError("original export VA census changed")
        decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
        for index, va, size, symbol, expected_hash, chunk in TARGETS:
            original = by_va.get(va)
            indexed = previous_index["targets"][index - 1]
            if original is None or original.name != symbol or int(original["st_size"]) != size:
                raise RuntimeError(f"source export identity changed: 0x{va:x}")
            if (indexed["elf_va"] != f"0x{va:x}" or indexed["symbol"] != symbol or
                indexed["size_bytes"] != size or indexed["source_body_sha256"] != expected_hash):
                raise RuntimeError(f"prior target index changed: 0x{va:x}")
            body, offset = original_body(elf, source, va, size)
            if hashlib.sha256(body).hexdigest() != expected_hash or indexed["file_offset"] != f"0x{offset:x}":
                raise RuntimeError(f"original PT_LOAD/body hash mismatch: 0x{va:x}")
            old_raw_path = prior / f"libffmpeg.so/chunk_{chunk:02d}/ghidra_raw.json"
            raw = json.loads(old_raw_path.read_text(encoding="utf-8"))
            old_row = next((row for row in raw["targets"] if row["index"] == index), None)
            if (old_row is None or old_row["elf_va"] != f"0x{va:x}" or
                old_row["ghidra_memory_sha256"] != expected_hash or
                old_row["source_bytes_match"] is not True or old_row["decompile_success"] is not False or
                "Unable to find unique hash for varnode" not in old_row["error"]):
                raise RuntimeError(f"prior raw Ghidra failure changed: 0x{va:x}")
            decoded = list(decoder.disasm(body, va))
            if len(decoded) * 4 != size or any(ins.address != va + j * 4 for j, ins in enumerate(decoded)):
                raise RuntimeError(f"original ARM64 body not fully decoded: 0x{va:x}")
            assembly = [f"0x{ins.address:x}: {ins.mnemonic} {ins.op_str}".rstrip() for ins in decoded]
            row = {"index": index, "elf_va": f"0x{va:x}", "size_bytes": size,
                   "symbol": symbol, "source_body_sha256": expected_hash,
                   "file_offset": f"0x{offset:x}", "capstone_instruction_count": len(decoded),
                   "prior_raw_json_sha256": sha256(old_raw_path),
                   "prior_failure_error": old_row["error"],
                   "prior_ghidra_instruction_count": old_row["instruction_count_observed"],
                   "assembly": assembly}
            source_rows.append(row)
            write_json(REPORT / f"prior_failure_{index}.json", old_row)
            atomic_bytes(REPORT / f"source_assembly_{index}.txt",
                         ("\n".join(assembly) + "\n").encode("utf-8"))
            atomic_bytes(REPORT / f"target_{index}.tsv",
                         (f"{index}\t0x{va:x}\t{size}\t{expected_hash}\t{symbol}\n").encode("utf-8"))
    old_project = ROOT / "RESEARCH_WORK/TASK_170_R1/libffmpeg.so/ghidra_project"
    new_project = SCRATCH / "ghidra_project"
    originals = sorted(item for item in old_project.rglob("*") if item.is_file())
    if not originals or not (old_project / "Task170.gpr").is_file():
        raise RuntimeError("accepted analyzed Ghidra project missing")
    project_records = []
    for original in originals:
        check_lease()
        relative = original.relative_to(old_project)
        destination = new_project / relative
        destination.parent.mkdir(parents=True, exist_ok=True)
        before = sha256(original)
        shutil.copy2(original, destination)
        after = sha256(destination)
        if before != after or original.stat().st_size != destination.stat().st_size:
            raise RuntimeError("analyzed project copy differs: " + str(relative))
        project_records.append({"relative_path": relative.as_posix(), "size_bytes": destination.stat().st_size,
                                "source_sha256": before, "copy_sha256": after})
    write_json(REPORT / "project_copy_manifest.json", {
        "source_project": str(old_project), "copy_project": str(new_project),
        "file_count": len(project_records), "files": project_records,
        "copy_verified_at": now(), "prior_complete_sha256": PRIOR_COMPLETE_SHA})
    write_json(REPORT / "source_targets.json", {
        "task_id": "TASK_173", "revision": 1, "generated_at": now(),
        "actor": AGENT_ID, "lease_id": LEASE_ID, "fencing_token": FENCE,
        "standard_path": str(STANDARD), "standard_sha256": STANDARD_SHA, "task_sha256": TASK_SHA,
        "source_path": str(source), "source_sha256": SOURCE_SHA, "source_size": source.stat().st_size,
        "prior_complete_path": str(prior / "COMPLETE.json"), "prior_complete_sha256": PRIOR_COMPLETE_SHA,
        "targets": source_rows})
    write_json(REPORT / "PROGRESS.json", {
        "task_id": "TASK_173", "revision": 1, "status": "SOURCE_AND_PROJECT_COPY_VERIFIED",
        "generated_at": now(), "targets_verified": 2, "project_files_verified": len(project_records),
        "alternative_attempts_started": 0})
    audit = ("# TASK_173 R1 audit index\n\n"
             f"Canonical standard fully re-read: `{STANDARD}` SHA-256 `{STANDARD_SHA}`.\n\n"
             f"Task SHA-256 `{TASK_SHA}`; actor `{AGENT_ID}`; lease `{LEASE_ID}`; fence `{FENCE}`.\n\n"
             "Only two pinned FFmpeg NEON exports are in scope. Original PT_LOAD bytes, accepted prior "
             "Ghidra failures, and analyzed project copy hashes are in this report. Static research only.\n")
    atomic_bytes(REPORT / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    print(json.dumps({"targets_verified": 2, "project_files_verified": len(project_records),
                      "project_copy_bytes": sum(x["size_bytes"] for x in project_records)}))


if __name__ == "__main__":
    main()
