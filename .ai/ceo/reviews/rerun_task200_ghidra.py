"""Fresh CEO read-only Ghidra replay of all TASK_200 candidate rows."""

import json
import shutil
import sys

from rerun_task183_184_ghidra import ROOT, WORKTREE, OUT, hashes, run, sha

sys.path.insert(0, str(ROOT / '.ai/ceo'))
from controller import Controller  # noqa: E402


SOURCE = ROOT / 'RESEARCH_WORK/TASK_200_R1/ghidra_project'
DEST = WORKTREE / 'review_task200_ghidra_project'
AREA = OUT / 'TASK_200_CEO_REPLAY'
REPORT = ROOT / 'RULES/REPORT/TASK_200_REPORT_R1'
STANDARD_SHA = '10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f'


def rows(path):
    return [json.loads(line) for line in path.read_text(encoding='utf8').splitlines() if line]


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or sha(ROOT / 'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt') != STANDARD_SHA:
        raise RuntimeError('END requested or canonical standard changed')
    lease = ctl.ceo_lease(ctl.read_json(ctl.registry))
    if DEST.exists() or AREA.exists():
        raise RuntimeError('CEO TASK_200 replay destination already exists')
    ctl.authorized(lease, DEST)
    ctl.authorized(lease, AREA)
    source_hashes = hashes(SOURCE)
    if len(source_hashes) != 9:
        raise RuntimeError('unexpected source project inventory')
    shutil.copytree(SOURCE, DEST)
    if hashes(DEST) != source_hashes:
        raise RuntimeError('project copy differs')
    AREA.mkdir()
    count = exact = 0
    seconds = 0.0
    for chunk in range(2):
        source_folder = REPORT / f'chunk_{chunk:02d}'
        area = AREA / f'chunk_{chunk:02d}'
        output = area / 'ghidra_raw.ndjson'
        ctl.authorized(lease, output)
        result = run(ctl, lease, area, DEST, 'PVGColor168', 'libPVGColorFunctions.so',
                     ROOT / 'scripts/task_200_codex_internal/ExportInternal200.java',
                     [str(source_folder / 'targets.tsv'), str(output)])
        expected, fresh = rows(source_folder / 'ghidra_raw.ndjson'), rows(output)
        if len(expected) != 16 or len(fresh) != 16:
            raise RuntimeError(f'chunk {chunk} row count differs')
        for old, new in zip(expected, fresh):
            if set(old) != set(new):
                raise RuntimeError(f'chunk={chunk} row keyset differs')
            for key, value in old.items():
                if key != 'elapsed_ms' and value != new.get(key):
                    raise RuntimeError(f'chunk={chunk} row={old["index"]} field={key} differs')
            exact += new['boundary_classification'] == 'GHIDRA_BODY_EQUALS_FDE_RANGE'
        count += len(fresh)
        seconds += result['elapsed_seconds']
        print(json.dumps({'task': 200, 'chunk': chunk, 'rows': len(fresh),
                          'seconds': round(result['elapsed_seconds'], 3)}), flush=True)
    if count != 32 or exact != 32:
        raise RuntimeError('fresh original evidence count differs')
    if hashes(DEST) != source_hashes or hashes(SOURCE) != source_hashes:
        raise RuntimeError('read-only replay changed project')
    summary = {'task_id': 'TASK_200', 'revision': 1, 'fresh_original_rows': count,
               'fresh_original_full_fde_bodies': exact,
               'source_project_file_sha256': source_hashes,
               'ceo_project_unchanged': True, 'elapsed_seconds': seconds,
               'no_behavior_or_product_claim': True}
    output = AREA / 'summary.json'
    ctl.authorized(lease, output)
    output.write_text(json.dumps(summary, ensure_ascii=False, indent=2) + '\n', encoding='utf8')
    print(json.dumps({'result': 'PASS', 'task': 200, 'rows': count,
                      'original_exact': exact, 'seconds': round(seconds, 3)}), flush=True)


if __name__ == '__main__':
    main()
