"""Stage exact accepted TASK_201 R1 evidence plus R2 census correction."""

import json
import shutil
import sys
from datetime import datetime, timezone
from pathlib import Path

from integrate_tasks162_167 import BRANCH, ROOT, STANDARD_SHA, WORKTREE, git, git_blob_sha, safe_path, sha

sys.path.insert(0, str(ROOT / '.ai/ceo'))
from controller import Controller  # noqa: E402
from prepare_publish_tasks189_190 import atomic_file  # noqa: E402


TASK = 'TASK_201'
LEDGER = 'RULES/REPORT/CEO_SO45_ORCHESTRATION/ACCEPTED_INTERNAL_FDE_RESEARCH_201_R1_R2.json'
REFERENCE = '.ai/ceo/reviews/TASK_201_R1_GHIDRA_PROJECT_REFERENCE.json'
PRIOR_PROJECT = 'RESEARCH_WORK/TASK_197_R1/ghidra_project/'
CURRENT_PROJECT = 'RESEARCH_WORK/TASK_201_R1/ghidra_project/'


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
    if not ctl.accepted(TASK, state, tasks, required_revision=2):
        raise RuntimeError('current accepted TASK_201 R2 fingerprint absent')
    verdict = state['tasks'][TASK]['verdict']
    r1_folder = 'RULES/REPORT/TASK_201_REPORT_R1'
    r2_folder = 'RULES/REPORT/TASK_201_REPORT_R2'
    r1 = safe_path(ROOT, r1_folder)
    r2 = safe_path(ROOT, r2_folder)
    seal1 = json.loads((r1 / 'COMPLETE.json').read_text(encoding='utf8'))
    seal2 = json.loads((r2 / 'COMPLETE.json').read_text(encoding='utf8'))
    if (seal1['task_id'], seal1['revision'], seal1['status'], seal1['standard_sha256']) != (TASK, 1, 'COMPLETE', STANDARD_SHA):
        raise RuntimeError('wrong TASK_201 R1 seal')
    if (seal2['task_id'], seal2['revision'], seal2['status'], seal2['standard_sha256']) != (TASK, 2, 'COMPLETE', STANDARD_SHA):
        raise RuntimeError('wrong TASK_201 R2 seal')
    if seal2['r1_complete_sha256'] != sha(r1 / 'COMPLETE.json'):
        raise RuntimeError('R2 does not pin immutable R1 seal')
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

    for folder, seal in ((r1_folder, seal1), (r2_folder, seal2)):
        actual = {p.relative_to(safe_path(ROOT, folder)).as_posix()
                  for p in safe_path(ROOT, folder).rglob('*') if p.is_file()} - {
                      'COMPLETE.json', 'PROGRESS.json', 'PROGRESS.md'}
        if actual != set(seal['files']):
            raise RuntimeError('report inventory changed: ' + folder)
        for relative, expected in seal['files'].items():
            add(folder + '/' + relative, expected)
        for relative, expected in seal['code_files'].items():
            add(relative, expected)
        add(folder + '/COMPLETE.json')
    for relative, expected in seal1['scratch_files'].items():
        if not relative.startswith(CURRENT_PROJECT):
            add(relative, expected)
    r1_task_archive = f'.ai/ceo/reviews/TASK_201_R1_TASK_ARCHIVE_{seal1["task_sha256"]}.md'
    add(r1_task_archive, seal1['task_sha256'])
    add('RULES/TASK/TASK_201_SO45_CODEX_INTERNAL_ACTIVE.md', seal2['task_sha256'])
    add('.ai/ceo/reviews/TASK_201_internal_targets.json', seal1['target_manifest_sha256'])
    add('.ai/ceo/reviews/TASK_201_R2_internal_targets.json', seal2['target_manifest_sha256'])
    add('.ai/ceo/reviews/TASK_201-3aa9e79e3edebe13205ab0a1be1682e7c957aaa99dafe7e1c53f0c2247de5599.md')
    add(verdict['review_file'], verdict['review_sha256'])
    add('.ai/ceo/reviews/publish_task201_r2.py')
    add('.ai/ceo/reviews/integrate_task201.py')
    replay = safe_path(ROOT, '.ai/ceo/reviews/TASK_201_CEO_REPLAY')
    for path in sorted(replay.rglob('*')):
        if path.is_file():
            add(path.relative_to(ROOT).as_posix())
    prior_seal = json.loads(safe_path(ROOT, 'RULES/REPORT/TASK_197_REPORT_R1/COMPLETE.json').read_text(encoding='utf8'))
    current_project = {k[len(CURRENT_PROJECT):]: v for k, v in seal1['scratch_files'].items()
                       if k.startswith(CURRENT_PROJECT)}
    prior_project = {k[len(PRIOR_PROJECT):]: v for k, v in prior_seal['scratch_files'].items()
                     if k.startswith(PRIOR_PROJECT)}
    if len(current_project) != 9 or current_project != prior_project:
        raise RuntimeError('TASK_201 private project differs from accepted TASK_197 project')
    for suffix, expected in prior_project.items():
        relative = PRIOR_PROJECT + suffix
        if sha(safe_path(ROOT, relative)) != expected:
            raise RuntimeError('prior project source hash changed: ' + relative)
        tree = git('ls-tree', 'HEAD', '--', relative).decode().split()
        if len(tree) < 3 or tree[2] != git_blob_sha(safe_path(ROOT, relative)):
            raise RuntimeError('prior project branch blob missing/differs: ' + relative)
    for relative in ('.ai/ceo/reviews/prepare_publish_tasks201_202.py',
                     '.ai/ceo/reviews/rerun_tasks201_202_ghidra.py'):
        tree = git('ls-tree', 'HEAD', '--', relative).decode().split()
        if len(tree) < 3 or tree[2] != git_blob_sha(safe_path(ROOT, relative)):
            raise RuntimeError('previous tooling branch blob missing/differs: ' + relative)
    ref_path = safe_path(ROOT, REFERENCE)
    ctl.authorized(lease, ref_path)
    if ref_path.exists():
        raise RuntimeError('TASK_201 project reference already exists')
    reference = {'schema_version': '2.1.2', 'task_id': TASK, 'revision': 1,
                 'generated_at': datetime.now(timezone.utc).isoformat(),
                 'r1_complete_sha256': sha(r1 / 'COMPLETE.json'),
                 'r2_complete_sha256': sha(r2 / 'COMPLETE.json'),
                 'accepted_r2_review_sha256': verdict['review_sha256'],
                 'project_files': current_project,
                 'delivery': 'identical nine-file project already in accepted TASK_197 branch commit',
                 'branch_path_prefix': PRIOR_PROJECT,
                 'prior_task197_complete_sha256': sha(safe_path(ROOT, 'RULES/REPORT/TASK_197_REPORT_R1/COMPLETE.json')),
                 'byte_identity_verified': True}
    atomic_file(ref_path, (json.dumps(reference, ensure_ascii=False, indent=2) + '\n').encode('utf8'))
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
    ledger = {'schema_version': '2.1.2', 'generated_at': datetime.now(timezone.utc).isoformat(),
              'branch': BRANCH, 'standard_sha256': STANDARD_SHA,
              'task_id': TASK, 'accepted_revision': 2,
              'fingerprint': verdict['fingerprint'], 'review_sha256': verdict['review_sha256'],
              'r1_complete_sha256': sha(r1 / 'COMPLETE.json'),
              'r2_complete_sha256': sha(r2 / 'COMPLETE.json'),
              'research_disposition': 'ACCEPTED_BOUNDED_PARTIAL_STATIC_RESEARCH_WITH_CENSUS_CORRECTION',
              'current_slice_fde_candidates': 62, 'selected_cumulative_candidates': 376,
              'remaining_nonselected_candidates': 135, 'project_delivery': REFERENCE,
              'files': paths, 'behavior_equivalence_proven': False,
              'all_45_so_complete': False, 'product_phase_pass': False, 'v4_opened': False}
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
