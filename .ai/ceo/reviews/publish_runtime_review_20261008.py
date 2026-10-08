"""Publish only reviewed CEO tooling and diagnostics on the owned branch."""
from pathlib import Path
import hashlib
import json
import os
import shutil
import subprocess
import sys
import uuid

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / '.ai/ceo'))
from controller import Controller, digest, file_sha, iso

C = Controller(ROOT)
WT = Path('F:/CONVERT_WORKTREES/ceo-so45-20261008')
BRANCH = 'ceo/so45-v4-orchestration-20261008'
RELS = {
    '.ai/ceo/controller.py', '.ai/ceo/config.json', '.ai/ceo/SO45_TO_V4_PLAN.md',
    '.ai/ceo/reviews/CEO_CONTROLLER_BUDGET_GUARD_28073ff3_APPROVED.md',
    '.ai/ceo/reviews/independent_budget_full_api_harness_20261008.py',
    '.ai/ceo/reviews/TASK071_retire_actual_source_fixture.cjs',
    '.ai/ceo/reviews/TASK071_3685f2e8_42bfe949_INDEPENDENT_APPROVED.md',
    '.ai/ceo/reviews/TASK_070_eaa0fb44_VERIFICATION.json',
    '.ai/ceo/reviews/publish_runtime_review_20261008.py',
    '.ai/ceo/receipts/CEO_HEARTBEAT_5MIN_20261008.json',
    '.ai/ceo/receipts/TASK_070_DISPATCH.json',
    '.ai/ceo/receipts/TASK_071_ASSIGNMENT.json',
    '.ai/ceo/receipts/TASK_071_PATCH_RECEIPT.json',
    '.ai/ceo/receipts/TASK_071_SOURCE_GATE_AND_BUDGET.json',
}

for task in ('TASK_069', 'TASK_070', 'TASK_071'):
    meta = C.tasks()[task]
    RELS.add(Path(meta['_path']).as_posix())
    if task == 'TASK_069':
        continue
    folder = ROOT / meta['report_folder']
    manifest = C.read_json(folder / 'COMPLETE.json')
    for rel, sha in manifest['files'].items():
        assert file_sha(folder / rel) == sha, rel
        RELS.add((folder / rel).relative_to(ROOT).as_posix())
    RELS.add((folder / 'COMPLETE.json').relative_to(ROOT).as_posix())
    for rel, sha in manifest.get('code_sha256', {}).items():
        assert file_sha(ROOT / rel) == sha, rel
    RELS.update(manifest['code_files'])
    verdict = C.read_json(C.state_path)['tasks'][task]['verdict']
    assert verdict['disposition'] == 'ACCEPTED'
    RELS.add(verdict['review_file'])

for pattern in ('TASK_069*BUDGET*', 'TASK_069*EXHAUST*', 'TASK_069*DEADLINE*',
                'PASEO_DAEMON_RESTART_INDEPENDENT_AUDIT_20261008.json'):
    RELS.update(p.relative_to(ROOT).as_posix()
                for p in (ROOT / '.ai/ceo/receipts').glob(pattern) if p.is_file())

with C.transaction() as (registry, state):
    lease = C.ceo_lease(registry)
    C.authorized(lease, WT / 'publication-scope')
    plan = ROOT / '.ai/ceo/SO45_TO_V4_PLAN.md'
    marker = b'## Reviewed source and runtime deployment checkpoint 2026-10-08'
    current = plan.read_bytes()
    if marker not in current:
        note = ('\n\n' + marker.decode() + '\n'
                'TASK070 independently ACCEPTED at diagnostic gate, fingerprint eaa0fb44...; '
                'historical abort initiator remains UNKNOWN. TASK071 independently ACCEPTED '
                'at source/testing gate, fingerprint b233cd37...; actual global source writes, '
                'tests and independent review preceded original host deadline. Administrative '
                'manifest packaging under orchestration lease1007 finished12.338251 seconds '
                'after host deadline; no host retry/budget extension. Host lease1020 closed. '
                'Live activation remains pending: supported supervisor stop/start closes all '
                'agents and terminals, so wait for checkpointed actual idle maintenance. '
                'Owned worker32548 window hidden without termination at08:57:44Z; permanent '
                'hidden launch and real cleanup recovery remain unverified. Existing CEO '
                'heartbeat9ed2909e remains5minutes, no duplicate. 063/069 remain blocked; '
                '064/065/066 and V4 remain gated.\n')
        C.authorized(lease, plan)
        temp = ROOT / '.ai' / ('locks.ceo.' + uuid.uuid4().hex + '.tmp')
        C.authorized(lease, temp)
        with temp.open('xb') as stream:
            stream.write(current + note.encode())
            stream.flush()
            os.fsync(stream.fileno())
        assert digest(C.read_json(C.registry)) == digest(registry)
        os.replace(temp, plan)
    hashes = {rel: file_sha(ROOT / rel) for rel in sorted(RELS)}
    assert hashes['.ai/ceo/controller.py'] == '28073ff339e7c5e57366ff5281a713d8f7039d1f1d3dbb314cc74b7ec499c699'
    assert C.tasks()['TASK_069']['status'] == 'BLOCKED'
    nonces = []
    for task in ('TASK_067', 'TASK_069', 'TASK_070'):
        for p in (ROOT / '.ai/ceo/receipts').glob(task + '*PRIVATE.json'):
            nonce = json.loads(p.read_text(encoding='utf-8-sig')).get('dispatch_token')
            if nonce:
                nonces.append(nonce.encode())
    for rel in hashes:
        assert hashes[rel] and 'PRIVATE' not in rel and (ROOT / rel).is_file(), rel
        assert not any(nonce in (ROOT / rel).read_bytes() for nonce in nonces), 'Private token leak'

