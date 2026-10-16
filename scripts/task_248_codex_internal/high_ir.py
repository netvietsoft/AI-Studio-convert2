"""Bounded register-style HighFunction IR readout after alternate diagnostics."""

import json
import os
import subprocess
import time
from datetime import datetime, timezone

from run import (DEADLINE, FENCE, GHIDRA, HERE, JAVA_HOME, LEASE, PROJECT, REPORT,
                 guard, json_write, now, sha)


def main() -> None:
    guard()
    if not (REPORT / "alternate/styles.json").is_file():
        raise RuntimeError("alternate diagnostics absent")
    out = REPORT / "register_ir"
    if out.exists():
        raise RuntimeError("no duplicate high IR attempt")
    out.mkdir(parents=True)
    result = out / "result.json"
    command = [str(GHIDRA / "support/analyzeHeadless.bat"), str(PROJECT), "Task158",
        "-process", "libPVGCodec.so", "-noanalysis", "-readOnly", "-max-cpu", "1",
        "-scriptPath", str(HERE), "-postScript", "HighIR248.java", str(result)]
    env = os.environ.copy()
    env["JAVA_HOME"] = str(JAVA_HOME)
    env["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + env.get("PATH", "")
    env["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    env["DOUBLE_CLICKED"] = "n"
    timeout = min(900.0, (DEADLINE - datetime.now(timezone.utc)).total_seconds() - 120)
    if timeout <= 0:
        raise RuntimeError("insufficient remaining time")
    base = {"task_id": "TASK_248", "revision": 1, "lease_id": LEASE, "fencing_token": FENCE,
            "operation": "REGISTER_HIGH_FUNCTION_IR_NO_C", "max_cpu": 1, "max_heap": "1G",
            "per_decompile_timeout_seconds": 15, "command": command,
            "java_script_sha256": sha(HERE / "HighIR248.java"), "started_at": now(),
            "timeout_seconds": timeout}
    json_write(out / "command.json", {**base, "status": "STARTING"})
    start = time.monotonic()
    status = "ERROR"
    code = None
    pid = None
    with (out / "stdout.log").open("wb") as stdout, (out / "stderr.log").open("wb") as stderr:
        proc = subprocess.Popen(command, stdin=subprocess.DEVNULL, stdout=stdout, stderr=stderr,
            env=env, creationflags=(getattr(subprocess, "CREATE_NO_WINDOW", 0) |
                                    getattr(subprocess, "CREATE_NEW_PROCESS_GROUP", 0)))
        pid = proc.pid
        try:
            code = proc.wait(timeout=timeout)
            status = "EXIT_ZERO" if code == 0 else "EXIT_NONZERO"
        except subprocess.TimeoutExpired:
            subprocess.run(["taskkill", "/PID", str(pid), "/T", "/F"], capture_output=True, timeout=30)
            code = proc.wait(timeout=30)
            status = "TIMEOUT"
    if status == "EXIT_ZERO" and result.is_file():
        status = "OUTPUT_READY"
    json_write(out / "command.json", {**base, "status": status, "ended_at": now(),
        "elapsed_seconds": round(time.monotonic() - start, 3), "launcher_pid": pid,
        "exit_code": code, "stdout_sha256": sha(out / "stdout.log"),
        "stderr_sha256": sha(out / "stderr.log"),
        "result_sha256": sha(result) if result.is_file() else None})
    json_write(REPORT / "PROGRESS.json", {"task_id": "TASK_248", "revision": 1,
        "status": "HIGH_IR_" + status, "generated_at": now(), "lease_id": LEASE,
        "fencing_token": FENCE, "result_exists": result.is_file()})
    print(json.dumps({"stage": "HIGH_IR", "status": status,
                      "elapsed_seconds": round(time.monotonic() - start, 3),
                      "result_exists": result.is_file()}), flush=True)


if __name__ == "__main__":
    main()
