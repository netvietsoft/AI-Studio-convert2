"""TASK_182 one bounded vector-only copied-project Ghidra pass."""

from __future__ import annotations

import hashlib
import json
import os
import shutil
import subprocess
import sys
import tempfile
import time
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
TASK = ROOT / "RULES/TASK/TASK_182_SO45_CODEX_CORRECTION_ACTIVE.md"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libglide-webp.so")
SOURCE_PROJECT = ROOT / "RESEARCH_WORK/TASK_155_R1/libglide-webp.so/ghidra_project"
PROJECT = ROOT / "RESEARCH_WORK/TASK_182_R1/libglide-webp.so/ghidra_project"
REPORT = ROOT / "RULES/REPORT/TASK_182_REPORT_R1"
SCRIPTS = Path(__file__).resolve().parent
STD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
TASK_SHA = "8990e1b96ffa8867ec84270288450ce726f185bbbf1212614d3c43e07a28074b"
SOURCE_SHA = "2f7f38acc0d294a3333069aa8a3c07e69d4bc0a64f162215578bd55dbe1a4486"
BODY_SHA = "fc4cf89d6b719a3d8d73009a57a1e755ca9ce11dda3bdd03da45c5b869053404"
LEASE = "LEASE-CEO-WORKER-TASK_182-R1"
FENCE = 1210
DEADLINE = datetime.fromisoformat("2026-10-13T10:27:48.417200+00:00")


def now() -> str:
    return datetime.now(timezone.utc).isoformat().replace("+00:00", "Z")


