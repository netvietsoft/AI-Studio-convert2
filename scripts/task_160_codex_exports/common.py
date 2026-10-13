"""Pinned identities, lease guard, and atomic output for TASK_160 R1."""

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
TASK = ROOT / "RULES/TASK/TASK_160_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md"
TASK_SHA = "6672294da0a90ae239a7d348915f5a748aea8d1496061606c8a9852e58c80989"
SOURCE_DIR = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a")
REPORT = ROOT / "RULES/REPORT/TASK_160_REPORT_R1"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_160_R1"
SCRIPTS = Path(__file__).resolve().parent
LEASE_ID = "LEASE-CEO-WORKER-TASK_160-R1"
AGENT_ID = "/root/so45_pvg_renderer"
FENCE = 1188
DEADLINE = datetime.fromisoformat("2026-10-13T08:40:35.965235+00:00")
LIBRARIES = {
    "libPVGImageCodec.so": ("7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b", 3326),
}
SCOPES = (
    "RULES/REPORT/TASK_160_REPORT_R1/**",
    "scripts/task_160_codex_exports/**",
    "RESEARCH_WORK/TASK_160_R1/**",
)


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as source:
        for chunk in iter(lambda: source.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def now() -> str:
    return datetime.now(timezone.utc).isoformat().replace("+00:00", "Z")


def check_lease() -> dict:
    if sha256(STANDARD) != STANDARD_SHA or sha256(TASK) != TASK_SHA:
        raise RuntimeError("canonical/task identity changed")
    flag = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    if flag.is_file() and flag.read_text(encoding="utf-8-sig").strip().upper() == "TRUE":
        raise RuntimeError("END_AGENT_SESSION=TRUE")
    if datetime.now(timezone.utc) >= DEADLINE:
        raise RuntimeError("original TASK_160 deadline passed")
    registry = json.loads((ROOT / ".ai/locks.json").read_text(encoding="utf-8"))
    matches = [item for item in registry["active_locks"] if item.get("lease_id") == LEASE_ID]
    if len(matches) != 1:
        raise RuntimeError("exact TASK_160 lease missing/duplicated")
    lease = matches[0]
    expiry = datetime.fromisoformat(lease["expiry"].replace("Z", "+00:00"))
    identity = (lease.get("status"), lease.get("agent_id"), lease.get("task_id"),
                lease.get("task_revision"), lease.get("task_sha"), lease.get("fencing_token"))
    if identity != ("ACTIVE", AGENT_ID, "TASK_160", 1, TASK_SHA, FENCE) or expiry <= datetime.now(timezone.utc):
        raise RuntimeError("TASK_160 lease identity/expiry invalid")
    if not set(SCOPES).issubset(lease.get("files_allowed", [])):
        raise RuntimeError("TASK_160 lease missing exact write scope")
    return lease


def atomic_bytes(path: Path, content: bytes) -> None:
    check_lease()
    relative = path.resolve().relative_to(ROOT.resolve()).as_posix()
    if not any(relative.startswith(scope[:-3]) for scope in SCOPES):
        raise RuntimeError("write outside TASK_160 scope: " + relative)
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temporary = tempfile.mkstemp(prefix=".task160-", dir=path.parent)
    try:
        with os.fdopen(fd, "wb") as stream:
            stream.write(content)
            stream.flush()
            os.fsync(stream.fileno())
        os.replace(temporary, path)
    finally:
        if os.path.exists(temporary):
            os.unlink(temporary)


def write_json(path: Path, value: object) -> None:
    atomic_bytes(path, (json.dumps(value, ensure_ascii=False, indent=2) + "\n").encode("utf-8"))
