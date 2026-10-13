"""Pinned TASK_171 identities, atomic writes and exact fenced lease guard."""
from __future__ import annotations

import hashlib
import json
import os
import tempfile
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SCRIPTS = Path(__file__).resolve().parent
REPORT = ROOT / "RULES/REPORT/TASK_171_REPORT_R1"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_171_R1"
SOURCE_DIR = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a")
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
TASK = ROOT / "RULES/TASK/TASK_171_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md"
TASK_SHA = "e85eb5e0d2c82135f8af7e2c500e365a346630c9aa4c7bddcdd2fed5413cc6f5"
LEASE_ID = "LEASE-CEO-WORKER-TASK_171-R1"
AGENT_ID = "/root/so45_dexvmp_correction"
FENCE = 1200
DEADLINE = datetime.fromisoformat("2026-10-13T10:07:29.141259+00:00")
NEW_LIBRARIES = {}
REUSED_LIBRARIES = {
    "libARSPM.so": ("ec420f2eec97cf2debbf4778045cfd0ac08b78eae656a4f90e282d49b3ef0114", 56, "TASK_155"),
    "libPVGLive.so": ("e443f6a16cb8137d74a1583529666eb02bf4859b372175e2b4c226f6e188484c", 20, "TASK_149"),
    "libCtaApiLib.so": ("4a91ccac45408daa30e8dd60f7c6eee68aeffbdd66e1e9b6e435b1aa3377fcd5", 146, "TASK_153"),
    "libKKMusicFX.so": ("cd876a2e49a129b1bcefdc4aca42047faa4aaf954c6c1286edb80209ac38031d", 57, "TASK_153"),
    "libffavc.so": ("1e214164a6c153f74f25018c1625f3e71d1d5ba601f6592c4dd89385dcc4b0bc", 2, "TASK_149"),
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
    fd, temp = tempfile.mkstemp(prefix=".task171-", dir=path.parent)
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
    for scope in ("RULES/REPORT/TASK_171_REPORT_R1/**", "scripts/task_171_codex_exports/**",
                  "RESEARCH_WORK/TASK_171_R1/**"):
        if scope not in lease["files_allowed"]:
            raise RuntimeError("lease scope absent: " + scope)
    return lease
