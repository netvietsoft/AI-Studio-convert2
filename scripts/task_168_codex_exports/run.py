"""One sequential bounded Ghidra import/source and read-only export chunks."""
from __future__ import annotations

import json
import os
import subprocess
import time
from datetime import datetime, timezone
from pathlib import Path

from common import (DEADLINE, FENCE, LEASE_ID, NEW_LIBRARIES, REPORT, SCRATCH,
                    SCRIPTS, SOURCE_DIR, check_lease, now, sha256, write_json)

GHIDRA = Path("F:/TOOLS/ghidra_12.1.4_PUBLIC")
JAVA_HOME = Path("F:/TOOLS/jdk-21.0.12.1+1")
SCRIPT = SCRIPTS / "ExportSo168.java"
PROJECT_NAMES = {"libARKernelInterface.so": "ARKernel168", "libPVGColorFunctions.so": "PVGColor168"}
AGGREGATE_CAP_SECONDS = 6600

def run_process(command: list[str], folder: Path, receipt_path: Path, base: dict,
                env: dict, began: float) -> dict:
    check_lease()
    if receipt_path.exists():
        raise RuntimeError("duplicate process forbidden: " + str(receipt_path))
    timeout = min(900.0, (DEADLINE - datetime.now(timezone.utc)).total_seconds(),
                  AGGREGATE_CAP_SECONDS - (time.monotonic() - began))
    if timeout <= 0:
        return {**base, "status": "TIME_BUDGET_NOT_STARTED", "command": command}
    folder.mkdir(parents=True, exist_ok=True)
    stdout = folder / "ghidra_stdout.log"
    stderr = folder / "ghidra_stderr.log"
    receipt = {**base, "command": command, "started_at": now(),
               "timeout_seconds": round(timeout, 3), "status": "STARTING"}
    write_json(receipt_path, receipt)
    started = time.monotonic()
    exit_code = None
    kill_receipt = None
    status = "FAILED"
    try:
        with stdout.open("wb") as out, stderr.open("wb") as err:
            process = subprocess.Popen(command, env=env, stdin=subprocess.DEVNULL,
                stdout=out, stderr=err,
                creationflags=(getattr(subprocess, "CREATE_NO_WINDOW", 0) |
                               getattr(subprocess, "CREATE_NEW_PROCESS_GROUP", 0)))
            try:
                exit_code = process.wait(timeout=timeout)
            except subprocess.TimeoutExpired:
                killed = subprocess.run(["taskkill", "/PID", str(process.pid), "/T", "/F"],
                                        capture_output=True, text=True, timeout=30)
                kill_receipt = {"own_process_pid": process.pid, "taskkill_exit_code": killed.returncode,
                                "taskkill_stdout": killed.stdout[-1000:],
                                "taskkill_stderr": killed.stderr[-1000:]}
                exit_code = process.wait(timeout=30)
                status = "TIMEOUT"
        if status != "TIMEOUT":
            status = "EXIT_ZERO" if exit_code == 0 else "EXIT_NONZERO"
    finally:
        receipt = {**receipt, "ended_at": now(), "elapsed_seconds": round(time.monotonic() - started, 3),
                   "exit_code": exit_code, "status": status, "kill_receipt": kill_receipt,
                   "stdout_sha256": sha256(stdout) if stdout.is_file() else None,
                   "stderr_sha256": sha256(stderr) if stderr.is_file() else None}
        write_json(receipt_path, receipt)
    return receipt

