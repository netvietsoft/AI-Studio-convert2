"""Fenced, source-anchored TASK_238 static research pipeline."""
from __future__ import annotations

import datetime as dt
import hashlib
import json
import os
import shutil
import subprocess
import sys
import tempfile
import time
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]
SCRIPT_DIR = Path(__file__).resolve().parent
TASK = ROOT / "RULES/TASK/TASK_238_SO45_INTERNAL_CONTINUATION_ACTIVE.md"
TARGETS = ROOT / ".ai/ceo/reviews/TASK_238_internal_targets.json"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
SOURCE = ROOT.parent / "SOURCE/extracted_native_libs/lib/arm64-v8a/libPVGImageCodec.so"
PRIOR_PROJECT = ROOT / "RESEARCH_WORK/TASK_216_R1/ghidra_project"
REPORT = ROOT / "RULES/REPORT/TASK_238_REPORT_R1"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_238_R1"
PROJECT = SCRATCH / "ghidra_project"
GHIDRA = Path("F:/TOOLS/ghidra_12.1.4_PUBLIC")
JDK = Path("F:/TOOLS/jdk-21.0.12.1+1")
LEASE_ID = "LEASE-CEO-WORKER-TASK_238-R1"
AGENT = "/root/audit_210"
FENCE = 1276
TASK_SHA = "8ac7f1841f072cc3651bc880727fe3bec12d62901fdcbd8adbb1a959b5940f73"
TARGET_SHA = "be609310fe32d6f2b2d150534cd1f64a21824a6f37756103ae3c26f8c884d367"
SOURCE_SHA = "7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
DEADLINE = dt.datetime.fromisoformat("2026-10-15T12:19:30.479572+00:00")
SCOPES = ("RULES/REPORT/TASK_238_REPORT_R1/", "scripts/task_238_codex_internal/", "RESEARCH_WORK/TASK_238_R1/")


def now() -> str:
    return dt.datetime.now(dt.timezone.utc).isoformat()


def sha(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1 << 20), b""):
            digest.update(chunk)
    return digest.hexdigest()


def check() -> None:
    if dt.datetime.now(dt.timezone.utc) >= DEADLINE:
        raise RuntimeError("absolute task deadline reached")
    for path, expected in ((TASK, TASK_SHA), (TARGETS, TARGET_SHA), (SOURCE, SOURCE_SHA), (STANDARD, STANDARD_SHA)):
        if sha(path) != expected:
            raise RuntimeError(f"pinned input changed: {path}")
    flag = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    if flag.is_file() and flag.read_text(encoding="utf-8-sig").strip().upper() == "TRUE":
        raise RuntimeError("campaign ended")
    locks = json.loads((ROOT / ".ai/locks.json").read_text(encoding="utf-8"))["active_locks"]
    rows = [x for x in locks if x.get("lease_id") == LEASE_ID]
    if len(rows) != 1:
        raise RuntimeError("exact worker lease unavailable")
    lease = rows[0]
    identity = (lease.get("status"), lease.get("agent_id"), lease.get("task_id"),
                lease.get("task_revision"), lease.get("task_sha"), lease.get("fencing_token"))
    if identity != ("ACTIVE", AGENT, "TASK_238", 1, TASK_SHA, FENCE):
        raise RuntimeError(f"lease identity changed: {identity}")
    if dt.datetime.fromisoformat(lease["expiry"].replace("Z", "+00:00")) <= dt.datetime.now(dt.timezone.utc):
        raise RuntimeError("worker lease expired")
    if not all(scope + "**" in lease.get("files_allowed", []) for scope in SCOPES):
        raise RuntimeError("worker lease scope changed")


def write(path: Path, data: bytes) -> None:
    check()
    rel = path.resolve().relative_to(ROOT.resolve()).as_posix()
    if not any(rel.startswith(prefix) for prefix in SCOPES):
        raise RuntimeError(f"out of task scope: {rel}")
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temp = tempfile.mkstemp(prefix=".task238-", dir=path.parent)
    try:
        with os.fdopen(fd, "wb") as stream:
            stream.write(data)
            stream.flush()
            os.fsync(stream.fileno())
        os.replace(temp, path)
    finally:
        if os.path.exists(temp):
            os.unlink(temp)


