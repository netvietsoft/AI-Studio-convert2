"""Publish the narrow TASK_203 R2 evidence-label correction."""

import datetime as dt
import hashlib
import json

from prepare_publish_tasks189_190 import ROOT, STANDARD_SHA, atomic_file
from controller import Controller, file_sha


TASK_PATH = ROOT / 'RULES/TASK/TASK_203_SO45_CODEX_INTERNAL_ACTIVE.md'
R1_TASK_SHA = '3491b85ad4935c7ae64cf940c97e8933186cbe3378f0321349d066cb37384089'
MANIFEST = ROOT / '.ai/ceo/reviews/TASK_203_internal_targets.json'
MANIFEST_SHA = '96936496c5edc481ace634698375d3ae72977f4916844fa2d581ebe1ac82d522'
R1_REPORT = ROOT / 'RULES/REPORT/TASK_203_REPORT_R1'
R1_SEAL_SHA = 'ffbb2a6d39b492aebd72f733235470dc8e4e89ddeb6af64f79d645d04b1d605e'
R1_FINGERPRINT = 'ca1e3a82782b329dc2bf93a516c0a588714927bf640938c8029dcbfb6622f7cb'
R1_REVIEW = ROOT / f'.ai/ceo/reviews/TASK_203-{R1_FINGERPRINT}.md'
R1_ARCHIVE = ROOT / f'.ai/ceo/reviews/TASK_203_R1_TASK_ARCHIVE_{R1_TASK_SHA}.md'
SOURCE_SHA = '3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6'
ORIGINAL_DEADLINE = '2026-10-13T14:30:13.240060+00:00'


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or file_sha(ROOT / 'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt') != STANDARD_SHA:
        raise RuntimeError('END requested or canonical changed')
    if (file_sha(TASK_PATH) != R1_TASK_SHA or file_sha(MANIFEST) != MANIFEST_SHA
            or file_sha(R1_REPORT / 'COMPLETE.json') != R1_SEAL_SHA):
        raise RuntimeError('immutable R1 task/manifest/report changed')
    if any(p.exists() for p in (R1_ARCHIVE, ROOT / 'RULES/REPORT/TASK_203_REPORT_R2')):
        raise RuntimeError('R2 publication already started')
    now = dt.datetime.now(dt.timezone.utc)
    if now >= dt.datetime.fromisoformat(ORIGINAL_DEADLINE):
        raise RuntimeError('original absolute budget deadline exhausted')
    stamp = now.isoformat(timespec='microseconds').replace('+00:00', 'Z')
    report = 'RULES/REPORT/TASK_203_REPORT_R2'
    meta = {
        'schema_version': '2.1.2', 'task_id': 'TASK_203', 'revision': 2,
        'status': 'ACTIVE', 'assignee': '/root/so45_pvg_followon',
        'agent_id': '/root/so45_pvg_followon', 'priority': 'P1',
        'dependencies': [{'task_id': 'TASK_200', 'revision': 1}],
        'mode': 'RESEARCH_CORRECTION', 'report_folder': report,
        'files_allowed': [report + '/**', 'scripts/task_203_codex_correction_r2/**'],
        'files_forbidden': ['RULES/TASK/**', 'RULES/REPORT/TASK_203_REPORT_R1/**',
                            'RESEARCH_WORK/**', 'SOURCE/**', '.ai/**', 'app/**',
                            'apps/**', 'lib-*/**', 'Backend/**', 'services/**', 'packages/**'],
        'max_minutes': 15, 'max_cpu': 1, 'max_heap': '1G',
        'expected_lease_id': 'LEASE-CEO-WORKER-TASK_203-R2',
        'standard_sha256': STANDARD_SHA,
        'source_libraries': {'libPVGColorFunctions.so': {
            'sha256': SOURCE_SHA, 'defined_nonzero_export_vas': 81}},
        'target_manifest_path': MANIFEST.relative_to(ROOT).as_posix(),
        'target_manifest_sha256': MANIFEST_SHA, 'target_candidate_count': 2,
        'correction_of': {'task_revision': 1, 'task_sha256': R1_TASK_SHA,
                          'manifest_sha256': MANIFEST_SHA,
                          'report_folder': 'RULES/REPORT/TASK_203_REPORT_R1',
                          'complete_sha256': R1_SEAL_SHA,
                          'window_evidence_sha256': file_sha(R1_REPORT / 'window_evidence.json'),
                          'ceo_review_fingerprint': R1_FINGERPRINT,
                          'ceo_review_sha256': file_sha(R1_REVIEW),
                          'ceo_replay_summary_sha256': file_sha(ROOT / '.ai/ceo/reviews/TASK_203_CEO_REPLAY/summary.json')},
        'created_at': stamp, 'modified_time': stamp,
        'budget_deadline_utc': ORIGINAL_DEADLINE,
        'authorization_reference': 'Chairman Tony direct Codex SO45 decoding; CEO R1 NEEDS_FIX review',
    }
    body = f'''# TASK_203 R2 - correct whole-FDE C-like evidence labels only

STATUS: ACTIVE
ASSIGNEE: /root/so45_pvg_followon
PRIORITY: P1
MODIFIED_TIME: {stamp}

```json
{json.dumps(meta, ensure_ascii=False, indent=2)}
```

CEO R1 review `{R1_REVIEW.relative_to(ROOT).as_posix()}` found a material semantic error. R1 `window_evidence.json` says `whole_fde_c_like_present: true` for both targets, although the original FDE #505 has a 96-byte Ghidra body gap at `0x3cd44..0x3cda3` and #556 has a 660-byte gap at `0x4e7e8..0x4ea7b`. The two Ghidra function objects have C-like output, but neither output covers its **whole original FDE**; `COMPLETE.json` correctly says `ghidra_exact_fde_c_like_count: 0`. R1 report and raw evidence stay immutable. The exact original target manifest `{MANIFEST.relative_to(ROOT).as_posix()}` SHA-256 `{MANIFEST_SHA}` still selects indices 505 and 556.

Before any write fully reread `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` SHA-256 `{STANDARD_SHA}`, AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, config/state/locks/END, this exact ACTIVE R2 task and manifest. Claim TASK_203 revision 2 as `/root/so45_pvg_followon` via `LEASE-CEO-WORKER-TASK_203-R2`. Original absolute deadline {ORIGINAL_DEADLINE} persists and this correction is capped at 15 minutes from claim. R1 task archive, report, code, private Ghidra project, original SO and CEO replay are read-only. Write only `{report}/**` and `scripts/task_203_codex_correction_r2/**`.

Produce `window_evidence_corrected.json` as a full semantic copy of the immutable R1 window evidence: for both targets set `whole_fde_c_like_present` to **false**, set `whole_fde_c_like_failure` to a nonempty exact body-gap explanation, and add separately named `ghidra_function_c_like_present: true`. All other source/window measurements and gap contexts must compare equal after parsing. Publish a machine-readable R1-to-R2 delta proving only those semantic keys changed. Independently verify each original FDE body gap against R1 raw Ghidra body-membership records. Include `00_AUDIT_INDEX.md` canonical-read receipt and immutable R1 hashes, `01_MASTER_REPORT.md` with explicit PARTIAL limits, `PROGRESS.json`, and SHA-256 sealed `COMPLETE.json` for all R2 report/code files. No Ghidra rerun, R1 alteration, original SO/product/P0 edit, source-code/behavior/parity claim, product Phase PASS, V4/P7, all-45-SO completion, commit or push before CEO independent review.
'''
    task_raw = body.encode('utf8')
    with ctl.transaction() as (registry, state):
        lease = ctl.ceo_lease(registry)
        prior = state['tasks'].get('TASK_203', {}).get('verdict') or {}
        if (prior.get('disposition'), prior.get('revision'), prior.get('fingerprint')) != (
                'NEEDS_FIX', 1, R1_FINGERPRINT):
            raise RuntimeError('exact R1 NEEDS_FIX verdict absent')
        if not ctl.accepted('TASK_200', state, ctl.tasks(), required_revision=1):
            raise RuntimeError('TASK_200 dependency stale')
        if file_sha(TASK_PATH) != R1_TASK_SHA:
            raise RuntimeError('R1 task changed during publication')
        for path in (R1_ARCHIVE, TASK_PATH):
            ctl.authorized(lease, path)
        atomic_file(R1_ARCHIVE, TASK_PATH.read_bytes())
        atomic_file(TASK_PATH, task_raw)
        ctl.event(state, 'CODEX_TASK_CORRECTION_REVISION_PUBLISHED', task_id='TASK_203',
                  revision=2, task_sha256=hashlib.sha256(task_raw).hexdigest(),
                  manifest_sha256=MANIFEST_SHA, prior_task_archive=R1_ARCHIVE.relative_to(ROOT).as_posix(),
                  prior_fingerprint=R1_FINGERPRINT, deadline=ORIGINAL_DEADLINE,
                  scope='R1 whole-FDE C-like true to false; immutable original extraction')
    print(json.dumps({'task_id': 'TASK_203', 'revision': 2,
                      'task_sha256': file_sha(TASK_PATH),
                      'manifest_sha256': file_sha(MANIFEST),
                      'archive_sha256': file_sha(R1_ARCHIVE),
                      'original_deadline': ORIGINAL_DEADLINE}))


if __name__ == '__main__':
    main()
