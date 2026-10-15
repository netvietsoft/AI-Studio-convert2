"""Recheck every TASK_228 native byte/word and seal a truthful static report."""
from __future__ import annotations

import hashlib
import json
import math
from collections import Counter
from pathlib import Path

from common import (AGENT, FENCE, LEASE_ID, REPORT, ROOT, SCRATCH, SOURCE,
                    SOURCE_SHA, STANDARD, STANDARD_SHA, TARGETS, TARGETS_SHA,
                    TASK_SHA, check_lease, now, sha256, write_json, atomic_bytes)


def require(ok: bool, label: str) -> None:
    if not ok:
        raise RuntimeError(label)


def main() -> None:
    check_lease()
    require(not (REPORT / 'COMPLETE.json').exists(), 'already sealed')
    canonical_read_at = now()
    require(sha256(STANDARD) == STANDARD_SHA, 'canonical changed')
    manifest = json.loads(TARGETS.read_text(encoding='utf8'))
    targets = {x['global_index']: x for x in manifest['targets']}
    require(len(targets) == 512 and set(targets) ==
            set(range(1025, 1537)), 'exact 512 target selection')
    require(manifest['skipped_in_slice'] == [], 'unexpected skipped candidate')
    index = json.loads((REPORT / 'source_project_index.json').read_text(encoding='utf8'))
    require(index['source_sha256'] == SOURCE_SHA and
            index['target_manifest_sha256'] == TARGETS_SHA and
            index['task_sha256'] == TASK_SHA, 'source/project index binding')
    original = SOURCE.read_bytes()
    require(hashlib.sha256(original).hexdigest() == SOURCE_SHA, 'original ELF hash')
    project = Path(index['project_copy'])
    project_current = {}
    for item in index['project_files']:
        current = sha256(project / item['relative_path'])
        require(current == item['sha256'], 'Ghidra project changed: ' + item['relative_path'])
        project_current[item['relative_path']] = current
    raws: dict[int, tuple[dict, Path]] = {}
    batch_receipts = []
    for batch in range(1, 17):
        receipt_path = REPORT / f'ghidra_batch{batch}_command.json'
        rec = json.loads(receipt_path.read_text(encoding='utf8'))
        require(rec['status'] == 'OUTPUT_READY' and rec['exit_code'] == 0 and
                rec['raw_result_files'] == 32 and rec['fencing_token'] == FENCE and
                rec['lease_id'] == LEASE_ID and rec['source_sha256'] == SOURCE_SHA and
                rec['max_cpu'] == 1 and rec['max_heap'] == '1G' and
                rec['max_decompile_seconds_per_candidate'] == 15,
                f'headless batch receipt {batch}')
        require(rec['script_sha256'] == sha256(ROOT / 'scripts/task_228_codex_internal/ExtractInternal228.java') and
                rec['target_tsv_sha256'] == sha256(SCRATCH / f'target_batch_{batch}.tsv') and
                rec['stdout_sha256'] == sha256(REPORT / f'ghidra_batch{batch}_stdout.log') and
                rec['stderr_sha256'] == sha256(REPORT / f'ghidra_batch{batch}_stderr.log'),
                f'headless batch command/log/script hash {batch}')
        require(len(rec['raw_result_hashes']) == 32, 'raw receipt count')
        for name, digest in rec['raw_result_hashes'].items():
            path = REPORT / f'ghidra_raw_batch{batch}' / name
            require(sha256(path) == digest, 'raw receipt hash: ' + name)
            raw = json.loads(path.read_text(encoding='utf8'))
            idx = raw['index'] - 1
            require(idx in targets and idx not in raws, 'duplicate/wrong raw index')
            raws[idx] = (raw, path)
        batch_receipts.append({'batch': batch, 'command_sha256': sha256(receipt_path),
                               'stdout_sha256': rec['stdout_sha256'],
                               'stderr_sha256': rec['stderr_sha256'],
                               'raw_results': 32, 'elapsed_seconds': rec['elapsed_seconds']})
    require(len(raws) == 512, '512 unique raw rows')

    gap_meta = json.loads((REPORT / 'gap_candidates.json').read_text(encoding='utf8'))
    partial_indices = sorted(i for i, (raw, _) in raws.items()
                             if raw['fde_byte_membership_count'] != raw['size_bytes'])
    require(len(partial_indices) == 247 and
            gap_meta['global_zero_based_indices'] == partial_indices and
            gap_meta['unsafe_overlap_global_indices'] == [] and
            gap_meta['all_partial_count'] == 247 and
            gap_meta['measured_missing_body_bytes'] == 41792 and
            gap_meta['measured_missing_listing_slots'] == 10448 and
            gap_meta['target_tsv_sha256'] == sha256(SCRATCH / 'correction_targets.tsv'),
            '247 measured safe gaps')

    correction_steps = []
    corrections: dict[int, tuple[dict, Path]] = {}
    fresh_rows: dict[int, dict] = {}
    for name, expected_count, script, tsv in (
        ('ghidra_correction', 247, 'RepairMembership228.java', SCRATCH / 'correction_targets.tsv'),
        ('ghidra_fresh_batch1', 32, 'ExtractInternal228.java', SCRATCH / 'target_batch_1.tsv'),
        ('ghidra_fresh_batch2', 32, 'ExtractInternal228.java', SCRATCH / 'target_batch_2.tsv'),
        ('ghidra_fresh_batch3', 32, 'ExtractInternal228.java', SCRATCH / 'target_batch_3.tsv'),
        ('ghidra_fresh_batch4', 32, 'ExtractInternal228.java', SCRATCH / 'target_batch_4.tsv'),
        ('ghidra_fresh_batch5', 32, 'ExtractInternal228.java', SCRATCH / 'target_batch_5.tsv'),
        ('ghidra_fresh_batch6', 32, 'ExtractInternal228.java', SCRATCH / 'target_batch_6.tsv'),
        ('ghidra_fresh_batch7', 32, 'ExtractInternal228.java', SCRATCH / 'target_batch_7.tsv'),
        ('ghidra_fresh_batch8', 32, 'ExtractInternal228.java', SCRATCH / 'target_batch_8.tsv'),
        ('ghidra_fresh_batch9', 32, 'ExtractInternal228.java', SCRATCH / 'target_batch_9.tsv'),
        ('ghidra_fresh_batch10', 32, 'ExtractInternal228.java', SCRATCH / 'target_batch_10.tsv'),
        ('ghidra_fresh_batch11', 32, 'ExtractInternal228.java', SCRATCH / 'target_batch_11.tsv'),
        ('ghidra_fresh_batch12', 32, 'ExtractInternal228.java', SCRATCH / 'target_batch_12.tsv'),
        ('ghidra_fresh_batch13', 32, 'ExtractInternal228.java', SCRATCH / 'target_batch_13.tsv'),
        ('ghidra_fresh_batch14', 32, 'ExtractInternal228.java', SCRATCH / 'target_batch_14.tsv'),
        ('ghidra_fresh_batch15', 32, 'ExtractInternal228.java', SCRATCH / 'target_batch_15.tsv'),
        ('ghidra_fresh_batch16', 32, 'ExtractInternal228.java', SCRATCH / 'target_batch_16.tsv'),
    ):
        receipt_path = REPORT / f'{name}_command.json'
        rec = json.loads(receipt_path.read_text(encoding='utf8'))
        require(rec['status'] == 'OUTPUT_READY' and rec['exit_code'] == 0 and
                rec['output_files'] == expected_count and rec['fencing_token'] == FENCE and
                rec['lease_id'] == LEASE_ID and rec['source_sha256'] == SOURCE_SHA and
                rec['max_cpu'] == 1 and rec['max_heap'] == '1G' and
                rec['max_per_decompile_seconds'] == 15 and
                rec['script_sha256'] == sha256(ROOT / 'scripts/task_228_codex_internal' / script) and
                rec['target_tsv_sha256'] == sha256(tsv) and
                rec['stdout_sha256'] == sha256(REPORT / f'{name}_stdout.log') and
                rec['stderr_sha256'] == sha256(REPORT / f'{name}_stderr.log') and
                rec['project_files_before'] == project_current and
                rec['project_files_after'] == project_current and
                rec['project_metadata_unchanged'] and
                len(rec['output_hashes']) == expected_count,
                f'correction/fresh headless receipt {name}')
        for filename, digest in rec['output_hashes'].items():
            path = REPORT / name / filename
            require(sha256(path) == digest, f'correction/fresh raw hash {filename}')
            row = json.loads(path.read_text(encoding='utf8'))
            idx = row['index'] - 1
            if name == 'ghidra_correction':
                require(idx in partial_indices and idx not in corrections,
                        f'correction target {idx}')
                corrections[idx] = (row, path)
            else:
                require(idx in raws and idx not in fresh_rows,
                        f'fresh rollback target {idx}')
                fresh_rows[idx] = row
        correction_steps.append({'name': name, 'command_sha256': sha256(receipt_path),
                                 'output_files': expected_count,
                                 'project_metadata_unchanged': True,
                                 'elapsed_seconds': rec['elapsed_seconds']})
    require(set(corrections) == set(partial_indices) and len(fresh_rows) == 512,
            '247 correction/512 fresh-session rows')
    for idx, fresh in fresh_rows.items():
        raw = raws[idx][0]
        require(fresh['index'] == raw['index'] and fresh['elf_va'] == raw['elf_va'] and
                fresh['ghidra_memory_sha256'] == raw['ghidra_memory_sha256'] and
                fresh['fde_byte_membership_bits'] == raw['fde_byte_membership_bits'] and
                fresh['missing_analyzed_instruction_count'] == raw['missing_analyzed_instruction_count'] and
                fresh['function_body_total_address_count'] == raw['function_body_total_address_count'],
                f'fresh-session rollback membership/memory {idx}')

    ordered = sorted(targets)
    sample = sorted({ordered[round(j * (len(ordered)-1)/52)] for j in range(53)})
    require(len(sample) >= math.ceil(.10*512), 'ordinary spread sample <10%')
    per = []
    checks = []
    counts = Counter()
    for idx in ordered:
        check_lease()
        target = targets[idx]
        raw, raw_file = raws[idx]
        va = int(target['elf_va'], 16)
        off = int(target['file_offset'], 16)
        size = target['size_bytes']
        body = original[off:off+size]
        body_hash = hashlib.sha256(body).hexdigest()
        require(len(body) == size and body_hash == target['body_sha256'] and
                size % 4 == 0 and target['instruction_slots'] == size//4,
                f'original source range {idx}')
        asm_file = REPORT / 'source_assembly' / raw_file.name
        asm = json.loads(asm_file.read_text(encoding='utf8'))
        require(asm['selected_zero_index'] == idx and asm['index'] == idx+1 and
                asm['source_body_sha256'] == body_hash and asm['elf_va'] == target['elf_va'] and
                asm['capstone_decoded_slots'] == size//4 and
                len(asm['instructions']) == size//4 and
                not asm['other_fde_overlap'] and not asm['export_body_overlap'],
                f'Capstone/overlap record {idx}')
        for j, ins in enumerate(asm['instructions']):
            require(int(ins['elf_va'],16) == va + 4*j and
                    ins['word_hex'] == body[4*j:4*j+4].hex() and ins['assembly'],
                    f'original instruction word {idx}:{j}')
        require(raw['index'] == idx+1 and raw['elf_va'] == target['elf_va'] and
                raw['size_bytes'] == size and raw['instruction_slots'] == size//4 and
                raw['ghidra_memory_sha256'] == body_hash and
                raw['ghidra_instruction_count'] + raw['missing_analyzed_instruction_count'] == size//4 and
                raw['existing_exact_function_start'] and
                raw['boundary_classification'].startswith(
                    'EXACT_GHIDRA_FUNCTION_START_FDE_BOUNDARY_UNPROVEN') and
                len(raw['fde_byte_membership_bits']) == size and
                raw['fde_byte_membership_bits'].count('1') == raw['fde_byte_membership_count'] and
                raw['other_function_byte_count'] == 0 and
                raw['extra_body_address_count'] == 0,
                f'Ghidra memory/listing/function-body binding {idx}')
        is_partial = idx in partial_indices
        require(is_partial == (raw['fde_byte_membership_count'] < size) and
                (not is_partial or raw['boundary_classification'].endswith(
                    '_PARTIAL_OR_DISCONTIGUOUS_BODY' +
                    '')) and
                (is_partial or (raw['fde_byte_membership_bits'] == '1'*size and
                                raw['missing_analyzed_instruction_count'] == 0 and
                                not raw['fde_missing_body_ranges'])),
                f'raw partial/full boundary classification {idx}')
        require(raw['c_like_nonempty'] == bool(raw['c_like_text'].strip()) and
                (not raw['c_like_nonempty'] or not raw['decompile_error']),
                f'C-like/decompiler classification {idx}')
        correction_hash = None
        if is_partial:
            correction, correction_file = corrections[idx]
            require(correction['index'] == idx+1 and correction['elf_va'] == target['elf_va'] and
                    correction['size_bytes'] == size and correction['memory_sha256'] == body_hash and
                    correction['original_function_fde_membership_count'] == raw['fde_byte_membership_count'] and
                    correction['original_function_fde_membership_bits'] == raw['fde_byte_membership_bits'] and
                    correction['other_function_byte_count'] == 0 and
                    correction['temporary_old_function_removed'] and
                    correction['temporary_full_fde_function_created'] and
                    correction['corrected_function_fde_membership_count'] == size and
                    correction['corrected_function_fde_membership_bits'] == '1'*size and
                    correction['corrected_function_body_total_address_count'] == size and
                    correction['full_fde_instruction_count'] == size//4 and
                    correction['memory_unchanged_after_rollback'] and
                    correction['c_like_nonempty'] == bool(correction['c_like_text'].strip()) and
                    correction['c_like_nonempty'] and not correction['error'],
                    f'transient full-FDE correction {idx}')
            pcode_corr = correction['instruction_pcode']
            require(len(pcode_corr) == size//4 and
                    sum(len(x.get('pcode_ops', [])) for x in pcode_corr) == correction['full_fde_pcode_ops'],
                    f'correction p-code count {idx}')
            for j, ins in enumerate(pcode_corr):
                require(int(ins['database_va'],16) ==
                        int(raw['database_va'],16)+4*j and
                        bool(ins.get('assembly')) and isinstance(ins.get('pcode_ops'), list),
                        f'correction instruction position {idx}:{j}')
            require(idx in fresh_rows, f'fresh-session rollback absent {idx}')
            correction_hash = sha256(correction_file)
            counts['transient_full_fde_c_like'] += 1
            counts['transient_full_fde_pcode_ops'] += correction['full_fde_pcode_ops']
            counts['transient_full_fde_instruction_slots'] += size//4
        if idx in sample:
            pcode = raw['instruction_pcode']
            require(len(pcode) == size//4 and
                    sum(len(x.get('pcode_ops', [])) for x in pcode) == raw['ghidra_pcode_ops'],
                    f'ordinary p-code count {idx}')
            for j, ins in enumerate(pcode):
                require(int(ins['database_va'],16) ==
                        int(raw['database_va'],16)+4*j and
                        (bool(ins.get('assembly')) and isinstance(ins.get('pcode_ops'), list)
                         if not ins.get('missing_analyzed_instruction') else
                         not ins.get('assembly')),
                        f'ordinary p-code provenance {idx}:{j}')
            checks.append({'global_zero_based_index': idx,
                           'r1_style_one_based_row': idx+1, 'elf_va': target['elf_va'],
                           'source_body_sha256': body_hash,
                           'raw_sha256': sha256(raw_file),
                           'source_assembly_sha256': sha256(asm_file),
                           'pcode_instruction_positions': len(pcode),
                           'pcode_operations': raw['ghidra_pcode_ops'],
                           'c_like_sha256': hashlib.sha256(raw['c_like_text'].encode()).hexdigest()})
        counts['original_bytes'] += size
        counts['instruction_slots'] += size//4
        counts['ghidra_pcode_operations'] += raw['ghidra_pcode_ops']
        counts['nonempty_c_like'] += bool(raw['c_like_nonempty'])
        counts['raw_listing_slots'] += raw['ghidra_instruction_count']
        counts['raw_missing_listing_slots'] += raw['missing_analyzed_instruction_count']
        counts['raw_missing_body_bytes'] += size - raw['fde_byte_membership_count']
        counts['preexisting_full_body_ranges'] += not is_partial
        per.append({'global_zero_based_fde_index': idx, 'one_based_raw_row': idx+1,
                    'elf_va': target['elf_va'], 'size_bytes': size,
                    'original_body_sha256': body_hash,
                    'source_assembly_sha256': sha256(asm_file),
                    'ghidra_raw_sha256': sha256(raw_file),
                    'ghidra_pcode_operations': raw['ghidra_pcode_ops'],
                    'c_like_nonempty': raw['c_like_nonempty'],
                    'c_like_sha256': hashlib.sha256(raw['c_like_text'].encode()).hexdigest()
                        if raw['c_like_nonempty'] else None,
                    'decompile_error': raw['decompile_error'],
                    'preexisting_body_membership_bytes': raw['fde_byte_membership_count'],
                    'raw_missing_listing_slots': raw['missing_analyzed_instruction_count'],
                    'transient_full_fde_c_like_sha256':
                        hashlib.sha256(corrections[idx][0]['c_like_text'].encode()).hexdigest()
                        if is_partial else None,
                    'transient_correction_sha256': correction_hash,
                    'fresh_session_rollback_verified': idx in fresh_rows,
                    'ordinary_spread_rechecked': idx in sample,
                    'classification': ('PARTIAL_RAW_MEMBERSHIP_TRANSIENT_FULL_FDE_HYPOTHESIS'
                                       if is_partial else 'STATIC_C_LIKE_BOUNDARY_AND_BEHAVIOR_UNPROVEN')})
    require(counts['original_bytes'] == 171960 and counts['instruction_slots'] == 42990,
            'aggregate source totals')
    require(counts['preexisting_full_body_ranges'] == 265 and
            counts['raw_missing_body_bytes'] == 41792 and
            counts['raw_missing_listing_slots'] == 10448 and
            counts['transient_full_fde_c_like'] == 247 and
            counts['transient_full_fde_instruction_slots'] == 36967 and
            counts['transient_full_fde_pcode_ops'] == 122360,
            'partial/correction aggregate totals')
    raw_partial_pcode = sum(raws[i][0]['ghidra_pcode_ops'] for i in partial_indices)
    effective_pcode = counts['ghidra_pcode_operations'] - raw_partial_pcode + 122360
    write_json(REPORT / 'source_spread_recheck.json', {
        'task_id': 'TASK_228', 'revision': 1, 'sampled_count': len(sample),
        'total_candidate_count': 512, 'sample_fraction': len(sample)/512,
        'rule': 'spread across sorted candidate indices; each sampled raw p-code row position/count rechecked',
        'rows': checks})
    atomic_bytes(REPORT / 'candidate_evidence.jsonl',
                 ''.join(json.dumps(x, ensure_ascii=False)+'\n' for x in per).encode('utf8'))
    write_json(REPORT / 'evidence_summary.json', {
        'task_id': 'TASK_228', 'revision': 1, 'source_so_sha256': SOURCE_SHA,
        'target_manifest_sha256': TARGETS_SHA,
        'original_fde_candidate_bodies_verified': 512,
        'original_bytes_verified': counts['original_bytes'],
        'original_instruction_words_verified': counts['instruction_slots'],
        'ghidra_pcode_operations_recorded': counts['ghidra_pcode_operations'],
        'raw_partial_pcode_operations': raw_partial_pcode,
        'effective_full_fde_pcode_operations': effective_pcode,
        'nonempty_c_like_outputs': counts['nonempty_c_like'],
        'preexisting_full_body_ranges': 265,
        'partial_raw_membership_ranges': 247,
        'raw_missing_body_bytes': 41792,
        'raw_missing_listing_slots': 10448,
        'transient_full_fde_c_like_outputs': 247,
        'transient_full_fde_instruction_slots': 36967,
        'transient_full_fde_pcode_operations': 122360,
        'unresolved_other_function_overlap_global_indices': [],
        'unresolved_other_function_overlap_bytes': 0,
        'transient_correction_same_session_metadata_restored': 0,
        'fresh_session_rollback_rows_verified': 512,
        'correction_and_fresh_receipts': correction_steps,
        'unresolved_c_like_indices': [x['global_zero_based_fde_index'] for x in per
                                      if not x['c_like_nonempty']],
        'ordinary_spread_rechecked': sample,
        'ordinary_spread_fraction': len(sample)/512,
        'project_file_hashes_unchanged': project_current,
        'batch_receipts': batch_receipts,
        'skipped_oversized_global_indices_in_this_slice': [],
        'behaviorally_equivalent_functions_verified': 0,
        'boundary_limit': 'FDE and analyzed Ghidra function membership do not prove exact original semantic source-function boundary',
    })
    atomic_bytes(REPORT / '00_AUDIT_INDEX.md', (
        '# TASK_228 R1 audit index\n\n'
        f'Canonical Standard fully read at {canonical_read_at}: `{STANDARD}`; SHA-256 `{STANDARD_SHA}`.\n\n'
        f'Task SHA-256 `{TASK_SHA}`; target manifest SHA-256 `{TARGETS_SHA}`. '
        f'Worker `{AGENT}`, lease `{LEASE_ID}`, fencing token `{FENCE}`.\n\n'
        'Source index, 512 per-candidate Capstone source records, 512 raw Ghidra output records, '
        'sixteen batch receipts, a 247-row transient correction and sixteen fresh-session rollback '
        'receipts, candidate ledger and spread recheck are included. All 9 copied project '
        'hashes remained unchanged after headless processing.\n').encode('utf8'))
    atomic_bytes(REPORT / '01_MASTER_REPORT.md', (
        '# TASK_228 R1 — libPVGImageCodec nonexport FDE continuation\n\n'
        'The next 512 pinned VA-sorted nonexport FDE candidate spans, global zero-based indices '
        '1025–1536 with no exclusion in this slice, cover 171,960 original ELF bytes / 42,990 '
        'AArch64 instruction words. All source-body hashes and every original instruction word '
        'were reverified against the pinned ELF and PT_LOAD mapping. No selected range overlaps '
        'another FDE or an exported body in the source census.\n\n'
        f'Sixteen sequential private Ghidra headless batches produced {counts["nonempty_c_like"]}/512 nonempty C-like outputs '
        f'and {counts["ghidra_pcode_operations"]:,} raw recorded p-code operations. All have exact '
        'Ghidra function starts. Pre-existing Ghidra body membership covers the entire FDE '
        'for 265/512. The other 247 have partial or discontiguous pre-existing membership, missing '
        '41,792 bytes and 10,448 analyzed instruction slots in aggregate. Those source bytes are '
        'still independently verified and Capstone-decoded. A transient rollback-only correction '
        'made a full FDE function for all 247 nonoverlapping partial ranges and yielded 247 nonempty '
        'C-like hypotheses, 36,967 full-span listing slots and 122,360 p-code operations. '
        'Same-session function metadata restoration was false; 512 separate fresh-session rows, '
        'including all 247 partials, '
        'reproduced original membership and memory, and all 9 private project file hashes stayed '
        'unchanged. Neither route proves exact original source-function boundaries or behavior. '
        f'A spread sample of {len(sample)}/512 ({len(sample)/512:.2%}) independently rechecked '
        'every sampled p-code row address and operation count against raw output. Source bytes and '
        'instruction words were checked 512/512. Raw commands, logs, generator hash and all 9 '
        'private project file hashes were rechecked.\n\n'
        'There was no oversized exclusion in this slice. Earlier open oversized indices '
        '450, 499 and 555, and index 465 lacking C-like, remain separate limitations. '
        'These C-like outputs are static research, not source-equivalent algorithms or behavior '
        'parity. No product Phase PASS, V4 implementation, or full SO completion is claimed. '
        'This report awaits independent CEO review before any commit/push.\n\n'
        '`candidate_evidence.jsonl` binds each range/hash/output status; '
        '`source_spread_recheck.json` records the ordinary provenance sample; '
        '`evidence_summary.json` records totals and command/project checks.\n').encode('utf8'))
    write_json(REPORT / 'PROGRESS.json', {
        'task_id': 'TASK_228', 'revision': 1,
        'status': 'REVIEW_CANDIDATE_AWAITING_CEO', 'generated_at': now(),
        'original_fde_candidates_verified': 512,
        'nonempty_c_like_outputs': counts['nonempty_c_like'],
        'original_instruction_words_verified': 42990,
        'preexisting_full_body_ranges': 265,
        'partial_raw_membership_ranges': 247,
        'transient_full_fde_c_like_outputs': 247,
        'unresolved_other_function_overlap_global_indices': [],
        'ordinary_spread_recheck_count': len(sample),
    })
    check_lease()
    files = {p.relative_to(REPORT).as_posix(): sha256(p)
             for p in sorted(REPORT.rglob('*')) if p.is_file() and
             p.name not in ('COMPLETE.json', 'PROGRESS.json')}
    report_bytes = sum(p.stat().st_size for p in REPORT.rglob('*') if p.is_file())
    require(report_bytes < 134217728, 'report byte cap')
    write_json(REPORT / 'COMPLETE.json', {
        'schema_version': '2.1.2', 'task_id': 'TASK_228', 'revision': 1,
        'status': 'COMPLETE',
        'research_result': 'PARTIAL_STATIC_RESEARCH_BOUNDARIES_UNPROVEN',
        'generated_at': now(), 'agent_id': AGENT,
        'lease_id': LEASE_ID, 'fencing_token': FENCE,
        'standard_path': str(STANDARD), 'standard_sha256': STANDARD_SHA,
        'task_sha256': TASK_SHA, 'target_manifest_sha256': TARGETS_SHA,
        'original_so_sha256': SOURCE_SHA,
        'original_fde_candidate_bodies_verified': 512,
        'original_instruction_words_verified': 42990,
        'nonempty_c_like_outputs': counts['nonempty_c_like'],
        'preexisting_full_body_ranges': 265,
        'partial_raw_membership_ranges': 247,
        'transient_full_fde_c_like_outputs': 247,
        'unresolved_other_function_overlap_global_indices': [],
        'fresh_session_rollback_rows_verified': 512,
        'behaviorally_equivalent_functions_verified': 0,
        'files': files,
        'code_files': ['scripts/task_228_codex_internal/common.py',
                       'scripts/task_228_codex_internal/prepare.py',
                       'scripts/task_228_codex_internal/ExtractInternal228.java',
                       'scripts/task_228_codex_internal/run_batch.py',
                       'scripts/task_228_codex_internal/RepairMembership228.java',
                       'scripts/task_228_codex_internal/run_correction.py',
                       'scripts/task_228_codex_internal/package.py'],
    })
    print(json.dumps({'status':'SEALED_REVIEW_CANDIDATE', 'manifest_files':len(files),
                      'report_bytes':report_bytes,
                      'complete_sha256':sha256(REPORT/'COMPLETE.json')}))


if __name__ == '__main__':
    main()
