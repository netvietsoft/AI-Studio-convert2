"""Pinned identities and fenced writes for TASK_203 R2 semantic correction."""
from __future__ import annotations

import hashlib
import json
import os
import tempfile
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
CODE = Path(__file__).resolve().parent
REPORT = ROOT / "RULES/REPORT/TASK_203_REPORT_R2"
R1_REPORT = ROOT / "RULES/REPORT/TASK_203_REPORT_R1"
R1_PROJECT = ROOT / "RESEARCH_WORK/TASK_203_R1/ghidra_project"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
TASK = ROOT / "RULES/TASK/TASK_203_SO45_CODEX_INTERNAL_ACTIVE.md"
MANIFEST = ROOT / ".ai/ceo/reviews/TASK_203_internal_targets.json"
REVIEW = ROOT / ".ai/ceo/reviews/TASK_203-ca1e3a82782b329dc2bf93a516c0a588714927bf640938c8029dcbfb6622f7cb.md"
REPLAY = ROOT / ".ai/ceo/reviews/TASK_203_CEO_REPLAY/summary.json"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libPVGColorFunctions.so")
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
TASK_SHA = "e4414d22ad527aadc4638a54b3a2f85128d554eeefa7e9b0b62a8479ac0190b4"
MANIFEST_SHA = "96936496c5edc481ace634698375d3ae72977f4916844fa2d581ebe1ac82d522"
SOURCE_SHA = "3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6"
R1_COMPLETE_SHA = "ffbb2a6d39b492aebd72f733235470dc8e4e89ddeb6af64f79d645d04b1d605e"
R1_WINDOW_SHA = "756904e19cebd62782432a9ac380f7df200cebaf9fdf196bc40ca66362df025a"
REVIEW_SHA = "28c2f06a2d61b402c5f2656e653dc17ce47e3382269708b414bd5eee8657c44c"
REPLAY_SHA = "26a3643c38e616b47f461ee6182bf7fe123583d262a93f6df23a7bd202808695"
REVIEW_FINGERPRINT = "ca1e3a82782b329dc2bf93a516c0a588714927bf640938c8029dcbfb6622f7cb"
AGENT_ID = "/root/so45_pvg_followon"
LEASE_ID = "LEASE-CEO-WORKER-TASK_203-R2"
FENCE = 1238
ABSOLUTE_DEADLINE = datetime.fromisoformat("2026-10-13T14:30:13.240060+00:00")


def now() -> str:
    return datetime.now(timezone.utc).isoformat().replace("+00:00", "Z")


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for part in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(part)
    return digest.hexdigest()


def atomic_bytes(path: Path, content: bytes) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temp = tempfile.mkstemp(prefix=".task203r2-", dir=path.parent)
    try:
        with os.fdopen(fd, "wb") as stream:
            stream.write(content)
            stream.flush()
            os.fsync(stream.fileno())
        os.replace(temp, path)
    finally:
        if os.path.exists(temp):
            os.unlink(temp)


def write_json(path: Path, value: object) -> None:
    atomic_bytes(path, (json.dumps(value, ensure_ascii=False, indent=2) + "\n").encode("utf-8"))


def check_lease() -> dict:
    if (sha256(STANDARD), sha256(TASK), sha256(MANIFEST)) != (STANDARD_SHA, TASK_SHA, MANIFEST_SHA):
        raise RuntimeError("pinned canonical/task/manifest hash changed")
    flag = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    if flag.is_file() and flag.read_text(encoding="utf-8-sig").strip().upper() == "TRUE":
        raise RuntimeError("END_AGENT_SESSION=TRUE")
    matches = [x for x in json.loads((ROOT / ".ai/locks.json").read_text(encoding="utf-8"))["active_locks"]
               if x.get("lease_id") == LEASE_ID]
    if len(matches) != 1:
        raise RuntimeError("R2 lease missing or duplicated")
    lease = matches[0]
    if (lease.get("status"), lease.get("agent_id"), lease.get("task_sha"), lease.get("fencing_token")) != (
            "ACTIVE", AGENT_ID, TASK_SHA, FENCE):
        raise RuntimeError("R2 lease identity mismatch")
    expiry = datetime.fromisoformat(lease["expiry"].replace("Z", "+00:00"))
    if datetime.now(timezone.utc) >= min(expiry, ABSOLUTE_DEADLINE):
        raise RuntimeError("R2 lease/deadline expired")
    required = ["RULES/REPORT/TASK_203_REPORT_R2/**", "scripts/task_203_codex_correction_r2/**"]
    if lease["files_allowed"] != required:
        raise RuntimeError("R2 lease scopes differ")
    return lease
