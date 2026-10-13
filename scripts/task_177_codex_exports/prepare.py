"""Re-enumerate originals and validate unaccepted TASK_149/153 historical evidence."""
from __future__ import annotations

import hashlib
import json
import shutil
from pathlib import Path

from elftools.elf.elffile import ELFFile

from common import (AGENT_ID, FENCE, LEASE_ID, REPORT, ROOT, SCRATCH,
                    SOURCE_DIR, STANDARD, STANDARD_SHA, TASK_SHA,
                    atomic_bytes, check_lease, historical_task, now,
                    prior_project, prior_report, sha256, task_metadata, write_json)

HISTORICAL_FILES = ('target_index.json', 'targets.tsv', 'ghidra_raw.json',
                    'ghidra_command.json', 'ghidra_stdout.log', 'ghidra_stderr.log')
PRIOR_COMPLETE_SHA = {
    149: 'bd2439079eebac487c2f81e26ab69a5478d67868a194c91797156bf77583249f',
    153: 'f33a16301c2f4a8782b3771f5cdcfa6a49c99ae52829bc5bc02a0e883801880f',
}
KNOWN_GAPS = {('libMTGif.so', 32), ('libMTGif.so', 49)}


def mapped_bytes(elf: ELFFile, source: Path, va: int, size: int) -> tuple[bytes, int]:
    for segment in elf.iter_segments():
        if segment['p_type'] != 'PT_LOAD':
            continue
        base, length = int(segment['p_vaddr']), int(segment['p_filesz'])
        if base <= va and va + size <= base + length:
            offset = int(segment['p_offset']) + va - base
            with source.open('rb') as stream:
                stream.seek(offset)
                data = stream.read(size)
            if len(data) == size:
                return data, offset
    raise RuntimeError(f'original PT_LOAD mapping absent: {source.name}:0x{va:x}+{size}')