def write_json(path: Path, data: object) -> None:
    write(path, (json.dumps(data, ensure_ascii=False, indent=2) + "\n").encode("utf-8"))


def prepare() -> None:
    check()
    if REPORT.exists() or SCRATCH.exists():
        raise RuntimeError("TASK_238 output already exists")
    target_manifest = json.loads(TARGETS.read_text(encoding="utf-8"))
    if len(target_manifest["targets"]) != 506 or target_manifest["selected_count"] != 506:
        raise RuntimeError("target census changed")
    skipped = {3867, 3877, 4025, 4051, 4052, 4066}
    expected_indices = [index for index in range(3585, 4097) if index not in skipped]
    if ([row["global_index"] for row in target_manifest["targets"]] != expected_indices
            or {row["global_index"] for row in target_manifest["skipped_in_slice"]} != skipped
            or any(row["size_bytes"] <= 4096 for row in target_manifest["skipped_in_slice"])):
        raise RuntimeError("exact next-506 selection or oversized skips changed")
    prior_pending = []
    for name, expected_sha in (
        ("TASK_216_internal_targets.json", "dea3690cb38e6e9322c79a7e6a3ebdec0eb45b32d9a79ea7ab303148687bba78"),
        ("TASK_231_internal_targets.json", "c9de296ff1de433983a492ba2b76a7586e5736f63985e97e4f8f9668be224361"),
        ("TASK_234_internal_targets.json", "b3826715c6efa37471c853e3a7517ef98ae197c4ebffe0f19faeb3d51a9bc1e8"),
        ("TASK_235_internal_targets.json", "d80c299fbdc6bf5dcf24a2d6bf417a87bae7250570bd26d2245681abb402fce4"),
        ("TASK_237_internal_targets.json", "ea7262a4d1a0f3553fc9314f784ffc6fa2406f9669f901653c7e38730efebdb2"),
    ):
        path = ROOT / ".ai/ceo/reviews" / name
        if sha(path) != expected_sha:
            raise RuntimeError(f"prior pending manifest changed: {name}")
        previous = json.loads(path.read_text(encoding="utf-8"))
        prior_pending.extend(previous.get("skipped_in_slice", previous.get("skipped_before_last_selected", [])))
    if {row["global_index"] for row in prior_pending} != {555, 1542, 1586, 1620, 1623, 1626, 1830, 1912, 2293, 2775, 2776, 3106, 3132, 3134, 3285, 3523}:
        raise RuntimeError("prior oversized pending index set changed")
    all_pending = prior_pending + target_manifest["skipped_in_slice"]
    md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    rows = []
    samples = []
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        if elf["e_machine"] != "EM_AARCH64":
            raise RuntimeError("source ISA changed")
        fdes = sorted((int(x["initial_location"]), int(x["address_range"]))
                      for x in elf.get_dwarf_info().EH_CFI_entries() if isinstance(x, FDE))
        dyn = elf.get_section_by_name(".dynsym")
        exports = {(int(s["st_value"]), int(s["st_size"])) for s in dyn.iter_symbols()
                   if s["st_info"]["type"] == "STT_FUNC" and s["st_shndx"] != "SHN_UNDEF"
                   and int(s["st_value"]) > 0 and int(s["st_size"]) > 0}
        export_starts = {x for x, _ in exports}
        candidates = sorted(x for x in fdes if x[0] not in export_starts)
        if (len(fdes), len(export_starts), len(candidates)) != (9981, 3326, 6655):
            raise RuntimeError("source FDE/export census changed")
        if any(candidates[row["global_index"]] != (int(row["elf_va"], 16), row["size_bytes"])
               or row["size_bytes"] <= 4096 for row in all_pending):
            raise RuntimeError("cumulative oversized candidate evidence changed")
        loads = [(int(s["p_vaddr"]), int(s["p_filesz"]), int(s["p_offset"]))
                 for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
        for target in target_manifest["targets"]:
            check()
            idx, va, size = target["global_index"], int(target["elf_va"], 16), target["size_bytes"]
            if idx in skipped or idx < 3585 or idx > 4096 or candidates[idx] != (va, size):
                raise RuntimeError(f"FDE target mismatch {idx}")
            mappings = [offset + va - base for base, length, offset in loads
                        if base <= va and va + size <= base + length]
            if len(mappings) != 1 or mappings[0] != int(target["file_offset"], 16):
                raise RuntimeError(f"PT_LOAD target mismatch {idx}")
            stream.seek(mappings[0])
            body = stream.read(size)
            if size <= 0 or size > 4096 or size % 4 or sha_bytes(body) != target["body_sha256"]:
                raise RuntimeError(f"source body mismatch {idx}")
            ins = []
            calls = []
            for off in range(0, size, 4):
                word = body[off:off+4]
                decoded = list(md.disasm(word, va+off, count=1))
                text = (decoded[0].mnemonic + " " + decoded[0].op_str).strip() if decoded and decoded[0].size == 4 else None
                row = {"elf_va": f"0x{va+off:x}", "word_hex": word.hex(), "assembly": text}
                ins.append(row)
                if text and decoded[0].mnemonic in {"bl", "blr", "blraa", "blrab", "blraaz", "blrabz"}:
                    calls.append(row)
                if off % 40 == 0:
                    samples.append({"index": idx, "slot": off // 4, **row})
            overlaps = [(f"0x{x:x}", y) for x, y in fdes if x != va and x < va+size and va < x+y]
            export_overlaps = [(f"0x{x:x}", y) for x, y in exports if x < va+size and va < x+y]
            evidence = {"task_id": "TASK_238", "revision": 1, "global_index": idx,
                        "elf_va": f"0x{va:x}", "size_bytes": size, "file_offset": f"0x{mappings[0]:x}",
                        "source_body_sha256": sha_bytes(body), "instruction_slots": size // 4,
                        "decoded_slots": sum(x["assembly"] is not None for x in ins),
                        "other_fde_overlap": overlaps, "export_body_overlap": export_overlaps,
                        "call_sites": calls, "instructions": ins,
                        "boundary_classification": "FDE_CANDIDATE_NOT_PROVEN_FUNCTION"}
            name = f"{idx:03d}_{va:x}.json"
            write_json(REPORT / "source_assembly" / name, evidence)
            rows.append({"global_index": idx, "elf_va": f"0x{va:x}", "size_bytes": size,
                         "file_offset": f"0x{mappings[0]:x}", "source_body_sha256": sha_bytes(body),
                         "instruction_slots": size // 4, "decoded_slots": evidence["decoded_slots"],
                         "source_evidence": f"source_assembly/{name}", "source_evidence_sha256": sha(REPORT / "source_assembly" / name),
                         "other_fde_overlap_count": len(overlaps), "export_body_overlap_count": len(export_overlaps)})
    if sum(r["instruction_slots"] for r in rows) != 48116 or any(r["decoded_slots"] != r["instruction_slots"] for r in rows):
        raise RuntimeError("instruction slot total/decoder mismatch")
    if not PRIOR_PROJECT.is_dir() or len(list(PRIOR_PROJECT.glob("*.gpr"))) != 1:
        raise RuntimeError("accepted prior Ghidra project unavailable")
    prior_index = json.loads((ROOT / "RULES/REPORT/TASK_216_REPORT_R1/source_project_index.json").read_text(encoding="utf-8"))
    prior_hashes = {x["relative_path"]: x["sha256"] for x in prior_index["project_files"]}
    if prior_index["source_sha256"] != SOURCE_SHA or len(prior_hashes) != 9:
        raise RuntimeError("prior image project provenance changed")
    copied = []
    for src in sorted(p for p in PRIOR_PROJECT.rglob("*") if p.is_file()):
        check()
        rel = src.relative_to(PRIOR_PROJECT)
        dst = PROJECT / rel
        dst.parent.mkdir(parents=True, exist_ok=True)
        before = sha(src)
        if prior_hashes.get(rel.as_posix()) != before:
            raise RuntimeError(f"prior image project hash changed: {rel}")
        shutil.copy2(src, dst)
        if sha(dst) != before:
            raise RuntimeError(f"project copy mismatch {rel}")
        copied.append({"relative_path": rel.as_posix(), "sha256": before, "bytes": dst.stat().st_size})
    batches = {}
    for i in range(16):
        subset = rows[i*32:(i+1)*32]
        tsv = "".join(f'{r["global_index"]}\t{r["elf_va"]}\t{r["size_bytes"]}\t{r["source_body_sha256"]}\n' for r in subset)
        path = SCRATCH / f"targets_{i+1}.tsv"
        write(path, tsv.encode("ascii"))
        batches[str(i+1)] = {"path": str(path), "sha256": sha(path), "count": len(subset)}
    write_json(REPORT / "source_index.json", {"task_id": "TASK_238", "revision": 1,
        "source_path": str(SOURCE), "source_sha256": SOURCE_SHA, "target_manifest_sha256": TARGET_SHA,
        "all_fde_count": 9981, "export_starts": 3326, "nonexport_candidates": 6655,
        "selected": rows, "skipped_oversized_candidates_pending": all_pending,
        "project_source": str(PRIOR_PROJECT), "project_copy": str(PROJECT),
        "project_name": next(PRIOR_PROJECT.glob("*.gpr")).stem,
        "project_files": copied, "batches": batches})
    write_json(REPORT / "source_spread_recheck.json", {"method": "every tenth source instruction per target",
        "total_slots": 48116, "checked_slots": len(samples), "samples": samples,
        "note": "Independent verifier must re-read original bytes; this is producer spread."})
    write(REPORT / "00_AUDIT_INDEX.md", (
        f"# TASK_238 R1 audit index\n\nCanonical Standard fully read: `{STANDARD}`; "
        f"SHA-256 `{STANDARD_SHA}`. Actor `{AGENT}`; lease `{LEASE_ID}`, fence `{FENCE}`.\n\n"
        f"Task SHA-256 `{TASK_SHA}`; target manifest SHA-256 `{TARGET_SHA}`; "
        f"original SO SHA-256 `{SOURCE_SHA}`.\n\n"
        "These are ELF unwind FDE candidates, not proven unique source functions or behavior.\n").encode("utf-8"))
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_238", "revision": 1,
        "status": "SOURCE_ANCHORED_OUTPUT_READY", "generated_at": now(),
        "original_candidate_bodies_verified": 506, "original_instruction_words_verified": 48116,
        "ghidra_output_rows": 0, "new_imports": 0})
    print(json.dumps({"phase": "prepare", "targets": len(rows), "bytes": sum(x["size_bytes"] for x in rows),
                      "slots": 48116, "project_files": len(copied), "spread_samples": len(samples)}), flush=True)


def sha_bytes(value: bytes) -> str:
    return hashlib.sha256(value).hexdigest()


def run_batch(batch: int) -> None:
    check()
    if batch not in range(1, 17):
        raise RuntimeError("batch must be 1..16")
    index = json.loads((REPORT / "source_index.json").read_text(encoding="utf-8"))
    if len(index["selected"]) != 506:
        raise RuntimeError("source index incomplete")
    tsv = SCRATCH / f"targets_{batch}.tsv"
    if sha(tsv) != index["batches"][str(batch)]["sha256"]:
        raise RuntimeError("target TSV changed")
    if batch > 1:
        previous = json.loads((REPORT / f"ghidra_batch{batch-1}_command.json").read_text())
        if previous.get("status") != "OUTPUT_READY" or previous.get("raw_result_files") != 32:
            raise RuntimeError("previous batch incomplete")
    if not (GHIDRA / "support/analyzeHeadless.bat").is_file() or not (JDK / "bin/java.exe").is_file():
        raise RuntimeError("Ghidra/JDK unavailable")
    for item in index["project_files"]:
        src = PROJECT / item["relative_path"]
        if not src.is_file() or sha(src) != item["sha256"]:
            raise RuntimeError(f"private project changed: {src}")
    output = REPORT / f"ghidra_raw_batch{batch}"
    stdout = REPORT / f"ghidra_batch{batch}_stdout.log"
    stderr = REPORT / f"ghidra_batch{batch}_stderr.log"
    receipt = REPORT / f"ghidra_batch{batch}_command.json"
    if any(x.exists() for x in (stdout, stderr, receipt)):
        raise RuntimeError("batch command or logs already exist")
    if output.exists():
        if not output.is_dir() or any(output.iterdir()):
            raise RuntimeError("batch output already contains results")
    else:
        output.mkdir(parents=True)
    command = [str(GHIDRA / "support/analyzeHeadless.bat"), str(PROJECT), index["project_name"],
               "-process", "libPVGImageCodec.so", "-noanalysis", "-readOnly", "-max-cpu", "1",
               "-scriptPath", str(SCRIPT_DIR), "-postScript", "ExtractInternal238.java", str(tsv), str(output)]
    base = {"task_id": "TASK_238", "revision": 1, "batch": batch, "lease_id": LEASE_ID,
            "fencing_token": FENCE, "source_sha256": SOURCE_SHA, "project_copy": str(PROJECT),
            "target_tsv_sha256": sha(tsv), "script_sha256": sha(SCRIPT_DIR / "ExtractInternal238.java"),
            "command": command, "max_cpu": 1, "max_heap": "1G", "max_per_decompile_seconds": 15,
            "started_at": now(), "status": "STARTING"}
    write_json(receipt, base)
    env = os.environ.copy()
    env["JAVA_HOME"] = str(JDK)
    env["PATH"] = str(JDK / "bin") + os.pathsep + env.get("PATH", "")
    env["GHIDRA_HEADLESS_MAXMEM"] = "1G"
    env["DOUBLE_CLICKED"] = "n"
    remaining = min(1200, (DEADLINE - dt.datetime.now(dt.timezone.utc)).total_seconds())
    if remaining <= 0:
        raise RuntimeError("deadline before Ghidra start")
    started = time.monotonic()
    with stdout.open("wb") as out, stderr.open("wb") as err:
        proc = subprocess.Popen(command, env=env, stdin=subprocess.DEVNULL, stdout=out, stderr=err,
                                creationflags=getattr(subprocess, "CREATE_NO_WINDOW", 0))
        try:
            code = proc.wait(timeout=remaining)
            timeout = False
        except subprocess.TimeoutExpired:
            proc.kill()
            code = proc.wait(timeout=15)
            timeout = True
    files = sorted(output.glob("*.json"))
    status = "PROCESS_TIMEOUT" if timeout else "OUTPUT_READY" if code == 0 and len(files) == index["batches"][str(batch)]["count"] else "PARTIAL_OUTPUT"
    project_after = {x["relative_path"]: sha(PROJECT / x["relative_path"]) for x in index["project_files"]}
    write_json(receipt, {**base, "status": status, "ended_at": now(),
        "elapsed_seconds": round(time.monotonic()-started, 3), "exit_code": code,
        "raw_result_files": len(files), "raw_result_hashes": {x.name: sha(x) for x in files},
        "stdout_sha256": sha(stdout), "stderr_sha256": sha(stderr), "project_post_hashes": project_after})
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_238", "revision": 1,
        "status": f"GHIDRA_BATCH_{batch}_{status}", "generated_at": now(),
        "original_candidate_bodies_verified": 506,
        "ghidra_output_rows": sum(len(list((REPORT / f"ghidra_raw_batch{k}").glob("*.json"))) for k in range(1, batch+1)),
        "new_imports": 0})
    print(json.dumps({"phase": "run", "batch": batch, "status": status, "outputs": len(files),
                      "seconds": round(time.monotonic()-started, 3)}), flush=True)


