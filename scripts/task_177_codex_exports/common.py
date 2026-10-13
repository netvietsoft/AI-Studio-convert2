"""TASK_177 exact identities, lease fence and scoped atomic output."""
from __future__ import annotations

import hashlib
import json
import os
import re
import tempfile
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
STANDARD = ROOT / 'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt'
STANDARD_SHA = '10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f'
TASK = ROOT / 'RULES/TASK/TASK_177_SO45_CODEX_GAP_RECOVERY_ACTIVE.md'
TASK_SHA = '3b82aa1a7eda4ba39b047effe1f261bbf6e922901c2042aa2c852b625ab85c61'
SOURCE_DIR = Path('F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a')
REPORT = ROOT / 'RULES/REPORT/TASK_177_REPORT_R1'
SCRATCH = ROOT / 'RESEARCH_WORK/TASK_177_R1'
SCRIPTS = Path(__file__).resolve().parent
AGENT_ID = '/root/so45_pvg_renderer'
LEASE_ID = 'LEASE-CEO-WORKER-TASK_177-R1'
FENCE = 1206
DEADLINE = datetime.fromisoformat('2026-10-13T10:35:57.657908+00:00')
SCOPES = ('RULES/REPORT/TASK_177_REPORT_R1/**',
          'scripts/task_177_codex_exports/**', 'RESEARCH_WORK/TASK_177_R1/**')


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            digest.update(block)
    return digest.hexdigest()


def now() -> str:
    return datetime.now(timezone.utc).isoformat().replace('+00:00', 'Z')


def task_metadata() -> dict:
    raw = TASK.read_text(encoding='utf-8')
    return json.loads(re.search(r'```json\s*(\{.*?\})\s*```', raw, re.S).group(1))


def historical_task(name: str) -> int:
    return 153 if name in {'libMTGif.so', 'libMTLReportTool.so'} else 149


def prior_report(name: str) -> Path:
    return ROOT / f'RULES/REPORT/TASK_{historical_task(name)}_REPORT_R1' / name


def prior_project(name: str) -> Path:
    return ROOT / f'RESEARCH_WORK/TASK_{historical_task(name)}_R1' / name / 'ghidra_project'


def check_lease() -> dict:
    if sha256(STANDARD) != STANDARD_SHA or sha256(TASK) != TASK_SHA:
        raise RuntimeError('canonical Standard or exact task revision changed')
    flag = ROOT / '.ai/ceo/END_AGENT_SESSION.flag'
    if flag.is_file() and flag.read_text(encoding='utf-8-sig').strip().upper() == 'TRUE':
        raise RuntimeError('END_AGENT_SESSION=TRUE')
    if datetime.now(timezone.utc) >= DEADLINE:
        raise RuntimeError('original TASK_177 deadline passed')
    registry = json.loads((ROOT / '.ai/locks.json').read_text(encoding='utf-8'))
    rows = [item for item in registry['active_locks'] if item.get('lease_id') == LEASE_ID]
    if len(rows) != 1:
        raise RuntimeError('TASK_177 exact lease absent/duplicated')
    lease = rows[0]
    identity = (lease.get('status'), lease.get('agent_id'), lease.get('task_id'),
                lease.get('task_revision'), lease.get('task_sha'), lease.get('fencing_token'))
    if identity != ('ACTIVE', AGENT_ID, 'TASK_177', 1, TASK_SHA, FENCE):
        raise RuntimeError('TASK_177 exact lease identity/fence invalid')
    if datetime.fromisoformat(lease['expiry'].replace('Z', '+00:00')) <= datetime.now(timezone.utc):
        raise RuntimeError('TASK_177 lease expired')
    if not set(SCOPES).issubset(lease.get('files_allowed', [])):
        raise RuntimeError('TASK_177 write scopes absent')
    return lease


def atomic_bytes(path: Path, data: bytes) -> None:
    check_lease()
    relative = path.resolve().relative_to(ROOT.resolve()).as_posix()
    if not any(relative.startswith(scope[:-3]) for scope in SCOPES):
        raise RuntimeError(f'outside TASK_177 scope: {relative}')
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temp = tempfile.mkstemp(prefix='.task177-', dir=path.parent)
    try:
        with os.fdopen(fd, 'wb') as stream:
            stream.write(data)
            stream.flush()
            os.fsync(stream.fileno())
        os.replace(temp, path)
    finally:
        if os.path.exists(temp):
            os.unlink(temp)


def write_json(path: Path, data: object) -> None:
    atomic_bytes(path, (json.dumps(data, ensure_ascii=False, indent=2) + '\n').encode('utf-8'))
