"""Verify R2 body membership/source provenance and seal correction for CEO review."""

from __future__ import annotations

import hashlib
import json
import struct
from datetime import datetime, timezone
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile

from common import (AGENT, CEO_REVIEW, FENCE, LEASE, ORIGINAL_PROJECT,
                    OWN_PROJECT, R1_REPORT, R1_SEAL_SHA, REPORT, ROOT, SCRATCH,
                    SCRIPTS, SOURCE, SOURCE_SHA, STANDARD_SHA, TARGETS, TARGETS_SHA,
                    TASK_SHA, atomic_bytes, guard, now, sha, write_json)


def project_hashes(project: Path) -> dict[str, str]:
    return {p.relative_to(project).as_posix(): sha(p)
            for p in sorted(project.rglob("*")) if p.is_file()}


def unwind_starts(data: bytes, elf: ELFFile) -> set[int]:
    ph = [seg for seg in elf.iter_segments() if seg["p_type"] == "PT_GNU_EH_FRAME"]
    if len(ph) != 1:
        raise RuntimeError("GNU EH frame header count changed")
    seg = ph[0]
    offset = int(seg["p_offset"])
    va = int(seg["p_vaddr"])
    if data[offset:offset + 4] != bytes((1, 0x1B, 0x03, 0x3B)):
        raise RuntimeError("GNU EH frame encoding changed")
    count = struct.unpack_from("<I", data, offset + 8)[0]
    if count != 1027 or int(seg["p_filesz"]) != 12 + count * 8:
        raise RuntimeError("GNU EH frame count/length changed")
    return {va + struct.unpack_from("<i", data, offset + 12 + 8 * i)[0]
            for i in range(count)}


