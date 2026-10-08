"""Pinned, task-leased source acquisition only; never executes upstream code."""
import datetime, hashlib, json, os, subprocess, sys, uuid
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / '.ai/ceo'))
from controller import Controller, guard
C = Controller(ROOT)
BASE = ROOT / '.ai/reconstruction/reference_sources/storytold'
REPORT = ROOT / 'RULES/REPORT/TASK_068_REPORT_R1'
PINS = {
    'photocraft': '452672765d91acef793bae654e6a29cf10fa5df2',
    'lightcraft': '629e39380e296f588c64cd9c0053a8edc3528f36',
    'filmcraft': '61238bf8fc129077fe2b7982550303be49f55a93',
}
RECEIPTS = []

def now():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()

def sha(data):
    return hashlib.sha256(data).hexdigest()

def lease(path):
    registry = C.read_json(C.registry)
    matches = [v for v in registry['active_locks'] if v['lease_id'] == 'LEASE-CEO-WORKER-TASK_068-R1']
    assert len(matches) == 1
    v = matches[0]
    assert v['agent_id'] == 'c835368f-e9f9-41b6-88ee-8cd104245fa8' and v['fencing_token'] == 1014 and C.lease_live(v)
    assert v['task_sha'] == '98f0f5f68d0b90844796ae42f42a4e0663ed17e8ded37efec782e880bb0bb0c7'
    C.authorized(v, path)
    return v

def write(path, data):
    with guard(ROOT / '.ai/locks.registry.guard'):
        lease(path)
        path.parent.mkdir(parents=True, exist_ok=True)
        temp = path.parent / ('.task068-' + uuid.uuid4().hex + '.tmp')
        lease(temp)
        try:
            with temp.open('xb') as stream:
                stream.write(data); stream.flush(); os.fsync(stream.fileno())
            lease(path); os.replace(temp, path)
        finally:
            if temp.exists(): temp.unlink()

def jwrite(path, value):
    write(path, (json.dumps(value, ensure_ascii=False, indent=2) + '\n').encode('utf-8'))

def git(args, cwd, label):
    lease(cwd / '.git/task068-command-scope')
    cmd = ['git', '-c', 'core.autocrlf=false', '-c', 'core.symlinks=false'] + args
    start = now()
    env = dict(os.environ, GIT_TERMINAL_PROMPT='0', GIT_LFS_SKIP_SMUDGE='1')
    result = subprocess.run(cmd, cwd=cwd if cwd.exists() else ROOT, capture_output=True, env=env, timeout=240)
    end = now()
    out = REPORT / 'raw' / (label + '.stdout')
    err = REPORT / 'raw' / (label + '.stderr')
    write(out, result.stdout); write(err, result.stderr)
    RECEIPTS.append({'command': cmd, 'cwd': str(cwd), 'started_at': start, 'ended_at': end,
                     'exit_code': result.returncode, 'stdout_path': str(out.relative_to(ROOT)), 'stdout_sha256': sha(result.stdout),
                     'stderr_path': str(err.relative_to(ROOT)), 'stderr_sha256': sha(result.stderr)})
    jwrite(REPORT / 'raw/command_receipts.json', RECEIPTS)
    if result.returncode: raise RuntimeError(label + ' failed; see retained stderr')
    return result.stdout

