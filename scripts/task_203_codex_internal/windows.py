"""Join pinned source windows with raw Ghidra body, listing, and p-code evidence."""
from __future__ import annotations

import hashlib
import json

from common import FENCE, LEASE_ID, MANIFEST, REPORT, check_lease, now, write_json


def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def parse_range(text: str) -> tuple[int, int]:
    first, last = text.split("..")
    return int(first, 16), int(last, 16) + 1


def main() -> None:
    check_lease()
    if (REPORT / "window_evidence.json").exists():
        raise RuntimeError("existing window evidence must not be overwritten")
    targets = json.loads(MANIFEST.read_text(encoding="utf-8"))["targets"]
    flows = json.loads((REPORT / "source_flow.json").read_text(encoding="utf-8"))["targets"]
    assembly = [json.loads(line) for line in (REPORT / "source_assembly.ndjson").read_text(encoding="utf-8").splitlines()]
    if len(targets) != len(flows) or len(targets) != len(assembly) or len(targets) != 2:
        raise RuntimeError("source/raw cardinality mismatch")
    outputs = []
    for n, (target, flow, source_asm) in enumerate(zip(targets, flows, assembly)):
        global_index = target["global_nonexport_fde_index"]
        raw = json.loads((REPORT / f"chunk_{n:02d}/ghidra_raw.ndjson").read_text(encoding="utf-8").strip())
        body = (REPORT / f"original_fde_{global_index}.bin").read_bytes()
        base = int(target["elf_va"], 16)
        bits = raw["fde_membership_bits"]
        slots = raw["instruction_pcode"]
        if (flow["global_nonexport_fde_index"] != global_index or
                source_asm["global_nonexport_fde_index"] != global_index or
                raw["elf_va"] != target["elf_va"] or len(body) != len(bits) or
                len(slots) * 4 != len(body) or digest(body) != target["body_sha256"]):
            raise RuntimeError(f"source/Ghidra identity mismatch at {global_index}")
        windows = []
        for source_window in flow["source_windows"]:
            start = int(source_window["start_va"], 16)
            end = int(source_window["end_exclusive_va"], 16)
            lo, hi = start-base, end-base
            part = body[lo:hi]
            ghidra_slots = slots[lo//4:hi//4]
            reconstructed = bytes.fromhex("".join(x["word_le"] for x in ghidra_slots))
            if reconstructed != part or digest(part) != source_window["body_sha256"]:
                raise RuntimeError(f"source/Ghidra window bytes differ at {global_index}:{start:x}")
            selected_branches = [b for b in flow["branch_records"] if start <= int(b["from_va"], 16) < end]
            selected_literals = [b for b in flow["literal_addressing_candidates"] if start <= int(b["from_va"], 16) < end]
            windows.append({"window_index": source_window["window_index"],
                "start_va": hex(start), "end_exclusive_va": hex(end),
                "source_body_sha256": digest(part), "ghidra_words_sha256": digest(reconstructed),
                "source_instruction_slots": len(ghidra_slots),
                "ghidra_listing_slots": sum(not x["missing_instruction"] for x in ghidra_slots),
                "ghidra_pcode_slots": sum(bool(x["pcode_ops"]) for x in ghidra_slots),
                "ghidra_pcode_ops": sum(len(x["pcode_ops"]) for x in ghidra_slots),
                "function_member_bytes": bits[lo:hi].count("1"),
                "function_missing_bytes": bits[lo:hi].count("0"),
                "source_branch_count": len(selected_branches),
                "source_direct_call_count": sum(b["kind"] == "CALL" and b["direct_target_va"] is not None for b in selected_branches),
                "source_literal_addressing_candidate_count": len(selected_literals)})
        gaps = []
        for text in raw["fde_missing_ranges"]:
            start, end = parse_range(text)
            lo, hi = start-base, end-base
            first_slot, last_slot = lo//4, (hi+3)//4
            context_start = max(0, first_slot-4)
            context_end = min(len(slots), last_slot+4)
            target_branches = [b for b in flow["branch_records"] if b["direct_target_va"] is not None
                               and start <= int(b["direct_target_va"], 16) < end]
            source_branches = [b for b in flow["branch_records"] if start <= int(b["from_va"], 16) < end]
            literals = [b for b in flow["literal_addressing_candidates"] if start <= int(b["target_va"], 16) < end]
            overlapping_blocks = [b for b in flow["syntactic_basic_blocks"]
                                  if int(b["start_va"], 16) < end and start < int(b["end_exclusive_va"], 16)]
            gaps.append({"missing_range": text, "size_bytes": hi-lo,
                         "original_gap_sha256": digest(body[lo:hi]),
                         "capstone_decoded_slots_in_gap": len(source_asm["instructions"][first_slot:last_slot]),
                         "ghidra_listing_slots_in_gap": sum(not x["missing_instruction"] for x in slots[first_slot:last_slot]),
                         "ghidra_pcode_slots_in_gap": sum(bool(x["pcode_ops"]) for x in slots[first_slot:last_slot]),
                         "source_direct_branch_targets_into_gap": target_branches,
                         "source_branch_sites_within_gap": source_branches,
                         "literal_addressing_targets_into_gap": literals,
                         "syntactic_basic_blocks_overlapping_gap": len(overlapping_blocks),
                         "context_source_instructions": source_asm["instructions"][context_start:context_end],
                         "code_data_ambiguity": "Unresolved: decode and branch/literal evidence do not prove this gap is executable code."})
        outputs.append({"global_nonexport_fde_index": global_index, "elf_va": target["elf_va"],
                        "size_bytes": len(body), "window_bytes": 256, "windows": windows,
                        "window_count": len(windows), "window_source_slots": sum(w["source_instruction_slots"] for w in windows),
                        "window_ghidra_listing_slots": sum(w["ghidra_listing_slots"] for w in windows),
                        "window_function_missing_bytes": sum(w["function_missing_bytes"] for w in windows),
                        "gap_contexts": gaps, "boundary_classification": raw["boundary_classification"],
                        "whole_fde_c_like_present": raw["c_like_present"],
                        "whole_fde_c_like_failure": raw["failure"]})
    check_lease()
    write_json(REPORT / "window_evidence.json", {"task_id": "TASK_203", "revision": 1,
        "generated_at": now(), "method": "256-byte source windows joined with per-slot raw Ghidra evidence",
        "targets": outputs})
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_203", "revision": 1,
        "status": "WINDOW_EVIDENCE_READY", "generated_at": now(),
        "lease_id": LEASE_ID, "fencing_token": FENCE,
        "target_rows_processed": len(outputs),
        "total_source_windows": sum(x["window_count"] for x in outputs),
        "total_source_slots": sum(x["window_source_slots"] for x in outputs),
        "whole_fde_c_like_rows": sum(x["whole_fde_c_like_present"] for x in outputs),
        "total_function_missing_bytes": sum(x["window_function_missing_bytes"] for x in outputs)})
    print(json.dumps({"status": "WINDOW_EVIDENCE_READY", "targets": len(outputs),
                      "windows": sum(x["window_count"] for x in outputs),
                      "source_slots": sum(x["window_source_slots"] for x in outputs),
                      "function_missing_bytes": sum(x["window_function_missing_bytes"] for x in outputs)}))


if __name__ == "__main__":
    main()
