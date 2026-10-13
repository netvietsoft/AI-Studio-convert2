"""Pinned AIModelSearchKit source, canonical rule and exact Codex lane lease."""

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
TASK = ROOT / "RULES/TASK/TASK_157_SO45_CODEX_AIMODELSEARCH_ACTIVE.md"
TASK_SHA = "4ebb0377a70634ca1d92a1f46aa2ded23c405af7fa629a48d431eb49c646a34d"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libAIModelSearchKit.so")
SOURCE_SHA = "20233f05b4b010280d16e728103a0995ca2580697b5f9c708fa333e9ff8d1899"
REPORT = ROOT / "RULES/REPORT/TASK_157_REPORT_R1"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_157_R1"
SCRIPTS = Path(__file__).resolve().parent
LEASE_ID = "LEASE-CEO-WORKER-TASK_157-R1"
AGENT_ID = "/root/so45_ai_model_search"
FENCE = 1185
PROJECT = SCRATCH / "ghidra_project"
PROJECT_NAME = "AIModelSearch157"
CHUNK_SIZE = 256
MAX_REPORT_BYTES = 67_108_864


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
    fd, temp = tempfile.mkstemp(prefix=".task157-", dir=path.parent)
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
        raise RuntimeError("exact TASK_157 lease missing/duplicated")
    lease = matches[0]
    expiry = datetime.fromisoformat(lease["expiry"].replace("Z", "+00:00"))
    if (lease.get("status"), lease.get("agent_id"), lease.get("fencing_token"), lease.get("task_sha")) != (
        "ACTIVE", AGENT_ID, FENCE, TASK_SHA
    ) or expiry <= datetime.now(timezone.utc):
        raise RuntimeError("TASK_157 lease identity/expiry invalid")
    for scope in ("RULES/REPORT/TASK_157_REPORT_R1/**",
                  "scripts/task157_codex_aimodelsearch/**", "RESEARCH_WORK/TASK_157_R1/**"):
        if scope not in lease["files_allowed"]:
            raise RuntimeError("missing exact scope: " + scope)
    return lease


def tree_hashes(path: Path) -> dict[str, str]:
    return {p.relative_to(path).as_posix(): sha256(p)
            for p in sorted(path.rglob("*")) if p.is_file()}
