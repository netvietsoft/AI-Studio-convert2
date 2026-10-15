"""Independently verify and seal TASK_211 static-research inheritance."""
from __future__ import annotations

import hashlib
import json
import math
import shutil
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path

from run_retry import ROOT, REPORT, SOURCE_INDEX, TASK, check_lease, sha, now

R1 = ROOT / "RULES/REPORT/TASK_208_REPORT_R1"
MANIFEST = ROOT / ".ai/ceo/reviews/TASK_208_internal_targets.json"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
SOURCE_SHA = "7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
MANIFEST_SHA = "db877766e2100738fdeab4f388ca67760b31702a9c92e5a237358a0d556a7dbc"


def write_json(path: Path, obj: object) -> None:
    path.write_text(json.dumps(obj, indent=2, ensure_ascii=False) + "\n", encoding="utf8")


def require(condition: bool, message: str) -> None:
    if not condition:
        raise RuntimeError(message)


def main() -> None:
    check_lease()
    require(not (REPORT / "COMPLETE.json").exists(), "already sealed")
    require(sha(STANDARD) == STANDARD_SHA, "canonical standard changed")
    require(sha(MANIFEST) == MANIFEST_SHA, "target manifest changed")
    target_obj = json.loads(MANIFEST.read_text(encoding="utf8"))
    target_by_index = {x["global_nonexport_fde_index"]: x for x in target_obj["targets"]}
    require(len(target_by_index) == 126, "target count/duplicates")
    require(set(target_by_index) == set(range(384, 512)) - {450, 499}, "target index selection")
    index = json.loads(SOURCE_INDEX.read_text(encoding="utf8"))
    source_file = Path(index["source_path"])
    require(sha(source_file) == SOURCE_SHA, "original ELF changed")
    source_bytes = source_file.read_bytes()
    require(index["target_manifest_sha256"] == MANIFEST_SHA, "index manifest identity")
    require(index["source_sha256"] == SOURCE_SHA, "index source identity")
    require(len(index["selected_candidate_rows"]) == 126, "R1 source rows")
    for item in index["project_files"]:
        require(sha(Path(index["project_copy"]) / item["relative_path"]) == item["sha256"],
                "R1 Ghidra project mutated: " + item["relative_path"])

    batch_raw: dict[int, Path] = {}
    r1_files: list[Path] = [R1 / "00_AUDIT_INDEX.md", SOURCE_INDEX]
    for b in range(1, 5):
        command = R1 / f"ghidra_batch{b}_command.json"
        d = json.loads(command.read_text(encoding="utf8"))
        require(d["status"] == "OUTPUT_READY" and d["exit_code"] == 0,
                f"R1 batch {b} did not complete")
        stdout = R1 / f"ghidra_batch{b}_stdout.log"
        stderr = R1 / f"ghidra_batch{b}_stderr.log"
        require(sha(stdout) == d["stdout_sha256"] and sha(stderr) == d["stderr_sha256"],
                f"R1 batch {b} log hash")
        require(d["script_sha256"] == sha(ROOT / "scripts/task_208_codex_internal/ExtractInternal208.java"),
                f"R1 batch {b} generator hash")
        require(d["source_sha256"] == SOURCE_SHA and d["lease_id"] ==
                "LEASE-CEO-WORKER-TASK_208-R1" and d["fencing_token"] == 1245,
                f"R1 batch {b} provenance")
        for name, digest in d["raw_result_hashes"].items():
            f = R1 / f"ghidra_raw_batch{b}" / name
            require(sha(f) == digest, "R1 raw hash: " + name)
            row = json.loads(f.read_text(encoding="utf8"))
            i = row["index"] - 1
            require(i in target_by_index and i not in batch_raw, "R1 raw row mismatch")
            batch_raw[i] = f
            r1_files.append(f)
        r1_files.extend([command, stdout, stderr])
    require(len(batch_raw) == 126, "R1 raw batch count")

    retry = json.loads((REPORT / "row466_retry.json").read_text(encoding="utf8"))
    fresh = json.loads((REPORT / "row466_fresh_verify.json").read_text(encoding="utf8"))
    for mode, obj in (("retry", retry), ("fresh_verify", fresh)):
        receipt = json.loads((REPORT / f"row466_{mode}_command.json").read_text(encoding="utf8"))
        require(receipt["status"] == "OUTPUT_READY" and receipt["exit_code"] == 0 and
                receipt["project_metadata_unchanged"] and
                receipt["output_sha256"] == sha(REPORT / f"row466_{mode}.json") and
                receipt["stdout_sha256"] == sha(REPORT / f"row466_{mode}_stdout.log") and
                receipt["stderr_sha256"] == sha(REPORT / f"row466_{mode}_stderr.log"),
                f"TASK_211 {mode} receipt")
        require(obj["global_zero_based_fde_index"] == 465 and
                obj["r1_raw_one_based_row"] == 466 and obj["elf_va"] == "0x1ebdd8" and
                obj["original_memory_sha256"] == target_by_index[465]["body_sha256"] and
                obj["function_body_bytes"] == 2780 and obj["instruction_slots"] == 695,
                f"TASK_211 {mode} target mismatch")
    require(not retry["c_like_nonempty"] and
            "Unable to find unique hash for varnode" in retry["decompile_error"],
            "failed row retry classification changed")

    selected = sorted(target_by_index)
    ordinary_sample = sorted({selected[round(j * (len(selected)-1) / 13)] for j in range(14)} | {465})
    rows: list[dict] = []
    counts = Counter()
    missing = []
    for i in selected:
        target = target_by_index[i]
        raw_file = batch_raw[i]
        raw = json.loads(raw_file.read_text(encoding="utf8"))
        asm_file = R1 / "source_assembly" / raw_file.name
        require(asm_file.is_file(), "R1 source assembly missing " + raw_file.name)
        asm = json.loads(asm_file.read_text(encoding="utf8"))
        r1_files.append(asm_file)
        va = int(target["elf_va"], 16)
        offset = int(target["file_offset"], 16)
        size = target["size_bytes"]
        body = source_bytes[offset:offset+size]
        require(len(body) == size and hashlib.sha256(body).hexdigest() == target["body_sha256"],
                f"original body hash {i}")
        require(raw["index"] == i+1 and raw["elf_va"] == target["elf_va"] and
                raw["size_bytes"] == size and raw["instruction_slots"] == size//4 and
                raw["ghidra_memory_sha256"] == target["body_sha256"],
                f"R1 raw/source binding {i}")
        require(asm["selected_zero_index"] == i and asm["index"] == i+1 and
                asm["source_body_sha256"] == target["body_sha256"] and
                asm["capstone_decoded_slots"] == size//4 and
                len(asm["instructions"]) == size//4, f"assembly record binding {i}")
        for j, ins in enumerate(asm["instructions"]):
            require(int(ins["elf_va"], 16) == va + 4*j and
                    ins["word_hex"] == body[4*j:4*j+4].hex(),
                    f"original AArch64 word {i}:{j}")
        require(raw["existing_exact_function_start"] and
                raw["boundary_classification"] ==
                "EXACT_GHIDRA_FUNCTION_START_FDE_BOUNDARY_UNPROVEN" and
                raw["fde_byte_membership_count"] == size and
                raw["fde_byte_membership_bits"] == "1"*size and
                raw["extra_body_address_count"] == 0 and
                raw["other_function_byte_count"] == 0 and
                raw["missing_analyzed_instruction_count"] == 0 and
                raw["ghidra_instruction_count"] == size//4,
                f"R1 analyzed function-body condition {i}")
        if i in ordinary_sample:
            pcode = raw["instruction_pcode"]
            require(len(pcode) == size//4 and
                    sum(len(x["pcode_ops"]) for x in pcode) == raw["ghidra_pcode_ops"],
                    f"ordinary p-code count {i}")
            for j, ins in enumerate(pcode):
                require(int(ins["database_va"], 16) ==
                        int(raw["database_va"], 16) + 4*j and
                        bool(ins.get("assembly")) and isinstance(ins.get("pcode_ops"), list),
                        f"ordinary p-code provenance {i}:{j}")
            require(raw["c_like_nonempty"] == bool(raw["c_like_text"].strip()),
                    f"ordinary C-like text {i}")
        if raw["c_like_nonempty"]:
            require(not raw["decompile_error"], f"inconsistent decompile error {i}")
        else:
            missing.append(i)
        counts["bytes"] += size
        counts["instruction_slots"] += size//4
        counts["ghidra_pcode_ops"] += raw["ghidra_pcode_ops"]
        counts["c_like_nonempty"] += bool(raw["c_like_nonempty"])
        rows.append({
            "global_zero_based_fde_index": i,
            "r1_raw_one_based_row": i+1,
            "elf_va": target["elf_va"], "file_offset": target["file_offset"],
            "size_bytes": size, "original_body_sha256": target["body_sha256"],
            "instruction_slots": size//4, "ghidra_pcode_ops": raw["ghidra_pcode_ops"],
            "ghidra_boundary_classification": raw["boundary_classification"],
            "c_like_nonempty": raw["c_like_nonempty"],
            "c_like_sha256": hashlib.sha256(raw["c_like_text"].encode("utf8")).hexdigest()
                if raw["c_like_nonempty"] else None,
            "decompile_error": raw["decompile_error"],
            "source_assembly_r1_sha256": sha(asm_file),
            "ghidra_raw_r1_sha256": sha(raw_file),
            "ordinary_provenance_rechecked": i in ordinary_sample,
            "status": "STATIC_C_LIKE_ONLY_BOUNDARY_UNPROVEN" if raw["c_like_nonempty"]
                      else "PARTIAL_PCODE_ONLY_NO_C_LIKE",
        })
    require(counts["bytes"] == 74008 and counts["instruction_slots"] == 18502 and
            counts["c_like_nonempty"] == 125 and missing == [465],
            "aggregate/source/decompile count changed")
    require(len(ordinary_sample) >= math.ceil(126*.10), "ordinary sample under 10 percent")

    inherited = REPORT / "inherited_task208_r1"
    require(not inherited.exists(), "inherited directory already exists")
    for old in r1_files:
        relative = old.relative_to(R1)
        new = inherited / relative
        new.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(old, new)
        require(sha(new) == sha(old), "inherited copy changed: " + str(relative))

    evidence = {
        "task_id": "TASK_211", "revision": 1,
        "source_so_sha256": SOURCE_SHA,
        "target_manifest_sha256": MANIFEST_SHA,
        "inherited_task208_r1_task_sha256": index["task_sha256"],
        "inherited_task208_r1_source_project_index_sha256": sha(SOURCE_INDEX),
        "inherited_task208_r1_generator_sha256":
            sha(ROOT / "scripts/task_208_codex_internal/ExtractInternal208.java"),
        "selected_candidate_count": 126,
        "selected_global_zero_based_indices": selected,
        "excluded_oversized_global_zero_based_indices": [450, 499],
        "original_bytes_verified": counts["bytes"],
        "original_instruction_words_verified": counts["instruction_slots"],
        "ghidra_pcode_operations_recorded": counts["ghidra_pcode_ops"],
        "nonempty_c_like_outputs": counts["c_like_nonempty"],
        "failed_c_like_global_zero_based_indices": missing,
        "ordinary_spread_recheck_indices": ordinary_sample,
        "ordinary_spread_recheck_fraction": len(ordinary_sample)/126,
        "critical_rechecks": "all 126 original body SHA-256, all 18,502 source words, all 126 Ghidra memory/body bindings, all four headless command/log/raw hashes, 9 Ghidra project files; row466 retry and fresh-session proof",
        "behaviorally_equivalent_functions_verified": 0,
        "boundary_limit": "unwind FDE range plus exact Ghidra function-body membership does not prove original unique semantic source-function boundary",
        "candidate_rows_file": "candidate_evidence.jsonl",
    }
    write_json(REPORT / "evidence_summary.json", evidence)
    (REPORT / "candidate_evidence.jsonl").write_text(
        "".join(json.dumps(row, ensure_ascii=False) + "\n" for row in rows), encoding="utf8")
    timestamp = now()
    (REPORT / "00_AUDIT_INDEX.md").write_text(
        "# TASK_211 R1 audit index\n\n"
        f"Canonical Standard fully read at {timestamp}: `{STANDARD}`; SHA-256 `{STANDARD_SHA}`.\n\n"
        f"Task SHA-256 `{sha(TASK)}`; target manifest SHA-256 `{MANIFEST_SHA}`. "
        "Actor `/root/audit_208`, lease `LEASE-CEO-WORKER-TASK_211-R1`, fencing token `1249`.\n\n"
        "`inherited_task208_r1/` is a byte-for-byte read-only copy of the selected expired R1 raw evidence, "
        "not a retroactive seal of TASK_208. Its own task and lease remain historical. "
        "`evidence_summary.json` and `candidate_evidence.jsonl` record this task's independent checks. "
        "`row466_retry*` and `row466_fresh_verify*` are new bounded headless sessions.\n",
        encoding="utf8")
    (REPORT / "01_MASTER_REPORT.md").write_text(
        "# TASK_211 R1 — libPVGImageCodec nonexport FDE static continuation\n\n"
        "## Result\n\n"
        "The 126 pinned, distinct zero-based nonexport FDE candidates 384–511, excluding oversized "
        "450 and 499, map to 74,008 original ELF bytes and 18,502 AArch64 words. Every original body "
        "hash and every word was independently rechecked against the pinned SO. Ghidra's existing "
        "analyzed project has an exact function start/body for each selected range, with no listed "
        "missing instruction, body gap or extra range. Its four prior headless batches produced "
        "125 nonempty C-like outputs and 64,056 recorded p-code operations. A spread 15/126 "
        "ordinary provenance sample checked per-instruction p-code positions/counts and C-like text.\n\n"
        "Global **zero-based FDE index 465** is R1 raw **one-based row 466**, ELF VA `0x1ebdd8`, "
        "2,780 bytes / 695 instructions. Its first attempt failed with `Unable to find unique hash for varnode`; "
        "a fresh, targeted 15-second-cap decompiler attempt reproduced the same error. The separate "
        "fresh-session inspection found the original exact function body and bytes unchanged. All "
        "nine private project files matched before/after both read-only processes. This row is "
        "PARTIAL: source assembly and p-code, no whole C-like body. R1 raw row 465 is a different "
        "candidate and did decompile.\n\n"
        "## Limits and next work\n\n"
        "These are static research outputs, not reconstructed and tested algorithms. FDE boundaries "
        "and Ghidra C-like text do not establish source semantics, ABI correctness or behavior parity. "
        "Global indices 450 and 499 were excluded for size and remain open. After this selection, "
        "6,153 of the 6,655 nonexport FDE candidates remain unselected (including those two and "
        "earlier exclusions); no claim that the 45 SO campaign or this library is complete. "
        "Further work on index 465 should use a distinct bounded diagnostic method, not repeat "
        "the same decompiler call without new evidence.\n\n"
        "The expired TASK_208 R1 was not modified, accepted or counted as a complete task. "
        "This TASK_211 package awaits independent CEO review; no commit/push or product gate is claimed.\n\n"
        "## Reproduction and evidence\n\n"
        "`evidence_summary.json` gives pinned hashes and aggregate checks; `candidate_evidence.jsonl` "
        "binds each index, VA, body hash, raw evidence hash and C-like/PARTIAL status. "
        "`inherited_task208_r1/` carries the exact source assembly, Ghidra raw output and original "
        "command logs. `row466_retry_command.json` and `row466_fresh_verify_command.json` bind "
        "new headless commands, stdout/stderr, project hashes and results.\n",
        encoding="utf8")
    write_json(REPORT / "PROGRESS.json", {
        "task_id": "TASK_211", "revision": 1,
        "status": "REVIEW_CANDIDATE_AWAITING_CEO", "generated_at": now(),
        "source_candidates_verified": 126, "c_like_nonempty": 125,
        "c_like_failed_global_zero_based": [465],
        "original_instruction_words_verified": 18502,
        "ordinary_spread_recheck_count": len(ordinary_sample),
    })
    check_lease()
    files = {}
    for f in sorted(REPORT.rglob("*")):
        if f.is_file() and f.name not in ("COMPLETE.json", "PROGRESS.json"):
            files[f.relative_to(REPORT).as_posix()] = sha(f)
    require(sum(f.stat().st_size for f in REPORT.rglob("*") if f.is_file()) < 134217728,
            "report byte cap")
    complete = {
        "schema_version": "2.1.2", "task_id": "TASK_211", "revision": 1,
        "status": "COMPLETE",
        "research_result": "PARTIAL_STATIC_RESEARCH_BOUNDARIES_UNPROVEN",
        "generated_at": now(), "agent_id": "/root/audit_208",
        "lease_id": "LEASE-CEO-WORKER-TASK_211-R1", "fencing_token": 1249,
        "standard_path": str(STANDARD), "standard_sha256": STANDARD_SHA,
        "task_sha256": sha(TASK), "target_manifest_sha256": MANIFEST_SHA,
        "original_so_sha256": SOURCE_SHA,
        "original_fde_candidate_bodies_verified": 126,
        "original_instruction_words_verified": 18502,
        "nonempty_c_like_outputs": 125,
        "behaviorally_equivalent_functions_verified": 0,
        "failed_c_like_global_zero_based_fde_index": 465,
        "failed_c_like_r1_raw_one_based_row": 466,
        "files": files,
        "code_files": [
            "scripts/task_211_codex_internal/RetryIndex466.java",
            "scripts/task_211_codex_internal/run_retry.py",
            "scripts/task_211_codex_internal/package.py",
        ],
    }
    write_json(REPORT / "COMPLETE.json", complete)
    print(json.dumps({"status": "SEALED_REVIEW_CANDIDATE", "files": len(files),
                      "c_like": 125, "partial": 1,
                      "complete_sha256": sha(REPORT / "COMPLETE.json")}))


if __name__ == "__main__":
    main()
