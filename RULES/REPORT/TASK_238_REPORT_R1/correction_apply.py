"""One-time TASK_238 report metadata correction under fence 1276."""
import datetime as dt
import hashlib
import json
import os
import pathlib
import tempfile

root = pathlib.Path(__file__).resolve().parents[3]
report = pathlib.Path(__file__).resolve().parent
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
pins = {
    "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
    "RULES/TASK/TASK_238_SO45_INTERNAL_CONTINUATION_ACTIVE.md": "8ac7f1841f072cc3651bc880727fe3bec12d62901fdcbd8adbb1a959b5940f73",
    ".ai/ceo/reviews/TASK_238_internal_targets.json": "be609310fe32d6f2b2d150534cd1f64a21824a6f37756103ae3c26f8c884d367",
}
for rel, digest in pins.items():
    assert sha(root / rel) == digest, rel
flag = root / ".ai/ceo/END_AGENT_SESSION.flag"
assert not flag.exists() or flag.read_text(encoding="utf-8-sig").strip().upper() != "TRUE"
locks = json.loads((root / ".ai/locks.json").read_text())["active_locks"]
leases = [x for x in locks if x.get("lease_id") == "LEASE-CEO-WORKER-TASK_238-R1"]
assert len(leases) == 1
lease = leases[0]
assert (lease["status"], lease["agent_id"], lease["task_id"], lease["task_revision"],
        lease["task_sha"], lease["fencing_token"]) == (
            "ACTIVE", "/root/audit_210", "TASK_238", 1, pins["RULES/TASK/TASK_238_SO45_INTERNAL_CONTINUATION_ACTIVE.md"], 1276)
assert dt.datetime.now(dt.timezone.utc) < dt.datetime.fromisoformat(lease["expiry"].replace("Z", "+00:00"))
complete_path = report / "COMPLETE.json"
complete = json.loads(complete_path.read_text())
for rel, digest in complete["files"].items():
    assert sha(report / rel) == digest, rel
for rel, digest in {**complete["code_files"], **complete["scratch_files"]}.items():
    assert sha(root / rel) == digest, rel
review = (root / ".ai/ceo/reviews/TASK_236-f9416ddcf084cc190484cf9901167c38cc81e9b7e36a0f296038fb9f8410ec13.md").read_text()
assert "ACCEPTED as PARTIAL static research only" in review
manifest236 = json.loads((root / ".ai/ceo/reviews/TASK_236_internal_targets.json").read_text())
manifest239 = json.loads((root / ".ai/ceo/reviews/TASK_239_internal_targets.json").read_text())
manifest238 = json.loads((root / ".ai/ceo/reviews/TASK_238_internal_targets.json").read_text())
resolved = sorted(x["global_index"] for x in manifest236["targets"])
assigned = sorted(x["global_index"] for x in manifest239["targets"])
current = sorted(x["global_index"] for x in manifest238["skipped_in_slice"])
assert resolved == [1542, 1586, 1620, 1623, 1626, 1830, 1912]
assert assigned == [450, 499, 555, 2293, 2775, 2776, 3106, 3132, 3134, 3285, 3523]
assert current == [3867, 3877, 4025, 4051, 4052, 4066]
assert len(set(resolved + assigned + current)) == 24
rows = [json.loads(p.read_text()) for p in report.glob("ghidra_raw_batch*/*.json")]
assert len(rows) == len({x["index"] for x in rows}) == 506
assert sum(bool(x["c_like_nonempty"]) for x in rows) == 506
overlap = sorted(x["index"] for x in rows if x["other_function_byte_count"] > 0)
assert overlap == [3588, 3590]
assert {x["index"]: x["other_function_byte_count"] for x in rows if x["index"] in overlap} == {3588: 12, 3590: 92}
source = json.loads((report / "source_index.json").read_text())
summary = json.loads((report / "verification_summary.json").read_text())
assert (summary["original_fde_candidate_bodies_verified"], summary["original_bytes_verified"],
        summary["original_instruction_words_verified"], summary["ghidra_raw_rows"],
        summary["ghidra_listing_positions"], summary["ghidra_missing_listing_positions"]) == (
            506, 192464, 48116, 506, 48036, 80)
old_by_index = {x["global_index"]: x for x in source["skipped_oversized_candidates_pending"]}
current_by_index = {x["global_index"]: x for x in manifest238["skipped_in_slice"]}
assigned_by_index = {x["global_index"]: x for x in manifest239["targets"]}
pending = [old_by_index.get(i, assigned_by_index.get(i, current_by_index.get(i))) for i in sorted(assigned + current)]
assert len(pending) == 17 and all(pending)
source["skipped_oversized_candidates_pending"] = pending
source["oversized_disposition"] = {
    "current_slice_skipped_indices": current,
    "older_assigned_to_active_TASK_239_not_accepted_indices": assigned,
    "accepted_TASK_236_partial_research_indices": resolved,
    "accepted_TASK_236_review_fingerprint": "f9416ddcf084cc190484cf9901167c38cc81e9b7e36a0f296038fb9f8410ec13",
}
summary["skipped_oversized_candidates_pending"] = pending
summary["current_slice_skipped_oversized_indices"] = current
summary["older_assigned_to_active_TASK_239_not_accepted_indices"] = assigned
summary["accepted_TASK_236_partial_research_indices"] = resolved
summary["unresolved_source_function_boundary_indices"] = overlap
summary["c_like_rows_without_other_function_overlap"] = 504
summary["independently_decoded_source_functions"] = 0

