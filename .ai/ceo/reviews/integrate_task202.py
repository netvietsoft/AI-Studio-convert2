"""Stage exact accepted TASK_202 research with deduplicated Ghidra project."""

import json
import shutil
import sys
from datetime import datetime, timezone
from pathlib import Path

from integrate_tasks162_167 import BRANCH, ROOT, STANDARD_SHA, WORKTREE, git, git_blob_sha, safe_path, sha

sys.path.insert(0, str(ROOT / '.ai/ceo'))
from controller import Controller  # noqa: E402


TASK = 'TASK_202'
LEDGER = 'RULES/REPORT/CEO_SO45_ORCHESTRATION/ACCEPTED_INTERNAL_FDE_RESEARCH_202_R1.json'
REFERENCE = '.ai/ceo/reviews/TASK_202_R1_GHIDRA_PROJECT_REFERENCE.json'
ARCHIVE = '.ai/ceo/reviews/TASK_199_R1_GHIDRA_PROJECT.zip'
ARCHIVE_RECEIPT = '.ai/ceo/reviews/TASK_199_R1_GHIDRA_PROJECT_ARCHIVE.json'


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
    state, tasks = ctl.read_json(ROOT / '.ai/ceo/state.json'), ctl.tasks()
    if not ctl.accepted(TASK, state, tasks, required_revision=1):
        raise RuntimeError('current accepted TASK_202 fingerprint absent')
    verdict = state['tasks'][TASK]['verdict']
    report_folder = f'RULES/REPORT/{TASK}_REPORT_R1'
    report = safe_path(ROOT, report_folder)
    seal = json.loads((report / 'COMPLETE.json').read_text(encoding='utf8'))
    if (seal['task_id'], seal['revision'], seal['status'], seal['standard_sha256']) != (
            TASK, 1, 'COMPLETE', STANDARD_SHA):
        raise RuntimeError('wrong TASK_202 seal')
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
        add(report_folder + '/' + relative, expected)
    for relative, expected in seal['code_files'].items():
        add(relative, expected)
    for relative, expected in seal['scratch_files'].items():
        if '/ghidra_project/' not in relative:
            add(relative, expected)
    add(report_folder + '/COMPLETE.json')
    add('RULES/TASK/TASK_202_SO45_CODEX_INTERNAL_ACTIVE.md', seal['task_sha256'])
    add('.ai/ceo/reviews/TASK_202_internal_targets.json', seal['target_manifest_sha256'])
    add(verdict['review_file'], verdict['review_sha256'])
    add('.ai/ceo/reviews/prepare_publish_tasks201_202.py')
    add('.ai/ceo/reviews/rerun_tasks201_202_ghidra.py')
    replay = safe_path(ROOT, '.ai/ceo/reviews/TASK_202_CEO_REPLAY')
    for path in sorted(replay.rglob('*')):
        if path.is_file():
            add(path.relative_to(ROOT).as_posix())
    prior_receipt = json.loads(safe_path(ROOT, ARCHIVE_RECEIPT).read_text(encoding='utf8'))
    prefix202 = 'RESEARCH_WORK/TASK_202_R1/ghidra_project/'
    prefix199 = 'RESEARCH_WORK/TASK_199_R1/ghidra_project/'
    current_project = {k[len(prefix202):]: v for k, v in seal['scratch_files'].items()
                       if k.startswith(prefix202)}
    archive_project = {k[len(prefix199):]: v for k, v in prior_receipt['project_files'].items()
                       if k.startswith(prefix199)}
    if len(current_project) != 9 or current_project != archive_project or not prior_receipt['roundtrip_verified']:
        raise RuntimeError('TASK_202 project differs from accepted TASK_199 archive')
    archive_path = safe_path(ROOT, ARCHIVE)
    if sha(archive_path) != prior_receipt['archive_sha256']:
        raise RuntimeError('accepted archive changed')
    if not git('ls-tree', 'HEAD', '--', ARCHIVE).strip():
        raise RuntimeError('accepted archive not present on owned branch')
    branch_blob = git('ls-tree', 'HEAD', '--', ARCHIVE).decode().split()[2]
    if branch_blob != git_blob_sha(archive_path):
        raise RuntimeError('branch archive blob differs')
    ref_path = safe_path(ROOT, REFERENCE)
    ctl.authorized(lease, ref_path)
    if ref_path.exists():
        raise RuntimeError('TASK_202 project reference already exists')
    reference = {'schema_version': '2.1.2', 'task_id': TASK, 'revision': 1,
                 'generated_at': datetime.now(timezone.utc).isoformat(),
                 'complete_sha256': sha(report / 'COMPLETE.json'),
                 'accepted_review_sha256': verdict['review_sha256'],
                 'project_files': current_project,
                 'delivery': 'identical nine-file project in prior accepted TASK_199 archive',
                 'archive_path': ARCHIVE,
                 'archive_sha256': prior_receipt['archive_sha256'],
                 'archive_receipt_sha256': sha(safe_path(ROOT, ARCHIVE_RECEIPT)),
                 'roundtrip_verified': True}
    ref_path.write_text(json.dumps(reference, ensure_ascii=False, indent=2) + '\n', encoding='utf8')
    add(REFERENCE)
    add('.ai/ceo/reviews/integrate_task202.py')
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
    ledger = {'schema_version': '2.1.2', 'generated_at': datetime.now(timezone.utc).isoformat(),
              'branch': BRANCH, 'standard_sha256': STANDARD_SHA,
              'task_id': TASK, 'revision': 1,
              'fingerprint': verdict['fingerprint'], 'review_sha256': verdict['review_sha256'],
              'complete_sha256': sha(report / 'COMPLETE.json'),
              'research_disposition': 'ACCEPTED_BOUNDED_PARTIAL_STATIC_RESEARCH',
              'source_candidates': 62, 'c_like_successes': 61,
              'c_like_failure_candidate_index': 193,
              'project_delivery': REFERENCE,
              'files': paths,
              'behavior_equivalence_proven': False, 'all_45_so_complete': False,
              'product_phase_pass': False, 'v4_opened': False}
    ledger_path.write_text(json.dumps(ledger, ensure_ascii=False, indent=2) + '\n', encoding='utf8')
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
                      'reference_sha256': sha(ref_path)}))


if __name__ == '__main__':
    main()
