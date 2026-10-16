"""Byte-anchored CFG map of TASK_233's omitted FDE253 interval."""

import hashlib
import json

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM

from run import PRIOR_RAW, REPORT, SOURCE, branch_target, guard, json_write, now


def main() -> None:
    guard()
    prior = json.loads(PRIOR_RAW.read_text(encoding="utf-8"))
    hole = {"start_offset": 25912, "end_exclusive": 27520}
    if prior["fde_missing_body_ranges"] != [hole] or prior["missing_analyzed_instruction_count"] != 402:
        raise RuntimeError("historical uncovered interval changed")
    src = SOURCE.read_bytes()
    fde_va = 0xa8b08
    start = fde_va + hole["start_offset"]
    stop = fde_va + hole["end_exclusive"]
    data = src[start:stop]
    if len(data) != 1608:
        raise RuntimeError("uncovered source byte count mismatch")
    ins = list(Cs(CS_ARCH_ARM64, CS_MODE_ARM).disasm(data, start))
    if len(ins) != 402 or sum(x.size for x in ins) != len(data):
        raise RuntimeError("uncovered region not fully decoded")
    branches = []
    rows = []
    for x in ins:
        m = x.mnemonic.lower()
        direct = m == "b" or m.startswith("b.") or m in ("cbz", "cbnz", "tbz", "tbnz")
        call = m in ("bl", "blr")
        target = branch_target(x) if direct or m == "bl" else None
        if direct or call or m in ("br", "ret", "eret"):
            branches.append({"source_va": f"0x{x.address:x}", "mnemonic": m,
                "target_va": f"0x{target:x}" if target is not None else None,
                "target_in_omitted_region": target is not None and start <= target < stop,
                "target_in_fde": target is not None and fde_va <= target < fde_va + 27524})
        rows.append({"elf_va": f"0x{x.address:x}", "offset_in_fde": x.address - fde_va,
            "word_le": bytes(x.bytes).hex(), "mnemonic": x.mnemonic, "operands": x.op_str})
    cfg = json.loads((REPORT / "source_cfg.json").read_text(encoding="utf-8"))
    incoming = []
    outgoing = []
    for x in cfg["branch_sites"]:
        source_va = int(x["va"], 16)
        target_va = int(x["target"], 16) if x["target"] else None
        if target_va is not None and not (start <= source_va < stop) and start <= target_va < stop:
            incoming.append(x)
        if start <= source_va < stop and target_va is not None and not (start <= target_va < stop):
            outgoing.append(x)
    json_write(REPORT / "omitted_subregion.json", {"task_id": "TASK_248", "revision": 1,
        "generated_at": now(), "classification": "STATIC_DISASSEMBLY_OF_PRIOR_GHIDRA_BODY_GAP",
        "fde_va": f"0x{fde_va:x}", "fde_size_bytes": 27524,
        "start_offset": hole["start_offset"], "end_exclusive_offset": hole["end_exclusive"],
        "start_va": f"0x{start:x}", "end_exclusive_va": f"0x{stop:x}",
        "source_bytes": len(data), "source_sha256": hashlib.sha256(data).hexdigest(),
        "original_words": len(ins), "branch_or_call_sites": len(branches),
        "direct_branches_into_region_from_outside": incoming,
        "direct_branches_out_of_region": outgoing,
        "instructions": rows, "branch_or_call_rows": branches,
        "limitations": ["No CFG/IR listing proves source function boundary or behavior",
                        "Indirect targets unresolved", "This region has no Ghidra body membership or analyzed instructions"]})
    print(json.dumps({"stage": "SUBREGION", "source_bytes": len(data),
        "source_words": len(ins), "branches_or_calls": len(branches),
        "direct_incoming": len(incoming), "direct_outgoing": len(outgoing)}), flush=True)


if __name__ == "__main__":
    main()
