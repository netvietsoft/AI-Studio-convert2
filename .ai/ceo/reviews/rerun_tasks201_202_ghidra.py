"""Fresh CEO read-only replay of sealed TASK_201/202 Ghidra observations."""

import json
import shutil
import sys

from rerun_task183_184_ghidra import ROOT, WORKTREE, OUT, hashes, run, sha

sys.path.insert(0, str(ROOT / '.ai/ceo'))
from controller import Controller  # noqa: E402


STANDARD_SHA = '10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f'
SPECS = {
    201: ('MTFilterHair143', 'libMTFilterKernel.so', 7),
    202: ('Task160', 'libPVGImageCodec.so', 9),
}


def obj(path):
    return json.loads(path.read_text(encoding='utf8'))


def replay(ctl, lease, number, dest, area, project_name, program,
           script, tsv, expected_folder, expected_count):
    output = area / 'raw'
    ctl.authorized(lease, output)
    result = run(ctl, lease, area, dest, project_name, program,
                 script, [str(tsv), str(output)])
    expected = sorted(expected_folder.glob('*.json'))
    observed = sorted(output.glob('*.json'))
    if len(expected) != expected_count or len(observed) != expected_count:
        raise RuntimeError(f'TASK_{number} {area.name} count mismatch')
    for previous, current in zip(expected, observed):
        if previous.name != current.name:
            raise RuntimeError(f'TASK_{number} row identity mismatch')
        old, fresh = obj(previous), obj(current)
        if set(old) != set(fresh):
            raise RuntimeError(f'TASK_{number} keyset mismatch {previous.name}')
        for key, value in old.items():
            if key not in {'generated_at', 'decompile_elapsed_ms'} and value != fresh[key]:
                raise RuntimeError(f'TASK_{number} {previous.name} field {key} mismatch')
    print(json.dumps({'task_id': f'TASK_{number}', 'stage': area.name,
                      'rows': expected_count,
                      'seconds': round(result['elapsed_seconds'], 3)}), flush=True)
    return result['elapsed_seconds']


def one(ctl, lease, number):
    project_name, program, correction_count = SPECS[number]
    source = ROOT / f'RESEARCH_WORK/TASK_{number}_R1/ghidra_project'
    dest = WORKTREE / f'review_task{number}_ghidra_project'
    area = OUT / f'TASK_{number}_CEO_REPLAY'
    report = ROOT / f'RULES/REPORT/TASK_{number}_REPORT_R1'
    scripts = ROOT / f'scripts/task_{number}_codex_internal'
    scratch = ROOT / f'RESEARCH_WORK/TASK_{number}_R1'
    if dest.exists() or area.exists():
        raise RuntimeError(f'TASK_{number} CEO replay already exists')
    ctl.authorized(lease, dest)
    ctl.authorized(lease, area)
    source_hashes = hashes(source)
    if len(source_hashes) != 9:
        raise RuntimeError(f'TASK_{number} project has {len(source_hashes)} files')
    shutil.copytree(source, dest)
    if hashes(dest) != source_hashes:
        raise RuntimeError(f'TASK_{number} project copy differs')
    area.mkdir()
    stages = [
        (f'batch_{batch}', f'ExtractInternal{number}.java',
         scratch / f'target_batch_{batch}.tsv',
         report / f'ghidra_raw_batch{batch}', 31)
        for batch in (1, 2)
    ]
    stages.extend([
        ('correction', f'RepairMembership{number}.java',
         scratch / 'correction_targets.tsv',
         report / 'ghidra_correction_raw', correction_count),
        ('postrollback', f'CheckOriginalMembership{number}.java',
         scratch / 'correction_targets.tsv',
         report / 'ghidra_postrollback_raw', correction_count),
    ])
    seconds = 0.0
    for title, script, tsv, expected_folder, expected_count in stages:
        seconds += replay(ctl, lease, number, dest, area / title, project_name, program,
                          scripts / script, tsv, expected_folder, expected_count)
    if hashes(dest) != source_hashes or hashes(source) != source_hashes:
        raise RuntimeError(f'TASK_{number} replay mutated Ghidra project')
    summary = {'task_id': f'TASK_{number}', 'revision': 1, 'result': 'PASS',
               'fresh_original_rows': 62,
               'fresh_correction_rows': correction_count,
               'fresh_postrollback_rows': correction_count,
               'project_file_sha256': source_hashes,
               'replay_project_unchanged': True,
               'elapsed_seconds': seconds,
               'no_behavior_or_product_claim': True}
    target = area / 'summary.json'
    ctl.authorized(lease, target)
    target.write_text(json.dumps(summary, ensure_ascii=False, indent=2) + '\n',
                      encoding='utf8')
    print(json.dumps({'task_id': f'TASK_{number}', 'result': 'PASS',
                      'seconds': round(seconds, 3)}), flush=True)


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or sha(ROOT / 'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt') != STANDARD_SHA:
        raise RuntimeError('END requested or canonical changed')
    lease = ctl.ceo_lease(ctl.read_json(ctl.registry))
    for number in (201, 202):
        one(ctl, lease, number)


if __name__ == '__main__':
    main()
