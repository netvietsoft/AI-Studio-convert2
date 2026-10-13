"""Independently verify and seal TASK_176's revalidated historical export evidence.

This is a static evidence verifier, not another Ghidra import or decompilation.
"""

from __future__ import annotations

import hashlib
import json
import math
from collections import Counter
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

from common import (AGENT_ID, HISTORICAL, HISTORICAL_PROJECTS, LEASE_ID,
                    LIBRARIES, REPORT, ROOT, SCRATCH, SCRIPTS, SOURCE_DIR,
                    STANDARD, STANDARD_SHA, TASK_SHA, atomic_bytes,
                    check_lease, now, sha256, write_json)
from prepare import HISTORICAL_COMPLETE_SHA, HISTORICAL_FILES, mapped_bytes

ALIAS_PAIRS = {("b.cs", "b.hs"), ("b.cc", "b.lo"), ("orr", "mov"),
               ("dup", "mov"), ("bfm", "bfi"), ("negs", "cmp")}


def load(path: Path) -> dict:
    return json.loads(path.read_text(encoding="utf-8"))


def sample_indices(total: int) -> set[int]:
    # A deterministic, evenly spread 12% ordinary-provenance sample.
    count = math.ceil(total * 0.12)
    return {1 + round(k * (total - 1) / (count - 1)) for k in range(count)}


def verify_project(name: str, manifest: dict) -> dict:
    old = Path(manifest["original_project_path"])
    copied = Path(manifest["copy_project_path"])
    if old != HISTORICAL_PROJECTS / name / "ghidra_project" or copied != SCRATCH / name / "ghidra_project":
        raise RuntimeError(f"project location differs: {name}")
    same = []
    session_metadata = []
    for record in manifest["files"]:
        relative = record["relative_path"]
        src = old / relative
        dst = copied / relative
        if sha256(src) != record["source_sha256"] or record["source_sha256"] != record["copy_sha256"]:
            raise RuntimeError(f"historical analyzed project changed: {name} {relative}")
        actual = sha256(dst) if dst.is_file() else None
        if actual == record["copy_sha256"]:
            same.append(relative)
        else:
            if relative not in {"SmallLib156.rep/idata/~index.bak",
                                "SmallLib156.rep/idata/~journal.bak"}:
                raise RuntimeError(f"copied analyzed project content changed: {name} {relative}")
            session_metadata.append({"path": relative, "before_sha256": record["copy_sha256"],
                                     "after_sha256": actual})
    required = ["SmallLib156.gpr", "SmallLib156.rep/idata/00/00000000.prp",
                "SmallLib156.rep/idata/00/~00000000.db/db.1.gbf"]
    if not all(relative in same for relative in required):
        raise RuntimeError(f"copied Ghidra program database changed: {name}")
    return {"library": name, "copied_project_files_initially_verified": len(manifest["files"]),
            "program_database_content_files_still_equal": required,
            "current_equal_file_count": len(same),
            "ghidra_session_metadata_changes": session_metadata}


