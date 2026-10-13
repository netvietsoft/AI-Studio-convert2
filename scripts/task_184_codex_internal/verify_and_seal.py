"""Independent source/row verification and final worker evidence seal for TASK_184."""

from __future__ import annotations

import hashlib
import json
import struct
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path

from elftools.elf.elffile import ELFFile

from common import (AGENT, FENCE, LEASE, ORIGINAL_PROJECT, OWN_PROJECT, REPORT,
                    ROOT, SCRATCH, SCRIPTS, SOURCE, SOURCE_SHA, STANDARD_SHA,
                    TARGETS, TARGETS_SHA, TASK_SHA, atomic_bytes, guard, now, sha,
                    write_json)


def source_header_starts(data: bytes, elf: ELFFile) -> set[int]:
    headers = [s for s in elf.iter_segments() if s["p_type"] == "PT_GNU_EH_FRAME"]
    if len(headers) != 1:
        raise RuntimeError("expected one GNU EH frame header")
    header = headers[0]
    start = int(header["p_offset"])
    length = int(header["p_filesz"])
    version, ptr, count_enc, table_enc = struct.unpack_from("<BBBB", data, start)
    if (version, ptr, count_enc, table_enc) != (1, 0x1B, 0x03, 0x3B):
        raise RuntimeError("unwind table encoding changed")
    count = struct.unpack_from("<I", data, start + 8)[0]
    if count != 1027 or 12 + count * 8 != length:
        raise RuntimeError("unwind table count/length mismatch")
    va = int(header["p_vaddr"])
    return {va + struct.unpack_from("<i", data, start + 12 + index * 8)[0]
            for index in range(count)}


def project_hashes(project: Path) -> dict[str, str]:
    return {str(p.relative_to(project)).replace("\\", "/"): sha(p)
            for p in sorted(project.rglob("*")) if p.is_file()}


