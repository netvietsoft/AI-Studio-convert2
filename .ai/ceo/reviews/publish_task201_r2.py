"""Publish a narrow TASK_201 census correction without altering sealed R1 evidence."""

import copy
import datetime as dt
import hashlib
import json

from prepare_publish_tasks189_190 import ROOT, STANDARD_SHA, atomic_file
from controller import Controller, file_sha


TASK_PATH = ROOT / 'RULES/TASK/TASK_201_SO45_CODEX_INTERNAL_ACTIVE.md'
R1_TASK_SHA = '5caebf855c995650171dd848e46aa4699e06475b3e29945a8108df04ab6a243a'
R1_MANIFEST = ROOT / '.ai/ceo/reviews/TASK_201_internal_targets.json'
R1_MANIFEST_SHA = '3523ec8697b80bace822a7367bdcc226e984eb328b5b3a7f6d4a95128dbe5746'
R2_MANIFEST = ROOT / '.ai/ceo/reviews/TASK_201_R2_internal_targets.json'
R1_REPORT = ROOT / 'RULES/REPORT/TASK_201_REPORT_R1'
R1_SEAL_SHA = 'c1ed5968c93cc30bb4e1caa8e991dac870dbaeae084e78b8866959199e5933db'
R1_FINGERPRINT = '3aa9e79e3edebe13205ab0a1be1682e7c957aaa99dafe7e1c53f0c2247de5599'
R1_REVIEW = ROOT / f'.ai/ceo/reviews/TASK_201-{R1_FINGERPRINT}.md'
R1_ARCHIVE = ROOT / f'.ai/ceo/reviews/TASK_201_R1_TASK_ARCHIVE_{R1_TASK_SHA}.md'
SOURCE_SHA = 'f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4'
ORIGINAL_DEADLINE = '2026-10-13T14:25:58.997082+00:00'
EXCLUSIONS = [201, 211, 216, 235, 293, 304, 349, 362]


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or file_sha(ROOT / 'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt') != STANDARD_SHA:
        raise RuntimeError('END requested or canonical changed')
    if (file_sha(TASK_PATH) != R1_TASK_SHA or file_sha(R1_MANIFEST) != R1_MANIFEST_SHA
            or file_sha(R1_REPORT / 'COMPLETE.json') != R1_SEAL_SHA):
        raise RuntimeError('immutable R1 task/manifest/report changed')
    if any(p.exists() for p in (R2_MANIFEST, R1_ARCHIVE, ROOT / 'RULES/REPORT/TASK_201_REPORT_R2')):
        raise RuntimeError('R2 publication already started')
    now = dt.datetime.now(dt.timezone.utc)
    if now >= dt.datetime.fromisoformat(ORIGINAL_DEADLINE):
        raise RuntimeError('original absolute budget deadline exhausted')
    stamp = now.isoformat(timespec='microseconds').replace('+00:00', 'Z')
    old = json.loads(R1_MANIFEST.read_text(encoding='utf8'))
    if (old['revision'] != 1 or old['all_nonexport_fde_candidates'] != 511
            or old['selected_count'] != 62 or len(old['targets']) != 62
            or old['remaining_nonselected_candidates_after_slice'] != 129):
        raise RuntimeError('unexpected R1 census')
    newer = copy.deepcopy(old)
    newer['revision'] = 2
    newer['generated_at'] = stamp
    newer['remaining_nonselected_candidates_after_slice'] = 135
    newer['remaining_unselected_breakdown'] = {
        'tail_global_indices_inclusive': [384, 510],
        'tail_count': 127,
        'previous_and_current_excluded_indices': EXCLUSIONS,
        'excluded_count': 8,
        'basis': '511 distinct nonexport FDE candidates minus 376 distinct targets selected by TASK_187,189,193,197,201',
    }
    newer['correction_of_manifest_sha256'] = R1_MANIFEST_SHA
    manifest_raw = (json.dumps(newer, ensure_ascii=False, indent=2) + '\n').encode('utf8')
    manifest_sha = hashlib.sha256(manifest_raw).hexdigest()
    report = 'RULES/REPORT/TASK_201_REPORT_R2'
    meta = {
        'schema_version': '2.1.2', 'task_id': 'TASK_201', 'revision': 2,
        'status': 'ACTIVE', 'assignee': '/root/so45_mtfilter_next',
        'agent_id': '/root/so45_mtfilter_next', 'priority': 'P1',
        'dependencies': [{'task_id': 'TASK_197', 'revision': 1}],
        'mode': 'RESEARCH_CORRECTION', 'report_folder': report,
        'files_allowed': [report + '/**', 'scripts/task_201_codex_correction_r2/**'],
        'files_forbidden': ['RULES/TASK/**', 'RULES/REPORT/TASK_201_REPORT_R1/**',
                            'RESEARCH_WORK/**', 'SOURCE/**', '.ai/**', 'app/**',
                            'apps/**', 'lib-*/**', 'Backend/**', 'services/**', 'packages/**'],
        'max_minutes': 15, 'max_cpu': 1, 'max_heap': '1G',
        'expected_lease_id': 'LEASE-CEO-WORKER-TASK_201-R2',
        'standard_sha256': STANDARD_SHA,
        'source_libraries': {'libMTFilterKernel.so': {
            'sha256': SOURCE_SHA, 'defined_nonzero_export_vas': 2362}},
        'target_manifest_path': R2_MANIFEST.relative_to(ROOT).as_posix(),
        'target_manifest_sha256': manifest_sha, 'target_candidate_count': 62,
        'correction_of': {'task_revision': 1, 'task_sha256': R1_TASK_SHA,
                          'manifest_sha256': R1_MANIFEST_SHA,
                          'report_folder': 'RULES/REPORT/TASK_201_REPORT_R1',
                          'complete_sha256': R1_SEAL_SHA,
                          'worker_verification_sha256': file_sha(R1_REPORT / 'WORKER_VERIFICATION.json'),
                          'ceo_review_fingerprint': R1_FINGERPRINT,
                          'ceo_review_sha256': file_sha(R1_REVIEW),
                          'ceo_replay_summary_sha256': file_sha(ROOT / '.ai/ceo/reviews/TASK_201_CEO_REPLAY/summary.json')},
        'created_at': stamp, 'modified_time': stamp,
        'budget_deadline_utc': ORIGINAL_DEADLINE,
        'authorization_reference': 'Chairman Tony direct Codex SO45 decoding; CEO R1 NEEDS_FIX review',
    }
    body = f'''# TASK_201 R2 - correct remaining MTFilter candidate count only

STATUS: ACTIVE
ASSIGNEE: /root/so45_mtfilter_next
PRIORITY: P1
MODIFIED_TIME: {stamp}

```json
{json.dumps(meta, ensure_ascii=False, indent=2)}
```

CEO R1 review `{R1_REVIEW.relative_to(ROOT).as_posix()}` has NEEDS_FIX for one census error. The five exact accepted/sealed MTFilter manifests select 128+64+60+62+62 = 376 distinct targets out of 511 nonexport FDE candidates. The unselected total is **135**, comprising tail indices 384..510 (127) plus eight prior/current exclusions {EXCLUSIONS}. R1 mistakenly says 129 because it omits six earlier exclusions. R2 manifest `{R2_MANIFEST.relative_to(ROOT).as_posix()}` SHA-256 `{manifest_sha}` preserves all 62 target rows and original body hashes; only census metadata changes. The older TASK_197 residual count is also historical and inaccurate; do not edit its sealed artifact.

Before any write fully reread `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` SHA-256 `{STANDARD_SHA}`, AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, config/state/locks/END, this exact ACTIVE R2 task and manifest. Claim TASK_201 revision 2 as `/root/so45_mtfilter_next` via `LEASE-CEO-WORKER-TASK_201-R2`. The original absolute deadline {ORIGINAL_DEADLINE} persists and this correction is capped at 15 minutes from claim. R1 task archive, report, source/assembly, code, project and CEO replay are read-only; write only `{report}/**` and `scripts/task_201_codex_correction_r2/**`.

Independently recompute the union of the five manifest target indices and exclusions. Produce `00_AUDIT_INDEX.md` with canonical path/hash, `01_MASTER_REPORT.md` with exact 376/511/135 arithmetic and limits, `CORRECTION_DELTA.json` proving the new manifest's 62 targets match R1 byte-for-byte after JSON parsing and identifying only changed census metadata, `PROGRESS.json`, and SHA-256 sealed `COMPLETE.json` for all R2 report/code files. Explicitly cite immutable R1 COMPLETE, original task/manifest and CEO review/replay hashes. Do not rerun Ghidra, alter R1, original SO, product code or P0, claim complete unique functions or behavior, product Phase PASS, V4/P7, all 45 SOs, or commit/push before CEO independent review.
'''
    task_raw = body.encode('utf8')
    with ctl.transaction() as (registry, state):
        lease = ctl.ceo_lease(registry)
        prior = state['tasks'].get('TASK_201', {}).get('verdict') or {}
        if (prior.get('disposition'), prior.get('revision'), prior.get('fingerprint')) != (
                'NEEDS_FIX', 1, R1_FINGERPRINT):
            raise RuntimeError('exact R1 NEEDS_FIX verdict absent')
        if not ctl.accepted('TASK_197', state, ctl.tasks(), required_revision=1):
            raise RuntimeError('TASK_197 dependency stale')
        if file_sha(TASK_PATH) != R1_TASK_SHA:
            raise RuntimeError('R1 task changed during publication')
        for path in (R1_ARCHIVE, R2_MANIFEST, TASK_PATH):
            ctl.authorized(lease, path)
        atomic_file(R1_ARCHIVE, TASK_PATH.read_bytes())
        atomic_file(R2_MANIFEST, manifest_raw)
        atomic_file(TASK_PATH, task_raw)
        ctl.event(state, 'CODEX_TASK_CORRECTION_REVISION_PUBLISHED', task_id='TASK_201',
                  revision=2, task_sha256=hashlib.sha256(task_raw).hexdigest(),
                  manifest_sha256=manifest_sha, prior_task_archive=R1_ARCHIVE.relative_to(ROOT).as_posix(),
                  prior_fingerprint=R1_FINGERPRINT, deadline=ORIGINAL_DEADLINE,
                  scope='R1 count 129 to correct 135; immutable original extraction')
    print(json.dumps({'task_id': 'TASK_201', 'revision': 2,
                      'task_sha256': file_sha(TASK_PATH),
                      'manifest_sha256': file_sha(R2_MANIFEST),
                      'archive_sha256': file_sha(R1_ARCHIVE),
                      'original_deadline': ORIGINAL_DEADLINE}))


if __name__ == '__main__':
    main()
