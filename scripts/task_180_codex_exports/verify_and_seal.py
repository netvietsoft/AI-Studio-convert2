"""Independently verify the two source-anchored p-code/fragment experiments."""
from __future__ import annotations

import hashlib
import json
import math
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

from common import (AGENT_ID, LEASE_ID, PRIOR153, PRIOR154, PRIOR177,
                    PRIOR_PROJECT, REPORT, ROOT, SCRATCH, SCRIPTS, SOURCE,
                    SOURCE_SHA, STANDARD, STANDARD_SHA, TASK_SHA, atomic_bytes,
                    check_lease, metadata, now, sha256, write_json)
from prepare import mapped_bytes
from run import FRAGMENTS


def load(path: Path) -> dict:
    return json.loads(path.read_text(encoding='utf-8'))


def sample_indices(count: int) -> set[int]:
    n = math.ceil(.12 * count)
    return {1 + round(i * (count - 1) / (n - 1)) for i in range(n)}


def verify_project_copy(index: int, record: dict) -> dict:
    original = PRIOR_PROJECT
    copied = SCRATCH / f'target_{index}' / 'ghidra_project'
    if record['source_project'] != str(original) or record['project_dir'] != str(copied):
        raise RuntimeError(f'project origin/copy path differs: target {index}')
    same = []
    ephemeral = []
    for row in record['files']:
        relative = row['relative_path']
        src = original / relative
        dst = copied / relative
        if sha256(src) != row['sha256'] or src.stat().st_size != row['bytes']:
            raise RuntimeError(f'original analyzed project changed: target {index} {relative}')
        actual = sha256(dst) if dst.is_file() else None
        if actual == row['sha256']:
            same.append(relative)
        else:
            if not relative.endswith(('/idata/~index.bak', '/idata/~journal.bak')):
                raise RuntimeError(f'copied program DB changed: target {index} {relative}')
            ephemeral.append({'path': relative, 'initial_sha256': row['sha256'],
                              'after_session_sha256': actual})
    if not (any(x.endswith('.gpr') for x in same) and
            any(x.endswith('/00000000.prp') for x in same) and
            any(x.endswith('/db.1.gbf') for x in same)):
        raise RuntimeError(f'copied program content DB not preserved: target {index}')
    return {'initial_byte_identical_project_files': len(record['files']),
            'program_content_files_still_identical': len(same),
            'ephemeral_session_metadata_changes': ephemeral}


def verify_history() -> dict:
    old153 = load(PRIOR153 / 'ghidra_raw.json')
    old154 = load(PRIOR154 / 'ghidra_raw.json')
    recent = load(PRIOR177 / 'independent_verification.json')
    cmd153 = load(PRIOR153 / 'ghidra_command.json')
    cmd154 = load(PRIOR154 / 'ghidra_command.json')
    if (sha256(PRIOR153.parent / 'COMPLETE.json') !=
        'f33a16301c2f4a8782b3771f5cdcfa6a49c99ae52829bc5bc02a0e883801880f' or
        sha256(PRIOR154 / 'COMPLETE.json') !=
        'cc8299662a80d882e5e141b88c9ade9a09b6898e6e44996ea5a8c443505c54fb' or
        cmd153['result_sha256'] != sha256(PRIOR153 / 'ghidra_raw.json') or
        cmd154['result_sha256'] != sha256(PRIOR154 / 'ghidra_raw.json') or
        cmd153['stdout_sha256'] != sha256(PRIOR153 / 'ghidra_stdout.log') or
        cmd153['stderr_sha256'] != sha256(PRIOR153 / 'ghidra_stderr.log') or
        cmd154['stdout_sha256'] != sha256(PRIOR154 / 'ghidra_stdout.log') or
        cmd154['stderr_sha256'] != sha256(PRIOR154 / 'ghidra_stderr.log') or
        len(recent['precise_c_like_gaps']) != 2):
        raise RuntimeError('historical failure command/log/raw seals differ')
    exact = []
    for task_row in metadata()['target_exports']:
        old = [r for r in old153['targets'] if r['elf_va'] == task_row['elf_va']]
        correction = [r for r in old154['targets'] if r['elf_va'] == task_row['elf_va']]
        if len(old) != 1 or len(correction) != 1:
            raise RuntimeError('historical target count differs')
        a, b = old[0], correction[0]
        if (a['expected_source_sha256'] != task_row['source_body_sha256'] or
            b['expected_source_sha256'] != task_row['source_body_sha256'] or
            a['decompile_success'] or a['pseudocode'].strip() or
            b['decompile_success'] or b['pseudocode'].strip() or
            'varnode' not in a['error']):
            raise RuntimeError('historical two-gap failure differs')
        exact.append({'target': task_row, 'TASK_153_raw': a, 'TASK_154_normalize_raw': b})
    result = {'task_id': 'TASK_180', 'previous_whole_original_c_like_recovered': 0,
              'TASK_153_raw_sha256': sha256(PRIOR153 / 'ghidra_raw.json'),
              'TASK_153_command_sha256': sha256(PRIOR153 / 'ghidra_command.json'),
              'TASK_153_stdout_sha256': sha256(PRIOR153 / 'ghidra_stdout.log'),
              'TASK_153_stderr_sha256': sha256(PRIOR153 / 'ghidra_stderr.log'),
              'TASK_154_raw_sha256': sha256(PRIOR154 / 'ghidra_raw.json'),
              'TASK_154_command_sha256': sha256(PRIOR154 / 'ghidra_command.json'),
              'TASK_154_stdout_sha256': sha256(PRIOR154 / 'ghidra_stdout.log'),
              'TASK_154_stderr_sha256': sha256(PRIOR154 / 'ghidra_stderr.log'),
              'TASK_177_verification_sha256': sha256(PRIOR177 / 'independent_verification.json'),
              'exact_failure_rows': exact}
    write_json(REPORT / 'historical_failure_receipt.json', result)
    return result


