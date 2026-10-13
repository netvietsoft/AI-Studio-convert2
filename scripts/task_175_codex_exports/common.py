"""Exact TASK_175 R1 identity, lease and scoped output helpers."""

from __future__ import annotations

import hashlib
import json
import os
import tempfile
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SCRIPTS = Path(__file__).resolve().parent
REPORT = ROOT / "RULES/REPORT/TASK_175_REPORT_R1"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_175_R1"
SOURCE_DIR = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a")
HISTORICAL = ROOT / "RULES/REPORT/TASK_155_REPORT_R1"
HISTORICAL_SCRIPT = ROOT / "scripts/task155_direct_four_mixedlibs/ExportSmallLib155.java"
HISTORICAL_PROJECT = ROOT / "RESEARCH_WORK/TASK_155_R1/libglide-webp.so/ghidra_project"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
TASK = ROOT / "RULES/TASK/TASK_175_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
TASK_SHA = "f30434b75dcdb18e7e45c19ce8b849d8ff580165a87b344b8d6248eb1217af33"
LEASE_ID = "LEASE-CEO-WORKER-TASK_175-R1"
FENCE = 1204
LIBRARIES = {
    "libfantasy.so": ("fefb87a88745a4aa8e8dcc421c7ec46a91a648e7afef86a312d1a3776a8c7724", 197),
    "libglide-webp.so": ("2f7f38acc0d294a3333069aa8a3c07e69d4bc0a64f162215578bd55dbe1a4486", 230),
}
DEADLINE = datetime.fromisoformat("2026-10-13T10:30:02.875962+00:00")


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
        raise RuntimeError("canonical standard or exact TASK_175 task changed")
    flag = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    if flag.is_file() and flag.read_text(encoding="utf-8-sig").strip().upper() == "TRUE":
        raise RuntimeError("END_AGENT_SESSION=TRUE")
    if datetime.now(timezone.utc) >= DEADLINE:
        raise RuntimeError("TASK_175 original deadline reached")
    registry = json.loads((ROOT / ".ai/locks.json").read_text(encoding="utf-8"))
    matches = [item for item in registry["active_locks"] if item.get("lease_id") == LEASE_ID]
    if len(matches) != 1:
        raise RuntimeError("exact TASK_175 lease missing or duplicated")
    lease = matches[0]
    expiry = datetime.fromisoformat(lease["expiry"].replace("Z", "+00:00"))
    if (lease.get("status"), lease.get("agent_id"), lease.get("task_id"),
            lease.get("task_revision"), lease.get("task_sha"), lease.get("fencing_token")) != (
            "ACTIVE", "/root/so45_ai_model_search", "TASK_175", 1, TASK_SHA, FENCE):
        raise RuntimeError("TASK_175 lease identity/fence changed")
    if expiry <= datetime.now(timezone.utc):
        raise RuntimeError("TASK_175 lease expired")
    for allowed in ("RULES/REPORT/TASK_175_REPORT_R1/**",
                    "scripts/task_175_codex_exports/**", "RESEARCH_WORK/TASK_175_R1/**"):
        if allowed not in lease["files_allowed"]:
            raise RuntimeError("TASK_175 lease missing " + allowed)
    return lease


def atomic_bytes(path: Path, content: bytes) -> None:
    check_lease()
    path.parent.mkdir(parents=True, exist_ok=True)
    descriptor, temporary = tempfile.mkstemp(prefix=".task175-", dir=path.parent)
    try:
        with os.fdopen(descriptor, "wb") as stream:
            stream.write(content)
            stream.flush()
            os.fsync(stream.fileno())
        check_lease()
        os.replace(temporary, path)
    finally:
        if os.path.exists(temporary):
            os.unlink(temporary)


def write_json(path: Path, value: object) -> None:
    atomic_bytes(path, (json.dumps(value, ensure_ascii=False, indent=2) + "\n").encode("utf-8"))
