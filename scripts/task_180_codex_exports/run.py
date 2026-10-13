"""Run one bounded, sequential Ghidra p-code/fragment session per pinned target."""
from __future__ import annotations

import json
import os
import subprocess
import time
from datetime import datetime, timezone
from pathlib import Path

from common import (DEADLINE, FENCE, LEASE_ID, REPORT, SCRATCH, SCRIPTS,
                    SOURCE, SOURCE_SHA, check_lease, metadata, now, sha256, write_json)

GHIDRA = Path('F:/TOOLS/ghidra_12.1.4_PUBLIC')
JAVA_HOME = Path('F:/TOOLS/jdk-21.0.12.1+1')
SCRIPT = SCRIPTS / 'ExtractPcodeFragment180.java'
FRAGMENTS = {1: ('0xa3f0', '0xa468'), 2: ('0xb4b0', '0xb518')}
MAX_PROCESS_SECONDS = 180


def verify_project(index: int) -> tuple[Path, str]:
    manifest = json.loads((REPORT / 'source_and_project_index.json').read_text(encoding='utf-8'))
    record = manifest['analyzed_project_copies'][str(index)]
    directory = SCRATCH / f'target_{index}' / 'ghidra_project'
    if record['project_dir'] != str(directory) or len(record['files']) < 3:
        raise RuntimeError(f'project census/path differs: {index}')
    for file in record['files']:
        path = directory / file['relative_path']
        if not path.is_file() or path.stat().st_size != file['bytes'] or sha256(path) != file['sha256']:
            raise RuntimeError(f'copied analyzed project file differs: {index} {file["relative_path"]}')
    return directory, record['project_name']


def run_one(index: int, target: dict, env: dict) -> dict:
    check_lease()
    if sha256(SOURCE) != SOURCE_SHA:
        raise RuntimeError('pinned original libMTGif changed')
    project, project_name = verify_project(index)
    fragment_start, fragment_end = FRAGMENTS[index]
    folder = REPORT / f'target_{index}'
    output = folder / 'ghidra_pcode_fragment_raw.json'
    stdout = folder / 'ghidra_stdout.log'
    stderr = folder / 'ghidra_stderr.log'
    receipt = folder / 'ghidra_command.json'
    if any(p.exists() for p in (output, stdout, stderr, receipt)):
        raise RuntimeError(f'target {index} Ghidra session already started')
    command = [str(GHIDRA / 'support/analyzeHeadless.bat'), str(project), project_name,
               '-process', 'libMTGif.so', '-noanalysis', '-readOnly', '-max-cpu', '1',
               '-scriptPath', str(SCRIPTS), '-postScript', SCRIPT.name,
               str(index), target['elf_va'], str(target['size_bytes']),
               target['source_body_sha256'], fragment_start, fragment_end, str(output)]
    base = {'task_id': 'TASK_180', 'revision': 1, 'target_index': index,
            'lease_id': LEASE_ID, 'fencing_token': FENCE,
            'started_at': now(), 'source_sha256': SOURCE_SHA,
            'source_body_sha256': target['source_body_sha256'],
            'script_sha256': sha256(SCRIPT),
            'operation': 'ORIGINAL_PCODE_AND_SINGLE_SYNTHETIC_SCALAR_FRAGMENT_NO_IMPORT',
            'fragment_elf_start': fragment_start, 'fragment_elf_end_inclusive': fragment_end,
            'hard_process_cap_seconds': MAX_PROCESS_SECONDS, 'cpu_cap': 1, 'heap_cap': '1G',
            'command': command}
    write_json(receipt, {**base, 'status': 'STARTING'})
    remaining = min(MAX_PROCESS_SECONDS, (DEADLINE - datetime.now(timezone.utc)).total_seconds())
    if remaining <= 0:
        write_json(receipt, {**base, 'status': 'NOT_STARTED_DEADLINE', 'ended_at': now()})
        return {'target_index': index, 'status': 'NOT_STARTED_DEADLINE'}
    started = time.monotonic()
    code = None
    status = 'PROCESS_FAILED'
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
    raw = None
    if output.is_file():
        try:
            raw = json.loads(output.read_text(encoding='utf-8'))
        except Exception:
            status = 'UNPARSEABLE_RESULT'
    if status != 'PROCESS_TIMEOUT' and code == 0 and raw is not None:
        if (raw.get('task_id') == 'TASK_180' and raw.get('target_index') == index and
            raw.get('elf_va') == target['elf_va'] and
            raw.get('ghidra_original_memory_sha256') == target['source_body_sha256'] and
            raw.get('memory_unchanged_after_rollback') is True and
            raw.get('original_instruction_count', 0) > 0 and
            raw.get('original_pcode_operation_count', 0) > 0):
            status = 'OUTPUT_READY'
    observed = None if raw is None else {
        'original_instruction_count': raw.get('original_instruction_count'),
        'original_pcode_operation_count': raw.get('original_pcode_operation_count'),
        'synthetic_function_created': raw.get('synthetic_fragment', {}).get('function_created'),
        'synthetic_fragment_c_like_nonempty': raw.get('synthetic_fragment', {}).get('decompile_success'),
        'synthetic_fragment_error': raw.get('synthetic_fragment', {}).get('error')}
    elapsed = round(time.monotonic() - started, 3)
    write_json(receipt, {**base, 'ended_at': now(), 'elapsed_seconds': elapsed,
                         'exit_code': code, 'status': status,
                         'stdout_sha256': sha256(stdout), 'stderr_sha256': sha256(stderr),
                         'result_sha256': sha256(output) if output.is_file() else None,
                         'observed': observed})
    return {'target_index': index, 'status': status, 'elapsed_seconds': elapsed,
            'exit_code': code, 'observed': observed}


