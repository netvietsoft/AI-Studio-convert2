"""One additional bounded copied-project pass for exact FDE #10 truncation."""
from __future__ import annotations

import json
import os
import subprocess
import time
from datetime import datetime, timezone
from pathlib import Path

from common import (DEADLINE, FENCE, LEASE_ID, REPORT, SCRATCH, SCRIPTS,
                    check_lease, now, sha256, write_json)

GHIDRA = Path('F:/TOOLS/ghidra_12.1.4_PUBLIC')
JAVA_HOME = Path('F:/TOOLS/jdk-21.0.12.1+1')
SCRIPT = SCRIPTS / 'RepairBoundary183.java'


def main() -> None:
    check_lease()
    original = json.loads((REPORT / 'ghidra_raw/10_e724.json').read_text(encoding='utf-8'))
    if (original['index'] != 10 or original['ghidra_instruction_count'] != 15
            or original['missing_analyzed_instruction_count'] != 5
            or original['ghidra_memory_sha256'] !=
            'f629ed5510c08e0a84ba8de78c755467f3a12e61f3de620dae26771549583088'):
        raise RuntimeError('precise existing Ghidra function gap changed')
    output = REPORT / 'ghidra_boundary_10.json'
    stdout = REPORT / 'boundary_10_stdout.log'
    stderr = REPORT / 'boundary_10_stderr.log'
    receipt = REPORT / 'boundary_10_command.json'
    if any(x.exists() for x in (output, stdout, stderr, receipt)):
        raise RuntimeError('boundary correction already attempted')
    project = SCRATCH / 'ghidra_project'
    project_name = json.loads((REPORT / 'source_project_index.json').read_text())['project_name']
    command = [str(GHIDRA / 'support/analyzeHeadless.bat'), str(project), project_name,
               '-process', 'libMTGif.so', '-noanalysis', '-readOnly', '-max-cpu', '1',
               '-scriptPath', str(SCRIPTS), '-postScript', SCRIPT.name, str(output)]
    base = {'task_id': 'TASK_183', 'revision': 1, 'only_candidate_index': 10,
            'lease_id': LEASE_ID, 'fencing_token': FENCE,
            'reason': 'FDE 80 bytes versus pre-existing Ghidra function 60 bytes',
            'script_sha256': sha256(SCRIPT), 'command': command,
            'max_cpu': 1, 'max_heap': '1G', 'max_process_seconds': 1200,
            'max_decompile_seconds': 10, 'started_at': now(), 'status': 'STARTING'}
    write_json(receipt, base)
    remaining = min(1200, (DEADLINE - datetime.now(timezone.utc)).total_seconds())
    if remaining <= 0:
        write_json(receipt, {**base, 'status': 'NOT_STARTED_DEADLINE', 'ended_at': now()})
        return
    env = os.environ.copy()
    env['JAVA_HOME'] = str(JAVA_HOME)
    env['PATH'] = str(JAVA_HOME / 'bin') + os.pathsep + env.get('PATH', '')
    env['GHIDRA_HEADLESS_MAXMEM'] = '1G'
    env['DOUBLE_CLICKED'] = 'n'
    started = time.monotonic()
    status = 'PROCESS_FAILED'
    code = None
    with stdout.open('wb') as out, stderr.open('wb') as err:
        process = subprocess.Popen(command, env=env, stdin=subprocess.DEVNULL,
                                   stdout=out, stderr=err,
                                   creationflags=getattr(subprocess, 'CREATE_NO_WINDOW', 0))
        try:
            code = process.wait(timeout=remaining)
        except subprocess.TimeoutExpired:
            process.kill()
            code = process.wait(timeout=15)
            status = 'PROCESS_TIMEOUT'
    parsed = None
    if output.is_file():
        try:
            parsed = json.loads(output.read_text(encoding='utf-8'))
        except Exception:
            status = 'INVALID_OUTPUT'
    if status not in ('PROCESS_TIMEOUT', 'INVALID_OUTPUT'):
        status = 'OUTPUT_READY' if code == 0 and parsed is not None else 'PARTIAL_OUTPUT'
    write_json(receipt, {**base, 'status': status, 'ended_at': now(),
                         'elapsed_seconds': round(time.monotonic() - started, 3),
                         'exit_code': code, 'stdout_sha256': sha256(stdout),
                         'stderr_sha256': sha256(stderr),
                         'result_sha256': sha256(output) if output.is_file() else None,
                         'observed': None if parsed is None else {
                             'full_fde_instruction_count': parsed.get('full_fde_instruction_count'),
                             'full_fde_pcode_ops': parsed.get('full_fde_pcode_ops'),
                             'c_like_nonempty': parsed.get('c_like_nonempty'),
                             'error': parsed.get('error')}})
    print(json.dumps({'status': status, 'elapsed_seconds': round(time.monotonic() - started, 3),
                      'observed': None if parsed is None else {
                          'instructions': parsed.get('full_fde_instruction_count'),
                          'pcode': parsed.get('full_fde_pcode_ops'),
                          'c_like': parsed.get('c_like_nonempty'),
                          'error': parsed.get('error')}}), flush=True)


if __name__ == '__main__':
    main()
