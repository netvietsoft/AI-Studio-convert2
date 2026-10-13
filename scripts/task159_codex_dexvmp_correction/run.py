"""Four sequential, bounded read-only Ghidra passes on a verified project copy."""

from __future__ import annotations

import json
import os
import subprocess
import time
from datetime import datetime, timezone
from pathlib import Path

from common import (DEADLINE, FENCE, LEASE_ID, PROJECT, REPORT, SCRIPTS,
                    SOURCE, SOURCE_SHA, check_lease, now, sha256, write_json)

GHIDRA = Path("F:/TOOLS/ghidra_12.1.4_PUBLIC")
JAVA_HOME = Path("F:/TOOLS/jdk-21.0.12.1+1")
SCRIPT = SCRIPTS / "ExportDexvmp159.java"


def run_one(meta: dict, env: dict, overall_start: float) -> dict:
    check_lease()
    number = meta["chunk"]
    folder = REPORT / meta["folder"]
    targets = folder / "targets.tsv"
    result = folder / "ghidra_raw.json"
    stdout = folder / "ghidra_stdout.log"
    stderr = folder / "ghidra_stderr.log"
    receipt = folder / "ghidra_command.json"
    if (sha256(targets) != meta["target_tsv_sha256"] or
            any(path.exists() for path in (result, stdout, stderr, receipt))):
        raise RuntimeError("target changed or chunk attempt already started")
    remaining_deadline = (DEADLINE - datetime.now(timezone.utc)).total_seconds()
    remaining_aggregate = 3600 - (time.monotonic() - overall_start)
    timeout = min(900, remaining_deadline, remaining_aggregate)
    if timeout <= 0:
        raise RuntimeError("task/aggregate deadline reached before chunk")
    command = [str(GHIDRA / "support/analyzeHeadless.bat"), str(PROJECT),
               "SmallLib156", "-process", SOURCE.name, "-noanalysis", "-readOnly",
               "-max-cpu", "1", "-scriptPath", str(SCRIPTS),
               "-postScript", SCRIPT.name, str(targets), str(result)]
    base = {"task_id": "TASK_159", "revision": 1, "chunk": number,
            "lease_id": LEASE_ID, "fencing_token": FENCE,
            "started_at": now(), "source_sha256": SOURCE_SHA,
            "target_tsv_sha256": sha256(targets),
            "script_sha256": sha256(SCRIPT), "command": command,
            "timeout_seconds": round(timeout, 3), "read_only_project_copy": True,
            "fresh_imports": 0}
    write_json(receipt, {**base, "status": "STARTING"})
    started = time.monotonic()
    status = "FAILED"
    code = None
    kill_receipt = None
    try:
        with stdout.open("wb") as out, stderr.open("wb") as err:
            process = subprocess.Popen(
                command, env=env, stdin=subprocess.DEVNULL, stdout=out, stderr=err,
                creationflags=(getattr(subprocess, "CREATE_NO_WINDOW", 0) |
                               getattr(subprocess, "CREATE_NEW_PROCESS_GROUP", 0)))
            try:
                code = process.wait(timeout=timeout)
            except subprocess.TimeoutExpired:
                # The known PID is this exact invocation's cmd.exe tree, not a guessed worker.
                killed = subprocess.run(["taskkill", "/PID", str(process.pid), "/T", "/F"],
                                        capture_output=True, text=True, timeout=30)
                kill_receipt = {"own_process_pid": process.pid,
                                "taskkill_exit_code": killed.returncode,
                                "taskkill_stdout": killed.stdout[-1000:],
                                "taskkill_stderr": killed.stderr[-1000:]}
                code = process.wait(timeout=30)
                status = "TIMEOUT"
        if status != "TIMEOUT" and code == 0 and result.is_file():
            data = json.loads(result.read_text(encoding="utf-8"))
            if (data.get("task_id") == "TASK_159" and
                    data.get("program_name") == SOURCE.name and
                    len(data.get("targets", [])) == meta["count"]):
                status = "OUTPUT_READY"
    finally:
        observed = None
        if result.is_file():
            try:
                rows = json.loads(result.read_text(encoding="utf-8"))["targets"]
                observed = {"rows": len(rows),
                            "source_bytes_matched": sum(r.get("source_bytes_match") is True for r in rows),
                            "c_like_bodies": sum(r.get("decompile_success") is True and
                                                  bool(r.get("pseudocode", "").strip()) for r in rows),
                            "instruction_rows": sum(r.get("instruction_count_observed", 0) > 0
                                                    for r in rows)}
            except Exception as exc:
                observed = {"parse_error": str(exc)}
        elapsed = round(time.monotonic() - started, 3)
        write_json(receipt, {**base, "ended_at": now(), "elapsed_seconds": elapsed,
                             "exit_code": code, "status": status,
                             "stdout_sha256": sha256(stdout) if stdout.is_file() else None,
                             "stderr_sha256": sha256(stderr) if stderr.is_file() else None,
                             "result_sha256": sha256(result) if result.is_file() else None,
                             "observed": observed, "kill_receipt": kill_receipt})
    return {"chunk": number, "folder": meta["folder"], "status": status,
            "elapsed_seconds": elapsed, "exit_code": code, "observed": observed}


