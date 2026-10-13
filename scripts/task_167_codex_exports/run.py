"""One import per SO, then sequential read-only Ghidra chunks under original caps."""

from __future__ import annotations

import json
import os
import subprocess
import time
from datetime import datetime, timezone
from pathlib import Path

from common import (DEADLINE, FENCE, LEASE_ID, LIBRARIES, REPORT, SCRATCH,
                    SCRIPTS, SOURCE_DIR, check_lease, now, sha256, write_json)

GHIDRA = Path("F:/TOOLS/ghidra_12.1.4_PUBLIC")
JAVA_HOME = Path("F:/TOOLS/jdk-21.0.12.1+1")
SCRIPT = SCRIPTS / "ExportChunk167.java"
MAX_AGGREGATE_SECONDS = 6600
MAX_PROCESS_SECONDS = 900


def one_chunk(name: str, digest: str, meta: dict, first: bool,
              environment: dict, aggregate_started: float) -> dict:
    check_lease()
    if sha256(SOURCE_DIR / name) != digest:
        raise RuntimeError("original source changed: " + name)
    number = meta["chunk"]
    folder = REPORT / name / f"chunk_{number:02d}"
    targets = folder / "targets.tsv"
    result = folder / "ghidra_raw.json"
    stdout = folder / "ghidra_stdout.log"
    stderr = folder / "ghidra_stderr.log"
    receipt = folder / "ghidra_command.json"
    project = SCRATCH / name / "ghidra_project"
    if (sha256(targets) != meta["target_tsv_sha256"] or receipt.exists() or
        result.exists() or stdout.exists() or stderr.exists()):
        raise RuntimeError("chunk input changed or attempt already started")
    if first:
        if project.exists():
            raise RuntimeError("duplicate import/project for " + name)
        project.mkdir(parents=True)
        operation = ["-import", str(SOURCE_DIR / name), "-max-cpu", "1",
                     "-analysisTimeoutPerFile", "480"]
    else:
        if not project.exists():
            raise RuntimeError("missing imported project for " + name)
        operation = ["-process", name, "-noanalysis", "-readOnly", "-max-cpu", "1"]
    command = [str(GHIDRA / "support/analyzeHeadless.bat"), str(project),
               "Task167", *operation, "-scriptPath", str(SCRIPTS),
               "-postScript", SCRIPT.name, str(targets), str(result)]
    base = {"task_id": "TASK_167", "revision": 1, "library": name,
            "chunk": number, "operation": "IMPORT" if first else "READ_ONLY_PROCESS",
            "lease_id": LEASE_ID, "fencing_token": FENCE,
            "started_at": now(), "source_sha256": digest,
            "target_tsv_sha256": sha256(targets),
            "script_sha256": sha256(SCRIPT), "command": command}
    write_json(receipt, {**base, "status": "STARTING"})
    remaining = min(MAX_PROCESS_SECONDS,
                    MAX_AGGREGATE_SECONDS - (time.monotonic() - aggregate_started),
                    (DEADLINE - datetime.now(timezone.utc)).total_seconds())
    if remaining <= 0:
        write_json(receipt, {**base, "status": "NOT_STARTED_TIME_CAP", "ended_at": now()})
        return {"library": name, "chunk": number, "status": "NOT_STARTED_TIME_CAP"}
    start = time.monotonic()
    code = None
    status = "FAILED"
    try:
        with stdout.open("wb") as output, stderr.open("wb") as errors:
            process = subprocess.Popen(command, env=environment, stdin=subprocess.DEVNULL,
                                       stdout=output, stderr=errors,
                                       creationflags=getattr(subprocess, "CREATE_NO_WINDOW", 0))
            try:
                code = process.wait(timeout=remaining)
            except subprocess.TimeoutExpired:
                process.kill()
                code = process.wait(timeout=15)
                status = "TIMEOUT"
        if status != "TIMEOUT" and code == 0 and result.is_file():
            data = json.loads(result.read_text(encoding="utf-8"))
            if (data.get("task_id") == "TASK_167" and
                data.get("program_name") == name and
                len(data.get("targets", [])) == meta["count"]):
                status = "OUTPUT_READY"
    finally:
        observed = None
        if result.is_file():
            try:
                rows = json.loads(result.read_text(encoding="utf-8"))["targets"]
                observed = {"rows": len(rows),
                            "source_bytes_matched": sum(r.get("source_bytes_match") is True for r in rows),
                            "decompile_success": sum(r.get("decompile_success") is True for r in rows),
                            "instruction_rows": sum(r.get("instruction_count_observed", 0) > 0 for r in rows)}
            except Exception as error:
                observed = {"parse_error": str(error)}
        elapsed = round(time.monotonic() - start, 3)
        write_json(receipt, {**base, "ended_at": now(), "elapsed_seconds": elapsed,
                             "exit_code": code, "status": status,
                             "stdout_sha256": sha256(stdout) if stdout.is_file() else None,
                             "stderr_sha256": sha256(stderr) if stderr.is_file() else None,
                             "result_sha256": sha256(result) if result.is_file() else None,
                             "observed": observed})
    return {"library": name, "chunk": number, "status": status,
            "exit_code": code, "elapsed_seconds": elapsed, "observed": observed}


