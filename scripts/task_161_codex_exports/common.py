"""Pinned TASK_161 sources and exact Codex worker lease."""

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
TASK = ROOT / "RULES/TASK/TASK_161_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md"
TASK_SHA = "5c1cae9057b62789528c9bfdd01163d7c2c0c1868f19b21c236834cfcb0a9860"
SOURCE_ROOT = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a")
SOURCES = {
    "libManis.so": ("19daf9b4b1718c843169d68391e99a27d10bd3cece52226c887c3ab9b93dddc2", 266),
    "libmanis_npu_adapter.so": ("99a9a4b161b9797d7cf621e93a51a7df408f80c84e652bbc6724eef7e71ca6f3", 996),
}
LIB_KEY = os.environ.get("TASK161_LIB", "")
if LIB_KEY not in SOURCES:
    raise RuntimeError("set TASK161_LIB to exactly one pinned source name")
SOURCE = SOURCE_ROOT / LIB_KEY
SOURCE_SHA, EXPECTED_VAS = SOURCES[LIB_KEY]
BASE_REPORT = ROOT / "RULES/REPORT/TASK_161_REPORT_R1"
REPORT = BASE_REPORT / SOURCE.stem
BASE_SCRATCH = ROOT / "RESEARCH_WORK/TASK_161_R1"
SCRATCH = BASE_SCRATCH / SOURCE.stem
SCRIPTS = Path(__file__).resolve().parent
LEASE_ID = "LEASE-CEO-WORKER-TASK_161-R1"
AGENT_ID = "/root/so45_ai_model_search"
FENCE = 1190
PROJECT = SCRATCH / "ghidra_project"
PROJECT_NAME = "TASK161_" + SOURCE.stem
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
    fd, temp = tempfile.mkstemp(prefix=".task161-", dir=path.parent)
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
        raise RuntimeError("exact TASK_161 lease missing/duplicated")
    lease = matches[0]
    expiry = datetime.fromisoformat(lease["expiry"].replace("Z", "+00:00"))
    if (lease.get("status"), lease.get("agent_id"), lease.get("fencing_token"), lease.get("task_sha")) != (
        "ACTIVE", AGENT_ID, FENCE, TASK_SHA
    ) or expiry <= datetime.now(timezone.utc):
        raise RuntimeError("TASK_161 lease identity/expiry invalid")
    for scope in ("RULES/REPORT/TASK_161_REPORT_R1/**",
                  "scripts/task_161_codex_exports/**", "RESEARCH_WORK/TASK_161_R1/**"):
        if scope not in lease["files_allowed"]:
            raise RuntimeError("missing exact scope: " + scope)
    return lease


def tree_hashes(path: Path) -> dict[str, str]:
    return {p.relative_to(path).as_posix(): sha256(p)
            for p in sorted(path.rglob("*")) if p.is_file()}
