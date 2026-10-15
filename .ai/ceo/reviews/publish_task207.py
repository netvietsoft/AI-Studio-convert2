"""Publish the next disjoint, bounded LayerFlow nonexport-FDE slice."""

import copy
import datetime as dt
import hashlib
import json

from prepare_publish_tasks189_190 import ROOT, STANDARD_SHA, atomic_file
from prepare_publish_tasks204_206 import prepare_one
from controller import Controller, file_sha


SPEC = {
    'task': 'TASK_207', 'library': 'libLayerFlow.so',
    'sha': 'ef8d1581038778b72abca3ca8fd5046e49fd44e0465871b023647fe42a582262',
    'selection': (128, 256), 'totals': (5082, 8935, 3853), 'bytes': 14620,
    'expected_excluded': set(), 'expected_selected': (128, 14620, 3655),
    'prior': [(206, 0, 128)], 'prior_corrected_manifest': {},
    'expected_prior_excluded': set(), 'expected_residual': 3597,
    'assignee': '/root/so45_pvg_followon', 'dependency': ('TASK_206', 1),
    'project': 'RESEARCH_WORK/TASK_146_R1/ghidra_project',
    'project_note': 'The original TASK_146 project is an UNREVIEWED technical cache, although TASK_206 bounded identity and 17-row independent replay succeeded. Verify all original project hashes and full source/program identity again before copying it; do not adopt TASK_146 semantic conclusions. The exact original cache is archived in .ai/ceo/reviews/TASK_206_GHIDRA_TECHNICAL_CACHE.zip. The private TASK_206 project had transient metadata drift and is not the input.',
    'minutes': 90,
}


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or file_sha(ROOT / 'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt') != STANDARD_SHA:
        raise RuntimeError('END requested or canonical changed')
    now = dt.datetime.now(dt.timezone.utc)
    manifest_path, manifest_raw, task_path, task_raw, rows, deadline = prepare_one(SPEC, now)
    with ctl.transaction() as (registry, state):
        lease = ctl.ceo_lease(registry)
        tasks = ctl.tasks()
        if not ctl.accepted('TASK_206', state, tasks, required_revision=1):
            raise RuntimeError('TASK_206 current fingerprint not accepted')
        if manifest_path.exists() or task_path.exists():
            raise RuntimeError('TASK_207 already prepared')
        ctl.authorized(lease, manifest_path)
        updated = copy.deepcopy(registry)
        active = ctl.ceo_lease(updated)
        scope = 'RULES/TASK/TASK_207*'
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
        ctl.authorized(ctl.ceo_lease(registry), task_path)
        atomic_file(manifest_path, manifest_raw)
        atomic_file(task_path, task_raw)
        config_path = ROOT / '.ai/ceo/config.json'
        config_sha = file_sha(config_path)
        config = ctl.read_json(config_path)
        if 'TASK_207' in config['task_ids']:
            raise RuntimeError('TASK_207 already configured')
        config['task_ids'].append('TASK_207')
        ctl.replace_json(config_path, config, registry, config_sha)
        ctl.event(state, 'CODEX_INTERNAL_FDE_TASK_PUBLISHED', task_id='TASK_207',
                  assignee=SPEC['assignee'], source=SPEC['library'],
                  target_count=len(rows), manifest_sha256=hashlib.sha256(manifest_raw).hexdigest(),
                  task_sha256=hashlib.sha256(task_raw).hexdigest(), deadline=deadline,
                  excluded_oversized_global_indices=[])
    print(json.dumps({'task_id': 'TASK_207', 'assignee': SPEC['assignee'],
                      'target_count': len(rows), 'source_bytes': sum(r['size_bytes'] for r in rows),
                      'task_sha256': file_sha(task_path),
                      'manifest_sha256': file_sha(manifest_path), 'deadline': deadline}))


if __name__ == '__main__':
    main()