def file_hash(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for part in iter(lambda: stream.read(1024 * 1024), b""):
            h.update(part)
    return h.hexdigest()


def hashes(path: Path) -> dict[str, str]:
    return {p.relative_to(path).as_posix(): file_hash(p) for p in sorted(path.rglob("*")) if p.is_file()}


def atomic(path: Path, data: bytes) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temp = tempfile.mkstemp(prefix=".task182-", dir=path.parent)
    try:
        with os.fdopen(fd, "wb") as stream:
            stream.write(data)
            stream.flush()
            os.fsync(stream.fileno())
        os.replace(temp, path)
    finally:
        if os.path.exists(temp):
            os.unlink(temp)


def write_json(path: Path, obj: object) -> None:
    atomic(path, (json.dumps(obj, ensure_ascii=False, indent=2) + "\n").encode())


def guard() -> None:
    if (file_hash(STANDARD), file_hash(TASK), file_hash(SOURCE)) != (STD_SHA, TASK_SHA, SOURCE_SHA):
        raise RuntimeError("canonical/task/source hash changed")
    flag = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    if flag.is_file() and flag.read_text(encoding="utf-8-sig").strip().upper() == "TRUE":
        raise RuntimeError("END_AGENT_SESSION=TRUE")
    locks = json.loads((ROOT / ".ai/locks.json").read_text(encoding="utf-8"))
    hits = [x for x in locks["active_locks"] if x.get("lease_id") == LEASE]
    if len(hits) != 1:
        raise RuntimeError("lease absent/duplicate")
    x = hits[0]
    if (x.get("status"), x.get("agent_id"), x.get("task_id"), x.get("task_revision"),
            x.get("fencing_token"), x.get("task_sha")) != (
            "ACTIVE", "/root/so45_dexvmp_correction", "TASK_182", 1, FENCE, TASK_SHA):
        raise RuntimeError("lease identity invalid")
    expiry = datetime.fromisoformat(x["expiry"].replace("Z", "+00:00"))
    if datetime.now(timezone.utc) >= min(expiry, DEADLINE):
        raise RuntimeError("lease/deadline expired")
    for scope in ("RULES/REPORT/TASK_182_REPORT_R1/**", "RESEARCH_WORK/TASK_182_R1/**",
                  "scripts/task_182_codex_exports/**"):
        if scope not in x["files_allowed"]:
            raise RuntimeError("write scope missing")


def main() -> None:
    guard()
    source_bytes = SOURCE.read_bytes()
    if hashlib.sha256(source_bytes[0x328DC:0x328DC + 624]).hexdigest() != BODY_SHA:
        raise RuntimeError("source target body changed")
    REPORT.mkdir(parents=True, exist_ok=True)
    if PROJECT.exists():
        raise RuntimeError("one-pass scratch project already exists; refuse duplicate run")
    historical = hashes(SOURCE_PROJECT)
    if not historical or "SmallLib155.gpr" not in historical:
        raise RuntimeError("analyzed source project absent")
    PROJECT.parent.mkdir(parents=True, exist_ok=True)
    shutil.copytree(SOURCE_PROJECT, PROJECT)
    copied = hashes(PROJECT)
    if copied != historical:
        raise RuntimeError("project copy differs before pass")
    write_json(REPORT / "project_copy_receipt.json", {
        "source_project": str(SOURCE_PROJECT), "copied_project": str(PROJECT),
        "files_before": historical, "files_copied": copied,
        "all_file_sha256_equal_before_pass": True, "fresh_imports": 0})
    output = REPORT / "vector_probe_raw.json"
    command = [str(Path("F:/TOOLS/ghidra_12.1.4_PUBLIC/support/analyzeHeadless.bat")),
               str(PROJECT), "SmallLib155", "-process", "libglide-webp.so", "-noanalysis",
               "-readOnly", "-max-cpu", "1", "-scriptPath", str(SCRIPTS), "-postScript",
               "VectorProbe182.java", str(output)]
    env = os.environ.copy()
    env["JAVA_HOME"] = "F:/TOOLS/jdk-21.0.12.1+1"
    env["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    env["DOUBLE_CLICKED"] = "n"
    receipt = {"task_id": "TASK_182", "revision": 1, "started_at": now(),
               "lease_id": LEASE, "fencing_token": FENCE, "source_sha256": SOURCE_SHA,
               "body_sha256": BODY_SHA, "script_sha256": file_hash(SCRIPTS / "VectorProbe182.java"),
               "command": command, "timeout_seconds": 180, "max_cpu": 1, "max_heap": "1G",
               "source_project_files_sha256_before": historical,
               "copied_project_files_sha256_before": copied,
               "synthetic_vector_only": True, "fresh_imports": 0}
    write_json(REPORT / "vector_probe_command.json", receipt)
    started = time.monotonic()
    try:
        done = subprocess.run(command, cwd=ROOT, env=env, capture_output=True, timeout=180,
                              check=False)
        out, err = done.stdout, done.stderr
        code, timed_out = done.returncode, False
    except subprocess.TimeoutExpired as ex:
        out, err = ex.stdout or b"", ex.stderr or b""
        code, timed_out = None, True
    atomic(REPORT / "vector_probe_stdout.log", out)
    atomic(REPORT / "vector_probe_stderr.log", err)
    receipt.update({"ended_at": now(), "elapsed_seconds": time.monotonic() - started,
                    "exit_code": code, "timed_out": timed_out,
                    "stdout_sha256": file_hash(REPORT / "vector_probe_stdout.log"),
                    "stderr_sha256": file_hash(REPORT / "vector_probe_stderr.log"),
                    "result_present": output.is_file(),
                    "result_sha256": file_hash(output) if output.is_file() else None,
                    "source_project_files_sha256_after": hashes(SOURCE_PROJECT),
                    "copied_project_files_sha256_after": hashes(PROJECT)})
    receipt["historical_project_unchanged"] = receipt["source_project_files_sha256_after"] == historical
    receipt["status"] = "OUTPUT_READY" if code == 0 and output.is_file() else "PARTIAL_PASS_FAILURE"
    write_json(REPORT / "vector_probe_command.json", receipt)
    print(f"TASK_182 vector probe status={receipt['status']} elapsed={receipt['elapsed_seconds']:.2f}s "
          f"exit={code} result={output.is_file()} historical_unchanged={receipt['historical_project_unchanged']}")


if __name__ == "__main__":
    main()
