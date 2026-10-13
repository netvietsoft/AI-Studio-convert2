"""Independent 51-body/FDE/position/provenance verification and immutable candidate seal."""
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
EXPECTED_GHIDRA_RAW = 51
EXPECTED_SOURCE_INSTRUCTIONS = 3990


def load(path):
    return json.loads(path.read_text(encoding='utf-8'))


def sample_ordinals(count: int) -> list[int]:
    n = max(1, math.ceil(.12 * count))
    if n == 1:
        return [(count - 1) // 2]
    return sorted({round(i * (count - 1) / (n - 1)) for i in range(n)})


def verify_command(path, stdout, stderr, expected_script, expected_files=None):
    cmd = load(path)
    if (cmd['status'] != 'OUTPUT_READY' or cmd['exit_code'] != 0 or
            cmd['script_sha256'] != sha256(SCRIPTS / expected_script) or
            cmd['stdout_sha256'] != sha256(stdout) or
            cmd['stderr_sha256'] != sha256(stderr) or
            cmd['elapsed_seconds'] > 1200 or
            cmd['max_cpu'] != 1 or cmd['max_heap'] != '1G' or
            '-noanalysis' not in cmd['command'] or '-readOnly' not in cmd['command'] or
            '-import' in cmd['command'] or
            cmd['command'].count(expected_script) != 1 or
            str(SCRATCH / 'ghidra_project') not in cmd['command']):
        raise RuntimeError(f'Ghidra command/log/provenance mismatch: {path}')
    if expected_files is not None:
        if cmd['raw_result_files'] != expected_files or len(cmd['raw_result_hashes']) != expected_files:
            raise RuntimeError('Ghidra raw census differs')
        for name, expected_sha in cmd['raw_result_hashes'].items():
            if sha256(REPORT / 'ghidra_raw' / name) != expected_sha:
                raise RuntimeError(f'Ghidra result hash differs: {name}')
    else:
        if cmd['result_sha256'] != sha256(REPORT / 'ghidra_boundary_10.json'):
            raise RuntimeError('boundary correction raw hash differs')
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
    if (len(manifest['targets']) != 51 or len(index['rows']) != 51 or
            index['task_sha256'] != TASK_SHA or index['target_manifest_sha256'] != TARGETS_SHA or
            index['standard_sha256'] != STANDARD_SHA or index['actor'] != AGENT_ID or
            index['lease_id'] != LEASE_ID or index['fencing_token'] != FENCE or
            index['source_sha256'] != SOURCE_SHA or sha256(SOURCE) != SOURCE_SHA or
            index['target_tsv_sha256'] != sha256(SCRATCH / 'target_batch.tsv')):
        raise RuntimeError('pinned source/project/task metadata differs')
    primary_cmd = verify_command(REPORT / 'ghidra_command.json',
                                 REPORT / 'ghidra_stdout.log',
                                 REPORT / 'ghidra_stderr.log',
                                 'ExtractInternal183.java', EXPECTED_GHIDRA_RAW)
    correction_cmd = verify_command(REPORT / 'boundary_10_command.json',
                                    REPORT / 'boundary_10_stdout.log',
                                    REPORT / 'boundary_10_stderr.log',
                                    'RepairBoundary183.java')
    corrected = load(REPORT / 'ghidra_boundary_10.json')
    if (corrected['index'] != 10 or corrected['elf_va'] != '0xe724' or
            corrected['size_bytes'] != 80 or corrected['old_analyzed_instruction_slots'] != 15 or
            corrected['full_fde_instruction_count'] != 20 or
            corrected['temporary_old_function_removed'] is not True or
            corrected['temporary_full_fde_function_created'] is not True or
            corrected['memory_unchanged_after_rollback'] is not True or
            corrected['memory_sha256'] != manifest['targets'][9]['body_sha256'] or
            corrected['decompile_elapsed_ms'] > 10_000 or
            not corrected['c_like_nonempty'] or not corrected['c_like_text'].strip() or
            corrected['error']):
        raise RuntimeError('candidate #10 precise boundary correction differs')
    project = verify_project(index)
    cs = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    results = []
    spread = []
    source_instructions = 0
    ghidra_pcode_positions = 0
    pcode_ops = 0
    exact_function_body_ranges = 0
    with SOURCE.open('rb') as stream:
        elf = ELFFile(stream)
        if elf['e_machine'] != 'EM_AARCH64':
            raise RuntimeError('original ELF architecture changed')
        fdes = {(int(f['initial_location']), int(f['address_range']))
                for f in elf.get_dwarf_info().EH_CFI_entries() if isinstance(f, FDE)}
        if len(fdes) != 155:
            raise RuntimeError('original FDE census changed')
        dyn = elf.get_section_by_name('.dynsym')
        exports = {int(s['st_value']) for s in dyn.iter_symbols()
                   if s['st_info']['type'] == 'STT_FUNC' and s['st_shndx'] != 'SHN_UNDEF'
                   and int(s['st_value']) > 0 and int(s['st_size']) > 0}
        if len(exports) != 104:
            raise RuntimeError('original export starts changed')
        segments = [(int(s['p_vaddr']), int(s['p_filesz']), int(s['p_offset']))
                    for s in elf.iter_segments() if s['p_type'] == 'PT_LOAD']
        for position, target in enumerate(manifest['targets'], 1):
            check_lease()
            va = int(target['elf_va'], 16)
            size = target['size_bytes']
            if (va, size) not in fdes or va in exports:
                raise RuntimeError(f'candidate #{position} lost original nonexport FDE identity')
            offsets = [off + va - base for base, length, off in segments
                       if base <= va and va + size <= base + length]
            if len(offsets) != 1 or offsets[0] != int(target['file_offset'], 16):
                raise RuntimeError(f'candidate #{position} PT_LOAD mapping changed')
            stream.seek(offsets[0])
            body = stream.read(size)
            digest = hashlib.sha256(body).hexdigest()
            if len(body) != size or digest != target['body_sha256']:
                raise RuntimeError(f'candidate #{position} original body hash changed')
            source = load(REPORT / 'source_assembly' / f'{position:02d}_{va:x}.json')
            raw_path = REPORT / 'ghidra_raw' / f'{position:02d}_{va:x}.json'
            raw = load(raw_path)
            if (source['index'] != position or source['source_body_sha256'] != digest or
                    source['fde_exact_match'] is not True or
                    source['other_fde_overlap'] or source['export_body_overlap'] or
                    raw['index'] != position or raw['elf_va'] != target['elf_va'] or
                    raw['size_bytes'] != size or raw['ghidra_memory_sha256'] != digest or
                    raw['instruction_slots'] != size // 4 or
                    raw['decompile_elapsed_ms'] > 10_000 or
                    not raw['c_like_nonempty'] or not raw['c_like_text'].strip() or
                    raw['decompile_error'] or
                    raw['boundary_classification'] != 'EXACT_GHIDRA_FUNCTION_START_FDE_RANGE_UNPROVEN' or
                    len(source['instructions']) != size // 4 or
                    len(raw['instruction_pcode']) != size // 4):
                raise RuntimeError(f'candidate #{position} source/Ghidra row differs')
            if position == 10:
                if raw['missing_analyzed_instruction_count'] != 5:
                    raise RuntimeError('candidate #10 original truncated body differs')
                ghidra_rows = corrected['instruction_pcode']
                if len(ghidra_rows) != 20:
                    raise RuntimeError('candidate #10 corrected instruction rows differ')
                boundary = 'FDE_80_BYTES_OLD_FUNCTION_60_BYTES_TRANSIENT_FULL_METADATA_CLIKE_TAIL_OMITTED'
                c_text = corrected['c_like_text']
                c_sha = hashlib.sha256(c_text.encode()).hexdigest()
                c_nonempty = True
            else:
                if raw['missing_analyzed_instruction_count'] != 0:
                    raise RuntimeError(f'candidate #{position} missing analyzed instructions')
                ghidra_rows = raw['instruction_pcode']
                if (int(raw['function_body_min'], 16) != int(raw['database_va'], 16) or
                        int(raw['function_body_max'], 16) != int(raw['database_va'], 16) + size - 1):
                    raise RuntimeError(f'candidate #{position} analyzed function range differs from FDE')
                exact_function_body_ranges += 1
                boundary = 'FDE_RANGE_EQUALS_EXISTING_GHIDRA_FUNCTION_BODY_BOUNDARY_NOT_PROVEN_SEMANTICALLY'
                c_text = raw['c_like_text']
                c_sha = hashlib.sha256(c_text.encode()).hexdigest()
                c_nonempty = True
            if len(ghidra_rows) != size // 4:
                raise RuntimeError(f'candidate #{position} Ghidra position coverage differs')
            dis = list(cs.disasm(body, va))
            if len(dis) != size // 4 or any(ins.size != 4 for ins in dis):
                raise RuntimeError(f'candidate #{position} fresh source disassembly differs')
            for ordinal, (ins, source_row, ghidra_row) in enumerate(zip(
                    dis, source['instructions'], ghidra_rows)):
                expected_pc = int(raw['database_va'], 16) + ordinal * 4
                word = body[ordinal * 4: ordinal * 4 + 4]
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
                if ordinal in sample_ordinals(len(dis)):
                    spread.append({'candidate_index': position, 'instruction_ordinal_zero_based': ordinal,
                                   'elf_va': source_row['elf_va'], 'word_sha256': hashlib.sha256(word).hexdigest(),
                                   'source_mnemonic': ins.mnemonic, 'ghidra_mnemonic': gh_mnemonic,
                                   'pcode_ops': len(ghidra_row['pcode_ops']),
                                   'pcode_sha256': hashlib.sha256(
                                       '\n'.join(ghidra_row['pcode_ops']).encode()).hexdigest()})
            if sum(len(x['pcode_ops']) for x in ghidra_rows) != (corrected['full_fde_pcode_ops']
                    if position == 10 else raw['ghidra_pcode_ops']):
                raise RuntimeError(f'candidate #{position} p-code census differs')
            source_instructions += len(dis)
            ghidra_pcode_positions += len(ghidra_rows)
            pcode_ops += sum(len(x['pcode_ops']) for x in ghidra_rows)
            results.append({'index': position, 'elf_va': target['elf_va'],
                            'fde_size_bytes': size, 'original_pt_load_body_sha256': digest,
                            'copied_ghidra_memory_sha256': raw['ghidra_memory_sha256'],
                            'original_instruction_count': len(dis),
                            'ghidra_pcode_instruction_positions': len(ghidra_rows),
                            'ghidra_pcode_operations': sum(len(x['pcode_ops']) for x in ghidra_rows),
                            'c_like_nonempty': c_nonempty, 'c_like_sha256': c_sha,
                            'c_like_chars': len(c_text), 'boundary_classification': boundary,
                            'ordinary_spread_sample_count': len(sample_ordinals(len(dis))),
                            'raw_ghidra_file_sha256': sha256(raw_path),
                            'corrective_ghidra_file_sha256': sha256(REPORT / 'ghidra_boundary_10.json')
                            if position == 10 else None})
    if (source_instructions != EXPECTED_SOURCE_INSTRUCTIONS or
            ghidra_pcode_positions != EXPECTED_SOURCE_INSTRUCTIONS or
            len(results) != 51 or exact_function_body_ranges != 50 or
            len(spread) < math.ceil(.1 * source_instructions) or
            sum(r['ordinary_spread_sample_count'] for r in results) != len(spread)):
        raise RuntimeError('51-candidate static coverage/spread verification differs')
    verification = {'task_id': 'TASK_183', 'revision': 1, 'generated_at': now(),
                    'original_source_sha256': SOURCE_SHA, 'target_manifest_sha256': TARGETS_SHA,
                    'original_fde_candidate_bodies_verified': len(results),
                    'original_arm64_instruction_words_verified': source_instructions,
                    'copied_ghidra_memory_bodies_verified': len(results),
                    'ghidra_pcode_instruction_positions_verified': ghidra_pcode_positions,
                    'ghidra_pcode_operations': pcode_ops,
                    'nonempty_ghidra_c_like_texts': sum(r['c_like_nonempty'] for r in results),
                    'existing_ghidra_function_body_exact_fde_range': exact_function_body_ranges,
                    'one_transient_full_fde_metadata_boundary_correction': True,
                    'candidate_10_c_like_omits_5_instruction_exception_tail': True,
                    'verified_behavior_candidates': 0,
                    'ordinary_spread_instruction_sample_count': len(spread),
                    'ordinary_spread_instruction_sample_percent': round(100*len(spread)/source_instructions, 2),
                    'ordinary_spread_samples': spread, 'rows': results,
                    'copied_project_provenance': project,
                    'primary_ghidra_command_sha256': sha256(REPORT / 'ghidra_command.json'),
                    'boundary_correction_command_sha256': sha256(REPORT / 'boundary_10_command.json'),
                    'primary_process_seconds': primary_cmd['elapsed_seconds'],
                    'boundary_process_seconds': correction_cmd['elapsed_seconds'],
                    'fresh_imports': 0,
                    'limits': 'FDE start is only a candidate boundary; C-like is Ghidra approximation, not verified behavior. Candidate #10 decompiler still omits exception tail despite complete original/p-code positions.'}
    write_json(REPORT / 'independent_verification.json', verification)
    master = ('# TASK_183 R1 — MTGif nonexport unwind candidates\n\n'
              '**Result: PARTIAL static research with all 51 pinned candidates processed.** '
              'The original `libMTGif.so` SHA-256 and all 51 exact nonexport `.eh_frame` FDE ranges '
              'were rechecked against original PT_LOAD bytes. All 3,990 AArch64 instruction words '
              f'and {pcode_ops:,} Ghidra p-code operations at 3,990 positions are present. '
              'All 51 candidates have nonempty Ghidra C-like text. '
              'A deterministic spread check independently re-read '
              f'{len(spread):,}/3,990 ({100*len(spread)/3990:.2f}%) instruction words, '
              'positions and p-code hashes. Source/project provenance, raw commands/logs and '
              'per-candidate JSON are in this package. No fresh import or prior export rerun occurred.\n\n'
              'For 50 candidates, the pre-existing Ghidra function body matches the FDE byte range. '
              'Candidate #10 at ELF VA `0xe724` has an 80-byte FDE, but its pre-existing function '
              'ends after 60 bytes. A transient full-FDE function in the owned project copy '
              'recovered instruction/p-code positions **20/20**, then rolled back. Its C-like '
              'still omits the five-instruction exception tail at `0xe760..0xe770` after a '
              'noreturn throw. Therefore C-like output is nonempty **51/51**, but whole-FDE '
              'C-like representation is unproven for #10 and may omit optimized/unreachable '
              'operations elsewhere. The FDE starts are candidate boundaries, not a proven '
              'complete internal-function census.\n\n'
              'No function behavior, binary equivalence, image/pixel parity, product integration, '
              'Phase PASS, all-45-SO completion or V4 readiness is claimed. Independent CEO '
              'review is pending.\n')
    atomic_bytes(REPORT / '01_MASTER_REPORT.md', master.encode())
    audit = (REPORT / '00_AUDIT_INDEX.md').read_text(encoding='utf-8')
    audit += ('\nFinal evidence: `source_project_index.json`, 51 `source_assembly/` rows, '
              '51 `ghidra_raw/` rows, `ghidra_command.json`, raw stdout/stderr, '
              '`ghidra_boundary_10.json`, boundary command/stdout/stderr, and '
              '`independent_verification.json`. `COMPLETE.json` hashes every non-progress '
              'report file, each owned code file and all scratch files.\n')
    atomic_bytes(REPORT / '00_AUDIT_INDEX.md', audit.encode())
    write_json(REPORT / 'PROGRESS.json', {'task_id': 'TASK_183', 'revision': 1,
               'status': 'SEALED_PARTIAL_STATIC_RESEARCH_CANDIDATE', 'generated_at': now(),
               'fde_bodies_verified': 51, 'original_instruction_positions': source_instructions,
               'ghidra_pcode_positions': ghidra_pcode_positions,
               'ghidra_pcode_operations': pcode_ops, 'nonempty_c_like': 51,
               'candidate_10_c_like_tail_omitted': True,
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
    complete = {'schema_version': '2.1.2', 'task_id': 'TASK_183', 'revision': 1,
                'status': 'COMPLETE',
                'research_result': 'PARTIAL_C_LIKE_BOUNDARY_ONE_OF_51_FULL_FDE_TAIL_OMITTED',
                'generated_at': now(), 'agent_id': AGENT_ID, 'lease_id': LEASE_ID,
                'fencing_token': FENCE, 'standard_path': str(STANDARD),
                'standard_sha256': STANDARD_SHA, 'task_sha256': TASK_SHA,
                'target_manifest_sha256': TARGETS_SHA,
                'original_so_sha256': SOURCE_SHA,
                'original_fde_candidate_bodies_verified': 51,
                'original_instruction_words_verified': source_instructions,
                'ghidra_pcode_instruction_positions': ghidra_pcode_positions,
                'ghidra_pcode_operations': pcode_ops,
                'nonempty_c_like_outputs': 51,
                'one_known_c_like_exception_tail_omission': True,
                'ordinary_spread_instruction_sample_count': len(spread),
                'fresh_imports': 0, 'verified_behavior_candidates': 0,
                'files': report_files, 'code_files': code_files,
                'scratch_files': scratch_files,
                'limits': 'Unwind FDE starts do not prove function census/boundary; Ghidra C-like is unverified approximation; candidate #10 omits exception tail in C-like despite full assembly/p-code.'}
    write_json(REPORT / 'COMPLETE.json', complete)
    print(json.dumps({'status': 'SEALED_PARTIAL_STATIC_RESEARCH_CANDIDATE',
                      'original_fde_bodies': 51, 'source_and_pcode_instruction_positions': source_instructions,
                      'pcode_ops': pcode_ops, 'nonempty_c_like': 51,
                      'spread_samples': len(spread),
                      'complete_sha256': sha256(REPORT / 'COMPLETE.json')}))


if __name__ == '__main__':
    main()
