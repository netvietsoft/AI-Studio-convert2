"""One bounded independent Ghidra spot-check over 10% spread export VAs."""
from __future__ import annotations

import json
import os
import subprocess
import time
from datetime import datetime, timezone
from pathlib import Path

from common import (DEADLINE, FENCE, LEASE_ID, REPORT, SCRIPTS, SCRATCH,
                    SOURCE, SOURCE_SHA, check_lease, now, sha256, write_json)
from prepare import tree_hashes

GHIDRA = Path("F:/TOOLS/ghidra_12.1.4_PUBLIC/support/analyzeHeadless.bat")
JAVA_HOME = Path("F:/TOOLS/jdk-21.0.12.1+1")
SCRIPT = SCRIPTS / "AuditMTFilter165.java"
PROJECT = SCRATCH / "ghidra_project"
FOLDER = REPORT / "audit_sample"

def main() -> None:
    check_lease()
    receipt_path = FOLDER / "ghidra_command.json"
    result = FOLDER / "ghidra_raw.json"
    stdout = FOLDER / "ghidra_stdout.log"
    stderr = FOLDER / "ghidra_stderr.log"
    if any(path.exists() for path in (receipt_path, result, stdout, stderr)):
        raise RuntimeError("audit process already attempted; no retry")
    index = json.loads((REPORT / "source_index.json").read_text(encoding="utf-8"))
    archive = json.loads((REPORT / "archive_receipt.json").read_text(encoding="utf-8"))
    if index["audit_sample_tsv_sha256"] != sha256(FOLDER / "targets.tsv"):
        raise RuntimeError("spread target file changed")
    if len(index["audit_sample_positions"]) != 237:
        raise RuntimeError("spread sample changed")
    if sha256(SOURCE) != SOURCE_SHA or tree_hashes(PROJECT) != archive["project_file_hashes"]:
        raise RuntimeError("source or copied project changed before spot-check")
    if not GHIDRA.is_file() or not (JAVA_HOME / "bin/java.exe").is_file():
        raise RuntimeError("Ghidra/JDK unavailable")
    timeout = min(900.0, (DEADLINE - datetime.now(timezone.utc)).total_seconds())
    if timeout <= 0:
        raise RuntimeError("task deadline reached before Ghidra spot-check")
    command = [str(GHIDRA), str(PROJECT), "MTFilterHair143", "-process", SOURCE.name,
               "-noanalysis", "-readOnly", "-max-cpu", "1", "-scriptPath", str(SCRIPTS),
               "-postScript", SCRIPT.name, str(FOLDER / "targets.tsv"), str(result)]
    env = os.environ.copy()
    env["JAVA_HOME"] = str(JAVA_HOME)
    env["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + env.get("PATH", "")
    env["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    env["DOUBLE_CLICKED"] = "n"
    receipt = {"task_id": "TASK_165", "revision": 1, "stage": "independent_spread_audit",
               "lease_id": LEASE_ID, "fencing_token": FENCE, "command": command,
               "expected_rows": 237, "source_sha256": SOURCE_SHA,
               "target_tsv_sha256": sha256(FOLDER / "targets.tsv"),
               "script_sha256": sha256(SCRIPT), "fresh_imports_this_revision": 0,
               "read_only_project": True, "timeout_seconds": timeout,
               "started_at": now(), "status": "STARTING"}
    write_json(receipt_path, receipt)
    begin = time.monotonic()
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
                kill_receipt = {"owned_process_pid": process.pid,
                                "taskkill_exit_code": killed.returncode,
                                "taskkill_stdout": killed.stdout[-1000:],
                                "taskkill_stderr": killed.stderr[-1000:]}
                exit_code = process.wait(timeout=30)
                status = "TIMEOUT"
        if status != "TIMEOUT":
            status = "EXIT_ZERO" if exit_code == 0 else "EXIT_NONZERO"
    finally:
        observed = None
        if result.is_file():
            try:
                data = json.loads(result.read_text(encoding="utf-8"))
                rows = data["targets"]
                observed = {"rows": len(rows),
                            "memory_matched": sum(row.get("source_bytes_match") is True for row in rows),
                            "c_like_bodies": sum(row.get("decompile_success") is True and
                                                 bool(row.get("pseudocode", "").strip()) for row in rows)}
                if (status == "EXIT_ZERO" and data.get("task_id") == "TASK_165" and
                        data.get("program_name") == SOURCE.name and len(rows) == 237):
                    status = "OUTPUT_READY"
            except Exception as exc:
                observed = {"parse_error": str(exc)}
        receipt.update({"ended_at": now(), "elapsed_seconds": round(time.monotonic() - begin, 3),
                        "status": status, "exit_code": exit_code, "kill_receipt": kill_receipt,
                        "stdout_sha256": sha256(stdout) if stdout.is_file() else None,
                        "stderr_sha256": sha256(stderr) if stderr.is_file() else None,
                        "result_sha256": sha256(result) if result.is_file() else None,
                        "observed": observed,
                        "post_project_hashes": tree_hashes(PROJECT)})
        write_json(receipt_path, receipt)
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_165", "revision": 1,
        "generated_at": now(), "status": "GHIDRA_SPREAD_AUDIT_" + status,
        "lease_id": LEASE_ID, "fencing_token": FENCE, "observed": observed,
        "fresh_imports_this_revision": 0})
    print(json.dumps({"status": status, "elapsed_seconds": receipt["elapsed_seconds"],
                      "observed": observed}), flush=True)

if __name__ == "__main__":
    main()
