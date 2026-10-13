"""Stage exact accepted TASK_206 evidence and a reproducible technical cache."""

import hashlib
import json
import shutil
import sys
import zipfile
from datetime import datetime, timezone
from pathlib import Path

from integrate_tasks162_167 import BRANCH, ROOT, STANDARD_SHA, WORKTREE, git, git_blob_sha, safe_path, sha

sys.path.insert(0, str(ROOT / '.ai/ceo'))
from controller import Controller  # noqa: E402
from prepare_publish_tasks189_190 import atomic_file  # noqa: E402


TASK = 'TASK_206'
REPORT_FOLDER = 'RULES/REPORT/TASK_206_REPORT_R1'
LEDGER = 'RULES/REPORT/CEO_SO45_ORCHESTRATION/ACCEPTED_INTERNAL_FDE_RESEARCH_206_R1.json'
ARCHIVE = '.ai/ceo/reviews/TASK_206_GHIDRA_TECHNICAL_CACHE.zip'
REFERENCE = '.ai/ceo/reviews/TASK_206_GHIDRA_TECHNICAL_CACHE_REFERENCE.json'
REPLAY_DEST = '.ai/ceo/reviews/TASK_206_CEO_REPLAY_SUCCESS'
REPLAY_SOURCE = Path('F:/CONVERT_WORKTREES/ceo-so45-20261008/TASK_206_CEO_REPLAY')
TECHNICAL_CACHE = 'RESEARCH_WORK/TASK_146_R1/ghidra_project'
SO = 'lib-core-graphics/src/main/jniLibs/arm64-v8a/libLayerFlow.so'


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or sha(ROOT / 'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt') != STANDARD_SHA:
        raise RuntimeError('END requested or canonical changed')
    lease = ctl.ceo_lease(ctl.read_json(ROOT / '.ai/locks.json'))
    if git('branch', '--show-current').decode().strip() != BRANCH:
        raise RuntimeError('wrong owned branch')
    if not WORKTREE.resolve().is_relative_to(Path('F:/CONVERT_WORKTREES/ceo-so45-20261008').resolve()):
        raise RuntimeError('unexpected owned worktree')
    if git('diff', '--cached', '--name-only', '-z').strip(b'\0'):
        raise RuntimeError('owned index already staged')
    if git('status', '--short', '--', '.gitattributes').strip():
        raise RuntimeError('owned attributes have unrelated changes')
    state, tasks = ctl.read_json(ROOT / '.ai/ceo/state.json'), ctl.tasks()
    if not ctl.accepted(TASK, state, tasks, required_revision=1):
        raise RuntimeError('current accepted TASK_206 fingerprint absent')
    verdict = state['tasks'][TASK]['verdict']
    report = safe_path(ROOT, REPORT_FOLDER)
    seal = json.loads((report / 'COMPLETE.json').read_text(encoding='utf8'))
    if (seal['task_id'], seal['revision'], seal['status'], seal['standard_sha256']) != (TASK, 1, 'COMPLETE', STANDARD_SHA):
        raise RuntimeError('wrong TASK_206 seal')
    if (seal['target_fde_candidate_count'], seal['ghidra_function_c_like_count'],
            seal['ghidra_instruction_slots'], seal['ghidra_pcode_instruction_slots'],
            seal['rows_with_missing_fde_bytes']) != (128, 128, 2247, 2236, 4):
        raise RuntimeError('critical task206 counts changed')
    if sha(safe_path(ROOT, SO)) != seal['original_so_sha256']:
        raise RuntimeError('original SO changed')
    tree = git('ls-tree', 'HEAD', '--', SO).decode().split()
    if len(tree) < 3 or tree[2] != git_blob_sha(safe_path(ROOT, SO)):
        raise RuntimeError('pinned SO missing/differs on owned branch')
    actual = {p.relative_to(report).as_posix() for p in report.rglob('*') if p.is_file()} - {
        'COMPLETE.json', 'PROGRESS.json', 'PROGRESS.md'}
    if actual != set(seal['files']):
        raise RuntimeError('report inventory changed')
    paths = {}

    def add(relative, expected=None):
        path = safe_path(ROOT, relative)
        if not path.is_file():
            raise RuntimeError('missing source: ' + relative)
        value = sha(path)
        if expected is not None and value != expected:
            raise RuntimeError('source hash mismatch: ' + relative)
        if relative in paths and paths[relative] != value:
            raise RuntimeError('conflicting path: ' + relative)
        paths[relative] = value

    for relative, expected in seal['files'].items():
        add(REPORT_FOLDER + '/' + relative, expected)
    for relative, expected in seal['code_files'].items():
        add(relative, expected)
    add(REPORT_FOLDER + '/COMPLETE.json')
    add('RULES/TASK/TASK_206_SO45_CODEX_INTERNAL_ACTIVE.md', seal['task_sha256'])
    add('.ai/ceo/reviews/TASK_206_internal_targets.json', seal['target_manifest_sha256'])
    add(verdict['review_file'], verdict['review_sha256'])
    for relative in ('.ai/ceo/reviews/prepare_publish_tasks204_206.py',
                     '.ai/ceo/reviews/replay_task206.py',
                     '.ai/ceo/reviews/integrate_task206.py'):
        add(relative)
    for path in sorted((ROOT / '.ai/ceo/reviews/TASK_206_CEO_REPLAY').glob('*')):
        if path.is_file():
            add(path.relative_to(ROOT).as_posix())

    replay_summary = json.loads((REPLAY_SOURCE / 'summary.json').read_text(encoding='utf8'))
    if sha(REPLAY_SOURCE / 'summary.json') != '6d43909bc02ede91e08f2a26f4b443c7cd419993eaa9a2edeadf4dfff5c422c8':
        raise RuntimeError('successful independent replay changed')
    if not REPLAY_SOURCE.resolve().is_relative_to(Path('F:/CONVERT_WORKTREES/ceo-so45-20261008').resolve()):
        raise RuntimeError('unexpected replay source')
    for name in ('ghidra_raw.ndjson', 'stderr.log', 'stdout.log', 'summary.json', 'targets.tsv'):
        destination = safe_path(ROOT, REPLAY_DEST + '/' + name)
        ctl.authorized(lease, destination)
        destination.parent.mkdir(parents=True, exist_ok=True)
        if destination.exists() and sha(destination) != sha(REPLAY_SOURCE / name):
            raise RuntimeError('existing successful replay destination differs')
        if not destination.exists():
            shutil.copyfile(REPLAY_SOURCE / name, destination)
        add(REPLAY_DEST + '/' + name, sha(REPLAY_SOURCE / name))

    copy_receipt = json.loads((report / 'project_copy_receipt.json').read_text(encoding='utf8'))
    source_hashes = copy_receipt['technical_cache_file_sha256']
    if copy_receipt['technical_cache_status'] != 'UNREVIEWED' or len(source_hashes) != 10:
        raise RuntimeError('unexpected technical cache receipt')
    archive_path = safe_path(ROOT, ARCHIVE)
    ctl.authorized(lease, archive_path)
    if archive_path.exists():
        raise RuntimeError('technical archive already exists')
    archive_path.parent.mkdir(parents=True, exist_ok=True)
    with zipfile.ZipFile(archive_path, 'w', zipfile.ZIP_DEFLATED, compresslevel=6) as zf:
        for suffix, expected in sorted(source_hashes.items()):
            original = safe_path(ROOT, TECHNICAL_CACHE + '/' + suffix)
            if sha(original) != expected:
                raise RuntimeError('technical cache source changed: ' + suffix)
            zf.write(original, TECHNICAL_CACHE + '/' + suffix)
    if archive_path.stat().st_size >= 100_000_000:
        raise RuntimeError('technical archive exceeds GitHub blob limit')
    with zipfile.ZipFile(archive_path) as zf:
        if set(zf.namelist()) != {TECHNICAL_CACHE + '/' + key for key in source_hashes}:
            raise RuntimeError('technical archive entries differ')
        for suffix, expected in source_hashes.items():
            if hashlib.sha256(zf.read(TECHNICAL_CACHE + '/' + suffix)).hexdigest() != expected:
                raise RuntimeError('technical archive roundtrip differs: ' + suffix)
    add(ARCHIVE)

    reference_path = safe_path(ROOT, REFERENCE)
    ctl.authorized(lease, reference_path)
    if reference_path.exists():
        raise RuntimeError('technical reference already exists')
    reference = {
        'schema_version': '2.1.2', 'task_id': TASK, 'revision': 1,
        'generated_at': datetime.now(timezone.utc).isoformat(),
        'complete_sha256': sha(report / 'COMPLETE.json'),
        'accepted_review_sha256': verdict['review_sha256'],
        'original_so_path': SO, 'original_so_sha256': seal['original_so_sha256'],
        'original_so_git_blob': tree[2],
        'cache_status': 'UNREVIEWED_TECHNICAL_CACHE_ONLY',
        'cache_source': TECHNICAL_CACHE,
        'archive_path': ARCHIVE, 'archive_sha256': sha(archive_path),
        'archive_bytes': archive_path.stat().st_size,
        'project_files': source_hashes, 'roundtrip_verified': True,
        'program_identity_probe': REPORT_FOLDER + '/identity/program_identity.json',
        'private_project_postrun_drift': REPORT_FOLDER + '/project_postrun_receipt.json',
        'independent_successful_replay': REPLAY_DEST + '/summary.json',
        'replay_rows': 17,
        'note': 'Archive holds the original unreviewed TASK_146 technical cache, not the nine-file private postrun project. Identity and bounded extraction were independently checked; no full-library semantics or runtime parity is asserted.',
    }
    atomic_file(reference_path, (json.dumps(reference, ensure_ascii=False, indent=2) + '\n').encode('utf8'))
    add(REFERENCE)
    for relative, expected in paths.items():
        destination = safe_path(WORKTREE, relative)
        ctl.authorized(lease, destination)
        if destination.exists() and sha(destination) != expected:
            raise RuntimeError('destination differs: ' + relative)
        if git('ls-tree', 'HEAD', '--', relative).strip():
            raise RuntimeError('path already tracked: ' + relative)
    ledger_path = safe_path(ROOT, LEDGER)
    ctl.authorized(lease, ledger_path)
    if ledger_path.exists():
        raise RuntimeError('ledger already exists')
    ledger = {
        'schema_version': '2.1.2', 'generated_at': datetime.now(timezone.utc).isoformat(),
        'branch': BRANCH, 'standard_sha256': STANDARD_SHA,
        'task_id': TASK, 'accepted_revision': 1,
        'fingerprint': verdict['fingerprint'], 'review_sha256': verdict['review_sha256'],
        'complete_sha256': sha(report / 'COMPLETE.json'),
        'research_disposition': 'ACCEPTED_BOUNDED_PARTIAL_STATIC_FDE_BOUNDARY',
        'source_candidates': 128, 'whole_fde_exact_body_c_like_count': 124,
        'ghidra_function_c_like_count': 128,
        'missing_fde_byte_rows': 4,
        'technical_cache_delivery': REFERENCE,
        'successful_replay_summary_sha256': sha(REPLAY_SOURCE / 'summary.json'),
        'files': paths,
        'behavior_equivalence_proven': False, 'all_45_so_complete': False,
        'product_phase_pass': False, 'v4_opened': False,
    }
    atomic_file(ledger_path, (json.dumps(ledger, ensure_ascii=False, indent=2) + '\n').encode('utf8'))
    add(LEDGER)
    for relative, expected in paths.items():
        destination = safe_path(WORKTREE, relative)
        destination.parent.mkdir(parents=True, exist_ok=True)
        if not destination.exists():
            shutil.copyfile(safe_path(ROOT, relative), destination)
        if sha(destination) != expected:
            raise RuntimeError('copy differs: ' + relative)
    attributes = WORKTREE / '.gitattributes'
    ctl.authorized(lease, attributes)
    original = attributes.read_bytes()
    lines = set(original.decode('utf8').splitlines())
    additions = [f'/{relative} -text' for relative in sorted(paths)
                 if f'/{relative} -text' not in lines]
    if additions:
        attributes.write_bytes(original + ('\n'.join(additions) + '\n').encode('utf8'))
    git('add', '--', '.gitattributes')
    ordered = sorted(paths)
    for start in range(0, len(ordered), 75):
        git('add', '--', *ordered[start:start + 75])
    staged = {x for x in git('diff', '--cached', '--name-only', '-z').decode().split('\0') if x}
    if staged != set(paths) | {'.gitattributes'}:
        raise RuntimeError('unexpected staged paths')
    for relative in paths:
        row = git('ls-files', '--stage', '--', relative).decode().split()
        if len(row) < 2 or row[1] != git_blob_sha(safe_path(ROOT, relative)):
            raise RuntimeError('index blob mismatch: ' + relative)
    print(json.dumps({'status': 'STAGED_EXACT_BYTES', 'task_id': TASK,
                      'paths': len(paths), 'ledger_sha256': sha(ledger_path),
                      'archive_bytes': archive_path.stat().st_size,
                      'replay_rows': replay_summary.get('matched_rows', 'see summary')}))


if __name__ == '__main__':
    main()
