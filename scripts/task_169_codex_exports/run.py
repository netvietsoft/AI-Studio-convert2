"""Run 20 new-only LayerFlow export chunks on the verified reused Ghidra project."""

from __future__ import annotations

import json
import os
import subprocess
import time
from datetime import datetime, timezone
from pathlib import Path

from common import (EXPECTED_VAS, FENCE, LEASE_ID, PROJECT, PROJECT_NAME, REPORT,
                    SCRIPTS, SOURCE, SOURCE_SHA, check_lease, now, sha256, write_json)

GHIDRA = Path("F:/TOOLS/ghidra_12.1.4_PUBLIC")
JAVA_HOME = Path("F:/TOOLS/jdk-21.0.12.1+1")
SCRIPT = SCRIPTS / "ExportLayerFlowChunk169.java"
PROJECT_DB_REL = "LayerFlowHair146.rep/idata/00/~00000000.db/db.1.gbf"


def remaining_seconds() -> float:
    lease = check_lease()
    expiry = datetime.fromisoformat(lease["expiry"].replace("Z", "+00:00"))
    return (expiry - datetime.now(timezone.utc)).total_seconds()


def check_reused_project() -> dict:
    check_lease()
    receipt = json.loads((REPORT / "project_reuse_receipt.json").read_text(encoding="utf-8"))
    if (receipt["task_id"] != "TASK_169" or receipt["source_sha256"] != SOURCE_SHA or
            receipt["execution_mode"] != "REUSED_ANALYZED_TASK_147_PROJECT_NO_FRESH_IMPORT"):
        raise RuntimeError("project reuse receipt identity mismatch")
    db = PROJECT / PROJECT_DB_REL
    gpr = PROJECT / (PROJECT_NAME + ".gpr")
    if (not db.is_file() or not gpr.is_file() or
            sha256(db) != receipt["copied_project_db_sha256"] or
            sha256(gpr) != receipt["copied_project_initial_file_hashes"][gpr.name]):
        raise RuntimeError("copied analyzed Ghidra project changed before run")
    return {"status": "PROJECT_REUSED", "historical_source": receipt["historical_lineage"]["original_project"],
            "project_db_sha256": sha256(db), "fresh_imports": 0}


def process_chunk(meta: dict, env: dict) -> dict:
    check_lease()
    number = meta["chunk"]
    folder = REPORT / f"chunk_{number:02d}"
    targets = folder / "targets.tsv"
    result = folder / "ghidra_raw.json"
    stdout = folder / "ghidra_stdout.log"
    stderr = folder / "ghidra_stderr.log"
    receipt = folder / "ghidra_command.json"
    if (not targets.is_file() or sha256(targets) != meta["target_tsv_sha256"] or
            receipt.exists() or result.exists() or stdout.exists() or stderr.exists()):
        raise RuntimeError("chunk target changed or attempt already started")
    command = [str(GHIDRA / "support/analyzeHeadless.bat"), str(PROJECT),
               PROJECT_NAME, "-process", SOURCE.name, "-noanalysis", "-readOnly",
               "-max-cpu", "1", "-scriptPath", str(SCRIPTS),
               "-postScript", SCRIPT.name, str(targets), str(result)]
    base = {"task_id": "TASK_169", "revision": 1, "chunk": number,
            "lease_id": LEASE_ID, "fencing_token": FENCE,
            "started_at": now(), "source_sha256": SOURCE_SHA,
            "target_tsv_sha256": sha256(targets), "script_sha256": sha256(SCRIPT),
            "project_db_sha256_before": sha256(PROJECT / PROJECT_DB_REL),
            "command": command, "fresh_import": False}
    write_json(receipt, {**base, "status": "STARTING"})
    begin = time.monotonic()
    code = None
    status = "FAILED"
    try:
        with stdout.open("wb") as output, stderr.open("wb") as errors:
            process = subprocess.Popen(command, env=env, stdin=subprocess.DEVNULL,
                                       stdout=output, stderr=errors,
                                       creationflags=getattr(subprocess, "CREATE_NO_WINDOW", 0))
            try:
                code = process.wait(timeout=min(900, max(1, remaining_seconds() - 2)))
            except subprocess.TimeoutExpired:
                process.kill()
                code = process.wait(timeout=15)
                status = "TIMEOUT"
        if status != "TIMEOUT" and code == 0 and result.is_file():
            data = json.loads(result.read_text(encoding="utf-8"))
            if (data.get("task_id") == "TASK_169" and data.get("program_name") == SOURCE.name and
                    len(data.get("targets", [])) == meta["count"] and
                    [x["index"] for x in data["targets"]] == meta["indices"]):
                status = "OUTPUT_READY"
    finally:
        observed = None
        if result.is_file():
            try:
                rows = json.loads(result.read_text(encoding="utf-8"))["targets"]
                observed = {"rows": len(rows),
                    "source_bytes_matched": sum(x.get("source_bytes_match") is True for x in rows),
                    "decompile_success": sum(x.get("decompile_success") is True for x in rows),
                    "instruction_rows": sum(x.get("instruction_count_observed", 0) > 0 for x in rows)}
            except Exception as exc:
                observed = {"parse_error": str(exc)}
        elapsed = round(time.monotonic() - begin, 3)
        write_json(receipt, {**base, "ended_at": now(), "elapsed_seconds": elapsed,
            "exit_code": code, "status": status,
            "project_db_sha256_after": sha256(PROJECT / PROJECT_DB_REL),
            "stdout_sha256": sha256(stdout) if stdout.is_file() else None,
            "stderr_sha256": sha256(stderr) if stderr.is_file() else None,
            "result_sha256": sha256(result) if result.is_file() else None,
            "observed": observed})
    return {"chunk": number, "status": status, "exit_code": code,
            "elapsed_seconds": elapsed, "observed": observed}


