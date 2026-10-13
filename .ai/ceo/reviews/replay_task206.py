"""Fresh bounded CEO replay of TASK_206 critical and spread Ghidra rows.

The technical cache is copied into a unique CEO review directory because
Ghidra's -readOnly flag can still alter backup metadata in its project copy.
"""

from __future__ import annotations

import datetime as dt
import hashlib
import json
import os
import shutil
import subprocess
import time
from pathlib import Path

from prepare_publish_tasks189_190 import ROOT, STANDARD_SHA, atomic_file
from controller import Controller, file_sha


REPORT = ROOT / 'RULES/REPORT/TASK_206_REPORT_R1'
REPLAY = Path('F:/CONVERT_WORKTREES/ceo-so45-20261008/TASK_206_CEO_REPLAY')
CACHE = ROOT / 'RESEARCH_WORK/TASK_146_R1/ghidra_project'
SCRIPT_DIR = ROOT / 'scripts/task_206_codex_internal'
SCRIPT = SCRIPT_DIR / 'ExportInternal206.java'
GHIDRA = Path('F:/TOOLS/ghidra_12.1.4_PUBLIC')
JDK = Path('F:/TOOLS/jdk-21.0.12.1+1')
CRITICAL = {13, 36, 72, 109}
ORDINARY = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120}
R1_SEAL = 'b6a6cc58b41b7a08126ad0e7f8e1d9a4521b0b0bc941e9fdd518ee3ea2c5c5c1'
SOURCE = Path('F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libLayerFlow.so')
SOURCE_SHA = 'ef8d1581038778b72abca3ca8fd5046e49fd44e0465871b023647fe42a582262'


def utc() -> str:
    return dt.datetime.now(dt.timezone.utc).isoformat(timespec='microseconds')


def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def tree_hashes(folder: Path) -> dict[str, str]:
    return {p.relative_to(folder).as_posix(): file_sha(p)
            for p in sorted(folder.rglob('*')) if p.is_file()}


def write(name: str, value: object) -> None:
    atomic_file(REPLAY / name, (json.dumps(value, indent=2, ensure_ascii=False) + '\n').encode('utf8'))


