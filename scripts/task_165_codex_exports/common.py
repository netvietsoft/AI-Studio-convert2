"""Pinned TASK_165 identity and exact fenced write guard."""
from __future__ import annotations

import hashlib
import json
import os
import tempfile
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SCRIPTS = Path(__file__).resolve().parent
REPORT = ROOT / "RULES/REPORT/TASK_165_REPORT_R1"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_165_R1"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libMTFilterKernel.so")
SOURCE_SHA = "f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
TASK = ROOT / "RULES/TASK/TASK_165_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md"
TASK_SHA = "5adff21b71d60d014f7e85b82fb8a22bd975f22f22fabb46dd0a7e2e4d1388a1"
LEASE_ID = "LEASE-CEO-WORKER-TASK_165-R1"
AGENT_ID = "/root/so45_dexvmp_correction"
FENCE = 1194
DEADLINE = datetime.fromisoformat("2026-10-13T09:20:20.541634+00:00")
HIST151 = ROOT / "RULES/REPORT/TASK_151_REPORT_R1"
HIST152 = ROOT / "RULES/REPORT/TASK_152_REPORT_R1"

def now() -> str:
    return datetime.now(timezone.utc).isoformat().replace("+00:00", "Z")

def sha256(path: Path) -> str:
    value = hashlib.sha256()
    with path.open("rb") as stream:
        for part in iter(lambda: stream.read(1024 * 1024), b""):
            value.update(part)
    return value.hexdigest()

def atomic_bytes(path: Path, payload: bytes) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temp = tempfile.mkstemp(prefix=".task165-", dir=path.parent)
    try:
        with os.fdopen(fd, "wb") as stream:
            stream.write(payload)
            stream.flush()
            os.fsync(stream.fileno())
        os.replace(temp, path)
    finally:
        if os.path.exists(temp):
            os.unlink(temp)

def write_json(path: Path, value: object) -> None:
    atomic_bytes(path, (json.dumps(value, ensure_ascii=False, indent=2) + "\n").encode("utf-8"))

def check_lease() -> dict:
    if sha256(STANDARD) != STANDARD_SHA or sha256(TASK) != TASK_SHA:
        raise RuntimeError("canonical or exact task identity changed")
    flag = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    if flag.is_file() and flag.read_text(encoding="utf-8-sig").strip().upper() == "TRUE":
        raise RuntimeError("END_AGENT_SESSION=TRUE")
    registry = json.loads((ROOT / ".ai/locks.json").read_text(encoding="utf-8"))
    matches = [entry for entry in registry["active_locks"] if entry.get("lease_id") == LEASE_ID]
    if len(matches) != 1:
        raise RuntimeError("exact lease missing or duplicated")
    lease = matches[0]
    identity = (lease.get("status"), lease.get("agent_id"), lease.get("fencing_token"), lease.get("task_sha"))
    if identity != ("ACTIVE", AGENT_ID, FENCE, TASK_SHA):
        raise RuntimeError("exact lease identity invalid")
    if datetime.fromisoformat(lease["expiry"].replace("Z", "+00:00")) <= datetime.now(timezone.utc):
        raise RuntimeError("exact lease expired")
    if datetime.now(timezone.utc) >= DEADLINE:
        raise RuntimeError("task deadline exceeded")
    for scope in ("RULES/REPORT/TASK_165_REPORT_R1/**", "scripts/task_165_codex_exports/**",
                  "RESEARCH_WORK/TASK_165_R1/**"):
        if scope not in lease["files_allowed"]:
            raise RuntimeError("scope missing from lease: " + scope)
    return lease
