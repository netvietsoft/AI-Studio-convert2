"""Run four sequential bounded Ghidra batches against a private copied project."""
from __future__ import annotations

import json
import os
import subprocess
import time
from datetime import datetime, timezone
from pathlib import Path

from common import (CODE, DEADLINE, FENCE, LEASE_ID, MANIFEST, PROJECT, REPORT,
                    SOURCE, SOURCE_SHA, check_lease, now, sha256, write_json)

GHIDRA = Path("F:/TOOLS/ghidra_12.1.4_PUBLIC")
JAVA_HOME = Path("F:/TOOLS/jdk-21.0.12.1+1")
SCRIPT = CODE / "ExportInternal190.java"
MAX_PER_PROCESS_SECONDS = 1200.0


def run_chunk(chunk: dict, env: dict) -> dict:
    check_lease()
    if sha256(SOURCE) != SOURCE_SHA:
        raise RuntimeError("original source changed")
    tsv = REPORT / chunk["target_tsv"]
    if sha256(tsv) != chunk["target_tsv_sha256"]:
        raise RuntimeError("target TSV changed")
    folder = tsv.parent
    receipt_path = folder / "ghidra_command.json"
    output = folder / "ghidra_raw.ndjson"
    if receipt_path.exists() or output.exists():
        raise RuntimeError("no rerun of an attempted Ghidra chunk")
    remaining = (DEADLINE - datetime.now(timezone.utc)).total_seconds()
    timeout = min(MAX_PER_PROCESS_SECONDS, remaining)
    if timeout <= 0:
        raise RuntimeError("task deadline reached before chunk")
    command = [str(GHIDRA / "support/analyzeHeadless.bat"), str(PROJECT), "PVGColor168",
               "-process", "libPVGColorFunctions.so", "-noanalysis", "-readOnly", "-max-cpu", "1",
               "-scriptPath", str(CODE), "-postScript", SCRIPT.name, str(tsv), str(output)]
    stdout, stderr = folder / "ghidra_stdout.log", folder / "ghidra_stderr.log"
    receipt = {"task_id": "TASK_190", "revision": 1, "chunk": chunk["chunk"],
               "start_index": chunk["start_index"], "end_index": chunk["end_index"],
               "command": command, "script_sha256": sha256(SCRIPT), "target_tsv_sha256": sha256(tsv),
               "original_source_sha256": SOURCE_SHA, "fresh_imports": 0, "read_only_project": True,
               "lease_id": LEASE_ID, "fencing_token": FENCE, "started_at": now(),
               "timeout_seconds": timeout, "status": "STARTING"}
    write_json(receipt_path, receipt)
    started = time.monotonic()
    env = env.copy()
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
        receipt.update({"ended_at": now(), "elapsed_seconds": round(time.monotonic() - started, 3),
                        "stdout_sha256": sha256(stdout) if stdout.is_file() else None,
                        "stderr_sha256": sha256(stderr) if stderr.is_file() else None})
    receipt.update({"exit_code": exit_code, "termination": termination,
                    "raw_output_sha256": sha256(output) if output.is_file() else None})
    rows = []
    errors = []
    if output.is_file():
        for line in output.read_text(encoding="utf-8").splitlines():
            try:
                rows.append(json.loads(line))
            except Exception as exc:
                errors.append(str(exc))
    expected = list(range(chunk["start_index"], chunk["end_index"] + 1))
    receipt.update({"rows": len(rows), "row_indices_match": [r.get("index") for r in rows] == expected,
                    "rows_body_bytes_match": sum(r.get("body_bytes_match") is True for r in rows),
                    "rows_c_like": sum(r.get("c_like_present") is True for r in rows),
                    "rows_exact_fde_c_like": sum(r.get("c_like_present") is True and
                        r.get("boundary_classification") == "GHIDRA_BODY_EQUALS_FDE_RANGE" for r in rows),
                    "parse_errors": errors})
    receipt["status"] = ("OUTPUT_READY" if exit_code == 0 and not errors and
                         receipt["row_indices_match"] and len(rows) == len(expected) else
                         ("TIMEOUT" if termination else "PARTIAL_OR_FAILED"))
    write_json(receipt_path, receipt)
    return {"chunk": chunk["chunk"], "status": receipt["status"], "rows": len(rows),
            "c_like": receipt["rows_c_like"], "exact_fde_c_like": receipt["rows_exact_fde_c_like"],
            "elapsed_seconds": receipt["elapsed_seconds"]}


def main() -> None:
    check_lease()
    if not (GHIDRA / "support/analyzeHeadless.bat").is_file() or not (JAVA_HOME / "bin/java.exe").is_file():
        raise RuntimeError("Ghidra/JDK missing")
    if not (PROJECT / "PVGColor168.gpr").is_file():
        raise RuntimeError("private Ghidra project copy missing")
    chunks = json.loads((REPORT / "chunk_index.json").read_text(encoding="utf-8"))["chunks"]
    if len(chunks) != 4:
        raise RuntimeError("expected exactly four bounded chunks")
    env = os.environ.copy()
    env["JAVA_HOME"] = str(JAVA_HOME)
    env["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + env.get("PATH", "")
    env["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    env["DOUBLE_CLICKED"] = "n"
    for chunk in chunks:
        check_lease()
        if datetime.now(timezone.utc) >= DEADLINE:
            break
        result = run_chunk(chunk, env)
        progress = {"task_id": "TASK_190", "revision": 1, "status": "GHIDRA_RUNNING",
                    "generated_at": now(), "lease_id": LEASE_ID, "fencing_token": FENCE,
                    "last_chunk": result, "fresh_imports": 0,
                    "output_ready_chunks": sum((REPORT / f"chunk_{i:02d}/ghidra_command.json").is_file()
                        and json.loads((REPORT / f"chunk_{i:02d}/ghidra_command.json").read_text(encoding="utf8"))
                        .get("status") == "OUTPUT_READY" for i in range(4))}
        write_json(REPORT / "PROGRESS.json", progress)
        print(json.dumps(result), flush=True)
        if result["status"] != "OUTPUT_READY":
            break


if __name__ == "__main__":
    main()
