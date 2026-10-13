"""Recheck TASK_201 source/output provenance and seal a bounded research package."""
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

CORRECTIONS = (347, 348, 357, 358, 360, 361, 363)
EXCLUDED_OVERSIZED = (349, 362)
# Capstone and Ghidra choose different textual aliases for the same AArch64 word.
ALIASES = {('b.hs', 'b.cs'), ('b.lo', 'b.cc'), ('mov', 'orr'), ('orr', 'mov'), ('mov', 'dup'),
           ('bfi', 'bfm'), ('ushll2', 'uxtl2'), ('ushll', 'uxtl')}


def load(path):
    return json.loads(path.read_text(encoding='utf-8'))


def gaps(bits: str) -> list[dict]:
    result = []
    start = None
    for offset, bit in enumerate(bits):
        if bit == '0' and start is None:
            start = offset
        elif bit == '1' and start is not None:
            result.append({'start_offset': start, 'end_exclusive': offset})
            start = None
    if start is not None:
        result.append({'start_offset': start, 'end_exclusive': len(bits)})
    return result


def sample_ordinals(count: int) -> list[int]:
    n = max(1, math.ceil(.12 * count))
    if n == 1:
        return [(count - 1) // 2]
    return sorted({round(i * (count - 1) / (n - 1)) for i in range(n)})


def check_command(name: str, script_name: str, result_dir: str, expected: int) -> dict:
    command = load(REPORT / f'{name}_command.json')
    if (command['task_id'] != 'TASK_201' or command['revision'] != 1 or
            command['status'] != 'OUTPUT_READY' or command['exit_code'] != 0 or
            command['raw_result_files'] != expected or
            len(command['raw_result_hashes']) != expected or
            command['script_sha256'] != sha256(SCRIPTS / script_name) or
            command['target_tsv_sha256'] != sha256(
                SCRATCH / (f"target_batch_{command['batch']}.tsv" if 'batch' in command
                           else 'correction_targets.tsv')) or
            command['stdout_sha256'] != sha256(REPORT / f'{name}_stdout.log') or
            command['stderr_sha256'] != sha256(REPORT / f'{name}_stderr.log') or
            command['elapsed_seconds'] > 1200 or command['max_cpu'] != 1 or
            command['max_heap'] != '1G' or '-noanalysis' not in command['command'] or
            '-readOnly' not in command['command'] or '-import' in command['command'] or
            command['command'].count(script_name) != 1):
        raise RuntimeError(f'{name} command/log/source provenance differs')
    for filename, digest in command['raw_result_hashes'].items():
        if sha256(REPORT / result_dir / filename) != digest:
            raise RuntimeError(f'{name} raw result hash differs: {filename}')
    return command


def main() -> None:
    check_lease()
    if (REPORT / 'COMPLETE.json').exists():
        raise RuntimeError('already sealed')
    manifest = load(TARGETS)
    index = load(REPORT / 'source_project_index.json')
    if (len(manifest['targets']) != 62 or len(index['selected_candidate_rows']) != 62 or
            index['task_sha256'] != TASK_SHA or index['target_manifest_sha256'] != TARGETS_SHA or
            index['standard_sha256'] != STANDARD_SHA or index['actor'] != AGENT or
            index['lease_id'] != LEASE_ID or index['fencing_token'] != FENCE or
            index['source_sha256'] != SOURCE_SHA or sha256(SOURCE) != SOURCE_SHA or
            index['all_fde_count'] != 2873 or index['all_nonexport_fde_candidates'] != 511 or
            index['defined_nonzero_export_vas'] != 2362):
        raise RuntimeError('pinned source/task/manifest metadata differs')
    for batch in (1, 2):
        if (index['batch_files'][str(batch)]['sha256'] !=
                sha256(SCRATCH / f'target_batch_{batch}.tsv')):
            raise RuntimeError('target batch TSV changed')
    first = check_command('ghidra_batch1', 'ExtractInternal201.java', 'ghidra_raw_batch1', 31)
    second = check_command('ghidra_batch2', 'ExtractInternal201.java', 'ghidra_raw_batch2', 31)
    correction = check_command('ghidra_correction', 'RepairMembership201.java',
                               'ghidra_correction_raw', 7)
    post = check_command('ghidra_postrollback', 'CheckOriginalMembership201.java',
                         'ghidra_postrollback_raw', 7)
    if index['project_source'] != str(PROJECT) or index['project_copy'] != str(SCRATCH / 'ghidra_project'):
        raise RuntimeError('project source/copy paths differ')
    prior_report = ROOT / 'RULES/REPORT/TASK_197_REPORT_R1'
    prior_complete = prior_report / 'COMPLETE.json'
    prior_index = prior_report / 'source_project_index.json'
    if (sha256(prior_complete) !=
            '5f8974ca71263eec6f3ace06a72a523d2a994b1d9e7d367206bd75904a765925' or
            index['prior_task197_r1_complete_sha256'] != sha256(prior_complete) or
            index['prior_task197_r1_source_project_index_sha256'] != sha256(prior_index) or
            index['excluded_oversized_global_indices'] != list(EXCLUDED_OVERSIZED) or
            manifest['excluded_oversized_bytes'] != 11364):
        raise RuntimeError('prior accepted project/excluded scope receipt differs')
    prior_seal = load(prior_complete)
    for item in index['project_files']:
        src = PROJECT / item['relative_path']
        dst = SCRATCH / 'ghidra_project' / item['relative_path']
        if (not src.is_file() or not dst.is_file() or src.stat().st_size != item['bytes'] or
                sha256(src) != item['sha256'] or sha256(dst) != item['sha256'] or
                prior_seal['scratch_files'].get(src.relative_to(ROOT).as_posix()) != item['sha256']):
            raise RuntimeError(f'analyzed project hash differs: {item["relative_path"]}')
    corrected = {load(p)['index']: load(p)
                 for p in (REPORT / 'ghidra_correction_raw').glob('*.json')}
    postrows = {load(p)['index']: load(p)
                for p in (REPORT / 'ghidra_postrollback_raw').glob('*.json')}
    if set(corrected) != set(CORRECTIONS) or set(postrows) != set(CORRECTIONS):
        raise RuntimeError('correction/postrollback target set differs')
    cs = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    results = []
    spread = []
    source_slots = 0
    original_ghidra_slots = 0
    effective_slots = 0
    effective_ops = 0
    original_missing_slots = 0
    original_full_bodies = 0
    corrected_full_bodies = 0
    source_direct_calls = 0
    source_indirect_calls = 0
    with SOURCE.open('rb') as stream:
        elf = ELFFile(stream)
        if elf['e_machine'] != 'EM_AARCH64':
            raise RuntimeError('ELF architecture differs')
        fdes = [(int(x['initial_location']), int(x['address_range']))
                for x in elf.get_dwarf_info().EH_CFI_entries() if isinstance(x, FDE)]
        dyn = elf.get_section_by_name('.dynsym')
        exports = {(int(x['st_value']), int(x['st_size'])) for x in dyn.iter_symbols()
                   if x['st_info']['type'] == 'STT_FUNC' and x['st_shndx'] != 'SHN_UNDEF'
                   and int(x['st_value']) > 0 and int(x['st_size']) > 0}
        starts = {va for va, _ in exports}
        nonexports = sorted(x for x in fdes if x[0] not in starts)
        pinned = [(int(x['elf_va'], 16), x['size_bytes']) for x in manifest['targets']]
        selected_indices = [i for i in range(320,384) if i not in EXCLUDED_OVERSIZED]
        if (len(fdes) != 2873 or len(starts) != 2362 or len(nonexports) != 511 or
                manifest['excluded_oversized_global_indices'] != list(EXCLUDED_OVERSIZED) or
                [x['global_nonexport_fde_index'] for x in manifest['targets']] != selected_indices or
                pinned != [nonexports[i] for i in selected_indices]):
            raise RuntimeError('exact 62-candidate original source selection differs')
        segments = [(int(s['p_vaddr']), int(s['p_filesz']), int(s['p_offset']))
                    for s in elf.iter_segments() if s['p_type'] == 'PT_LOAD']
        for ordinal, target in enumerate(manifest['targets'], 1):
            check_lease()
            number = target['global_nonexport_fde_index']
            va, size = pinned[ordinal - 1]
            offsets = [off + va - base for base, length, off in segments
                       if base <= va and va + size <= base + length]
            if len(offsets) != 1 or offsets[0] != int(target['file_offset'], 16):
                raise RuntimeError(f'PT_LOAD mapping differs #{number}')
            stream.seek(offsets[0])
            body = stream.read(size)
            digest = hashlib.sha256(body).hexdigest()
            if len(body) != size or digest != target['body_sha256']:
                raise RuntimeError(f'source body hash differs #{number}')
            source = load(REPORT / 'source_assembly' / f'{number:03d}_{va:x}.json')
            batch = 1 if ordinal <= 31 else 2
            raw_path = REPORT / f'ghidra_raw_batch{batch}' / f'{number:03d}_{va:x}.json'
            raw = load(raw_path)
            if (source['index'] != number or source['selected_zero_index'] != number or
                    source['source_body_sha256'] != digest or not source['fde_exact_match'] or
                    source['other_fde_overlap'] or source['export_body_overlap'] or
                    source['instruction_slots'] != size//4 or
                    source['capstone_decoded_slots'] != size//4 or
                    raw['index'] != number or raw['elf_va'] != target['elf_va'] or
                    raw['size_bytes'] != size or raw['ghidra_memory_sha256'] != digest or
                    raw['instruction_slots'] != size//4 or
                    len(source['instructions']) != size//4 or
                    len(raw['instruction_pcode']) != size//4 or
                    not raw['existing_exact_function_start'] or
                    raw['existing_function_contains_nonstart'] or
                    raw['temporary_function_created_and_rolled_back'] or
                    raw['other_function_byte_count'] != 0 or
                    raw['decompile_elapsed_ms'] > 10_000 or
                    raw['decompile_error'] or not raw['c_like_nonempty'] or
                    not raw['c_like_text'].strip()):
                raise RuntimeError(f'Ghidra/source identity/output differs #{number}')
            bits = raw['fde_byte_membership_bits']
            extra_ranges = raw['extra_body_ranges']
            extra_bytes = sum(int(r['end_exclusive'],16)-int(r['start'],16) for r in extra_ranges)
            if (len(bits) != size or set(bits)-{'0','1'} or
                    bits.count('1') != raw['fde_byte_membership_count'] or
                    raw['fde_missing_body_ranges'] != gaps(bits) or
                    raw['fde_byte_membership_transitions'] != sum(
                        bits[n] != bits[n-1] for n in range(1,len(bits))) or
                    extra_bytes != raw['extra_body_address_count'] or
                    raw['function_body_total_address_count'] != bits.count('1')+extra_bytes or
                    extra_bytes != 0 or int(raw['function_start'],16) != int(raw['database_va'],16)):
                raise RuntimeError(f'per-byte Ghidra body/extra range differs #{number}')
            missing = raw['missing_analyzed_instruction_count']
            if missing != size//4 - raw['ghidra_instruction_count']:
                raise RuntimeError(f'raw Ghidra instruction count differs #{number}')
            original_missing_slots += missing
            original_ghidra_slots += raw['ghidra_instruction_count']
            if bits == '1'*size:
                original_full_bodies += 1
            if number in CORRECTIONS:
                item = corrected[number]
                restored = postrows[number]
                cbits = item['corrected_function_fde_membership_bits']
                if (missing <= 0 or bits.count('1') >= size or
                        item['elf_va'] != target['elf_va'] or item['size_bytes'] != size or
                        item['memory_sha256'] != digest or
                        not item['memory_unchanged_after_rollback'] or
                        item['same_session_function_metadata_restored'] is not False or
                        item['original_function_fde_membership_bits'] != bits or
                        item['original_function_fde_membership_count'] != bits.count('1') or
                        item['other_function_byte_count'] != 0 or
                        not item['temporary_old_function_removed'] or
                        not item['temporary_full_fde_function_created'] or
                        cbits != '1'*size or
                        item['corrected_function_fde_membership_count'] != size or
                        item['corrected_function_body_total_address_count'] != size or
                        item['full_fde_instruction_count'] != size//4 or
                        len(item['instruction_pcode']) != size//4 or
                        item['decompile_elapsed_ms'] > 10_000 or
                        not item['c_like_nonempty'] or not item['c_like_text'].strip() or
                        item['error'] or
                        restored['memory_sha256'] != digest or
                        restored['body_bits'] != bits or
                        restored['function_start'] != raw['function_start'] or
                        restored['function_name'] != raw['function_name'] or
                        restored['other_function_byte_count'] != 0):
                    raise RuntimeError(f'correction/reopen provenance differs #{number}')
                effective_rows = item['instruction_pcode']
                c_text = item['c_like_text']
                corrected_full_bodies += 1
                classification = 'TRANSIENT_FULL_FDE_METADATA_ASSUMPTION_ORIGINAL_BODY_PARTIAL'
                correction_sha = sha256(REPORT / 'ghidra_correction_raw' / f'{number:03d}_{va:x}.json')
                post_sha = sha256(REPORT / 'ghidra_postrollback_raw' / f'{number:03d}_{va:x}.json')
            else:
                if missing or bits != '1'*size or raw['ghidra_instruction_count'] != size//4:
                    raise RuntimeError(f'unlisted Ghidra gap #{number}')
                effective_rows = raw['instruction_pcode']
                c_text = raw['c_like_text']
                classification = 'EXISTING_GHIDRA_BODY_CONTAINS_EVERY_FDE_BYTE_BOUNDARY_UNPROVEN'
                correction_sha = None
                post_sha = None
            decoded = list(cs.disasm(body,va))
            if len(decoded) != size//4 or any(ins.size != 4 for ins in decoded):
                raise RuntimeError(f'source disassembly differs #{number}')
            expected_calls = [{'elf_va':f'0x{ins.address:x}','mnemonic':ins.mnemonic,
                               'operand':ins.op_str,
                               'direct_target_va':ins.op_str.lstrip('#') if ins.mnemonic == 'bl' else None}
                              for ins in decoded if ins.mnemonic in
                              {'bl','blr','blraa','blrab','blraaz','blrabz'}]
            if (source['source_calls'] != expected_calls or
                    source['source_direct_call_count'] != sum(x['mnemonic']=='bl' for x in expected_calls) or
                    source['source_indirect_call_count'] != sum(x['mnemonic']!='bl' for x in expected_calls)):
                raise RuntimeError(f'original source call sites differ #{number}')
            source_direct_calls += source['source_direct_call_count']
            source_indirect_calls += source['source_indirect_call_count']
            selected = set(sample_ordinals(len(decoded)))
            for instruction_index,(ins,srow,grow,erow) in enumerate(zip(
                    decoded,source['instructions'],raw['instruction_pcode'],effective_rows)):
                word = body[instruction_index*4:instruction_index*4+4]
                expected_pc = int(raw['database_va'],16)+instruction_index*4
                if (srow['elf_va'] != f'0x{va+instruction_index*4:x}' or
                        srow['word_hex'] != word.hex() or
                        srow['assembly'].split()[0].lower() != ins.mnemonic.lower() or
                        int(grow['database_va'],16) != expected_pc or
                        int(erow['database_va'],16) != expected_pc):
                    raise RuntimeError(f'instruction byte/PC differs #{number}:{instruction_index}')
                if grow.get('missing_analyzed_instruction'):
                    if number not in CORRECTIONS or grow.get('pcode_ops') is not None:
                        raise RuntimeError(f'unlisted missing Ghidra instruction #{number}:{instruction_index}')
                elif not isinstance(grow.get('pcode_ops'),list):
                    raise RuntimeError(f'raw p-code row differs #{number}:{instruction_index}')
                if (erow.get('missing_analyzed_instruction') or
                        erow.get('missing_instruction') or
                        not isinstance(erow.get('pcode_ops'),list)):
                    raise RuntimeError(f'effective p-code row missing #{number}:{instruction_index}')
                gh_mnemonic = erow['assembly'].split()[0].lower()
                if ins.mnemonic.lower() != gh_mnemonic and (ins.mnemonic.lower(),gh_mnemonic) not in ALIASES:
                    raise RuntimeError(f'source/Ghidra mnemonic differs #{number}:{instruction_index}: '
                                       f'{ins.mnemonic}/{gh_mnemonic}')
                if instruction_index in selected:
                    spread.append({'candidate_index':number,'instruction_ordinal_zero_based':instruction_index,
                                   'elf_va':srow['elf_va'],'word_sha256':hashlib.sha256(word).hexdigest(),
                                   'source_mnemonic':ins.mnemonic,'ghidra_mnemonic':gh_mnemonic,
                                   'pcode_ops':len(erow['pcode_ops']),
                                   'pcode_sha256':hashlib.sha256(
                                       '\n'.join(erow['pcode_ops']).encode()).hexdigest()})
            raw_ops = sum(len(r['pcode_ops']) for r in raw['instruction_pcode']
                          if isinstance(r.get('pcode_ops'),list))
            local_ops = sum(len(r['pcode_ops']) for r in effective_rows)
            if raw_ops != raw['ghidra_pcode_ops'] or (
                    number in CORRECTIONS and local_ops != corrected[number]['full_fde_pcode_ops']):
                raise RuntimeError(f'p-code operation census differs #{number}')
            source_slots += len(decoded)
            effective_slots += len(effective_rows)
            effective_ops += local_ops
            results.append({'index':number,'selected_zero_index':number,'elf_va':target['elf_va'],
                            'fde_size_bytes':size,'original_pt_load_body_sha256':digest,
                            'copied_ghidra_memory_sha256':raw['ghidra_memory_sha256'],
                            'original_instruction_slots':len(decoded),
                            'source_direct_call_count':source['source_direct_call_count'],
                            'source_indirect_call_count':source['source_indirect_call_count'],
                            'source_call_sites':expected_calls,
                            'original_ghidra_instruction_count':raw['ghidra_instruction_count'],
                            'original_ghidra_missing_instruction_count':missing,
                            'effective_ghidra_pcode_slots':len(effective_rows),
                            'effective_ghidra_pcode_operations':local_ops,
                            'original_ghidra_body_membership_bytes':bits.count('1'),
                            'original_ghidra_body_missing_ranges':gaps(bits),
                            'extra_body_ranges':extra_ranges,
                            'other_function_overlap_bytes':0,
                            'transient_full_fde_body_membership_bytes':size if number in CORRECTIONS else None,
                            'nonempty_c_like':bool(c_text.strip()),
                            'effective_c_like_sha256':hashlib.sha256(c_text.encode()).hexdigest(),
                            'effective_c_like_chars':len(c_text),
                            'boundary_classification':classification,
                            'ordinary_spread_sample_count':len(selected),
                            'raw_ghidra_sha256':sha256(raw_path),
                            'corrective_ghidra_sha256':correction_sha,
                            'fresh_postrollback_ghidra_sha256':post_sha})
    if (len(results) != 62 or source_slots != 9467 or effective_slots != 9467 or
            original_full_bodies != 55 or corrected_full_bodies != 7 or
            original_missing_slots != 98 or original_ghidra_slots != 9467-98 or
            len(spread) < math.ceil(.1*source_slots) or
            sum(row['ordinary_spread_sample_count'] for row in results) != len(spread)):
        raise RuntimeError('62-candidate coverage/membership/spread totals differ')
    verification = {'task_id':'TASK_201','revision':1,'generated_at':now(),
                    'original_source_sha256':SOURCE_SHA,'target_manifest_sha256':TARGETS_SHA,
                    'original_fde_candidate_bodies_verified':62,
                    'original_arm64_instruction_words_verified':source_slots,
                    'original_ghidra_analyzed_instruction_positions':original_ghidra_slots,
                    'original_ghidra_missing_instruction_positions':original_missing_slots,
                    'effective_ghidra_pcode_instruction_positions':effective_slots,
                    'effective_ghidra_pcode_operations':effective_ops,
                    'nonempty_effective_c_like_texts':62,
                    'existing_ghidra_bodies_contain_every_fde_byte':original_full_bodies,
                    'transient_full_fde_metadata_assumptions':corrected_full_bodies,
                    'fresh_session_original_metadata_and_memory_replays':7,
                    'source_direct_call_sites':source_direct_calls,
                    'source_indirect_call_sites':source_indirect_calls,
                    'excluded_oversized_global_indices':list(EXCLUDED_OVERSIZED),
                    'verified_behavior_candidates':0,
                    'ordinary_spread_instruction_sample_count':len(spread),
                    'ordinary_spread_instruction_sample_percent':round(100*len(spread)/source_slots,2),
                    'ordinary_spread_samples':spread,'rows':results,
                    'original_and_private_project_files_byte_verified':len(index['project_files']),
                    'command_receipts':[sha256(REPORT/f'{x}_command.json') for x in
                                        ('ghidra_batch1','ghidra_batch2','ghidra_correction',
                                         'ghidra_postrollback')],
                    'headless_process_seconds':[first['elapsed_seconds'],second['elapsed_seconds'],
                                                correction['elapsed_seconds'],
                                                post['elapsed_seconds']],
                    'fresh_imports':0,
                    'limits':'Unwind FDE ranges do not prove unique function boundaries. '
                             'Transient full-FDE function metadata is an assumption, not semantics. '
                             'Ghidra C-like output may omit paths. No behavior or pixel parity.'}
    write_json(REPORT/'WORKER_VERIFICATION.json',verification)
    master = ('# TASK_201 R1 — MTFilterKernel nonexport FDE indices 320..383, '
              'excluding two oversized bodies\n\n'
              '**Result: PARTIAL static research, 62 pinned candidate ranges processed.** '
              'The original SO, each selected unwind FDE/PT_LOAD body and all 9,467 '
              'AArch64 instruction positions were checked. On a byte-verified private '
              f'Ghidra project, effective p-code covers 9,467 positions ({effective_ops:,} '
              'operations), with 62 nonempty C-like texts. A deterministic spread check '
              f're-read {len(spread):,}/9,467 source positions '
              f'({100*len(spread)/9467:.2f}%). The original instruction stream includes '
              f'{source_direct_calls} direct and {source_indirect_calls} indirect call sites; '
              'addresses and operands appear in per-candidate source evidence.\n\n'
              'Pre-existing Ghidra function bodies cover every FDE byte in 55/62 '
              'candidates. Seven (#347, #348, #357, #358, #360, #361, #363) have truncated/discontinuous '
              'metadata and 98 missing analyzed instruction positions, with no '
              'other-function overlap. A transient full-FDE metadata pass recovered '
              'those seven instruction/p-code sets in the private read-only project. '
              'The same-session Ghidra API did not show restored metadata after rollback; '
              'a separate fresh read-only process reproduced original function names, '
              'starts, body bitmaps and source-memory hashes for all seven. These '
              'are boundary-limited reconstructions, not verified unique functions '
              'or behavior.\n\n'
              'Global zero-based indices 349 and 362 have two oversized '
              'bodies (11,364 bytes total) and are explicitly excluded and unanalyzed '
              'by this task. This is 62 of 511 nonexport FDE candidates; earlier '
              'accepted slices are disjoint, and 129 candidates remain outside '
              'all five slices, including earlier and current exclusions. No product '
              'behavior, binary equivalence, image/pixel parity, Phase PASS, all-45-SO '
              'completion, V4 or P7 readiness is claimed. No new import, production '
              'edit, commit or push. Independent CEO review is pending.\n')
    atomic_bytes(REPORT/'01_MASTER_REPORT.md',master.encode('utf-8'))
    audit = (REPORT/'00_AUDIT_INDEX.md').read_text(encoding='utf-8')
    audit += ('\nFinal evidence: 62 `source_assembly/` rows with call sites, 62 '
              '`ghidra_raw_batch{1,2}/` rows, seven `ghidra_correction_raw/` '
              'rows, seven `ghidra_postrollback_raw/` rows, source/project index, '
              'raw command/stdout/stderr receipts, and `WORKER_VERIFICATION.json` with per-byte '
              'membership, output hashes and a spread source-instruction sample. '
              '`COMPLETE.json` hashes every immutable report/code/scratch artifact.\n')
    atomic_bytes(REPORT/'00_AUDIT_INDEX.md',audit.encode('utf-8'))
    write_json(REPORT/'PROGRESS.json',{'task_id':'TASK_201','revision':1,
               'status':'SEALED_PARTIAL_STATIC_RESEARCH_CANDIDATE','generated_at':now(),
               'fde_bodies_verified':62,'original_instruction_positions':source_slots,
               'effective_ghidra_pcode_positions':effective_slots,
               'effective_ghidra_pcode_operations':effective_ops,
               'nonempty_c_like':62,'transient_full_fde_metadata_assumptions':7,
               'fresh_postrollback_replays':7,'spread_instruction_sample_count':len(spread),
               'excluded_oversized_global_indices':list(EXCLUDED_OVERSIZED),
               'fresh_imports':0,'disposition':'AWAITING_INDEPENDENT_CEO_REVIEW'})
    report_files = {p.relative_to(REPORT).as_posix():sha256(p)
                    for p in sorted(REPORT.rglob('*')) if p.is_file()
                    and p.name not in {'COMPLETE.json','PROGRESS.json','PROGRESS.md'}}
    code_files = {p.relative_to(ROOT).as_posix():sha256(p)
                  for p in sorted(SCRIPTS.rglob('*')) if p.is_file() and p.suffix in {'.py','.java'}}
    scratch_files = {p.relative_to(ROOT).as_posix():sha256(p)
                     for p in sorted(SCRATCH.rglob('*')) if p.is_file()}
    if sum(p.stat().st_size for p in REPORT.rglob('*') if p.is_file()) > 134_217_728:
        raise RuntimeError('report exceeds task cap')
    complete = {'schema_version':'2.1.2','task_id':'TASK_201','revision':1,
                'status':'COMPLETE','research_result':'PARTIAL_BOUNDARY_SEVEN_TRANSIENT_FULL_FDE_TWO_OVERSIZED_EXCLUDED',
                'generated_at':now(),'agent_id':AGENT,'lease_id':LEASE_ID,
                'fencing_token':FENCE,'standard_path':str(STANDARD),'standard_sha256':STANDARD_SHA,
                'task_sha256':TASK_SHA,'target_manifest_sha256':TARGETS_SHA,
                'original_so_sha256':SOURCE_SHA,'original_fde_candidate_bodies_verified':62,
                'original_instruction_words_verified':source_slots,
                'effective_ghidra_pcode_instruction_positions':effective_slots,
                'effective_ghidra_pcode_operations':effective_ops,
                'nonempty_c_like_outputs':62,'original_full_fde_body_membership':55,
                'transient_full_fde_metadata_assumptions':7,
                'fresh_session_original_metadata_and_memory_replays':7,
                'excluded_oversized_global_indices':list(EXCLUDED_OVERSIZED),
                'source_direct_call_sites':source_direct_calls,
                'source_indirect_call_sites':source_indirect_calls,
                'ordinary_spread_instruction_sample_count':len(spread),
                'fresh_imports':0,'verified_behavior_candidates':0,
                'files':report_files,'code_files':code_files,'scratch_files':scratch_files,
                'limits':'FDE candidate boundaries and C-like texts do not prove unique functions or behavior; '
                         'Seven transient full-FDE reconstructions are boundary-limited; two oversized bodies are excluded.'}
    write_json(REPORT/'COMPLETE.json',complete)
    print(json.dumps({'status':'SEALED_PARTIAL_STATIC_RESEARCH_CANDIDATE',
                      'original_fde_bodies':62,'source_and_effective_pcode_positions':source_slots,
                      'effective_pcode_ops':effective_ops,'nonempty_c_like':62,
                      'transient_full_fde_metadata_assumptions':7,
                      'fresh_postrollback_replays':7,'spread_samples':len(spread),
                      'complete_sha256':sha256(REPORT/'COMPLETE.json')}))


if __name__ == '__main__':
    main()
