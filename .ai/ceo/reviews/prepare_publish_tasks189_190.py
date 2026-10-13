"""Issue two exact nonoverlapping Codex-only SO45 static FDE lanes."""
import copy
import datetime as dt
import hashlib
import json
import os
import sys
from pathlib import Path

from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / ".ai/ceo"))
from controller import Controller, file_sha  # noqa: E402

STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
SOURCE_DIR = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a")
SPECS = (
    {"task": "TASK_189", "library": "libMTFilterKernel.so", "sha": "f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4",
     "selection": (128, 192), "totals": (2362, 2873, 511), "bytes": 33660,
     "assignee": "/root/so45_mtfilter_next", "dependency": ("TASK_187", 2),
     "project": "RESEARCH_WORK/TASK_187_R1/ghidra_project", "minutes": 90},
    {"task": "TASK_190", "library": "libPVGColorFunctions.so", "sha": "3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6",
     "selection": (256, 384), "totals": (81, 753, 672), "bytes": 4432,
     "assignee": "/root/so45_pvg_next", "dependency": ("TASK_186", 2),
     "project": "RESEARCH_WORK/TASK_186_R1/ghidra_project", "minutes": 60},
)


def atomic_file(path, raw):
    temp = path.with_name(path.name + ".tmp")
    with temp.open("xb") as stream:
        stream.write(raw)
        stream.flush()
        os.fsync(stream.fileno())
    os.replace(temp, path)


