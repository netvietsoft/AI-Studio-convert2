"""Verify TASK_201's cumulative MTFilter FDE census and seal an R2-only correction."""
from __future__ import annotations

import hashlib
import json
import os
import tempfile
from datetime import datetime, timezone
from pathlib import Path

from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]
REPORT = ROOT / 'RULES/REPORT/TASK_201_REPORT_R2'
SCRIPT = Path(__file__).resolve()
TASK = ROOT / 'RULES/TASK/TASK_201_SO45_CODEX_INTERNAL_ACTIVE.md'
STANDARD = ROOT / 'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt'
SOURCE = Path('F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libMTFilterKernel.so')
R1_REPORT = ROOT / 'RULES/REPORT/TASK_201_REPORT_R1'
R1_MANIFEST = ROOT / '.ai/ceo/reviews/TASK_201_internal_targets.json'
R2_MANIFEST = ROOT / '.ai/ceo/reviews/TASK_201_R2_internal_targets.json'
R1_TASK_ARCHIVE = ROOT / '.ai/ceo/reviews/TASK_201_R1_TASK_ARCHIVE_5caebf855c995650171dd848e46aa4699e06475b3e29945a8108df04ab6a243a.md'
CEO_REVIEW = ROOT / '.ai/ceo/reviews/TASK_201-3aa9e79e3edebe13205ab0a1be1682e7c957aaa99dafe7e1c53f0c2247de5599.md'
CEO_REPLAY = ROOT / '.ai/ceo/reviews/TASK_201_CEO_REPLAY/summary.json'
EXPECTED = {
    STANDARD: '10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f',
    TASK: 'a27842302657268895653e9b3b8d3a3e3ff67cd58b5ef58bbf6357e2db2a5d96',
    SOURCE: 'f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4',
    R1_MANIFEST: '3523ec8697b80bace822a7367bdcc226e984eb328b5b3a7f6d4a95128dbe5746',
    R2_MANIFEST: '4f1f0e38460ef8d32d0e0d15de56feadc050d6e097cf385c4e9a41dca7f7932a',
    R1_TASK_ARCHIVE: '5caebf855c995650171dd848e46aa4699e06475b3e29945a8108df04ab6a243a',
    R1_REPORT / 'COMPLETE.json': 'c1ed5968c93cc30bb4e1caa8e991dac870dbaeae084e78b8866959199e5933db',
    R1_REPORT / 'WORKER_VERIFICATION.json': '8c8c4ca1e82ada63b54de414ee6624d9d1b99a139a051c4f8e520ec3259ee0e1',
    CEO_REVIEW: '592a92628e96f1537dc98ff82b55166a35b38d60bbd6fe1b860de2bd20dfabd6',
    CEO_REPLAY: '1f0cc23cffcadb4395a4979c287819979e3059c350f51cff2ed54ad8de54d76b',
}
MANIFESTS = {
    187: 'cdca39d65d7a29d866b3e43264f687d147b549c43945e4f0c694fb8e73d56bf8',
    189: '569b5f8348e847139cc90ec5e42023a4360724d98210101c83003a86e3587693',
    193: '44c08dc8cb67c4e3dec44dbd29726602dcd74e5be771d8ba926252c7d8e95d44',
    197: '273d3508fb7a933cbbff362364a8e35be067892aba01620adb953a54697d1af6',
    201: EXPECTED[R1_MANIFEST],
}
LEASE = 'LEASE-CEO-WORKER-TASK_201-R2'
FENCE = 1237
AGENT = '/root/so45_mtfilter_next'
ABSOLUTE_DEADLINE = datetime.fromisoformat('2026-10-13T14:25:58.997082+00:00')


def digest(path: Path) -> str:
    h = hashlib.sha256()
    with path.open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            h.update(block)
    return h.hexdigest()


def load(path: Path) -> dict:
    return json.loads(path.read_text(encoding='utf-8'))


def stamp() -> str:
    return datetime.now(timezone.utc).isoformat().replace('+00:00', 'Z')


