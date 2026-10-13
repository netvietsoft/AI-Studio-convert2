"""One bounded scratch-only Ghidra import plus 20 unwind-range samples."""

from __future__ import annotations

import hashlib
import json
import os
import subprocess
import time
from datetime import datetime, timezone
from pathlib import Path

from package import require_lease


ROOT = Path(__file__).resolve().parents[2]
GHIDRA = Path("F:/TOOLS/ghidra_12.1.4_PUBLIC")
JAVA_HOME = Path("F:/TOOLS/jdk-21.0.12.1+1")
SCRIPTS = ROOT / "scripts/task_174_codex_exports"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_174_R1/scratch"
REPORT = ROOT / "RULES/REPORT/TASK_174_REPORT_R1/raw"
REPAIRED = SCRATCH / "libmfxkit_truncated_repaired_for_ghidra.so"
TARGETS = REPORT / "ghidra_sample_targets.tsv"
OUTPUT = REPORT / "ghidra_sample_raw.json"
RECEIPT = REPORT / "ghidra_command.json"
STDOUT = REPORT / "ghidra_stdout.log"
STDERR = REPORT / "ghidra_stderr.log"
PROJECT_DIR = SCRATCH / "ghidra_project"
DEADLINE = datetime.fromisoformat("2026-10-13T09:35:34.762261+00:00")


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def write_receipt(value: dict) -> None:
    RECEIPT.write_text(json.dumps(value, indent=2) + "\n", encoding="utf-8")


def main() -> None:
    require_lease()
    if any(p.exists() for p in (RECEIPT, STDOUT, STDERR, OUTPUT, PROJECT_DIR)):
        raise RuntimeError("Ghidra attempt/output already present: no duplicate import")
    if not (GHIDRA / "support/analyzeHeadless.bat").is_file():
        raise RuntimeError("Ghidra unavailable")
    if not (JAVA_HOME / "bin/java.exe").is_file():
        raise RuntimeError("JDK unavailable")
    repair_meta = json.loads((REPORT / "scratch_repair.json").read_text(encoding="utf-8"))
    if sha(REPAIRED) != repair_meta["scratch_sha256"]:
        raise ValueError("scratch repair SHA changed")
    if sha(TARGETS) != repair_meta["targets_sha256"]:
        raise ValueError("sample TSV SHA changed")
    now = datetime.now(timezone.utc)
    remaining = (DEADLINE - now).total_seconds()
    if remaining < 950:
        raise RuntimeError("insufficient task deadline for bounded import")
    PROJECT_DIR.mkdir(parents=True)
    command = [
        str(GHIDRA / "support/analyzeHeadless.bat"),
        str(PROJECT_DIR), "Mfx174",
        "-import", str(REPAIRED),
        "-max-cpu", "1", "-analysisTimeoutPerFile", "480",
        "-scriptPath", str(SCRIPTS),
        "-postScript", "ExportFde174.java", str(TARGETS), str(OUTPUT),
    ]
    receipt = {
        "schema": "task174-one-scratch-ghidra-process-v1",
        "task_id": "TASK_174", "revision": 1,
        "lease_id": "LEASE-CEO-WORKER-TASK_174-R1", "fencing_token": 1203,
        "scratch_sha256": sha(REPAIRED),
        "targets_sha256": sha(TARGETS),
        "script_sha256": sha(SCRIPTS / "ExportFde174.java"),
        "command": command, "started_at": now.isoformat(),
        "timeout_seconds": 900,
        "max_cpu": 1, "heap_limit": "1G",
        "status": "STARTING",
    }
    write_receipt(receipt)
    env = os.environ.copy()
    env["JAVA_HOME"] = str(JAVA_HOME)
    env["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + env.get("PATH", "")
    env["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    env["DOUBLE_CLICKED"] = "n"
    started = time.monotonic()
    exit_code = None
    status = "FAILED"
    kill_receipt = None
    try:
        with STDOUT.open("wb") as out, STDERR.open("wb") as err:
            process = subprocess.Popen(
                command, cwd=ROOT, env=env, stdin=subprocess.DEVNULL,
                stdout=out, stderr=err,
                creationflags=(getattr(subprocess, "CREATE_NO_WINDOW", 0) |
                               getattr(subprocess, "CREATE_NEW_PROCESS_GROUP", 0)),
            )
            try:
                exit_code = process.wait(timeout=900)
                status = "EXIT_ZERO" if exit_code == 0 else "EXIT_NONZERO"
            except subprocess.TimeoutExpired:
                killed = subprocess.run(
                    ["taskkill", "/PID", str(process.pid), "/T", "/F"],
                    capture_output=True, text=True, timeout=30,
                )
                kill_receipt = {
                    "owned_launcher_pid": process.pid,
                    "exit_code": killed.returncode,
                    "stdout": killed.stdout[-1000:], "stderr": killed.stderr[-1000:],
                }
                exit_code = process.wait(timeout=30)
                status = "TIMEOUT"
    finally:
        receipt.update({
            "ended_at": datetime.now(timezone.utc).isoformat(),
            "elapsed_seconds": round(time.monotonic() - started, 3),
            "exit_code": exit_code, "status": status,
            "kill_receipt": kill_receipt,
            "stdout_sha256": sha(STDOUT) if STDOUT.exists() else None,
            "stderr_sha256": sha(STDERR) if STDERR.exists() else None,
            "output_sha256": sha(OUTPUT) if OUTPUT.exists() else None,
            "output_bytes": OUTPUT.stat().st_size if OUTPUT.exists() else None,
        })
        write_receipt(receipt)
    print(json.dumps({
        "status": status, "exit_code": exit_code,
        "output_exists": OUTPUT.exists(),
        "output_bytes": receipt["output_bytes"],
        "elapsed_seconds": receipt["elapsed_seconds"],
    }))


if __name__ == "__main__":
    main()
