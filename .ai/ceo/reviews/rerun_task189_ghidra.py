"""CEO read-only Ghidra replay of TASK_189 original, transient, and postrollback claims."""
import json
import shutil
import sys

from rerun_task183_184_ghidra import ROOT, WORKTREE, OUT, hashes, run, sha

sys.path.insert(0, str(ROOT / ".ai/ceo"))
from controller import Controller  # noqa: E402

SOURCE = ROOT / "RESEARCH_WORK/TASK_189_R1/ghidra_project"
DEST = WORKTREE / "review_task189_ghidra_project"
AREA = OUT / "TASK_189_CEO_REPLAY"
REPORT = ROOT / "RULES/REPORT/TASK_189_REPORT_R1"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
CORRECTED = [167, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 187]
RAW_FIELDS = ("index", "elf_va", "database_va", "size_bytes", "ghidra_memory_sha256",
              "instruction_slots", "ghidra_instruction_count", "missing_analyzed_instruction_count",
              "ghidra_pcode_ops", "boundary_classification", "existing_exact_function_start",
              "existing_function_contains_nonstart", "temporary_function_created_and_rolled_back",
              "function_name", "function_start", "function_body_min", "function_body_max",
              "function_body_total_address_count", "extra_body_address_count", "extra_body_ranges",
              "fde_byte_membership_count", "fde_byte_membership_bits", "fde_byte_membership_transitions",
              "fde_missing_body_ranges", "other_function_byte_count", "c_like_nonempty",
              "decompile_error", "c_like_text", "instruction_pcode")


def json_rows(folder):
    return {json.loads(p.read_text(encoding="utf8"))["index"]: json.loads(p.read_text(encoding="utf8"))
            for p in folder.glob("*.json")}


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") != STANDARD_SHA:
        raise RuntimeError("END requested or canonical standard changed")
    lease = ctl.ceo_lease(ctl.read_json(ctl.registry))
    if DEST.exists() or AREA.exists():
        raise RuntimeError("CEO TASK_189 replay destination already exists")
    ctl.authorized(lease, DEST)
    ctl.authorized(lease, AREA)
    source_hashes = hashes(SOURCE)
    if len(source_hashes) != 9:
        raise RuntimeError("unexpected analyzed project inventory")
    shutil.copytree(SOURCE, DEST)
    if hashes(DEST) != source_hashes:
        raise RuntimeError("CEO project copy differs")
    AREA.mkdir()
    seconds = 0.0
    original_rows = {}
    for batch in (1, 2):
        area = AREA / f"batch_{batch}"
        output = area / "raw"
        ctl.authorized(lease, output)
        receipt = run(ctl, lease, area, DEST, "MTFilterHair143", "libMTFilterKernel.so",
                      ROOT / "scripts/task_189_codex_internal/ExtractInternal189.java",
                      [str(ROOT / f"RESEARCH_WORK/TASK_189_R1/target_batch_{batch}.tsv"), str(output)])
        old = json_rows(REPORT / f"ghidra_raw_batch{batch}")
        fresh = json_rows(output)
        if len(old) != len(fresh) or len(fresh) != 32 or set(old) != set(fresh):
            raise RuntimeError("original extraction row inventory differs")
        for index in sorted(old):
            for key in RAW_FIELDS:
                if old[index][key] != fresh[index][key]:
                    raise RuntimeError(f"batch={batch} row={index} field={key} differs")
        original_rows.update(fresh)
        seconds += receipt["elapsed_seconds"]
        print(json.dumps({"task": 189, "batch": batch, "rows": len(fresh),
                          "seconds": round(receipt["elapsed_seconds"], 3)}), flush=True)
    exact = sum(x["fde_byte_membership_count"] == x["size_bytes"] for x in original_rows.values())
    gaps = sorted(x["index"] for x in original_rows.values()
                  if x["fde_byte_membership_count"] != x["size_bytes"])
    if exact != 50 or gaps != CORRECTED:
        raise RuntimeError("original boundary census differs")
    corrected_area = AREA / "correction"
    corrected_out = corrected_area / "raw"
    ctl.authorized(lease, corrected_out)
    receipt = run(ctl, lease, corrected_area, DEST, "MTFilterHair143", "libMTFilterKernel.so",
                  ROOT / "scripts/task_189_codex_internal/RepairMembership189.java",
                  [str(ROOT / "RESEARCH_WORK/TASK_189_R1/correction_targets.tsv"), str(corrected_out)])
    corrected_old = json_rows(REPORT / "ghidra_correction_retry_raw")
    corrected_new = json_rows(corrected_out)
    if sorted(corrected_new) != CORRECTED or set(corrected_old) != set(corrected_new):
        raise RuntimeError("correction row inventory differs")
    for index in CORRECTED:
        old, new = corrected_old[index], corrected_new[index]
        for key in old:
            if key not in ("generated_at", "decompile_elapsed_ms", "same_session_function_metadata_restored"):
                if old[key] != new[key]:
                    raise RuntimeError(f"correction row={index} field={key} differs")
        if not (new["corrected_function_fde_membership_count"] == new["size_bytes"] and
                new["corrected_function_fde_membership_bits"] == "1" * new["size_bytes"] and
                new["memory_unchanged_after_rollback"] and new["c_like_nonempty"] and
                new["other_function_byte_count"] == 0 and not new["error"]):
            raise RuntimeError("fresh transient result incomplete")
    seconds += receipt["elapsed_seconds"]
    post_area = AREA / "postrollback"
    post_out = post_area / "raw"
    ctl.authorized(lease, post_out)
    receipt = run(ctl, lease, post_area, DEST, "MTFilterHair143", "libMTFilterKernel.so",
                  ROOT / "scripts/task_189_codex_internal/CheckOriginalMembership189.java",
                  [str(ROOT / "RESEARCH_WORK/TASK_189_R1/correction_targets.tsv"), str(post_out)])
    post_old = json_rows(REPORT / "ghidra_postrollback_raw")
    post_new = json_rows(post_out)
    if sorted(post_new) != CORRECTED or set(post_old) != set(post_new):
        raise RuntimeError("fresh postrollback row inventory differs")
    for index in CORRECTED:
        if post_new[index] != post_old[index]:
            raise RuntimeError(f"fresh postrollback row differs index={index}")
        if post_new[index]["body_bits"] != original_rows[index]["fde_byte_membership_bits"]:
            raise RuntimeError(f"original metadata not restored index={index}")
    seconds += receipt["elapsed_seconds"]
    if hashes(DEST) != source_hashes or hashes(SOURCE) != source_hashes:
        raise RuntimeError("CEO read-only replay changed analyzed project")
    summary = {"task_id": "TASK_189", "revision": 1, "fresh_original_rows": 64,
               "fresh_original_full_fde_bodies": exact, "fresh_transient_full_fde_rows": 14,
               "fresh_separate_session_original_metadata_and_memory_rows": 14,
               "source_project_file_sha256": source_hashes,
               "ceo_project_unchanged": True, "elapsed_seconds": seconds,
               "no_behavior_or_product_claim": True}
    path = AREA / "summary.json"
    ctl.authorized(lease, path)
    path.write_text(json.dumps(summary, ensure_ascii=False, indent=2) + "\n", encoding="utf8")
    print(json.dumps({"result": "PASS", "task": 189, "rows": 64,
                      "original_exact": exact, "correction": 14, "fresh_postrollback": 14,
                      "seconds": round(seconds, 3)}), flush=True)


if __name__ == "__main__":
    main()
