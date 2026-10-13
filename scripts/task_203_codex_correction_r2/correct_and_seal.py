"""Correct only the R1 whole-FDE C-like labels and seal an auditable R2 overlay."""
from __future__ import annotations

import copy
import hashlib
import json
from pathlib import Path

from common import (ABSOLUTE_DEADLINE, AGENT_ID, CODE, FENCE, LEASE_ID, MANIFEST,
                    MANIFEST_SHA, R1_COMPLETE_SHA, R1_PROJECT, R1_REPORT, R1_WINDOW_SHA,
                    REPLAY, REPLAY_SHA, REPORT, REVIEW, REVIEW_FINGERPRINT, REVIEW_SHA,
                    ROOT, SOURCE, SOURCE_SHA, STANDARD, STANDARD_SHA, TASK_SHA,
                    atomic_bytes, check_lease, now, sha256, write_json)


def tree_hashes(folder: Path) -> dict[str, str]:
    return {p.relative_to(folder).as_posix(): sha256(p)
            for p in sorted(folder.rglob("*")) if p.is_file()}


def zero_ranges(bits: str, va: int) -> list[str]:
    ranges = []
    start = None
    for offset, bit in enumerate(bits + "1"):
        if bit == "0" and start is None:
            start = offset
        elif bit == "1" and start is not None:
            ranges.append(f"0x{va+start:x}..0x{va+offset-1:x}")
            start = None
    return ranges


def normalized(value: object) -> str:
    return json.dumps(value, ensure_ascii=False, sort_keys=True, separators=(",", ":"))


def masked(value: dict) -> dict:
    result = copy.deepcopy(value)
    for target in result["targets"]:
        target.pop("whole_fde_c_like_present", None)
        target.pop("whole_fde_c_like_failure", None)
        target.pop("ghidra_function_c_like_present", None)
    return result


def differences(left: object, right: object, path: str = "$") -> list[dict]:
    if isinstance(left, dict) and isinstance(right, dict):
        changed = []
        for key in sorted(set(left) | set(right)):
            child = f"{path}.{key}"
            if key not in left:
                changed.append({"path": child, "from_exists": False,
                                "to_exists": True, "to": right[key]})
            elif key not in right:
                changed.append({"path": child, "from_exists": True,
                                "from": left[key], "to_exists": False})
            else:
                changed.extend(differences(left[key], right[key], child))
        return changed
    if isinstance(left, list) and isinstance(right, list):
        if len(left) != len(right):
            return [{"path": path, "from": left, "to": right}]
        changed = []
        for index, (a, b) in enumerate(zip(left, right)):
            changed.extend(differences(a, b, f"{path}[{index}]"))
        return changed
    return [] if left == right else [{"path": path, "from_exists": True, "from": left,
                                      "to_exists": True, "to": right}]


