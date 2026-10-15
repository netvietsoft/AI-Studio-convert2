"""Verify exact TASK_247 CFG/IR provenance and seal an honest partial report."""

from __future__ import annotations

import hashlib
import json

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs

from run import (FENCE, HERE, LEASE, ORIGINAL, PRIOR_FRESH, PRIOR_RAW, PRIOR_RETRY,
                 PROJECT, REPORT, ROOT, SHA, SOURCE, STANDARD, TARGETS, TASK,
                 guard, json_write, now, project_hashes, sha, write)


def main() -> None:
    guard()
    if (REPORT / "COMPLETE.json").exists():
        raise RuntimeError("already sealed")
    receipt = json.loads((REPORT / "source_and_prior_receipt.json").read_text(encoding="utf-8"))
    cfg = json.loads((REPORT / "source_cfg.json").read_text(encoding="utf-8"))
    alt_command = json.loads((REPORT / "alternate/command.json").read_text(encoding="utf-8"))
    styles = json.loads((REPORT / "alternate/styles.json").read_text(encoding="utf-8"))
    failed_command = json.loads((REPORT / "high_ir/command.json").read_text(encoding="utf-8"))
    ir_command = json.loads((REPORT / "high_ir_retry/command.json").read_text(encoding="utf-8"))
    high = json.loads((REPORT / "high_ir_retry/result.json").read_text(encoding="utf-8"))
    original = SOURCE.read_bytes()
    body = original[0x1ebdd8:0x1ebdd8 + 2780]
    expected = "2ee0e7f90483583800b9d2f7e93ff3f73456d991585e00cc7d211af010db3cca"
    if (hashlib.sha256(body).hexdigest() != expected or cfg["source_sha256"] != expected or
        receipt["target"]["body_sha256"] != expected or high["source_memory_sha256"] != expected or
        styles["source_memory_sha256"] != expected or receipt["source_sha256"] != SHA[SOURCE]):
        raise RuntimeError("critical source body identity mismatch")
    if receipt["independent_spread_words_checked"] < 70 or len(receipt["independent_spread_word_indices"]) < 70:
        raise RuntimeError("less than 10% ordinary word provenance recheck")
    ins = list(Cs(CS_ARCH_ARM64, CS_MODE_ARM).disasm(body, 0x1ebdd8))
    if len(ins) != 695 or len(cfg["instructions"]) != 695:
        raise RuntimeError("source instruction count mismatch")
    for word, x in zip(cfg["instructions"], ins):
        if word["va"] != f"0x{x.address:x}" or word["word_le"] != bytes(x.bytes).hex():
            raise RuntimeError(f"source CFG word mapping failed at {word['va']}")
    block_words = 0
    for block in cfg["blocks"]:
        a = int(block["start_va"], 16) - 0x1ebdd8
        b = int(block["end_exclusive_va"], 16) - 0x1ebdd8
        if hashlib.sha256(body[a:b]).hexdigest() != block["body_sha256"]:
            raise RuntimeError("CFG block byte hash mismatch")
        block_words += block["instruction_count"]
    if block_words != 695 or len(cfg["blocks"]) != 23 or len(cfg["branch_sites"]) != 18:
        raise RuntimeError("CFG coverage mismatch")
    if (sha(PRIOR_RAW) != receipt["prior_raw_sha256"] or
        sha(PRIOR_RETRY) != receipt["prior_retry_sha256"] or
        sha(PRIOR_FRESH) != receipt["prior_fresh_sha256"]):
        raise RuntimeError("historical raw/retry/fresh evidence changed")
    prior = json.loads(PRIOR_RAW.read_text(encoding="utf-8"))
    retry = json.loads(PRIOR_RETRY.read_text(encoding="utf-8"))
    if ("Unable to find unique hash for varnode" not in prior["decompile_error"] or
        "Unable to find unique hash for varnode" not in retry["decompile_error"]):
        raise RuntimeError("historical failure was not preserved")
    if alt_command["status"] != "OUTPUT_READY" or sha(REPORT / "alternate/styles.json") != alt_command["result_sha256"]:
        raise RuntimeError("alternate decompiler result/command mismatch")
    if failed_command["status"] != "EXIT_ZERO" or failed_command["result_sha256"] is not None:
        raise RuntimeError("initial IR compile failure evidence changed")
    fail_log = (REPORT / "high_ir/stdout.log").read_text(encoding="utf-8", errors="replace")
    if "cannot find symbol" not in fail_log or "HighFunction" not in fail_log:
        raise RuntimeError("initial compile failure log absent")
    if ir_command["status"] != "OUTPUT_READY" or sha(REPORT / "high_ir_retry/result.json") != ir_command["result_sha256"]:
        raise RuntimeError("corrected high IR command/result mismatch")
    for subdir, command in (("alternate", alt_command), ("high_ir", failed_command),
                            ("high_ir_retry", ir_command)):
        if (sha(REPORT / subdir / "stdout.log") != command["stdout_sha256"] or
            sha(REPORT / subdir / "stderr.log") != command["stderr_sha256"]):
            raise RuntimeError(f"{subdir} stdout/stderr changed")
    if (styles["elf_va"] != "0x1ebdd8" or styles["size_bytes"] != 2780 or
        styles["instruction_slots"] != 695 or styles["pcode_ops"] != 3814 or
        styles["function_body_bytes"] != 2780 or
        [x["style"] for x in styles["styles"]] != ["firstpass", "register", "normalize"]):
        raise RuntimeError("alternate style target/metadata mismatch")
    for item in styles["styles"]:
        text = item["c_like_text"]
        if (item["elapsed_ms"] > 15000 or not item["decompile_completed"] or
            item["c_like_nonempty"] or text or
            hashlib.sha256(text.encode("utf-8")).hexdigest() != item["c_like_sha256"]):
            raise RuntimeError("unexpected C-like or timeout in alternate mode")
    if (high["mode"] != "normalize_high_ir_no_c" or not high["decompile_completed"] or
        not high["high_function_present"] or high["elapsed_ms"] > 15000 or
        high["high_ir_ops"] != len(high["ops"])):
        raise RuntimeError("normalized high IR metadata mismatch")
    mapped = set()
    all_rows = []
    for index, op in enumerate(high["ops"]):
        va = int(op["elf_va"], 16)
        db = int(op["database_va"], 16)
        if va + 0x100000 != db:
            raise RuntimeError(f"IR image-base mismatch at {index}")
        if 0x1ebdd8 <= va < 0x1ebdd8 + 2780 and (va - 0x1ebdd8) % 4 == 0:
            mapped.add(va)
            all_rows.append({"ir_index": index, "elf_va": op["elf_va"],
                "original_word_le": body[va-0x1ebdd8:va-0x1ebdd8+4].hex(),
                "opcode": op["opcode"]})
    if len(mapped) != high["unique_source_instruction_vas"] or len(mapped) != 468:
        raise RuntimeError("IR source-address coverage mismatch")
    all_vas = {x.address for x in ins}
    absent = sorted(all_vas - mapped)
    if len(absent) != 227:
        raise RuntimeError("optimized IR absence census mismatch")
    if project_hashes(ORIGINAL) != receipt["original_project_file_hashes"]:
        raise RuntimeError("accepted project changed")
    owned = project_hashes(PROJECT)
    json_write(REPORT / "high_ir_source_mapping.json", {"task_id": "TASK_247",
        "source_body_sha256": expected, "high_ir_ops": len(high["ops"]),
        "mapped_ir_ops": len(all_rows), "distinct_source_word_vas": len(mapped),
        "source_words_without_normalized_high_ir_address": [f"0x{x:x}" for x in absent],
        "absence_interpretation": "optimized IR address absence is not proof of semantic absence",
        "rows": all_rows})
    summary = {"source_fde_index_zero_based": 465, "source_bytes": 2780, "source_words": 695,
        "source_body_sha256": expected, "source_cfg_blocks": 23, "source_cfg_branch_sites": 18,
        "instruction_pcode_ops": 3814, "alternate_styles_completed": 3,
        "alternate_styles_with_c_like": 0, "normalized_high_ir_ops": len(high["ops"]),
        "normalized_high_ir_distinct_source_word_vas": len(mapped),
        "source_word_addresses_absent_from_normalized_ir": len(absent),
        "full_fde_ghidra_body_membership_bytes": 2780,
        "independent_spread_words_rechecked": len(receipt["independent_spread_word_indices"]),
        "ordinary_words_total": 695, "runtime_or_pixel_semantics_proven": False,
        "original_project_unchanged": True, "owned_project_file_count_after": len(owned)}
    json_write(REPORT / "verification.json", {"task_id": "TASK_247", "revision": 1,
        "generated_at": now(), "summary": summary, "prior_failure_verified": True,
        "first_high_ir_compile_failure_retained": True,
        "all_original_695_words_verified": True, "normalized_high_ir_address_map_verified": True,
        "owned_project_after_hashes": owned})
    report = f"""# TASK_247 R1 — ImageCodec FDE465 corrective CFG/IR research

Status: **BOUNDED_PARTIAL_IR_RESEARCH_CANDIDATE**, awaiting independent CEO review.

The pinned original `libPVGImageCodec.so` SHA-256 `{SHA[SOURCE]}` and executable ELF PT_LOAD/FDE identify zero-based nonexport FDE index 465 at VA `0x1ebdd8`, 2,780 bytes / 695 AArch64 words, body SHA-256 `{expected}`. All words were decoded and an independent source-stream reread checked the complete body plus {summary['independent_spread_words_rechecked']}/695 spread word positions. The conservative byte-anchored CFG has 23 blocks and 18 branch sites; indirect edges, call effects, and source boundaries remain unproven.

TASK_211's first decompile and targeted retry both report `Unable to find unique hash for varnode`; their raw bytes and hashes are referenced in `source_and_prior_receipt.json`. A separate read-only, 1-CPU/1-GiB Ghidra session tried `firstpass`, `register`, and `normalize`, each capped at 15 seconds. All three completed, but **none produced C-like text**. The initial HighFunction script had a Java import compile error; its raw command/log is retained under `high_ir/`. After the owned-script import correction, a fresh bounded session produced {summary['normalized_high_ir_ops']:,} normalized high-IR ops mapped to {summary['normalized_high_ir_distinct_source_word_vas']}/695 distinct original word addresses. The {summary['source_word_addresses_absent_from_normalized_ir']} addresses absent from this optimized IR are explicitly listed in `high_ir_source_mapping.json`; this address absence does not prove their behavior is absent.

Ghidra's existing body spans all 2,780 FDE bytes, but no whole-function C-like recovery or executable algorithm was achieved. `source_cfg.json` and `high_ir_source_mapping.json` are static evidence, not C++ source or codec-equivalence proof. Runtime/device parity, product Phase PASS and V4 readiness remain unproven. No product/source file was edited; no commit, push or self-review was performed.
"""
    write(REPORT / "01_MASTER_REPORT.md", report.encode("utf-8"))
    json_write(REPORT / "PROGRESS.json", {"task_id": "TASK_247", "revision": 1,
        "status": "BOUNDED_PARTIAL_IR_RESEARCH_CANDIDATE", "generated_at": now(),
        "lease_id": LEASE, "fencing_token": FENCE, "source_words": 695,
        "c_like_recovered": 0, "high_ir_ops": len(high["ops"]),
        "ir_source_word_addresses": len(mapped), "independent_spread_words": len(receipt["independent_spread_word_indices"])})
    files = {p.relative_to(REPORT).as_posix(): sha(p) for p in sorted(REPORT.rglob("*"))
             if p.is_file() and p.name not in ("COMPLETE.json", "PROGRESS.json")}
    code = {p.relative_to(ROOT).as_posix(): sha(p) for p in sorted(HERE.glob("*")) if p.is_file()}
    json_write(REPORT / "COMPLETE.json", {"schema_version": "2.1.2", "task_id": "TASK_247",
        "revision": 1, "status": "COMPLETE", "semantic_disposition": "BOUNDED_PARTIAL_IR_RESEARCH_CANDIDATE",
        "generated_at": now(), "standard_path": str(STANDARD), "standard_sha256": SHA[STANDARD],
        "task_sha256": SHA[TASK], "target_manifest_sha256": SHA[TARGETS],
        "source_sha256": SHA[SOURCE], "lease_id": LEASE, "fencing_token": FENCE,
        "review_state": "AWAITING_INDEPENDENT_CEO_REVIEW", "source_bodies_rehashed": 1,
        "ordinary_records_independently_rechecked": 1, "ordinary_records_total": 1,
        "ordinary_words_independently_rechecked": len(receipt["independent_spread_word_indices"]),
        "ordinary_words_total": 695, "c_like_bodies_recovered": 0,
        "normalized_high_ir_ops": len(high["ops"]), "runtime_or_pixel_semantics_proven": False,
        "files": files, "code_files": code})
    print(json.dumps({"stage": "SEALED", "summary": summary, "report_files": len(files),
        "code_files": len(code), "complete_sha256": sha(REPORT / "COMPLETE.json")}), flush=True)


if __name__ == "__main__":
    main()
