"""Bounded transient FDE-gap probe plus two fresh-session rollback checks."""
from __future__ import annotations

import json
import os
import subprocess
import time
from datetime import datetime, timezone
from pathlib import Path

from common import (DEADLINE, FENCE, LEASE_ID, REPORT, SCRATCH, SCRIPTS,
                    SOURCE_SHA, TARGETS, check_lease, now, sha256,
                    atomic_bytes, write_json)

GHIDRA = Path('F:/TOOLS/ghidra_12.1.4_PUBLIC/support/analyzeHeadless.bat')
JAVA_HOME = Path('F:/TOOLS/jdk-21.0.12.1+1')


def target_list() -> Path:
    check_lease()
    manifest = json.loads(TARGETS.read_text(encoding='utf8'))
    target_by_index = {x['global_index']: x for x in manifest['targets']}
    raw_by_index = {}
    for folder in REPORT.glob('ghidra_raw_batch*'):
        if folder.is_dir():
            for file in folder.glob('*.json'):
                row = json.loads(file.read_text(encoding='utf8'))
                idx = row['index'] - 1
                if idx in raw_by_index:
                    raise RuntimeError('duplicate raw candidate')
                raw_by_index[idx] = row
    if len(raw_by_index) != 505:
        raise RuntimeError('raw 505 not ready')
    partial = []
    for idx in sorted(raw_by_index):
        row = raw_by_index[idx]
        target = target_by_index[idx]
        if row['fde_byte_membership_count'] < row['size_bytes']:
            if (row['extra_body_address_count'] != 0 or
                row['ghidra_memory_sha256'] != target['body_sha256'] or
                row['elf_va'] != target['elf_va'] or
                row['size_bytes'] != target['size_bytes']):
                raise RuntimeError(f'raw candidate differs {idx}')
            if row['other_function_byte_count'] != 0:
                raise RuntimeError(f'other function overlap {idx}')
            partial.append(target)
    if len(partial) != 144:
        raise RuntimeError(f'expected 144 safe measured gaps; found {len(partial)}')
    path = SCRATCH / 'correction_targets.tsv'
    if path.exists():
        raise RuntimeError('correction targets already exist')
    atomic_bytes(path, ''.join(f"{x['global_index']+1}\t{x['elf_va']}\t{x['size_bytes']}\t{x['body_sha256']}\n"
                               for x in partial).encode('ascii'))
    write_json(REPORT / 'gap_candidates.json', {
        'task_id': 'TASK_231', 'revision': 1,
        'global_zero_based_indices': [x['global_index'] for x in partial],
        'unsafe_overlap_global_indices': [],
        'all_partial_count': 144,
        'one_based_raw_rows': [x['global_index']+1 for x in partial],
        'target_tsv_sha256': sha256(path),
        'measured_missing_body_bytes': sum(raw_by_index[x['global_index']]['size_bytes'] -
                                          raw_by_index[x['global_index']]['fde_byte_membership_count']
                                          for x in partial),
        'measured_missing_listing_slots': sum(raw_by_index[x['global_index']]['missing_analyzed_instruction_count']
                                              for x in partial),
        'other_function_overlap_bytes': 0,
    })
    return path


def run_one(name: str, script: str, tsv: Path, count: int) -> dict:
    check_lease()
    index_path = REPORT / 'source_project_index.json'
    index = json.loads(index_path.read_text(encoding='utf8'))
    project = Path(index['project_copy'])
    before = {x['relative_path']: sha256(project / x['relative_path'])
              for x in index['project_files']}
    if before != {x['relative_path']: x['sha256'] for x in index['project_files']}:
        raise RuntimeError('private project differs before headless job')
    outdir = REPORT / name
    stdout = REPORT / f'{name}_stdout.log'
    stderr = REPORT / f'{name}_stderr.log'
    receipt = REPORT / f'{name}_command.json'
    if any(x.exists() for x in (outdir, stdout, stderr, receipt)):
        raise RuntimeError(name + ' already started')
    timeout = min(1200, (DEADLINE - datetime.now(timezone.utc)).total_seconds())
    if timeout <= 0:
        raise RuntimeError('deadline exceeded')
    command = [str(GHIDRA), str(project), index['project_name'],
               '-process', 'libPVGImageCodec.so', '-noanalysis', '-readOnly',
               '-max-cpu', '1', '-scriptPath', str(SCRIPTS),
               '-postScript', script, str(tsv), str(outdir)]
    env = os.environ.copy()
    env['JAVA_HOME'] = str(JAVA_HOME)
    env['PATH'] = str(JAVA_HOME / 'bin') + os.pathsep + env.get('PATH', '')
    env['GHIDRA_HEADLESS_MAXMEM'] = '1G'
    env['DOUBLE_CLICKED'] = 'n'
    outdir.mkdir()
    base = {
        'task_id': 'TASK_231', 'revision': 1, 'step': name,
        'lease_id': LEASE_ID, 'fencing_token': FENCE,
        'source_sha256': SOURCE_SHA, 'command': command,
        'script_sha256': sha256(SCRIPTS / script), 'target_tsv_sha256': sha256(tsv),
        'project_index_sha256': sha256(index_path), 'project_files_before': before,
        'max_cpu': 1, 'max_heap': '1G', 'max_per_decompile_seconds': 15,
        'max_process_seconds': timeout, 'started_at': now(),
    }
    write_json(receipt, {**base, 'status': 'STARTING'})
    began = time.monotonic()
    status = 'PROCESS_FAILED'
    with stdout.open('wb') as out, stderr.open('wb') as err:
        proc = subprocess.Popen(command, env=env, stdin=subprocess.DEVNULL,
                                stdout=out, stderr=err,
                                creationflags=getattr(subprocess, 'CREATE_NO_WINDOW', 0))
        try:
            code = proc.wait(timeout=timeout)
        except subprocess.TimeoutExpired:
            proc.kill()
            code = proc.wait(timeout=15)
            status = 'PROCESS_TIMEOUT'
    files = sorted(outdir.glob('*.json'))
    if status != 'PROCESS_TIMEOUT':
        status = 'OUTPUT_READY' if code == 0 and len(files) == count else 'PARTIAL_OUTPUT'
    after = {x['relative_path']: sha256(project / x['relative_path'])
             for x in index['project_files']}
    result = {
        **base, 'status': status, 'ended_at': now(),
        'elapsed_seconds': round(time.monotonic() - began, 3),
        'exit_code': code, 'output_files': len(files),
        'output_hashes': {x.name: sha256(x) for x in files},
        'stdout_sha256': sha256(stdout), 'stderr_sha256': sha256(stderr),
        'project_files_after': after, 'project_metadata_unchanged': before == after,
    }
    write_json(receipt, result)
    print(json.dumps({'step': name, 'status': status, 'exit_code': code,
                      'output_files': len(files), 'elapsed_seconds': result['elapsed_seconds'],
                      'project_metadata_unchanged': before == after}), flush=True)
    return result


def main() -> None:
    target = target_list()
    corrected = run_one('ghidra_correction', 'RepairMembership231.java', target, 144)
    if corrected['status'] != 'OUTPUT_READY':
        return
    for batch in range(1, 17):
        fresh = run_one(f'ghidra_fresh_batch{batch}', 'ExtractInternal231.java',
                        SCRATCH / f'target_batch_{batch}.tsv', (25 if batch == 16 else 32))
        if fresh['status'] != 'OUTPUT_READY':
            return


if __name__ == '__main__':
    main()
