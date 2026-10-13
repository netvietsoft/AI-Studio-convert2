"""Independent, read-only TASK_160 original-ELF and raw-Ghidra audit."""

import hashlib
import json
import math
import re
from collections import Counter
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile


ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_160_REPORT_R1"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libPVGImageCodec.so")
TASK = ROOT / "RULES/TASK/TASK_160_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"


def digest(path):
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1 << 20), b""):
            h.update(block)
    return h.hexdigest()


def read(path):
    return json.loads(path.read_text(encoding="utf-8"))


def require(ok, message):
    if not ok:
        raise AssertionError(message)


def main():
    require(digest(STANDARD) == "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f", "standard hash")
    require(digest(TASK) == "6672294da0a90ae239a7d348915f5a748aea8d1496061606c8a9852e58c80989", "task hash")
    require(digest(SOURCE) == "7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b", "original SO hash")
    seal_path = REPORT / "COMPLETE.json"
    seal_hash = digest(seal_path)
    seal = read(seal_path)
    require(seal["task_id"] == "TASK_160" and seal["revision"] == 1 and seal["status"] == "COMPLETE" and seal["fencing_token"] == 1188, "seal identity")
    require(seal["source_bodies_rehashed"] == seal["c_like_bodies_recovered"] == 3326, "seal coverage")
    require(seal["internal_nonexported_functions_covered"] is False and seal["runtime_or_pixel_semantics_proven"] is False, "semantic caveat")
    actual = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()} - {"COMPLETE.json", "PROGRESS.json"}
    require(set(seal["files"]) == actual, "manifest exact files")
    for name, expected in seal["files"].items():
        require(digest(REPORT / name) == expected, "report hash " + name)
    for name, expected in seal["code_files"].items():
        require(digest(ROOT / name) == expected, "code hash " + name)
    report_bytes = sum((REPORT / name).stat().st_size for name in actual)
    require(report_bytes <= 134217728, "report cap")
    require("10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f" in (REPORT / "00_AUDIT_INDEX.md").read_text(encoding="utf-8").lower(), "standard receipt")
    run = read(REPORT / "batch_run_receipt.json")
    require(run["status"] == "OUTPUT_READY" and len(run["chunks"]) == 13 and run["elapsed_seconds"] <= 6600, "run bounds")
    require(sum(x["elapsed_seconds"] for x in run["chunks"]) <= 6600, "aggregate process time")
    batch = read(REPORT / "source_batch_index.json")
    require(batch["total_unique_export_vas"] == 3326 and batch["libraries"][0]["library"] == SOURCE.name, "batch census")
    index = read(REPORT / SOURCE.name / "target_index.json")
    require(index["unique_export_vas"] == 3326 and index["defined_nonzero_function_symbols"] == 3702 and len(index["targets"]) == 3326, "index census")
    verification = read(REPORT / "independent_verification.json")
    c_manifest = read(REPORT / "source_c_manifest.json")
    require(len(verification["records"]) == len(c_manifest["records"]) == 3326, "record census")
    source = SOURCE.read_bytes()
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        require(elf["e_machine"] == "EM_AARCH64", "ELF machine")
        by_va = {}
        for sym in elf.get_section_by_name(".dynsym").iter_symbols():
            if sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF" and int(sym["st_size"]) > 0 and int(sym["st_value"]) > 0:
                by_va.setdefault(int(sym["st_value"]), []).append((sym.name, int(sym["st_size"])))
        loads = [(int(s["p_vaddr"]), int(s["p_offset"]), int(s["p_filesz"])) for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
    require(len(by_va) == 3326 and sum(map(len, by_va.values())) == 3702, "independent ELF export census")
    raw_rows = {}
    image_base = None
    for n, chunk in enumerate(index["chunks"], start=1):
        require(chunk["chunk"] == n and 0 < chunk["count"] <= 256, "chunk order/cap")
        folder = REPORT / SOURCE.name / f"chunk_{n:02d}"
        receipt = read(folder / "ghidra_command.json")
        outcome = run["chunks"][n - 1]
        require(receipt["status"] == outcome["status"] == "OUTPUT_READY" and receipt["exit_code"] == outcome["exit_code"] == 0, "chunk exit")
        require(receipt["elapsed_seconds"] <= 900 and receipt["elapsed_seconds"] == outcome["elapsed_seconds"], "chunk clock")
        cmd = receipt["command"]
        require(cmd[cmd.index("-max-cpu") + 1] == "1", "CPU cap")
        require(("-import" in cmd) == (n == 1), "one import")
        if n > 1:
            require("-process" in cmd and "-readOnly" in cmd and "-noanalysis" in cmd, "read-only subsequent")
        require(receipt["script_sha256"] == digest(ROOT / "scripts/task_160_codex_exports/ExportChunk160.java"), "executed script")
        for filename, key in (("targets.tsv", "target_tsv_sha256"), ("ghidra_raw.json", "result_sha256"), ("ghidra_stdout.log", "stdout_sha256"), ("ghidra_stderr.log", "stderr_sha256")):
            require(digest(folder / filename) == receipt[key], "receipt hash " + filename)
        require(digest(folder / "targets.tsv") == chunk["target_tsv_sha256"], "indexed TSV")
        stdout = (folder / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace")
        require(f"[TASK_160] processed {chunk['count']}/{chunk['count']}" in stdout, "Ghidra log completion")
        require(("REPORT: Import succeeded" in stdout) if n == 1 else ("Processing read-only project file" in stdout), "Ghidra operation log")
        raw = read(folder / "ghidra_raw.json")
        require(raw["task_id"] == "TASK_160" and raw["program_name"] == SOURCE.name and len(raw["targets"]) == chunk["count"], "raw chunk identity")
        base = int(raw["image_base"], 16)
        require(image_base is None or base == image_base, "stable image base")
        image_base = base
        require([r["index"] for r in raw["targets"]] == list(range(chunk["first_index"], chunk["last_index"] + 1)), "raw coverage")
        lines = (folder / "targets.tsv").read_text(encoding="utf-8").splitlines()
        require(len(lines) == len(raw["targets"]), "TSV row count")
        for line, row in zip(lines, raw["targets"]):
            require(line.split("\t", 4) == [str(row["index"]), row["elf_va"], str(row["size_bytes"]), row["expected_source_sha256"], row["symbol"]], "TSV/raw identity")
            require(row["index"] not in raw_rows, "duplicate raw index")
            raw_rows[row["index"]] = row
    require(set(raw_rows) == set(range(1, 3327)), "complete raw rows")
    require((ROOT / "RESEARCH_WORK/TASK_160_R1/libPVGImageCodec.so/ghidra_project/Task160.gpr").is_file(), "saved Ghidra project")
    sample = {round(i * 3325 / 333) for i in range(334)}
    require(len(sample) >= math.ceil(3326 * 0.1), "ordinary sample")
    cap = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    metrics = Counter()
    joined = []
    for position, target in enumerate(index["targets"]):
        i = position + 1
        require(target["index"] == i, "target index")
        va, size = int(target["elf_va"], 16), int(target["size_bytes"])
        aliases = sorted(by_va[va], key=lambda pair: (-pair[1], pair[0]))
        require((target["symbol"], size) == aliases[0] and target["aliases"] == [x for x, _ in aliases], "ELF alias")
        offsets = [off + va - start for start, off, length in loads if start <= va and va + size <= start + length]
        require(offsets and int(target["file_offset"], 16) in offsets, "PT_LOAD offset")
        body = source[offsets[0]:offsets[0] + size]
        body_hash = hashlib.sha256(body).hexdigest()
        require(len(body) == size and body_hash == target["source_body_sha256"], "original body hash")
        row = raw_rows[i]
        require(row["elf_va"] == target["elf_va"] and row["size_bytes"] == size and row["symbol"] == target["symbol"], "raw target")
        require(int(row["database_va"], 16) == image_base + va and row["source_bytes_match"] is True and row["expected_source_sha256"] == row["ghidra_memory_sha256"] == body_hash, "Ghidra memory/source")
        require(0 <= row["elapsed_ms"] <= 15000, "per-function decompile bound")
        decoded = list(cap.disasm(body, va))
        require(sum(ins.size for ins in decoded) == size, "full source AArch64 decode")
        lookup = {ins.address: ins for ins in decoded}
        listed = row["instructions"]
        require(listed and len(listed) == row["instruction_count_observed"], "listing count")
        addresses = []
        for line in listed:
            match = re.match(r"^([0-9a-fA-F]+):\s+", line)
            require(match is not None, "listing syntax")
            addr = int(match.group(1), 16) - image_base
            require(addr in lookup, "listed instruction aligns with original")
            addresses.append(addr)
        require(addresses == sorted(set(addresses)), "listing order")
        for call in row["calls"]:
            match = re.match(r"^([0-9a-fA-F]+)\s+->\s+", call)
            require(match is not None, "call syntax")
            addr = int(match.group(1), 16) - image_base
            require(addr in lookup and lookup[addr].mnemonic in ("bl", "blr", "b", "br"), "call source opcode")
            metrics["source_call_sites"] += 1
        c = row["pseudocode"]
        require(row["decompile_success"] is True and not row["error"] and c.strip() and "{" in c, "C-like body")
        joined.append(f"/* {SOURCE.name} ELF VA 0x{va:x}; source body SHA-256 {body_hash} */\n" + c + "\n")
        metrics["source_instructions"] += len(decoded)
        metrics["listed_instructions"] += len(listed)
        metrics["full_listings"] += len(listed) == len(decoded)
        metrics["C_like"] += 1
        metrics["C_warnings"] += "WARNING:" in c
        metrics["max_function_elapsed_ms"] = max(metrics["max_function_elapsed_ms"], row["elapsed_ms"])
        if position in sample:
            for record in (verification["records"][position], c_manifest["records"][position]):
                require(record["library"] == SOURCE.name and record["index"] == i and record["elf_va"] == target["elf_va"], "sample identity")
                require(record["source_body_sha256"] == body_hash and record["source_capstone_instructions"] == len(decoded) and record["ghidra_listed_instructions"] == len(listed), "sample source/listing")
                require(record["ghidra_pseudocode_sha256"] == hashlib.sha256(c.encode("utf-8")).hexdigest(), "sample C hash")
    require(metrics["source_instructions"] == verification["source_capstone_instructions"] == 182869, "source instruction total")
    require(metrics["listed_instructions"] == verification["ghidra_listed_source_aligned_instructions"] == 176336, "Ghidra listed total")
    require(metrics["full_listings"] == verification["ghidra_fully_listed_bodies"] == 2759, "full listing count")
    require(metrics["C_like"] == verification["ghidra_c_like_bodies_recovered"] == 3326, "C-like total")
    require("\n".join(joined).encode("utf-8") == (REPORT / "all_recovered_export_pseudocode.c").read_bytes(), "joined C artifact")
    require(digest(seal_path) == seal_hash, "unchanged seal")
    print(json.dumps({"verdict": "INDEPENDENT_PROVENANCE_PASS", "seal_sha256": seal_hash, "report_files": len(actual), "code_files": len(seal["code_files"]), "report_bytes": report_bytes, "export_symbols": 3702, "export_vas": 3326, "Ghidra_chunks": len(run["chunks"]), "ordinary_sample": len(sample), "metrics": dict(metrics), "caveat": "567 partial Ghidra listings; export-only static research; no runtime or device proof"}, indent=2))


if __name__ == "__main__":
    main()
