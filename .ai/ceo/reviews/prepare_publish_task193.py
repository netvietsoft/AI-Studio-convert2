"""Publish bounded MTFilterKernel next slice excluding four oversized FDEs."""

import copy
import datetime as dt
import hashlib
import json

from prepare_publish_tasks189_190 import ROOT, STANDARD_SHA, atomic_file, prepare
from controller import Controller, file_sha


SPEC = {"task": "TASK_193", "library": "libMTFilterKernel.so",
        "sha": "f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4",
        "selection": (192, 256), "totals": (2362, 2873, 511), "bytes": 94860,
        "assignee": "/root/so45_mtfilter_next", "dependency": ("TASK_189", 1),
        "project": "RESEARCH_WORK/TASK_189_R1/ghidra_project", "minutes": 90}
EXCLUDED = {201, 211, 216, 235}


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or file_sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") != STANDARD_SHA:
        raise RuntimeError("END requested or canonical standard changed")
    now = dt.datetime.now(dt.timezone.utc)
    manifest_path, original_raw, task_path, _, original_rows, deadline = prepare(SPEC, now)
    if {192 + i for i, row in enumerate(original_rows) if row["size_bytes"] > 4096} != EXCLUDED:
        raise RuntimeError("oversized candidate set changed")
    manifest = json.loads(original_raw)
    rows = []
    for global_index, row in enumerate(original_rows, 192):
        if global_index not in EXCLUDED:
            rows.append({"global_nonexport_fde_index": global_index, **row})
    if len(rows) != 60 or sum(r["size_bytes"] for r in rows) != 41532:
        raise RuntimeError("safe MTFilter candidate census changed")
    manifest["targets"] = rows
    manifest["selected_count"] = len(rows)
    manifest["selection"] = "sorted nonexport FDE indices 192..255, excluding 201,211,216,235"
    manifest["excluded_oversized_global_indices"] = sorted(EXCLUDED)
    manifest["excluded_oversized_bytes"] = 53328
    manifest["remaining_nonselected_candidates_after_slice"] = 511 - 192 - len(rows)
    manifest_raw = (json.dumps(manifest, ensure_ascii=False, indent=2) + "\n").encode("utf8")
    manifest_sha = hashlib.sha256(manifest_raw).hexdigest()
    stamp = now.isoformat(timespec="microseconds").replace("+00:00", "Z")
    task = SPEC["task"]
    report = f"RULES/REPORT/{task}_REPORT_R1"
    meta = {"schema_version": "2.1.2", "task_id": task, "revision": 1,
            "status": "ACTIVE", "assignee": SPEC["assignee"], "agent_id": SPEC["assignee"],
            "priority": "P1", "dependencies": [{"task_id": "TASK_189", "revision": 1}],
            "mode": "RESEARCH", "report_folder": report,
            "files_allowed": [f"{report}/**", "scripts/task_193_codex_internal/**", "RESEARCH_WORK/TASK_193_R1/**"],
            "files_forbidden": ["RULES/TASK/**", "SOURCE/**", ".ai/**", "app/**", "apps/**",
                                "lib-*/**", "Backend/**", "services/**", "packages/**"],
            "max_minutes": 90, "max_cpu": 1, "max_heap": "1G", "max_report_bytes": 134217728,
            "expected_lease_id": "LEASE-CEO-WORKER-TASK_193-R1", "standard_sha256": STANDARD_SHA,
            "source_libraries": {SPEC["library"]: {"sha256": SPEC["sha"], "defined_nonzero_export_vas": 2362}},
            "target_manifest_path": manifest_path.relative_to(ROOT).as_posix(),
            "target_manifest_sha256": manifest_sha, "target_candidate_count": len(rows),
            "authorization_reference": "Chairman Tony directs direct SO45 decoding with real Codex subagents, without AGY",
            "created_at": stamp, "budget_deadline_utc": deadline}
    body = f"""# TASK_193 R1 - bounded libMTFilterKernel.so nonexport FDE candidates

STATUS: ACTIVE
ASSIGNEE: {SPEC['assignee']}
PRIORITY: P1
MODIFIED_TIME: {stamp}

```json
{json.dumps(meta, ensure_ascii=False, indent=2)}
```

Process only the **60** exact VA-sorted nonexport FDE candidate rows in `.ai/ceo/reviews/TASK_193_internal_targets.json` SHA-256 `{manifest_sha}` from original `libMTFilterKernel.so` SHA-256 `{SPEC['sha']}`. These correspond to global zero-based indices 192..255 **excluding 201, 211, 216, 235**, which contain four oversized bodies totalling 53,328 bytes and are explicitly outside this lease. Do not silently count those four as analyzed. This task's 60 bodies total 41,532 bytes and 10,383 AArch64 positions; each body is at most 4,096 bytes. The accepted TASK_189 research covers earlier indices128..191 and is read-only. Reuse its analyzed project `RESEARCH_WORK/TASK_189_R1/ghidra_project` only after verifying all project hashes against its accepted sealed receipt.

An unwind FDE is a candidate range, not proof of complete unique source-function boundaries. Verify every target against original ELF FDE/PT_LOAD/body hashes and all source instruction positions. On a private byte-verified project copy, preserve raw per-candidate Ghidra memory hashes, every-byte function-body membership, missing/extra ranges, instruction/p-code coverage, C-like text/hash or failure, calls, exact command/log receipts and project before/after hashes. Mark ambiguous boundaries PARTIAL, preserve other functions' metadata. Transient correction is permitted only on nonoverlapping gaps, in a read-only project session with rollback and before/after memory proof. Use one CPU, 1 GiB heap, sequential <=20-minute headless processes and <=10 seconds per decompile. Independently recheck all critical claims and >=10% spread ordinary source instruction slots. Seal a truthful bounded report even if incomplete. Do not infer behavior/pixel parity, product Phase PASS, V4/P7, or all-45-SO completion.

Before any write fully read `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` and verify SHA-256 `{STANDARD_SHA}`. Also read AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task/manifest, config/state/locks/END and git status. Claim exact ACTIVE TASK_193 revision1 as `{SPEC['assignee']}` using expected lease `LEASE-CEO-WORKER-TASK_193-R1` before any write. Write only `{report}/**`, `scripts/task_193_codex_internal/**`, `RESEARCH_WORK/TASK_193_R1/**`; source SO, prior research, other lanes and P0 are read-only. Produce 00_AUDIT_INDEX.md canonical-read receipt, 01_MASTER_REPORT.md, raw evidence, PROGRESS and COMPLETE.json SHA-256 seal. No AGY, further subagents, self-review or commit/push before CEO independent review. Stop by {deadline}.
"""
    task_raw = body.encode("utf8")
    with ctl.transaction() as (registry, state):
        ceo = ctl.ceo_lease(registry)
        if not ctl.accepted("TASK_189", state, ctl.tasks(), required_revision=1):
            raise RuntimeError("TASK_189 dependency not accepted")
        if manifest_path.exists() or task_path.exists():
            raise RuntimeError("TASK_193 already prepared")
        ctl.authorized(ceo, manifest_path)
        updated = copy.deepcopy(registry)
        active = ctl.ceo_lease(updated)
        scope = "RULES/TASK/TASK_193*"
        if scope not in active["files_allowed"]:
            active["files_allowed"].append(scope)
            active.setdefault("scope_authorization_history", []).append({
                "at": now.isoformat(), "scope": scope,
                "authorization": "Chairman Tony direct Codex multi-lane remaining SO45 decoding, no AGY",
                "limits": "Bounded static research; four oversized FDEs excluded; P0/product/V4/P7 frozen"})
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
            raise RuntimeError("TASK_193 already configured")
        config["task_ids"].append(task)
        ctl.replace_json(config_path, config, registry, config_sha)
        ctl.event(state, "CODEX_INTERNAL_FDE_TASK_PUBLISHED", task_id=task,
                  assignee=SPEC["assignee"], source=SPEC["library"], target_count=len(rows),
                  manifest_sha256=manifest_sha, task_sha256=hashlib.sha256(task_raw).hexdigest(),
                  excluded_oversized_global_indices=sorted(EXCLUDED), deadline=deadline)
    print(json.dumps({"task_id": task, "assignee": SPEC["assignee"],
                      "source": SPEC["library"], "target_count": len(rows),
                      "instruction_slots": sum(row["instruction_slots"] for row in rows),
                      "max_target_bytes": max(row["size_bytes"] for row in rows),
                      "excluded_oversized_global_indices": sorted(EXCLUDED),
                      "task_sha256": file_sha(task_path),
                      "manifest_sha256": file_sha(manifest_path), "deadline": deadline}))


if __name__ == "__main__":
    main()
