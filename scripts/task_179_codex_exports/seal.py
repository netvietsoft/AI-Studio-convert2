"""Independently verify and seal the bounded TASK_179 partial-research package."""

from __future__ import annotations

import json
import math
import re
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

from evidence import (BODY_SHA, ELF_VA, FENCE, LEASE, PRIOR, REPORT, ROOT,
                      SIZE, SOURCE, SOURCE_SHA, TASK_SHA, check_lease,
                      sha256, utc_now, write_json)


HISTORICAL_155 = ROOT / "RULES/REPORT/TASK_155_REPORT_R1/libglide-webp.so/ghidra_raw.json"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
SCRIPTS = ["scripts/task_179_codex_exports/evidence.py",
           "scripts/task_179_codex_exports/probe.py",
           "scripts/task_179_codex_exports/ScalarTailProbe179.java",
           "scripts/task_179_codex_exports/seal.py"]


def require(condition: bool, reason: str) -> None:
    if not condition:
        raise RuntimeError(reason)


def main() -> None:
    check_lease()
    require(not (REPORT / "COMPLETE.json").exists(), "TASK_179 already sealed")
    require(sha256(STANDARD.read_bytes()) == STANDARD_SHA, "canonical Standard SHA changed")
    require(sha256(SOURCE.read_bytes()) == SOURCE_SHA, "original SO changed")
    source_proof = json.loads((REPORT / "source_proof.json").read_text(encoding="utf-8"))
    instructions = json.loads((REPORT / "instruction_evidence.json").read_text(encoding="utf-8"))
    cfg = json.loads((REPORT / "cfg_evidence.json").read_text(encoding="utf-8"))
    probe = json.loads((REPORT / "probe_command.json").read_text(encoding="utf-8"))
    scalar = json.loads((REPORT / "scalar_tail_probe_raw.json").read_text(encoding="utf-8"))
    prior_bytes = PRIOR.read_bytes()
    prior = json.loads(prior_bytes)
    original_155_bytes = HISTORICAL_155.read_bytes()
    original_155 = json.loads(original_155_bytes)
    prior_targets = [row for row in original_155["targets"] if row.get("elf_va") == "0x328dc"]
    require(len(prior_targets) == 1, "historical default-decompile gap not unique")
    old_target = prior_targets[0]
    require(old_target["symbol"] == "WebPConvertRGBA32ToUV_C" and
            old_target["expected_source_sha256"] == BODY_SHA and
            old_target["decompile_success"] is False and
            "Unable to find unique hash for varnode" in old_target["error"],
            "historical default-decompile failure changed")
    require(prior["c_like_nonempty"] is False and prior["analysis_style"] == "normalize"
            and source_proof["prior_TASK_175_raw_sha256"] == sha256(prior_bytes),
            "TASK_175 normalize result changed")
    require(probe["status"] == "OUTPUT_READY" and probe["exit_code"] == 0
            and probe["timed_out"] is False and probe["elapsed_seconds"] <= 180
            and probe["max_cpu"] == 1 and probe["GHIDRA_HEADLESS_MAXMEM"] == "1G"
            and probe["fresh_imports"] == 0 and probe["decompile_passes"] == 1
            and probe["historical_project_unchanged"] is True,
            "new isolated probe did not meet bounded controls")
    require(probe["result_sha256"] == sha256((REPORT / "scalar_tail_probe_raw.json").read_bytes())
            and probe["stdout_sha256"] == sha256((REPORT / "probe_stdout.log").read_bytes())
            and probe["stderr_sha256"] == sha256((REPORT / "probe_stderr.log").read_bytes()),
            "new probe raw output/log hash mismatch")
    require(probe["historical_project_files_sha256_before"] ==
            probe["historical_project_files_sha256_after"] ==
            probe["copied_project_files_sha256_before"],
            "historical project changed or copy initially differed")
    require(scalar["task_id"] == "TASK_179" and scalar["revision"] == 1
            and scalar["source_body_sha256"] == BODY_SHA
            and scalar["copied_project_memory_sha256"] == BODY_SHA
            and scalar["whole_original_function_decompiled"] is False
            and scalar["decompile_style"] == "decompile"
            and scalar["decompile_completed"] is True
            and scalar["scalar_tail_c_like_nonempty"] is True
            and scalar["error"] == "", "scalar-tail raw result unsupported")
    c_text = scalar["scalar_tail_c_like"]
    for text in ("-0x4a89", "-0x25f7", "0x7080", "-0x5e34", "-0x124c",
                 "0x2020000", "puVar9", "puVar10"):
        require(text in c_text, "scalar-tail coefficient/store missing: " + text)
    require(source_proof["source_body_sha256"] == BODY_SHA and
            source_proof["instruction_count"] == 156 and
            source_proof["pcode_ops_in_historical_output"] == 1307 and
            source_proof["spread_sample_count"] >= math.ceil(0.1 * 156),
            "source proof count or spread sample unsupported")
    rows = instructions["rows"]
    require(len(rows) == 156 and len(cfg["basic_blocks"]) == 11 and
            len(cfg["branch_and_return_edges"]) == 8,
            "complete instruction/CFG counts differ")
    body_offset = int(source_proof["file_offset"], 16)
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        require(elf["e_machine"] == "EM_AARCH64" and elf.little_endian,
                "source ELF machine/endianness differs")
        stream.seek(body_offset)
        body = stream.read(SIZE)
    require(sha256(body) == BODY_SHA, "direct reread body hash differs")
    cap = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    decoded = list(cap.disasm(body, ELF_VA))
    require(len(decoded) == 156, "direct full body decode differs")
    for row, ins in zip(rows, decoded):
        require(row["elf_va"] == f"0x{ins.address:x}" and
                row["source_word_hex"] == ins.bytes.hex() and
                row["source_file_offset"] == f"0x{body_offset + ins.address - ELF_VA:x}",
                "direct complete-source instruction mismatch")
    sample = instructions["spread_sample"]
    require(len(sample) == 16 and len({row["index"] for row in sample}) == 16,
            "spread instruction sample duplicates")
    require(min(row["index"] for row in sample) == 0 and
            max(row["index"] for row in sample) == 155,
            "spread instruction sample does not cover boundaries")
    for row in sample:
        require(rows[row["index"]] == row, "spread sample not drawn from full source list")
    pseudocode = (REPORT / "02_SOURCE_ANCHORED_BLOCK_PSEUDOCODE.md").read_text(encoding="utf-8")
    for anchor in ("0x328dc", "0x328f4", "0x329a8", "0x32ab8", "0x32ae0", "0x32b48"):
        require(anchor in pseudocode, "critical source anchor missing from interpretation")
    require("no whole-function C-like" in pseudocode and
            "not a runtime-verified behavioral contract" in pseudocode,
            "interpretation does not disclose critical limitations")

    check_lease()
    (REPORT / "historical_TASK_175_normalize_raw.json").write_bytes(prior_bytes)
    target_record = {"historical_task_id": "TASK_155", "historical_raw_path": str(HISTORICAL_155),
                     "historical_raw_sha256": sha256(original_155_bytes),
                     "target_row": old_target}
    write_json("historical_TASK_155_target.json", target_record)
    source_stdout = (REPORT / "source_evidence_stdout.log").read_bytes()
    source_stderr = (REPORT / "source_evidence_stderr.log").read_bytes()
    # Windows PowerShell's stdout redirection wrote UTF-16LE with a BOM.
    decoded_stdout = source_stdout.decode("utf-16" if source_stdout.startswith(b"\xff\xfe") else "utf-8")
    require("SOURCE_INSTRUCTION_CFG_VERIFIED" in decoded_stdout and not source_stderr,
            "source evidence command output not clean")
    write_json("source_evidence_command.json", {
        "task_id": "TASK_179", "revision": 1, "command": ["python", "-X", "utf8", "-B",
            "scripts/task_179_codex_exports/evidence.py"],
        "stdout_redirect": "RULES/REPORT/TASK_179_REPORT_R1/source_evidence_stdout.log",
        "stderr_redirect": "RULES/REPORT/TASK_179_REPORT_R1/source_evidence_stderr.log",
        "observed_exit_code": 0, "stdout_encoding": "utf-16le-bom" if source_stdout.startswith(b"\xff\xfe") else "utf-8",
        "script_sha256": sha256((ROOT / SCRIPTS[0]).read_bytes()),
        "stdout_sha256": sha256(source_stdout), "stderr_sha256": sha256(source_stderr),
        "result_source_proof_sha256": sha256((REPORT / "source_proof.json").read_bytes())})
    write_json("final_verification.json", {
        "task_id": "TASK_179", "revision": 1, "verified_at": utc_now(),
        "task_sha256": TASK_SHA, "standard_sha256": STANDARD_SHA,
        "original_source_sha256": SOURCE_SHA, "original_body_sha256": BODY_SHA,
        "source_bytes_direct_reread": SIZE, "original_instruction_words_direct_reread": 156,
        "historical_pcode_ops_address_aligned": 1307,
        "basic_blocks": 11, "branch_return_sites": 8,
        "spread_ordinary_instruction_words_direct_reread": len(sample),
        "prior_default_whole_function_error_confirmed": True,
        "prior_normalize_whole_function_c_like": False,
        "new_synthetic_scalar_tail_c_like": True,
        "new_whole_original_function_c_like": False,
        "runtime_behavior_verified": False,
        "historical_analyzed_project_unchanged": True,
        "source_or_product_modified": False})
    write_json("PROGRESS.json", {
        "task_id": "TASK_179", "revision": 1,
        "status": "SEALED_PARTIAL_RESEARCH_CANDIDATE_AWAITING_CEO",
        "generated_at": utc_now(), "lease_id": LEASE, "fencing_token": FENCE,
        "source_instructions": 156, "historical_pcode_ops": 1307,
        "new_scalar_tail_c_like": True, "whole_original_function_c_like": False,
        "independent_ceo_review_pending": True})
    files = {p.relative_to(REPORT).as_posix(): sha256(p.read_bytes())
             for p in sorted(REPORT.rglob("*")) if p.is_file()
             and p.name not in ("COMPLETE.json", "PROGRESS.json")}
    code = {name: sha256((ROOT / name).read_bytes()) for name in SCRIPTS}
    package_bytes = sum((REPORT / name).stat().st_size for name in files)
    require(package_bytes <= 134217728, "report package exceeds task cap")
    seal = {"schema_version": "2.1.2", "task_id": "TASK_179", "revision": 1,
            "status": "COMPLETE", "research_result": "PARTIAL",
            "review_state": "REVIEW_CANDIDATE_AWAITING_CEO", "generated_at": utc_now(),
            "lease_id": LEASE, "fencing_token": FENCE,
            "task_sha256": TASK_SHA, "standard_sha256": STANDARD_SHA,
            "source_sha256": SOURCE_SHA, "original_body_sha256": BODY_SHA,
            "original_source_bytes_covered": 624, "original_instruction_words_covered": 156,
            "historical_pcode_ops_address_aligned": 1307,
            "new_scalar_tail_c_like": True, "new_whole_original_function_c_like": False,
            "verified_behavior": False, "unresolved_gap":
            "No whole-function C-like decompiler output for SIMD path or runtime parity evidence",
            "report_bytes_excluding_progress_and_seal": package_bytes,
            "files": files, "code_files": code,
            "self_review_or_commit_or_push": False}
    write_json("COMPLETE.json", seal)
    print(json.dumps({"status": "SEALED_PARTIAL", "report_files": len(files),
                      "code_files": len(code), "body_sha256": BODY_SHA,
                      "whole_c_like": False, "scalar_tail_c_like": True}))


if __name__ == "__main__":
    main()