def verify_target(index: int, target: dict, record: dict, run: dict, elf: ELFFile) -> dict:
    check_lease()
    source_cfg = load(REPORT / f'target_{index}_source_cfg.json')
    folder = REPORT / f'target_{index}'
    command = load(folder / 'ghidra_command.json')
    raw = load(folder / 'ghidra_pcode_fragment_raw.json')
    va = int(target['elf_va'], 16)
    size = target['size_bytes']
    body, offset = mapped_bytes(elf, va, size)
    body_sha = hashlib.sha256(body).hexdigest()
    if body_sha != target['source_body_sha256'] or source_cfg['source_body_sha256'] != body_sha:
        raise RuntimeError(f'original source body hash changed: target {index}')
    if (source_cfg['elf_va'] != target['elf_va'] or
        source_cfg['pt_load_file_offset'] != f'0x{offset:x}' or
        source_cfg['source_bytes'] != size or
        raw['target_index'] != index or raw['elf_va'] != target['elf_va'] or
        raw['ghidra_original_memory_sha256'] != body_sha or
        raw['memory_unchanged_after_rollback'] is not True or
        command['source_sha256'] != SOURCE_SHA or command['source_body_sha256'] != body_sha or
        command['script_sha256'] != sha256(SCRIPTS / 'ExtractPcodeFragment180.java') or
        command['result_sha256'] != sha256(folder / 'ghidra_pcode_fragment_raw.json') or
        command['stdout_sha256'] != sha256(folder / 'ghidra_stdout.log') or
        command['stderr_sha256'] != sha256(folder / 'ghidra_stderr.log') or
        command['status'] != 'OUTPUT_READY' or command['exit_code'] != 0 or
        command['elapsed_seconds'] > 180 or command['cpu_cap'] != 1 or
        command['heap_cap'] != '1G' or '-readOnly' not in command['command'] or
        '-noanalysis' not in command['command'] or '-import' in command['command'] or
        command['command'].count('ExtractPcodeFragment180.java') != 1 or
        command['operation'] != 'ORIGINAL_PCODE_AND_SINGLE_SYNTHETIC_SCALAR_FRAGMENT_NO_IMPORT' or
        run['target_index'] != index or run['status'] != 'OUTPUT_READY' or run['exit_code'] != 0):
        raise RuntimeError(f'Ghidra raw/command/log/source provenance differs: target {index}')
    base = int(raw['database_va'], 16) - va
    if source_cfg['database_va'] != raw['database_va']:
        raise RuntimeError(f'Ghidra image base differs: target {index}')
    cs = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    dis = list(cs.disasm(body, base + va))
    if len(dis) * 4 != size or len(dis) != raw['original_instruction_count']:
        raise RuntimeError(f'original ARM64 decode differs: target {index}')
    by_pc = {ins.address: ins for ins in dis}
    rows = raw['original_instruction_pcode']
    if len(rows) != len(dis) or any(not row['pcode_ops'] for row in rows):
        raise RuntimeError(f'original source-anchored p-code coverage differs: target {index}')
    pcode_count = 0
    for pos, row in enumerate(rows):
        pc = int(row['database_va'], 16)
        ins = by_pc.get(pc)
        if ins is None or pc != dis[pos].address or row['assembly'].split()[0].lower() != ins.mnemonic.lower():
            raise RuntimeError(f'Ghidra p-code PC/mnemonic differs: target {index} index {pos+1}')
        pcode_count += len(row['pcode_ops'])
    if pcode_count != raw['original_pcode_operation_count']:
        raise RuntimeError(f'original p-code operation census differs: target {index}')
    cfg_pcs = []
    for block in source_cfg['blocks']:
        for line in block['raw_assembly']:
            pc = int(line.split(':', 1)[0], 16)
            ins = by_pc.get(pc)
            if ins is None or line.split(':', 1)[1].strip().split()[0].lower() != ins.mnemonic.lower():
                raise RuntimeError(f'original CFG/Capstone instruction differs: target {index}')
            cfg_pcs.append(pc)
        if len(block['raw_assembly']) != block['instruction_count']:
            raise RuntimeError(f'CFG block instruction census differs: target {index}')
    if sorted(cfg_pcs) != sorted(by_pc) or len(set(cfg_pcs)) != len(dis):
        raise RuntimeError(f'CFG blocks do not exactly partition source: target {index}')
    frag = raw['synthetic_fragment']
    start, end = FRAGMENTS[index]
    if (frag['elf_start'] != start or frag['elf_end_inclusive'] != end or
        command['fragment_elf_start'] != start or command['fragment_elf_end_inclusive'] != end or
        frag['function_created'] is not True or frag['decompile_success'] is not True or
        not frag['c_like_fragment_only'].strip() or frag['error'] or
        frag['elapsed_ms'] > 15_000 or
        'task180_scalar_fragment_' not in frag['c_like_fragment_only']):
        raise RuntimeError(f'bounded synthetic fragment result differs: target {index}')
    frag_start, frag_end = int(start, 16), int(end, 16)
    fragment_bytes = body[frag_start-va:frag_end-va+4]
    if len(fragment_bytes) != frag_end - frag_start + 4:
        raise RuntimeError(f'fragment is not an exact original source subset: target {index}')
    sampled = []
    for pos in sorted(sample_indices(len(dis))):
        ins = dis[pos - 1]
        row = rows[pos - 1]
        word = body[(ins.address-base-va):(ins.address-base-va+4)]
        sampled.append({'source_instruction_ordinal': pos, 'database_va': row['database_va'],
                        'source_instruction_word_sha256': hashlib.sha256(word).hexdigest(),
                        'source_mnemonic': ins.mnemonic,
                        'ghidra_pcode_ops': len(row['pcode_ops']),
                        'ghidra_pcode_sha256': hashlib.sha256('\n'.join(row['pcode_ops']).encode()).hexdigest()})
    result = {'task_id': 'TASK_180', 'revision': 1, 'target_index': index,
              'symbol': target['symbol'], 'original_so_sha256': SOURCE_SHA,
              'elf_va': target['elf_va'], 'source_size_bytes': size,
              'pt_load_file_offset': f'0x{offset:x}', 'source_body_sha256': body_sha,
              'fresh_ghidra_original_memory_sha256': raw['ghidra_original_memory_sha256'],
              'original_capstone_instruction_count': len(dis),
              'original_ghidra_pcode_instruction_count': len(rows),
              'original_ghidra_pcode_operation_count': pcode_count,
              'source_cfg_block_count': len(source_cfg['blocks']),
              'fragment_only': {'elf_start': start, 'elf_end_inclusive': end,
                                'source_fragment_bytes': len(fragment_bytes),
                                'source_fragment_sha256': hashlib.sha256(fragment_bytes).hexdigest(),
                                'c_like_fragment_sha256': hashlib.sha256(frag['c_like_fragment_only'].encode()).hexdigest(),
                                'c_like_fragment_chars': len(frag['c_like_fragment_only']),
                                'entry_register_and_stack_context': 'UNKNOWN_FROM_SYNTHETIC_ENTRY',
                                'whole_original_c_like_recovered': False},
              'ordinary_spread_sample_count': len(sampled),
              'ordinary_spread_sample_percent': round(100*len(sampled)/len(dis), 2),
              'ordinary_spread_sample': sampled,
              'copied_project_provenance': verify_project_copy(index, record)}
    write_json(REPORT / f'target_{index}_independent_verification.json', result)
    return {k: v for k, v in result.items() if k != 'ordinary_spread_sample'}


