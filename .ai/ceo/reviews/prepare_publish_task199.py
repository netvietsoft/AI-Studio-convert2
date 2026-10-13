"""Publish the next bounded ImageCodec FDE slice to a real Codex worker."""

import copy
import datetime as dt
import hashlib
import json

from prepare_publish_tasks189_190 import ROOT, STANDARD_SHA, atomic_file, prepare
from controller import Controller, file_sha


SPEC = {"task": "TASK_199", "library": "libPVGImageCodec.so",
        "sha": "7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b",
        "selection": (128, 192), "totals": (3326, 9981, 6655), "bytes": 74224,
        "assignee": "/root/so45_imagecodec_internal", "dependency": ("TASK_195", 1),
        "project": "RESEARCH_WORK/TASK_195_R1/ghidra_project", "minutes": 90}
EXCLUDED = {158, 168, 174, 191}
EXPECTED_SELECTED = (60, 44208, 11052)


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or file_sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") != STANDARD_SHA:
        raise RuntimeError("END requested or canonical standard changed")
    now = dt.datetime.now(dt.timezone.utc)
    manifest_path, raw, task_path, _, original_rows, deadline = prepare(SPEC, now)
    begin, end = SPEC["selection"]
    oversized = {begin + i for i, row in enumerate(original_rows) if row["size_bytes"] > 4096}
    if oversized != EXCLUDED:
        raise RuntimeError(f"oversized census changed: {oversized}")
    rows = [{"global_nonexport_fde_index": index, **row}
            for index, row in enumerate(original_rows, begin) if index not in EXCLUDED]
    totals = (len(rows), sum(r["size_bytes"] for r in rows), sum(r["instruction_slots"] for r in rows))
    if totals != EXPECTED_SELECTED:
        raise RuntimeError(f"selected source census changed: {totals}")
    manifest = json.loads(raw)
    manifest["targets"] = rows
    manifest["selected_count"] = len(rows)
    manifest["selection"] = f"sorted nonexport FDE global zero-based indices {begin}..{end-1}, excluding {sorted(EXCLUDED)}"
    manifest["excluded_oversized_global_indices"] = sorted(EXCLUDED)
    manifest["excluded_oversized_bytes"] = sum(original_rows[i-begin]["size_bytes"] for i in EXCLUDED)
    manifest["remaining_nonselected_candidates_after_slice"] = SPEC["totals"][2] - begin - len(rows)
    manifest_raw = (json.dumps(manifest, ensure_ascii=False, indent=2) + "\n").encode("utf8")
    manifest_sha = hashlib.sha256(manifest_raw).hexdigest()
    task, assignee = SPEC["task"], SPEC["assignee"]
    report = f"RULES/REPORT/{task}_REPORT_R1"
    stamp = now.isoformat(timespec="microseconds").replace("+00:00", "Z")
    meta = {"schema_version": "2.1.2", "task_id": task, "revision": 1,
            "status": "ACTIVE", "assignee": assignee, "agent_id": assignee,
            "priority": "P1", "dependencies": [{"task_id": "TASK_195", "revision": 1}],
            "mode": "RESEARCH", "report_folder": report,
            "files_allowed": [f"{report}/**", "scripts/task_199_codex_internal/**",
                              "RESEARCH_WORK/TASK_199_R1/**"],
            "files_forbidden": ["RULES/TASK/**", "SOURCE/**", ".ai/**", "app/**", "apps/**",
                                "lib-*/**", "Backend/**", "services/**", "packages/**"],
            "max_minutes": 90, "max_cpu": 1, "max_heap": "1G", "max_report_bytes": 134217728,
            "expected_lease_id": "LEASE-CEO-WORKER-TASK_199-R1",
            "standard_sha256": STANDARD_SHA,
            "source_libraries": {SPEC["library"]: {"sha256": SPEC["sha"],
                                                   "defined_nonzero_export_vas": 3326}},
            "target_manifest_path": manifest_path.relative_to(ROOT).as_posix(),
            "target_manifest_sha256": manifest_sha, "target_candidate_count": len(rows),
            "authorization_reference": "Chairman Tony directs direct SO45 decoding with real Codex subagents, without AGY",
            "created_at": stamp, "modified_time": stamp, "budget_deadline_utc": deadline}
    body = f"""# TASK_199 R1 - bounded next libPVGImageCodec.so nonexport FDE candidates

STATUS: ACTIVE
ASSIGNEE: {assignee}
PRIORITY: P1
MODIFIED_TIME: {stamp}

```json
{json.dumps(meta, ensure_ascii=False, indent=2)}
```

Process only the 60 exact global zero-based VA-sorted nonexport FDE indices in `{meta['target_manifest_path']}` SHA-256 `{manifest_sha}` from original `libPVGImageCodec.so` SHA-256 `{SPEC['sha']}`. The slice is 128..191 excluding oversized {sorted(EXCLUDED)} (30,016 excluded bytes); selected targets contain 44,208 bytes and 11,052 AArch64 source instruction positions. Excluded indices remain unanalysed. Accepted TASK_195 R1 is the prior disjoint slice; its sealed Ghidra project `{SPEC['project']}` is read-only input. Verify all nine project hashes from that task's seal before using a private byte-verified copy. Do not count earlier, excluded or partial rows as solved.

An unwind FDE is only a candidate range, not proof of a complete unique source function. Verify original ELF FDE/dynsym/PT_LOAD/body hashes, every source instruction position, and nonoverlap. On a private Ghidra project copy collect one raw result per target: memory hash, exact every-byte function-body membership, missing/extra ranges, instruction/p-code coverage, C-like text/hash or failure, calls, command/log receipts, and before/after project hashes. Mark ambiguous boundaries PARTIAL. Transient correction is allowed only on nonoverlapping gaps with fresh-session rollback and memory proof; never erase other function metadata. Use one CPU, 1 GiB heap, sequential <=20-minute headless jobs, <=10 seconds per decompile and the original absolute deadline. Independently recheck every critical claim and >=10% spread ordinary source positions; seal truthful partial results if incomplete. No behavior/pixel parity, product Phase PASS, V4/P7 or all-45-SO completion inference.

Before any write fully read `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` and verify SHA-256 `{STANDARD_SHA}`. Also read AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task and manifest, config/state/locks/END and git status. Claim exact ACTIVE TASK_199 R1 as `{assignee}` using `LEASE-CEO-WORKER-TASK_199-R1` before writes. Write only `{report}/**`, `scripts/task_199_codex_internal/**`, `RESEARCH_WORK/TASK_199_R1/**`; SO, prior research, other lanes and P0 are read-only. Create `00_AUDIT_INDEX.md` canonical-read receipt, `01_MASTER_REPORT.md`, raw per-candidate and command/log evidence, `PROGRESS.json`, and SHA-256 sealed `COMPLETE.json`. No AGY, further subagents, self-review, commit or push before CEO independent review. Stop by {deadline}.
"""
    task_raw = body.encode("utf8")
    with ctl.transaction() as (registry, state):
        lease = ctl.ceo_lease(registry)
        if not ctl.accepted("TASK_195", state, ctl.tasks(), required_revision=1):
            raise RuntimeError("TASK_195 acceptance absent")
        if manifest_path.exists() or task_path.exists():
            raise RuntimeError("TASK_199 already exists")
        ctl.authorized(lease, manifest_path)
        updated = copy.deepcopy(registry)
        active = ctl.ceo_lease(updated)
        scope = "RULES/TASK/TASK_199*"
        if scope not in active["files_allowed"]:
            active["files_allowed"].append(scope)
            active.setdefault("scope_authorization_history", []).append({
                "at": now.isoformat(), "scope": scope,
                "authorization": "Chairman Tony direct Codex multi-lane remaining SO45 decoding, no AGY",
                "limits": "Bounded static research; oversized excluded; P0/product/V4/P7 frozen"})
        updated["revision"] = registry["revision"] + 1
        updated["updated_at"] = now.isoformat()
        ctl.replace_json(ctl.registry, updated, registry)
        registry.clear()
        registry.update(updated)
        ctl.authorized(ctl.ceo_lease(registry), task_path)
        atomic_file(manifest_path, manifest_raw)
        atomic_file(task_path, task_raw)
        config_path = ROOT / ".ai/ceo/config.json"
        config_sha = file_sha(config_path)
        config = ctl.read_json(config_path)
        if task in config["task_ids"]:
            raise RuntimeError("TASK_199 already configured")
        config["task_ids"].append(task)
        ctl.replace_json(config_path, config, registry, config_sha)
        ctl.event(state, "CODEX_INTERNAL_FDE_TASK_PUBLISHED", task_id=task,
                  assignee=assignee, source=SPEC["library"], target_count=len(rows),
                  manifest_sha256=manifest_sha, task_sha256=hashlib.sha256(task_raw).hexdigest(),
                  deadline=deadline, excluded_oversized_global_indices=sorted(EXCLUDED))
    print(json.dumps({"task_id": task, "assignee": assignee, "target_count": len(rows),
                      "instruction_slots": totals[2], "task_sha256": file_sha(task_path),
                      "manifest_sha256": file_sha(manifest_path), "deadline": deadline}))


if __name__ == "__main__":
    main()
