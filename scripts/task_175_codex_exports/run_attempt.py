"""Copy the verified TASK_155 analyzed project and run one isolated Ghidra attempt."""

from __future__ import annotations

import json
import os
import shutil
import subprocess
import time
from datetime import datetime, timezone
from pathlib import Path

from common import (DEADLINE, FENCE, HISTORICAL_PROJECT, LEASE_ID, LIBRARIES,
                    REPORT, SCRATCH, SCRIPTS, SOURCE_DIR, check_lease, now,
                    sha256, write_json)

GHIDRA = Path("F:/TOOLS/ghidra_12.1.4_PUBLIC")
JAVA_HOME = Path("F:/TOOLS/jdk-21.0.12.1+1")
PROJECT = SCRATCH / "libglide-webp.so/ghidra_project"
PROJECT_NAME = "SmallLib155"
SCRIPT = SCRIPTS / "AttemptGlideMissing175.java"


def tree_hashes(path: Path) -> dict[str, str]:
    return {file.relative_to(path).as_posix(): sha256(file)
            for file in sorted(path.rglob("*")) if file.is_file()}


def main() -> None:
    check_lease()
    if (REPORT / "attempt_command.json").exists() or PROJECT.exists():
        raise RuntimeError("TASK_175 isolated attempt or project copy already exists")
    verified = json.loads((REPORT / "historical_revalidation.json").read_text(encoding="utf-8"))
    if (verified["source_bodies_rehashed"] != 427 or
            verified["historical_ghidra_memory_bodies_rehashed"] != 427 or
            verified["historical_c_like_bodies_recovered"] != 426 or
            len(verified["missing_historical_c_like"]) != 1 or
            verified["missing_historical_c_like"][0]["elf_va"] != "0x328dc"):
        raise RuntimeError("historical precondition changed")
    source = SOURCE_DIR / "libglide-webp.so"
    if sha256(source) != LIBRARIES[source.name][0]:
        raise RuntimeError("original libglide-webp.so changed")
    tool = GHIDRA / "support/analyzeHeadless.bat"
    if not tool.is_file() or not (JAVA_HOME / "bin/java.exe").is_file():
        raise RuntimeError("Ghidra/JDK missing")
    if not (HISTORICAL_PROJECT / (PROJECT_NAME + ".gpr")).is_file():
        raise RuntimeError("historical analyzed Ghidra project missing")
    before = tree_hashes(HISTORICAL_PROJECT)
    if not before or sum((HISTORICAL_PROJECT / rel).stat().st_size for rel in before) > 256 * 1024 * 1024:
        raise RuntimeError("historical project copy cap invalid")
    check_lease()
    PROJECT.parent.mkdir(parents=True, exist_ok=True)
    shutil.copytree(HISTORICAL_PROJECT, PROJECT)
    after = tree_hashes(PROJECT)
    if before != after:
        raise RuntimeError("analyzed project copy differs from historical source")
    write_json(REPORT / "project_copy_inventory.json", {
        "task_id": "TASK_175", "revision": 1, "generated_at": now(),
        "historical_project": str(HISTORICAL_PROJECT), "copied_project": str(PROJECT),
        "source_file_count": len(before), "copied_file_count": len(after),
        "source_files_sha256": before, "copied_files_sha256_before_attempt": after,
        "historical_ghidra_command_sha256": sha256(
            REPORT / "historical_TASK_155_R1/libglide-webp.so/ghidra_command.json")})
    output = REPORT / "alternative_normalize_raw.json"
    stdout = REPORT / "alternative_ghidra_stdout.log"
    stderr = REPORT / "alternative_ghidra_stderr.log"
    command = [str(tool), str(PROJECT), PROJECT_NAME,
               "-process", source.name, "-noanalysis", "-readOnly", "-max-cpu", "1",
               "-scriptPath", str(SCRIPTS), "-postScript", SCRIPT.name, str(output)]
    if any(path.exists() for path in (output, stdout, stderr)):
        raise RuntimeError("alternative attempt outputs already exist")
    env = os.environ.copy()
    env["JAVA_HOME"] = str(JAVA_HOME)
    env["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + env.get("PATH", "")
    env["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    env["DOUBLE_CLICKED"] = "n"
    base = {"task_id": "TASK_175", "revision": 1, "lease_id": LEASE_ID,
            "fencing_token": FENCE, "started_at": now(), "source_sha256": LIBRARIES[source.name][0],
            "historical_task_id": "TASK_155", "historical_project_copied": True,
            "fresh_imports": 0, "decompile_target_count": 1,
            "decompile_target_elf_va": "0x328dc", "decompile_timeout_seconds": 15,
            "max_cpu": 1, "GHIDRA_HEADLESS_MAXMEM": "1G",
            "script_sha256": sha256(SCRIPT), "command": command}
    write_json(REPORT / "attempt_command.json", {**base, "status": "STARTING"})
    begin = time.monotonic()
    code = None
    status = "FAILED"
    try:
        with stdout.open("wb") as out, stderr.open("wb") as err:
            process = subprocess.Popen(command, env=env, stdin=subprocess.DEVNULL,
                                       stdout=out, stderr=err,
                                       creationflags=getattr(subprocess, "CREATE_NO_WINDOW", 0))
            expiry = datetime.fromisoformat(check_lease()["expiry"].replace("Z", "+00:00"))
            remaining = min((expiry - datetime.now(timezone.utc)).total_seconds(),
                            (DEADLINE - datetime.now(timezone.utc)).total_seconds())
            try:
                code = process.wait(timeout=min(900, max(1, remaining - 30)))
            except subprocess.TimeoutExpired:
                process.kill()
                code = process.wait(timeout=15)
                status = "TIMEOUT"
        if status != "TIMEOUT" and code == 0 and output.is_file():
            raw = json.loads(output.read_text(encoding="utf-8"))
            if (raw.get("task_id") == "TASK_175" and raw.get("program_name") == source.name and
                    raw.get("elf_va") == "0x328dc"):
                status = "OUTPUT_READY"
    finally:
        elapsed = round(time.monotonic() - begin, 3)
        write_json(REPORT / "attempt_command.json", {**base,
            "ended_at": now(), "elapsed_seconds": elapsed, "exit_code": code,
            "status": status,
            "stdout_sha256": sha256(stdout) if stdout.is_file() else None,
            "stderr_sha256": sha256(stderr) if stderr.is_file() else None,
            "result_sha256": sha256(output) if output.is_file() else None,
            "copied_project_files_sha256_after_attempt": tree_hashes(PROJECT)})
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_175", "revision": 1,
        "status": "ISOLATED_ALTERNATIVE_" + status, "generated_at": now(),
        "lease_id": LEASE_ID, "fencing_token": FENCE,
        "historical_c_like_bodies_recovered": 426, "source_bodies_rehashed": 427,
        "alternative_result_ready": status == "OUTPUT_READY", "independent_review_pending": True})
    print(json.dumps({"status": status, "exit_code": code, "elapsed_seconds": elapsed,
                      "result": str(output) if output.is_file() else None}), flush=True)


if __name__ == "__main__":
    main()