def check_lease() -> None:
    for path, expected in EXPECTED.items():
        if digest(path) != expected:
            raise RuntimeError(f'pinned input hash differs: {path}')
    flag = ROOT / '.ai/ceo/END_AGENT_SESSION.flag'
    if flag.exists() and flag.read_text(encoding='utf-8-sig').strip().upper() == 'TRUE':
        raise RuntimeError('END_AGENT_SESSION=TRUE')
    if datetime.now(timezone.utc) >= ABSOLUTE_DEADLINE:
        raise RuntimeError('original absolute deadline passed')
    locks = load(ROOT / '.ai/locks.json')['active_locks']
    rows = [row for row in locks if row.get('lease_id') == LEASE]
    if len(rows) != 1:
        raise RuntimeError('exact R2 lease missing/duplicated')
    row = rows[0]
    if (row.get('status'), row.get('agent_id'), row.get('task_id'),
        row.get('task_revision'), row.get('task_sha'), row.get('fencing_token')) != (
            'ACTIVE', AGENT, 'TASK_201', 2, EXPECTED[TASK], FENCE):
        raise RuntimeError('lease identity or fencing differs')
    if datetime.fromisoformat(row['expiry'].replace('Z', '+00:00')) <= datetime.now(timezone.utc):
        raise RuntimeError('15-minute R2 lease expired')
    allowed = set(row.get('files_allowed', []))
    if allowed != {'RULES/REPORT/TASK_201_REPORT_R2/**',
                   'scripts/task_201_codex_correction_r2/**'}:
        raise RuntimeError('R2 write scope differs')


def atomic(path: Path, content: bytes) -> None:
    check_lease()
    relative = path.resolve().relative_to(ROOT.resolve()).as_posix()
    if not relative.startswith('RULES/REPORT/TASK_201_REPORT_R2/'):
        raise RuntimeError('output outside R2 report scope')
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temporary = tempfile.mkstemp(prefix='.task201r2-', dir=path.parent)
    try:
        with os.fdopen(fd, 'wb') as out:
            out.write(content)
            out.flush()
            os.fsync(out.fileno())
        os.replace(temporary, path)
    finally:
        if os.path.exists(temporary):
            os.unlink(temporary)


def write_json(path: Path, value: object) -> None:
    atomic(path, (json.dumps(value, ensure_ascii=False, indent=2) + '\n').encode('utf-8'))


