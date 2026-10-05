"""
TASK_058 Multi-Process Parallel Orchestrator
Authority: Chairman Tony
Target Task: TASK_058_TASK055_EVIDENCE_COMPLIANCE_AND_SO45_CONTINUATION_ACTIVE
"""

import os
import sys
import time
import zipfile
import hashlib
import subprocess
from pathlib import Path
from datetime import datetime

# Add root to sys.path
sys.path.insert(0, str(Path(__file__).resolve().parent.parent.parent))

from scripts.task058.constants import (
    REPO_ROOT, TASK058_DIR, RAW_EV_DIR, VN_TZ, TASK_ID,
    PACKAGE_ZIP_NAME, PACKAGE_SHA_NAME, LANES_SPEC
)
from scripts.task058.law_gate import run_preexec_law_gate

def compute_sha256(path: Path) -> str:
    h = hashlib.sha256()
    with open(path, "rb") as f:
        while chunk := f.read(65536):
            h.update(chunk)
    return h.hexdigest().upper()

def main():
    print("=" * 80)
    print("TASK_058 MULTI-PROCESS PARALLEL EXECUTION TURN STARTING")
    print(f"Task ID: {TASK_ID}")
    print(f"Time:    {datetime.now(VN_TZ).isoformat()}")
    print("=" * 80)

    # 1. Execute Mandatory Pre-Execution Law Gate
    print("\n[PHASE 1] Executing Mandatory Law Gate...")
    run_preexec_law_gate()

    # 2. Launch Lanes A through F concurrently with independent OS processes
    print("\n[PHASE 2] Launching Lanes A through F in Parallel OS Processes...")
    scripts_dir = Path(__file__).resolve().parent

    active_procs = {}
    for lane_id in ["LANE_A", "LANE_B", "LANE_C", "LANE_D", "LANE_E", "LANE_F"]:
        script_file = scripts_dir / LANES_SPEC[lane_id]["script"]
        proc = subprocess.Popen(
            [sys.executable, str(script_file)],
            cwd=str(REPO_ROOT),
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        active_procs[lane_id] = {
            "proc": proc,
            "pid": proc.pid,
            "script": script_file.name
        }
        print(f"  -> Spawned {lane_id} ({script_file.name}) with OS PID={proc.pid}")

    # Wait for all parallel processes to complete
    print("\n[PHASE 3] Monitoring Parallel Lane Execution...")
    failed_lanes = []
    for lane_id, pinfo in active_procs.items():
        stdout, stderr = pinfo["proc"].communicate()
        exit_code = pinfo["proc"].returncode
        print(f"  -> {lane_id} (PID={pinfo['pid']}) exited with code {exit_code}")
        if stdout:
            for line in stdout.strip().split("\n"):
                print(f"     [STDOUT] {line}")
        if exit_code != 0:
            failed_lanes.append((lane_id, exit_code, stderr))
            print(f"     [STDERR] {stderr}")

    if failed_lanes:
        raise RuntimeError(f"CRITICAL: The following parallel lanes failed: {failed_lanes}")

    # 3. Launch Lane G (Integrator and Evidence Auditor)
    print("\n[PHASE 4] Launching Lane G (Integrator and Auditor)...")
    lane_g_script = scripts_dir / LANES_SPEC["LANE_G"]["script"]
    proc_g = subprocess.Popen(
        [sys.executable, str(lane_g_script)],
        cwd=str(REPO_ROOT),
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    print(f"  -> Spawned LANE_G ({lane_g_script.name}) with OS PID={proc_g.pid}")
    stdout_g, stderr_g = proc_g.communicate()
    print(f"  -> LANE_G (PID={proc_g.pid}) exited with code {proc_g.returncode}")
    if stdout_g:
        for line in stdout_g.strip().split("\n"):
            print(f"     [STDOUT] {line}")
    if proc_g.returncode != 0:
        raise RuntimeError(f"CRITICAL: Lane G failed: {stderr_g}")

    # 4. Package report folder into Zip archive
    print("\n[PHASE 5] Packaging Report Bundle...")
    zip_path = TASK058_DIR / PACKAGE_ZIP_NAME
    with zipfile.ZipFile(zip_path, "w", zipfile.ZIP_DEFLATED) as zipf:
        for item in sorted(TASK058_DIR.rglob("*")):
            if item.is_file() and not item.name.endswith(".zip") and not item.name.endswith(".zip.sha256"):
                rel_path = item.relative_to(TASK058_DIR)
                zipf.write(item, arcname=str(rel_path))

    zip_sha = compute_sha256(zip_path)
    sha_path = TASK058_DIR / PACKAGE_SHA_NAME
    with open(sha_path, "w", encoding="utf-8") as f:
        f.write(f"{zip_sha}  {PACKAGE_ZIP_NAME}\n")

    print(f"[PACKAGE] Generated: {zip_path.name} ({zip_path.stat().st_size:,} bytes)")
    print(f"[PACKAGE] SHA-256:   {zip_sha}")

    print("\n" + "=" * 80)
    print("TASK_058 MULTI-PROCESS EXECUTION TURN COMPLETED SUCCESSFULLY")
    print("=" * 80)

if __name__ == "__main__":
    main()
