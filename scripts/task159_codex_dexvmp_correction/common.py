"""Pinned identities and atomic report writes for TASK_159 R1."""

from __future__ import annotations

import hashlib
import json
import os
import tempfile
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
TASK = ROOT / "RULES/TASK/TASK_159_SO45_CODEX_DEXVMP_CORRECTION_ACTIVE.md"
TASK_SHA = "230b513b634d6bf1f7ee6a1be91008494141226dd976ac1f5f8a15fed8470de6"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libdexvmp.so")
SOURCE_SHA = "b4a46520ec989fef5346833db8f9a1bd6a6690902731414ed26f65cc529cc06e"
PRIOR_REPORT = ROOT / "RULES/REPORT/TASK_156_REPORT_R1/libdexvmp.so"
PRIOR_PROJECT = ROOT / "RESEARCH_WORK/TASK_156_R1/libdexvmp.so/ghidra_project"
REPORT = ROOT / "RULES/REPORT/TASK_159_REPORT_R1"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_159_R1"
PROJECT = SCRATCH / "ghidra_project"
SCRIPTS = Path(__file__).resolve().parent
LEASE_ID = "LEASE-CEO-WORKER-TASK_159-R1"
FENCE = 1187
AGENT_ID = "/root/so45_dexvmp_correction"
DEADLINE = datetime.fromisoformat("2026-10-13T07:57:56.338034+00:00")
SCOPES = (
    "RULES/REPORT/TASK_159_REPORT_R1/**",
    "scripts/task159_codex_dexvmp_correction/**",
    "RESEARCH_WORK/TASK_159_R1/**",
)


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        for block in iter(lambda: handle.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def now() -> str:
    return datetime.now(timezone.utc).isoformat().replace("+00:00", "Z")


def atomic_bytes(path: Path, data: bytes) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temp = tempfile.mkstemp(prefix=".task159-", dir=path.parent)
    try:
        with os.fdopen(fd, "wb") as handle:
            handle.write(data)
            handle.flush()
            os.fsync(handle.fileno())
        os.replace(temp, path)
    finally:
        if os.path.exists(temp):
            os.unlink(temp)


def write_json(path: Path, value: object) -> None:
    atomic_bytes(path, (json.dumps(value, ensure_ascii=False, indent=2) + "\n").encode("utf-8"))


def tree_hashes(root: Path) -> dict[str, str]:
    return {path.relative_to(root).as_posix(): sha256(path)
            for path in sorted(root.rglob("*")) if path.is_file()}


def check_lease() -> dict:
    if sha256(STANDARD) != STANDARD_SHA or sha256(TASK) != TASK_SHA or sha256(SOURCE) != SOURCE_SHA:
        raise RuntimeError("canonical/task/source identity changed")
    flag = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    if flag.is_file() and flag.read_text(encoding="utf-8-sig").strip().upper() == "TRUE":
        raise RuntimeError("END_AGENT_SESSION=TRUE")
    locks = json.loads((ROOT / ".ai/locks.json").read_text(encoding="utf-8"))
    matches = [lock for lock in locks["active_locks"] if lock.get("lease_id") == LEASE_ID]
    if len(matches) != 1:
        raise RuntimeError("TASK_159 lease missing or duplicated")
    lease = matches[0]
    expiry = datetime.fromisoformat(lease["expiry"].replace("Z", "+00:00"))
    if (lease.get("status"), lease.get("agent_id"), lease.get("task_id"),
            lease.get("task_revision"), lease.get("fencing_token"), lease.get("task_sha")) != (
            "ACTIVE", AGENT_ID, "TASK_159", 1, FENCE, TASK_SHA):
        raise RuntimeError("TASK_159 lease identity invalid")
    if expiry <= datetime.now(timezone.utc) or DEADLINE <= datetime.now(timezone.utc):
        raise RuntimeError("TASK_159 lease/deadline expired")
    if any(scope not in lease["files_allowed"] for scope in SCOPES):
        raise RuntimeError("TASK_159 write scope invalid")
    return lease
