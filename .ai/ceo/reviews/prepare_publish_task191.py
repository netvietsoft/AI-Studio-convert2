"""Publish the next exact PVGColorFunctions Codex-only FDE lane."""
import copy
import datetime as dt
import hashlib
import json

from prepare_publish_tasks189_190 import ROOT, STANDARD_SHA, atomic_file, prepare
from controller import Controller, file_sha

SPEC = {"task": "TASK_191", "library": "libPVGColorFunctions.so",
        "sha": "3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6",
        "selection": (384, 448), "totals": (81, 753, 672), "bytes": 27848,
        "assignee": "/root/so45_pvg_followon", "dependency": ("TASK_190", 1),
        "project": "RESEARCH_WORK/TASK_190_R1/ghidra_project", "minutes": 90}


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or file_sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") != STANDARD_SHA:
        raise RuntimeError("END requested or canonical standard changed")
    now = dt.datetime.now(dt.timezone.utc)
    manifest_path, manifest_raw, task_path, task_raw, rows, deadline = prepare(SPEC, now)
    with ctl.transaction() as (registry, state):
        ceo = ctl.ceo_lease(registry)
        if not ctl.accepted("TASK_190", state, ctl.tasks(), required_revision=1):
            raise RuntimeError("TASK_190 dependency not accepted")
        if manifest_path.exists() or task_path.exists():
            raise RuntimeError("TASK_191 already prepared")
        ctl.authorized(ceo, manifest_path)
        updated = copy.deepcopy(registry)
        active = ctl.ceo_lease(updated)
        scope = "RULES/TASK/TASK_191*"
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
        if "TASK_191" in config["task_ids"]:
            raise RuntimeError("TASK_191 already configured")
        config["task_ids"].append("TASK_191")
        ctl.replace_json(config_path, config, registry, config_sha)
        ctl.event(state, "CODEX_INTERNAL_FDE_TASK_PUBLISHED", task_id="TASK_191",
                  assignee=SPEC["assignee"], source=SPEC["library"],
                  target_count=len(rows), manifest_sha256=hashlib.sha256(manifest_raw).hexdigest(),
                  task_sha256=hashlib.sha256(task_raw).hexdigest(), deadline=deadline)
    print(json.dumps({"task_id": "TASK_191", "assignee": SPEC["assignee"],
                      "source": SPEC["library"], "target_count": len(rows),
                      "instruction_slots": sum(row["instruction_slots"] for row in rows),
                      "max_target_bytes": max(row["size_bytes"] for row in rows),
                      "task_sha256": file_sha(task_path),
                      "manifest_sha256": file_sha(manifest_path), "deadline": deadline}))


if __name__ == "__main__":
    main()
