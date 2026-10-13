"""Independent CEO source/raw provenance audit for bounded TASK_169 R1."""

from __future__ import annotations

import hashlib
import json
import math
import re
from collections import Counter
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile

ROOT = Path("F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2")
REPORT = ROOT / "RULES/REPORT/TASK_169_REPORT_R1"
TASK = ROOT / "RULES/TASK/TASK_169_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libLayerFlow.so")
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
SOURCE_SHA = "ef8d1581038778b72abca3ca8fd5046e49fd44e0465871b023647fe42a582262"
TASK_SHA = "8d1342c727fa9661baf00f4f6e0f84b3a74b87552e9112a51e4690d51ec9d912"
DB_REL = "LayerFlowHair146.rep/idata/00/~00000000.db/db.1.gbf"


def digest(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1 << 20), b""):
            h.update(block)
    return h.hexdigest()


def read(path: Path):
    return json.loads(path.read_text(encoding="utf-8"))


def ck(ok, where: str):
    if not ok:
        raise AssertionError(where)


def main():
    ck(digest(STANDARD) == STANDARD_SHA and digest(TASK) == TASK_SHA and
       digest(SOURCE) == SOURCE_SHA, "canonical/task/original source")
    seal_path = REPORT / "COMPLETE.json"
    seal_sha = digest(seal_path)
    seal = read(seal_path)
    ck((seal["task_id"], seal["revision"], seal["status"], seal["semantic_disposition"],
        seal["fencing_token"], seal["execution_mode"]) ==
       ("TASK_169", 1, "COMPLETE", "BOUNDED_RESEARCH_CANDIDATE", 1198,
        "REAL_CODEX_SUBAGENT_REUSED_ANALYZED_PROJECT_NO_AGY"), "seal identity")
    ck(seal["standard_sha256"] == STANDARD_SHA and seal["task_sha256"] == TASK_SHA and
       seal["source_sha256"] == SOURCE_SHA and seal["fresh_imports"] == 0 and
       seal["internal_nonexported_functions_covered"] is False and
       seal["runtime_or_pixel_semantics_proven"] is False, "seal bounded scope")
    listed_files = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()}
    listed_files -= {"COMPLETE.json", "PROGRESS.json"}
    ck(listed_files == set(seal["files"]) and len(listed_files) == 137 and
       len(seal["code_files"]) == 5, "manifest extent")
    for rel, expected in seal["files"].items():
        ck(digest(REPORT / rel) == expected, f"report hash {rel}")
    for rel, expected in seal["code_files"].items():
        ck(digest(ROOT / rel) == expected, f"code hash {rel}")
    ck(sum((REPORT / rel).stat().st_size for rel in listed_files) <= 134217728,
       "report byte cap")
    audit_index = (REPORT / "00_AUDIT_INDEX.md").read_text(encoding="utf-8").lower()
    ck(STANDARD_SHA in audit_index and TASK_SHA in audit_index, "audit index canonical identity")
    index = read(REPORT / "target_index.json")
    verify = read(REPORT / "worker_source_verification.json")
    batch = read(REPORT / "batch_run_receipt.json")
    reuse = read(REPORT / "historical_reuse.json")
    project = read(REPORT / "project_reuse_receipt.json")
    inventory = read(REPORT / "project_inventory.json")
    ck(index["task_id"] == verify["task_id"] == batch["task_id"] == "TASK_169" and
       index["fencing_token"] == verify["fencing_token"] == project["fencing_token"] == 1198 and
       index["source_sha256"] == verify["source_sha256"] == project["source_sha256"] == SOURCE_SHA and
       index["unique_export_vas"] == len(index["targets"]) == 5082 and
       index["defined_nonzero_function_symbols"] == 5341 and
       index["historical_reused_vas"] == 15 and index["new_ghidra_target_vas"] == 5067 and
       len(index["chunks"]) == len(batch["chunks"]) == 20 and
       batch["status"] == "OUTPUT_READY" and batch["elapsed_seconds"] <= 6600 and
       batch["project"]["fresh_imports"] == 0, "census/project/batch metadata")
    ck(project["execution_mode"] == "REUSED_ANALYZED_TASK_147_PROJECT_NO_FRESH_IMPORT" and
       project["copied_project_db_sha256"] == project["historical_lineage"]["project_db_sha256"] and
       digest(Path(project["copied_project"]) / DB_REL) == project["copied_project_db_sha256"] and
       inventory["database_hash_unchanged_from_TASK_147"] is True and
       inventory["files"][DB_REL] == project["copied_project_db_sha256"], "Ghidra project DB lineage")
    for task in ("TASK_146", "TASK_147"):
        copy = REPORT / "historical" / f"{task}_REPORT_R1"
        original = ROOT / "RULES/REPORT" / f"{task}_REPORT_R1"
        old = read(copy / "COMPLETE.json")
        ck(old["task_id"] == task and old["source_sha256"] == SOURCE_SHA and
           digest(copy / "COMPLETE.json") == digest(original / "COMPLETE.json") ==
           project["historical_reports"][task]["source_complete_sha256"], f"{task} old seal")
        for rel, expected in old["files"].items():
            ck(digest(copy / rel) == digest(original / rel) == expected, f"{task} old file {rel}")
        for rel, expected in old["code_files"].items():
            ck(digest(ROOT / rel) == expected, f"{task} old code {rel}")
        command = read(copy / "ghidra_command.json")
        raw_name = "layerflow_hair_ghidra_raw.json" if task == "TASK_146" else "applylayer_ghidra_raw.json"
        ck(command["status"] == "OUTPUT_READY" and command["exit_code"] == 0 and
           command["result_sha256"] == digest(copy / raw_name) and
           command["stdout_sha256"] == digest(copy / "ghidra_stdout.log") and
           command["stderr_sha256"] == digest(copy / "ghidra_stderr.log") and
           command["source_sha256"] == SOURCE_SHA, f"{task} raw command")
    copied = Path(project["copied_project"])
    old_project = Path(project["historical_lineage"]["original_project"])
    for rel, initial in project["copied_project_initial_file_hashes"].items():
        ck(digest(old_project / rel) == initial ==
           project["historical_lineage"]["original_project_file_hashes_at_reuse"][rel],
           f"historical project {rel}")
    rows = {}
    image_bases = {}
    historical = set()
    ck(reuse["historical_reused_vas"] == len(reuse["rows"]) == 15 and
       reuse["excluded_from_new_ghidra_passes"] is True, "historical subset")
    for item in reuse["rows"]:
        task = item["task_id"]
        rel = item["raw_file"]
        raw = read(REPORT / rel)
        ck(digest(REPORT / rel) == item["original_raw_sha256"], "historical raw hash")
        candidates = [r for r in raw["targets"] if r["index"] == item["original_row_index"] and
                      r["elf_va"] == item["elf_va"]]
        ck(len(candidates) == 1 and item["index"] not in rows, "historical row mapping")
        row = dict(candidates[0]); row["index"] = item["index"]
        rows[item["index"]] = row
        image_bases[item["index"]] = int(raw["image_base"], 16)
        historical.add(item["index"])
        ck(item["source_body_sha256"] == index["targets"][item["index"]-1]["source_body_sha256"],
           "historical source body")
        if item["elf_va"] == "0x3f94fc":
            ck(task == "TASK_147" and item["historical_decompile_timeout_seconds"] == 180,
               "applyLayer timeout exception")
        else:
            ck(task == "TASK_146" and item["historical_decompile_timeout_seconds"] == 15,
               "ordinary historical timeout")
    ck(len(historical) == 15, "historical unique")
    previous_end = None
    for number, (meta, outcome) in enumerate(zip(index["chunks"], batch["chunks"])):
        folder = REPORT / f"chunk_{number:02d}"
        command = read(folder / "ghidra_command.json")
        raw = read(folder / "ghidra_raw.json")
        ck(meta["chunk"] == outcome["chunk"] == command["chunk"] == number and
           0 < meta["count"] <= 256 and meta["count"] == len(meta["indices"]) == len(raw["targets"]) and
           outcome["status"] == command["status"] == "OUTPUT_READY" and
           outcome["exit_code"] == command["exit_code"] == 0 and
           0 < command["elapsed_seconds"] <= 900 and
           outcome["elapsed_seconds"] == command["elapsed_seconds"] and
           command["fresh_import"] is False and "-import" not in command["command"] and
           command["command"][3:9] ==
           ["-process", "libLayerFlow.so", "-noanalysis", "-readOnly", "-max-cpu", "1"] and
           command["script_sha256"] == digest(ROOT / "scripts/task_169_codex_exports/ExportLayerFlowChunk169.java") and
           command["project_db_sha256_before"] == command["project_db_sha256_after"] ==
           project["copied_project_db_sha256"] and
           command["source_sha256"] == SOURCE_SHA and
           command["target_tsv_sha256"] == meta["target_tsv_sha256"], f"chunk {number} bounds")
        ck(previous_end is None or command["started_at"] >= previous_end, f"chunk {number} sequential")
        previous_end = command["ended_at"]
        for filename, key in (("targets.tsv", "target_tsv_sha256"),
                              ("ghidra_raw.json", "result_sha256"),
                              ("ghidra_stdout.log", "stdout_sha256"),
                              ("ghidra_stderr.log", "stderr_sha256")):
            ck(digest(folder / filename) == command[key], f"chunk {number} {filename}")
        stdout = (folder / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace")
        ck(f"[TASK_169] processed {meta['count']}/{meta['count']}" in stdout and
           "Processing read-only project file: /libLayerFlow.so" in stdout and
           raw["task_id"] == "TASK_169" and raw["program_name"] == "libLayerFlow.so" and
           [r["index"] for r in raw["targets"]] == meta["indices"], f"chunk {number} raw/log")
        lines = (folder / "targets.tsv").read_text(encoding="utf-8").splitlines()
        ck(len(lines) == len(meta["indices"]), f"chunk {number} TSV extent")
        for row, line in zip(raw["targets"], lines):
            n = row["index"]
            target = index["targets"][n - 1]
            ck(n not in rows and line.split("\t", 4) ==
               [str(n), target["elf_va"], str(target["size_bytes"]),
                target["source_body_sha256"], target["symbol"]], f"chunk {number} target/row")
            rows[n] = row
            image_bases[n] = int(raw["image_base"], 16)
    ck(set(rows) == set(range(1, 5083)) and len(rows) - len(historical) == 5067 and
       len(set(image_bases.values())) == 1, "exact 5,082 Ghidra rows")
    cap = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    source_bytes = SOURCE.read_bytes()
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        ck(elf["e_machine"] == "EM_AARCH64", "ELF AArch64")
        by_va = {}
        for symbol in elf.get_section_by_name(".dynsym").iter_symbols():
            if (symbol["st_info"]["type"] == "STT_FUNC" and symbol["st_shndx"] != "SHN_UNDEF" and
                    int(symbol["st_size"]) > 0 and int(symbol["st_value"]) > 0):
                by_va.setdefault(int(symbol["st_value"]), []).append((symbol.name, int(symbol["st_size"])))
        segments = [(int(s["p_vaddr"]), int(s["p_offset"]), int(s["p_filesz"]))
                    for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
    ck(len(by_va) == 5082 and sum(map(len, by_va.values())) == 5341 and
       [int(t["elf_va"], 16) for t in index["targets"]] == sorted(by_va), "original dynsym VAs")
    totals = Counter()
    samples = 0
    n_sample = math.ceil(5082 * .1)
    spread = {1 + round(i * (5082 - 1) / (n_sample - 1)) for i in range(n_sample)}
    for target, record in zip(index["targets"], verify["records"]):
        n, va, size = target["index"], int(target["elf_va"], 16), target["size_bytes"]
        ck(n == record["index"] and n in rows, f"record order {n}")
        aliases = sorted(by_va[va], key=lambda item: (-item[1], item[0]))
        ck((target["symbol"], size) == aliases[0] and
           target["aliases"] == [name for name, _ in aliases], f"original aliases {n}")
        offsets = [off + va - base for base, off, filesz in segments
                   if base <= va and va + size <= base + filesz]
        ck(len(offsets) == 1 and target["file_offset"] == f"0x{offsets[0]:x}", f"PT_LOAD {n}")
        body = source_bytes[offsets[0]:offsets[0] + size]
        body_sha = hashlib.sha256(body).hexdigest()
        ck(len(body) == size and body_sha == target["source_body_sha256"] ==
           record["source_body_sha256"], f"body {n}")
        decoded = list(cap.disasm(body, va))
        by_addr = {x.address: x for x in decoded}
        full = sum(x.size for x in decoded) == size
        row = rows[n]
        base = image_bases[n]
        ck(row["elf_va"] == target["elf_va"] and row["symbol"] == target["symbol"] and
           row["size_bytes"] == size and int(row["database_va"], 16) == base + va and
           row["expected_source_sha256"] == row["ghidra_memory_sha256"] == body_sha and
           row["source_bytes_match"] is True and row["decompile_success"] is True and
           bool(row["pseudocode"].strip()) and not row["error"], f"Ghidra body/C {n}")
        ck(n in historical or 0 <= row["elapsed_ms"] <= 15000, f"current decompile cap {n}")
        addrs = []
        for line in row["instructions"]:
            match = re.match(r"^([0-9a-fA-F]+):\s+", line)
            ck(match is not None, f"instruction parse {n}")
            addrs.append(int(match.group(1), 16) - base)
        ck(len(addrs) == row["instruction_count_observed"] and
           addrs == sorted(set(addrs)) and all(addr in by_addr for addr in addrs),
           f"Ghidra instruction addresses {n}")
        transfer = 0
        for line in row["calls"]:
            match = re.match(r"^([0-9a-fA-F]+)\s+->\s+", line)
            ck(match is not None, f"call parse {n}")
            call_va = int(match.group(1), 16) - base
            ck(call_va in by_addr and by_addr[call_va].mnemonic in ("bl", "blr", "b", "br"),
               f"original call opcode {n}")
            totals[by_addr[call_va].mnemonic] += 1
            transfer += 1
        c_warning = "WARNING:" in row["pseudocode"]
        fully_listed = full and len(addrs) == len(decoded)
        expected_mode = ("HISTORICAL_TASK_147" if n in historical and va == 0x3f94fc else
                         "HISTORICAL_TASK_146" if n in historical else "TASK_169_NEW")
        ck(record["elf_va"] == target["elf_va"] and record["symbol"] == target["symbol"] and
           record["size_bytes"] == size and record["provenance"] == expected_mode and
           record["source_capstone_instructions"] == len(decoded) and
           record["source_fully_decoded"] == full and
           record["ghidra_listed_instructions"] == len(addrs) and
           record["ghidra_flow_transfers_source_verified"] == transfer and
           record["ghidra_c_like_recovered"] is True and
           record["ghidra_c_like_characters"] == len(row["pseudocode"]) and
           record["ghidra_c_warning_present"] == c_warning, f"worker record join {n}")
        totals["warnings"] += c_warning
        totals["fully_listed"] += fully_listed
        totals["source_instructions"] += len(decoded)
        totals["ghidra_instructions"] += len(addrs)
        totals["source_full"] += full
        if n in spread:
            ck(hashlib.sha256(source_bytes[offsets[0]:offsets[0] + size]).hexdigest() ==
               row["ghidra_memory_sha256"], f"spread ordinary {n}")
            samples += 1
    ck(samples == n_sample == 509 and totals["warnings"] == 2018 and
       totals["fully_listed"] == 3512 and totals["source_instructions"] == 336380 and
       totals["ghidra_instructions"] == 308373 and
       totals["source_full"] == 5082 and
       {k: totals[k] for k in ("bl", "blr", "b", "br")} ==
       verify["ghidra_flow_transfer_source_opcode_counts"] and
       verify["ghidra_listing_alignment_mismatches"] == [] and
       verify["ordinary_records_spread_sampled"] == 509 and
       seal["source_bodies_rehashed"] == seal["ghidra_memory_bodies_rehashed_total"] ==
       seal["c_like_bodies_recovered"] == 5082 and seal["new_ghidra_rows_rehashed"] == 5067 and
       seal["historical_reused_vas"] == 15 and seal["c_bodies_with_warnings"] == 2018 and
       seal["ghidra_fully_listed_bodies"] == 3512 and seal["unrecovered_c_like_vas"] == [],
       "recomputed aggregate source/Ghidra/limitations")
    ck(digest(seal_path) == seal_sha, "stable seal snapshot")
    print(json.dumps({"verdict": "INDEPENDENT_STATIC_PROVENANCE_PASS",
                      "seal_sha256": seal_sha, "report_files": len(listed_files),
                      "code_files": len(seal["code_files"]), "source_export_vas": len(by_va),
                      "historical_rows": len(historical), "fresh_ghidra_rows": len(rows)-len(historical),
                      "ordinary_spread": samples, "metrics": dict(totals),
                      "limitation": "2,018 C warnings, 1,570 partial instruction listings, export-only"},
                     indent=2))


if __name__ == "__main__":
    main()
