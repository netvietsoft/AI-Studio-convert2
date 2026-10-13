"""Recheck TASK_204 source/output provenance and seal a bounded research package."""
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

CORRECTIONS = (405, 406, 407, 408)
EXCLUDED_OVERSIZED = ()
# Capstone and Ghidra choose different textual aliases for the same AArch64 word.
ALIASES = {('b.hs', 'b.cs'), ('b.lo', 'b.cc'), ('cmp', 'negs'),
           ('mov', 'orr'), ('orr', 'mov'), ('mov', 'dup'),
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
    if (command['task_id'] != 'TASK_204' or command['revision'] != 1 or
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
    if (len(manifest['targets']) != 127 or len(index['selected_candidate_rows']) != 127 or
            index['task_sha256'] != TASK_SHA or index['target_manifest_sha256'] != TARGETS_SHA or
            index['standard_sha256'] != STANDARD_SHA or index['actor'] != AGENT or
            index['lease_id'] != LEASE_ID or index['fencing_token'] != FENCE or
            index['source_sha256'] != SOURCE_SHA or sha256(SOURCE) != SOURCE_SHA or
            index['all_fde_count'] != 2873 or index['all_nonexport_fde_candidates'] != 511 or
            index['defined_nonzero_export_vas'] != 2362):
        raise RuntimeError('pinned source/task/manifest metadata differs')
    for batch in range(1, 6):
        if (index['batch_files'][str(batch)]['sha256'] !=
                sha256(SCRATCH / f'target_batch_{batch}.tsv')):
            raise RuntimeError('target batch TSV changed')
    batches = [check_command(f'ghidra_batch{batch}', 'ExtractInternal204.java',
                             f'ghidra_raw_batch{batch}', index['batch_files'][str(batch)]['count'])
               for batch in range(1, 6)]
    correction = check_command('ghidra_correction', 'RepairMembership204.java',
                               'ghidra_correction_raw', 4)
    post = check_command('ghidra_postrollback', 'CheckOriginalMembership204.java',
                         'ghidra_postrollback_raw', 4)
    if index['project_source'] != str(PROJECT) or index['project_copy'] != str(SCRATCH / 'ghidra_project'):
        raise RuntimeError('project source/copy paths differ')
    prior_report = ROOT / 'RULES/REPORT/TASK_201_REPORT_R1'
    prior_complete = prior_report / 'COMPLETE.json'
    prior_index = prior_report / 'source_project_index.json'
    if (sha256(prior_complete) !=
            'c1ed5968c93cc30bb4e1caa8e991dac870dbaeae084e78b8866959199e5933db' or
            index['prior_task201_r1_complete_sha256'] != sha256(prior_complete) or
            index['prior_task201_r1_source_project_index_sha256'] != sha256(prior_index) or
            index['excluded_oversized_global_indices'] != list(EXCLUDED_OVERSIZED) or
            manifest['excluded_oversized_bytes'] != 0):
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
        selected_indices = list(range(384, 511))
        if (len(fdes) != 2873 or len(starts) != 2362 or len(nonexports) != 511 or
                manifest['excluded_oversized_global_indices'] != list(EXCLUDED_OVERSIZED) or
                [x['global_nonexport_fde_index'] for x in manifest['targets']] != selected_indices or
                pinned != [nonexports[i] for i in selected_indices]):
            raise RuntimeError('exact 127-candidate original source selection differs')
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
            batch = (ordinal - 1) // 26 + 1
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
    from seal_tail import finish
    frame = locals()
    names = ('manifest','index','results','spread','source_slots','original_ghidra_slots','original_missing_slots','effective_slots','effective_ops','original_full_bodies','corrected_full_bodies','source_direct_calls','source_indirect_calls','batches','correction','post')
    return finish(**{name: frame[name] for name in names})


if __name__ == '__main__':
    main()
