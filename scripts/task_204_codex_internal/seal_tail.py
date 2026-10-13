"""Seal the independently checked TASK_204 source/Ghidra research evidence."""
from __future__ import annotations

import json
import math

from common import (AGENT, FENCE, LEASE_ID, PROJECT, REPORT, ROOT, SCRATCH,
                    SCRIPTS, SOURCE, SOURCE_SHA, STANDARD, STANDARD_SHA, TARGETS_SHA,
                    TASK_SHA, atomic_bytes, check_lease, now, sha256, write_json)


def finish(*, manifest, index, results, spread, source_slots, original_ghidra_slots,
           original_missing_slots, effective_slots, effective_ops,
           original_full_bodies, corrected_full_bodies,
           source_direct_calls, source_indirect_calls, batches, correction, post):
    check_lease()
    if (len(results) != 127 or [r['index'] for r in results] != list(range(384, 511))
            or source_slots != 10943 or effective_slots != 10943
            or original_ghidra_slots != 10939 or original_missing_slots != 4
            or original_full_bodies != 123 or corrected_full_bodies != 4
            or len(spread) < math.ceil(.1 * source_slots)
            or sum(row['ordinary_spread_sample_count'] for row in results) != len(spread)
            or manifest['cumulative_selected_distinct_candidates'] != 503
            or manifest['remaining_nonselected_candidates_after_slice'] != 8
            or manifest['remaining_unselected_breakdown']['previous_and_current_excluded_indices']
               != [201, 211, 216, 235, 293, 304, 349, 362]):
        raise RuntimeError('TASK_204 count/coverage/source selection differs')
    if (len(batches) != 5 or sum(b['raw_result_files'] for b in batches) != 127
            or any(b['elapsed_seconds'] > 1200 for b in (*batches, correction, post))
            or sha256(SOURCE) != SOURCE_SHA):
        raise RuntimeError('bounded headless command or source identity differs')
    for item in index['project_files']:
        original = PROJECT / item['relative_path']
        copied = SCRATCH / 'ghidra_project' / item['relative_path']
        if (not original.is_file() or not copied.is_file()
                or original.stat().st_size != item['bytes']
                or sha256(original) != item['sha256']
                or sha256(copied) != item['sha256']):
            raise RuntimeError(f'project changed after read-only sessions: {item["relative_path"]}')
    preflight = json.loads((REPORT / 'correction_preflight.json').read_text(encoding='utf-8'))
    if (preflight['target_indices'] != [405, 406, 407, 408]
            or preflight['target_count'] != 4
            or correction['target_indices'] != [405, 406, 407, 408]):
        raise RuntimeError('correction preflight/receipt differs')
    command_names = [f'ghidra_batch{i}' for i in range(1, 6)] + [
        'ghidra_correction', 'ghidra_postrollback']
    verification = {
        'task_id': 'TASK_204', 'revision': 1, 'generated_at': now(),
        'original_source_sha256': SOURCE_SHA, 'target_manifest_sha256': TARGETS_SHA,
        'original_fde_candidate_bodies_verified': 127,
        'original_arm64_instruction_words_verified': source_slots,
        'original_ghidra_analyzed_instruction_positions': original_ghidra_slots,
        'original_ghidra_missing_instruction_positions': original_missing_slots,
        'effective_ghidra_pcode_instruction_positions': effective_slots,
        'effective_ghidra_pcode_operations': effective_ops,
        'nonempty_effective_c_like_texts': sum(bool(r['nonempty_c_like']) for r in results),
        'existing_ghidra_bodies_contain_every_fde_byte': original_full_bodies,
        'transient_full_fde_metadata_assumptions': corrected_full_bodies,
        'fresh_session_original_metadata_and_memory_replays': 4,
        'source_direct_call_sites': source_direct_calls,
        'source_indirect_call_sites': source_indirect_calls,
        'excluded_oversized_global_indices': [],
        'cumulative_selected_distinct_candidates': 503,
        'remaining_unselected_global_indices': [201, 211, 216, 235, 293, 304, 349, 362],
        'verified_behavior_candidates': 0,
        'ordinary_spread_instruction_sample_count': len(spread),
        'ordinary_spread_instruction_sample_percent': round(100 * len(spread) / source_slots, 2),
        'ordinary_spread_samples': spread, 'rows': results,
        'original_and_private_project_files_byte_verified': len(index['project_files']),
        'command_receipts': {n: sha256(REPORT / f'{n}_command.json') for n in command_names},
        'headless_process_seconds': {n: json.loads((REPORT / f'{n}_command.json').read_text())['elapsed_seconds']
                                     for n in command_names},
        'fresh_imports': 0,
        'limits': 'FDE ranges are candidate boundaries, not proof of unique complete functions. '
                  'Four full-FDE transient metadata reconstructions are assumptions; '
                  'fresh read-only sessions prove the original database metadata reappears. '
                  'C-like output and p-code do not establish functional or pixel parity.'}
    if verification['nonempty_effective_c_like_texts'] != 127:
        raise RuntimeError('nonempty C-like count differs')
    write_json(REPORT / 'WORKER_VERIFICATION.json', verification)
    sample_percent = 100 * len(spread) / source_slots
    master = (
        '# TASK_204 R1 — MTFilterKernel nonexport FDE indices 384..510\n\n'
        '**Result: PARTIAL static research of 127 pinned candidate ranges.** '
        f'Original SO/PT_LOAD bytes and all {source_slots:,} AArch64 instruction words '
        f'were verified. Five sequential read-only headless batches yielded {effective_slots:,} '
        f'effective Ghidra instruction/p-code positions ({effective_ops:,} operations) '
        'and 127 nonempty C-like texts. An independently re-decoded deterministic spread '
        f'checked {len(spread):,}/{source_slots:,} positions ({sample_percent:.2f}%). '
        f'Original instruction streams include {source_direct_calls} direct and '
        f'{source_indirect_calls} indirect call sites, preserved with addresses and operands.\n\n'
        'Existing Ghidra function metadata contains all FDE bytes for 123/127 candidates. '
        'Indices 405–408 each omit one 4-byte instruction in pre-existing function metadata. '
        'The four missing bytes have no other-function, export-body or FDE overlap. '
        'A transient full-FDE function/disassembly pass supplied their missing p-code; '
        'the same-session Ghidra API did not report original metadata restoration after '
        'rollback. A separate fresh read-only session reproduced each original function '
        'name/start, original body bitmap and original memory hash. Original and private '
        'Ghidra project files still match their pre-run hashes. These four rows remain '
        'boundary-limited assumptions, not verified complete functions or behavior.\n\n'
        'This slice brings the distinct selected nonexport FDE candidate census to '
        '503/511. Eight earlier oversized exclusions (global indices 201, 211, 216, '
        '235, 293, 304, 349, 362) remain unanalyzed here. The candidate census is '
        'not a count of fully recovered functions. No 45-SO completion, behavioral '
        'equivalence, pixel parity, product Phase PASS, V4 or P7 readiness is claimed. '
        'No source import, production edit, commit or push was made. Independent CEO '
        'review is pending.\n')
    atomic_bytes(REPORT / '01_MASTER_REPORT.md', master.encode('utf-8'))
    audit = (REPORT / '00_AUDIT_INDEX.md').read_text(encoding='utf-8')
    audit += ('\nFinal evidence: 127 `source_assembly/` source-word/call records; '
              '127 first-pass `ghidra_raw_batch1..5/` records; four each '
              '`ghidra_correction_raw/` and `ghidra_postrollback_raw/` records; '
              'seven command/stdout/stderr receipts; exact source/project index and '
              '`WORKER_VERIFICATION.json` with boundary and source-word spread checks. '
              '`COMPLETE.json` hashes immutable report, code and scratch artifacts.\n')
    atomic_bytes(REPORT / '00_AUDIT_INDEX.md', audit.encode('utf-8'))
    write_json(REPORT / 'PROGRESS.json', {
        'task_id': 'TASK_204', 'revision': 1,
        'status': 'SEALED_PARTIAL_STATIC_RESEARCH_CANDIDATE', 'generated_at': now(),
        'fde_bodies_verified': 127, 'original_instruction_positions': source_slots,
        'effective_ghidra_pcode_positions': effective_slots,
        'effective_ghidra_pcode_operations': effective_ops,
        'nonempty_c_like': 127, 'transient_full_fde_metadata_assumptions': 4,
        'fresh_postrollback_replays': 4, 'spread_instruction_sample_count': len(spread),
        'remaining_exclusions': [201, 211, 216, 235, 293, 304, 349, 362],
        'fresh_imports': 0, 'disposition': 'AWAITING_INDEPENDENT_CEO_REVIEW'})
    report_files = {p.relative_to(REPORT).as_posix(): sha256(p)
                    for p in sorted(REPORT.rglob('*')) if p.is_file()
                    and p.name not in {'COMPLETE.json', 'PROGRESS.json', 'PROGRESS.md'}}
    code_files = {p.relative_to(ROOT).as_posix(): sha256(p)
                  for p in sorted(SCRIPTS.rglob('*')) if p.is_file() and p.suffix in {'.py', '.java'}}
    scratch_files = {p.relative_to(ROOT).as_posix(): sha256(p)
                     for p in sorted(SCRATCH.rglob('*')) if p.is_file()}
    if sum(p.stat().st_size for p in REPORT.rglob('*') if p.is_file()) > 134_217_728:
        raise RuntimeError('report exceeds task cap')
    complete = {
        'schema_version': '2.1.2', 'task_id': 'TASK_204', 'revision': 1,
        'status': 'COMPLETE',
        'research_result': 'PARTIAL_BOUNDARY_FOUR_TRANSIENT_FULL_FDE_EIGHT_PREVIOUS_EXCLUSIONS',
        'generated_at': now(), 'agent_id': AGENT, 'lease_id': LEASE_ID,
        'fencing_token': FENCE, 'standard_path': str(STANDARD),
        'standard_sha256': STANDARD_SHA, 'task_sha256': TASK_SHA,
        'target_manifest_sha256': TARGETS_SHA, 'original_so_sha256': SOURCE_SHA,
        'original_fde_candidate_bodies_verified': 127,
        'original_instruction_words_verified': source_slots,
        'effective_ghidra_pcode_instruction_positions': effective_slots,
        'effective_ghidra_pcode_operations': effective_ops,
        'nonempty_c_like_outputs': 127, 'original_full_fde_body_membership': 123,
        'transient_full_fde_metadata_assumptions': 4,
        'fresh_session_original_metadata_and_memory_replays': 4,
        'cumulative_selected_distinct_candidates': 503,
        'remaining_unselected_global_indices': [201, 211, 216, 235, 293, 304, 349, 362],
        'source_direct_call_sites': source_direct_calls,
        'source_indirect_call_sites': source_indirect_calls,
        'ordinary_spread_instruction_sample_count': len(spread),
        'fresh_imports': 0, 'verified_behavior_candidates': 0,
        'files': report_files, 'code_files': code_files, 'scratch_files': scratch_files,
        'limits': 'FDE/C-like/p-code evidence does not prove unique function boundaries or behavior. '
                  'Four transient full-FDE metadata assumptions remain PARTIAL; eight earlier '
                  'oversized candidates remain unanalyzed.'}
    write_json(REPORT / 'COMPLETE.json', complete)
    print(json.dumps({
        'status': 'SEALED_PARTIAL_STATIC_RESEARCH_CANDIDATE',
        'original_fde_bodies': 127, 'source_and_effective_pcode_positions': source_slots,
        'effective_pcode_ops': effective_ops, 'nonempty_c_like': 127,
        'transient_full_fde_metadata_assumptions': 4,
        'fresh_postrollback_replays': 4, 'spread_samples': len(spread),
        'complete_sha256': sha256(REPORT / 'COMPLETE.json')}))