def main() -> None:
    check_lease()
    if sha256(SOURCE) != SOURCE_SHA:
        raise RuntimeError("source changed")
    if (REPORT / "batch_run_receipt.json").exists():
        raise RuntimeError("batch already started; no retry")
    if not (GHIDRA / "support/analyzeHeadless.bat").is_file() or not (JAVA_HOME / "bin/java.exe").is_file():
        raise RuntimeError("Ghidra/JDK absent")
    index = json.loads((REPORT / "target_index.json").read_text(encoding="utf-8"))
    chunks = index["chunks"]
    if (index["unique_export_vas"] != EXPECTED_VAS or len(chunks) != 20 or
            sum(x["count"] for x in chunks) != EXPECTED_VAS - 15 or
            any(x["count"] > 256 for x in chunks)):
        raise RuntimeError("new-only chunk index changed")
    reused = check_reused_project()
    env = os.environ.copy()
    env["JAVA_HOME"] = str(JAVA_HOME)
    env["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + env.get("PATH", "")
    env["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    env["DOUBLE_CLICKED"] = "n"
    begin = time.monotonic()
    started = now()
    outcomes = []
    write_json(REPORT / "batch_run_receipt.json", {
        "task_id": "TASK_169", "revision": 1, "started_at": started,
        "status": "PROJECT_REUSED", "project": reused, "chunks": outcomes})
    print(json.dumps({"project": reused}), flush=True)
    for meta in chunks:
        if time.monotonic() - begin >= 6600 or remaining_seconds() <= 5:
            outcomes.append({"chunk": meta["chunk"], "status": "BUDGET_OR_DEADLINE_NOT_STARTED"})
            continue
        try:
            row = process_chunk(meta, env)
        except Exception as exc:
            row = {"chunk": meta["chunk"], "status": "ERROR", "error": str(exc)}
        outcomes.append(row)
        write_json(REPORT / "batch_run_receipt.json", {
            "task_id": "TASK_169", "revision": 1, "started_at": started,
            "updated_at": now(), "status": "RUNNING", "project": reused,
            "chunks": outcomes})
        write_json(REPORT / "PROGRESS.json", {
            "task_id": "TASK_169", "revision": 1, "status": "GHIDRA_BATCH_RUNNING",
            "generated_at": now(), "lease_id": LEASE_ID, "fencing_token": FENCE,
            "historical_reused_vas": 15, "chunks_attempted": len(outcomes),
            "chunks_output_ready": sum(x["status"] == "OUTPUT_READY" for x in outcomes),
            "new_rows_output_ready": sum(x.get("observed", {}).get("rows", 0) for x in outcomes if x["status"] == "OUTPUT_READY"),
            "last_chunk": meta["chunk"], "last_status": row["status"]})
        print(json.dumps(row), flush=True)
    status = "OUTPUT_READY" if len(outcomes) == 20 and all(x["status"] == "OUTPUT_READY" for x in outcomes) else "PARTIAL"
    write_json(REPORT / "batch_run_receipt.json", {
        "task_id": "TASK_169", "revision": 1, "started_at": started,
        "ended_at": now(), "elapsed_seconds": round(time.monotonic() - begin, 3),
        "status": status, "project": reused, "chunks": outcomes})
    write_json(REPORT / "PROGRESS.json", {
        "task_id": "TASK_169", "revision": 1, "status": status,
        "generated_at": now(), "lease_id": LEASE_ID, "fencing_token": FENCE,
        "historical_reused_vas": 15,
        "chunks_output_ready": sum(x["status"] == "OUTPUT_READY" for x in outcomes),
        "chunks_total": 20, "ghidra_batch_finished": True})
    print(json.dumps({"status": status, "chunks_output_ready":
                      sum(x["status"] == "OUTPUT_READY" for x in outcomes)}), flush=True)


if __name__ == "__main__":
    main()
