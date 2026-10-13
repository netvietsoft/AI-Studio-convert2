"""Independent CEO audit of TASK_170's truthful partial FFmpeg export map."""

import hashlib
import json
import math
import re
from collections import Counter
from datetime import datetime
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile

ROOT = Path("F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2")
REPORT = ROOT / "RULES/REPORT/TASK_170_REPORT_R1"
TASK = ROOT / "RULES/TASK/TASK_170_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libffmpeg.so")
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
TASK_SHA = "dd2842461ccd113886c09b663c5c6c99589d2606e1492d95d960e609cfb8e502"
SOURCE_SHA = "d8df8c5cb7a6b5a7eb771782d74a38e0b8d3cfacd1fbef1ae67a96171e3325c9"
MISSING = {2283: (0x658fe8, "x264_8_deblock_h_luma_intra_neon"),
           2330: (0x65aea8, "x264_8_frame_init_lowres_core_neon")}


def sha(path):
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1 << 20), b""):
            h.update(block)
    return h.hexdigest()


def read(path):
    return json.loads(path.read_text(encoding="utf-8"))


def ck(condition, message):
    if not condition:
        raise AssertionError(message)


def stamp(value):
    return datetime.fromisoformat(value.replace("Z", "+00:00"))


def main():
    ck(sha(STANDARD) == STANDARD_SHA and sha(TASK) == TASK_SHA and sha(SOURCE) == SOURCE_SHA,
       "canonical/task/original source")
    seal_path = REPORT / "COMPLETE.json"
    seal_sha = sha(seal_path)
    seal = read(seal_path)
    ck((seal["task_id"], seal["revision"], seal["status"], seal["semantic_disposition"],
        seal["fencing_token"], seal["execution_mode"]) ==
       ("TASK_170", 1, "COMPLETE", "PARTIAL_RESEARCH_CANDIDATE", 1199,
        "REAL_CODEX_SUBAGENT_NO_AGY") and
       seal["standard_sha256"] == STANDARD_SHA and seal["task_sha256"] == TASK_SHA and
       seal["internal_nonexported_functions_covered"] is False and
       seal["runtime_or_pixel_semantics_proven"] is False, "bounded seal identity")
    files = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()}
    files -= {"COMPLETE.json", "PROGRESS.json"}
    ck(files == set(seal["files"]) and len(files) == 58 and len(seal["code_files"]) == 5,
       "manifest extent")
    for rel, expected in seal["files"].items():
        ck(sha(REPORT / rel) == expected, "report file " + rel)
    for rel, expected in seal["code_files"].items():
        ck(sha(ROOT / rel) == expected, "code file " + rel)
    report_bytes = sum((REPORT / rel).stat().st_size for rel in files)
    ck(report_bytes <= 134217728, "report bytes cap")
    audit = (REPORT / "00_AUDIT_INDEX.md").read_text(encoding="utf-8").lower()
    ck(STANDARD_SHA in audit and TASK_SHA in audit, "audit identities")
    batch = read(REPORT / "batch_run_receipt.json")
    index = read(REPORT / "libffmpeg.so/target_index.json")
    source_batch = read(REPORT / "source_batch_index.json")
    verified = read(REPORT / "independent_verification.json")
    c_manifest = read(REPORT / "source_c_manifest.json")
    ck(batch["task_id"] == "TASK_170" and batch["status"] == "OUTPUT_READY" and
       batch["elapsed_seconds"] <= 6600 and len(batch["chunks"]) == 10 and
       source_batch["total_unique_export_vas"] == 2461 and
       verified["records"] == c_manifest["records"] and
       verified["libraries"] == c_manifest["source_libraries"] and
       len(verified["records"]) == 2461 and
       index["task_id"] == "TASK_170" and index["fencing_token"] == 1199 and
       index["standard_sha256"] == STANDARD_SHA and index["task_sha256"] == TASK_SHA and
       index["source_sha256"] == SOURCE_SHA and index["source_size"] == SOURCE.stat().st_size and
       index["unique_export_vas"] == len(index["targets"]) == 2461 and
       len(index["chunks"]) == 10, "task batch/index/source/verification")
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        ck(elf["e_machine"] == "EM_AARCH64", "original AArch64")
        by_va = {}
        for sym in elf.get_section_by_name(".dynsym").iter_symbols():
            if (sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF" and
                    int(sym["st_size"]) > 0 and int(sym["st_value"]) > 0):
                by_va.setdefault(int(sym["st_value"]), []).append((sym.name, int(sym["st_size"])))
        loads = [(int(seg["p_vaddr"]), int(seg["p_offset"]), int(seg["p_filesz"]))
                 for seg in elf.iter_segments() if seg["p_type"] == "PT_LOAD"]
    ck(len(by_va) == 2461 and sum(map(len, by_va.values())) ==
       index["defined_nonzero_function_symbols"], "original .dynsym census")
    ck([int(t["elf_va"], 16) for t in index["targets"]] == sorted(by_va),
       "original .dynsym VA set/order")
    raw_rows = {}
    image_bases = set()
    previous_end = None
    outcomes = {(x["library"], x["chunk"]): x for x in batch["chunks"]}
    ck(len(outcomes) == 10, "unique outcomes")
    script_sha = sha(ROOT / "scripts/task_170_codex_exports/ExportChunk170.java")
    import_count = 0
    for meta in index["chunks"]:
        number = meta["chunk"]
        chunk = REPORT / "libffmpeg.so" / f"chunk_{number:02d}"
        rec = read(chunk / "ghidra_command.json")
        outcome = outcomes.get(("libffmpeg.so", number))
        raw = read(chunk / "ghidra_raw.json")
        ck(outcome is not None and outcome["status"] == rec["status"] == "OUTPUT_READY" and
           outcome["exit_code"] == rec["exit_code"] == 0 and
           outcome["observed"] == rec["observed"] and
           0 < rec["elapsed_seconds"] <= 900 and
           rec["elapsed_seconds"] == outcome["elapsed_seconds"] and
           rec["fencing_token"] == 1199 and rec["source_sha256"] == SOURCE_SHA and
           rec["script_sha256"] == script_sha and
           0 < meta["count"] <= 256 and
           meta["last_index"] - meta["first_index"] + 1 == meta["count"] and
           meta["target_tsv_sha256"] == rec["target_tsv_sha256"], f"chunk {number} receipt")
        ck(previous_end is None or stamp(rec["started_at"]) >= previous_end,
           f"chunk {number} sequential")
        previous_end = stamp(rec["ended_at"])
        cmd = rec["command"]
        ck(cmd[0].endswith("analyzeHeadless.bat") and
           cmd[cmd.index("-max-cpu") + 1] == "1" and
           cmd[cmd.index("-postScript") + 1] == "ExportChunk170.java" and
           cmd[-2].replace("\\", "/") == str(chunk / "targets.tsv").replace("\\", "/") and
           cmd[-1].replace("\\", "/") == str(chunk / "ghidra_raw.json").replace("\\", "/"),
           f"chunk {number} command")
        if number == 1:
            ck(rec["operation"] == "IMPORT" and cmd.count("-import") == 1 and
               "-process" not in cmd and
               cmd[cmd.index("-import") + 1].replace("\\", "/") == str(SOURCE).replace("\\", "/"),
               "sole original import")
            import_count += 1
        else:
            ck(rec["operation"] == "READ_ONLY_PROCESS" and "-import" not in cmd and
               cmd[3:9] == ["-process", "libffmpeg.so", "-noanalysis", "-readOnly", "-max-cpu", "1"],
               f"chunk {number} read-only")
        for filename, key in (("targets.tsv", "target_tsv_sha256"),
                              ("ghidra_raw.json", "result_sha256"),
                              ("ghidra_stdout.log", "stdout_sha256"),
                              ("ghidra_stderr.log", "stderr_sha256")):
            ck(sha(chunk / filename) == rec[key], f"chunk {number} {filename}")
        log = (chunk / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace")
        ck(f"[TASK_170] processed {meta['count']}/{meta['count']}" in log and
           (number != 1 or "REPORT: Import succeeded" in log), f"chunk {number} Ghidra log")
        ck(raw["task_id"] == "TASK_170" and raw["program_name"] == "libffmpeg.so" and
           [r["index"] for r in raw["targets"]] ==
           list(range(meta["first_index"], meta["last_index"] + 1)),
           f"chunk {number} raw rows")
        image_bases.add(int(raw["image_base"], 16))
        subset = index["targets"][meta["first_index"] - 1:meta["last_index"]]
        tsv = (chunk / "targets.tsv").read_text(encoding="utf-8").splitlines()
        ck(len(tsv) == len(subset), f"chunk {number} target TSV")
        for target, row, line in zip(subset, raw["targets"], tsv):
            ck(row["index"] not in raw_rows and line.split("\t", 4) ==
               [str(target["index"]), target["elf_va"], str(target["size_bytes"]),
                target["source_body_sha256"], target["symbol"]], f"chunk {number} row/target")
            raw_rows[row["index"]] = row
    ck(import_count == 1 and len(image_bases) == 1 and
       set(raw_rows) == set(range(1, 2462)), "one import/full raw coverage")
    image_base = next(iter(image_bases))
    cap = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    original = SOURCE.read_bytes()
    totals = Counter()
    independent_records = []
    c_bodies = []
    missing = {}
    spread = {1 + round(i * 2460 / 247) for i in range(248)}
    for position, target in enumerate(index["targets"], 1):
        va, size = int(target["elf_va"], 16), int(target["size_bytes"])
        aliases = sorted(by_va[va], key=lambda pair: (-pair[1], pair[0]))
        ck(target["index"] == position and (target["symbol"], size) == aliases[0] and
           target["aliases"] == [name for name, _ in aliases], f"original aliases {position}")
        offsets = [off + va - base for base, off, filesz in loads
                   if base <= va and va + size <= base + filesz]
        ck(len(offsets) == 1 and target["file_offset"] == f"0x{offsets[0]:x}",
           f"PT_LOAD {position}")
        body = original[offsets[0]:offsets[0] + size]
        body_sha = hashlib.sha256(body).hexdigest()
        ck(len(body) == size and body_sha == target["source_body_sha256"],
           f"original body {position}")
        decoded = list(cap.disasm(body, va))
        ck(sum(ins.size for ins in decoded) == size, f"source decode {position}")
        decoded_by_va = {ins.address: ins for ins in decoded}
        row = raw_rows[position]
        ck(row["index"] == position and row["elf_va"] == target["elf_va"] and
           row["symbol"] == target["symbol"] and row["size_bytes"] == size and
           int(row["database_va"], 16) == image_base + va and
           row["source_bytes_match"] is True and
           row["expected_source_sha256"] == row["ghidra_memory_sha256"] == body_sha and
           0 <= row["elapsed_ms"] <= 15000, f"Ghidra memory/time {position}")
        addresses = []
        for item in row["instructions"]:
            match = re.match(r"^([0-9a-fA-F]+):\s+", item)
            ck(match is not None, f"instruction syntax {position}")
            addresses.append(int(match.group(1), 16) - image_base)
        ck(addresses and addresses == sorted(set(addresses)) and
           len(addresses) == row["instruction_count_observed"] and
           all(addr in decoded_by_va for addr in addresses),
           f"Ghidra listed source addresses {position}")
        for call in row["calls"]:
            match = re.match(r"^([0-9a-fA-F]+)\s+->\s+", call)
            ck(match is not None, f"call syntax {position}")
            call_va = int(match.group(1), 16) - image_base
            ck(call_va in decoded_by_va and decoded_by_va[call_va].mnemonic in
               ("bl", "blr", "b", "br"), f"source call opcode {position}")
        recovered = bool(row["decompile_success"] is True and
                         row["pseudocode"].strip() and not row["error"])
        c_sha = hashlib.sha256(row["pseudocode"].encode("utf-8")).hexdigest() if recovered else None
        if not recovered:
            missing[position] = {"va": va, "symbol": row["symbol"], "error": row["error"]}
        else:
            c_bodies.append(f"/* libffmpeg.so ELF VA 0x{va:x}; source body SHA-256 {body_sha} */\n"
                            + row["pseudocode"] + "\n")
        independent_records.append({"library": "libffmpeg.so", "index": position,
            "elf_va": target["elf_va"], "source_body_sha256": body_sha,
            "source_size_bytes": size, "source_capstone_instructions": len(decoded),
            "source_fully_decoded": True, "ghidra_memory_source_match": True,
            "ghidra_listed_instructions": len(addresses), "ghidra_c_like_recovered": recovered,
            "ghidra_pseudocode_sha256": c_sha, "ghidra_call_sites": len(row["calls"]),
            "raw_chunk_json": f"libffmpeg.so/chunk_{(position - 1) // 256 + 1:02d}/ghidra_raw.json"})
        totals["source_instructions"] += len(decoded)
        totals["listed_instructions"] += len(addresses)
        totals["full_listings"] += len(decoded) == len(addresses)
        totals["C_like"] += recovered
        if position in spread:
            ck(hashlib.sha256(original[offsets[0]:offsets[0] + size]).hexdigest() ==
               row["ghidra_memory_sha256"], f"spread ordinary {position}")
    ck({n: (item["va"], item["symbol"]) for n, item in missing.items()} == MISSING and
       all("Unable to find unique hash for varnode" in item["error"] for item in missing.values()),
       "exact two NEON decompiler failures")
    ck(independent_records == verified["records"] == c_manifest["records"] and
       totals["source_instructions"] == verified["source_capstone_instructions"] == 206465 and
       totals["listed_instructions"] == verified["ghidra_listed_source_aligned_instructions"] == 206156 and
       totals["full_listings"] == verified["ghidra_fully_listed_bodies"] == 2456 and
       totals["C_like"] == verified["ghidra_c_like_bodies_recovered"] == seal["c_like_bodies_recovered"] == 2459 and
       verified["ghidra_memory_source_matched"] == verified["export_vas_source_rehashed"] ==
       seal["source_bodies_rehashed"] == 2461 and
       seal["ordinary_records_independently_rechecked"] == len(spread) == 248 and
       verified["ordinary_function_records_spread_sampled"] == 248,
       "recomputed provenance aggregates")
    ck(hashlib.sha256("\n".join(c_bodies).encode("utf-8")).hexdigest() ==
       sha(REPORT / "all_recovered_export_pseudocode.c"), "exact combined C-like bytes")
    ck(sha(seal_path) == seal_sha, "stable seal snapshot")
    print(json.dumps({"verdict": "INDEPENDENT_PARTIAL_STATIC_PROVENANCE_PASS",
                      "seal_sha256": seal_sha, "report_files": len(files),
                      "code_files": len(seal["code_files"]), "report_bytes": report_bytes,
                      "source_export_vas": 2461, "ghidra_C_like": totals["C_like"],
                      "missing": missing, "ordinary_spread": len(spread),
                      "metrics": dict(totals), "imports": import_count,
                      "limitation": "two missing NEON C-like bodies; 5 partial listings; export-only"}, indent=2))


if __name__ == "__main__":
    main()
