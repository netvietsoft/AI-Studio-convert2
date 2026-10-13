"""Publish the narrow TASK_205 R2 p-code-coverage wording correction."""

import datetime as dt
import hashlib
import json

from prepare_publish_tasks189_190 import ROOT, STANDARD_SHA, atomic_file
from controller import Controller, file_sha


TASK_PATH = ROOT / 'RULES/TASK/TASK_205_SO45_CODEX_INTERNAL_ACTIVE.md'
R1_TASK_SHA = '4eb23a8ff4eb3345be6a3bb61f353725377a45f5fdcf1c8070e402d2bf2906ac'
MANIFEST = ROOT / '.ai/ceo/reviews/TASK_205_internal_targets.json'
MANIFEST_SHA = 'fb7fc5d6f7ef0bb067a0989263bffc60b75a1be40e3ac2c39b9c7759b8666d12'
R1_REPORT = ROOT / 'RULES/REPORT/TASK_205_REPORT_R1'
R1_SEAL_SHA = 'd1d03840795c96e092241be72ce9c3bf6d8939c44660898ceb39825384cc8fac'
R1_FINGERPRINT = '61976a1abb5c257fa3e159a8f0ee85bfc0d3182533bc85e509e5aa1389788cdf'
R1_REVIEW = ROOT / f'.ai/ceo/reviews/TASK_205-{R1_FINGERPRINT}.md'
R1_ARCHIVE = ROOT / f'.ai/ceo/reviews/TASK_205_R1_TASK_ARCHIVE_{R1_TASK_SHA}.md'
SOURCE_SHA = '7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b'
ORIGINAL_DEADLINE = '2026-10-13T15:09:28.505005+00:00'


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or file_sha(ROOT / 'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt') != STANDARD_SHA:
        raise RuntimeError('END requested or canonical changed')
    if (file_sha(TASK_PATH) != R1_TASK_SHA or file_sha(MANIFEST) != MANIFEST_SHA
            or file_sha(R1_REPORT / 'COMPLETE.json') != R1_SEAL_SHA):
        raise RuntimeError('immutable R1 task/manifest/report changed')
    if any(p.exists() for p in (R1_ARCHIVE, ROOT / 'RULES/REPORT/TASK_205_REPORT_R2')):
        raise RuntimeError('R2 publication already started')
    now = dt.datetime.now(dt.timezone.utc)
    if now >= dt.datetime.fromisoformat(ORIGINAL_DEADLINE):
        raise RuntimeError('original absolute budget deadline exhausted')
    stamp = now.isoformat(timespec='microseconds').replace('+00:00', 'Z')
    report = 'RULES/REPORT/TASK_205_REPORT_R2'
    meta = {
        'schema_version': '2.1.2', 'task_id': 'TASK_205', 'revision': 2,
        'status': 'ACTIVE', 'assignee': '/root/so45_imagecodec_internal',
        'agent_id': '/root/so45_imagecodec_internal', 'priority': 'P1',
        'dependencies': [{'task_id': 'TASK_202', 'revision': 1}],
        'mode': 'RESEARCH_CORRECTION', 'report_folder': report,
        'files_allowed': [report + '/**', 'scripts/task_205_codex_correction_r2/**'],
        'files_forbidden': ['RULES/TASK/**', 'RULES/REPORT/TASK_205_REPORT_R1/**',
                            'RESEARCH_WORK/**', 'SOURCE/**', '.ai/**', 'app/**',
                            'apps/**', 'lib-*/**', 'Backend/**', 'services/**', 'packages/**'],
        'max_minutes': 15, 'max_cpu': 1, 'max_heap': '1G',
        'expected_lease_id': 'LEASE-CEO-WORKER-TASK_205-R2',
        'standard_sha256': STANDARD_SHA,
        'source_libraries': {'libPVGImageCodec.so': {
            'sha256': SOURCE_SHA, 'defined_nonzero_export_vas': 3326}},
        'target_manifest_path': MANIFEST.relative_to(ROOT).as_posix(),
        'target_manifest_sha256': MANIFEST_SHA, 'target_candidate_count': 126,
        'correction_of': {'task_revision': 1, 'task_sha256': R1_TASK_SHA,
                          'manifest_sha256': MANIFEST_SHA,
                          'report_folder': 'RULES/REPORT/TASK_205_REPORT_R1',
                          'complete_sha256': R1_SEAL_SHA,
                          'ceo_review_fingerprint': R1_FINGERPRINT,
                          'ceo_review_sha256': file_sha(R1_REVIEW)},
        'created_at': stamp, 'modified_time': stamp,
        'budget_deadline_utc': ORIGINAL_DEADLINE,
        'authorization_reference': 'Chairman Tony direct Codex SO45 decoding; CEO R1 NEEDS_FIX review',
    }
    body = f'''# TASK_205 R2 - correct nonempty p-code coverage labels only

STATUS: ACTIVE
ASSIGNEE: /root/so45_imagecodec_internal
PRIORITY: P1
MODIFIED_TIME: {stamp}

```json
{json.dumps(meta, ensure_ascii=False, indent=2)}
```

CEO R1 review `{R1_REVIEW.relative_to(ROOT).as_posix()}` found one material reporting overclaim. The immutable R1 raw Ghidra evidence has 6,246/6,246 instruction listings, but six `nop` rows have `pcode_ops: []`: candidate 380 at database VA `0x2db2ac`; candidate 381 at `0x2db538`, `0x2dbdd0`, `0x2dbe6c`; candidate 384 at `0x2dc3f0`, `0x2dc3fc`. Thus only 6,240 positions have at least one p-code operation; total p-code operations remain 25,604. The R1 master/audit and machine-readable verification/seal/progress unqualified 6,246-p-code-position claim is false under its ordinary meaning. R1 report/code/raw/private project and exact original manifest `{MANIFEST.relative_to(ROOT).as_posix()}` SHA-256 `{MANIFEST_SHA}` stay immutable.

Before any write fully reread `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` SHA-256 `{STANDARD_SHA}`, AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, config/state/locks/END, this exact ACTIVE R2 task and manifest. Claim TASK_205 revision 2 as `/root/so45_imagecodec_internal` via `LEASE-CEO-WORKER-TASK_205-R2`. The original absolute deadline {ORIGINAL_DEADLINE} persists, and this correction is capped at 15 minutes from claim. R1 task archive, report/code/project, original SO and CEO review are read-only. Write only `{report}/**` and `scripts/task_205_codex_correction_r2/**`.

Independently parse all 126 immutable R1 effective Ghidra instruction/p-code records, identify the six exact empty-list NOPs, and recheck 6,246 listings, 6,240 nonempty-p-code positions and 25,604 total operations. Publish `CORRECTED_COVERAGE.json` with these separately named metrics and six exact candidate/source/database VAs; `R1_TO_R2_DELTA.json` with every corrected claim/field and proof that all other critical source, C-like, boundary, project and call/branch counts remain unchanged. Produce `00_AUDIT_INDEX.md` with canonical read and pinned R1 hashes, `01_MASTER_REPORT.md` stating PARTIAL research and corrected coverage, `PROGRESS.json`, and SHA-256-sealed `COMPLETE.json` with exact report/code file inventory. An overlay is sufficient; do not rewrite R1 files. No Ghidra rerun, original SO/product/P0 edit, functional/parity/complete-function claim, product Phase PASS, V4/P7, all-45-SO completion, commit or push before CEO independent review.
'''
    task_raw = body.encode('utf8')
    with ctl.transaction() as (registry, state):
        lease = ctl.ceo_lease(registry)
        prior = state['tasks'].get('TASK_205', {}).get('verdict') or {}
        if (prior.get('disposition'), prior.get('revision'), prior.get('fingerprint')) != (
                'NEEDS_FIX', 1, R1_FINGERPRINT):
            raise RuntimeError('exact R1 NEEDS_FIX verdict absent')
        if not ctl.accepted('TASK_202', state, ctl.tasks(), required_revision=1):
            raise RuntimeError('TASK_202 dependency stale')
        if file_sha(TASK_PATH) != R1_TASK_SHA:
            raise RuntimeError('R1 task changed during publication')
        for path in (R1_ARCHIVE, TASK_PATH):
            ctl.authorized(lease, path)
        atomic_file(R1_ARCHIVE, TASK_PATH.read_bytes())
        atomic_file(TASK_PATH, task_raw)
        ctl.event(state, 'CODEX_TASK_CORRECTION_REVISION_PUBLISHED', task_id='TASK_205',
                  revision=2, task_sha256=hashlib.sha256(task_raw).hexdigest(),
                  manifest_sha256=MANIFEST_SHA, prior_task_archive=R1_ARCHIVE.relative_to(ROOT).as_posix(),
                  prior_fingerprint=R1_FINGERPRINT, deadline=ORIGINAL_DEADLINE,
                  scope='R1 listing 6246 vs nonempty p-code 6240; immutable original extraction')
    print(json.dumps({'task_id': 'TASK_205', 'revision': 2,
                      'task_sha256': file_sha(TASK_PATH),
                      'manifest_sha256': file_sha(MANIFEST),
                      'archive_sha256': file_sha(R1_ARCHIVE),
                      'original_deadline': ORIGINAL_DEADLINE}))


if __name__ == '__main__':
    main()
