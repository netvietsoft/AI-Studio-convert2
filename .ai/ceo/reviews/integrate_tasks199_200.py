"""Stage exact CEO-accepted TASK_199/200 research on the owned branch."""

import json
import shutil
import sys
from datetime import datetime, timezone
from pathlib import Path

from integrate_tasks162_167 import BRANCH, ROOT, STANDARD_SHA, WORKTREE, git, git_blob_sha, safe_path, sha

sys.path.insert(0, str(ROOT / '.ai/ceo'))
from controller import Controller  # noqa: E402


TASKS = ('TASK_199', 'TASK_200')
LEDGER = 'RULES/REPORT/CEO_SO45_ORCHESTRATION/ACCEPTED_INTERNAL_FDE_RESEARCH_199_200_R1.json'


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or sha(ROOT / 'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt') != STANDARD_SHA:
        raise RuntimeError('END requested or canonical changed')
    lease = ctl.ceo_lease(ctl.read_json(ctl.registry))
    if git('branch', '--show-current').decode().strip() != BRANCH:
        raise RuntimeError('wrong owned branch')
    if not WORKTREE.resolve().is_relative_to(Path('F:/CONVERT_WORKTREES/ceo-so45-20261008').resolve()):
        raise RuntimeError('unexpected owned worktree')
    if git('diff', '--cached', '--name-only', '-z').strip(b'\0'):
        raise RuntimeError('index already staged')
    state, tasks = ctl.read_json(ROOT / '.ai/ceo/state.json'), ctl.tasks()
    paths, task_rows = {}, []

    def add(relative, expected=None):
        path = safe_path(ROOT, relative)
        if not path.is_file():
            raise RuntimeError('missing source: ' + relative)
        digest = sha(path)
        if expected is not None and digest != expected:
            raise RuntimeError('source hash changed: ' + relative)
        if relative in paths and paths[relative] != digest:
            raise RuntimeError('conflicting source: ' + relative)
        paths[relative] = digest

    for task in TASKS:
        if not ctl.accepted(task, state, tasks, required_revision=1):
            raise RuntimeError('current accepted fingerprint absent: ' + task)
        verdict = state['tasks'][task]['verdict']
        if verdict['disposition'] != 'ACCEPTED' or verdict['revision'] != 1:
            raise RuntimeError('wrong verdict: ' + task)
        folder = f'RULES/REPORT/{task}_REPORT_R1'
        report = safe_path(ROOT, folder)
        seal = json.loads((report / 'COMPLETE.json').read_text(encoding='utf8'))
        if (seal['task_id'], seal['revision'], seal['status'], seal['standard_sha256']) != (
                task, 1, 'COMPLETE', STANDARD_SHA):
            raise RuntimeError('wrong seal: ' + task)
        actual = {p.relative_to(report).as_posix() for p in report.rglob('*') if p.is_file()} - {
            'COMPLETE.json', 'PROGRESS.json', 'PROGRESS.md'}
        if actual != set(seal['files']):
            raise RuntimeError('report inventory changed: ' + task)
        for relative, expected in seal['files'].items():
            add(folder + '/' + relative, expected)
        for relative, expected in seal['code_files'].items():
            add(relative, expected)
        add(folder + '/COMPLETE.json')
        add(f'RULES/TASK/{task}_SO45_CODEX_INTERNAL_ACTIVE.md', seal['task_sha256'])
        add(f'.ai/ceo/reviews/{task}_internal_targets.json', seal['target_manifest_sha256'])
        add(verdict['review_file'], verdict['review_sha256'])
        add(f'.ai/ceo/reviews/rerun_task{task[-3:]}_ghidra.py')
        replay = safe_path(ROOT, f'.ai/ceo/reviews/{task}_CEO_REPLAY')
        for path in sorted(replay.rglob('*')):
            if path.is_file():
                add(path.relative_to(ROOT).as_posix())
        if task == 'TASK_199':
            for relative, expected in seal['scratch_files'].items():
                if '/ghidra_project/' not in relative:
                    add(relative, expected)
            receipt_rel = '.ai/ceo/reviews/TASK_199_R1_GHIDRA_PROJECT_ARCHIVE.json'
            archive_rel = '.ai/ceo/reviews/TASK_199_R1_GHIDRA_PROJECT.zip'
            receipt = json.loads(safe_path(ROOT, receipt_rel).read_text(encoding='utf8'))
            expected_project = {k: v for k, v in seal['scratch_files'].items() if '/ghidra_project/' in k}
            if (receipt['complete_sha256'] != sha(report / 'COMPLETE.json')
                    or receipt['project_files'] != expected_project or len(expected_project) != 9
                    or not receipt['roundtrip_verified']):
                raise RuntimeError('archive receipt mismatch')
            add(archive_rel, receipt['archive_sha256'])
            add(receipt_rel)
            add('.ai/ceo/reviews/archive_task199_project.py')
            add('.ai/ceo/reviews/prepare_publish_task199.py')
            project_delivery = 'byte-verified nine-file ZIP archive'
        else:
            for relative, expected in seal['scratch_project_files'].items():
                add(f'RESEARCH_WORK/TASK_200_R1/ghidra_project/{relative}', expected)
            add('.ai/ceo/reviews/prepare_publish_task200.py')
            project_delivery = 'nine plain byte-verified project files'
        task_rows.append({'task_id': task, 'revision': 1,
                          'fingerprint': verdict['fingerprint'],
                          'review_sha256': verdict['review_sha256'],
                          'complete_sha256': sha(report / 'COMPLETE.json'),
                          'research_disposition': 'ACCEPTED_BOUNDED_STATIC_RESEARCH',
                          'source_candidates': 60 if task == 'TASK_199' else 32,
                          'project_delivery': project_delivery,
                          'behavior_equivalence_proven': False, 'all_45_so_complete': False,
                          'product_phase_pass': False, 'v4_opened': False})
    add('.ai/ceo/reviews/integrate_tasks199_200.py')
    for relative, expected in paths.items():
        destination = safe_path(WORKTREE, relative)
        ctl.authorized(lease, destination)
        if destination.exists() and sha(destination) != expected:
            raise RuntimeError('destination differs: ' + relative)
        if git('ls-tree', 'HEAD', '--', relative).strip():
            raise RuntimeError('path already tracked in branch: ' + relative)
    ledger_path = safe_path(ROOT, LEDGER)
    ctl.authorized(lease, ledger_path)
    if ledger_path.exists():
        raise RuntimeError('ledger already exists')
    ledger = {'schema_version': '2.1.2', 'generated_at': datetime.now(timezone.utc).isoformat(),
              'branch': BRANCH, 'standard_sha256': STANDARD_SHA, 'tasks': task_rows,
              'files': paths,
              'limits': 'Research gate only; FDE candidates do not prove semantic functions or product Phase PASS/V4/P7'}
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
    additions = [f'/{relative} -text' for relative in sorted(paths) if f'/{relative} -text' not in lines]
    attributes.write_bytes(original + ('\n'.join(additions) + '\n').encode('utf8'))
    git('add', '--', '.gitattributes')
    ordered = sorted(paths)
    for start in range(0, len(ordered), 75):
        git('add', '--', *ordered[start:start+75])
    staged = {x for x in git('diff', '--cached', '--name-only', '-z').decode().split('\0') if x}
    if staged != set(paths) | {'.gitattributes'}:
        raise RuntimeError('unexpected staged paths')
    for relative in paths:
        row = git('ls-files', '--stage', '--', relative).decode().split()
        if len(row) < 2 or row[1] != git_blob_sha(safe_path(ROOT, relative)):
            raise RuntimeError('index blob mismatch: ' + relative)
    print(json.dumps({'status': 'STAGED_EXACT_BYTES', 'tasks': list(TASKS),
                      'paths': len(paths), 'ledger_sha256': sha(ledger_path),
                      'archive_sha256': paths['.ai/ceo/reviews/TASK_199_R1_GHIDRA_PROJECT.zip']}))


if __name__ == '__main__':
    main()
