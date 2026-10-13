"""Read-only independent original-ELF and raw-Ghidra audit for TASK_158."""

import hashlib
import json
import math
import re
from collections import Counter
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_158_REPORT_R1"
SOURCES = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a")
PINNED = {
    "libPVGCodec.so": ("4fa5f275c8ddecf7caa960c812108ec9e801365bfe5bc9cf38598233bc449ffc", 417, 467),
    "libVERenderer.so": ("2da896556822804506871c47fadda3fadf8537952e38642e6c496ccbbab8ca46", 886, 1014),
}


def digest(path):
    h = hashlib.sha256()
    with path.open("rb") as file:
        for block in iter(lambda: file.read(1 << 20), b""):
            h.update(block)
    return h.hexdigest()


def read(path):
    return json.loads(path.read_text(encoding="utf-8"))


def check(ok, why):
    if not ok:
        raise AssertionError(why)


def main():
    check(digest(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") == "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f", "standard")
    check(digest(ROOT / "RULES/TASK/TASK_158_SO45_CODEX_PVG_RENDERER_ACTIVE.md") == "feac7b1bc4c619531ddf1fe70aed04f94b581c6a39e3d290fd6c96ad4e2658c7", "task")
    sealed_path = REPORT / "COMPLETE.json"
    sealed_sha = digest(sealed_path)
    sealed = read(sealed_path)
    check(sealed["task_id"] == "TASK_158" and sealed["revision"] == 1 and sealed["fencing_token"] == 1186, "seal identity")
    names = set(sealed["files"])
    actual = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()} - {"COMPLETE.json", "PROGRESS.json"}
    check(names == actual, "manifest exact set")
    for name, expected in sealed["files"].items():
        check(digest(REPORT / name) == expected, "manifest report hash " + name)
    for name, expected in sealed["code_files"].items():
        check(digest(ROOT / name) == expected, "manifest code hash " + name)
    total_bytes = sum((REPORT / name).stat().st_size for name in names)
    check(total_bytes <= 67_108_864, "report cap")
    batch = read(REPORT / "batch_run_receipt.json")
    check(batch["status"] == "OUTPUT_READY" and len(batch["chunks"]) == 11 and batch["elapsed_seconds"] <= 6600, "batch result")
    check(read(REPORT / "source_batch_index.json")["total_unique_export_vas"] == 1303, "batch index")
    verification = read(REPORT / "independent_verification.json")
    c_manifest = read(REPORT / "source_c_manifest.json")
    check(len(verification["records"]) == len(c_manifest["records"]) == 1303, "record count")
    run = {(x["library"], x["chunk"]): x for x in batch["chunks"]}
    check(len(run) == 11, "unique chunks")
    sample = {round(i * 1302 / 131) for i in range(132)}
    check(len(sample) >= math.ceil(.1 * 1303), "sample size")
    cap = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    metrics = Counter()
    calls = Counter()
    joined_c = []
    global_position = 0
    source_symbols = {}
    for library, (expected_sha, expected_vas, expected_names) in PINNED.items():
        path = SOURCES / library
        check(digest(path) == expected_sha, "source hash " + library)
        source = path.read_bytes()
        index = read(REPORT / library / "target_index.json")
        check(index["source_sha256"] == expected_sha and index["unique_export_vas"] == expected_vas and len(index["targets"]) == expected_vas, "index identity " + library)
        check(index["defined_nonzero_function_symbols"] == expected_names, "index name census")
        with path.open("rb") as stream:
            elf = ELFFile(stream)
            check(elf["e_machine"] == "EM_AARCH64", "machine")
            by_va = {}
            for sym in elf.get_section_by_name(".dynsym").iter_symbols():
                if sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF" and int(sym["st_size"]) > 0 and int(sym["st_value"]) > 0:
                    by_va.setdefault(int(sym["st_value"]), []).append((sym.name, int(sym["st_size"])))
            segments = [(int(s["p_vaddr"]), int(s["p_offset"]), int(s["p_filesz"])) for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
        check(len(by_va) == expected_vas and sum(map(len, by_va.values())) == expected_names, "independent ELF census")
        source_symbols[library] = expected_names
        raw_rows = {}
        base = None
        for position, chunk in enumerate(index["chunks"], start=1):
            n = chunk["chunk"]
            check(n == position and 0 < chunk["count"] <= 128, "chunk order/cap")
            folder = REPORT / library / f"chunk_{n:02d}"
            receipt = read(folder / "ghidra_command.json")
            outcome = run[library, n]
            check(receipt["status"] == outcome["status"] == "OUTPUT_READY" and receipt["exit_code"] == outcome["exit_code"] == 0 and receipt["elapsed_seconds"] <= 900, "chunk success")
            cmd = receipt["command"]
            check(cmd[5:7] == ["-max-cpu", "1"] if n == 1 else cmd[3:9] == ["-process", library, "-noanalysis", "-readOnly", "-max-cpu", "1"], "command bounds")
            check(("-import" in cmd) == (n == 1), "exact one import per SO")
            check(receipt["script_sha256"] == digest(ROOT / "scripts/task158_codex_pvg_renderer/ExportChunk158.java"), "script identity")
            for filename, key in (("targets.tsv", "target_tsv_sha256"), ("ghidra_raw.json", "result_sha256"), ("ghidra_stdout.log", "stdout_sha256"), ("ghidra_stderr.log", "stderr_sha256")):
                check(digest(folder / filename) == receipt[key], "receipt hash " + filename)
            check(digest(folder / "targets.tsv") == chunk["target_tsv_sha256"], "TSV/index hash")
            log = (folder / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace")
            check(f"[TASK_158] processed {chunk['count']}/{chunk['count']}" in log, "Ghidra completion log")
            if n == 1:
                check("REPORT: Import succeeded" in log, "import success log")
            else:
                check("Processing read-only project file" in log, "readonly log")
            raw = read(folder / "ghidra_raw.json")
            check(raw["task_id"] == "TASK_158" and raw["program_name"] == library and len(raw["targets"]) == chunk["count"], "raw identity")
            b = int(raw["image_base"], 16)
            check(base is None or base == b, "image base stability")
            base = b
            expected_indices = list(range(chunk["first_index"], chunk["last_index"] + 1))
            check([x["index"] for x in raw["targets"]] == expected_indices, "raw coverage")
            lines = (folder / "targets.tsv").read_text(encoding="utf-8").splitlines()
            for line, row in zip(lines, raw["targets"]):
                check(line.split("\t", 4) == [str(row["index"]), row["elf_va"], str(row["size_bytes"]), row["expected_source_sha256"], row["symbol"]], "TSV/raw")
                check(row["index"] not in raw_rows, "duplicate raw index")
                raw_rows[row["index"]] = row
        check(set(raw_rows) == set(range(1, expected_vas + 1)), "complete raw target set")
        check((ROOT / f"RESEARCH_WORK/TASK_158_R1/{library}/ghidra_project/Task158.gpr").is_file(), "saved Ghidra project")
        for i, target in enumerate(index["targets"], start=1):
            check(target["index"] == i, "target order")
            va, size = int(target["elf_va"], 16), target["size_bytes"]
            aliases = sorted(by_va[va], key=lambda pair: (-pair[1], pair[0]))
            check((target["symbol"], size) == aliases[0] and target["aliases"] == [x for x, _ in aliases], "source alias")
            offsets = [offset + va - start for start, offset, length in segments if start <= va and va + size <= start + length]
            check(offsets and int(target["file_offset"], 16) in offsets, "PT_LOAD offset")
            body = source[offsets[0]:offsets[0] + size]
            body_sha = hashlib.sha256(body).hexdigest()
            check(len(body) == size and target["source_body_sha256"] == body_sha, "source body")
            row = raw_rows[i]
            check(row["elf_va"] == target["elf_va"] and row["symbol"] == target["symbol"] and row["size_bytes"] == size, "raw body identity")
            check(int(row["database_va"], 16) == base + va and row["source_bytes_match"] is True and row["expected_source_sha256"] == row["ghidra_memory_sha256"] == body_sha, "Ghidra memory/source")
            decoded = list(cap.disasm(body, va))
            lookup = {item.address: item for item in decoded}
            check(sum(item.size for item in decoded) == size, "Capstone full source decode")
            listed = row["instructions"]
            check(len(listed) == row["instruction_count_observed"] and listed, "listing count")
            addrs = []
            for line in listed:
                match = re.match(r"^([0-9a-fA-F]+):\s+", line)
                check(match is not None, "listing parse")
                addr = int(match.group(1), 16) - base
                check(addr in lookup, "listing source alignment")
                addrs.append(addr)
            check(addrs == sorted(set(addrs)), "listing order")
            for call in row["calls"]:
                match = re.match(r"^([0-9a-fA-F]+)\s+->\s+", call)
                check(match is not None, "call parse")
                addr = int(match.group(1), 16) - base
                check(addr in lookup and lookup[addr].mnemonic in ("bl", "blr", "b", "br"), "call source opcode")
                calls[lookup[addr].mnemonic] += 1
            c = row["pseudocode"]
            check(row["decompile_success"] is True and not row["error"] and c.strip() and "{" in c, "nonempty C-like")
            joined_c.append(f"/* {library} ELF VA 0x{va:x}; source body SHA-256 {body_sha} */\n" + c + "\n")
            metrics["source_instructions"] += len(decoded)
            metrics["listed_instructions"] += len(listed)
            metrics["full_listings"] += len(listed) == len(decoded)
            metrics["C_like"] += 1
            metrics["warnings"] += "WARNING:" in c
            record = verification["records"][global_position]
            second = c_manifest["records"][global_position]
            if global_position in sample:
                for observed in (record, second):
                    check(observed["library"] == library and observed["index"] == i and observed["elf_va"] == target["elf_va"], "sample record identity")
                    check(observed["source_body_sha256"] == body_sha and observed["source_capstone_instructions"] == len(decoded) and observed["ghidra_listed_instructions"] == len(listed), "sample coverage")
                    check(observed["ghidra_pseudocode_sha256"] == hashlib.sha256(c.encode("utf-8")).hexdigest(), "sample C hash")
            global_position += 1
    check(global_position == 1303 and metrics["source_instructions"] == verification["source_capstone_instructions"] == 132185, "source instruction total")
    check(metrics["listed_instructions"] == verification["ghidra_listed_source_aligned_instructions"] == 125610, "Ghidra listing total")
    check(metrics["full_listings"] == verification["ghidra_fully_listed_bodies"] == 951, "full listing total")
    check(metrics["C_like"] == verification["ghidra_c_like_bodies_recovered"] == sealed["c_like_bodies_recovered"] == 1303, "C-like total")
    check("\n".join(joined_c).encode("utf-8") == (REPORT / "all_recovered_export_pseudocode.c").read_bytes(), "joined C artifact")
    check(digest(sealed_path) == sealed_sha, "stable seal")
    print(json.dumps({"verdict": "INDEPENDENT_PROVENANCE_PASS", "seal_sha256": sealed_sha,
                      "report_files": len(names), "code_files": len(sealed["code_files"]), "report_bytes": total_bytes,
                      "source_export_symbols": source_symbols, "unique_export_vas": global_position,
                      "Ghidra_chunks": len(run), "ordinary_sample": len(sample),
                      "metrics": dict(metrics), "call_opcodes": dict(calls),
                      "caveat": "352 partial listings; static exports only; no runtime/device proof"}, indent=2))


if __name__ == "__main__":
    main()
