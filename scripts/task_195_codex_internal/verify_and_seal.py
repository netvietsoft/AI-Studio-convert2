"""Independently verify the bounded ImageCodec FDE evidence and seal it."""
from __future__ import annotations

import hashlib
import json
import math

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile

from common import (AGENT, FENCE, LEASE_ID, PROJECT, REPORT, ROOT, SCRATCH,
                    SCRIPTS, SOURCE, SOURCE_SHA, STANDARD, STANDARD_SHA, TARGETS,
                    TARGETS_SHA, TASK_SHA, atomic_bytes, check_lease, now,
                    sha256, write_json)

CORRECTIONS = (85, 86, 88, 96, 103, 109, 112, 115, 121, 122, 126)
ALIASES = {('b.hs', 'b.cs'), ('b.lo', 'b.cc'), ('mov', 'orr'), ('mov', 'dup'),
           ('bfi', 'bfm')}


def load(path):
    return json.loads(path.read_text(encoding='utf-8'))


def gaps(bits):
    result, start = [], None
    for offset, bit in enumerate(bits):
        if bit == '0' and start is None:
            start = offset
        if bit == '1' and start is not None:
            result.append({'start_offset': start, 'end_exclusive': offset})
            start = None
    if start is not None:
        result.append({'start_offset': start, 'end_exclusive': len(bits)})
    return result


def sample_ordinals(count):
    n = max(1, math.ceil(.12 * count))
    return sorted({round(i * (count - 1) / max(1, n - 1)) for i in range(n)})


def check_command(stem, script_name, directory, expected):
    receipt = load(REPORT / f'{stem}_command.json')
    tsv = SCRATCH / (f"target_batch_{receipt['batch']}.tsv" if 'batch' in receipt
                     else 'correction_targets.tsv')
    if (receipt['task_id'] != 'TASK_195' or receipt['revision'] != 1 or
            receipt['status'] != 'OUTPUT_READY' or receipt['exit_code'] != 0 or
            receipt['raw_result_files'] != expected or
            len(receipt['raw_result_hashes']) != expected or
            receipt['script_sha256'] != sha256(SCRIPTS / script_name) or
            receipt['target_tsv_sha256'] != sha256(tsv) or
            receipt['stdout_sha256'] != sha256(REPORT / f'{stem}_stdout.log') or
            receipt['stderr_sha256'] != sha256(REPORT / f'{stem}_stderr.log') or
            receipt['elapsed_seconds'] > 1200 or receipt['max_cpu'] != 1 or
            receipt['max_heap'] != '1G' or '-readOnly' not in receipt['command'] or
            '-noanalysis' not in receipt['command'] or '-import' in receipt['command'] or
            receipt['command'].count(script_name) != 1):
        raise RuntimeError(f'headless command/provenance invalid: {stem}')
    observed = {p.name: sha256(p) for p in (REPORT / directory).glob('*.json')}
    if observed != receipt['raw_result_hashes']:
        raise RuntimeError(f'raw output digest set differs: {stem}')
    return receipt