def main():
    standard = ROOT / 'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt'
    text = standard.read_text(encoding='utf-8')
    standard_sha = sha(standard.read_bytes())
    assert standard_sha == '10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f'
    for rel in ['AGENTS.md', 'Docs/rules.md', '.ai/ceo/SO45_TO_V4_PLAN.md', '.ai/ceo/config.json', '.ai/ceo/state.json']:
        (ROOT / rel).read_text(encoding='utf-8-sig')
    lease(REPORT / '00_AUDIT_INDEX.md')
    assert not (REPORT / 'COMPLETE.json').exists(), 'Frozen candidate must not be modified'
    old_receipts = REPORT / 'raw/command_receipts.json'
    if old_receipts.exists(): RECEIPTS.extend(json.loads(old_receipts.read_text(encoding='utf-8')))
    audit = ('# TASK068 audit index\nActual executor: Codex CEO root, external ID c835368f-e9f9-41b6-88ee-8cd104245fa8.\n'
             'Execution mode: CEO direct acquisition, real read-only collaboration reviewers.\n'
             'Lease: LEASE-CEO-WORKER-TASK_068-R1; fencing_token1014.\nFull canonical UTF8 read at ' + now() + '\n'
             'Path: ' + str(standard) + '\nSHA256: ' + standard_sha + '\nRead chars: ' + str(len(text)) + '\n'
             'AGENTS/rules/plan/config/state read. No upstream scripts/builds/dependencies executed. No production/P0 writes.\n')
    write(REPORT / '00_AUDIT_INDEX.md', audit.encode('utf-8'))
    sources = []
    for name, pin in PINS.items():
        dest = BASE / name
        url = 'https://github.com/storytold/' + name + '.git'
        progress = {'schema_version': '2.1.2', 'task_id': 'TASK_068', 'revision': 1, 'status': 'TASK_EXECUTING',
                    'milestone': 'ACQUIRE_' + name.upper(), 'updated_at': now(), 'fencing_token': 1014}
        jwrite(REPORT / 'PROGRESS.json', progress)
        owner = BASE / (name + '.owner.json')
        if not owner.exists():
            assert not dest.exists(), 'Refusing pre-existing unowned destination'
            jwrite(owner, {'task_id': 'TASK_068', 'repository': url, 'commit': pin})
        assert json.loads(owner.read_text(encoding='utf-8')) == {'task_id': 'TASK_068', 'repository': url, 'commit': pin}
        if not (dest / '.git').exists():
            assert not dest.exists(), 'Partial clone requires inspection before resuming'
            lease(dest / 'source-write-scope'); dest.parent.mkdir(parents=True, exist_ok=True)
            git(['clone', '--depth', '1', '--no-checkout', '--quiet', url, str(dest)], dest, name + '_clone')
        origin = git(['remote', 'get-url', 'origin'], dest, name + '_origin').decode().strip()
        assert origin == url
        # Fetch only the pinned reachable commit; never silently substitute current main.
        git(['fetch', '--depth', '1', '--quiet', 'origin', pin], dest, name + '_fetch_pinned')
        git(['checkout', '--detach', '--quiet', pin], dest, name + '_checkout')
        head = git(['rev-parse', 'HEAD'], dest, name + '_head').decode().strip()
        assert head == pin
        git(['fsck', '--full', '--no-reflogs'], dest, name + '_fsck')
        tree = git(['ls-tree', '-r', '-z', 'HEAD'], dest, name + '_tree')
        files, submodules, pointers = [], [], []
        for record in tree.split(b'\0'):
            if not record: continue
            info, relb = record.split(b'\t', 1); mode, kind, oid = info.decode().split()
            rel = relb.decode('utf-8'); p = (dest / rel).resolve()
            assert p.is_relative_to(dest.resolve())
            if kind == 'commit':
                submodules.append({'path': rel, 'commit': oid}); continue
            assert kind == 'blob' and p.is_file()
            content = p.read_bytes()
            blob = hashlib.sha1(b'blob ' + str(len(content)).encode() + b'\0' + content).hexdigest()
            assert blob == oid, 'Working file differs from Git blob: ' + rel
            files.append({'path': rel, 'bytes': len(content), 'sha256': sha(content), 'git_blob': oid, 'mode': mode})
            if content.startswith(b'version https://git-lfs.github.com/spec/v1'):
                pointers.append(rel)
        licenses = [v for v in files if v['path'] in ['LICENSE-MIT', 'LICENSE-APACHE', 'NOTICE', 'ATTRIBUTION.md']]
        assert {'LICENSE-MIT', 'LICENSE-APACHE'}.issubset({v['path'] for v in licenses})
        status = git(['status', '--porcelain'], dest, name + '_clean').decode()
        assert not status.strip(), 'Upstream checkout has local changes'
        source = {'classification': 'UPSTREAM_OPEN_SOURCE_REFERENCE', 'name': name, 'url': url, 'commit': head,
                  'path': str(dest.relative_to(ROOT)), 'files': files, 'tracked_file_count': len(files),
                  'tracked_bytes': sum(v['bytes'] for v in files), 'license_files': licenses,
                  'lfs_pointers_not_materialized': pointers, 'submodules_not_materialized': submodules,
                  'all_materialized_blobs_verified': True, 'android_build_and_runtime': 'NOT_TESTED',
                  'asset_model_dependency_licenses': 'REVIEW_SEPARATELY'}
        sources.append(source)
        jwrite(REPORT / ('source_' + name + '.json'), source)
        print(json.dumps({'repository': name, 'commit': head, 'files': len(files), 'bytes': source['tracked_bytes'],
                          'lfs_pointers': len(pointers), 'submodules': len(submodules)}), flush=True)
    manifest = {'schema_version': '2.1.2', 'task_id': 'TASK_068', 'revision': 1, 'classification': 'UPSTREAM_OPEN_SOURCE_REFERENCE',
                'generated_at': now(), 'standard_sha256': standard_sha, 'sources': sources,
                'command_receipts': 'raw/command_receipts.json', 'script_sha256': sha(Path(__file__).read_bytes()),
                'gate': 'REFERENCE_ONLY; NO_SO45_ACCEPTANCE_OR_PRODUCTION_V4'}
    jwrite(REPORT / '02_SOURCE_MANIFEST.json', manifest)
    jwrite(REPORT / 'PROGRESS.json', {'schema_version': '2.1.2', 'task_id': 'TASK_068', 'revision': 1,
            'status': 'TASK_EXECUTING', 'milestone': 'THREE_PINNED_SOURCES_VERIFIED_AWAITING_INDEX', 'updated_at': now(), 'fencing_token': 1014})
    print('All three pinned sources acquired and blob-verified. Index/report remain to finalize.', flush=True)

if __name__ == '__main__': main()
