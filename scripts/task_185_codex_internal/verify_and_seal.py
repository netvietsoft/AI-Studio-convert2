"""Independently verify source/Ghidra evidence and seal the bounded research package."""
from __future__ import annotations

import hashlib
import json
from pathlib import Path

from common import (AGENT_ID, CODE, FENCE, LEASE_ID, MANIFEST, MANIFEST_SHA,
                    PRIOR_PROJECT, PROJECT, REPORT, ROOT, SOURCE, SOURCE_SHA,
                    STANDARD, STANDARD_SHA, TASK_SHA, check_lease, now, sha256,
                    atomic_bytes, write_json)


def hashes(folder: Path) -> dict[str, str]:
    return {p.relative_to(folder).as_posix(): sha256(p) for p in sorted(folder.rglob("*")) if p.is_file()}


def main() -> None:
    check_lease()
    if sha256(SOURCE) != SOURCE_SHA:
        raise RuntimeError("original source changed")
    if (REPORT / "COMPLETE.json").exists():
        raise RuntimeError("a final seal already exists; do not silently overwrite")
    targets = json.loads(MANIFEST.read_text(encoding="utf-8"))["targets"]
    source_index = json.loads((REPORT / "source_index.json").read_text(encoding="utf-8"))
    assembly = [json.loads(line) for line in (REPORT / "source_assembly.ndjson").read_text(encoding="utf-8").splitlines()]
    rows = [json.loads(line) for path in sorted(REPORT.glob("chunk_*/ghidra_raw.ndjson"))
            for line in path.read_text(encoding="utf-8").splitlines()]
    if len(targets) != 128 or len(source_index["targets"]) != 128 or len(rows) != 128 or len(assembly) != 128:
        raise RuntimeError("candidate row count mismatch")
    if [row["index"] for row in rows] != list(range(1, 129)):
        raise RuntimeError("raw Ghidra rows not exactly 1..128")
    commands = [json.loads(p.read_text(encoding="utf-8")) for p in sorted(REPORT.glob("chunk_*/ghidra_command.json"))]
    if len(commands) != 4 or any(c["status"] != "OUTPUT_READY" or c["rows"] != 32 or
                              c["rows_body_bytes_match"] != 32 or c["exit_code"] != 0 for c in commands):
        raise RuntimeError("raw command receipts do not prove four bounded completed chunks")
    if any(c["elapsed_seconds"] > 1200 or c["timeout_seconds"] > 1200 or
           c["fresh_imports"] != 0 or not c["read_only_project"] for c in commands):
        raise RuntimeError("execution bounds/provenance violated")
    source_bytes = SOURCE.read_bytes()
    for ix, (target, indexed, raw) in enumerate(zip(targets, source_index["targets"], rows), 1):
        offset, size = int(target["file_offset"], 16), target["size_bytes"]
        digest = hashlib.sha256(source_bytes[offset:offset + size]).hexdigest()
        if (indexed["index"] != ix or raw["index"] != ix or
                indexed["elf_va"] != target["elf_va"] or raw["elf_va"] != target["elf_va"] or
                indexed["size_bytes"] != size or raw["fde_size_bytes"] != size or
                indexed["source_body_sha256"] != digest or target["body_sha256"] != digest or
                raw["original_body_sha256"] != digest or raw["copy_memory_body_sha256"] != digest or
                raw["body_bytes_match"] is not True):
            raise RuntimeError(f"original/private body evidence mismatch at row {ix}")
        if raw["instruction_slots"] != size // 4 or raw["instruction_count_observed"] != size // 4:
            raise RuntimeError(f"Ghidra instruction coverage mismatch at row {ix}")
        if not 0 <= raw["pcode_instruction_count"] <= raw["instruction_slots"]:
            raise RuntimeError(f"invalid p-code coverage row {ix}")
        if raw["c_like_present"]:
            c_sha = hashlib.sha256(raw["c_like_text"].encode("utf-8")).hexdigest()
            if not raw["c_like_text"].strip() or c_sha != raw["c_like_sha256"]:
                raise RuntimeError(f"C-like text/hash mismatch row {ix}")

    project_receipt = json.loads((REPORT / "project_copy_receipt.json").read_text(encoding="utf-8"))
    historical_hashes = hashes(PRIOR_PROJECT)
    private_hashes = hashes(PROJECT)
    if not (historical_hashes == private_hashes == project_receipt["historical_file_sha256"] ==
            project_receipt["private_copy_file_sha256"]) or len(private_hashes) != 9:
        raise RuntimeError("Ghidra project copied/processed byte hashes changed")
    write_json(REPORT / "project_postrun_receipt.json", {"task_id": "TASK_185", "revision": 1,
        "historical_task": "TASK_168", "original_project_path": str(PRIOR_PROJECT),
        "owned_copy_path": str(PROJECT), "file_count": len(private_hashes),
        "pre_post_and_historical_hashes_match": True, "file_sha256": private_hashes,
        "generated_at": now()})

    selected_indices = sorted({1 + round(i * 127 / 15) for i in range(16)})
    samples = []
    for ix in selected_indices:
        target, raw, dis = targets[ix - 1], rows[ix - 1], assembly[ix - 1]
        va, size, offset = int(target["elf_va"], 16), target["size_bytes"], int(target["file_offset"], 16)
        slots = size // 4
        if dis["index"] != ix or len(dis["instructions"]) != slots or len(raw["instructions"]) != slots:
            raise RuntimeError(f"sample row instruction count differs {ix}")
        for slot in sorted({0, slots // 2, slots - 1}):
            item = dis["instructions"][slot]
            word = source_bytes[offset + 4 * slot:offset + 4 * slot + 4].hex()
            ghidra_text = raw["instructions"][slot]
            ghidra_va = int(ghidra_text.split(":", 1)[0], 16)
            if (item["va"] != hex(va + slot * 4) or item["word_le"] != word or
                    ghidra_va != int(raw["database_va"], 16) + slot * 4):
                raise RuntimeError(f"spread instruction source/Capstone/Ghidra mismatch: {ix}:{slot}")
            samples.append({"index": ix, "slot": slot, "elf_va": item["va"],
                            "original_word_le": word, "capstone_mnemonic": item["mnemonic"],
                            "capstone_operands": item["operands"], "ghidra_text": ghidra_text})
    write_json(REPORT / "independent_verification.json", {"task_id": "TASK_185", "revision": 1,
        "generated_at": now(), "original_source_sha256": SOURCE_SHA,
        "every_target_body_rehashed": 128, "every_private_memory_body_hash_checked": 128,
        "spread_candidate_indices": selected_indices, "spread_candidate_count": len(selected_indices),
        "spread_candidate_fraction": len(selected_indices) / 128,
        "spread_instruction_word_count": len(samples), "sampled_instruction_words": samples,
        "historical_and_private_project_files_unchanged": len(private_hashes),
        "all_four_ghidra_process_receipts_verified": True})

    boundary = {}
    for row in rows:
        key = row["boundary_classification"]
        boundary[key] = boundary.get(key, 0) + 1
    c_like_count = sum(row["c_like_present"] for row in rows)
    exact_c_like = sum(row["c_like_present"] and row["boundary_classification"] ==
                       "GHIDRA_BODY_EQUALS_FDE_RANGE" for row in rows)
    instruction_total = sum(row["instruction_slots"] for row in rows)
    instruction_observed = sum(row["instruction_count_observed"] for row in rows)
    pcode_instructions = sum(row["pcode_instruction_count"] for row in rows)
    index = [{"index": row["index"], "elf_va": row["elf_va"], "fde_size_bytes": row["fde_size_bytes"],
              "original_body_sha256": row["original_body_sha256"],
              "copy_memory_body_sha256": row["copy_memory_body_sha256"],
              "instruction_slots": row["instruction_slots"],
              "instruction_count_observed": row["instruction_count_observed"],
              "pcode_instruction_count": row["pcode_instruction_count"],
              "pcode_op_count": row["pcode_op_count"],
              "boundary_classification": row["boundary_classification"],
              "function_metadata_created_in_owned_copy": row["function_metadata_created_in_owned_copy"],
              "c_like_present": row["c_like_present"], "c_like_sha256": row["c_like_sha256"],
              "failure": row["failure"]} for row in rows]
    write_json(REPORT / "candidate_index.json", {"task_id": "TASK_185", "revision": 1,
        "target_count": 128, "c_like_ghidra_function_count": c_like_count,
        "c_like_exact_fde_boundary_count": exact_c_like,
        "not_exact_fde_boundary_count": 128 - exact_c_like, "boundary_classifications": boundary,
        "original_source_instruction_slots": instruction_total,
        "ghidra_instruction_slots_observed": instruction_observed,
        "ghidra_pcode_instruction_slots": pcode_instructions,
        "function_metadata_created_in_owned_copy": sum(row["function_metadata_created_in_owned_copy"] for row in rows),
        "candidates": index})

    audit = f"""# TASK_185 R1 audit index

- Canonical Standard fully read before writes: `{STANDARD}`; SHA-256 `{STANDARD_SHA}`; read/claim acknowledged 2026-10-13T09:43:48.007790+00:00.
- Exact ACTIVE task: `RULES/TASK/TASK_185_SO45_CODEX_INTERNAL_ACTIVE.md`; SHA-256 `{TASK_SHA}`.
- Target manifest: `.ai/ceo/reviews/TASK_185_internal_targets.json`; SHA-256 `{MANIFEST_SHA}`; exact first 128 VA-sorted nonexport FDE starts only.
- Actual agent/lease/fence: `{AGENT_ID}` / `{LEASE_ID}` / `{FENCE}`.
- Original source: `{SOURCE}`; SHA-256 `{SOURCE_SHA}`.
- Raw files: `source_index.json`, `source_assembly.ndjson`, `project_copy_receipt.json`, `project_postrun_receipt.json`, four `chunk_XX/targets.tsv`, four `chunk_XX/ghidra_command.json`, four stdout/stderr pairs, four `ghidra_raw.ndjson` files, `candidate_index.json`, and `independent_verification.json`.
- C-like strings and hashes are in each raw Ghidra NDJSON row; `candidate_index.json` links all 128 addresses and boundary classifications.
- `COMPLETE.json` hashes every nonvolatile report file plus all task-owned scripts; CEO performs independent review. No self-ack or commit/push.
"""
    atomic_bytes(REPORT / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    report = f"""# TASK_185 R1 — bounded nonexport FDE candidate research

This batch processed all **128/128** exact VA-sorted candidates in the Chairman/CEO-pinned target manifest for original `libPVGColorFunctions.so`. Every candidate range is an `.eh_frame` FDE start absent from 81 defined nonzero-size `.dynsym` function export VAs. This is a bounded candidate batch, not an internal-function census: the manifest leaves 544 other nonexport FDE candidates unselected, and FDE starts alone do not prove exact function boundaries.

All 128 original body ranges were independently matched to ELF FDE start/range, PT_LOAD file offset and SHA-256. Source Capstone decoded {instruction_total:,}/{instruction_total:,} AArch64 instruction slots. The prior TASK_168 analyzed Ghidra project was copied into private TASK_185 scratch with 9/9 historical/copy file hashes matching before and after the run; no fresh import occurred. Four sequential Ghidra processes ran with `-max-cpu 1`, 1 GiB configured heap and <=20-minute process caps. Raw command/output/logs are retained.

Ghidra memory matched the original body SHA in **128/128** rows. Listing instructions cover **{instruction_observed:,}/{instruction_total:,}** slots and p-code is present for **{pcode_instructions:,}/{instruction_total:,}** slots. C-like text exists for **{c_like_count}/128** Ghidra functions. Only **{exact_c_like}/128** Ghidra function bodies exactly equal the pinned FDE ranges; the other **{128-exact_c_like}/128** are classified `GHIDRA_BODY_DOES_NOT_COVER_FDE_RANGE`, so their C-like text is boundary-limited and cannot be claimed as full-FDE recovery. No function metadata was created by this script; the copied analyzed project already had entries at all 128 starts. Detailed per-candidate ranges, failures, p-code counts, source/copy hashes and C-like hashes are in `candidate_index.json` and raw chunk NDJSON.

Independent verifier rehashed every original body and compared the Ghidra memory digest for every row. It also sampled {len(selected_indices)}/128 candidates ({100*len(selected_indices)/128:.1f}%) spread across the full VA-sorted batch and checked {len(samples)} first/middle/last instruction words against original bytes, Capstone source assembly and Ghidra listing addresses. Evidence is in `independent_verification.json`.

Disposition: **PARTIAL_STATIC_FDE_BOUNDARY** for full-FDE C-like recovery. Source bytes, instruction coverage, p-code presence and C-like decompiler text are separate evidence levels. No dynamic execution, pixel/behavioral equivalence, product Phase PASS, V4 implementation, or all-45-SO completion is claimed. Scope and research package are complete for these exact 128 rows; remaining boundary ambiguity and 544 unselected candidates require separate CEO decisions/tasks. `PROJECT_ERROR.md`/`ACQUIREMENTS.md` were consulted; this task did not have write scope to modify them. No commit or push was made pending CEO review.
"""
    atomic_bytes(REPORT / "01_MASTER_REPORT.md", report.encode("utf-8"))
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_185", "revision": 1,
        "status": "SEALED_REVIEW_CANDIDATE", "generated_at": now(), "agent_id": AGENT_ID,
        "lease_id": LEASE_ID, "fencing_token": FENCE, "target_rows_processed": 128,
        "source_and_ghidra_body_hashes_verified": 128, "c_like_ghidra_function_rows": c_like_count,
        "c_like_exact_fde_boundary_rows": exact_c_like,
        "research_disposition": "PARTIAL_STATIC_FDE_BOUNDARY"})

    check_lease()
    report_files = {p.relative_to(REPORT).as_posix(): sha256(p)
                    for p in sorted(REPORT.rglob("*")) if p.is_file() and
                    p.name not in ("PROGRESS.json", "COMPLETE.json")}
    code_files = {p.relative_to(ROOT).as_posix(): sha256(p)
                  for p in sorted(CODE.rglob("*")) if p.is_file()}
    scratch_files = {p.relative_to(ROOT).as_posix(): sha256(p)
                     for p in sorted(PROJECT.rglob("*")) if p.is_file()}
    total_report_bytes = sum((REPORT / rel).stat().st_size for rel in report_files)
    if total_report_bytes > 134217728:
        raise RuntimeError("report exceeds 128 MiB task cap")
    complete = {"schema_version": "2.1.2", "task_id": "TASK_185", "revision": 1,
        "status": "COMPLETE", "research_disposition": "PARTIAL_STATIC_FDE_BOUNDARY",
        "review_status": "REVIEW_CANDIDATE_AWAITING_CEO", "generated_at": now(),
        "agent_id": AGENT_ID, "lease_id": LEASE_ID, "fencing_token": FENCE,
        "standard_sha256": STANDARD_SHA, "task_sha256": TASK_SHA,
        "target_manifest_sha256": MANIFEST_SHA, "original_so_sha256": SOURCE_SHA,
        "target_fde_candidate_count": 128, "original_body_hashes_verified": 128,
        "ghidra_memory_body_hashes_verified": 128,
        "source_instruction_slots": instruction_total,
        "ghidra_instruction_slots_observed": instruction_observed,
        "ghidra_pcode_instruction_slots": pcode_instructions,
        "ghidra_c_like_function_count": c_like_count,
        "exact_fde_boundary_c_like_count": exact_c_like,
        "not_exact_fde_boundary_count": 128 - exact_c_like,
        "spread_verification_candidates": len(selected_indices),
        "spread_verification_instruction_words": len(samples),
        "fresh_imports": 0, "product_phase_pass": False,
        "behavior_equivalence_tested": False, "commit_sha": None, "push_receipt": None,
        "report_bytes_excluding_progress_and_seal": total_report_bytes,
        "files": report_files, "code_files": code_files, "scratch_project_files": scratch_files}
    write_json(REPORT / "COMPLETE.json", complete)
    print(json.dumps({"status": "SEALED", "complete_sha256": sha256(REPORT / "COMPLETE.json"),
                      "report_file_count": len(report_files), "code_file_count": len(code_files),
                      "c_like": c_like_count, "exact_fde_c_like": exact_c_like,
                      "spread_candidates": len(selected_indices), "spread_words": len(samples),
                      "report_bytes": total_report_bytes}))


if __name__ == "__main__":
    main()
