"""Recheck every TASK_216 native byte/word and seal a truthful static report."""
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
    require(len(targets) == 128 and set(targets) ==
            set(range(512, 641)) - {555}, 'exact 128 target selection')
    require(manifest['skipped_in_slice'] ==
            [{'global_index': 555, 'elf_va': '0x1f8bc4', 'size_bytes': 4796}],
            'oversized exclusion')
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
    for batch in range(1, 5):
        receipt_path = REPORT / f'ghidra_batch{batch}_command.json'
        rec = json.loads(receipt_path.read_text(encoding='utf8'))
        require(rec['status'] == 'OUTPUT_READY' and rec['exit_code'] == 0 and
                rec['raw_result_files'] == 32 and rec['fencing_token'] == FENCE and
                rec['lease_id'] == LEASE_ID and rec['source_sha256'] == SOURCE_SHA and
                rec['max_cpu'] == 1 and rec['max_heap'] == '1G' and
                rec['max_decompile_seconds_per_candidate'] == 15,
                f'headless batch receipt {batch}')
        require(rec['script_sha256'] == sha256(ROOT / 'scripts/task_216_codex_internal/ExtractInternal216.java') and
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
    require(len(raws) == 128, '128 unique raw rows')

    ordered = sorted(targets)
    sample = sorted({ordered[round(j * (len(ordered)-1)/12)] for j in range(13)})
    require(len(sample) >= math.ceil(.10*128), 'ordinary spread sample <10%')
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
                raw['ghidra_instruction_count'] == size//4 and
                raw['missing_analyzed_instruction_count'] == 0 and
                raw['existing_exact_function_start'] and
                raw['boundary_classification'] ==
                    'EXACT_GHIDRA_FUNCTION_START_FDE_BOUNDARY_UNPROVEN' and
                raw['fde_byte_membership_count'] == size and
                raw['fde_byte_membership_bits'] == '1'*size and
                not raw['fde_missing_body_ranges'] and
                raw['other_function_byte_count'] == 0 and
                raw['extra_body_address_count'] == 0,
                f'Ghidra memory/listing/function-body binding {idx}')
        require(raw['c_like_nonempty'] == bool(raw['c_like_text'].strip()) and
                (not raw['c_like_nonempty'] or not raw['decompile_error']),
                f'C-like/decompiler classification {idx}')
        if idx in sample:
            pcode = raw['instruction_pcode']
            require(len(pcode) == size//4 and
                    sum(len(x['pcode_ops']) for x in pcode) == raw['ghidra_pcode_ops'],
                    f'ordinary p-code count {idx}')
            for j, ins in enumerate(pcode):
                require(int(ins['database_va'],16) ==
                        int(raw['database_va'],16)+4*j and ins.get('assembly') and
                        isinstance(ins.get('pcode_ops'), list),
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
                    'ordinary_spread_rechecked': idx in sample,
                    'classification': 'STATIC_C_LIKE_BOUNDARY_AND_BEHAVIOR_UNPROVEN'
                        if raw['c_like_nonempty'] else 'PARTIAL_NO_C_LIKE'})
    require(counts['original_bytes'] == 86676 and counts['instruction_slots'] == 21669 and
            counts['nonempty_c_like'] == 128, 'aggregate totals')
    write_json(REPORT / 'source_spread_recheck.json', {
        'task_id': 'TASK_216', 'revision': 1, 'sampled_count': len(sample),
        'total_candidate_count': 128, 'sample_fraction': len(sample)/128,
        'rule': 'spread across sorted candidate indices; each sampled raw p-code row position/count rechecked',
        'rows': checks})
    atomic_bytes(REPORT / 'candidate_evidence.jsonl',
                 ''.join(json.dumps(x, ensure_ascii=False)+'\n' for x in per).encode('utf8'))
    write_json(REPORT / 'evidence_summary.json', {
        'task_id': 'TASK_216', 'revision': 1, 'source_so_sha256': SOURCE_SHA,
        'target_manifest_sha256': TARGETS_SHA,
        'original_fde_candidate_bodies_verified': 128,
        'original_bytes_verified': counts['original_bytes'],
        'original_instruction_words_verified': counts['instruction_slots'],
        'ghidra_pcode_operations_recorded': counts['ghidra_pcode_operations'],
        'nonempty_c_like_outputs': counts['nonempty_c_like'],
        'unresolved_c_like_indices': [x['global_zero_based_fde_index'] for x in per
                                      if not x['c_like_nonempty']],
        'ordinary_spread_rechecked': sample,
        'ordinary_spread_fraction': len(sample)/128,
        'project_file_hashes_unchanged': project_current,
        'batch_receipts': batch_receipts,
        'skipped_oversized_global_index': 555,
        'behaviorally_equivalent_functions_verified': 0,
        'boundary_limit': 'FDE and analyzed Ghidra function membership do not prove exact original semantic source-function boundary',
    })
    atomic_bytes(REPORT / '00_AUDIT_INDEX.md', (
        '# TASK_216 R1 audit index\n\n'
        f'Canonical Standard fully read at {canonical_read_at}: `{STANDARD}`; SHA-256 `{STANDARD_SHA}`.\n\n'
        f'Task SHA-256 `{TASK_SHA}`; target manifest SHA-256 `{TARGETS_SHA}`. '
        f'Worker `{AGENT}`, lease `{LEASE_ID}`, fencing token `{FENCE}`.\n\n'
        'Source index, 128 per-candidate Capstone source records, 128 raw Ghidra output records, '
        'four command/stdout/stderr receipts, candidate ledger and spread recheck are included. '
        'All 9 copied project hashes remained unchanged after read-only headless processing.\n').encode('utf8'))
    atomic_bytes(REPORT / '01_MASTER_REPORT.md', (
        '# TASK_216 R1 — libPVGImageCodec nonexport FDE continuation\n\n'
        'The next 128 pinned VA-sorted nonexport FDE candidate spans, global zero-based indices '
        '512–640 excluding oversized index 555, cover 86,676 original ELF bytes / 21,669 '
        'AArch64 instruction words. All source-body hashes and every original instruction word '
        'were reverified against the pinned ELF and PT_LOAD mapping. No selected range overlaps '
        'another FDE or an exported body in the source census.\n\n'
        f'Four sequential private Ghidra headless batches produced 128/128 nonempty C-like outputs '
        f'and {counts["ghidra_pcode_operations"]:,} recorded p-code operations. All have exact '
        'Ghidra function starts and range membership with no missing listing slot, body gap or '
        'extra function-body byte. This does **not** prove exact original source function boundaries. '
        f'A spread sample of {len(sample)}/128 ({len(sample)/128:.2%}) independently rechecked '
        'every sampled p-code row address and operation count against raw output. Source bytes and '
        'instruction words were checked 128/128. Raw commands, logs, generator hash and all 9 '
        'private project file hashes were rechecked. No metadata changed; fresh-session rollback '
        'was not applicable.\n\n'
        'Oversized index 555 (VA `0x1f8bc4`, 4,796 bytes) remains unselected. Earlier open '
        'indices 450 and 499 and index 465 lacking C-like also remain separate limitations. '
        'These C-like outputs are static research, not source-equivalent algorithms or behavior '
        'parity. No product Phase PASS, V4 implementation, or full SO completion is claimed. '
        'This report awaits independent CEO review before any commit/push.\n\n'
        '`candidate_evidence.jsonl` binds each range/hash/output status; '
        '`source_spread_recheck.json` records the ordinary provenance sample; '
        '`evidence_summary.json` records totals and command/project checks.\n').encode('utf8'))
    write_json(REPORT / 'PROGRESS.json', {
        'task_id': 'TASK_216', 'revision': 1,
        'status': 'REVIEW_CANDIDATE_AWAITING_CEO', 'generated_at': now(),
        'original_fde_candidates_verified': 128,
        'nonempty_c_like_outputs': 128,
        'original_instruction_words_verified': 21669,
        'ordinary_spread_recheck_count': len(sample),
    })
    check_lease()
    files = {p.relative_to(REPORT).as_posix(): sha256(p)
             for p in sorted(REPORT.rglob('*')) if p.is_file() and
             p.name not in ('COMPLETE.json', 'PROGRESS.json')}
    report_bytes = sum(p.stat().st_size for p in REPORT.rglob('*') if p.is_file())
    require(report_bytes < 134217728, 'report byte cap')
    write_json(REPORT / 'COMPLETE.json', {
        'schema_version': '2.1.2', 'task_id': 'TASK_216', 'revision': 1,
        'status': 'COMPLETE',
        'research_result': 'PARTIAL_STATIC_RESEARCH_BOUNDARIES_UNPROVEN',
        'generated_at': now(), 'agent_id': AGENT,
        'lease_id': LEASE_ID, 'fencing_token': FENCE,
        'standard_path': str(STANDARD), 'standard_sha256': STANDARD_SHA,
        'task_sha256': TASK_SHA, 'target_manifest_sha256': TARGETS_SHA,
        'original_so_sha256': SOURCE_SHA,
        'original_fde_candidate_bodies_verified': 128,
        'original_instruction_words_verified': 21669,
        'nonempty_c_like_outputs': 128,
        'behaviorally_equivalent_functions_verified': 0,
        'files': files,
        'code_files': ['scripts/task_216_codex_internal/common.py',
                       'scripts/task_216_codex_internal/prepare.py',
                       'scripts/task_216_codex_internal/ExtractInternal216.java',
                       'scripts/task_216_codex_internal/run_batch.py',
                       'scripts/task_216_codex_internal/package.py'],
    })
    print(json.dumps({'status':'SEALED_REVIEW_CANDIDATE', 'manifest_files':len(files),
                      'report_bytes':report_bytes,
                      'complete_sha256':sha256(REPORT/'COMPLETE.json')}))


if __name__ == '__main__':
    main()
