"""CEO read-only Ghidra replay of all TASK_186 R2 body boundaries."""
import json
import shutil
import sys
from pathlib import Path

from rerun_task183_184_ghidra import ROOT, WORKTREE, OUT, hashes, run, sha

sys.path.insert(0, str(ROOT / ".ai/ceo"))
from controller import Controller  # noqa: E402

SOURCE = ROOT / "RESEARCH_WORK/TASK_186_R1/ghidra_project"
DEST = WORKTREE / "review_task186_ghidra_project"
AREA = OUT / "TASK_186_CEO_REPLAY"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"


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
    if len(source_hashes) != 9:
        raise RuntimeError("unexpected project inventory")
    shutil.copytree(SOURCE, DEST)
    if hashes(DEST) != source_hashes:
        raise RuntimeError("copied project differs")
    AREA.mkdir()
    tsv = AREA / "all_targets.tsv"
    ctl.authorized(lease, tsv)
    tsv.write_bytes(b"".join((ROOT / f"RULES/REPORT/TASK_186_REPORT_R1/{chunk}/targets.tsv").read_bytes()
                             for chunk in ("chunk_00_retry1", "chunk_01", "chunk_02", "chunk_03")))
    output = AREA / "body_ranges.ndjson"
    ctl.authorized(lease, output)
    result = run(ctl, lease, AREA / "body_replay", DEST, "PVGColor168", "libPVGColorFunctions.so",
                 OUT / "ReviewBodyRanges.java", [str(tsv), str(output)])
    rows = [json.loads(line) for line in output.read_text(encoding="utf8").splitlines() if line]
    if len(rows) != 128 or [row["index"] for row in rows] != list(range(1, 129)):
        raise RuntimeError("replay rows differ")
    nonexact = [row["index"] for row in rows if not row["body_equals_fde"]]
    if nonexact:
        raise RuntimeError("body replay not exact: " + str(nonexact))
    if hashes(DEST) != source_hashes:
        raise RuntimeError("read-only replay changed project")
    summary = {"task_id": "TASK_186", "revision": 2, "original_body_rows": len(rows),
               "original_exact": len(rows), "replay_seconds": result["elapsed_seconds"],
               "source_project_file_sha256": source_hashes, "ceo_project_unchanged": True,
               "no_behavior_or_product_claim": True}
    path = AREA / "summary.json"
    ctl.authorized(lease, path)
    path.write_text(json.dumps(summary, ensure_ascii=False, indent=2) + "\n", encoding="utf8")
    print(json.dumps({"result": "PASS", "task_id": "TASK_186", "original_exact": len(rows),
                      "seconds": round(result["elapsed_seconds"], 3)}))


if __name__ == "__main__":
    main()
