"""Run exactly one read-only normalized decompile process for each pinned VA."""

from __future__ import annotations

import json
import os
import subprocess
import time
from datetime import datetime, timezone
from pathlib import Path

from common import (DEADLINE, FENCE, LEASE_ID, REPORT, ROOT, SCRATCH, SCRIPTS,
                    SOURCE_DIR, check_lease, now, sha256, write_json)

GHIDRA = Path("F:/TOOLS/ghidra_12.1.4_PUBLIC")
JAVA_HOME = Path("F:/TOOLS/jdk-21.0.12.1+1")
SCRIPT = SCRIPTS / "AltNeon173.java"
MAX_AGGREGATE_SECONDS = 2700
MAX_PROCESS_SECONDS = 210  # 180 seconds decompilation plus bounded startup/shutdown.
TARGET_INDICES = (2283, 2330)
SOURCE_SHA = "d8df8c5cb7a6b5a7eb771782d74a38e0b8d3cfacd1fbef1ae67a96171e3325c9"


def check_project_copy() -> str:
    manifest_path = REPORT / "project_copy_manifest.json"
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    project = SCRATCH / "ghidra_project"
    if manifest["file_count"] != 9 or len(manifest["files"]) != 9:
        raise RuntimeError("analyzed copy manifest count changed")
    for item in manifest["files"]:
        candidate = project / item["relative_path"]
        if not candidate.is_file() or candidate.stat().st_size != item["size_bytes"]:
            raise RuntimeError("analyzed project copy file missing/size changed")
        if sha256(candidate) != item["copy_sha256"]:
            raise RuntimeError("analyzed project copy hash changed")
    return sha256(manifest_path)


def one_target(index: int, source: dict, environment: dict, started: float) -> dict:
    check_lease()
    if sha256(SOURCE_DIR / "libffmpeg.so") != SOURCE_SHA:
        raise RuntimeError("pinned original source changed")
    project_manifest_sha = check_project_copy()
    target_path = REPORT / f"target_{index}.tsv"
    result_path = REPORT / f"alternative_{index}_raw.json"
    stdout_path = REPORT / f"alternative_{index}_stdout.log"
    stderr_path = REPORT / f"alternative_{index}_stderr.log"
    receipt_path = REPORT / f"alternative_{index}_command.json"
    if any(path.exists() for path in (result_path, stdout_path, stderr_path, receipt_path)):
        raise RuntimeError("alternative attempt already started for index " + str(index))
    project = SCRATCH / "ghidra_project"
    command = [str(GHIDRA / "support/analyzeHeadless.bat"), str(project), "Task170",
               "-process", "libffmpeg.so", "-noanalysis", "-readOnly", "-max-cpu", "1",
               "-scriptPath", str(SCRIPTS), "-postScript", SCRIPT.name,
               str(target_path), str(result_path)]
    base = {"task_id": "TASK_173", "revision": 1, "target_index": index,
            "elf_va": source["elf_va"], "symbol": source["symbol"],
            "lease_id": LEASE_ID, "fencing_token": FENCE, "started_at": now(),
            "source_sha256": SOURCE_SHA, "source_body_sha256": source["source_body_sha256"],
            "project_copy_manifest_sha256": project_manifest_sha,
            "target_tsv_sha256": sha256(target_path), "script_sha256": sha256(SCRIPT),
            "operation": "READ_ONLY_PROCESS_ONE_NORMALIZE_ATTEMPT", "command": command}
    write_json(receipt_path, {**base, "status": "STARTING"})
    remaining = min(MAX_PROCESS_SECONDS, MAX_AGGREGATE_SECONDS - (time.monotonic() - started),
                    (DEADLINE - datetime.now(timezone.utc)).total_seconds())
    if remaining <= 0:
        write_json(receipt_path, {**base, "status": "NOT_STARTED_TIME_CAP", "ended_at": now()})
        return {"target_index": index, "status": "NOT_STARTED_TIME_CAP"}
    elapsed_start = time.monotonic()
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
            if (raw.get("task_id") == "TASK_173" and raw.get("target_index") == index and
                raw.get("elf_va") == source["elf_va"] and
                raw.get("source_bytes_match") is True and
                raw.get("ghidra_memory_sha256") == source["source_body_sha256"]):
                status = "OUTPUT_READY"
    finally:
        elapsed = round(time.monotonic() - elapsed_start, 3)
        observed = None
        if result_path.is_file():
            try:
                raw = json.loads(result_path.read_text(encoding="utf-8"))
                observed = {"source_bytes_match": raw.get("source_bytes_match"),
                            "decompile_completed": raw.get("decompile_completed"),
                            "c_like_nonempty": bool(raw.get("c_like", "").strip()),
                            "instruction_rows": len(raw.get("instructions", [])),
                            "raw_pcode_rows": len(raw.get("raw_pcode", [])),
                            "high_pcode_rows": len(raw.get("normalized_high_pcode", [])),
                            "error": raw.get("decompile_error")}
            except Exception as failure:
                observed = {"parse_error": str(failure)}
        write_json(receipt_path, {**base, "ended_at": now(), "elapsed_seconds": elapsed,
                                  "exit_code": code, "status": status,
                                  "stdout_sha256": sha256(stdout_path) if stdout_path.is_file() else None,
                                  "stderr_sha256": sha256(stderr_path) if stderr_path.is_file() else None,
                                  "result_sha256": sha256(result_path) if result_path.is_file() else None,
                                  "observed": observed})
    return {"target_index": index, "status": status, "elapsed_seconds": elapsed,
            "exit_code": code, "observed": observed}