def verify_library(name: str, expected_sha: str, expected_count: int,
                   batch: dict, receipt: dict, project: dict) -> dict:
    check_lease()
    source = SOURCE_DIR / name
    folder = REPORT / name
    if sha256(source) != expected_sha:
        raise RuntimeError(f"original SO SHA changed: {name}")
    copied = {row["report_path"]: row for row in batch["historical_files"]}
    if len(copied) != len(HISTORICAL_FILES):
        raise RuntimeError(f"historical file copy count differs: {name}")
    for filename in HISTORICAL_FILES:
        original = HISTORICAL / name / filename
        report = folder / ("historical_" + filename)
        row = copied[report.relative_to(REPORT).as_posix()]
        if row["original_path"] != str(original) or row["sha256"] != sha256(original) or row["sha256"] != sha256(report):
            raise RuntimeError(f"historical raw copy differs: {name}/{filename}")

    source_index = load(folder / "source_index.json")
    historical_index = load(folder / "historical_target_index.json")
    historical_raw = load(folder / "historical_ghidra_raw.json")
    historical_command = load(folder / "historical_ghidra_command.json")
    fresh = load(folder / "fresh_memory_raw.json")
    command = load(folder / "fresh_memory_command.json")
    if (source_index["source_sha256"] != expected_sha or
        source_index["historical_raw_sha256"] != sha256(folder / "historical_ghidra_raw.json") or
        source_index["original_unique_export_vas"] != expected_count or
        historical_index["source_sha256"] != expected_sha or
        historical_index["unique_export_vas"] != expected_count or
        historical_command["result_sha256"] != sha256(folder / "historical_ghidra_raw.json") or
        historical_command["stdout_sha256"] != sha256(folder / "historical_ghidra_stdout.log") or
        historical_command["stderr_sha256"] != sha256(folder / "historical_ghidra_stderr.log") or
        historical_command["target_tsv_sha256"] != sha256(folder / "historical_targets.tsv") or
        command["result_sha256"] != sha256(folder / "fresh_memory_raw.json") or
        command["stdout_sha256"] != sha256(folder / "fresh_memory_stdout.log") or
        command["stderr_sha256"] != sha256(folder / "fresh_memory_stderr.log") or
        command["source_sha256"] != expected_sha or
        command["script_sha256"] != sha256(SCRIPTS / "VerifyMemory176.java") or
        command["historical_targets_tsv_sha256"] != sha256(folder / "historical_targets.tsv") or
        command["status"] != "OUTPUT_READY" or command["exit_code"] != 0 or
        command["operation"] != "READ_ONLY_MEMORY_HASH_ONLY_NO_IMPORT_NO_DECOMPILATION" or
        "-readOnly" not in command["command"] or "-noanalysis" not in command["command"] or
        "-max-cpu" not in command["command"] or "-import" in command["command"] or
        "VerifyMemory176.java" not in command["command"] or
        fresh["fresh_imports"] != 0 or fresh["fresh_decompilations"] != 0):
        raise RuntimeError(f"command/raw/log provenance differs: {name}")
    for key in ("expected_target_count",):
        if command[key] != expected_count:
            raise RuntimeError(f"fresh command target count differs: {name}")
    if (len(source_index["targets"]) != expected_count or
        len(historical_index["targets"]) != expected_count or
        len(historical_raw["targets"]) != expected_count or
        len(fresh["targets"]) != expected_count or
        fresh["target_count"] != expected_count):
        raise RuntimeError(f"raw/index/fresh row count differs: {name}")
    if receipt["library"] != name or receipt["status"] != "OUTPUT_READY" or receipt["exit_code"] != 0:
        raise RuntimeError(f"run receipt differs: {name}")

    sample = sample_indices(expected_count)
    cs = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    totals = Counter()
    aliases = Counter()
    sample_rows = []
    evidence_rows = []
    with source.open("rb") as stream:
        elf = ELFFile(stream)
        if elf["e_machine"] != "EM_AARCH64":
            raise RuntimeError(f"source architecture differs: {name}")
        symbols: dict[int, list[tuple[str, int]]] = {}
        dynsym = elf.get_section_by_name(".dynsym")
        if dynsym is None:
            raise RuntimeError(f"source .dynsym absent: {name}")
        for sym in dynsym.iter_symbols():
            if (sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF"
                and int(sym["st_value"]) > 0 and int(sym["st_size"]) > 0):
                symbols.setdefault(int(sym["st_value"]), []).append((sym.name, int(sym["st_size"])))
        if len(symbols) != expected_count:
            raise RuntimeError(f"unique original export VAs differ: {name}")
        if fresh["image_base"] != historical_raw["image_base"]:
            raise RuntimeError(f"Ghidra image bases differ: {name}")
        base = int(fresh["image_base"], 16)
        for idx, va in enumerate(sorted(symbols), 1):
            aliases_at_va = sorted(symbols[va], key=lambda item: (-item[1], item[0]))
            symbol, size = aliases_at_va[0]
            body, offset = mapped_bytes(elf, source, va, size)
            body_sha = hashlib.sha256(body).hexdigest()
            srow = source_index["targets"][idx - 1]
            irow = historical_index["targets"][idx - 1]
            hrow = historical_raw["targets"][idx - 1]
            frow = fresh["targets"][idx - 1]
            row_identity = (idx, f"0x{va:x}", symbol, size, body_sha)
            for row in (srow, irow, hrow, frow):
                actual = (row["index"], row["elf_va"], row["symbol"], row["size_bytes"],
                          row.get("source_body_sha256", row.get("expected_source_sha256",
                                  row.get("ghidra_memory_sha256"))))
                if actual != row_identity:
                    raise RuntimeError(f"source/index/Ghidra row differs: {name} index {idx}")
            if (srow["file_offset"] != f"0x{offset:x}" or
                srow["aliases"] != [item[0] for item in aliases_at_va] or
                irow["file_offset"] != f"0x{offset:x}" or
                irow["aliases"] != srow["aliases"] or
                hrow["ghidra_memory_sha256"] != body_sha or
                frow["ghidra_memory_sha256"] != body_sha or
                hrow["source_bytes_match"] is not True or
                frow["source_bytes_match"] is not True or
                frow["function_present"] is not True or
                hrow["decompile_success"] is not True or
                hrow["error"] or not hrow["pseudocode"].strip() or
                hrow["instruction_count_observed"] != len(hrow["instructions"]) or
                frow["instruction_starts"] != len(hrow["instructions"]) or
                srow["historical_c_like_chars"] != len(hrow["pseudocode"]) or
                srow["historical_instruction_rows"] != len(hrow["instructions"]) or
                int(frow["database_va"], 16) != base + va or
                frow["database_va"] != hrow["database_va"]):
                raise RuntimeError(f"body/C-like/Ghidra memory differs: {name} index {idx}")
            # Independent Capstone decoding uses the pinned original PT_LOAD bytes.
            decoded = {ins.address: ins for ins in cs.disasm(body, base + va)}
            if len(decoded) * 4 != len(body):
                raise RuntimeError(f"original ARM64 body has undecoded bytes: {name} index {idx}")
            previous_pc = 0
            for line in hrow["instructions"]:
                pc_text, instruction = line.split(": ", 1)
                pc = int(pc_text, 16)
                if pc not in decoded or pc <= previous_pc:
                    raise RuntimeError(f"historical instruction PC/order differs: {name} index {idx}")
                previous_pc = pc
                ghidra_mnemonic = instruction.split()[0].lower()
                capstone_mnemonic = decoded[pc].mnemonic.lower()
                if ghidra_mnemonic != capstone_mnemonic:
                    pair = (ghidra_mnemonic, capstone_mnemonic)
                    if pair not in ALIAS_PAIRS:
                        raise RuntimeError(f"unexpected Ghidra/Capstone mnemonic: {name} index {idx} {pair}")
                    aliases[f"{pair[0]} -> {pair[1]}"] += 1
                totals["historical_instruction_pcs_cross_checked"] += 1
            for call in hrow["calls"]:
                pc_text, target_text = call.split(" -> ", 1)
                pc = int(pc_text, 16)
                ins = decoded.get(pc)
                if ins is None or ins.mnemonic not in {"bl", "b", "blr"}:
                    raise RuntimeError(f"historical call PC/instruction differs: {name} index {idx}")
                if target_text == "INDIRECT":
                    if ins.mnemonic != "blr":
                        raise RuntimeError(f"historical indirect call differs: {name} index {idx}")
                    totals["indirect_calls_cross_checked"] += 1
                else:
                    target = int(target_text.split(" ", 1)[0], 16)
                    if ins.mnemonic not in {"bl", "b"} or target != int(ins.op_str.lstrip("#"), 0):
                        raise RuntimeError(f"historical direct target differs: {name} index {idx}")
                    totals["direct_call_branch_targets_cross_checked"] += 1
            totals["original_pt_load_body_hashes_cross_checked"] += 1
            totals["historical_c_like_bodies_cross_checked"] += 1
            totals["fresh_ghidra_memory_bodies_cross_checked"] += 1
            totals["source_body_bytes_cross_checked"] += size
            if idx in sample:
                sample_rows.append({"index": idx, "elf_va": f"0x{va:x}", "symbol": symbol,
                                    "source_body_sha256": body_sha,
                                    "c_like_sha256": hashlib.sha256(hrow["pseudocode"].encode()).hexdigest(),
                                    "capstone_decoded_instructions": len(decoded),
                                    "ghidra_instruction_pcs": len(hrow["instructions"]),
                                    "direct_or_tail_calls": sum("INDIRECT" not in c for c in hrow["calls"]),
                                    "indirect_calls": sum("INDIRECT" in c for c in hrow["calls"])})
            evidence_rows.append({"index": idx, "elf_va": f"0x{va:x}",
                                  "source_body_sha256": body_sha,
                                  "ghidra_memory_sha256": frow["ghidra_memory_sha256"],
                                  "historical_c_like_sha256": hashlib.sha256(hrow["pseudocode"].encode()).hexdigest(),
                                  "historical_instruction_rows": len(hrow["instructions"]),
                                  "fresh_instruction_starts": frow["instruction_starts"]})
    if totals["source_body_bytes_cross_checked"] != fresh["body_bytes_hashed"]:
        raise RuntimeError(f"fresh Ghidra body byte count differs: {name}")
    if len(sample_rows) < math.ceil(0.1 * expected_count):
        raise RuntimeError(f"ordinary provenance sample below 10%: {name}")
    result = {"library": name, "original_source_sha256": expected_sha,
              "original_unique_defined_nonzero_dynsym_func_vas": expected_count,
              "historical_evidence_class": "TASK_156_C_LIKE_REVALIDATED_NOT_NEWLY_DECOMPILED",
              "fresh_imports": 0, "fresh_decompilations": 0,
              "all_critical_checks": dict(totals),
              "ghidra_capstone_alias_mnemonics": dict(aliases),
              "ordinary_spread_sample_count": len(sample_rows),
              "ordinary_spread_sample_percent": round(100 * len(sample_rows) / expected_count, 2),
              "ordinary_spread_sample": sample_rows,
              "project_provenance": verify_project(name, project),
              "all_export_evidence_rows": evidence_rows}
    write_json(folder / "independent_verification.json", result)
    return {key: value for key, value in result.items() if key not in {"ordinary_spread_sample", "all_export_evidence_rows"}}