def verify_source_and_history(name: str, pin: dict) -> dict:
    source = SOURCE_DIR / name
    prior = prior_report(name)
    expected_sha = pin['sha256']
    expected_count = pin['expected_unique_export_vas']
    if sha256(source) != expected_sha:
        raise RuntimeError(f'original source SHA mismatch: {name}')
    pidx = json.loads((prior / 'target_index.json').read_text(encoding='utf-8'))
    praw = json.loads((prior / 'ghidra_raw.json').read_text(encoding='utf-8'))
    pcmd = json.loads((prior / 'ghidra_command.json').read_text(encoding='utf-8'))
    if (pidx['source_sha256'] != expected_sha or pidx['unique_export_vas'] != expected_count or
        praw['program_name'] != name or len(pidx['targets']) != expected_count or
        len(praw['targets']) != expected_count or pcmd['source_sha256'] != expected_sha or
        pcmd['status'] != 'OUTPUT_READY' or pcmd['exit_code'] != 0 or
        pcmd['result_sha256'] != sha256(prior / 'ghidra_raw.json') or
        pcmd['stdout_sha256'] != sha256(prior / 'ghidra_stdout.log') or
        pcmd['stderr_sha256'] != sha256(prior / 'ghidra_stderr.log') or
        pcmd['target_tsv_sha256'] != sha256(prior / 'targets.tsv') or
        '-import' not in pcmd['command'] or '-max-cpu' not in pcmd['command']):
        raise RuntimeError(f'historical raw provenance mismatch: {name}')
    source_rows = []
    gaps = []
    with source.open('rb') as stream:
        elf = ELFFile(stream)
        if elf['e_machine'] != 'EM_AARCH64':
            raise RuntimeError(f'original architecture differs: {name}')
        dynsym = elf.get_section_by_name('.dynsym')
        if dynsym is None:
            raise RuntimeError(f'original dynsym missing: {name}')
        by_va = {}
        for sym in dynsym.iter_symbols():
            if (sym['st_info']['type'] == 'STT_FUNC' and sym['st_shndx'] != 'SHN_UNDEF' and
                int(sym['st_value']) > 0 and int(sym['st_size']) > 0):
                by_va.setdefault(int(sym['st_value']), []).append((sym.name, int(sym['st_size'])))
        if len(by_va) != expected_count:
            raise RuntimeError(f'original export VA count differs: {name}: {len(by_va)}')
        for index, va in enumerate(sorted(by_va), 1):
            alias_sizes = sorted(by_va[va], key=lambda pair: (-pair[1], pair[0]))
            symbol, size = alias_sizes[0]
            body, offset = mapped_bytes(elf, source, va, size)
            body_sha = hashlib.sha256(body).hexdigest()
            ir = pidx['targets'][index - 1]
            hr = praw['targets'][index - 1]
            if (ir['index'] != index or ir['elf_va'] != f'0x{va:x}' or
                ir['size_bytes'] != size or ir['symbol'] != symbol or
                ir['aliases'] != [entry[0] for entry in alias_sizes] or
                ir['file_offset'] != f'0x{offset:x}' or
                ir['source_body_sha256'] != body_sha or
                hr['index'] != index or hr['elf_va'] != f'0x{va:x}' or
                hr['symbol'] != symbol or hr['size_bytes'] != size or
                hr['expected_source_sha256'] != body_sha or
                hr['ghidra_memory_sha256'] != body_sha or
                hr['source_bytes_match'] is not True or
                hr['instruction_count_observed'] != len(hr['instructions'])):
                raise RuntimeError(f'historical body identity differs: {name} {index}')
            c_like = hr['decompile_success'] is True and bool(hr['pseudocode'].strip())
            if not c_like:
                if (name, index) not in KNOWN_GAPS:
                    raise RuntimeError(f'unexpected historical C-like gap: {name} {index}')
                gaps.append({'index': index, 'symbol': symbol, 'elf_va': f'0x{va:x}',
                             'size_bytes': size, 'source_body_sha256': body_sha,
                             'historical_error': hr.get('error', ''),
                             'historical_decompile_success': hr['decompile_success']})
            source_rows.append({'index': index, 'elf_va': f'0x{va:x}',
                                'symbol': symbol, 'aliases': [entry[0] for entry in alias_sizes],
                                'size_bytes': size, 'file_offset': f'0x{offset:x}',
                                'source_body_sha256': body_sha,
                                'historical_database_va': hr['database_va'],
                                'historical_c_like_nonempty': c_like,
                                'historical_c_like_sha256': hashlib.sha256(hr['pseudocode'].encode()).hexdigest()
                                if c_like else None,
                                'historical_instruction_rows': len(hr['instructions'])})
    folder = REPORT / name
    copied = []
    for filename in HISTORICAL_FILES:
        check_lease()
        original = prior / filename
        target = folder / ('historical_' + filename)
        digest = sha256(original)
        atomic_bytes(target, original.read_bytes())
        if sha256(target) != digest:
            raise RuntimeError(f'historical evidence copy differed: {name}/{filename}')
        copied.append({'original_path': str(original),
                       'report_path': target.relative_to(REPORT).as_posix(),
                       'bytes': target.stat().st_size, 'sha256': digest})
    write_json(folder / 'source_index.json', {
        'schema_version': '2.1.2', 'task_id': 'TASK_177', 'revision': 1,
        'library': name, 'source_path': str(source), 'source_sha256': expected_sha,
        'source_bytes': source.stat().st_size,
        'original_unique_export_vas': expected_count,
        'historical_task_id': f'TASK_{historical_task(name)}',
        'historical_raw_sha256': sha256(prior / 'ghidra_raw.json'),
        'targets': source_rows})
    return {'library': name, 'source_sha256': expected_sha,
            'historical_task_id': f'TASK_{historical_task(name)}',
            'original_unique_export_vas': expected_count,
            'original_pt_load_bodies_verified': len(source_rows),
            'historical_c_like_nonempty': expected_count - len(gaps),
            'precise_c_like_gaps': gaps, 'historical_files': copied}


