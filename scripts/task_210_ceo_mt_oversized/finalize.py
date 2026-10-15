"""Seal truthful bounded static research; leave CEO acceptance independent."""
from __future__ import annotations

import datetime as dt
import json
from pathlib import Path

from extract_original import (ROOT, REPORT, SOURCE, SOURCE_SHA, STANDARD,
                              STANDARD_SHA, TARGETS, TARGETS_SHA, TASK,
                              check_lease, sha, write_json)


def main() -> None:
    check_lease()
    if any((REPORT / x).exists() for x in ("COMPLETE.json", "FREEZE.json", "01_MASTER_REPORT.md")):
        raise RuntimeError("final report already exists")
    if sha(SOURCE) != SOURCE_SHA or sha(STANDARD) != STANDARD_SHA or sha(TARGETS) != TARGETS_SHA:
        raise RuntimeError("pinned source/standard/target changed")
    source = json.loads((REPORT / "source_index.json").read_text(encoding="utf-8"))
    copy = json.loads((REPORT / "project_copy_index.json").read_text(encoding="utf-8"))
    main_run = json.loads((REPORT / "ghidra_command.json").read_text(encoding="utf-8"))
    correction_run = json.loads((REPORT / "ghidra_correction_command.json").read_text(encoding="utf-8"))
    replay_run = json.loads((REPORT / "ghidra_rollback_check_command.json").read_text(encoding="utf-8"))
    spread = json.loads((REPORT / "source_spread_recheck.json").read_text(encoding="utf-8"))
    for run, count in ((main_run, 7), (correction_run, 3), (replay_run, 7)):
        if run["status"] != "OUTPUT_READY" or run["exit_code"] != 0:
            raise RuntimeError("headless stage incomplete")
        hashes = run.get("raw_result_hashes", run.get("output_hashes"))
        if len(hashes) != count:
            raise RuntimeError("headless row count mismatch")
        for name, expected in hashes.items():
            folder = "ghidra_raw" if run is main_run else run["step"]
            if sha(REPORT / folder / name) != expected:
                raise RuntimeError("headless row changed")
        for entry in copy["project_files"]:
            if run["project_post_hashes"].get(entry["relative_path"]) != entry["sha256"]:
                raise RuntimeError("private project changed")
    if spread["mismatches"] or spread["checked_slots"] < spread["total_slots"] * .1:
        raise RuntimeError("source spread insufficient")
    rows = source["selected"]
    if [r["index"] for r in rows] != [211, 216, 235, 293, 304, 349, 362]:
        raise RuntimeError("target set mismatch")
    raw = {}
    corrected = {}
    effective_slots = effective_pcode = full_original = 0
    for row in rows:
        index = row["index"]
        src = json.loads((ROOT / row["evidence_path"]).read_text(encoding="utf-8"))
        if len(src["instructions"]) != row["instruction_slots"] or src["body_sha256"] != row["source_sha256"]:
            raise RuntimeError(f"source evidence mismatch {index}")
        file = REPORT / "ghidra_raw" / f"{index:03d}_{int(row['elf_va'], 16):x}.json"
        evidence = json.loads(file.read_text(encoding="utf-8"))
        raw[index] = evidence
        if (evidence["ghidra_memory_sha256"] != row["source_sha256"] or
                len(evidence["instruction_pcode"]) != row["instruction_slots"] or
                len(evidence["fde_byte_membership_bits"]) != row["size_bytes"]):
            raise RuntimeError(f"raw Ghidra mismatch {index}")
        if evidence["fde_byte_membership_count"] == row["size_bytes"]:
            full_original += 1
        replay = json.loads((REPORT / "ghidra_rollback_check" / file.name).read_text(encoding="utf-8"))
        if (replay["ghidra_memory_sha256"] != evidence["ghidra_memory_sha256"] or
                replay["fde_byte_membership_bits"] != evidence["fde_byte_membership_bits"] or
                replay["function_start"] != evidence["function_start"]):
            raise RuntimeError(f"fresh rollback mismatch {index}")
        if index in (304, 349, 362):
            c = json.loads((REPORT / "ghidra_correction" / file.name).read_text(encoding="utf-8"))
            corrected[index] = c
            if (c["memory_sha256"] != row["source_sha256"] or
                    c["other_function_byte_count"] != 0 or
                    c["original_function_fde_membership_bits"] != evidence["fde_byte_membership_bits"] or
                    c["corrected_function_fde_membership_count"] != row["size_bytes"] or
                    c["full_fde_instruction_count"] != row["instruction_slots"] or
                    not c["memory_unchanged_after_rollback"]):
                raise RuntimeError(f"correction mismatch {index}")
            effective_slots += c["full_fde_instruction_count"]
            effective_pcode += c["full_fde_pcode_ops"]
        else:
            if evidence["fde_byte_membership_count"] != row["size_bytes"]:
                raise RuntimeError(f"unexpected body gap {index}")
            effective_slots += evidence["ghidra_instruction_count"]
            effective_pcode += evidence["ghidra_pcode_ops"]
    if effective_slots != 10114 or full_original != 4:
        raise RuntimeError("effective evidence census changed")
    summary = {
        "task_id": "TASK_210", "revision": 1, "result": "PARTIAL_STATIC_RESEARCH_BOUNDARIES_UNPROVEN",
        "selected_indices": [r["index"] for r in rows], "source_sha256": SOURCE_SHA,
        "original_bytes_verified": sum(r["size_bytes"] for r in rows),
        "original_instruction_words_verified": spread["total_slots"],
        "source_spread_rechecked": spread["checked_slots"],
        "ghidra_raw_listing_positions": sum(g["ghidra_instruction_count"] for g in raw.values()),
        "ghidra_raw_missing_listing_positions": sum(g["missing_analyzed_instruction_count"] for g in raw.values()),
        "effective_ghidra_instruction_positions": effective_slots,
        "effective_ghidra_pcode_ops": effective_pcode,
        "nonempty_c_like_rows": sum(g["c_like_nonempty"] for g in raw.values()),
        "original_full_fde_body_membership_rows": full_original,
        "transient_full_fde_metadata_assumptions": len(corrected),
        "fresh_session_original_metadata_and_memory_replays": len(rows),
        "same_session_metadata_restored_flags": {str(i): corrected[i]["same_session_function_metadata_restored"] for i in corrected},
        "verified_behavior_candidates": 0, "fresh_imports": 0,
        "remaining_nonselected_MTFilter_nonexport_fde_indices": [201],
    }
    write_json(REPORT / "verification_summary.json", summary)
    report = ("# TASK_210 R1 — seven oversized libMTFilterKernel.so FDE candidates\n\n"
              "**Result: PARTIAL static research.** The seven exact pinned candidate ranges "
              "(indices 211, 216, 235, 293, 304, 349, 362) total 40,456 original bytes and "
              "10,114 AArch64 instruction words. ELF unwind entries and PT_LOAD mapping match the original SO; "
              "10,114/10,114 words decode with Capstone. A deterministic spread independently re-read and "
              "re-decoded 1,014/10,114 slots (10.03%) with zero mismatches.\n\n"
              "A byte-identical copy of the previously accepted private MTFilter project was used in "
              "single-CPU, 1 GiB headless Ghidra. Seven raw rows yielded 9,985 listing positions, "
              "40,510 p-code operations and seven nonempty C-like texts. Four existing Ghidra functions cover "
              "their entire FDE range. Indices 304, 349 and 362 have, respectively, 260, 32 and 224 "
              "missing function-body bytes (516 total, 129 instruction positions), with zero other-function "
              "ownership in those gaps. A transaction-scoped metadata/disassembly probe supplies full-FDE "
              "listing and p-code for those three, giving 10,114 effective positions and 40,717 p-code "
              "operations. These are **assumed FDE boundaries**, not proven complete source functions.\n\n"
              "The three correction rows report `same_session_function_metadata_restored=false`. "
              "A separate fresh read-only Ghidra session reproduced the original function starts, "
              "byte membership bitmaps and memory hashes for all seven. All nine private project files "
              "matched their pre-run hashes after every run. The fresh session is the rollback evidence; "
              "the same-session flag is not treated as success.\n\n"
              "The distinct selected MTFilter nonexport-FDE candidate census is now 510/511 across prior "
              "accepted work plus this task; index 201 (36,172 bytes) remains unselected. Candidate selection "
              "and C-like output do not establish unique source boundaries or recovered algorithm behavior. "
              "No behavioral equivalence, full 45-SO completion, pixel parity, product Phase PASS, V4 or P7 "
              "readiness is claimed. No production/source edit or fresh import occurred. Independent CEO "
              "review and any commit/push remain pending.\n")
    check_lease()
    (REPORT / "01_MASTER_REPORT.md").write_text(report, encoding="utf-8")
    code = {p.relative_to(ROOT).as_posix(): sha(p) for p in sorted((ROOT / "scripts/task_210_ceo_mt_oversized").glob("*")) if p.is_file()}
    files = {p.relative_to(REPORT).as_posix(): sha(p) for p in sorted(REPORT.rglob("*"))
             if p.is_file() and p.name not in {"COMPLETE.json", "PROGRESS.json", "PROGRESS.md"}}
    manifest = {"schema_version": "2.1.2", "task_id": "TASK_210", "revision": 1,
                "status": "COMPLETE", "research_result": summary["result"],
                "generated_at": dt.datetime.now(dt.timezone.utc).isoformat(),
                "agent_id": "Codex_CEO", "lease_id": "LEASE-CEO-WORKER-TASK_210-R1",
                "fencing_token": 1248, "standard_path": str(STANDARD),
                "standard_sha256": STANDARD_SHA, "task_sha256": sha(TASK),
                "target_manifest_sha256": TARGETS_SHA, "original_so_sha256": SOURCE_SHA,
                "original_fde_candidate_bodies_verified": 7,
                "original_instruction_words_verified": 10114,
                "effective_ghidra_pcode_instruction_positions": effective_slots,
                "effective_ghidra_pcode_operations": effective_pcode,
                "nonempty_c_like_outputs": summary["nonempty_c_like_rows"],
                "verified_behavior_candidates": 0, "files": files, "code_files": code}
    write_json(REPORT / "COMPLETE.json", manifest)
    print(json.dumps({"files_sealed": len(files), "code_files": len(code), "effective_slots": effective_slots,
                      "pcode_ops": effective_pcode, "complete_sha256": sha(REPORT / "COMPLETE.json")}))


if __name__ == "__main__":
    main()
