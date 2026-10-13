"""Read-only original ELF and failure receipts; construct source CFG and copied projects."""
from __future__ import annotations

import hashlib
import json
import shutil
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

from common import (AGENT_ID, FENCE, LEASE_ID, PRIOR153, PRIOR154, PRIOR177,
                    PRIOR_PROJECT, REPORT, SCRATCH, SOURCE, SOURCE_SHA,
                    STANDARD, STANDARD_SHA, TASK_SHA, atomic_bytes,
                    check_lease, metadata, now, sha256, write_json)


def mapped_bytes(elf: ELFFile, va: int, size: int) -> tuple[bytes, int]:
    for segment in elf.iter_segments():
        if segment['p_type'] != 'PT_LOAD':
            continue
        base, length = int(segment['p_vaddr']), int(segment['p_filesz'])
        if base <= va and va + size <= base + length:
            offset = int(segment['p_offset']) + va - base
            with SOURCE.open('rb') as stream:
                stream.seek(offset)
                body = stream.read(size)
            if len(body) == size:
                return body, offset
    raise RuntimeError(f'no PT_LOAD mapping: 0x{va:x}+{size}')


def cfg(instructions: list, start: int, end: int) -> dict:
    pcs = {ins.address for ins in instructions}
    leaders = {start}
    successors = {}
    for ins in instructions:
        pc = ins.address
        next_pc = pc + 4
        mnemonic = ins.mnemonic
        conditional = mnemonic.startswith(('b.', 'cbz', 'cbnz', 'tbz', 'tbnz'))
        unconditional = mnemonic in {'b', 'br', 'ret'}
        edges = []
        if conditional or mnemonic == 'b':
            target_text = ins.op_str.split(',')[-1].strip().lstrip('#')
            try:
                target = int(target_text, 0)
                edges.append({'kind': 'branch', 'to': f'0x{target:x}',
                              'inside_body': target in pcs})
                if target in pcs:
                    leaders.add(target)
            except ValueError:
                edges.append({'kind': 'indirect_or_unparsed_branch', 'target_text': target_text})
        if conditional:
            edges.append({'kind': 'fallthrough', 'to': f'0x{next_pc:x}',
                          'inside_body': next_pc in pcs})
            if next_pc in pcs:
                leaders.add(next_pc)
        elif not unconditional:
            edges.append({'kind': 'fallthrough', 'to': f'0x{next_pc:x}',
                          'inside_body': next_pc in pcs})
        if conditional or unconditional:
            successors[pc] = edges
            if next_pc in pcs:
                leaders.add(next_pc)
    ordered = sorted(leaders)
    blocks = []
    for i, leader in enumerate(ordered):
        following = ordered[i + 1] if i + 1 < len(ordered) else end
        members = [ins for ins in instructions if leader <= ins.address < following]
        if not members:
            continue
        last = members[-1]
        out = successors.get(last.address)
        if out is None:
            next_pc = last.address + 4
            out = [{'kind': 'fallthrough', 'to': f'0x{next_pc:x}',
                    'inside_body': next_pc in pcs}] if next_pc in pcs else []
        blocks.append({'start': f'0x{leader:x}', 'end_exclusive': f'0x{last.address+4:x}',
                       'instruction_count': len(members),
                       'raw_assembly': [f'0x{x.address:x}: {x.mnemonic} {x.op_str}' for x in members],
                       'out_edges': out})
    if sum(x['instruction_count'] for x in blocks) != len(instructions):
        raise RuntimeError('CFG blocks do not partition source instructions')
    return {'block_count': len(blocks), 'blocks': blocks}


