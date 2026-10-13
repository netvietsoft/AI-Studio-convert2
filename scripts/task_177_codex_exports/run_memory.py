"""Read each of 11 copied historical Ghidra programs once, without import/decompile."""

from __future__ import annotations

import json
import os
import subprocess
import time
from datetime import datetime, timezone
from pathlib import Path

from common import (DEADLINE, FENCE, LEASE_ID, REPORT, SCRATCH,
                    SCRIPTS, SOURCE_DIR, check_lease, now, sha256,
                    task_metadata, write_json)

GHIDRA = Path("F:/TOOLS/ghidra_12.1.4_PUBLIC")
JAVA_HOME = Path("F:/TOOLS/jdk-21.0.12.1+1")
SCRIPT = SCRIPTS / "VerifyMemory177.java"
MAX_PROCESS_SECONDS = 900
MAX_AGGREGATE_SECONDS = 6600


def check_project_copy(name: str) -> str:
    manifest_path = REPORT / "project_copy_manifest.json"
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    project = manifest["projects"][name]
    if project["file_count"] != len(project["files"]) or not project["files"]:
        raise RuntimeError("project copy census differs")
    for item in project["files"]:
        candidate = SCRATCH / name / "ghidra_project" / item["relative_path"]
        if (not candidate.is_file() or candidate.stat().st_size != item["bytes"] or
            sha256(candidate) != item["copy_sha256"] or
            item["source_sha256"] != item["copy_sha256"]):
            raise RuntimeError("analyzed Ghidra copy differs: " + str(candidate))
    return sha256(manifest_path)


def one_library(name: str, source_sha: str, expected_count: int,
                environment: dict, started: float) -> dict:
    check_lease()
    if sha256(SOURCE_DIR / name) != source_sha:
        raise RuntimeError("pinned original source changed: " + name)
    project_manifest_sha = check_project_copy(name)
    folder = REPORT / name
    input_path = folder / "historical_targets.tsv"
    result_path = folder / "fresh_memory_raw.json"
    stdout_path = folder / "fresh_memory_stdout.log"
    stderr_path = folder / "fresh_memory_stderr.log"
    receipt_path = folder / "fresh_memory_command.json"
    if any(path.exists() for path in (result_path, stdout_path, stderr_path, receipt_path)):
        raise RuntimeError("read-only memory verification already started for " + name)
    project = SCRATCH / name / "ghidra_project"
    project_name = json.loads((REPORT / "project_copy_manifest.json").read_text(encoding="utf-8"))["projects"][name]["project_name"]
    command = [str(GHIDRA / "support/analyzeHeadless.bat"), str(project), project_name,
               "-process", name, "-noanalysis", "-readOnly", "-max-cpu", "1",
               "-scriptPath", str(SCRIPTS), "-postScript", SCRIPT.name,
               name, str(expected_count), str(input_path), str(result_path)]
    base = {"task_id": "TASK_177", "revision": 1, "library": name,
            "lease_id": LEASE_ID, "fencing_token": FENCE,
            "started_at": now(), "source_sha256": source_sha,
            "historical_targets_tsv_sha256": sha256(input_path),
            "project_copy_manifest_sha256": project_manifest_sha,
            "script_sha256": sha256(SCRIPT), "expected_target_count": expected_count,
            "operation": "READ_ONLY_MEMORY_HASH_ONLY_NO_IMPORT_NO_DECOMPILATION",
            "command": command}
    write_json(receipt_path, {**base, "status": "STARTING"})
    remaining = min(MAX_PROCESS_SECONDS, MAX_AGGREGATE_SECONDS - (time.monotonic() - started),
                    (DEADLINE - datetime.now(timezone.utc)).total_seconds())
    if remaining <= 0:
        write_json(receipt_path, {**base, "status": "NOT_STARTED_TIME_CAP", "ended_at": now()})
        return {"library": name, "status": "NOT_STARTED_TIME_CAP"}
    began = time.monotonic()
    status = "FAILED"
    code = None
    try:
        with stdout_path.open("wb") as stdout, stderr_path.open("wb") as stderr:
            process = subprocess.Popen(command, env=environment, stdin=subprocess.DEVNULL,
                                       stdout=stdout, stderr=stderr,
                                       creationflags=getattr(subprocess, "CREATE_NO_WINDOW", 0))
            try:
                code = process.wait(timeout=remaining)
            except subprocess.TimeoutExpired:
                process.kill()
                code = process.wait(timeout=15)
                status = "PROCESS_TIMEOUT"
        if status != "PROCESS_TIMEOUT" and code == 0 and result_path.is_file():
            raw = json.loads(result_path.read_text(encoding="utf-8"))
            if (raw.get("task_id") == "TASK_177" and raw.get("program_name") == name and
                raw.get("target_count") == expected_count and
                raw.get("fresh_imports") == 0 and raw.get("fresh_decompilations") == 0 and
                len(raw.get("targets", [])) == expected_count and
                all(row.get("source_bytes_match") is True for row in raw["targets"])):
                status = "OUTPUT_READY"
    finally:
        elapsed = round(time.monotonic() - began, 3)
        observed = None
        if result_path.is_file():
            try:
                raw = json.loads(result_path.read_text(encoding="utf-8"))
                observed = {"rows": len(raw.get("targets", [])),
                            "body_bytes_hashed": raw.get("body_bytes_hashed"),
                            "source_bytes_matched": sum(row.get("source_bytes_match") is True
                                                        for row in raw.get("targets", [])),
                            "fresh_imports": raw.get("fresh_imports"),
                            "fresh_decompilations": raw.get("fresh_decompilations")}
            except Exception as failure:
                observed = {"parse_error": str(failure)}
        write_json(receipt_path, {**base, "ended_at": now(), "elapsed_seconds": elapsed,
                                  "exit_code": code, "status": status,
                                  "stdout_sha256": sha256(stdout_path) if stdout_path.is_file() else None,
                                  "stderr_sha256": sha256(stderr_path) if stderr_path.is_file() else None,
                                  "result_sha256": sha256(result_path) if result_path.is_file() else None,
                                  "observed": observed})
    return {"library": name, "status": status, "elapsed_seconds": elapsed,
            "exit_code": code, "observed": observed}


