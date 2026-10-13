"""One transient, rolled-back Ghidra body-gap probe for TASK_190 row 128."""
from __future__ import annotations

import json
import os
import subprocess
import time
from datetime import datetime, timezone
from pathlib import Path

from common import (CODE, DEADLINE, FENCE, LEASE_ID, MANIFEST, PROJECT,
                    REPORT, SOURCE, SOURCE_SHA, check_lease, now, sha256,
                    atomic_bytes, write_json)

GHIDRA = Path("F:/TOOLS/ghidra_12.1.4_PUBLIC")
JAVA_HOME = Path("F:/TOOLS/jdk-21.0.12.1+1")


def main() -> None:
    check_lease()
    if sha256(SOURCE) != SOURCE_SHA:
        raise RuntimeError("source changed")
    original = json.loads((REPORT / "chunk_03/ghidra_raw.ndjson").read_text(encoding="utf-8").splitlines()[-1])
    if (original["index"] != 128 or original["boundary_classification"] !=
            "GHIDRA_BODY_PREFIX_OF_FDE_RANGE" or original["fde_missing_bytes"] != 4 or
            original["fde_missing_ranges"] != ["0x2d99c..0x2d99f"]):
        raise RuntimeError("exact single gap changed; no transient correction permitted")
    target = json.loads(MANIFEST.read_text(encoding="utf-8"))["targets"][127]
    if target["body_sha256"] != original["original_body_sha256"]:
        raise RuntimeError("source/raw target differs")
    prior = REPORT / "project_copy_receipt.json"
    prior_hashes = json.loads(prior.read_text(encoding="utf-8"))["private_copy_file_sha256"]
    current_hashes = {p.relative_to(PROJECT).as_posix(): sha256(p)
                      for p in sorted(PROJECT.rglob("*")) if p.is_file()}
    if current_hashes != prior_hashes:
        raise RuntimeError("private project changed before transient correction")

    folder = REPORT / "transient_gap_correction"
    if folder.exists():
        raise RuntimeError("transient correction folder exists; do not silently rerun")
    folder.mkdir(parents=True)
    tsv = folder / "anomaly.tsv"
    atomic_bytes(tsv, (f"128\t{target['elf_va']}\t{target['size_bytes']}\t"
                       f"{target['body_sha256']}\n").encode("ascii"))
    output = folder / "results"
    script = CODE / "RepairMembership190.java"
    command = [str(GHIDRA / "support/analyzeHeadless.bat"), str(PROJECT), "PVGColor168",
               "-process", "libPVGColorFunctions.so", "-noanalysis", "-readOnly",
               "-max-cpu", "1", "-scriptPath", str(CODE), "-postScript", script.name,
               str(tsv), str(output)]
    env = os.environ.copy()
    env["JAVA_HOME"] = str(JAVA_HOME)
    env["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + env.get("PATH", "")
    env["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    env["DOUBLE_CLICKED"] = "n"
    remaining = (DEADLINE - datetime.now(timezone.utc)).total_seconds()
    timeout = min(1200.0, remaining)
    if timeout <= 0:
        raise RuntimeError("deadline elapsed")
    receipt = {"task_id": "TASK_190", "revision": 1, "status": "STARTING",
               "lease_id": LEASE_ID, "fencing_token": FENCE, "started_at": now(),
               "command": command, "script_sha256": sha256(script),
               "target_tsv_sha256": sha256(tsv), "original_source_sha256": SOURCE_SHA,
               "read_only_project": True, "fresh_imports": 0,
               "timeout_seconds": timeout, "original_raw_row_index": 128,
               "original_raw_body_gap_bytes": 4}
    receipt_path = folder / "ghidra_command.json"
    write_json(receipt_path, receipt)
    stdout, stderr = folder / "ghidra_stdout.log", folder / "ghidra_stderr.log"
    started = time.monotonic()
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
    result_files = sorted(p for p in output.rglob("*.json") if p.is_file()) if output.exists() else []
    results = [json.loads(p.read_text(encoding="utf-8")) for p in result_files]
    post_hashes = {p.relative_to(PROJECT).as_posix(): sha256(p)
                   for p in sorted(PROJECT.rglob("*")) if p.is_file()}
    receipt.update({"ended_at": now(), "elapsed_seconds": round(time.monotonic() - started, 3),
                    "exit_code": exit_code, "termination": termination,
                    "stdout_sha256": sha256(stdout), "stderr_sha256": sha256(stderr),
                    "result_files": [p.relative_to(folder).as_posix() for p in result_files],
                    "result_sha256": {p.relative_to(folder).as_posix(): sha256(p) for p in result_files},
                    "project_file_hashes_unchanged": post_hashes == prior_hashes})
    receipt["status"] = "OUTPUT_READY" if exit_code == 0 and len(results) == 1 and termination is None else "PARTIAL_OR_FAILED"
    write_json(receipt_path, receipt)
    print(json.dumps({"status": receipt["status"], "exit_code": exit_code,
                      "elapsed_seconds": receipt["elapsed_seconds"],
                      "results": len(results), "project_unchanged": post_hashes == prior_hashes,
                      "correction": {k: results[0].get(k) for k in
                                     ("index", "original_function_fde_membership_count",
                                      "other_function_byte_count", "corrected_function_fde_membership_count",
                                      "full_fde_instruction_count", "full_fde_pcode_ops",
                                      "c_like_nonempty", "error")} if results else None}))


if __name__ == "__main__":
    main()
