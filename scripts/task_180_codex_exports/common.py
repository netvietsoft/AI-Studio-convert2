"""TASK_180 pinned identities, valid lease and atomic scoped writes."""
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
TASK = ROOT / 'RULES/TASK/TASK_180_SO45_CODEX_CORRECTION_ACTIVE.md'
TASK_SHA = 'b7c15fcb495043e7d38b6b56183c0e30fc9256fd300c59859c8799ebfe6ab3b0'
SOURCE = Path('F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libMTGif.so')
SOURCE_SHA = 'a896d526a7ee74611ffd9a611b797c65505e60b4c60ff27fab75ecabbe69a134'
REPORT = ROOT / 'RULES/REPORT/TASK_180_REPORT_R1'
SCRATCH = ROOT / 'RESEARCH_WORK/TASK_180_R1'
SCRIPTS = Path(__file__).resolve().parent
PRIOR153 = ROOT / 'RULES/REPORT/TASK_153_REPORT_R1/libMTGif.so'
PRIOR154 = ROOT / 'RULES/REPORT/TASK_154_REPORT_R1'
PRIOR177 = ROOT / 'RULES/REPORT/TASK_177_REPORT_R1/libMTGif.so'
PRIOR_PROJECT = ROOT / 'RESEARCH_WORK/TASK_153_R1/libMTGif.so/ghidra_project'
AGENT_ID = '/root/so45_pvg_renderer'
LEASE_ID = 'LEASE-CEO-WORKER-TASK_180-R1'
FENCE = 1209
DEADLINE = datetime.fromisoformat('2026-10-13T10:27:48.417200+00:00')
SCOPES = ('RULES/REPORT/TASK_180_REPORT_R1/**',
          'scripts/task_180_codex_exports/**', 'RESEARCH_WORK/TASK_180_R1/**')


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            digest.update(block)
    return digest.hexdigest()


def now() -> str:
    return datetime.now(timezone.utc).isoformat().replace('+00:00', 'Z')


def metadata() -> dict:
    return json.loads(re.search(r'```json\s*(\{.*?\})\s*```', TASK.read_text(encoding='utf-8'), re.S).group(1))


def check_lease() -> dict:
    if sha256(STANDARD) != STANDARD_SHA or sha256(TASK) != TASK_SHA or sha256(SOURCE) != SOURCE_SHA:
        raise RuntimeError('canonical Standard/task/original SO changed')
    flag = ROOT / '.ai/ceo/END_AGENT_SESSION.flag'
    if flag.is_file() and flag.read_text(encoding='utf-8-sig').strip().upper() == 'TRUE':
        raise RuntimeError('END_AGENT_SESSION=TRUE')
    if datetime.now(timezone.utc) >= DEADLINE:
        raise RuntimeError('original TASK_180 deadline passed')
    rows = [row for row in json.loads((ROOT / '.ai/locks.json').read_text(encoding='utf-8'))['active_locks']
            if row.get('lease_id') == LEASE_ID]
    if len(rows) != 1:
        raise RuntimeError('TASK_180 exact lease absent/duplicated')
    lease = rows[0]
    identity = (lease.get('status'), lease.get('agent_id'), lease.get('task_id'),
                lease.get('task_revision'), lease.get('task_sha'), lease.get('fencing_token'))
    if identity != ('ACTIVE', AGENT_ID, 'TASK_180', 1, TASK_SHA, FENCE):
        raise RuntimeError('TASK_180 lease identity/fence invalid')
    if datetime.fromisoformat(lease['expiry'].replace('Z', '+00:00')) <= datetime.now(timezone.utc):
        raise RuntimeError('TASK_180 lease expired')
    if not set(SCOPES).issubset(lease.get('files_allowed', [])):
        raise RuntimeError('TASK_180 write scopes absent')
    return lease


def atomic_bytes(path: Path, data: bytes) -> None:
    check_lease()
    relative = path.resolve().relative_to(ROOT.resolve()).as_posix()
    if not any(relative.startswith(scope[:-3]) for scope in SCOPES):
        raise RuntimeError(f'outside TASK_180 scope: {relative}')
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, tmp = tempfile.mkstemp(prefix='.task180-', dir=path.parent)
    try:
        with os.fdopen(fd, 'wb') as out:
            out.write(data)
            out.flush()
            os.fsync(out.fileno())
        os.replace(tmp, path)
    finally:
        if os.path.exists(tmp):
            os.unlink(tmp)


def write_json(path: Path, obj: object) -> None:
    atomic_bytes(path, (json.dumps(obj, ensure_ascii=False, indent=2) + '\n').encode())