def main() -> None:
    check_lease()
    if (REPORT / "memory_run_receipt.json").exists():
        raise RuntimeError("TASK_177 read-only memory batch already started")
    if not (GHIDRA / "support/analyzeHeadless.bat").is_file() or not (JAVA_HOME / "bin/java.exe").is_file():
        raise RuntimeError("Ghidra/JDK missing")
    environment = os.environ.copy()
    environment["JAVA_HOME"] = str(JAVA_HOME)
    environment["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + environment.get("PATH", "")
    environment["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    environment["DOUBLE_CLICKED"] = "n"
    started_at = now()
    started = time.monotonic()
    outcomes = []
    write_json(REPORT / "memory_run_receipt.json", {
        "task_id": "TASK_177", "revision": 1, "status": "RUNNING",
        "started_at": started_at, "libraries": outcomes})
    for name, pin in task_metadata()["source_libraries"].items():
        try:
            row = one_library(name, pin["sha256"], pin["expected_unique_export_vas"], environment, started)
        except Exception as failure:
            row = {"library": name, "status": "ERROR", "error": str(failure)}
        outcomes.append(row)
        write_json(REPORT / "memory_run_receipt.json", {
            "task_id": "TASK_177", "revision": 1, "status": "RUNNING",
            "started_at": started_at, "updated_at": now(), "libraries": outcomes})
        write_json(REPORT / "PROGRESS.json", {
            "task_id": "TASK_177", "revision": 1,
            "status": "FRESH_READ_ONLY_GHIDRA_MEMORY_RUNNING", "generated_at": now(),
            "libraries_finished": len(outcomes),
            "source_bytes_matched": sum((entry.get("observed") or {}).get("source_bytes_matched", 0)
                                        for entry in outcomes),
            "fresh_imports": 0, "fresh_decompilations": 0,
            "last_library": name, "last_status": row["status"]})
        print(json.dumps(row), flush=True)
    status = "OUTPUT_READY" if all(row["status"] == "OUTPUT_READY" for row in outcomes) else "PARTIAL_OUTPUT"
    write_json(REPORT / "memory_run_receipt.json", {
        "task_id": "TASK_177", "revision": 1, "status": status,
        "started_at": started_at, "finished_at": now(), "libraries": outcomes})
    print(json.dumps({"status": status, "libraries": len(outcomes)}), flush=True)


if __name__ == "__main__":
    main()
