"""Independent read-only audit of TASK_168 original SO and mixed Ghidra provenance."""

import hashlib
import json
import math
import re
from collections import Counter
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_168_REPORT_R1"
TASK = ROOT / "RULES/TASK/TASK_168_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md"
STD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
SRC = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a")
STD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
TASK_SHA = "a33a9ec2b34bbb57f76c59e2ca7343c025b6e52c9e16170313f94225c934827c"
SOURCES = {
    "libARKernelInterface.so": ("594c5085475d8bb58baacb20293aec805211aa5ccc53b3542f3149196d354953", 635, "new"),
    "libPVGColorFunctions.so": ("3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6", 81, "new"),
    "libPVGVideoCodec.so": ("336cf1e8cdaaac1ad5bf77b96a03ae9ad90527e583c82aea44b05b25e5da4d26", 160, "TASK_153"),
    "libffmpegfilter.so": ("f22a7ea6da3194d046ecbce5ce3b602bcb56edfd96444a6e29e1a3c3449cf981", 216, "TASK_155"),
}


def sha(path):
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1 << 20), b""):
            h.update(block)
    return h.hexdigest()


def read(path):
    return json.loads(path.read_text(encoding="utf-8"))


def ck(ok, msg):
    if not ok:
        raise AssertionError(msg)


def spread(count):
    n = math.ceil(count * .1)
    return {1 + round(i * (count - 1) / (n - 1)) for i in range(n)}


