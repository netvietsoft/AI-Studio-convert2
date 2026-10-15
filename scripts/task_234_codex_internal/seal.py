"""Verify TASK_234 raw results against original source and seal research evidence."""

from __future__ import annotations

import hashlib
import json
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs

from run import (AGENT, FENCE, HERE, LEASE, ORIGINAL, PROJECT, REPORT, ROOT,
                 SHA, SOURCE, STANDARD, TARGETS, TASK, guard, json_write, now,
                 project_hashes, sha, write)


def main() -> None:
    guard()
    if (REPORT / "COMPLETE.json").exists():
        raise RuntimeError("report already sealed")
    source = SOURCE.read_bytes()
    index = json.loads((REPORT / "source_index.json").read_text(encoding="utf-8"))
    manifest = json.loads(TARGETS.read_text(encoding="utf-8"))
    copy = json.loads((REPORT / "project_copy_receipt.json").read_text(encoding="utf-8"))
    success = json.loads((REPORT / "ghidra/command.json").read_text(encoding="utf-8"))
    if success["status"] != "OUTPUT_READY" or success["observed"]["parseable_rows"] != 511:
        raise RuntimeError("corrected Ghidra receipt incomplete")
    if project_hashes(ORIGINAL) != copy["copied_hashes"]:
        raise RuntimeError("accepted source project changed")
    # The owned project is processed read-only; any transient files must not be mistaken for source changes.
    owned_after = project_hashes(PROJECT)
    raw_dir = REPORT / "ghidra/candidates"
    raw_files = sorted(raw_dir.glob("candidate_*.json"))
    if len(raw_files) != 511 or len(index["rows"]) != 511 or len(manifest["targets"]) != 511:
        raise RuntimeError("511-way report/manifest set mismatch")
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    decoder.skipdata = True
    summary = {"targets": 511, "original_bytes": 0, "source_slots": 0, "listed_slots": 0,
               "pcode_bearing_slots": 0, "pcode_ops": 0, "memory_hashes_match": 0,
               "c_like": 0, "body_exact_fde": 0, "body_boundary_limited": 0,
               "missing_body_bytes": 0, "warning_bodies": 0, "source_calls": 0,
               "failed_rows": 0}
    rows = []
    sample_indices = sorted({1, 511, *[1 + round(i * 510 / 51) for i in range(52)]})
    sample = []
    image_base = 0x100000
    for number, (raw_file, target, pinned) in enumerate(zip(raw_files, index["rows"], manifest["targets"]), 1):
        raw = json.loads(raw_file.read_text(encoding="utf-8"))
        va = int(target["elf_va"], 16)
        offset = int(target["file_offset"], 16)
        size = target["size_bytes"]
        body = source[offset:offset + size]
        digest = hashlib.sha256(body).hexdigest()
        if (raw["index"] != number or target["index"] != number or
            pinned["global_index"] != number + 2048 + (1 if number >= 245 else 0) or
            target["global_index"] != pinned["global_index"] or raw["elf_va"] != target["elf_va"] or
            raw["size_bytes"] != size or raw["original_file_offset"] != target["file_offset"] or
            raw["expected_original_body_sha256"] != digest or target["body_sha256"] != digest or
            pinned["body_sha256"] != digest or raw["owned_project_memory_sha256"] != digest or
            raw["source_bytes_match"] is not True):
            raise RuntimeError(f"critical original/Ghidra identity mismatch at row {number}")
        ins = list(decoder.disasm(body, va))
        if len(ins) != size // 4 or raw["instruction_count"] != len(ins) or raw["missing_instruction_slots"] != 0:
            raise RuntimeError(f"source/listing slot count mismatch at row {number}")
        listed = raw["instructions"]
        if len(listed) != len(ins):
            raise RuntimeError(f"listed row count mismatch at row {number}")
        for original_instruction, listing in zip(ins, listed):
            try:
                listed_va = int(listing.split(":", 1)[0], 16)
            except ValueError:
                listed_va = -1
            if listed_va != image_base + original_instruction.address:
                raise RuntimeError(f"listing address mismatch at row {number}: {listing[:30]}")
        if raw["database_va"] != f"0x{image_base + va:x}":
            raise RuntimeError(f"Ghidra image base mismatch at row {number}")
        if raw["decompile_success"] is not True or not raw["pseudocode"].strip():
            summary["failed_rows"] += 1
        else:
            summary["c_like"] += 1
        if raw["pseudocode_sha256"] != hashlib.sha256(raw["pseudocode"].encode("utf-8")).hexdigest():
            raise RuntimeError(f"C-like text hash mismatch at row {number}")
        entry = int(raw["function_entry"], 16) if raw["function_entry"] else -1
        exact = (raw["body_member_bytes_within_fde"] == size and
                 raw["body_extra_bytes_outside_fde"] == 0 and entry == image_base + va)
        if exact and raw["boundary_ambiguity"]:
            raise RuntimeError(f"exact body incorrectly ambiguous at row {number}")
        if not exact and not raw["boundary_ambiguity"]:
            raise RuntimeError(f"nonexact body incorrectly unambiguous at row {number}")
        summary["body_exact_fde" if exact else "body_boundary_limited"] += 1
        summary["missing_body_bytes"] += max(0, size - raw["body_member_bytes_within_fde"])
        summary["original_bytes"] += size
        summary["source_slots"] += len(ins)
        summary["listed_slots"] += raw["instruction_count"]
        summary["pcode_bearing_slots"] += raw["pcode_instruction_slots"]
        summary["pcode_ops"] += raw["pcode_op_count"]
        summary["memory_hashes_match"] += 1
        summary["warning_bodies"] += "WARNING:" in raw["pseudocode"]
        summary["source_calls"] += sum(x.mnemonic in ("bl", "blr") for x in ins)
        rows.append({"index": number, "elf_va": target["elf_va"], "size_bytes": size,
                     "body_sha256": digest, "raw_sha256": sha(raw_file), "c_like_sha256": raw["pseudocode_sha256"],
                     "listed_slots": raw["instruction_count"], "pcode_slots": raw["pcode_instruction_slots"],
                     "body_exact_fde": exact, "body_member_bytes": raw["body_member_bytes_within_fde"],
                     "body_extra_bytes": raw["body_extra_bytes_outside_fde"],
                     "warning_in_c_like": "WARNING:" in raw["pseudocode"]})
        if number in sample_indices:
            # A second independent byte stream read, word decode, and hash for >10% spread rows.
            with SOURCE.open("rb") as stream:
                stream.seek(offset)
                independent = stream.read(size)
            again = list(decoder.disasm(independent, va))
            if hashlib.sha256(independent).hexdigest() != digest or len(again) != len(ins):
                raise RuntimeError(f"ordinary spread provenance mismatch at row {number}")
            sample.append({"index": number, "elf_va": target["elf_va"], "body_sha256": digest,
                           "source_slots_redecoded": len(again), "raw_sha256": sha(raw_file)})
    if summary["source_slots"] != index["instruction_slots"] or summary["original_bytes"] != index["body_bytes"]:
        raise RuntimeError("aggregate source coverage mismatch")
    if len(sample) < 52:
        raise RuntimeError("<10% ordinary provenance sample")
    summary["ordinary_rechecked"] = len(sample)
    summary["ordinary_total"] = 511
    summary["original_project_unchanged"] = True
    summary["owned_project_file_count_after"] = len(owned_after)
    json_write(REPORT / "verification.json", {"task_id": "TASK_234", "revision": 1,
               "generated_at": now(), "scope": "STATIC_RESEARCH_ONLY", "summary": summary,
               "ordinary_spread_sample": sample, "rows": rows,
               "original_project_before_and_after_hashes_match": True,
               "owned_project_after_hashes": owned_after})
    report = f"""# TASK_234 R1 — libPVGImageCodec internal FDE research

Status: **BOUNDED_PARTIAL_RESEARCH_CANDIDATE**, awaiting independent CEO review.

The pinned original `.so` SHA-256 `{SHA[SOURCE]}` has 9,981 unwind FDE starts and 3,326 distinct nonzero defined `.dynsym` function export VAs. This task selected 511 ordinary global indices 2049-2560 of 6,655 FDE starts absent from those exports, excluding oversized index 2293 (`0x2bed18`, 5,056 bytes). The seven oversized indices deferred in TASK_231 also remain pending. This selection does not overlap TASK_231. Each selected executable PT_LOAD span and SHA-256 was rechecked against the original file. Capstone decoded {summary['original_bytes']:,} original bytes / {summary['source_slots']:,} AArch64 instruction slots.

One read-only Ghidra process from a private byte-verified copy of the accepted TASK_216 project completed in {success['elapsed_seconds']} seconds. Each decompile was capped at 15 seconds; raw command/logs and 511 individual outputs are under `ghidra/`. The accepted original project hashes remain unchanged.

The Ghidra run matched original memory for {summary['memory_hashes_match']}/511 selected spans and emitted {summary['c_like']}/511 nonempty C-like texts. It listed {summary['listed_slots']:,}/{summary['source_slots']:,} source-aligned instruction starts; {summary['pcode_bearing_slots']:,} slots had p-code ({summary['pcode_ops']:,} p-code ops). Full function-body membership versus the FDE span was **exact for {summary['body_exact_fde']}** and **boundary-limited for {summary['body_boundary_limited']}**, missing {summary['missing_body_bytes']:,} FDE bytes from those Ghidra bodies. {summary['warning_bodies']} C-like texts contain Ghidra `WARNING:` output. A second original-byte/hash/decode check covered {summary['ordinary_rechecked']}/511 spread records ({summary['ordinary_rechecked']/511:.1%}).

An unwind FDE is a candidate range, not proof of an entire source function. Nonempty C-like output, even with all original instructions listed, is not validated algorithm behavior. Boundary-limited texts require special care; neither this task nor accepted TASK_216 proves internal-function completeness, codec behavior, product Phase PASS, device parity or V4 readiness. No source, P0 or product file was edited; no commit/push or self-review was performed.
"""
    write(REPORT / "01_MASTER_REPORT.md", report.encode("utf-8"))
    # Progress is updated before sealing so every sealed byte remains stable for review.
    json_write(REPORT / "PROGRESS.json", {"task_id": "TASK_234", "revision": 1,
               "status": "BOUNDED_PARTIAL_RESEARCH_CANDIDATE", "generated_at": now(),
               "lease_id": LEASE, "fencing_token": FENCE, "selected": 511,
               "c_like": summary["c_like"], "body_exact_fde": summary["body_exact_fde"],
               "body_boundary_limited": summary["body_boundary_limited"],
               "skipped_oversized_global_indices": [2293],
               "prior_deferred_oversized_global_indices": [1542, 1586, 1620, 1623, 1626, 1830, 1912]})
    # The CEO controller snapshots PROGRESS.json on a separate channel.
    files = {p.relative_to(REPORT).as_posix(): sha(p) for p in sorted(REPORT.rglob("*"))
             if p.is_file() and p.name not in ("COMPLETE.json", "PROGRESS.json")}
    code = {p.relative_to(ROOT).as_posix(): sha(p) for p in sorted(HERE.glob("*")) if p.is_file()}
    json_write(REPORT / "COMPLETE.json", {"schema_version": "2.1.2", "task_id": "TASK_234",
               "revision": 1, "status": "COMPLETE", "semantic_disposition": "BOUNDED_PARTIAL_RESEARCH_CANDIDATE",
               "generated_at": now(), "standard_path": str(STANDARD), "standard_sha256": SHA[STANDARD],
               "task_sha256": SHA[TASK], "target_manifest_sha256": SHA[TARGETS],
               "source_sha256": SHA[SOURCE], "lease_id": LEASE, "fencing_token": FENCE,
               "review_state": "AWAITING_INDEPENDENT_CEO_REVIEW", "source_bodies_rehashed": 511,
               "ordinary_records_independently_rechecked": len(sample),
               "ordinary_records_total": 511, "c_like_bodies_recovered": summary["c_like"],
               "full_fde_body_membership": summary["body_exact_fde"],
               "boundary_limited_c_like": summary["body_boundary_limited"],
               "runtime_or_pixel_semantics_proven": False, "files": files, "code_files": code})
    print(json.dumps({"stage": "SEALED", "summary": summary, "report_files": len(files),
                      "code_files": len(code), "complete_sha256": sha(REPORT / "COMPLETE.json")}), flush=True)


if __name__ == "__main__":
    main()
