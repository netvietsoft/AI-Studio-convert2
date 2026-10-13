"""Run one bounded scalar-tail Ghidra probe from a copy of TASK_155's analyzed project."""

from __future__ import annotations

import hashlib
import json
import os
import shutil
import subprocess
import time
from pathlib import Path

from evidence import BODY_SHA, FENCE, LEASE, REPORT, ROOT, SOURCE_SHA, check_lease, sha256, utc_now, write_json


SOURCE_PROJECT = ROOT / "RESEARCH_WORK/TASK_155_R1/libglide-webp.so/ghidra_project"
DEST_PROJECT = ROOT / "RESEARCH_WORK/TASK_179_R1/libglide-webp.so/ghidra_project"
SCRIPT = ROOT / "scripts/task_179_codex_exports/ScalarTailProbe179.java"
HEADLESS = Path("F:/TOOLS/ghidra_12.1.4_PUBLIC/support/analyzeHeadless.bat")
JAVA_HOME = "F:/TOOLS/jdk-21.0.12.1+1"


def files_sha(root: Path) -> dict[str, str]:
    return {p.relative_to(root).as_posix(): sha256(p.read_bytes())
            for p in sorted(root.rglob("*")) if p.is_file()}


def main() -> None:
    check_lease()
    if not SCRIPT.is_file() or not HEADLESS.is_file() or not Path(JAVA_HOME).is_dir():
        raise RuntimeError("Ghidra/JDK/script unavailable")
    if DEST_PROJECT.exists() or (REPORT / "scalar_tail_probe_raw.json").exists():
        raise RuntimeError("TASK_179 scalar-tail probe already attempted; no repeat allowed")
    source_before = files_sha(SOURCE_PROJECT)
    if not source_before or "SmallLib155.gpr" not in source_before:
        raise RuntimeError("historical analyzed Ghidra project missing")
    DEST_PROJECT.parent.mkdir(parents=True, exist_ok=True)
    shutil.copytree(SOURCE_PROJECT, DEST_PROJECT)
    dest_before = files_sha(DEST_PROJECT)
    if dest_before != source_before:
        raise RuntimeError("copied Ghidra project differs before probe")
    output = REPORT / "scalar_tail_probe_raw.json"
    command = [str(HEADLESS), str(DEST_PROJECT), "SmallLib155", "-process",
               "libglide-webp.so", "-noanalysis", "-readOnly", "-max-cpu", "1",
               "-scriptPath", str(SCRIPT.parent), "-postScript", SCRIPT.name, str(output)]
    receipt = {"task_id": "TASK_179", "revision": 1, "lease_id": LEASE,
               "fencing_token": FENCE, "started_at": utc_now(), "historical_task_id": "TASK_155",
               "historical_project_source": str(SOURCE_PROJECT),
               "historical_project_files_sha256_before": source_before,
               "copied_project_files_sha256_before": dest_before,
               "fresh_imports": 0, "decompile_passes": 1, "decompile_scope": "synthetic_scalar_tail_only",
               "whole_original_function_decompiled": False,
               "source_sha256": SOURCE_SHA, "source_body_sha256": BODY_SHA,
               "script_sha256": sha256(SCRIPT.read_bytes()),
               "max_cpu": 1, "GHIDRA_HEADLESS_MAXMEM": "1G",
               "decompile_timeout_seconds": 120, "process_timeout_seconds": 180,
               "command": command}
    write_json("probe_command.json", receipt)
    env = os.environ.copy()
    env["JAVA_HOME"] = JAVA_HOME
    env["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    started = time.monotonic()
    try:
        process = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                                 timeout=180, env=env, check=False)
        stdout = process.stdout
        stderr = process.stderr
        exit_code = process.returncode
        timed_out = False
    except subprocess.TimeoutExpired as error:
        stdout = error.stdout or b""
        stderr = error.stderr or b""
        exit_code = None
        timed_out = True
    elapsed = time.monotonic() - started
    check_lease()
    REPORT.mkdir(parents=True, exist_ok=True)
    (REPORT / "probe_stdout.log").write_bytes(stdout)
    (REPORT / "probe_stderr.log").write_bytes(stderr)
    receipt.update({"ended_at": utc_now(), "elapsed_seconds": elapsed,
                    "exit_code": exit_code, "timed_out": timed_out,
                    "stdout_sha256": sha256(stdout), "stderr_sha256": sha256(stderr),
                    "result_present": output.is_file(),
                    "result_sha256": sha256(output.read_bytes()) if output.is_file() else None,
                    "copied_project_files_sha256_after": files_sha(DEST_PROJECT),
                    "historical_project_files_sha256_after": files_sha(SOURCE_PROJECT)})
    receipt["historical_project_unchanged"] = (
        receipt["historical_project_files_sha256_after"] == source_before)
    if not receipt["historical_project_unchanged"]:
        raise RuntimeError("historical analyzed Ghidra project changed unexpectedly")
    receipt["status"] = "OUTPUT_READY" if exit_code == 0 and output.is_file() else "PARTIAL_PROBE_FAILURE"
    write_json("probe_command.json", receipt)
    print(json.dumps({key: receipt[key] for key in ("status", "exit_code", "timed_out",
                                                   "elapsed_seconds", "result_present",
                                                   "historical_project_unchanged")}))


if __name__ == "__main__":
    main()
