"""Pinned TASK_168 identities, atomic writes and exact fenced lease guard."""
from __future__ import annotations

import hashlib
import json
import os
import tempfile
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SCRIPTS = Path(__file__).resolve().parent
REPORT = ROOT / "RULES/REPORT/TASK_168_REPORT_R1"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_168_R1"
SOURCE_DIR = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a")
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
TASK = ROOT / "RULES/TASK/TASK_168_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md"
TASK_SHA = "a33a9ec2b34bbb57f76c59e2ca7343c025b6e52c9e16170313f94225c934827c"
LEASE_ID = "LEASE-CEO-WORKER-TASK_168-R1"
AGENT_ID = "/root/so45_dexvmp_correction"
FENCE = 1197
DEADLINE = datetime.fromisoformat("2026-10-13T09:40:56.720945+00:00")
NEW_LIBRARIES = {
    "libARKernelInterface.so": ("594c5085475d8bb58baacb20293aec805211aa5ccc53b3542f3149196d354953", 635),
    "libPVGColorFunctions.so": ("3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6", 81),
}
REUSED_LIBRARIES = {
    "libPVGVideoCodec.so": ("336cf1e8cdaaac1ad5bf77b96a03ae9ad90527e583c82aea44b05b25e5da4d26", 160, "TASK_153"),
    "libffmpegfilter.so": ("f22a7ea6da3194d046ecbce5ce3b602bcb56edfd96444a6e29e1a3c3449cf981", 216, "TASK_155"),
}
LIBRARIES = {**NEW_LIBRARIES, **{k: (v[0], v[1]) for k, v in REUSED_LIBRARIES.items()}}

def now() -> str:
    return datetime.now(timezone.utc).isoformat().replace("+00:00", "Z")

def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for part in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(part)
    return digest.hexdigest()

def atomic_bytes(path: Path, payload: bytes) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temp = tempfile.mkstemp(prefix=".task168-", dir=path.parent)
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
        raise RuntimeError("canonical or task identity changed")
    flag = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    if flag.is_file() and flag.read_text(encoding="utf-8-sig").strip().upper() == "TRUE":
        raise RuntimeError("END_AGENT_SESSION=TRUE")
    matches = [x for x in json.loads((ROOT / ".ai/locks.json").read_text(encoding="utf-8"))["active_locks"]
               if x.get("lease_id") == LEASE_ID]
    if len(matches) != 1:
        raise RuntimeError("exact task lease missing or duplicate")
    lease = matches[0]
    identity = (lease.get("status"), lease.get("agent_id"), lease.get("fencing_token"), lease.get("task_sha"))
    if identity != ("ACTIVE", AGENT_ID, FENCE, TASK_SHA):
        raise RuntimeError("exact task lease identity invalid")
    if datetime.fromisoformat(lease["expiry"].replace("Z", "+00:00")) <= datetime.now(timezone.utc):
        raise RuntimeError("exact task lease expired")
    if datetime.now(timezone.utc) >= DEADLINE:
        raise RuntimeError("task deadline exceeded")
    for scope in ("RULES/REPORT/TASK_168_REPORT_R1/**", "scripts/task_168_codex_exports/**",
                  "RESEARCH_WORK/TASK_168_R1/**"):
        if scope not in lease["files_allowed"]:
            raise RuntimeError("lease scope absent: " + scope)
    return lease
