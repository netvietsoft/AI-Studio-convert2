"""Scoped, fenced TASK_204 R1 evidence helpers."""
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
TASK = ROOT / 'RULES/TASK/TASK_204_SO45_CODEX_INTERNAL_ACTIVE.md'
TASK_SHA = 'a175e7b87e7e257d6623d4f650201ba091868794d54cd2d77ca7a3ebaf9d43ee'
TARGETS = ROOT / '.ai/ceo/reviews/TASK_204_internal_targets.json'
TARGETS_SHA = '548a3f83bf498b047d34dd77e707c00d3644d1c8780eef4e71d8e43802874793'
SOURCE = Path('F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libMTFilterKernel.so')
SOURCE_SHA = 'f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4'
PROJECT = ROOT / 'RESEARCH_WORK/TASK_201_R1/ghidra_project'
REPORT = ROOT / 'RULES/REPORT/TASK_204_REPORT_R1'
SCRATCH = ROOT / 'RESEARCH_WORK/TASK_204_R1'
SCRIPTS = Path(__file__).resolve().parent
AGENT = '/root/so45_mtfilter_next'
LEASE_ID = 'LEASE-CEO-WORKER-TASK_204-R1'
FENCE = 1241
DEADLINE = datetime.fromisoformat('2026-10-13T15:09:28.505005+00:00')
SCOPES = ('RULES/REPORT/TASK_204_REPORT_R1/',
          'scripts/task_204_codex_internal/', 'RESEARCH_WORK/TASK_204_R1/')


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            digest.update(block)
    return digest.hexdigest()


def now() -> str:
    return datetime.now(timezone.utc).isoformat().replace('+00:00', 'Z')


def task_meta() -> dict:
    match = re.search(r'```json\s*(\{.*?\})\s*```', TASK.read_text(encoding='utf-8'), re.S)
    if not match:
        raise RuntimeError('task metadata missing')
    return json.loads(match.group(1))


def check_lease() -> dict:
    for path, expected in ((STANDARD, STANDARD_SHA), (TASK, TASK_SHA),
                           (TARGETS, TARGETS_SHA), (SOURCE, SOURCE_SHA)):
        if sha256(path) != expected:
            raise RuntimeError(f'pinned input changed: {path}')
    flag = ROOT / '.ai/ceo/END_AGENT_SESSION.flag'
    if flag.is_file() and flag.read_text(encoding='utf-8-sig').strip().upper() == 'TRUE':
        raise RuntimeError('END_AGENT_SESSION=TRUE')
    if datetime.now(timezone.utc) >= DEADLINE:
        raise RuntimeError('TASK_204 deadline passed')
    locks = json.loads((ROOT / '.ai/locks.json').read_text(encoding='utf-8'))['active_locks']
    rows = [x for x in locks if x.get('lease_id') == LEASE_ID]
    if len(rows) != 1:
        raise RuntimeError('exact lease missing/duplicated')
    lease = rows[0]
    identity = (lease.get('status'), lease.get('agent_id'), lease.get('task_id'),
                lease.get('task_revision'), lease.get('task_sha'), lease.get('fencing_token'))
    if identity != ('ACTIVE', AGENT, 'TASK_204', 1, TASK_SHA, FENCE):
        raise RuntimeError(f'lease identity/fence differs: {identity}')
    if datetime.fromisoformat(lease['expiry'].replace('Z', '+00:00')) <= datetime.now(timezone.utc):
        raise RuntimeError('lease expired')
    if not all(s + '**' in lease.get('files_allowed', []) for s in SCOPES):
        raise RuntimeError('lease scopes differ')
    return lease


def atomic_bytes(path: Path, data: bytes) -> None:
    check_lease()
    relative = path.resolve().relative_to(ROOT.resolve()).as_posix()
    if not any(relative.startswith(scope) for scope in SCOPES):
        raise RuntimeError(f'outside TASK_204 scope: {relative}')
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temp = tempfile.mkstemp(prefix='.task204-', dir=path.parent)
    try:
        with os.fdopen(fd, 'wb') as stream:
            stream.write(data)
            stream.flush()
            os.fsync(stream.fileno())
        os.replace(temp, path)
    finally:
        if os.path.exists(temp):
            os.unlink(temp)


def write_json(path: Path, value: object) -> None:
    atomic_bytes(path, (json.dumps(value, ensure_ascii=False, indent=2) + '\n').encode('utf-8'))