def seal() -> None:
    check_lease()
    if (REPORT / 'COMPLETE.json').exists():
        raise RuntimeError('TASK_180 already sealed; refusing rewrite')
    meta = metadata()
    source_index = load(REPORT / 'source_and_project_index.json')
    run = load(REPORT / 'run_receipt.json')
    if (source_index['standard_sha256'] != STANDARD_SHA or
        source_index['task_sha256'] != TASK_SHA or
        source_index['actor'] != AGENT_ID or source_index['lease_id'] != LEASE_ID or
        source_index['source_sha256'] != SOURCE_SHA or
        source_index['original_unique_export_vas'] != 104 or
        len(source_index['only_target_exports']) != 2 or
        run['status'] != 'OUTPUT_READY' or len(run['targets']) != 2):
        raise RuntimeError('TASK_180 source/run index differs')
    history = verify_history()
    results = []
    with SOURCE.open('rb') as stream:
        elf = ELFFile(stream)
        if elf['e_machine'] != 'EM_AARCH64':
            raise RuntimeError('source architecture differs')
        dynsym = elf.get_section_by_name('.dynsym')
        unique = {int(sym['st_value']) for sym in dynsym.iter_symbols()
                  if sym['st_info']['type'] == 'STT_FUNC' and sym['st_shndx'] != 'SHN_UNDEF'
                  and int(sym['st_value']) > 0 and int(sym['st_size']) > 0}
        if len(unique) != 104:
            raise RuntimeError('original export census differs')
        for index, (target, prior_row, run_row) in enumerate(zip(
                meta['target_exports'], source_index['only_target_exports'], run['targets']), 1):
            if (prior_row['elf_va'] != target['elf_va'] or
                prior_row['source_body_sha256'] != target['source_body_sha256'] or
                int(target['elf_va'], 16) not in unique):
                raise RuntimeError(f'exact target differs: {index}')
            results.append(verify_target(index, target,
                                         source_index['analyzed_project_copies'][str(index)],
                                         run_row, elf))
    instructions = sum(r['original_capstone_instruction_count'] for r in results)
    pcode = sum(r['original_ghidra_pcode_operation_count'] for r in results)
    sampled = sum(r['ordinary_spread_sample_count'] for r in results)
    if instructions != 522 or sampled < math.ceil(.1*instructions):
        raise RuntimeError('522 source instruction or >=10% spread check differs')
    master = ('# TASK_180 R1 — two MTGif decompiler-failure corrections\n\n'
              '**Result: PARTIAL static research.** The pinned original `libMTGif.so` has both '
              'exact exported function bodies at ELF VAs `0xa1f0` and `0xaf70`. Their original '
              'PT_LOAD hashes, copied Ghidra memory hashes, all 522 ARM64 instruction positions '
              f'and {pcode} Ghidra raw p-code operations were checked. The original CFG contains '
              '5 and 18 basic blocks respectively. A deterministic spread sample of '
              f'{sampled}/522 ({100*sampled/522:.2f}%) source instructions records exact word '
              'and p-code hashes. Raw commands, stdout, stderr, Ghidra results and per-target '
              'source CFGs are sealed below.\n\n'
              'A genuinely different bounded technique created one transient **scalar suffix '
              'fragment** per target on separate analyzed-project copies and rolled each '
              'transaction back. Both produced C-like fragment text: `0xa3f0..0xa468` of '
              '`get_nearest_index` and `0xb4b0..0xb518` of `DecreaseBpp2`. These start '
              'inside the original functions, so incoming vector registers, general registers '
              'and stack values are not reconstructed by the synthetic decompiler. The first '
              'fragment shows a minimum/index selection and stack-canary return path; the '
              'second shows cleanup, conditional `pthread_exit`, and canary path. These are '
              'source-anchored **fragments**, not whole-original C-like or validated semantics.\n\n'
              'TASK_153 whole-function decompilation failed with `Unable to find unique hash '
              'for varnode`; TASK_154 `normalize` returned empty C-like for both. This task '
              'did not re-run those methods or reprocess the other 102 MTGif exports. '
              'Whole-original C-like remains **0/2**, source-byte/assembly/p-code position '
              'coverage is **2/2**, and verified behavior is **0/2**. No internal-function '
              'coverage, functional equivalence, product integration, Phase PASS or V4 '
              'readiness is claimed. Independent CEO review remains required.\n')
    atomic_bytes(REPORT / '01_MASTER_REPORT.md', master.encode())
    audit = (REPORT / '00_AUDIT_INDEX.md').read_text(encoding='utf-8')
    audit += ('\nFinal evidence: `historical_failure_receipt.json`, `run_receipt.json`, '
              '`target_{1,2}_source_cfg.json`, `target_{1,2}/ghidra_command.json`, '
              'raw stdout/stderr/p-code/fragment JSON, and '
              '`target_{1,2}_independent_verification.json`. '
              '`COMPLETE.json` byte-hash seals the report, code and owned scratch.\n')
    atomic_bytes(REPORT / '00_AUDIT_INDEX.md', audit.encode())
    write_json(REPORT / 'PROGRESS.json', {'task_id': 'TASK_180', 'revision': 1,
        'status': 'SEALED_PARTIAL_CANDIDATE', 'generated_at': now(),
        'original_target_export_bodies_verified': 2,
        'original_source_instructions_verified': instructions,
        'original_ghidra_pcode_operations': pcode,
        'synthetic_c_like_fragments': 2,
        'whole_original_c_like_recovered': 0,
        'ordinary_spread_instruction_sample': sampled,
        'fresh_imports': 0, 'disposition': 'AWAITING_INDEPENDENT_CEO_REVIEW'})
    files = {p.relative_to(REPORT).as_posix(): sha256(p)
             for p in sorted(REPORT.rglob('*')) if p.is_file() and
             p.name not in {'COMPLETE.json', 'PROGRESS.json', 'PROGRESS.md'}}
    code_files = {p.relative_to(ROOT).as_posix(): sha256(p)
                  for p in sorted(SCRIPTS.rglob('*')) if p.is_file() and p.suffix in {'.py', '.java'}}
    scratch_files = {p.relative_to(ROOT).as_posix(): sha256(p)
                     for p in sorted(SCRATCH.rglob('*')) if p.is_file()}
    report_bytes = sum(p.stat().st_size for p in REPORT.rglob('*') if p.is_file())
    if report_bytes > 134_217_728:
        raise RuntimeError('report exceeds task cap')
    manifest = {'schema_version': '2.1.2', 'task_id': 'TASK_180', 'revision': 1,
                'status': 'COMPLETE', 'research_result': 'PARTIAL_TWO_FRAGMENTS_NO_WHOLE_C_LIKE',
                'generated_at': now(), 'agent_id': AGENT_ID, 'lease_id': LEASE_ID,
                'standard_path': str(STANDARD), 'standard_sha256': STANDARD_SHA,
                'task_sha256': TASK_SHA, 'original_so_sha256': SOURCE_SHA,
                'original_target_bodies_verified': 2,
                'original_source_instruction_positions_verified': instructions,
                'original_pcode_operations': pcode,
                'synthetic_c_like_fragments': 2, 'whole_original_c_like_recovered': 0,
                'ordinary_spread_instruction_sample_count': sampled,
                'fresh_imports': 0, 'files': files,
                'code_files': code_files, 'scratch_files': scratch_files,
                'limits': 'synthetic scalar suffix fragments have unknown entry registers/stack; no whole-function or behavior claim'}
    write_json(REPORT / 'COMPLETE.json', manifest)
    print(json.dumps({'status': 'SEALED_PARTIAL_CANDIDATE', 'original_targets': 2,
                      'source_instructions': instructions, 'original_pcode_ops': pcode,
                      'scalar_c_like_fragments': 2, 'whole_original_c_like': 0,
                      'sampled_instructions': sampled,
                      'complete_sha256': sha256(REPORT / 'COMPLETE.json')}))


if __name__ == '__main__':
    seal()
