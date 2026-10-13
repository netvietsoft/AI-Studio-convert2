"""Publish three disjoint Codex-only SO45 nonexport FDE research lanes."""

import copy
import datetime as dt
import hashlib
import json

from prepare_publish_tasks189_190 import ROOT, STANDARD_SHA, atomic_file, prepare
from controller import Controller, file_sha


SPECS = (
    {'task': 'TASK_204', 'library': 'libMTFilterKernel.so',
     'sha': 'f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4',
     'selection': (384, 511), 'totals': (2362, 2873, 511), 'bytes': 43772,
     'expected_excluded': set(), 'expected_selected': (127, 43772, 10943),
     'prior': [(187, 0, 128), (189, 128, 192), (193, 192, 256),
               (197, 256, 320), (201, 320, 384)],
     'prior_corrected_manifest': {201: '.ai/ceo/reviews/TASK_201_R2_internal_targets.json'},
     'expected_prior_excluded': {201, 211, 216, 235, 293, 304, 349, 362},
     'expected_residual': 8, 'assignee': '/root/so45_mtfilter_next',
     'dependency': ('TASK_201', 2),
     'project': 'RESEARCH_WORK/TASK_201_R1/ghidra_project',
     'project_note': 'The accepted TASK_201 R1 project is read-only input; TASK_201 R2 corrects its cumulative census without changing that project.',
     'minutes': 90},
    {'task': 'TASK_205', 'library': 'libPVGImageCodec.so',
     'sha': '7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b',
     'selection': (256, 384), 'totals': (3326, 9981, 6655), 'bytes': 39976,
     'expected_excluded': {348, 369}, 'expected_selected': (126, 24984, 6246),
     'prior': [(192, 0, 64), (195, 64, 128), (199, 128, 192), (202, 192, 256)],
     'prior_corrected_manifest': {},
     'expected_prior_excluded': {158, 168, 174, 191, 199, 202},
     'expected_residual': 6279, 'assignee': '/root/so45_imagecodec_internal',
     'dependency': ('TASK_202', 1),
     'project': 'RESEARCH_WORK/TASK_202_R1/ghidra_project',
     'project_note': 'The accepted TASK_202 R1 project is read-only input; candidate 193 there lacks C-like output despite source/p-code records.',
     'minutes': 90},
    {'task': 'TASK_206', 'library': 'libLayerFlow.so',
     'sha': 'ef8d1581038778b72abca3ca8fd5046e49fd44e0465871b023647fe42a582262',
     'selection': (0, 128), 'totals': (5082, 8935, 3853), 'bytes': 9060,
     'expected_excluded': set(), 'expected_selected': (128, 9060, 2265),
     'prior': [], 'prior_corrected_manifest': {}, 'expected_prior_excluded': set(),
     'expected_residual': 3725, 'assignee': '/root/so45_pvg_followon',
     'dependency': None,
     'project': 'RESEARCH_WORK/TASK_146_R1/ghidra_project',
     'project_note': 'TASK_146 project is an UNREVIEWED technical cache only, never accepted evidence. Rehash all files and verify source/program identity before a private copy; if uncertain, use a fresh bounded headless import. No conclusion may rely on TASK_146 claims.',
     'minutes': 90},
)


def previous_selection(spec):
    selected = set()
    excluded = set()
    for task_num, begin, end in spec['prior']:
        relative = spec['prior_corrected_manifest'].get(
            task_num, f'.ai/ceo/reviews/TASK_{task_num}_internal_targets.json')
        manifest = json.loads((ROOT / relative).read_text(encoding='utf8'))
        if manifest['source_library'] != spec['library'] or manifest['source_sha256'] != spec['sha']:
            raise RuntimeError(f'prior source mismatch: TASK_{task_num}')
        missing = set(manifest.get('excluded_oversized_global_indices', []))
        indices = [i for i in range(begin, end) if i not in missing]
        if len(indices) != manifest['selected_count'] or len(indices) != len(manifest['targets']):
            raise RuntimeError(f'prior selection count mismatch: TASK_{task_num}')
        for index, row in zip(indices, manifest['targets']):
            if row.get('global_nonexport_fde_index', index) != index:
                raise RuntimeError(f'prior selection order mismatch: TASK_{task_num}')
        if selected.intersection(indices) or excluded.intersection(indices):
            raise RuntimeError(f'prior selection overlaps: TASK_{task_num}')
        selected.update(indices)
        excluded.update(missing)
    if excluded != spec['expected_prior_excluded']:
        raise RuntimeError(f'prior exclusion census changed: {spec["task"]}: {excluded}')
    return selected, excluded