def main() -> None:
    check_lease()
    if REPORT.exists():
        raise RuntimeError('R2 report already started; do not overwrite a candidate')
    r1, r2 = load(R1_MANIFEST), load(R2_MANIFEST)
    if r1['targets'] != r2['targets'] or len(r1['targets']) != 62:
        raise RuntimeError('R1/R2 target rows differ')
    target_encoding = lambda value: json.dumps(value, sort_keys=True, separators=(',', ':')).encode('utf-8')
    target_hash = hashlib.sha256(target_encoding(r1['targets'])).hexdigest()
    changes = sorted(k for k in set(r1) | set(r2) if r1.get(k) != r2.get(k))
    expected_changes = ['correction_of_manifest_sha256', 'generated_at',
                        'remaining_nonselected_candidates_after_slice',
                        'remaining_unselected_breakdown', 'revision']
    if changes != expected_changes or r1['revision'] != 1 or r2['revision'] != 2 or (
            r1['remaining_nonselected_candidates_after_slice'],
            r2['remaining_nonselected_candidates_after_slice']) != (129, 135) or (
            r2['correction_of_manifest_sha256'] != EXPECTED[R1_MANIFEST]):
        raise RuntimeError(f'R1/R2 metadata delta differs: {changes}')
    r1_seal = load(R1_REPORT / 'COMPLETE.json')
    for rel, expected in r1_seal['files'].items():
        if digest(R1_REPORT / rel) != expected:
            raise RuntimeError(f'R1 report artifact changed: {rel}')
    for key in ('code_files', 'scratch_files'):
        for rel, expected in r1_seal[key].items():
            if digest(ROOT / rel) != expected:
                raise RuntimeError(f'R1 {key} artifact changed: {rel}')
    selected = set()
    exclusions = {201, 211, 216, 235, 293, 304, 349, 362}
    expected_counts = {187: 128, 189: 64, 193: 60, 197: 62, 201: 62}
    manifest_rows = []
    with SOURCE.open('rb') as stream:
        elf = ELFFile(stream)
        if elf['e_machine'] != 'EM_AARCH64':
            raise RuntimeError('original SO architecture differs')
        fdes = [(int(x['initial_location']), int(x['address_range']))
                for x in elf.get_dwarf_info().EH_CFI_entries() if isinstance(x, FDE)]
        dyn = elf.get_section_by_name('.dynsym')
        starts = {int(x['st_value']) for x in dyn.iter_symbols()
                  if x['st_info']['type'] == 'STT_FUNC' and x['st_shndx'] != 'SHN_UNDEF'
                  and int(x['st_value']) > 0 and int(x['st_size']) > 0}
        candidates = sorted(x for x in fdes if x[0] not in starts)
        segments = [(int(s['p_vaddr']), int(s['p_filesz']), int(s['p_offset']))
                    for s in elf.iter_segments() if s['p_type'] == 'PT_LOAD']
        if len(fdes) != 2873 or len(starts) != 2362 or len(candidates) != 511:
            raise RuntimeError('original SO FDE/dynsym census differs')
        for task_id in (187, 189, 193, 197, 201):
            path = ROOT / f'.ai/ceo/reviews/TASK_{task_id}_internal_targets.json'
            if digest(path) != MANIFESTS[task_id]:
                raise RuntimeError(f'TASK_{task_id} manifest hash differs')
            data = load(path)
            rows = data['targets']
            start = {187: 0, 189: 128, 193: 192, 197: 256, 201: 320}[task_id]
            stop = {187: 128, 189: 192, 193: 256, 197: 320, 201: 384}[task_id]
            excluded_here = set(data.get('excluded_oversized_global_indices', []))
            expected_ids = [i for i in range(start, stop) if i not in excluded_here]
            if len(rows) != expected_counts[task_id] or len(rows) != len(expected_ids):
                raise RuntimeError(f'TASK_{task_id} row count differs')
            verified_bytes = 0
            for number, row in zip(expected_ids, rows):
                if number in selected or number in exclusions:
                    raise RuntimeError(f'duplicate/excluded selected index {number}')
                va, size = int(row['elf_va'], 16), row['size_bytes']
                mappings = [off + va - base for base, length, off in segments
                            if base <= va and va + size <= base + length]
                if ((va, size) != candidates[number] or len(mappings) != 1 or
                        mappings[0] != int(row['file_offset'], 16) or
                        row['instruction_slots'] != size // 4 or
                        ('global_nonexport_fde_index' in row and
                         row['global_nonexport_fde_index'] != number)):
                    raise RuntimeError(f'TASK_{task_id} ELF/FDE mapping differs index {number}')
                stream.seek(mappings[0])
                if hashlib.sha256(stream.read(size)).hexdigest() != row['body_sha256']:
                    raise RuntimeError(f'TASK_{task_id} original body hash differs index {number}')
                verified_bytes += size
                selected.add(number)
            manifest_rows.append({'task_id': f'TASK_{task_id}', 'manifest_sha256': MANIFESTS[task_id],
                                  'global_index_start': start, 'global_index_end_exclusive': stop,
                                  'selected_count': len(rows), 'verified_original_body_bytes': verified_bytes,
                                  'excluded_indices': sorted(excluded_here)})
    unselected = set(range(511)) - selected
    tail = set(range(384, 511))
    if (len(selected) != 376 or len(unselected) != 135 or unselected != exclusions | tail or
            len(tail) != 127 or len(exclusions) != 8 or
            r2['remaining_nonselected_candidates_after_slice'] != len(unselected) or
            r2['remaining_unselected_breakdown']['tail_count'] != 127 or
            r2['remaining_unselected_breakdown']['excluded_count'] != 8 or
            r2['remaining_unselected_breakdown']['previous_and_current_excluded_indices'] != sorted(exclusions)):
        raise RuntimeError('five-manifest union/residual census differs')
    delta = {
        'task_id': 'TASK_201', 'revision': 2, 'generated_at': stamp(),
        'r1_manifest_sha256': EXPECTED[R1_MANIFEST], 'r2_manifest_sha256': EXPECTED[R2_MANIFEST],
        'r1_target_rows': 62, 'r2_target_rows': 62, 'targets_equal_after_json_parse': True,
        'canonical_targets_sha256_both_revisions': target_hash,
        'changed_top_level_fields_only': changes,
        'census_delta': {'r1_claimed_remaining': 129, 'r2_correct_remaining': 135,
                         'r1_missing_exclusions': [201, 211, 216, 235, 293, 304]},
        'original_so_sha256': EXPECTED[SOURCE], 'original_fde_ranges': 2873,
        'defined_nonzero_export_vas': 2362, 'nonexport_fde_candidates': 511,
        'five_manifests': manifest_rows, 'selected_distinct': 376,
        'unselected_distinct': 135, 'unselected_tail_indices_inclusive': [384, 510],
        'unselected_tail_count': 127, 'unselected_exclusions': sorted(exclusions),
        'unselected_exclusion_count': 8,
        'r1_complete_sha256': EXPECTED[R1_REPORT / 'COMPLETE.json'],
        'r1_worker_verification_sha256': EXPECTED[R1_REPORT / 'WORKER_VERIFICATION.json'],
        'r1_task_archive_sha256': EXPECTED[R1_TASK_ARCHIVE],
        'ceo_r1_review_fingerprint': '3aa9e79e3edebe13205ab0a1be1682e7c957aaa99dafe7e1c53f0c2247de5599',
        'ceo_r1_review_sha256': EXPECTED[CEO_REVIEW], 'ceo_replay_summary_sha256': EXPECTED[CEO_REPLAY],
        'r1_declared_report_files_rehashed': len(r1_seal['files']),
        'r1_declared_code_files_rehashed': len(r1_seal['code_files']),
        'r1_declared_scratch_files_rehashed': len(r1_seal['scratch_files']),
    }
    audit = (
        '# TASK_201 R2 audit index\n\n'
        f'Canonical Standard fully reread: `{STANDARD.resolve()}`; SHA-256 `{EXPECTED[STANDARD]}`.\n\n'
        f'Exact ACTIVE R2 task SHA-256 `{EXPECTED[TASK]}` and target manifest SHA-256 `{EXPECTED[R2_MANIFEST]}`. '
        f'Worker `{AGENT}`, lease `{LEASE}`, fence `{FENCE}`.\n\n'
        f'Immutable R1 task archive `{R1_TASK_ARCHIVE.relative_to(ROOT).as_posix()}` SHA-256 `{EXPECTED[R1_TASK_ARCHIVE]}`; '
        f'R1 manifest `{EXPECTED[R1_MANIFEST]}`, R1 COMPLETE `{EXPECTED[R1_REPORT / "COMPLETE.json"]}`, '
        f'R1 worker verification `{EXPECTED[R1_REPORT / "WORKER_VERIFICATION.json"]}`. '
        f'CEO NEEDS_FIX review `{CEO_REVIEW.relative_to(ROOT).as_posix()}` SHA-256 `{EXPECTED[CEO_REVIEW]}` '
        f'and read-only replay summary SHA-256 `{EXPECTED[CEO_REPLAY]}`.\n\n'
        'This revision changes only cumulative unselected-candidate census packaging. '
        '`CORRECTION_DELTA.json` proves target-row equality and the five-manifest original-SO union. '
        'R1 report, code, project, original SO and CEO review/replay were read-only.\n'
    )
    master = (
        '# TASK_201 R2 — corrected MTFilter candidate census\n\n'
        '**Result: 376 selected distinct FDE candidates out of 511; 135 remain unselected.** '
        'Five immutable manifest selections contain 128 + 64 + 60 + 62 + 62 = 376 distinct '
        'global zero-based nonexport FDE indices. The remainder is 127 tail indices 384..510 '
        'plus eight earlier/current exclusions [201, 211, 216, 235, 293, 304, 349, 362]. '
        'R1 reported 129 by omitting six prior exclusions. The older TASK_197 residual count '
        'is historical and also inaccurate; its sealed report remains unchanged.\n\n'
        'The 62 TASK_201 target rows and body hashes are identical in R1 and R2 after JSON '
        'parsing. All 376 selections were checked against the original SO FDE/dynsym/PT_LOAD '
        'census and body hashes. R1 extraction evidence remains the same research candidate: '
        'seven full-FDE boundary assumptions, two oversized current exclusions and no proven '
        'unique functions or behavior. CEO independent review of the corrected package is '
        'pending. No Ghidra rerun, production edit, commit, push, Phase PASS, all-45-SO '
        'completion, V4 or P7 claim.\n'
    )
    atomic(REPORT / '00_AUDIT_INDEX.md', audit.encode('utf-8'))
    atomic(REPORT / '01_MASTER_REPORT.md', master.encode('utf-8'))
    write_json(REPORT / 'CORRECTION_DELTA.json', delta)
    write_json(REPORT / 'PROGRESS.json', {
        'task_id': 'TASK_201', 'revision': 2, 'status': 'SEALED_CENSUS_CORRECTION_CANDIDATE',
        'generated_at': stamp(), 'selected_distinct': 376, 'unselected_distinct': 135,
        'targets_unchanged': True, 'ghidra_reruns': 0,
        'disposition': 'AWAITING_INDEPENDENT_CEO_REVIEW'})
    files = {p.relative_to(REPORT).as_posix(): digest(p) for p in sorted(REPORT.rglob('*'))
             if p.is_file() and p.name not in {'COMPLETE.json', 'PROGRESS.json', 'PROGRESS.md'}}
    code_files = {SCRIPT.relative_to(ROOT).as_posix(): digest(SCRIPT)}
    if set(files) != {'00_AUDIT_INDEX.md', '01_MASTER_REPORT.md', 'CORRECTION_DELTA.json'}:
        raise RuntimeError('unexpected report files before seal')
    complete = {
        'schema_version': '2.1.2', 'task_id': 'TASK_201', 'revision': 2,
        'status': 'COMPLETE', 'research_result': 'PARTIAL_BOUNDARY_CENSUS_CORRECTED',
        'generated_at': stamp(), 'agent_id': AGENT, 'lease_id': LEASE,
        'fencing_token': FENCE, 'standard_path': str(STANDARD),
        'standard_sha256': EXPECTED[STANDARD], 'task_sha256': EXPECTED[TASK],
        'target_manifest_sha256': EXPECTED[R2_MANIFEST],
        'r1_complete_sha256': EXPECTED[R1_REPORT / 'COMPLETE.json'],
        'r1_worker_verification_sha256': EXPECTED[R1_REPORT / 'WORKER_VERIFICATION.json'],
        'ceo_r1_review_sha256': EXPECTED[CEO_REVIEW],
        'selected_distinct_fde_candidates': 376, 'unselected_distinct_fde_candidates': 135,
        'tail_unselected': 127, 'excluded_unselected': 8,
        'r1_r2_target_rows_identical': True, 'ghidra_reruns': 0,
        'files': files, 'code_files': code_files,
        'limits': 'Census correction only. FDE candidates, C-like text and transient full-FDE metadata '
                  'do not prove unique function boundaries, behavior or product readiness.'}
    atomic(REPORT / 'COMPLETE.json', (json.dumps(complete, ensure_ascii=False, indent=2) + '\n').encode('utf-8'))
    print(json.dumps({'status': 'SEALED_CENSUS_CORRECTION_CANDIDATE',
                      'selected': len(selected), 'unselected': len(unselected),
                      'target_hash': target_hash,
                      'complete_sha256': digest(REPORT / 'COMPLETE.json')}))


if __name__ == '__main__':
    main()
