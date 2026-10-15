"""Activate the next three disjoint SO45 FDE batches under the CEO lease."""
from __future__ import annotations

import datetime as dt
import hashlib
import importlib.util
import json
import os
import sys
import uuid
from pathlib import Path

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
spec = importlib.util.spec_from_file_location("ceo_controller", ROOT / ".ai/ceo/controller.py")
module = importlib.util.module_from_spec(spec)
assert spec.loader is not None
spec.loader.exec_module(module)
sys.path.insert(0, str(ROOT / "scripts/task_174_codex_exports"))
from unwind import parse_unwind  # type: ignore

STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
SOURCE_DIR = ROOT.parent / "SOURCE/extracted_native_libs/lib/arm64-v8a"
SPECS = (
    ("TASK_217", "/root/audit_157_158", "libAIModelSearchKit.so",
     "20233f05b4b010280d16e728103a0995ca2580697b5f9c708fa333e9ff8d1899", "TASK_214", 255),
    ("TASK_218", "/root/audit_210", "libPVGCodec.so",
     "4fa5f275c8ddecf7caa960c812108ec9e801365bfe5bc9cf38598233bc449ffc", "TASK_215", 260),
    ("TASK_219", "/root/audit_208", "libPVGImageCodec.so",
     "7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b", "TASK_216", 640),
)


def atomic_text(path: Path, value: str) -> None:
    temp = ROOT / ".ai" / f"locks.ceo.{uuid.uuid4().hex}.tmp"
    with temp.open("x", encoding="utf-8", newline="\n") as stream:
        stream.write(value)
        stream.flush()
        os.fsync(stream.fileno())
    os.replace(temp, path)


