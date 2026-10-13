"""Independent original-byte/provenance check and truthful TASK_177 PARTIAL seal."""
from __future__ import annotations

import hashlib
import json
import math
from collections import Counter
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

from common import (AGENT_ID, LEASE_ID, REPORT, ROOT, SCRATCH, SCRIPTS,
                    SOURCE_DIR, STANDARD, STANDARD_SHA, TASK_SHA,
                    atomic_bytes, check_lease, historical_task, now,
                    prior_project, prior_report, sha256, task_metadata, write_json)
from prepare import HISTORICAL_FILES, KNOWN_GAPS, PRIOR_COMPLETE_SHA, mapped_bytes

ALIAS_PAIRS = {('b.cs', 'b.hs'), ('b.cc', 'b.lo'), ('orr', 'mov'),
               ('dup', 'mov'), ('bfm', 'bfi'), ('negs', 'cmp')}
CORRECTION = ROOT / 'RULES/REPORT/TASK_154_REPORT_R1'
CORRECTION_SHA = 'cc8299662a80d882e5e141b88c9ade9a09b6898e6e44996ea5a8c443505c54fb'
CORRECTION_FILES = ('ghidra_raw.json', 'ghidra_command.json', 'ghidra_stdout.log',
                    'ghidra_stderr.log', 'source_disassembly.txt',
                    'project_copy_receipt.json', 'independent_verification.json')


def load(path: Path) -> dict:
    return json.loads(path.read_text(encoding='utf-8'))


def sample_indices(count: int) -> set[int]:
    n = max(1, math.ceil(0.12 * count))
    if n == 1:
        return {1}
    return {1 + round(i * (count - 1) / (n - 1)) for i in range(n)}


def verify_project(name: str, record: dict) -> dict:
    original = prior_project(name)
    copied = SCRATCH / name / 'ghidra_project'
    if (record['original_project_path'] != str(original) or
        record['copy_project_path'] != str(copied) or
        record['file_count'] != len(record['files'])):
        raise RuntimeError(f'project provenance differs: {name}')
    core = []
    metadata_changes = []
    for row in record['files']:
        relative = row['relative_path']
        src = original / relative
        dst = copied / relative
        if sha256(src) != row['source_sha256'] or row['copy_sha256'] != row['source_sha256']:
            raise RuntimeError(f'historical analyzed project changed: {name}/{relative}')
        actual = sha256(dst) if dst.is_file() else None
        if actual == row['copy_sha256']:
            core.append(relative)
        else:
            if not relative.endswith(('/idata/~index.bak', '/idata/~journal.bak')):
                raise RuntimeError(f'Ghidra program database copy changed: {name}/{relative}')
            metadata_changes.append({'path': relative, 'initial_sha256': row['copy_sha256'],
                                     'after_read_only_sha256': actual})
    if (not any(x.endswith('.gpr') for x in core) or
        not any(x.endswith('/00000000.prp') for x in core) or
        not any(x.endswith('/db.1.gbf') for x in core)):
        raise RuntimeError(f'Ghidra program DB/gpr not preserved: {name}')
    return {'initial_byte_identical_project_files': len(record['files']),
            'program_content_files_still_identical': len(core),
            'session_metadata_changes': metadata_changes}


def verify_correction() -> dict:
    if sha256(CORRECTION / 'COMPLETE.json') != CORRECTION_SHA:
        raise RuntimeError('TASK_154 correction seal changed')
    cmd = load(CORRECTION / 'ghidra_command.json')
    raw = load(CORRECTION / 'ghidra_raw.json')
    rows = raw['targets']
    if (len(rows) != 2 or [x['elf_va'] for x in rows] != ['0xa1f0', '0xaf70'] or
        any(x['decompile_success'] or x['pseudocode'].strip() for x in rows) or
        cmd['exit_code'] != 0 or cmd['result_sha256'] != sha256(CORRECTION / 'ghidra_raw.json') or
        cmd['stdout_sha256'] != sha256(CORRECTION / 'ghidra_stdout.log') or
        cmd['stderr_sha256'] != sha256(CORRECTION / 'ghidra_stderr.log')):
        raise RuntimeError('TASK_154 raw correction is not the known two-gap attempt')
    records = []
    for filename in CORRECTION_FILES:
        check_lease()
        src = CORRECTION / filename
        dst = REPORT / 'libMTGif.so' / ('correction_TASK_154_' + filename)
        atomic_bytes(dst, src.read_bytes())
        if sha256(dst) != sha256(src):
            raise RuntimeError(f'TASK_154 evidence copy changed: {filename}')
        records.append({'original_path': str(src),
                        'report_path': dst.relative_to(REPORT).as_posix(),
                        'sha256': sha256(src), 'bytes': dst.stat().st_size})
    result = {'correction_task': 'TASK_154', 'complete_sha256': CORRECTION_SHA,
              'observed_source_aligned_targets': 2, 'c_like_bodies_recovered': 0,
              'evidence_files': records}
    write_json(REPORT / 'libMTGif.so' / 'correction_TASK_154_receipt.json', result)
    return result


