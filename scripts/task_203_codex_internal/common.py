"""Pinned identities and fenced, atomic writes for TASK_203."""
from __future__ import annotations

import hashlib
import json
import os
import tempfile
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
CODE = Path(__file__).resolve().parent
REPORT = ROOT / "RULES/REPORT/TASK_203_REPORT_R1"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_203_R1"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
TASK = ROOT / "RULES/TASK/TASK_203_SO45_CODEX_INTERNAL_ACTIVE.md"
MANIFEST = ROOT / ".ai/ceo/reviews/TASK_203_internal_targets.json"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libPVGColorFunctions.so")
PRIOR_PROJECT = ROOT / "RESEARCH_WORK/TASK_200_R1/ghidra_project"
PROJECT = SCRATCH / "ghidra_project"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
TASK_SHA = "3491b85ad4935c7ae64cf940c97e8933186cbe3378f0321349d066cb37384089"
MANIFEST_SHA = "96936496c5edc481ace634698375d3ae72977f4916844fa2d581ebe1ac82d522"
SOURCE_SHA = "3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6"
AGENT_ID = "/root/so45_pvg_followon"
LEASE_ID = "LEASE-CEO-WORKER-TASK_203-R1"
FENCE = 1236
DEADLINE = datetime.fromisoformat("2026-10-13T14:30:13.240060+00:00")


def now() -> str:
    return datetime.now(timezone.utc).isoformat().replace("+00:00", "Z")


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for part in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(part)
    return digest.hexdigest()


def atomic_bytes(path: Path, content: bytes) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temp = tempfile.mkstemp(prefix=".task203-", dir=path.parent)
    try:
        with os.fdopen(fd, "wb") as stream:
            stream.write(content)
            stream.flush()
            os.fsync(stream.fileno())
        os.replace(temp, path)
    finally:
        if os.path.exists(temp):
            os.unlink(temp)


def write_json(path: Path, value: object) -> None:
    atomic_bytes(path, (json.dumps(value, ensure_ascii=False, indent=2) + "\n").encode("utf-8"))


def check_lease() -> dict:
    if sha256(STANDARD) != STANDARD_SHA or sha256(TASK) != TASK_SHA or sha256(MANIFEST) != MANIFEST_SHA:
        raise RuntimeError("pinned canonical/task/target SHA changed")
    flag = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    if flag.is_file() and flag.read_text(encoding="utf-8-sig").strip().upper() == "TRUE":
        raise RuntimeError("END_AGENT_SESSION=TRUE")
    locks = json.loads((ROOT / ".ai/locks.json").read_text(encoding="utf-8"))["active_locks"]
    matches = [item for item in locks if item.get("lease_id") == LEASE_ID]
    if len(matches) != 1:
        raise RuntimeError("exact lease missing or duplicated")
    lease = matches[0]
    identity = (lease.get("status"), lease.get("agent_id"), lease.get("fencing_token"), lease.get("task_sha"))
    if identity != ("ACTIVE", AGENT_ID, FENCE, TASK_SHA):
        raise RuntimeError(f"lease identity mismatch: {identity}")
    if datetime.fromisoformat(lease["expiry"].replace("Z", "+00:00")) <= datetime.now(timezone.utc):
        raise RuntimeError("lease expired")
    if datetime.now(timezone.utc) >= DEADLINE:
        raise RuntimeError("task deadline exceeded")
    required = ("RULES/REPORT/TASK_203_REPORT_R1/**", "scripts/task_203_codex_internal/**",
                "RESEARCH_WORK/TASK_203_R1/**")
    if any(scope not in lease["files_allowed"] for scope in required):
        raise RuntimeError("lease missing required write scope")
    return lease
