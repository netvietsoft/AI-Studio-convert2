"""TASK_176 R1 pinned identities, exact lease guard, and atomic scoped writes."""

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
TASK = ROOT / "RULES/TASK/TASK_176_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md"
TASK_SHA = "9a857be97472797f4613cab6823fac87ca78548437dbb709b432b4ea39996bee"
SOURCE_DIR = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a")
HISTORICAL = ROOT / "RULES/REPORT/TASK_156_REPORT_R1"
HISTORICAL_PROJECTS = ROOT / "RESEARCH_WORK/TASK_156_R1"
REPORT = ROOT / "RULES/REPORT/TASK_176_REPORT_R1"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_176_R1"
SCRIPTS = Path(__file__).resolve().parent
AGENT_ID = "/root/so45_pvg_renderer"
LEASE_ID = "LEASE-CEO-WORKER-TASK_176-R1"
FENCE = 1205
DEADLINE = datetime.fromisoformat("2026-10-13T10:36:32.504425+00:00")
LIBRARIES = {
    "libbmpKit.so": ("550e87fbfd13b8de0833789df04038c659e0472606e6a161eaf775ba126cd168", 316),
    "libfftw3.so": ("0968cee954c2bcbbb8df9daca5a9d122343b280462aaad9533f083f15a4b1c32", 367),
}
SCOPES = ("RULES/REPORT/TASK_176_REPORT_R1/**",
          "scripts/task_176_codex_exports/**", "RESEARCH_WORK/TASK_176_R1/**")


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def now() -> str:
    return datetime.now(timezone.utc).isoformat().replace("+00:00", "Z")


def check_lease() -> dict:
    if sha256(STANDARD) != STANDARD_SHA or sha256(TASK) != TASK_SHA:
        raise RuntimeError("canonical standard or exact TASK_176 revision changed")
    flag = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    if flag.is_file() and flag.read_text(encoding="utf-8-sig").strip().upper() == "TRUE":
        raise RuntimeError("END_AGENT_SESSION=TRUE")
    if datetime.now(timezone.utc) >= DEADLINE:
        raise RuntimeError("original TASK_176 deadline passed")
    registry = json.loads((ROOT / ".ai/locks.json").read_text(encoding="utf-8"))
    rows = [item for item in registry["active_locks"] if item.get("lease_id") == LEASE_ID]
    if len(rows) != 1:
        raise RuntimeError("TASK_176 lease missing or duplicated")
    lease = rows[0]
    identity = (lease.get("status"), lease.get("agent_id"), lease.get("task_id"),
                lease.get("task_revision"), lease.get("task_sha"), lease.get("fencing_token"))
    if identity != ("ACTIVE", AGENT_ID, "TASK_176", 1, TASK_SHA, FENCE):
        raise RuntimeError("TASK_176 lease identity/fence invalid")
    if datetime.fromisoformat(lease["expiry"].replace("Z", "+00:00")) <= datetime.now(timezone.utc):
        raise RuntimeError("TASK_176 lease expired")
    if not set(SCOPES).issubset(lease.get("files_allowed", [])):
        raise RuntimeError("TASK_176 write scopes absent")
    return lease


def atomic_bytes(path: Path, content: bytes) -> None:
    check_lease()
    relative = path.resolve().relative_to(ROOT.resolve()).as_posix()
    if not any(relative.startswith(scope[:-3]) for scope in SCOPES):
        raise RuntimeError("write outside TASK_176 scope: " + relative)
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temporary = tempfile.mkstemp(prefix=".task176-", dir=path.parent)
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
