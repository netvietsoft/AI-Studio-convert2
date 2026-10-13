"""Fresh CEO read-only Ghidra replay of all TASK_190 extraction and correction claims."""
import json
import shutil
import sys

from rerun_task183_184_ghidra import ROOT, WORKTREE, OUT, hashes, run, sha

sys.path.insert(0, str(ROOT / ".ai/ceo"))
from controller import Controller  # noqa: E402

SOURCE = ROOT / "RESEARCH_WORK/TASK_190_R1/ghidra_project"
DEST = WORKTREE / "review_task190_ghidra_project"
AREA = OUT / "TASK_190_CEO_REPLAY"
REPORT = ROOT / "RULES/REPORT/TASK_190_REPORT_R1"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
FIELDS = ("index", "elf_va", "database_va", "fde_size_bytes", "original_body_sha256",
          "copy_memory_body_sha256", "body_bytes_match", "instruction_slots",
          "instruction_count_observed", "pcode_instruction_count", "pcode_op_count",
          "function_metadata_created_in_owned_copy", "fde_start_inside_other_ghidra_function",
          "function_name", "function_entry", "function_min", "function_max",
          "function_body_address_count", "fde_member_bytes", "fde_missing_bytes",
          "extra_body_bytes", "boundary_classification", "fde_missing_ranges",
          "c_like_present", "c_like_sha256", "c_like_text", "failure", "instructions", "calls")


def rows(path):
    return [json.loads(line) for line in path.read_text(encoding="utf8").splitlines() if line]


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") != STANDARD_SHA:
        raise RuntimeError("END requested or canonical standard changed")
    lease = ctl.ceo_lease(ctl.read_json(ctl.registry))
    if DEST.exists() or AREA.exists():
        raise RuntimeError("CEO TASK_190 replay destination already exists")
    ctl.authorized(lease, DEST)
    ctl.authorized(lease, AREA)
    source_hashes = hashes(SOURCE)
    if len(source_hashes) != 9:
        raise RuntimeError("unexpected prior project inventory")
    shutil.copytree(SOURCE, DEST)
    if hashes(DEST) != source_hashes:
        raise RuntimeError("CEO project copy differs")
    AREA.mkdir()
    count = 0
    seconds = 0.0
    original_exact = 0
    for chunk in range(4):
        source_folder = REPORT / f"chunk_{chunk:02d}"
        area = AREA / f"chunk_{chunk:02d}"
        output = area / "ghidra_raw.ndjson"
        ctl.authorized(lease, output)
        result = run(ctl, lease, area, DEST, "PVGColor168", "libPVGColorFunctions.so",
                     ROOT / "scripts/task_190_codex_internal/ExportInternal190.java",
                     [str(source_folder / "targets.tsv"), str(output)])
        expected = rows(source_folder / "ghidra_raw.ndjson")
        fresh = rows(output)
        if len(expected) != 32 or len(fresh) != 32:
            raise RuntimeError(f"chunk {chunk} row count differs")
        for old, new in zip(expected, fresh):
            for key in FIELDS:
                if old[key] != new[key]:
                    raise RuntimeError(f"chunk={chunk} row={old['index']} field={key} differs")
            original_exact += new["boundary_classification"] == "GHIDRA_BODY_EQUALS_FDE_RANGE"
        count += len(fresh)
        seconds += result["elapsed_seconds"]
        print(json.dumps({"task": 190, "chunk": chunk, "rows": len(fresh),
                          "seconds": round(result["elapsed_seconds"], 3)}), flush=True)
    if count != 128 or original_exact != 127:
        raise RuntimeError("fresh original evidence count differs")
    correction = AREA / "correction"
    corrected_output = correction / "results"
    ctl.authorized(lease, corrected_output)
    result = run(ctl, lease, correction, DEST, "PVGColor168", "libPVGColorFunctions.so",
                 ROOT / "scripts/task_190_codex_internal/RepairMembership190.java",
                 [str(REPORT / "transient_gap_correction/anomaly.tsv"), str(corrected_output)])
    expected = json.loads((REPORT / "transient_gap_correction/results/128_2d8ec.json").read_text(encoding="utf8"))
    fresh = json.loads((corrected_output / "128_2d8ec.json").read_text(encoding="utf8"))
    for key in expected:
        if key not in ("generated_at", "decompile_elapsed_ms") and expected[key] != fresh[key]:
            raise RuntimeError("fresh correction differs field=" + key)
    if not (fresh["corrected_function_fde_membership_count"] == 180 and
            fresh["original_function_fde_membership_count"] == 176 and
            fresh["memory_unchanged_after_rollback"] and fresh["other_function_byte_count"] == 0):
        raise RuntimeError("fresh correction critical claim differs")
    seconds += result["elapsed_seconds"]
    if hashes(DEST) != source_hashes or hashes(SOURCE) != source_hashes:
        raise RuntimeError("CEO read-only replay changed analyzed project")
    summary = {"task_id": "TASK_190", "revision": 1, "fresh_original_rows": count,
               "fresh_original_full_fde_bodies": original_exact,
               "fresh_transient_full_fde_corrections": 1,
               "source_project_file_sha256": source_hashes,
               "ceo_project_unchanged": True, "elapsed_seconds": seconds,
               "no_behavior_or_product_claim": True}
    output = AREA / "summary.json"
    ctl.authorized(lease, output)
    output.write_text(json.dumps(summary, ensure_ascii=False, indent=2) + "\n", encoding="utf8")
    print(json.dumps({"result": "PASS", "task": 190, "rows": count,
                      "original_exact": original_exact, "correction": 1,
                      "seconds": round(seconds, 3)}), flush=True)


if __name__ == "__main__":
    main()