def main() -> None:
    check_lease()
    if (REPORT / "batch_run_receipt.json").exists():
        raise RuntimeError("TASK_173 batch already started")
    if not (GHIDRA / "support/analyzeHeadless.bat").is_file() or not (JAVA_HOME / "bin/java.exe").is_file():
        raise RuntimeError("Ghidra/JDK missing")
    source_index = json.loads((REPORT / "source_targets.json").read_text(encoding="utf-8"))
    sources = {row["index"]: row for row in source_index["targets"]}
    if set(sources) != set(TARGET_INDICES):
        raise RuntimeError("target scope changed")
    environment = os.environ.copy()
    environment["JAVA_HOME"] = str(JAVA_HOME)
    environment["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + environment.get("PATH", "")
    environment["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    environment["DOUBLE_CLICKED"] = "n"
    started_at = now()
    started = time.monotonic()
    outcomes = []
    write_json(REPORT / "batch_run_receipt.json", {
        "task_id": "TASK_173", "revision": 1, "status": "RUNNING",
        "started_at": started_at, "targets": outcomes})
    for index in TARGET_INDICES:
        try:
            row = one_target(index, sources[index], environment, started)
        except Exception as failure:
            row = {"target_index": index, "status": "ERROR", "error": str(failure)}
        outcomes.append(row)
        write_json(REPORT / "batch_run_receipt.json", {
            "task_id": "TASK_173", "revision": 1, "status": "RUNNING",
            "started_at": started_at, "updated_at": now(), "targets": outcomes})
        write_json(REPORT / "PROGRESS.json", {
            "task_id": "TASK_173", "revision": 1, "status": "ALTERNATIVE_DECOMPILE_RUNNING",
            "generated_at": now(), "lease_id": LEASE_ID, "fencing_token": FENCE,
            "attempts_finished": len(outcomes),
            "c_like_nonempty": sum(bool((x.get("observed") or {}).get("c_like_nonempty")) for x in outcomes),
            "last_target_index": index, "last_status": row["status"]})
        print(json.dumps(row), flush=True)
    status = "OUTPUT_READY" if all(x["status"] == "OUTPUT_READY" for x in outcomes) else "PARTIAL_OUTPUT"
    write_json(REPORT / "batch_run_receipt.json", {
        "task_id": "TASK_173", "revision": 1, "status": status,
        "started_at": started_at, "finished_at": now(), "targets": outcomes})
    print(json.dumps({"status": status, "targets": len(outcomes)}), flush=True)


if __name__ == "__main__":
    main()
