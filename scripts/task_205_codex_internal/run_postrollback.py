"""Reopen the private project read-only and prove original metadata after correction."""
from __future__ import annotations

import json
import os
import subprocess
import time
from datetime import datetime, timezone
from pathlib import Path

from common import (DEADLINE, FENCE, LEASE_ID, PROJECT, REPORT, SCRATCH,
                    SCRIPTS, check_lease, now, sha256, write_json)

GHIDRA = Path('F:/TOOLS/ghidra_12.1.4_PUBLIC')
JAVA_HOME = Path('F:/TOOLS/jdk-21.0.12.1+1')
SCRIPT = SCRIPTS / 'CheckOriginalMembership205.java'
CAP_SECONDS = 1200


def main() -> None:
    check_lease()
    prior = json.loads((REPORT / 'ghidra_correction_command.json').read_text(encoding='utf-8'))
    if prior['status'] != 'OUTPUT_READY' or prior['raw_result_files'] != 2:
        raise RuntimeError('corrective candidate output incomplete')
    index = json.loads((REPORT / 'source_project_index.json').read_text(encoding='utf-8'))
    if index['project_source'] != str(PROJECT) or len(index['project_files']) != 9:
        raise RuntimeError('pinned project origin differs')
    for row in index['project_files']:
        path = PROJECT / row['relative_path']
        if sha256(path) != row['sha256']:
            raise RuntimeError(f'prior project changed: {path}')
    project = SCRATCH / 'ghidra_project'
    tsv = SCRATCH / 'correction_targets.tsv'
    output = REPORT / 'ghidra_postrollback_raw'
    stdout = REPORT / 'ghidra_postrollback_stdout.log'
    stderr = REPORT / 'ghidra_postrollback_stderr.log'
    receipt = REPORT / 'ghidra_postrollback_command.json'
    if any(p.exists() for p in (output, stdout, stderr, receipt)):
        raise RuntimeError('fresh postrollback session already attempted')
    output.mkdir(parents=True, exist_ok=False)
    command = [str(GHIDRA / 'support/analyzeHeadless.bat'), str(project), index['project_name'],
               '-process', 'libPVGImageCodec.so', '-noanalysis', '-readOnly', '-max-cpu', '1',
               '-scriptPath', str(SCRIPTS), '-postScript', SCRIPT.name, str(tsv), str(output)]
    base = {'task_id': 'TASK_205', 'revision': 1, 'lease_id': LEASE_ID,
            'fencing_token': FENCE, 'target_tsv_sha256': sha256(tsv),
            'script_sha256': sha256(SCRIPT), 'command': command,
            'operation': 'FRESH_READ_ONLY_METADATA_AND_MEMORY_REPLAY_NO_IMPORT',
            'max_cpu': 1, 'max_heap': '1G', 'max_process_seconds': CAP_SECONDS,
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
        status = 'OUTPUT_READY' if code == 0 and len(files) == 2 else 'PARTIAL_OUTPUT'
    write_json(receipt, {**base, 'status': status, 'ended_at': now(),
                         'elapsed_seconds': round(time.monotonic() - started, 3),
                         'exit_code': code, 'raw_result_files': len(files),
                         'stdout_sha256': sha256(stdout), 'stderr_sha256': sha256(stderr),
                         'raw_result_hashes': {p.name: sha256(p) for p in files}})
    print(json.dumps({'status': status, 'exit_code': code, 'output_files': len(files),
                      'elapsed_seconds': round(time.monotonic() - started, 3)}), flush=True)


if __name__ == '__main__':
    main()