def main() -> None:
    check_lease()
    if REPORT.exists() or SCRATCH.exists():
        raise RuntimeError('TASK_180 output already started')
    meta = metadata()
    if (meta['source_libraries']['libMTGif.so']['sha256'] != SOURCE_SHA or
        meta['source_libraries']['libMTGif.so']['expected_unique_export_vas'] != 104 or
        len(meta['target_exports']) != 2):
        raise RuntimeError('exact active task target census differs')
    old = json.loads((PRIOR153 / 'ghidra_raw.json').read_text(encoding='utf-8'))
    correction = json.loads((PRIOR154 / 'ghidra_raw.json').read_text(encoding='utf-8'))
    recent = json.loads((PRIOR177 / 'independent_verification.json').read_text(encoding='utf-8'))
    if (sha256(PRIOR153.parent / 'COMPLETE.json') !=
        'f33a16301c2f4a8782b3771f5cdcfa6a49c99ae52829bc5bc02a0e883801880f' or
        sha256(PRIOR154 / 'COMPLETE.json') !=
        'cc8299662a80d882e5e141b88c9ade9a09b6898e6e44996ea5a8c443505c54fb' or
        len(recent['precise_c_like_gaps']) != 2 or len(correction['targets']) != 2):
        raise RuntimeError('historical sealed gap evidence differs')
    targets = []
    cs = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    with SOURCE.open('rb') as stream:
        elf = ELFFile(stream)
        dynsym = elf.get_section_by_name('.dynsym')
        unique = {int(sym['st_value']) for sym in dynsym.iter_symbols()
                  if sym['st_info']['type'] == 'STT_FUNC' and sym['st_shndx'] != 'SHN_UNDEF'
                  and int(sym['st_value']) > 0 and int(sym['st_size']) > 0}
        if len(unique) != 104 or elf['e_machine'] != 'EM_AARCH64':
            raise RuntimeError('original SO architecture/export census differs')
        for index, task_row in enumerate(meta['target_exports'], 1):
            va = int(task_row['elf_va'], 16)
            size = task_row['size_bytes']
            body, offset = mapped_bytes(elf, va, size)
            body_sha = hashlib.sha256(body).hexdigest()
            if va not in unique or body_sha != task_row['source_body_sha256']:
                raise RuntimeError(f'original target body identity differs: {index}')
            rows = [x for x in old['targets'] if x['elf_va'] == task_row['elf_va']]
            if len(rows) != 1 or rows[0]['symbol'] != task_row['symbol'] or rows[0]['decompile_success'] or rows[0]['pseudocode'].strip() or 'varnode' not in rows[0]['error']:
                raise RuntimeError(f'TASK_153 failure differs: {index}')
            corr = correction['targets'][index - 1]
            if corr['elf_va'] != task_row['elf_va'] or corr['decompile_success'] or corr['pseudocode'].strip():
                raise RuntimeError(f'TASK_154 normalize failure differs: {index}')
            ghr = recent['all_export_evidence_rows'][old['targets'].index(rows[0])]
            if ghr['source_body_sha256'] != body_sha or ghr['fresh_ghidra_memory_sha256'] != body_sha:
                raise RuntimeError(f'TASK_177 source/fresh memory differs: {index}')
            base = int(old['image_base'], 16)
            dis = list(cs.disasm(body, base + va))
            if len(dis) * 4 != size:
                raise RuntimeError(f'incomplete original AArch64 decode: {index}')
            graph = cfg(dis, base + va, base + va + size)
            write_json(REPORT / f'target_{index}_source_cfg.json', {
                'task_id': 'TASK_180', 'target_index': index, 'symbol': task_row['symbol'],
                'original_so_sha256': SOURCE_SHA, 'elf_va': task_row['elf_va'],
                'database_va': f'0x{base+va:x}', 'pt_load_file_offset': f'0x{offset:x}',
                'source_body_sha256': body_sha, 'source_bytes': size,
                'capstone_instruction_count': len(dis), **graph})
            targets.append({'target_index': index, **task_row, 'pt_load_file_offset': f'0x{offset:x}',
                            'ghidra_database_va': f'0x{base+va:x}',
                            'source_instruction_count': len(dis),
                            'source_cfg_blocks': graph['block_count'],
                            'historical_TASK_153_error': rows[0]['error'],
                            'historical_TASK_154_normalize_empty': True})
    # Two isolated copies prevent transient synthetic-function edits from contaminating the other target.
    project_files = sorted(p for p in PRIOR_PROJECT.rglob('*') if p.is_file())
    if not project_files:
        raise RuntimeError('analyzed Ghidra project missing')
    projects = {}
    for index in (1, 2):
        dest = SCRATCH / f'target_{index}' / 'ghidra_project'
        files = []
        for original in project_files:
            check_lease()
            rel = original.relative_to(PRIOR_PROJECT)
            copy = dest / rel
            copy.parent.mkdir(parents=True, exist_ok=True)
            before = sha256(original)
            shutil.copy2(original, copy)
            if sha256(copy) != before:
                raise RuntimeError(f'Ghidra project copy differs: {rel}')
            files.append({'relative_path': rel.as_posix(), 'sha256': before, 'bytes': copy.stat().st_size})
        projects[str(index)] = {'project_dir': str(dest), 'project_name': next(PRIOR_PROJECT.glob('*.gpr')).stem,
                                'source_project': str(PRIOR_PROJECT), 'files': files}
    write_json(REPORT / 'source_and_project_index.json', {
        'task_id': 'TASK_180', 'revision': 1, 'generated_at': now(),
        'actor': AGENT_ID, 'lease_id': LEASE_ID, 'fencing_token': FENCE,
        'standard_path': str(STANDARD), 'standard_sha256': STANDARD_SHA,
        'task_sha256': TASK_SHA, 'source_path': str(SOURCE), 'source_sha256': SOURCE_SHA,
        'original_unique_export_vas': 104, 'only_target_exports': targets,
        'prior_TASK_153_raw_sha256': sha256(PRIOR153 / 'ghidra_raw.json'),
        'prior_TASK_154_raw_sha256': sha256(PRIOR154 / 'ghidra_raw.json'),
        'prior_TASK_177_verification_sha256': sha256(PRIOR177 / 'independent_verification.json'),
        'analyzed_project_copies': projects})
    write_json(REPORT / 'PROGRESS.json', {
        'task_id': 'TASK_180', 'revision': 1, 'status': 'SOURCE_CFG_AND_COPIED_PROJECT_VERIFIED',
        'generated_at': now(), 'only_targets': 2, 'original_pt_load_bodies_verified': 2,
        'capstone_source_instructions': sum(r['source_instruction_count'] for r in targets),
        'fresh_ghidra_imports': 0, 'fresh_whole_function_c_like': 0})
    audit = ('# TASK_180 R1 audit index\n\n'
             f'Canonical standard fully re-read: `{STANDARD}` SHA-256 `{STANDARD_SHA}`.\n\n'
             f'Task SHA-256 `{TASK_SHA}`; actor `{AGENT_ID}`; lease `{LEASE_ID}`; fence `{FENCE}`.\n\n'
             'Only two pinned `libMTGif.so` exports are in scope. Original source, previous '
             'TASK_153/154/177 failures and analyzed project remain read-only. Full original '
             'PT_LOAD bytes, Capstone instruction coverage, CFG and copied-project hashes are '
             'in `source_and_project_index.json` and `target_*_source_cfg.json`.\n')
    atomic_bytes(REPORT / '00_AUDIT_INDEX.md', audit.encode())
    print(json.dumps({'only_targets': 2, 'source_instructions': sum(r['source_instruction_count'] for r in targets),
                      'source_cfg_blocks': sum(r['source_cfg_blocks'] for r in targets),
                      'copied_project_files': sum(len(p['files']) for p in projects.values())}))


if __name__ == '__main__':
    main()