def main() -> None:
    lease = check_lease()
    if (REPORT / "COMPLETE.json").exists():
        raise RuntimeError("existing R2 seal cannot be overwritten")
    if (sha256(REVIEW), sha256(REPLAY), sha256(SOURCE)) != (REVIEW_SHA, REPLAY_SHA, SOURCE_SHA):
        raise RuntimeError("review/replay/original SO changed")
    r1_complete_path = R1_REPORT / "COMPLETE.json"
    r1_window_path = R1_REPORT / "window_evidence.json"
    if (sha256(r1_complete_path), sha256(r1_window_path)) != (R1_COMPLETE_SHA, R1_WINDOW_SHA):
        raise RuntimeError("R1 seal/window evidence changed")
    r1_complete = json.loads(r1_complete_path.read_text(encoding="utf-8"))
    if (r1_complete["task_id"], r1_complete["revision"], r1_complete["status"],
            r1_complete["files"]["window_evidence.json"]) != (
            "TASK_203", 1, "COMPLETE", R1_WINDOW_SHA):
        raise RuntimeError("R1 seal identity differs")
    r1_code = ROOT / "scripts/task_203_codex_internal"
    report_before, code_before, project_before = (tree_hashes(R1_REPORT),
                                                    tree_hashes(r1_code), tree_hashes(R1_PROJECT))
    if (len(r1_complete["files"]) != 23 or len(r1_complete["code_files"]) != 7 or
            len(project_before) != 9 or
            any(report_before.get(p) != h for p, h in r1_complete["files"].items()) or
            any(sha256(ROOT / p) != h for p, h in r1_complete["code_files"].items()) or
            project_before != r1_complete["scratch_project_files"]):
        raise RuntimeError("R1 report/code/project files differ from immutable seal")
    manifest = json.loads(MANIFEST.read_text(encoding="utf-8"))
    targets = manifest["targets"]
    original = json.loads(r1_window_path.read_text(encoding="utf-8"))
    if (manifest["task_id"], [t["global_nonexport_fde_index"] for t in targets],
            [x["global_nonexport_fde_index"] for x in original["targets"]]) != (
            "TASK_203", [505, 556], [505, 556]):
        raise RuntimeError("R1 window/target selection differs")
    corrected = copy.deepcopy(original)
    raw_proofs = []
    for index, (target, prior, fixed) in enumerate(zip(targets, original["targets"], corrected["targets"])):
        raw_path = R1_REPORT / f"chunk_{index:02d}/ghidra_raw.ndjson"
        raw = json.loads(raw_path.read_text(encoding="utf-8").strip())
        body = (R1_REPORT / f"original_fde_{target['global_nonexport_fde_index']}.bin").read_bytes()
        bits = raw["fde_membership_bits"]
        va = int(target["elf_va"], 16)
        if (raw["elf_va"] != target["elf_va"] or raw["fde_size_bytes"] != target["size_bytes"] or
                sha256(R1_REPORT / f"original_fde_{target['global_nonexport_fde_index']}.bin") != target["body_sha256"] or
                len(body) != len(bits) or set(bits) - {"0", "1"} or
                bits.count("0") != raw["fde_missing_bytes"] or
                bits.count("1") != raw["fde_member_bytes"] or
                zero_ranges(bits, va) != raw["fde_missing_ranges"] or
                prior["window_function_missing_bytes"] != raw["fde_missing_bytes"] or
                [g["missing_range"] for g in prior["gap_contexts"]] != raw["fde_missing_ranges"] or
                prior["whole_fde_c_like_present"] is not True or
                prior["whole_fde_c_like_failure"] != "" or
                raw["c_like_present"] is not True or not raw["c_like_text"] or
                hashlib.sha256(raw["c_like_text"].encode("utf-8")).hexdigest() != raw["c_like_sha256"]):
            raise RuntimeError(f"R1 raw body-gap/C-like proof differs at row {index+1}")
        expected_gap = (96, "0x3cd44..0x3cda3") if index == 0 else (660, "0x4e7e8..0x4ea7b")
        if raw["fde_missing_bytes"] != expected_gap[0] or raw["fde_missing_ranges"] != [expected_gap[1]]:
            raise RuntimeError(f"R1 body gap differs from CEO finding at row {index+1}")
        explanation = (f"Whole original FDE C-like coverage unestablished: existing Ghidra function body "
                       f"misses {expected_gap[0]} FDE bytes at {expected_gap[1]}; C-like text exists only "
                       "for that narrower Ghidra function object.")
        fixed["whole_fde_c_like_present"] = False
        fixed["whole_fde_c_like_failure"] = explanation
        fixed["ghidra_function_c_like_present"] = True
        raw_proofs.append({"global_nonexport_fde_index": target["global_nonexport_fde_index"],
                           "elf_va": target["elf_va"], "size_bytes": target["size_bytes"],
                           "body_sha256": target["body_sha256"], "r1_raw_path": str(raw_path),
                           "r1_raw_sha256": sha256(raw_path),
                           "membership_bitmap_bytes": len(bits),
                           "membership_missing_bytes": bits.count("0"),
                           "reconstructed_missing_ranges": zero_ranges(bits, va),
                           "ghidra_function_c_like_sha256": raw["c_like_sha256"],
                           "whole_fde_c_like_present_corrected": False,
                           "ghidra_function_c_like_present": True})
    expected_paths = {f"$.targets[{i}].{key}" for i in range(2) for key in (
        "whole_fde_c_like_present", "whole_fde_c_like_failure", "ghidra_function_c_like_present")}
    changes = differences(original, corrected)
    if len(changes) != 6 or {x["path"] for x in changes} != expected_paths or masked(original) != masked(corrected):
        raise RuntimeError("R2 changes extend beyond the three allowed semantic keys per target")
    masked_hash = hashlib.sha256(normalized(masked(original)).encode("utf-8")).hexdigest()
    if masked_hash != hashlib.sha256(normalized(masked(corrected)).encode("utf-8")).hexdigest():
        raise RuntimeError("nonsemantic source/window measurements differ")
    check_lease()
    REPORT.mkdir(parents=True, exist_ok=True)
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_203", "revision": 2,
        "status": "R1_PINNED_AND_DELTA_VERIFIED", "generated_at": now(),
        "lease_id": LEASE_ID, "fencing_token": FENCE,
        "r1_report_files": len(report_before), "r1_code_files": len(code_before),
        "r1_project_files": len(project_before), "corrected_target_rows": 2,
        "allowed_semantic_changes": len(changes), "other_values_equal": True})
    write_json(REPORT / "window_evidence_corrected.json", corrected)
    written = json.loads((REPORT / "window_evidence_corrected.json").read_text(encoding="utf-8"))
    if differences(original, written) != changes or masked(written) != masked(original):
        raise RuntimeError("on-disk R2 overlay differs from proven semantic delta")
    report_after, code_after, project_after = (tree_hashes(R1_REPORT),
                                               tree_hashes(r1_code), tree_hashes(R1_PROJECT))
    if (report_before, code_before, project_before) != (report_after, code_after, project_after):
        raise RuntimeError("immutable R1 report/code/project changed during R2 correction")
    write_json(REPORT / "body_gap_verification.json", {"task_id": "TASK_203", "revision": 2,
        "generated_at": now(), "original_source_sha256": SOURCE_SHA,
        "r1_raw_membership_rows_independently_rebuilt": 2,
        "total_missing_fde_bytes": sum(x["membership_missing_bytes"] for x in raw_proofs),
        "rows": raw_proofs})
    write_json(REPORT / "R1_to_R2_delta.json", {"task_id": "TASK_203", "revision": 2,
        "generated_at": now(), "r1_complete_sha256": R1_COMPLETE_SHA,
        "r1_window_evidence_sha256": R1_WINDOW_SHA,
        "r2_corrected_window_evidence_sha256": sha256(REPORT / "window_evidence_corrected.json"),
        "ceo_review_fingerprint": REVIEW_FINGERPRINT,
        "changed_fields": changes, "changed_field_count": len(changes),
        "all_other_parsed_fields_equal": True,
        "nonsemantic_masked_object_sha256_before_and_after": masked_hash,
        "r1_report_file_sha256_before_and_after": report_before,
        "r1_code_file_sha256_before_and_after": code_before,
        "r1_project_file_sha256_before_and_after": project_before})
    write_json(REPORT / "independent_verification.json", {"task_id": "TASK_203", "revision": 2,
        "generated_at": now(), "r1_complete_sha256_verified": R1_COMPLETE_SHA,
        "r1_window_evidence_sha256_verified": R1_WINDOW_SHA,
        "ceo_review_sha256_verified": REVIEW_SHA,
        "ceo_replay_summary_sha256_verified": REPLAY_SHA,
        "r1_report_seal_entries_verified": len(r1_complete["files"]),
        "r1_code_seal_entries_verified": len(r1_complete["code_files"]),
        "r1_project_seal_entries_verified": len(project_before),
        "r1_raw_body_membership_rows_verified": 2,
        "corrected_whole_fde_c_like_count": 0,
        "preserved_ghidra_function_c_like_count": 2,
        "gap_bytes": 756,
        "allowed_semantic_field_changes": len(changes),
        "all_other_parsed_fields_equal": True,
        "no_ghidra_rerun": True,
        "r1_report_code_project_unchanged": True})
    audit = f"""# TASK_203 R2 audit index

- Canonical Standard fully reread before writes: `{STANDARD}`; SHA-256 `{STANDARD_SHA}`; controller standard-read acknowledgement `{lease['acquired_at']}`.
- Exact ACTIVE TASK_203 revision 2 SHA-256 `{TASK_SHA}`; target manifest `.ai/ceo/reviews/TASK_203_internal_targets.json` SHA-256 `{MANIFEST_SHA}`.
- CEO NEEDS_FIX review fingerprint `{REVIEW_FINGERPRINT}`; review SHA-256 `{REVIEW_SHA}`; replay summary SHA-256 `{REPLAY_SHA}`.
- Immutable R1 seal `RULES/REPORT/TASK_203_REPORT_R1/COMPLETE.json` SHA-256 `{R1_COMPLETE_SHA}`; immutable window evidence SHA-256 `{R1_WINDOW_SHA}`. All 23 R1 sealed report, seven code, and nine project files were rehashed; full R1 trees matched before and after this correction.
- Original source: `{SOURCE}`; SHA-256 `{SOURCE_SHA}`. R1 raw per-byte membership independently reconstructs 96 missing bytes at `0x3cd44..0x3cda3` and 660 at `0x4e7e8..0x4ea7b`.
- Lease/agent/fence: `{LEASE_ID}` / `{AGENT_ID}` / `{FENCE}`; original absolute deadline `{ABSOLUTE_DEADLINE.isoformat()}` and shorter lease expiry `{lease['expiry']}`.
- `window_evidence_corrected.json` is the complete R1 parsed evidence with exactly six semantic changes. `R1_to_R2_delta.json` lists each old/new value and proves every other parsed field equal. `body_gap_verification.json` records independent raw bitmap and C-like-text checks.
- `COMPLETE.json` seals every R2 report/code file. R1 raw evidence is referenced, not recopied or modified. CEO independent R2 review remains pending. No Ghidra rerun, source/product edit, AGY, commit, push or Phase PASS.
"""
    atomic_bytes(REPORT / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    master = """# TASK_203 R2 - correct whole-FDE C-like evidence labels

The R1 window evidence mislabeled both oversized candidates as having whole-FDE C-like output. The original Ghidra function objects do have C-like text, but their bodies omit 96 original FDE bytes for #505 (`0x3cd44..0x3cda3`) and 660 bytes for #556 (`0x4e7e8..0x4ea7b`). Neither C-like output establishes coverage of the whole original FDE.

`window_evidence_corrected.json` sets `whole_fde_c_like_present` to `false` and gives each exact body-gap explanation. It separately sets `ghidra_function_c_like_present` to `true`. The parsed R1-to-R2 delta contains exactly these three field changes per target; every other source/window value and gap context is equal to immutable R1. The raw Ghidra membership bitmaps independently reproduce both missing ranges and 756 total missing bytes.

The result remains **PARTIAL_OVERSIZED_FDE_BOUNDARY** for #505 and #556. R1 raw source, Ghidra output, C-like text, project files and CEO replay remain immutable; no Ghidra run or metadata correction occurred in R2. This correction establishes no complete source-function recovery, code/data classification, functional or pixel parity, product Phase PASS, V4/P7, or all-45-SO completion. CEO independent R2 review is pending.
"""
    atomic_bytes(REPORT / "01_MASTER_REPORT.md", master.encode("utf-8"))
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_203", "revision": 2,
        "status": "SEALED_REVIEW_CANDIDATE", "generated_at": now(),
        "agent_id": AGENT_ID, "lease_id": LEASE_ID, "fencing_token": FENCE,
        "corrected_target_rows": 2, "whole_fde_c_like_count": 0,
        "ghidra_function_c_like_count": 2, "gap_bytes": 756,
        "allowed_semantic_changes": 6, "all_other_values_equal": True,
        "research_disposition": "PARTIAL_OVERSIZED_FDE_BOUNDARY"})
    check_lease()
    report_files = {p.relative_to(REPORT).as_posix(): sha256(p)
                    for p in sorted(REPORT.rglob("*")) if p.is_file()
                    and p.name not in ("PROGRESS.json", "COMPLETE.json")}
    code_files = {p.relative_to(ROOT).as_posix(): sha256(p)
                  for p in sorted(CODE.rglob("*")) if p.is_file()}
    total_bytes = sum((REPORT / p).stat().st_size for p in report_files)
    if total_bytes > 134217728:
        raise RuntimeError("R2 report exceeds task size cap")
    write_json(REPORT / "COMPLETE.json", {"schema_version": "2.1.2", "task_id": "TASK_203",
        "revision": 2, "status": "COMPLETE", "review_status": "REVIEW_CANDIDATE_AWAITING_CEO",
        "research_disposition": "PARTIAL_OVERSIZED_FDE_BOUNDARY", "generated_at": now(),
        "agent_id": AGENT_ID, "lease_id": LEASE_ID, "fencing_token": FENCE,
        "standard_sha256": STANDARD_SHA, "task_sha256": TASK_SHA,
        "target_manifest_sha256": MANIFEST_SHA, "original_so_sha256": SOURCE_SHA,
        "ceo_review_fingerprint": REVIEW_FINGERPRINT,
        "r1_complete_sha256": R1_COMPLETE_SHA, "r1_window_evidence_sha256": R1_WINDOW_SHA,
        "r2_corrected_window_evidence_sha256": sha256(REPORT / "window_evidence_corrected.json"),
        "target_fde_candidate_count": 2, "whole_fde_c_like_count": 0,
        "ghidra_function_c_like_count": 2, "fde_body_missing_bytes": 756,
        "allowed_semantic_changed_fields": 6, "all_other_parsed_fields_equal": True,
        "r1_report_code_project_unchanged": True, "ghidra_reruns": 0,
        "product_phase_pass": False, "behavior_equivalence_tested": False,
        "commit_sha": None, "push_receipt": None,
        "report_bytes_excluding_progress_and_seal": total_bytes,
        "files": report_files, "code_files": code_files,
        "immutable_r1_project_files": project_before})
    print(json.dumps({"status": "SEALED", "complete_sha256": sha256(REPORT / "COMPLETE.json"),
                      "changed_semantic_fields": len(changes), "r1_project_files": len(project_before),
                      "report_file_count": len(report_files), "code_file_count": len(code_files)}))


if __name__ == "__main__":
    main()
