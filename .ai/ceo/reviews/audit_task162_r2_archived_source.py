"""Independent read-only evidence audit of TASK_162 R1 despite its invalid final schema."""

import hashlib
import json
import math
import re
from collections import Counter
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile


ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_162_REPORT_R1"
SOURCES = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a")
PINNED = (
    ("libhiai_ir.so", "c96af03947bde73255f4b77e3c253ae63130fdfed8b259196d24bbf3ba84a7d1", 1002),
    ("libkoom-strip-dump.so", "db0db1bdef5f51386ea2036682c0129b842aa5e3445a26d60ea6c5d29113faa3", 668),
)


def digest(path):
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1 << 20), b""):
            h.update(block)
    return h.hexdigest()


def data(path):
    return json.loads(path.read_text(encoding="utf-8"))


def require(ok, message):
    if not ok:
        raise AssertionError(message)


def main():
    require(digest(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") == "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f", "canonical hash")
    require(digest(ROOT / "RULES/REPORT/CEO_SO45_ORCHESTRATION/TASK_162_R1_TASK_ARCHIVE.md") == "22e38e8081d202d558704a99fb1d5cc6ea9e30a1a8267f44467ab15320e52942", "task hash")
    seal_path = REPORT / "COMPLETE.json"
    seal_sha = digest(seal_path)
    seal = data(seal_path)
    require(seal["task_id"] == "TASK_162" and seal["revision"] == 1 and seal["fencing_token"] == 1189, "seal identity")
    require(seal["status"] == "COMPLETE_CANDIDATE" and "files" not in seal and "code_files" not in seal, "known controller schema defect")
    names = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()} - {"COMPLETE.json"}
    require(set(seal["file_sha256"]) == names, "legacy hash-map exact set")
    for name, expected in seal["file_sha256"].items():
        require(digest(REPORT / name) == expected, "legacy report hash " + name)
    report_bytes = sum((REPORT / name).stat().st_size for name in names)
    require(report_bytes == seal["report_bytes_excluding_complete"] and report_bytes <= 134217728, "report extent")
    code_files = sorted(p for p in (ROOT / "scripts/task_162_codex_exports").glob("*") if p.is_file() and p.suffix in (".py", ".java"))
    require(len(code_files) == 5, "generator code inventory")
    code_hashes = {p.relative_to(ROOT).as_posix(): digest(p) for p in code_files}
    run = data(REPORT / "batch_run_receipt.json")
    require(run["status"] == "OUTPUT_READY" and len(run["steps"]) == 16 and run["elapsed_seconds"] <= 6600, "batch run")
    batch = data(REPORT / "source_batch_index.json")
    require(batch["total_unique_export_vas"] == 1670, "batch census")
    cap = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    totals = Counter()
    sample_total = 0
    for source_name, source_sha, expected_vas in PINNED:
        source_path = SOURCES / source_name
        require(digest(source_path) == source_sha, "original SO hash " + source_name)
        source = source_path.read_bytes()
        folder = REPORT / source_name
        index = data(folder / "source_index.json")
        require(index["source_sha256"] == source_sha and index["unique_export_vas"] == expected_vas and len(index["targets"]) == expected_vas, "source index")
        with source_path.open("rb") as stream:
            elf = ELFFile(stream)
            require(elf["e_machine"] == "EM_AARCH64", "ELF machine")
            by_va = {}
            for sym in elf.get_section_by_name(".dynsym").iter_symbols():
                if sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF" and int(sym["st_size"]) > 0 and int(sym["st_value"]) > 0:
                    by_va.setdefault(int(sym["st_value"]), []).append((sym.name, int(sym["st_size"])))
            loads = [(int(s["p_vaddr"]), int(s["p_offset"]), int(s["p_filesz"])) for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
        require(len(by_va) == expected_vas and sum(map(len, by_va.values())) == index["defined_nonzero_function_symbols"], "independent dynsym census")
        import_receipt = data(folder / "import/ghidra_command.json")
        require(import_receipt["status"] == "IMPORT_READY" and import_receipt["exit_code"] == 0 and import_receipt["elapsed_seconds"] <= 900, "fresh import receipt")
        import_cmd = import_receipt["command"]
        require(import_cmd.count("-import") == 1 and import_cmd[import_cmd.index("-max-cpu") + 1] == "1", "one bounded import")
        for stream_name in ("stdout", "stderr"):
            require(digest(folder / f"import/ghidra_{stream_name}.log") == import_receipt[stream_name + "_sha256"], "import log hash")
        require("REPORT: Import succeeded" in (folder / "import/ghidra_stdout.log").read_text(encoding="utf-8", errors="replace"), "import success log")
        source_assembly = [json.loads(line) for line in (folder / "source_assembly.ndjson").read_text(encoding="utf-8").splitlines() if line]
        require(len(source_assembly) == expected_vas, "source assembly rows")
        raw_rows = {}
        base = None
        for n, chunk in enumerate(index["chunks"]):
            require(chunk["chunk"] == n and 0 < chunk["count"] <= 128, "chunk order/bounds")
            sub = folder / f"chunk_{n:03d}"
            receipt = data(sub / "ghidra_command.json")
            require(receipt["status"] == "OUTPUT_READY" and receipt["exit_code"] == 0 and receipt["elapsed_seconds"] <= 900, "chunk output")
            cmd = receipt["command"]
            require("-import" not in cmd and "-process" in cmd and "-readOnly" in cmd and "-noanalysis" in cmd and cmd[cmd.index("-max-cpu") + 1] == "1", "read-only chunk")
            require(receipt["script_sha256"] == code_hashes["scripts/task_162_codex_exports/ExportSo162.java"], "executed Java hash")
            for name, key in (("targets.tsv", "target_tsv_sha256"), ("ghidra_raw.json", "result_sha256"), ("ghidra_stdout.log", "stdout_sha256"), ("ghidra_stderr.log", "stderr_sha256")):
                require(digest(sub / name) == receipt[key], "raw receipt hash " + name)
            require(digest(sub / "targets.tsv") == chunk["target_tsv_sha256"], "indexed TSV")
            require(f"[TASK_162] processed {chunk['count']}/{chunk['count']}" in (sub / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace"), "raw completion log")
            raw = data(sub / "ghidra_raw.json")
            require(raw["task_id"] == "TASK_162" and raw["program_name"] == source_name and len(raw["targets"]) == chunk["count"], "raw chunk identity")
            new_base = int(raw["image_base"], 16)
            require(base is None or base == new_base, "image base stable")
            base = new_base
            require([row["index"] for row in raw["targets"]] == list(range(chunk["first_index"], chunk["last_index"] + 1)), "raw indices")
            tsv = (sub / "targets.tsv").read_text(encoding="utf-8").splitlines()
            require(len(tsv) == len(raw["targets"]), "TSV rows")
            for line, row in zip(tsv, raw["targets"]):
                require(line.split("\t", 4) == [str(row["index"]), row["elf_va"], str(row["size_bytes"]), row["expected_source_sha256"], row["symbol"]], "TSV/raw")
                require(row["index"] not in raw_rows, "duplicate Ghidra row")
                raw_rows[row["index"]] = row
        require(set(raw_rows) == set(range(1, expected_vas + 1)), "complete raw coverage")
        sample_count = math.ceil(.1 * expected_vas)
        sample = {round(i * (expected_vas - 1) / (sample_count - 1)) for i in range(sample_count)}
        require(len(sample) == sample_count, "spread sample")
        sample_total += sample_count
        metrics = Counter()
        for position, target in enumerate(index["targets"]):
            i = position + 1
            require(target["index"] == i, "target order")
            va, size = int(target["elf_va"], 16), target["size_bytes"]
            aliases = sorted(by_va[va], key=lambda pair: (-pair[1], pair[0]))
            require((target["symbol"], size) == aliases[0], "symbol/size")
            offsets = [off + va - start for start, off, length in loads if start <= va and va + size <= start + length]
            require(offsets and int(target["file_offset"], 16) in offsets, "PT_LOAD offset")
            body = source[offsets[0]:offsets[0] + size]
            body_sha = hashlib.sha256(body).hexdigest()
            require(len(body) == size and body_sha == target["source_body_sha256"], "original body hash")
            assembly = source_assembly[position]
            require(assembly["index"] == i and assembly["elf_va"] == target["elf_va"] and bytes.fromhex(assembly["source_bytes_hex"]) == body, "retained source assembly/body")
            decoded = list(cap.disasm(body, va))
            require(sum(ins.size for ins in decoded) == size and len(assembly["capstone_source_assembly"]) == len(decoded), "full Capstone source decode")
            lookup = {ins.address: ins for ins in decoded}
            row = raw_rows[i]
            require(row["elf_va"] == target["elf_va"] and row["size_bytes"] == size and row["symbol"] == target["symbol"], "raw target")
            require(row["source_bytes_match"] is True and row["expected_source_sha256"] == row["ghidra_memory_sha256"] == body_sha and int(row["database_va"], 16) == base + va, "Ghidra memory/source")
            require(0 <= row["elapsed_ms"] <= 15000, "function time")
            listing = row["instructions"]
            require(listing and len(listing) == row["instruction_count_observed"], "listing count")
            addresses = []
            for line in listing:
                match = re.match(r"^([0-9a-fA-F]+):\s+", line)
                require(match is not None, "listing syntax")
                addr = int(match.group(1), 16) - base
                require(addr in lookup, "listing original alignment")
                addresses.append(addr)
            require(addresses == sorted(set(addresses)), "listing order")
            for call in row["calls"]:
                match = re.match(r"^([0-9a-fA-F]+)\s+->\s+", call)
                require(match is not None, "call syntax")
                addr = int(match.group(1), 16) - base
                require(addr in lookup and lookup[addr].mnemonic in ("bl", "blr", "b", "br"), "call source opcode")
                metrics["calls"] += 1
            c = row["pseudocode"]
            require(row["decompile_success"] is True and not row["error"] and c.strip() and "{" in c, "C-like body")
            metrics["source_instructions"] += len(decoded)
            metrics["listed_instructions"] += len(listing)
            metrics["full_listings"] += len(listing) == len(decoded)
            metrics["warnings"] += "WARNING:" in c
            metrics["max_elapsed_ms"] = max(metrics["max_elapsed_ms"], row["elapsed_ms"])
            if position in sample:
                for line, ins in zip(assembly["capstone_source_assembly"], decoded):
                    match = re.match(r"^0x([0-9a-fA-F]+):\s+(\S+)", line)
                    require(match is not None and int(match.group(1), 16) == ins.address and match.group(2) == ins.mnemonic, "sample source assembly")
        totals.update({"export_vas": expected_vas, "source_instructions": metrics["source_instructions"], "listed_instructions": metrics["listed_instructions"], "full_listings": metrics["full_listings"], "warnings": metrics["warnings"], "calls": metrics["calls"]})
    require(totals["export_vas"] == seal["source_export_vas"] == seal["ghidra_memory_matched"] == seal["c_like_export_bodies"] == 1670, "aggregate coverage")
    require(sample_total == seal["ordinary_provenance_sample_count"] == 168, "ordinary 10% sample")
    require(digest(seal_path) == seal_sha, "stable seal")
    print(json.dumps({"verdict": "RAW_EVIDENCE_PASS_CONTROLLER_SCHEMA_FAIL", "seal_sha256": seal_sha, "report_files": len(names), "report_bytes": report_bytes, "code_hashes": code_hashes, "ordinary_sample": sample_total, "metrics": dict(totals)}, indent=2))


if __name__ == "__main__":
    main()
