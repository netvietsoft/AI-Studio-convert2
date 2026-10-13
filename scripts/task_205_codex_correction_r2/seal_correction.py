"""Read-only replay of TASK_205 R1 p-code coverage and atomic R2 overlay seal."""
from __future__ import annotations

import hashlib
import json
import os
import pathlib
import tempfile
from datetime import datetime, timezone


ROOT = pathlib.Path(__file__).resolve().parents[2]
R1 = ROOT / "RULES/REPORT/TASK_205_REPORT_R1"
R2 = ROOT / "RULES/REPORT/TASK_205_REPORT_R2"
SCRIPT = ROOT / "scripts/task_205_codex_correction_r2/seal_correction.py"
TASK = ROOT / "RULES/TASK/TASK_205_SO45_CODEX_INTERNAL_ACTIVE.md"
TARGETS = ROOT / ".ai/ceo/reviews/TASK_205_internal_targets.json"
REVIEW = ROOT / ".ai/ceo/reviews/TASK_205-61976a1abb5c257fa3e159a8f0ee85bfc0d3182533bc85e509e5aa1389788cdf.md"
R1_TASK = ROOT / ".ai/ceo/reviews/TASK_205_R1_TASK_ARCHIVE_4eb23a8ff4eb3345be6a3bb61f353725377a45f5fdcf1c8070e402d2bf2906ac.md"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
SOURCE_SO = ROOT / "lib-core-graphics/src/main/jniLibs/arm64-v8a/libPVGImageCodec.so"
TASK_SHA = "aa2ea858233747e6c128a43e1f60b1d72dcc41a2a5f4c19bbc16a416c4a53e09"
TARGET_SHA = "fb7fc5d6f7ef0bb067a0989263bffc60b75a1be40e3ac2c39b9c7759b8666d12"
STD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
R1_SEAL_SHA = "d1d03840795c96e092241be72ce9c3bf6d8939c44660898ceb39825384cc8fac"
REVIEW_SHA = "c6800f28b63522d207cf9697e72de10569d2f17ce630ed4f66b56cd23ce1b776"
R1_TASK_SHA = "4eb23a8ff4eb3345be6a3bb61f353725377a45f5fdcf1c8070e402d2bf2906ac"
SO_SHA = "7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b"
EXPECTED_EMPTY = {
    (380, "0x2db2ac"), (381, "0x2db538"), (381, "0x2dbdd0"),
    (381, "0x2dbe6c"), (384, "0x2dc3f0"), (384, "0x2dc3fc"),
}


def sha(path: pathlib.Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(1024 * 1024), b""):
            h.update(chunk)
    return h.hexdigest()


def read(path: pathlib.Path):
    return json.loads(path.read_text(encoding="utf-8"))


def require(condition, message):
    if not condition:
        raise RuntimeError(message)


def gate():
    for path, digest in ((STANDARD, STD_SHA), (TASK, TASK_SHA), (TARGETS, TARGET_SHA),
                         (R1 / "COMPLETE.json", R1_SEAL_SHA), (REVIEW, REVIEW_SHA),
                         (R1_TASK, R1_TASK_SHA)):
        require(sha(path) == digest, f"Pinned SHA mismatch: {path}")
    end = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    require(not end.exists() or "TRUE" not in end.read_text(encoding="utf-8").upper(), "END flag")
    locks = read(ROOT / ".ai/locks.json")["active_locks"]
    matches = [x for x in locks if x.get("lease_id") == "LEASE-CEO-WORKER-TASK_205-R2"]
    require(len(matches) == 1, "Lease absent or duplicated")
    lease = matches[0]
    require(lease.get("status") == "ACTIVE" and lease.get("agent_id") == "/root/so45_imagecodec_internal"
            and lease.get("task_id") == "TASK_205" and lease.get("task_revision") == 2
            and lease.get("task_sha") == TASK_SHA and lease.get("fencing_token") == 1242,
            "Wrong lease/revision/fence")
    require(datetime.now(timezone.utc) < datetime.fromisoformat(lease["expiry"]), "Lease expired")
    return lease


