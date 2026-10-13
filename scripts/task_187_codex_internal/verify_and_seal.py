"""Independently verify 128 FDE bodies, every body byte, p-code positions and 12% spread."""
from __future__ import annotations

import hashlib
import json
import math

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile

from common import (AGENT_ID, FENCE, LEASE_ID, PROJECT, REPORT, ROOT, SCRATCH,
                    SCRIPTS, SOURCE, SOURCE_SHA, STANDARD, STANDARD_SHA, TARGETS,
                    TARGETS_SHA, TASK_SHA, atomic_bytes, check_lease, now,
                    sha256, write_json)

ALIASES = {('b.hs', 'b.cs'), ('b.lo', 'b.cc'), ('mov', 'orr')}
CORRECTIONS = (18, 23, 30, 43, 85, 128)
EXPECTED_INSTRUCTION_SLOTS = 14865


def load(path):
    return json.loads(path.read_text(encoding='utf-8'))


def sample_ordinals(count: int) -> list[int]:
    n = max(1, math.ceil(.12 * count))
    if n == 1:
        return [(count - 1) // 2]
    return sorted({round(i * (count - 1) / (n - 1)) for i in range(n)})


def gap_ranges(bits: str) -> list[dict]:
    gaps = []
    start = None
    for offset, bit in enumerate(bits):
        if bit == '0' and start is None:
            start = offset
        elif bit == '1' and start is not None:
            gaps.append({'start_offset': start, 'end_exclusive': offset})
            start = None
    if start is not None:
        gaps.append({'start_offset': start, 'end_exclusive': len(bits)})
    return gaps


def verify_command(batch: int, expected_count: int) -> dict:
    prefix = f'ghidra_batch{batch}'
    cmd = load(REPORT / f'{prefix}_command.json')
    if (cmd['task_id'] != 'TASK_187' or cmd['revision'] != 1 or cmd['batch'] != batch or
            cmd['status'] != 'OUTPUT_READY' or cmd['exit_code'] != 0 or
            cmd['script_sha256'] != sha256(SCRIPTS / 'ExtractInternal187.java') or
            cmd['target_tsv_sha256'] != sha256(SCRATCH / f'target_batch_{batch}.tsv') or
            cmd['stdout_sha256'] != sha256(REPORT / f'{prefix}_stdout.log') or
            cmd['stderr_sha256'] != sha256(REPORT / f'{prefix}_stderr.log') or
            cmd['elapsed_seconds'] > 1200 or cmd['max_cpu'] != 1 or cmd['max_heap'] != '1G' or
            cmd['max_decompile_seconds_per_candidate'] != 10 or
            '-noanalysis' not in cmd['command'] or '-readOnly' not in cmd['command'] or
            '-import' in cmd['command'] or cmd['command'].count('ExtractInternal187.java') != 1 or
            cmd['raw_result_files'] != expected_count or len(cmd['raw_result_hashes']) != expected_count or
            cmd['project_copy'] != str(SCRATCH / 'ghidra_project')):
        raise RuntimeError(f'Ghidra batch {batch} command/log/source provenance differs')
    for name, digest in cmd['raw_result_hashes'].items():
        if sha256(REPORT / f'ghidra_raw_batch{batch}' / name) != digest:
            raise RuntimeError(f'Ghidra batch {batch} result hash differs: {name}')
    return cmd


def verify_correction() -> dict:
    cmd = load(REPORT / 'ghidra_correction_command.json')
    if (cmd['task_id'] != 'TASK_187' or cmd['revision'] != 1 or
            cmd['target_indices'] != list(CORRECTIONS) or cmd['status'] != 'OUTPUT_READY' or
            cmd['exit_code'] != 0 or cmd['raw_result_files'] != 6 or
            len(cmd['raw_result_hashes']) != 6 or
            cmd['script_sha256'] != sha256(SCRIPTS / 'RepairMembership187.java') or
            cmd['target_tsv_sha256'] != sha256(SCRATCH / 'correction_targets.tsv') or
            cmd['stdout_sha256'] != sha256(REPORT / 'ghidra_correction_stdout.log') or
            cmd['stderr_sha256'] != sha256(REPORT / 'ghidra_correction_stderr.log') or
            cmd['elapsed_seconds'] > 1200 or cmd['max_cpu'] != 1 or cmd['max_heap'] != '1G' or
            cmd['max_decompile_seconds_per_candidate'] != 10 or
            '-noanalysis' not in cmd['command'] or '-readOnly' not in cmd['command'] or
            '-import' in cmd['command'] or cmd['command'].count('RepairMembership187.java') != 1):
        raise RuntimeError('six-candidate correction command/log provenance differs')
    for name, digest in cmd['raw_result_hashes'].items():
        if sha256(REPORT / 'ghidra_correction_raw' / name) != digest:
            raise RuntimeError(f'correction result hash differs: {name}')
    return cmd


def verify_project(index: dict) -> dict:
    copied = SCRATCH / 'ghidra_project'
    if index['project_source'] != str(PROJECT) or index['project_copy'] != str(copied):
        raise RuntimeError('project origin/copy path differs')
    identical = 0
    ephemeral = []
    for row in index['project_files']:
        relative = row['relative_path']
        src = PROJECT / relative
        dst = copied / relative
        if not src.is_file() or src.stat().st_size != row['bytes'] or sha256(src) != row['sha256']:
            raise RuntimeError(f'original analyzed project changed: {relative}')
        actual = sha256(dst) if dst.is_file() else None
        if actual == row['sha256']:
            identical += 1
        elif relative.endswith(('/idata/~index.bak', '/idata/~journal.bak')):
            ephemeral.append({'path': relative, 'initial_sha256': row['sha256'],
                              'after_session_sha256': actual})
        else:
            raise RuntimeError(f'copied content DB changed: {relative}')
    if identical < len(index['project_files']) - 2:
        raise RuntimeError('too many copied project file changes')
    return {'original_project_files_byte_verified': len(index['project_files']),
            'copied_project_files_still_identical': identical,
            'ephemeral_session_metadata_changes': ephemeral}


def main() -> None:
    check_lease()
    if (REPORT / 'COMPLETE.json').exists():
        raise RuntimeError('already sealed; refusing rewrite')
    manifest = load(TARGETS)
    index = load(REPORT / 'source_project_index.json')
    if (len(manifest['targets']) != 128 or len(index['selected_candidate_rows']) != 128 or
            index['task_sha256'] != TASK_SHA or index['target_manifest_sha256'] != TARGETS_SHA or
            index['standard_sha256'] != STANDARD_SHA or index['actor'] != AGENT_ID or
            index['lease_id'] != LEASE_ID or index['fencing_token'] != FENCE or
            index['source_sha256'] != SOURCE_SHA or sha256(SOURCE) != SOURCE_SHA or
            index['all_fde_count'] != 2873 or index['all_nonexport_fde_candidates'] != 511 or
            index['defined_nonzero_export_vas'] != 2362 or
            index['batch_files']['1']['sha256'] != sha256(SCRATCH / 'target_batch_1.tsv') or
            index['batch_files']['2']['sha256'] != sha256(SCRATCH / 'target_batch_2.tsv')):
        raise RuntimeError('pinned source/project/task metadata differs')
    batch_commands = [verify_command(1, 64), verify_command(2, 64)]
    correction_command = verify_correction()
    project_provenance = verify_project(index)
    corrections = {load(p)['index']: load(p)
                   for p in (REPORT / 'ghidra_correction_raw').glob('*.json')}
    if set(corrections) != set(CORRECTIONS):
        raise RuntimeError('six correction results differ')
    cs = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    results = []
    spread = []
    source_slots = 0
    effective_pcode_slots = 0
    effective_pcode_ops = 0
    original_membership_full = 0
    corrected_membership_full = 0
    original_missing_slots = 0
    nonempty_c_like = 0
    with SOURCE.open('rb') as stream:
        elf = ELFFile(stream)
        if elf['e_machine'] != 'EM_AARCH64':
            raise RuntimeError('original ELF architecture changed')
        fdes = [(int(x['initial_location']), int(x['address_range']))
                for x in elf.get_dwarf_info().EH_CFI_entries() if isinstance(x, FDE)]
        if len(fdes) != 2873:
            raise RuntimeError('original FDE census changed')
        dyn = elf.get_section_by_name('.dynsym')
        exports = {(int(x['st_value']), int(x['st_size'])) for x in dyn.iter_symbols()
                   if x['st_info']['type'] == 'STT_FUNC' and x['st_shndx'] != 'SHN_UNDEF'
                   and int(x['st_value']) > 0 and int(x['st_size']) > 0}
        starts = {va for va, _ in exports}
        if len(starts) != 2362:
            raise RuntimeError('original export starts changed')
        nonexports = sorted(x for x in fdes if x[0] not in starts)
        pinned = [(int(x['elf_va'], 16), x['size_bytes']) for x in manifest['targets']]
        if len(nonexports) != 511 or pinned != nonexports[:128]:
            raise RuntimeError('exact first 128 candidate selection changed')
        segments = [(int(s['p_vaddr']), int(s['p_filesz']), int(s['p_offset']))
                    for s in elf.iter_segments() if s['p_type'] == 'PT_LOAD']
        for position, target in enumerate(manifest['targets'], 1):
            check_lease()
            va, size = pinned[position - 1]
            offsets = [off + va - base for base, length, off in segments
                       if base <= va and va + size <= base + length]
            if len(offsets) != 1 or offsets[0] != int(target['file_offset'], 16):
                raise RuntimeError(f'candidate #{position} PT_LOAD mapping changed')
            stream.seek(offsets[0])
            body = stream.read(size)
            digest = hashlib.sha256(body).hexdigest()
            if len(body) != size or digest != target['body_sha256']:
                raise RuntimeError(f'candidate #{position} original body hash changed')
            source = load(REPORT / 'source_assembly' / f'{position:03d}_{va:x}.json')
            batch = 1 if position <= 64 else 2
            raw_path = REPORT / f'ghidra_raw_batch{batch}' / f'{position:03d}_{va:x}.json'
            raw = load(raw_path)
            if (source['index'] != position or source['source_body_sha256'] != digest or
                    source['fde_exact_match'] is not True or source['other_fde_overlap'] or
                    source['export_body_overlap'] or source['instruction_slots'] != size // 4 or
                    source['capstone_decoded_slots'] != size // 4 or
                    raw['index'] != position or raw['elf_va'] != target['elf_va'] or
                    raw['size_bytes'] != size or raw['ghidra_memory_sha256'] != digest or
                    raw['instruction_slots'] != size // 4 or
                    raw['decompile_elapsed_ms'] > 10_000 or
                    not raw['c_like_nonempty'] or not raw['c_like_text'].strip() or
                    raw['decompile_error'] or not raw['existing_exact_function_start'] or
                    raw['existing_function_contains_nonstart'] or
                    raw['temporary_function_created_and_rolled_back'] or
                    raw['other_function_byte_count'] != 0 or
                    len(source['instructions']) != size // 4 or
                    len(raw['instruction_pcode']) != size // 4):
                raise RuntimeError(f'candidate #{position} source/Ghidra raw differs')
            bits = raw['fde_byte_membership_bits']
            if (len(bits) != size or set(bits) - {'0', '1'} or
                    bits.count('1') != raw['fde_byte_membership_count'] or
                    raw['fde_missing_body_ranges'] != gap_ranges(bits) or
                    raw['fde_byte_membership_transitions'] != sum(
                        bits[n] != bits[n-1] for n in range(1, len(bits))) or
                    raw['function_body_total_address_count'] != bits.count('1') or
                    int(raw['function_start'], 16) != int(raw['database_va'], 16)):
                raise RuntimeError(f'candidate #{position} per-byte function-body membership differs')
            old_missing = raw['missing_analyzed_instruction_count']
            original_missing_slots += old_missing
            if bits.count('1') == size:
                original_membership_full += 1
            if position in CORRECTIONS:
                corrected = corrections[position]
                cbits = corrected['corrected_function_fde_membership_bits']
                if (old_missing <= 0 or bits.count('1') >= size or
                        corrected['elf_va'] != target['elf_va'] or
                        corrected['size_bytes'] != size or
                        corrected['memory_sha256'] != digest or
                        corrected['memory_unchanged_after_rollback'] is not True or
                        corrected['original_function_fde_membership_bits'] != bits or
                        corrected['original_function_fde_membership_count'] != bits.count('1') or
                        corrected['other_function_byte_count'] != 0 or
                        corrected['temporary_old_function_removed'] is not True or
                        corrected['temporary_full_fde_function_created'] is not True or
                        cbits != '1' * size or corrected['corrected_function_fde_membership_count'] != size or
                        corrected['corrected_function_body_total_address_count'] != size or
                        corrected['full_fde_instruction_count'] != size // 4 or
                        len(corrected['instruction_pcode']) != size // 4 or
                        corrected['decompile_elapsed_ms'] > 10_000 or
                        not corrected['c_like_nonempty'] or not corrected['c_like_text'].strip() or
                        corrected['error']):
                    raise RuntimeError(f'candidate #{position} exact corrected full-FDE result differs')
                ghidra_rows = corrected['instruction_pcode']
                c_text = corrected['c_like_text']
                corrected_membership_full += 1
                classification = 'ORIGINAL_GHIDRA_BODY_PARTIAL_OR_DISCONTIGUOUS_TRANSIENT_FULL_FDE_ASSUMPTION'
                correction_sha = sha256(REPORT / 'ghidra_correction_raw' / f'{position:03d}_{va:x}.json')
            else:
                if old_missing or bits != '1' * size or raw['ghidra_instruction_count'] != size // 4:
                    raise RuntimeError(f'candidate #{position} unlisted body/instruction gap')
                ghidra_rows = raw['instruction_pcode']
                c_text = raw['c_like_text']
                classification = 'EXISTING_GHIDRA_BODY_CONTAINS_EVERY_FDE_BYTE_BOUNDARY_UNPROVEN'
                correction_sha = None
            dis = list(cs.disasm(body, va))
            if len(dis) != size // 4 or any(ins.size != 4 for ins in dis):
                raise RuntimeError(f'candidate #{position} source disassembly differs')
            if len(ghidra_rows) != size // 4:
                raise RuntimeError(f'candidate #{position} effective Ghidra slots differ')
            sampled = set(sample_ordinals(len(dis)))
            for ordinal, (ins, source_row, ghidra_row) in enumerate(zip(
                    dis, source['instructions'], ghidra_rows)):
                expected_pc = int(raw['database_va'], 16) + ordinal * 4
                word = body[ordinal * 4:ordinal * 4 + 4]
                if (source_row['elf_va'] != f'0x{va+ordinal*4:x}' or
                        source_row['word_hex'] != word.hex() or
                        source_row['assembly'].split()[0].lower() != ins.mnemonic.lower() or
                        int(ghidra_row['database_va'], 16) != expected_pc or
                        ghidra_row.get('missing_analyzed_instruction') or
                        ghidra_row.get('missing_instruction') or
                        not isinstance(ghidra_row.get('pcode_ops'), list)):
                    raise RuntimeError(f'candidate #{position} instruction #{ordinal} provenance differs')
                gh_mnemonic = ghidra_row['assembly'].split()[0].lower()
                if (ins.mnemonic.lower() != gh_mnemonic and
                        (ins.mnemonic.lower(), gh_mnemonic) not in ALIASES):
                    raise RuntimeError(f'candidate #{position} instruction #{ordinal} mnemonic mismatch')
                if ordinal in sampled:
                    spread.append({'candidate_index': position,
                                   'instruction_ordinal_zero_based': ordinal,
                                   'elf_va': source_row['elf_va'],
                                   'word_sha256': hashlib.sha256(word).hexdigest(),
                                   'source_mnemonic': ins.mnemonic, 'ghidra_mnemonic': gh_mnemonic,
                                   'pcode_ops': len(ghidra_row['pcode_ops']),
                                   'pcode_sha256': hashlib.sha256(
                                       '\n'.join(ghidra_row['pcode_ops']).encode()).hexdigest()})
            local_ops = sum(len(x['pcode_ops']) for x in ghidra_rows)
            expected_ops = corrections[position]['full_fde_pcode_ops'] if position in CORRECTIONS else raw['ghidra_pcode_ops']
            if local_ops != expected_ops:
                raise RuntimeError(f'candidate #{position} p-code operation census differs')
            source_slots += len(dis)
            effective_pcode_slots += len(ghidra_rows)
            effective_pcode_ops += local_ops
            nonempty_c_like += bool(c_text.strip())
            results.append({'index': position, 'elf_va': target['elf_va'],
                            'fde_size_bytes': size, 'original_pt_load_body_sha256': digest,
                            'copied_ghidra_memory_sha256': raw['ghidra_memory_sha256'],
                            'original_instruction_slots': len(dis),
                            'effective_ghidra_pcode_slots': len(ghidra_rows),
                            'effective_ghidra_pcode_operations': local_ops,
                            'original_ghidra_body_membership_bytes': bits.count('1'),
                            'original_ghidra_body_missing_ranges': gap_ranges(bits),
                            'original_ghidra_body_discontinuities': raw['fde_byte_membership_transitions'],
                            'transient_full_fde_body_membership_bytes': size if position in CORRECTIONS else None,
                            'other_function_overlap_bytes': raw['other_function_byte_count'],
                            'nonempty_c_like': bool(c_text.strip()),
                            'effective_c_like_sha256': hashlib.sha256(c_text.encode()).hexdigest(),
                            'effective_c_like_chars': len(c_text),
                            'boundary_classification': classification,
                            'ordinary_spread_sample_count': len(sampled),
                            'raw_ghidra_sha256': sha256(raw_path),
                            'corrective_ghidra_sha256': correction_sha})
    if (len(results) != 128 or source_slots != EXPECTED_INSTRUCTION_SLOTS or
            effective_pcode_slots != EXPECTED_INSTRUCTION_SLOTS or
            original_membership_full != 122 or corrected_membership_full != 6 or
            original_missing_slots != 66 or nonempty_c_like != 128 or
            len(spread) < math.ceil(.1 * source_slots) or
            sum(x['ordinary_spread_sample_count'] for x in results) != len(spread)):
        raise RuntimeError('128-candidate coverage/membership/spread totals differ')
    verification = {'task_id': 'TASK_187', 'revision': 1, 'generated_at': now(),
                    'original_source_sha256': SOURCE_SHA, 'target_manifest_sha256': TARGETS_SHA,
                    'original_fde_candidate_bodies_verified': 128,
                    'original_arm64_instruction_words_verified': source_slots,
                    'copied_ghidra_memory_bodies_verified': 128,
                    'effective_ghidra_pcode_instruction_positions_verified': effective_pcode_slots,
                    'effective_ghidra_pcode_operations': effective_pcode_ops,
                    'nonempty_ghidra_c_like_texts': nonempty_c_like,
                    'existing_ghidra_bodies_contain_every_fde_byte': original_membership_full,
                    'original_ghidra_missing_instruction_slots': original_missing_slots,
                    'six_transient_full_fde_metadata_boundary_corrections': corrected_membership_full,
                    'verified_behavior_candidates': 0,
                    'ordinary_spread_instruction_sample_count': len(spread),
                    'ordinary_spread_instruction_sample_percent': round(100*len(spread)/source_slots, 2),
                    'ordinary_spread_samples': spread, 'rows': results,
                    'copied_project_provenance': project_provenance,
                    'batch_command_sha256': [sha256(REPORT / f'ghidra_batch{i}_command.json') for i in (1, 2)],
                    'correction_command_sha256': sha256(REPORT / 'ghidra_correction_command.json'),
                    'batch_process_seconds': [x['elapsed_seconds'] for x in batch_commands],
                    'correction_process_seconds': correction_command['elapsed_seconds'],
                    'fresh_imports': 0,
                    'limits': 'FDE start is candidate boundary, not complete internal census. Ghidra C-like output may omit exception/unreachable paths even with complete per-byte metadata; no behavior proof.'}
    write_json(REPORT / 'independent_verification.json', verification)
    master = ('# TASK_187 R1 — MTFilterKernel first 128 nonexport FDE candidates\n\n'
              '**Result: PARTIAL static research with all 128 pinned candidates processed.** '
              'Original `libMTFilterKernel.so` and every selected FDE/PT_LOAD body hash were '
              'independently checked. All 14,865 AArch64 instruction words and '
              f'{effective_pcode_ops:,} Ghidra p-code operations at 14,865 effective positions '
              'are present; C-like text is nonempty 128/128. '
              f'A deterministic spread check re-read {len(spread):,}/14,865 '
              f'({100*len(spread)/14865:.2f}%) source words, addresses and p-code hashes.\n\n'
              'Per-byte membership, rather than only min/max endpoints, shows 122 FDE ranges '
              'fully in their pre-existing Ghidra function bodies. Six ranges (#18, #23, #30, '
              '#43, #85, #128) had 66 missing instruction slots in truncated or discontinuous '
              'function bodies, with no other-function overlap. One bounded transient pass in '
              'the copied project disassembled those exact gaps, created full-FDE candidate '
              'metadata, recovered all six full-range assembly/p-code sets and rolled back. '
              'Their C-like outputs are nonempty but may still omit unreachable or exception '
              'paths; no whole-FDE semantic equivalence is inferred. The six original and '
              'corrected per-byte membership bitmaps and exact gap ranges are retained.\n\n'
              'This is **128 of 511** nonexport unwind FDE candidates, with 383 outside this '
              'task. An FDE start is not proof of a unique function boundary or complete internal '
              'census. No behavior, binary equivalence, image/pixel parity, product integration, '
              'Phase PASS, all-45-SO completion or V4 readiness is claimed. No new Ghidra '
              'import or prior export rerun occurred. Independent CEO review is pending.\n')
    atomic_bytes(REPORT / '01_MASTER_REPORT.md', master.encode())
    audit = (REPORT / '00_AUDIT_INDEX.md').read_text(encoding='utf-8')
    audit += ('\nFinal evidence: `source_project_index.json`, 128 `source_assembly/` rows, '
              '128 `ghidra_raw_batch{1,2}/` rows, six `ghidra_correction_raw/` rows, '
              'three command receipts and raw stdout/stderr pairs, and '
              '`independent_verification.json` with all per-byte membership counts/gaps '
              'and a spread instruction sample. `COMPLETE.json` hashes every non-progress '
              'report file, each owned code file and all scratch files.\n')
    atomic_bytes(REPORT / '00_AUDIT_INDEX.md', audit.encode())
    write_json(REPORT / 'PROGRESS.json', {'task_id': 'TASK_187', 'revision': 1,
               'status': 'SEALED_PARTIAL_STATIC_RESEARCH_CANDIDATE', 'generated_at': now(),
               'fde_bodies_verified': 128, 'original_instruction_positions': source_slots,
               'effective_ghidra_pcode_positions': effective_pcode_slots,
               'effective_ghidra_pcode_operations': effective_pcode_ops,
               'nonempty_c_like': 128, 'six_transient_fde_body_corrections': 6,
               'spread_instruction_sample_count': len(spread), 'fresh_imports': 0,
               'disposition': 'AWAITING_INDEPENDENT_CEO_REVIEW'})
    report_files = {p.relative_to(REPORT).as_posix(): sha256(p)
                    for p in sorted(REPORT.rglob('*')) if p.is_file()
                    and p.name not in {'COMPLETE.json', 'PROGRESS.json', 'PROGRESS.md'}}
    code_files = {p.relative_to(ROOT).as_posix(): sha256(p)
                  for p in sorted(SCRIPTS.rglob('*')) if p.is_file() and p.suffix in {'.py', '.java'}}
    scratch_files = {p.relative_to(ROOT).as_posix(): sha256(p)
                     for p in sorted(SCRATCH.rglob('*')) if p.is_file()}
    if sum(p.stat().st_size for p in REPORT.rglob('*') if p.is_file()) > 134_217_728:
        raise RuntimeError('report exceeds absolute task cap')
    complete = {'schema_version': '2.1.2', 'task_id': 'TASK_187', 'revision': 1,
                'status': 'COMPLETE',
                'research_result': 'PARTIAL_BOUNDARY_SIX_OF_128_TRANSIENT_FULL_FDE_METADATA',
                'generated_at': now(), 'agent_id': AGENT_ID, 'lease_id': LEASE_ID,
                'fencing_token': FENCE, 'standard_path': str(STANDARD),
                'standard_sha256': STANDARD_SHA, 'task_sha256': TASK_SHA,
                'target_manifest_sha256': TARGETS_SHA,
                'original_so_sha256': SOURCE_SHA,
                'original_fde_candidate_bodies_verified': 128,
                'original_instruction_words_verified': source_slots,
                'effective_ghidra_pcode_instruction_positions': effective_pcode_slots,
                'effective_ghidra_pcode_operations': effective_pcode_ops,
                'nonempty_c_like_outputs': 128,
                'original_full_fde_body_membership': 122,
                'six_transient_full_fde_body_corrections': 6,
                'ordinary_spread_instruction_sample_count': len(spread),
                'fresh_imports': 0, 'verified_behavior_candidates': 0,
                'files': report_files, 'code_files': code_files,
                'scratch_files': scratch_files,
                'limits': 'Unwind FDE starts do not prove unique function boundaries or an internal census; C-like is an unverified approximation and six transient full-FDE metadata corrections do not prove full semantics.'}
    write_json(REPORT / 'COMPLETE.json', complete)
    print(json.dumps({'status': 'SEALED_PARTIAL_STATIC_RESEARCH_CANDIDATE',
                      'original_fde_bodies': 128, 'source_and_pcode_instruction_positions': source_slots,
                      'pcode_ops': effective_pcode_ops, 'nonempty_c_like': 128,
                      'transient_full_fde_corrections': 6, 'spread_samples': len(spread),
                      'complete_sha256': sha256(REPORT / 'COMPLETE.json')}))


if __name__ == '__main__':
    main()
