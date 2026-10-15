"""Prove unreviewed cache Program bytes against pinned source before extraction."""
from __future__ import annotations

import json
import os
import subprocess
import time
from datetime import datetime, timezone
from pathlib import Path

from common import (CODE, DEADLINE, FENCE, LEASE_ID, PROJECT, REPORT, SOURCE,
                    SOURCE_SHA, check_lease, now, sha256, write_json)

GHIDRA = Path("F:/TOOLS/ghidra_12.1.4_PUBLIC")
JAVA_HOME = Path("F:/TOOLS/jdk-21.0.12.1+1")
SCRIPT = CODE / "VerifyLayerFlow207.java"


def main() -> None:
    check_lease()
    if sha256(SOURCE) != SOURCE_SHA:
        raise RuntimeError("original LayerFlow SO changed")
    if not (PROJECT / "LayerFlowHair146.gpr").is_file():
        raise RuntimeError("private copied technical-cache project missing")
    if not (GHIDRA / "support/analyzeHeadless.bat").is_file() or not (JAVA_HOME / "bin/java.exe").is_file():
        raise RuntimeError("Ghidra/JDK missing")
    source_index = json.loads((REPORT / "source_index.json").read_text(encoding="utf-8"))
    text = source_index["original_text_section"]
    tsv = REPORT / "identity_targets.tsv"
    folder = REPORT / "identity"
    folder.mkdir(parents=True, exist_ok=True)
    receipt_path = folder / "ghidra_command.json"
    output = folder / "program_identity.json"
    if receipt_path.exists() or output.exists():
        raise RuntimeError("no rerun of attempted identity probe")
    remaining = (DEADLINE - datetime.now(timezone.utc)).total_seconds()
    timeout = min(1200.0, remaining)
    if timeout <= 0:
        raise RuntimeError("task deadline reached")
    command = [str(GHIDRA / "support/analyzeHeadless.bat"), str(PROJECT), "LayerFlowHair146",
               "-process", "libLayerFlow.so", "-noanalysis", "-readOnly", "-max-cpu", "1",
               "-scriptPath", str(CODE), "-postScript", SCRIPT.name, str(tsv), str(output),
               text["elf_va"], str(text["size_bytes"]), text["sha256"]]
    receipt = {"task_id": "TASK_207", "revision": 1, "purpose": "UNREVIEWED_CACHE_PROGRAM_IDENTITY",
               "command": command, "script_sha256": sha256(SCRIPT),
               "target_tsv_sha256": sha256(tsv), "original_source_sha256": SOURCE_SHA,
               "source_text_sha256": text["sha256"], "read_only_project": True,
               "fresh_imports": 0, "lease_id": LEASE_ID, "fencing_token": FENCE,
               "started_at": now(), "timeout_seconds": timeout, "status": "STARTING"}
    write_json(receipt_path, receipt)
    stdout, stderr = folder / "ghidra_stdout.log", folder / "ghidra_stderr.log"
    env = os.environ.copy()
    env["JAVA_HOME"] = str(JAVA_HOME)
    env["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + env.get("PATH", "")
    env["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    env["DOUBLE_CLICKED"] = "n"
    started = time.monotonic()
    try:
        with stdout.open("wb") as out, stderr.open("wb") as err:
            proc = subprocess.Popen(command, env=env, stdin=subprocess.DEVNULL,
                                    stdout=out, stderr=err,
                                    creationflags=(getattr(subprocess, "CREATE_NO_WINDOW", 0) |
                                                   getattr(subprocess, "CREATE_NEW_PROCESS_GROUP", 0)))
            try:
                exit_code = proc.wait(timeout=timeout)
                termination = None
            except subprocess.TimeoutExpired:
                killed = subprocess.run(["taskkill", "/PID", str(proc.pid), "/T", "/F"],
                                        capture_output=True, text=True, timeout=30)
                exit_code = proc.wait(timeout=30)
                termination = {"owned_pid": proc.pid, "taskkill_exit_code": killed.returncode,
                               "stdout": killed.stdout[-1000:], "stderr": killed.stderr[-1000:]}
    finally:
        receipt.update({"ended_at": now(), "elapsed_seconds": round(time.monotonic()-started, 3),
                        "stdout_sha256": sha256(stdout) if stdout.exists() else None,
                        "stderr_sha256": sha256(stderr) if stderr.exists() else None,
                        "output_sha256": sha256(output) if output.exists() else None})
    receipt.update({"exit_code": exit_code, "termination": termination})
    identity = json.loads(output.read_text(encoding="utf-8")) if output.is_file() else {}
    target_rows = identity.get("targets", [])
    basename = identity.get("executable_path_metadata", "").replace("\\", "/").split("/")[-1]
    metadata_sha = identity.get("executable_sha256_metadata", "").lower()
    valid = (exit_code == 0 and termination is None and identity.get("task_id") == "TASK_207"
             and identity.get("program_name") == "libLayerFlow.so"
             and "AARCH64" in identity.get("language_id", "").upper()
             and identity.get("endian") == "LITTLE"
             and identity.get("source_text_sha256") == text["sha256"]
             and identity.get("source_text_size_bytes") == text["size_bytes"]
             and identity.get("full_text_bytes_match") is True
             and identity.get("target_count") == 128
             and identity.get("memory_body_sha256_matches") == 128
             and len(target_rows) == 128
             and [x.get("index") for x in target_rows] == list(range(1,129))
             and all(x.get("body_bytes_match") is True for x in target_rows)
             and (not basename or basename == "libLayerFlow.so")
             and (not metadata_sha or metadata_sha == SOURCE_SHA))
    receipt.update({"status": "IDENTITY_PROVEN" if valid else "IDENTITY_UNCERTAIN",
                    "program_name": identity.get("program_name"),
                    "language_id": identity.get("language_id"),
                    "image_base": identity.get("image_base"),
                    "full_text_bytes_match": identity.get("full_text_bytes_match"),
                    "target_memory_hash_matches": identity.get("memory_body_sha256_matches"),
                    "executable_sha256_metadata": metadata_sha,
                    "executable_path_basename": basename})
    write_json(receipt_path, receipt)
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_207", "revision": 1,
        "status": receipt["status"], "generated_at": now(),
        "lease_id": LEASE_ID, "fencing_token": FENCE,
        "unreviewed_cache_identity_proven_for_pinned_source": valid,
        "full_text_bytes_match": identity.get("full_text_bytes_match"),
        "target_memory_hash_matches": identity.get("memory_body_sha256_matches"),
        "fresh_imports": 0, "c_like_rows": 0})
    print(json.dumps({"status": receipt["status"], "elapsed_seconds": receipt["elapsed_seconds"],
                      "program_name": receipt["program_name"], "language_id": receipt["language_id"],
                      "image_base": receipt["image_base"], "text_match": receipt["full_text_bytes_match"],
                      "body_matches": receipt["target_memory_hash_matches"],
                      "metadata_sha": metadata_sha}))


if __name__ == "__main__":
    main()