def run_import(name: str, source_sha: str, env: dict, began: float) -> dict:
    source = SOURCE_DIR / name
    if sha256(source) != source_sha:
        raise RuntimeError("pinned source changed: " + name)
    folder = REPORT / name / "import"
    receipt_path = folder / "ghidra_command.json"
    project = SCRATCH / name / "ghidra_project"
    project_name = PROJECT_NAMES[name]
    if project.exists() or receipt_path.exists():
        return {"library": name, "status": "PRIOR_IMPORT_ATTEMPT_PRESENT_NO_RETRY"}
    project.mkdir(parents=True)
    command = [str(GHIDRA / "support/analyzeHeadless.bat"), str(project), project_name,
               "-import", str(source), "-max-cpu", "1", "-analysisTimeoutPerFile", "480"]
    base = {"task_id": "TASK_168", "revision": 1, "stage": "import", "library": name,
            "source_sha256": source_sha, "lease_id": LEASE_ID, "fencing_token": FENCE,
            "fresh_import_attempt_number": 1}
    receipt = run_process(command, folder, receipt_path, base, env, began)
    gpr = project / f"{project_name}.gpr"
    log = (folder / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace")
    if receipt["status"] == "EXIT_ZERO" and gpr.is_file() and "Import succeeded" in log:
        receipt["status"] = "IMPORT_READY"
        receipt["project_gpr_sha256"] = sha256(gpr)
    else:
        receipt["status"] = "IMPORT_INCOMPLETE"
        receipt["project_gpr_sha256"] = sha256(gpr) if gpr.is_file() else None
    receipt["autoanalysis_timed_out"] = "Analysis timed out" in log
    write_json(receipt_path, receipt)
    return {"library": name, "status": receipt["status"],
            "elapsed_seconds": receipt.get("elapsed_seconds"),
            "autoanalysis_timed_out": receipt["autoanalysis_timed_out"]}

def run_chunk(name: str, meta: dict, env: dict, began: float) -> dict:
    check_lease()
    folder = REPORT / meta["folder"]
    targets = folder / "targets.tsv"
    result = folder / "ghidra_raw.json"
    receipt_path = folder / "ghidra_command.json"
    if receipt_path.exists() or result.exists():
        return {"library": name, "chunk": meta["chunk"], "status": "PRIOR_CHUNK_ATTEMPT_PRESENT_NO_RETRY"}
    if sha256(targets) != meta["target_tsv_sha256"] or meta["count"] > 256:
        raise RuntimeError("chunk target identity/count changed")
    project = SCRATCH / name / "ghidra_project"
    command = [str(GHIDRA / "support/analyzeHeadless.bat"), str(project), PROJECT_NAMES[name],
               "-process", name, "-noanalysis", "-readOnly", "-max-cpu", "1",
               "-scriptPath", str(SCRIPTS), "-postScript", SCRIPT.name, str(targets), str(result)]
    base = {"task_id": "TASK_168", "revision": 1, "stage": "chunk", "library": name,
            "chunk": meta["chunk"], "expected_rows": meta["count"],
            "lease_id": LEASE_ID, "fencing_token": FENCE,
            "target_tsv_sha256": sha256(targets), "script_sha256": sha256(SCRIPT),
            "fresh_imports": 0, "read_only_project": True}
    receipt = run_process(command, folder, receipt_path, base, env, began)
    observed = None
    if result.is_file():
        try:
            raw = json.loads(result.read_text(encoding="utf-8"))
            rows = raw["targets"]
            observed = {"rows": len(rows), "source_bytes_matched": sum(x.get("source_bytes_match") is True for x in rows),
                        "c_like_bodies": sum(x.get("decompile_success") is True and bool(x.get("pseudocode", "").strip()) for x in rows),
                        "instruction_rows": sum(x.get("instruction_count_observed", 0) > 0 for x in rows)}
            if (receipt["status"] == "EXIT_ZERO" and raw.get("task_id") == "TASK_168" and
                    raw.get("program_name") == name and len(rows) == meta["count"]):
                receipt["status"] = "OUTPUT_READY"
        except Exception as exc:
            observed = {"parse_error": str(exc)}
    receipt["result_sha256"] = sha256(result) if result.is_file() else None
    receipt["observed"] = observed
    write_json(receipt_path, receipt)
    return {"library": name, "chunk": meta["chunk"], "status": receipt["status"],
            "elapsed_seconds": receipt.get("elapsed_seconds"), "observed": observed}

def main() -> None:
    check_lease()
    if not (GHIDRA / "support/analyzeHeadless.bat").is_file() or not (JAVA_HOME / "bin/java.exe").is_file():
        raise RuntimeError("Ghidra/JDK unavailable")
    if (REPORT / "batch_run_receipt.json").exists():
        raise RuntimeError("batch already started")
    env = os.environ.copy()
    env["JAVA_HOME"] = str(JAVA_HOME)
    env["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + env.get("PATH", "")
    env["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    env["DOUBLE_CLICKED"] = "n"
    began = time.monotonic()
    started_at = now()
    steps = []
    def record(step: dict) -> None:
        steps.append(step)
        write_json(REPORT / "batch_run_receipt.json", {"task_id": "TASK_168", "revision": 1,
            "started_at": started_at, "updated_at": now(), "status": "RUNNING", "steps": steps,
            "elapsed_seconds": round(time.monotonic() - began, 3)})
        write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_168", "revision": 1,
            "status": "GHIDRA_RUNNING", "generated_at": now(), "lease_id": LEASE_ID,
            "fencing_token": FENCE, "last_step": step,
            "chunks_output_ready": sum(x.get("status") == "OUTPUT_READY" for x in steps),
            "c_like_bodies_observed": sum((x.get("observed") or {}).get("c_like_bodies", 0) for x in steps)})
        print(json.dumps(step), flush=True)
    write_json(REPORT / "batch_run_receipt.json", {"task_id": "TASK_168", "revision": 1,
        "started_at": started_at, "status": "RUNNING", "steps": steps})
    for name, (digest, count) in NEW_LIBRARIES.items():
        check_lease()
        source_index = json.loads((REPORT / name / "source_index.json").read_text(encoding="utf-8"))
        if source_index["unique_export_vas"] != count:
            raise RuntimeError("target index count changed: " + name)
        imp = run_import(name, digest, env, began)
        record(imp)
        if imp["status"] != "IMPORT_READY":
            continue
        for meta in source_index["chunks"]:
            if datetime.now(timezone.utc) >= DEADLINE or time.monotonic() - began >= AGGREGATE_CAP_SECONDS:
                record({"library": name, "chunk": meta["chunk"], "status": "TIME_BUDGET_NOT_STARTED"})
                continue
            step = run_chunk(name, meta, env, began)
            record(step)
    status = "OUTPUT_READY" if sum(x.get("status") == "OUTPUT_READY" for x in steps) == 4 else "PARTIAL"
    write_json(REPORT / "batch_run_receipt.json", {"task_id": "TASK_168", "revision": 1,
        "started_at": started_at, "ended_at": now(), "status": status, "steps": steps,
        "elapsed_seconds": round(time.monotonic() - began, 3)})
    print(json.dumps({"status": status, "steps": len(steps)}), flush=True)

if __name__ == "__main__":
    main()
