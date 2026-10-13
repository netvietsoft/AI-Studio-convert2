"""Verify every pinned ELF/FDE body, decode original ARM64, copy prior analyzed project."""
from __future__ import annotations

import hashlib
import json
import shutil

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile

from common import (AGENT_ID, FENCE, LEASE_ID, PROJECT, REPORT, SCRATCH,
                    SOURCE, SOURCE_SHA, STANDARD, STANDARD_SHA, TARGETS,
                    TARGETS_SHA, TASK_SHA, atomic_bytes, check_lease, now,
                    sha256, task_metadata, write_json)


def main() -> None:
    check_lease()
    if REPORT.exists() or SCRATCH.exists():
        raise RuntimeError('TASK_183 output already started')
    task = task_metadata()
    manifest = json.loads(TARGETS.read_text(encoding='utf-8'))
    if (task['target_candidate_count'] != 51 or task['target_manifest_sha256'] != TARGETS_SHA
            or manifest['selected_count'] != 51 or len(manifest['targets']) != 51
            or manifest['source_sha256'] != SOURCE_SHA):
        raise RuntimeError('target manifest/task census differs')
    cs = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    rows = []
    with SOURCE.open('rb') as stream:
        elf = ELFFile(stream)
        if elf['e_machine'] != 'EM_AARCH64':
            raise RuntimeError('source is not AArch64')
        fde = [(int(entry['initial_location']), int(entry['address_range']))
               for entry in elf.get_dwarf_info().EH_CFI_entries() if isinstance(entry, FDE)]
        if len(fde) != 155:
            raise RuntimeError(f'original unwind FDE census differs: {len(fde)}')
        dyn = elf.get_section_by_name('.dynsym')
        exported = {(int(s['st_value']), int(s['st_size'])) for s in dyn.iter_symbols()
                    if s['st_info']['type'] == 'STT_FUNC' and s['st_shndx'] != 'SHN_UNDEF'
                    and int(s['st_value']) > 0 and int(s['st_size']) > 0}
        starts = {va for va, _ in exported}
        if len(starts) != 104:
            raise RuntimeError('original defined export VA census differs')
        nonexports = sorted(x for x in fde if x[0] not in starts)
        targets = [(int(t['elf_va'], 16), int(t['size_bytes'])) for t in manifest['targets']]
        if nonexports != targets:
            raise RuntimeError('exact FDE nonexport selection differs')
        segments = [(int(s['p_vaddr']), int(s['p_filesz']), int(s['p_offset']))
                    for s in elf.iter_segments() if s['p_type'] == 'PT_LOAD']
        for index, target in enumerate(manifest['targets'], 1):
            check_lease()
            va, size = targets[index - 1]
            if size <= 0 or size > 4096 or size % 4 or va % 4:
                raise RuntimeError(f'bad candidate range #{index}')
            mappings = [(off + va - base, base) for base, length, off in segments
                        if base <= va and va + size <= base + length]
            if len(mappings) != 1:
                raise RuntimeError(f'ambiguous PT_LOAD candidate #{index}')
            file_offset, _ = mappings[0]
            stream.seek(file_offset)
            body = stream.read(size)
            digest = hashlib.sha256(body).hexdigest()
            if (len(body) != size or digest != target['body_sha256']
                    or file_offset != int(target['file_offset'], 16)
                    or target['instruction_slots'] != size // 4):
                raise RuntimeError(f'original source target #{index} differs')
            instructions = list(cs.disasm(body, va))
            if len(instructions) != size // 4 or any(ins.size != 4 for ins in instructions):
                raise RuntimeError(f'incomplete original AArch64 decode #{index}')
            with_file = [(x, y) for x, y in fde if x != va and x < va + size and va < x + y]
            export_overlaps = [(x, y) for x, y in exported if x < va + size and va < x + y]
            row = {'index': index, 'elf_va': target['elf_va'], 'size_bytes': size,
                   'end_exclusive': f'0x{va+size:x}', 'file_offset': target['file_offset'],
                   'source_body_sha256': digest, 'instruction_count': len(instructions),
                   'fde_exact_match': True, 'other_fde_overlap': [(f'0x{x:x}', y) for x, y in with_file],
                   'export_body_overlap': [(f'0x{x:x}', y) for x, y in export_overlaps],
                   'first_word_hex': body[:4].hex(), 'last_word_hex': body[-4:].hex()}
            write_json(REPORT / 'source_assembly' / f'{index:02d}_{va:x}.json',
                       {**row, 'instructions': [
                           {'elf_va': f'0x{i.address:x}', 'word_hex': bytes(i.bytes).hex(),
                            'assembly': f'{i.mnemonic} {i.op_str}'.strip()}
                           for i in instructions]})
            rows.append(row)
    project_files = sorted(p for p in PROJECT.rglob('*') if p.is_file())
    if not project_files or len(list(PROJECT.glob('*.gpr'))) != 1:
        raise RuntimeError('prior analyzed project unavailable')
    copied = []
    destination = SCRATCH / 'ghidra_project'
    for source_file in project_files:
        check_lease()
        relative = source_file.relative_to(PROJECT)
        target_file = destination / relative
        target_file.parent.mkdir(parents=True, exist_ok=True)
        before = sha256(source_file)
        shutil.copy2(source_file, target_file)
        if sha256(target_file) != before:
            raise RuntimeError(f'project copy hash mismatch {relative}')
        copied.append({'relative_path': relative.as_posix(), 'sha256': before,
                       'bytes': target_file.stat().st_size})
    tsv = ''.join(f"{r['index']}\t{r['elf_va']}\t{r['size_bytes']}\t{r['source_body_sha256']}\n"
                  for r in rows)
    atomic_bytes(SCRATCH / 'target_batch.tsv', tsv.encode('ascii'))
    write_json(REPORT / 'source_project_index.json', {
        'task_id': 'TASK_183', 'revision': 1, 'generated_at': now(),
        'actor': AGENT_ID, 'lease_id': LEASE_ID, 'fencing_token': FENCE,
        'standard_path': str(STANDARD), 'standard_sha256': STANDARD_SHA,
        'task_sha256': TASK_SHA, 'target_manifest_sha256': TARGETS_SHA,
        'source_path': str(SOURCE), 'source_sha256': SOURCE_SHA,
        'source_bytes': SOURCE.stat().st_size, 'all_fde_count': len(fde),
        'defined_nonzero_export_vas': len(starts), 'nonexport_fde_candidates': len(rows),
        'rows': rows, 'project_source': str(PROJECT), 'project_copy': str(destination),
        'project_name': next(PROJECT.glob('*.gpr')).stem, 'project_files': copied,
        'target_tsv_sha256': sha256(SCRATCH / 'target_batch.tsv')})
    write_json(REPORT / 'PROGRESS.json', {'task_id': 'TASK_183', 'revision': 1,
               'status': 'ORIGINAL_FDE_PT_LOAD_AND_PROJECT_COPY_VERIFIED', 'generated_at': now(),
               'original_candidate_bodies_verified': len(rows),
               'original_aarch64_instructions_decoded': sum(r['instruction_count'] for r in rows),
               'new_imports': 0, 'ghidra_candidates_processed': 0})
    atomic_bytes(REPORT / '00_AUDIT_INDEX.md', (
        '# TASK_183 R1 audit index\n\n'
        f'Canonical Standard fully read: `{STANDARD}`; SHA-256 `{STANDARD_SHA}`.\n\n'
        f'Task SHA-256 `{TASK_SHA}`; exact target manifest SHA-256 `{TARGETS_SHA}`. '
        f'Worker `{AGENT_ID}`; lease `{LEASE_ID}`; fencing token `{FENCE}`.\n\n'
        'Each of 51 selected nonexport unwind FDE candidate ranges is pinned to original '
        '`libMTGif.so` PT_LOAD bytes and completely decoded as AArch64 instructions. '
        'The candidate label does not prove exact function boundaries or a full internal census. '
        '`source_project_index.json` records every source body, overlap and verified analyzed-project copy. '
        '`source_assembly/` contains per-candidate original instruction words and assembly.\n').encode())
    print(json.dumps({'bodies': len(rows), 'instructions': sum(r['instruction_count'] for r in rows),
                      'project_files': len(copied), 'overlap_fde': sum(bool(r['other_fde_overlap']) for r in rows),
                      'overlap_export_body': sum(bool(r['export_body_overlap']) for r in rows)}))


if __name__ == '__main__':
    main()