def seal() -> None:
    check_lease()
    if (REPORT / "COMPLETE.json").exists():
        raise RuntimeError("TASK_176 already sealed; refusing to rewrite")
    if sha256(HISTORICAL / "COMPLETE.json") != HISTORICAL_COMPLETE_SHA:
        raise RuntimeError("historical TASK_156 manifest changed")
    batch = load(REPORT / "source_batch_index.json")
    receipt = load(REPORT / "memory_run_receipt.json")
    project = load(REPORT / "project_copy_manifest.json")
    if (batch["standard_sha256"] != STANDARD_SHA or batch["task_sha256"] != TASK_SHA or
        batch["actor"] != AGENT_ID or batch["lease_id"] != LEASE_ID or
        batch["total_original_unique_export_vas"] != 683 or
        batch["total_original_pt_load_bodies_revalidated"] != 683 or
        batch["total_historical_c_like_bodies"] != 683 or
        project["historical_complete_sha256"] != HISTORICAL_COMPLETE_SHA or
        len(receipt["libraries"]) != 2):
        raise RuntimeError("batch/receipt/project summary differs")
    results = []
    for (name, (expected_sha, expected_count)), source_row, run_row in zip(
            LIBRARIES.items(), batch["libraries"], receipt["libraries"]):
        if source_row["library"] != name or run_row["library"] != name:
            raise RuntimeError("source or run order differs")
        results.append(verify_library(name, expected_sha, expected_count, source_row,
                                      run_row, project["projects"][name]))
    total_calls = sum(result["all_critical_checks"]["direct_call_branch_targets_cross_checked"]
                      for result in results)
    total_indirect = sum(result["all_critical_checks"]["indirect_calls_cross_checked"]
                         for result in results)
    total_instructions = sum(result["all_critical_checks"]["historical_instruction_pcs_cross_checked"]
                             for result in results)
    total_sample = sum(result["ordinary_spread_sample_count"] for result in results)
    master = ("# TASK_176 R1 — static export evidence revalidation\n\n"
              "The pinned original `libbmpKit.so` and `libfftw3.so` contain 316 and 367 "
              "unique, defined, nonzero-size `.dynsym` STT_FUNC export VAs respectively. "
              "All 683 original PT_LOAD function bodies, historical TASK_156 C-like bodies and "
              "fresh Ghidra memory bodies were cross-checked against the original bytes. "
              "This is **revalidated historical research**, with zero fresh imports and zero "
              "fresh decompilations. TASK_156's earlier report was not treated as approved.\n\n"
              f"Independent ARM64 decoding checked {total_instructions} historical instruction "
              f"addresses, {total_calls} direct call/tail-branch targets and {total_indirect} "
              "indirect call sites against pinned original bytes. A deterministic index-spread "
              f"sample of {total_sample}/683 exports ({100*total_sample/683:.2f}%) received "
              "per-row C-like hashes and instruction/call receipts, in addition to the complete "
              "683-row critical checks. The copied Ghidra program database bytes were unchanged "
              "after read-only inspection; Ghidra altered only ephemeral project index/journal "
              "metadata, recorded in each independent verification file.\n\n"
              "The recovered material is static, Ghidra-generated C-like pseudocode for these "
              "exported VAs. It does not establish behavioral equivalence, all internal-function "
              "coverage, product integration, Phase PASS, or V4 readiness. Independent CEO "
              "review remains required.\n")
    atomic_bytes(REPORT / "01_MASTER_REPORT.md", master.encode("utf-8"))
    audit = (REPORT / "00_AUDIT_INDEX.md").read_text(encoding="utf-8")
    audit += ("\nIndependent verification: `01_MASTER_REPORT.md`, each library's "
              "`source_index.json`, `historical_*` raw command/log/result, `fresh_memory_*` "
              "read-only Ghidra command/log/result, and `independent_verification.json`. "
              "`project_copy_manifest.json` records original and copied analyzed-project hashes. "
              "`COMPLETE.json` seals all report and script hashes. No new pseudocode was generated.\n")
    atomic_bytes(REPORT / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    write_json(REPORT / "PROGRESS.json", {
        "task_id": "TASK_176", "revision": 1, "status": "SEALED_CANDIDATE",
        "generated_at": now(), "original_unique_export_vas": 683,
        "original_pt_load_bodies_verified": 683,
        "historical_c_like_bodies_revalidated": 683,
        "fresh_ghidra_memory_bodies_verified": 683,
        "ordinary_spread_sample": total_sample,
        "fresh_imports": 0, "fresh_decompilations": 0,
        "disposition": "AWAITING_INDEPENDENT_CEO_REVIEW"})
    report_files = {p.relative_to(REPORT).as_posix(): sha256(p)
                    for p in sorted(REPORT.rglob("*"))
                    if p.is_file() and p.name not in {"COMPLETE.json", "PROGRESS.json", "PROGRESS.md"}}
    code_files = {p.relative_to(ROOT).as_posix(): sha256(p)
                  for p in sorted(SCRIPTS.rglob("*"))
                  if p.is_file() and p.suffix in {".py", ".java"}}
    scratch_files = {p.relative_to(ROOT).as_posix(): sha256(p)
                     for p in sorted(SCRATCH.rglob("*")) if p.is_file()}
    report_bytes = sum(p.stat().st_size for p in REPORT.rglob("*") if p.is_file())
    if report_bytes > 134_217_728:
        raise RuntimeError("report exceeds TASK_176 cap")
    manifest = {
        "schema_version": "2.1.2", "task_id": "TASK_176", "revision": 1,
        "status": "COMPLETE", "result_class": "REVALIDATED_HISTORICAL_STATIC_EXPORT_RESEARCH",
        "generated_at": now(), "agent_id": AGENT_ID, "lease_id": LEASE_ID,
        "standard_path": str(STANDARD), "standard_sha256": STANDARD_SHA,
        "task_sha256": TASK_SHA,
        "original_export_vas": 683, "historical_c_like_bodies_revalidated": 683,
        "fresh_ghidra_memory_bodies_verified": 683,
        "fresh_imports": 0, "fresh_decompilations": 0,
        "ordinary_spread_sample_count": total_sample,
        "files": report_files, "code_files": code_files,
        "scratch_files": scratch_files,
        "limits": "static exported VA C-like only; no behavior parity or product phase claim"
    }
    write_json(REPORT / "COMPLETE.json", manifest)
    print(json.dumps({"status": "SEALED_CANDIDATE", "libraries": len(results),
                      "original_vas": 683, "historical_c_like": 683,
                      "fresh_memory_verified": 683, "instruction_pcs": total_instructions,
                      "direct_call_targets": total_calls, "indirect_calls": total_indirect,
                      "spread_sample": total_sample,
                      "complete_sha256": sha256(REPORT / "COMPLETE.json")}))


if __name__ == "__main__":
    seal()