def atomic(path, payload):
    fd, temp = tempfile.mkstemp(prefix=".task238-correction-", dir=path.parent)
    try:
        with os.fdopen(fd, "wb") as stream:
            stream.write(payload)
            stream.flush()
            os.fsync(stream.fileno())
        os.replace(temp, path)
    finally:
        if os.path.exists(temp):
            os.unlink(temp)

def save_json(path, value):
    atomic(path, (json.dumps(value, ensure_ascii=False, indent=2) + "\n").encode())

save_json(report / "source_index.json", source)
save_json(report / "verification_summary.json", summary)
body = f"""# TASK_238 R1 — libPVGImageCodec.so bounded internal candidates

**PARTIAL static research.** The exact 506 pinned nonexport FDE candidates were revalidated against the original SO: 192,464 bytes / 48,116 AArch64 instruction words. Bounded Ghidra produced 506 raw rows and 506 nonempty C-like texts, with 48,036/48,116 listing positions, 80 gaps and 145,757 p-code operations. Full FDE body membership appears in 496/506 rows.

Indices **3588** (12 overlapping bytes) and **3590** (92 overlapping bytes) overlap another Ghidra function. Their source-function boundaries remain unresolved. Thus **504 C-like candidate rows lack this specific overlap**; none is independently decoded or behavior-equivalent source code. The other membership/listing gaps remain visible in the raw rows.

The six current-slice oversized indices {current} were skipped under the <=4,096-byte bound. Eleven older oversized indices {assigned} are assigned to ACTIVE TASK_239 and are **not yet accepted**. Seven indices {resolved} were independently ACCEPTED as **partial static research** in TASK_236; they are not pending here.

The 5,050/48,116 spread source positions (10.50%) rechecked with zero mismatch; the private project hashes were unchanged. These are ELF unwind FDE candidates, not proven unique source-function boundaries or recovered behavior. No native/device equivalence, product Phase PASS, V4 or P7 is claimed. Independent CEO review and commit/push remain pending.
"""
atomic(report / "01_MASTER_REPORT.md", body.encode())
correction = f"""# TASK_238 R1 report correction

The first sealed report incorrectly included seven TASK_236 accepted partial-research indices in the pending list and omitted older 450/499. This correction changes only task-owned report metadata and narrative. The 506 Ghidra raw rows, source assembly, command receipts, logs, code and scratch bytes retain their original hashes.

Current slice skipped: {current}.
Older assigned to ACTIVE TASK_239 and not accepted: {assigned}.
Accepted as partial static research by TASK_236: {resolved}.
Remaining pending: {sorted(assigned + current)}.

Raw rows 3588 and 3590 overlap another Ghidra function (12 and 92 bytes). They are unresolved source-function boundaries. There are 506 C-like raw outputs, 504 without this specific overlap, and zero independently decoded source functions or verified behaviors.
"""
atomic(report / "02_CORRECTION.md", correction.encode())
progress = json.loads((report / "PROGRESS.json").read_text())
progress.update({"status": "FINAL_RESEARCH_CANDIDATE_CORRECTED",
                 "generated_at": dt.datetime.now(dt.timezone.utc).isoformat(),
                 "pending_oversized_count": 17,
                 "accepted_TASK_236_partial_count": 7,
                 "unresolved_source_function_boundary_indices": overlap,
                 "c_like_rows_without_other_function_overlap": 504})
save_json(report / "PROGRESS.json", progress)
files = {p.relative_to(report).as_posix(): sha(p) for p in report.rglob("*")
         if p.is_file() and p.name not in ("COMPLETE.json", "PROGRESS.json")}
complete["files"] = files
complete["generated_at"] = dt.datetime.now(dt.timezone.utc).isoformat()
save_json(complete_path, complete)
assert all(sha(report / rel) == digest for rel, digest in files.items())
assert all(sha(root / rel) == digest for rel, digest in complete["code_files"].items())
assert all(sha(root / rel) == digest for rel, digest in complete["scratch_files"].items())
print(json.dumps({"complete_sha256": sha(complete_path), "report_files": len(files),
                  "code_files": len(complete["code_files"]), "scratch_files": len(complete["scratch_files"]),
                  "pending_count": len(pending), "accepted_partial_count": len(resolved),
                  "overlap": overlap, "raw_rows": len(rows)}))
