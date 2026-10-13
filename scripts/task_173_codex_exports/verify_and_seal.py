"""Independently check both full original instruction ranges and seal TASK_173 R1."""

from __future__ import annotations

import hashlib
import json
import re
from collections import Counter
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile

from common import (AGENT_ID, FENCE, LEASE_ID, REPORT, ROOT, SCRATCH, SCRIPTS,
                    SOURCE_DIR, STANDARD, STANDARD_SHA, TASK, TASK_SHA,
                    atomic_bytes, check_lease, now, sha256, write_json)
from prepare import PRIOR_COMPLETE_SHA, SOURCE_SHA, TARGETS, original_body
from run import check_project_copy

INDICES = (2283, 2330)
PREVIOUS_SEAL_SHA = "44fa160900b66bfe09fa04ce067ce4a947f615d60014d79cbd5df343a9a55add"
REQUIRED_COMMAND_SWITCHES = ("-process", "libffmpeg.so", "-noanalysis", "-readOnly",
                             "-max-cpu", "1", "-postScript", "AltNeon173.java")


def require(condition: bool, message: str) -> None:
    if not condition:
        raise RuntimeError(message)


def read_json(path: Path) -> dict:
    return json.loads(path.read_text(encoding="utf-8"))


def verify_original() -> tuple[dict, int]:
    source = SOURCE_DIR / "libffmpeg.so"
    require(sha256(source) == SOURCE_SHA, "original source SHA changed")
    require(sha256(ROOT / "RULES/REPORT/TASK_170_REPORT_R1/COMPLETE.json") ==
            PRIOR_COMPLETE_SHA, "accepted TASK_170 identity changed")
    source_index = read_json(REPORT / "source_targets.json")
    require(source_index["source_sha256"] == SOURCE_SHA and
            source_index["prior_complete_sha256"] == PRIOR_COMPLETE_SHA and
            {row["index"] for row in source_index["targets"]} == set(INDICES),
            "prepared original source target index differs")
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    verified = {}
    total_instructions = 0
    with source.open("rb") as stream:
        elf = ELFFile(stream)
        require(elf["e_machine"] == "EM_AARCH64", "original architecture differs")
        dynamic = elf.get_section_by_name(".dynsym")
        by_va = {int(symbol["st_value"]): symbol for symbol in dynamic.iter_symbols()
                 if symbol["st_info"]["type"] == "STT_FUNC" and
                 symbol["st_shndx"] != "SHN_UNDEF" and
                 int(symbol["st_value"]) > 0 and int(symbol["st_size"]) > 0}
        require(len(by_va) == 2461, "original unique exported VA census differs")
        for index, va, size, name, body_sha, _ in TARGETS:
            symbol = by_va.get(va)
            require(symbol is not None and symbol.name == name and
                    int(symbol["st_size"]) == size, f"export differs at 0x{va:x}")
            body, offset = original_body(elf, source, va, size)
            require(hashlib.sha256(body).hexdigest() == body_sha,
                    f"original PT_LOAD body differs at 0x{va:x}")
            decoded = list(decoder.disasm(body, va))
            require(len(decoded) * 4 == size and
                    all(ins.address == va + j * 4 for j, ins in enumerate(decoded)),
                    f"source full instruction range not decoded at 0x{va:x}")
            assembly = [f"0x{ins.address:x}: {ins.mnemonic} {ins.op_str}".rstrip()
                        for ins in decoded]
            require((REPORT / f"source_assembly_{index}.txt").read_text(encoding="utf-8").splitlines()
                    == assembly, f"independent source assembly differs for {index}")
            row = next(row for row in source_index["targets"] if row["index"] == index)
            require(row["assembly"] == assembly and row["source_body_sha256"] == body_sha and
                    row["file_offset"] == f"0x{offset:x}" and
                    row["capstone_instruction_count"] == len(assembly),
                    f"prepared source/body/census differs for {index}")
            old = read_json(REPORT / f"prior_failure_{index}.json")
            require(old["index"] == index and old["source_bytes_match"] is True and
                    old["ghidra_memory_sha256"] == body_sha and
                    old["decompile_success"] is False and
                    "Unable to find unique hash for varnode" in old["error"],
                    f"prior Ghidra failure evidence differs for {index}")
            verified[index] = {"index": index, "elf_va": f"0x{va:x}", "symbol": name,
                               "size_bytes": size, "source_body_sha256": body_sha,
                               "source_file_offset": f"0x{offset:x}",
                               "source_instruction_count": len(assembly),
                               "assembly_sha256": sha256(REPORT / f"source_assembly_{index}.txt")}
            total_instructions += len(assembly)
    return verified, total_instructions


