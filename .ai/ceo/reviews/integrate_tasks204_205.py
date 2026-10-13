"""Stage accepted TASK_204/205 R1 raw evidence and R2 coverage overlays exactly."""

import json
import shutil
import sys
from datetime import datetime, timezone
from pathlib import Path

from integrate_tasks162_167 import BRANCH, ROOT, STANDARD_SHA, WORKTREE, git, git_blob_sha, safe_path, sha

sys.path.insert(0, str(ROOT / '.ai/ceo'))
from controller import Controller  # noqa: E402
from prepare_publish_tasks189_190 import atomic_file  # noqa: E402


SPECS = {
    'TASK_204': {
        'source': 'lib-core-graphics/src/main/jniLibs/arm64-v8a/libMTFilterKernel.so',
        'prior_ref': '.ai/ceo/reviews/TASK_201_R1_GHIDRA_PROJECT_REFERENCE.json',
        'delivery': 'tracked_prior_project',
        'prior_project': 'RESEARCH_WORK/TASK_197_R1/ghidra_project/',
        'expected_counts': (127, 10943, 10746, 197, 37532),
        'prior_review': '.ai/ceo/reviews/TASK_204-21d00b2a2cba642f907fc577b233fda1a8c89b8df4e239dd5e9ed5e99c590d4b.md',
        'publish_r2': '.ai/ceo/reviews/publish_task204_r2.py',
    },
    'TASK_205': {
        'source': 'lib-core-graphics/src/main/jniLibs/arm64-v8a/libPVGImageCodec.so',
        'prior_ref': '.ai/ceo/reviews/TASK_202_R1_GHIDRA_PROJECT_REFERENCE.json',
        'delivery': 'prior_archive',
        'prior_archive': '.ai/ceo/reviews/TASK_199_R1_GHIDRA_PROJECT.zip',
        'expected_counts': (126, 6246, 6240, 6, 25604),
        'prior_review': '.ai/ceo/reviews/TASK_205-61976a1abb5c257fa3e159a8f0ee85bfc0d3182533bc85e509e5aa1389788cdf.md',
        'publish_r2': '.ai/ceo/reviews/publish_task205_r2.py',
    },
}


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
    paths = {}
    prepared = {}

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

    for task, spec in SPECS.items():
        if not ctl.accepted(task, state, tasks, required_revision=2):
            raise RuntimeError('current accepted R2 fingerprint absent: ' + task)
        verdict = state['tasks'][task]['verdict']
        r1_folder = f'RULES/REPORT/{task}_REPORT_R1'
        r2_folder = f'RULES/REPORT/{task}_REPORT_R2'
        r1 = safe_path(ROOT, r1_folder)
        r2 = safe_path(ROOT, r2_folder)
        seal1 = json.loads((r1 / 'COMPLETE.json').read_text(encoding='utf8'))
        seal2 = json.loads((r2 / 'COMPLETE.json').read_text(encoding='utf8'))
        if (seal1['task_id'], seal1['revision'], seal1['status'], seal1['standard_sha256']) != (task, 1, 'COMPLETE', STANDARD_SHA):
            raise RuntimeError('wrong R1 seal: ' + task)
        if (seal2['task_id'], seal2['revision'], seal2['status'], seal2['standard_sha256']) != (task, 2, 'COMPLETE', STANDARD_SHA):
            raise RuntimeError('wrong R2 seal: ' + task)
        if seal2['r1_complete_sha256'] != sha(r1 / 'COMPLETE.json'):
            raise RuntimeError('R2 does not pin R1: ' + task)
        expected = spec['expected_counts']
        if task == 'TASK_204':
            actual_counts = (seal2['original_fde_candidate_bodies_verified'], seal2['instruction_listings'],
                             seal2['nonempty_pcode_instruction_positions'], seal2['empty_pcode_instruction_positions'],
                             seal2['pcode_operations'])
        else:
            actual_counts = (seal2['candidate_count'], seal2['effective_ghidra_instruction_listings'],
                             seal2['effective_ghidra_positions_with_nonempty_pcode'],
                             seal2['effective_ghidra_positions_with_empty_pcode'],
                             seal2['effective_ghidra_pcode_operations'])
        if actual_counts != expected:
            raise RuntimeError('R2 critical counts changed: ' + task)
        source = safe_path(ROOT, spec['source'])
        if sha(source) != seal1['original_so_sha256'] or sha(source) != seal2['original_so_sha256']:
            raise RuntimeError('pinned source changed: ' + task)
        source_tree = git('ls-tree', 'HEAD', '--', spec['source']).decode().split()
        if len(source_tree) < 3 or source_tree[2] != git_blob_sha(source):
            raise RuntimeError('pinned source not in owned branch: ' + task)
        for folder, seal in ((r1_folder, seal1), (r2_folder, seal2)):
            directory = safe_path(ROOT, folder)
            actual = {p.relative_to(directory).as_posix() for p in directory.rglob('*') if p.is_file()} - {
                'COMPLETE.json', 'PROGRESS.json', 'PROGRESS.md'}
            if actual != set(seal['files']):
                raise RuntimeError('report inventory changed: ' + folder)
            for relative, digest in seal['files'].items():
                add(folder + '/' + relative, digest)
            for relative, digest in seal['code_files'].items():
                add(relative, digest)
            add(folder + '/COMPLETE.json')
        archive = f'.ai/ceo/reviews/{task}_R1_TASK_ARCHIVE_{seal1["task_sha256"]}.md'
        add(archive, seal1['task_sha256'])
        add(f'RULES/TASK/{task}_SO45_CODEX_INTERNAL_ACTIVE.md', seal2['task_sha256'])
        add(f'.ai/ceo/reviews/{task}_internal_targets.json', seal1['target_manifest_sha256'])
        add(spec['prior_review'])
        add(verdict['review_file'], verdict['review_sha256'])
        add(spec['publish_r2'])
        project = {relative.split('/ghidra_project/', 1)[1]: digest
                   for relative, digest in seal1['scratch_files'].items()
                   if '/ghidra_project/' in relative}
        prior_ref = json.loads(safe_path(ROOT, spec['prior_ref']).read_text(encoding='utf8'))
        if len(project) != 9 or project != prior_ref['project_files']:
            raise RuntimeError('project differs from prior accepted reference: ' + task)
        tree_ref = git('ls-tree', 'HEAD', '--', spec['prior_ref']).decode().split()
        if len(tree_ref) < 3 or tree_ref[2] != git_blob_sha(safe_path(ROOT, spec['prior_ref'])):
            raise RuntimeError('prior accepted project reference missing: ' + task)
        if spec['delivery'] == 'tracked_prior_project':
            for suffix, digest in project.items():
                prior = spec['prior_project'] + suffix
                original = safe_path(ROOT, prior)
                tree = git('ls-tree', 'HEAD', '--', prior).decode().split()
                if sha(original) != digest or len(tree) < 3 or tree[2] != git_blob_sha(original):
                    raise RuntimeError('prior project branch blob differs: ' + prior)
        else:
            archive_path = safe_path(ROOT, spec['prior_archive'])
            tree = git('ls-tree', 'HEAD', '--', spec['prior_archive']).decode().split()
            if sha(archive_path) != prior_ref['archive_sha256'] or len(tree) < 3 or tree[2] != git_blob_sha(archive_path):
                raise RuntimeError('prior project archive differs: ' + task)
        for relative, digest in seal1['scratch_files'].items():
            if '/ghidra_project/' not in relative:
                add(relative, digest)
        reference_name = f'.ai/ceo/reviews/{task}_R1_GHIDRA_PROJECT_REFERENCE.json'
        reference_path = safe_path(ROOT, reference_name)
        ctl.authorized(lease, reference_path)
        if reference_path.exists():
            raise RuntimeError('current project reference already exists: ' + task)
        reference = {
            'schema_version': '2.1.2', 'task_id': task, 'revision': 1,
            'generated_at': datetime.now(timezone.utc).isoformat(),
            'r1_complete_sha256': sha(r1 / 'COMPLETE.json'),
            'r2_complete_sha256': sha(r2 / 'COMPLETE.json'),
            'accepted_r2_review_sha256': verdict['review_sha256'],
            'project_files': project, 'delivery': spec['delivery'],
            'prior_accepted_reference': spec['prior_ref'],
            'prior_accepted_reference_sha256': sha(safe_path(ROOT, spec['prior_ref'])),
            'byte_identity_verified': True,
        }
        atomic_file(reference_path, (json.dumps(reference, ensure_ascii=False, indent=2) + '\n').encode('utf8'))
        add(reference_name)
        prepared[task] = (seal1, seal2, verdict, spec, reference_name)

    add('.ai/ceo/reviews/integrate_tasks204_205.py')
    for relative, digest in paths.items():
        destination = safe_path(WORKTREE, relative)
        ctl.authorized(lease, destination)
        if destination.exists() and sha(destination) != digest:
            raise RuntimeError('destination differs: ' + relative)
        if git('ls-tree', 'HEAD', '--', relative).strip():
            raise RuntimeError('path already tracked: ' + relative)
    ledger_name = 'RULES/REPORT/CEO_SO45_ORCHESTRATION/ACCEPTED_INTERNAL_FDE_RESEARCH_204_205_R1_R2.json'
    ledger_path = safe_path(ROOT, ledger_name)
    ctl.authorized(lease, ledger_path)
    if ledger_path.exists():
        raise RuntimeError('ledger already exists')
    ledger = {
        'schema_version': '2.1.2', 'generated_at': datetime.now(timezone.utc).isoformat(),
        'branch': BRANCH, 'standard_sha256': STANDARD_SHA,
        'research_disposition': 'ACCEPTED_BOUNDED_PARTIAL_STATIC_FDE_WITH_REPORT_CORRECTION',
        'tasks': {task: {
            'accepted_revision': 2, 'fingerprint': verdict['fingerprint'],
            'review_sha256': verdict['review_sha256'],
            'r1_complete_sha256': sha(safe_path(ROOT, f'RULES/REPORT/{task}_REPORT_R1/COMPLETE.json')),
            'r2_complete_sha256': sha(safe_path(ROOT, f'RULES/REPORT/{task}_REPORT_R2/COMPLETE.json')),
            'source_sha256': seal2['original_so_sha256'],
            'project_delivery': reference_name,
            'critical_counts': spec['expected_counts'],
        } for task, (seal1, seal2, verdict, spec, reference_name) in prepared.items()},
        'files': paths,
        'behavior_equivalence_proven': False, 'all_45_so_complete': False,
        'product_phase_pass': False, 'v4_opened': False,
    }
    atomic_file(ledger_path, (json.dumps(ledger, ensure_ascii=False, indent=2) + '\n').encode('utf8'))
    add(ledger_name)
    for relative, digest in paths.items():
        destination = safe_path(WORKTREE, relative)
        destination.parent.mkdir(parents=True, exist_ok=True)
        if not destination.exists():
            shutil.copyfile(safe_path(ROOT, relative), destination)
        if sha(destination) != digest:
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
    print(json.dumps({'status': 'STAGED_EXACT_BYTES', 'tasks': sorted(prepared),
                      'paths': len(paths), 'ledger_sha256': sha(ledger_path)}))


if __name__ == '__main__':
    main()