def manifest(tid: str, library: str, expected_sha: str, prior_last: int) -> tuple[str, str]:
    source = SOURCE_DIR / library
    data = source.read_bytes()
    if hashlib.sha256(data).hexdigest() != expected_sha:
        raise RuntimeError(f"source changed: {library}")
    unwind = parse_unwind(data)
    with source.open("rb") as stream:
        elf = ELFFile(stream)
        if elf["e_machine"] != "EM_AARCH64":
            raise RuntimeError("non-AArch64 source")
        dynsym = elf.get_section_by_name(".dynsym")
        if dynsym is None:
            raise RuntimeError("missing dynsym")
        exports = {int(s["st_value"]) for s in dynsym.iter_symbols()
                   if s["st_info"]["type"] == "STT_FUNC" and s["st_shndx"] != "SHN_UNDEF"
                   and int(s["st_size"]) > 0 and int(s["st_value"]) != 0}
    candidates = sorted((r for r in unwind["records"] if r["function_va"] not in exports),
                        key=lambda r: r["function_va"])
    eligible = [(i, r) for i, r in enumerate(candidates) if i > prior_last
                and 0 < r["function_size"] <= 4096 and r["function_size"] % 4 == 0
                and r["body_complete_in_input"]]
    selected = eligible[:128]
    if len(selected) != 128:
        raise RuntimeError(f"insufficient selected ranges: {library}")
    targets = [
        {"global_index": i, "elf_va": hex(r["function_va"]), "size_bytes": r["function_size"],
         "file_offset": hex(r["body_file_offset"]), "body_sha256": r["retained_body_sha256"],
         "instruction_slots": r["function_size"] // 4}
        for i, r in selected
    ]
    skipped = [
        {"global_index": i, "elf_va": hex(r["function_va"]), "size_bytes": r["function_size"]}
        for i, r in enumerate(candidates)
        if prior_last < i <= selected[-1][0] and i not in {x for x, _ in selected}
    ]
    out = {
        "schema_version": "2.1.2", "task_id": tid, "revision": 1,
        "classification": "FDE_START_ABSENT_DEFINED_NONZERO_DYNSYM_STT_FUNC_EXPORT",
        "source_library": library, "source_sha256": expected_sha,
        "all_fde_ranges": unwind["fde_table_count"], "defined_nonzero_export_vas": len(exports),
        "all_nonexport_fde_candidates": len(candidates),
        "selection": f"next 128 complete <=4096-byte VA-sorted nonexport FDE spans after index {prior_last}",
        "prior_last_selected_global_index": prior_last, "selected_count": len(targets),
        "last_selected_global_index": selected[-1][0],
        "skipped_in_slice": skipped, "targets": targets,
        "limits": "FDE spans are candidates, not proven function boundaries or behavior",
    }
    text = json.dumps(out, ensure_ascii=False, indent=2) + "\n"
    return text, hashlib.sha256(text.encode()).hexdigest()


def main() -> None:
    c = module.Controller(ROOT)
    if module.file_sha(ROOT / module.STANDARD) != STANDARD_SHA or c.end_requested():
        raise RuntimeError("canonical Standard changed or END requested")
    prepared = {}
    for tid, agent, lib, sha, dependency, prior in SPECS:
        if dependency == "TASK_211":
            previous = json.loads((ROOT / ".ai/ceo/reviews/TASK_208_internal_targets.json").read_text(encoding="utf-8"))
            actual_prior = previous["targets"][-1]["global_nonexport_fde_index"]
        else:
            previous = json.loads((ROOT / f".ai/ceo/reviews/{dependency}_internal_targets.json").read_text(encoding="utf-8"))
            actual_prior = previous["targets"][-1]["global_index"]
        if actual_prior != prior:
            raise RuntimeError(f"prior selection shifted: {tid}")
        prepared[tid] = manifest(tid, lib, sha, prior)
    now = dt.datetime.now(dt.timezone.utc)
    stamp = now.isoformat()
    deadline = (now + dt.timedelta(minutes=120)).isoformat()
    task_files = {}
    for tid, agent, lib, sha, dep, prior in SPECS:
        manifest_path = f".ai/ceo/reviews/{tid}_internal_targets.json"
        meta = {
            "schema_version": "2.1.2", "task_id": tid, "revision": 1, "status": "ACTIVE",
            "assignee": agent, "agent_id": agent, "priority": "P1", "mode": "RESEARCH",
            "dependencies": [{"task_id": dep, "revision": 1}],
            "report_folder": f"RULES/REPORT/{tid}_REPORT_R1",
            "files_allowed": [f"RULES/REPORT/{tid}_REPORT_R1/**",
                              f"scripts/{tid.lower()}_codex_internal/**",
                              f"RESEARCH_WORK/{tid}_R1/**"],
            "files_forbidden": ["RULES/TASK/**", "SOURCE/**", ".ai/**", "app/**", "apps/**",
                                "lib-*/**", "Backend/**", "services/**", "packages/**"],
            "max_minutes": 120, "max_cpu": 1, "max_heap": "1G",
            "max_per_decompile_seconds": 15, "max_report_bytes": 134217728,
            "expected_lease_id": f"LEASE-CEO-WORKER-{tid}-R1",
            "standard_sha256": STANDARD_SHA,
            "source_libraries": {lib: {"sha256": sha}},
            "target_candidate_count": 128,
            "authorization_reference": "Chairman Tony direct instruction to finish SO45 decoding without AGY; bounded research only",
            "created_at": stamp, "modified_time": stamp, "budget_deadline_utc": deadline,
            "target_manifest_path": manifest_path,
            "target_manifest_sha256": prepared[tid][1],
        }
        body = (
            f"# {tid} R1 - bounded {lib} continuation\n\nSTATUS: ACTIVE\nASSIGNEE: {agent}\n"
            f"PRIORITY: P1\nMODIFIED_TIME: {stamp}\n\n```json\n"
            f"{json.dumps(meta, ensure_ascii=False, indent=2)}\n```\n\n"
            f"Research only the exact 128 previously unselected nonexport FDE candidates in the CEO manifest "
            f"after prior global index {prior}. Reverify original ELF/PT_LOAD/FDE bytes and all ARM64 slots. "
            "Use a private bounded Ghidra project (one CPU, 1 GiB heap, <=15 seconds per decompile). "
            "Capture byte membership, listing/p-code, raw C-like or failure, logs and unchanged project hashes. "
            "Independently recheck >=10% spread ordinary provenance. Keep all skipped oversized candidates "
            "explicitly pending. A C-like output is static research, not exact source or behavior proof. "
            "Seal truthful PARTIAL results if any target is unresolved.\n\n"
            f"Before any write fully read the canonical Standard at {ROOT / module.STANDARD} "
            f"(SHA-256 {STANDARD_SHA}), AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, "
            f"PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task and manifest, config/state/locks/END "
            f"and git status. Claim exact ACTIVE {tid} R1 as {agent} via "
            f"{meta['expected_lease_id']} before writing. Write only files_allowed; prior reports and "
            "source are read-only. Report canonical path and SHA in 00_AUDIT_INDEX.md. No AGY, child agents, "
            "self-review, commit or push before independent CEO review. Stop at absolute deadline.\n"
        )
        task_files[ROOT / "RULES/TASK" / f"{tid}_SO45_INTERNAL_CONTINUATION_ACTIVE.md"] = body
    initial = c.read_json(c.registry)
    c.ceo_lease(initial)
    with module.guard(c.home / "control.guard"), module.guard(ROOT / ".ai/locks.registry.guard"):
        registry = c.read_json(c.registry)
        lease = c.ceo_lease(registry)
        config = c.read_json(c.home / "config.json")
        state = c.read_json(c.state_path)
        existing_tasks = c.tasks()
        if any(not c.accepted(dep, state, existing_tasks, 1) for *_, dep, _ in SPECS):
            raise RuntimeError("dependency acceptance stale")
        if any(tid in config["task_ids"] for tid, *_ in SPECS):
            raise RuntimeError("task ID already configured")
        outputs = list(task_files) + [ROOT / f".ai/ceo/reviews/{tid}_internal_targets.json" for tid in prepared]
        if any(path.exists() for path in outputs):
            raise RuntimeError("task output already exists")
        updated = json.loads(json.dumps(registry))
        ceo = next(x for x in updated["active_locks"] if x["lease_id"] == module.CEO_LEASE)
        for tid, *_ in SPECS:
            scope = f"RULES/TASK/{tid}*"
            ceo["files_allowed"].append(scope)
            ceo.setdefault("scope_extensions", []).append({
                "at": stamp, "scope": scope, "authorization": "Tony direct SO45 continuation without AGY",
                "limits": "research only; P0/product/V4/P7 frozen"})
            config["task_ids"].append(tid)
        updated["revision"] += 1
        updated["updated_at"] = stamp
        config_sha = module.file_sha(c.home / "config.json")
        c.replace_json(c.registry, updated, registry)
        c.replace_json(c.home / "config.json", config, updated, config_sha)
        for tid, (text, _) in prepared.items():
            path = ROOT / f".ai/ceo/reviews/{tid}_internal_targets.json"
            c.authorized(ceo, path)
            atomic_text(path, text)
        for path, text in task_files.items():
            c.authorized(ceo, path)
            atomic_text(path, text)
    print(json.dumps({"tasks": [s[0] for s in SPECS], "deadline": deadline,
                      "ceo_fence": lease["fencing_token"],
                      "manifests": {tid: sha for tid, (_, sha) in prepared.items()}}, indent=2))


if __name__ == "__main__":
    main()
