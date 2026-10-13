"""Independent read-only audit of all three TASK_166 source packages."""

import hashlib
import json
import math
import re
from collections import Counter
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_166_REPORT_R1"
TASK = ROOT / "RULES/TASK/TASK_166_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
SOURCE_ROOT = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a")
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
TASK_SHA = "ed9fba8e670855c9f73c05e988549ca1192bf6050ee40df342fae8e64a469652"
SOURCES = {
    "libAIModelKit.so": ("96eb16089da9b1b797928a73ec4b4ddd27c43bc557940c96ca167cf657a89b9c", 144, 130, 109, 33),
    "libaidetectionplugin.so": ("910ef898f457cac694080829b8f7b219ae6cc696f5adebe90beca9a70c0deda8", 477, 436, 318, 196),
    "libhiai.so": ("30a096c17346403d98a32a1a4d0762fa8e220f6c40e65aec9460cdfd6c7418ee", 366, 343, 343, 184),
}


def sha(path):
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def read(path):
    return json.loads(path.read_text(encoding="utf-8"))


def check(ok, message):
    if not ok:
        raise AssertionError(message)


def audit_source(name, expected):
    source_sha, names, count, full, warnings = expected
    source = SOURCE_ROOT / name
    folder = REPORT / source.stem
    check(sha(source) == source_sha, name + " original SHA")
    index = read(folder / "target_index.json")
    verify = read(folder / "worker_source_verification.json")
    source_seal = read(folder / "SOURCE_COMPLETE.json")
    batch = read(folder / "batch_run_receipt.json")
    check((index["task_id"], index["revision"], index["source_name"], index["source_sha256"],
           index["task_sha256"], index["standard_sha256"], index["fencing_token"]) ==
          ("TASK_166", 1, name, source_sha, TASK_SHA, STANDARD_SHA, 1195), name + " index pins")
    check(index["defined_nonzero_function_symbols"] == names and
          index["unique_export_vas"] == len(index["targets"]) == len(verify["records"]) == count and
          len(index["chunks"]) == math.ceil(count / 256), name + " indexed count")
    source_files = {p.relative_to(folder).as_posix() for p in folder.rglob("*") if p.is_file()} - {
        "SOURCE_COMPLETE.json", "PROGRESS.json"}
    check(set(source_seal["files"]) == source_files, name + " source manifest inventory")
    for rel, digest in source_seal["files"].items():
        check(sha(folder / rel) == digest, name + " source file " + rel)
    for rel, digest in source_seal["code_files"].items():
        check(sha(ROOT / rel) == digest, name + " source code " + rel)
    check(source_seal["c_like_bodies_recovered"] == count and
          source_seal["internal_nonexported_functions_covered"] is False and
          source_seal["runtime_or_pixel_semantics_proven"] is False, name + " bounded scope")
    imp = read(folder / "ghidra_import_command.json")
    cmd = imp["command"]
    check((imp["task_id"], imp["status"], imp["exit_code"], imp["fencing_token"],
           imp["source_sha256"]) == ("TASK_166", "PROJECT_READY", 0, 1195, source_sha)
          and 0 < imp["elapsed_seconds"] <= 900 and cmd.count("-import") == 1 and
          "-process" not in cmd and cmd[cmd.index("-import") + 1].replace("\\", "/") == str(source).replace("\\", "/")
          and cmd[cmd.index("-max-cpu") + 1] == "1", name + " import receipt")
    for log, key in (("ghidra_import_stdout.log", "stdout_sha256"),
                     ("ghidra_import_stderr.log", "stderr_sha256")):
        check(sha(folder / log) == imp[key], name + " import log " + log)
    check("REPORT: Import succeeded" in (folder / "ghidra_import_stdout.log").read_text(
        encoding="utf-8", errors="replace"), name + " import success log")
    inventory = read(folder / "project_inventory.json")
    project = Path(inventory["project_root"])
    check(set(inventory["files"]) ==
          {p.relative_to(project).as_posix() for p in project.rglob("*") if p.is_file()},
          name + " project inventory")
    for rel, digest in inventory["files"].items():
        check(sha(project / rel) == digest, name + " project bytes " + rel)
    project_name = "TASK166_" + source.stem
    check(sha(project / (project_name + ".gpr")) == imp["project_gpr_sha256"], name + " GPR")
    check(batch["task_id"] == "TASK_166" and batch["status"] == "OUTPUT_READY" and
          len(batch["chunks"]) == len(index["chunks"]) and batch["elapsed_seconds"] <= 6600,
          name + " batch result")
    with source.open("rb") as stream:
        elf = ELFFile(stream)
        check(elf["e_machine"] == "EM_AARCH64", name + " architecture")
        by_va = {}
        for sym in elf.get_section_by_name(".dynsym").iter_symbols():
            if sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF" and \
                    int(sym["st_size"]) > 0 and int(sym["st_value"]) > 0:
                by_va.setdefault(int(sym["st_value"]), []).append((sym.name, int(sym["st_size"])))
        loads = [(int(s["p_vaddr"]), int(s["p_offset"]), int(s["p_filesz"]))
                 for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
    check(len(by_va) == count and sum(map(len, by_va.values())) == names, name + " independent .dynsym")
    source_bytes = source.read_bytes()
    rows = {}
    bases = set()
    elapsed = imp["elapsed_seconds"]
    for meta, outcome in zip(index["chunks"], batch["chunks"]):
        n = meta["chunk"]
        chunk = folder / f"chunk_{n:02d}"
        rec = read(chunk / "ghidra_command.json")
        raw_path = chunk / "ghidra_raw.json"
        check(meta["count"] <= 256 and meta["last_index"] - meta["first_index"] + 1 == meta["count"] and
              outcome["chunk"] == n and outcome["status"] == rec["status"] == "OUTPUT_READY" and
              outcome["exit_code"] == rec["exit_code"] == 0 and
              0 < rec["elapsed_seconds"] <= 900 and rec["fencing_token"] == 1195 and
              rec["source_sha256"] == source_sha, name + " chunk outcome")
        elapsed += rec["elapsed_seconds"]
        command = rec["command"]
        check(command[3:9] == ["-process", name, "-noanalysis", "-readOnly", "-max-cpu", "1"] and
              "-import" not in command and rec["script_sha256"] ==
              sha(ROOT / "scripts/task_166_codex_exports/ExportTask166Chunk.java"), name + " chunk command")
        for rel, key in (("targets.tsv", "target_tsv_sha256"), ("ghidra_raw.json", "result_sha256"),
                         ("ghidra_stdout.log", "stdout_sha256"),
                         ("ghidra_stderr.log", "stderr_sha256")):
            check(sha(chunk / rel) == rec[key], name + " chunk byte hash " + rel)
        check(meta["target_tsv_sha256"] == rec["target_tsv_sha256"], name + " chunk target index")
        check(f"[TASK_166] processed {meta['count']}/{meta['count']}" in
              (chunk / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace"),
              name + " Ghidra completion log")
        raw = read(raw_path)
        check(raw["task_id"] == "TASK_166" and raw["program_name"] == name and
              len(raw["targets"]) == meta["count"] and
              [r["index"] for r in raw["targets"]] ==
              list(range(meta["first_index"], meta["last_index"] + 1)),
              name + " raw chunk rows")
        image_base = int(raw["image_base"], 16)
        bases.add(image_base)
        lines = (chunk / "targets.tsv").read_text(encoding="utf-8").splitlines()
        check(len(lines) == meta["count"], name + " chunk TSV lines")
        for row, line in zip(raw["targets"], lines):
            check(line.split("\t", 4) == [str(row["index"]), row["elf_va"], str(row["size_bytes"]),
                                           row["expected_source_sha256"], row["symbol"]],
                  name + " raw/TSV target")
            check(row["index"] not in rows, name + " duplicate raw index")
            rows[row["index"]] = row
    check(elapsed <= 6600 and len(bases) == 1 and set(rows) == set(range(1, count + 1)),
          name + " aggregate time/raw coverage")
    image_base = next(iter(bases))
    sample = {round(i * (count - 1) / (math.ceil(count * .1) - 1)) for i in range(math.ceil(count * .1))}
    check(len(sample) >= math.ceil(count * .1), name + " spread >=10%")
    cap = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    metrics = Counter()
    for position, target in enumerate(index["targets"]):
        number = position + 1
        va, size = int(target["elf_va"], 16), int(target["size_bytes"])
        aliases = sorted(by_va[va], key=lambda p: (-p[1], p[0]))
        check(target["index"] == number and (target["symbol"], size) == aliases[0] and
              target["aliases"] == [p[0] for p in aliases], name + f" original symbol {number}")
        offsets = [offset + va - base for base, offset, length in loads
                   if base <= va and va + size <= base + length]
        check(len(offsets) == 1 and target["file_offset"] == f"0x{offsets[0]:x}",
              name + f" PT_LOAD mapping {number}")
        body = source_bytes[offsets[0]:offsets[0] + size]
        digest = hashlib.sha256(body).hexdigest()
        check(len(body) == size and digest == target["source_body_sha256"], name + f" original body {number}")
        decoded = list(cap.disasm(body, va))
        check(sum(ins.size for ins in decoded) == size, name + f" AArch64 decode {number}")
        lookup = {ins.address: ins for ins in decoded}
        row = rows[number]
        check(row["index"] == number and row["elf_va"] == target["elf_va"] and
              row["symbol"] == target["symbol"] and row["size_bytes"] == size and
              int(row["database_va"], 16) == image_base + va and
              row["source_bytes_match"] is True and
              row["expected_source_sha256"] == row["ghidra_memory_sha256"] == digest and
              0 <= row["elapsed_ms"] <= 15000, name + f" Ghidra original memory {number}")
        addresses = []
        for item in row["instructions"]:
            match = re.match(r"^([0-9a-fA-F]+):\s+", item)
            check(match is not None, name + f" listing syntax {number}")
            address = int(match.group(1), 16) - image_base
            check(address in lookup, name + f" listing outside source {number}")
            addresses.append(address)
        check(addresses and addresses == sorted(set(addresses)) and
              len(addresses) == row["instruction_count_observed"], name + f" listing count/order {number}")
        flow = Counter()
        for item in row["calls"]:
            match = re.match(r"^([0-9a-fA-F]+)\s+->\s+", item)
            check(match is not None, name + f" call syntax {number}")
            address = int(match.group(1), 16) - image_base
            check(address in lookup and lookup[address].mnemonic in ("bl", "blr", "b", "br"),
                  name + f" call absent from original {number}")
            flow[lookup[address].mnemonic] += 1
        c = row["pseudocode"]
        check(row["decompile_success"] is True and not row["error"] and c.strip() and "{" in c,
              name + f" nonempty C-like output {number}")
        metrics["source_instructions"] += len(decoded)
        metrics["listed_instructions"] += len(addresses)
        metrics["full_listings"] += len(addresses) == len(decoded)
        metrics["warnings"] += "WARNING:" in c
        metrics["C_like"] += 1
        for opcode, qty in flow.items():
            metrics["flow_" + opcode] += qty
        if position in sample:
            record = verify["records"][position]
            check(record["index"] == number and record["elf_va"] == target["elf_va"] and
                  record["source_body_sha256"] == digest and
                  record["source_capstone_instructions"] == len(decoded) and
                  record["ghidra_listed_instructions"] == len(addresses) and
                  record["ghidra_flow_transfers_source_verified"] == sum(flow.values()) and
                  record["ghidra_c_like_recovered"] is True and
                  record["ghidra_c_like_characters"] == len(c) and
                  record["ghidra_c_warning_present"] == ("WARNING:" in c),
                  name + f" ordinary spread record {number}")
            metrics["sample"] += 1
    check(metrics["full_listings"] == verify["ghidra_fully_listed_bodies"] == full and
          metrics["warnings"] == verify["c_bodies_with_warnings"] == warnings and
          metrics["C_like"] == verify["ghidra_c_like_bodies_recovered"] == count and
          metrics["source_instructions"] == verify["source_capstone_instructions"] and
          metrics["listed_instructions"] == verify["ghidra_listed_source_aligned_instructions"] and
          metrics["sample"] == verify["ordinary_records_spread_sampled"] and
          all(metrics["flow_" + op] == verify["ghidra_flow_transfer_source_opcode_counts"][op]
              for op in ("bl", "blr", "b", "br")), name + " independent metrics")
    return {"name": name, "names": names, "vas": count, "sample": metrics["sample"],
            "metrics": dict(metrics), "source_complete_sha256": sha(folder / "SOURCE_COMPLETE.json")}


def main():
    check(sha(STANDARD) == STANDARD_SHA and sha(TASK) == TASK_SHA,
          "canonical/task identity")
    seal_path = REPORT / "COMPLETE.json"
    seal_sha = sha(seal_path)
    seal = read(seal_path)
    check((seal["task_id"], seal["revision"], seal["status"], seal["fencing_token"]) ==
          ("TASK_166", 1, "COMPLETE", 1195), "top seal identity")
    check(seal["standard_sha256"] == STANDARD_SHA and seal["task_sha256"] == TASK_SHA and
          seal["internal_nonexported_functions_covered"] is False and
          seal["runtime_or_pixel_semantics_proven"] is False, "top seal scope")
    actual = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()} - {
        "COMPLETE.json", "PROGRESS.json"}
    check(set(seal["files"]) == actual and len(actual) == 60 and len(seal["code_files"]) == 6,
          "top seal exact inventory")
    for rel, digest in seal["files"].items():
        check(sha(REPORT / rel) == digest, "top sealed file " + rel)
    for rel, digest in seal["code_files"].items():
        check(sha(ROOT / rel) == digest, "top sealed code " + rel)
    report_bytes = sum((REPORT / rel).stat().st_size for rel in actual)
    check(report_bytes <= 134217728, "report size cap")
    audit = (REPORT / "00_AUDIT_INDEX.md").read_text(encoding="utf-8").lower()
    check(STANDARD_SHA in audit and TASK_SHA in audit, "top audit index")
    results = [audit_source(name, expected) for name, expected in SOURCES.items()]
    summaries = seal["source_summaries"]
    for result, summary in zip(results, summaries):
        check(result["name"] == summary["source_name"] and
              result["source_complete_sha256"] == summary["source_complete_sha256"] and
              result["vas"] == summary["unique_export_vas"] and
              result["sample"] == summary["spread_sampled"], "top/source summary")
    check(sum(r["vas"] for r in results) == seal["source_bodies_rehashed"] ==
          seal["ghidra_memory_bodies_rehashed"] == seal["c_like_bodies_recovered"] == 909 and
          sum(r["sample"] for r in results) == seal["ordinary_records_spread_checked"] == 92,
          "top aggregate census")
    check(sha(seal_path) == seal_sha, "stable sealed snapshot")
    print(json.dumps({"verdict": "INDEPENDENT_STATIC_PROVENANCE_PASS", "seal_sha256": seal_sha,
                      "report_files": len(actual), "code_files": len(seal["code_files"]),
                      "report_bytes": report_bytes, "sources": results,
                      "limitation": "139 partial listings; 413 warning-bearing C outputs; export-only"}, indent=2))


if __name__ == "__main__":
    main()
