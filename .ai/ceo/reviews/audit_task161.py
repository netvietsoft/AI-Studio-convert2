"""Read-only, independent original-ELF/raw-Ghidra audit for TASK_161."""

import hashlib
import json
import math
import re
from collections import Counter
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile


ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_161_REPORT_R1"
SOURCES = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a")
PINNED = (
    ("libManis.so", "libManis", "19daf9b4b1718c843169d68391e99a27d10bd3cece52226c887c3ab9b93dddc2", 266, 287, 27),
    ("libmanis_npu_adapter.so", "libmanis_npu_adapter", "99a9a4b161b9797d7cf621e93a51a7df408f80c84e652bbc6724eef7e71ca6f3", 996, 1003, 100),
)


def digest(path):
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1 << 20), b""):
            h.update(block)
    return h.hexdigest()


def data(path):
    return json.loads(path.read_text(encoding="utf-8"))


def require(condition, message):
    if not condition:
        raise AssertionError(message)


def main():
    require(digest(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") == "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f", "canonical hash")
    require(digest(ROOT / "RULES/TASK/TASK_161_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md") == "5c1cae9057b62789528c9bfdd01163d7c2c0c1868f19b21c236834cfcb0a9860", "task hash")
    seal_path = REPORT / "COMPLETE.json"
    seal_sha = digest(seal_path)
    seal = data(seal_path)
    require(seal["task_id"] == "TASK_161" and seal["revision"] == 1 and seal["status"] == "COMPLETE" and seal["fencing_token"] == 1190, "seal identity")
    require(seal["source_bodies_rehashed"] == seal["ghidra_memory_bodies_rehashed"] == seal["c_like_bodies_recovered"] == 1262, "aggregate coverage")
    require(seal["internal_nonexported_functions_covered"] is False and seal["runtime_or_pixel_semantics_proven"] is False, "semantic limit")
    actual = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()} - {"COMPLETE.json", "PROGRESS.json"}
    require(set(seal["files"]) == actual, "manifest exact set")
    for name, expected in seal["files"].items():
        require(digest(REPORT / name) == expected, "report hash " + name)
    for name, expected in seal["code_files"].items():
        require(digest(ROOT / name) == expected, "code hash " + name)
    report_bytes = sum((REPORT / name).stat().st_size for name in actual)
    require(report_bytes <= 134217728, "report cap")
    cap = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    totals = Counter()
    source_summaries = []
    for source_name, folder_name, expected_sha, expected_vas, expected_names, sample_count in PINNED:
        source_path = SOURCES / source_name
        require(digest(source_path) == expected_sha, "source SO hash " + source_name)
        source = source_path.read_bytes()
        folder = REPORT / folder_name
        index = data(folder / "target_index.json")
        worker = data(folder / "worker_source_verification.json")
        source_seal = data(folder / "SOURCE_COMPLETE.json")
        require(index["source_sha256"] == source_seal["source_sha256"] == expected_sha, "source identity")
        require(index["unique_export_vas"] == expected_vas and index["defined_nonzero_function_symbols"] == expected_names and len(index["targets"]) == expected_vas, "index census")
        require(source_seal["source_bodies_rehashed"] == source_seal["c_like_bodies_recovered"] == expected_vas, "source seal census")
        require(digest(folder / "SOURCE_COMPLETE.json") == next(x["source_complete_sha256"] for x in seal["source_summaries"] if x["source_name"] == source_name), "source seal hash")
        source_files = {p.relative_to(folder).as_posix() for p in folder.rglob("*") if p.is_file()} - {"SOURCE_COMPLETE.json", "PROGRESS.json"}
        require(set(source_seal["files"]) == source_files, "source manifest set")
        for name, expected in source_seal["files"].items():
            require(digest(folder / name) == expected, "source manifest hash " + name)
        with source_path.open("rb") as stream:
            elf = ELFFile(stream)
            require(elf["e_machine"] == "EM_AARCH64", "ELF machine")
            by_va = {}
            for sym in elf.get_section_by_name(".dynsym").iter_symbols():
                if sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF" and int(sym["st_size"]) > 0 and int(sym["st_value"]) > 0:
                    by_va.setdefault(int(sym["st_value"]), []).append((sym.name, int(sym["st_size"])))
            loads = [(int(s["p_vaddr"]), int(s["p_offset"]), int(s["p_filesz"])) for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
        require(len(by_va) == expected_vas and sum(map(len, by_va.values())) == expected_names, "independent dynsym census")
        import_receipt = data(folder / "ghidra_import_command.json")
        run = data(folder / "batch_run_receipt.json")
        require(import_receipt["status"] == "PROJECT_READY" and import_receipt["exit_code"] == 0 and import_receipt["elapsed_seconds"] <= 900, "import receipt")
        cmd = import_receipt["command"]
        require(cmd.count("-import") == 1 and "-max-cpu" in cmd and cmd[cmd.index("-max-cpu") + 1] == "1", "one bounded import")
        require(source_name.lower() in " ".join(cmd).lower(), "import original SO")
        for stream_name in ("stdout", "stderr"):
            require(digest(folder / f"ghidra_import_{stream_name}.log") == import_receipt[stream_name + "_sha256"], "import log hash")
        require("REPORT: Import succeeded" in (folder / "ghidra_import_stdout.log").read_text(encoding="utf-8", errors="replace"), "import log outcome")
        require(run["status"] == "OUTPUT_READY" and len(run["chunks"]) == len(index["chunks"]) and run["elapsed_seconds"] <= 6600, "batch receipt")
        raw_rows = {}
        image_base = None
        for n, chunk in enumerate(index["chunks"]):
            require(chunk["chunk"] == n and 0 < chunk["count"] <= 256, "chunk order/bound")
            sub = folder / f"chunk_{n:02d}"
            receipt = data(sub / "ghidra_command.json")
            outcome = run["chunks"][n]
            require(receipt["status"] == outcome["status"] == "OUTPUT_READY" and receipt["exit_code"] == outcome["exit_code"] == 0 and receipt["elapsed_seconds"] <= 900, "chunk outcome")
            cmd = receipt["command"]
            require("-import" not in cmd and "-process" in cmd and "-noanalysis" in cmd and "-readOnly" in cmd and cmd[cmd.index("-max-cpu") + 1] == "1", "read-only Ghidra command")
            require(receipt["script_sha256"] == digest(ROOT / "scripts/task_161_codex_exports/ExportTask161Chunk.java"), "executed Java")
            for name, key in (("targets.tsv", "target_tsv_sha256"), ("ghidra_raw.json", "result_sha256"), ("ghidra_stdout.log", "stdout_sha256"), ("ghidra_stderr.log", "stderr_sha256")):
                require(digest(sub / name) == receipt[key], "chunk receipt hash " + name)
            require(digest(sub / "targets.tsv") == chunk["target_tsv_sha256"], "indexed TSV")
            require(f"[TASK_161] processed {chunk['count']}/{chunk['count']}" in (sub / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace"), "raw Ghidra completion")
            raw = data(sub / "ghidra_raw.json")
            require(raw["program_name"] == source_name and raw["task_id"] == "TASK_161" and len(raw["targets"]) == chunk["count"], "raw chunk identity")
            base = int(raw["image_base"], 16)
            require(image_base is None or base == image_base, "image base")
            image_base = base
            require([r["index"] for r in raw["targets"]] == list(range(chunk["first_index"], chunk["last_index"] + 1)), "raw index range")
            lines = (sub / "targets.tsv").read_text(encoding="utf-8").splitlines()
            require(len(lines) == len(raw["targets"]), "TSV row count")
            for line, row in zip(lines, raw["targets"]):
                require(line.split("\t", 4) == [str(row["index"]), row["elf_va"], str(row["size_bytes"]), row["expected_source_sha256"], row["symbol"]], "TSV/raw")
                require(row["index"] not in raw_rows, "duplicate raw index")
                raw_rows[row["index"]] = row
        require(set(raw_rows) == set(range(1, expected_vas + 1)), "complete raw targets")
        require(len(worker["records"]) == expected_vas, "worker record count")
        sample = {round(i * (expected_vas - 1) / (sample_count - 1)) for i in range(sample_count)}
        require(len(sample) >= math.ceil(.1 * expected_vas), "spread sample")
        metrics = Counter()
        for position, target in enumerate(index["targets"]):
            i = position + 1
            require(target["index"] == i, "target index")
            va, size = int(target["elf_va"], 16), target["size_bytes"]
            aliases = sorted(by_va[va], key=lambda pair: (-pair[1], pair[0]))
            require((target["symbol"], size) == aliases[0] and target["aliases"] == [name for name, _ in aliases], "ELF alias")
            offsets = [off + va - start for start, off, length in loads if start <= va and va + size <= start + length]
            require(offsets and int(target["file_offset"], 16) in offsets, "PT_LOAD offset")
            body = source[offsets[0]:offsets[0] + size]
            body_sha = hashlib.sha256(body).hexdigest()
            require(len(body) == size and body_sha == target["source_body_sha256"], "original body")
            row = raw_rows[i]
            require(row["elf_va"] == target["elf_va"] and row["symbol"] == target["symbol"] and row["size_bytes"] == size, "raw identity")
            require(row["source_bytes_match"] is True and row["expected_source_sha256"] == row["ghidra_memory_sha256"] == body_sha and int(row["database_va"], 16) == image_base + va, "Ghidra/source body")
            require(0 <= row["elapsed_ms"] <= 15000, "per-function time")
            decoded = list(cap.disasm(body, va))
            require(sum(ins.size for ins in decoded) == size, "AArch64 full source decode")
            lookup = {ins.address: ins for ins in decoded}
            listing = row["instructions"]
            require(listing and len(listing) == row["instruction_count_observed"], "listing length")
            addrs = []
            for line in listing:
                match = re.match(r"^([0-9a-fA-F]+):\s+", line)
                require(match is not None, "listing syntax")
                address = int(match.group(1), 16) - image_base
                require(address in lookup, "listing original alignment")
                addrs.append(address)
            require(addrs == sorted(set(addrs)), "listing order")
            for call in row["calls"]:
                match = re.match(r"^([0-9a-fA-F]+)\s+->\s+", call)
                require(match is not None, "call syntax")
                address = int(match.group(1), 16) - image_base
                require(address in lookup and lookup[address].mnemonic in ("bl", "blr", "b", "br"), "call opcode")
                metrics["calls"] += 1
            c = row["pseudocode"]
            require(row["decompile_success"] is True and not row["error"] and c.strip() and "{" in c, "C-like body")
            metrics["source_instructions"] += len(decoded)
            metrics["listed_instructions"] += len(listing)
            metrics["full_listings"] += len(listing) == len(decoded)
            metrics["warnings"] += "WARNING:" in c
            metrics["max_elapsed_ms"] = max(metrics["max_elapsed_ms"], row["elapsed_ms"])
            if position in sample:
                record = worker["records"][position]
                require(record["index"] == i and record["elf_va"] == target["elf_va"] and record["source_body_sha256"] == body_sha, "sample identity")
                require(record["source_capstone_instructions"] == len(decoded) and record["ghidra_listed_instructions"] == len(listing), "sample instruction counts")
                require(record["ghidra_c_like_characters"] == len(c) and record["ghidra_c_warning_present"] == ("WARNING:" in c), "sample C provenance")
        require(worker["source_capstone_instructions"] == metrics["source_instructions"] and worker["ghidra_listed_source_aligned_instructions"] == metrics["listed_instructions"], "instruction totals")
        require(worker["ghidra_fully_listed_bodies"] == metrics["full_listings"] and worker["c_bodies_with_warnings"] == metrics["warnings"], "listing/warning totals")
        totals.update({"export_vas": expected_vas, "export_symbols": expected_names, "source_instructions": metrics["source_instructions"], "listed_instructions": metrics["listed_instructions"], "full_listings": metrics["full_listings"], "warnings": metrics["warnings"], "calls": metrics["calls"], "sample": len(sample)})
        source_summaries.append({"source": source_name, "export_vas": expected_vas, "ordinary_sample": len(sample), "metrics": dict(metrics)})
    require(totals["export_vas"] == 1262 and totals["sample"] == 127, "aggregate independent counts")
    require(digest(seal_path) == seal_sha, "stable seal")
    print(json.dumps({"verdict": "INDEPENDENT_PROVENANCE_PASS", "seal_sha256": seal_sha, "report_files": len(actual), "code_files": len(seal["code_files"]), "report_bytes": report_bytes, "totals": dict(totals), "sources": source_summaries, "caveat": "static export text only; warning and partial listings limit semantics"}, indent=2))


if __name__ == "__main__":
    main()
