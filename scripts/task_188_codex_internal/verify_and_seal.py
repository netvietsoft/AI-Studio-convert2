"""Re-read original ELF and Ghidra evidence, then seal a bounded research result."""
from __future__ import annotations

import hashlib
import json
import math
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile

from common import (AGENT_ID, FENCE, LEASE_ID, PROJECT, REPORT, ROOT, SCRATCH,
                    SCRIPTS, SOURCE, SOURCE_SHA, STANDARD, STANDARD_SHA, TARGETS,
                    TARGETS_SHA, TASK_SHA, atomic_bytes, check_lease, now, sha256,
                    write_json)

CORRECTED = (10, 15, 17, 18, 28, 30, 32, 35, 43, 52, 55, 56, 58, 59, 62, 69)
OVERLAP = (47, 57, 60)
ALIASES = {('b.hs', 'b.cs'), ('b.lo', 'b.cc'), ('mov', 'orr')}
SLOTS = 6885


def load(path: Path) -> dict:
    return json.loads(path.read_text(encoding='utf-8'))


def missing_ranges(bits: str) -> list[dict]:
    ranges = []
    start = None
    for offset, bit in enumerate(bits):
        if bit == '0' and start is None:
            start = offset
        elif bit == '1' and start is not None:
            ranges.append({'start_offset': start, 'end_exclusive': offset})
            start = None
    if start is not None:
        ranges.append({'start_offset': start, 'end_exclusive': len(bits)})
    return ranges


