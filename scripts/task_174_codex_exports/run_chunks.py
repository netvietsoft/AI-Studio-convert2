"""Sequential read-only Ghidra extraction of remaining byte-complete FDEs."""

from __future__ import annotations

import hashlib
import json
import os
import subprocess
import time
from datetime import datetime, timezone
from pathlib import Path

from package import require_lease
from run_ghidra import GHIDRA, JAVA_HOME, PROJECT_DIR, REPORT, SCRIPTS


ROOT = Path(__file__).resolve().parents[2]
CHUNKS = REPORT / "ghidra_chunks"
DEADLINE = datetime.fromisoformat("2026-10-13T09:35:34.762261+00:00")


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def run_one(entry: dict, env: dict) -> dict:
    require_lease()
    folder = ROOT / entry["folder"]
    targets = folder / "targets.tsv"
    output = folder / "ghidra_raw.json"
    receipt_path = folder / "ghidra_command.json"
    stdout = folder / "ghidra_stdout.log"
    stderr = folder / "ghidra_stderr.log"
    if any(p.exists() for p in (output, receipt_path, stdout, stderr)):
        raise RuntimeError(f"chunk {entry['chunk']} prior attempt exists")
    if sha(targets) != entry["targets_sha256"] or entry["count"] != 200:
        raise ValueError("chunk target identity/count mismatch")
    remaining = (DEADLINE - datetime.now(timezone.utc)).total_seconds()
    timeout = min(900.0, remaining - 90.0)
    if timeout <= 0:
        raise RuntimeError("deadline reached before chunk")
    command = [
        str(GHIDRA / "support/analyzeHeadless.bat"), str(PROJECT_DIR), "Mfx174",
        "-process", "libmfxkit_truncated_repaired_for_ghidra.so",
        "-noanalysis", "-readOnly", "-max-cpu", "1",
        "-scriptPath", str(SCRIPTS),
        "-postScript", "ExportFdeBatch174.java", str(targets), str(output),
    ]
    receipt = {
        "schema": "task174-ghidra-readonly-chunk-v1",
        "task_id": "TASK_174", "revision": 1,
        "lease_id": "LEASE-CEO-WORKER-TASK_174-R1", "fencing_token": 1203,
        "chunk": entry["chunk"], "count": entry["count"],
        "targets_sha256": entry["targets_sha256"],
        "script_sha256": sha(SCRIPTS / "ExportFdeBatch174.java"),
        "fresh_imports": 0, "read_only_project": True,
        "max_cpu": 1, "heap_limit": "1G",
        "command": command,
        "started_at": datetime.now(timezone.utc).isoformat(),
        "timeout_seconds": timeout,
        "status": "STARTING",
    }
    receipt_path.write_text(json.dumps(receipt, indent=2) + "\n", encoding="utf-8")
    started = time.monotonic()
    status = "FAILED"
    code = None
    kill = None
    try:
        with stdout.open("wb") as out, stderr.open("wb") as err:
            proc = subprocess.Popen(
                command, cwd=ROOT, env=env, stdin=subprocess.DEVNULL,
                stdout=out, stderr=err,
                creationflags=(getattr(subprocess, "CREATE_NO_WINDOW", 0) |
                               getattr(subprocess, "CREATE_NEW_PROCESS_GROUP", 0)),
            )
            try:
                code = proc.wait(timeout=timeout)
                status = "EXIT_ZERO" if code == 0 else "EXIT_NONZERO"
            except subprocess.TimeoutExpired:
                result = subprocess.run(
                    ["taskkill", "/PID", str(proc.pid), "/T", "/F"],
                    capture_output=True, text=True, timeout=30,
                )
                kill = {"owned_launcher_pid": proc.pid, "exit_code": result.returncode,
                        "stdout": result.stdout[-1000:], "stderr": result.stderr[-1000:]}
                code = proc.wait(timeout=30)
                status = "TIMEOUT"
    finally:
        receipt.update({
            "ended_at": datetime.now(timezone.utc).isoformat(),
            "elapsed_seconds": round(time.monotonic() - started, 3),
            "status": status, "exit_code": code, "kill_receipt": kill,
            "stdout_sha256": sha(stdout) if stdout.exists() else None,
            "stderr_sha256": sha(stderr) if stderr.exists() else None,
            "output_sha256": sha(output) if output.exists() else None,
            "output_bytes": output.stat().st_size if output.exists() else None,
        })
        receipt_path.write_text(json.dumps(receipt, indent=2) + "\n", encoding="utf-8")
    if status == "EXIT_ZERO" and output.exists():
        data = json.loads(output.read_text(encoding="utf-8"))
        rows = data.get("targets", [])
        receipt["observed"] = {
            "rows": len(rows),
            "source_bytes_match": sum(x.get("source_bytes_match") is True for x in rows),
            "c_like_bodies": sum(x.get("decompile_success") is True and
                                 bool(x.get("pseudocode", "").strip()) for x in rows),
        }
        if len(rows) == entry["count"]:
            receipt["status"] = "OUTPUT_READY"
        receipt_path.write_text(json.dumps(receipt, indent=2) + "\n", encoding="utf-8")
    return receipt


def main() -> None:
    require_lease()
    if not (PROJECT_DIR / "Mfx174.gpr").is_file():
        raise RuntimeError("the one imported scratch project is absent")
    manifest = json.loads((CHUNKS / "manifest.json").read_text(encoding="utf-8"))
    if len(manifest["chunks"]) != 5 or manifest["remaining_count"] != 1000:
        raise ValueError("invalid disjoint chunk manifest")
    env = os.environ.copy()
    env["JAVA_HOME"] = str(JAVA_HOME)
    env["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + env.get("PATH", "")
    env["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    env["DOUBLE_CLICKED"] = "n"
    for entry in manifest["chunks"]:
        result = run_one(entry, env)
        print(json.dumps({"chunk": entry["chunk"], "status": result["status"],
                          "elapsed_seconds": result["elapsed_seconds"],
                          "observed": result.get("observed")}), flush=True)
        if result["status"] != "OUTPUT_READY":
            break


if __name__ == "__main__":
    main()
