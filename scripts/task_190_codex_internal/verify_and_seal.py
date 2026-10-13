"""Verify the exact TASK_190 evidence and seal a bounded review candidate."""
from __future__ import annotations

import hashlib
import json
from collections import Counter
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile

from common import (AGENT_ID, CODE, FENCE, LEASE_ID, MANIFEST, MANIFEST_SHA,
                    PRIOR_PROJECT, PROJECT, REPORT, ROOT, SOURCE, SOURCE_SHA,
                    STANDARD, STANDARD_SHA, TASK_SHA, check_lease, now, sha256,
                    atomic_bytes, write_json)


def file_hashes(folder: Path) -> dict[str, str]:
    return {p.relative_to(folder).as_posix(): sha256(p)
            for p in sorted(folder.rglob("*")) if p.is_file()}


def main() -> None:
    check_lease()
    if (REPORT / "COMPLETE.json").exists():
        raise RuntimeError("existing seal must never be silently overwritten")
    manifest = json.loads(MANIFEST.read_text(encoding="utf-8"))
    targets = manifest["targets"]
    indexed = json.loads((REPORT / "source_index.json").read_text(encoding="utf-8"))
    assembly = [json.loads(line) for line in
                (REPORT / "source_assembly.ndjson").read_text(encoding="utf-8").splitlines()]
    chunks = json.loads((REPORT / "chunk_index.json").read_text(encoding="utf-8"))["chunks"]
    if len(targets) != 128 or len(indexed["targets"]) != 128 or len(assembly) != 128 or len(chunks) != 4:
        raise RuntimeError("target/preflight count mismatch")
    raw = []
    commands = []
    for chunk in chunks:
        folder = REPORT / f"chunk_{chunk['chunk']:02d}"
        receipt = json.loads((folder / "ghidra_command.json").read_text(encoding="utf-8"))
        rows = [json.loads(line) for line in
                (folder / "ghidra_raw.ndjson").read_text(encoding="utf-8").splitlines()]
        if (receipt["status"] != "OUTPUT_READY" or receipt["exit_code"] != 0 or
                receipt["rows"] != len(rows) or len(rows) != 32 or
                receipt["row_indices_match"] is not True or
                receipt["rows_body_bytes_match"] != 32 or
                receipt["elapsed_seconds"] > 1200 or receipt["timeout_seconds"] > 1200 or
                receipt["fresh_imports"] != 0 or receipt["read_only_project"] is not True):
            raise RuntimeError(f"failed bounded Ghidra receipt: {folder}")
        for path_key, name in (("stdout_sha256", "ghidra_stdout.log"),
                               ("stderr_sha256", "ghidra_stderr.log"),
                               ("raw_output_sha256", "ghidra_raw.ndjson"),
                               ("target_tsv_sha256", "targets.tsv")):
            if receipt[path_key] != sha256(folder / name):
                raise RuntimeError(f"Ghidra command/output hash mismatch: {folder}/{name}")
        if receipt["script_sha256"] != sha256(CODE / "ExportInternal190.java"):
            raise RuntimeError(f"Ghidra script version mismatch: {folder}")
        expected = list(range(chunk["start_index"], chunk["end_index"] + 1))
        if [r["index"] for r in rows] != expected:
            raise RuntimeError(f"missing/duplicate candidate in {folder}")
        raw.extend(rows)
        commands.append(receipt)
    if [r["index"] for r in raw] != list(range(1, 129)):
        raise RuntimeError("Ghidra row order mismatch")

    original = SOURCE.read_bytes()
    if hashlib.sha256(original).hexdigest() != SOURCE_SHA:
        raise RuntimeError("original SO changed")
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        if elf["e_machine"] != "EM_AARCH64":
            raise RuntimeError("source architecture changed")
        fdes = sorted((int(x["initial_location"]), int(x["address_range"]))
                      for x in elf.get_dwarf_info().EH_CFI_entries() if isinstance(x, FDE))
        dyn = elf.get_section_by_name(".dynsym")
        export_starts = {int(s["st_value"]) for s in dyn.iter_symbols()
                         if s["st_info"]["type"] == "STT_FUNC" and
                         s["st_shndx"] != "SHN_UNDEF" and int(s["st_size"]) > 0}
        candidates = [(va, size) for va, size in fdes if size > 0 and va not in export_starts]
        loads = [(int(s["p_vaddr"]), int(s["p_offset"]), int(s["p_filesz"]))
                 for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
    if len(fdes) != 753 or len(export_starts) != 81 or len(candidates) != 672:
        raise RuntimeError("ELF FDE/export census changed")
    if [(int(t["elf_va"], 16), t["size_bytes"]) for t in targets] != candidates[256:384]:
        raise RuntimeError("manifest not exact zero-based indices 256..383")

    dis = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    sample = []
    total_slots = 0
    listing_slots = 0
    pcode_slots = 0
    for i, (target, src, asm, row) in enumerate(zip(targets, indexed["targets"], assembly, raw), 1):
        va, size, offset = int(target["elf_va"], 16), int(target["size_bytes"]), int(target["file_offset"], 16)
        if (src["index"], asm["index"], row["index"]) != (i, i, i):
            raise RuntimeError(f"row identity differs: {i}")
        matches = [s for s in loads if s[0] <= va and va + size <= s[0] + s[2]]
        if len(matches) != 1 or matches[0][1] + va - matches[0][0] != offset:
            raise RuntimeError(f"PT_LOAD offset mismatch: {i}")
        body = original[offset:offset + size]
        digest = hashlib.sha256(body).hexdigest()
        if (digest != target["body_sha256"] or digest != src["source_body_sha256"] or
                digest != row["original_body_sha256"] or
                digest != row["copy_memory_body_sha256"] or row["body_bytes_match"] is not True):
            raise RuntimeError(f"original/private memory hash mismatch: {i}")
        slots = size // 4
        instructions = list(dis.disasm(body, va))
        if (len(instructions) != slots or len(asm["instructions"]) != slots or
                row["instruction_slots"] != slots or
                row["instruction_count_observed"] != slots or
                len(row["instructions"]) != slots):
            raise RuntimeError(f"instruction coverage mismatch: {i}")
        dbva = int(row["database_va"], 16)
        for j, ins in enumerate(instructions):
            item = asm["instructions"][j]
            ghidra = row["instructions"][j]
            if (ins.address != va + j * 4 or item["va"] != hex(ins.address) or
                    item["word_le"] != body[j * 4:j * 4 + 4].hex() or
                    item["mnemonic"] != ins.mnemonic or item["operands"] != ins.op_str or
                    int(ghidra.split(":", 1)[0], 16) != dbva + j * 4 or
                    not ghidra.split(":", 1)[1].strip()):
                raise RuntimeError(f"source/Capstone/Ghidra listing mismatch: {i}:{j}")
        if not (0 <= row["pcode_instruction_count"] <= slots and row["pcode_op_count"] >= 0):
            raise RuntimeError(f"invalid p-code count: {i}")
        member, missing, extra = (int(row[k]) for k in
                                  ("fde_member_bytes", "fde_missing_bytes", "extra_body_bytes"))
        if (not 0 <= member <= size or missing != size - member or extra < 0 or
                row["function_body_address_count"] != member + extra):
            raise RuntimeError(f"function-body byte accounting mismatch: {i}")
        missing_intervals = []
        for text in row["fde_missing_ranges"]:
            lo, hi = map(lambda x: int(x, 16), text.split("..", 1))
            if lo < va or hi >= va + size or lo > hi:
                raise RuntimeError(f"invalid missing interval: {i}")
            missing_intervals.append((lo, hi))
        if sum(hi - lo + 1 for lo, hi in missing_intervals) != missing:
            raise RuntimeError(f"missing interval byte sum mismatch: {i}")
        classification = row["boundary_classification"]
        if classification == "GHIDRA_BODY_EQUALS_FDE_RANGE":
            if missing or extra or int(row["function_entry"], 16) != dbva:
                raise RuntimeError(f"false exact FDE body: {i}")
        elif classification == "GHIDRA_BODY_CONTAINS_FDE_WITH_EXTRA_BYTES":
            if missing or extra <= 0:
                raise RuntimeError(f"false extra-body classification: {i}")
        elif classification in ("GHIDRA_BODY_PREFIX_OF_FDE_RANGE",
                                "FDE_HAS_INTERNAL_GAPS_IN_GHIDRA_BODY",
                                "GHIDRA_BODY_MISSES_ENTIRE_FDE_RANGE"):
            if missing <= 0:
                raise RuntimeError(f"false missing-body classification: {i}")
        elif classification == "FDE_START_INSIDE_EXISTING_GHIDRA_FUNCTION":
            if row["fde_start_inside_other_ghidra_function"] is not True:
                raise RuntimeError(f"false overlapping-function classification: {i}")
        else:
            raise RuntimeError(f"unrecognized body classification: {i}: {classification}")
        if row["c_like_present"]:
            if (not row["c_like_text"].strip() or
                    hashlib.sha256(row["c_like_text"].encode("utf-8")).hexdigest() !=
                    row["c_like_sha256"]):
                raise RuntimeError(f"C-like text/hash mismatch: {i}")
        total_slots += slots
        listing_slots += row["instruction_count_observed"]
        pcode_slots += row["pcode_instruction_count"]
        # One distinct source word from every candidate exceeds 10% of this slice.
        j = (i * 37) % slots
        sample.append({"index": i, "slot": j, "source_va": hex(va + j * 4),
                       "source_word_le": body[j * 4:j * 4 + 4].hex(),
                       "capstone": asm["instructions"][j], "ghidra": row["instructions"][j]})
    if len(sample) * 10 < total_slots:
        raise RuntimeError("ordinary source instruction sample below 10%")

    correction_folder = REPORT / "transient_gap_correction"
    correction_path = correction_folder / "results/128_2d8ec.json"
    correction = json.loads(correction_path.read_text(encoding="utf-8"))
    correction_command = json.loads((correction_folder / "ghidra_command.json").read_text(encoding="utf-8"))
    last = targets[-1]
    expected_sha = last["body_sha256"]
    if (correction_command["status"] != "OUTPUT_READY" or
            correction_command["exit_code"] != 0 or
            correction_command["termination"] is not None or
            correction_command["elapsed_seconds"] > 1200 or
            correction_command["timeout_seconds"] > 1200 or
            correction_command["read_only_project"] is not True or
            correction_command["project_file_hashes_unchanged"] is not True or
            correction_command["script_sha256"] != sha256(CODE / "RepairMembership190.java") or
            correction_command["target_tsv_sha256"] != sha256(correction_folder / "anomaly.tsv") or
            correction_command["stdout_sha256"] != sha256(correction_folder / "ghidra_stdout.log") or
            correction_command["stderr_sha256"] != sha256(correction_folder / "ghidra_stderr.log") or
            correction_command["result_sha256"] !=
            {"results/128_2d8ec.json": sha256(correction_path)}):
        raise RuntimeError("transient correction command/log/output provenance differs")
    if (correction["task_id"] != "TASK_190" or correction["revision"] != 1 or
            correction["index"] != 128 or correction["elf_va"] != last["elf_va"] or
            correction["size_bytes"] != last["size_bytes"] or
            correction["memory_sha256"] != expected_sha or
            correction["original_function_fde_membership_count"] != 176 or
            correction["original_function_fde_membership_bits"] != "1" * 176 + "0" * 4 or
            correction["other_function_byte_count"] != 0 or
            correction["temporary_old_function_removed"] is not True or
            correction["temporary_full_fde_function_created"] is not True or
            correction["corrected_function_fde_membership_count"] != 180 or
            correction["corrected_function_fde_membership_bits"] != "1" * 180 or
            correction["corrected_function_body_total_address_count"] != 180 or
            correction["full_fde_instruction_count"] != 45 or
            correction["full_fde_pcode_ops"] <= 0 or
            correction["c_like_nonempty"] is not True or
            not correction["c_like_text"].strip() or correction["error"] or
            correction["memory_unchanged_after_rollback"] is not True or
            len(correction["instruction_pcode"]) != 45):
        raise RuntimeError("transient full-FDE gap correction does not match critical claims")
    base = int(correction["database_va"], 16)
    for j, item in enumerate(correction["instruction_pcode"]):
        if (int(item["database_va"], 16) != base + 4 * j or
                item.get("missing_instruction", False) or
                not item["assembly"].strip() or not isinstance(item["pcode_ops"], list)):
            raise RuntimeError(f"transient correction instruction position differs: {j}")
    if sum(len(x["pcode_ops"]) for x in correction["instruction_pcode"]) != correction["full_fde_pcode_ops"]:
        raise RuntimeError("transient p-code operation count mismatch")

    original_project = file_hashes(PRIOR_PROJECT)
    copied_project = file_hashes(PROJECT)
    prior_receipt = json.loads((REPORT / "project_copy_receipt.json").read_text(encoding="utf-8"))
    if (len(original_project) != 9 or original_project != copied_project or
            prior_receipt["historical_file_sha256"] != original_project or
            prior_receipt["private_copy_file_sha256"] != copied_project):
        raise RuntimeError("prior/private analyzed project changed")
    write_json(REPORT / "project_postrun_receipt.json", {
        "task_id": "TASK_190", "revision": 1, "generated_at": now(),
        "prior_project_path": str(PRIOR_PROJECT), "private_project_path": str(PROJECT),
        "files_verified": len(copied_project), "pre_post_hashes_match": True,
        "file_sha256": copied_project})

    kinds = dict(Counter(r["boundary_classification"] for r in raw))
    c_count = sum(bool(r["c_like_present"]) for r in raw)
    exact_count = sum(r["c_like_present"] and
                      r["boundary_classification"] == "GHIDRA_BODY_EQUALS_FDE_RANGE" for r in raw)
    missing_count = sum(r["fde_missing_bytes"] > 0 for r in raw)
    extra_count = sum(r["extra_body_bytes"] > 0 for r in raw)
    disposition = "BOUNDED_STATIC_FDE_MATCH" if exact_count == 128 else "PARTIAL_STATIC_FDE_BOUNDARY"
    write_json(REPORT / "independent_verification.json", {
        "task_id": "TASK_190", "revision": 1, "generated_at": now(),
        "original_source_sha256": SOURCE_SHA, "all_128_fde_pt_load_body_hashes_checked": True,
        "all_source_capstone_ghidra_listing_positions_checked": total_slots,
        "all_function_body_byte_accounting_rows_checked": 128,
        "all_c_like_text_hashes_checked": c_count,
        "spread_source_instruction_words_checked": len(sample),
        "spread_source_instruction_fraction": len(sample) / total_slots,
        "one_spread_word_from_each_candidate": True,
        "sample": sample, "bounded_process_receipts_verified": 4,
        "transient_correction_command_and_rollback_verified": True,
        "transient_correction_index": 128,
        "transient_correction_c_like_sha256": hashlib.sha256(
            correction["c_like_text"].encode("utf-8")).hexdigest(),
        "prior_project_and_private_copy_hashes_unchanged": len(copied_project)})
    write_json(REPORT / "candidate_index.json", {
        "task_id": "TASK_190", "revision": 1, "target_count": 128,
        "source_instruction_slots": total_slots, "ghidra_instruction_slots": listing_slots,
        "ghidra_pcode_instruction_slots": pcode_slots,
        "ghidra_c_like_count": c_count, "ghidra_exact_fde_c_like_count": exact_count,
        "rows_with_missing_fde_bytes": missing_count, "rows_with_extra_body_bytes": extra_count,
        "boundary_classifications": kinds,
        "candidates": [{k: r[k] for k in (
            "index", "elf_va", "fde_size_bytes", "original_body_sha256",
            "copy_memory_body_sha256", "instruction_slots", "instruction_count_observed",
            "pcode_instruction_count", "pcode_op_count", "function_entry",
            "function_body_address_count", "fde_member_bytes", "fde_missing_bytes",
            "extra_body_bytes", "fde_missing_ranges", "boundary_classification",
            "fde_start_inside_other_ghidra_function", "c_like_present",
            "c_like_sha256", "failure")} for r in raw]})

    audit = f"""# TASK_190 R1 audit index

- Canonical Standard fully read before writes: `{STANDARD}`; SHA-256 `{STANDARD_SHA}`; claim receipt 2026-10-13T11:15:04.309394+00:00.
- Exact ACTIVE task: `RULES/TASK/TASK_190_SO45_CODEX_INTERNAL_ACTIVE.md`; SHA-256 `{TASK_SHA}`.
- Target manifest: `.ai/ceo/reviews/TASK_190_internal_targets.json`; SHA-256 `{MANIFEST_SHA}`; VA-sorted nonexport FDE candidate indices 256..383 only.
- Actual agent/lease/fence: `{AGENT_ID}` / `{LEASE_ID}` / `{FENCE}`.
- Original source: `{SOURCE}`; SHA-256 `{SOURCE_SHA}`.
- `source_index.json` and `source_assembly.ndjson` record exact source bodies and all instruction slots. Four `chunk_XX/` folders preserve raw Ghidra output, target TSVs, command receipts and process logs.
- `transient_gap_correction/` records a separately bounded read-only Ghidra transaction for row 128's four-byte tail gap, with other-function ownership check, full-FDE instruction/p-code/C-like output, rollback, unchanged source-memory SHA and project hashes.
- `project_copy_receipt.json` and `project_postrun_receipt.json` verify the read-only prior analyzed project and private copy. `candidate_index.json` and `independent_verification.json` summarize per-candidate boundaries and spread provenance.
- `COMPLETE.json` hashes every nonvolatile report file and code script; CEO independently reviews before any commit/push. No product or V4 acceptance.
"""
    atomic_bytes(REPORT / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    master = f"""# TASK_190 R1 — bounded PVGColorFunctions internal FDE research

The exact zero-based VA-sorted nonexport FDE candidate slice **256..383** contains **128** ranges in the pinned original `libPVGColorFunctions.so`; the earlier accepted TASK_185/186 slices do not overlap. The full ELF has 753 FDE ranges, 81 defined nonzero-size function-export starts and 672 nonexport FDE candidates. This batch leaves 288 later candidates outside its scope. FDE ranges are unwind metadata and are not proof of unique complete source functions.

All 128 original FDE ranges, PT_LOAD offsets and body SHA-256 values matched the manifest. Capstone decoded **{total_slots:,}/{total_slots:,}** source AArch64 instruction slots. The previous analyzed Ghidra project was copied into private scratch, 9/9 file hashes matched before and after, and no new binary import ran. Four sequential read-only headless processes used `-max-cpu 1`, a 1 GiB configured heap and <=20-minute process caps; raw command/log/output files are retained.

Ghidra memory SHA matched the original body for 128/128 rows. Listing coverage is **{listing_slots:,}/{total_slots:,}** instruction slots and p-code appears on **{pcode_slots:,}/{total_slots:,}** slots. C-like text exists for **{c_count}/128** original Ghidra function objects; **{exact_count}/128** have whole-byte Ghidra body membership exactly equal to the respective FDE range. **{missing_count}** original row has missing FDE bytes and **{extra_count}** have extra Ghidra body bytes; categories may overlap. Classifications: `{kinds}`. The original row 128 body stops at 0x2d99b and omits the final four bytes 0x2d99c..0x2d99f. A separate read-only, rollback-only Ghidra transaction verified no other-function ownership in that gap and temporarily produced 180/180 full-FDE body bytes, 45/45 instructions, {correction['full_fde_pcode_ops']} p-code operations and nonempty C-like text. Its original 176/180 boundary limitation is retained as raw evidence. Full per-row C-like strings/hashes, instruction listings, p-code counts, call text, body intervals and failures are in the raw NDJSON and transient correction files.

The task verifier rechecked all critical source/PT_LOAD/body, Ghidra memory-hash, byte-membership and C-like-hash claims. It re-decoded all {total_slots:,} source words and compared all {listing_slots:,} recorded Ghidra listing addresses. Its 128 distinct spread source-word checks cover **{len(sample)/total_slots:.2%}** of ordinary instruction positions, one sampled slot from every candidate; `independent_verification.json` records each sample.

Research disposition: **{disposition}** for the original analyzed project, with one separately verified transient full-FDE correction. This is static evidence for this exact candidate slice; dynamic behavior, call semantics, pixel parity, product Phase PASS, V4 and completion of 45 SOs were not established. `PROJECT_ERROR.md` and `ACQUIREMENTS.md` were consulted; this lease does not allow edits to them. No AGY, self-review, commit or push was used.
"""
    atomic_bytes(REPORT / "01_MASTER_REPORT.md", master.encode("utf-8"))
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_190", "revision": 1,
        "status": "SEALED_REVIEW_CANDIDATE", "generated_at": now(),
        "agent_id": AGENT_ID, "lease_id": LEASE_ID, "fencing_token": FENCE,
        "target_rows_processed": 128, "source_instruction_slots": total_slots,
        "ghidra_instruction_slots": listing_slots, "ghidra_c_like_rows": c_count,
        "ghidra_exact_fde_c_like_rows": exact_count, "research_disposition": disposition})

    check_lease()
    reports = {p.relative_to(REPORT).as_posix(): sha256(p)
               for p in sorted(REPORT.rglob("*")) if p.is_file() and
               p.name not in ("PROGRESS.json", "COMPLETE.json")}
    code = {p.relative_to(ROOT).as_posix(): sha256(p)
            for p in sorted(CODE.rglob("*")) if p.is_file()}
    total_bytes = sum((REPORT / rel).stat().st_size for rel in reports)
    if total_bytes > 134217728:
        raise RuntimeError("report exceeds 128 MiB cap")
    complete = {"schema_version": "2.1.2", "task_id": "TASK_190", "revision": 1,
        "status": "COMPLETE", "review_status": "REVIEW_CANDIDATE_AWAITING_CEO",
        "research_disposition": disposition, "generated_at": now(),
        "agent_id": AGENT_ID, "lease_id": LEASE_ID, "fencing_token": FENCE,
        "standard_sha256": STANDARD_SHA, "task_sha256": TASK_SHA,
        "target_manifest_sha256": MANIFEST_SHA, "original_so_sha256": SOURCE_SHA,
        "target_fde_candidate_count": 128, "source_instruction_slots": total_slots,
        "ghidra_instruction_slots": listing_slots, "ghidra_pcode_instruction_slots": pcode_slots,
        "ghidra_c_like_count": c_count, "ghidra_exact_fde_c_like_count": exact_count,
        "rows_with_missing_fde_bytes": missing_count, "rows_with_extra_body_bytes": extra_count,
        "transient_corrected_full_fde_rows": 1,
        "transient_correction_row": 128,
        "transient_correction_c_like_sha256": hashlib.sha256(
            correction["c_like_text"].encode("utf-8")).hexdigest(),
        "spread_source_instruction_words": len(sample), "spread_source_instruction_fraction": len(sample)/total_slots,
        "ghidra_processes": len(commands) + 1, "fresh_imports": 0,
        "product_phase_pass": False, "behavior_equivalence_tested": False,
        "commit_sha": None, "push_receipt": None,
        "report_bytes_excluding_progress_and_seal": total_bytes,
        "files": reports, "code_files": code, "scratch_project_files": copied_project}
    write_json(REPORT / "COMPLETE.json", complete)
    print(json.dumps({"status": "SEALED", "complete_sha256": sha256(REPORT / "COMPLETE.json"),
                      "source_slots": total_slots, "c_like": c_count,
                      "exact_fde_c_like": exact_count, "sample_words": len(sample),
                      "report_file_count": len(reports), "code_file_count": len(code)}))


if __name__ == "__main__":
    main()
