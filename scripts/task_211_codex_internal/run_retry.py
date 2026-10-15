"""One read-only Ghidra retry and a separate fresh-session verification."""
from __future__ import annotations

import hashlib
import json
import os
import shutil
import subprocess
import sys
import time
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
REPORT = ROOT / "RULES/REPORT/TASK_211_REPORT_R1"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_211_R1"
SOURCE_INDEX = ROOT / "RULES/REPORT/TASK_208_REPORT_R1/source_project_index.json"
TASK = ROOT / "RULES/TASK/TASK_211_SO45_PVGIMAGE_R1_RECOVERY_ACTIVE.md"
SCRIPT = Path(__file__).resolve().parent / "RetryIndex466.java"
GHIDRA = Path("F:/TOOLS/ghidra_12.1.4_PUBLIC/support/analyzeHeadless.bat")
JAVA_HOME = Path("F:/TOOLS/jdk-21.0.12.1+1")
LEASE = "LEASE-CEO-WORKER-TASK_211-R1"
TASK_SHA = "d52fbd35b774d1e35979cd0f55bd6ba87f860a48b8834b767105f40d05f825e5"


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def now() -> str:
    return datetime.now(timezone.utc).isoformat()


def check_lease() -> None:
    if sha(TASK) != TASK_SHA:
        raise RuntimeError("TASK_211 text changed")
    locks = json.loads((ROOT / ".ai/locks.json").read_text(encoding="utf8"))
    matches = [x for x in locks["active_locks"] if x.get("lease_id") == LEASE]
    if len(matches) != 1:
        raise RuntimeError("exact lease absent")
    lock = matches[0]
    if (lock.get("fencing_token") != 1249 or lock.get("agent_id") != "/root/audit_208"
            or lock.get("task_sha") != TASK_SHA or lock.get("status") != "ACTIVE"):
        raise RuntimeError("lease/fence/actor invalid")
    expiry = datetime.fromisoformat(lock["expiry"])
    if datetime.now(timezone.utc) >= expiry:
        raise RuntimeError("lease expired")


def main(mode: str) -> None:
    check_lease()
    if mode not in ("retry", "fresh_verify"):
        raise RuntimeError("mode must be retry/fresh_verify")
    if not GHIDRA.is_file() or not (JAVA_HOME / "bin/java.exe").is_file():
        raise RuntimeError("Ghidra/JDK absent")
    index = json.loads(SOURCE_INDEX.read_text(encoding="utf8"))
    project_src = Path(index["project_copy"])
    project = SCRATCH / "ghidra_project"
    if mode == "retry":
        if project.exists():
            raise RuntimeError("private project already exists")
        SCRATCH.mkdir(parents=True, exist_ok=True)
        for item in index["project_files"]:
            if sha(project_src / item["relative_path"]) != item["sha256"]:
                raise RuntimeError("R1 analyzed project differs before copy")
        shutil.copytree(project_src, project)
    elif not project.is_dir():
        raise RuntimeError("private project missing for fresh session")
    before = {x["relative_path"]: sha(project / x["relative_path"])
              for x in index["project_files"]}
    if before != {x["relative_path"]: x["sha256"] for x in index["project_files"]}:
        raise RuntimeError("private project copy differs from original technical input")
    REPORT.mkdir(parents=True, exist_ok=True)
    outfile = REPORT / f"row466_{mode}.json"
    receipt = REPORT / f"row466_{mode}_command.json"
    stdout = REPORT / f"row466_{mode}_stdout.log"
    stderr = REPORT / f"row466_{mode}_stderr.log"
    if any(x.exists() for x in (outfile, receipt, stdout, stderr)):
        raise RuntimeError("output already exists")
    cmd = [str(GHIDRA), str(project), index["project_name"],
           "-process", "libPVGImageCodec.so", "-noanalysis", "-readOnly",
           "-max-cpu", "1", "-scriptPath", str(SCRIPT.parent),
           "-postScript", SCRIPT.name, str(outfile), mode]
    env = os.environ.copy()
    env["JAVA_HOME"] = str(JAVA_HOME)
    env["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + env.get("PATH", "")
    env["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    env["DOUBLE_CLICKED"] = "n"
    check_lease()
    start = time.monotonic()
    status = "PROCESS_FAILED"
    code = None
    with stdout.open("wb") as out, stderr.open("wb") as err:
        proc = subprocess.Popen(cmd, env=env, stdin=subprocess.DEVNULL,
                                stdout=out, stderr=err,
                                creationflags=getattr(subprocess, "CREATE_NO_WINDOW", 0))
        try:
            code = proc.wait(timeout=1200)
        except subprocess.TimeoutExpired:
            proc.kill()
            code = proc.wait(timeout=15)
            status = "PROCESS_TIMEOUT"
    after = {x["relative_path"]: sha(project / x["relative_path"])
             for x in index["project_files"]}
    if status != "PROCESS_TIMEOUT":
        status = "OUTPUT_READY" if code == 0 and outfile.is_file() else "PARTIAL_OUTPUT"
    result = {
        "task_id": "TASK_211", "revision": 1,
        "lease_id": LEASE, "fencing_token": 1249,
        "mode": mode, "status": status, "exit_code": code,
        "command": cmd, "max_cpu": 1, "max_heap": "1G",
        "max_process_seconds": 1200, "max_per_decompile_seconds": 15,
        "elapsed_seconds": round(time.monotonic() - start, 3),
        "ended_at": now(), "script_sha256": sha(SCRIPT),
        "source_project_sha256": sha(project_src / "Task160.rep/idata/00/~00000000.db/db.1.gbf"),
        "project_file_hashes_before": before,
        "project_file_hashes_after": after,
        "project_metadata_unchanged": before == after,
        "stdout_sha256": sha(stdout), "stderr_sha256": sha(stderr),
        "output_sha256": sha(outfile) if outfile.is_file() else None,
    }
    receipt.write_text(json.dumps(result, indent=2) + "\n", encoding="utf8")
    print(json.dumps({k: result[k] for k in
                      ("mode", "status", "exit_code", "elapsed_seconds",
                       "project_metadata_unchanged", "output_sha256")}))


if __name__ == "__main__":
    main(sys.argv[1])