def main() -> None:
    check_lease()
    if (REPORT / "batch_run_receipt.json").exists():
        raise RuntimeError("TASK_159 Ghidra batch already started")
    if not (GHIDRA / "support/analyzeHeadless.bat").is_file() or not (JAVA_HOME / "bin/java.exe").is_file():
        raise RuntimeError("Ghidra/JDK unavailable")
    if not (PROJECT / "SmallLib156.gpr").is_file():
        raise RuntimeError("copied project missing")
    index = json.loads((REPORT / "target_index.json").read_text(encoding="utf-8"))
    chunks = index["chunks"]
    if ([x["count"] for x in chunks] != [100, 100, 83, 1] or
            chunks[3].get("isolated_oversized") is not True):
        raise RuntimeError("target chunk index changed")
    env = os.environ.copy()
    env["JAVA_HOME"] = str(JAVA_HOME)
    env["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + env.get("PATH", "")
    env["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    env["DOUBLE_CLICKED"] = "n"
    started = now()
    began = time.monotonic()
    outcomes = []
    write_json(REPORT / "batch_run_receipt.json", {
        "task_id": "TASK_159", "revision": 1, "started_at": started,
        "status": "RUNNING", "chunks": outcomes, "fresh_imports": 0})
    for meta in chunks:
        if (time.monotonic() - began >= 3600 or datetime.now(timezone.utc) >= DEADLINE):
            row = {"chunk": meta["chunk"], "status": "TIME_CAP_NOT_STARTED"}
        else:
            try:
                row = run_one(meta, env, began)
            except Exception as exc:
                row = {"chunk": meta["chunk"], "status": "ERROR", "error": str(exc)}
        outcomes.append(row)
        check_lease()
        write_json(REPORT / "batch_run_receipt.json", {
            "task_id": "TASK_159", "revision": 1, "started_at": started,
            "updated_at": now(), "status": "RUNNING", "chunks": outcomes,
            "fresh_imports": 0})
        write_json(REPORT / "PROGRESS.json", {
            "task_id": "TASK_159", "revision": 1,
            "status": "GHIDRA_BATCH_RUNNING", "generated_at": now(),
            "lease_id": LEASE_ID, "fencing_token": FENCE,
            "chunks_attempted": len(outcomes),
            "chunks_output_ready": sum(x["status"] == "OUTPUT_READY" for x in outcomes),
            "last_chunk": meta["chunk"], "last_status": row["status"],
            "c_like_bodies_observed": sum((x.get("observed") or {}).get("c_like_bodies", 0)
                                          for x in outcomes),
            "independent_review_pending": True,
        })
        print(json.dumps(row), flush=True)
    status = "OUTPUT_READY" if all(x["status"] == "OUTPUT_READY" for x in outcomes) else "PARTIAL"
    write_json(REPORT / "batch_run_receipt.json", {
        "task_id": "TASK_159", "revision": 1, "started_at": started,
        "ended_at": now(), "elapsed_seconds": round(time.monotonic() - began, 3),
        "status": status, "chunks": outcomes, "fresh_imports": 0})
    print(json.dumps({"status": status, "chunks_output_ready":
                      sum(x["status"] == "OUTPUT_READY" for x in outcomes)}), flush=True)


if __name__ == "__main__":
    main()
