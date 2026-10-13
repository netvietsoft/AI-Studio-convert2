"""Preserve failed chunk 0 and run one labeled serializer correction attempt."""
from __future__ import annotations

import json
import os
import shutil
from datetime import datetime, timezone

from common import CODE, FENCE, LEASE_ID, REPORT, check_lease, now, sha256, write_json
from run import GHIDRA, JAVA_HOME, PROJECT, run_chunk


def main() -> None:
    check_lease()
    chunks = json.loads((REPORT / "chunk_index.json").read_text(encoding="utf-8"))["chunks"]
    if len(chunks) != 4:
        raise RuntimeError("expected four original chunks")
    first = json.loads((REPORT / "chunk_00/ghidra_command.json").read_text(encoding="utf-8"))
    if (first.get("status") != "PARTIAL_OR_FAILED" or first.get("exit_code") != 0 or
            first.get("rows") != 0 or len(first.get("parse_errors", [])) != 32):
        raise RuntimeError("first-attempt serializer failure evidence differs")
    if not (GHIDRA / "support/analyzeHeadless.bat").is_file() or not (JAVA_HOME / "bin/java.exe").is_file():
        raise RuntimeError("Ghidra or JDK missing")
    if not (PROJECT / "PVGColor168.gpr").is_file():
        raise RuntimeError("owned copied project missing")
    failed_tsv = REPORT / chunks[0]["target_tsv"]
    retry_folder = REPORT / "chunk_00_retry1"
    retry_folder.mkdir(parents=True, exist_ok=True)
    retry_tsv = retry_folder / "targets.tsv"
    if retry_tsv.exists() or (retry_folder / "ghidra_command.json").exists():
        raise RuntimeError("labeled correction attempt already begun; no silent rerun")
    shutil.copyfile(failed_tsv, retry_tsv)
    if sha256(retry_tsv) != chunks[0]["target_tsv_sha256"]:
        raise RuntimeError("correction attempt targets differ")
    write_json(retry_folder / "retry_reason.json", {
        "task_id": "TASK_186", "revision": 1, "attempt": "chunk_00_retry1",
        "reason": "First Ghidra process emitted 32 rows, but serializer had an extra quote after extra_body_bytes; raw NDJSON failed parsing.",
        "failed_attempt_receipt_sha256": sha256(REPORT / "chunk_00/ghidra_command.json"),
        "failed_attempt_raw_sha256": sha256(REPORT / "chunk_00/ghidra_raw.ndjson"),
        "corrected_script_sha256": sha256(CODE / "ExportInternal186.java"),
        "same_target_tsv_sha256": sha256(retry_tsv),
        "lease_id": LEASE_ID, "fencing_token": FENCE, "created_at": now(),
    })
    environment = os.environ.copy()
    environment["JAVA_HOME"] = str(JAVA_HOME)
    environment["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + environment.get("PATH", "")
    environment["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    environment["DOUBLE_CLICKED"] = "n"
    retry_chunk = dict(chunks[0], target_tsv="chunk_00_retry1/targets.tsv")
    for chunk in [retry_chunk, *chunks[1:]]:
        check_lease()
        result = run_chunk(chunk, environment)
        output_ready = sum((REPORT / folder / "ghidra_command.json").is_file() and
                           json.loads((REPORT / folder / "ghidra_command.json").read_text(encoding="utf-8"))
                           .get("status") == "OUTPUT_READY"
                           for folder in ("chunk_00_retry1", "chunk_01", "chunk_02", "chunk_03"))
        write_json(REPORT / "PROGRESS.json", {
            "task_id": "TASK_186", "revision": 1, "status": "GHIDRA_RUNNING",
            "generated_at": now(), "lease_id": LEASE_ID, "fencing_token": FENCE,
            "last_chunk": result, "completed_valid_chunks": output_ready,
            "preserved_failed_serializer_attempt": "chunk_00", "fresh_imports": 0,
        })
        print(json.dumps(result), flush=True)
        if result["status"] != "OUTPUT_READY":
            break


if __name__ == "__main__":
    main()
