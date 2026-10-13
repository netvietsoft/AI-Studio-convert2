"""Reconcile TASK_204 R1 instruction listings with nonempty p-code coverage.

Only immutable R1 evidence is read. All writes are confined to the exact R2
report folder and guarded by the live R2 lease/fencing token.
"""
from __future__ import annotations

import hashlib
import json
import os
import tempfile
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
TASK = ROOT / 'RULES/TASK/TASK_204_SO45_CODEX_INTERNAL_ACTIVE.md'
MANIFEST = ROOT / '.ai/ceo/reviews/TASK_204_internal_targets.json'
REVIEW = ROOT / '.ai/ceo/reviews/TASK_204-21d00b2a2cba642f907fc577b233fda1a8c89b8df4e239dd5e9ed5e99c590d4b.md'
STANDARD = ROOT / 'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt'
SOURCE = Path('F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libMTFilterKernel.so')
R1 = ROOT / 'RULES/REPORT/TASK_204_REPORT_R1'
R2 = ROOT / 'RULES/REPORT/TASK_204_REPORT_R2'
SCRIPT_DIR = Path(__file__).resolve().parent
AGENT = '/root/so45_mtfilter_next'
LEASE = 'LEASE-CEO-WORKER-TASK_204-R2'
FENCE = 1243
TASK_SHA = '5a72c775e94aabc3888023e913655d7058257d667e2e8ca4dcaced2d64bdcce0'
MANIFEST_SHA = '548a3f83bf498b047d34dd77e707c00d3644d1c8780eef4e71d8e43802874793'
REVIEW_SHA = 'c41315ed4cd882867982b3de7f16f832d3ef5b343ad26ed05c4769fca0b4d391'
STANDARD_SHA = '10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f'
SOURCE_SHA = 'f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4'
R1_SHA = 'edbbc77985569a49089745f51c672b807cc428bab307566c697551e49de7b710'
DEADLINE = datetime.fromisoformat('2026-10-13T15:09:28.505005+00:00')
EMPTY_EXPECTED = {'nop': 24, 'bti': 96, 'paciasp': 29, 'autiasp': 46,
                  'autib1716': 1, 'autia1716': 1}


def now() -> str:
    return datetime.now(timezone.utc).isoformat().replace('+00:00', 'Z')


