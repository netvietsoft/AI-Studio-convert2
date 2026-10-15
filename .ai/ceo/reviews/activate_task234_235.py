"""CEO activation of one new image slice and two disjoint oversized backlog tasks."""
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
m = importlib.util.module_from_spec(spec)
assert spec.loader is not None
spec.loader.exec_module(m)
sys.path.insert(0, str(ROOT / "scripts/task_174_codex_exports"))
from unwind import parse_unwind

STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
SOURCE_DIR = ROOT.parent / "SOURCE/extracted_native_libs/lib/arm64-v8a"
SPECS = (
    ("TASK_234", "/root/audit_157_158", "libPVGImageCodec.so",
     "7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b",
     "TASK_228", "ordinary", list(range(2049, 2561))),
    ("TASK_235", "/root/audit_210", "libPVGImageCodec.so",
     "7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b",
     "TASK_228", "ordinary", list(range(2561, 3073))),
)

def atomic_text(path: Path, value: str) -> None:
    temp = ROOT / ".ai" / f"locks.ceo.{uuid.uuid4().hex}.tmp"
    with temp.open("x", encoding="utf-8", newline="\n") as stream:
        stream.write(value)
        stream.flush()
        os.fsync(stream.fileno())
    os.replace(temp, path)


def manifest(tid: str, lib: str, expected_sha: str, kind: str, indices: list[int]) -> tuple[str, str]:
    source = SOURCE_DIR / lib
    data = source.read_bytes()
    if hashlib.sha256(data).hexdigest() != expected_sha:
        raise RuntimeError("original SO hash changed: " + lib)
    unwind = parse_unwind(data)
    with source.open("rb") as stream:
        elf = ELFFile(stream)
        if elf["e_machine"] != "EM_AARCH64":
            raise RuntimeError("non-AArch64 source")
        dyn = elf.get_section_by_name(".dynsym")
        exports = {int(s["st_value"]) for s in dyn.iter_symbols()
                   if s["st_info"]["type"] == "STT_FUNC" and s["st_shndx"] != "SHN_UNDEF"
                   and int(s["st_size"]) > 0 and int(s["st_value"]) != 0}
        loads = [p for p in elf.iter_segments() if p["p_type"] == "PT_LOAD"]
    candidates = sorted((r for r in unwind["records"] if r["function_va"] not in exports),
                        key=lambda r: r["function_va"])
    if max(indices) >= len(candidates):
        raise RuntimeError("candidate index outside census")
    targets = []
    skipped = []
    for i in indices:
        r = candidates[i]
        va, size, off = r["function_va"], r["function_size"], r["body_file_offset"]
        if not r["body_complete_in_input"] or size <= 0 or size % 4:
            raise RuntimeError(f"incomplete/misaligned FDE candidate {i}")
        if kind == "ordinary" and size > 4096:
            skipped.append({"global_index": i, "elf_va": hex(va), "size_bytes": size})
            continue
        if kind == "oversized" and size <= 4096:
            raise RuntimeError(f"oversized backlog shifted at {i}")
        if not any(p["p_vaddr"] <= va and va + size <= p["p_vaddr"] + p["p_filesz"]
                   and off == p["p_offset"] + va - p["p_vaddr"] for p in loads):
            raise RuntimeError(f"PT_LOAD mapping invalid at {i}")
        body = data[off:off + size]
        if hashlib.sha256(body).hexdigest() != r["retained_body_sha256"]:
            raise RuntimeError(f"body hash invalid at {i}")
        targets.append({"global_index": i, "elf_va": hex(va), "size_bytes": size,
                        "file_offset": hex(off), "body_sha256": r["retained_body_sha256"],
                        "instruction_slots": size // 4})
    if kind == "ordinary" and len(targets) < 400:
        raise RuntimeError("unexpectedly short ordinary image slice")
    out = {"schema_version": "2.1.2", "task_id": tid, "revision": 1,
           "classification": "FDE_START_ABSENT_DEFINED_NONZERO_DYNSYM_STT_FUNC_EXPORT",
           "source_library": lib, "source_sha256": expected_sha,
           "all_fde_ranges": unwind["fde_table_count"],
           "defined_nonzero_export_vas": len(exports),
           "all_nonexport_fde_candidates": len(candidates),
           "selection": f"{kind} exact VA-sorted nonexport FDE indices {indices[0]}..{indices[-1]}",
           "selected_count": len(targets), "skipped_in_slice": skipped,
           "targets": targets,
           "limits": "FDE spans are candidates, not proven source boundaries or behavior"}
    text = json.dumps(out, ensure_ascii=False, indent=2) + "\n"
    return text, hashlib.sha256(text.encode()).hexdigest()


def main() -> None:
    c = m.Controller(ROOT)
    if m.file_sha(ROOT / m.STANDARD) != STANDARD_SHA or c.end_requested():
        raise RuntimeError("canonical Standard changed or END requested")
    previous_image = json.loads((ROOT / ".ai/ceo/reviews/TASK_231_internal_targets.json").read_text(encoding="utf-8"))
    if previous_image["targets"][-1]["global_index"] != 2048:
        raise RuntimeError("prior image slice shifted")
    prepared = {tid: manifest(tid, lib, sha, kind, indices)
                for tid, _, lib, sha, _, kind, indices in SPECS}
    now = dt.datetime.now(dt.timezone.utc)
    stamp = now.isoformat()
    deadline = (now + dt.timedelta(minutes=120)).isoformat()
    task_files = {}
    for tid, agent, lib, sha, dep, kind, indices in SPECS:
        count = len(json.loads(prepared[tid][0])["targets"])
        manifest_path = f".ai/ceo/reviews/{tid}_internal_targets.json"
        meta = {
            "schema_version": "2.1.2", "task_id": tid, "revision": 1, "status": "ACTIVE",
            "assignee": agent, "agent_id": agent, "priority": "P1", "mode": "RESEARCH",
            "dependencies": [{"task_id": dep, "revision": 1}],
            "report_folder": f"RULES/REPORT/{tid}_REPORT_R1",
            "files_allowed": [f"RULES/REPORT/{tid}_REPORT_R1/**",
                              f"scripts/{tid.lower()}_codex_internal/**",
                              f"RESEARCH_WORK/{tid}_R1/**"],
            "files_forbidden": ["RULES/TASK/**", "SOURCE/**", ".ai/**", "app/**",
                                "apps/**", "lib-*/**", "Backend/**", "services/**", "packages/**"],
            "max_minutes": 120, "max_cpu": 1, "max_heap": "1G",
            "max_per_decompile_seconds": 15, "max_report_bytes": 134217728,
            "expected_lease_id": f"LEASE-CEO-WORKER-{tid}-R1",
            "standard_sha256": STANDARD_SHA,
            "source_libraries": {lib: {"sha256": sha}},
            "target_candidate_count": count,
            "authorization_reference": "Chairman Tony direct SO45 decoding continuation without AGY; bounded research only",
            "created_at": stamp, "modified_time": stamp, "budget_deadline_utc": deadline,
            "target_manifest_path": manifest_path,
            "target_manifest_sha256": prepared[tid][1],
        }
        special = (
            "These oversized FDE candidates were deliberately deferred by prior <=4096-byte "
            "ordinary batches. Analyze each with bounded per-function memory/time, splitting "
            "read-only batches or sealing a truthful failure when a bound is hit. Do not omit "
            "a target silently or call an incomplete C-like body complete."
            if kind == "oversized" else
            "This next image slice may contain oversized candidates; record every skipped "
            "index explicitly and continue only within bounded 1 GiB/15-second per-decompile "
            "limits. Preserve all earlier unresolved image indices."
        )
        body = (
            f"# {tid} R1 - bounded {lib} {kind} continuation\n\nSTATUS: ACTIVE\nASSIGNEE: {agent}\n"
            f"PRIORITY: P1\nMODIFIED_TIME: {stamp}\n\n```json\n"
            f"{json.dumps(meta, ensure_ascii=False, indent=2)}\n```\n\n"
            f"Research only exact manifest targets ({count} selected from indices {indices[0]}..{indices[-1]}). "
            "Reverify original ELF/PT_LOAD/FDE body bytes and every ARM64 word. Use a private "
            "bounded Ghidra project (one CPU, 1 GiB heap, <=15 seconds per decompile). "
            "Capture exact membership, listing/p-code, raw C-like or failure, command/log/project hashes, "
            "and independently recheck >=10% spread ordinary provenance. " + special + " "
            "C-like output is static research, not source or behavioral proof. Seal PARTIAL "
            "if any target or boundary remains unresolved.\n\n"
            f"Before any write fully read canonical Standard at {ROOT / m.STANDARD} "
            f"(SHA-256 {STANDARD_SHA}), AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, "
            "PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task/manifest and config/state/locks/END. "
            f"Claim exact ACTIVE {tid} R1 as {agent} using {meta['expected_lease_id']} before writing. "
            "Write only files_allowed; original SO and prior reports are read-only. Report canonical path "
            "and SHA in 00_AUDIT_INDEX.md. No AGY, child agents, self-review, commit/push before CEO review. "
            "P0/product/V4/P7 remain frozen. Stop at absolute task deadline.\n"
        )
        # Strip the JS-template escapes used to keep Python markdown fences literal.
        body = body.replace("\\`", "`")
        task_files[ROOT / "RULES/TASK" / f"{tid}_SO45_INTERNAL_CONTINUATION_ACTIVE.md"] = body
    with m.guard(c.home / "control.guard"), m.guard(ROOT / ".ai/locks.registry.guard"):
        registry = c.read_json(c.registry)
        lease = c.ceo_lease(registry)
        config = c.read_json(c.home / "config.json")
        state = c.read_json(c.state_path)
        existing = c.tasks()
        if any(not c.accepted(dep, state, existing, 1) for _, _, _, _, dep, _, _ in SPECS):
            raise RuntimeError("dependency acceptance not current")
        if any(tid in config["task_ids"] for tid, *_ in SPECS):
            raise RuntimeError("task ID already configured")
        outputs = list(task_files) + [ROOT / f".ai/ceo/reviews/{tid}_internal_targets.json" for tid in prepared]
        if any(p.exists() for p in outputs):
            raise RuntimeError("task output already exists")
        updated = json.loads(json.dumps(registry))
        ceo = next(x for x in updated["active_locks"] if x["lease_id"] == m.CEO_LEASE)
        for tid, *_ in SPECS:
            scope = f"RULES/TASK/{tid}*"
            ceo["files_allowed"].append(scope)
            ceo.setdefault("scope_extensions", []).append({
                "at": stamp, "scope": scope, "authorization": "Tony direct SO45 continuation without AGY",
                "limits": "research only; P0/product/V4/P7 frozen"})
            config["task_ids"].append(tid)
        updated["revision"] += 1
        updated["updated_at"] = stamp
        config_sha = m.file_sha(c.home / "config.json")
        c.replace_json(c.registry, updated, registry)
        c.replace_json(c.home / "config.json", config, updated, config_sha)
        for tid, (text, _) in prepared.items():
            p = ROOT / f".ai/ceo/reviews/{tid}_internal_targets.json"
            c.authorized(ceo, p)
            atomic_text(p, text)
        for p, text in task_files.items():
            c.authorized(ceo, p)
            atomic_text(p, text)
    print(json.dumps({"tasks": [s[0] for s in SPECS], "deadline": deadline,
                      "ceo_fence": lease["fencing_token"],
                      "manifests": {tid: sha for tid, (_, sha) in prepared.items()}}, indent=2))


if __name__ == "__main__":
    main()
