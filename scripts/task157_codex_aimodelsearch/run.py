"""One import and five sequential bounded Ghidra export passes."""

from __future__ import annotations

import json
import os
import subprocess
import time
from pathlib import Path

from common import (FENCE, LEASE_ID, PROJECT, PROJECT_NAME, REPORT, SCRIPTS,
                    SOURCE, SOURCE_SHA, check_lease, now, sha256,
                    write_json)

GHIDRA = Path("F:/TOOLS/ghidra_12.1.4_PUBLIC")
JAVA_HOME = Path("F:/TOOLS/jdk-21.0.12.1+1")
SCRIPT = SCRIPTS / "ExportAIModelSearchChunk157.java"


def import_source(env: dict) -> dict:
    """Import once, retaining command/log receipts on failure."""
    check_lease()
    receipt = REPORT / "ghidra_import_command.json"
    stdout = REPORT / "ghidra_import_stdout.log"
    stderr = REPORT / "ghidra_import_stderr.log"
    gpr = PROJECT / (PROJECT_NAME + ".gpr")
    if receipt.exists() or stdout.exists() or stderr.exists() or gpr.exists():
        raise RuntimeError("import already attempted or project already exists")
    command = [str(GHIDRA / "support/analyzeHeadless.bat"), str(PROJECT),
               PROJECT_NAME, "-import", str(SOURCE), "-max-cpu", "1",
               "-analysisTimeoutPerFile", "600"]
    base = {"task_id": "TASK_157", "revision": 1, "lease_id": LEASE_ID,
            "fencing_token": FENCE, "started_at": now(), "source_sha256": SOURCE_SHA,
            "command": command}
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
                code = process.wait(timeout=900)
            except subprocess.TimeoutExpired:
                process.kill()
                code = process.wait(timeout=15)
                status = "TIMEOUT"
        if status != "TIMEOUT" and code == 0 and gpr.is_file():
            status = "PROJECT_READY"
    finally:
        write_json(receipt, {**base, "ended_at": now(),
            "elapsed_seconds": round(time.monotonic() - begin, 3),
            "exit_code": code, "status": status,
            "stdout_sha256": sha256(stdout) if stdout.is_file() else None,
            "stderr_sha256": sha256(stderr) if stderr.is_file() else None,
            "project_gpr_sha256": sha256(gpr) if gpr.is_file() else None})
    return {"status": status, "exit_code": code,
            "elapsed_seconds": round(time.monotonic() - begin, 3)}


