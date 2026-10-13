"""Pinned aicodec source, canonical rule and exact Codex lane lease."""

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
TASK = ROOT / "RULES/TASK/TASK_164_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md"
TASK_SHA = "c91f97592399d81dad8efdc58a63df484fcd38be3915693481a0c644c31c4c74"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libaicodec.so")
SOURCE_SHA = "f957a5b290991053f65943356816e837ae5a9d996fa0b2809fc89f680fc8a3cc"
REPORT = ROOT / "RULES/REPORT/TASK_164_REPORT_R1"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_164_R1"
SCRIPTS = Path(__file__).resolve().parent
LEASE_ID = "LEASE-CEO-WORKER-TASK_164-R1"
AGENT_ID = "/root/so45_ai_model_search"
FENCE = 1193
PROJECT = SCRATCH / "ghidra_project"
PROJECT_NAME = "Aicodec164"
CHUNK_SIZE = 256
MAX_REPORT_BYTES = 134_217_728


def sha256(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(1024 * 1024), b""):
            h.update(chunk)
    return h.hexdigest()


def now() -> str:
    return datetime.now(timezone.utc).isoformat().replace("+00:00", "Z")


def atomic_bytes(path: Path, value: bytes) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temp = tempfile.mkstemp(prefix=".task164-", dir=path.parent)
    try:
        with os.fdopen(fd, "wb") as f:
            f.write(value)
            f.flush()
            os.fsync(f.fileno())
        os.replace(temp, path)
    finally:
        if os.path.exists(temp):
            os.unlink(temp)


def write_json(path: Path, value: object) -> None:
    atomic_bytes(path, (json.dumps(value, ensure_ascii=False, indent=2) + "\n").encode("utf-8"))


def check_lease() -> dict:
    if sha256(STANDARD) != STANDARD_SHA or sha256(TASK) != TASK_SHA:
        raise RuntimeError("canonical/task identity changed")
    flag = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    if flag.is_file() and flag.read_text(encoding="utf-8-sig").strip().upper() == "TRUE":
        raise RuntimeError("END_AGENT_SESSION=TRUE")
    reg = json.loads((ROOT / ".ai/locks.json").read_text(encoding="utf-8"))
    matches = [x for x in reg["active_locks"] if x.get("lease_id") == LEASE_ID]
    if len(matches) != 1:
        raise RuntimeError("exact TASK_164 lease missing/duplicated")
    lease = matches[0]
    expiry = datetime.fromisoformat(lease["expiry"].replace("Z", "+00:00"))
    if (lease.get("status"), lease.get("agent_id"), lease.get("fencing_token"), lease.get("task_sha")) != (
        "ACTIVE", AGENT_ID, FENCE, TASK_SHA
    ) or expiry <= datetime.now(timezone.utc):
        raise RuntimeError("TASK_164 lease identity/expiry invalid")
    for scope in ("RULES/REPORT/TASK_164_REPORT_R1/**",
                  "scripts/task_164_codex_exports/**", "RESEARCH_WORK/TASK_164_R1/**"):
        if scope not in lease["files_allowed"]:
            raise RuntimeError("missing exact scope: " + scope)
    return lease


def tree_hashes(path: Path) -> dict[str, str]:
    return {p.relative_to(path).as_posix(): sha256(p)
            for p in sorted(path.rglob("*")) if p.is_file()}
