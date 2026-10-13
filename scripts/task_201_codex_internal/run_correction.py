"""One bounded transient full-FDE pass for seven exact pre-existing membership gaps."""
from __future__ import annotations

import json
import os
import subprocess
import time
from datetime import datetime, timezone
from pathlib import Path

from common import (DEADLINE, FENCE, LEASE_ID, REPORT, SCRATCH, SCRIPTS,
                    atomic_bytes, check_lease, now, sha256, write_json)

GHIDRA = Path('F:/TOOLS/ghidra_12.1.4_PUBLIC')
JAVA_HOME = Path('F:/TOOLS/jdk-21.0.12.1+1')
SCRIPT = SCRIPTS / 'RepairMembership201.java'
INDICES = (347, 348, 357, 358, 360, 361, 363)
CAP_SECONDS = 1200


def main() -> None:
    check_lease()
    for batch in (1, 2):
        cmd = json.loads((REPORT / f'ghidra_batch{batch}_command.json').read_text(encoding='utf-8'))
        if cmd['status'] != 'OUTPUT_READY' or cmd['raw_result_files'] != 31:
            raise RuntimeError(f'initial batch {batch} is incomplete')
    index = json.loads((REPORT / 'source_project_index.json').read_text(encoding='utf-8'))
    rows = {row['index']: row for row in index['selected_candidate_rows']}
    raw = {}
    for batch in (1, 2):
        for file in (REPORT / f'ghidra_raw_batch{batch}').glob('*.json'):
            data = json.loads(file.read_text(encoding='utf-8'))
            raw[data['index']] = data
    if len(raw) != 62:
        raise RuntimeError('62 raw result census differs')
    anomalies = sorted(i for i, r in raw.items()
                       if r['fde_byte_membership_count'] != r['size_bytes'] or
                       r['missing_analyzed_instruction_count'] > 0)
    if anomalies != list(INDICES):
        raise RuntimeError(f'exact seven anomaly indices changed: {anomalies}')
    for i in INDICES:
        r = raw[i]
        source = rows[i]
        if (r['elf_va'] != source['elf_va'] or r['size_bytes'] != source['size_bytes'] or
                r['ghidra_memory_sha256'] != source['source_body_sha256'] or
                r['other_function_byte_count'] != 0 or not r['existing_exact_function_start']):
            raise RuntimeError(f'anomaly #{i} source/Ghidra identity differs')
    tsv = SCRATCH / 'correction_targets.tsv'
    output = REPORT / 'ghidra_correction_raw'
    stdout = REPORT / 'ghidra_correction_stdout.log'
    stderr = REPORT / 'ghidra_correction_stderr.log'
    receipt = REPORT / 'ghidra_correction_command.json'
    if any(p.exists() for p in (output, stdout, stderr, receipt)):
        raise RuntimeError('corrective pass already attempted')
    atomic_bytes(tsv, ''.join(
        f"{i}\t{rows[i]['elf_va']}\t{rows[i]['size_bytes']}\t{rows[i]['source_body_sha256']}\n"
        for i in INDICES).encode('ascii'))
    check_lease()
    output.mkdir(parents=True, exist_ok=False)
    project = SCRATCH / 'ghidra_project'
    command = [str(GHIDRA / 'support/analyzeHeadless.bat'), str(project), index['project_name'],
               '-process', 'libMTFilterKernel.so', '-noanalysis', '-readOnly', '-max-cpu', '1',
               '-scriptPath', str(SCRIPTS), '-postScript', SCRIPT.name, str(tsv), str(output)]
    base = {'task_id': 'TASK_201', 'revision': 1, 'lease_id': LEASE_ID,
            'fencing_token': FENCE, 'target_indices': list(INDICES),
            'target_tsv_sha256': sha256(tsv), 'script_sha256': sha256(SCRIPT),
            'command': command, 'operation': 'SEVEN_TRANSIENT_FULL_FDE_METADATA_CORRECTIONS_NO_IMPORT',
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
        status = 'OUTPUT_READY' if code == 0 and len(files) == 7 else 'PARTIAL_OUTPUT'
    write_json(receipt, {**base, 'status': status, 'ended_at': now(),
                         'elapsed_seconds': round(time.monotonic() - started, 3),
                         'exit_code': code, 'raw_result_files': len(files),
                         'stdout_sha256': sha256(stdout), 'stderr_sha256': sha256(stderr),
                         'raw_result_hashes': {p.name: sha256(p) for p in files}})
    write_json(REPORT / 'PROGRESS.json', {'task_id': 'TASK_201', 'revision': 1,
               'status': 'SEVEN_FDE_BOUNDARY_CORRECTIONS_' + status,
               'generated_at': now(), 'original_bodies_verified': 62,
               'first_pass_candidates_output': 62, 'correction_output': len(files),
               'new_imports': 0})
    print(json.dumps({'status': status, 'exit_code': code, 'output_files': len(files),
                      'elapsed_seconds': round(time.monotonic() - started, 3)}), flush=True)


if __name__ == '__main__':
    main()

