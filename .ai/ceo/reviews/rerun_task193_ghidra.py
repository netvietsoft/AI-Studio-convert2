"""Fresh read-only CEO Ghidra replay of TASK_193 original and transient evidence."""

import json
import shutil
import sys

from rerun_task183_184_ghidra import ROOT, WORKTREE, OUT, hashes, run, sha

sys.path.insert(0, str(ROOT / ".ai/ceo"))
from controller import Controller  # noqa: E402


SOURCE = ROOT / "RESEARCH_WORK/TASK_193_R1/ghidra_project"
DEST = WORKTREE / "review_task193_ghidra_project_retry"
AREA = OUT / "TASK_193_CEO_REPLAY_RETRY"
REPORT = ROOT / "RULES/REPORT/TASK_193_REPORT_R1"
SCRIPTS = ROOT / "scripts/task_193_codex_internal"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_193_R1"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"


def obj(path):
    return json.loads(path.read_text(encoding="utf8"))


def compare(source, fresh, volatile):
    old, new = obj(source), obj(fresh)
    assert set(old) == set(new), (source, "keys")
    for key, value in old.items():
        if key not in volatile and value != new[key]:
            raise RuntimeError(f"Fresh Ghidra differs {source.name} field={key}")


def replay(ctl, lease, title, script, tsv, expected_folder, expected_count):
    area = AREA / title
    output = area / "raw"
    ctl.authorized(lease, output)
    result = run(ctl, lease, area, DEST, "MTFilterHair143", "libMTFilterKernel.so",
                 SCRIPTS / script, [str(tsv), str(output)])
    expected = sorted(expected_folder.glob("*.json"))
    observed = sorted(output.glob("*.json"))
    assert len(expected) == len(observed) == expected_count
    for old, fresh in zip(expected, observed):
        assert old.name == fresh.name
        compare(old, fresh, {"generated_at", "decompile_elapsed_ms"})
    print(json.dumps({"task": 193, "stage": title, "rows": expected_count,
                      "seconds": round(result["elapsed_seconds"], 3)}), flush=True)
    return result["elapsed_seconds"]


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") != STANDARD_SHA:
        raise RuntimeError("END requested or canonical standard changed")
    lease = ctl.ceo_lease(ctl.read_json(ctl.registry))
    if DEST.exists() or AREA.exists():
        raise RuntimeError("CEO TASK_193 replay destination already exists")
    ctl.authorized(lease, DEST)
    ctl.authorized(lease, AREA)
    source_hashes = hashes(SOURCE)
    assert len(source_hashes) == 9
    shutil.copytree(SOURCE, DEST)
    assert hashes(DEST) == source_hashes
    AREA.mkdir()
    seconds = 0.0
    for batch in (1, 2):
        seconds += replay(ctl, lease, f"batch_{batch}", "ExtractInternal193.java",
                          SCRATCH / f"target_batch_{batch}.tsv",
                          REPORT / ("ghidra_raw_batch1" if batch == 1 else "ghidra_raw_batch2"), 30)
    seconds += replay(ctl, lease, "correction", "RepairMembership193.java",
                      SCRATCH / "correction_targets.tsv", REPORT / "ghidra_correction_raw", 3)
    seconds += replay(ctl, lease, "postrollback", "CheckOriginalMembership193.java",
                      SCRATCH / "correction_targets.tsv", REPORT / "ghidra_postrollback_raw", 3)
    assert hashes(DEST) == hashes(SOURCE) == source_hashes
    summary = {"task": "TASK_193", "revision": 1, "result": "PASS",
               "fresh_original_rows": 60, "fresh_correction_rows": 3,
               "fresh_postrollback_rows": 3, "project_file_sha256": source_hashes,
               "replay_project_unchanged": True, "elapsed_seconds": seconds,
               "no_behavior_or_product_claim": True}
    target = AREA / "summary.json"
    ctl.authorized(lease, target)
    target.write_text(json.dumps(summary, ensure_ascii=False, indent=2) + "\n", encoding="utf8")
    print(json.dumps({"result": "PASS", "task": 193, "rows": 60,
                      "corrections": 3, "rollback_replays": 3,
                      "seconds": round(seconds, 3)}), flush=True)


if __name__ == "__main__":
    main()