def verify_target(index: int, source: dict) -> dict:
    raw_path = REPORT / f"alternative_{index}_raw.json"
    command_path = REPORT / f"alternative_{index}_command.json"
    stdout_path = REPORT / f"alternative_{index}_stdout.log"
    stderr_path = REPORT / f"alternative_{index}_stderr.log"
    require(all(path.is_file() for path in
                (raw_path, command_path, stdout_path, stderr_path)),
            f"alternative attempt evidence missing for {index}")
    raw = read_json(raw_path)
    command = read_json(command_path)
    expected = ("TASK_173", 1, index, "libffmpeg.so", source["elf_va"],
                source["symbol"], source["size_bytes"], source["source_body_sha256"])
    actual = (raw["task_id"], raw["revision"], raw["target_index"], raw["program_name"],
              raw["elf_va"], raw["symbol"], raw["size_bytes"],
              raw["ghidra_memory_sha256"])
    require(actual == expected and raw["expected_source_sha256"] == source["source_body_sha256"]
            and raw["source_bytes_match"] is True and raw["alternative_style"] == "normalize",
            f"Ghidra program/memory target does not match original for {index}")
    require(0 <= raw["alternative_decompile_seconds"] <= 180 and
            raw["decompile_completed"] is True, f"decompile cap/completion failed for {index}")
    require(command["task_id"] == "TASK_173" and command["revision"] == 1 and
            command["target_index"] == index and command["lease_id"] == LEASE_ID and
            command["fencing_token"] == FENCE and command["status"] == "OUTPUT_READY" and
            command["exit_code"] == 0 and 0 <= command["elapsed_seconds"] <= 210 and
            command["source_sha256"] == SOURCE_SHA and
            command["source_body_sha256"] == source["source_body_sha256"],
            f"attempt receipt differs for {index}")
    args = command["command"]
    require(all(switch in args for switch in REQUIRED_COMMAND_SWITCHES) and
            "-import" not in args and "-readOnly" in args and
            args.count("-postScript") == 1 and
            command["script_sha256"] == sha256(SCRIPTS / "AltNeon173.java") and
            command["result_sha256"] == sha256(raw_path) and
            command["stdout_sha256"] == sha256(stdout_path) and
            command["stderr_sha256"] == sha256(stderr_path),
            f"read-only command/output hashes differ for {index}")
    require(command["target_tsv_sha256"] == sha256(REPORT / f"target_{index}.tsv") and
            command["project_copy_manifest_sha256"] ==
            sha256(REPORT / "project_copy_manifest.json"),
            f"input/project provenance differs for {index}")
    observed = command["observed"]
    require(observed["source_bytes_match"] is True and
            observed["decompile_completed"] is True and
            observed["c_like_nonempty"] == bool(raw["c_like"].strip()) and
            observed["instruction_rows"] == len(raw["instructions"]) and
            observed["raw_pcode_rows"] == len(raw["raw_pcode"]) and
            observed["high_pcode_rows"] == len(raw["normalized_high_pcode"]),
            f"attempt output summary differs for {index}")

    # Independently enumerate every original 4-byte instruction address. The
    # Ghidra database uses a 0x100000 image base; address alignment and every
    # instruction's raw p-code are checked, not only file/function counts.
    image_base = int(raw["database_va"], 16) - int(source["elf_va"], 16)
    require(image_base == 0x100000, f"Ghidra image base changed for {index}")
    addresses = [int(line.split(":", 1)[0], 16) for line in raw["instructions"]]
    expected_addresses = [image_base + int(source["elf_va"], 16) + 4 * j
                          for j in range(source["source_instruction_count"])]
    require(addresses == expected_addresses, f"Ghidra full instruction range differs for {index}")
    raw_pcode_counts = Counter(int(line.split(":", 1)[0], 16)
                               for line in raw["raw_pcode"])
    require(set(raw_pcode_counts) == set(expected_addresses) and
            all(raw_pcode_counts[address] > 0 for address in expected_addresses),
            f"Ghidra raw p-code does not cover every original instruction for {index}")
    high_pcode_counts = Counter(int(line.split(":", 1)[0], 16)
                                for line in raw["normalized_high_pcode"])
    require(high_pcode_counts and set(high_pcode_counts).issubset(set(expected_addresses)),
            f"normalized p-code addresses outside source range for {index}")
    rows = [{"index": j + 1, "elf_pc": f"0x{int(source['elf_va'], 16) + 4*j:x}",
             "ghidra_pc": f"0x{address:x}",
             "source_assembly": (REPORT / f"source_assembly_{index}.txt")
             .read_text(encoding="utf-8").splitlines()[j],
             "ghidra_instruction": raw["instructions"][j],
             "raw_pcode_ops": raw_pcode_counts[address],
             "normalized_pcode_ops": high_pcode_counts[address]}
            for j, address in enumerate(expected_addresses)]
    write_json(REPORT / f"instruction_verification_{index}.json", {
        "task_id": "TASK_173", "target_index": index,
        "source_body_sha256": source["source_body_sha256"],
        "all_original_instructions_verified": len(rows), "rows": rows})
    return {**source, "ghidra_image_base": f"0x{image_base:x}",
            "ghidra_instruction_count": len(addresses),
            "raw_pcode_ops": len(raw["raw_pcode"]),
            "normalized_pcode_ops": len(raw["normalized_high_pcode"]),
            "normalized_pcode_source_pcs": len(high_pcode_counts),
            "alternative_decompile_seconds": raw["alternative_decompile_seconds"],
            "attempt_wall_seconds": command["elapsed_seconds"],
            "c_like_recovered": bool(raw["c_like"].strip()),
            "decompile_error": raw["decompile_error"],
            "instruction_verification_sha256":
            sha256(REPORT / f"instruction_verification_{index}.json")}


