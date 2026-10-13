"""One-shot continuation after a pre-execution 128/256 guard error; never re-import ARKernel."""
from __future__ import annotations

import json
import os
import time
from datetime import datetime, timezone

from common import (DEADLINE, FENCE, LEASE_ID, NEW_LIBRARIES, REPORT,
                    SCRATCH, SOURCE_DIR, check_lease, now, sha256, write_json)
from run import (AGGREGATE_CAP_SECONDS, JAVA_HOME, PROJECT_NAMES,
                 run_chunk, run_import)

def main() -> None:
    check_lease()
    if (REPORT / "resume_after_guard_receipt.json").exists():
        raise RuntimeError("guard continuation already attempted; no retry")
    batch_path = REPORT / "batch_run_receipt.json"
    batch = json.loads(batch_path.read_text(encoding="utf-8"))
    steps = batch.get("steps", [])
    if ((batch.get("task_id"), batch.get("revision"), batch.get("status")) !=
            ("TASK_168", 1, "RUNNING") or len(steps) != 1 or
            steps[0].get("library") != "libARKernelInterface.so" or
            steps[0].get("status") != "IMPORT_READY" or "chunk" in steps[0]):
        raise RuntimeError("initial batch is not exact expected pre-chunk guard stop")
    first = "libARKernelInterface.so"
    import_receipt = json.loads((REPORT / first / "import/ghidra_command.json").read_text(encoding="utf-8"))
    if (import_receipt.get("status") != "IMPORT_READY" or
            import_receipt.get("fresh_import_attempt_number") != 1 or
            import_receipt.get("lease_id") != LEASE_ID or
            import_receipt.get("fencing_token") != FENCE or
            import_receipt.get("source_sha256") != NEW_LIBRARIES[first][0] or
            import_receipt.get("exit_code") != 0):
        raise RuntimeError("first import cannot be reused")
    project = SCRATCH / first / "ghidra_project" / f"{PROJECT_NAMES[first]}.gpr"
    if not project.is_file() or sha256(project) != import_receipt["project_gpr_sha256"]:
        raise RuntimeError("first imported project identity changed")
    first_index = json.loads((REPORT / first / "source_index.json").read_text(encoding="utf-8"))
    if any((REPORT / meta["folder"] / "ghidra_command.json").exists() or
           (REPORT / meta["folder"] / "ghidra_raw.json").exists()
           for meta in first_index["chunks"]):
        raise RuntimeError("a first-source chunk was already attempted")
    if (SCRATCH / "libPVGColorFunctions.so" / "ghidra_project").exists():
        raise RuntimeError("second import project already exists")
    env = os.environ.copy()
    env["JAVA_HOME"] = str(JAVA_HOME)
    env["PATH"] = str(JAVA_HOME / "bin") + os.pathsep + env.get("PATH", "")
    env["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    env["DOUBLE_CLICKED"] = "n"
    original_import_seconds = float(import_receipt["elapsed_seconds"])
    began = time.monotonic() - original_import_seconds
    started_at = batch["started_at"]
    write_json(REPORT / "resume_after_guard_receipt.json", {
        "task_id": "TASK_168", "revision": 1, "started_at": now(),
        "reason": "runner guard rejected 256-target chunk before any chunk process launched",
        "first_source_reimported": False, "first_import_command_sha256": sha256(REPORT / first / "import/ghidra_command.json"),
        "first_import_elapsed_seconds": original_import_seconds,
        "lease_id": LEASE_ID, "fencing_token": FENCE, "status": "RUNNING"})
    def record(step: dict) -> None:
        steps.append(step)
        elapsed = time.monotonic() - began
        write_json(batch_path, {"task_id": "TASK_168", "revision": 1,
            "started_at": started_at, "updated_at": now(), "status": "RUNNING",
            "steps": steps, "elapsed_seconds": round(elapsed, 3),
            "resumed_after_pre_execution_guard": True})
        write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_168", "revision": 1,
            "status": "GHIDRA_RUNNING", "generated_at": now(), "lease_id": LEASE_ID,
            "fencing_token": FENCE, "last_step": step,
            "chunks_output_ready": sum(x.get("status") == "OUTPUT_READY" for x in steps),
            "c_like_bodies_observed": sum((x.get("observed") or {}).get("c_like_bodies", 0) for x in steps)})
        print(json.dumps(step), flush=True)
    for name, (digest, count) in NEW_LIBRARIES.items():
        check_lease()
        index = json.loads((REPORT / name / "source_index.json").read_text(encoding="utf-8"))
        if index["unique_export_vas"] != count or sha256(SOURCE_DIR / name) != digest:
            raise RuntimeError("source/index changed: " + name)
        if name != first:
            imp = run_import(name, digest, env, began)
            record(imp)
            if imp["status"] != "IMPORT_READY":
                continue
        for meta in index["chunks"]:
            if datetime.now(timezone.utc) >= DEADLINE or time.monotonic() - began >= AGGREGATE_CAP_SECONDS:
                record({"library": name, "chunk": meta["chunk"], "status": "TIME_BUDGET_NOT_STARTED"})
                continue
            record(run_chunk(name, meta, env, began))
    status = "OUTPUT_READY" if sum(x.get("status") == "OUTPUT_READY" for x in steps) == 4 else "PARTIAL"
    elapsed = round(time.monotonic() - began, 3)
    write_json(batch_path, {"task_id": "TASK_168", "revision": 1,
        "started_at": started_at, "ended_at": now(), "status": status,
        "steps": steps, "elapsed_seconds": elapsed,
        "resumed_after_pre_execution_guard": True})
    write_json(REPORT / "resume_after_guard_receipt.json", {
        "task_id": "TASK_168", "revision": 1, "ended_at": now(),
        "reason": "runner guard rejected 256-target chunk before any chunk process launched",
        "first_source_reimported": False, "first_import_command_sha256": sha256(REPORT / first / "import/ghidra_command.json"),
        "first_import_elapsed_seconds": original_import_seconds,
        "lease_id": LEASE_ID, "fencing_token": FENCE,
        "steps_after_guard": len(steps) - 1, "status": status,
        "aggregate_elapsed_seconds": elapsed})
    print(json.dumps({"status": status, "steps": len(steps), "elapsed_seconds": elapsed}), flush=True)

if __name__ == "__main__":
    main()
