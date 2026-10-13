"""Publish two exact disjoint Codex-only nonexport FDE slices."""

import copy
import datetime as dt
import hashlib
import json

from prepare_publish_tasks197_198 import prepare_one
from prepare_publish_tasks189_190 import ROOT, STANDARD_SHA, atomic_file
from controller import Controller, file_sha


SPECS = (
    {'task': 'TASK_201', 'library': 'libMTFilterKernel.so',
     'sha': 'f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4',
     'selection': (320, 384), 'totals': (2362, 2873, 511), 'bytes': 49232,
     'expected_excluded': {349, 362}, 'expected_selected': (62, 37868, 9467),
     'assignee': '/root/so45_mtfilter_next', 'dependency': ('TASK_197', 1),
     'project': 'RESEARCH_WORK/TASK_197_R1/ghidra_project', 'minutes': 90,
     'prior_note': 'TASK_197 left indices 293 and 304 unanalyzed and six boundary-assumption rows; these remain open. '},
    {'task': 'TASK_202', 'library': 'libPVGImageCodec.so',
     'sha': '7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b',
     'selection': (192, 256), 'totals': (3326, 9981, 6655), 'bytes': 50736,
     'expected_excluded': {199, 202}, 'expected_selected': (62, 38788, 9697),
     'assignee': '/root/so45_imagecodec_internal', 'dependency': ('TASK_199', 1),
     'project': 'RESEARCH_WORK/TASK_199_R1/ghidra_project', 'minutes': 90,
     'prior_note': 'TASK_199 left indices 158, 168, 174 and 191 unanalyzed and six boundary-assumption rows; these remain open. '},
)
OLD_NOTE = 'TASK_196 left index 556 unanalysed and five boundary-PARTIAL rows; these remain open. '


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or file_sha(ROOT / 'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt') != STANDARD_SHA:
        raise RuntimeError('END requested or canonical changed')
    now = dt.datetime.now(dt.timezone.utc)
    prepared = []
    for spec in SPECS:
        manifest_path, manifest_raw, task_path, task_raw, rows, deadline = prepare_one(spec, now)
        body = task_raw.decode('utf8')
        if body.count(OLD_NOTE) != 1:
            raise RuntimeError('unexpected inherited prior-note template')
        task_raw = body.replace(OLD_NOTE, spec['prior_note']).encode('utf8')
        prepared.append((spec, manifest_path, manifest_raw, task_path, task_raw, rows, deadline))
    with ctl.transaction() as (registry, state):
        lease = ctl.ceo_lease(registry)
        tasks = ctl.tasks()
        for spec, manifest_path, _, task_path, _, _, _ in prepared:
            dependency, revision = spec['dependency']
            if not ctl.accepted(dependency, state, tasks, required_revision=revision):
                raise RuntimeError('dependency not accepted: ' + dependency)
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
                    'limits': 'Bounded static research; oversized excluded; P0/product/V4/P7 frozen'})
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
