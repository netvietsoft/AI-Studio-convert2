"""Independent R2 verification of immutable TASK_187 R1 native evidence.

This script does not invoke Ghidra or write to the R1 task. It checks the
original ELF and the recorded raw outputs before sealing an R2-only report.
"""
from __future__ import annotations

import hashlib
import json
import math
import os
import tempfile
from datetime import datetime, timezone
from pathlib import Path

import psutil
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]
CODE = Path(__file__).resolve().parent
REPORT = ROOT / "RULES/REPORT/TASK_187_REPORT_R2"
R1_REPORT = ROOT / "RULES/REPORT/TASK_187_REPORT_R1"
R1_CODE = ROOT / "scripts/task_187_codex_internal"
R1_SCRATCH = ROOT / "RESEARCH_WORK/TASK_187_R1"
R2_SCRATCH = ROOT / "RESEARCH_WORK/TASK_187_R2"
R1_ARCHIVE = ROOT / ".ai/ceo/reviews/TASK_187_R1_TASK_SNAPSHOT.md"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
TASK = ROOT / "RULES/TASK/TASK_187_SO45_CODEX_INTERNAL_ACTIVE.md"
TARGETS = ROOT / ".ai/ceo/reviews/TASK_187_internal_targets.json"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libMTFilterKernel.so")
HISTORICAL_PROJECT = ROOT / "RESEARCH_WORK/TASK_165_R1/ghidra_project"
AGENT = "/root/so45_ai_model_search"
LEASE = "LEASE-CEO-WORKER-TASK_187-R2"
FENCE = 1218
DEADLINE = datetime.fromisoformat("2026-10-13T11:32:24.643651+00:00")
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
TASK_SHA = "787386f96e5837df33b71c069eb2b0caebb6273d24137ca7fb41e921a4301a61"
TARGET_SHA = "cdca39d65d7a29d866b3e43264f687d147b549c43945e4f0c694fb8e73d56bf8"
SOURCE_SHA = "f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4"
R1_TASK_SHA = "6f62d5b04b4681750141b52f99916ad3685ec1871a0a74f28a5829e3322888d3"
CORRECTIONS = {18, 23, 30, 43, 85, 128}
MNEMONIC_ALIASES = {("b.hs", "b.cs"), ("b.lo", "b.cc"), ("mov", "orr")}


