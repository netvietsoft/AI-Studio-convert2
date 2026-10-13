"""TASK_162 identities, atomic writes and exact lease guard."""
from __future__ import annotations

import hashlib
import json
import os
import tempfile
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SCRIPTS = Path(__file__).resolve().parent
REPORT = ROOT / "RULES/REPORT/TASK_162_REPORT_R1"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_162_R1"
SOURCE_DIR = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a")
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
TASK = ROOT / "RULES/TASK/TASK_162_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md"
TASK_SHA = "22e38e8081d202d558704a99fb1d5cc6ea9e30a1a8267f44467ab15320e52942"
LEASE_ID = "LEASE-CEO-WORKER-TASK_162-R1"
AGENT_ID = "/root/so45_dexvmp_correction"
FENCE = 1189
DEADLINE = datetime.fromisoformat("2026-10-13T08:40:36.662647+00:00")
LIBRARIES = {
    "libhiai_ir.so": ("c96af03947bde73255f4b77e3c253ae63130fdfed8b259196d24bbf3ba84a7d1", 1002),
    "libkoom-strip-dump.so": ("db0db1bdef5f51386ea2036682c0129b842aa5e3445a26d60ea6c5d29113faa3", 668),
}

def now() -> str:
    return datetime.now(timezone.utc).isoformat().replace("+00:00", "Z")

def sha256(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(1024 * 1024), b""):
            h.update(chunk)
    return h.hexdigest()

def atomic_bytes(path: Path, payload: bytes) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temp = tempfile.mkstemp(prefix=".task162-", dir=path.parent)
    try:
        with os.fdopen(fd, "wb") as f:
            f.write(payload)
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
        raise RuntimeError("canonical standard or exact task changed")
    flag = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    if flag.is_file() and flag.read_text(encoding="utf-8-sig").strip().upper() == "TRUE":
        raise RuntimeError("END_AGENT_SESSION=TRUE")
    registry = json.loads((ROOT / ".ai/locks.json").read_text(encoding="utf-8"))
    matches = [x for x in registry["active_locks"] if x.get("lease_id") == LEASE_ID]
    if len(matches) != 1:
        raise RuntimeError("exact lease missing or duplicate")
    lease = matches[0]
    expiry = datetime.fromisoformat(lease["expiry"].replace("Z", "+00:00"))
    identity = (lease.get("status"), lease.get("agent_id"), lease.get("fencing_token"), lease.get("task_sha"))
    if identity != ("ACTIVE", AGENT_ID, FENCE, TASK_SHA) or expiry <= datetime.now(timezone.utc):
        raise RuntimeError("lease identity or expiry invalid")
    for scope in ("scripts/task_162_codex_exports/**", "RESEARCH_WORK/TASK_162_R1/**",
                  "RULES/REPORT/TASK_162_REPORT_R1/**"):
        if scope not in lease["files_allowed"]:
            raise RuntimeError("lease scope absent: " + scope)
    return lease