def main() -> None:
    check_lease()
    if (REPORT / "batch_run_receipt.json").exists():
        raise RuntimeError("TASK_167 batch already started")
    if not (GHIDRA / "support/analyzeHeadless.bat").is_file() or not (JAVA_HOME / "bin/java.exe").is_file():
        raise RuntimeError("Ghidra/JDK missing")
    index = json.loads((REPORT / "source_batch_index.json").read_text(encoding="utf-8"))
    if index["total_unique_export_vas"] != 4526:
        raise RuntimeError("source target count changed")
    environment = os.environ.copy()
    environment["JAVA_HOME"] = str(JAVA_HOME)
    environment["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + environment.get("PATH", "")
    environment["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    environment["DOUBLE_CLICKED"] = "n"
    started = now()
    aggregate_started = time.monotonic()
    outcomes = []
    write_json(REPORT / "batch_run_receipt.json", {
        "task_id": "TASK_167", "revision": 1, "started_at": started,
        "status": "RUNNING", "chunks": outcomes})
    for name, (digest, count) in LIBRARIES.items():
        library_index = json.loads((REPORT / name / "target_index.json").read_text(encoding="utf-8"))
        chunks = library_index["chunks"]
        if library_index["unique_export_vas"] != count or sum(x["count"] for x in chunks) != count:
            raise RuntimeError("chunk census changed: " + name)
        for meta in chunks:
            if (datetime.now(timezone.utc) >= DEADLINE or
                time.monotonic() - aggregate_started >= MAX_AGGREGATE_SECONDS):
                row = {"library": name, "chunk": meta["chunk"], "status": "NOT_STARTED_TIME_CAP"}
            elif meta["chunk"] > 1 and any(x["library"] == name and x["status"] != "OUTPUT_READY" for x in outcomes):
                row = {"library": name, "chunk": meta["chunk"], "status": "NOT_STARTED_PRIOR_FAILURE"}
            else:
                try:
                    row = one_chunk(name, digest, meta, meta["chunk"] == 1,
                                    environment, aggregate_started)
                except Exception as error:
                    row = {"library": name, "chunk": meta["chunk"], "status": "ERROR", "error": str(error)}
            outcomes.append(row)
            write_json(REPORT / "batch_run_receipt.json", {
                "task_id": "TASK_167", "revision": 1, "started_at": started,
                "updated_at": now(), "status": "RUNNING", "chunks": outcomes})
            write_json(REPORT / "PROGRESS.json", {
                "task_id": "TASK_167", "revision": 1, "status": "GHIDRA_BATCH_RUNNING",
                "generated_at": now(), "lease_id": LEASE_ID, "fencing_token": FENCE,
                "chunks_attempted": len(outcomes),
                "chunks_output_ready": sum(x["status"] == "OUTPUT_READY" for x in outcomes),
                "last_library": name, "last_chunk": meta["chunk"],
                "last_status": row["status"]})
            print(json.dumps(row), flush=True)
    finished = len(outcomes) == 19 and all(x["status"] == "OUTPUT_READY" for x in outcomes)
    status = "OUTPUT_READY" if finished else "PARTIAL"
    write_json(REPORT / "batch_run_receipt.json", {
        "task_id": "TASK_167", "revision": 1, "started_at": started,
        "ended_at": now(), "elapsed_seconds": round(time.monotonic() - aggregate_started, 3),
        "status": status, "chunks": outcomes})
    write_json(REPORT / "PROGRESS.json", {
        "task_id": "TASK_167", "revision": 1, "status": status,
        "generated_at": now(), "lease_id": LEASE_ID, "fencing_token": FENCE,
        "chunks_output_ready": sum(x["status"] == "OUTPUT_READY" for x in outcomes),
        "chunks_total": len(outcomes), "ghidra_batch_finished": True})
    print(json.dumps({"status": status,
                      "chunks_output_ready": sum(x["status"] == "OUTPUT_READY" for x in outcomes),
                      "chunks_total": len(outcomes)}), flush=True)


if __name__ == "__main__":
    main()
