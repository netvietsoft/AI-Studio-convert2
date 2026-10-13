"""Independent, read-only audit of the sealed TASK_164 R1 research package."""

import hashlib
import json
import math
import re
from collections import Counter
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile


ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_164_REPORT_R1"
TASK = ROOT / "RULES/TASK/TASK_164_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libaicodec.so")
SOURCE_SHA = "f957a5b290991053f65943356816e837ae5a9d996fa0b2809fc89f680fc8a3cc"
TASK_SHA = "c91f97592399d81dad8efdc58a63df484fcd38be3915693481a0c644c31c4c74"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"


def digest(path):
    h = hashlib.sha256()
    with path.open("rb") as f:
        for block in iter(lambda: f.read(1 << 20), b""):
            h.update(block)
    return h.hexdigest()


def read(path):
    return json.loads(path.read_text(encoding="utf-8"))


def check(ok, message):
    if not ok:
        raise AssertionError(message)


def main():
    check(digest(STANDARD) == STANDARD_SHA, "standard hash")
    check(digest(TASK) == TASK_SHA, "task hash")
    check(digest(SOURCE) == SOURCE_SHA, "original SO hash")
    seal_path = REPORT / "COMPLETE.json"
    seal_sha = digest(seal_path)
    seal = read(seal_path)
    check((seal["task_id"], seal["revision"], seal["status"], seal["fencing_token"]) ==
          ("TASK_164", 1, "COMPLETE", 1193), "seal identity")
    check(seal["standard_sha256"] == STANDARD_SHA and seal["task_sha256"] == TASK_SHA and
          seal["source_sha256"] == SOURCE_SHA, "seal source identity")
    check(seal["source_bodies_rehashed"] == seal["c_like_bodies_recovered"] == 2178 and
          seal["internal_nonexported_functions_covered"] is False and
          seal["runtime_or_pixel_semantics_proven"] is False, "seal scope")
    actual = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()} - {
        "COMPLETE.json", "PROGRESS.json"}
    check(set(seal["files"]) == actual and len(actual) == 54, "exact report manifest")
    for name, expected in seal["files"].items():
        check(digest(REPORT / name) == expected, "report hash " + name)
    check(len(seal["code_files"]) == 5, "five code files")
    for name, expected in seal["code_files"].items():
        check(digest(ROOT / name) == expected, "code hash " + name)
    report_bytes = sum((REPORT / name).stat().st_size for name in actual)
    check(report_bytes <= 134217728, "report cap")
    audit_text = (REPORT / "00_AUDIT_INDEX.md").read_text(encoding="utf-8").lower()
    check(STANDARD_SHA in audit_text and SOURCE_SHA in audit_text, "audit index identity")
    run = read(REPORT / "batch_run_receipt.json")
    check(run["status"] == "OUTPUT_READY" and len(run["chunks"]) == 9 and
          run["elapsed_seconds"] <= 6600, "run scope/time")
    imp = read(REPORT / "ghidra_import_command.json")
    check(imp["status"] == "PROJECT_READY" and imp["exit_code"] == 0 and
          imp["elapsed_seconds"] <= 900 and imp["source_sha256"] == SOURCE_SHA,
          "import outcome")
    import_command = imp["command"]
    check(import_command.count("-import") == 1 and "-process" not in import_command and
          import_command[import_command.index("-max-cpu") + 1] == "1" and
          import_command[import_command.index("-import") + 1].replace("\\", "/") == str(SOURCE).replace("\\", "/"),
          "import command")
    for file, key in (("ghidra_import_stdout.log", "stdout_sha256"),
                      ("ghidra_import_stderr.log", "stderr_sha256")):
        check(digest(REPORT / file) == imp[key], "import log hash " + file)
    check("REPORT: Import succeeded" in (REPORT / "ghidra_import_stdout.log").read_text(
        encoding="utf-8", errors="replace"), "actual import success log")
    project = ROOT / "RESEARCH_WORK/TASK_164_R1/ghidra_project"
    inventory = read(REPORT / "project_inventory.json")
    check(Path(inventory["project_root"]).resolve() == project.resolve(), "project root")
    check(set(inventory["files"]) == {p.relative_to(project).as_posix() for p in project.rglob("*") if p.is_file()},
          "project file inventory")
    for name, expected in inventory["files"].items():
        check(digest(project / name) == expected, "project file hash " + name)
    check(digest(project / "Aicodec164.gpr") == imp["project_gpr_sha256"], "project GPR hash")
    index = read(REPORT / "target_index.json")
    verify = read(REPORT / "worker_source_verification.json")
    check(index["task_id"] == verify["task_id"] == "TASK_164" and
          index["unique_export_vas"] == verify["unique_export_vas_recounted"] == 2178 and
          index["defined_nonzero_function_symbols"] == verify["export_symbols_recounted"] == 2401 and
          len(index["targets"]) == len(verify["records"]) == 2178 and len(index["chunks"]) == 9,
          "index/verification census")
    source = SOURCE.read_bytes()
    with SOURCE.open("rb") as f:
        elf = ELFFile(f)
        check(elf["e_machine"] == "EM_AARCH64", "ELF architecture")
        by_va = {}
        for sym in elf.get_section_by_name(".dynsym").iter_symbols():
            if sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF" and int(sym["st_size"]) > 0 and int(sym["st_value"]) > 0:
                by_va.setdefault(int(sym["st_value"]), []).append((sym.name, int(sym["st_size"])))
        loads = [(int(s["p_vaddr"]), int(s["p_offset"]), int(s["p_filesz"]))
                 for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
    check(len(by_va) == 2178 and sum(map(len, by_va.values())) == 2401, "independent .dynsym census")
    raw_rows = {}
    image_base = None
    script_hash = digest(ROOT / "scripts/task_164_codex_exports/ExportAicodecChunk164.java")
    elapsed = imp["elapsed_seconds"]
    for n, meta in enumerate(index["chunks"]):
        check(meta["chunk"] == n and 0 < meta["count"] <= 256 and
              meta["last_index"] - meta["first_index"] + 1 == meta["count"], "chunk split")
        folder = REPORT / f"chunk_{n:02d}"
        receipt = read(folder / "ghidra_command.json")
        outcome = run["chunks"][n]
        check(outcome["chunk"] == n and outcome["status"] == receipt["status"] == "OUTPUT_READY" and
              outcome["exit_code"] == receipt["exit_code"] == 0 and
              outcome["elapsed_seconds"] == receipt["elapsed_seconds"] <= 900, "chunk outcome")
        elapsed += receipt["elapsed_seconds"]
        cmd = receipt["command"]
        check("-import" not in cmd and all(x in cmd for x in ("-process", "-readOnly", "-noanalysis")) and
              cmd[cmd.index("-max-cpu") + 1] == "1" and
              receipt["script_sha256"] == script_hash, "read-only Ghidra command/script")
        for name, key in (("targets.tsv", "target_tsv_sha256"), ("ghidra_raw.json", "result_sha256"),
                          ("ghidra_stdout.log", "stdout_sha256"),
                          ("ghidra_stderr.log", "stderr_sha256")):
            check(digest(folder / name) == receipt[key], "chunk hash " + name)
        check(meta["target_tsv_sha256"] == receipt["target_tsv_sha256"], "indexed targets")
        stdout = (folder / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace")
        check(f"[TASK_164] processed {meta['count']}/{meta['count']}" in stdout and
              "Processing read-only project file" in stdout, "raw Ghidra completion")
        raw = read(folder / "ghidra_raw.json")
        check(raw["task_id"] == "TASK_164" and raw["program_name"] == SOURCE.name and
              len(raw["targets"]) == meta["count"], "raw chunk identity")
        base = int(raw["image_base"], 16)
        check(image_base is None or base == image_base, "stable image base")
        image_base = base
        check([row["index"] for row in raw["targets"]] == list(range(meta["first_index"], meta["last_index"] + 1)),
              "raw row interval")
        lines = (folder / "targets.tsv").read_text(encoding="utf-8").splitlines()
        check(len(lines) == len(raw["targets"]), "TSV count")
        for line, row in zip(lines, raw["targets"]):
            check(line.split("\t", 4) == [str(row["index"]), row["elf_va"], str(row["size_bytes"]),
                                         row["expected_source_sha256"], row["symbol"]], "TSV/raw identity")
            check(row["index"] not in raw_rows, "duplicate raw index")
            raw_rows[row["index"]] = row
    check(elapsed <= 6600 and set(raw_rows) == set(range(1, 2179)), "aggregate time/coverage")
    cap = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    sample = {round(i * 2177 / 217) for i in range(218)}
    check(len(sample) >= math.ceil(2178 * .1), "10 percent spread sample")
    metrics = Counter()
    for pos, target in enumerate(index["targets"]):
        i = pos + 1
        check(target["index"] == i, "target order")
        va, size = int(target["elf_va"], 16), int(target["size_bytes"])
        aliases = sorted(by_va[va], key=lambda pair: (-pair[1], pair[0]))
        check((target["symbol"], size) == aliases[0] and
              target["aliases"] == [name for name, _ in aliases], "original symbol/alias")
        offsets = [off + va - start for start, off, length in loads
                   if start <= va and va + size <= start + length]
        check(offsets and int(target["file_offset"], 16) in offsets, "PT_LOAD mapping")
        body = source[offsets[0]:offsets[0] + size]
        body_hash = hashlib.sha256(body).hexdigest()
        check(len(body) == size and body_hash == target["source_body_sha256"], "original body hash")
        row = raw_rows[i]
        check(row["elf_va"] == target["elf_va"] and row["size_bytes"] == size and
              row["symbol"] == target["symbol"] and
              int(row["database_va"], 16) == image_base + va and
              row["source_bytes_match"] is True and
              row["expected_source_sha256"] == row["ghidra_memory_sha256"] == body_hash,
              "source/Ghidra body match")
        check(0 <= row["elapsed_ms"] <= 15000, "function time cap")
        decoded = list(cap.disasm(body, va))
        check(sum(ins.size for ins in decoded) == size, "full original AArch64 decode")
        lookup = {ins.address: ins for ins in decoded}
        listed = row["instructions"]
        check(listed and len(listed) == row["instruction_count_observed"], "listing count")
        addresses = []
        for line in listed:
            match = re.match(r"^([0-9a-fA-F]+):\s+", line)
            check(match is not None, "listed syntax")
            addr = int(match.group(1), 16) - image_base
            check(addr in lookup, "listed instruction in original")
            addresses.append(addr)
        check(addresses == sorted(set(addresses)), "instruction order/no duplicates")
        for call in row["calls"]:
            match = re.match(r"^([0-9a-fA-F]+)\s+->\s+", call)
            check(match is not None, "call syntax")
            addr = int(match.group(1), 16) - image_base
            check(addr in lookup and lookup[addr].mnemonic in ("bl", "blr", "b", "br"),
                  "call original opcode")
            metrics["flow_" + lookup[addr].mnemonic] += 1
        c = row["pseudocode"]
        check(row["decompile_success"] is True and not row["error"] and c.strip() and "{" in c,
              "nonempty C-like output")
        metrics["source_instructions"] += len(decoded)
        metrics["listed_instructions"] += len(listed)
        metrics["full_listings"] += len(listed) == len(decoded)
        metrics["C_like"] += 1
        metrics["C_warnings"] += "WARNING:" in c
        metrics["max_function_elapsed_ms"] = max(metrics["max_function_elapsed_ms"], row["elapsed_ms"])
        if pos in sample:
            record = verify["records"][pos]
            check(record["index"] == i and record["elf_va"] == target["elf_va"] and
                  record["source_body_sha256"] == body_hash and
                  record["source_capstone_instructions"] == len(decoded) and
                  record["ghidra_listed_instructions"] == len(listed) and
                  record["ghidra_flow_transfers_source_verified"] == len(row["calls"]) and
                  record["ghidra_c_like_characters"] == len(c) and
                  record["ghidra_c_warning_present"] == ("WARNING:" in c),
                  "ordinary spread record mismatch")
    check(metrics["source_instructions"] == verify["source_capstone_instructions"] == 177039,
          "source instruction total")
    check(metrics["listed_instructions"] == verify["ghidra_listed_source_aligned_instructions"] == 170662,
          "listed instruction total")
    check(metrics["full_listings"] == verify["ghidra_fully_listed_bodies"] == 1784,
          "full listing count")
    check(metrics["C_like"] == verify["ghidra_c_like_bodies_recovered"] == 2178 and
          metrics["C_warnings"] == verify["c_bodies_with_warnings"] == 425,
          "C-like/warning count")
    check(all(metrics["flow_" + k] == verify["ghidra_flow_transfer_source_opcode_counts"][k]
              for k in ("bl", "blr", "b", "br")), "flow opcode counts")
    check(digest(seal_path) == seal_sha, "stable sealed snapshot")
    print(json.dumps({"verdict": "INDEPENDENT_STATIC_PROVENANCE_PASS", "seal_sha256": seal_sha,
                      "report_files": len(actual), "code_files": len(seal["code_files"]),
                      "report_bytes": report_bytes, "export_names": 2401, "export_vas": 2178,
                      "ordinary_sample": len(sample), "metrics": dict(metrics),
                      "limitation": "394 partial instruction listings; 425 C warnings; export-only static research"}, indent=2))


if __name__ == "__main__":
    main()
