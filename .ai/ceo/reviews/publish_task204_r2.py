"""Publish the narrow TASK_204 R2 p-code-coverage wording correction."""

import datetime as dt
import hashlib
import json

from prepare_publish_tasks189_190 import ROOT, STANDARD_SHA, atomic_file
from controller import Controller, file_sha


TASK_PATH = ROOT / 'RULES/TASK/TASK_204_SO45_CODEX_INTERNAL_ACTIVE.md'
R1_TASK_SHA = 'a175e7b87e7e257d6623d4f650201ba091868794d54cd2d77ca7a3ebaf9d43ee'
MANIFEST = ROOT / '.ai/ceo/reviews/TASK_204_internal_targets.json'
MANIFEST_SHA = '548a3f83bf498b047d34dd77e707c00d3644d1c8780eef4e71d8e43802874793'
R1_REPORT = ROOT / 'RULES/REPORT/TASK_204_REPORT_R1'
R1_SEAL_SHA = 'edbbc77985569a49089745f51c672b807cc428bab307566c697551e49de7b710'
R1_FINGERPRINT = '21d00b2a2cba642f907fc577b233fda1a8c89b8df4e239dd5e9ed5e99c590d4b'
R1_REVIEW = ROOT / f'.ai/ceo/reviews/TASK_204-{R1_FINGERPRINT}.md'
R1_ARCHIVE = ROOT / f'.ai/ceo/reviews/TASK_204_R1_TASK_ARCHIVE_{R1_TASK_SHA}.md'
SOURCE_SHA = 'f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4'
ORIGINAL_DEADLINE = '2026-10-13T15:09:28.505005+00:00'


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or file_sha(ROOT / 'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt') != STANDARD_SHA:
        raise RuntimeError('END requested or canonical changed')
    if (file_sha(TASK_PATH) != R1_TASK_SHA or file_sha(MANIFEST) != MANIFEST_SHA
            or file_sha(R1_REPORT / 'COMPLETE.json') != R1_SEAL_SHA):
        raise RuntimeError('immutable R1 task/manifest/report changed')
    if any(p.exists() for p in (R1_ARCHIVE, ROOT / 'RULES/REPORT/TASK_204_REPORT_R2')):
        raise RuntimeError('R2 publication already started')
    now = dt.datetime.now(dt.timezone.utc)
    if now >= dt.datetime.fromisoformat(ORIGINAL_DEADLINE):
        raise RuntimeError('original absolute budget deadline exhausted')
    stamp = now.isoformat(timespec='microseconds').replace('+00:00', 'Z')
    report = 'RULES/REPORT/TASK_204_REPORT_R2'
    meta = {
        'schema_version': '2.1.2', 'task_id': 'TASK_204', 'revision': 2,
        'status': 'ACTIVE', 'assignee': '/root/so45_mtfilter_next',
        'agent_id': '/root/so45_mtfilter_next', 'priority': 'P1',
        'dependencies': [{'task_id': 'TASK_201', 'revision': 2}],
        'mode': 'RESEARCH_CORRECTION', 'report_folder': report,
        'files_allowed': [report + '/**', 'scripts/task_204_codex_correction_r2/**'],
        'files_forbidden': ['RULES/TASK/**', 'RULES/REPORT/TASK_204_REPORT_R1/**',
                            'RESEARCH_WORK/**', 'SOURCE/**', '.ai/**', 'app/**',
                            'apps/**', 'lib-*/**', 'Backend/**', 'services/**', 'packages/**'],
        'max_minutes': 15, 'max_cpu': 1, 'max_heap': '1G',
        'expected_lease_id': 'LEASE-CEO-WORKER-TASK_204-R2',
        'standard_sha256': STANDARD_SHA,
        'source_libraries': {'libMTFilterKernel.so': {
            'sha256': SOURCE_SHA, 'defined_nonzero_export_vas': 2362}},
        'target_manifest_path': MANIFEST.relative_to(ROOT).as_posix(),
        'target_manifest_sha256': MANIFEST_SHA, 'target_candidate_count': 127,
        'correction_of': {'task_revision': 1, 'task_sha256': R1_TASK_SHA,
                          'manifest_sha256': MANIFEST_SHA,
                          'report_folder': 'RULES/REPORT/TASK_204_REPORT_R1',
                          'complete_sha256': R1_SEAL_SHA,
                          'ceo_review_fingerprint': R1_FINGERPRINT,
                          'ceo_review_sha256': file_sha(R1_REVIEW)},
        'created_at': stamp, 'modified_time': stamp,
        'budget_deadline_utc': ORIGINAL_DEADLINE,
        'authorization_reference': 'Chairman Tony direct Codex SO45 decoding; CEO R1 NEEDS_FIX review',
    }
    body = f'''# TASK_204 R2 - correct nonempty p-code coverage labels only

STATUS: ACTIVE
ASSIGNEE: /root/so45_mtfilter_next
PRIORITY: P1
MODIFIED_TIME: {stamp}

```json
{json.dumps(meta, ensure_ascii=False, indent=2)}
```

CEO R1 review `{R1_REVIEW.relative_to(ROOT).as_posix()}` found a material coverage-label error. Immutable R1 raw Ghidra evidence has 10,943/10,943 instruction listings, but 197 listings have `pcode_ops: []`: 24 NOP, 96 BTI, 29 PACIASP, 46 AUTIASP, one AUTIB1716 and one AUTIA1716. Only 10,746 positions have at least one p-code operation; total operations remain 37,532. BTI/PAC/AUT semantics are not proven by their empty p-code lists or by C-like text alone. R1 report/code/raw/private project and exact original manifest `{MANIFEST.relative_to(ROOT).as_posix()}` SHA-256 `{MANIFEST_SHA}` stay immutable.

Before any write fully reread `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` SHA-256 `{STANDARD_SHA}`, AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, config/state/locks/END, this exact ACTIVE R2 task and manifest. Claim TASK_204 revision 2 as `/root/so45_mtfilter_next` via `LEASE-CEO-WORKER-TASK_204-R2`. The original absolute deadline {ORIGINAL_DEADLINE} persists, and this correction is capped at 15 minutes from claim. R1 task archive, report/code/project, original SO and CEO review are read-only. Write only `{report}/**` and `scripts/task_204_codex_correction_r2/**`.

Independently parse all 127 immutable R1 effective Ghidra instruction/p-code records and the four correction overlays. Recheck 10,943 listings, 10,746 nonempty-p-code positions, 197 empty-list positions and 37,532 total operations. Publish `CORRECTED_COVERAGE.json` with separately named metrics, per-candidate empty counts and opcode categories; `R1_TO_R2_DELTA.json` with every corrected claim/field and proof that all other critical source, C-like, boundary, project and call/branch counts remain unchanged. Produce `00_AUDIT_INDEX.md` with canonical read and pinned R1 hashes, `01_MASTER_REPORT.md` stating PARTIAL research and corrected coverage/PAC-BTI limit, `PROGRESS.json`, and SHA-256-sealed `COMPLETE.json` with exact report/code inventory. An overlay is sufficient; do not rewrite R1 files. No Ghidra rerun, original SO/product/P0 edit, functional/parity/complete-function claim, product Phase PASS, V4/P7, all-45-SO completion, commit or push before CEO independent review.
'''
    task_raw = body.encode('utf8')
    with ctl.transaction() as (registry, state):
        lease = ctl.ceo_lease(registry)
        prior = state['tasks'].get('TASK_204', {}).get('verdict') or {}
        if (prior.get('disposition'), prior.get('revision'), prior.get('fingerprint')) != (
                'NEEDS_FIX', 1, R1_FINGERPRINT):
            raise RuntimeError('exact R1 NEEDS_FIX verdict absent')
        if not ctl.accepted('TASK_201', state, ctl.tasks(), required_revision=2):
            raise RuntimeError('TASK_201 R2 dependency stale')
        if file_sha(TASK_PATH) != R1_TASK_SHA:
            raise RuntimeError('R1 task changed during publication')
        for path in (R1_ARCHIVE, TASK_PATH):
            ctl.authorized(lease, path)
        atomic_file(R1_ARCHIVE, TASK_PATH.read_bytes())
        atomic_file(TASK_PATH, task_raw)
        ctl.event(state, 'CODEX_TASK_CORRECTION_REVISION_PUBLISHED', task_id='TASK_204',
                  revision=2, task_sha256=hashlib.sha256(task_raw).hexdigest(),
                  manifest_sha256=MANIFEST_SHA, prior_task_archive=R1_ARCHIVE.relative_to(ROOT).as_posix(),
                  prior_fingerprint=R1_FINGERPRINT, deadline=ORIGINAL_DEADLINE,
                  scope='R1 listing 10943 vs nonempty p-code 10746; immutable original extraction')
    print(json.dumps({'task_id': 'TASK_204', 'revision': 2,
                      'task_sha256': file_sha(TASK_PATH),
                      'manifest_sha256': file_sha(MANIFEST),
                      'archive_sha256': file_sha(R1_ARCHIVE),
                      'original_deadline': ORIGINAL_DEADLINE}))


if __name__ == '__main__':
    main()
