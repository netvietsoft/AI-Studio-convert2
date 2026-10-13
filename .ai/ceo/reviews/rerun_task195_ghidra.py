"""Fresh CEO read-only Ghidra replay of all TASK_195 original/correction rows."""

import json
import shutil
import sys

from rerun_task183_184_ghidra import ROOT, WORKTREE, OUT, hashes, run, sha

sys.path.insert(0, str(ROOT / ".ai/ceo"))
from controller import Controller  # noqa: E402


SOURCE = ROOT / "RESEARCH_WORK/TASK_195_R1/ghidra_project"
DEST = WORKTREE / "review_task195_ghidra_project"
AREA = OUT / "TASK_195_CEO_REPLAY"
REPORT = ROOT / "RULES/REPORT/TASK_195_REPORT_R1"
SCRIPTS = ROOT / "scripts/task_195_codex_internal"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_195_R1"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"


def obj(path):
    return json.loads(path.read_text(encoding="utf8"))


def replay(ctl, lease, title, script, tsv, expected_folder, expected_count):
    area = AREA / title
    output = area / "raw"
    ctl.authorized(lease, output)
    result = run(ctl, lease, area, DEST, "Task160", "libPVGImageCodec.so",
                 SCRIPTS / script, [str(tsv), str(output)])
    expected = sorted(expected_folder.glob("*.json"))
    observed = sorted(output.glob("*.json"))
    if len(expected) != len(observed) or len(observed) != expected_count:
        raise RuntimeError("fresh replay row count differs: " + title)
    for old_path, fresh_path in zip(expected, observed):
        if old_path.name != fresh_path.name:
            raise RuntimeError("fresh replay row identity differs: " + title)
        old, fresh = obj(old_path), obj(fresh_path)
        if set(old) != set(fresh):
            raise RuntimeError("fresh replay keyset differs: " + old_path.name)
        for key, value in old.items():
            if key not in {"generated_at", "decompile_elapsed_ms"} and value != fresh[key]:
                raise RuntimeError(f"fresh replay row={old_path.name} field={key} differs")
    print(json.dumps({"task": 195, "stage": title, "rows": expected_count,
                      "seconds": round(result["elapsed_seconds"], 3)}), flush=True)
    return result["elapsed_seconds"]


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") != STANDARD_SHA:
        raise RuntimeError("END requested or canonical standard changed")
    lease = ctl.ceo_lease(ctl.read_json(ctl.registry))
    if DEST.exists() or AREA.exists():
        raise RuntimeError("CEO TASK_195 replay destination already exists")
    ctl.authorized(lease, DEST)
    ctl.authorized(lease, AREA)
    source_hashes = hashes(SOURCE)
    if len(source_hashes) != 9:
        raise RuntimeError("unexpected source project inventory")
    shutil.copytree(SOURCE, DEST)
    if hashes(DEST) != source_hashes:
        raise RuntimeError("project copy differs")
    AREA.mkdir()
    seconds = 0.0
    for batch in (1, 2):
        seconds += replay(ctl, lease, f"batch_{batch}", "ExtractInternal195.java",
                          SCRATCH / f"target_batch_{batch}.tsv", REPORT / f"ghidra_raw_batch{batch}", 32)
    seconds += replay(ctl, lease, "correction", "RepairMembership195.java",
                      SCRATCH / "correction_targets.tsv", REPORT / "ghidra_correction_raw", 11)
    seconds += replay(ctl, lease, "postrollback", "CheckOriginalMembership195.java",
                      SCRATCH / "correction_targets.tsv", REPORT / "ghidra_postrollback_raw", 11)
    if hashes(DEST) != source_hashes or hashes(SOURCE) != source_hashes:
        raise RuntimeError("read-only Ghidra replay changed project")
    summary = {"task_id": "TASK_195", "revision": 1, "result": "PASS",
               "fresh_original_rows": 64, "fresh_correction_rows": 11,
               "fresh_postrollback_rows": 11, "project_file_sha256": source_hashes,
               "replay_project_unchanged": True, "elapsed_seconds": seconds,
               "no_behavior_or_product_claim": True}
    target = AREA / "summary.json"
    ctl.authorized(lease, target)
    target.write_text(json.dumps(summary, ensure_ascii=False, indent=2) + "\n", encoding="utf8")
    print(json.dumps({"result": "PASS", "task": 195, "rows": 64,
                      "corrections": 11, "rollback_replays": 11,
                      "seconds": round(seconds, 3)}), flush=True)


if __name__ == "__main__":
    main()