def main() -> None:
    check_lease()
    if (REPORT / 'run_receipt.json').exists():
        raise RuntimeError('TASK_180 Ghidra batch already started')
    if not (GHIDRA / 'support/analyzeHeadless.bat').is_file() or not (JAVA_HOME / 'bin/java.exe').is_file():
        raise RuntimeError('Ghidra/JDK absent')
    env = os.environ.copy()
    env['JAVA_HOME'] = str(JAVA_HOME)
    env['PATH'] = str(JAVA_HOME / 'bin') + os.pathsep + env.get('PATH', '')
    env['GHIDRA_HEADLESS_MAXMEM'] = '1G'
    env['DOUBLE_CLICKED'] = 'n'
    started_at = now()
    outcomes = []
    write_json(REPORT / 'run_receipt.json', {'task_id': 'TASK_180', 'revision': 1,
                                             'status': 'RUNNING', 'started_at': started_at,
                                             'targets': outcomes})
    for index, target in enumerate(metadata()['target_exports'], 1):
        try:
            row = run_one(index, target, env)
        except Exception as failure:
            row = {'target_index': index, 'status': 'ERROR', 'error': str(failure)}
        outcomes.append(row)
        write_json(REPORT / 'run_receipt.json', {'task_id': 'TASK_180', 'revision': 1,
                                                 'status': 'RUNNING', 'started_at': started_at,
                                                 'updated_at': now(), 'targets': outcomes})
        write_json(REPORT / 'PROGRESS.json', {'task_id': 'TASK_180', 'revision': 1,
                                              'status': 'PCODE_AND_FRAGMENT_RUNNING',
                                              'generated_at': now(), 'targets_finished': len(outcomes),
                                              'last_target': index, 'last_status': row['status'],
                                              'fresh_imports': 0,
                                              'whole_original_c_like_recovered': 0})
        print(json.dumps(row), flush=True)
    status = 'OUTPUT_READY' if all(row['status'] == 'OUTPUT_READY' for row in outcomes) else 'PARTIAL_OUTPUT'
    write_json(REPORT / 'run_receipt.json', {'task_id': 'TASK_180', 'revision': 1,
                                             'status': status, 'started_at': started_at,
                                             'finished_at': now(), 'targets': outcomes})
    print(json.dumps({'status': status, 'targets': len(outcomes)}), flush=True)


if __name__ == '__main__':
    main()