def verify_one(name: str, pin: dict, batch: dict, run: dict, project: dict) -> dict:
    check_lease()
    expected_sha = pin['sha256']
    count = pin['expected_unique_export_vas']
    source = SOURCE_DIR / name
    folder = REPORT / name
    if sha256(source) != expected_sha:
        raise RuntimeError(f'original source changed: {name}')
    copied = {row['report_path']: row for row in batch['historical_files']}
    if len(copied) != len(HISTORICAL_FILES):
        raise RuntimeError(f'historical evidence census differs: {name}')
    for filename in HISTORICAL_FILES:
        src = prior_report(name) / filename
        dst = folder / ('historical_' + filename)
        record = copied[dst.relative_to(REPORT).as_posix()]
        if record['original_path'] != str(src) or record['sha256'] != sha256(src) or record['sha256'] != sha256(dst):
            raise RuntimeError(f'historical raw copy changed: {name}/{filename}')
    source_index = load(folder / 'source_index.json')
    old_index = load(folder / 'historical_target_index.json')
    old_raw = load(folder / 'historical_ghidra_raw.json')
    old_cmd = load(folder / 'historical_ghidra_command.json')
    fresh = load(folder / 'fresh_memory_raw.json')
    cmd = load(folder / 'fresh_memory_command.json')
    if (source_index['source_sha256'] != expected_sha or
        source_index['historical_raw_sha256'] != sha256(folder / 'historical_ghidra_raw.json') or
        source_index['original_unique_export_vas'] != count or
        old_index['source_sha256'] != expected_sha or old_index['unique_export_vas'] != count or
        old_cmd['result_sha256'] != sha256(folder / 'historical_ghidra_raw.json') or
        old_cmd['stdout_sha256'] != sha256(folder / 'historical_ghidra_stdout.log') or
        old_cmd['stderr_sha256'] != sha256(folder / 'historical_ghidra_stderr.log') or
        old_cmd['target_tsv_sha256'] != sha256(folder / 'historical_targets.tsv') or
        cmd['result_sha256'] != sha256(folder / 'fresh_memory_raw.json') or
        cmd['stdout_sha256'] != sha256(folder / 'fresh_memory_stdout.log') or
        cmd['stderr_sha256'] != sha256(folder / 'fresh_memory_stderr.log') or
        cmd['script_sha256'] != sha256(SCRIPTS / 'VerifyMemory177.java') or
        cmd['historical_targets_tsv_sha256'] != sha256(folder / 'historical_targets.tsv') or
        cmd['source_sha256'] != expected_sha or cmd['status'] != 'OUTPUT_READY' or
        cmd['exit_code'] != 0 or cmd['expected_target_count'] != count or
        cmd['operation'] != 'READ_ONLY_MEMORY_HASH_ONLY_NO_IMPORT_NO_DECOMPILATION' or
        '-readOnly' not in cmd['command'] or '-noanalysis' not in cmd['command'] or
        '-max-cpu' not in cmd['command'] or '-import' in cmd['command'] or
        'VerifyMemory177.java' not in cmd['command'] or
        fresh['fresh_imports'] != 0 or fresh['fresh_decompilations'] != 0 or
        run['library'] != name or run['status'] != 'OUTPUT_READY' or run['exit_code'] != 0):
        raise RuntimeError(f'raw command/log/result provenance differs: {name}')
    sources = source_index['targets']
    previous = old_index['targets']
    history = old_raw['targets']
    memory = fresh['targets']
    if not all(len(rows) == count for rows in (sources, previous, history, memory)):
        raise RuntimeError(f'export census differs: {name}')
    if fresh['target_count'] != count or old_raw['program_name'] != name or fresh['program_name'] != name:
        raise RuntimeError(f'Ghidra program identity differs: {name}')
    if old_raw['image_base'] != fresh['image_base']:
        raise RuntimeError(f'Ghidra image base differs: {name}')
    base = int(fresh['image_base'], 16)
    cs = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    totals = Counter()
    aliases = Counter()
    samples = []
    all_rows = []
    gaps = []
    sample = sample_indices(count)
    with source.open('rb') as stream:
        elf = ELFFile(stream)
        if elf['e_machine'] != 'EM_AARCH64':
            raise RuntimeError(f'original architecture differs: {name}')
        dynsym = elf.get_section_by_name('.dynsym')
        if dynsym is None:
            raise RuntimeError(f'original dynsym absent: {name}')
        symbols = {}
        for sym in dynsym.iter_symbols():
            if (sym['st_info']['type'] == 'STT_FUNC' and sym['st_shndx'] != 'SHN_UNDEF' and
                int(sym['st_value']) > 0 and int(sym['st_size']) > 0):
                symbols.setdefault(int(sym['st_value']), []).append((sym.name, int(sym['st_size'])))
        if len(symbols) != count:
            raise RuntimeError(f'original unique export count differs: {name}')
        for index, va in enumerate(sorted(symbols), 1):
            alias_sizes = sorted(symbols[va], key=lambda item: (-item[1], item[0]))
            symbol, size = alias_sizes[0]
            body, offset = mapped_bytes(elf, source, va, size)
            body_sha = hashlib.sha256(body).hexdigest()
            srow, irow, hrow, frow = (rows[index - 1] for rows in (sources, previous, history, memory))
            identity = (index, f'0x{va:x}', symbol, size)
            if any((r['index'], r['elf_va'], r['symbol'], r['size_bytes']) != identity
                   for r in (srow, irow, hrow, frow)):
                raise RuntimeError(f'original/index/Ghidra VA differs: {name} index {index}')
            if (srow['file_offset'] != f'0x{offset:x}' or irow['file_offset'] != f'0x{offset:x}' or
                srow['aliases'] != [x[0] for x in alias_sizes] or irow['aliases'] != srow['aliases'] or
                srow['source_body_sha256'] != body_sha or irow['source_body_sha256'] != body_sha or
                hrow['expected_source_sha256'] != body_sha or
                hrow['ghidra_memory_sha256'] != body_sha or
                frow['ghidra_memory_sha256'] != body_sha or
                hrow['source_bytes_match'] is not True or frow['source_bytes_match'] is not True or
                frow['function_present'] is not True or
                frow['database_va'] != hrow['database_va'] or
                int(frow['database_va'], 16) != base + va or
                frow['instruction_starts'] != hrow['instruction_count_observed'] or
                hrow['instruction_count_observed'] != len(hrow['instructions'])):
                raise RuntimeError(f'original body/Ghidra memory differs: {name} index {index}')
            c_like = hrow['decompile_success'] is True and bool(hrow['pseudocode'].strip())
            if c_like != srow['historical_c_like_nonempty']:
                raise RuntimeError(f'C-like source index differs: {name} index {index}')
            if not c_like:
                if (name, index) not in KNOWN_GAPS:
                    raise RuntimeError(f'unexpected C-like gap: {name} index {index}')
                gaps.append({'index': index, 'elf_va': f'0x{va:x}', 'symbol': symbol,
                             'source_body_sha256': body_sha, 'historical_error': hrow.get('error', '')})
            else:
                if srow['historical_c_like_sha256'] != hashlib.sha256(hrow['pseudocode'].encode()).hexdigest():
                    raise RuntimeError(f'C-like body hash differs: {name} index {index}')
                totals['historical_c_like_bodies_revalidated'] += 1
            dis = {ins.address: ins for ins in cs.disasm(body, base + va)}
            if len(dis) * 4 != len(body):
                raise RuntimeError(f'original body has undecoded ARM64 bytes: {name} index {index}')
            previous_pc = 0
            for line in hrow['instructions']:
                pc_text, instruction = line.split(': ', 1)
                pc = int(pc_text, 16)
                if pc not in dis or pc <= previous_pc:
                    raise RuntimeError(f'historical instruction address/order differs: {name} index {index}')
                previous_pc = pc
                ghidra_mnemonic = instruction.split()[0].lower()
                capstone_mnemonic = dis[pc].mnemonic.lower()
                if ghidra_mnemonic != capstone_mnemonic:
                    pair = (ghidra_mnemonic, capstone_mnemonic)
                    if pair not in ALIAS_PAIRS:
                        raise RuntimeError(f'unexpected mnemonic disagreement: {name} index {index} {pair}')
                    aliases[f'{pair[0]} -> {pair[1]}'] += 1
                totals['historical_instruction_pcs_cross_checked'] += 1
            for call in hrow['calls']:
                pc_text, target_text = call.split(' -> ', 1)
                instruction = dis.get(int(pc_text, 16))
                if instruction is None or instruction.mnemonic not in {'bl', 'b', 'blr'}:
                    raise RuntimeError(f'historical call PC differs: {name} index {index}')
                if target_text == 'INDIRECT':
                    if instruction.mnemonic != 'blr':
                        raise RuntimeError(f'indirect call type differs: {name} index {index}')
                    totals['indirect_calls_cross_checked'] += 1
                else:
                    target = int(target_text.split(' ', 1)[0], 16)
                    if instruction.mnemonic not in {'bl', 'b'} or target != int(instruction.op_str.lstrip('#'), 0):
                        raise RuntimeError(f'direct branch target differs: {name} index {index}')
                    totals['direct_branch_call_targets_cross_checked'] += 1
            totals['original_pt_load_body_hashes_cross_checked'] += 1
            totals['fresh_ghidra_memory_body_hashes_cross_checked'] += 1
            totals['original_function_bytes_cross_checked'] += size
            row = {'index': index, 'elf_va': f'0x{va:x}', 'symbol': symbol,
                   'source_body_sha256': body_sha, 'fresh_ghidra_memory_sha256': frow['ghidra_memory_sha256'],
                   'historical_c_like_sha256': srow['historical_c_like_sha256'],
                   'historical_instruction_rows': len(hrow['instructions']),
                   'fresh_instruction_starts': frow['instruction_starts']}
            all_rows.append(row)
            if index in sample:
                samples.append({**row, 'original_capstone_decoded_instructions': len(dis),
                                'historical_call_rows': len(hrow['calls'])})
    if totals['original_function_bytes_cross_checked'] != fresh['body_bytes_hashed']:
        raise RuntimeError(f'fresh Ghidra body byte total differs: {name}')
    if len(samples) < math.ceil(.1 * count):
        raise RuntimeError(f'ordinary spread sample below 10%: {name}')
    if len(gaps) != len(batch['precise_c_like_gaps']) or count - len(gaps) != batch['historical_c_like_nonempty']:
        raise RuntimeError(f'historical gap inventory differs: {name}')
    result = {'library': name, 'source_sha256': expected_sha,
              'historical_task': f'TASK_{historical_task(name)}',
              'original_unique_defined_nonzero_dynsym_func_vas': count,
              'fresh_imports': 0, 'fresh_decompilations': 0,
              'all_critical_checks': dict(totals),
              'ghidra_capstone_alias_mnemonics': dict(aliases),
              'precise_c_like_gaps': gaps,
              'ordinary_spread_sample_count': len(samples),
              'ordinary_spread_sample_percent': round(100 * len(samples) / count, 2),
              'ordinary_spread_sample': samples,
              'project_provenance': verify_project(name, project),
              'all_export_evidence_rows': all_rows}
    write_json(folder / 'independent_verification.json', result)
    return {k: v for k, v in result.items() if k not in {'ordinary_spread_sample', 'all_export_evidence_rows'}}


