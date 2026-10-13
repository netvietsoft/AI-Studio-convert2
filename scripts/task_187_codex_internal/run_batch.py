"""Run exactly one of two sequential 64-candidate headless batches, no new import."""
from __future__ import annotations

import json
import os
import subprocess
import sys
import time
from datetime import datetime, timezone
from pathlib import Path

from common import (DEADLINE, FENCE, LEASE_ID, REPORT, SCRATCH, SCRIPTS,
                    SOURCE, SOURCE_SHA, check_lease, now, sha256, write_json)

GHIDRA = Path('F:/TOOLS/ghidra_12.1.4_PUBLIC')
JAVA_HOME = Path('F:/TOOLS/jdk-21.0.12.1+1')
SCRIPT = SCRIPTS / 'ExtractInternal187.java'
CAP_SECONDS = 1200


def main(batch: int) -> None:
    check_lease()
    if batch not in (1, 2):
        raise RuntimeError('batch must be 1 or 2')
    if batch == 2:
        first = json.loads((REPORT / 'ghidra_batch1_command.json').read_text(encoding='utf-8'))
        if first['status'] != 'OUTPUT_READY' or first['raw_result_files'] != 64:
            raise RuntimeError('batch 1 incomplete; stop sequential processing')
    if sha256(SOURCE) != SOURCE_SHA:
        raise RuntimeError('original SO changed')
    if not (GHIDRA / 'support/analyzeHeadless.bat').is_file() or not (JAVA_HOME / 'bin/java.exe').is_file():
        raise RuntimeError('Ghidra/JDK absent')
    index = json.loads((REPORT / 'source_project_index.json').read_text(encoding='utf-8'))
    if len(index['selected_candidate_rows']) != 128 or index['source_sha256'] != SOURCE_SHA:
        raise RuntimeError('source index differs')
    tsv = SCRATCH / f'target_batch_{batch}.tsv'
    if index['batch_files'][str(batch)]['sha256'] != sha256(tsv):
        raise RuntimeError('exact 64-candidate TSV changed')
    project = SCRATCH / 'ghidra_project'
    if project != Path(index['project_copy']):
        raise RuntimeError('project path differs')
    for item in index['project_files']:
        path = project / item['relative_path']
        if not path.is_file():
            if item['relative_path'].endswith('/idata/~journal.bak'):
                continue
            raise RuntimeError(f'copied project file absent: {path}')
        if sha256(path) != item['sha256'] and not item['relative_path'].endswith(
                ('/idata/~index.bak', '/idata/~journal.bak')):
            raise RuntimeError(f'copied content DB changed before batch {batch}: {path}')
    output = REPORT / f'ghidra_raw_batch{batch}'
    stdout = REPORT / f'ghidra_batch{batch}_stdout.log'
    stderr = REPORT / f'ghidra_batch{batch}_stderr.log'
    receipt = REPORT / f'ghidra_batch{batch}_command.json'
    if any(p.exists() for p in (output, stdout, stderr, receipt)):
        raise RuntimeError(f'Ghidra batch {batch} already started')
    check_lease()
    output.mkdir(parents=True, exist_ok=False)
    command = [str(GHIDRA / 'support/analyzeHeadless.bat'), str(project), index['project_name'],
               '-process', 'libMTFilterKernel.so', '-noanalysis', '-readOnly', '-max-cpu', '1',
               '-scriptPath', str(SCRIPTS), '-postScript', SCRIPT.name, str(tsv), str(output)]
    base = {'task_id': 'TASK_187', 'revision': 1, 'batch': batch, 'lease_id': LEASE_ID,
            'fencing_token': FENCE, 'source_sha256': SOURCE_SHA,
            'project_source': index['project_source'], 'project_copy': str(project),
            'target_tsv_sha256': sha256(tsv), 'script_sha256': sha256(SCRIPT),
            'command': command, 'operation': 'COPY_ONLY_64_FDE_NONEXPORT_CANDIDATES_NO_IMPORT',
            'max_cpu': 1, 'max_heap': '1G', 'max_process_seconds': CAP_SECONDS,
            'max_decompile_seconds_per_candidate': 10,
            'started_at': now(), 'status': 'STARTING'}
    write_json(receipt, base)
    env = os.environ.copy()
    env['JAVA_HOME'] = str(JAVA_HOME)
    env['PATH'] = str(JAVA_HOME / 'bin') + os.pathsep + env.get('PATH', '')
    env['GHIDRA_HEADLESS_MAXMEM'] = '1G'
    env['DOUBLE_CLICKED'] = 'n'
    remaining = min(CAP_SECONDS, (DEADLINE - datetime.now(timezone.utc)).total_seconds())
    if remaining <= 0:
        write_json(receipt, {**base, 'status': 'NOT_STARTED_DEADLINE', 'ended_at': now()})
        return
    started = time.monotonic()
    status = 'PROCESS_FAILED'
    code = None
    with stdout.open('wb') as out, stderr.open('wb') as err:
        proc = subprocess.Popen(command, env=env, stdin=subprocess.DEVNULL,
                                stdout=out, stderr=err,
                                creationflags=getattr(subprocess, 'CREATE_NO_WINDOW', 0))
        try:
            code = proc.wait(timeout=remaining)
        except subprocess.TimeoutExpired:
            proc.kill()
            code = proc.wait(timeout=15)
            status = 'PROCESS_TIMEOUT'
    files = sorted(output.glob('*.json'))
    if status != 'PROCESS_TIMEOUT':
        status = 'OUTPUT_READY' if code == 0 and len(files) == 64 else 'PARTIAL_OUTPUT'
    write_json(receipt, {**base, 'status': status, 'ended_at': now(),
                         'elapsed_seconds': round(time.monotonic() - started, 3),
                         'exit_code': code, 'raw_result_files': len(files),
                         'stdout_sha256': sha256(stdout), 'stderr_sha256': sha256(stderr),
                         'raw_result_hashes': {p.name: sha256(p) for p in files}})
    write_json(REPORT / 'PROGRESS.json', {'task_id': 'TASK_187', 'revision': 1,
               'status': status if batch == 2 else 'FIRST_GHIDRA_BATCH_' + status,
               'generated_at': now(), 'ghidra_candidates_output': len(files) + (64 if batch == 2 else 0),
               'new_imports': 0, 'original_bodies_verified': 128})
    print(json.dumps({'batch': batch, 'status': status, 'exit_code': code,
                      'output_files': len(files), 'elapsed_seconds': round(time.monotonic() - started, 3)}),
          flush=True)


if __name__ == '__main__':
    if len(sys.argv) != 2:
        raise SystemExit('usage: run_batch.py 1|2')
    main(int(sys.argv[1]))