def spread_ordinals(count: int) -> list[int]:
    number = max(1, math.ceil(0.12 * count))
    if number == 1:
        return [(count - 1) // 2]
    return sorted({round(i * (count - 1) / (number - 1)) for i in range(number)})


def command_receipt(name: str, expected_count: int, script_name: str, tsv_name: str) -> dict:
    receipt = load(REPORT / f'{name}_command.json')
    out = REPORT / (f'ghidra_raw_batch{receipt["batch"]}' if 'batch' in receipt
                    else 'ghidra_correction_raw')
    tsv = SCRATCH / tsv_name
    script = SCRIPTS / script_name
    command = receipt['command']
    if (receipt['task_id'] != 'TASK_188' or receipt['revision'] != 1 or
            receipt['status'] != 'OUTPUT_READY' or receipt['exit_code'] != 0 or
            receipt['raw_result_files'] != expected_count or
            len(receipt['raw_result_hashes']) != expected_count or
            receipt['script_sha256'] != sha256(script) or
            receipt['target_tsv_sha256'] != sha256(tsv) or
            receipt['stdout_sha256'] != sha256(REPORT / f'{name}_stdout.log') or
            receipt['stderr_sha256'] != sha256(REPORT / f'{name}_stderr.log') or
            receipt['elapsed_seconds'] > 1200 or receipt['max_cpu'] != 1 or
            receipt['max_heap'] != '1G' or
            receipt['max_decompile_seconds_per_candidate'] != 10 or
            '-noanalysis' not in command or '-readOnly' not in command or
            '-import' in command or command.count(script_name) != 1 or
            '-max-cpu' not in command or command[command.index('-max-cpu') + 1] != '1' or
            command[command.index('-process') + 1] != 'libMTLReportTool.so'):
        raise RuntimeError(f'{name} command/log/provenance differs')
    files = {x.name for x in out.glob('*.json')}
    if files != set(receipt['raw_result_hashes']):
        raise RuntimeError(f'{name} result inventory differs')
    for filename, digest in receipt['raw_result_hashes'].items():
        if sha256(out / filename) != digest:
            raise RuntimeError(f'{name} raw result changed: {filename}')
    return receipt


def project_provenance(index: dict) -> dict:
    if index['project_source'] != str(PROJECT) or index['project_copy'] != str(SCRATCH / 'ghidra_project'):
        raise RuntimeError('analyzed project origin/copy differs')
    old = load(ROOT / 'RULES/REPORT/TASK_177_REPORT_R1/project_copy_manifest.json')['projects']['libMTLReportTool.so']
    if Path(old['original_project_path']) != PROJECT:
        raise RuntimeError('TASK_177 project provenance differs')
    expected = {x['relative_path']: x['source_sha256'] for x in old['files']}
    if expected != {x['relative_path']: x['sha256'] for x in index['project_files']}:
        raise RuntimeError('copied project manifest does not match TASK_177 original')
    transient = []
    identical = 0
    for relative, digest in expected.items():
        original = PROJECT / relative
        copied = SCRATCH / 'ghidra_project' / relative
        if not original.is_file() or sha256(original) != digest:
            raise RuntimeError(f'original analyzed project changed: {relative}')
        actual = sha256(copied) if copied.is_file() else None
        if actual == digest:
            identical += 1
        elif relative.endswith(('/idata/~index.bak', '/idata/~journal.bak')):
            transient.append({'path': relative, 'initial_sha256': digest,
                              'after_session_sha256': actual})
        else:
            raise RuntimeError(f'copied analyzed content changed: {relative}')
    return {'original_project_files_verified': len(expected),
            'copied_project_files_still_identical': identical,
            'transient_session_metadata': transient}


def main() -> None:
    check_lease()
    if (REPORT / 'COMPLETE.json').exists():
        raise RuntimeError('TASK_188 already sealed')
    manifest = load(TARGETS)
    index = load(REPORT / 'source_project_index.json')
    if (manifest['source_sha256'] != SOURCE_SHA or manifest['selected_count'] != 117 or
            len(manifest['targets']) != 117 or len(index['selected_candidate_rows']) != 117 or
            index['task_sha256'] != TASK_SHA or index['target_manifest_sha256'] != TARGETS_SHA or
            index['standard_sha256'] != STANDARD_SHA or index['actor'] != AGENT_ID or
            index['lease_id'] != LEASE_ID or index['fencing_token'] != FENCE or
            index['source_sha256'] != SOURCE_SHA or sha256(SOURCE) != SOURCE_SHA or
            index['all_fde_count'] != 147 or index['all_nonexport_fde_candidates'] != 117 or
            index['defined_nonzero_export_vas'] != 30):
        raise RuntimeError('pinned source/task/manifest preflight differs')
    for batch, count in ((1, 60), (2, 57)):
        batch_info = index['batch_files'][str(batch)]
        if batch_info['count'] != count or batch_info['sha256'] != sha256(SCRATCH / f'target_batch_{batch}.tsv'):
            raise RuntimeError(f'target batch {batch} differs')
    batches = [command_receipt(f'ghidra_batch{i}', n, 'ExtractInternal188.java',
                               f'target_batch_{i}.tsv') for i, n in ((1, 60), (2, 57))]
    correction_cmd = command_receipt('ghidra_correction', 16,
                                     'RepairMembership188.java', 'correction_targets.tsv')
    if correction_cmd['target_indices'] != list(CORRECTED):
        raise RuntimeError('correction target set differs')
    copied_project = project_provenance(index)
    correction = {load(path)['index']: load(path)
                  for path in (REPORT / 'ghidra_correction_raw').glob('*.json')}
    if set(correction) != set(CORRECTED):
        raise RuntimeError('correction result inventory differs')

    capstone = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    rows = []
    samples = []
    source_slots = ghidra_slots = pcode_ops = c_like_count = 0
    full_original = full_corrected = raw_missing_slots = 0
    with SOURCE.open('rb') as stream:
        elf = ELFFile(stream)
        if elf['e_machine'] != 'EM_AARCH64':
            raise RuntimeError('ELF machine differs')
        fdes = [(int(x['initial_location']), int(x['address_range']))
                for x in elf.get_dwarf_info().EH_CFI_entries() if isinstance(x, FDE)]
        dyn = elf.get_section_by_name('.dynsym')
        exports = {(int(x['st_value']), int(x['st_size'])) for x in dyn.iter_symbols()
                   if x['st_info']['type'] == 'STT_FUNC' and x['st_shndx'] != 'SHN_UNDEF'
                   and int(x['st_value']) > 0 and int(x['st_size']) > 0}
        nonexports = sorted(x for x in fdes if x[0] not in {a for a, _ in exports})
        selected = [(int(x['elf_va'], 16), x['size_bytes']) for x in manifest['targets']]
        if (len(fdes) != 147 or len({a for a, _ in exports}) != 30 or
                len(nonexports) != 117 or nonexports != selected):
            raise RuntimeError('original source FDE/export census changed')
        segments = [(int(s['p_vaddr']), int(s['p_filesz']), int(s['p_offset']))
                    for s in elf.iter_segments() if s['p_type'] == 'PT_LOAD']
        for position, target in enumerate(manifest['targets'], 1):
            check_lease()
            va, size = selected[position - 1]
            offsets = [off + va - base for base, length, off in segments
                       if base <= va and va + size <= base + length]
            if len(offsets) != 1 or offsets[0] != int(target['file_offset'], 16):
                raise RuntimeError(f'candidate {position} PT_LOAD mapping changed')
            stream.seek(offsets[0])
            body = stream.read(size)
            digest = hashlib.sha256(body).hexdigest()
            if len(body) != size or digest != target['body_sha256']:
                raise RuntimeError(f'candidate {position} original body hash changed')
            source = load(REPORT / 'source_assembly' / f'{position:03d}_{va:x}.json')
            raw_path = REPORT / f'ghidra_raw_batch{1 if position <= 60 else 2}' / f'{position:03d}_{va:x}.json'
            raw = load(raw_path)
            if (source['index'] != position or source['source_body_sha256'] != digest or
                    source['fde_exact_match'] is not True or source['other_fde_overlap'] or
                    source['export_body_overlap'] or source['instruction_slots'] != size // 4 or
                    source['capstone_decoded_slots'] != size // 4 or
                    len(source['instructions']) != size // 4 or raw['task_id'] != 'TASK_188' or
                    raw['index'] != position or raw['elf_va'] != target['elf_va'] or
                    raw['size_bytes'] != size or raw['ghidra_memory_sha256'] != digest or
                    raw['instruction_slots'] != size // 4 or
                    not raw['existing_exact_function_start'] or
                    raw['existing_function_contains_nonstart'] or
                    raw['temporary_function_created_and_rolled_back'] or
                    not raw['c_like_nonempty'] or not raw['c_like_text'].strip() or
                    raw['decompile_error'] or raw['decompile_elapsed_ms'] > 10_000 or
                    len(raw['instruction_pcode']) != size // 4):
                raise RuntimeError(f'candidate {position} source/Ghidra fields differ')
            bits = raw['fde_byte_membership_bits']
            membership = bits.count('1')
            extra = raw['function_body_total_address_count'] - membership
            if (len(bits) != size or set(bits) - {'0', '1'} or
                    membership != raw['fde_byte_membership_count'] or
                    raw['fde_missing_body_ranges'] != missing_ranges(bits) or
                    raw['fde_byte_membership_transitions'] != sum(bits[k] != bits[k-1]
                                                                  for k in range(1, size)) or
                    extra != 0 or int(raw['function_start'], 16) != int(raw['database_va'], 16)):
                raise RuntimeError(f'candidate {position} every-byte body membership differs')
            original_missing = sum(bool(x.get('missing_analyzed_instruction'))
                                   for x in raw['instruction_pcode'])
            if (original_missing != raw['missing_analyzed_instruction_count'] or
                    size // 4 - original_missing != raw['ghidra_instruction_count'] or
                    sum(len(x.get('pcode_ops', [])) for x in raw['instruction_pcode']) != raw['ghidra_pcode_ops']):
                raise RuntimeError(f'candidate {position} first-pass instruction/p-code census differs')
            raw_missing_slots += original_missing
            if membership == size:
                full_original += 1
            corrected_path = None
            if position in CORRECTED:
                fixed = correction[position]
                corrected_path = REPORT / 'ghidra_correction_raw' / f'{position:03d}_{va:x}.json'
                if (raw['other_function_byte_count'] != 0 or membership == size or
                        fixed['task_id'] != 'TASK_188' or fixed['elf_va'] != target['elf_va'] or
                        fixed['size_bytes'] != size or fixed['memory_sha256'] != digest or
                        not fixed['memory_unchanged_after_rollback'] or
                        fixed['original_function_fde_membership_bits'] != bits or
                        fixed['original_function_fde_membership_count'] != membership or
                        fixed['other_function_byte_count'] != 0 or
                        not fixed['temporary_old_function_removed'] or
                        not fixed['temporary_full_fde_function_created'] or
                        fixed['corrected_function_fde_membership_bits'] != '1' * size or
                        fixed['corrected_function_fde_membership_count'] != size or
                        fixed['corrected_function_body_total_address_count'] != size or
                        fixed['full_fde_instruction_count'] != size // 4 or
                        fixed['full_fde_pcode_ops'] != sum(len(x.get('pcode_ops', []))
                                                         for x in fixed['instruction_pcode']) or
                        len(fixed['instruction_pcode']) != size // 4 or
                        not fixed['c_like_nonempty'] or not fixed['c_like_text'].strip() or
                        fixed['error'] or fixed['decompile_elapsed_ms'] > 10_000):
                    raise RuntimeError(f'candidate {position} transient correction differs')
                effective = fixed['instruction_pcode']
                c_text = fixed['c_like_text']
                classification = 'TRANSIENT_FULL_FDE_BODY_ASSUMPTION_NONOVERLAP_BOUNDARY_UNPROVEN'
                full_corrected += 1
            else:
                effective = raw['instruction_pcode']
                c_text = raw['c_like_text']
                if position in OVERLAP:
                    if raw['other_function_byte_count'] != 4 or membership >= size:
                        raise RuntimeError(f'candidate {position} other-function overlap changed')
                    classification = 'OTHER_GHIDRA_FUNCTION_OVERLAP_BOUNDARY_LIMITED'
                else:
                    if bits != '1' * size or original_missing or raw['other_function_byte_count']:
                        raise RuntimeError(f'candidate {position} unlisted body/instruction gap')
                    classification = 'EXISTING_GHIDRA_BODY_COVERS_FDE_BOUNDARY_UNPROVEN'
            decoded = list(capstone.disasm(body, va))
            if len(decoded) != size // 4 or any(ins.size != 4 for ins in decoded):
                raise RuntimeError(f'candidate {position} source disassembly differs')
            available = []
            for ordinal, (ins, src, gh) in enumerate(zip(decoded, source['instructions'], effective)):
                word = body[4*ordinal:4*ordinal+4]
                expected_database_va = int(raw['database_va'], 16) + ordinal * 4
                if (src['elf_va'] != f'0x{va+ordinal*4:x}' or src['word_hex'] != word.hex() or
                        src['assembly'].split()[0].lower() != ins.mnemonic.lower() or
                        int(gh['database_va'], 16) != expected_database_va):
                    raise RuntimeError(f'candidate {position} instruction {ordinal} source/address differs')
                if gh.get('missing_analyzed_instruction') or gh.get('missing_instruction'):
                    continue
                if not isinstance(gh.get('pcode_ops'), list) or not gh.get('assembly'):
                    raise RuntimeError(f'candidate {position} instruction {ordinal} lacks p-code/assembly')
                available.append(ordinal)
            for sample_position in spread_ordinals(len(available)):
                ordinal = available[sample_position]
                ins = decoded[ordinal]
                gh = effective[ordinal]
                gh_mnemonic = gh['assembly'].split()[0].lower()
                if ins.mnemonic.lower() != gh_mnemonic and (ins.mnemonic.lower(), gh_mnemonic) not in ALIASES:
                    raise RuntimeError(f'candidate {position} sample instruction {ordinal} mnemonic differs: {ins.mnemonic}/{gh_mnemonic}')
                word = body[4*ordinal:4*ordinal+4]
                samples.append({'candidate_index': position, 'instruction_ordinal_zero_based': ordinal,
                                'elf_va': f'0x{va+4*ordinal:x}',
                                'source_word_sha256': hashlib.sha256(word).hexdigest(),
                                'source_mnemonic': ins.mnemonic, 'ghidra_mnemonic': gh_mnemonic,
                                'pcode_count': len(gh['pcode_ops']),
                                'pcode_sha256': hashlib.sha256('\n'.join(gh['pcode_ops']).encode()).hexdigest()})
            effective_count = len(available)
            ops = sum(len(x.get('pcode_ops', [])) for x in effective)
            source_slots += len(decoded)
            ghidra_slots += effective_count
            pcode_ops += ops
            c_like_count += bool(c_text.strip())
            rows.append({'index': position, 'elf_va': target['elf_va'], 'fde_size_bytes': size,
                         'source_body_sha256': digest, 'copied_ghidra_memory_sha256': raw['ghidra_memory_sha256'],
                         'source_instruction_slots': len(decoded),
                         'first_pass_ghidra_instruction_slots': raw['ghidra_instruction_count'],
                         'effective_ghidra_instruction_pcode_slots': effective_count,
                         'effective_pcode_operations': ops,
                         'first_pass_body_membership_bytes': membership,
                         'first_pass_body_total_address_count': raw['function_body_total_address_count'],
                         'first_pass_body_extra_address_count': extra,
                         'first_pass_missing_body_ranges': missing_ranges(bits),
                         'first_pass_body_membership_transitions': raw['fde_byte_membership_transitions'],
                         'other_function_overlap_bytes': raw['other_function_byte_count'],
                         'transient_full_fde_membership_bytes': size if corrected_path else None,
                         'effective_c_like_sha256': hashlib.sha256(c_text.encode()).hexdigest(),
                         'effective_c_like_chars': len(c_text),
                         'boundary_classification': classification,
                         'ordinary_spread_samples': len(spread_ordinals(len(available))),
                         'raw_ghidra_sha256': sha256(raw_path),
                         'corrective_ghidra_sha256': sha256(corrected_path) if corrected_path else None})
    if (len(rows) != 117 or source_slots != SLOTS or full_original != 98 or
            full_corrected != 16 or len(OVERLAP) != 3 or c_like_count != 117 or
            ghidra_slots != SLOTS - 125 or raw_missing_slots != 456 or
            len(samples) < math.ceil(0.1 * SLOTS)):
        raise RuntimeError('total coverage, boundary or spread check differs')
    verification = {'schema_version': '2.1.2', 'task_id': 'TASK_188', 'revision': 1,
                    'generated_at': now(), 'original_source_sha256': SOURCE_SHA,
                    'target_manifest_sha256': TARGETS_SHA,
                    'original_fde_bodies_verified': 117,
                    'original_source_instruction_words_verified': source_slots,
                    'effective_ghidra_instruction_pcode_slots': ghidra_slots,
                    'effective_ghidra_pcode_operations': pcode_ops,
                    'nonempty_c_like_texts': c_like_count,
                    'existing_ghidra_full_fde_body_membership': full_original,
                    'nonoverlap_transient_full_fde_assumptions': full_corrected,
                    'other_function_boundary_limited_candidates': list(OVERLAP),
                    'raw_ghidra_missing_instruction_slots': raw_missing_slots,
                    'ordinary_spread_sample_count': len(samples),
                    'ordinary_spread_sample_percent_of_all_source_slots': round(100 * len(samples) / SLOTS, 2),
                    'ordinary_spread_samples': samples, 'rows': rows,
                    'project_provenance': copied_project,
                    'batch_process_seconds': [x['elapsed_seconds'] for x in batches],
                    'correction_process_seconds': correction_cmd['elapsed_seconds'],
                    'fresh_imports': 0, 'verified_behavior_candidates': 0,
                    'limits': 'Unwind FDE candidate boundaries and C-like text do not establish unique functions, complete semantics or product behavior. Three candidates overlap another Ghidra function and retain incomplete p-code positions.'}
    write_json(REPORT / 'worker_verification.json', verification)
    master = ('# TASK_188 R1 — MTLReportTool 117 nonexport FDE candidates\n\n'
              '**Result: PARTIAL static research.** The original `libMTLReportTool.so` SHA-256, '
              'all 117 FDE/PT_LOAD body hashes and 6,885/6,885 AArch64 source instruction words '
              'were rechecked. Ghidra returned nonempty C-like text for 117/117 candidates. '
              f'Effective Ghidra instruction/p-code coverage is {ghidra_slots:,}/6,885 slots '
              f'with {pcode_ops:,} p-code operations. A spread check re-read '
              f'{len(samples):,}/6,885 ({100*len(samples)/SLOTS:.2f}%) ordinary source '
              'instruction slots, addresses, mnemonics and p-code hashes.\n\n'
              'The pre-existing Ghidra function body contains every FDE byte for 98 candidates. '
              'Sixteen other candidates had nonoverlapping body gaps; one bounded transient '
              'metadata/disassembly pass on the byte-verified project copy obtained full-FDE '
              'membership, instruction/p-code rows and nonempty C-like output for each, then '
              'rolled back without persisting changes. These full-FDE bodies are assumptions '
              'about candidate boundaries. The remaining #47, #57 and #60 each overlap '
              'another Ghidra function by four bytes. Their original body membership and '
              'gaps are preserved; 125 instruction/p-code positions remain unanalyzed in '
              'Ghidra across these three candidates. No other function metadata was removed. '
              'The report records all per-byte membership bitmaps, missing ranges, '
              'total body address counts and the absence of body addresses outside each FDE.\n\n'
              'An unwind FDE range is a candidate, not proof of a unique or complete function. '
              'C-like output may omit exception or unreachable paths. No function behavior, '
              'pixel parity, product Phase PASS, V4/P7 readiness or all-45-SO completion is '
              'claimed. No new Ghidra import occurred. Independent CEO review is pending.\n')
    atomic_bytes(REPORT / '01_MASTER_REPORT.md', master.encode('utf-8'))
    audit = (REPORT / '00_AUDIT_INDEX.md').read_text(encoding='utf-8')
    audit += ('\nFinal evidence: `source_project_index.json`, 117 `source_assembly/` rows, '
              '117 `ghidra_raw_batch{1,2}/` rows, 16 `ghidra_correction_raw/` rows, '
              'three command receipts and raw stdout/stderr pairs, and '
              '`worker_verification.json`. `COMPLETE.json` hashes all fixed report files, '
              'owned code files and scratch/project files.\n')
    atomic_bytes(REPORT / '00_AUDIT_INDEX.md', audit.encode('utf-8'))
    write_json(REPORT / 'PROGRESS.json', {'task_id': 'TASK_188', 'revision': 1,
               'status': 'SEALED_PARTIAL_STATIC_RESEARCH_CANDIDATE', 'generated_at': now(),
               'fde_bodies_verified': 117, 'source_instruction_slots': source_slots,
               'effective_ghidra_pcode_slots': ghidra_slots,
               'nonempty_c_like': c_like_count, 'nonoverlap_corrections': full_corrected,
               'boundary_limited_overlap_candidates': list(OVERLAP),
               'spread_sample_count': len(samples), 'fresh_imports': 0,
               'disposition': 'AWAITING_INDEPENDENT_CEO_REVIEW'})
    report_files = {p.relative_to(REPORT).as_posix(): sha256(p)
                    for p in sorted(REPORT.rglob('*')) if p.is_file()
                    and p.name not in {'COMPLETE.json', 'PROGRESS.json', 'PROGRESS.md'}}
    code_files = {p.relative_to(ROOT).as_posix(): sha256(p)
                  for p in sorted(SCRIPTS.rglob('*')) if p.is_file() and p.suffix in {'.py', '.java'}}
    scratch_files = {p.relative_to(ROOT).as_posix(): sha256(p)
                     for p in sorted(SCRATCH.rglob('*')) if p.is_file()}
    report_bytes = sum(p.stat().st_size for p in REPORT.rglob('*') if p.is_file())
    if report_bytes > 134_217_728:
        raise RuntimeError('report exceeds task cap')
    complete = {'schema_version': '2.1.2', 'task_id': 'TASK_188', 'revision': 1,
                'status': 'COMPLETE', 'research_result': 'PARTIAL_THREE_BOUNDARY_LIMITED_OVERLAPS',
                'generated_at': now(), 'agent_id': AGENT_ID, 'lease_id': LEASE_ID,
                'fencing_token': FENCE, 'standard_path': str(STANDARD),
                'standard_sha256': STANDARD_SHA, 'task_sha256': TASK_SHA,
                'target_manifest_sha256': TARGETS_SHA, 'original_so_sha256': SOURCE_SHA,
                'original_fde_candidate_bodies_verified': 117,
                'original_source_instruction_words_verified': source_slots,
                'effective_ghidra_instruction_pcode_slots': ghidra_slots,
                'effective_ghidra_pcode_operations': pcode_ops,
                'nonempty_c_like_outputs': c_like_count,
                'original_full_fde_body_membership': full_original,
                'nonoverlap_transient_full_fde_body_corrections': full_corrected,
                'boundary_limited_overlap_indices': list(OVERLAP),
                'ordinary_spread_instruction_sample_count': len(samples),
                'fresh_imports': 0, 'verified_behavior_candidates': 0,
                'files': report_files, 'code_files': code_files, 'scratch_files': scratch_files,
                'limits': verification['limits']}
    write_json(REPORT / 'COMPLETE.json', complete)
    print(json.dumps({'status': 'SEALED_PARTIAL_STATIC_RESEARCH_CANDIDATE',
                      'bodies': 117, 'source_slots': source_slots, 'effective_pcode_slots': ghidra_slots,
                      'pcode_ops': pcode_ops, 'nonempty_c_like': c_like_count,
                      'nonoverlap_corrections': full_corrected, 'boundary_limited': list(OVERLAP),
                      'spread_samples': len(samples), 'complete_sha256': sha256(REPORT / 'COMPLETE.json')}))


if __name__ == '__main__':
    main()
