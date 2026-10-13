"""Fresh read-only CEO Ghidra replay of TASK_192 original and transient evidence."""

import json
import shutil
import sys

from rerun_task183_184_ghidra import ROOT, WORKTREE, OUT, hashes, run, sha

sys.path.insert(0, str(ROOT / ".ai/ceo"))
from controller import Controller  # noqa: E402


SOURCE = ROOT / "RESEARCH_WORK/TASK_192_R1/ghidra_project"
DEST = WORKTREE / "review_task192_ghidra_project"
AREA = OUT / "TASK_192_CEO_REPLAY"
REPORT = ROOT / "RULES/REPORT/TASK_192_REPORT_R1"
SCRIPTS = ROOT / "scripts/task_192_codex_internal"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_192_R1"
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
    result = run(ctl, lease, area, DEST, "Task160", "libPVGImageCodec.so",
                 SCRIPTS / script, [str(tsv), str(output)])
    expected = sorted(expected_folder.glob("*.json"))
    observed = sorted(output.glob("*.json"))
    assert len(expected) == len(observed) == expected_count
    for old, fresh in zip(expected, observed):
        assert old.name == fresh.name
        compare(old, fresh, {"generated_at", "decompile_elapsed_ms"})
    print(json.dumps({"task": 192, "stage": title, "rows": expected_count,
                      "seconds": round(result["elapsed_seconds"], 3)}), flush=True)
    return result["elapsed_seconds"]


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") != STANDARD_SHA:
        raise RuntimeError("END requested or canonical standard changed")
    lease = ctl.ceo_lease(ctl.read_json(ctl.registry))
    if DEST.exists() or AREA.exists():
        raise RuntimeError("CEO replay destination already exists")
    ctl.authorized(lease, DEST)
    ctl.authorized(lease, AREA)
    source_hashes = hashes(SOURCE)
    assert len(source_hashes) == 9
    shutil.copytree(SOURCE, DEST)
    assert hashes(DEST) == source_hashes
    AREA.mkdir()
    seconds = 0.0
    for batch in (1, 2):
        seconds += replay(ctl, lease, f"batch_{batch}", "ExtractInternal192.java",
                          SCRATCH / f"target_batch_{batch}.tsv",
                          REPORT / ("ghidra_raw_batch1_retry" if batch == 1 else "ghidra_raw_batch2"), 32)
    seconds += replay(ctl, lease, "correction", "RepairMembership192.java",
                      SCRATCH / "correction_targets.tsv", REPORT / "ghidra_correction_raw", 4)
    seconds += replay(ctl, lease, "postrollback", "CheckOriginalMembership192.java",
                      SCRATCH / "correction_targets.tsv", REPORT / "ghidra_postrollback_raw", 4)
    assert hashes(DEST) == hashes(SOURCE) == source_hashes
    summary = {"task": "TASK_192", "revision": 1, "result": "PASS",
               "fresh_original_rows": 64, "fresh_correction_rows": 4,
               "fresh_postrollback_rows": 4, "project_file_sha256": source_hashes,
               "replay_project_unchanged": True, "elapsed_seconds": seconds,
               "no_behavior_or_product_claim": True}
    target = AREA / "summary.json"
    ctl.authorized(lease, target)
    target.write_text(json.dumps(summary, ensure_ascii=False, indent=2) + "\n", encoding="utf8")
    print(json.dumps({"result": "PASS", "task": 192, "rows": 64,
                      "corrections": 4, "rollback_replays": 4,
                      "seconds": round(seconds, 3)}), flush=True)


if __name__ == "__main__":
    main()