def finalize() -> None:
    check()
    index = json.loads((REPORT / "source_index.json").read_text(encoding="utf-8"))
    spread = json.loads((REPORT / "source_spread_recheck.json").read_text(encoding="utf-8"))
    source_bytes = SOURCE.read_bytes()
    md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    target_by_index = {x["global_index"]: x for x in index["selected"]}
    spread_errors = []
    for sample in spread["samples"]:
        target = target_by_index[sample["index"]]
        offset = int(target["file_offset"], 16) + sample["slot"] * 4
        word = source_bytes[offset:offset+4]
        va = int(target["elf_va"], 16) + sample["slot"] * 4
        decoded = list(md.disasm(word, va, count=1))
        text = (decoded[0].mnemonic + " " + decoded[0].op_str).strip() if decoded and decoded[0].size == 4 else None
        if (word.hex(), f"0x{va:x}", text) != (sample["word_hex"], sample["elf_va"], sample["assembly"]):
            spread_errors.append((sample["index"], sample["slot"]))
    if spread_errors or len(spread["samples"]) * 10 < sum(x["instruction_slots"] for x in index["selected"]):
        raise RuntimeError(f"independent spread recheck failed: {spread_errors[:5]}")
    write_json(REPORT / "source_spread_recheck.json", {**spread,
        "independent_original_byte_and_capstone_recheck": True,
        "mismatches": len(spread_errors), "rechecked_at": now()})
    rows = []
    receipts = []
    for batch in range(1, 17):
        rec = json.loads((REPORT / f"ghidra_batch{batch}_command.json").read_text(encoding="utf-8"))
        receipts.append(rec)
        if rec["status"] != "OUTPUT_READY" or rec["raw_result_files"] != index["batches"][str(batch)]["count"]:
            raise RuntimeError(f"incomplete batch {batch}")
        for file in sorted((REPORT / f"ghidra_raw_batch{batch}").glob("*.json")):
            row = json.loads(file.read_text(encoding="utf-8"))
            if file.name not in rec["raw_result_hashes"] or sha(file) != rec["raw_result_hashes"][file.name]:
                raise RuntimeError(f"unsealed Ghidra raw row {file}")
            rows.append((file, row))
    if len(rows) != 506 or {x["index"] for _, x in rows} != {x["global_index"] for x in index["selected"]}:
        raise RuntimeError("raw target index set differs")
    selected = {x["global_index"]: x for x in index["selected"]}
    for file, row in rows:
        target = selected[row["index"]]
        if row["ghidra_memory_sha256"] != target["source_body_sha256"] or row["size_bytes"] != target["size_bytes"]:
            raise RuntimeError(f"Ghidra/source body mismatch: {file}")
        if row["ghidra_instruction_count"] + row["missing_analyzed_instruction_count"] != target["instruction_slots"]:
            raise RuntimeError(f"Ghidra listing slot mismatch: {file}")
        if len(row["instruction_pcode"]) != target["instruction_slots"]:
            raise RuntimeError(f"Ghidra pcode slot map mismatch: {file}")
        start = int(row["database_va"], 16)
        if any(int(pos["database_va"], 16) != start + 4 * offset
               for offset, pos in enumerate(row["instruction_pcode"])):
            raise RuntimeError(f"Ghidra pcode address map mismatch: {file}")
    summary = {"task_id": "TASK_238", "revision": 1,
        "result": "PARTIAL_STATIC_RESEARCH_BOUNDARIES_UNPROVEN",
        "original_fde_candidate_bodies_verified": 506,
        "original_bytes_verified": sum(x["size_bytes"] for x in index["selected"]),
        "original_instruction_words_verified": 48116,
        "ghidra_raw_rows": len(rows),
        "ghidra_listing_positions": sum(x["ghidra_instruction_count"] for _, x in rows),
        "ghidra_missing_listing_positions": sum(x["missing_analyzed_instruction_count"] for _, x in rows),
        "ghidra_pcode_operations": sum(x["ghidra_pcode_ops"] for _, x in rows),
        "nonempty_c_like_outputs": sum(bool(x["c_like_nonempty"]) for _, x in rows),
        "full_fde_body_membership_rows": sum(x["fde_byte_membership_count"] == x["size_bytes"] for _, x in rows),
        "other_function_overlap_rows": sum(x["other_function_byte_count"] > 0 for _, x in rows),
        "verified_behavior_candidates": 0,
        "skipped_oversized_candidates_pending": index["skipped_oversized_candidates_pending"],
        "spread_provenance_rechecked": len(spread["samples"]),
        "spread_provenance_mismatches": 0,
        "project_files_unchanged": all(rec["project_post_hashes"] == {x["relative_path"]: x["sha256"] for x in index["project_files"]} for rec in receipts)}
    write_json(REPORT / "verification_summary.json", summary)
    report = ("# TASK_238 R1 — libPVGImageCodec.so bounded internal candidates\n\n"
              "**PARTIAL static research.** Exact 506 pinned nonexport FDE candidates revalidated against the "
              f"original SO: {summary['original_bytes_verified']:,} bytes / 48,116 AArch64 instruction words. "
              f"Ghidra produced {summary['ghidra_raw_rows']} raw rows, "
              f"{summary['nonempty_c_like_outputs']} nonempty C-like texts, "
              f"{summary['ghidra_listing_positions']:,}/48,116 listing positions, "
              f"{summary['ghidra_pcode_operations']:,} p-code operations. "
              f"Full FDE body membership appears in {summary['full_fde_body_membership_rows']}/506 rows; "
              f"{summary['other_function_overlap_rows']} rows overlap another Ghidra function. "
              "Earlier oversized image candidates 555, 1542, 1586, 1620, 1623, 1626, 1830, 1912, 2293, 2775, 2776, 3106, 3132, 3134, 3285, 3523 and current 3867, 3877, 4025, 4051, 4052, 4066 remain pending. "
              "These are observed outputs, not proven source-function boundaries or recovered algorithm behavior. "
              "No native/device equivalence, product Phase PASS, V4 or P7 is claimed. "
              "Independent CEO review and commit/push remain pending.\n")
    write(REPORT / "01_MASTER_REPORT.md", report.encode("utf-8"))
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_238", "revision": 1,
        "status": "FINAL_RESEARCH_CANDIDATE", "generated_at": now(),
        "original_candidate_bodies_verified": 506, "ghidra_output_rows": 506,
        "ghidra_listing_positions": summary["ghidra_listing_positions"],
        "nonempty_c_like_outputs": summary["nonempty_c_like_outputs"],
        "spread_provenance_rechecked": summary["spread_provenance_rechecked"],
        "verified_behavior_candidates": 0, "new_imports": 0})
    files = {x.relative_to(REPORT).as_posix(): sha(x) for x in REPORT.rglob("*")
             if x.is_file() and x.name not in ("COMPLETE.json", "PROGRESS.json")}
    code_files = {x.relative_to(ROOT).as_posix(): sha(x) for x in SCRIPT_DIR.rglob("*") if x.is_file()}
    scratch_files = {x.relative_to(ROOT).as_posix(): sha(x) for x in SCRATCH.rglob("*") if x.is_file()}
    complete = {"schema_version": "2.1.2", "task_id": "TASK_238", "revision": 1,
        "status": "COMPLETE", "research_result": summary["result"], "generated_at": now(),
        "agent_id": AGENT, "lease_id": LEASE_ID, "fencing_token": FENCE,
        "standard_path": str(STANDARD), "standard_sha256": STANDARD_SHA,
        "task_sha256": TASK_SHA, "target_manifest_sha256": TARGET_SHA,
        "original_so_sha256": SOURCE_SHA,
        "original_fde_candidate_bodies_verified": 506,
        "original_instruction_words_verified": 48116,
        "nonempty_c_like_outputs": summary["nonempty_c_like_outputs"],
        "verified_behavior_candidates": 0,
        "files": files, "code_files": code_files, "scratch_files": scratch_files}
    write_json(REPORT / "COMPLETE.json", complete)
    print(json.dumps({"phase": "finalize", **summary, "report_files": len(files)}), flush=True)


if __name__ == "__main__":
    if len(sys.argv) < 2 or sys.argv[1] not in ("prepare", "run", "finalize"):
        raise SystemExit("usage: pipeline.py prepare|run <1..4>|finalize")
    if sys.argv[1] == "prepare":
        prepare()
    elif sys.argv[1] == "run":
        run_batch(int(sys.argv[2]))
    else:
        finalize()