def main() -> None:
    ctl = Controller(ROOT)
    with ctl.transaction() as (registry, _state):
        lease = ctl.ceo_lease(registry)
        ctl.authorized(lease, REPLAY / 'summary.json')
        if ctl.end_requested() or file_sha(ROOT / 'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt') != STANDARD_SHA:
            raise RuntimeError('END requested or canonical changed')
        if file_sha(REPORT / 'COMPLETE.json') != R1_SEAL or file_sha(SOURCE) != SOURCE_SHA:
            raise RuntimeError('sealed report or source changed')
        if REPLAY.exists():
            raise RuntimeError('CEO replay already exists; no rerun/overwrite')
    if not (GHIDRA / 'support/analyzeHeadless.bat').is_file() or not (JDK / 'bin/java.exe').is_file():
        raise RuntimeError('Ghidra/JDK missing')
    original_hashes = tree_hashes(CACHE)
    if len(original_hashes) != 10:
        raise RuntimeError('unexpected technical-cache file inventory')
    REPLAY.mkdir(parents=True)
    project = REPLAY / 'project'
    shutil.copytree(CACHE, project)
    copied_hashes = tree_hashes(project)
    if copied_hashes != original_hashes:
        raise RuntimeError('private copy differs from technical cache')

    targets: dict[int, str] = {}
    raw: dict[int, dict] = {}
    for chunk in range(8):
        folder = REPORT / f'chunk_{chunk:02d}'
        for line in (folder / 'targets.tsv').read_text(encoding='utf8').splitlines():
            fields = line.split('\t')
            index = int(fields[0]) - 1
            targets[index] = line
        for line in (folder / 'ghidra_raw.ndjson').read_text(encoding='utf8').splitlines():
            row = json.loads(line)
            raw[int(row['index']) - 1] = row
    selected = sorted(CRITICAL | ORDINARY)
    if len(targets) != 128 or len(raw) != 128 or len(selected) != 17:
        raise RuntimeError('incomplete sealed target/raw census')
    tsv = REPLAY / 'targets.tsv'
    atomic_file(tsv, ('\n'.join(targets[i] for i in selected) + '\n').encode('utf8'))
    out = REPLAY / 'ghidra_raw.ndjson'
    command = [str(GHIDRA / 'support/analyzeHeadless.bat'), str(project), 'LayerFlowHair146',
               '-process', 'libLayerFlow.so', '-noanalysis', '-readOnly', '-max-cpu', '1',
               '-scriptPath', str(SCRIPT_DIR), '-postScript', SCRIPT.name, str(tsv), str(out)]
    env = os.environ.copy()
    env['JAVA_HOME'] = str(JDK)
    env['PATH'] = str(JDK / 'bin') + os.pathsep + env.get('PATH', '')
    env['GHIDRA_HEADLESS_MAXMEM'] = '1G'
    env['DOUBLE_CLICKED'] = 'n'
    started_at = utc()
    start = time.monotonic()
    proc = subprocess.run(command, cwd=ROOT, env=env, stdin=subprocess.DEVNULL,
                          capture_output=True, timeout=1200,
                          creationflags=getattr(subprocess, 'CREATE_NO_WINDOW', 0))
    elapsed = round(time.monotonic() - start, 3)
    atomic_file(REPLAY / 'stdout.log', proc.stdout)
    atomic_file(REPLAY / 'stderr.log', proc.stderr)
    rows = [json.loads(line) for line in out.read_text(encoding='utf8').splitlines()] if out.is_file() else []
    mismatches = []
    for position, item in enumerate(rows):
        index = selected[position] if position < len(selected) else -1
        expected = raw.get(index)
        replayed = {k: v for k, v in item.items() if k != 'elapsed_ms'}
        sealed = {k: v for k, v in expected.items() if k != 'elapsed_ms'} if expected else None
        if replayed != sealed:
            mismatches.append({'expected_zero_based_index': index, 'actual_one_based_index': item.get('index'),
                               'different_keys': sorted(k for k in set(replayed) | set(sealed or {})
                                                        if replayed.get(k) != (sealed or {}).get(k))})
    post_hashes = tree_hashes(project)
    summary = {
        'task_id': 'TASK_206', 'revision': 1, 'started_at': started_at, 'ended_at': utc(),
        'elapsed_seconds': elapsed, 'source_sha256': SOURCE_SHA,
        'standard_sha256': STANDARD_SHA, 'sealed_complete_sha256': R1_SEAL,
        'selected_zero_based_indices': selected, 'critical_zero_based_indices': sorted(CRITICAL),
        'ordinary_zero_based_indices': sorted(ORDINARY),
        'project_source_file_hashes': original_hashes,
        'project_private_pre_hashes': copied_hashes, 'project_private_post_hashes': post_hashes,
        'project_source_post_hashes': tree_hashes(CACHE),
        'command': command, 'script_sha256': file_sha(SCRIPT), 'targets_sha256': file_sha(tsv),
        'stdout_sha256': file_sha(REPLAY / 'stdout.log'),
        'stderr_sha256': file_sha(REPLAY / 'stderr.log'),
        'raw_sha256': file_sha(out) if out.is_file() else None,
        'exit_code': proc.returncode, 'rows': len(rows), 'expected_rows': len(selected),
        'mismatches_excluding_elapsed_ms': mismatches,
        'original_cache_unchanged': tree_hashes(CACHE) == original_hashes,
    }
    write('summary.json', summary)
    print(json.dumps({'exit_code': proc.returncode, 'rows': len(rows), 'mismatches': mismatches,
                      'elapsed_seconds': elapsed, 'summary_sha256': file_sha(REPLAY / 'summary.json')}))
    if proc.returncode != 0 or len(rows) != len(selected) or mismatches:
        raise RuntimeError('independent Ghidra replay mismatch')


if __name__ == '__main__':
    main()
