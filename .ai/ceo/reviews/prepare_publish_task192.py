"""Publish the disjoint libPVGImageCodec Codex-only internal-FDE lane."""

import copy
import datetime as dt
import hashlib
import json

from prepare_publish_tasks189_190 import ROOT, STANDARD_SHA, atomic_file, prepare
from controller import Controller, file_sha


SPEC = {"task": "TASK_192", "library": "libPVGImageCodec.so",
        "sha": "7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b",
        "selection": (0, 64), "totals": (3326, 9981, 6655), "bytes": 8296,
        "assignee": "/root/so45_imagecodec_internal", "dependency": ("TASK_160", 1),
        "project": "RESEARCH_WORK/TASK_160_R1/libPVGImageCodec.so/ghidra_project", "minutes": 90}


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or file_sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") != STANDARD_SHA:
        raise RuntimeError("END requested or canonical standard changed")
    now = dt.datetime.now(dt.timezone.utc)
    manifest_path, manifest_raw, task_path, task_raw, rows, deadline = prepare(SPEC, now)
    task_raw = task_raw.replace(
        b"The accepted TASK_160 research covers an earlier, disjoint candidate slice; do not re-run it.",
        b"The accepted TASK_160 research covers exports only; it does not establish nonexport FDE coverage. Do not re-run its export slice.")
    if b"The accepted TASK_160 research covers exports only" not in task_raw:
        raise RuntimeError("task dependency wording replacement failed")
    with ctl.transaction() as (registry, state):
        ceo = ctl.ceo_lease(registry)
        if not ctl.accepted("TASK_160", state, ctl.tasks(), required_revision=1):
            raise RuntimeError("TASK_160 dependency not accepted")
        if manifest_path.exists() or task_path.exists():
            raise RuntimeError("TASK_192 already prepared")
        ctl.authorized(ceo, manifest_path)
        updated = copy.deepcopy(registry)
        active = ctl.ceo_lease(updated)
        scope = "RULES/TASK/TASK_192*"
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
        if "TASK_192" in config["task_ids"]:
            raise RuntimeError("TASK_192 already configured")
        config["task_ids"].append("TASK_192")
        ctl.replace_json(config_path, config, registry, config_sha)
        ctl.event(state, "CODEX_INTERNAL_FDE_TASK_PUBLISHED", task_id="TASK_192",
                  assignee=SPEC["assignee"], source=SPEC["library"],
                  target_count=len(rows), manifest_sha256=hashlib.sha256(manifest_raw).hexdigest(),
                  task_sha256=hashlib.sha256(task_raw).hexdigest(), deadline=deadline)
    print(json.dumps({"task_id": "TASK_192", "assignee": SPEC["assignee"],
                      "source": SPEC["library"], "target_count": len(rows),
                      "instruction_slots": sum(row["instruction_slots"] for row in rows),
                      "max_target_bytes": max(row["size_bytes"] for row in rows),
                      "task_sha256": file_sha(task_path),
                      "manifest_sha256": file_sha(manifest_path), "deadline": deadline}))


if __name__ == "__main__":
    main()
