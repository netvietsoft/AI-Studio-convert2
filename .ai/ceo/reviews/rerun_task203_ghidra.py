"""Fresh read-only CEO replay of two oversized PVG FDE observations."""

import json
import shutil
import sys

from rerun_task183_184_ghidra import ROOT, WORKTREE, OUT, hashes, run, sha

sys.path.insert(0, str(ROOT / '.ai/ceo'))
from controller import Controller  # noqa: E402


STANDARD_SHA = '10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f'
SOURCE = ROOT / 'RESEARCH_WORK/TASK_203_R1/ghidra_project'
DEST = WORKTREE / 'review_task203_ghidra_project'
AREA = OUT / 'TASK_203_CEO_REPLAY'
REPORT = ROOT / 'RULES/REPORT/TASK_203_REPORT_R1'
SCRIPT = ROOT / 'scripts/task_203_codex_internal/ExportInternal203.java'


def rows(path):
    return [json.loads(line) for line in path.read_text(encoding='utf8').splitlines() if line.strip()]


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or sha(ROOT / 'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt') != STANDARD_SHA:
        raise RuntimeError('END requested or canonical changed')
    lease = ctl.ceo_lease(ctl.read_json(ctl.registry))
    if DEST.exists() or AREA.exists():
        raise RuntimeError('TASK_203 CEO replay already exists')
    ctl.authorized(lease, DEST)
    ctl.authorized(lease, AREA)
    project_hashes = hashes(SOURCE)
    if len(project_hashes) != 9:
        raise RuntimeError('TASK_203 project inventory differs')
    shutil.copytree(SOURCE, DEST)
    if hashes(DEST) != project_hashes:
        raise RuntimeError('TASK_203 project copy mismatch')
    AREA.mkdir()
    seconds = 0.0
    for chunk in (0, 1):
        title = f'chunk_{chunk:02d}'
        prior = REPORT / title
        target = AREA / title / 'ghidra_raw.ndjson'
        ctl.authorized(lease, target)
        result = run(ctl, lease, AREA / title, DEST, 'PVGColor168',
                     'libPVGColorFunctions.so', SCRIPT,
                     [str(prior / 'targets.tsv'), str(target)])
        seconds += result['elapsed_seconds']
        old_rows = rows(prior / 'ghidra_raw.ndjson')
        fresh_rows = rows(target)
        if len(old_rows) != 1 or len(fresh_rows) != 1:
            raise RuntimeError(f'{title} missing oversized row')
        old, fresh = old_rows[0], fresh_rows[0]
        if set(old) != set(fresh):
            raise RuntimeError(f'{title} row keyset differs')
        for key, value in old.items():
            if key != 'elapsed_ms' and value != fresh[key]:
                raise RuntimeError(f'{title} row field {key} differs')
        print(json.dumps({'task_id': 'TASK_203', 'stage': title,
                          'rows': 1, 'seconds': round(result['elapsed_seconds'], 3)}), flush=True)
    if hashes(DEST) != project_hashes or hashes(SOURCE) != project_hashes:
        raise RuntimeError('TASK_203 read-only replay mutated project')
    summary = {'task_id': 'TASK_203', 'revision': 1, 'result': 'PASS',
               'fresh_rows': 2, 'project_file_sha256': project_hashes,
               'replay_project_unchanged': True,
               'elapsed_seconds': seconds,
               'no_full_function_or_product_claim': True}
    path = AREA / 'summary.json'
    ctl.authorized(lease, path)
    path.write_text(json.dumps(summary, ensure_ascii=False, indent=2) + '\n', encoding='utf8')
    print(json.dumps({'task_id': 'TASK_203', 'result': 'PASS',
                      'seconds': round(seconds, 3)}), flush=True)


if __name__ == '__main__':
    main()
