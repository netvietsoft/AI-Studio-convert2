"""Independently check TASK_203 raw evidence and seal a bounded research candidate."""
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
from flow import build_flow


def files(folder: Path) -> dict[str, str]:
    return {p.relative_to(folder).as_posix(): sha256(p)
            for p in sorted(folder.rglob("*")) if p.is_file()}


def interval(text: str) -> tuple[int, int]:
    first, last = text.split("..")
    a, b = int(first, 16), int(last, 16)
    if a > b:
        raise RuntimeError(f"invalid interval: {text}")
    return a, b


def grouped_zero_ranges(bits: str, va: int) -> list[str]:
    result = []
    start = None
    for j, bit in enumerate(bits + "1"):
        if bit == "0" and start is None:
            start = j
        elif bit == "1" and start is not None:
            result.append(f"0x{va + start:x}..0x{va + j - 1:x}")
            start = None
    return result


def verify_body_accounting(row: dict, va: int, size: int) -> None:
    bits = row["fde_membership_bits"]
    if len(bits) != size or set(bits) - {"0", "1"}:
        raise RuntimeError(f"invalid membership bitmap at {va:x}")
    ranges = [interval(x) for x in row["function_body_ranges"]]
    if ranges != sorted(ranges) or any(ranges[j][0] <= ranges[j-1][1] for j in range(1, len(ranges))):
        raise RuntimeError(f"unsorted/overlapping function ranges at {va:x}")
    rebuilt = "".join("1" if any(a <= va+j <= b for a, b in ranges) else "0"
                      for j in range(size))
    if bits != rebuilt:
        raise RuntimeError(f"membership bits disagree with function body ranges at {va:x}")
    total = sum(b-a+1 for a, b in ranges)
    member = bits.count("1")
    extra = total - member
    expected_extra = []
    for a, b in ranges:
        if a < va:
            expected_extra.append(f"0x{a:x}..0x{min(b,va-1):x}")
        if b >= va + size:
            expected_extra.append(f"0x{max(a,va+size):x}..0x{b:x}")
    if (total != row["function_body_address_count"] or
            member != row["fde_member_bytes"] or size-member != row["fde_missing_bytes"] or
            extra != row["extra_body_bytes"] or
            grouped_zero_ranges(bits, va) != row["fde_missing_ranges"] or
            expected_extra != row["extra_body_ranges"]):
        raise RuntimeError(f"function body byte accounting differs at {va:x}")
    if row["fde_start_inside_other_ghidra_function"]:
        expected_class = "FDE_START_INSIDE_EXISTING_GHIDRA_FUNCTION"
    elif not ranges:
        expected_class = "GHIDRA_FUNCTION_ABSENT"
    elif member == size and extra == 0:
        expected_class = "GHIDRA_BODY_EQUALS_FDE_RANGE"
    elif member == size:
        expected_class = "GHIDRA_BODY_CONTAINS_FDE_WITH_EXTRA_BYTES"
    elif "0" in bits[:bits.rfind("1")] if "1" in bits else False:
        expected_class = "FDE_HAS_INTERNAL_GAPS_IN_GHIDRA_BODY"
    elif member:
        expected_class = "GHIDRA_BODY_PREFIX_OF_FDE_RANGE"
    else:
        expected_class = "GHIDRA_BODY_MISSES_ENTIRE_FDE_RANGE"
    if row["boundary_classification"] != expected_class:
        raise RuntimeError(f"function boundary classification differs at {va:x}")


