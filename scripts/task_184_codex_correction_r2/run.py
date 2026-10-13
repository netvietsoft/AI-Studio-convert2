"""One bounded read-only Ghidra body-membership pass over the 141 R2 targets."""

from __future__ import annotations

import json
import os
import subprocess
import time
from datetime import datetime, timezone
from pathlib import Path

from common import (DEADLINE, FENCE, LEASE, OWN_PROJECT, REPORT, SCRIPTS,
                    SOURCE, SOURCE_SHA, guard, now, sha, write_json)

GHIDRA = Path("F:/TOOLS/ghidra_12.1.4_PUBLIC")
JAVA_HOME = Path("F:/TOOLS/jdk-21.0.12.1+1")


def main() -> None:
    guard()
    targets = REPORT / "targets.tsv"
    output = REPORT / "body_membership.ndjson"
    stdout = REPORT / "ghidra_stdout.log"
    stderr = REPORT / "ghidra_stderr.log"
    receipt = REPORT / "ghidra_command.json"
    if any(path.exists() for path in (output, stdout, stderr, receipt)):
        raise RuntimeError("no duplicate TASK_184 R2 Ghidra process")
    if len(targets.read_text(encoding="utf-8").splitlines()) != 141:
        raise RuntimeError("target TSV count changed")
    if sha(SOURCE) != SOURCE_SHA or not (OWN_PROJECT / "Task184R2.gpr").is_file():
        raise RuntimeError("source or owned project identity invalid")
    timeout = min(1200.0, (DEADLINE - datetime.now(timezone.utc)).total_seconds() - 90.0)
    if timeout <= 0:
        raise RuntimeError("deadline too close for bounded Ghidra pass")
    script = SCRIPTS / "ReviewBodyMembership184R2.java"
    command = [str(GHIDRA / "support/analyzeHeadless.bat"), str(OWN_PROJECT), "Task184R2",
               "-process", "libVERenderer.so", "-noanalysis", "-readOnly", "-max-cpu", "1",
               "-scriptPath", str(SCRIPTS), "-postScript", script.name,
               str(targets), str(output)]
    environment = os.environ.copy()
    environment["JAVA_HOME"] = str(JAVA_HOME)
    environment["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + environment.get("PATH", "")
    environment["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    environment["DOUBLE_CLICKED"] = "n"
    base = {"schema": "task184-r2-ghidra-command-v1", "task_id": "TASK_184",
            "revision": 2, "lease_id": LEASE, "fencing_token": FENCE,
            "source_sha256": SOURCE_SHA, "fresh_imports": 0,
            "operation": "READ_ONLY_BODY_MEMBERSHIP_OWNED_PROJECT",
            "max_cpu": 1, "max_heap": "1G", "targets_sha256": sha(targets),
            "script_sha256": sha(script), "command": command,
            "started_at": now(), "timeout_seconds": timeout}
    write_json(receipt, {**base, "status": "STARTING"})
    started = time.monotonic()
    status = "ERROR"
    code = None
    launcher_pid = None
    kill_receipt = None
    try:
        with stdout.open("wb") as out, stderr.open("wb") as err:
            process = subprocess.Popen(command, stdin=subprocess.DEVNULL, stdout=out,
                                       stderr=err, env=environment,
                                       creationflags=(getattr(subprocess, "CREATE_NO_WINDOW", 0) |
                                                      getattr(subprocess, "CREATE_NEW_PROCESS_GROUP", 0)))
            launcher_pid = process.pid
            try:
                code = process.wait(timeout=timeout)
                status = "EXIT_ZERO" if code == 0 else "EXIT_NONZERO"
            except subprocess.TimeoutExpired:
                killed = subprocess.run(["taskkill", "/PID", str(process.pid), "/T", "/F"],
                                        capture_output=True, text=True, timeout=30)
                kill_receipt = {"owned_launcher_pid": process.pid,
                                "exit_code": killed.returncode,
                                "stdout": killed.stdout[-1000:], "stderr": killed.stderr[-1000:]}
                code = process.wait(timeout=30)
                status = "TIMEOUT"
    finally:
        rows = []
        if output.is_file():
            try:
                rows = [json.loads(line) for line in output.read_text(encoding="utf-8").splitlines()]
            except Exception:
                pass
        if status == "EXIT_ZERO" and len(rows) == 141:
            status = "OUTPUT_READY"
        observed = {"parseable_rows": len(rows),
                    "exact_body_rows": sum(r.get("body_equals_fde") is True for r in rows),
                    "nonexact_body_rows": sum(r.get("body_equals_fde") is False for r in rows),
                    "nonexact_indices": [r["index"] for r in rows if r.get("body_equals_fde") is False],
                    "index_96_missing_slots": next((r["missing_instruction_slots"] for r in rows if r["index"] == 96), None)}
        write_json(receipt, {**base, "status": status, "ended_at": now(),
                             "elapsed_seconds": round(time.monotonic() - started, 3),
                             "owned_launcher_pid": launcher_pid, "exit_code": code,
                             "kill_receipt": kill_receipt, "observed": observed,
                             "stdout_sha256": sha(stdout) if stdout.exists() else None,
                             "stderr_sha256": sha(stderr) if stderr.exists() else None,
                             "output_sha256": sha(output) if output.exists() else None})
        write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_184", "revision": 2,
                  "status": "GHIDRA_" + status, "generated_at": now(),
                  "lease_id": LEASE, "fencing_token": FENCE,
                  "observed": observed})
    print(json.dumps({"status": status,
                      "elapsed_seconds": round(time.monotonic() - started, 3),
                      "observed": observed}), flush=True)


if __name__ == "__main__":
    main()
