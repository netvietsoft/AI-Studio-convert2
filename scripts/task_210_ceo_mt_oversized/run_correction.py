"""Transient gap probe followed by fresh-session rollback verification."""
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
SCRIPTS = ROOT / "scripts/task_210_ceo_mt_oversized"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_210_R1"


def one(name: str, script: str, target: Path, expected: int) -> dict:
    check_lease()
    index = json.loads((REPORT / "project_copy_index.json").read_text(encoding="utf-8"))
    project = Path(index["project_copy"])
    output = REPORT / name
    stdout, stderr, receipt = [REPORT / f"{name}_{suffix}" for suffix in
                               ("stdout.log", "stderr.log", "command.json")]
    if any(p.exists() for p in (output, stdout, stderr, receipt)):
        raise RuntimeError(f"{name} already run")
    task_meta = json.loads(TASK.read_text(encoding="utf-8").split("```json\n", 1)[1].split("\n```", 1)[0])
    deadline = dt.datetime.fromisoformat(task_meta["budget_deadline_utc"].replace("Z", "+00:00"))
    timeout = min(1200, (deadline - dt.datetime.now(dt.timezone.utc)).total_seconds())
    if timeout <= 0:
        raise RuntimeError("deadline passed")
    command = [str(GHIDRA), str(project), index["project_name"], "-process",
               "libMTFilterKernel.so", "-noanalysis", "-readOnly", "-max-cpu", "1",
               "-scriptPath", str(SCRIPTS), "-postScript", script, str(target), str(output)]
    base = {"task_id": "TASK_210", "revision": 1, "step": name,
            "lease_id": "LEASE-CEO-WORKER-TASK_210-R1", "fencing_token": 1248,
            "command": command, "target_sha256": sha(target),
            "script_sha256": sha(SCRIPTS / script), "project_index_sha256": sha(REPORT / "project_copy_index.json"),
            "max_cpu": 1, "max_heap": "1G", "max_process_seconds": timeout,
            "max_per_decompile_seconds": 20, "started_at": dt.datetime.now(dt.timezone.utc).isoformat()}
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
        status = "OUTPUT_READY" if code == 0 and len(files) == expected else "PARTIAL_OUTPUT"
    result = {**base, "status": status, "ended_at": dt.datetime.now(dt.timezone.utc).isoformat(),
              "elapsed_seconds": round(time.monotonic() - began, 3), "exit_code": code,
              "output_files": len(files), "output_hashes": {p.name: sha(p) for p in files},
              "stdout_sha256": sha(stdout), "stderr_sha256": sha(stderr),
              "project_post_hashes": {r["relative_path"]: sha(project / r["relative_path"])
                                      for r in index["project_files"]}}
    write_json(receipt, result)
    return result


def main() -> None:
    correction = one("ghidra_correction", "RepairMembership210.java",
                     SCRATCH / "correction_targets.tsv", 3)
    if correction["status"] != "OUTPUT_READY":
        print(json.dumps({"correction": correction["status"]}))
        return
    fresh = one("ghidra_rollback_check", "ExtractInternal210.java", SCRATCH / "targets.tsv", 7)
    print(json.dumps({"correction": correction["status"], "correction_rows": correction["output_files"],
                      "fresh_rollback_check": fresh["status"], "fresh_rows": fresh["output_files"]}))


if __name__ == "__main__":
    main()
