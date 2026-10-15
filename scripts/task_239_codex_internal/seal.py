"""Independently recheck TASK_239 evidence and seal a truthful partial report."""
from __future__ import annotations

import json
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile

from common import (AGENT, FENCE, LEASE_ID, REPORT, SCRATCH, SCRIPTS, SOURCE, SOURCE_SHA,
                    STANDARD, STANDARD_SHA, TARGETS, TARGETS_SHA, TASK_SHA,
                    atomic_bytes, check_lease, now, sha256, write_json)


def require(ok: bool, reason: str) -> None:
    if not ok:
        raise RuntimeError(reason)


def read(path: Path) -> dict:
    return json.loads(path.read_text(encoding='utf8'))


def only(folder: Path) -> tuple[Path, dict]:
    files = list(folder.glob('*.json'))
    require(len(files) == 1, f'exactly one output required: {folder}')
    return files[0], read(files[0])


def main() -> None:
    check_lease()
    manifest = read(TARGETS)
    index = read(REPORT / 'source_project_index.json')
    require(manifest['selected_count'] == 11 and len(manifest['targets']) == 11,
            'manifest target count')
    require(index['task_sha256'] == TASK_SHA and
            index['target_manifest_sha256'] == TARGETS_SHA and
            index['source_sha256'] == SOURCE_SHA, 'source index pins')
    targets = manifest['targets']
    indices = [int(t['global_index']) for t in targets]
    require(indices == [450,499,555,2293,2775,2776,3106,3132,3134,3285,3523],
            'exact task target selection')
    project = Path(index['project_copy'])
    for row in index['project_files']:
        require(sha256(project / row['relative_path']) == row['sha256'],
                'private project changed: ' + row['relative_path'])
    correction_receipt = read(REPORT / 'ghidra_correction_retry_command.json')
    require(correction_receipt['status'] == 'OUTPUT_READY' and
            correction_receipt['output_files'] == 8 and
            correction_receipt['project_metadata_unchanged'] and
            correction_receipt['max_cpu'] == 1 and correction_receipt['max_heap'] == '1G' and
            correction_receipt['max_per_decompile_seconds'] == 15,
            'bounded correction receipt')
    first_attempt = read(REPORT / 'ghidra_correction_command.json')
    require(first_attempt['status'] == 'PARTIAL_OUTPUT' and
            first_attempt['output_files'] == 0 and
            'expected exact six safe oversized anomaly rows' in
            (REPORT / 'ghidra_correction_stdout.log').read_text(encoding='utf8'),
            'failed first attempt provenance')
    correction = {}
    for path in (REPORT / 'ghidra_correction_retry').glob('*.json'):
        row = read(path)
        key = row['index'] - 1
        require(key not in correction and key in indices, 'correction duplicate or foreign target')
        require(correction_receipt['output_hashes'][path.name] == sha256(path),
                'correction output hash')
        correction[key] = row
    require(len(correction) == 8, 'eight correction rows')
    require(all(row['same_session_function_metadata_restored'] is False
                for row in correction.values()),
            'eight same-session metadata restoration flags')
    cs = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    evidence = []
    with SOURCE.open('rb') as stream:
        elf = ELFFile(stream)
        fdes = [(int(x['initial_location']), int(x['address_range']))
                for x in elf.get_dwarf_info().EH_CFI_entries() if isinstance(x, FDE)]
        dyn = elf.get_section_by_name('.dynsym')
        exports = {int(x['st_value']) for x in dyn.iter_symbols()
                   if x['st_info']['type'] == 'STT_FUNC' and x['st_shndx'] != 'SHN_UNDEF'
                   and int(x['st_value']) > 0 and int(x['st_size']) > 0}
        nonexports = sorted(pair for pair in fdes if pair[0] not in exports)
        segments = [(int(s['p_vaddr']), int(s['p_filesz']), int(s['p_offset']))
                    for s in elf.iter_segments() if s['p_type'] == 'PT_LOAD']
        require(len(fdes) == 9981 and len(exports) == 3326 and
                len(nonexports) == 6655, 'independent source FDE/export census')
        for ordinal, t in enumerate(targets, 1):
            check_lease()
            key, va, size = int(t['global_index']), int(t['elf_va'],16), int(t['size_bytes'])
            require(nonexports[key] == (va,size), f'FDE index {key}')
            require(t['instruction_slots'] == size//4, f'ARM64 slots {key}')
            offsets = [off + va - base for base,length,off in segments
                       if base <= va and va+size <= base+length]
            require(len(offsets) == 1 and offsets[0] == int(t['file_offset'],16),
                    f'PT_LOAD map {key}')
            stream.seek(offsets[0]); body = stream.read(size)
            import hashlib
            require(len(body) == size and hashlib.sha256(body).hexdigest() == t['body_sha256'],
                    f'original bytes {key}')
            asm_path = REPORT / 'source_assembly' / f'{key+1:03d}_{va:x}.json'
            asm = read(asm_path)
            require(asm['source_body_sha256'] == t['body_sha256'] and
                    asm['fde_exact_match'] and not asm['other_fde_overlap'] and
                    not asm['export_body_overlap'] and len(asm['instructions']) == size//4,
                    f'source assembly metadata {key}')
            for slot, item in enumerate(asm['instructions']):
                addr = va + 4*slot
                word = body[4*slot:4*slot+4]
                decoded = list(cs.disasm(word, addr, count=1))
                require(item['elf_va'] == f'0x{addr:x}' and
                        item['word_hex'] == word.hex() and decoded and
                        item['assembly'] == f'{decoded[0].mnemonic} {decoded[0].op_str}'.strip(),
                        f'ARM64 word {key}:{slot}')
            batch = read(REPORT / f'ghidra_batch{ordinal}_command.json')
            raw_path, raw = only(REPORT / f'ghidra_raw_batch{ordinal}')
            fresh_receipt = read(REPORT / f'ghidra_fresh_batch{ordinal}_command.json')
            fresh_path, fresh = only(REPORT / f'ghidra_fresh_batch{ordinal}')
            for receipt, path, label in [(batch,raw_path,'raw'),
                                         (fresh_receipt,fresh_path,'fresh')]:
                hashes = receipt.get('raw_result_hashes', receipt.get('output_hashes',{}))
                require(receipt['status'] == 'OUTPUT_READY' and
                        hashes[path.name] == sha256(path) and
                        receipt['max_cpu'] == 1 and receipt['max_heap'] == '1G',
                        f'{label} bounded receipt/hash {key}')
            require(fresh_receipt['project_metadata_unchanged'], f'fresh project rollback {key}')
            for row in (raw,fresh):
                require(row['index'] == key+1 and row['elf_va'] == t['elf_va'] and
                        row['size_bytes'] == size and
                        row['ghidra_memory_sha256'] == t['body_sha256'] and
                        row['instruction_slots'] == size//4 and
                        row['other_function_byte_count'] == 0 and
                        row['extra_body_address_count'] == 0,
                        f'Ghidra original candidate {key}')
            require(raw['fde_byte_membership_bits'] == fresh['fde_byte_membership_bits'] and
                    raw['fde_byte_membership_count'] == fresh['fde_byte_membership_count'],
                    f'fresh-session original membership {key}')
            partial = raw['fde_byte_membership_count'] < size
            corr = correction.get(key)
            require(partial == (corr is not None), f'partial/correction selection {key}')
            if corr:
                require(corr['memory_sha256'] == t['body_sha256'] and
                        corr['memory_unchanged_after_rollback'] and
                        corr['original_function_fde_membership_count'] ==
                        raw['fde_byte_membership_count'] and
                        corr['original_function_fde_membership_bits'] ==
                        raw['fde_byte_membership_bits'] and
                        corr['other_function_byte_count'] == 0 and
                        corr['temporary_old_function_removed'] and
                        corr['temporary_full_fde_function_created'] and
                        corr['corrected_function_fde_membership_count'] == size and
                        corr['corrected_function_fde_membership_bits'] == '1'*size and
                        corr['full_fde_instruction_count'] == size//4,
                        f'transient correction evidence {key}')
            c_like = bool(corr['c_like_nonempty'] if corr else raw['c_like_nonempty'])
            error = corr['error'] if corr else raw['decompile_error']
            evidence.append({
                'global_zero_based_index':key, 'one_based_ghidra_row':key+1,
                'elf_va':t['elf_va'], 'size_bytes':size, 'source_body_sha256':t['body_sha256'],
                'source_instruction_words_verified':size//4,
                'raw_membership_bytes':raw['fde_byte_membership_count'],
                'transient_full_fde_membership_bytes':
                    corr['corrected_function_fde_membership_count'] if corr else None,
                'raw_c_like_nonempty':raw['c_like_nonempty'],
                'transient_c_like_nonempty':corr['c_like_nonempty'] if corr else None,
                'effective_c_like_nonempty':c_like, 'decompile_error':error,
                'boundary_classification':raw['boundary_classification'],
                'research_classification': 'BOUNDED_DECOMPILATION_TIMEOUT_PARTIAL'
                    if not c_like else 'STATIC_C_LIKE_BOUNDARY_AND_BEHAVIOR_UNPROVEN',
                'source_assembly':asm_path.relative_to(REPORT).as_posix(),
                'raw_output':raw_path.relative_to(REPORT).as_posix(),
                'fresh_output':fresh_path.relative_to(REPORT).as_posix(),
                'correction_output': f'ghidra_correction_retry/{key+1}_{va:x}.json'
                    if corr else None,
            })
    require(sum(x['size_bytes'] for x in evidence)==86800 and
            sum(x['source_instruction_words_verified'] for x in evidence)==21700,
            'total source bytes/words')
    require(sum(x['effective_c_like_nonempty'] for x in evidence)==9 and
            [x['global_zero_based_index'] for x in evidence
             if not x['effective_c_like_nonempty']]==[3134,3285],
            'truthful timeout classification')
    require(sum(x['raw_membership_bytes'] < x['size_bytes'] for x in evidence)==8,
            'eight raw partial memberships')
    code_paths = sorted(p for p in SCRIPTS.iterdir()
                        if p.is_file() and p.suffix in ('.py', '.java'))
    require(len(code_paths) == 8, 'eight task-owned source files')
    write_json(REPORT / 'candidate_evidence.json', evidence)
    write_json(REPORT / 'evidence_summary.json', {
        'task_id':'TASK_239','revision':1,'source_sha256':SOURCE_SHA,
        'target_manifest_sha256':TARGETS_SHA,'targets_verified':11,
        'original_bytes_verified':86800,'original_ARM64_words_verified':21700,
        'ordinary_provenance_recheck_count':11,
        'ordinary_provenance_recheck_fraction':1.0,
        'raw_preexisting_full_body_ranges':3,'raw_partial_body_ranges':8,
        'transient_full_fde_reconstructions':8,
        'same_session_metadata_restored':False,
        'fresh_session_original_membership_verified':11,
        'task_owned_code_files':len(code_paths),
        'nonempty_c_like_outputs':9,'timed_out_global_indices':[3134,3285],
        'behaviorally_equivalent_functions_verified':0,
        'first_correction_attempt':'FAILED_GUARD_NO_OUTPUT_PRESERVED',
        'research_result':'PARTIAL_STATIC_RESEARCH_TWO_TIMEOUTS_ALL_BOUNDARIES_UNPROVEN'})
    audit = (f'# TASK_239 R1 audit index\n\nCanonical Standard fully read: `{STANDARD}`; '
             f'SHA-256 `{STANDARD_SHA}`. Task SHA-256 `{TASK_SHA}`; manifest SHA-256 '
             f'`{TARGETS_SHA}`. Worker `{AGENT}`, lease `{LEASE_ID}`, fence `{FENCE}`.\n\n'
             'All 11 original ELF FDE/PT_LOAD bodies and all 21,700 ARM64 words were '
             'independently rechecked. Every candidate (100%, exceeding the 10% provenance '
             'sample) was rechecked against its raw and fresh-session Ghidra output. '
             f'All {len(code_paths)} task-owned source files are SHA-256 pinned in '
             '`COMPLETE.json` under `code_files`. '
             'See `source_project_index.json`, `source_assembly/`, per-batch receipts/logs, '
             '`ghidra_correction_retry/`, and `candidate_evidence.json`. '
             'The failed initial correction attempt and successful retry are both retained.\n')
    atomic_bytes(REPORT / '00_AUDIT_INDEX.md', audit.encode('utf8'))
    report = ('# TASK_239 R1 — oversized ImageCodec internal candidates\n\n'
              'The 11 exact nonexport FDE candidates cover 86,800 original bytes and '
              '21,700 independently verified ARM64 words. Three had full pre-existing '
              'Ghidra body membership; eight had partial/discontiguous membership. '
              'A rollback-only full-FDE metadata pass covered all eight, and fresh-session '
              'checks showed original function membership again and copied project '
              'file hashes stayed unchanged. The correction output records '
              '`same_session_function_metadata_restored=false` for all eight; '
              'restoration is supported by the separate fresh sessions, not by '
              'same-session metadata inspection. '
              'Nine candidates have nonempty static C-like output. The two largest, '
              'global zero-based indices **3134** and **3285**, hit the 15-second '
              'decompile limit even after full-FDE reconstruction and remain incomplete.\n\n'
              'The first correction command produced no rows because a copied script '
              'retained the previous task’s six-row guard; its log and receipt remain in '
              'the package. The corrected eight-row retry produced all eight records. '
              'All eleven later fresh-session records matched the original Ghidra '
              'membership, and copied project file hashes stayed unchanged.\n\n'
              '**Research result: PARTIAL.** Static FDE ranges and Ghidra C-like text do '
              'not establish exact source-function boundaries or behavioral parity. '
              'No production code was changed, no Phase PASS or V4 release is claimed.\n')
    atomic_bytes(REPORT / '01_MASTER_REPORT.md', report.encode('utf8'))
    files = {p.relative_to(REPORT).as_posix():sha256(p)
             for p in REPORT.rglob('*') if p.is_file() and p.name not in
             ('COMPLETE.json', 'PROGRESS.json')}
    size_total = sum((REPORT / name).stat().st_size for name in files)
    require(size_total <= 134217728, 'report size bound')
    write_json(REPORT / 'COMPLETE.json', {
        'schema_version':'2.1.2','task_id':'TASK_239','revision':1,
        'status':'COMPLETE','research_result':'PARTIAL_STATIC_RESEARCH_TWO_TIMEOUTS',
        'generated_at':now(),'agent_id':AGENT,'lease_id':LEASE_ID,'fencing_token':FENCE,
        'standard_path':str(STANDARD),'standard_sha256':STANDARD_SHA,
        'task_sha256':TASK_SHA,'target_manifest_sha256':TARGETS_SHA,
        'original_so_sha256':SOURCE_SHA,'original_fde_candidate_bodies_verified':11,
        'original_instruction_words_verified':21700,
        'nonempty_c_like_outputs':9,'timed_out_global_indices':[3134,3285],
        'behaviorally_equivalent_functions_verified':0,
        'report_bytes_excluding_seal':size_total,'files':files,
        'code_files':{p.relative_to(SCRIPTS.parents[1]).as_posix():sha256(p)
                      for p in code_paths}})
    print(json.dumps({'status':'SEALED_PARTIAL_REVIEW_CANDIDATE',
                      'files':len(files),'report_bytes':size_total,
                      'bodies':11,'words':21700,'c_like':9,
                      'timed_out':[3134,3285]}))


if __name__=='__main__':
    main()