def atomic(path: pathlib.Path, data: bytes):
    gate()
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, tmp = tempfile.mkstemp(prefix=".r2_", dir=path.parent)
    try:
        with os.fdopen(fd, "wb") as f:
            f.write(data)
            f.flush()
            os.fsync(f.fileno())
        os.replace(tmp, path)
    finally:
        if os.path.exists(tmp):
            os.unlink(tmp)


def dump(path: pathlib.Path, obj):
    atomic(path, (json.dumps(obj, ensure_ascii=False, indent=2, sort_keys=True) + "\n").encode("utf-8"))


def verify_r1_inventory(r1_seal):
    require("PROGRESS.json" not in r1_seal["files"] and "COMPLETE.json" not in r1_seal["files"], "R1 volatile inventory")
    actual = {p.relative_to(R1).as_posix() for p in R1.rglob("*") if p.is_file()
              and p.name not in ("PROGRESS.json", "COMPLETE.json")}
    require(actual == set(r1_seal["files"]), "R1 report inventory drift")
    for rel, digest in r1_seal["files"].items():
        require(sha(R1 / rel) == digest, f"R1 report drift: {rel}")
    for key in ("code_files", "scratch_files"):
        for rel, digest in r1_seal[key].items():
            require(sha(ROOT / rel) == digest, f"R1 {key} drift: {rel}")
    return {k: len(r1_seal[k]) for k in ("files", "code_files", "scratch_files")}


