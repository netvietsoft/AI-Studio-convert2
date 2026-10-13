"""Pinned TASK_183 identities and guarded writes; no original source mutation."""
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
TASK = ROOT / 'RULES/TASK/TASK_183_SO45_CODEX_INTERNAL_ACTIVE.md'
TASK_SHA = '081a4a0fd10a3977c18ffbea95f055974bfff8957e377b29557093619afebedd'
TARGETS = ROOT / '.ai/ceo/reviews/TASK_183_internal_targets.json'
TARGETS_SHA = '45c16c21e4393ae9a2a8c297896d8c3e4d5c00c753f924a309a52a8a02a05150'
SOURCE = Path('F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libMTGif.so')
SOURCE_SHA = 'a896d526a7ee74611ffd9a611b797c65505e60b4c60ff27fab75ecabbe69a134'
PROJECT = ROOT / 'RESEARCH_WORK/TASK_153_R1/libMTGif.so/ghidra_project'
REPORT = ROOT / 'RULES/REPORT/TASK_183_REPORT_R1'
SCRATCH = ROOT / 'RESEARCH_WORK/TASK_183_R1'
SCRIPTS = Path(__file__).resolve().parent
AGENT_ID = '/root/so45_pvg_renderer'
LEASE_ID = 'LEASE-CEO-WORKER-TASK_183-R1'
FENCE = 1212
DEADLINE = datetime.fromisoformat('2026-10-13T11:12:37.448604+00:00')
SCOPES = ('RULES/REPORT/TASK_183_REPORT_R1/',
          'scripts/task_183_codex_internal/', 'RESEARCH_WORK/TASK_183_R1/')


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            digest.update(block)
    return digest.hexdigest()


def now() -> str:
    return datetime.now(timezone.utc).isoformat().replace('+00:00', 'Z')


def task_metadata() -> dict:
    return json.loads(re.search(r'```json\s*(\{.*?\})\s*```', TASK.read_text(encoding='utf-8'), re.S).group(1))


def check_lease() -> dict:
    for path, expected in ((STANDARD, STANDARD_SHA), (TASK, TASK_SHA),
                           (TARGETS, TARGETS_SHA), (SOURCE, SOURCE_SHA)):
        if sha256(path) != expected:
            raise RuntimeError(f'pinned input changed: {path}')
    flag = ROOT / '.ai/ceo/END_AGENT_SESSION.flag'
    if flag.is_file() and flag.read_text(encoding='utf-8-sig').strip().upper() == 'TRUE':
        raise RuntimeError('END_AGENT_SESSION=TRUE')
    if datetime.now(timezone.utc) >= DEADLINE:
        raise RuntimeError('TASK_183 original deadline passed')
    rows = [x for x in json.loads((ROOT / '.ai/locks.json').read_text(encoding='utf-8'))['active_locks']
            if x.get('lease_id') == LEASE_ID]
    if len(rows) != 1:
        raise RuntimeError('exact lease missing/duplicated')
    lease = rows[0]
    identity = (lease.get('status'), lease.get('agent_id'), lease.get('task_id'),
                lease.get('task_revision'), lease.get('task_sha'), lease.get('fencing_token'))
    if identity != ('ACTIVE', AGENT_ID, 'TASK_183', 1, TASK_SHA, FENCE):
        raise RuntimeError(f'lease identity/fence differs: {identity}')
    if datetime.fromisoformat(lease['expiry'].replace('Z', '+00:00')) <= datetime.now(timezone.utc):
        raise RuntimeError('lease expired')
    if not all(s + '**' in lease.get('files_allowed', []) for s in SCOPES):
        raise RuntimeError('lease write scopes differ')
    return lease


def atomic_bytes(path: Path, data: bytes) -> None:
    check_lease()
    relative = path.resolve().relative_to(ROOT.resolve()).as_posix()
    if not any(relative.startswith(scope) for scope in SCOPES):
        raise RuntimeError(f'outside TASK_183 scope: {relative}')
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temp = tempfile.mkstemp(prefix='.task183-', dir=path.parent)
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
