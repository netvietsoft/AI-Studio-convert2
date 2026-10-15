"""Independently check TASK_207 raw evidence and seal a bounded research candidate."""
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
    chunks = json.loads((REPORT / "chunk_index.json").read_text(encoding="utf-8"))["chunks"]
    flow = json.loads((REPORT / "source_flow.json").read_text(encoding="utf-8"))
    blob = (REPORT / "original_selected_bodies.bin").read_bytes()
    if (len(targets) != len(source_index["targets"]) or len(targets) != len(assembly)
            or len(targets) != len(flow["targets"]) or len(targets) != 128 or len(chunks) != 8):
        raise RuntimeError("manifest/preflight/chunk count mismatch")

    original = SOURCE.read_bytes()
    if hashlib.sha256(original).hexdigest() != SOURCE_SHA or len(original) != 5544776:
        raise RuntimeError("original SO hash/size changed")
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        if elf["e_machine"] != "EM_AARCH64":
            raise RuntimeError("source architecture differs")
        fdes = sorted((int(e["initial_location"]), int(e["address_range"]))
                      for e in elf.get_dwarf_info().EH_CFI_entries() if isinstance(e, FDE))
        dyn = elf.get_section_by_name(".dynsym")
        section = elf.get_section_by_name(".text")
        text_identity = {"elf_va":hex(int(section["sh_addr"])),
                         "size_bytes":int(section["sh_size"]),
                         "file_offset":hex(int(section["sh_offset"])),
                         "sha256":hashlib.sha256(section.data()).hexdigest()}
        exports = [(int(s["st_value"]), int(s["st_size"])) for s in dyn.iter_symbols()
                   if s["st_info"]["type"] == "STT_FUNC" and s["st_shndx"] != "SHN_UNDEF"
                   and int(s["st_size"]) > 0]
        starts = {va for va, _ in exports}
        candidates = sorted((va, size) for va, size in fdes if size > 0 and va not in starts)
        loads = [(i, int(p["p_vaddr"]), int(p["p_offset"]), int(p["p_filesz"]))
                 for i, p in enumerate(elf.iter_segments()) if p["p_type"] == "PT_LOAD"]
    if (len(fdes) != 8935 or len(starts) != 5082 or len(candidates) != 3853
            or source_index["original_text_section"] != text_identity
            or source_index["all_fde_ranges"] != len(fdes)
            or source_index["export_unique_vas"] != len(starts)
            or source_index["nonexport_fde_candidate_starts"] != len(candidates)):
        raise RuntimeError("ELF FDE/export census differs")
    expected = [(i,va,size) for i,(va,size) in enumerate(candidates) if 128 <= i <= 255]
    observed = [(t["global_nonexport_fde_index"],int(t["elf_va"],16),t["size_bytes"]) for t in targets]
    if (observed != expected or len(expected) != 128 or
            sum(size for _,_,size in expected) != 14620 or
            max(size for _,_,size in expected) > 4096 or
            hashlib.sha256(blob).hexdigest() != source_index["selected_body_blob_sha256"]):
        raise RuntimeError("selection no longer equals candidate slice 128..255")

    identity_path = REPORT / "identity" / "program_identity.json"
    identity_receipt_path = REPORT / "identity" / "ghidra_command.json"
    identity = json.loads(identity_path.read_text(encoding="utf-8"))
    identity_receipt = json.loads(identity_receipt_path.read_text(encoding="utf-8"))
    identity_args = identity_receipt["command"]
    if (identity_receipt["status"] != "IDENTITY_PROVEN" or identity_receipt["exit_code"] != 0
            or identity_receipt["termination"] is not None or identity_receipt["elapsed_seconds"] > 1200
            or identity_receipt["output_sha256"] != sha256(identity_path)
            or identity_receipt["stdout_sha256"] != sha256(REPORT/"identity/ghidra_stdout.log")
            or identity_receipt["stderr_sha256"] != sha256(REPORT/"identity/ghidra_stderr.log")
            or identity_receipt["target_tsv_sha256"] != sha256(REPORT/"identity_targets.tsv")
            or identity_receipt["script_sha256"] != sha256(CODE/"VerifyLayerFlow207.java")
            or identity_receipt["lease_id"] != LEASE_ID or identity_receipt["fencing_token"] != FENCE
            or identity_receipt["fresh_imports"] != 0 or identity_receipt["read_only_project"] is not True
            or identity_args[3:10] != ["-process", "libLayerFlow.so", "-noanalysis", "-readOnly", "-max-cpu", "1", "-scriptPath"]
            or "VerifyLayerFlow207.java" not in identity_args
            or identity["program_name"] != "libLayerFlow.so"
            or "AARCH64" not in identity["language_id"].upper() or identity["endian"] != "LITTLE"
            or identity["source_text_sha256"] != text_identity["sha256"]
            or identity["source_text_elf_va"] != text_identity["elf_va"]
            or identity["source_text_size_bytes"] != text_identity["size_bytes"]
            or identity["program_text_memory_sha256"] != text_identity["sha256"]
            or identity["full_text_bytes_match"] is not True or identity["target_count"] != 128
            or identity["memory_body_sha256_matches"] != 128 or len(identity["targets"]) != 128
            or identity["executable_sha256_metadata"].lower() != SOURCE_SHA
            or [x["index"] for x in identity["targets"]] != list(range(1,129))
            or any(x["elf_va"] != t["elf_va"] or x["size_bytes"] != t["size_bytes"] or
                   x["source_body_sha256"] != t["body_sha256"] or
                   x["program_memory_body_sha256"] != t["body_sha256"] or
                   x["body_bytes_match"] is not True
                   for x,t in zip(identity["targets"],targets))):
        raise RuntimeError("unreviewed technical-cache source/Program identity not proven")

    raw = []
    commands = []
    for chunk in chunks:
        folder = REPORT / f"chunk_{chunk['chunk']:02d}"
        command = json.loads((folder / "ghidra_command.json").read_text(encoding="utf-8"))
        rows = [json.loads(line) for line in (folder / "ghidra_raw.ndjson").read_text(encoding="utf-8").splitlines()]
        expected = list(range(chunk["start_index"], chunk["end_index"]+1))
        if (command["task_id"] != "TASK_207" or command["status"] != "OUTPUT_READY" or
                command["exit_code"] != 0 or command["rows"] != len(rows) or
                [r["index"] for r in rows] != expected or len(rows) != len(expected) or
                command["rows_body_bytes_match"] != len(expected) or command["row_indices_match"] is not True or
                command["elapsed_seconds"] > 1200 or command["timeout_seconds"] > 1200 or
                command["fresh_imports"] != 0 or command["read_only_project"] is not True or
                command["lease_id"] != LEASE_ID or command["fencing_token"] != FENCE):
            raise RuntimeError(f"bounded Ghidra receipt failed: {folder}")
        args = command["command"]
        if (args[3:10] != ["-process", "libLayerFlow.so", "-noanalysis", "-readOnly", "-max-cpu", "1", "-scriptPath"] or
                "-postScript" not in args or "ExportInternal207.java" not in args):
            raise RuntimeError(f"Ghidra command options differ: {folder}")
        for key, filename in (("stdout_sha256", "ghidra_stdout.log"),
                              ("stderr_sha256", "ghidra_stderr.log"),
                              ("raw_output_sha256", "ghidra_raw.ndjson"),
                              ("target_tsv_sha256", "targets.tsv")):
            if command[key] != sha256(folder / filename):
                raise RuntimeError(f"Ghidra receipt hash differs: {folder}/{filename}")
        if command["script_sha256"] != sha256(CODE / "ExportInternal207.java"):
            raise RuntimeError(f"Ghidra exporter changed after execution: {folder}")
        raw.extend(rows)
        commands.append(command)
    if [r["index"] for r in raw] != list(range(1,129)):
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
    blob_cursor = 0
    for j, (target, ix, asm, row) in enumerate(zip(targets, source_index["targets"], assembly, raw), 1):
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
                ix["selected_body_blob_offset"] != blob_cursor or blob[blob_cursor:blob_cursor+size] != body or
                ix["overlapping_export_starts"] or ix["overlapping_other_fde_starts"]):
            raise RuntimeError(f"original FDE/PT_LOAD/body check differs at row {j}")
        if flow["targets"][j-1] != build_flow(target["global_nonexport_fde_index"], va, body):
            raise RuntimeError(f"original source branch/block/window evidence differs at row {j}")
        blob_cursor += size
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
        if row["c_like_present"]:
            if not row["c_like_text"].strip() or hashlib.sha256(
                    row["c_like_text"].encode("utf-8")).hexdigest() != row["c_like_sha256"]:
                raise RuntimeError(f"C-like text/hash differs at row {j}")
            c_like += 1
        elif row["c_like_text"] or row["c_like_sha256"]:
            raise RuntimeError(f"C-like absence claim differs at row {j}")
        exact += row["c_like_present"] and row["boundary_classification"] == "GHIDRA_BODY_EQUALS_FDE_RANGE"
    if source_slots != 3655 or blob_cursor != len(blob) or len(sample) / source_slots < .10:
        raise RuntimeError("source instruction count/spread recheck insufficient")

    original_project = files(PRIOR_PROJECT)
    copied_project = files(PROJECT)
    copy_receipt = json.loads((REPORT/"project_copy_receipt.json").read_text(encoding="utf-8"))
    pre_project = copy_receipt["private_copy_file_sha256"]
    changed_project_paths = sorted(key for key in set(pre_project) | set(copied_project)
                                   if pre_project.get(key) != copied_project.get(key))
    allowed_metadata_drift = {"LayerFlowHair146.rep/idata/~index.bak",
                              "LayerFlowHair146.rep/idata/~journal.bak"}
    core_program_files = ["LayerFlowHair146.rep/idata/00/~00000000.db/db.1.gbf",
                          "LayerFlowHair146.rep/idata/~index.dat"]
    archive = ROOT / ".ai/ceo/reviews/TASK_206_GHIDRA_TECHNICAL_CACHE.zip"
    if (len(original_project) != 10 or original_project != pre_project or
            not set(changed_project_paths).issubset(allowed_metadata_drift) or
            any(pre_project.get(key) != copied_project.get(key) for key in core_program_files) or
            original_project != copy_receipt["technical_cache_file_sha256"] or
            original_project != copy_receipt["archive_member_sha256"] or
            copy_receipt["technical_cache_archive_sha256"] != sha256(archive) or
            copy_receipt["original_cache_archive_member_hashes_match"] is not True or
            copy_receipt["technical_cache_status"] != "UNREVIEWED" or
            copy_receipt["copy_byte_hashes_match"] is not True):
        raise RuntimeError("unreviewed technical-cache/private Ghidra project hashes differ")
    write_json(REPORT/"project_postrun_receipt.json", {
        "task_id":"TASK_207","revision":1,"generated_at":now(),
        "technical_cache_path":str(PRIOR_PROJECT),"private_project_path":str(PROJECT),
        "technical_cache_status":"UNREVIEWED","identity_probe_status":"IDENTITY_PROVEN",
        "technical_cache_file_sha256":original_project,
        "private_pre_file_sha256":pre_project,"private_post_file_sha256":copied_project,
        "private_pre_post_hashes_match":not changed_project_paths,"private_metadata_backup_drift_paths":changed_project_paths,
        "program_gbf_and_core_index_hashes_unchanged":True,
        "read_only_command_did_not_prevent_private_metadata_backup_changes":bool(changed_project_paths)})

    kinds = dict(Counter(r["boundary_classification"] for r in raw))
    missing_rows = [r for r in raw if r["fde_missing_bytes"]]
    extra_rows = [r for r in raw if r["extra_body_bytes"]]
    disposition = "BOUNDED_STATIC_FDE_MATCH" if exact == 128 and not changed_project_paths else "PARTIAL_STATIC_FDE_BOUNDARY_OR_METADATA"
    write_json(REPORT/"independent_verification.json", {
        "task_id":"TASK_207","revision":1,"generated_at":now(),
        "source_fde_pt_load_body_hash_rows_checked":128,
        "source_branch_block_window_rows_checked":128,
        "source_capstone_positions_checked":source_slots,
        "ghidra_memory_sha_rows_checked":128,
        "ghidra_function_body_byte_membership_rows_checked":128,
        "ghidra_instruction_records_checked":source_slots,
        "ghidra_listing_positions_observed":listed_slots,
        "ghidra_nonempty_pcode_positions_observed":pcode_slots,
        "ghidra_listing_positions_with_empty_pcode":listed_slots-pcode_slots,
        "c_like_text_hashes_checked":c_like,
        "spread_source_instruction_words_checked":len(sample),
        "spread_source_instruction_fraction":len(sample)/source_slots,
        "spread_sample":sample,
        "bounded_process_receipts_verified":len(commands),
        "unreviewed_cache_identity_proven":True,
        "technical_cache_files_unchanged":len(original_project),
        "private_project_core_program_files_unchanged":True,
        "private_project_metadata_backup_drift_paths":changed_project_paths})
    write_json(REPORT/"candidate_index.json", {
        "task_id":"TASK_207","revision":1,"target_count":128,
        "source_instruction_slots":source_slots,"ghidra_listing_positions":listed_slots,
        "ghidra_nonempty_pcode_positions":pcode_slots,"ghidra_pcode_ops":pcode_ops,
        "ghidra_function_c_like_count":c_like,"whole_fde_exact_body_c_like_count":exact,
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
    one_slot_indices = [t["global_nonexport_fde_index"] for t in targets if t["size_bytes"] == 4]
    stub_note = (f"One-instruction indices {one_slot_indices} may be stubs or thunks."
                 if one_slot_indices else "No one-instruction FDE candidates occur in this slice.")
    boundary_note = (f"The gaps total {sum(r['fde_missing_bytes'] for r in missing_rows)} bytes, or "
                     f"{sum(r['fde_missing_bytes'] for r in missing_rows)//4} four-byte positions. "
                     "They remain PARTIAL: an FDE can cover data or code that Ghidra did not put in the function body."
                     if missing_rows else "No FDE body bytes are missing from Ghidra function bodies in this slice.")
    metadata_note = (f"Despite `-readOnly`, the private project's backup metadata changed at "
                     f"{changed_project_paths}; exact pre/post hashes are retained."
                     if changed_project_paths else
                     "The private project file hashes stayed unchanged after `-readOnly` runs.")
    audit = f"""# TASK_207 R1 audit index

- Canonical Standard fully read before writes: `{STANDARD}`; SHA-256 `{STANDARD_SHA}`; controller claim standard-read ACK `{lease['acquired_at']}`.
- Exact ACTIVE task: `RULES/TASK/TASK_207_SO45_CODEX_INTERNAL_ACTIVE.md`; SHA-256 `{TASK_SHA}`.
- Target manifest: `.ai/ceo/reviews/TASK_207_internal_targets.json`; SHA-256 `{MANIFEST_SHA}`; exact VA-sorted nonexport FDE candidate indices 128..255, no exclusions in this slice.
- Actual agent/lease/fence: `{AGENT_ID}` / `{LEASE_ID}` / `{FENCE}`.
- Original source: `{SOURCE}`; SHA-256 `{SOURCE_SHA}`. TASK_146 project at `{PRIOR_PROJECT}` is an UNREVIEWED technical cache. Ten original file hashes matched the CEO archive `{archive}` SHA-256 `{sha256(archive)}`, matched the initial private copy and remained unchanged in the original cache. Read-only Ghidra identity probe matched the pinned executable metadata SHA, original full `.text` bytes and all 128 selected original body hashes before candidate extraction. {metadata_note} Core Program GBF/index files stayed byte-identical.
- `source_index.json`, `original_selected_bodies.bin`, `source_assembly.ndjson` and `source_flow.json` record every selected source FDE/PT_LOAD body, instruction position and syntactic branch/block/window. Eight `chunk_XX/` folders preserve per-candidate raw Ghidra output, target TSV, command receipts, stdout and stderr.
- `identity/` retains the probe command, program identity, stdout and stderr. `project_copy_receipt.json` and `project_postrun_receipt.json` contain exact before/after file hashes, including the private backup-metadata drift. `candidate_index.json` and `independent_verification.json` give boundary/accounting and spread checks.
- `COMPLETE.json` hashes every fixed report file and code script; CEO independent review remains pending. No source/product/V4/45-SO acceptance is claimed.
"""
    atomic_bytes(REPORT/"00_AUDIT_INDEX.md", audit.encode("utf-8"))
    master = f"""# TASK_207 R1 - bounded LayerFlow nonexport FDE slice

The exact zero-based VA-sorted nonexport FDE slice **128..255** contains 128 ranges, {source_slots:,} AArch64 instruction positions and 14,620 original bytes in pinned `libLayerFlow.so`. No index in this slice exceeds 4,096 bytes. The ELF has 8,935 FDE ranges, 5,082 defined nonzero-size function export starts and 3,853 nonexport FDE candidates. With TASK_206's disjoint earlier slice, 256 candidates have been selected and another 3,597 remain unselected. FDE ranges are unwind metadata, not proof of unique complete source functions. {stub_note}

All 128 original FDE ranges, PT_LOAD translations and body SHA-256 values match the manifest; Capstone decoded {source_slots:,}/{source_slots:,} positions. Syntactic branch, block and 256-byte source-window records are retained; their code/data ambiguity is explicit. The TASK_146 analyzed Ghidra project was treated only as an UNREVIEWED technical cache. Its ten files matched the CEO technical-cache archive and were copied byte-for-byte to private scratch. Before candidate extraction, a read-only identity probe matched pinned executable SHA metadata, all 2,561,972 original `.text` bytes and 128/128 selected original body hashes. All ten files of the original cache stayed unchanged. Private core Program GBF/index files stayed byte-identical. {metadata_note} No restoration was attempted. Eight sequential candidate runs used `-max-cpu 1`, a configured 1 GiB heap, no fresh import, a 20-minute cap per process and 10 seconds per decompile. Raw commands, logs and candidate outputs are retained.

Ghidra memory SHA matches 128/128 original bodies. Listing appears at **{listed_slots:,}/{source_slots:,}** source positions. Nonempty p-code appears at **{pcode_slots:,}/{source_slots:,}** source positions, comprising {pcode_ops:,} operations; {listed_slots-pcode_slots:,} listed positions have empty p-code. These are separate counts. C-like text exists for {c_like}/128 original Ghidra function objects; **{exact}/128** have whole-byte Ghidra function-body membership exactly equal to the corresponding FDE range. **{len(missing_rows)}** rows have missing FDE body bytes and **{len(extra_rows)}** have extra Ghidra body bytes. Boundary classifications: `{kinds}`. Gap rows, if any:

{gap_lines}

{boundary_note} No other function metadata was removed, and no transient function correction was attempted. Full per-byte membership bitmaps, body/missing/extra ranges, instruction and p-code text, C-like text/hash, calls and failures are preserved per row in the raw NDJSON.

The task verifier independently reparsed the original ELF and rechecked all 128 FDE/PT_LOAD/body hashes, all {source_slots:,} source Capstone positions, 128 source branch/block/window records, all 128 Ghidra memory hashes and per-byte body membership claims, {source_slots:,} Ghidra slot records and {c_like} C-like hashes. Its {len(sample):,} distinct spread source-word checks cover {len(sample)/source_slots:.2%} of instruction positions; each sampled source word is recorded. This is an internal consistency check of the preserved Ghidra output; the CEO has not yet independently replayed Ghidra.

Research disposition: **{disposition}** for this exact FDE candidate slice. Any differing function-body boundaries and private Ghidra metadata drift remain explicit PARTIAL limits. Original SO, original technical cache and private core Program GBF bytes are separately evidenced. Dynamic behavior, call semantics, pixel/device parity, product Phase PASS, V4/P7 and completion of all 45 SOs are unestablished. `PROJECT_ERROR.md` and `ACQUIREMENTS.md` were consulted but this lease does not permit edits to them. No AGY, self-review, commit or push occurred.
"""
    atomic_bytes(REPORT/"01_MASTER_REPORT.md", master.encode("utf-8"))
    write_json(REPORT/"PROGRESS.json", {
        "task_id":"TASK_207","revision":1,"status":"SEALED_REVIEW_CANDIDATE",
        "generated_at":now(),"agent_id":AGENT_ID,"lease_id":LEASE_ID,"fencing_token":FENCE,
        "target_rows_processed":128,"source_instruction_slots":source_slots,
        "ghidra_listing_positions":listed_slots,"ghidra_nonempty_pcode_positions":pcode_slots,
        "ghidra_c_like_rows":c_like,
        "whole_fde_exact_body_c_like_rows":exact,"research_disposition":disposition})

    check_lease()
    report_files = {p.relative_to(REPORT).as_posix():sha256(p)
                    for p in sorted(REPORT.rglob("*")) if p.is_file() and p.name not in ("PROGRESS.json","COMPLETE.json")}
    code_files = {p.relative_to(ROOT).as_posix():sha256(p) for p in sorted(CODE.rglob("*")) if p.is_file()}
    total_bytes = sum((REPORT/p).stat().st_size for p in report_files)
    if total_bytes > 134217728:
        raise RuntimeError("report exceeds 128 MiB cap")
    complete = {
        "schema_version":"2.1.2","task_id":"TASK_207","revision":1,"status":"COMPLETE",
        "review_status":"REVIEW_CANDIDATE_AWAITING_CEO","research_disposition":disposition,
        "generated_at":now(),"agent_id":AGENT_ID,"lease_id":LEASE_ID,"fencing_token":FENCE,
        "standard_sha256":STANDARD_SHA,"task_sha256":TASK_SHA,"target_manifest_sha256":MANIFEST_SHA,
        "original_so_sha256":SOURCE_SHA,"target_fde_candidate_count":128,
        "excluded_oversized_global_indices":[],
        "source_instruction_slots":source_slots,"ghidra_listing_positions":listed_slots,
        "ghidra_nonempty_pcode_positions":pcode_slots,
        "ghidra_listing_positions_with_empty_pcode":listed_slots-pcode_slots,
        "ghidra_function_c_like_count":c_like,
        "whole_fde_exact_body_c_like_count":exact,"rows_with_missing_fde_bytes":len(missing_rows),
        "rows_with_extra_body_bytes":len(extra_rows),"spread_source_instruction_words":len(sample),
        "spread_source_instruction_fraction":len(sample)/source_slots,
        "ghidra_processes":len(commands)+1,"fresh_imports":0,
        "private_project_metadata_backup_drift_paths":changed_project_paths,
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
