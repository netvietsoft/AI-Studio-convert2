"""CEO independent Ghidra replay of TASK_188 original and transient FDE membership."""
import json
import shutil
import sys
from pathlib import Path

from rerun_task183_184_ghidra import ROOT, WORKTREE, OUT, hashes, run, sha

sys.path.insert(0, str(ROOT / ".ai/ceo"))
from controller import Controller  # noqa: E402

SOURCE = ROOT / "RESEARCH_WORK/TASK_188_R1/ghidra_project"
DEST = WORKTREE / "review_task188_ghidra_project"
AREA = OUT / "TASK_188_CEO_REPLAY"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
CORRECTED = [10, 15, 17, 18, 28, 30, 32, 35, 43, 52, 55, 56, 58, 59, 62, 69]
OVERLAP = [47, 57, 60]


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") != STANDARD_SHA:
        raise RuntimeError("END requested or canonical standard changed")
    lease = ctl.ceo_lease(ctl.read_json(ctl.registry))
    if DEST.exists() or AREA.exists():
        raise RuntimeError("CEO TASK_188 replay destination already exists")
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
    target.write_bytes(b"".join((ROOT / f"RESEARCH_WORK/TASK_188_R1/target_batch_{number}.tsv").read_bytes()
                                for number in (1, 2)))
    output = AREA / "body_membership.ndjson"
    ctl.authorized(lease, output)
    original = run(ctl, lease, AREA / "original", DEST, "SmallLib153", "libMTLReportTool.so",
                   OUT / "ReviewBoundary188.java", [str(target), str(output)])
    body_rows = [json.loads(line) for line in output.read_text(encoding="utf8").splitlines() if line]
    if len(body_rows) != 117:
        raise RuntimeError("original replay row count differs")
    expected = {}
    for batch in (1, 2):
        for path in (ROOT / f"RULES/REPORT/TASK_188_REPORT_R1/ghidra_raw_batch{batch}").glob("*.json"):
            row = json.loads(path.read_text(encoding="utf8"))
            expected[row["index"]] = row
    if len(expected) != 117:
        raise RuntimeError("worker raw original row count differs")
    nonexact = []
    overlap = []
    for row in body_rows:
        worker = expected[row["index"]]
        for key in ("fde_byte_membership_bits", "fde_byte_membership_count",
                    "function_body_total_address_count", "other_function_byte_count"):
            if row[key] != worker[key]:
                raise RuntimeError(f"original replay differs index={row['index']} key={key}")
        if not row["function_at_start"]:
            raise RuntimeError(f"function absent index={row['index']}")
        if row["fde_byte_membership_count"] != row["size_bytes"]:
            nonexact.append(row["index"])
        if row["other_function_byte_count"]:
            overlap.append(row["index"])
    if nonexact != sorted(CORRECTED + OVERLAP) or overlap != OVERLAP:
        raise RuntimeError("original boundary discrepancy: " + str((nonexact, overlap)))
    for index in OVERLAP:
        if expected[index]["other_function_byte_count"] != 4:
            raise RuntimeError("other-function overlap size differs")
    print(json.dumps({"task": 188, "stage": "original", "exact": 117-len(nonexact),
                      "nonexact": nonexact, "overlap": overlap,
                      "seconds": round(original["elapsed_seconds"], 3)}), flush=True)
    corrections = AREA / "correction" / "results"
    ctl.authorized(lease, corrections)
    corrected = run(ctl, lease, AREA / "correction", DEST, "SmallLib153", "libMTLReportTool.so",
                    ROOT / "scripts/task_188_codex_internal/RepairMembership188.java",
                    [str(ROOT / "RESEARCH_WORK/TASK_188_R1/correction_targets.tsv"), str(corrections)])
    corrected_rows = [json.loads(p.read_text(encoding="utf8")) for p in sorted(corrections.glob("*.json"))]
    if len(corrected_rows) != 16 or [row["index"] for row in corrected_rows] != CORRECTED:
        raise RuntimeError("correction replay row count differs")
    for row in corrected_rows:
        if not (row["corrected_function_fde_membership_count"] == row["size_bytes"] and
                row["corrected_function_fde_membership_bits"] == "1" * row["size_bytes"] and
                row["memory_unchanged_after_rollback"] and row["c_like_nonempty"] and
                row["temporary_old_function_removed"] and row["temporary_full_fde_function_created"] and
                row["other_function_byte_count"] == 0 and not row["error"]):
            raise RuntimeError("correction replay body/rollback mismatch")
    if hashes(DEST) != source_hashes or hashes(SOURCE) != source_hashes:
        raise RuntimeError("CEO read-only replay changed project")
    summary = {"task_id": "TASK_188", "revision": 1,
               "original_body_rows": len(body_rows), "original_exact": len(body_rows)-len(nonexact),
               "original_nonexact_indices": nonexact, "other_function_overlap_indices": overlap,
               "transient_corrections_reproduced": len(corrected_rows),
               "original_replay_seconds": original["elapsed_seconds"],
               "correction_replay_seconds": corrected["elapsed_seconds"],
               "source_project_file_sha256": source_hashes,
               "ceo_project_unchanged": True, "no_behavior_or_product_claim": True}
    path = AREA / "summary.json"
    ctl.authorized(lease, path)
    path.write_text(json.dumps(summary, ensure_ascii=False, indent=2) + "\n", encoding="utf8")
    print(json.dumps({"result": "PASS", "task": 188, "original_exact": 98,
                      "original_nonexact": nonexact, "corrected": len(corrected_rows),
                      "overlap": overlap,
                      "seconds": round(original["elapsed_seconds"] + corrected["elapsed_seconds"], 3)}), flush=True)


if __name__ == "__main__":
    main()