def prepare(spec, now):
    source = SOURCE_DIR / spec["library"]
    raw = source.read_bytes()
    if hashlib.sha256(raw).hexdigest() != spec["sha"]:
        raise RuntimeError("source changed: " + spec["library"])
    with source.open("rb") as stream:
        elf = ELFFile(stream)
        if elf["e_machine"] != "EM_AARCH64":
            raise RuntimeError("unexpected ELF architecture")
        exports = {int(s["st_value"]) for s in elf.get_section_by_name(".dynsym").iter_symbols()
                   if s["st_info"]["type"] == "STT_FUNC" and s["st_shndx"] != "SHN_UNDEF"
                   and int(s["st_value"]) > 0 and int(s["st_size"]) > 0}
        fdes = {(int(f["initial_location"]), int(f["address_range"]))
                for f in elf.get_dwarf_info().EH_CFI_entries()
                if isinstance(f, FDE) and int(f["address_range"]) > 0}
        loads = [s for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
    ordered = sorted((va, size) for va, size in fdes if va not in exports)
    if (len(exports), len(fdes), len(ordered)) != spec["totals"]:
        raise RuntimeError("FDE/export census changed: " + spec["library"])
    begin, end = spec["selection"]
    selected = ordered[begin:end]
    if len(selected) != end - begin or sum(size for _, size in selected) != spec["bytes"]:
        raise RuntimeError("candidate slice/size changed: " + spec["library"])
    rows = []
    for va, size in selected:
        if va % 4 or size % 4 or size <= 0:
            raise RuntimeError("unaligned FDE: " + hex(va))
        mapped = [int(s["p_offset"]) + va - int(s["p_vaddr"]) for s in loads
                  if int(s["p_vaddr"]) <= va and va + size <= int(s["p_vaddr"]) + int(s["p_filesz"])]
        if len(mapped) != 1:
            raise RuntimeError("ambiguous PT_LOAD: " + hex(va))
        offset = mapped[0]
        body = raw[offset:offset + size]
        if len(body) != size:
            raise RuntimeError("truncated original FDE: " + hex(va))
        rows.append({"elf_va": f"0x{va:x}", "size_bytes": size,
                     "file_offset": f"0x{offset:x}", "body_sha256": hashlib.sha256(body).hexdigest(),
                     "instruction_slots": size // 4})
    stamp = now.isoformat(timespec="microseconds").replace("+00:00", "Z")
    deadline = (now + dt.timedelta(minutes=spec["minutes"])).isoformat()
    task = spec["task"]
    manifest_path = ROOT / f".ai/ceo/reviews/{task}_internal_targets.json"
    task_path = ROOT / f"RULES/TASK/{task}_SO45_CODEX_INTERNAL_ACTIVE.md"
    payload = {"schema_version": "2.1.2", "task_id": task, "revision": 1,
               "generated_at": stamp,
               "classification": "UNWIND_FDE_START_NOT_IN_DEFINED_NONZERO_DYNSYM_EXPORTS_CANDIDATE",
               "source_library": spec["library"], "source_sha256": spec["sha"],
               "original_file_bytes": len(raw), "defined_nonzero_export_vas": len(exports),
               "all_fde_ranges": len(fdes), "all_nonexport_fde_candidates": len(ordered),
               "selection": f"sorted nonexport FDE indices {begin}..{end - 1} inclusive",
               "selected_count": len(rows), "remaining_nonselected_candidates_after_slice": len(ordered) - end,
               "scope_limit": "FDE candidate ranges are not proof of complete unique functions or behavior",
               "targets": rows}
    manifest_raw = (json.dumps(payload, ensure_ascii=False, indent=2) + "\n").encode("utf8")
    manifest_sha = hashlib.sha256(manifest_raw).hexdigest()
    report = f"RULES/REPORT/{task}_REPORT_R1"
    meta = {"schema_version": "2.1.2", "task_id": task, "revision": 1,
            "status": "ACTIVE", "assignee": spec["assignee"], "agent_id": spec["assignee"],
            "priority": "P1", "dependencies": [{"task_id": spec["dependency"][0], "revision": spec["dependency"][1]}],
            "mode": "RESEARCH", "report_folder": report,
            "files_allowed": [f"{report}/**", f"scripts/{task.lower()}_codex_internal/**", f"RESEARCH_WORK/{task}_R1/**"],
            "files_forbidden": ["RULES/TASK/**", "SOURCE/**", ".ai/**", "app/**", "apps/**",
                                "lib-*/**", "Backend/**", "services/**", "packages/**"],
            "max_minutes": spec["minutes"], "max_cpu": 1, "max_heap": "1G", "max_report_bytes": 134217728,
            "expected_lease_id": f"LEASE-CEO-WORKER-{task}-R1", "standard_sha256": STANDARD_SHA,
            "source_libraries": {spec["library"]: {"sha256": spec["sha"], "defined_nonzero_export_vas": len(exports)}},
            "target_manifest_path": manifest_path.relative_to(ROOT).as_posix(),
            "target_manifest_sha256": manifest_sha, "target_candidate_count": len(rows),
            "authorization_reference": "Chairman Tony directs direct SO45 decoding with real Codex subagents, without AGY",
            "created_at": stamp, "budget_deadline_utc": deadline}
    body = f"""# {task} R1 - bounded {spec['library']} nonexport FDE candidates

STATUS: ACTIVE
ASSIGNEE: {spec['assignee']}
PRIORITY: P1
MODIFIED_TIME: {stamp}

```json
{json.dumps(meta, ensure_ascii=False, indent=2)}
```

Process only exact sorted nonexport FDE candidate indices {begin}..{end - 1} in `{meta['target_manifest_path']}` SHA-256 `{manifest_sha}` from original `{spec['library']}` SHA-256 `{spec['sha']}`. The accepted {spec['dependency'][0]} research covers an earlier, disjoint candidate slice; do not re-run it. The prior analyzed project `{spec['project']}` is read-only input; verify source and copied-project hashes before reuse. An unwind FDE is a candidate range, not proof of complete or unique source-function boundaries. Check all original FDE/PT_LOAD body hashes and all source instruction positions. On a private byte-verified project copy, collect one Ghidra result per candidate: memory SHA, every-byte function-body membership, missing/extra ranges, instruction/p-code coverage, C-like text/hash or failure, and raw command/log receipts. Mark overlaps and ambiguous boundaries PARTIAL; never remove metadata of another function. Transient correction is permitted only on nonoverlapping gaps, in a read-only project session with rollback and before/after memory proof. Use one CPU, 1 GiB heap, sequential <=20-minute headless processes and <=10 seconds per decompile. Independently recheck all critical body/output claims and >=10% spread ordinary source instruction slots; seal a truthful bounded report even if incomplete. Do not infer all internal functions, behavior/pixel parity, product Phase PASS, V4/P7, or all-45-SO completion.

Before any write fully read `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` and verify SHA-256 `{STANDARD_SHA}`. Also read AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task/manifest, config/state/locks/END and git status. Claim exact ACTIVE {task} revision 1 as `{spec['assignee']}` using expected lease `{meta['expected_lease_id']}` before any write. Write only `{report}/**`, `scripts/{task.lower()}_codex_internal/**`, `RESEARCH_WORK/{task}_R1/**`; source SO, prior research, other lanes and P0 are read-only. Create 00_AUDIT_INDEX.md canonical read receipt, 01_MASTER_REPORT.md, raw per-candidate and command/log evidence, PROGRESS and COMPLETE.json SHA-256 manifest. No AGY, further subagents, self-review or commit/push before CEO independent review. Stop by {deadline}.
"""
    return manifest_path, manifest_raw, task_path, body.encode("utf8"), rows, deadline


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or file_sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") != STANDARD_SHA:
        raise RuntimeError("END requested or canonical standard changed")
    now = dt.datetime.now(dt.timezone.utc)
    prepared = [(spec, *prepare(spec, now)) for spec in SPECS]
    with ctl.transaction() as (registry, state):
        ceo = ctl.ceo_lease(registry)
        tasks = ctl.tasks()
        for spec, manifest_path, manifest_raw, task_path, task_raw, rows, deadline in prepared:
            dep, revision = spec["dependency"]
            if not ctl.accepted(dep, state, tasks, required_revision=revision):
                raise RuntimeError("dependency not accepted: " + dep)
            if manifest_path.exists() or task_path.exists():
                raise RuntimeError("task already prepared: " + spec["task"])
            ctl.authorized(ceo, manifest_path)
        updated = copy.deepcopy(registry)
        active = ctl.ceo_lease(updated)
        for spec, *_ in prepared:
            scope = f"RULES/TASK/{spec['task']}*"
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
        for spec, manifest_path, manifest_raw, task_path, task_raw, rows, deadline in prepared:
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
        for spec, manifest_path, manifest_raw, task_path, task_raw, rows, deadline in prepared:
            ctl.event(state, "CODEX_INTERNAL_FDE_TASK_PUBLISHED", task_id=spec["task"],
                      assignee=spec["assignee"], source=spec["library"],
                      target_count=len(rows), manifest_sha256=hashlib.sha256(manifest_raw).hexdigest(),
                      task_sha256=hashlib.sha256(task_raw).hexdigest(), deadline=deadline)
    print(json.dumps([{"task_id": spec["task"], "assignee": spec["assignee"],
                       "source": spec["library"], "target_count": len(rows),
                       "instruction_slots": sum(row["instruction_slots"] for row in rows),
                       "max_target_bytes": max(row["size_bytes"] for row in rows),
                       "task_sha256": file_sha(task_path),
                       "manifest_sha256": file_sha(manifest_path), "deadline": deadline}
                      for spec, manifest_path, manifest_raw, task_path, task_raw, rows, deadline in prepared]))


if __name__ == "__main__":
    main()