def sha(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        for chunk in iter(lambda: handle.read(1 << 20), b""):
            digest.update(chunk)
    return digest.hexdigest()


def load(path: Path) -> dict:
    return json.loads(path.read_text(encoding="utf-8"))


def utcnow() -> str:
    return datetime.now(timezone.utc).isoformat().replace("+00:00", "Z")


def require(condition: bool, message: str) -> None:
    if not condition:
        raise RuntimeError(message)


def guard() -> None:
    for path, expected in ((STANDARD, STANDARD_SHA), (TASK, TASK_SHA),
                           (TARGETS, TARGET_SHA), (SOURCE, SOURCE_SHA),
                           (R1_ARCHIVE, R1_TASK_SHA)):
        require(path.is_file() and sha(path) == expected, f"pinned input changed: {path}")
    flag = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    require(not flag.is_file() or flag.read_text(encoding="utf-8-sig").strip().upper() != "TRUE",
            "END_AGENT_SESSION=TRUE")
    require(datetime.now(timezone.utc) < DEADLINE, "R2 deadline reached")
    matches = [row for row in load(ROOT / ".ai/locks.json")["active_locks"]
               if row.get("lease_id") == LEASE]
    require(len(matches) == 1, "R2 lease missing/duplicated")
    lock = matches[0]
    identity = (lock.get("status"), lock.get("task_id"), lock.get("task_revision"),
                lock.get("agent_id"), lock.get("task_sha"), lock.get("fencing_token"))
    require(identity == ("ACTIVE", "TASK_187", 2, AGENT, TASK_SHA, FENCE),
            f"R2 lease identity differs: {identity}")
    require(datetime.fromisoformat(lock["expiry"].replace("Z", "+00:00")) > datetime.now(timezone.utc),
            "R2 lease expired")
    allowed = lock.get("files_allowed", [])
    require(all(path in allowed for path in (
        "RULES/REPORT/TASK_187_REPORT_R2/**", "scripts/task_187_codex_continuation_r2/**",
        "RESEARCH_WORK/TASK_187_R2/**")), "R2 lease write scope differs")


def atomic_bytes(path: Path, value: bytes) -> None:
    guard()
    require(path.resolve().is_relative_to(REPORT.resolve()), f"outside R2 report scope: {path}")
    path.parent.mkdir(parents=True, exist_ok=True)
    descriptor, temporary = tempfile.mkstemp(prefix=".task187r2-", dir=path.parent)
    try:
        with os.fdopen(descriptor, "wb") as handle:
            handle.write(value)
            handle.flush()
            os.fsync(handle.fileno())
        os.replace(temporary, path)
    finally:
        if os.path.exists(temporary):
            os.unlink(temporary)


def write_json(path: Path, value: object) -> None:
    atomic_bytes(path, (json.dumps(value, ensure_ascii=False, indent=2) + "\n").encode("utf-8"))


def tree_inventory(folder: Path) -> dict[str, dict]:
    require(folder.is_dir(), f"missing evidence root: {folder}")
    result = {}
    for path in sorted(folder.rglob("*")):
        require(not path.is_symlink(), f"symlink in evidence tree: {path}")
        if path.is_file():
            result[path.relative_to(ROOT).as_posix()] = {
                "bytes": path.stat().st_size, "sha256": sha(path)}
    return result


def verify_receipt(path: Path, script: Path, tsv: Path, raw_folder: Path,
                   expected_count: int, expected_batch: int | None = None) -> dict:
    receipt = load(path)
    require(receipt["task_id"] == "TASK_187" and receipt["revision"] == 1 and
            receipt["lease_id"] == "LEASE-CEO-WORKER-TASK_187-R1" and
            receipt["fencing_token"] == 1216 and receipt["status"] == "OUTPUT_READY" and
            receipt["exit_code"] == 0 and receipt["raw_result_files"] == expected_count and
            receipt["script_sha256"] == sha(script) and
            receipt["target_tsv_sha256"] == sha(tsv) and
            receipt["max_cpu"] == 1 and receipt["max_heap"] == "1G" and
            receipt["max_process_seconds"] <= 1200 and receipt["elapsed_seconds"] <= 1200 and
            receipt["max_decompile_seconds_per_candidate"] == 10 and
            "-readOnly" in receipt["command"] and "-noanalysis" in receipt["command"] and
            "-import" not in receipt["command"] and
            receipt["command"].count(script.name) == 1,
            f"Ghidra command bounds/provenance differ: {path.name}")
    if expected_batch is None:
        require(receipt["target_indices"] == sorted(CORRECTIONS), "correction indices differ")
        prefix = "ghidra_correction"
    else:
        require(receipt["batch"] == expected_batch and
                receipt["source_sha256"] == SOURCE_SHA, "batch identity/source differs")
        prefix = f"ghidra_batch{expected_batch}"
    require(receipt["stdout_sha256"] == sha(R1_REPORT / f"{prefix}_stdout.log") and
            receipt["stderr_sha256"] == sha(R1_REPORT / f"{prefix}_stderr.log") and
            len(receipt["raw_result_hashes"]) == expected_count,
            f"Ghidra logs/raw count differ: {path.name}")
    actual_names = {p.name for p in raw_folder.glob("*.json")}
    require(actual_names == set(receipt["raw_result_hashes"]),
            f"raw file set differs: {path.name}")
    for name, digest in receipt["raw_result_hashes"].items():
        require(sha(raw_folder / name) == digest, f"raw hash differs: {name}")
    return {"path": path.relative_to(ROOT).as_posix(), "sha256": sha(path),
            "raw_count": expected_count, "elapsed_seconds": receipt["elapsed_seconds"],
            "script_sha256": receipt["script_sha256"]}


def gaps(bits: str) -> list[dict]:
    result = []
    start = None
    for index, bit in enumerate(bits):
        if bit == "0" and start is None:
            start = index
        if bit == "1" and start is not None:
            result.append({"start_offset": start, "end_exclusive": index})
            start = None
    if start is not None:
        result.append({"start_offset": start, "end_exclusive": len(bits)})
    return result


def sampled_slots(slots: int) -> list[int]:
    n = max(1, math.ceil(slots * 0.12))
    return sorted({round(i * (slots - 1) / (n - 1)) for i in range(n)}) if n > 1 else [slots // 2]


def main() -> None:
    guard()
    require(not (REPORT / "COMPLETE.json").exists(), "R2 seal already exists")
    running = []
    for process in psutil.process_iter(["pid", "name", "cmdline"]):
        try:
            command = " ".join(process.info["cmdline"] or [])
            if ("TASK_187_R1" in command or "task_187_codex_internal" in command or
                    "TASK_187_REPORT_R1" in command) and "analyzeHeadless" in command:
                running.append({"pid": process.info["pid"], "name": process.info["name"]})
        except (psutil.AccessDenied, psutil.NoSuchProcess):
            continue
    require(not running, f"R1 Ghidra process still running: {running}")
    r1_inventory_before = {
        "report": tree_inventory(R1_REPORT), "code": tree_inventory(R1_CODE),
        "scratch": tree_inventory(R1_SCRATCH)}
    require("RULES/REPORT/TASK_187_REPORT_R1/COMPLETE.json" not in r1_inventory_before["report"],
            "R1 unexpectedly sealed")
    index = load(R1_REPORT / "source_project_index.json")
    manifest = load(TARGETS)
    require(len(manifest["targets"]) == 128 and len(index["selected_candidate_rows"]) == 128 and
            index["source_sha256"] == SOURCE_SHA and index["task_sha256"] == R1_TASK_SHA and
            index["target_manifest_sha256"] == TARGET_SHA and
            index["all_fde_count"] == 2873 and index["all_nonexport_fde_candidates"] == 511 and
            index["defined_nonzero_export_vas"] == 2362 and
            index["project_source"] == str(HISTORICAL_PROJECT) and
            index["project_copy"] == str(R1_SCRATCH / "ghidra_project"),
            "R1 source/project index differs")
    receipts = [
        verify_receipt(R1_REPORT / f"ghidra_batch{batch}_command.json",
                       R1_CODE / "ExtractInternal187.java",
                       R1_SCRATCH / f"target_batch_{batch}.tsv",
                       R1_REPORT / f"ghidra_raw_batch{batch}", 64, batch)
        for batch in (1, 2)]
    receipts.append(verify_receipt(R1_REPORT / "ghidra_correction_command.json",
                                   R1_CODE / "RepairMembership187.java",
                                   R1_SCRATCH / "correction_targets.tsv",
                                   R1_REPORT / "ghidra_correction_raw", 6))
    project_rows = []
    for record in index["project_files"]:
        relative = record["relative_path"]
        original = HISTORICAL_PROJECT / relative
        copy = R1_SCRATCH / "ghidra_project" / relative
        require(original.is_file() and copy.is_file() and
                original.stat().st_size == record["bytes"] and
                sha(original) == record["sha256"] and sha(copy) == record["sha256"],
                f"historical/copy Ghidra project byte hash differs: {relative}")
        project_rows.append({"relative_path": relative, "sha256": record["sha256"]})
    require(len(project_rows) == 9, "Ghidra project copy file count differs")
    source_bytes = SOURCE.read_bytes()
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        require(elf["e_machine"] == "EM_AARCH64", "ELF architecture differs")
        fdes = sorted((int(entry["initial_location"]), int(entry["address_range"]))
                      for entry in elf.get_dwarf_info().EH_CFI_entries()
                      if isinstance(entry, FDE))
        dyn = elf.get_section_by_name(".dynsym")
        exports = sorted((int(sym["st_value"]), int(sym["st_size"]))
                         for sym in dyn.iter_symbols()
                         if sym["st_info"]["type"] == "STT_FUNC" and
                         sym["st_shndx"] != "SHN_UNDEF" and
                         int(sym["st_value"]) > 0 and int(sym["st_size"]) > 0)
        export_starts = {address for address, _ in exports}
        nonexports = [row for row in fdes if row[0] not in export_starts]
        segments = [(int(seg["p_vaddr"]), int(seg["p_offset"]), int(seg["p_filesz"]))
                    for seg in elf.iter_segments() if seg["p_type"] == "PT_LOAD"]
    require(len(fdes) == 2873 and len(export_starts) == 2362 and len(nonexports) == 511,
            "original ELF FDE/export census differs")
    selected = [(int(row["elf_va"], 16), int(row["size_bytes"]))
                for row in manifest["targets"]]
    require(selected == nonexports[:128], "target ordering/nonexport selection differs")
    capstone = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    records = []
    samples = []
    total_slots = 0
    total_pcode_ops = 0
    original_full = 0
    original_missing_slots = 0
    corrections_seen = set()
    for position, (va, size) in enumerate(selected, 1):
        guard()
        target = manifest["targets"][position - 1]
        name = f"{position:03d}_{va:x}.json"
        offsets = [offset + va - base for base, offset, length in segments
                   if base <= va and va + size <= base + length]
        require(len(offsets) == 1 and offsets[0] == int(target["file_offset"], 16),
                f"PT_LOAD body mapping differs: #{position}")
        body = source_bytes[offsets[0]:offsets[0] + size]
        digest = hashlib.sha256(body).hexdigest()
        require(len(body) == size and digest == target["body_sha256"] and
                size % 4 == 0 and target["instruction_slots"] == size // 4,
                f"original target body hash/size differs: #{position}")
        require(not any(other_va < va + size and va < other_va + other_size
                        for other_va, other_size in fdes if other_va != va),
                f"another FDE intersects target: #{position}")
        require(not any(export_va < va + size and va < export_va + export_size
                        for export_va, export_size in exports),
                f"export function body intersects target: #{position}")
        src = load(R1_REPORT / "source_assembly" / name)
        raw = load(R1_REPORT / f"ghidra_raw_batch{1 if position <= 64 else 2}" / name)
        indexed = index["selected_candidate_rows"][position - 1]
        require(src["index"] == raw["index"] == indexed["index"] == position and
                src["elf_va"] == raw["elf_va"] == indexed["elf_va"] == target["elf_va"] and
                src["size_bytes"] == raw["size_bytes"] == indexed["size_bytes"] == size and
                src["source_body_sha256"] == indexed["source_body_sha256"] ==
                raw["ghidra_memory_sha256"] == digest and
                src["file_offset"] == indexed["file_offset"] == target["file_offset"] and
                src["fde_exact_match"] is True and not src["other_fde_overlap"] and
                not src["export_body_overlap"] and
                len(src["instructions"]) == len(raw["instruction_pcode"]) == size // 4 and
                raw["instruction_slots"] == src["instruction_slots"] == size // 4 and
                raw["decompile_elapsed_ms"] <= 10_000 and raw["c_like_nonempty"] is True and
                raw["c_like_text"].strip() and not raw["decompile_error"] and
                raw["other_function_byte_count"] == 0,
                f"source/first-pass Ghidra row differs: #{position}")
        bits = raw["fde_byte_membership_bits"]
        members = bits.count("1")
        require(len(bits) == size and set(bits) <= {"0", "1"} and
                members == raw["fde_byte_membership_count"] and
                raw["fde_missing_body_ranges"] == gaps(bits) and
                raw["fde_byte_membership_transitions"] == sum(bits[i] != bits[i-1]
                                                            for i in range(1, len(bits))) and
                raw["function_body_total_address_count"] == members and
                int(raw["function_start"], 16) == int(raw["database_va"], 16),
                f"full-byte original Ghidra membership differs: #{position}")
        old_missing = raw["missing_analyzed_instruction_count"]
        original_missing_slots += old_missing
        if members == size:
            original_full += 1
        corrected = None
        if position in CORRECTIONS:
            corrected = load(R1_REPORT / "ghidra_correction_raw" / name)
            cbits = corrected["corrected_function_fde_membership_bits"]
            require(members < size and old_missing > 0 and
                    corrected["index"] == position and corrected["elf_va"] == target["elf_va"] and
                    corrected["size_bytes"] == size and corrected["memory_sha256"] == digest and
                    corrected["original_function_fde_membership_bits"] == bits and
                    corrected["original_function_fde_membership_count"] == members and
                    corrected["other_function_byte_count"] == 0 and
                    corrected["temporary_old_function_removed"] is True and
                    corrected["temporary_full_fde_function_created"] is True and
                    corrected["memory_unchanged_after_rollback"] is True and
                    cbits == "1" * size and
                    corrected["corrected_function_fde_membership_count"] == size and
                    corrected["corrected_function_body_total_address_count"] == size and
                    corrected["full_fde_instruction_count"] == size // 4 and
                    corrected["decompile_elapsed_ms"] <= 10_000 and
                    corrected["c_like_nonempty"] is True and corrected["c_like_text"].strip() and
                    not corrected["error"],
                    f"transient correction evidence differs: #{position}")
            effective = corrected["instruction_pcode"]
            c_text = corrected["c_like_text"]
            corrections_seen.add(position)
        else:
            require(bits == "1" * size and old_missing == 0 and
                    raw["ghidra_instruction_count"] == size // 4,
                    f"unlisted Ghidra body/instruction gap: #{position}")
            effective = raw["instruction_pcode"]
            c_text = raw["c_like_text"]
        require(len(effective) == size // 4, f"effective instruction set differs: #{position}")
        decoded = list(capstone.disasm(body, va))
        require(len(decoded) == size // 4 and all(ins.size == 4 for ins in decoded),
                f"original Capstone instruction coverage differs: #{position}")
        local_ops = 0
        sampled = set(sampled_slots(len(decoded)))
        for slot, (instruction, src_inst, gh_inst) in enumerate(zip(
                decoded, src["instructions"], effective)):
            word = body[4*slot:4*slot+4]
            require(src_inst["elf_va"] == f"0x{va + 4*slot:x}" and
                    src_inst["word_hex"] == word.hex() and
                    int(gh_inst["database_va"], 16) == int(raw["database_va"], 16) + 4*slot and
                    not gh_inst.get("missing_analyzed_instruction") and
                    not gh_inst.get("missing_instruction") and
                    isinstance(gh_inst.get("pcode_ops"), list),
                    f"source word/Ghidra p-code position differs: #{position}/{slot}")
            local_ops += len(gh_inst["pcode_ops"])
            if slot in sampled:
                source_mnemonic = instruction.mnemonic.lower()
                ghidra_mnemonic = gh_inst["assembly"].split()[0].lower()
                require(source_mnemonic == src_inst["assembly"].split()[0].lower() and
                        (source_mnemonic == ghidra_mnemonic or
                         (source_mnemonic, ghidra_mnemonic) in MNEMONIC_ALIASES),
                        f"sampled source/Ghidra mnemonic differs: #{position}/{slot}")
                samples.append({"candidate_index": position, "elf_va": f"0x{va + 4*slot:x}",
                                "instruction_slot": slot, "word_hex": word.hex(),
                                "source_mnemonic": source_mnemonic,
                                "ghidra_mnemonic": ghidra_mnemonic,
                                "pcode_op_count": len(gh_inst["pcode_ops"]),
                                "pcode_sha256": hashlib.sha256("\n".join(
                                    gh_inst["pcode_ops"]).encode("utf-8")).hexdigest()})
        require(local_ops == (corrected["full_fde_pcode_ops"] if corrected else raw["ghidra_pcode_ops"]),
                f"p-code operation census differs: #{position}")
        total_slots += len(decoded)
        total_pcode_ops += local_ops
        records.append({"index": position, "elf_va": target["elf_va"],
                        "fde_size_bytes": size, "original_body_sha256": digest,
                        "original_ghidra_body_member_bytes": members,
                        "original_ghidra_body_missing_ranges": gaps(bits),
                        "transient_corrected_full_fde_metadata": corrected is not None,
                        "effective_pcode_instruction_slots": len(effective),
                        "effective_pcode_operations": local_ops,
                        "effective_c_like_sha256": hashlib.sha256(c_text.encode("utf-8")).hexdigest(),
                        "effective_c_like_chars": len(c_text),
                        "sampled_instruction_slots": len(sampled),
                        "first_pass_raw_sha256": sha(R1_REPORT /
                            f"ghidra_raw_batch{1 if position <= 64 else 2}" / name),
                        "correction_raw_sha256": sha(R1_REPORT / "ghidra_correction_raw" / name)
                            if corrected else None})
    require(len(records) == 128 and total_slots == 14865 and total_pcode_ops == 40694 and
            original_full == 122 and original_missing_slots == 66 and
            corrections_seen == CORRECTIONS and len(samples) >= math.ceil(total_slots * .1),
            "final candidate/position/membership/sample census differs")
    require(r1_inventory_before == {
        "report": tree_inventory(R1_REPORT), "code": tree_inventory(R1_CODE),
        "scratch": tree_inventory(R1_SCRATCH)},
        "R1 evidence changed during R2 verification")
    verification = {"task_id": "TASK_187", "revision": 2, "agent_id": AGENT,
                    "lease_id": LEASE, "fencing_token": FENCE, "generated_at": utcnow(),
                    "source_sha256": SOURCE_SHA, "target_manifest_sha256": TARGET_SHA,
                    "r1_task_archive_sha256": R1_TASK_SHA,
                    "original_candidate_bodies_verified": len(records),
                    "original_instruction_words_verified": total_slots,
                    "effective_ghidra_pcode_positions_verified": total_slots,
                    "effective_ghidra_pcode_operations": total_pcode_ops,
                    "nonempty_c_like_texts": len(records),
                    "original_full_byte_body_membership": original_full,
                    "original_missing_instruction_slots": original_missing_slots,
                    "transient_full_fde_metadata_corrections": sorted(corrections_seen),
                    "spread_sample_instruction_count": len(samples),
                    "spread_sample_fraction": len(samples)/total_slots,
                    "spread_sample_addresses": samples,
                    "rows": records, "ghidra_processes_running_for_r1": running,
                    "fresh_imports_or_ghidra_runs_by_r2": 0,
                    "r1_command_receipts": receipts,
                    "historical_and_private_project_files_verified": project_rows,
                    "limitation": "FDE ranges and transient full-range metadata are static candidates; C-like text is not semantic or device parity."}
    inventory = {"task_id": "TASK_187", "revision": 2,
                 "generated_at": utcnow(), "r1_unsealed": True,
                 "r1_evidence": r1_inventory_before,
                 "r1_evidence_file_count": sum(map(len, r1_inventory_before.values())),
                 "r1_task_archive": {"path": R1_ARCHIVE.relative_to(ROOT).as_posix(),
                                     "sha256": R1_TASK_SHA},
                 "target_manifest": {"path": TARGETS.relative_to(ROOT).as_posix(),
                                     "sha256": TARGET_SHA},
                 "original_source": {"path": str(SOURCE), "sha256": SOURCE_SHA},
                 "historical_project_file_sha256": project_rows}
    write_json(REPORT / "R1_EVIDENCE_INVENTORY.json", inventory)
    write_json(REPORT / "INDEPENDENT_VERIFICATION.json", verification)
    audit = ("# TASK_187 R2 audit index\n\n"
             f"- Canonical Standard fully read before writes: `{STANDARD}`; SHA-256 `{STANDARD_SHA}`.\n"
             f"- Exact ACTIVE R2 task: `{TASK.relative_to(ROOT).as_posix()}`; SHA-256 `{TASK_SHA}`.\n"
             f"- Target manifest SHA-256 `{TARGET_SHA}`; original source SHA-256 `{SOURCE_SHA}`.\n"
             f"- Actual agent/lease/fence: `{AGENT}` / `{LEASE}` / `{FENCE}`.\n"
             f"- R1 task archive SHA-256 `{R1_TASK_SHA}`; R1 report/code/scratch are immutable,"
             " R1 has no COMPLETE.json.\n"
             "- `R1_EVIDENCE_INVENTORY.json` hashes every referenced R1 report, code and scratch file;"
             " `INDEPENDENT_VERIFICATION.json` records original ELF/FDE/PT_LOAD, per-byte membership,"
             " C-like/p-code hashes, raw command receipts and spread instruction addresses.\n"
             "- `COMPLETE.json` hashes every nonvolatile R2 report and code file."
             " No Ghidra relaunch, self-review, commit or push.\n")
    atomic_bytes(REPORT / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    master = ("# TASK_187 R2 — MTFilterKernel static candidate batch continuation\n\n"
              "**PARTIAL static research, R2 evidence package complete for independent CEO review.** "
              "Original R1 worker exhausted its runtime before sealing; R1 remains byte-for-byte "
              "preserved and unsealed. This R2 reverified the exact 128 source-pinned nonexport FDE "
              "candidates against the original libMTFilterKernel.so ELF.\n\n"
              f"Original FDE/PT_LOAD/body hashes agree for 128/128 candidates. {total_slots:,} "
              "AArch64 words match source assembly and Ghidra memory records; the effective Ghidra "
              f"p-code has {total_slots:,} positions and {total_pcode_ops:,} operations. "
              "All 128 effective C-like texts are nonempty and individually hashed in the R2 index. "
              f"Original Ghidra function bodies cover every FDE byte in {original_full}/128 rows; "
              "six rows (#18, #23, #30, #43, #85, #128) originally missed 66 instruction slots. "
              "Their R1 transient metadata corrections show full candidate FDE membership, "
              "assembly and p-code, with source memory unchanged after rollback. Those outputs "
              "remain boundary assumptions and do not establish exact function semantics.\n\n"
              f"R2 independently checked {len(samples):,}/{total_slots:,} ({100*len(samples)/total_slots:.2f}%) "
              "spread instruction addresses against original bytes, Capstone, the R1 source record "
              "and Ghidra text/p-code positions. All R1 report, code and scratch files were hashed "
              "before and after this check and remain unchanged. Three R1 Ghidra command/log/result "
              "sets were rehashed; no task-owned process remained and R2 launched none.\n\n"
              "The remaining 383 nonexport FDE candidates were outside this task. FDE boundaries "
              "do not establish a complete internal-function census. No behavioral equivalence, "
              "device/pixel parity, product Phase PASS, all-45-SO completion or V4/P7 readiness "
              "is claimed. No commit or push occurred pending CEO review.\n")
    atomic_bytes(REPORT / "01_MASTER_REPORT.md", master.encode("utf-8"))
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_187", "revision": 2,
               "status": "SEALED_STATIC_RESEARCH_REVIEW_CANDIDATE",
               "generated_at": utcnow(), "original_bodies_verified": 128,
               "ordinary_spread_instruction_samples": len(samples),
               "r1_immutable_evidence_files": inventory["r1_evidence_file_count"],
               "fresh_imports_or_ghidra_runs": 0, "awaiting_ceo_review": True})
    report_files = {p.relative_to(REPORT).as_posix(): sha(p) for p in sorted(REPORT.rglob("*"))
                    if p.is_file() and p.name not in ("COMPLETE.json", "PROGRESS.json")}
    code_files = {p.relative_to(ROOT).as_posix(): sha(p) for p in sorted(CODE.rglob("*"))
                  if p.is_file()}
    scratch_files = {p.relative_to(ROOT).as_posix(): sha(p) for p in sorted(R2_SCRATCH.rglob("*"))
                     if p.is_file()} if R2_SCRATCH.is_dir() else {}
    report_bytes = sum(p.stat().st_size for p in REPORT.rglob("*") if p.is_file())
    require(report_bytes <= 134_217_728, "R2 report cap exceeded")
    require(r1_inventory_before == {
        "report": tree_inventory(R1_REPORT), "code": tree_inventory(R1_CODE),
        "scratch": tree_inventory(R1_SCRATCH)}, "R1 evidence changed before sealing")
    complete = {"schema_version": "2.1.2", "task_id": "TASK_187", "revision": 2,
                "status": "COMPLETE", "research_result": "PARTIAL_STATIC_FDE_BOUNDARY",
                "review_status": "AWAITING_INDEPENDENT_CEO_REVIEW",
                "generated_at": utcnow(), "agent_id": AGENT, "lease_id": LEASE,
                "fencing_token": FENCE, "standard_sha256": STANDARD_SHA,
                "task_sha256": TASK_SHA, "target_manifest_sha256": TARGET_SHA,
                "original_so_sha256": SOURCE_SHA,
                "original_fde_candidate_bodies_verified": 128,
                "original_instruction_words_verified": total_slots,
                "effective_ghidra_pcode_instruction_positions": total_slots,
                "effective_ghidra_pcode_operations": total_pcode_ops,
                "nonempty_c_like_outputs": 128,
                "original_full_fde_body_membership": original_full,
                "six_transient_full_fde_metadata_corrections": len(corrections_seen),
                "ordinary_spread_instruction_sample_count": len(samples),
                "r1_unsealed_evidence_files_rehashed": inventory["r1_evidence_file_count"],
                "fresh_imports": 0, "behavior_equivalence_tested": False,
                "product_phase_pass": False, "commit_sha": None, "push_receipt": None,
                "files": report_files, "code_files": code_files, "scratch_files": scratch_files,
                "limits": "Static FDE candidate recovery only; six transient metadata corrections and C-like outputs do not prove semantics or image parity."}
    write_json(REPORT / "COMPLETE.json", complete)
    print(json.dumps({"status": "SEALED_R2_STATIC_RESEARCH_CANDIDATE",
                      "complete_sha256": sha(REPORT / "COMPLETE.json"),
                      "r1_evidence_files_rehashed": inventory["r1_evidence_file_count"],
                      "original_bodies": 128, "instruction_words": total_slots,
                      "pcode_ops": total_pcode_ops, "spread_samples": len(samples),
                      "r2_manifest_files": len(report_files)+len(code_files)+len(scratch_files)}))


if __name__ == "__main__":
    main()
