"""TASK_184 exact lease, source identity, and scoped atomic output."""

from __future__ import annotations

import hashlib
import json
import os
import tempfile
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SCRIPTS = Path(__file__).resolve().parent
REPORT = ROOT / "RULES/REPORT/TASK_184_REPORT_R1"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_184_R1"
SOURCE = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libVERenderer.so")
ORIGINAL_PROJECT = ROOT / "RESEARCH_WORK/TASK_158_R1/libVERenderer.so/ghidra_project"
OWN_PROJECT = SCRATCH / "ghidra_project"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
TASK = ROOT / "RULES/TASK/TASK_184_SO45_CODEX_INTERNAL_ACTIVE.md"
TARGETS = ROOT / ".ai/ceo/reviews/TASK_184_internal_targets.json"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
TASK_SHA = "1fbab2b3072b94c02d7684246d5c5280ab6fbc560b4a5c8cf98d062a2e808042"
TARGETS_SHA = "0b11084f86a80398343bd576843dfdabf7f697b7d8a31aa652ad452c6d071a0b"
SOURCE_SHA = "2da896556822804506871c47fadda3fadf8537952e38642e6c496ccbbab8ca46"
LEASE = "LEASE-CEO-WORKER-TASK_184-R1"
AGENT = "/root/so45_dexvmp_correction"
FENCE = 1214
DEADLINE = datetime.fromisoformat("2026-10-13T11:12:37.448604+00:00")
SCOPES = (
    ROOT / "RULES/REPORT/TASK_184_REPORT_R1",
    ROOT / "scripts/task_184_codex_internal",
    ROOT / "RESEARCH_WORK/TASK_184_R1",
)


def sha(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for part in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(part)
    return digest.hexdigest()


def now() -> str:
    return datetime.now(timezone.utc).isoformat().replace("+00:00", "Z")


def guard() -> None:
    if datetime.now(timezone.utc) >= DEADLINE:
        raise RuntimeError("TASK_184 absolute deadline reached")
    if (sha(STANDARD), sha(TASK), sha(TARGETS), sha(SOURCE)) != (
        STANDARD_SHA, TASK_SHA, TARGETS_SHA, SOURCE_SHA
    ):
        raise RuntimeError("TASK_184 canonical/task/targets/original source identity changed")
    end = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    if end.is_file() and end.read_text(encoding="utf-8-sig").strip().upper() == "TRUE":
        raise RuntimeError("END_AGENT_SESSION TRUE")
    locks = json.loads((ROOT / ".ai/locks.json").read_text(encoding="utf-8"))
    matches = [entry for entry in locks["active_locks"] if entry.get("lease_id") == LEASE]
    if len(matches) != 1:
        raise RuntimeError("TASK_184 exact lease missing or duplicated")
    entry = matches[0]
    if (entry.get("status"), entry.get("task_id"), entry.get("task_revision"),
        entry.get("agent_id"), entry.get("task_sha"), entry.get("fencing_token")) != (
        "ACTIVE", "TASK_184", 1, AGENT, TASK_SHA, FENCE
    ):
        raise RuntimeError("TASK_184 lease identity/fence invalid")
    expiry = datetime.fromisoformat(entry["expiry"].replace("Z", "+00:00"))
    if expiry <= datetime.now(timezone.utc):
        raise RuntimeError("TASK_184 lease expired")
    expected = {"RULES/REPORT/TASK_184_REPORT_R1/**", "scripts/task_184_codex_internal/**",
                "RESEARCH_WORK/TASK_184_R1/**"}
    if not expected.issubset(set(entry.get("files_allowed", []))):
        raise RuntimeError("TASK_184 lease scope mismatch")


def atomic_bytes(path: Path, content: bytes) -> None:
    guard()
    resolved = path.resolve()
    if not any(resolved.is_relative_to(scope.resolve()) for scope in SCOPES):
        raise RuntimeError("TASK_184 out-of-scope write: " + str(path))
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temporary = tempfile.mkstemp(prefix=".task184-", dir=path.parent)
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
