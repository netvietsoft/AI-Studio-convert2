"""Recover the TASK_203 publication receipt after a late NameError.

The task, manifest, registry scope, and config were atomically written before the
error.  Reconstruct their exact bytes from their recorded timestamp and only
then append the missing controller event under its transaction guard.
"""

import datetime as dt
import hashlib
import json
import re

from prepare_publish_task203 import ROOT, TASK, build
from controller import Controller, file_sha


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested():
        raise RuntimeError('END requested')
    task_path = ROOT / 'RULES/TASK/TASK_203_SO45_CODEX_INTERNAL_ACTIVE.md'
    existing = task_path.read_text(encoding='utf8')
    match = re.search(r'^```json\s*\n(.*?)\n```', existing, re.S | re.M)
    if not match:
        raise RuntimeError('missing task metadata')
    meta = json.loads(match.group(1))
    if meta['task_id'] != TASK or meta['status'] != 'ACTIVE' or meta['revision'] != 1:
        raise RuntimeError('task is not the exact ACTIVE revision')
    now = dt.datetime.fromisoformat(meta['created_at'].replace('Z', '+00:00'))
    manifest_path, manifest_raw, rebuilt_task, task_raw, rows, deadline = build(now)
    if rebuilt_task != task_path or task_raw != task_path.read_bytes() or manifest_raw != manifest_path.read_bytes():
        raise RuntimeError('published bytes differ from independently rebuilt source census')
    manifest_sha = hashlib.sha256(manifest_raw).hexdigest()
    task_sha = hashlib.sha256(task_raw).hexdigest()
    if meta['target_manifest_sha256'] != manifest_sha or meta['budget_deadline_utc'] != deadline:
        raise RuntimeError('task/manifest metadata mismatch')
    if TASK not in ctl.read_json(ROOT / '.ai/ceo/config.json')['task_ids']:
        raise RuntimeError('task is absent from config')
    with ctl.transaction() as (registry, state):
        lease = ctl.ceo_lease(registry)
        ctl.authorized(lease, task_path)
        ctl.authorized(lease, manifest_path)
        if not ctl.accepted('TASK_200', state, ctl.tasks(), required_revision=1):
            raise RuntimeError('dependency changed')
        event = ctl.event(state, 'CODEX_OVERSIZED_FDE_TASK_PUBLISHED', task_id=TASK,
                          assignee=meta['assignee'], source='libPVGColorFunctions.so',
                          target_count=2, manifest_sha256=manifest_sha,
                          task_sha256=task_sha, deadline=deadline)
    print(json.dumps({'task_id': TASK, 'task_sha256': file_sha(task_path),
                      'manifest_sha256': file_sha(manifest_path),
                      'target_count': len(rows), 'event_added': event is not None,
                      'deadline': deadline}))


if __name__ == '__main__':
    main()