def process_chunk(meta: dict, env: dict) -> dict:
    check_lease()
    number = meta["chunk"]
    folder = REPORT / f"chunk_{number:02d}"
    targets = folder / "targets.tsv"
    result = folder / "ghidra_raw.json"
    stdout = folder / "ghidra_stdout.log"
    stderr = folder / "ghidra_stderr.log"
    receipt = folder / "ghidra_command.json"
    if (targets.exists() is False or sha256(targets) != meta["target_tsv_sha256"] or
            receipt.exists() or result.exists() or stdout.exists()):
        raise RuntimeError("chunk target changed or attempt already started")
    command = [str(GHIDRA / "support/analyzeHeadless.bat"), str(PROJECT),
               PROJECT_NAME, "-process", SOURCE.name, "-noanalysis",
               "-readOnly", "-max-cpu", "1", "-scriptPath", str(SCRIPTS),
               "-postScript", SCRIPT.name, str(targets), str(result)]
    started = now()
    base = {"task_id": "TASK_157", "revision": 1,
            "chunk": number, "lease_id": LEASE_ID, "fencing_token": FENCE,
            "started_at": started, "source_sha256": SOURCE_SHA,
            "target_tsv_sha256": sha256(targets),
            "script_sha256": sha256(SCRIPT), "command": command}
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
                code = process.wait(timeout=900)
            except subprocess.TimeoutExpired:
                process.kill()
                code = process.wait(timeout=15)
                status = "TIMEOUT"
        if status != "TIMEOUT" and code == 0 and result.is_file():
            data = json.loads(result.read_text(encoding="utf-8"))
            expected = meta["count"]
            if data.get("task_id") == "TASK_157" and len(data.get("targets", [])) == expected:
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
        write_json(receipt, {**base, "ended_at": now(),
            "elapsed_seconds": elapsed, "exit_code": code, "status": status,
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
        raise RuntimeError("batch already started")
    if not (GHIDRA / "support/analyzeHeadless.bat").is_file() or not (JAVA_HOME / "bin/java.exe").is_file():
        raise RuntimeError("Ghidra/JDK absent")
    index = json.loads((REPORT / "target_index.json").read_text(encoding="utf-8"))
    chunks = index["chunks"]
    if len(chunks) != 5 or sum(x["count"] for x in chunks) != 1231:
        raise RuntimeError("chunk index changed")
    env = os.environ.copy()
    env["JAVA_HOME"] = str(JAVA_HOME)
    env["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + env.get("PATH", "")
    env["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    env["DOUBLE_CLICKED"] = "n"
    begin = time.monotonic()
    started = now()
    outcomes = []
    write_json(REPORT / "batch_run_receipt.json", {
        "task_id": "TASK_157", "revision": 1,
        "started_at": started, "status": "IMPORTING", "chunks": outcomes})
    try:
        imported = import_source(env)
    except Exception as exc:
        imported = {"status": "ERROR", "error": str(exc)}
    write_json(REPORT / "PROGRESS.json", {
        "task_id": "TASK_157", "revision": 1,
        "status": "GHIDRA_IMPORT_" + imported["status"], "generated_at": now(),
        "lease_id": LEASE_ID, "fencing_token": FENCE,
        "import": imported, "chunks_attempted": 0})
    print(json.dumps({"import": imported}), flush=True)
    if imported["status"] != "PROJECT_READY":
        write_json(REPORT / "batch_run_receipt.json", {
            "task_id": "TASK_157", "revision": 1,
            "started_at": started, "ended_at": now(),
            "elapsed_seconds": round(time.monotonic() - begin, 3),
            "status": "PARTIAL_IMPORT_FAILED", "import": imported, "chunks": outcomes})
        return
    for meta in chunks:
        if time.monotonic() - begin >= 6600:
            outcomes.append({"chunk": meta["chunk"], "status": "OVERALL_TIME_CAP_NOT_STARTED"})
            continue
        try:
            row = process_chunk(meta, env)
        except Exception as exc:
            row = {"chunk": meta["chunk"], "status": "ERROR", "error": str(exc)}
        outcomes.append(row)
        write_json(REPORT / "batch_run_receipt.json", {
            "task_id": "TASK_157", "revision": 1,
            "started_at": started, "updated_at": now(),
            "status": "RUNNING", "chunks": outcomes})
        write_json(REPORT / "PROGRESS.json", {
            "task_id": "TASK_157", "revision": 1,
            "status": "GHIDRA_BATCH_RUNNING", "generated_at": now(),
            "lease_id": LEASE_ID, "fencing_token": FENCE,
            "chunks_attempted": len(outcomes),
            "chunks_output_ready": sum(x["status"] == "OUTPUT_READY" for x in outcomes),
            "last_chunk": meta["chunk"], "last_status": row["status"]})
        print(json.dumps(row), flush=True)
    status = "OUTPUT_READY" if len(outcomes) == 5 and all(x["status"] == "OUTPUT_READY" for x in outcomes) else "PARTIAL"
    write_json(REPORT / "batch_run_receipt.json", {
        "task_id": "TASK_157", "revision": 1,
        "started_at": started, "ended_at": now(),
        "elapsed_seconds": round(time.monotonic() - begin, 3),
        "status": status, "import": imported, "chunks": outcomes})
    write_json(REPORT / "PROGRESS.json", {
        "task_id": "TASK_157", "revision": 1,
        "status": status, "generated_at": now(),
        "lease_id": LEASE_ID, "fencing_token": FENCE,
        "chunks_output_ready": sum(x["status"] == "OUTPUT_READY" for x in outcomes),
        "chunks_total": 5, "ghidra_batch_finished": True})
    print(json.dumps({"status": status, "chunks_output_ready":
                      sum(x["status"] == "OUTPUT_READY" for x in outcomes)}), flush=True)


if __name__ == "__main__":
    main()