def main() -> None:
    check_lease()
    previous_seal = REPORT / "COMPLETE.json"
    require(not previous_seal.exists() or sha256(previous_seal) == PREVIOUS_SEAL_SHA,
            "TASK_173 seal changed outside the exact schema correction")
    require(check_project_copy() == sha256(REPORT / "project_copy_manifest.json"),
            "analyzed project copy changed")
    project_manifest = read_json(REPORT / "project_copy_manifest.json")
    for item in project_manifest["files"]:
        original = Path(project_manifest["source_project"]) / item["relative_path"]
        require(original.is_file() and sha256(original) == item["source_sha256"] and
                item["source_sha256"] == item["copy_sha256"],
                "accepted Ghidra project/source copy differs")
    originals, total_instructions = verify_original()
    batch = read_json(REPORT / "batch_run_receipt.json")
    require(batch["task_id"] == "TASK_173" and batch["revision"] == 1 and
            batch["status"] == "OUTPUT_READY" and len(batch["targets"]) == 2 and
            [entry["target_index"] for entry in batch["targets"]] == list(INDICES),
            "bounded one-shot batch receipt differs")
    results = [verify_target(index, originals[index]) for index in INDICES]
    for entry, result in zip(batch["targets"], results):
        require(entry["status"] == "OUTPUT_READY" and
                entry["elapsed_seconds"] == result["attempt_wall_seconds"],
                "batch command duration/status differs")
    c_like_count = sum(int(result["c_like_recovered"]) for result in results)
    manual = REPORT / "manual_register_pseudocode.md"
    if c_like_count < 2:
        require(manual.is_file() and all(label in manual.read_text(encoding="utf-8")
                for label in ("manual register-level", "0x658fe8", "0x65aea8",
                              "source_assembly_2283.txt", "source_assembly_2330.txt")),
                "explicitly labeled manual fallback missing")
    verification = {
        "task_id": "TASK_173", "revision": 1, "verified_at": now(),
        "verdict": "TWO_C_LIKE_RECOVERED" if c_like_count == 2 else "PARTIAL_STATIC_FALLBACK",
        "original_so_sha256": SOURCE_SHA, "prior_accepted_complete_sha256": PRIOR_COMPLETE_SHA,
        "original_unique_export_vas": 2461, "original_instruction_rows_verified": total_instructions,
        "target_count": 2, "bounded_alternative_attempts": 2,
        "bounded_attempt_wall_seconds_total": sum(row["attempt_wall_seconds"] for row in results),
        "c_like_recovered_count": c_like_count,
        "register_level_manual_count": 2 - c_like_count,
        "project_file_hashes_verified": len(project_manifest["files"]),
        "target_results": results,
        "behavioral_equivalence_tested": False, "product_phase_pass": False,
        "review_status": "PENDING_CEO_INDEPENDENT_REVIEW",
    }
    write_json(REPORT / "verification.json", verification)
    disposition = ("COMPLETE_STATIC_RESEARCH_CANDIDATE" if c_like_count == 2
                   else "PARTIAL_STATIC_RESEARCH_CANDIDATE")
    report_text = (
        "# TASK_173 R1 — two FFmpeg NEON correction attempts\n\n"
        f"**Disposition:** {disposition}. CEO review pending. No product Phase PASS or V4 claim.\n\n"
        f"Pinned original libffmpeg.so SHA-256 `{SOURCE_SHA}`; accepted TASK_170 report "
        f"SHA-256 `{PRIOR_COMPLETE_SHA}`. Both original PT_LOAD bodies and all "
        f"{total_instructions} AArch64 instructions were independently decoded and matched "
        "to the copied Ghidra program's full instruction ranges and raw p-code PCs. "
        "The 9-file analyzed project copy remained byte-identical to the prior project.\n\n"
        "One read-only, no-analysis Ghidra `normalize` attempt ran per target, with one "
        "CPU and 1 GiB heap. Both decompiles completed and produced raw plus normalized "
        "p-code but no C-like body. There were no retries, reimports, or full-library scans.\n\n"
        "| Index | Original VA | Original body | Raw p-code ops | Normalized ops | "
        "Attempt wall time | Result |\n"
        "|---:|---|---|---:|---:|---:|---|\n" +
        "\n".join(f"| {row['index']} | {row['elf_va']} | `{row['source_body_sha256']}` | "
                  f"{row['raw_pcode_ops']} | {row['normalized_pcode_ops']} | "
                  f"{row['attempt_wall_seconds']:.3f}s | "
                  f"{'C-like recovered' if row['c_like_recovered'] else 'manual register-level fallback only'} |"
                  for row in results) +
        "\n\n`manual_register_pseudocode.md` contains the separately labeled fallback, "
        "with exact instruction-address references. `source_assembly_*.txt`, "
        "`instruction_verification_*.json`, `alternative_*_raw.json`, command receipts, "
        "stdout and stderr are the primary provenance. The manual interpretation is "
        "static and has not been compiled or tested against native behavior. The two "
        "targets therefore remain unresolved for C-like recovery and product purposes.\n")
    atomic_bytes(REPORT / "01_MASTER_REPORT.md", report_text.encode("utf-8"))
    audit = ("# TASK_173 R1 audit index\n\n"
             f"Canonical standard fully re-read: `{STANDARD}` SHA-256 `{STANDARD_SHA}`.\n\n"
             f"Exact ACTIVE task `{TASK}` SHA-256 `{TASK_SHA}`; actor `{AGENT_ID}`; "
             f"lease `{LEASE_ID}`; fence `{FENCE}`.\n\n"
             "Source, previous accepted report, Ghidra project copy, both full original "
             "instruction ranges, command receipts, raw output, and per-instruction "
             "verification are indexed in `COMPLETE.json`.\n\n"
             f"Disposition: `{disposition}`; independent CEO review pending.\n")
    atomic_bytes(REPORT / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    write_json(REPORT / "PROGRESS.json", {
        "task_id": "TASK_173", "revision": 1, "status": "SEALED_CANDIDATE",
        "generated_at": now(), "disposition": disposition,
        "original_instruction_rows_verified": total_instructions,
        "alternative_attempts_finished": 2, "c_like_recovered": c_like_count,
        "manual_register_level_fallback": 2 - c_like_count,
        "lease_id": LEASE_ID, "fencing_token": FENCE})
    report_files = sorted(path for path in REPORT.rglob("*") if path.is_file()
                          and path.name != "COMPLETE.json")
    report_bytes = sum(path.stat().st_size for path in report_files)
    require(report_bytes <= 33554432, "report package exceeds task cap")
    script_files = sorted(path for path in SCRIPTS.rglob("*") if path.is_file()
                          and "__pycache__" not in path.parts)
    file_hashes = {path.relative_to(ROOT).as_posix(): sha256(path)
                   for path in report_files + script_files}
    # The CEO controller snapshots PROGRESS separately. Its report-file manifest
    # uses paths relative to this report folder, while code_files uses root paths.
    controller_files = {path.relative_to(REPORT).as_posix(): sha256(path)
                        for path in report_files
                        if path.name not in ("PROGRESS.json", "PROGRESS.md")}
    controller_code_files = {path.relative_to(ROOT).as_posix(): sha256(path)
                             for path in script_files}
    for item in project_manifest["files"]:
        path = SCRATCH / "ghidra_project" / item["relative_path"]
        file_hashes[path.relative_to(ROOT).as_posix()] = sha256(path)
    seal = {
        "schema_version": "2.1.2", "task_id": "TASK_173", "revision": 1,
        "status": "COMPLETE", "semantic_disposition": disposition,
        "sealed_at": now(), "actor": AGENT_ID,
        "lease_id": LEASE_ID, "fencing_token": FENCE,
        "canonical_standard_path": str(STANDARD), "canonical_standard_sha256": STANDARD_SHA,
        "standard_sha256": STANDARD_SHA,
        "task_path": str(TASK), "task_sha256": TASK_SHA,
        "source_sha256": SOURCE_SHA, "accepted_prior_complete_sha256": PRIOR_COMPLETE_SHA,
        "target_count": 2, "critical_original_instruction_rows_verified": total_instructions,
        "alternative_attempts": 2, "c_like_recovered_count": c_like_count,
        "register_level_manual_fallback_count": 2 - c_like_count,
        "report_bytes_excluding_seal": report_bytes,
        "files": controller_files,
        "code_files": controller_code_files,
        "artifact_sha256": file_hashes,
        "independent_ceo_review": "PENDING", "behavioral_equivalence_tested": False,
        "product_phase_pass": False, "v4_authorized": False,
    }
    write_json(REPORT / "COMPLETE.json", seal)
    print(json.dumps({"status": "COMPLETE", "disposition": disposition,
                      "critical_instruction_rows_verified": total_instructions,
                      "report_bytes_excluding_seal": report_bytes,
                      "artifacts": len(file_hashes),
                      "complete_sha256": sha256(REPORT / "COMPLETE.json")}))


if __name__ == "__main__":
    main()