ENV = dict(os.environ, GIT_TERMINAL_PROMPT='0')

def git(*args, timeout=55, input_bytes=None):
    result = subprocess.run(['git', '-C', str(WT), *args], capture_output=True,
                            input=input_bytes, timeout=timeout, env=ENV,
                            creationflags=subprocess.CREATE_NO_WINDOW)
    if result.returncode:
        raise RuntimeError('git ' + args[0] + ' exit=' + str(result.returncode) + ' ' +
                           result.stderr.decode(errors='replace')[-600:])
    return result.stdout

assert git('branch', '--show-current').decode().strip() == BRANCH
assert set(git('diff', '--cached', '--name-only').decode().splitlines()) <= set(hashes)
for rel, sha in hashes.items():
    assert file_sha(ROOT / rel) == sha, rel
    target = WT / rel
    C.authorized(C.ceo_lease(C.read_json(C.registry)), target)
    target.parent.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(ROOT / rel, target)
git('-c', 'core.autocrlf=false', 'add', '--', *hashes)
changed = git('diff', '--cached', '--name-only').decode().splitlines()
assert set(changed) <= set(hashes)
if changed:
    # Preserve the frozen raw unified diff, whose blank context line has a space.
    # Check authored code/documents without altering this evidence artifact.
    checked = [rel for rel in changed if not rel.endswith('/runtime_fix.diff')]
    git('-c', 'core.whitespace=blank-at-eol,blank-at-eof,space-before-tab,cr-at-eol',
        'diff', '--cached', '--check', '--', *checked)
    git('commit', '-m', 'fix(ceo): bound leases and record reviewed Paseo source repair')
commit = git('rev-parse', 'HEAD').decode().strip()
objects = git('cat-file', '--batch', input_bytes=''.join(
    commit + ':' + rel + '\n' for rel in hashes).encode())
offset = 0
for rel, sha in hashes.items():
    end = objects.index(b'\n', offset)
    header = objects[offset:end].split()
    assert len(header) == 3 and header[1] == b'blob', rel
    size = int(header[2])
    body = objects[end + 1:end + 1 + size]
    assert len(body) == size and hashlib.sha256(body).hexdigest() == sha, rel
    offset = end + 1 + size
    assert objects[offset:offset + 1] == b'\n', rel
    offset += 1
assert offset == len(objects)
print(json.dumps({'stage': 'COMMIT_VERIFIED', 'commit': commit, 'blobs': len(hashes)}), flush=True)
git('push', 'origin', BRANCH)
remote = git('ls-remote', 'origin', 'refs/heads/' + BRANCH).decode().split()[0]
assert remote == commit
with C.transaction() as (registry, state):
    receipt = {'schema_version': '2.1.2', 'commit': commit, 'branch': BRANCH,
               'remote_verified': remote, 'files': hashes, 'observed_at': iso(C.clock()),
               'scope': 'Controller repair, TASK070 diagnostic, TASK071 source/testing; live deployment pending',
               'whitespace_check_exception': 'Immutable runtime_fix.diff blank context line; all other changed authored files checked',
               'production_baseline_v4_accepted': False, 'private_tokens_published': False}
    C.replace_json(ROOT / '.ai/ceo/receipts/PASEO_REVIEWED_SOURCE_PUBLICATION_20261008.json', receipt, registry)
    updated = json.loads(json.dumps(registry))
    matched = [x for x in updated['active_locks'] if x.get('fencing_token') == 1019]
    assert len(matched) == 1
    matched[0].update(status='RELEASED', expiry=0, released_at=iso(C.clock()),
                      release_reason='TASK070 accepted diagnostic blobs and remote verified')
    C.replace_json(C.registry, updated, registry)
    registry.clear()
    registry.update(updated)
    for task in ('TASK_070', 'TASK_071'):
        meta = C.tasks()[task]
        state.setdefault('completion_records', {})[task] = {
            'task_id': task, 'revision': meta['revision'],
            'fingerprint': state['tasks'][task]['fingerprint'],
            'task_sha256': file_sha(ROOT / meta['_path']),
            'report_folder': meta['report_folder'], 'commit': commit,
            'remote_verified': remote, 'completed_at': iso(C.clock()),
            'scope': 'Diagnostic only' if task == 'TASK_070' else 'Source/testing only; live deployment remains pending'}
    state['last_target_commit_sha'] = commit
    C.event(state, 'CEO_REVIEWED_TOOLING_PUBLICATION_VERIFIED', None,
            commit=commit, remote_verified=remote, scoped_blob_hashes=len(hashes), live_deployment_verified=False)
print(json.dumps({'stage': 'REMOTE_VERIFIED', 'commit': commit, 'blobs': len(hashes),
                  'lease1019': 'RELEASED', 'live_deployment_verified': False}), flush=True)