def main():
    check_lease()
    if (REPORT / 'COMPLETE.json').exists():
        raise RuntimeError('TASK_195 already sealed')
    manifest = load(TARGETS)
    index = load(REPORT / 'source_project_index.json')
    if (len(manifest['targets']) != 64 or len(index['selected_candidate_rows']) != 64 or
            sha256(SOURCE) != SOURCE_SHA or index['source_sha256'] != SOURCE_SHA or
            index['task_sha256'] != TASK_SHA or index['target_manifest_sha256'] != TARGETS_SHA or
            index['standard_sha256'] != STANDARD_SHA or index['actor'] != AGENT or
            index['lease_id'] != LEASE_ID or index['fencing_token'] != FENCE or
            index['project_source'] != str(PROJECT) or
            index['project_copy'] != str(SCRATCH / 'ghidra_project') or
            index['all_fde_count'] != 9981 or
            index['all_nonexport_fde_candidates'] != 6655 or
            index['defined_nonzero_export_vas'] != 3326):
        raise RuntimeError('pinned project/source/task provenance differs')
    prior = load(ROOT / 'RULES/REPORT/TASK_192_REPORT_R1/COMPLETE.json')
    prior_project_hashes = {k.removeprefix('RESEARCH_WORK/TASK_192_R1/ghidra_project/'): v
                            for k, v in prior['scratch_files'].items()
                            if k.startswith('RESEARCH_WORK/TASK_192_R1/ghidra_project/')}
    if len(index['project_files']) != 9 or len(prior_project_hashes) != 9:
        raise RuntimeError('prior project receipt file count differs')
    project_after = []
    for item in index['project_files']:
        rel = item['relative_path']
        src, dst = PROJECT / rel, SCRATCH / 'ghidra_project' / rel
        before = item['sha256']
        if (before != prior_project_hashes.get(rel) or sha256(src) != before or
                sha256(dst) != before or src.stat().st_size != item['bytes']):
            raise RuntimeError(f'prior/private project byte hash differs: {rel}')
        project_after.append({'relative_path': rel, 'before_sha256': before,
                              'after_sha256': sha256(dst), 'bytes': item['bytes']})
    copied_files = {p.relative_to(SCRATCH / 'ghidra_project').as_posix()
                    for p in (SCRATCH / 'ghidra_project').rglob('*') if p.is_file()}
    if copied_files != {r['relative_path'] for r in project_after}:
        raise RuntimeError('private project inventory changed')
    for batch in (1, 2):
        if index['batch_files'][str(batch)]['sha256'] != sha256(SCRATCH / f'target_batch_{batch}.tsv'):
            raise RuntimeError('batch TSV hash differs')
    commands = [check_command('ghidra_batch1', 'ExtractInternal195.java',
                              'ghidra_raw_batch1', 32),
                check_command('ghidra_batch2', 'ExtractInternal195.java',
                              'ghidra_raw_batch2', 32),
                check_command('ghidra_correction', 'RepairMembership195.java',
                              'ghidra_correction_raw', 11),
                check_command('ghidra_postrollback', 'CheckOriginalMembership195.java',
                              'ghidra_postrollback_raw', 11)]
    corrected = {load(p)['index']: load(p)
                 for p in (REPORT / 'ghidra_correction_raw').glob('*.json')}
    postrows = {load(p)['index']: load(p)
                for p in (REPORT / 'ghidra_postrollback_raw').glob('*.json')}
    if set(corrected) != set(CORRECTIONS) or set(postrows) != set(CORRECTIONS):
        raise RuntimeError('correction and independent rollback index sets differ')
    cs = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    results, spread, call_sites = [], [], []
    source_slots = raw_slots = effective_slots = raw_ops = effective_ops = 0
    original_full = original_missing = 0
    with SOURCE.open('rb') as stream:
        elf = ELFFile(stream)
        fdes = [(int(x['initial_location']), int(x['address_range']))
                for x in elf.get_dwarf_info().EH_CFI_entries() if isinstance(x, FDE)]
        dyn = elf.get_section_by_name('.dynsym')
        exports = {(int(x['st_value']), int(x['st_size'])) for x in dyn.iter_symbols()
                   if x['st_info']['type'] == 'STT_FUNC' and x['st_shndx'] != 'SHN_UNDEF'
                   and int(x['st_value']) > 0 and int(x['st_size']) > 0}
        starts = {va for va, _ in exports}
        nonexports = sorted(x for x in fdes if x[0] not in starts)
        loads = [(int(s['p_vaddr']), int(s['p_filesz']), int(s['p_offset']))
                 for s in elf.iter_segments() if s['p_type'] == 'PT_LOAD']
        if (len(fdes), len(starts), len(nonexports)) != (9981, 3326, 6655):
            raise RuntimeError('original ELF FDE/export census differs')
        for ordinal, target in enumerate(manifest['targets']):
            check_lease()
            number = ordinal + 65
            va, size = int(target['elf_va'], 16), int(target['size_bytes'])
            if (target['global_nonexport_fde_index'] != ordinal + 64 or
                    nonexports[ordinal + 64] != (va, size) or
                    size < 4 or size > 4096 or size % 4 or va % 4):
                raise RuntimeError(f'FDE range/source index differs #{number}')
            mappings = [off + va - base for base, length, off in loads
                        if base <= va and va + size <= base + length]
            if len(mappings) != 1 or mappings[0] != int(target['file_offset'], 16):
                raise RuntimeError(f'PT_LOAD mapping differs #{number}')
            if (any(other != va and other < va + size and va < other + length
                    for other, length in fdes) or
                    any(other < va + size and va < other + length for other, length in exports)):
                raise RuntimeError(f'FDE/export body overlaps #{number}')
            stream.seek(mappings[0])
            body = stream.read(size)
            digest = hashlib.sha256(body).hexdigest()
            if len(body) != size or digest != target['body_sha256']:
                raise RuntimeError(f'original body hash differs #{number}')
            source = load(REPORT / 'source_assembly' / f'{number:03d}_{va:x}.json')
            raw_path = REPORT / f'ghidra_raw_batch{1 if ordinal < 32 else 2}' / f'{number:03d}_{va:x}.json'
            raw = load(raw_path)
            if (source['index'] != number or source['selected_zero_index'] != ordinal + 64 or
                    source['source_body_sha256'] != digest or not source['fde_exact_match'] or
                    source['other_fde_overlap'] or source['export_body_overlap'] or
                    source['instruction_slots'] != size//4 or
                    source['capstone_decoded_slots'] != size//4 or
                    raw['task_id'] != 'TASK_195' or raw['index'] != number or
                    raw['elf_va'] != target['elf_va'] or raw['size_bytes'] != size or
                    raw['ghidra_memory_sha256'] != digest or
                    raw['instruction_slots'] != size//4 or
                    len(raw['instruction_pcode']) != size//4 or
                    not raw['existing_exact_function_start'] or
                    raw['existing_function_contains_nonstart'] or
                    raw['temporary_function_created_and_rolled_back'] or
                    raw['other_function_byte_count'] or raw['extra_body_address_count'] or
                    raw['extra_body_ranges'] or raw['decompile_elapsed_ms'] > 10000 or
                    raw['decompile_error'] or not raw['c_like_nonempty'] or
                    not raw['c_like_text'].strip() or
                    int(raw['function_start'],16) != int(raw['database_va'],16)):
                raise RuntimeError(f'original/Ghidra raw identity differs #{number}')
            bits = raw['fde_byte_membership_bits']
            if (len(bits) != size or set(bits)-{'0','1'} or
                    bits.count('1') != raw['fde_byte_membership_count'] or
                    raw['fde_missing_body_ranges'] != gaps(bits) or
                    raw['fde_byte_membership_transitions'] != sum(
                        bits[n] != bits[n-1] for n in range(1, size)) or
                    raw['function_body_total_address_count'] != bits.count('1')):
                raise RuntimeError(f'per-byte function membership differs #{number}')
            missing = raw['missing_analyzed_instruction_count']
            if missing != size//4 - raw['ghidra_instruction_count']:
                raise RuntimeError(f'analyzed instruction census differs #{number}')
            original_missing += missing
            raw_slots += raw['ghidra_instruction_count']
            if bits == '1'*size:
                original_full += 1
            if number in CORRECTIONS:
                item, restored = corrected[number], postrows[number]
                corrected_bits = item['corrected_function_fde_membership_bits']
                if (missing <= 0 or bits.count('1') >= size or
                        item['elf_va'] != target['elf_va'] or item['size_bytes'] != size or
                        item['memory_sha256'] != digest or
                        not item['memory_unchanged_after_rollback'] or
                        item['original_function_fde_membership_bits'] != bits or
                        item['original_function_fde_membership_count'] != bits.count('1') or
                        item['other_function_byte_count'] or
                        not item['temporary_old_function_removed'] or
                        not item['temporary_full_fde_function_created'] or
                        corrected_bits != '1'*size or
                        item['corrected_function_fde_membership_count'] != size or
                        item['corrected_function_body_total_address_count'] != size or
                        item['full_fde_instruction_count'] != size//4 or
                        len(item['instruction_pcode']) != size//4 or
                        item['decompile_elapsed_ms'] > 10000 or
                        not item['c_like_nonempty'] or not item['c_like_text'].strip() or
                        item['error'] or restored['memory_sha256'] != digest or
                        restored['body_bits'] != bits or
                        restored['function_start'] != raw['function_start'] or
                        restored['function_name'] != raw['function_name'] or
                        restored['other_function_byte_count']):
                    raise RuntimeError(f'correction/independent rollback differs #{number}')
                effective = item['instruction_pcode']
                c_text = item['c_like_text']
                classification = 'TRANSIENT_FULL_FDE_METADATA_ASSUMPTION_ORIGINAL_BODY_PARTIAL'
                correction_hash = sha256(REPORT / 'ghidra_correction_raw' / f'{number:03d}_{va:x}.json')
                rollback_hash = sha256(REPORT / 'ghidra_postrollback_raw' / f'{number:03d}_{va:x}.json')
            else:
                if missing or bits != '1'*size:
                    raise RuntimeError(f'unlisted Ghidra metadata gap #{number}')
                effective = raw['instruction_pcode']
                c_text = raw['c_like_text']
                classification = 'EXISTING_GHIDRA_BODY_CONTAINS_FDE_RANGE_BOUNDARY_UNPROVEN'
                correction_hash = rollback_hash = None
            decoded = list(cs.disasm(body, va))
            if len(decoded) != size//4 or any(ins.size != 4 for ins in decoded):
                raise RuntimeError(f'original instruction decoding differs #{number}')
            selected = set(sample_ordinals(len(decoded)))
            local_calls = []
            for instruction_index, (ins, srow, grow, erow) in enumerate(zip(
                    decoded, source['instructions'], raw['instruction_pcode'], effective)):
                word = body[instruction_index*4:instruction_index*4+4]
                expected_pc = int(raw['database_va'], 16) + instruction_index*4
                if (srow['elf_va'] != f'0x{va+instruction_index*4:x}' or
                        srow['word_hex'] != word.hex() or
                        srow['assembly'].split()[0].lower() != ins.mnemonic.lower() or
                        int(grow['database_va'], 16) != expected_pc or
                        int(erow['database_va'], 16) != expected_pc):
                    raise RuntimeError(f'per-instruction byte/address differs #{number}:{instruction_index}')
                if grow.get('missing_analyzed_instruction'):
                    if number not in CORRECTIONS or 'pcode_ops' in grow:
                        raise RuntimeError(f'undeclared raw missing instruction #{number}:{instruction_index}')
                elif not isinstance(grow.get('pcode_ops'), list):
                    raise RuntimeError(f'raw p-code row invalid #{number}:{instruction_index}')
                if erow.get('missing_analyzed_instruction') or erow.get('missing_instruction') or not isinstance(erow.get('pcode_ops'), list):
                    raise RuntimeError(f'effective p-code missing #{number}:{instruction_index}')
                gh_mnemonic = erow['assembly'].split()[0].lower()
                if ins.mnemonic.lower() != gh_mnemonic and (ins.mnemonic.lower(), gh_mnemonic) not in ALIASES:
                    raise RuntimeError(f'source/Ghidra mnemonic differs #{number}:{instruction_index}: {ins.mnemonic}/{gh_mnemonic}')
                if ins.mnemonic.lower().startswith('bl'):
                    site = {'candidate_index': number, 'instruction_ordinal_zero_based': instruction_index,
                            'source_va': srow['elf_va'], 'word_hex': word.hex(),
                            'mnemonic': ins.mnemonic, 'operand_text': ins.op_str,
                            'direct_target_va': ins.op_str if ins.mnemonic.lower() == 'bl' else None,
                            'kind': 'DIRECT_BL' if ins.mnemonic.lower() == 'bl' else 'INDIRECT_OR_AUTHENTICATED_BL'}
                    local_calls.append(site)
                    call_sites.append(site)
                if instruction_index in selected:
                    spread.append({'candidate_index': number,
                                   'instruction_ordinal_zero_based': instruction_index,
                                   'source_va': srow['elf_va'],
                                   'word_sha256': hashlib.sha256(word).hexdigest(),
                                   'source_mnemonic': ins.mnemonic,
                                   'ghidra_mnemonic': gh_mnemonic,
                                   'effective_pcode_ops': len(erow['pcode_ops']),
                                   'effective_pcode_sha256': hashlib.sha256(
                                       '\n'.join(erow['pcode_ops']).encode()).hexdigest()})
            local_raw_ops = sum(len(r['pcode_ops']) for r in raw['instruction_pcode']
                                if isinstance(r.get('pcode_ops'), list))
            local_ops = sum(len(r['pcode_ops']) for r in effective)
            if (local_raw_ops != raw['ghidra_pcode_ops'] or
                    number in CORRECTIONS and local_ops != corrected[number]['full_fde_pcode_ops']):
                raise RuntimeError(f'p-code operation count differs #{number}')
            source_slots += len(decoded)
            effective_slots += len(effective)
            raw_ops += local_raw_ops
            effective_ops += local_ops
            results.append({'index': number, 'selected_zero_index': ordinal+64,
                            'elf_va': target['elf_va'], 'fde_size_bytes': size,
                            'original_pt_load_body_sha256': digest,
                            'copied_ghidra_memory_sha256': raw['ghidra_memory_sha256'],
                            'source_instruction_slots': len(decoded),
                            'original_ghidra_analyzed_slots': raw['ghidra_instruction_count'],
                            'original_ghidra_missing_slots': missing,
                            'effective_ghidra_pcode_slots': len(effective),
                            'original_ghidra_pcode_ops': local_raw_ops,
                            'effective_ghidra_pcode_ops': local_ops,
                            'original_function_fde_membership_bytes': bits.count('1'),
                            'original_function_missing_ranges': gaps(bits),
                            'extra_function_body_ranges': raw['extra_body_ranges'],
                            'other_function_overlap_bytes': 0,
                            'transient_full_fde_membership_bytes': size if number in CORRECTIONS else None,
                            'c_like_nonempty': bool(c_text.strip()),
                            'effective_c_like_sha256': hashlib.sha256(c_text.encode()).hexdigest(),
                            'effective_c_like_chars': len(c_text),
                            'call_site_count': len(local_calls),
                            'boundary_classification': classification,
                            'ordinary_spread_sample_count': len(selected),
                            'raw_ghidra_sha256': sha256(raw_path),
                            'correction_sha256': correction_hash,
                            'fresh_postrollback_sha256': rollback_hash})
    if (len(results) != 64 or source_slots != 6349 or effective_slots != 6349 or
            original_full != 53 or original_missing != 114 or raw_slots != 6235 or
            len(spread) < math.ceil(.10 * source_slots) or
            sum(r['ordinary_spread_sample_count'] for r in results) != len(spread)):
        raise RuntimeError('final FDE/P-code/ordinary spread totals differ')
    write_json(REPORT / 'CALL_SITES.json', {'task_id': 'TASK_195', 'revision': 1,
               'source_library': 'libPVGImageCodec.so', 'source_sha256': SOURCE_SHA,
               'classification': 'AARCH64_BL_FAMILY_STATIC_INSTRUCTION_SITES_ONLY',
               'count': len(call_sites), 'sites': call_sites,
               'limits': 'A call instruction site does not establish a resolved runtime callee or behavior.'})
    verification = {'task_id': 'TASK_195', 'revision': 1, 'generated_at': now(),
                    'original_source_sha256': SOURCE_SHA,
                    'target_manifest_sha256': TARGETS_SHA,
                    'original_fde_candidate_bodies_verified': 64,
                    'original_arm64_instruction_words_verified': source_slots,
                    'original_ghidra_analyzed_instruction_positions': raw_slots,
                    'original_ghidra_missing_instruction_positions': original_missing,
                    'effective_ghidra_pcode_instruction_positions': effective_slots,
                    'original_ghidra_pcode_operations': raw_ops,
                    'effective_ghidra_pcode_operations': effective_ops,
                    'nonempty_effective_c_like_texts': sum(r['c_like_nonempty'] for r in results),
                    'original_full_fde_body_membership': original_full,
                    'transient_full_fde_metadata_assumptions': len(CORRECTIONS),
                    'fresh_session_original_metadata_and_memory_replays': len(postrows),
                    'static_call_instruction_sites': len(call_sites),
                    'ordinary_spread_instruction_sample_count': len(spread),
                    'ordinary_spread_instruction_sample_percent': round(100*len(spread)/source_slots,2),
                    'ordinary_spread_samples': spread, 'rows': results,
                    'project_hashes_before_after': project_after,
                    'command_receipt_hashes': {stem: sha256(REPORT/f'{stem}_command.json')
                        for stem in ('ghidra_batch1','ghidra_batch2','ghidra_correction','ghidra_postrollback')},
                    'headless_process_seconds': [r['elapsed_seconds'] for r in commands],
                    'fresh_imports': 0, 'verified_behavior_candidates': 0,
                    'limits': 'Unwind FDE ranges do not prove unique function boundaries. '
                              'Transient full-FDE metadata is an assumption. C-like text may omit paths; '
                              'static call instructions do not prove runtime behavior.'}
    write_json(REPORT / 'WORKER_VERIFICATION.json', verification)
    master = (f'# TASK_195 R1 — ImageCodec nonexport FDE indices 64..127\n\n'
              '**Result: PARTIAL static research, 64 pinned candidate ranges processed.** '
              'The original SO, FDE/PT_LOAD bodies and all 6,349 AArch64 source positions '
              f'were verified. A byte-verified private analyzed Ghidra project produced '
              f'64 nonempty C-like outputs and effective p-code at 6,349 positions '
              f'({effective_ops:,} operations). A deterministic spread check independently '
              f'read {len(spread):,}/6,349 source positions ({100*len(spread)/6349:.2f}%).\n\n'
              f'Pre-existing function bodies cover all FDE bytes in {original_full}/64 candidates; '
              f'11 have 114 missing analyzed instruction positions. A transient full-FDE '
              'metadata pass recovered p-code/C-like evidence for those 11 in a private '
              'read-only Ghidra process. Same-session metadata rollback views were stale; '
              'a separate fresh read-only Ghidra session reproduced the original function '
              'names, starts, body bitmaps and memory hashes for 11/11. Original and '
              'private project files remained 9/9 byte-identical to the prior sealed receipt.\n\n'
              f'CALL_SITES.json records {len(call_sites)} original AArch64 BL-family static '
              'instruction sites with source word/address. These are syntactic call sites; '
              'indirect destinations and runtime behavior remain unverified. FDE boundaries '
              'are candidates, not proven unique source functions. This slice is 64 of '
              '6,655 nonexport FDE candidates; 6,527 lie beyond index 127. No product '
              'behavior, binary equivalence, image/pixel parity, Phase PASS, all-45-SO '
              'completion, V4 or P7 readiness is claimed. No new import, production edit, '
              'commit or push. Independent CEO review is pending.\n')
    atomic_bytes(REPORT / '01_MASTER_REPORT.md', master.encode('utf-8'))
    audit = (REPORT / '00_AUDIT_INDEX.md').read_text(encoding='utf-8')
    audit += ('\nFinal evidence: 64 source_assembly and 64 ghidra_raw_batch rows, '
              '11 ghidra_correction_raw and 11 fresh ghidra_postrollback_raw rows. '
              'WORKER_VERIFICATION.json records exact per-byte membership, every '
              'source/P-code position, C-like digests, before/after project hashes and '
              'a spread sample. CALL_SITES.json records original static call sites. '
              'COMPLETE.json seals the immutable report, code and private scratch inventory.\n')
    atomic_bytes(REPORT / '00_AUDIT_INDEX.md', audit.encode('utf-8'))
    write_json(REPORT / 'PROGRESS.json', {'task_id':'TASK_195', 'revision':1,
               'status':'SEALED_PARTIAL_STATIC_RESEARCH_CANDIDATE', 'generated_at':now(),
               'fde_bodies_verified':64, 'original_instruction_positions':source_slots,
               'effective_ghidra_pcode_positions':effective_slots,
               'effective_ghidra_pcode_operations':effective_ops,
               'nonempty_c_like':64, 'transient_full_fde_metadata_assumptions':11,
               'fresh_postrollback_replays':11, 'spread_instruction_sample_count':len(spread),
               'static_call_instruction_sites':len(call_sites), 'fresh_imports':0,
               'disposition':'AWAITING_INDEPENDENT_CEO_REVIEW'})
    report_files = {p.relative_to(REPORT).as_posix():sha256(p)
                    for p in sorted(REPORT.rglob('*')) if p.is_file()
                    and p.name not in {'COMPLETE.json', 'PROGRESS.json'}}
    code_files = {p.relative_to(ROOT).as_posix():sha256(p)
                  for p in sorted(SCRIPTS.rglob('*')) if p.is_file() and p.suffix in {'.py','.java'}}
    scratch_files = {p.relative_to(ROOT).as_posix():sha256(p)
                     for p in sorted(SCRATCH.rglob('*')) if p.is_file()}
    if sum(p.stat().st_size for p in REPORT.rglob('*') if p.is_file()) > 134_217_728:
        raise RuntimeError('report byte cap exceeded')
    complete = {'schema_version':'2.1.2', 'task_id':'TASK_195', 'revision':1,
                'status':'COMPLETE',
                'research_result':'PARTIAL_BOUNDARY_ELEVEN_TRANSIENT_FULL_FDE_METADATA',
                'generated_at':now(), 'agent_id':AGENT, 'lease_id':LEASE_ID,
                'fencing_token':FENCE, 'standard_path':str(STANDARD),
                'standard_sha256':STANDARD_SHA, 'task_sha256':TASK_SHA,
                'target_manifest_sha256':TARGETS_SHA, 'original_so_sha256':SOURCE_SHA,
                'original_fde_candidate_bodies_verified':64,
                'original_instruction_words_verified':source_slots,
                'effective_ghidra_pcode_instruction_positions':effective_slots,
                'effective_ghidra_pcode_operations':effective_ops,
                'nonempty_c_like_outputs':64,
                'original_full_fde_body_membership':original_full,
                'transient_full_fde_metadata_assumptions':11,
                'fresh_session_original_metadata_and_memory_replays':11,
                'ordinary_spread_instruction_sample_count':len(spread),
                'static_call_instruction_sites':len(call_sites),
                'fresh_imports':0, 'verified_behavior_candidates':0,
                'files':report_files, 'code_files':code_files, 'scratch_files':scratch_files,
                'limits':'FDE boundaries and C-like output do not establish unique source '
                         'functions or behavior; 11 full-FDE reconstructions are explicitly '
                         'boundary-limited transient metadata assumptions.'}
    write_json(REPORT / 'COMPLETE.json', complete)
    print(json.dumps({'status':'SEALED_PARTIAL_STATIC_RESEARCH_CANDIDATE',
                      'original_fde_bodies':64, 'source_and_effective_pcode_positions':source_slots,
                      'effective_pcode_ops':effective_ops, 'nonempty_c_like':64,
                      'transient_full_fde_metadata_assumptions':11,
                      'fresh_postrollback_replays':11, 'spread_samples':len(spread),
                      'call_sites':len(call_sites),
                      'complete_sha256':sha256(REPORT/'COMPLETE.json')}))


if __name__ == '__main__':
    main()
