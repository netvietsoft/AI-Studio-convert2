"""CEO read-only Ghidra replay of original and transient TASK_187 body claims."""
import json
import shutil
import sys
from pathlib import Path

from rerun_task183_184_ghidra import ROOT, WORKTREE, OUT, hashes, run, sha

sys.path.insert(0, str(ROOT / ".ai/ceo"))
from controller import Controller  # noqa: E402

SOURCE = ROOT / "RESEARCH_WORK/TASK_187_R1/ghidra_project"
DEST = WORKTREE / "review_task187_ghidra_project"
AREA = OUT / "TASK_187_CEO_REPLAY"
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
        raise RuntimeError("unexpected Ghidra project inventory")
    shutil.copytree(SOURCE, DEST)
    if hashes(DEST) != source_hashes:
        raise RuntimeError("CEO project copy differs")
    AREA.mkdir()
    target = AREA / "all_targets.tsv"
    ctl.authorized(lease, target)
    target.write_bytes(b"".join((ROOT / f"RESEARCH_WORK/TASK_187_R1/target_batch_{number}.tsv").read_bytes()
                                for number in (1, 2)))
    output = AREA / "body_ranges.ndjson"
    ctl.authorized(lease, output)
    original = run(ctl, lease, AREA / "original", DEST, "MTFilterHair143", "libMTFilterKernel.so",
                   OUT / "ReviewBodyRanges.java", [str(target), str(output)])
    body_rows = [json.loads(line) for line in output.read_text(encoding="utf8").splitlines() if line]
    if len(body_rows) != 128:
        raise RuntimeError("original replay row count differs")
    nonexact = [row["index"] for row in body_rows if not row["body_equals_fde"]]
    if nonexact != [18, 23, 30, 43, 85, 128]:
        raise RuntimeError("original membership discrepancy: " + str(nonexact))
    corrections = AREA / "correction" / "results"
    ctl.authorized(lease, corrections)
    corrected = run(ctl, lease, AREA / "correction", DEST, "MTFilterHair143", "libMTFilterKernel.so",
                    ROOT / "scripts/task_187_codex_internal/RepairMembership187.java",
                    [str(ROOT / "RESEARCH_WORK/TASK_187_R1/correction_targets.tsv"), str(corrections)])
    corrected_rows = [json.loads(p.read_text(encoding="utf8")) for p in sorted(corrections.glob("*.json"))]
    if len(corrected_rows) != 6 or [row["index"] for row in corrected_rows] != nonexact:
        raise RuntimeError("correction replay row count differs")
    for row in corrected_rows:
        if not (row["corrected_function_fde_membership_count"] == row["size_bytes"] and
                row["corrected_function_fde_membership_bits"] == "1" * row["size_bytes"] and
                row["memory_unchanged_after_rollback"] and row["c_like_nonempty"]):
            raise RuntimeError("correction replay body/rollback mismatch")
    if hashes(DEST) != source_hashes:
        raise RuntimeError("CEO read-only replay changed project")
    summary = {"task_id": "TASK_187", "revision": 2,
               "original_body_rows": len(body_rows), "original_exact": len(body_rows) - len(nonexact),
               "original_nonexact_indices": nonexact,
               "transient_corrections_reproduced": len(corrected_rows),
               "original_replay_seconds": original["elapsed_seconds"],
               "correction_replay_seconds": corrected["elapsed_seconds"],
               "source_project_file_sha256": source_hashes,
               "ceo_project_unchanged": True,
               "no_behavior_or_product_claim": True}
    summary_path = AREA / "summary.json"
    ctl.authorized(lease, summary_path)
    summary_path.write_text(json.dumps(summary, ensure_ascii=False, indent=2) + "\n", encoding="utf8")
    print(json.dumps({"result": "PASS", "original_exact": len(body_rows) - len(nonexact),
                      "original_nonexact": nonexact, "corrected": len(corrected_rows),
                      "seconds": round(original["elapsed_seconds"] + corrected["elapsed_seconds"], 3)}))


if __name__ == "__main__":
    main()