def main():
    ck(sha(STD) == STD_SHA and sha(TASK) == TASK_SHA, "standard/task identities")
    seal_path = REPORT / "COMPLETE.json"
    seal_sha = sha(seal_path)
    seal = read(seal_path)
    ck((seal["task_id"], seal["revision"], seal["status"], seal["fencing_token"],
        seal["semantic_disposition"], seal["execution_mode"]) ==
       ("TASK_168", 1, "COMPLETE", 1197, "BOUNDED_EXPORT_CANDIDATE",
        "CODEX_SUBAGENT_NO_AGY"), "seal identity")
    ck(seal["standard_sha256"] == STD_SHA and seal["task_sha256"] == TASK_SHA and
       seal["internal_nonexported_functions_covered"] is False and
       seal["semantic_equivalence_proven"] is False and seal["phase_pass"] is False,
       "bounded gate")
    files = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()} - {
        "COMPLETE.json", "PROGRESS.json"}
    ck(files == set(seal["files"]) and len(files) == 57 and
       len(seal["code_files"]) == 6, "sealed file inventory")
    for rel, expected in seal["files"].items():
        ck(sha(REPORT / rel) == expected, "report hash " + rel)
    for rel, expected in seal["code_files"].items():
        ck(sha(ROOT / rel) == expected, "code hash " + rel)
    report_bytes = sum((REPORT / rel).stat().st_size for rel in files)
    ck(report_bytes == seal["report_bytes_excluding_seal_and_progress"] == 11682180,
       "report byte extent")
    audit = (REPORT / "00_AUDIT_INDEX.md").read_text(encoding="utf-8").lower()
    ck(STD_SHA in audit and TASK_SHA in audit, "audit identity")
    batch = read(REPORT / "batch_run_receipt.json")
    archive = read(REPORT / "historical_archive_receipt.json")
    resume = read(REPORT / "resume_after_guard_receipt.json")
    source_batch = read(REPORT / "source_batch_index.json")
    verify = read(REPORT / "independent_verification.json")
    export_map = [json.loads(line) for line in (REPORT / "export_map.ndjson").read_text(encoding="utf-8").splitlines()]
    ck(batch["status"] == "OUTPUT_READY" and batch["elapsed_seconds"] <= 6600 and
       len(batch["steps"]) == 6 and batch["resumed_after_pre_execution_guard"] is True and
       source_batch["total_export_vas"] == len(export_map) == 1092 and
       len(source_batch["libraries"]) == 4, "batch/source census")
    ck(resume["status"] == "OUTPUT_READY" and resume["first_source_reimported"] is False and
       resume["steps_after_guard"] == 5 and
       resume["first_import_command_sha256"] ==
       sha(REPORT / "libARKernelInterface.so/import/ghidra_command.json"),
       "truthful guard continuation")
    ck(archive["historical_commands_are_reused_evidence_not_current_execution"] is True,
       "historical distinction")
    metrics = Counter()
    independent_samples = []
    expected_map = []
    summaries = []
    cap = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    cap.skipdata = True
    for name, (source_sha, count, provenance) in SOURCES.items():
        source = SRC / name
        index = read(REPORT / name / "source_index.json")
        ck(sha(source) == source_sha and index["source_sha256"] == source_sha and
           index["source_file_size"] == source.stat().st_size and
           index["task_sha256"] == TASK_SHA and index["standard_sha256"] == STD_SHA and
           index["fencing_token"] == 1197 and index["unique_export_vas"] == count and
           len(index["targets"]) == count, name + " original/index identity")
        with source.open("rb") as stream:
            elf = ELFFile(stream)
            ck(elf["e_machine"] == "EM_AARCH64", name + " architecture")
            by_va = {}
            for sym in elf.get_section_by_name(".dynsym").iter_symbols():
                if sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF" and \
                        int(sym["st_size"]) > 0:
                    by_va.setdefault(int(sym["st_value"]), []).append((sym.name, int(sym["st_size"])))
            loads = [{"index": i, "va": int(s["p_vaddr"]), "offset": int(s["p_offset"]),
                      "file_size": int(s["p_filesz"]), "memory_size": int(s["p_memsz"])}
                     for i, s in enumerate(elf.iter_segments()) if s["p_type"] == "PT_LOAD"]
        ck(len(by_va) == count and sum(map(len, by_va.values())) ==
           index["defined_nonzero_function_symbols"] and loads == index["pt_load_segments"],
           name + " independent .dynsym/PT_LOAD")
        source_bytes = source.read_bytes()
        steps = [step for step in batch["steps"] if step["library"] == name]
        rows = {}
        row_meta = {}
        if provenance == "new":
            ck(len(steps) == len(index["chunks"]) + 1 and
               sum("chunk" not in step for step in steps) == 1 and
               steps[0]["status"] == "IMPORT_READY", name + " fresh run steps")
            import_folder = REPORT / name / "import"
            receipt = read(import_folder / "ghidra_command.json")
            command = receipt["command"]
            ck(receipt["status"] == "IMPORT_READY" and receipt["exit_code"] == 0 and
               receipt["fresh_import_attempt_number"] == 1 and receipt["fencing_token"] == 1197 and
               receipt["source_sha256"] == source_sha and 0 < receipt["elapsed_seconds"] <= 900 and
               receipt["elapsed_seconds"] == steps[0]["elapsed_seconds"] and
               command.count("-import") == 1 and "-process" not in command and
               command[4].replace("\\", "/") == str(source).replace("\\", "/") and
               command[command.index("-max-cpu") + 1] == "1" and
               sha(import_folder / "ghidra_stdout.log") == receipt["stdout_sha256"] and
               sha(import_folder / "ghidra_stderr.log") == receipt["stderr_sha256"] and
               "Import succeeded" in (import_folder / "ghidra_stdout.log").read_text(
                   encoding="utf-8", errors="replace"), name + " real one-import evidence")
            ck(receipt["autoanalysis_timed_out"] == (name == "libARKernelInterface.so"),
               name + " autoanalysis timeout disclosure")
            metrics["fresh_imports"] += 1
            for meta in index["chunks"]:
                chunk = REPORT / meta["folder"]
                rec = read(chunk / "ghidra_command.json")
                raw = read(chunk / "ghidra_raw.json")
                step = next((s for s in steps if s.get("chunk") == meta["chunk"]), None)
                ck(step is not None and step["status"] == rec["status"] == "OUTPUT_READY" and
                   rec["exit_code"] == 0 and rec["fencing_token"] == 1197 and
                   0 < rec["elapsed_seconds"] <= 900 and
                   step["elapsed_seconds"] == rec["elapsed_seconds"] and
                   0 < meta["count"] <= 256 and
                   meta["last_index"] - meta["first_index"] + 1 == meta["count"] and
                   rec["command"][3:9] ==
                   ["-process", name, "-noanalysis", "-readOnly", "-max-cpu", "1"] and
                   "-import" not in rec["command"] and
                   rec["script_sha256"] == sha(ROOT / "scripts/task_168_codex_exports/ExportSo168.java"),
                   name + f" chunk {meta['chunk']} run bounds")
                for rel, key in (("targets.tsv", "target_tsv_sha256"),
                                 ("ghidra_raw.json", "result_sha256"),
                                 ("ghidra_stdout.log", "stdout_sha256"),
                                 ("ghidra_stderr.log", "stderr_sha256")):
                    ck(sha(chunk / rel) == rec[key], name + " chunk file " + rel)
                ck(meta["target_tsv_sha256"] == rec["target_tsv_sha256"] and
                   raw["task_id"] == "TASK_168" and raw["program_name"] == name and
                   [r["index"] for r in raw["targets"]] ==
                   list(range(meta["first_index"], meta["last_index"] + 1)) and
                   f"[TASK_168] processed {meta['count']}/{meta['count']}" in
                   (chunk / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace"),
                   name + f" chunk {meta['chunk']} raw/log")
                subset = index["targets"][meta["first_index"] - 1:meta["last_index"]]
                tsv = (chunk / "targets.tsv").read_text(encoding="utf-8").splitlines()
                ck(len(tsv) == len(subset), name + " TSV extent")
                for target, row, line in zip(subset, raw["targets"], tsv):
                    ck(line.split("\t", 4) == [str(target["index"]), target["elf_va"],
                                               str(target["size_bytes"]),
                                               target["source_body_sha256"], target["symbol"]],
                       name + " TSV/source join")
                    ck(row["index"] not in rows, name + " duplicate row")
                    rows[row["index"]] = row
                    row_meta[row["index"]] = (int(raw["image_base"], 16),
                                               (chunk / "ghidra_raw.json").relative_to(REPORT).as_posix(),
                                               "TASK_168_NEW")
        else:
            ck(not steps and not index["chunks"], name + " historical has no fresh execution")
            archive_item = archive["sources"][name]
            historical_root = ROOT / "RULES/REPORT" / f"{provenance}_REPORT_R1"
            historical_seal = read(historical_root / "COMPLETE.json")
            ck(archive_item["prior_task"] == provenance and
               sha(historical_root / "COMPLETE.json") == archive_item["seal_sha256"] and
               historical_seal["task_id"] == provenance and
               historical_seal["status"] == "COMPLETE", name + " historical seal")
            for rel, expected in historical_seal["files"].items():
                ck(sha(historical_root / rel) == expected, name + " old sealed file " + rel)
            for rel, expected in historical_seal["code_files"].items():
                ck(sha(ROOT / rel) == expected, name + " old sealed code " + rel)
            copied = REPORT / name / "historical_raw"
            for filename, item in archive_item["copied_raw_files"].items():
                ck(sha(copied / filename) == item["sha256"] == sha(Path(item["original"])),
                   name + " original/copy bytes " + filename)
            old_index = read(copied / "target_index.json")
            ck(old_index["source_sha256"] == source_sha and
               len(old_index["targets"]) == count, name + " historical original source")
            receipt = read(copied / "ghidra_command.json")
            raw = read(copied / "ghidra_raw.json")
            ck(receipt["status"] == "OUTPUT_READY" and receipt["exit_code"] == 0 and
               receipt["task_id"] == provenance and receipt["library"] == name and
               receipt["source_sha256"] == source_sha and
               receipt["command"].count("-import") == 1 and
               receipt["command"][4].replace("\\", "/") == str(source).replace("\\", "/") and
               raw["task_id"] == provenance and raw["program_name"] == name and
               len(raw["targets"]) == count, name + " historical Ghidra provenance")
            for rel, key in (("targets.tsv", "target_tsv_sha256"),
                             ("ghidra_raw.json", "result_sha256"),
                             ("ghidra_stdout.log", "stdout_sha256"),
                             ("ghidra_stderr.log", "stderr_sha256")):
                ck(sha(copied / rel) == receipt[key], name + " historical file " + rel)
            for pos, (target, old) in enumerate(zip(index["targets"], old_index["targets"]), 1):
                ck(all(target[key] == old[key] for key in
                       ("index", "elf_va", "size_bytes", "file_offset", "source_body_sha256", "symbol")),
                   name + f" historical target {pos}")
            for row in raw["targets"]:
                ck(row["index"] not in rows, name + " duplicate historical row")
                rows[row["index"]] = row
                row_meta[row["index"]] = (int(raw["image_base"], 16),
                                           (copied / "ghidra_raw.json").relative_to(REPORT).as_posix(),
                                           provenance + "_HISTORICAL")
            metrics["historical_reuses"] += 1
        ck(set(rows) == set(range(1, count + 1)), name + " exact row coverage")
        source_assembly = [json.loads(line) for line in
                           (REPORT / name / "source_assembly.ndjson").read_text(encoding="utf-8").splitlines()]
        ck(len(source_assembly) == count, name + " source assembly extent")
        selected = spread(count)
        lib_metrics = Counter()
        for position, target in enumerate(index["targets"], 1):
            va, size = int(target["elf_va"], 16), target["size_bytes"]
            aliases = sorted(by_va[va], key=lambda p: (-p[1], p[0]))
            mapped = [(seg["index"], seg["offset"] + va - seg["va"])
                      for seg in loads if seg["va"] <= va and va + size <= seg["va"] + seg["file_size"]]
            ck(target["index"] == position and len(mapped) == 1 and
               (target["symbol"], size) == aliases[0] and
               target["aliases"] == [{"name": name_, "size_bytes": size_} for name_, size_ in aliases] and
               (target["pt_load_segment_index"], int(target["file_offset"], 16)) == mapped[0],
               name + f" PT_LOAD/aliases {position}")
            body = source_bytes[mapped[0][1]:mapped[0][1] + size]
            body_sha = hashlib.sha256(body).hexdigest()
            ck(len(body) == size and body_sha == target["source_body_sha256"],
               name + f" source body hash {position}")
            decoded = list(cap.disasm(body, va))
            canonical_assembly = [f"0x{ins.address:x}: {ins.mnemonic} {ins.op_str}".rstrip()
                                  for ins in decoded]
            assembly = source_assembly[position - 1]
            ck(assembly["index"] == position and assembly["elf_va"] == target["elf_va"] and
               assembly["source_bytes_hex"] == body.hex() and
               assembly["capstone_source_assembly"] == canonical_assembly,
               name + f" source assembly {position}")
            row = rows[position]
            image_base, raw_path, mode = row_meta[position]
            ck(row["index"] == position and row["elf_va"] == target["elf_va"] and
               row["symbol"] == target["symbol"] and row["size_bytes"] == size and
               int(row["database_va"], 16) == image_base + va and
               row["expected_source_sha256"] == row["ghidra_memory_sha256"] == body_sha and
               row["source_bytes_match"] is True and
               row["decompile_success"] is True and row["pseudocode"].strip() and
               not row["error"] and 0 <= row["elapsed_ms"] <= 15000,
               name + f" Ghidra memory/C {position}")
            addresses = []
            valid = {ins.address: ins for ins in decoded}
            for line in row["instructions"]:
                match = re.match(r"^([0-9a-fA-F]+):\s+", line)
                ck(match is not None, name + f" listing format {position}")
                addresses.append(int(match.group(1), 16) - image_base)
            ck(addresses and addresses == sorted(set(addresses)) and
               len(addresses) == row["instruction_count_observed"] and
               all(address in valid for address in addresses), name + f" listed original VA {position}")
            for call in row["calls"]:
                match = re.match(r"^([0-9a-fA-F]+)\s+->\s+", call)
                ck(match is not None, name + f" call syntax {position}")
                call_va = int(match.group(1), 16) - image_base
                ck(call_va in valid and valid[call_va].mnemonic in ("bl", "blr", "b", "br"),
                   name + f" call original opcode {position}")
            c_hash = hashlib.sha256(row["pseudocode"].encode("utf-8")).hexdigest()
            c_warning = "WARNING:" in row["pseudocode"]
            map_item = {"library": name, "index": position, "elf_va": target["elf_va"],
                        "symbol": target["symbol"], "aliases": target["aliases"],
                        "size_bytes": size, "pt_load_segment_index": target["pt_load_segment_index"],
                        "file_offset": target["file_offset"], "source_body_sha256": body_sha,
                        "ghidra_memory_sha256": body_sha, "c_like_recovered": True,
                        "c_like_utf8_sha256": c_hash,
                        "c_like_characters": len(row["pseudocode"]),
                        "c_warning_present": c_warning,
                        "ghidra_listed_instruction_count": len(addresses),
                        "raw_result": raw_path, "provenance_mode": mode}
            expected_map.append(map_item)
            if position in selected:
                independent_samples.append({"library": name, "index": position,
                    "elf_va": target["elf_va"], "source_body_sha256": body_sha,
                    "source_instruction_count": len(decoded),
                    "ghidra_memory_sha256": body_sha,
                    "ghidra_listed_instruction_count": len(addresses),
                    "c_like_recovered": True})
                lib_metrics["sample_partial"] += len(addresses) < len(decoded)
            lib_metrics["warnings"] += c_warning
            lib_metrics["rows"] += 1
            lib_metrics["calls"] += len(row["calls"])
        ck(lib_metrics["rows"] == count, name + " audit count")
        metrics.update(lib_metrics)
        summaries.append({"library": name, "source_sha256": source_sha, "vas": count,
                          "warnings": lib_metrics["warnings"],
                          "sample": len(selected), "sample_partial": lib_metrics["sample_partial"],
                          "mode": provenance})
    ck(expected_map == export_map, "exact full export map/source/Ghidra join")
    ck(independent_samples == verify["ordinary_samples"] and
       len(independent_samples) == seal["ordinary_spread_provenance_samples"] == 111 and
       verify["ordinary_spread_partial_ghidra_listings"] == metrics["sample_partial"] == 4 and
       verify["c_warning_bodies"] == metrics["warnings"] == 262 and
       verify["original_pt_load_bodies_rehashed"] ==
       verify["ghidra_memory_bodies_rehashed"] ==
       verify["c_like_export_bodies"] ==
       seal["source_bodies_rehashed"] == seal["ghidra_memory_bodies_rehashed"] ==
       seal["c_like_bodies_recovered"] == 1092 and
       verify["fresh_imports_this_task"] == metrics["fresh_imports"] == 2 and
       len(verify["historical_raw_reuse_libraries"]) == metrics["historical_reuses"] == 2,
       "independent aggregate metrics")
    ck(read(REPORT / "unresolved.json")["rows"] == [] and
       seal["unresolved_export_vas"] == [], "truthful unresolved extent")
    ck(sha(seal_path) == seal_sha, "stable seal snapshot")
    print(json.dumps({"verdict": "INDEPENDENT_STATIC_PROVENANCE_PASS",
                      "seal_sha256": seal_sha, "report_files": len(files),
                      "code_files": len(seal["code_files"]), "report_bytes": report_bytes,
                      "sources": summaries, "metrics": dict(metrics),
                      "ordinary_spread": len(independent_samples),
                      "limitation": "ARKernel autoanalysis timed out; 262 C warnings; four sampled partial listings; export-only"}, indent=2))


if __name__ == "__main__":
    main()
