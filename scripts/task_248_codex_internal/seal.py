"""Verify TASK_248's original-byte evidence and seal a bounded partial report."""

from __future__ import annotations

import hashlib
import json
from collections import Counter
from pathlib import Path

from run import (HERE, ORIGINAL, PRIOR_RAW, PROJECT, REPORT, ROOT, SOURCE,
                 STANDARD, TASK, SHA, TARGETS, FENCE, LEASE, guard, json_write, now, project_hashes,
                 sha, write)


def read(rel: str) -> dict:
    return json.loads((REPORT / rel).read_text(encoding="utf-8"))


def h(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def check(condition: bool, description: str) -> None:
    if not condition:
        raise RuntimeError(description)


def main() -> None:
    guard()
    check(not (REPORT / "COMPLETE.json").exists(), "already sealed")
    manifest = json.loads(TARGETS.read_text(encoding="utf-8"))
    target = manifest["targets"][0]
    base, size = int(target["elf_va"], 16), target["size_bytes"]
    with SOURCE.open("rb") as f:
        f.seek(int(target["file_offset"], 16))
        body = f.read(size)
    check(len(body) == 27524 and h(body) == target["body_sha256"], "original body changed")
    check(manifest["selected_count"] == 1 and target["global_index"] == 253, "target changed")

    receipt, cfg, gap = read("source_and_prior_receipt.json"), read("source_cfg.json"), read("omitted_subregion.json")
    prior = json.loads(PRIOR_RAW.read_text(encoding="utf-8"))
    check(sha(PRIOR_RAW) == receipt["prior_raw_sha256"], "prior raw changed")
    check(prior["ghidra_memory_sha256"] == h(body) and prior["fde_byte_membership_count"] == 25916,
          "prior memory/body evidence changed")
    check(prior["ghidra_instruction_count"] == 6479 and
          prior["missing_analyzed_instruction_count"] == 402 and
          prior["fde_missing_body_ranges"] == [{"start_offset": 25912, "end_exclusive": 27520}] and
          "timeout" in prior["decompile_error"].lower() and not prior["c_like_nonempty"],
          "prior gap/timeout evidence changed")
    check(project_hashes(ORIGINAL) == receipt["original_project_file_hashes"] and
          project_hashes(PROJECT) == receipt["original_project_file_hashes"],
          "private or accepted project changed")

    check(cfg["source_sha256"] == h(body) and cfg["source_bytes"] == size and
          cfg["source_words"] == 6881 and len(cfg["instructions"]) == 6881,
          "CFG source inventory mismatch")
    for i, word in enumerate(cfg["instructions"]):
        check(int(word["va"], 16) == base + 4*i and word["word_le"] == body[4*i:4*i+4].hex(),
              f"CFG word mismatch at {i}")
    cursor = base
    for block in cfg["blocks"]:
        start, end = int(block["start_va"], 16), int(block["end_exclusive_va"], 16)
        check(start == cursor and end > start and (end-start)//4 == block["instruction_count"] and
              block["body_sha256"] == h(body[start-base:end-base]), f"CFG block mismatch at {start:x}")
        cursor = end
    check(cursor == base+size and len(cfg["blocks"]) == 1187 and len(cfg["branch_sites"]) == 915,
          "CFG coverage/count mismatch")
    samples = receipt["independent_spread_word_indices"]
    check(len(samples) == len(set(samples)) == 690 and samples[0] == 0 and samples[-1] == 6880 and
          all(0 <= i < 6881 for i in samples), "spread sample invalid")
    check(receipt["independent_full_body_reread"] and receipt["independent_spread_words_checked"] == 690,
          "independent read receipt invalid")

    check((gap["start_offset"], gap["end_exclusive_offset"], gap["source_bytes"], gap["original_words"]) ==
          (25912, 27520, 1608, 402), "gap range changed")
    gap_bytes = body[25912:27520]
    check(gap["source_sha256"] == h(gap_bytes) and len(gap["instructions"]) == 402,
          "gap original bytes mismatch")
    for i, word in enumerate(gap["instructions"]):
        check(int(word["elf_va"], 16) == base+25912+4*i and
              word["offset_in_fde"] == 25912+4*i and
              word["word_le"] == gap_bytes[4*i:4*i+4].hex(), f"gap word mismatch {i}")
    check(len(gap["branch_or_call_rows"]) == gap["branch_or_call_sites"] == 240 and
          not gap["direct_branches_into_region_from_outside"] and
          len(gap["direct_branches_out_of_region"]) == 1, "gap branch inventory mismatch")

    alternate = read("alternate/styles.json")
    acmd = read("alternate/command.json")
    check(acmd["status"] == "OUTPUT_READY" and acmd["max_cpu"] == 1 and
          acmd["max_heap"] == "1G" and acmd["per_decompile_timeout_seconds"] == 15 and
          sha(REPORT / "alternate/styles.json") == acmd["result_sha256"] and
          sha(REPORT / "alternate/stdout.log") == acmd["stdout_sha256"] and
          sha(REPORT / "alternate/stderr.log") == acmd["stderr_sha256"] and
          sha(HERE / "Alternate248.java") == acmd["java_script_sha256"],
          "alternate command/log/script hash mismatch")
    check(alternate["source_memory_sha256"] == h(body) and
          (alternate["function_body_bytes"], alternate["instruction_slots"],
           alternate["missing_analyzed_instruction_slots"], alternate["pcode_ops"]) ==
          (25916, 6479, 402, 19731), "alternate original membership mismatch")
    styles = alternate["styles"]
    check([s["style"] for s in styles] == ["firstpass", "register", "normalize"] and
          all(not s["c_like_nonempty"] and not s["c_like_text"] and
              s["c_like_sha256"] == h(b"") for s in styles) and
          styles[0]["decompile_completed"] and styles[1]["decompile_completed"] and
          not styles[2]["decompile_completed"] and "timeout" in styles[2]["error"].lower() and
          styles[2]["elapsed_ms"] >= 15000, "alternate result mismatch")

    high = read("register_ir/result.json")
    hcmd = read("register_ir/command.json")
    check(hcmd["status"] == "OUTPUT_READY" and hcmd["max_cpu"] == 1 and
          hcmd["max_heap"] == "1G" and hcmd["per_decompile_timeout_seconds"] == 15 and
          sha(REPORT / "register_ir/result.json") == hcmd["result_sha256"] and
          sha(REPORT / "register_ir/stdout.log") == hcmd["stdout_sha256"] and
          sha(REPORT / "register_ir/stderr.log") == hcmd["stderr_sha256"] and
          sha(HERE / "HighIR248.java") == hcmd["java_script_sha256"],
          "high IR command/log/script mismatch")
    check(high["source_memory_sha256"] == h(body) and high["decompile_completed"] and
          high["high_function_present"] and not high["error"] and
          high["high_ir_ops"] == len(high["ops"]) == 86817 and
          high["unique_source_instruction_vas"] == 6372, "high IR inventory mismatch")
    counts = Counter()
    for op in high["ops"]:
        va = int(op["elf_va"], 16)
        check(base <= va < base+size and (va-base)%4 == 0, "IR op source VA outside original FDE")
        counts[va] += 1
    check(len(counts) == 6372, "IR source VA count mismatch")
    missing = [base+4*i for i in range(6881) if base+4*i not in counts]
    check(len(missing) == 509 and sum(base+25912 <= va < base+27520 for va in missing) == 402,
          "IR address gap count mismatch")
    json_write(REPORT / "ir_source_map.json", {
        "classification": "REGISTER_HIGH_IR_SOURCE_ADDRESS_MAP_NOT_C_LIKE_OR_SEMANTIC_COVERAGE",
        "original_body_sha256": h(body), "high_ir_ops": len(high["ops"]),
        "mapped_distinct_original_word_vas": len(counts),
        "mapped": [{"elf_va": f"0x{va:x}", "word_le": body[va-base:va-base+4].hex(),
                    "ir_op_count": counts[va]} for va in sorted(counts)],
        "absent_original_word_vas": [f"0x{va:x}" for va in missing],
        "absent_in_prior_body_gap": 402, "absent_elsewhere": 107,
        "limitation": "Optimized IR address absence is not evidence of unreachable or semantically absent code."})
    json_write(REPORT / "verification.json", {
        "task_id": "TASK_248", "revision": 1, "generated_at": now(),
        "original_so_sha256": receipt["source_sha256"], "original_body_sha256": h(body),
        "original_bytes_rehashed": size, "original_words_rechecked": 6881,
        "independent_spread_words_rechecked": len(samples),
        "spread_ratio": round(len(samples)/6881, 6),
        "static_cfg_blocks_verified": len(cfg["blocks"]),
        "static_cfg_branch_sites": len(cfg["branch_sites"]),
        "high_ir_ops_source_bound": len(high["ops"]),
        "high_ir_distinct_source_word_vas": len(counts),
        "high_ir_absent_original_word_vas": len(missing),
        "prior_ghidra_body_bytes": 25916, "prior_ghidra_missing_body_bytes": 1608,
        "prior_ghidra_missing_instruction_slots": 402,
        "c_like_bodies_recovered": 0, "full_fde_ghidra_body_membership": False,
        "source_semantics_or_runtime_validated": False,
        "disposition": "BOUNDED_PARTIAL_CFG_IR_RESEARCH_CANDIDATE"})
    report = f"""# TASK_248 R1 — bounded correction for libPVGCodec.so FDE253

**Disposition: PARTIAL research candidate for independent CEO review.** This work adds an original-byte static CFG, a bounded optimized HighFunction IR address map, and an explicit disassembly of the previously omitted region. It recovers **zero C-like function bodies** and does not close the oversized target.

The source is `{SOURCE}` SHA-256 `{receipt['source_sha256']}`. The pinned nonexport FDE index 253 begins at ELF VA `0xa8b08` and has {size:,} original bytes ({size//4:,} aligned ARM64 words), SHA-256 `{h(body)}`. Original ELF, executable PT_LOAD mapping, FDE and nonexport status were checked in `source_and_prior_receipt.json`. Its accepted private Ghidra project was copied with matching file hashes; all operations here used the private copy, `-readOnly`, one CPU, 1 GiB heap, and 15 seconds per decompile.

`source_cfg.json` maps every original word and divides this FDE span into {len(cfg['blocks']):,} conservative static blocks with {len(cfg['branch_sites']):,} recorded branch sites; every block was rehashed against original source bytes. An independent source reread and ARM64 decode checked {len(samples):,}/{size//4:,} spread words ({len(samples)/6881:.2%}). This CFG does not resolve indirect targets or prove function boundaries, high-level semantics, or behavior.

The prior Ghidra listing has 25,916/{size:,} bytes in its function body and 6,479/{size//4:,} analyzed instruction slots. Its 1,608-byte/402-word body gap is offset `[25912,27520)`, ELF VA `[0xaf040,0xaf688)`. `omitted_subregion.json` maps all 402 words to original bytes and records 240 direct branch/call sites there. There are zero direct branches into this region from outside and one direct branch out in the static map; preceding fallthrough remains possible, so reachability is unresolved. This region contains executable-looking ARM64 control-flow instructions, but its Ghidra body membership and analysis are still absent.

`alternate/styles.json` preserves three bounded decompile outcomes: `firstpass` completed in {styles[0]['elapsed_ms']} ms, `register` in {styles[1]['elapsed_ms']} ms, each with empty C-like text; `normalize` timed out in {styles[2]['elapsed_ms']} ms with no C-like text. The original TASK_233 whole-function timeout and zero C-like result are preserved by hash and in `source_and_prior_receipt.json`. `register_ir/result.json` holds {len(high['ops']):,} optimized IR ops from a {high['elapsed_ms']:,} ms HighFunction run, each mapped to an aligned VA inside the original FDE. They refer to {len(counts):,} distinct original instruction VAs. `ir_source_map.json` maps those addresses to source words and lists {len(missing)} addresses absent from this optimized IR: all 402 in the Ghidra body gap and 107 elsewhere. IR address absence cannot establish semantic absence or unreachable code.

The unresolved items are the 1,608-byte Ghidra body gap, 402 unanalyzed original words, 509 original word addresses absent from optimized IR, indirect control flow and call effects, and a complete C-like algorithm. No source reconstruction, behavior parity, device validation, Phase PASS, or V4 readiness is claimed. All raw results, command lines, logs, project/source hashes, and verification counts are included for independent review. No prior result is recounted as a new decoded body.
"""
    write(REPORT / "01_MASTER_REPORT.md", report.encode("utf-8"))
    json_write(REPORT / "PROGRESS.json", {"task_id": "TASK_248", "revision": 1,
        "status": "SEALED_PARTIAL_CANDIDATE", "generated_at": now(),
        "lease_id": LEASE, "fencing_token": FENCE,
        "c_like_bodies_recovered": 0, "report_requires_independent_ceo_review": True})
    guard()
    files = {p.relative_to(REPORT).as_posix(): sha(p) for p in sorted(REPORT.rglob("*"))
             if p.is_file() and p.name not in {"COMPLETE.json", "PROGRESS.json"}}
    code_files = {p.relative_to(ROOT).as_posix(): sha(p) for p in sorted(HERE.rglob("*"))
                  if p.is_file()}
    check(len(files) >= 12 and len(code_files) >= 6, "insufficient package")
    json_write(REPORT / "COMPLETE.json", {
        "schema_version": "2.1.2", "task_id": "TASK_248", "revision": 1, "status": "COMPLETE",
        "semantic_disposition": "BOUNDED_PARTIAL_CFG_IR_RESEARCH_CANDIDATE", "generated_at": now(),
        "standard_path": str(STANDARD), "standard_sha256": SHA[STANDARD],
        "task_sha256": SHA[TASK], "target_manifest_sha256": SHA[TARGETS],
        "review_state": "AWAITING_INDEPENDENT_CEO_REVIEW",
        "lease_id": LEASE, "fencing_token": FENCE,
        "source_sha256": receipt["source_sha256"], "original_fde_body_sha256": h(body),
        "ordinary_records_total": 1, "source_bodies_rehashed": 1,
        "ordinary_records_independently_rechecked": 1,
        "ordinary_words_total": 6881, "ordinary_words_independently_rechecked": 690,
        "c_like_bodies_recovered": 0, "full_fde_ghidra_body_membership": False,
        "unresolved_original_gap_bytes": 1608,
        "independent_review_required": True,
        "files": files, "code_files": code_files})
    sealed = read("COMPLETE.json")
    check(all(sha(REPORT / k) == v for k, v in sealed["files"].items()) and
          all(sha(ROOT / k) == v for k, v in sealed["code_files"].items()), "seal hash mismatch")
    actual = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*")
              if p.is_file() and p.name not in {"COMPLETE.json", "PROGRESS.json"}}
    check(actual == set(files), "seal report inventory mismatch")
    print(json.dumps({"stage": "SEALED_PARTIAL", "complete_sha256": sha(REPORT / "COMPLETE.json"),
                      "files": len(files), "code_files": len(code_files),
                      "c_like_bodies_recovered": 0, "spread_words": len(samples)}), flush=True)


if __name__ == "__main__":
    main()
