"""Publish the last 32 PVGColorFunctions nonexport FDE candidates."""

import copy
import datetime as dt
import hashlib
import json

from prepare_publish_tasks189_190 import ROOT, STANDARD_SHA, atomic_file
from prepare_publish_tasks197_198 import prepare_one
from controller import Controller, file_sha


SPEC = {"task": "TASK_200", "library": "libPVGColorFunctions.so",
        "sha": "3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6",
        "selection": (640, 672), "totals": (81, 753, 672), "bytes": 14460,
        "expected_excluded": set(), "expected_selected": (32, 14460, 3615),
        "assignee": "/root/so45_pvg_followon", "dependency": ("TASK_198", 1),
        "project": "RESEARCH_WORK/TASK_198_R1/ghidra_project", "minutes": 90}


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or file_sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") != STANDARD_SHA:
        raise RuntimeError("END requested or canonical standard changed")
    now = dt.datetime.now(dt.timezone.utc)
    manifest_path, manifest_raw, task_path, task_raw, rows, deadline = prepare_one(SPEC, now)
    task_raw = task_raw.replace(
        b"TASK_196 left index 556 unanalysed and five boundary-PARTIAL rows; these remain open. ",
        b"TASK_196 left index 556 unanalysed and five boundary-PARTIAL rows; TASK_198 left indices 620 and 625 PARTIAL. These remain open. ")
    if b"TASK_198 left indices 620 and 625 PARTIAL" not in task_raw:
        raise RuntimeError("prior gap note not inserted")
    with ctl.transaction() as (registry, state):
        lease = ctl.ceo_lease(registry)
        if not ctl.accepted("TASK_198", state, ctl.tasks(), required_revision=1):
            raise RuntimeError("TASK_198 acceptance absent")
        if manifest_path.exists() or task_path.exists():
            raise RuntimeError("TASK_200 already exists")
        ctl.authorized(lease, manifest_path)
        updated = copy.deepcopy(registry)
        active = ctl.ceo_lease(updated)
        scope = "RULES/TASK/TASK_200*"
        if scope not in active["files_allowed"]:
            active["files_allowed"].append(scope)
            active.setdefault("scope_authorization_history", []).append({
                "at": now.isoformat(), "scope": scope,
                "authorization": "Chairman Tony direct Codex multi-lane remaining SO45 decoding, no AGY",
                "limits": "Bounded static research; P0/product/V4/P7 frozen"})
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
        if SPEC["task"] in config["task_ids"]:
            raise RuntimeError("TASK_200 already configured")
        config["task_ids"].append(SPEC["task"])
        ctl.replace_json(config_path, config, registry, config_sha)
        ctl.event(state, "CODEX_INTERNAL_FDE_TASK_PUBLISHED", task_id=SPEC["task"],
                  assignee=SPEC["assignee"], source=SPEC["library"], target_count=len(rows),
                  manifest_sha256=hashlib.sha256(manifest_raw).hexdigest(),
                  task_sha256=hashlib.sha256(task_raw).hexdigest(), deadline=deadline,
                  excluded_oversized_global_indices=[])
    print(json.dumps({"task_id": SPEC["task"], "assignee": SPEC["assignee"],
                      "target_count": len(rows), "instruction_slots": sum(r["instruction_slots"] for r in rows),
                      "task_sha256": file_sha(task_path), "manifest_sha256": file_sha(manifest_path),
                      "deadline": deadline}))


if __name__ == "__main__":
    main()