def main() -> None:
    lease = check_lease()
    if (REPORT / "COMPLETE.json").exists():
        raise RuntimeError("an existing COMPLETE seal cannot be overwritten")
    manifest = json.loads(MANIFEST.read_text(encoding="utf-8"))
    targets = manifest["targets"]
    source_index = json.loads((REPORT / "source_index.json").read_text(encoding="utf-8"))
    assembly = [json.loads(line) for line in
                (REPORT / "source_assembly.ndjson").read_text(encoding="utf-8").splitlines()]
    flow_rows = json.loads((REPORT / "source_flow.json").read_text(encoding="utf-8"))["targets"]
    window_rows = json.loads((REPORT / "window_evidence.json").read_text(encoding="utf-8"))["targets"]
    chunks = json.loads((REPORT / "chunk_index.json").read_text(encoding="utf-8"))["chunks"]
    if (len(targets) != len(source_index["targets"]) or len(targets) != len(assembly)
            or len(targets) != len(flow_rows) or len(targets) != len(window_rows)
            or len(targets) != 2 or len(chunks) != 2):
        raise RuntimeError("manifest/preflight/chunk count mismatch")

    original = SOURCE.read_bytes()
    if hashlib.sha256(original).hexdigest() != SOURCE_SHA or len(original) != 380224:
        raise RuntimeError("original SO hash/size changed")
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        if elf["e_machine"] != "EM_AARCH64":
            raise RuntimeError("source architecture differs")
        fdes = sorted((int(e["initial_location"]), int(e["address_range"]))
                      for e in elf.get_dwarf_info().EH_CFI_entries() if isinstance(e, FDE))
        dyn = elf.get_section_by_name(".dynsym")
        exports = [(int(s["st_value"]), int(s["st_size"])) for s in dyn.iter_symbols()
                   if s["st_info"]["type"] == "STT_FUNC" and s["st_shndx"] != "SHN_UNDEF"
                   and int(s["st_size"]) > 0]
        starts = {va for va, _ in exports}
        candidates = sorted((va, size) for va, size in fdes if size > 0 and va not in starts)
        loads = [(i, int(p["p_vaddr"]), int(p["p_offset"]), int(p["p_filesz"]))
                 for i, p in enumerate(elf.iter_segments()) if p["p_type"] == "PT_LOAD"]
    if len(fdes) != 753 or len(starts) != 81 or len(candidates) != 672:
        raise RuntimeError("ELF FDE/export census differs")
    expected = [(i,va,size) for i,(va,size) in enumerate(candidates) if i in (505,556)]
    observed = [(t["global_nonexport_fde_index"],int(t["elf_va"],16),t["size_bytes"]) for t in targets]
    if observed != expected or len(expected) != 2 or [size for _,_,size in expected] != [4500,7068]:
        raise RuntimeError("selection no longer equals oversized candidates 505 and 556")

    raw = []
    commands = []
    for chunk in chunks:
        folder = REPORT / f"chunk_{chunk['chunk']:02d}"
        command = json.loads((folder / "ghidra_command.json").read_text(encoding="utf-8"))
        rows = [json.loads(line) for line in (folder / "ghidra_raw.ndjson").read_text(encoding="utf-8").splitlines()]
        expected = list(range(chunk["start_index"], chunk["end_index"]+1))
        if (command["task_id"] != "TASK_203" or command["status"] != "OUTPUT_READY" or
                command["exit_code"] != 0 or command["rows"] != len(rows) or
                [r["index"] for r in rows] != expected or len(rows) != len(expected) or
                command["rows_body_bytes_match"] != len(expected) or command["row_indices_match"] is not True or
                command["elapsed_seconds"] > 1200 or command["timeout_seconds"] > 1200 or
                command["fresh_imports"] != 0 or command["read_only_project"] is not True or
                command["lease_id"] != LEASE_ID or command["fencing_token"] != FENCE):
            raise RuntimeError(f"bounded Ghidra receipt failed: {folder}")
        args = command["command"]
        if (args[3:10] != ["-process", "libPVGColorFunctions.so", "-noanalysis", "-readOnly", "-max-cpu", "1", "-scriptPath"] or
                "-postScript" not in args or "ExportInternal203.java" not in args):
            raise RuntimeError(f"Ghidra command options differ: {folder}")
        for key, filename in (("stdout_sha256", "ghidra_stdout.log"),
                              ("stderr_sha256", "ghidra_stderr.log"),
                              ("raw_output_sha256", "ghidra_raw.ndjson"),
                              ("target_tsv_sha256", "targets.tsv")):
            if command[key] != sha256(folder / filename):
                raise RuntimeError(f"Ghidra receipt hash differs: {folder}/{filename}")
        if command["script_sha256"] != sha256(CODE / "ExportInternal203.java"):
            raise RuntimeError(f"Ghidra exporter changed after execution: {folder}")
        raw.extend(rows)
        commands.append(command)
    if [r["index"] for r in raw] != [1,2]:
        raise RuntimeError("raw candidate order/uniqueness differs")

    dis = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    source_slots = 0
    listed_slots = 0
    pcode_slots = 0
    pcode_ops = 0
    sample = []
    c_like = 0
    exact = 0
    base = None
    verified_windows = 0
    verified_blocks = 0
    verified_branches = 0
    verified_gap_contexts = 0
    for j, (target, ix, asm, row, flow, window) in enumerate(
            zip(targets, source_index["targets"], assembly, raw, flow_rows, window_rows), 1):
        va, size, offset = int(target["elf_va"],16), target["size_bytes"], int(target["file_offset"],16)
        body = original[offset:offset+size]
        body_hash = hashlib.sha256(body).hexdigest()
        covering = [(seg_ix,vaddr,seg_off,filesz) for seg_ix,vaddr,seg_off,filesz in loads
                    if vaddr <= va and va+size <= vaddr+filesz]
        if (len(covering) != 1 or covering[0][2]+va-covering[0][1] != offset or
                body_hash != target["body_sha256"] or size//4 != target["instruction_slots"] or
                (va,size) not in fdes or va in starts or
                ix["index"] != j or ix["global_nonexport_fde_index"] != target["global_nonexport_fde_index"] or
                asm["global_nonexport_fde_index"] != target["global_nonexport_fde_index"] or
                ix["source_body_sha256"] != body_hash or
                ix["pt_load_segment_index"] != covering[0][0] or
                ix["source_instruction_slots"] != size//4 or ix["capstone_full_decode"] is not True or
                ix["overlapping_export_starts"] or ix["overlapping_other_fde_starts"]):
            raise RuntimeError(f"original FDE/PT_LOAD/body check differs at row {j}")
        decoded = list(dis.disasm(body,va))
        if (len(decoded) != size//4 or asm["index"] != j or asm["elf_va"] != target["elf_va"] or
                len(asm["instructions"]) != len(decoded)):
            raise RuntimeError(f"Capstone source slot coverage differs at row {j}")
        if (row["index"] != j or row["elf_va"] != target["elf_va"] or
                row["fde_size_bytes"] != size or row["instruction_slots"] != size//4 or
                row["original_body_sha256"] != body_hash or
                row["copy_memory_body_sha256"] != body_hash or row["body_bytes_match"] is not True or
                row["function_metadata_created_in_owned_copy"] is not False or
                len(row["instruction_pcode"]) != size//4):
            raise RuntimeError(f"critical Ghidra body/output claim differs at row {j}")
        db = int(row["database_va"],16)
        if base is None:
            base = db-va
        if db-va != base:
            raise RuntimeError(f"Ghidra image base differs at row {j}")
        verify_body_accounting(row,va,size)
        expected_listing = []
        counted_pcode_slots = 0
        counted_pcode_ops = 0
        for k, (instruction, source_row, ghidra_row) in enumerate(zip(decoded, asm["instructions"], row["instruction_pcode"])):
            word = body[4*k:4*k+4].hex()
            if (instruction.address != va+4*k or source_row != {
                    "va": hex(instruction.address), "word_le": word,
                    "mnemonic": instruction.mnemonic, "operands": instruction.op_str} or
                    int(ghidra_row["database_va"],16) != db+4*k or ghidra_row["word_le"] != word):
                raise RuntimeError(f"source/Ghidra instruction position differs row {j} slot {k}")
            if not ghidra_row["missing_instruction"]:
                if not ghidra_row["assembly"].strip():
                    raise RuntimeError(f"empty Ghidra assembly row {j} slot {k}")
                expected_listing.append(ghidra_row["database_va"]+": "+ghidra_row["assembly"])
                counted_pcode_slots += bool(ghidra_row["pcode_ops"])
                counted_pcode_ops += len(ghidra_row["pcode_ops"])
            elif ghidra_row["assembly"] or ghidra_row["pcode_ops"]:
                raise RuntimeError(f"missing Ghidra slot claims code/p-code row {j} slot {k}")
            if source_slots % 8 == 0 or k == 0 or k == len(decoded)-1:
                sample.append({"index":j,"slot":k,"elf_va":hex(va+4*k),"word_le":word,
                               "capstone":instruction.mnemonic+" "+instruction.op_str,
                               "ghidra_missing":ghidra_row["missing_instruction"]})
            source_slots += 1
        if (expected_listing != row["instructions"] or
                len(expected_listing) != row["instruction_count_observed"] or
                counted_pcode_slots != row["pcode_instruction_count"] or
                counted_pcode_ops != row["pcode_op_count"]):
            raise RuntimeError(f"Ghidra listing/p-code accounting differs at row {j}")
        listed_slots += len(expected_listing)
        pcode_slots += counted_pcode_slots
        pcode_ops += counted_pcode_ops
        if (REPORT / f"original_fde_{target['global_nonexport_fde_index']}.bin").read_bytes() != body:
            raise RuntimeError(f"preserved original FDE bytes differ at row {j}")
        recomputed_flow = build_flow(target["global_nonexport_fde_index"], va, body)
        if flow != recomputed_flow:
            raise RuntimeError(f"source branch/block/window evidence differs at row {j}")
        blocks = flow["syntactic_basic_blocks"]
        if (not blocks or int(blocks[0]["start_va"], 16) != va or
                int(blocks[-1]["end_exclusive_va"], 16) != va+size or
                sum(b["instruction_slots"] for b in blocks) != size//4):
            raise RuntimeError(f"syntactic block coverage differs at row {j}")
        for left, right in zip(blocks, blocks[1:]):
            if left["end_exclusive_va"] != right["start_va"]:
                raise RuntimeError(f"syntactic block continuity differs at row {j}")
        verified_blocks += len(blocks)
        verified_branches += len(flow["branch_records"])
        if (window["global_nonexport_fde_index"] != target["global_nonexport_fde_index"] or
                window["elf_va"] != target["elf_va"] or window["size_bytes"] != size or
                window["window_count"] != len(flow["source_windows"]) or
                window["window_source_slots"] != size//4 or
                window["window_ghidra_listing_slots"] != len(expected_listing) or
                window["window_function_missing_bytes"] != row["fde_missing_bytes"] or
                len(window["windows"]) != len(flow["source_windows"])):
            raise RuntimeError(f"bounded window totals differ at row {j}")
        for source_window, merged in zip(flow["source_windows"], window["windows"]):
            start, finish = int(source_window["start_va"], 16), int(source_window["end_exclusive_va"], 16)
            lo, hi = start-va, finish-va
            selected = row["instruction_pcode"][lo//4:hi//4]
            source_part = body[lo:hi]
            selected_branches = [b for b in flow["branch_records"] if start <= int(b["from_va"],16) < finish]
            selected_literals = [b for b in flow["literal_addressing_candidates"] if start <= int(b["from_va"],16) < finish]
            expected_window = {"window_index": source_window["window_index"],
                "start_va": hex(start), "end_exclusive_va": hex(finish),
                "source_body_sha256": hashlib.sha256(source_part).hexdigest(),
                "ghidra_words_sha256": hashlib.sha256(bytes.fromhex("".join(x["word_le"] for x in selected))).hexdigest(),
                "source_instruction_slots": len(selected),
                "ghidra_listing_slots": sum(not x["missing_instruction"] for x in selected),
                "ghidra_pcode_slots": sum(bool(x["pcode_ops"]) for x in selected),
                "ghidra_pcode_ops": sum(len(x["pcode_ops"]) for x in selected),
                "function_member_bytes": row["fde_membership_bits"][lo:hi].count("1"),
                "function_missing_bytes": row["fde_membership_bits"][lo:hi].count("0"),
                "source_branch_count": len(selected_branches),
                "source_direct_call_count": sum(b["kind"] == "CALL" and b["direct_target_va"] is not None for b in selected_branches),
                "source_literal_addressing_candidate_count": len(selected_literals)}
            if merged != expected_window or merged["source_body_sha256"] != merged["ghidra_words_sha256"]:
                raise RuntimeError(f"bounded source/Ghidra window differs at row {j}:{start:x}")
            verified_windows += 1
        if len(window["gap_contexts"]) != len(row["fde_missing_ranges"]):
            raise RuntimeError(f"gap context cardinality differs at row {j}")
        for gap, source_range in zip(window["gap_contexts"], row["fde_missing_ranges"]):
            first, last = interval(source_range)
            lo, hi = first-va, last-va+1
            first_slot, last_slot = lo//4, (hi+3)//4
            target_branches = [b for b in flow["branch_records"] if b["direct_target_va"] is not None
                               and first <= int(b["direct_target_va"],16) <= last]
            source_branches = [b for b in flow["branch_records"] if first <= int(b["from_va"],16) <= last]
            literals = [b for b in flow["literal_addressing_candidates"] if first <= int(b["target_va"],16) <= last]
            overlap_blocks = [b for b in blocks if int(b["start_va"],16) <= last
                              and first < int(b["end_exclusive_va"],16)]
            if (gap["missing_range"] != source_range or gap["size_bytes"] != hi-lo or
                    gap["original_gap_sha256"] != hashlib.sha256(body[lo:hi]).hexdigest() or
                    gap["capstone_decoded_slots_in_gap"] != last_slot-first_slot or
                    gap["ghidra_listing_slots_in_gap"] != sum(not x["missing_instruction"] for x in row["instruction_pcode"][first_slot:last_slot]) or
                    gap["ghidra_pcode_slots_in_gap"] != sum(bool(x["pcode_ops"]) for x in row["instruction_pcode"][first_slot:last_slot]) or
                    gap["source_direct_branch_targets_into_gap"] != target_branches or
                    gap["source_branch_sites_within_gap"] != source_branches or
                    gap["literal_addressing_targets_into_gap"] != literals or
                    gap["syntactic_basic_blocks_overlapping_gap"] != len(overlap_blocks) or
                    gap["context_source_instructions"] != asm["instructions"][max(0,first_slot-4):min(size//4,last_slot+4)]):
                raise RuntimeError(f"gap source/Ghidra context differs at row {j}:{first:x}")
            verified_gap_contexts += 1
        if row["c_like_present"]:
            if not row["c_like_text"].strip() or hashlib.sha256(
                    row["c_like_text"].encode("utf-8")).hexdigest() != row["c_like_sha256"]:
                raise RuntimeError(f"C-like text/hash differs at row {j}")
            c_like += 1
        elif row["c_like_text"] or row["c_like_sha256"]:
            raise RuntimeError(f"C-like absence claim differs at row {j}")
        exact += row["c_like_present"] and row["boundary_classification"] == "GHIDRA_BODY_EQUALS_FDE_RANGE"
    if source_slots != 2892 or len(sample) / source_slots < .10:
        raise RuntimeError("source instruction count/spread recheck insufficient")

    original_project = files(PRIOR_PROJECT)
    copied_project = files(PROJECT)
    copy_receipt = json.loads((REPORT/"project_copy_receipt.json").read_text(encoding="utf-8"))
    prior_receipt_path = ROOT/"RULES/REPORT/TASK_200_REPORT_R1/project_postrun_receipt.json"
    prior_receipt = json.loads(prior_receipt_path.read_text(encoding="utf-8"))
    prior_seal = json.loads((ROOT/"RULES/REPORT/TASK_200_REPORT_R1/COMPLETE.json").read_text(encoding="utf-8"))
    if (len(original_project) != 9 or original_project != copied_project or
            original_project != prior_receipt["file_sha256"] or original_project != prior_seal["scratch_project_files"] or
            copied_project != copy_receipt["private_copy_file_sha256"] or
            original_project != copy_receipt["historical_file_sha256"] or
            sha256(prior_receipt_path) != copy_receipt["historical_postrun_receipt_sha256"]):
        raise RuntimeError("accepted prior/private Ghidra project hashes differ")
    write_json(REPORT/"project_postrun_receipt.json", {
        "task_id":"TASK_203","revision":1,"generated_at":now(),
        "prior_project_path":str(PRIOR_PROJECT),"private_project_path":str(PROJECT),
        "files_verified":len(copied_project),"pre_post_hashes_match":True,"file_sha256":copied_project})

    kinds = dict(Counter(r["boundary_classification"] for r in raw))
    missing_rows = [r for r in raw if r["fde_missing_bytes"]]
    extra_rows = [r for r in raw if r["extra_body_bytes"]]
    disposition = "BOUNDED_STATIC_FDE_MATCH" if exact == 2 else "PARTIAL_OVERSIZED_FDE_BOUNDARY"
    write_json(REPORT/"independent_verification.json", {
        "task_id":"TASK_203","revision":1,"generated_at":now(),
        "source_fde_pt_load_body_hash_rows_checked":2,
        "source_capstone_positions_checked":source_slots,
        "ghidra_memory_sha_rows_checked":2,
        "ghidra_function_body_byte_membership_rows_checked":2,
        "ghidra_instruction_and_pcode_slots_checked":source_slots,
        "original_fde_binary_files_checked":2,
        "syntactic_basic_blocks_checked":verified_blocks,
        "source_branch_records_checked":verified_branches,
        "source_ghidra_windows_checked":verified_windows,
        "gap_contexts_checked":verified_gap_contexts,
        "c_like_text_hashes_checked":c_like,
        "spread_source_instruction_words_checked":len(sample),
        "spread_source_instruction_fraction":len(sample)/source_slots,
        "spread_sample":sample,
        "bounded_process_receipts_verified":len(commands),
        "accepted_prior_and_private_project_files_unchanged":len(copied_project)})
    write_json(REPORT/"candidate_index.json", {
        "task_id":"TASK_203","revision":1,"target_count":2,
        "source_instruction_slots":source_slots,"ghidra_instruction_slots":listed_slots,
        "ghidra_pcode_instruction_slots":pcode_slots,"ghidra_pcode_ops":pcode_ops,
        "ghidra_c_like_count":c_like,"ghidra_exact_fde_c_like_count":exact,
        "rows_with_missing_fde_bytes":len(missing_rows),"rows_with_extra_body_bytes":len(extra_rows),
        "boundary_classifications":kinds,
        "candidates":[{"global_nonexport_fde_index":t["global_nonexport_fde_index"],
                       **{key:r[key] for key in (
            "index","elf_va","fde_size_bytes","original_body_sha256",
            "copy_memory_body_sha256","instruction_slots","instruction_count_observed",
            "pcode_instruction_count","pcode_op_count","function_entry",
            "function_body_address_count","fde_member_bytes","fde_missing_bytes",
            "extra_body_bytes","fde_missing_ranges","extra_body_ranges",
            "boundary_classification","fde_start_inside_other_ghidra_function",
            "c_like_present","c_like_sha256","failure")}} for r,t in zip(raw,targets)]})
    gap_lines = "\n".join(f"- Row {r['index']} `{r['elf_va']}`: {r['fde_missing_bytes']} missing body bytes at "
                          + ", ".join(f"`{x}`" for x in r["fde_missing_ranges"])
                          for r in missing_rows)
    if not gap_lines:
        gap_lines = "None in this slice."
    diagnostics = []
    for target, row, flow, window in zip(targets, raw, flow_rows, window_rows):
        gap_notes = "; ".join(
            f"{g['missing_range']} ({g['size_bytes']} bytes, {g['ghidra_listing_slots_in_gap']} Ghidra listing slots, "
            f"{len(g['source_direct_branch_targets_into_gap'])} direct source branch targets, "
            f"{len(g['source_branch_sites_within_gap'])} source branch sites)"
            for g in window["gap_contexts"])
        diagnostics.append(
            f"- FDE #{target['global_nonexport_fde_index']} `{target['elf_va']}`: {target['size_bytes']} source bytes, "
            f"{flow['decoded_instruction_slots']} decoded positions, {flow['syntactic_basic_block_count']} "
            f"syntactic blocks, {flow['source_window_count']} bounded windows and {flow['branch_count']} "
            f"source branch records. Ghidra membership {row['fde_member_bytes']}/{target['size_bytes']} bytes, "
            f"listing {row['instruction_count_observed']}/{target['instruction_slots']} positions, "
            f"C-like text {'present' if row['c_like_present'] else 'absent'}; missing: {gap_notes or 'none'}."
        )
    diagnostic_lines = "\n".join(diagnostics)
    audit = f"""# TASK_203 R1 audit index

- Canonical Standard fully read before writes: `{STANDARD}`; SHA-256 `{STANDARD_SHA}`; controller claim standard-read ACK `{lease['acquired_at']}`.
- Exact ACTIVE task: `RULES/TASK/TASK_203_SO45_CODEX_INTERNAL_ACTIVE.md`; SHA-256 `{TASK_SHA}`.
- Target manifest: `.ai/ceo/reviews/TASK_203_internal_targets.json`; SHA-256 `{MANIFEST_SHA}`; exact oversized nonexport FDE candidate indices 505 and 556 only.
- Actual agent/lease/fence: `{AGENT_ID}` / `{LEASE_ID}` / `{FENCE}`.
- Original source: `{SOURCE}`; SHA-256 `{SOURCE_SHA}`. Accepted prior TASK_200 project: `{PRIOR_PROJECT}`; nine file hashes matched its sealed postrun receipt and COMPLETE seal before copying.
- `source_index.json`, `source_assembly.ndjson`, `original_fde_505.bin`, `original_fde_556.bin` and `source_flow.json` record original bodies, all positions, branch sites, syntactic blocks and 256-byte windows. `window_evidence.json` joins every source window to raw Ghidra body/listing/p-code positions and records gap contexts. Two `chunk_XX/` folders preserve per-candidate raw Ghidra output, target TSV, command receipts, stdout and stderr.
- `project_copy_receipt.json` and `project_postrun_receipt.json` prove byte-identical private project copy and unchanged read-only files. `candidate_index.json` and `independent_verification.json` give boundary/accounting and spread checks.
- `COMPLETE.json` hashes every fixed report file and code script; CEO independent review remains pending. No source/product/V4/45-SO acceptance is claimed.
"""
    atomic_bytes(REPORT/"00_AUDIT_INDEX.md", audit.encode("utf-8"))
    master = f"""# TASK_203 R1 - targeted oversized PVGColorFunctions FDE diagnosis

Only the two manifest-specified VA-sorted nonexport FDE candidates, **#505** and **#556**, were analyzed. They contain 11,568 original bytes and {source_slots:,} AArch64 positions. Both exceed the 4,096-byte ordinary-slice limit and were previously excluded. The original ELF has 753 FDE ranges, 81 defined nonzero-size function-export starts and 672 nonexport FDE candidate starts. An unwind FDE is a candidate range, not proof of a complete unique function or that every decoded word is executable code. Prior small boundary-PARTIAL indices 506, 550, 553, 554, 557, 558, 620 and 625 remain separate.

The pinned original SO, both PT_LOAD translations, both FDE ranges and body SHA-256 values match the manifest. Every original body byte is preserved in `original_fde_505.bin` and `original_fde_556.bin`; `source_assembly.ndjson` records all {source_slots:,} four-byte words and Capstone positions. `source_flow.json` records {verified_branches} syntactic branch/call/return sites, {verified_blocks} source basic-block candidates and {verified_windows} contiguous 256-byte windows. Direct targets, indirect control flow, literal-addressing candidates and trap markers are recorded there as risk evidence, not proof of reachable code.

The accepted TASK_200 Ghidra project was copied byte-for-byte to private scratch; all nine project file hashes matched before and after two sequential read-only/no-analysis headless runs. Each used `-max-cpu 1`, a configured 1 GiB heap, no fresh import, a 20-minute process cap and 10 seconds per whole-function decompile. Both runs returned a raw row and C-like output. The C-like text describes the existing Ghidra function object and does not establish coverage of FDE bytes outside its body. Ghidra memory hashes match both original bodies; listing coverage is **{listed_slots:,}/{source_slots:,}** source positions and p-code appears on **{pcode_slots:,}/{source_slots:,}** positions with {pcode_ops:,} operations.

Per-FDE bounded findings:

{diagnostic_lines}

The two Ghidra bodies miss {sum(r['fde_missing_bytes'] for r in missing_rows)} FDE bytes ({sum(r['fde_missing_bytes'] for r in missing_rows)//4} four-byte positions). `window_evidence.json` accounts for every source/Ghidra position within {verified_windows} fixed windows and gives source/Ghidra context for each gap. The gap contexts contain syntactic branch targets and branch sites but no Ghidra listing positions; these facts do not settle whether the missing words are intended instructions, embedded data or boundaries of another source function. Both candidates remain **PARTIAL**. No transient metadata correction was attempted, and other function metadata was preserved. Full per-byte membership bitmaps, missing/extra ranges, instruction/p-code text, C-like text/hash, calls, failures, raw commands and logs remain in `chunk_00/` and `chunk_01/`.

The verifier independently reparsed the original ELF and checked both FDE/PT_LOAD/body hashes, all {source_slots:,} original Capstone positions and Ghidra word positions, both byte-level membership maps, {verified_branches} branch records, {verified_blocks} source blocks, {verified_windows} source/Ghidra windows, {verified_gap_contexts} gap contexts, both C-like hashes, command/log hashes and nine project file hashes. It recorded {len(sample):,} spread source-word checks ({len(sample)/source_slots:.2%} of positions). This is internal consistency verification of the retained evidence; CEO replay/review is pending.

Research disposition: **{disposition}** for these two oversized FDE candidates. Dynamic behavior, call semantics, code/data classification of the gaps, pixel/device parity, product Phase PASS, V4/P7 and completion of all 45 SOs remain unestablished. `PROJECT_ERROR.md` and `ACQUIREMENTS.md` were consulted but not edited. No AGY, self-review, commit or push occurred.
"""
    atomic_bytes(REPORT/"01_MASTER_REPORT.md", master.encode("utf-8"))
    write_json(REPORT/"PROGRESS.json", {
        "task_id":"TASK_203","revision":1,"status":"SEALED_REVIEW_CANDIDATE",
        "generated_at":now(),"agent_id":AGENT_ID,"lease_id":LEASE_ID,"fencing_token":FENCE,
        "target_rows_processed":2,"source_instruction_slots":source_slots,
        "ghidra_instruction_slots":listed_slots,"ghidra_c_like_rows":c_like,
        "ghidra_exact_fde_c_like_rows":exact,"research_disposition":disposition})

    check_lease()
    report_files = {p.relative_to(REPORT).as_posix():sha256(p)
                    for p in sorted(REPORT.rglob("*")) if p.is_file() and p.name not in ("PROGRESS.json","COMPLETE.json")}
    code_files = {p.relative_to(ROOT).as_posix():sha256(p) for p in sorted(CODE.rglob("*")) if p.is_file()}
    total_bytes = sum((REPORT/p).stat().st_size for p in report_files)
    if total_bytes > 134217728:
        raise RuntimeError("report exceeds 128 MiB cap")
    complete = {
        "schema_version":"2.1.2","task_id":"TASK_203","revision":1,"status":"COMPLETE",
        "review_status":"REVIEW_CANDIDATE_AWAITING_CEO","research_disposition":disposition,
        "generated_at":now(),"agent_id":AGENT_ID,"lease_id":LEASE_ID,"fencing_token":FENCE,
        "standard_sha256":STANDARD_SHA,"task_sha256":TASK_SHA,"target_manifest_sha256":MANIFEST_SHA,
        "original_so_sha256":SOURCE_SHA,"target_fde_candidate_count":2,
        "oversized_global_indices":[505,556],
        "source_instruction_slots":source_slots,"ghidra_instruction_slots":listed_slots,
        "ghidra_pcode_instruction_slots":pcode_slots,"ghidra_c_like_count":c_like,
        "ghidra_exact_fde_c_like_count":exact,"rows_with_missing_fde_bytes":len(missing_rows),
        "rows_with_extra_body_bytes":len(extra_rows),"spread_source_instruction_words":len(sample),
        "spread_source_instruction_fraction":len(sample)/source_slots,
        "ghidra_processes":len(commands),"fresh_imports":0,
        "syntactic_basic_blocks":verified_blocks,"source_branch_records":verified_branches,
        "source_ghidra_windows":verified_windows,"gap_contexts":verified_gap_contexts,
        "product_phase_pass":False,"behavior_equivalence_tested":False,
        "commit_sha":None,"push_receipt":None,"report_bytes_excluding_progress_and_seal":total_bytes,
        "files":report_files,"code_files":code_files,"scratch_project_files":copied_project}
    write_json(REPORT/"COMPLETE.json",complete)
    print(json.dumps({"status":"SEALED","complete_sha256":sha256(REPORT/"COMPLETE.json"),
                      "source_slots":source_slots,"listed_slots":listed_slots,"c_like":c_like,
                      "exact_fde_c_like":exact,"sample_words":len(sample),
                      "report_file_count":len(report_files),"code_file_count":len(code_files)}))


if __name__ == "__main__":
    main()
