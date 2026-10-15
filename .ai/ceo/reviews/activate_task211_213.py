"""Publish three disjoint, bounded SO45 continuation tasks under the CEO lease."""
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
SOURCES = {
    "libPVGImageCodec.so": "7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b",
    "libAIModelSearchKit.so": "20233f05b4b010280d16e728103a0995ca2580697b5f9c708fa333e9ff8d1899",
    "libPVGCodec.so": "4fa5f275c8ddecf7caa960c812108ec9e801365bfe5bc9cf38598233bc449ffc",
}


def atomic_text(path: Path, value: str) -> None:
    temp = ROOT / ".ai" / f"locks.ceo.{uuid.uuid4().hex}.tmp"
    with temp.open("x", encoding="utf-8", newline="\n") as stream:
        stream.write(value)
        stream.flush()
        os.fsync(stream.fileno())
    os.replace(temp, path)


def internal_manifest(task_id: str, library: str) -> tuple[str, str]:
    path = SOURCE_DIR / library
    data = path.read_bytes()
    if hashlib.sha256(data).hexdigest() != SOURCES[library]:
        raise RuntimeError(f"source changed: {library}")
    unwind = parse_unwind(data)
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        if elf["e_machine"] != "EM_AARCH64":
            raise RuntimeError("non-AArch64 input")
        dynsym = elf.get_section_by_name(".dynsym")
        if dynsym is None:
            raise RuntimeError("missing .dynsym")
        exports = {int(s["st_value"]) for s in dynsym.iter_symbols()
                   if s["st_info"]["type"] == "STT_FUNC"
                   and s["st_shndx"] != "SHN_UNDEF"
                   and int(s["st_size"]) > 0 and int(s["st_value"]) != 0}
    candidates = sorted((r for r in unwind["records"] if r["function_va"] not in exports),
                        key=lambda r: r["function_va"])
    selected = [(i, r) for i, r in enumerate(candidates)
                if 0 < r["function_size"] <= 4096 and r["body_complete_in_input"]][:128]
    if len(selected) != 128:
        raise RuntimeError(f"insufficient bounded candidates: {library}")
    skipped = [{"global_index": i, "elf_va": hex(r["function_va"]),
                "size_bytes": r["function_size"]}
               for i, r in enumerate(candidates[:selected[-1][0] + 1])
               if i not in {n for n, _ in selected}]
    targets = []
    for i, r in selected:
        targets.append({"global_index": i, "elf_va": hex(r["function_va"]),
                        "size_bytes": r["function_size"],
                        "file_offset": hex(r["body_file_offset"]),
                        "body_sha256": r["retained_body_sha256"],
                        "instruction_slots": r["function_size"] // 4})
    manifest = {"schema_version": "2.1.2", "task_id": task_id, "revision": 1,
                "classification": "FDE_START_ABSENT_DEFINED_NONZERO_DYNSYM_STT_FUNC_EXPORT",
                "source_library": library, "source_sha256": SOURCES[library],
                "all_fde_ranges": unwind["fde_table_count"],
                "defined_nonzero_export_vas": len(exports),
                "all_nonexport_fde_candidates": len(candidates),
                "selection": "first 128 VA-sorted complete nonexport FDE spans <=4096 bytes",
                "selected_count": len(targets), "last_selected_global_index": selected[-1][0],
                "skipped_before_last_selected": skipped, "targets": targets,
                "limits": "FDE spans are candidates, not proven function boundaries or behavior"}
    text = json.dumps(manifest, ensure_ascii=False, indent=2) + "\n"
    return text, hashlib.sha256(text.encode("utf-8")).hexdigest()


def task_meta(task_id: str, agent: str, library: str, stamp: str,
              deadline: str, manifest_path: str | None, manifest_sha: str | None) -> dict:
    meta = {
        "schema_version": "2.1.2", "task_id": task_id, "revision": 1, "status": "ACTIVE",
        "assignee": agent, "agent_id": agent, "priority": "P1", "mode": "RESEARCH",
        "dependencies": [{"task_id": "TASK_205", "revision": 2}] if task_id == "TASK_211" else
                        [{"task_id": "TASK_157" if task_id == "TASK_212" else "TASK_158", "revision": 1}],
        "report_folder": f"RULES/REPORT/{task_id}_REPORT_R1",
        "files_allowed": [f"RULES/REPORT/{task_id}_REPORT_R1/**",
                          f"scripts/{task_id.lower()}_codex_internal/**",
                          f"RESEARCH_WORK/{task_id}_R1/**"],
        "files_forbidden": ["RULES/TASK/**", "SOURCE/**", ".ai/**", "app/**", "apps/**",
                            "lib-*/**", "Backend/**", "services/**", "packages/**"],
        "max_minutes": 120, "max_cpu": 1, "max_heap": "1G",
        "max_per_decompile_seconds": 15, "max_report_bytes": 134217728,
        "expected_lease_id": f"LEASE-CEO-WORKER-{task_id}-R1", "standard_sha256": STANDARD_SHA,
        "source_libraries": {library: {"sha256": SOURCES[library]}},
        "target_candidate_count": 126 if task_id == "TASK_211" else 128,
        "authorization_reference": "Chairman Tony direct instruction to finish remaining SO45 decoding without AGY; bounded research only",
        "created_at": stamp, "modified_time": stamp, "budget_deadline_utc": deadline,
    }
    if manifest_path:
        meta["target_manifest_path"] = manifest_path
        meta["target_manifest_sha256"] = manifest_sha
    return meta


def main() -> None:
    c = module.Controller(ROOT)
    if module.file_sha(ROOT / module.STANDARD) != STANDARD_SHA or c.end_requested():
        raise RuntimeError("canonical standard changed or END requested")
    for library, expected in SOURCES.items():
        if module.file_sha(SOURCE_DIR / library) != expected:
            raise RuntimeError(f"source changed: {library}")
    old = ROOT / ".ai/ceo/reviews/TASK_208_internal_targets.json"
    old_sha = "db877766e2100738fdeab4f388ca67760b31702a9c92e5a237358a0d556a7dbc"
    if module.file_sha(old) != old_sha:
        raise RuntimeError("TASK_208 target manifest changed")
    targets = {
        "TASK_212": internal_manifest("TASK_212", "libAIModelSearchKit.so"),
        "TASK_213": internal_manifest("TASK_213", "libPVGCodec.so"),
    }
    now = dt.datetime.now(dt.timezone.utc)
    stamp = now.isoformat()
    deadline = (now + dt.timedelta(minutes=120)).isoformat()
    specs = [
        ("TASK_211", "/root/audit_208", "libPVGImageCodec.so", "TASK_211_SO45_PVGIMAGE_R1_RECOVERY_ACTIVE.md"),
        ("TASK_212", "/root/audit_157_158", "libAIModelSearchKit.so", "TASK_212_SO45_AIMODEL_INTERNAL_ACTIVE.md"),
        ("TASK_213", "/root/audit_210", "libPVGCodec.so", "TASK_213_SO45_PVGCODEC_INTERNAL_ACTIVE.md"),
    ]
    task_files = {}
    for tid, agent, library, filename in specs:
        manifest_path = (".ai/ceo/reviews/TASK_208_internal_targets.json" if tid == "TASK_211"
                         else f".ai/ceo/reviews/{tid}_internal_targets.json")
        manifest_sha = old_sha if tid == "TASK_211" else targets[tid][1]
        meta = task_meta(tid, agent, library, stamp, deadline, manifest_path, manifest_sha)
        if tid == "TASK_211":
            directions = (
                "Fresh bounded recovery of expired, unsealed TASK_208 R1 evidence; TASK_208 files are read-only. "
                "Rehash its exact 126 pinned source bodies, 18,502 ARM64 words, Ghidra raw outputs, logs and project; "
                "independently recheck >=10% spread ordinary provenance. Investigate/retry only index 465 within budget. "
                "Classify the 125 C-like outputs and any unresolved failure truthfully, including FDE boundary limits "
                "and exclusions 450/499. Produce a new standalone 00_AUDIT_INDEX.md, 01_MASTER_REPORT.md, "
                "per-candidate evidence and SHA-256 sealed COMPLETE.json in TASK_211_REPORT_R1. Do not mutate or "
                "seal TASK_208 R1 retroactively. Verify fresh-session rollback if any Ghidra metadata is changed.")
        else:
            directions = (
                "Research only the exact 128 selected nonexport FDE candidates in the pinned CEO manifest. "
                "Independently reverify original ELF/PT_LOAD/FDE bytes and ARM64 instruction slots. Use a private "
                "bounded Ghidra headless project (one CPU, 1 GiB heap, <=15 seconds per decompile), capture "
                "full body membership, listing/p-code coverage, raw C-like or failure and logs/project hashes; "
                "recheck >=10% spread provenance. Do not infer source-function boundaries or semantics from FDEs. "
                "Seal a truthful PARTIAL research report if any target remains unresolved.")
        body = (f"# {tid} R1 - bounded {library} continuation\n\nSTATUS: ACTIVE\nASSIGNEE: {agent}\n"
                f"PRIORITY: P1\nMODIFIED_TIME: {stamp}\n\n```json\n"
                f"{json.dumps(meta, ensure_ascii=False, indent=2)}\n```\n\n{directions}\n\n"
                "Before any write fully read the canonical Standard SHA-256 " + STANDARD_SHA +
                ", AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, "
                "ACQUIREMENTS.md, this exact task and manifest, config/state/locks/END and git status. "
                f"Claim exact ACTIVE {tid} R1 as {agent} via {meta['expected_lease_id']} before writing. "
                "Write only files_allowed; source, prior reports, P0 and product are read-only. "
                "Report canonical path and SHA in 00_AUDIT_INDEX.md. No AGY, child agents, self-review, "
                "commit or push before independent CEO review. Stop at the absolute deadline.\n")
        task_files[ROOT / "RULES/TASK" / filename] = body
    initial = c.read_json(c.registry)
    c.ceo_lease(initial)
    with module.guard(c.home / "control.guard"), module.guard(ROOT / ".ai/locks.registry.guard"):
        registry = c.read_json(c.registry)
        lease = c.ceo_lease(registry)
        config = c.read_json(c.home / "config.json")
        if any(tid in config["task_ids"] for tid, *_ in specs):
            raise RuntimeError("task id already configured")
        output_paths = list(task_files) + [ROOT / f".ai/ceo/reviews/{tid}_internal_targets.json"
                                           for tid in targets]
        if any(p.exists() for p in output_paths):
            raise RuntimeError("task or manifest already exists")
        updated = json.loads(json.dumps(registry))
        ceo = next(x for x in updated["active_locks"] if x["lease_id"] == module.CEO_LEASE)
        for tid, *_ in specs:
            scope = f"RULES/TASK/{tid}*"
            ceo["files_allowed"].append(scope)
            ceo.setdefault("scope_extensions", []).append({"at": stamp, "scope": scope,
                "authorization": "Tony direct SO45 completion without AGY", "limits": "research only; P0/product/V4/P7 frozen"})
            config["task_ids"].append(tid)
        updated["revision"] += 1
        updated["updated_at"] = stamp
        config_sha = module.file_sha(c.home / "config.json")
        c.replace_json(c.registry, updated, registry)
        c.replace_json(c.home / "config.json", config, updated, config_sha)
        for tid, (text, _) in targets.items():
            p = ROOT / f".ai/ceo/reviews/{tid}_internal_targets.json"
            c.authorized(ceo, p)
            atomic_text(p, text)
        for p, text in task_files.items():
            c.authorized(ceo, p)
            atomic_text(p, text)
    print(json.dumps({"tasks": list(spec[0] for spec in specs), "deadline": deadline,
                      "ceo_fence": lease["fencing_token"],
                      "manifests": {tid: sha for tid, (_, sha) in targets.items()}}, indent=2))


if __name__ == "__main__":
    main()
