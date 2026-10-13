"""Run one 47-candidate Ghidra chunk with a hard 20-minute process bound."""

from __future__ import annotations

import argparse
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
    parser = argparse.ArgumentParser()
    parser.add_argument("--chunk", type=int, required=True, choices=(1, 2, 3))
    args = parser.parse_args()
    guard()
    if sha(SOURCE) != SOURCE_SHA or not (OWN_PROJECT / "Task184.gpr").is_file():
        raise RuntimeError("source/project identity invalid")
    if not (GHIDRA / "support/analyzeHeadless.bat").is_file() or not (JAVA_HOME / "bin/java.exe").is_file():
        raise RuntimeError("Ghidra/JDK missing")
    folder = REPORT / "ghidra" / f"chunk_{args.chunk:02d}"
    targets = folder / "targets.tsv"
    raw = folder / "candidates"
    stdout = folder / "stdout.log"
    stderr = folder / "stderr.log"
    receipt = folder / "command.json"
    if any(p.exists() for p in (raw, stdout, stderr, receipt)):
        raise RuntimeError("no duplicate Ghidra chunk attempt")
    if len(targets.read_text(encoding="utf-8").splitlines()) != 47:
        raise RuntimeError("target chunk count changed")
    timeout = min(1200.0, (DEADLINE - datetime.now(timezone.utc)).total_seconds() - 90)
    if timeout <= 0:
        raise RuntimeError("task deadline too close for bounded process")
    command = [str(GHIDRA / "support/analyzeHeadless.bat"), str(OWN_PROJECT), "Task184",
               "-process", "libVERenderer.so", "-noanalysis", "-readOnly", "-max-cpu", "1",
               "-scriptPath", str(SCRIPTS), "-postScript", "ExtractInternal184.java",
               str(targets), str(raw)]
    environment = os.environ.copy()
    environment["JAVA_HOME"] = str(JAVA_HOME)
    environment["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + environment.get("PATH", "")
    environment["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    environment["DOUBLE_CLICKED"] = "n"
    base = {"schema": "task184-ghidra-command-v1", "task_id": "TASK_184", "revision": 1,
            "chunk": args.chunk, "candidate_count": 47, "fresh_imports": 0,
            "operation": "READ_ONLY_PROCESS_OWNED_COPY", "max_cpu": 1, "max_heap": "1G",
            "per_candidate_decompilation_timeout_seconds": 10,
            "lease_id": LEASE, "fencing_token": FENCE, "source_sha256": SOURCE_SHA,
            "targets_sha256": sha(targets), "java_script_sha256": sha(SCRIPTS / "ExtractInternal184.java"),
            "command": command, "started_at": now(), "timeout_seconds": timeout}
    write_json(receipt, {**base, "status": "STARTING"})
    raw.mkdir(parents=True)
    started = time.monotonic()
    status = "ERROR"
    code = None
    process_pid = None
    kill = None
    try:
        with stdout.open("wb") as out, stderr.open("wb") as err:
            process = subprocess.Popen(command, stdin=subprocess.DEVNULL, stdout=out, stderr=err,
                                       env=environment,
                                       creationflags=(getattr(subprocess, "CREATE_NO_WINDOW", 0) |
                                                      getattr(subprocess, "CREATE_NEW_PROCESS_GROUP", 0)))
            process_pid = process.pid
            try:
                code = process.wait(timeout=timeout)
                status = "EXIT_ZERO" if code == 0 else "EXIT_NONZERO"
            except subprocess.TimeoutExpired:
                killed = subprocess.run(["taskkill", "/PID", str(process.pid), "/T", "/F"],
                                        capture_output=True, text=True, timeout=30)
                kill = {"owned_launcher_pid": process.pid, "exit_code": killed.returncode,
                        "stdout": killed.stdout[-1000:], "stderr": killed.stderr[-1000:]}
                code = process.wait(timeout=30)
                status = "TIMEOUT"
    finally:
        paths = sorted(raw.glob("candidate_*.json"))
        rows = []
        for path in paths:
            try:
                rows.append(json.loads(path.read_text(encoding="utf-8")))
            except Exception:
                pass
        observed = {"candidate_files": len(paths), "parseable_rows": len(rows),
                    "memory_hash_matched": sum(r.get("source_bytes_match") is True for r in rows),
                    "c_like_rows": sum(r.get("decompile_success") is True for r in rows),
                    "instruction_rows": sum(r.get("instruction_count", 0) > 0 for r in rows),
                    "pcode_rows": sum(r.get("pcode_op_count", 0) > 0 for r in rows)}
        if status == "EXIT_ZERO" and len(paths) == 47 and len(rows) == 47:
            status = "OUTPUT_READY"
        write_json(receipt, {**base, "status": status, "ended_at": now(),
                             "elapsed_seconds": round(time.monotonic() - started, 3),
                             "owned_launcher_pid": process_pid, "exit_code": code,
                             "kill_receipt": kill, "observed": observed,
                             "stdout_sha256": sha(stdout) if stdout.exists() else None,
                             "stderr_sha256": sha(stderr) if stderr.exists() else None,
                             "output_files": {p.name: sha(p) for p in paths}})
        write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_184", "revision": 1,
                  "status": "GHIDRA_CHUNK_" + status, "generated_at": now(),
                  "lease_id": LEASE, "fencing_token": FENCE, "chunk": args.chunk,
                  "candidate_files_this_chunk": len(paths), "c_like_this_chunk": observed["c_like_rows"],
                  "ghidra_processes_started_so_far": args.chunk})
    print(json.dumps({"chunk": args.chunk, "status": status,
                      "elapsed_seconds": round(time.monotonic() - started, 3),
                      "observed": observed}), flush=True)


if __name__ == "__main__":
    main()
