"""Publish two disjoint Codex-only FDE slices after verified research gates."""

import copy
import datetime as dt
import hashlib
import json

from prepare_publish_tasks189_190 import ROOT, STANDARD_SHA, atomic_file, prepare
from controller import Controller, file_sha


SPECS = (
    {"task": "TASK_197", "library": "libMTFilterKernel.so",
     "sha": "f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4",
     "selection": (256, 320), "totals": (2362, 2873, 511), "bytes": 45232,
     "expected_excluded": {293, 304}, "expected_selected": (62, 33296, 8324),
     "assignee": "/root/so45_mtfilter_next", "dependency": ("TASK_193", 2),
     "project": "RESEARCH_WORK/TASK_193_R1/ghidra_project", "minutes": 90},
    {"task": "TASK_198", "library": "libPVGColorFunctions.so",
     "sha": "3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6",
     "selection": (576, 640), "totals": (81, 753, 672), "bytes": 12968,
     "expected_excluded": set(), "expected_selected": (64, 12968, 3242),
     "assignee": "/root/so45_pvg_followon", "dependency": ("TASK_196", 1),
     "project": "RESEARCH_WORK/TASK_196_R1/ghidra_project", "minutes": 90},
)


def prepare_one(spec, now):
    manifest_path, raw, task_path, _, original_rows, deadline = prepare(spec, now)
    begin, end = spec["selection"]
    excluded = {begin + i for i, row in enumerate(original_rows) if row["size_bytes"] > 4096}
    if excluded != spec["expected_excluded"]:
        raise RuntimeError(f"oversized candidate census changed for {spec['task']}: {excluded}")
    rows = [{"global_nonexport_fde_index": index, **row}
            for index, row in enumerate(original_rows, begin) if index not in excluded]
    totals = (len(rows), sum(row["size_bytes"] for row in rows),
              sum(row["instruction_slots"] for row in rows))
    if totals != spec["expected_selected"]:
        raise RuntimeError(f"selected source census changed for {spec['task']}: {totals}")
    manifest = json.loads(raw)
    manifest["targets"] = rows
    manifest["selected_count"] = len(rows)
    manifest["selection"] = f"sorted nonexport FDE global zero-based indices {begin}..{end-1}, excluding {sorted(excluded)}"
    manifest["excluded_oversized_global_indices"] = sorted(excluded)
    manifest["excluded_oversized_bytes"] = sum(original_rows[i-begin]["size_bytes"] for i in excluded)
    manifest["remaining_nonselected_candidates_after_slice"] = spec["totals"][2] - begin - len(rows)
    manifest_raw = (json.dumps(manifest, ensure_ascii=False, indent=2) + "\n").encode("utf8")
    manifest_sha = hashlib.sha256(manifest_raw).hexdigest()
    task = spec["task"]
    report = f"RULES/REPORT/{task}_REPORT_R1"
    stamp = now.isoformat(timespec="microseconds").replace("+00:00", "Z")
    dependency, revision = spec["dependency"]
    meta = {"schema_version": "2.1.2", "task_id": task, "revision": 1,
            "status": "ACTIVE", "assignee": spec["assignee"], "agent_id": spec["assignee"],
            "priority": "P1", "dependencies": [{"task_id": dependency, "revision": revision}],
            "mode": "RESEARCH", "report_folder": report,
            "files_allowed": [f"{report}/**", f"scripts/{task.lower()}_codex_internal/**",
                              f"RESEARCH_WORK/{task}_R1/**"],
            "files_forbidden": ["RULES/TASK/**", "SOURCE/**", ".ai/**", "app/**", "apps/**",
                                "lib-*/**", "Backend/**", "services/**", "packages/**"],
            "max_minutes": spec["minutes"], "max_cpu": 1, "max_heap": "1G",
            "max_report_bytes": 134217728,
            "expected_lease_id": f"LEASE-CEO-WORKER-{task}-R1",
            "standard_sha256": STANDARD_SHA,
            "source_libraries": {spec["library"]: {"sha256": spec["sha"],
                                                    "defined_nonzero_export_vas": spec["totals"][0]}},
            "target_manifest_path": manifest_path.relative_to(ROOT).as_posix(),
            "target_manifest_sha256": manifest_sha, "target_candidate_count": len(rows),
            "authorization_reference": "Chairman Tony directs direct SO45 decoding with real Codex subagents, without AGY",
            "created_at": stamp, "modified_time": stamp, "budget_deadline_utc": deadline}
    excluded_note = (f"Oversized indices {sorted(excluded)} remain unanalysed in this slice. "
                     if excluded else "No index in this slice exceeds 4,096 bytes. ")
    prior_note = ("TASK_193 R2 corrected labels on accepted R1 evidence; the R1 analyzed project is read-only input. "
                  if task == "TASK_197" else
                  "TASK_196 left index 556 unanalysed and five boundary-PARTIAL rows; these remain open. ")
    body = f"""# {task} R1 - bounded next {spec['library']} nonexport FDE candidates

STATUS: ACTIVE
ASSIGNEE: {spec['assignee']}
PRIORITY: P1
MODIFIED_TIME: {stamp}

```json
{json.dumps(meta, ensure_ascii=False, indent=2)}
```

Process only the {len(rows)} exact global zero-based VA-sorted nonexport FDE indices in `{meta['target_manifest_path']}` SHA-256 `{manifest_sha}` from original `{spec['library']}` SHA-256 `{spec['sha']}`. This slice is {begin}..{end-1}, excluding {sorted(excluded)}; it contains {totals[1]:,} bytes and {totals[2]:,} AArch64 instruction positions. {excluded_note}{prior_note}Do not count excluded, earlier or partial rows as solved. Accepted {dependency} R{revision} is the prior disjoint dependency; verify all hashes of `{spec['project']}` against its sealed evidence before making a private byte-verified copy.

An unwind FDE is a candidate range, not proof of a complete unique source function. Verify original ELF FDE/dynsym/PT_LOAD/body hashes, every source instruction position, and nonoverlap. On a private Ghidra project copy collect one raw result per target: memory hash, exact every-byte function-body membership, missing/extra ranges, instruction/p-code coverage, C-like text/hash or failure, calls, command/log receipts, and before/after project hashes. Mark ambiguous boundaries PARTIAL. Transient correction is allowed only on nonoverlapping gaps with fresh-session rollback and memory proof; never erase other function metadata. Use one CPU, 1 GiB heap, sequential <=20-minute headless jobs, <=10 seconds per decompile and the original absolute deadline. Independently recheck every critical claim and >=10% spread ordinary source positions; seal truthful partial results if incomplete. No behavior/pixel parity, product Phase PASS, V4/P7 or all-45-SO completion inference.

Before any write fully read `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` and verify SHA-256 `{STANDARD_SHA}`. Also read AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task and manifest, config/state/locks/END and git status. Claim exact ACTIVE {task} R1 as `{spec['assignee']}` using `{meta['expected_lease_id']}` before writes. Write only `{report}/**`, `scripts/{task.lower()}_codex_internal/**`, `RESEARCH_WORK/{task}_R1/**`; SO, prior research, other lanes and P0 are read-only. Create `00_AUDIT_INDEX.md` canonical-read receipt, `01_MASTER_REPORT.md`, raw per-candidate and command/log evidence, `PROGRESS.json`, and SHA-256 sealed `COMPLETE.json`. No AGY, further subagents, self-review, commit or push before CEO independent review. Stop by {deadline}.
"""
    return manifest_path, manifest_raw, task_path, body.encode("utf8"), rows, deadline


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or file_sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") != STANDARD_SHA:
        raise RuntimeError("END requested or canonical standard changed")
    now = dt.datetime.now(dt.timezone.utc)
    prepared = [(spec, *prepare_one(spec, now)) for spec in SPECS]
    with ctl.transaction() as (registry, state):
        lease = ctl.ceo_lease(registry)
        tasks = ctl.tasks()
        for spec, manifest_path, _, task_path, _, _, _ in prepared:
            dependency, revision = spec["dependency"]
            if not ctl.accepted(dependency, state, tasks, required_revision=revision):
                raise RuntimeError("dependency not accepted: " + dependency)
            if manifest_path.exists() or task_path.exists():
                raise RuntimeError("task already prepared: " + spec["task"])
            ctl.authorized(lease, manifest_path)
        updated = copy.deepcopy(registry)
        active = ctl.ceo_lease(updated)
        for spec, *_ in prepared:
            scope = f"RULES/TASK/{spec['task']}*"
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
        for spec, manifest_path, manifest_raw, task_path, task_raw, _, _ in prepared:
            ctl.authorized(ctl.ceo_lease(registry), task_path)
            atomic_file(manifest_path, manifest_raw)
            atomic_file(task_path, task_raw)
        config_path = ROOT / ".ai/ceo/config.json"
        config_sha = file_sha(config_path)
        config = ctl.read_json(config_path)
        for spec, *_ in prepared:
            if spec["task"] in config["task_ids"]:
                raise RuntimeError("task already configured: " + spec["task"])
            config["task_ids"].append(spec["task"])
        ctl.replace_json(config_path, config, registry, config_sha)
        for spec, _, manifest_raw, _, task_raw, rows, deadline in prepared:
            ctl.event(state, "CODEX_INTERNAL_FDE_TASK_PUBLISHED", task_id=spec["task"],
                      assignee=spec["assignee"], source=spec["library"],
                      target_count=len(rows), manifest_sha256=hashlib.sha256(manifest_raw).hexdigest(),
                      task_sha256=hashlib.sha256(task_raw).hexdigest(), deadline=deadline,
                      excluded_oversized_global_indices=sorted(spec["expected_excluded"]))
    print(json.dumps([{"task_id": spec["task"], "assignee": spec["assignee"],
                       "target_count": len(rows), "instruction_slots": sum(r["instruction_slots"] for r in rows),
                       "task_sha256": file_sha(task_path), "manifest_sha256": file_sha(manifest_path),
                       "deadline": deadline} for spec, manifest_path, _, task_path, _, rows, deadline in prepared]))


if __name__ == "__main__":
    main()