def main():
    lease = gate()
    target = read(TARGETS)
    verification = read(R1 / "WORKER_VERIFICATION.json")
    seal = read(R1 / "COMPLETE.json")
    inventory = verify_r1_inventory(seal)
    require(target["selected_count"] == 126 == len(target["targets"]) == len(verification["rows"]), "Candidate count")
    require(sha(SOURCE_SO) == SO_SHA, "Original SO drift")
    empty, row_deltas = [], []
    listings = nonempty = ops = source_words = source_bytes = 0
    calls = branches = clike = raw_count = correction_count = 0
    corrected = {264, 316}
    for ordinal, (item, row) in enumerate(zip(target["targets"], verification["rows"])):
        index = item["global_nonexport_fde_index"] + 1
        va = item["elf_va"]
        require(row["index"] == index and row["elf_va"] == va, f"Candidate order {index}")
        stem = f"{index}_{va[2:]}"
        src_path = R1 / "source_assembly" / f"{stem}.json"
        raw_path = R1 / f"ghidra_raw_batch{ordinal // 32 + 1}" / f"{stem}.json"
        src, raw = read(src_path), read(raw_path)
        require(sha(raw_path) == row["raw_ghidra_sha256"], f"Raw hash {index}")
        require(src["source_body_sha256"] == item["body_sha256"] == row["original_pt_load_body_sha256"], f"Source body {index}")
        require(src["instruction_slots"] == item["instruction_slots"] == row["source_instruction_slots"], f"Source slots {index}")
        require(len(src["instructions"]) == src["instruction_slots"], f"Source listing {index}")
        require(raw["ghidra_memory_sha256"] == item["body_sha256"], f"Ghidra bytes {index}")
        raw_count += 1
        effective = raw
        if index in corrected:
            corr_path = R1 / "ghidra_correction_raw" / f"{stem}.json"
            require(sha(corr_path) == row["correction_sha256"], f"Correction hash {index}")
            effective = read(corr_path)
            correction_count += 1
        else:
            require(row["correction_sha256"] is None, f"Unexpected correction {index}")
        instructions = effective["instruction_pcode"]
        require(len(instructions) == len(src["instructions"]) == row["effective_ghidra_pcode_slots"], f"Effective listing {index}")
        require(effective["c_like_nonempty"] and hashlib.sha256(effective["c_like_text"].encode("utf-8")).hexdigest() == row["effective_c_like_sha256"], f"C-like {index}")
        row_nonempty = row_ops = 0
        offset = int(raw["database_va"], 16) - int(va, 16)
        for source_inst, inst in zip(src["instructions"], instructions):
            dbva = inst["database_va"].lower()
            require(int(dbva, 16) - int(source_inst["elf_va"], 16) == offset, f"Position {index}:{dbva}")
            # Capstone and Ghidra may render equivalent instructions with different aliases.
            # The pinned original body SHA and exact source/database positions bind each row.
            count = len(inst["pcode_ops"])
            row_ops += count
            if count:
                row_nonempty += 1
            else:
                require(source_inst["assembly"].split()[0].lower() == "nop", f"Non-NOP empty p-code {index}:{dbva}")
                empty.append({"candidate_index_one_based": index,
                              "global_nonexport_fde_index": item["global_nonexport_fde_index"],
                              "source_elf_va": source_inst["elf_va"].lower(), "database_va": dbva,
                              "source_word_hex": source_inst["word_hex"].lower(),
                              "source_assembly": source_inst["assembly"],
                              "effective_assembly": inst["assembly"], "pcode_ops": [],
                              "effective_raw_sha256": sha(R1 / ("ghidra_correction_raw" if index in corrected else f"ghidra_raw_batch{ordinal // 32 + 1}") / f"{stem}.json")})
        require(row_ops == row["effective_ghidra_pcode_ops"], f"P-code op count {index}")
        if row_nonempty != len(instructions):
            row_deltas.append({"candidate_index_one_based": index, "source_elf_va": va,
                               "r1_effective_ghidra_pcode_slots": row["effective_ghidra_pcode_slots"],
                               "r2_effective_instruction_listings": len(instructions),
                               "r2_positions_with_nonempty_pcode": row_nonempty,
                               "empty_pcode_positions": len(instructions) - row_nonempty})
        listings += len(instructions)
        nonempty += row_nonempty
        ops += row_ops
        source_words += src["instruction_slots"]
        source_bytes += item["size_bytes"]
        calls += row["call_site_count"]
        branches += row["branch_site_count"]
        clike += bool(effective["c_like_nonempty"])
    require({(x["candidate_index_one_based"], x["database_va"]) for x in empty} == EXPECTED_EMPTY, "Six NOP address set")
    require((listings, nonempty, len(empty), ops) == (6246, 6240, 6, 25604), "Recomputed p-code totals")
    require((source_words, source_bytes, calls, branches, clike, raw_count, correction_count) ==
            (6246, 24984, 192, 1087, 126, 126, 2), "Unchanged critical counts")
    require({r["candidate_index_one_based"] for r in row_deltas} == {380, 381, 384}, "Affected rows")
    require(len(read(R1 / "CALL_SITES.json")["sites"]) == 192 and len(read(R1 / "BRANCH_SITES.json")["sites"]) == 1087, "Static site file counts")
    require(seal["effective_ghidra_pcode_operations"] == 25604 and verification["effective_ghidra_pcode_instruction_positions"] == 6246, "R1 claim binding")
    timestamp = datetime.now(timezone.utc).isoformat().replace("+00:00", "Z")
    bindings = {"r1_complete_sha256": R1_SEAL_SHA, "r1_review_fingerprint": "61976a1abb5c257fa3e159a8f0ee85bfc0d3182533bc85e509e5aa1389788cdf",
                "r1_review_sha256": REVIEW_SHA, "r1_task_archive_sha256": R1_TASK_SHA,
                "target_manifest_sha256": TARGET_SHA, "original_so_sha256": SO_SHA}
    coverage = {"schema_version": "2.1.2", "task_id": "TASK_205", "revision": 2,
                "generated_at": timestamp, "research_result": "PARTIAL_BOUNDARY_TWO_TRANSIENT_FULL_FDE_METADATA",
                **bindings, "candidate_count": 126, "source_instruction_positions": 6246,
                "effective_ghidra_instruction_listings": listings,
                "effective_ghidra_positions_with_nonempty_pcode": nonempty,
                "effective_ghidra_positions_with_empty_pcode": len(empty),
                "effective_ghidra_pcode_operations": ops, "empty_pcode_positions": empty,
                "affected_rows": row_deltas,
                "interpretation": "P-code operation count is unchanged. A listed NOP with an empty pcode_ops array is an analyzed instruction listing, not a position with a nonempty p-code operation."}
    delta = {"schema_version": "2.1.2", "task_id": "TASK_205", "revision": 2,
             "generated_at": timestamp, **bindings,
             "correction": "R1 conflated 6246 effective instruction listings with positions containing at least one p-code operation; six NOPs have empty arrays.",
             "replaced_claims": [
                 {"r1_file": "WORKER_VERIFICATION.json", "r1_field": "effective_ghidra_pcode_instruction_positions", "r1_value": 6246,
                  "r2_fields": ["effective_ghidra_instruction_listings=6246", "effective_ghidra_positions_with_nonempty_pcode=6240"]},
                 {"r1_file": "WORKER_VERIFICATION.json", "r1_field": "rows[*].effective_ghidra_pcode_slots", "r1_value": "listing counts; affected rows 380, 381, 384", "r2_field": "affected_rows lists listing and nonempty counts separately"},
                 {"r1_file": "COMPLETE.json", "r1_field": "effective_ghidra_pcode_instruction_positions", "r1_value": 6246, "r2_field": "effective_ghidra_positions_with_nonempty_pcode=6240"},
                 {"r1_file": "PROGRESS.json", "r1_field": "effective_ghidra_pcode_instruction_positions", "r1_value": 6246, "r2_field": "effective_ghidra_positions_with_nonempty_pcode=6240"},
                 {"r1_file": "01_MASTER_REPORT.md", "r1_claim": "effective p-code at all 6,246 positions", "r2_claim": "6,246 listings, 6,240 nonempty p-code positions"},
                 {"r1_file": "00_AUDIT_INDEX.md", "r1_claim": "every source/P-code position", "r2_claim": "every source and effective listing position; six NOPs have empty p-code"}],
             "unchanged_critical_results": {"source_candidates": 126, "source_bytes": source_bytes,
                 "source_instruction_words": source_words, "effective_pcode_operations": ops,
                 "nonempty_c_like_outputs": clike, "original_full_fde_membership": 124,
                 "transient_full_fde_metadata_assumptions": 2,
                 "fresh_session_original_metadata_and_memory_replays": 2,
                 "call_sites": calls, "branch_sites": branches,
                 "ordinary_spread_source_sample": 821,
                 "original_and_private_project_files_byte_identical": 9,
                 "r1_report_files_hash_verified": inventory["files"],
                 "r1_code_files_hash_verified": inventory["code_files"],
                 "r1_scratch_files_hash_verified": inventory["scratch_files"]},
             "r1_immutable": True, "ghidra_rerun": False, "production_edit": False}
    audit = f"""# TASK_205 R2 — audit index\n\nCanonical Standard read in full: `{STANDARD}`; SHA-256 `{STD_SHA}`. AGENTS.md, Docs/rules.md, SO45_TO_V4_PLAN.md, config/state/locks/END and exact R2 task read. R2 task SHA `{TASK_SHA}`; target manifest SHA `{TARGET_SHA}`. Valid lease `{lease['lease_id']}`, fence `{lease['fencing_token']}`.\n\nImmutable R1 seal SHA `{R1_SEAL_SHA}` and CEO review fingerprint `{bindings['r1_review_fingerprint']}`. Rehashed all {inventory['files']} R1 report files, {inventory['code_files']} code files and {inventory['scratch_files']} scratch files, plus original SO, review and archived task. Replayed 126 effective raw instruction arrays against 126 original source arrays; two R1 corrections used as the effective arrays. `CORRECTED_COVERAGE.json` identifies all six empty NOP p-code positions; `R1_TO_R2_DELTA.json` maps each overclaim to the corrected interpretation.\n\nThis overlay is PARTIAL static research. The FDE ranges and C-like text do not prove unique source-function boundaries or runtime behavior. Two full-FDE metadata reconstructions remain transient assumptions, with R1's fresh-session rollback evidence retained. R1 evidence and original source remain immutable. No Ghidra rerun, production edit, commit or push.\n"""
    master = f"""# TASK_205 R2 — corrected p-code coverage\n\n**PARTIAL static research.** Across 126 pinned ImageCodec nonexport FDE candidates, source evidence contains **6,246 AArch64 instruction words**. The effective Ghidra arrays contain **6,246 instruction listings**, of which **6,240 contain at least one p-code operation**. Six listed NOPs have `pcode_ops: []`; the total **25,604 p-code operations** is unchanged.\n\nAffected candidates are one-based 380, 381 and 384. `CORRECTED_COVERAGE.json` gives the source word and database/source address of each empty NOP; `R1_TO_R2_DELTA.json` names the R1 fields and prose superseded by this correction. The 126 C-like outputs and original static 192 call and 1,087 branch sites are unchanged. We independently replayed every effective source/listing position from the immutable R1 raw files and rehashed the R1 seal inventory.\n\nBoundary limits remain: unwind FDEs need not be unique source functions; two candidates required transient full-FDE metadata for complete listings, and R1's separate fresh-session read was used to verify original metadata and memory after rollback. This is not a behavior proof, product Phase PASS, or V4 readiness claim.\n"""
    dump(R2 / "CORRECTED_COVERAGE.json", coverage)
    dump(R2 / "R1_TO_R2_DELTA.json", delta)
    atomic(R2 / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    atomic(R2 / "01_MASTER_REPORT.md", master.encode("utf-8"))
    dump(R2 / "PROGRESS.json", {"task_id": "TASK_205", "revision": 2, "status": "REPORTING",
                                 "generated_at": timestamp, "listings": listings, "nonempty_pcode_positions": nonempty,
                                 "empty_nop_positions": 6, "pcode_operations": ops})
    files = {p.relative_to(R2).as_posix(): sha(p) for p in R2.rglob("*") if p.is_file()
             and p.name not in ("COMPLETE.json", "PROGRESS.json")}
    require(set(files) == {"00_AUDIT_INDEX.md", "01_MASTER_REPORT.md", "CORRECTED_COVERAGE.json", "R1_TO_R2_DELTA.json"}, "R2 inventory")
    code_files = {SCRIPT.relative_to(ROOT).as_posix(): sha(SCRIPT)}
    complete = {"schema_version": "2.1.2", "task_id": "TASK_205", "revision": 2,
                "status": "COMPLETE", "research_result": "PARTIAL_BOUNDARY_TWO_TRANSIENT_FULL_FDE_METADATA",
                "generated_at": timestamp, "agent_id": lease["agent_id"], "lease_id": lease["lease_id"],
                "fencing_token": lease["fencing_token"], "standard_path": str(STANDARD),
                "standard_sha256": STD_SHA, "task_sha256": TASK_SHA,
                "target_manifest_sha256": TARGET_SHA, "original_so_sha256": SO_SHA,
                "r1_complete_sha256": R1_SEAL_SHA, "r1_review_fingerprint": bindings["r1_review_fingerprint"],
                "candidate_count": 126, "source_instruction_positions": source_words,
                "effective_ghidra_instruction_listings": listings,
                "effective_ghidra_positions_with_nonempty_pcode": nonempty,
                "effective_ghidra_positions_with_empty_pcode": 6,
                "effective_ghidra_pcode_operations": ops,
                "nonempty_c_like_outputs": clike, "static_call_instruction_sites": calls,
                "static_branch_instruction_sites": branches,
                "r1_report_files_hash_verified": inventory["files"],
                "r1_code_files_hash_verified": inventory["code_files"],
                "r1_scratch_files_hash_verified": inventory["scratch_files"],
                "r1_immutable": True, "ghidra_rerun": False, "production_edit": False,
                "files": files, "code_files": code_files, "scratch_files": {},
                "limits": "FDE boundaries/C-like output do not establish unique source functions or behavior; two full-FDE metadata reconstructions are explicitly transient boundary assumptions."}
    dump(R2 / "COMPLETE.json", complete)
    print(json.dumps({"r2_complete_sha256": sha(R2 / "COMPLETE.json"), "files": files,
                      "code_files": code_files, "coverage": {k: coverage[k] for k in
                      ("effective_ghidra_instruction_listings", "effective_ghidra_positions_with_nonempty_pcode",
                       "effective_ghidra_positions_with_empty_pcode", "effective_ghidra_pcode_operations")}}, indent=2))


if __name__ == "__main__":
    main()
