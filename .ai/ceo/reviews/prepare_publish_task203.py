"""Publish a bounded Codex-only diagnosis for two oversized PVG FDE candidates."""

import copy
import datetime as dt
import hashlib
import json

from prepare_publish_tasks189_190 import ROOT, STANDARD_SHA, atomic_file, prepare
from controller import Controller, file_sha


TASK = 'TASK_203'
LIBRARY = 'libPVGColorFunctions.so'
SOURCE_SHA = '3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6'
ASSIGNEE = '/root/so45_pvg_followon'
SELECTIONS = ((505, 4500), (556, 7068))


def build(now):
    rows = []
    template = None
    for index, size in SELECTIONS:
        spec = {'task': TASK, 'library': LIBRARY, 'sha': SOURCE_SHA,
                'selection': (index, index + 1), 'totals': (81, 753, 672),
                'bytes': size, 'assignee': ASSIGNEE, 'dependency': ('TASK_200', 1),
                'project': 'RESEARCH_WORK/TASK_200_R1/ghidra_project', 'minutes': 90}
        manifest_path, raw, task_path, _, selected, deadline = prepare(spec, now)
        if len(selected) != 1:
            raise RuntimeError('wrong oversized candidate count')
        row = {'global_nonexport_fde_index': index, **selected[0]}
        rows.append(row)
        if template is None:
            template = json.loads(raw)
    if rows[0]['size_bytes'] != 4500 or rows[1]['size_bytes'] != 7068:
        raise RuntimeError('oversized FDE sizes changed')
    template['selection'] = 'exact global zero-based nonexport FDE indices [505, 556] only'
    template['selected_count'] = 2
    template.pop('remaining_nonselected_candidates_after_slice', None)
    template['selected_total_bytes'] = 11568
    template['selected_instruction_slots'] = 2892
    template['targets'] = rows
    template['scope_limit'] = 'Oversized unwind FDE candidates; diagnose blocks and boundaries without claiming full source function or behavior'
    manifest_raw = (json.dumps(template, ensure_ascii=False, indent=2) + '\n').encode('utf8')
    manifest_sha = hashlib.sha256(manifest_raw).hexdigest()
    stamp = now.isoformat(timespec='microseconds').replace('+00:00', 'Z')
    report = f'RULES/REPORT/{TASK}_REPORT_R1'
    meta = {'schema_version': '2.1.2', 'task_id': TASK, 'revision': 1,
            'status': 'ACTIVE', 'assignee': ASSIGNEE, 'agent_id': ASSIGNEE,
            'priority': 'P1', 'dependencies': [{'task_id': 'TASK_200', 'revision': 1}],
            'mode': 'RESEARCH', 'report_folder': report,
            'files_allowed': [f'{report}/**', 'scripts/task_203_codex_internal/**', 'RESEARCH_WORK/TASK_203_R1/**'],
            'files_forbidden': ['RULES/TASK/**', 'SOURCE/**', '.ai/**', 'app/**', 'apps/**',
                                'lib-*/**', 'Backend/**', 'services/**', 'packages/**'],
            'max_minutes': 90, 'max_cpu': 1, 'max_heap': '1G', 'max_report_bytes': 134217728,
            'expected_lease_id': 'LEASE-CEO-WORKER-TASK_203-R1',
            'standard_sha256': STANDARD_SHA,
            'source_libraries': {LIBRARY: {'sha256': SOURCE_SHA, 'defined_nonzero_export_vas': 81}},
            'target_manifest_path': manifest_path.relative_to(ROOT).as_posix(),
            'target_manifest_sha256': manifest_sha, 'target_candidate_count': 2,
            'authorization_reference': 'Chairman Tony directs direct SO45 decoding with real Codex subagents, without AGY',
            'created_at': stamp, 'modified_time': stamp, 'budget_deadline_utc': deadline}
    body = f'''# TASK_203 R1 - targeted oversized PVGColorFunctions FDE diagnosis

STATUS: ACTIVE
ASSIGNEE: {ASSIGNEE}
PRIORITY: P1
MODIFIED_TIME: {stamp}

```json
{json.dumps(meta, ensure_ascii=False, indent=2)}
```

Analyze only the two exact zero-based nonexport FDE candidates #505 (4,500 bytes) and #556 (7,068 bytes) in `{meta['target_manifest_path']}` SHA-256 `{manifest_sha}`. The original `{LIBRARY}` SHA-256 is `{SOURCE_SHA}`; selected bodies total 11,568 bytes / 2,892 AArch64 positions. Both were excluded from earlier ordinary <=4,096-byte slices. Accepted TASK_200 R1 is a disjoint dependency; its sealed nine-file project `RESEARCH_WORK/TASK_200_R1/ghidra_project` is read-only input. Rehash all nine files before a private copy. Prior small boundary-PARTIAL indices 506, 550, 553, 554, 557, 558, 620 and 625 remain separate and must not be counted here.

This is a targeted method for oversized FDE ranges, not an instruction to claim two complete functions. Independently reparse original ELF/FDE/dynsym/PT_LOAD, pin every original body byte and source instruction, call sites, branch/basic-block boundaries and any embedded literal/data risks. On a private Ghidra project copy, run bounded read-only/no-analysis headless extraction, record exact byte-level function-body membership, listing/p-code and C-like output or failure. If whole-range decompilation fails or exceeds the limit, extract bounded basic-block or address-window evidence with continuity/gap accounting. A transient metadata correction is allowed only when nonoverlap and rollback safety are proven, followed by a fresh-session check of original metadata and memory. Classify unknown boundaries or code/data ambiguities PARTIAL; do not invent source code or assert functional parity. Preserve raw output and command/log receipts, independent all-critical checks and >=10% spread ordinary source-position sample. Use one CPU, 1 GiB heap, sequential <=20-minute processes, <=10 seconds per whole decompile and the original 90-minute deadline. Seal a truthful bounded COMPLETE even if unresolved.

Before any write fully read `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` and verify SHA-256 `{STANDARD_SHA}`. Also read AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task/manifest, config/state/locks/END and git status. Claim exact ACTIVE TASK_203 R1 as `{ASSIGNEE}` using `LEASE-CEO-WORKER-TASK_203-R1` before writes. Write only `{report}/**`, `scripts/task_203_codex_internal/**`, `RESEARCH_WORK/TASK_203_R1/**`; original SO, prior research, other lanes and P0 are read-only. Create canonical-read receipt `00_AUDIT_INDEX.md`, truthful `01_MASTER_REPORT.md`, raw evidence, PROGRESS.json and SHA-256 sealed COMPLETE.json. No AGY, other subagent, self-review, commit or push before CEO independent review. No product Phase PASS, V4/P7 or all-45-SO completion inference. Stop by {deadline}.
'''
    return manifest_path, manifest_raw, task_path, body.encode('utf8'), rows, deadline


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or file_sha(ROOT / 'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt') != STANDARD_SHA:
        raise RuntimeError('END requested or canonical changed')
    now = dt.datetime.now(dt.timezone.utc)
    manifest_path, manifest_raw, task_path, task_raw, rows, deadline = build(now)
    manifest_sha = hashlib.sha256(manifest_raw).hexdigest()
    with ctl.transaction() as (registry, state):
        lease = ctl.ceo_lease(registry)
        if not ctl.accepted('TASK_200', state, ctl.tasks(), required_revision=1):
            raise RuntimeError('TASK_200 not accepted')
        if manifest_path.exists() or task_path.exists():
            raise RuntimeError('TASK_203 already prepared')
        ctl.authorized(lease, manifest_path)
        updated = copy.deepcopy(registry)
        active = ctl.ceo_lease(updated)
        scope = 'RULES/TASK/TASK_203*'
        if scope not in active['files_allowed']:
            active['files_allowed'].append(scope)
            active.setdefault('scope_authorization_history', []).append({
                'at': now.isoformat(), 'scope': scope,
                'authorization': 'Chairman Tony direct Codex multi-lane remaining SO45 decoding, no AGY',
                'limits': 'Two oversized static-research targets; P0/product/V4/P7 frozen'})
        updated['revision'] = registry['revision'] + 1
        updated['updated_at'] = now.isoformat()
        ctl.replace_json(ctl.registry, updated, registry)
        registry.clear()
        registry.update(updated)
        ctl.authorized(ctl.ceo_lease(registry), task_path)
        atomic_file(manifest_path, manifest_raw)
        atomic_file(task_path, task_raw)
        config_path = ROOT / '.ai/ceo/config.json'
        config_sha = file_sha(config_path)
        config = ctl.read_json(config_path)
        if TASK in config['task_ids']:
            raise RuntimeError('TASK_203 already configured')
        config['task_ids'].append(TASK)
        ctl.replace_json(config_path, config, registry, config_sha)
        ctl.event(state, 'CODEX_OVERSIZED_FDE_TASK_PUBLISHED', task_id=TASK,
                  assignee=ASSIGNEE, source=LIBRARY, target_count=2,
                  manifest_sha256=manifest_sha, task_sha256=hashlib.sha256(task_raw).hexdigest(),
                  deadline=deadline)
    print(json.dumps({'task_id': TASK, 'assignee': ASSIGNEE,
                      'target_count': len(rows), 'instruction_slots': sum(r['instruction_slots'] for r in rows),
                      'task_sha256': file_sha(task_path), 'manifest_sha256': file_sha(manifest_path),
                      'deadline': deadline}))


if __name__ == '__main__':
    main()
