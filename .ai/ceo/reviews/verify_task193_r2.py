"""Independent read-only verification of TASK_193's label-only R2 overlay."""

import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[3]
R2 = ROOT / "RULES/REPORT/TASK_193_REPORT_R2"
R1 = ROOT / "RULES/REPORT/TASK_193_REPORT_R1"
MANIFEST = ROOT / ".ai/ceo/reviews/TASK_193_internal_targets.json"
TASK = ROOT / "RULES/TASK/TASK_193_SO45_CODEX_INTERNAL_ACTIVE.md"
REVIEW = ROOT / ".ai/ceo/reviews/TASK_193-1949fc2bf631717871e80b7e35f862f9d9c0232084184ce8d0cb78d6957d5202.md"
CANONICAL = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def canonical(value):
    return json.dumps(value, ensure_ascii=False, sort_keys=True, separators=(",", ":")).encode("utf8")


def j(path):
    return json.loads(path.read_text(encoding="utf8"))


def main():
    seal = j(R2 / "COMPLETE.json")
    assert sha(R2 / "COMPLETE.json") == "a0d89e0f16be2b6f0c6b45d164c803281db769296eef8fb73fed43b7b413dd3f"
    assert seal["task_id"] == "TASK_193" and seal["revision"] == 2 and seal["status"] == "COMPLETE"
    assert seal["research_result"] == "PARTIAL_LABEL_ONLY_CORRECTION"
    for key, path in (("standard_sha256", CANONICAL), ("task_sha256", TASK),
                      ("target_manifest_sha256", MANIFEST), ("r1_complete_sha256", R1 / "COMPLETE.json"),
                      ("r1_worker_verification_sha256", R1 / "WORKER_VERIFICATION.json"),
                      ("ceo_r1_review_sha256", REVIEW)):
        assert seal[key] == sha(path), key
    assert seal["standard_sha256"] == "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
    assert seal["task_sha256"] == "555ee794be1651ef718d83df662269c11aef8a31a23ab71343194b750d7bcb66"
    assert seal["r1_complete_sha256"] == "043a7b9232dd43630b3cf3bd9155c3bc37492e9d19230017f2f36780e49799d5"
    assert seal["r1_worker_verification_sha256"] == "df46aa0a024a4de4750d21931fca6814c805622224e4a4b6d048bf404271ab6c"
    expected_files = set(seal["files"])
    actual_files = {path.relative_to(R2).as_posix() for path in R2.rglob("*") if path.is_file()} - {
        "COMPLETE.json", "PROGRESS.json", "PROGRESS.md"}
    assert actual_files == expected_files and len(expected_files) == 4
    for rel, digest in seal["files"].items():
        path = R2 / rel
        assert path.is_file() and sha(path) == digest, rel
    expected_code = {path.relative_to(ROOT).as_posix(): sha(path)
                     for path in (ROOT / "scripts/task_193_codex_correction_r2").rglob("*") if path.is_file()}
    assert len(expected_code) == 1 and seal["code_files"] == expected_code

    source = j(R1 / "WORKER_VERIFICATION.json")
    corrected = j(R2 / "WORKER_VERIFICATION_CORRECTED.json")
    manifest = j(MANIFEST)
    delta = j(R2 / "CORRECTION_DELTA.json")
    targets = manifest["targets"]
    assert len(source["rows"]) == len(corrected["rows"]) == len(targets) == len(delta["deltas"]) == 60
    assert manifest["excluded_oversized_global_indices"] == [201, 211, 216, 235]
    assert canonical({k:v for k,v in source.items() if k!="rows"}) == canonical({k:v for k,v in corrected.items() if k!="rows"})
    assert delta["changed_row_count"] == seal["corrected_labels"] == 60
    assert seal["other_field_differences"] == 0
    for i, (before, after, target, change) in enumerate(zip(source["rows"], corrected["rows"], targets, delta["deltas"], strict=True)):
        index = target["global_nonexport_fde_index"]
        assert before["index"] == after["index"] == index, i
        assert before["elf_va"] == after["elf_va"] == target["elf_va"], i
        assert before["original_pt_load_body_sha256"] == target["body_sha256"], i
        assert before["selected_zero_index"] == index - 1 and after["selected_zero_index"] == index, i
        before_other = {k:v for k,v in before.items() if k!="selected_zero_index"}
        after_other = {k:v for k,v in after.items() if k!="selected_zero_index"}
        assert canonical(before_other) == canonical(after_other), i
        assert change["global_nonexport_fde_index"] == index
        assert change["old_selected_zero_index"] == index - 1
        assert change["new_selected_zero_index"] == index
        assert change["elf_va"] == target["elf_va"]
        assert change["unchanged_other_fields_canonical_sha256"] == hashlib.sha256(canonical(before_other)).hexdigest()
    assert {row["index"] for row in corrected["rows"]} == set(range(192,256)) - {201,211,216,235}
    original_ledger = j(R1 / "COMPLETE.json")
    assert original_ledger["files"]["WORKER_VERIFICATION.json"] == seal["r1_worker_verification_sha256"]
    assert "PARTIAL" in (R2 / "01_MASTER_REPORT.md").read_text(encoding="utf8")
    print(json.dumps({"status":"PASS", "rows":60, "changed_field":"selected_zero_index",
                      "other_field_differences":0, "seal_sha256":sha(R2 / "COMPLETE.json"),
                      "source_r1_seal_sha256":sha(R1 / "COMPLETE.json")}))


if __name__ == "__main__":
    main()