def copy_projects(names: list[str]) -> dict:
    projects = {}
    for name in names:
        old = prior_project(name)
        new = SCRATCH / name / 'ghidra_project'
        files = sorted(path for path in old.rglob('*') if path.is_file())
        if len(files) < 3 or not list(old.glob('*.gpr')):
            raise RuntimeError(f'historical analyzed project absent: {name}')
        records = []
        for original in files:
            check_lease()
            relative = original.relative_to(old)
            destination = new / relative
            destination.parent.mkdir(parents=True, exist_ok=True)
            before = sha256(original)
            shutil.copy2(original, destination)
            after = sha256(destination)
            if before != after:
                raise RuntimeError(f'analyzed project copy differed: {name}/{relative}')
            records.append({'relative_path': relative.as_posix(),
                            'bytes': destination.stat().st_size,
                            'source_sha256': before, 'copy_sha256': after})
        projects[name] = {'original_project_path': str(old), 'copy_project_path': str(new),
                          'project_name': next(old.glob('*.gpr')).stem,
                          'file_count': len(records), 'files': records}
    return projects


def main() -> None:
    check_lease()
    if REPORT.exists() or SCRATCH.exists():
        raise RuntimeError('TASK_177 output already started')
    for task, digest in PRIOR_COMPLETE_SHA.items():
        if sha256(ROOT / f'RULES/REPORT/TASK_{task}_REPORT_R1/COMPLETE.json') != digest:
            raise RuntimeError(f'historical TASK_{task} seal changed')
    meta = task_metadata()
    libraries = [verify_source_and_history(name, pin)
                 for name, pin in meta['source_libraries'].items()]
    projects = copy_projects(list(meta['source_libraries']))
    write_json(REPORT / 'project_copy_manifest.json', {
        'task_id': 'TASK_177', 'revision': 1, 'verified_at': now(),
        'historical_complete_sha256': {str(k): v for k, v in PRIOR_COMPLETE_SHA.items()},
        'projects': projects})
    write_json(REPORT / 'source_batch_index.json', {
        'task_id': 'TASK_177', 'revision': 1, 'generated_at': now(),
        'actor': AGENT_ID, 'lease_id': LEASE_ID, 'fencing_token': FENCE,
        'standard_path': str(STANDARD), 'standard_sha256': STANDARD_SHA,
        'task_sha256': TASK_SHA, 'libraries': libraries,
        'total_original_unique_export_vas': sum(r['original_unique_export_vas'] for r in libraries),
        'total_original_pt_load_bodies_verified': sum(r['original_pt_load_bodies_verified'] for r in libraries),
        'total_historical_c_like_nonempty': sum(r['historical_c_like_nonempty'] for r in libraries),
        'total_precise_c_like_gaps': sum(len(r['precise_c_like_gaps']) for r in libraries)})
    write_json(REPORT / 'PROGRESS.json', {
        'task_id': 'TASK_177', 'revision': 1, 'status': 'ORIGINAL_AND_HISTORICAL_RAW_VERIFIED',
        'generated_at': now(), 'libraries_verified': len(libraries),
        'original_pt_load_bodies_verified': sum(r['original_pt_load_bodies_verified'] for r in libraries),
        'historical_c_like_nonempty': sum(r['historical_c_like_nonempty'] for r in libraries),
        'precise_c_like_gaps': sum(len(r['precise_c_like_gaps']) for r in libraries),
        'project_files_byte_verified': sum(p['file_count'] for p in projects.values()),
        'fresh_imports': 0, 'fresh_decompilations': 0})
    audit = ('# TASK_177 R1 audit index\n\n'
             f'Canonical standard fully re-read: `{STANDARD}` SHA-256 `{STANDARD_SHA}`.\n\n'
             f'Task SHA-256 `{TASK_SHA}`; actor `{AGENT_ID}`; lease `{LEASE_ID}`; fence `{FENCE}`.\n\n'
             'The 11 original ELF sources, historical unaccepted TASK_149/153 raw commands/logs/results, '
             'and byte-verified analyzed project copies are enumerated in `source_batch_index.json` '
             'and `project_copy_manifest.json`. Historical C-like text is not counted as newly decompiled.\n')
    atomic_bytes(REPORT / '00_AUDIT_INDEX.md', audit.encode())
    print(json.dumps({'libraries': len(libraries), 'original_vas': sum(r['original_unique_export_vas'] for r in libraries),
                      'historical_c_like': sum(r['historical_c_like_nonempty'] for r in libraries),
                      'gaps': [(r['library'], g['index'], g['elf_va']) for r in libraries for g in r['precise_c_like_gaps']],
                      'copied_project_files': sum(p['file_count'] for p in projects.values())}))


if __name__ == '__main__':
    main()