def prepare_one(spec, now):
    # Existing preparation performs full original-SO SHA, ELF/FDE/dynsym/PT_LOAD
    # mapping and source-body hash checks. Its provisional task text is discarded.
    input_spec = {**spec,
                  'dependency': spec['dependency'] or ('TASK_203', 2)}
    manifest_path, manifest_raw, task_path, _, originals, deadline = prepare(input_spec, now)
    begin, end = spec['selection']
    oversized = {begin+i for i, row in enumerate(originals) if row['size_bytes'] > 4096}
    if oversized != spec['expected_excluded']:
        raise RuntimeError(f'oversized census changed: {spec["task"]}: {oversized}')
    rows = [{'global_nonexport_fde_index': index, **row}
            for index, row in enumerate(originals, begin) if index not in oversized]
    selected_tuple = (len(rows), sum(x['size_bytes'] for x in rows),
                      sum(x['instruction_slots'] for x in rows))
    if selected_tuple != spec['expected_selected']:
        raise RuntimeError(f'selected slice census changed: {spec["task"]}: {selected_tuple}')
    previous, excluded = previous_selection(spec)
    new_ids = {row['global_nonexport_fde_index'] for row in rows}
    if previous.intersection(new_ids) or len(new_ids) != len(rows):
        raise RuntimeError('new target overlaps prior selection')
    union = previous | new_ids
    remainder = set(range(spec['totals'][2])) - union
    tail = set(range(end, spec['totals'][2]))
    all_excluded = excluded | oversized
    if remainder != tail | all_excluded or len(remainder) != spec['expected_residual']:
        raise RuntimeError(f'cumulative residual census changed: {spec["task"]}')
    manifest = json.loads(manifest_raw)
    manifest['targets'] = rows
    manifest['selected_count'] = len(rows)
    manifest['selection'] = f'sorted nonexport FDE global zero-based indices {begin}..{end-1}, excluding {sorted(oversized)}'
    manifest['excluded_oversized_global_indices'] = sorted(oversized)
    manifest['excluded_oversized_bytes'] = sum(originals[i-begin]['size_bytes'] for i in oversized)
    manifest['cumulative_selected_distinct_candidates'] = len(union)
    manifest['remaining_nonselected_candidates_after_slice'] = len(remainder)
    manifest['remaining_unselected_breakdown'] = {
        'tail_global_indices_inclusive': [end, spec['totals'][2]-1] if tail else [],
        'tail_count': len(tail), 'previous_and_current_excluded_indices': sorted(all_excluded),
        'excluded_count': len(all_excluded)}
    manifest_raw = (json.dumps(manifest, ensure_ascii=False, indent=2) + '\n').encode('utf8')
    manifest_sha = hashlib.sha256(manifest_raw).hexdigest()
    task = spec['task']
    report = f'RULES/REPORT/{task}_REPORT_R1'
    stamp = now.isoformat(timespec='microseconds').replace('+00:00', 'Z')
    dependencies = ([{'task_id': spec['dependency'][0], 'revision': spec['dependency'][1]}]
                    if spec['dependency'] else [])
    meta = {'schema_version': '2.1.2', 'task_id': task, 'revision': 1,
            'status': 'ACTIVE', 'assignee': spec['assignee'], 'agent_id': spec['assignee'],
            'priority': 'P1', 'dependencies': dependencies, 'mode': 'RESEARCH',
            'report_folder': report,
            'files_allowed': [f'{report}/**', f'scripts/{task.lower()}_codex_internal/**',
                              f'RESEARCH_WORK/{task}_R1/**'],
            'files_forbidden': ['RULES/TASK/**', 'SOURCE/**', '.ai/**', 'app/**', 'apps/**',
                                'lib-*/**', 'Backend/**', 'services/**', 'packages/**'],
            'max_minutes': spec['minutes'], 'max_cpu': 1, 'max_heap': '1G',
            'max_report_bytes': 134217728,
            'expected_lease_id': f'LEASE-CEO-WORKER-{task}-R1',
            'standard_sha256': STANDARD_SHA,
            'source_libraries': {spec['library']: {'sha256': spec['sha'],
                                                   'defined_nonzero_export_vas': spec['totals'][0]}},
            'target_manifest_path': manifest_path.relative_to(ROOT).as_posix(),
            'target_manifest_sha256': manifest_sha, 'target_candidate_count': len(rows),
            'authorization_reference': 'Chairman Tony direct Codex multi-lane remaining SO45 decoding without AGY',
            'created_at': stamp, 'modified_time': stamp, 'budget_deadline_utc': deadline}
    excluded_note = (f'Indices {sorted(oversized)} exceed 4,096 bytes and remain separate PARTIAL/UNANALYZED targets. '
                     if oversized else 'No index in this slice exceeds 4,096 bytes. ')
    dep_note = (f'Accepted {spec["dependency"][0]} R{spec["dependency"][1]} is the earlier disjoint research gate. '
                if spec['dependency'] else 'This is a new nonexport FDE lane on a different SO; no prior research gate is inferred. ')
    body = f'''# {task} R1 - bounded {spec['library']} nonexport FDE research

STATUS: ACTIVE
ASSIGNEE: {spec['assignee']}
PRIORITY: P1
MODIFIED_TIME: {stamp}

```json
{json.dumps(meta, ensure_ascii=False, indent=2)}
```

Process only the {len(rows)} exact zero-based nonexport FDE candidate indices in `{meta['target_manifest_path']}` SHA-256 `{manifest_sha}` from original `{spec['library']}` SHA-256 `{spec['sha']}`. Slice {begin}..{end-1} contains {selected_tuple[1]:,} selected original bytes / {selected_tuple[2]:,} AArch64 instruction slots. {excluded_note}{dep_note}{spec['project_note']} Prior exclusions remain open. The cumulative selection is {len(union)} of {spec['totals'][2]} candidate starts, with {len(remainder)} unselected ({len(tail)} later indices plus {len(all_excluded)} exclusions). This is a candidate-range census, not a count of recovered complete functions.

Use direct pyelftools/Capstone extraction for source mapping, all original bytes/instructions, branch sites and >=10% spread provenance. Use a bounded private Ghidra **headless** project with a persistent decompiler interface per Program where practical, not a GUI or bulk all-SO decompile. Rehash the `{spec['project']}` technical input before a private copy; for TASK_206 it is unreviewed and a fresh bounded import is required if identity cannot be proven. Capture exact function-body membership, gaps/extra ranges, listing and p-code, C-like text/hash or failure, raw command/stdout/stderr and before/after project hashes. A C-like result or FDE start alone is not complete source/behavior. Mark ambiguous boundaries PARTIAL; transient correction only for proven nonoverlapping gaps, followed by fresh-session rollback and original memory proof. One CPU, 1 GiB heap, sequential <=20-minute headless jobs, <=10 seconds per decompile and the original deadline; seal truthful partial results if a row cannot be resolved. Do not claim all 45 SOs, functional/pixel parity, product Phase PASS, V4/P7 or a 3-minute daemon.

Before any write fully reread `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` SHA-256 `{STANDARD_SHA}`, AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task/manifest, config/state/locks/END and git status. Claim exact ACTIVE {task} R1 as `{spec['assignee']}` via `LEASE-CEO-WORKER-{task}-R1` before any write. Write only `{report}/**`, `scripts/{task.lower()}_codex_internal/**`, `RESEARCH_WORK/{task}_R1/**`; source SO, other research, P0 and product are read-only. Create `00_AUDIT_INDEX.md` canonical-read receipt, truthful `01_MASTER_REPORT.md`, raw per-candidate evidence, `PROGRESS.json`, and SHA-256 sealed `COMPLETE.json`. No AGY, further subagents, self-review, commit or push before CEO independent review. Stop by {deadline}.
'''
    return manifest_path, manifest_raw, task_path, body.encode('utf8'), rows, deadline


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or file_sha(ROOT / 'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt') != STANDARD_SHA:
        raise RuntimeError('END requested or canonical changed')
    now = dt.datetime.now(dt.timezone.utc)
    prepared = [(spec, *prepare_one(spec, now)) for spec in SPECS]
    with ctl.transaction() as (registry, state):
        lease = ctl.ceo_lease(registry)
        tasks = ctl.tasks()
        for spec, manifest_path, _, task_path, _, _, _ in prepared:
            if spec['dependency'] and not ctl.accepted(spec['dependency'][0], state, tasks,
                                                        required_revision=spec['dependency'][1]):
                raise RuntimeError('dependency not accepted: ' + spec['dependency'][0])
            if manifest_path.exists() or task_path.exists():
                raise RuntimeError('task already prepared: ' + spec['task'])
            ctl.authorized(lease, manifest_path)
        updated = copy.deepcopy(registry)
        active = ctl.ceo_lease(updated)
        for spec, *_ in prepared:
            scope = f"RULES/TASK/{spec['task']}*"
            if scope not in active['files_allowed']:
                active['files_allowed'].append(scope)
                active.setdefault('scope_authorization_history', []).append({
                    'at': now.isoformat(), 'scope': scope,
                    'authorization': 'Chairman Tony direct Codex multi-lane remaining SO45 decoding, no AGY',
                    'limits': 'Bounded static research; P0/product/V4/P7 frozen'})
        updated['revision'] = registry['revision'] + 1
        updated['updated_at'] = now.isoformat()
        ctl.replace_json(ctl.registry, updated, registry)
        registry.clear()
        registry.update(updated)
        for spec, manifest_path, manifest_raw, task_path, task_raw, _, _ in prepared:
            ctl.authorized(ctl.ceo_lease(registry), task_path)
            atomic_file(manifest_path, manifest_raw)
            atomic_file(task_path, task_raw)
        config_path = ROOT / '.ai/ceo/config.json'
        config_sha = file_sha(config_path)
        config = ctl.read_json(config_path)
        for spec, *_ in prepared:
            if spec['task'] in config['task_ids']:
                raise RuntimeError('task already configured: ' + spec['task'])
            config['task_ids'].append(spec['task'])
        ctl.replace_json(config_path, config, registry, config_sha)
        for spec, _, manifest_raw, _, task_raw, rows, deadline in prepared:
            ctl.event(state, 'CODEX_INTERNAL_FDE_TASK_PUBLISHED', task_id=spec['task'],
                      assignee=spec['assignee'], source=spec['library'],
                      target_count=len(rows), manifest_sha256=hashlib.sha256(manifest_raw).hexdigest(),
                      task_sha256=hashlib.sha256(task_raw).hexdigest(), deadline=deadline,
                      excluded_oversized_global_indices=sorted(spec['expected_excluded']))
    print(json.dumps([{'task_id': spec['task'], 'assignee': spec['assignee'],
                       'target_count': len(rows), 'instruction_slots': sum(r['instruction_slots'] for r in rows),
                       'task_sha256': file_sha(task_path), 'manifest_sha256': file_sha(manifest_path),
                       'deadline': deadline} for spec, manifest_path, _, task_path, _, rows, deadline in prepared]))


if __name__ == '__main__':
    main()