def main() -> None:
    guard()
    if (REPORT / "COMPLETE.json").exists():
        raise RuntimeError("TASK_184 R2 already sealed")
    target = json.loads(TARGETS.read_text(encoding="utf-8"))
    pinned = target["targets"]
    if len(pinned) != 141:
        raise RuntimeError("pin count changed")
    r1_seal = json.loads((R1_REPORT / "COMPLETE.json").read_text(encoding="utf-8"))
    r1_reference = json.loads((REPORT / "r1_reference_receipt.json").read_text(encoding="utf-8"))
    if sha(R1_REPORT / "COMPLETE.json") != R1_SEAL_SHA:
        raise RuntimeError("R1 seal changed")
    raw_path = REPORT / "body_membership.ndjson"
    raw_rows = [json.loads(line) for line in raw_path.read_text(encoding="utf-8").splitlines()]
    command = json.loads((REPORT / "ghidra_command.json").read_text(encoding="utf-8"))
    if (command["status"] != "OUTPUT_READY" or command["output_sha256"] != sha(raw_path)
        or command["stdout_sha256"] != sha(REPORT / "ghidra_stdout.log")
        or command["stderr_sha256"] != sha(REPORT / "ghidra_stderr.log")):
        raise RuntimeError("R2 raw Ghidra evidence/command not complete")
    if len(raw_rows) != 141 or [x["index"] for x in raw_rows] != list(range(1, 142)):
        raise RuntimeError("R2 body rows not complete and ordered")
    if command["observed"]["exact_body_rows"] != 135 or command["observed"]["nonexact_body_rows"] != 6:
        raise RuntimeError("Ghidra receipt count mismatch")
    ceo_rows = [json.loads(line) for line in
                (ROOT / ".ai/ceo/reviews/TASK_184_CEO_REPLAY/body_ranges.ndjson")
                .read_text(encoding="utf-8").splitlines()]
    if len(ceo_rows) != 141:
        raise RuntimeError("CEO replay body row count changed")
    source = SOURCE.read_bytes()
    if hashlib.sha256(source).hexdigest() != SOURCE_SHA:
        raise RuntimeError("original SO changed")
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        starts = unwind_starts(source, elf)
        loads = [seg for seg in elf.iter_segments() if seg["p_type"] == "PT_LOAD"
                 and int(seg["p_flags"]) & 1]
    if len(starts) != 1027:
        raise RuntimeError("unwind starts not unique")

    r1_assembly = {row["index"]: row for row in
                   (json.loads(line) for line in
                    (R1_REPORT / "source/assembly.ndjson").read_text(encoding="utf-8").splitlines())}
    if len(r1_assembly) != 141:
        raise RuntimeError("R1 original-byte assembly rows missing")
    sample_indices = sorted({1 + round(i * 140 / 19) for i in range(20)})
    if len(sample_indices) != 20:
        raise RuntimeError("spread sample not 20 distinct candidates")
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    decoder.skipdata = True
    sample = []
    missing_details = []
    coverage_rows = []
    corrected_candidates = []
    all_body_bytes = 0
    all_member_bytes = 0
    all_slots = 0
    all_missing_slots = 0
    for ordinal, (pin, body_row, ceo_row) in enumerate(zip(pinned, raw_rows, ceo_rows), 1):
        va = int(pin["elf_va"], 16)
        size = int(pin["size_bytes"])
        offset = int(pin["file_offset"], 16)
        expected = pin["body_sha256"]
        if va not in starts:
            raise RuntimeError(f"candidate {ordinal} FDE header start absent")
        load = next((seg for seg in loads if int(seg["p_vaddr"]) <= va
                     and va + size <= int(seg["p_vaddr"]) + int(seg["p_filesz"])
                     and offset == int(seg["p_offset"]) + va - int(seg["p_vaddr"])), None)
        if load is None:
            raise RuntimeError(f"candidate {ordinal} executable PT_LOAD mapping absent")
        original_body = source[offset:offset + size]
        if len(original_body) != size or hashlib.sha256(original_body).hexdigest() != expected:
            raise RuntimeError(f"candidate {ordinal} original body hash mismatch")
        if (body_row["index"] != ordinal or body_row["elf_va"] != pin["elf_va"]
            or body_row["fde_size_bytes"] != size
            or body_row["original_file_offset"] != pin["file_offset"]
            or body_row["expected_original_body_sha256"] != expected
            or body_row["owned_project_memory_sha256"] != expected
            or body_row["body_member_bytes_within_fde"] + body_row["body_missing_bytes_within_fde"] != size
            or body_row["missing_instruction_slots"] * 4 != body_row["body_missing_bytes_within_fde"]
            or body_row["body_extra_bytes_outside_fde"] != 0):
            raise RuntimeError(f"candidate {ordinal} R2 body membership inconsistent")
        if (ceo_row["index"] != ordinal or ceo_row["body_equals_fde"] != body_row["body_equals_fde"]
            or ceo_row["body_num_addresses"] != body_row["body_num_addresses"]
            or ceo_row["body_contains_fde"] != body_row["body_contains_fde"]):
            raise RuntimeError(f"candidate {ordinal} disagrees with independent CEO replay")
        r1_chunk = (ordinal - 1) // 47 + 1
        r1_path = R1_REPORT / "ghidra" / f"chunk_{r1_chunk:02d}" / "candidates" / f"candidate_{ordinal:03d}.json"
        r1_rel = r1_path.relative_to(R1_REPORT).as_posix()
        if r1_reference["r1_141_candidate_file_sha256"].get(r1_rel) != sha(r1_path):
            raise RuntimeError(f"R1 candidate {ordinal} changed")
        r1_row = json.loads(r1_path.read_text(encoding="utf-8"))
        if (r1_row["index"] != ordinal or r1_row["owned_project_memory_sha256"] != expected
            or r1_row["pseudocode_sha256"] != hashlib.sha256(r1_row["pseudocode"].encode("utf-8")).hexdigest()
            or not r1_row["decompile_success"]):
            raise RuntimeError(f"R1 candidate {ordinal} content invalid")

        checked_missing = []
        for miss in body_row["missing_instructions"]:
            miss_va = int(miss["elf_va"], 16)
            miss_offset = int(miss["original_file_offset"], 16)
            if not (va <= miss_va < va + size) or miss_offset != offset + miss_va - va:
                raise RuntimeError(f"candidate {ordinal} missing-slot address outside body")
            word = source[miss_offset:miss_offset + 4]
            if word.hex() != miss["word_le"] or hashlib.sha256(word).hexdigest() != miss["word_sha256"]:
                raise RuntimeError(f"candidate {ordinal} missing word differs from original SO")
            ins = list(decoder.disasm(word, miss_va))
            mnemonic = ins[0].mnemonic if len(ins) == 1 and ins[0].size == 4 else "UNDECODED_WORD"
            checked_missing.append({**miss, "independent_capstone_mnemonic": mnemonic})
        if len(checked_missing) != body_row["missing_instruction_slots"]:
            raise RuntimeError(f"candidate {ordinal} missing-slot count mismatch")
        if checked_missing:
            missing_details.append({"index": ordinal, "elf_va": pin["elf_va"],
                                    "fde_size_bytes": size,
                                    "missing_bytes": body_row["body_missing_bytes_within_fde"],
                                    "missing_instructions": checked_missing})
        if ordinal in sample_indices:
            assembly = r1_assembly[ordinal]
            if len(assembly["instructions"]) != size // 4 or assembly["body_sha256"] != expected:
                raise RuntimeError(f"candidate {ordinal} R1 source assembly mismatch")
            independent = list(decoder.disasm(original_body, va))
            if len(independent) != size // 4 or sum(ins.size for ins in independent) != size:
                raise RuntimeError(f"candidate {ordinal} independent instruction coverage mismatch")
            for slot, (ins, row_ins) in enumerate(zip(independent, assembly["instructions"])):
                word = original_body[slot * 4:slot * 4 + 4]
                if (row_ins["word_le"] != word.hex() or int(row_ins["va"], 16) != ins.address
                    or row_ins["mnemonic"] != ins.mnemonic or row_ins["operands"] != ins.op_str):
                    raise RuntimeError(f"candidate {ordinal} independent instruction mismatch slot {slot}")
            sample.append({"index": ordinal, "elf_va": pin["elf_va"],
                           "body_sha256": expected, "instruction_words_verified": len(independent),
                           "first_word_le": original_body[:4].hex(),
                           "last_word_le": original_body[-4:].hex()})

        scope = "FULL_PINNED_FDE_BODY" if body_row["body_equals_fde"] else "BOUNDARY_LIMITED_GHIDRA_BODY"
        classification = "" if body_row["body_equals_fde"] else "GHIDRA_FUNCTION_BODY_EXCLUDES_PINNED_FDE_BYTES"
        corrected = {"index": ordinal, "elf_va": pin["elf_va"],
                     "fde_size_bytes": size, "original_body_sha256": expected,
                     "r1_candidate_path": str(r1_path.relative_to(ROOT)).replace("\\", "/"),
                     "r1_candidate_sha256": sha(r1_path),
                     "r1_c_like_sha256": r1_row["pseudocode_sha256"],
                     "r1_c_like_present": bool(r1_row["pseudocode"].strip()),
                     "r2_body_member_bytes": body_row["body_member_bytes_within_fde"],
                     "r2_body_missing_bytes": body_row["body_missing_bytes_within_fde"],
                     "r2_missing_instruction_slots": body_row["missing_instruction_slots"],
                     "r2_body_equals_fde": body_row["body_equals_fde"],
                     "boundary_ambiguity": classification, "c_like_scope": scope,
                     "behavior_verified": False}
        corrected_candidates.append(corrected)
        coverage_rows.append({**corrected,
                              "ghidra_listing_instruction_slots": r1_row["instruction_count"],
                              "ghidra_listing_pcode_slots": r1_row["pcode_instruction_slots"],
                              "ghidra_listing_pcode_ops": r1_row["pcode_op_count"],
                              "source_executable_pt_load_verified": True,
                              "source_fde_header_start_verified": True,
                              "owned_project_memory_sha256": body_row["owned_project_memory_sha256"]})
        all_body_bytes += size
        all_member_bytes += body_row["body_member_bytes_within_fde"]
        all_slots += size // 4
        all_missing_slots += body_row["missing_instruction_slots"]

    if (len(sample) != 20 or len(missing_details) != 6 or
        [r["index"] for r in missing_details] != [8, 14, 17, 46, 95, 96]):
        raise RuntimeError("spread sample or nonexact set changed")
    row96 = raw_rows[95]
    miss96 = row96["missing_instructions"]
    if (row96["fde_size_bytes"] != 436 or row96["body_num_addresses"] != 392
        or row96["body_missing_bytes_within_fde"] != 44
        or len(miss96) != 11 or [int(x["elf_va"], 16) for x in miss96]
        != list(range(0x5D868, 0x5D894, 4))):
        raise RuntimeError("candidate 96 exact interior gap differs")
    if (all_body_bytes, all_member_bytes, all_slots, all_missing_slots) != (30644, 30408, 7661, 59):
        raise RuntimeError("aggregate body membership totals differ")
    project_copy = json.loads((REPORT / "project_copy_receipt.json").read_text(encoding="utf-8"))
    if project_copy["copied_file_sha256"] != project_hashes(OWN_PROJECT):
        raise RuntimeError("owned project changed during read-only membership pass")
    original = project_hashes(ORIGINAL_PROJECT)
    if {name.replace("Task158", "Task184R2", 1): digest for name, digest in original.items()} != project_copy["copied_file_sha256"]:
        raise RuntimeError("original analyzed project changed")
    counts = {"pinned_candidates": 141, "source_pt_load_body_hashes_reverified": 141,
              "source_fde_header_starts_reverified": 141, "owned_project_memory_hashes_matched": 141,
              "assembly_slots_in_pinned_fdes": 7661,
              "ghidra_listing_instruction_slots_from_immutable_r1": 7661,
              "ghidra_listing_pcode_slots_from_immutable_r1": 7396,
              "ghidra_listing_pcode_ops_from_immutable_r1": 23977,
              "r1_nonempty_c_like_texts": 141,
              "c_like_texts_with_full_fde_ghidra_body_membership": 135,
              "c_like_texts_boundary_limited": 6,
              "full_fde_ghidra_body_membership_rows": 135,
              "nonexact_ghidra_body_membership_rows": 6,
              "fde_original_body_bytes": all_body_bytes,
              "ghidra_function_body_member_bytes_within_fdes": all_member_bytes,
              "ghidra_function_body_missing_bytes_within_fdes": all_body_bytes - all_member_bytes,
              "ghidra_function_body_member_instruction_slots_within_fdes": all_slots - all_missing_slots,
              "ghidra_function_body_missing_instruction_slots_within_fdes": all_missing_slots,
              "candidate_96_missing_interior_bytes": 44,
              "candidate_96_missing_interior_instruction_slots": 11,
              "spread_candidates_reverified": len(sample),
              "spread_instruction_words_reverified": sum(x["instruction_words_verified"] for x in sample),
              "fresh_imports": 0, "r2_ghidra_processes": 1,
              "r2_ghidra_process_seconds": command["elapsed_seconds"]}
    write_json(REPORT / "independent_source_verification.json", {
        "schema": "task184-r2-worker-verification-v1", "generated_at": now(),
        "source_sha256": SOURCE_SHA, "target_manifest_sha256": TARGETS_SHA,
        "all_141_original_pt_load_body_hashes_reverified": True,
        "all_141_unwind_header_starts_reverified": True,
        "all_141_owned_memory_hashes_cross_checked": True,
        "sample_method": "20 evenly spread candidates; all original words re-disassembled and matched against immutable R1 assembly",
        "sample_count": len(sample), "sample_candidate_fraction": len(sample) / 141,
        "sample_instruction_words": counts["spread_instruction_words_reverified"],
        "sample": sample, "r1_immutable": True,
        "r2_owned_project_unchanged_after_read_only_pass": True,
        "not_independent_ceo_review": True})
    write_json(REPORT / "missing_instruction_evidence.json", {
        "schema": "task184-r2-missing-instruction-evidence-v1",
        "source_sha256": SOURCE_SHA, "candidate_count": len(missing_details),
        "total_missing_bytes": counts["ghidra_function_body_missing_bytes_within_fdes"],
        "total_missing_instruction_slots": all_missing_slots,
        "candidate_96_gap": "0x5d868..0x5d893 inclusive; 11 AArch64 words",
        "rows": missing_details})
    atomic_bytes(REPORT / "corrected_candidates.ndjson", (
        "\n".join(json.dumps(row, separators=(",", ":")) for row in corrected_candidates) + "\n"
    ).encode("utf-8"))
    r1_96 = json.loads((R1_REPORT / "ghidra/chunk_03/candidates/candidate_096.json").read_text(encoding="utf-8"))
    write_json(REPORT / "candidate_096_corrected.json", {
        "schema": "task184-r2-candidate96-correction-v1", "r1_raw_candidate_immutable": True,
        "r1_candidate_sha256": corrected_candidates[95]["r1_candidate_sha256"],
        "r1_original_fields": r1_96,
        "r2_corrected": corrected_candidates[95],
        "r2_body_membership": row96,
        "c_like_scope_warning": "R1 Ghidra C-like text covers a function body missing 44 interior FDE bytes; it is not a complete FDE-range reconstruction",
    })
    write_json(REPORT / "coverage_index.json", {
        "schema": "task184-r2-corrected-coverage-index-v1",
        "task_id": "TASK_184", "revision": 2,
        "source_sha256": SOURCE_SHA, "r1_seal_sha256": R1_SEAL_SHA,
        "classification": target["classification"],
        "counts": counts, "rows": coverage_rows})
    bullets = []
    for row in missing_details:
        first = row["missing_instructions"][0]["elf_va"]
        last = row["missing_instructions"][-1]["elf_va"]
        bullets.append(f"- Candidate {row['index']} `{row['elf_va']}`: {row['missing_bytes']} FDE bytes / {len(row['missing_instructions'])} AArch64 words absent from Ghidra function body; missing word VA extent `{first}`–`{last}`.")
    report = [
        "# TASK_184 R2 — corrected VERenderer body coverage",
        "",
        "The R1 extraction remains static evidence for 141 pinned FDE candidates, but its full-body coverage count was wrong. R2 checks the entire Ghidra function address set, including interior gaps, and corrects the result to **135 exact / 6 nonexact**. The sixth case is candidate 96 at ELF VA `0x5d6e4`: its 436-byte FDE has only 392 bytes in the Ghidra function body, with 44 interior bytes / 11 words missing despite matching min/max endpoints.",
        "",
        f"Original SO SHA-256 `{SOURCE_SHA}`; target manifest SHA-256 `{TARGETS_SHA}`; immutable R1 seal SHA-256 `{R1_SEAL_SHA}`. The R2 read-only Ghidra body-membership pass used a byte-verified project copy, zero imports, 1 CPU/1 GiB, and completed in {command['elapsed_seconds']:.3f}s. Raw command, logs, 141 membership rows and each omitted word's original bytes/SHA-256 are retained.",
        "",
        "## Corrected coverage",
        "",
        "The 141 original FDE spans total 30,644 bytes / 7,661 AArch64 instruction slots. Ghidra function body membership includes 30,408 of those bytes / 7,602 slots; 236 bytes / 59 slots are outside the six function bodies. The R1 listing still has 7,661 decoded instruction slots, 7,396 p-code-bearing slots and 141 nonempty C-like texts, but only 135 of those C-like texts correspond to Ghidra bodies that include their entire pinned FDE span. The six remaining C-like texts are explicitly **boundary-limited**.",
        "",
        *bullets,
        "",
        "Candidate 96's 11 missing word starts are `0x5d868, 0x5d86c, 0x5d870, 0x5d874, 0x5d878, 0x5d87c, 0x5d880, 0x5d884, 0x5d888, 0x5d88c, 0x5d890`. `missing_instruction_evidence.json` records each word's original file offset, 4 source bytes, SHA-256 and independent AArch64 decode. `candidate_096_corrected.json` retains its exact R1 C-like text while overriding the mistaken empty boundary classification in R2.",
        "",
        f"All 141 original PT_LOAD body hashes, FDE header starts and R2 owned-project memory hashes were cross-checked. Twenty evenly spread candidates ({len(sample)/141:.1%}) had every source instruction word re-decoded ({counts['spread_instruction_words_reverified']} words). R2 membership agrees with the CEO's independent replay for all 141 entries. Immutable R1 report files and both Ghidra projects were unchanged.",
        "",
        "An unwind FDE is a candidate range, not a guaranteed complete internal function boundary. Ghidra's C-like output is not verified source equivalence, runtime behavior or pixel parity. This correction does not assert product Phase PASS, V4/P7, or completion of all 45 SOs. Awaiting independent CEO review; worker verification is not approval.",
        "",
    ]
    atomic_bytes(REPORT / "01_MASTER_REPORT.md", "\n".join(report).encode("utf-8"))
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_184", "revision": 2,
              "status": "SEALED_CANDIDATE_AWAITING_CEO_REVIEW", "generated_at": now(),
              "lease_id": LEASE, "fencing_token": FENCE, "counts": counts})
    files = {p.relative_to(REPORT).as_posix(): sha(p) for p in sorted(REPORT.rglob("*"))
             if p.is_file() and p.name not in ("PROGRESS.json", "COMPLETE.json")}
    code_files = {p.relative_to(ROOT).as_posix(): sha(p) for p in sorted(SCRIPTS.rglob("*")) if p.is_file()}
    research_files = {p.relative_to(ROOT).as_posix(): sha(p) for p in sorted(SCRATCH.rglob("*")) if p.is_file()}
    if len(files) < 10 or len(code_files) != 5 or len(research_files) != 9:
        raise RuntimeError("R2 file inventory incomplete")
    report_bytes = sum((REPORT / name).stat().st_size for name in files)
    if report_bytes > 134217728:
        raise RuntimeError("R2 report byte cap exceeded")
    write_json(REPORT / "COMPLETE.json", {
        "schema_version": "2.1.2", "task_id": "TASK_184", "revision": 2,
        "status": "COMPLETE", "semantic_disposition": "CORRECTED_135_FULL_6_BOUNDARY_LIMITED",
        "generated_at": now(), "standard_sha256": STANDARD_SHA,
        "task_sha256": TASK_SHA, "target_manifest_sha256": TARGETS_SHA,
        "source_sha256": SOURCE_SHA, "correction_of_r1_seal_sha256": R1_SEAL_SHA,
        "lease_id": LEASE, "fencing_token": FENCE,
        "execution_mode": "REAL_CODEX_SUBAGENT_NO_AGY",
        "review_state": "AWAITING_INDEPENDENT_CEO_REVIEW",
        "counts": counts, "behavior_verified": False, "phase_pass": False,
        "v4_opened": False, "report_bytes_excluding_seal_and_progress": report_bytes,
        "files": files, "code_files": code_files, "research_files": research_files,
    })
    seal = json.loads((REPORT / "COMPLETE.json").read_text(encoding="utf-8"))
    present = {p.relative_to(REPORT).as_posix(): sha(p) for p in REPORT.rglob("*")
               if p.is_file() and p.name not in ("PROGRESS.json", "COMPLETE.json")}
    if seal["files"] != present or seal["code_files"] != code_files or seal["research_files"] != research_files:
        raise RuntimeError("R2 post-seal manifest mismatch")
    print(json.dumps({"status": seal["semantic_disposition"], "counts": counts,
                      "report_files": len(files), "code_files": len(code_files),
                      "research_files": len(research_files),
                      "complete_sha256": sha(REPORT / "COMPLETE.json")}), flush=True)


if __name__ == "__main__":
    main()
