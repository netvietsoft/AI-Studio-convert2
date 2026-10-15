"""Bounded, read-only seven-target Ghidra decompilation for TASK_210."""
from __future__ import annotations

import datetime as dt
import json
import os
from pathlib import Path
import subprocess
import time

from extract_original import ROOT, REPORT, TASK, check_lease, sha, write_json

GHIDRA = Path("F:/TOOLS/ghidra_12.1.4_PUBLIC/support/analyzeHeadless.bat")
JAVA_HOME = Path("F:/TOOLS/jdk-21.0.12.1+1")
SCRIPT_DIR = ROOT / "scripts/task_210_ceo_mt_oversized"
SCRIPT = SCRIPT_DIR / "ExtractInternal210.java"


def main() -> None:
    check_lease()
    index = json.loads((REPORT / "project_copy_index.json").read_text(encoding="utf-8"))
    if index["target_count"] != 7 or not GHIDRA.is_file() or not (JAVA_HOME / "bin/java.exe").is_file():
        raise RuntimeError("missing pinned project, targets or runtime")
    project = Path(index["project_copy"])
    tsv = Path(index["targets_tsv"])
    if sha(tsv) != index["targets_tsv_sha256"]:
        raise RuntimeError("target TSV changed")
    for entry in index["project_files"]:
        if sha(project / entry["relative_path"]) != entry["sha256"]:
            raise RuntimeError("project copy changed before run")
    task_text = TASK.read_text(encoding="utf-8")
    meta = json.loads(task_text.split("```json\n", 1)[1].split("\n```", 1)[0])
    deadline = dt.datetime.fromisoformat(meta["budget_deadline_utc"].replace("Z", "+00:00"))
    remaining = (deadline - dt.datetime.now(dt.timezone.utc)).total_seconds()
    if remaining <= 0:
        raise RuntimeError("task deadline passed")
    timeout = min(1200, remaining)
    output = REPORT / "ghidra_raw"
    stdout = REPORT / "ghidra_stdout.log"
    stderr = REPORT / "ghidra_stderr.log"
    receipt = REPORT / "ghidra_command.json"
    if any(p.exists() for p in (output, stdout, stderr, receipt)):
        raise RuntimeError("headless run already started")
    command = [str(GHIDRA), str(project), index["project_name"], "-process",
               "libMTFilterKernel.so", "-noanalysis", "-readOnly", "-max-cpu", "1",
               "-scriptPath", str(SCRIPT_DIR), "-postScript", SCRIPT.name,
               str(tsv), str(output)]
    base = {"task_id": "TASK_210", "revision": 1, "operation": "READ_ONLY_SEVEN_EXACT_FDE_CANDIDATES",
            "lease_id": "LEASE-CEO-WORKER-TASK_210-R1", "fencing_token": 1248,
            "source_sha256": "f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4",
            "project_source": index["project_source"], "project_copy": str(project),
            "project_index_sha256": sha(REPORT / "project_copy_index.json"),
            "targets_tsv_sha256": sha(tsv), "script_sha256": sha(SCRIPT),
            "command": command, "max_cpu": 1, "max_heap": "1G", "max_process_seconds": timeout,
            "max_per_decompile_seconds": 20, "started_at": dt.datetime.now(dt.timezone.utc).isoformat()}
    check_lease()
    output.mkdir()
    write_json(receipt, {**base, "status": "STARTING"})
    env = os.environ.copy()
    env["JAVA_HOME"] = str(JAVA_HOME)
    env["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + env.get("PATH", "")
    env["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    env["DOUBLE_CLICKED"] = "n"
    began = time.monotonic()
    status = "FAILED"
    with stdout.open("wb") as out, stderr.open("wb") as err:
        proc = subprocess.Popen(command, env=env, stdin=subprocess.DEVNULL,
                                stdout=out, stderr=err,
                                creationflags=getattr(subprocess, "CREATE_NO_WINDOW", 0))
        try:
            code = proc.wait(timeout=timeout)
        except subprocess.TimeoutExpired:
            proc.kill()
            code = proc.wait(timeout=15)
            status = "TIMEOUT"
    files = sorted(output.glob("*.json"))
    if status != "TIMEOUT":
        status = "OUTPUT_READY" if code == 0 and len(files) == 7 else "PARTIAL_OUTPUT"
    post_files = {}
    for entry in index["project_files"]:
        path = project / entry["relative_path"]
        post_files[entry["relative_path"]] = sha(path) if path.is_file() else None
    write_json(receipt, {**base, "status": status, "ended_at": dt.datetime.now(dt.timezone.utc).isoformat(),
                         "elapsed_seconds": round(time.monotonic() - began, 3), "exit_code": code,
                         "raw_result_files": len(files), "raw_result_hashes": {p.name: sha(p) for p in files},
                         "stdout_sha256": sha(stdout), "stderr_sha256": sha(stderr),
                         "project_post_hashes": post_files})
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_210", "revision": 1,
                                           "status": status, "generated_at": dt.datetime.now(dt.timezone.utc).isoformat(),
                                           "source_candidate_count": 7, "ghidra_candidate_count": len(files),
                                           "semantic_equivalence_proven": False})
    print(json.dumps({"status": status, "exit_code": code, "output_files": len(files),
                      "elapsed_seconds": round(time.monotonic() - began, 3)}))


if __name__ == "__main__":
    main()
