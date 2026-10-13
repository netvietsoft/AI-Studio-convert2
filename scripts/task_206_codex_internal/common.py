"""Pinned identities and fenced, atomic writes for TASK_206."""
from __future__ import annotations

import hashlib
import json
import os
import tempfile
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
CODE = Path(__file__).resolve().parent
REPORT = ROOT / "RULES/REPORT/TASK_206_REPORT_R1"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_206_R1"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
TASK = ROOT / "RULES/TASK/TASK_206_SO45_CODEX_INTERNAL_ACTIVE.md"
MANIFEST = ROOT / ".ai/ceo/reviews/TASK_206_internal_targets.json"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libLayerFlow.so")
PRIOR_PROJECT = ROOT / "RESEARCH_WORK/TASK_146_R1/ghidra_project"
PROJECT = SCRATCH / "ghidra_project"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
TASK_SHA = "dc9617701bfe32bef9f268299e09187f020a3e393d8d789c8e6d6e654a0d864f"
MANIFEST_SHA = "a36459181b71d193b2a73606a91e8d855c5ee32557ca211f4c9f7ea289fbb46d"
SOURCE_SHA = "ef8d1581038778b72abca3ca8fd5046e49fd44e0465871b023647fe42a582262"
AGENT_ID = "/root/so45_pvg_followon"
LEASE_ID = "LEASE-CEO-WORKER-TASK_206-R1"
FENCE = 1239
DEADLINE = datetime.fromisoformat("2026-10-13T15:09:28.505005+00:00")


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
    fd, temp = tempfile.mkstemp(prefix=".task206-", dir=path.parent)
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
    required = ("RULES/REPORT/TASK_206_REPORT_R1/**", "scripts/task_206_codex_internal/**",
                "RESEARCH_WORK/TASK_206_R1/**")
    if any(scope not in lease["files_allowed"] for scope in required):
        raise RuntimeError("lease missing required write scope")
    return lease
