"""Verify 117 pinned nonexport FDE/PT_LOAD bodies and copy analyzed project once."""
from __future__ import annotations

import hashlib
import json
import shutil
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile

from common import (AGENT_ID, FENCE, LEASE_ID, PROJECT, REPORT, SCRATCH,
                    SOURCE, SOURCE_SHA, STANDARD, STANDARD_SHA, TARGETS,
                    TARGETS_SHA, TASK_SHA, atomic_bytes, check_lease, now,
                    sha256, task_metadata, write_json)


def main() -> None:
    check_lease()
    if SCRATCH.exists():
        raise RuntimeError('TASK_188 project copy already started')
    if REPORT.exists() and any(p.is_file() and p.parent != REPORT / 'source_assembly'
                               for p in REPORT.rglob('*')):
        raise RuntimeError('TASK_188 report has non-preflight output')
    task = task_metadata()
    manifest = json.loads(TARGETS.read_text(encoding='utf-8'))
    if (task['target_candidate_count'] != 117 or task['target_manifest_sha256'] != TARGETS_SHA
            or manifest['selected_count'] != 117 or len(manifest['targets']) != 117
            or manifest['source_sha256'] != SOURCE_SHA):
        raise RuntimeError('target manifest/task census differs')
    cs = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    rows = []
    with SOURCE.open('rb') as stream:
        elf = ELFFile(stream)
        if elf['e_machine'] != 'EM_AARCH64':
            raise RuntimeError('source is not AArch64')
        fdes = [(int(x['initial_location']), int(x['address_range']))
                for x in elf.get_dwarf_info().EH_CFI_entries() if isinstance(x, FDE)]
        if len(fdes) != 147:
            raise RuntimeError(f'original unwind FDE census differs: {len(fdes)}')
        dyn = elf.get_section_by_name('.dynsym')
        exported = {(int(x['st_value']), int(x['st_size'])) for x in dyn.iter_symbols()
                    if x['st_info']['type'] == 'STT_FUNC' and x['st_shndx'] != 'SHN_UNDEF'
                    and int(x['st_value']) > 0 and int(x['st_size']) > 0}
        starts = {va for va, _ in exported}
        if len(starts) != 30:
            raise RuntimeError('original defined export VA census differs')
        nonexports = sorted(x for x in fdes if x[0] not in starts)
        targets = [(int(t['elf_va'], 16), int(t['size_bytes'])) for t in manifest['targets']]
        if len(nonexports) != 117 or nonexports != targets:
            raise RuntimeError('exact 117 nonexport FDE selection differs')
        segments = [(int(s['p_vaddr']), int(s['p_filesz']), int(s['p_offset']))
                    for s in elf.iter_segments() if s['p_type'] == 'PT_LOAD']
        for index, target in enumerate(manifest['targets'], 1):
            check_lease()
            va, size = targets[index - 1]
            if size <= 0 or size > 4096 or size % 4 or va % 4:
                raise RuntimeError(f'bad candidate range #{index}')
            mappings = [off + va - base for base, length, off in segments
                        if base <= va and va + size <= base + length]
            if len(mappings) != 1:
                raise RuntimeError(f'ambiguous PT_LOAD candidate #{index}')
            file_offset = mappings[0]
            stream.seek(file_offset)
            body = stream.read(size)
            digest = hashlib.sha256(body).hexdigest()
            if (len(body) != size or digest != target['body_sha256']
                    or file_offset != int(target['file_offset'], 16)
                    or target['instruction_slots'] != size // 4):
                raise RuntimeError(f'original source target #{index} differs')
            instructions = []
            for offset in range(0, size, 4):
                word = body[offset:offset+4]
                decoded = list(cs.disasm(word, va+offset, count=1))
                instructions.append({'elf_va': f'0x{va+offset:x}', 'word_hex': word.hex(),
                                     'assembly': f'{decoded[0].mnemonic} {decoded[0].op_str}'.strip()
                                     if decoded and decoded[0].size == 4 else None})
            fde_overlaps = [(x, y) for x, y in fdes if x != va and x < va+size and va < x+y]
            export_overlaps = [(x, y) for x, y in exported if x < va+size and va < x+y]
            row = {'index': index, 'elf_va': target['elf_va'], 'size_bytes': size,
                   'end_exclusive': f'0x{va+size:x}', 'file_offset': target['file_offset'],
                   'source_body_sha256': digest, 'instruction_slots': len(instructions),
                   'capstone_decoded_slots': sum(x['assembly'] is not None for x in instructions),
                   'fde_exact_match': True,
                   'other_fde_overlap': [(f'0x{x:x}', y) for x, y in fde_overlaps],
                   'export_body_overlap': [(f'0x{x:x}', y) for x, y in export_overlaps]}
            write_json(REPORT / 'source_assembly' / f'{index:03d}_{va:x}.json',
                       {**row, 'instructions': instructions})
            rows.append(row)
    old_manifest = json.loads((SOURCE.parents[4] / 'CONVERT2/RULES/REPORT/TASK_177_REPORT_R1/project_copy_manifest.json').read_text(encoding='utf-8'))['projects']['libMTLReportTool.so']
    if Path(old_manifest['original_project_path']) != PROJECT or old_manifest['project_name'] != 'SmallLib153':
        raise RuntimeError('TASK_177 recorded original project differs')
    project_files = sorted(p for p in PROJECT.rglob('*') if p.is_file())
    if not project_files or len(list(PROJECT.glob('*.gpr'))) != 1:
        raise RuntimeError('prior analyzed project unavailable')
    listed = {x['relative_path']: x['source_sha256'] for x in old_manifest['files']}
    if {p.relative_to(PROJECT).as_posix() for p in project_files} != set(listed):
        raise RuntimeError('prior analyzed project file inventory differs')
    copied = []
    destination = SCRATCH / 'ghidra_project'
    for source_file in project_files:
        check_lease()
        relative = source_file.relative_to(PROJECT)
        target_file = destination / relative
        target_file.parent.mkdir(parents=True, exist_ok=True)
        before = sha256(source_file)
        if before != listed[relative.as_posix()]:
            raise RuntimeError(f'TASK_177 recorded original project file differs {relative}')
        shutil.copy2(source_file, target_file)
        if sha256(target_file) != before:
            raise RuntimeError(f'project copy hash mismatch {relative}')
        copied.append({'relative_path': relative.as_posix(), 'sha256': before,
                       'bytes': target_file.stat().st_size})
    batch_files = {}
    for batch_index, selection in enumerate((rows[:60], rows[60:]), 1):
        tsv = ''.join(f"{r['index']}\t{r['elf_va']}\t{r['size_bytes']}\t{r['source_body_sha256']}\n"
                      for r in selection)
        path = SCRATCH / f'target_batch_{batch_index}.tsv'
        atomic_bytes(path, tsv.encode('ascii'))
        batch_files[str(batch_index)] = {'path': str(path), 'sha256': sha256(path),
                                         'count': len(selection)}
    write_json(REPORT / 'source_project_index.json', {
        'task_id': 'TASK_188', 'revision': 1, 'generated_at': now(),
        'actor': AGENT_ID, 'lease_id': LEASE_ID, 'fencing_token': FENCE,
        'standard_path': str(STANDARD), 'standard_sha256': STANDARD_SHA,
        'task_sha256': TASK_SHA, 'target_manifest_sha256': TARGETS_SHA,
        'source_path': str(SOURCE), 'source_sha256': SOURCE_SHA,
        'source_bytes': SOURCE.stat().st_size, 'all_fde_count': len(fdes),
        'defined_nonzero_export_vas': len(starts), 'all_nonexport_fde_candidates': len(nonexports),
        'selected_candidate_rows': rows, 'project_source': str(PROJECT),
        'project_copy': str(destination), 'project_name': next(PROJECT.glob('*.gpr')).stem,
        'project_files': copied, 'batch_files': batch_files})
    write_json(REPORT / 'PROGRESS.json', {'task_id': 'TASK_188', 'revision': 1,
               'status': 'ORIGINAL_FDE_PT_LOAD_AND_PROJECT_COPY_VERIFIED', 'generated_at': now(),
               'original_candidate_bodies_verified': len(rows),
               'source_instruction_slots': sum(r['instruction_slots'] for r in rows),
               'source_decoded_slots': sum(r['capstone_decoded_slots'] for r in rows),
               'new_imports': 0, 'ghidra_candidates_processed': 0})
    atomic_bytes(REPORT / '00_AUDIT_INDEX.md', (
        '# TASK_188 R1 audit index\n\n'
        f'Canonical Standard fully read: `{STANDARD}`; SHA-256 `{STANDARD_SHA}`.\n\n'
        f'Task SHA-256 `{TASK_SHA}`; exact target manifest SHA-256 `{TARGETS_SHA}`. '
        f'Worker `{AGENT_ID}`; lease `{LEASE_ID}`; fencing token `{FENCE}`.\n\n'
        'Each of 117 selected nonexport unwind FDE candidate ranges is pinned to original '
        '`libMTLReportTool.so` PT_LOAD bytes. The candidate label does not prove unique '
        'function boundaries or an internal census. `source_project_index.json` records '
        'all source bodies, overlap metadata and byte-verified analyzed-project copy. '
        '`source_assembly/` contains original instruction words and bounded Capstone decoding.\n').encode())
    print(json.dumps({'bodies': len(rows), 'instruction_slots': sum(r['instruction_slots'] for r in rows),
                      'source_decoded_slots': sum(r['capstone_decoded_slots'] for r in rows),
                      'project_files': len(copied), 'overlap_fde': sum(bool(r['other_fde_overlap']) for r in rows),
                      'overlap_export_body': sum(bool(r['export_body_overlap']) for r in rows)}))


if __name__ == '__main__':
    main()
