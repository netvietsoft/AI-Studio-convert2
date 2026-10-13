"""Pinned identities, lease guard, and atomic output for TASK_173 R1."""

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
TASK = ROOT / "RULES/TASK/TASK_173_SO45_FFMPEG_NEON_CORRECTION_ACTIVE.md"
TASK_SHA = "b263e583054cad24d4f93bbf42f169706b35505437213a6d6e015c768e7cafc0"
SOURCE_DIR = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a")
REPORT = ROOT / "RULES/REPORT/TASK_173_REPORT_R1"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_173_R1"
SCRIPTS = Path(__file__).resolve().parent
LEASE_ID = "LEASE-CEO-WORKER-TASK_173-R1"
AGENT_ID = "/root/so45_pvg_renderer"
FENCE = 1202
DEADLINE = datetime.fromisoformat("2026-10-13T09:16:13.318038+00:00")
LIBRARIES = {
    "libffmpeg.so": ("d8df8c5cb7a6b5a7eb771782d74a38e0b8d3cfacd1fbef1ae67a96171e3325c9", 2461),
}
SCOPES = (
    "RULES/REPORT/TASK_173_REPORT_R1/**",
    "scripts/task_173_codex_exports/**",
    "RESEARCH_WORK/TASK_173_R1/**",
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
        raise RuntimeError("original TASK_173 deadline passed")
    registry = json.loads((ROOT / ".ai/locks.json").read_text(encoding="utf-8"))
    matches = [item for item in registry["active_locks"] if item.get("lease_id") == LEASE_ID]
    if len(matches) != 1:
        raise RuntimeError("exact TASK_173 lease missing/duplicated")
    lease = matches[0]
    expiry = datetime.fromisoformat(lease["expiry"].replace("Z", "+00:00"))
    identity = (lease.get("status"), lease.get("agent_id"), lease.get("task_id"),
                lease.get("task_revision"), lease.get("task_sha"), lease.get("fencing_token"))
    if identity != ("ACTIVE", AGENT_ID, "TASK_173", 1, TASK_SHA, FENCE) or expiry <= datetime.now(timezone.utc):
        raise RuntimeError("TASK_173 lease identity/expiry invalid")
    if not set(SCOPES).issubset(lease.get("files_allowed", [])):
        raise RuntimeError("TASK_173 lease missing exact write scope")
    return lease


def atomic_bytes(path: Path, content: bytes) -> None:
    check_lease()
    relative = path.resolve().relative_to(ROOT.resolve()).as_posix()
    if not any(relative.startswith(scope[:-3]) for scope in SCOPES):
        raise RuntimeError("write outside TASK_173 scope: " + relative)
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temporary = tempfile.mkstemp(prefix=".task173-", dir=path.parent)
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
