"""Bounded syntactic AArch64 branch, block, and source-window evidence."""
from __future__ import annotations

import hashlib

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM, CS_GRP_CALL, CS_GRP_JUMP, CS_GRP_RET
from capstone.arm64 import ARM64_OP_IMM


def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def build_flow(index: int, va: int, body: bytes) -> dict:
    if not body or len(body) % 4:
        raise ValueError("nonempty four-byte aligned FDE body required")
    dis = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    dis.detail = True
    instructions = list(dis.disasm(body, va))
    if len(instructions) != len(body) // 4 or any(
            ins.address != va + 4 * slot or ins.size != 4 for slot, ins in enumerate(instructions)):
        raise ValueError("source body does not decode at every four-byte position")
    end = va + len(body)
    branches = []
    leaders = {va}
    literal_refs = []
    trap_markers = []
    for ins in instructions:
        mnemonic = ins.mnemonic.lower()
        if mnemonic in ("adr", "adrp", "ldr", "ldrsw", "prfm") and ins.operands:
            operand = ins.operands[-1]
            if operand.type == ARM64_OP_IMM:
                target = int(operand.imm)
                literal_refs.append({"from_va": hex(ins.address), "mnemonic": mnemonic,
                                     "target_va": hex(target), "target_inside_fde": va <= target < end})
        if mnemonic in ("udf", "brk", "hlt", "svc", "hvc", "smc"):
            trap_markers.append({"va": hex(ins.address), "mnemonic": mnemonic,
                                 "word_le": body[ins.address-va:ins.address-va+4].hex()})
        if CS_GRP_CALL in ins.groups:
            kind = "CALL"
        elif CS_GRP_JUMP in ins.groups:
            kind = "JUMP"
        elif CS_GRP_RET in ins.groups:
            kind = "RETURN"
        else:
            continue
        target = None
        if ins.operands and ins.operands[-1].type == ARM64_OP_IMM:
            target = int(ins.operands[-1].imm)
        relation = ("INDIRECT_OR_NONE" if target is None else
                    "INSIDE_ALIGNED" if va <= target < end and target % 4 == va % 4 else
                    "INSIDE_MISALIGNED" if va <= target < end else "OUTSIDE_FDE")
        next_va = ins.address + 4
        if next_va < end:
            leaders.add(next_va)
        if kind == "JUMP" and relation == "INSIDE_ALIGNED":
            leaders.add(target)
        branches.append({"from_va": hex(ins.address), "mnemonic": ins.mnemonic,
                         "operands": ins.op_str, "kind": kind,
                         "direct_target_va": hex(target) if target is not None else None,
                         "target_relation": relation,
                         "next_va": hex(next_va) if next_va < end else None})

    branch_by_va = {int(b["from_va"], 16): b for b in branches}
    ordered_leaders = sorted(leaders)
    blocks = []
    for j, start in enumerate(ordered_leaders):
        block_end = ordered_leaders[j+1] if j+1 < len(ordered_leaders) else end
        terminal_va = block_end - 4
        terminal = branch_by_va.get(terminal_va)
        successors = []
        if terminal is None:
            if block_end < end:
                successors.append(hex(block_end))
        elif terminal["kind"] == "CALL":
            if block_end < end:
                successors.append(hex(block_end))
        elif terminal["kind"] == "JUMP":
            if terminal["target_relation"] == "INSIDE_ALIGNED":
                successors.append(terminal["direct_target_va"])
            if terminal["mnemonic"].lower() not in ("b", "br", "braa", "brab") and block_end < end:
                successors.append(hex(block_end))
        block_bytes = body[start-va:block_end-va]
        blocks.append({"start_va": hex(start), "end_exclusive_va": hex(block_end),
                       "instruction_slots": len(block_bytes)//4, "body_sha256": digest(block_bytes),
                       "terminal_va": hex(terminal_va),
                       "terminal_kind": terminal["kind"] if terminal else "FALLTHROUGH",
                       "candidate_successor_vas": sorted(set(successors), key=lambda x: int(x, 16))})

    windows = []
    for offset in range(0, len(body), 256):
        part = body[offset:offset+256]
        start, finish = va + offset, va + offset + len(part)
        selected = [b for b in branches if start <= int(b["from_va"], 16) < finish]
        windows.append({"window_index": len(windows), "start_va": hex(start),
                        "end_exclusive_va": hex(finish), "instruction_slots": len(part)//4,
                        "body_sha256": digest(part), "branch_count": len(selected),
                        "call_count": sum(b["kind"] == "CALL" for b in selected)})
    return {"global_nonexport_fde_index": index, "elf_va": hex(va),
            "size_bytes": len(body), "body_sha256": digest(body),
            "decoded_instruction_slots": len(instructions),
            "branch_records": branches, "branch_count": len(branches),
            "direct_call_count": sum(b["kind"] == "CALL" and b["direct_target_va"] is not None for b in branches),
            "indirect_control_flow_count": sum(b["target_relation"] == "INDIRECT_OR_NONE" and b["kind"] in ("CALL", "JUMP") for b in branches),
            "direct_target_inside_misaligned_count": sum(b["target_relation"] == "INSIDE_MISALIGNED" for b in branches),
            "literal_addressing_candidates": literal_refs,
            "trap_or_undefined_markers": trap_markers,
            "syntactic_basic_blocks": blocks, "syntactic_basic_block_count": len(blocks),
            "source_windows": windows, "source_window_count": len(windows),
            "code_data_ambiguity_note": "Full Capstone decode does not prove every FDE byte is executable code."}