def seal() -> None:
    check_lease()
    if (REPORT / 'COMPLETE.json').exists():
        raise RuntimeError('TASK_177 already sealed; refusing rewrite')
    for task, digest in PRIOR_COMPLETE_SHA.items():
        if sha256(ROOT / f'RULES/REPORT/TASK_{task}_REPORT_R1/COMPLETE.json') != digest:
            raise RuntimeError(f'historical TASK_{task} seal changed')
    meta = task_metadata()
    batch = load(REPORT / 'source_batch_index.json')
    receipt = load(REPORT / 'memory_run_receipt.json')
    projects = load(REPORT / 'project_copy_manifest.json')
    if (batch['standard_sha256'] != STANDARD_SHA or batch['task_sha256'] != TASK_SHA or
        batch['actor'] != AGENT_ID or batch['lease_id'] != LEASE_ID or
        batch['total_original_unique_export_vas'] != 229 or
        batch['total_original_pt_load_bodies_verified'] != 229 or
        batch['total_historical_c_like_nonempty'] != 227 or
        batch['total_precise_c_like_gaps'] != 2 or
        receipt['status'] != 'OUTPUT_READY' or len(receipt['libraries']) != 11):
        raise RuntimeError('batch/receipt summary differs')
    correction = verify_correction()
    results = []
    for (name, pin), b, run in zip(meta['source_libraries'].items(), batch['libraries'], receipt['libraries']):
        if b['library'] != name or run['library'] != name:
            raise RuntimeError('source or run library order differs')
        results.append(verify_one(name, pin, b, run, projects['projects'][name]))
    original = sum(x['all_critical_checks']['original_pt_load_body_hashes_cross_checked'] for x in results)
    c_like = sum(x['all_critical_checks'].get('historical_c_like_bodies_revalidated', 0) for x in results)
    fresh = sum(x['all_critical_checks']['fresh_ghidra_memory_body_hashes_cross_checked'] for x in results)
    instructions = sum(x['all_critical_checks']['historical_instruction_pcs_cross_checked'] for x in results)
    direct = sum(x['all_critical_checks'].get('direct_branch_call_targets_cross_checked', 0) for x in results)
    indirect = sum(x['all_critical_checks'].get('indirect_calls_cross_checked', 0) for x in results)
    sample = sum(x['ordinary_spread_sample_count'] for x in results)
    gaps = [{'library': x['library'], **gap} for x in results for gap in x['precise_c_like_gaps']]
    if (original, c_like, fresh, len(gaps)) != (229, 227, 229, 2) or sample < math.ceil(.1 * 229):
        raise RuntimeError('final 229/227/229/2 coverage or 10% sample differs')
    master = ('# TASK_177 R1 — eleven-SO export gap revalidation\n\n'
              '**Result: PARTIAL static C-like research.** The eleven pinned original SOs contain '
              '229 unique defined nonzero-size `.dynsym` STT_FUNC export VAs. Every original '
              'PT_LOAD body and every copied analyzed Ghidra memory body matched the source hash. '
              'Unaccepted TASK_149/153 historical C-like text was independently revalidated for '
              '227/229 exports. No fresh Ghidra import or decompilation was done.\n\n'
              'The two unresolved C-like exports are `libMTGif.so` index 32, ELF VA `0xa1f0` '
              '(`get_nearest_index`), and index 49, ELF VA `0xaf70` (see precise symbol in '
              '`libMTGif.so/independent_verification.json`). TASK_153 returned `Unable to find '
              'unique hash for varnode`; TASK_154 made a bounded read-only `normalize` attempt '
              'and still returned empty C-like bodies. Its raw command, logs, results and '
              'source assembly are copied into this report with hashes. Reimporting unchanged '
              'source would duplicate prior extraction without a corrective mechanism.\n\n'
              f'Independent ARM64 decoding cross-checked {instructions} historical instruction '
              f'PCs, {direct} direct branch/call targets, and {indirect} indirect call sites against '
              'the original bytes. The deterministic spread sample contains '
              f'{sample}/229 ({100*sample/229:.2f}%) exports, with per-row receipts in each '
              '`independent_verification.json`. The copied Ghidra program database bytes remained '
              'unchanged; only ephemeral project index/journal metadata changed during read-only '
              'sessions, recorded per library.\n\n'
              'Source-byte coverage is 229/229; static assembly address coverage is 229/229; '
              'Ghidra C-like coverage is 227/229; verified behavior coverage is 0/229. This '
              'does not prove all internal functions, functional equivalence, product integration, '
              'Phase PASS or V4 readiness. Independent CEO review remains required.\n')
    atomic_bytes(REPORT / '01_MASTER_REPORT.md', master.encode())
    audit = (REPORT / '00_AUDIT_INDEX.md').read_text(encoding='utf-8')
    audit += ('\nIndependent verification: `01_MASTER_REPORT.md`, each source `source_index.json`, '
              'historical raw command/log/result, fresh read-only Ghidra memory command/log/result, '
              'and `independent_verification.json`. `libMTGif.so/correction_TASK_154_receipt.json` '
              'hashes the prior two-gap correction raw. `COMPLETE.json` seals report/code/scratch.\n')
    atomic_bytes(REPORT / '00_AUDIT_INDEX.md', audit.encode())
    write_json(REPORT / 'PROGRESS.json', {
        'task_id': 'TASK_177', 'revision': 1, 'status': 'SEALED_PARTIAL_CANDIDATE',
        'generated_at': now(), 'original_export_vas': 229,
        'source_pt_load_bodies_verified': 229,
        'fresh_ghidra_memory_bodies_verified': 229,
        'historical_c_like_bodies_revalidated': 227,
        'unresolved_c_like_bodies': gaps,
        'ordinary_spread_sample': sample,
        'fresh_imports': 0, 'fresh_decompilations': 0,
        'disposition': 'AWAITING_INDEPENDENT_CEO_REVIEW'})
    report_files = {p.relative_to(REPORT).as_posix(): sha256(p)
                    for p in sorted(REPORT.rglob('*')) if p.is_file() and
                    p.name not in {'COMPLETE.json', 'PROGRESS.json', 'PROGRESS.md'}}
    code_files = {p.relative_to(ROOT).as_posix(): sha256(p)
                  for p in sorted(SCRIPTS.rglob('*')) if p.is_file() and p.suffix in {'.py', '.java'}}
    scratch_files = {p.relative_to(ROOT).as_posix(): sha256(p)
                     for p in sorted(SCRATCH.rglob('*')) if p.is_file()}
    report_bytes = sum(p.stat().st_size for p in REPORT.rglob('*') if p.is_file())
    if report_bytes > 134_217_728:
        raise RuntimeError('report exceeds 128-MiB task cap')
    manifest = {'schema_version': '2.1.2', 'task_id': 'TASK_177', 'revision': 1,
                'status': 'COMPLETE', 'research_result': 'PARTIAL_C_LIKE_227_OF_229',
                'generated_at': now(), 'agent_id': AGENT_ID, 'lease_id': LEASE_ID,
                'standard_path': str(STANDARD), 'standard_sha256': STANDARD_SHA,
                'task_sha256': TASK_SHA,
                'original_export_vas': 229, 'source_pt_load_bodies_verified': 229,
                'fresh_ghidra_memory_bodies_verified': 229,
                'historical_c_like_bodies_revalidated': 227,
                'unresolved_c_like_bodies': gaps,
                'ordinary_spread_sample_count': sample,
                'fresh_imports': 0, 'fresh_decompilations': 0,
                'files': report_files, 'code_files': code_files,
                'scratch_files': scratch_files,
                'limits': 'static export research only; two MTGif C-like gaps, no behavior parity or product phase claim'}
    write_json(REPORT / 'COMPLETE.json', manifest)
    print(json.dumps({'status': 'SEALED_PARTIAL_CANDIDATE', 'libraries': 11,
                      'original_vas': original, 'historical_c_like': c_like,
                      'fresh_ghidra_memory': fresh, 'instruction_pcs': instructions,
                      'direct_calls': direct, 'indirect_calls': indirect,
                      'spread_sample': sample, 'gaps': [(g['library'], g['index'], g['elf_va']) for g in gaps],
                      'complete_sha256': sha256(REPORT / 'COMPLETE.json')}))


if __name__ == '__main__':
    seal()