def sha(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            digest.update(block)
    return digest.hexdigest()


def read(path: Path) -> dict:
    return json.loads(path.read_text(encoding='utf-8-sig'))


def guard() -> dict:
    for path, pinned in ((TASK, TASK_SHA), (MANIFEST, MANIFEST_SHA),
                         (REVIEW, REVIEW_SHA), (STANDARD, STANDARD_SHA),
                         (SOURCE, SOURCE_SHA), (R1 / 'COMPLETE.json', R1_SHA)):
        if sha(path) != pinned:
            raise RuntimeError(f'pinned input changed: {path}')
    flag = ROOT / '.ai/ceo/END_AGENT_SESSION.flag'
    if flag.exists() and flag.read_text(encoding='utf-8-sig').strip().upper() == 'TRUE':
        raise RuntimeError('END_AGENT_SESSION=TRUE')
    if datetime.now(timezone.utc) >= DEADLINE:
        raise RuntimeError('original TASK_204 deadline expired')
    matches = [x for x in read(ROOT / '.ai/locks.json')['active_locks']
               if x.get('lease_id') == LEASE]
    if len(matches) != 1:
        raise RuntimeError('R2 lease absent/ambiguous')
    item = matches[0]
    actual = (item.get('status'), item.get('agent_id'), item.get('task_id'),
              item.get('task_revision'), item.get('task_sha'), item.get('fencing_token'))
    if actual != ('ACTIVE', AGENT, 'TASK_204', 2, TASK_SHA, FENCE):
        raise RuntimeError(f'R2 lease fence mismatch: {actual}')
    if datetime.fromisoformat(item['expiry'].replace('Z', '+00:00')) <= datetime.now(timezone.utc):
        raise RuntimeError('R2 lease expired')
    if item.get('files_allowed') != ['RULES/REPORT/TASK_204_REPORT_R2/**',
                                     'scripts/task_204_codex_correction_r2/**']:
        raise RuntimeError('R2 lease write scope changed')
    return item


def put(path: Path, content: bytes) -> None:
    guard()
    relative = path.resolve().relative_to(ROOT.resolve()).as_posix()
    if not relative.startswith('RULES/REPORT/TASK_204_REPORT_R2/'):
        raise RuntimeError('write outside R2 report scope')
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temp = tempfile.mkstemp(prefix='.task204r2-', dir=path.parent)
    try:
        with os.fdopen(fd, 'wb') as stream:
            stream.write(content)
            stream.flush()
            os.fsync(stream.fileno())
        os.replace(temp, path)
    finally:
        if os.path.exists(temp):
            os.unlink(temp)


def put_json(path: Path, data: object) -> None:
    put(path, (json.dumps(data, ensure_ascii=False, indent=2) + '\n').encode('utf-8'))


def check_r1_manifest() -> dict:
    seal = read(R1 / 'COMPLETE.json')
    for kind, base in (('files', R1), ('code_files', ROOT), ('scratch_files', ROOT)):
        for relative, digest in seal[kind].items():
            path = base / relative
            if not path.is_file() or sha(path) != digest:
                raise RuntimeError(f'immutable R1 {kind} differs: {relative}')
    actual = {p.relative_to(R1).as_posix() for p in R1.rglob('*') if p.is_file()
              and p.name not in {'COMPLETE.json', 'PROGRESS.json', 'PROGRESS.md'}}
    if actual != set(seal['files']):
        raise RuntimeError('R1 immutable report inventory differs')
    if (seal['task_sha256'] != 'a175e7b87e7e257d6623d4f650201ba091868794d54cd2d77ca7a3ebaf9d43ee'
            or seal['target_manifest_sha256'] != MANIFEST_SHA
            or seal['original_so_sha256'] != SOURCE_SHA):
        raise RuntimeError('R1 seal source/task identity differs')
    return seal


def main() -> None:
    guard()
    if R2.exists() and any(R2.iterdir()):
        raise RuntimeError('R2 report already started; do not overwrite a sealed revision')
    put_json(R2 / 'PROGRESS.json', {'task_id': 'TASK_204', 'revision': 2,
                                   'status': 'RECOUNTING_IMMUTABLE_R1', 'generated_at': now()})
    seal = check_r1_manifest()
    manifest = read(MANIFEST)
    verified = read(R1 / 'WORKER_VERIFICATION.json')
    if ([x['global_nonexport_fde_index'] for x in manifest['targets']] != list(range(384, 511))
            or len(verified['rows']) != 127
            or [x['index'] for x in verified['rows']] != list(range(384, 511))):
        raise RuntimeError('R1 selected candidate identity differs')
    total_listings = total_nonempty = total_operations = 0
    empty = Counter()
    candidate_rows = []
    empty_records = []
    for target, before in zip(manifest['targets'], verified['rows']):
        guard()
        index = target['global_nonexport_fde_index']
        va = int(target['elf_va'], 16)
        filename = f'{index:03d}_{va:x}.json'
        first_path = R1 / f'ghidra_raw_batch{(index-384)//26+1}' / filename
        first = read(first_path)
        overlay_path = R1 / 'ghidra_correction_raw' / filename if 405 <= index <= 408 else first_path
        effective = read(overlay_path)
        rows = effective['instruction_pcode']
        if (len(rows) != target['instruction_slots']
                or before['effective_ghidra_pcode_slots'] != len(rows)
                or first['ghidra_memory_sha256'] != target['body_sha256']
                or effective['index'] != index):
            raise RuntimeError(f'R1 listing/identity differs #{index}')
        row_ops = 0
        row_empty = Counter()
        for ordinal, item in enumerate(rows):
            ops = item.get('pcode_ops')
            if not isinstance(ops, list):
                raise RuntimeError(f'R1 effective p-code missing #{index}:{ordinal}')
            row_ops += len(ops)
            total_listings += 1
            if ops:
                total_nonempty += 1
            else:
                mnemonic = item['assembly'].split()[0].lower()
                empty[mnemonic] += 1
                row_empty[mnemonic] += 1
                empty_records.append({'candidate_index': index,
                                      'instruction_ordinal_zero_based': ordinal,
                                      'database_va': item['database_va'],
                                      'assembly': item['assembly'],
                                      'mnemonic': mnemonic,
                                      'effective_raw_sha256': sha(overlay_path)})
        total_operations += row_ops
        if row_ops != before['effective_ghidra_pcode_operations']:
            raise RuntimeError(f'R1 p-code op count differs #{index}')
        candidate_rows.append({'candidate_index': index,
                               'elf_va': target['elf_va'],
                               'instruction_listings': len(rows),
                               'nonempty_pcode_positions': len(rows) - sum(row_empty.values()),
                               'empty_pcode_positions': sum(row_empty.values()),
                               'empty_opcode_categories': dict(sorted(row_empty.items())),
                               'pcode_operations': row_ops,
                               'first_pass_raw_sha256': sha(first_path),
                               'effective_raw_sha256': sha(overlay_path),
                               'uses_transient_full_fde_overlay': index in (405, 406, 407, 408)})
    if ((total_listings, total_nonempty, total_listings-total_nonempty, total_operations)
            != (10943, 10746, 197, 37532)):
        raise RuntimeError('exact corrected coverage totals differ')
    if dict(empty) != EMPTY_EXPECTED or len(empty_records) != 197:
        raise RuntimeError('empty p-code opcode classification differs')
    samples = verified['ordinary_spread_samples']
    spread_nonempty = sum(int(x['pcode_ops']) > 0 for x in samples)
    if len(samples) != 1382 or spread_nonempty != 1332:
        raise RuntimeError('R1 deterministic spread p-code recount differs')
    unchanged = {
        'original_so_sha256': SOURCE_SHA,
        'target_manifest_sha256': MANIFEST_SHA,
        'original_fde_candidate_bodies_verified': 127,
        'original_instruction_words_verified': 10943,
        'effective_ghidra_pcode_operations': 37532,
        'nonempty_c_like_outputs': 127,
        'original_full_fde_body_membership': 123,
        'transient_full_fde_metadata_assumptions': 4,
        'fresh_session_original_metadata_and_memory_replays': 4,
        'source_direct_call_sites': 540,
        'source_indirect_call_sites': 77,
        'ordinary_spread_instruction_sample_count': 1382,
        'original_and_private_project_files_byte_verified': 9,
        'cumulative_selected_distinct_candidates': 503,
        'remaining_unselected_global_indices': [201, 211, 216, 235, 293, 304, 349, 362],
        'fresh_imports': 0, 'verified_behavior_candidates': 0}
    for key, expected in unchanged.items():
        actual = seal.get(key, verified.get(key))
        if actual != expected:
            raise RuntimeError(f'R1 unchanged critical claim differs: {key}')
    coverage = {
        'schema_version': '2.1.2', 'task_id': 'TASK_204', 'revision': 2,
        'generated_at': now(), 'classification': 'CORRECTED_STATIC_COVERAGE_PARTIAL',
        'r1_complete_sha256': R1_SHA, 'r1_verification_sha256': sha(R1 / 'WORKER_VERIFICATION.json'),
        'source_sha256': SOURCE_SHA, 'target_manifest_sha256': MANIFEST_SHA,
        'candidate_count': 127, 'instruction_listings': total_listings,
        'nonempty_pcode_instruction_positions': total_nonempty,
        'empty_pcode_instruction_positions': total_listings-total_nonempty,
        'pcode_operations': total_operations,
        'empty_opcode_categories': dict(sorted(empty.items())),
        'empty_control_security_opcode_positions': sum(empty[k] for k in
                                                       ('bti','paciasp','autiasp','autib1716','autia1716')),
        'ordinary_spread_listings': len(samples),
        'ordinary_spread_nonempty_pcode_positions': spread_nonempty,
        'ordinary_spread_nonempty_percent_of_all_nonempty': round(100*spread_nonempty/total_nonempty, 2),
        'per_candidate': candidate_rows,
        'empty_positions': empty_records,
        'limit': 'An instruction listing with pcode_ops: [] proves no p-code operation was emitted '
                 'in this extraction. BTI/PAC/AUT machine-level semantics and complete behavior '
                 'are not established by empty p-code or C-like output.'}
    put_json(R2 / 'CORRECTED_COVERAGE.json', coverage)
    delta = {
        'schema_version': '2.1.2', 'task_id': 'TASK_204', 'revision': 2,
        'generated_at': now(), 'r1_review_sha256': REVIEW_SHA,
        'r1_complete_sha256': R1_SHA,
        'r1_immutable_manifest_reverified': {
            'report_files': len(seal['files']), 'code_files': len(seal['code_files']),
            'scratch_files': len(seal['scratch_files']),
            'all_hashes_matched': True},
        'corrected_claims': [
            {'r1_artifacts': ['01_MASTER_REPORT.md', 'WORKER_VERIFICATION.json',
                              'COMPLETE.json', 'PROGRESS.json'],
             'r1_label': 'effective_ghidra_pcode_instruction_positions',
             'r1_value': 10943,
             'r2_instruction_listings': 10943,
             'r2_nonempty_pcode_instruction_positions': 10746,
             'r2_empty_pcode_instruction_positions': 197,
             'reason': 'R1 included empty pcode_ops lists as p-code-covered positions'},
            {'r1_label': 'ordinary_spread_instruction_sample_count',
             'r1_value': 1382, 'r2_spread_listings': 1382,
             'r2_spread_nonempty_pcode_positions': 1332,
             'reason': '50 sampled instruction listings have zero emitted p-code ops'}],
        'all_other_critical_source_c_like_boundary_project_call_counts_unchanged': unchanged,
        'r1_bodies_code_and_raw_immutable': True,
        'no_ghidra_rerun': True, 'no_new_import': True,
        'scope': 'report-only semantic correction; original R1 artifacts and source are immutable'}
    put_json(R2 / 'R1_TO_R2_DELTA.json', delta)
    audit = (
        '# TASK_204 R2 audit index\n\n'
        f'Canonical Standard fully reread: `{STANDARD}`; SHA-256 `{STANDARD_SHA}`. '
        f'R2 task SHA-256 `{TASK_SHA}`; target manifest SHA-256 `{MANIFEST_SHA}`. '
        f'Worker `{AGENT}`; lease `{LEASE}`; fencing token `{FENCE}`.\n\n'
        f'Immutable R1 COMPLETE SHA-256 `{R1_SHA}` and CEO NEEDS_FIX review SHA-256 '
        f'`{REVIEW_SHA}`. R1 inventory rehashed: {len(seal["files"])} report, '
        f'{len(seal["code_files"])} code, {len(seal["scratch_files"])} scratch. '
        'Every original/effective Ghidra instruction-p-code record was reparsed from '
        'the 127 pinned R1 raw candidates and four corrected overlays. '
        '`CORRECTED_COVERAGE.json` gives all per-candidate and empty-position records. '
        '`R1_TO_R2_DELTA.json` names corrected labels and unchanged critical claims.\n')
    put(R2 / '00_AUDIT_INDEX.md', audit.encode('utf-8'))
    master = (
        '# TASK_204 R2 — corrected p-code coverage\n\n'
        '**Result: PARTIAL static research.** The immutable R1 evidence has '
        '**10,943 instruction listings**, of which **10,746 positions have at least one '
        'emitted p-code operation** and **197 have an empty p-code list**. The '
        '**37,532 total p-code operations** and 127 nonempty C-like outputs remain '
        'unchanged. Empty listings are 24 NOP, 96 BTI, 29 PACIASP, 46 AUTIASP, '
        'one AUTIB1716 and one AUTIA1716. Of 1,382 deterministic spread listings, '
        '1,332 have nonempty p-code (12.40% of all 10,746 nonempty positions).\n\n'
        'The 173 BTI/PAC/AUT empty records need machine-level interpretation; '
        'their semantics are not established by empty p-code or C-like text alone. '
        'Original source words, FDE/PT_LOAD mappings, 540 direct/77 indirect calls, '
        '123 original full-body memberships, four transient boundary assumptions '
        'with fresh-session rollback proof, nine project hashes and all 314 R1 '
        'manifest hashes remain unchanged. This overlay corrects coverage labels '
        'only. It does not establish full unique functions, functional/pixel parity, '
        'all-45-SO completion, Phase PASS, V4 or P7 readiness. Independent CEO '
        'review is pending.\n')
    put(R2 / '01_MASTER_REPORT.md', master.encode('utf-8'))
    put_json(R2 / 'PROGRESS.json', {'task_id':'TASK_204','revision':2,
             'status':'SEALED_CORRECTED_PARTIAL_RESEARCH_CANDIDATE','generated_at':now(),
             'instruction_listings':10943,'nonempty_pcode_instruction_positions':10746,
             'empty_pcode_instruction_positions':197,'pcode_operations':37532,
             'disposition':'AWAITING_INDEPENDENT_CEO_REVIEW'})
    check_r1_manifest()
    files = {p.relative_to(R2).as_posix():sha(p) for p in sorted(R2.rglob('*'))
             if p.is_file() and p.name not in {'COMPLETE.json','PROGRESS.json','PROGRESS.md'}}
    codes = {p.relative_to(ROOT).as_posix():sha(p) for p in sorted(SCRIPT_DIR.rglob('*'))
             if p.is_file() and p.suffix == '.py'}
    put_json(R2 / 'COMPLETE.json', {
        'schema_version':'2.1.2','task_id':'TASK_204','revision':2,'status':'COMPLETE',
        'research_result':'PARTIAL_CORRECTED_NONEMPTY_PCODE_COVERAGE',
        'generated_at':now(),'agent_id':AGENT,'lease_id':LEASE,'fencing_token':FENCE,
        'standard_path':str(STANDARD),'standard_sha256':STANDARD_SHA,
        'task_sha256':TASK_SHA,'target_manifest_sha256':MANIFEST_SHA,
        'r1_complete_sha256':R1_SHA,'r1_review_sha256':REVIEW_SHA,
        'original_so_sha256':SOURCE_SHA,'original_fde_candidate_bodies_verified':127,
        'instruction_listings':10943,'nonempty_pcode_instruction_positions':10746,
        'empty_pcode_instruction_positions':197,'pcode_operations':37532,
        'empty_control_security_opcode_positions':173,
        'nonempty_c_like_outputs':127,'original_full_fde_body_membership':123,
        'transient_full_fde_metadata_assumptions':4,
        'fresh_session_original_metadata_and_memory_replays':4,
        'source_direct_call_sites':540,'source_indirect_call_sites':77,
        'ordinary_spread_listings':1382,'ordinary_spread_nonempty_pcode_positions':1332,
        'cumulative_selected_distinct_candidates':503,
        'remaining_unselected_global_indices':[201,211,216,235,293,304,349,362],
        'fresh_imports':0,'verified_behavior_candidates':0,
        'files':files,'code_files':codes,
        'limits':'197 listings lack emitted p-code, including 173 BTI/PAC/AUT; '
                 'FDE boundaries, C-like text and p-code do not prove complete behavior.'})
    print(json.dumps({'status':'SEALED_CORRECTED_PARTIAL_RESEARCH_CANDIDATE',
                      'listings':total_listings,'nonempty':total_nonempty,
                      'empty':len(empty_records),'operations':total_operations,
                      'complete_sha256':sha(R2/'COMPLETE.json')}))


if __name__ == '__main__':
    main()
