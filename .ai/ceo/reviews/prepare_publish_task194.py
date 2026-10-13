"""Publish PVGColorFunctions next bounded slice, isolating one oversized FDE."""

import copy
import datetime as dt
import hashlib
import json

from prepare_publish_tasks189_190 import ROOT, STANDARD_SHA, atomic_file, prepare
from controller import Controller, file_sha


SPEC = {"task": "TASK_194", "library": "libPVGColorFunctions.so",
        "sha": "3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6",
        "selection": (448, 512), "totals": (81, 753, 672), "bytes": 23068,
        "assignee": "/root/so45_pvg_followon", "dependency": ("TASK_191", 1),
        "project": "RESEARCH_WORK/TASK_191_R1/ghidra_project", "minutes": 75}
EXCLUDED = {505}


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or file_sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") != STANDARD_SHA:
        raise RuntimeError("END requested or canonical standard changed")
    now = dt.datetime.now(dt.timezone.utc)
    manifest_path, original_raw, task_path, _, original_rows, deadline = prepare(SPEC, now)
    if {448 + i for i, row in enumerate(original_rows) if row["size_bytes"] > 4096} != EXCLUDED:
        raise RuntimeError("oversized PVG candidate set changed")
    manifest = json.loads(original_raw)
    rows = [{"global_nonexport_fde_index": index, **row}
            for index, row in enumerate(original_rows, 448) if index not in EXCLUDED]
    if len(rows) != 63 or sum(r["size_bytes"] for r in rows) != 18568:
        raise RuntimeError("safe PVG candidate census changed")
    manifest["targets"] = rows
    manifest["selected_count"] = 63
    manifest["selection"] = "sorted nonexport FDE indices 448..511, excluding oversized index 505"
    manifest["excluded_oversized_global_indices"] = [505]
    manifest["excluded_oversized_bytes"] = 4500
    manifest["remaining_nonselected_candidates_after_slice"] = 672 - 448 - 63
    manifest_raw = (json.dumps(manifest, ensure_ascii=False, indent=2) + "\n").encode("utf8")
    manifest_sha = hashlib.sha256(manifest_raw).hexdigest()
    stamp = now.isoformat(timespec="microseconds").replace("+00:00", "Z")
    task = "TASK_194"
    report = "RULES/REPORT/TASK_194_REPORT_R1"
    meta = {"schema_version": "2.1.2", "task_id": task, "revision": 1,
            "status": "ACTIVE", "assignee": SPEC["assignee"], "agent_id": SPEC["assignee"],
            "priority": "P1", "dependencies": [{"task_id": "TASK_191", "revision": 1}],
            "mode": "RESEARCH", "report_folder": report,
            "files_allowed": [f"{report}/**", "scripts/task_194_codex_internal/**", "RESEARCH_WORK/TASK_194_R1/**"],
            "files_forbidden": ["RULES/TASK/**", "SOURCE/**", ".ai/**", "app/**", "apps/**",
                                "lib-*/**", "Backend/**", "services/**", "packages/**"],
            "max_minutes": 75, "max_cpu": 1, "max_heap": "1G", "max_report_bytes": 134217728,
            "expected_lease_id": "LEASE-CEO-WORKER-TASK_194-R1", "standard_sha256": STANDARD_SHA,
            "source_libraries": {SPEC["library"]: {"sha256": SPEC["sha"], "defined_nonzero_export_vas": 81}},
            "target_manifest_path": manifest_path.relative_to(ROOT).as_posix(),
            "target_manifest_sha256": manifest_sha, "target_candidate_count": len(rows),
            "authorization_reference": "Chairman Tony directs direct SO45 decoding with real Codex subagents, without AGY",
            "created_at": stamp, "budget_deadline_utc": deadline}
    body = f"""# TASK_194 R1 - bounded libPVGColorFunctions.so nonexport FDE candidates

STATUS: ACTIVE
ASSIGNEE: {SPEC['assignee']}
PRIORITY: P1
MODIFIED_TIME: {stamp}

```json
{json.dumps(meta, ensure_ascii=False, indent=2)}
```

Process only the **63** exact VA-sorted nonexport FDE rows in `.ai/ceo/reviews/TASK_194_internal_targets.json` SHA-256 `{manifest_sha}` from original `libPVGColorFunctions.so` SHA-256 `{SPEC['sha']}`. They are global zero-based indices 448..511 **excluding index505** (VA0x3bc10, 4,500 bytes, 1,125 AArch64 slots) reserved for a separately bounded large-body task. Do not count index505 as analyzed. This lease's 63 targets total 18,568 bytes and 4,642 source instruction positions. Indices507,508,511 may be one-instruction stubs/thunks; do not claim they are complete unique source functions. Prior accepted TASK_191 covers earlier indices384..447. Its analyzed project `RESEARCH_WORK/TASK_191_R1/ghidra_project` is read-only input; verify copied-project hashes against its sealed receipt before reuse.

An unwind FDE is a candidate range, not proof of complete unique source-function boundaries. Verify original ELF FDE/PT_LOAD/body hashes and every source instruction position. On a private byte-verified Ghidra project copy, preserve raw memory hashes, every-byte body membership, missing/extra ranges, instruction/p-code and C-like text/hash or failure, calls, command/log receipts and project before/after hashes. Mark ambiguous boundaries PARTIAL; never remove metadata of another function. Transient correction is permitted only on nonoverlapping gaps, in read-only project sessions with rollback and before/after memory proof. Use one CPU, 1 GiB heap, sequential <=20-minute headless processes and <=10 seconds per decompile. Independently recheck all critical claims plus >=10% spread ordinary source instruction slots and seal a truthful bounded report. No behavior/pixel parity, product Phase PASS, V4/P7, or all-45-SO completion inference.

Before any write fully read `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` and verify SHA-256 `{STANDARD_SHA}`. Also read AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, PROJECT_ERROR.md, ACQUIREMENTS.md, this task/manifest, config/state/locks/END and git status. Claim exact ACTIVE TASK_194 revision1 as `{SPEC['assignee']}` via controller with lease `LEASE-CEO-WORKER-TASK_194-R1` before writes. Write only `{report}/**`, `scripts/task_194_codex_internal/**`, `RESEARCH_WORK/TASK_194_R1/**`; source SO, prior research, other lanes, P0 read-only. Create 00_AUDIT_INDEX.md canonical-read receipt, 01_MASTER_REPORT.md, raw evidence, PROGRESS, COMPLETE.json SHA-256 seal. No AGY, further subagents, self-review, commit or push before CEO independent review. Stop by {deadline}.
"""
    task_raw = body.encode("utf8")
    with ctl.transaction() as (registry, state):
        ceo = ctl.ceo_lease(registry)
        if not ctl.accepted("TASK_191", state, ctl.tasks(), required_revision=1):
            raise RuntimeError("TASK_191 dependency not accepted")
        if manifest_path.exists() or task_path.exists():
            raise RuntimeError("TASK_194 already prepared")
        ctl.authorized(ceo, manifest_path)
        updated = copy.deepcopy(registry)
        active = ctl.ceo_lease(updated)
        scope = "RULES/TASK/TASK_194*"
        if scope not in active["files_allowed"]:
            active["files_allowed"].append(scope)
            active.setdefault("scope_authorization_history", []).append({
                "at": now.isoformat(), "scope": scope,
                "authorization": "Chairman Tony direct Codex multi-lane remaining SO45 decoding, no AGY",
                "limits": "Bounded static research; oversized index505 excluded; P0/product/V4/P7 frozen"})
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
            raise RuntimeError("TASK_194 already configured")
        config["task_ids"].append(task)
        ctl.replace_json(config_path, config, registry, config_sha)
        ctl.event(state, "CODEX_INTERNAL_FDE_TASK_PUBLISHED", task_id=task,
                  assignee=SPEC["assignee"], source=SPEC["library"], target_count=len(rows),
                  manifest_sha256=manifest_sha, task_sha256=hashlib.sha256(task_raw).hexdigest(),
                  excluded_oversized_global_indices=[505], deadline=deadline)
    print(json.dumps({"task_id": task, "assignee": SPEC["assignee"],
                      "source": SPEC["library"], "target_count": len(rows),
                      "instruction_slots": sum(row["instruction_slots"] for row in rows),
                      "max_target_bytes": max(row["size_bytes"] for row in rows),
                      "excluded_oversized_global_indices": [505],
                      "task_sha256": file_sha(task_path),
                      "manifest_sha256": file_sha(manifest_path), "deadline": deadline}))


if __name__ == "__main__":
    main()
