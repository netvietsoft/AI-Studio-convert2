"""Independent, read-only audit of TASK_159's dexvmp partial result."""

import hashlib
import json
import math
import re
from collections import Counter
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_159_REPORT_R1"
PRIOR = ROOT / "RULES/REPORT/TASK_156_REPORT_R1/libdexvmp.so"
PROJECT = ROOT / "RESEARCH_WORK/TASK_159_R1/ghidra_project"
PRIOR_PROJECT = ROOT / "RESEARCH_WORK/TASK_156_R1/libdexvmp.so/ghidra_project"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libdexvmp.so")
SOURCE_SHA = "b4a46520ec989fef5346833db8f9a1bd6a6690902731414ed26f65cc529cc06e"


def digest(path):
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1 << 20), b""):
            h.update(block)
    return h.hexdigest()


def read(path):
    return json.loads(path.read_text(encoding="utf-8"))


def check(value, message):
    if not value:
        raise AssertionError(message)


def main():
    check(digest(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") == "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f", "standard")
    check(digest(ROOT / "RULES/TASK/TASK_159_SO45_CODEX_DEXVMP_CORRECTION_ACTIVE.md") == "230b513b634d6bf1f7ee6a1be91008494141226dd976ac1f5f8a15fed8470de6", "task")
    check(digest(SOURCE) == SOURCE_SHA, "original SO")
    sealed_path = REPORT / "COMPLETE.json"
    sealed_sha = digest(sealed_path)
    sealed = read(sealed_path)
    check(sealed["task_id"] == "TASK_159" and sealed["revision"] == 1 and sealed["fencing_token"] == 1187 and sealed["semantic_disposition"] == "PARTIAL_RESEARCH_CANDIDATE", "seal identity")
    names = set(sealed["files"])
    actual_names = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()} - {"COMPLETE.json", "PROGRESS.json"}
    check(names == actual_names, "manifest exact set")
    for name, expected in sealed["files"].items():
        check(digest(REPORT / name) == expected, "report hash " + name)
    for name, expected in sealed["code_files"].items():
        check(digest(ROOT / name) == expected, "code hash " + name)
    report_bytes = sum((REPORT / name).stat().st_size for name in names)
    check(report_bytes <= 33_554_432, "report cap")
    index = read(REPORT / "target_index.json")
    prior_index = read(PRIOR / "target_index.json")
    check(index["prior_task156_index_sha256"] == digest(PRIOR / "target_index.json"), "prior source index identity")
    check(index["targets"] == prior_index["targets"] and len(index["targets"]) == 284 and index["source_sha256"] == SOURCE_SHA, "source index")
    copy = read(REPORT / "project_copy_receipt.json")
    check(copy["fresh_imports"] == 0 and copy["copied_file_hashes_match"] is True and len(copy["project_file_hashes"]) == 10, "project copy receipt")
    check(copy["prior_import_analysis_completed"] is False and copy["prior_import_analysis_timeout_seconds"] == 480, "prior analysis cap")
    prior_files = {p.relative_to(PRIOR_PROJECT).as_posix() for p in PRIOR_PROJECT.rglob("*") if p.is_file()}
    copied_files = {p.relative_to(PROJECT).as_posix() for p in PROJECT.rglob("*") if p.is_file()}
    check(prior_files == set(copy["project_file_hashes"]), "original project receipt file set")
    check(prior_files - copied_files == {"SmallLib156.rep/idata/~journal.bak"} and not copied_files - prior_files, "current copy lost only ephemeral Ghidra journal")
    changed_copy_files = []
    for name, expected in copy["project_file_hashes"].items():
        check(digest(PRIOR_PROJECT / name) == expected, "prior project hash")
        if name in copied_files:
            if digest(PROJECT / name) != expected:
                changed_copy_files.append(name)
    check(changed_copy_files == ["SmallLib156.rep/idata/~index.bak"], "only Ghidra backup metadata changed in current copy")
    for name in ("ghidra_command.json", "ghidra_stdout.log"):
        check(digest(PRIOR / name) == digest(REPORT / ("prior_task156_" + name)), "prior log/command copy")
    old_log = (PRIOR / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace")
    check("Analysis timed out at 480 seconds" in old_log and "IllegalArgumentException: invalid target bounds" in old_log, "prior failure cause")
    batch = read(REPORT / "batch_run_receipt.json")
    check(batch["status"] == "OUTPUT_READY" and batch["fresh_imports"] == 0 and len(batch["chunks"]) == 4 and batch["elapsed_seconds"] <= 3600, "batch execution")
    outcomes = {x["chunk"]: x for x in batch["chunks"]}
    check(set(outcomes) == {0, 1, 2, 3}, "chunk coverage")
    raw = {}
    image_bases = set()
    for meta in index["chunks"]:
        n = meta["chunk"]
        folder = REPORT / meta["folder"]
        receipt = read(folder / "ghidra_command.json")
        outcome = outcomes[n]
        check(outcome["status"] == receipt["status"] == "OUTPUT_READY" and outcome["exit_code"] == receipt["exit_code"] == 0, "chunk success")
        check(receipt["elapsed_seconds"] <= receipt["timeout_seconds"] <= 900 and receipt["fresh_imports"] == 0, "chunk time/import")
        cmd = receipt["command"]
        check(cmd[3:9] == ["-process", SOURCE.name, "-noanalysis", "-readOnly", "-max-cpu", "1"] and "-import" not in cmd, "readonly command")
        check(receipt["script_sha256"] == digest(ROOT / "scripts/task159_codex_dexvmp_correction/ExportDexvmp159.java"), "script identity")
        for filename, key in (("targets.tsv", "target_tsv_sha256"), ("ghidra_raw.json", "result_sha256"), ("ghidra_stdout.log", "stdout_sha256"), ("ghidra_stderr.log", "stderr_sha256")):
            check(digest(folder / filename) == receipt[key], "chunk file hash " + filename)
        check(digest(folder / "targets.tsv") == meta["target_tsv_sha256"], "chunk target hash")
        log = (folder / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace")
        check(f"[TASK_159] processed {meta['count']}/{meta['count']}" in log and "Processing read-only project file" in log, "chunk Ghidra log")
        rows = read(folder / "ghidra_raw.json")
        check(rows["task_id"] == "TASK_159" and rows["program_name"] == SOURCE.name and len(rows["targets"]) == meta["count"], "chunk raw identity")
        base = int(rows["image_base"], 16)
        image_bases.add(base)
        lines = (folder / "targets.tsv").read_text(encoding="utf-8").splitlines()
        check(len(lines) == meta["count"], "TSV count")
        for line, row in zip(lines, rows["targets"]):
            check(line.split("\t", 4) == [str(row["index"]), row["elf_va"], str(row["size_bytes"]), row["expected_source_sha256"], row["symbol"]], "TSV/raw identity")
            check(row["index"] not in raw, "duplicate raw target")
            raw[row["index"]] = row
    check(set(raw) == set(range(1, 285)) and image_bases == {0x100000}, "raw coverage/base")
    check([len(read(REPORT / meta["folder"] / "ghidra_raw.json")["targets"]) for meta in index["chunks"]] == [100, 100, 83, 1], "four bounded chunks")
    verified = read(REPORT / "independent_verification.json")
    check(len(verified["records"]) == 284, "verification records")
    sample = {round(i * 283 / 28) for i in range(29)}
    check(len(sample) >= math.ceil(284 * .1), "sample size")
    source = SOURCE.read_bytes()
    with SOURCE.open("rb") as handle:
        elf = ELFFile(handle)
        check(elf["e_machine"] == "EM_AARCH64", "machine")
        by_va = {}
        for sym in elf.get_section_by_name(".dynsym").iter_symbols():
            if sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF" and int(sym["st_size"]) > 0 and int(sym["st_value"]) > 0:
                by_va.setdefault(int(sym["st_value"]), []).append((sym.name, int(sym["st_size"])))
        segments = [(int(s["p_vaddr"]), int(s["p_offset"]), int(s["p_filesz"])) for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
    check(sum(map(len, by_va.values())) == len(by_va) == 284, "independent ELF census")
    cap = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    stats = Counter()
    assembly = []
    c_parts = []
    failures = []
    for position, target in enumerate(index["targets"]):
        n = position + 1
        check(target["index"] == n, "target order")
        va, size = int(target["elf_va"], 16), target["size_bytes"]
        check(by_va[va] == [(target["symbol"], size)], "ELF symbol")
        offsets = [offset + va - start for start, offset, length in segments if start <= va and va + size <= start + length]
        check(len(offsets) == 1 and int(target["file_offset"], 16) == offsets[0], "PT_LOAD")
        body = source[offsets[0]:offsets[0] + size]
        body_sha = hashlib.sha256(body).hexdigest()
        check(len(body) == size and body_sha == target["source_body_sha256"], "body hash")
        assembly.append(f"\n// EXPORT index={n} ELF_VA=0x{va:x} size={size} sha256={body_sha} symbol={target['symbol']}\n")
        decoded_map = {}
        decoded_here = 0
        undecoded_here = 0
        for offset in range(0, size, 4):
            word = body[offset:offset + 4]
            addr = va + offset
            decoded = list(cap.disasm(word, addr, count=1)) if len(word) == 4 else []
            if decoded and decoded[0].size == 4:
                ins = decoded[0]
                decoded_map[addr] = ins.mnemonic
                assembly.append(f"0x{addr:x}\t{word.hex()}\t{ins.mnemonic}\t{ins.op_str}\n")
                decoded_here += 1
            else:
                assembly.append(f"0x{addr:x}\t{word.hex()}\t.UNDECODED_WORD\n")
                undecoded_here += 1
        row = raw[n]
        check(row["elf_va"] == target["elf_va"] and row["size_bytes"] == size and row["symbol"] == target["symbol"], "Ghidra target")
        check(int(row["database_va"], 16) == 0x100000 + va and row["source_bytes_match"] is True and row["expected_source_sha256"] == row["ghidra_memory_sha256"] == body_sha, "Ghidra/source bytes")
        addresses = []
        for line in row["instructions"]:
            match = re.match(r"^([0-9a-fA-F]+):\s+", line)
            check(match is not None, "listing parse")
            addr = int(match.group(1), 16) - 0x100000
            check(addr in decoded_map, "listing source opcode")
            addresses.append(addr)
        check(len(addresses) == row["instruction_count_observed"] and addresses == sorted(set(addresses)), "listing order/count")
        for call in row["calls"]:
            match = re.match(r"^([0-9a-fA-F]+)\s+->\s+", call)
            check(match is not None, "flow parse")
            addr = int(match.group(1), 16) - 0x100000
            check(decoded_map.get(addr) in ("bl", "blr", "b", "br", "blraa", "blrab", "braa", "brab"), "flow source opcode")
        c = row["pseudocode"]
        good = row["decompile_success"] is True and bool(c.strip()) and not row["error"] and "{" in c
        if good:
            c_parts.append(f"\n/* EXPORT index={n} ELF_VA=0x{va:x} size={size} source_sha256={body_sha} */\n")
            c_parts.append(c)
            stats["C_like"] += 1
            stats["warnings"] += "WARNING:" in c
        else:
            failures.append((n, target["elf_va"], row["error"], row["elapsed_ms"]))
        stats["decoded_words"] += decoded_here
        stats["undecoded_words"] += undecoded_here
        stats["listed_instructions"] += len(addresses)
        stats["flows"] += len(row["calls"])
        record = verified["records"][position]
        if position in sample:
            check(record["index"] == n and record["source_body_sha256"] == body_sha and record["source_words_decoded"] == decoded_here and record["source_words_undecoded"] == undecoded_here, "ordinary source sample")
            check(record["ghidra_listed_source_aligned_instructions"] == len(addresses) and record["ghidra_c_like_recovered"] == good, "ordinary output sample")
    check("".join(assembly).encode("utf-8") == (REPORT / "all_source_assembly.txt").read_bytes(), "full assembly artifact")
    check("".join(c_parts).encode("utf-8") == (REPORT / "all_recovered_export_pseudocode.c").read_bytes(), "C artifact")
    check(dict(stats) == {"decoded_words": 86585, "undecoded_words": 193, "listed_instructions": 29848, "flows": 1030, "C_like": 283, "warnings": 118}, "aggregate metrics")
    check(len(failures) == 1 and failures[0][0:2] == (232, "0x29cd4") and "timeout" in failures[0][2].lower() and failures[0][3] >= 15000, "isolated decompiler failure")
    check(verified["ghidra_c_like_failures"] == [{"index": 232, "elf_va": "0x29cd4", "size_bytes": 224440, "error": failures[0][2]}], "failure manifest")
    check(sealed["c_like_bodies_recovered"] == 283 and sealed["unrecovered_c_like_vas"] == ["0x29cd4"], "sealed partial")
    check(digest(sealed_path) == sealed_sha, "stable seal")
    print(json.dumps({"verdict": "INDEPENDENT_PARTIAL_PROVENANCE_PASS", "seal_sha256": sealed_sha,
                      "report_files": len(names), "code_files": len(sealed["code_files"]), "report_bytes": report_bytes,
                      "source_export_vas": 284, "Ghidra_chunks": 4, "fresh_imports": 0,
                      "ordinary_sample": len(sample), "metrics": dict(stats),
                      "postprocess_project_metadata_change": {"changed": changed_copy_files,
                          "removed": sorted(prior_files - copied_files)},
                      "remaining_C_like_gap": {"index": 232, "elf_va": "0x29cd4", "size_bytes": 224440,
                                               "error": failures[0][2].strip()},
                      "caveat": "Prior autoanalysis incomplete; source assembly contains explicit undecoded words; no runtime semantics"}, indent=2))


if __name__ == "__main__":
    main()