def main() -> None:
    guard()
    if (REPORT / "COMPLETE.json").exists():
        raise RuntimeError("TASK_184 already sealed")
    manifest = json.loads(TARGETS.read_text(encoding="utf-8"))
    expected = manifest["targets"]
    index = json.loads((REPORT / "source/source_index.json").read_text(encoding="utf-8"))
    if len(expected) != len(index["rows"]) or len(expected) != 141:
        raise RuntimeError("source target count inconsistent")
    source = SOURCE.read_bytes()
    if hashlib.sha256(source).hexdigest() != SOURCE_SHA:
        raise RuntimeError("source SHA changed")
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        starts = source_header_starts(source, elf)
        loads = [seg for seg in elf.iter_segments() if seg["p_type"] == "PT_LOAD"
                 and (int(seg["p_flags"]) & 1)]
    if len(starts) != 1027:
        raise RuntimeError("duplicate/ambiguous FDE header starts")

    all_rows = []
    for chunk in range(1, 4):
        folder = REPORT / "ghidra" / f"chunk_{chunk:02d}"
        receipt = json.loads((folder / "command.json").read_text(encoding="utf-8"))
        if receipt["status"] != "OUTPUT_READY" or receipt["observed"]["parseable_rows"] != 47:
            raise RuntimeError(f"chunk {chunk} not complete")
        files = sorted((folder / "candidates").glob("candidate_*.json"))
        if len(files) != 47 or len(receipt["output_files"]) != 47:
            raise RuntimeError(f"chunk {chunk} candidate file count mismatch")
        for path in files:
            if receipt["output_files"].get(path.name) != sha(path):
                raise RuntimeError(f"chunk {chunk} output file SHA mismatch: {path.name}")
            all_rows.append(json.loads(path.read_text(encoding="utf-8")))
        if receipt["stdout_sha256"] != sha(folder / "stdout.log") or receipt["stderr_sha256"] != sha(folder / "stderr.log"):
            raise RuntimeError(f"chunk {chunk} raw log SHA mismatch")
    if len(all_rows) != 141 or sorted(r["index"] for r in all_rows) != list(range(1, 142)):
        raise RuntimeError("Ghidra result row coverage invalid")
    by_index = {r["index"]: r for r in all_rows}

    source_assembly = {}
    for line in (REPORT / "source/assembly.ndjson").read_text(encoding="utf-8").splitlines():
        row = json.loads(line)
        source_assembly[row["index"]] = row
    if sorted(source_assembly) != list(range(1, 142)):
        raise RuntimeError("source assembly coverage invalid")
    sample_indices = sorted({1 + round(pos * 140 / 14) for pos in range(15)})
    if len(sample_indices) != 15:
        raise RuntimeError("spread sample not 15 unique candidates")
    sample_evidence = []
    coverage = []
    for index_number, target in enumerate(expected, 1):
        va = int(target["elf_va"], 16)
        size = int(target["size_bytes"])
        offset = int(target["file_offset"], 16)
        digest = target["body_sha256"]
        if va not in starts:
            raise RuntimeError(f"target {index_number} absent from independent unwind index")
        load = next((seg for seg in loads if int(seg["p_vaddr"]) <= va
                     and va + size <= int(seg["p_vaddr"]) + int(seg["p_filesz"])
                     and offset == int(seg["p_offset"]) + va - int(seg["p_vaddr"])), None)
        if load is None:
            raise RuntimeError(f"target {index_number} not in original executable PT_LOAD")
        body = source[offset:offset + size]
        if len(body) != size or hashlib.sha256(body).hexdigest() != digest:
            raise RuntimeError(f"target {index_number} original body hash mismatch")
        row = by_index[index_number]
        if (row["elf_va"] != target["elf_va"] or row["size_bytes"] != size
            or row["original_file_offset"] != target["file_offset"]
            or row["expected_original_body_sha256"] != digest
            or row["owned_project_memory_sha256"] != digest
            or row["source_bytes_match"] is not True):
            raise RuntimeError(f"target {index_number} Ghidra/source byte identity mismatch")
        if (row["instruction_count"] + row["missing_instruction_slots"] != size // 4
            or row["pcode_instruction_slots"] > row["instruction_count"]
            or row["decompile_success"] is not True or not row["pseudocode"].strip()
            or hashlib.sha256(row["pseudocode"].encode("utf-8")).hexdigest()
               != row["pseudocode_sha256"]):
            raise RuntimeError(f"target {index_number} instruction/C-like metadata invalid")
        source_row = source_assembly[index_number]
        if source_row["body_sha256"] != digest or len(source_row["instructions"]) != size // 4:
            raise RuntimeError(f"target {index_number} original assembly coverage invalid")
        if index_number in sample_indices:
            for slot, entry in enumerate(source_row["instructions"]):
                word = body[slot * 4:slot * 4 + 4]
                if entry["word_le"] != word.hex() or int(entry["va"], 16) != va + slot * 4:
                    raise RuntimeError(f"target {index_number} sampled word mismatch at slot {slot}")
                if len(row["instructions"]) == size // 4:
                    if not row["instructions"][slot].startswith(f"{va + 0x100000 + slot * 4:08x}:"):
                        raise RuntimeError(f"target {index_number} sampled Ghidra address mismatch at slot {slot}")
            sample_evidence.append({"index": index_number, "elf_va": target["elf_va"],
                                    "original_file_offset": target["file_offset"],
                                    "body_sha256": digest, "instruction_words_verified": size // 4,
                                    "first_word_le": body[:4].hex(), "last_word_le": body[-4:].hex()})
        coverage.append({"index": index_number, "elf_va": target["elf_va"],
                         "size_bytes": size, "body_sha256": digest,
                         "original_executable_pt_load_verified": True,
                         "unwind_fde_header_start_verified": True,
                         "owned_project_memory_sha256": row["owned_project_memory_sha256"],
                         "instruction_slots": size // 4,
                         "ghidra_instruction_slots": row["instruction_count"],
                         "pcode_instruction_slots": row["pcode_instruction_slots"],
                         "pcode_op_count": row["pcode_op_count"],
                         "ghidra_function_origin": row["function_origin"],
                         "boundary_ambiguity": row["boundary_ambiguity"],
                         "c_like_sha256": row["pseudocode_sha256"],
                         "c_like_bytes_utf8": len(row["pseudocode"].encode("utf-8")),
                         "behavior_verified": False})

    copy = json.loads((REPORT / "project_copy_receipt.json").read_text(encoding="utf-8"))
    copied_hashes = copy["copied_byte_hashes"]
    if copied_hashes != project_hashes(OWN_PROJECT):
        raise RuntimeError("owned analyzed project was modified by read-only passes")
    original_hashes = project_hashes(ORIGINAL_PROJECT)
    normalized = {name.replace("Task158", "Task184", 1): digest
                  for name, digest in original_hashes.items()}
    if normalized != copied_hashes:
        raise RuntimeError("original analyzed project changed since copy")

    counts = {"candidates": 141, "original_body_hashes_reverified": 141,
              "unwind_header_starts_reverified": 141,
              "owned_memory_hashes_matched": sum(r["source_bytes_match"] is True for r in all_rows),
              "instruction_slots_expected": sum(r["size_bytes"] // 4 for r in all_rows),
              "instruction_slots_observed": sum(r["instruction_count"] for r in all_rows),
              "pcode_instruction_slots": sum(r["pcode_instruction_slots"] for r in all_rows),
              "pcode_ops": sum(r["pcode_op_count"] for r in all_rows),
              "c_like_rows": sum(r["decompile_success"] is True for r in all_rows),
              "exact_ghidra_fde_boundary_rows": sum(not r["boundary_ambiguity"] for r in all_rows),
              "boundary_ambiguous_rows": sum(bool(r["boundary_ambiguity"]) for r in all_rows),
              "spread_candidates_reverified": len(sample_evidence),
              "spread_instruction_words_reverified": sum(x["instruction_words_verified"] for x in sample_evidence),
              "fresh_imports": 0, "ghidra_processes": 3,
              "ghidra_process_seconds": sum(json.loads((REPORT / "ghidra" / f"chunk_{c:02d}" / "command.json").read_text(encoding="utf-8"))["elapsed_seconds"] for c in range(1, 4))}
    if counts["instruction_slots_observed"] != 7661 or counts["c_like_rows"] != 141:
        raise RuntimeError("bounded extraction is incomplete")
    write_json(REPORT / "coverage_index.json", {"schema": "task184-coverage-index-v1",
               "task_id": "TASK_184", "source_sha256": SOURCE_SHA,
               "classification": manifest["classification"], "counts": counts, "rows": coverage})
    write_json(REPORT / "independent_source_verification.json", {
        "schema": "task184-worker-independent-source-check-v1", "generated_at": now(),
        "original_source_sha256": SOURCE_SHA, "target_manifest_sha256": TARGETS_SHA,
        "original_elf_pt_gnu_eh_frame_starts": len(starts),
        "all_original_executable_pt_load_body_hashes_rechecked": 141,
        "all_owned_project_memory_hashes_cross_checked": 141,
        "sample_method": "15 evenly spread candidate indices; every original little-endian instruction word and matching Ghidra listing VA rechecked",
        "sample_count": len(sample_evidence), "sample_fraction": len(sample_evidence) / 141,
        "sample_instruction_words": counts["spread_instruction_words_reverified"],
        "sample": sample_evidence, "original_ghidra_project_unchanged": True,
        "owned_copy_unchanged_after_readonly_passes": True,
        "not_independent_ceo_review": True})
    ambiguous = [r for r in coverage if r["boundary_ambiguity"]]
    report = [
        "# TASK_184 R1 — VERenderer nonexport unwind candidate recovery",
        "",
        f"Original `libVERenderer.so` SHA-256 `{SOURCE_SHA}`; 141 exact manifest rows SHA-256 `{TARGETS_SHA}`.",
        f"Completed bounded extraction: {counts['c_like_rows']}/141 C-like texts, {counts['instruction_slots_observed']}/7661 instruction slots, {counts['pcode_instruction_slots']}/7661 slots with p-code, {counts['pcode_ops']} p-code operations.",
        f"All 141 source PT_LOAD bodies and FDE starts were rechecked; all 141 owned-project memory hashes equal original body hashes. Fifteen evenly spread candidates ({len(sample_evidence)/141:.1%}) had every original instruction word and Ghidra listing address independently rechecked ({counts['spread_instruction_words_reverified']} words).",
        f"Three sequential read-only Ghidra processes used the byte-verified copy of prior TASK_158 project, zero new imports, 1 CPU/1 GiB, 10 seconds per candidate decompilation, under 20 minutes per process ({counts['ghidra_process_seconds']:.3f}s combined). Raw command receipts, stdout/stderr, and 141 per-candidate JSON results remain under `ghidra/`.",
        "",
        "## Boundary and confidence limits",
        "",
        "These are 141 unwind FDE starts absent from defined nonzero `.dynsym` STT_FUNC export starts. An FDE start/span is a candidate range, not proof of a complete internal-function census or unique function boundary. Ghidra's existing function entry matched all 141 starts. Its function body differed from the pinned FDE span in five rows; their C-like output must be read with that boundary discrepancy.",
        "",
        *[f"- Candidate {r['index']} at `{r['elf_va']}`: `{r['boundary_ambiguity']}`; see per-candidate JSON for exact Ghidra body and FDE size." for r in ambiguous],
        "",
        "P-code operations are zero for some decoded instructions (e.g. architectural no-ops); therefore 7,396 p-code-covered slots are reported separately from full assembly-slot coverage. C-like text is Ghidra output only: it has not been compiled, tested against original execution, or checked for pixel/behavioral parity. No product Phase PASS, V4, P7, or all-45-SO completion is asserted.",
        "",
        "`coverage_index.json`, `source/source_index.json`, `source/assembly.ndjson`, `independent_source_verification.json`, and `ghidra/chunk_*/candidates/candidate_*.json` identify each row. This package awaits independent CEO review; worker verification is not approval.",
        "",
    ]
    atomic_bytes(REPORT / "01_MASTER_REPORT.md", "\n".join(report).encode("utf-8"))
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_184", "revision": 1,
              "status": "SEALED_CANDIDATE_AWAITING_CEO_REVIEW", "generated_at": now(),
              "lease_id": LEASE, "fencing_token": FENCE, "counts": counts})

    report_files = {str(p.relative_to(REPORT)).replace("\\", "/"): sha(p)
                    for p in sorted(REPORT.rglob("*")) if p.is_file()
                    and p.name not in ("COMPLETE.json", "PROGRESS.json")}
    code_files = {str(p.relative_to(ROOT)).replace("\\", "/"): sha(p)
                  for p in sorted(SCRIPTS.rglob("*")) if p.is_file()}
    research_files = {str(p.relative_to(ROOT)).replace("\\", "/"): sha(p)
                      for p in sorted(SCRATCH.rglob("*")) if p.is_file()}
    if len(report_files) < 150 or len(code_files) != 5 or len(research_files) < 9:
        raise RuntimeError("package file inventory unexpectedly small")
    report_bytes = sum((REPORT / rel).stat().st_size for rel in report_files)
    if report_bytes > 134217728:
        raise RuntimeError("report exceeds task cap")
    write_json(REPORT / "COMPLETE.json", {
        "schema_version": "2.1.2", "task_id": "TASK_184", "revision": 1,
        "status": "COMPLETE", "semantic_disposition": "COMPLETE_BOUNDED_CANDIDATE_BATCH_WITH_FDE_BOUNDARY_AMBIGUITY",
        "generated_at": now(), "standard_sha256": STANDARD_SHA,
        "task_sha256": TASK_SHA, "target_manifest_sha256": TARGETS_SHA,
        "source_sha256": SOURCE_SHA, "lease_id": LEASE, "fencing_token": FENCE,
        "execution_mode": "REAL_CODEX_SUBAGENT_NO_AGY",
        "review_state": "AWAITING_INDEPENDENT_CEO_REVIEW",
        "classification": manifest["classification"], "counts": counts,
        "behavior_verified": False, "phase_pass": False, "v4_opened": False,
        "report_bytes_excluding_seal_and_progress": report_bytes,
        "files": report_files, "code_files": code_files, "research_files": research_files,
    })
    # Validate the just-written seal against current bytes, without claiming CEO review.
    seal = json.loads((REPORT / "COMPLETE.json").read_text(encoding="utf-8"))
    current_report = {str(p.relative_to(REPORT)).replace("\\", "/"): sha(p)
                      for p in REPORT.rglob("*") if p.is_file()
                      and p.name not in ("COMPLETE.json", "PROGRESS.json")}
    if seal["files"] != current_report or seal["code_files"] != code_files or seal["research_files"] != research_files:
        raise RuntimeError("post-seal file manifest mismatch")
    print(json.dumps({"status": seal["semantic_disposition"], "counts": counts,
                      "report_files": len(report_files), "code_files": len(code_files),
                      "research_files": len(research_files),
                      "complete_sha256": sha(REPORT / "COMPLETE.json")}), flush=True)


if __name__ == "__main__":
    main()
