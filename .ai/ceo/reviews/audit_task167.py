"""CEO read-only independent verification of TASK_167's sealed static evidence."""

import hashlib
import json
import math
import re
from collections import Counter
from datetime import datetime
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_167_REPORT_R1"
TASK = ROOT / "RULES/TASK/TASK_167_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
SOURCE_ROOT = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a")
STD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
TASK_SHA = "1cca2d3e795cd343e1d70671da47b6d0c64cdee8962c002923e796ecab54d863"
SOURCES = {
    "libarkernel3_android.so": ("81aac3f4cdf285c4e71d0514ea985c60c5a88ac7c5ca9f1a95f812e3368799da", 2607, 2508),
    "libarkernel3_c.so": ("549ace66fe1522b7e9596fce23a3a254fbec25442f177235a10173dff8fde339", 1919, 1869),
}


def digest(path):
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def hashed(data):
    return hashlib.sha256(data).hexdigest()


def read(path):
    return json.loads(path.read_text(encoding="utf-8"))


def require(ok, explanation):
    if not ok:
        raise AssertionError(explanation)


def stamp(s):
    return datetime.fromisoformat(s.replace("Z", "+00:00"))


def main():
    require(digest(STANDARD) == STD_SHA and digest(TASK) == TASK_SHA, "canonical/task identity")
    seal_path = REPORT / "COMPLETE.json"
    initial_seal_sha = digest(seal_path)
    seal = read(seal_path)
    require((seal["task_id"], seal["revision"], seal["status"], seal["fencing_token"],
             seal["semantic_disposition"], seal["execution_mode"]) ==
            ("TASK_167", 1, "COMPLETE", 1196, "BOUNDED_RESEARCH_CANDIDATE",
             "REAL_CODEX_SUBAGENT_NO_AGY"), "seal identity")
    require(seal["standard_sha256"] == STD_SHA and seal["task_sha256"] == TASK_SHA and
            seal["internal_nonexported_functions_covered"] is False and
            seal["runtime_or_pixel_semantics_proven"] is False, "seal scope")
    files = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()} - {
        "COMPLETE.json", "PROGRESS.json"}
    require(set(seal["files"]) == files and len(files) == 104 and
            len(seal["code_files"]) == 5, "manifest exact inventory")
    for rel, expected in seal["files"].items():
        require(digest(REPORT / rel) == expected, "report manifest: " + rel)
    for rel, expected in seal["code_files"].items():
        require(digest(ROOT / rel) == expected, "code manifest: " + rel)
    report_bytes = sum((REPORT / rel).stat().st_size for rel in files)
    require(report_bytes <= 134217728, "report bytes cap")
    audit = (REPORT / "00_AUDIT_INDEX.md").read_text(encoding="utf-8").lower()
    require(STD_SHA in audit and TASK_SHA in audit, "canonical receipt")
    batch = read(REPORT / "batch_run_receipt.json")
    source_batch = read(REPORT / "source_batch_index.json")
    verification = read(REPORT / "independent_verification.json")
    c_manifest = read(REPORT / "source_c_manifest.json")
    require(batch["task_id"] == "TASK_167" and batch["status"] == "OUTPUT_READY" and
            len(batch["chunks"]) == 19 and batch["elapsed_seconds"] <= 6600 and
            source_batch["total_unique_export_vas"] == 4526 and
            len(source_batch["libraries"]) == 2, "aggregate batch")
    require(verification["records"] == c_manifest["records"] and
            verification["libraries"] == c_manifest["source_libraries"] and
            len(verification["records"]) == 4526, "aggregate record files")
    outcomes = {(r["library"], r["chunk"]): r for r in batch["chunks"]}
    require(len(outcomes) == 19, "duplicate chunk outcome")
    script_sha = digest(ROOT / "scripts/task_167_codex_exports/ExportChunk167.java")
    cap = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    totals = Counter()
    summaries = []
    independent_records = []
    c_bodies = []
    imports = 0
    for name, (source_sha, count, expected_full) in SOURCES.items():
        source = SOURCE_ROOT / name
        folder = REPORT / name
        index = read(folder / "target_index.json")
        require(digest(source) == source_sha, name + " original SHA")
        require(index["task_id"] == "TASK_167" and index["task_sha256"] == TASK_SHA and
                index["standard_sha256"] == STD_SHA and index["source_sha256"] == source_sha and
                index["source_size"] == source.stat().st_size and
                index["fencing_token"] == 1196 and index["library"] == name and
                index["unique_export_vas"] == len(index["targets"]) == count and
                len(index["chunks"]) == math.ceil(count / 256), name + " target index")
        with source.open("rb") as stream:
            elf = ELFFile(stream)
            require(elf["e_machine"] == "EM_AARCH64", name + " architecture")
            by_va = {}
            for sym in elf.get_section_by_name(".dynsym").iter_symbols():
                if sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF" and \
                        int(sym["st_size"]) > 0 and int(sym["st_value"]) > 0:
                    by_va.setdefault(int(sym["st_value"]), []).append((sym.name, int(sym["st_size"])))
            loads = [(int(s["p_vaddr"]), int(s["p_offset"]), int(s["p_filesz"]))
                     for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
        require(len(by_va) == count and sum(map(len, by_va.values())) ==
                index["defined_nonzero_function_symbols"], name + " .dynsym")
        source_bytes = source.read_bytes()
        raw_by_index = {}
        base_by_chunk = set()
        last_end = None
        chunk_elapsed = 0.0
        for meta in index["chunks"]:
            number = meta["chunk"]
            chunk = folder / f"chunk_{number:02d}"
            receipt = read(chunk / "ghidra_command.json")
            outcome = outcomes.get((name, number))
            require(outcome is not None and outcome["status"] == "OUTPUT_READY" and
                    outcome["exit_code"] == 0 and receipt["status"] == "OUTPUT_READY" and
                    receipt["exit_code"] == 0 and outcome["observed"] == receipt["observed"] and
                    receipt["fencing_token"] == 1196 and receipt["source_sha256"] == source_sha and
                    receipt["script_sha256"] == script_sha and
                    0 < receipt["elapsed_seconds"] <= 900 and
                    receipt["elapsed_seconds"] == outcome["elapsed_seconds"] and
                    0 < meta["count"] <= 256 and
                    meta["last_index"] - meta["first_index"] + 1 == meta["count"],
                    name + f" chunk {number} receipt/bounds")
            chunk_elapsed += receipt["elapsed_seconds"]
            require(last_end is None or stamp(receipt["started_at"]) >= last_end,
                    name + " sequential chunk timing")
            last_end = stamp(receipt["ended_at"])
            cmd = receipt["command"]
            require(cmd[0].endswith("analyzeHeadless.bat") and
                    cmd[cmd.index("-max-cpu") + 1] == "1" and
                    cmd[cmd.index("-postScript") + 1] == "ExportChunk167.java" and
                    cmd[-2].replace("\\", "/") == str(chunk / "targets.tsv").replace("\\", "/") and
                    cmd[-1].replace("\\", "/") == str(chunk / "ghidra_raw.json").replace("\\", "/"),
                    name + f" chunk {number} command")
            if number == 1:
                require(receipt["operation"] == "IMPORT" and cmd.count("-import") == 1 and
                        "-process" not in cmd and
                        cmd[cmd.index("-import") + 1].replace("\\", "/") == str(source).replace("\\", "/"),
                        name + " one import")
                imports += 1
            else:
                require(receipt["operation"] == "READ_ONLY_PROCESS" and "-import" not in cmd and
                        cmd[3:9] == ["-process", name, "-noanalysis", "-readOnly", "-max-cpu", "1"],
                        name + f" chunk {number} read-only")
            for filename, key in (("targets.tsv", "target_tsv_sha256"),
                                  ("ghidra_raw.json", "result_sha256"),
                                  ("ghidra_stdout.log", "stdout_sha256"),
                                  ("ghidra_stderr.log", "stderr_sha256")):
                require(digest(chunk / filename) == receipt[key],
                        name + f" chunk {number} file {filename}")
            require(meta["target_tsv_sha256"] == receipt["target_tsv_sha256"],
                    name + f" chunk {number} TSV index")
            stdout = (chunk / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace")
            require(f"[TASK_167] processed {meta['count']}/{meta['count']}" in stdout,
                    name + f" chunk {number} completion log")
            if number == 1:
                require("REPORT: Import succeeded" in stdout, name + " actual import log")
            raw = read(chunk / "ghidra_raw.json")
            require(raw["task_id"] == "TASK_167" and raw["program_name"] == name and
                    len(raw["targets"]) == meta["count"] and
                    [r["index"] for r in raw["targets"]] ==
                    list(range(meta["first_index"], meta["last_index"] + 1)),
                    name + f" chunk {number} raw rows")
            base_by_chunk.add(int(raw["image_base"], 16))
            subset = index["targets"][meta["first_index"] - 1:meta["last_index"]]
            lines = (chunk / "targets.tsv").read_text(encoding="utf-8").splitlines()
            require(len(lines) == len(subset), name + f" chunk {number} TSV lines")
            for target, row, line in zip(subset, raw["targets"], lines):
                require(line.split("\t", 4) ==
                        [str(target["index"]), target["elf_va"], str(target["size_bytes"]),
                         target["source_body_sha256"], target["symbol"]] and
                        row["index"] not in raw_by_index, name + f" chunk {number} target join")
                raw_by_index[row["index"]] = row
        require(chunk_elapsed <= 6600 and len(base_by_chunk) == 1 and
                set(raw_by_index) == set(range(1, count + 1)), name + " complete raw coverage")
        image_base = next(iter(base_by_chunk))
        metrics = Counter()
        for position, target in enumerate(index["targets"]):
            number = position + 1
            va, size = int(target["elf_va"], 16), int(target["size_bytes"])
            aliases = sorted(by_va[va], key=lambda pair: (-pair[1], pair[0]))
            require(target["index"] == number and
                    (target["symbol"], size) == aliases[0] and
                    target["aliases"] == [p[0] for p in aliases], name + f" symbol {number}")
            offsets = [off + va - base for base, off, length in loads
                       if base <= va and va + size <= base + length]
            require(len(offsets) == 1 and target["file_offset"] == f"0x{offsets[0]:x}",
                    name + f" PT_LOAD {number}")
            body = source_bytes[offsets[0]:offsets[0] + size]
            body_sha = hashed(body)
            require(len(body) == size and target["source_body_sha256"] == body_sha,
                    name + f" body hash {number}")
            decoded = list(cap.disasm(body, va))
            require(sum(ins.size for ins in decoded) == size, name + f" full AArch64 decode {number}")
            decoded_by_va = {ins.address: ins for ins in decoded}
            row = raw_by_index[number]
            require(row["index"] == number and row["elf_va"] == target["elf_va"] and
                    row["symbol"] == target["symbol"] and row["size_bytes"] == size and
                    int(row["database_va"], 16) == image_base + va and
                    row["source_bytes_match"] is True and
                    row["expected_source_sha256"] == row["ghidra_memory_sha256"] == body_sha and
                    row["decompile_success"] is True and not row["error"] and
                    row["pseudocode"].strip() and "{" in row["pseudocode"] and
                    0 <= row["elapsed_ms"] <= 15000,
                    name + f" Ghidra memory/C {number}")
            listed = []
            for item in row["instructions"]:
                m = re.match(r"^([0-9a-fA-F]+):\s+", item)
                require(m is not None, name + f" listing syntax {number}")
                listed.append(int(m.group(1), 16) - image_base)
            require(listed and listed == sorted(set(listed)) and
                    len(listed) == row["instruction_count_observed"] and
                    all(address in decoded_by_va for address in listed),
                    name + f" listed source addresses {number}")
            for call in row["calls"]:
                m = re.match(r"^([0-9a-fA-F]+)\s+->\s+", call)
                require(m is not None, name + f" call syntax {number}")
                call_va = int(m.group(1), 16) - image_base
                require(call_va in decoded_by_va and
                        decoded_by_va[call_va].mnemonic in ("bl", "blr", "b", "br"),
                        name + f" call source opcode {number}")
            c_sha = hashed(row["pseudocode"].encode("utf-8"))
            record = {"library": name, "index": number, "elf_va": target["elf_va"],
                      "source_body_sha256": body_sha, "source_size_bytes": size,
                      "source_capstone_instructions": len(decoded), "source_fully_decoded": True,
                      "ghidra_memory_source_match": True,
                      "ghidra_listed_instructions": len(listed), "ghidra_c_like_recovered": True,
                      "ghidra_pseudocode_sha256": c_sha, "ghidra_call_sites": len(row["calls"]),
                      "raw_chunk_json": f"{name}/chunk_{(position // 256) + 1:02d}/ghidra_raw.json"}
            independent_records.append(record)
            c_bodies.append(f"/* {name} ELF VA 0x{va:x}; source body SHA-256 {body_sha} */\n"
                            + row["pseudocode"] + "\n")
            metrics["source_instructions"] += len(decoded)
            metrics["listed_instructions"] += len(listed)
            metrics["full_listings"] += len(decoded) == len(listed)
            metrics["C_like"] += 1
            metrics["warnings"] += "WARNING:" in row["pseudocode"]
            metrics["calls"] += len(row["calls"])
        require(metrics["full_listings"] == expected_full, name + " full listing count")
        summaries.append({"library": name, "source_sha256": source_sha,
                          "export_vas": count, "source_bodies_rehashed": count,
                          "source_fully_capstone_decoded": count,
                          "source_capstone_instructions": metrics["source_instructions"],
                          "ghidra_memory_source_matched": count,
                          "ghidra_listed_source_aligned_instructions": metrics["listed_instructions"],
                          "ghidra_full_listings": metrics["full_listings"],
                          "ghidra_c_like_recovered": count,
                          "chunks_ready": len(index["chunks"]), "chunks_total": len(index["chunks"])})
        totals.update(metrics)
    require(imports == 2, "two distinct source imports")
    require(independent_records == verification["records"] and
            summaries == verification["libraries"], "all verification records/summaries")
    require(verification["export_vas_source_rehashed"] ==
            verification["ghidra_memory_source_matched"] ==
            verification["ghidra_c_like_bodies_recovered"] ==
            seal["source_bodies_rehashed"] == seal["c_like_bodies_recovered"] == 4526 and
            verification["source_capstone_instructions"] == totals["source_instructions"] == 32492 and
            verification["ghidra_listed_source_aligned_instructions"] == totals["listed_instructions"] == 30516 and
            verification["ghidra_fully_listed_bodies"] == totals["full_listings"] == 4377,
            "independent aggregate metrics")
    expected_c = "\n".join(c_bodies).encode("utf-8")
    require(hashed(expected_c) == digest(REPORT / "all_recovered_export_pseudocode.c"),
            "combined C-like output exact bytes")
    sampled = sorted({round(i * 4525 / 453) for i in range(454)})
    require(len(sampled) >= math.ceil(4526 * .1) and
            all(independent_records[i] == verification["records"][i] for i in sampled) and
            seal["ordinary_records_independently_rechecked"] == len(sampled),
            "454 spread ordinary records")
    require(digest(seal_path) == initial_seal_sha, "stable sealed snapshot")
    print(json.dumps({"verdict": "INDEPENDENT_STATIC_PROVENANCE_PASS",
                      "seal_sha256": initial_seal_sha, "report_files": len(files),
                      "code_files": len(seal["code_files"]), "report_bytes": report_bytes,
                      "libraries": summaries, "imports": imports, "metrics": dict(totals),
                      "ordinary_spread_sample": len(sampled),
                      "limitation": "149 partial listings; export-only static C-like evidence"}, indent=2))


if __name__ == "__main__":
    main()
