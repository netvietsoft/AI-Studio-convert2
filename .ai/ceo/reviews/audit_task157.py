"""Independent, read-only CEO audit of TASK_157's pinned research package."""

import hashlib
import json
import math
import re
from collections import Counter
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile


ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_157_REPORT_R1"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libAIModelSearchKit.so")
TASK = ROOT / "RULES/TASK/TASK_157_SO45_CODEX_AIMODELSEARCH_ACTIVE.md"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
SOURCE_SHA = "20233f05b4b010280d16e728103a0995ca2580697b5f9c708fa333e9ff8d1899"
TASK_SHA = "4ebb0377a70634ca1d92a1f46aa2ded23c405af7fa629a48d431eb49c646a34d"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"


def digest(path):
    h = hashlib.sha256()
    with path.open("rb") as file:
        for block in iter(lambda: file.read(1 << 20), b""):
            h.update(block)
    return h.hexdigest()


def read_json(path):
    return json.loads(path.read_text(encoding="utf-8"))


def insist(condition, message):
    if not condition:
        raise AssertionError(message)


def main():
    insist(digest(STANDARD) == STANDARD_SHA, "canonical hash")
    insist(digest(TASK) == TASK_SHA, "task hash")
    insist(digest(SOURCE) == SOURCE_SHA, "original source hash")
    completed_path = REPORT / "COMPLETE.json"
    first_complete_hash = digest(completed_path)
    completed = read_json(completed_path)
    index = read_json(REPORT / "target_index.json")
    worker = read_json(REPORT / "worker_source_verification.json")
    batch = read_json(REPORT / "batch_run_receipt.json")
    import_receipt = read_json(REPORT / "ghidra_import_command.json")
    insist(completed["task_id"] == "TASK_157" and completed["revision"] == 1, "manifest task")
    insist(completed["source_sha256"] == SOURCE_SHA and completed["task_sha256"] == TASK_SHA, "manifest identities")
    insist(completed["lease_id"] == "LEASE-CEO-WORKER-TASK_157-R1" and completed["fencing_token"] == 1185, "manifest lease")
    manifest_names = set(completed["files"])
    observed_names = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()} - {"COMPLETE.json", "PROGRESS.json"}
    insist(manifest_names == observed_names, "report manifest exact file set")
    for name, expected in completed["files"].items():
        insist(digest(REPORT / name) == expected, "report file hash " + name)
    for name, expected in completed["code_files"].items():
        insist(digest(ROOT / name) == expected, "code file hash " + name)
    report_size = sum((REPORT / name).stat().st_size for name in manifest_names)
    insist(report_size <= 67_108_864, "report size")

    insist(index["task_id"] == "TASK_157" and index["source_sha256"] == SOURCE_SHA, "target index identity")
    insist(len(index["targets"]) == 1231 and len(index["chunks"]) == 5, "target census")
    insist(batch["status"] == "OUTPUT_READY" and len(batch["chunks"]) == 5, "batch receipt")
    insist(import_receipt["status"] == "PROJECT_READY" and import_receipt["exit_code"] == 0, "import receipt")
    insist(import_receipt["command"].count("-import") == 1 and import_receipt["command"][4].replace("\\", "/").lower() == str(SOURCE).replace("\\", "/").lower(), "one import command")
    insist(import_receipt["command"][5:7] == ["-max-cpu", "1"], "import cpu")
    insist(import_receipt["elapsed_seconds"] <= 900, "import cap")
    for stream in ("stdout", "stderr"):
        insist(digest(REPORT / ("ghidra_import_" + stream + ".log")) == import_receipt[stream + "_sha256"], "import log hash")
    import_log = (REPORT / "ghidra_import_stdout.log").read_text(encoding="utf-8", errors="replace")
    insist("IMPORTING:" in import_log and "libAIModelSearchKit.so" in import_log and "REPORT: Import succeeded" in import_log, "import log source")
    project = ROOT / "RESEARCH_WORK/TASK_157_R1/ghidra_project"
    inventory = read_json(REPORT / "project_inventory.json")
    for name, expected in inventory["files"].items():
        insist(digest(project / name) == expected, "project file hash " + name)
    insist(set(inventory["files"]) == {p.relative_to(project).as_posix() for p in project.rglob("*") if p.is_file()}, "project file set")

    raw = {}
    image_bases = set()
    for n, meta in enumerate(index["chunks"]):
        insist(meta["chunk"] == n and meta["count"] <= 256, "chunk order or cap")
        folder = REPORT / f"chunk_{n:02d}"
        receipt = read_json(folder / "ghidra_command.json")
        outcome = batch["chunks"][n]
        insist(outcome["chunk"] == n and outcome["status"] == "OUTPUT_READY" and outcome["exit_code"] == 0, "batch chunk receipt")
        insist(receipt["status"] == "OUTPUT_READY" and receipt["exit_code"] == 0 and receipt["elapsed_seconds"] <= 900, "raw chunk receipt")
        cmd = receipt["command"]
        insist(cmd[3:9] == ["-process", SOURCE.name, "-noanalysis", "-readOnly", "-max-cpu", "1"], "readonly/cpu command")
        insist("-import" not in cmd and cmd[11:13] == ["-postScript", "ExportAIModelSearchChunk157.java"], "script command")
        for name, key in (("targets.tsv", "target_tsv_sha256"), ("ghidra_raw.json", "result_sha256"), ("ghidra_stdout.log", "stdout_sha256"), ("ghidra_stderr.log", "stderr_sha256")):
            insist(digest(folder / name) == receipt[key], "chunk receipt hash " + name)
        insist(digest(folder / "targets.tsv") == meta["target_tsv_sha256"], "target TSV hash")
        log = (folder / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace")
        insist(f"[TASK_157] processed {meta['count']}/{meta['count']}" in log and "Processing read-only project file" in log, "chunk log completed")
        data = read_json(folder / "ghidra_raw.json")
        insist(data["task_id"] == "TASK_157" and data["program_name"] == SOURCE.name, "raw identity")
        insist(len(data["targets"]) == meta["count"], "raw count")
        expected_indices = list(range(meta["first_index"], meta["last_index"] + 1))
        insist([row["index"] for row in data["targets"]] == expected_indices, "raw index continuity")
        tsv = (folder / "targets.tsv").read_text(encoding="utf-8").splitlines()
        insist(len(tsv) == meta["count"], "TSV count")
        image_base = int(data["image_base"], 16)
        image_bases.add(image_base)
        for row, line in zip(data["targets"], tsv):
            insist(row["index"] not in raw, "duplicate raw target")
            fields = line.split("\t", 4)
            insist(fields == [str(row["index"]), row["elf_va"], str(row["size_bytes"]), row["expected_source_sha256"], row["symbol"]], "TSV/raw row")
            raw[row["index"]] = row
    insist(set(raw) == set(range(1, 1232)) and len(image_bases) == 1, "raw coverage/image base")
    image_base = next(iter(image_bases))

    source = SOURCE.read_bytes()
    with SOURCE.open("rb") as file:
        elf = ELFFile(file)
        insist(elf["e_machine"] == "EM_AARCH64", "machine")
        dynsym = elf.get_section_by_name(".dynsym")
        by_va = {}
        for sym in dynsym.iter_symbols():
            if sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF" and int(sym["st_size"]) > 0 and int(sym["st_value"]) > 0:
                by_va.setdefault(int(sym["st_value"]), []).append((sym.name, int(sym["st_size"])))
        insist(sum(map(len, by_va.values())) == 1412 and len(by_va) == 1231, "independent ELF census")
        segments = [(int(s["p_vaddr"]), int(s["p_offset"]), int(s["p_filesz"])) for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
    cap = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    sample = {round(i * 1230 / 123) + 1 for i in range(124)}
    insist(len(sample) >= math.ceil(1231 * .1), "ordinary sample")
    stats = Counter()
    transfers = Counter()
    worker_records = worker["records"]
    insist(len(worker_records) == 1231, "worker record count")
    for n, target in enumerate(index["targets"], start=1):
        insist(target["index"] == n, "target index")
        va, size = int(target["elf_va"], 16), target["size_bytes"]
        aliases = sorted(by_va[va], key=lambda x: (-x[1], x[0]))
        insist((target["symbol"], size) == aliases[0] and target["aliases"] == [x for x, _ in aliases], "ELF name/aliases")
        candidates = [offset + va - base for base, offset, length in segments if base <= va and va + size <= base + length]
        insist(len(candidates) >= 1 and int(target["file_offset"], 16) in candidates, "PT_LOAD mapping")
        body = source[candidates[0]:candidates[0] + size]
        sha = hashlib.sha256(body).hexdigest()
        insist(len(body) == size and target["source_body_sha256"] == sha, "source body hash")
        row = raw[n]
        insist(row["elf_va"] == target["elf_va"] and row["symbol"] == target["symbol"] and row["size_bytes"] == size, "raw target identity")
        insist(int(row["database_va"], 16) == image_base + va and row["expected_source_sha256"] == sha and row["ghidra_memory_sha256"] == sha and row["source_bytes_match"] is True, "Ghidra memory/source")
        instructions = list(cap.disasm(body, va))
        by_address = {i.address: i for i in instructions}
        insist(sum(i.size for i in instructions) == size, "source full Capstone decode")
        listed = row["instructions"]
        insist(len(listed) == row["instruction_count_observed"] and listed, "Ghidra listing count")
        addresses = []
        for line in listed:
            match = re.match(r"^([0-9a-fA-F]+):\s+", line)
            insist(match is not None, "listing parse")
            addr = int(match.group(1), 16) - image_base
            insist(addr in by_address, "listing source alignment")
            addresses.append(addr)
        insist(addresses == sorted(set(addresses)), "listing order/duplicates")
        for call in row["calls"]:
            match = re.match(r"^([0-9a-fA-F]+)\s+->\s+", call)
            insist(match is not None, "call parse")
            addr = int(match.group(1), 16) - image_base
            insist(addr in by_address and by_address[addr].mnemonic in ("bl", "blr", "b", "br"), "call source opcode")
            transfers[by_address[addr].mnemonic] += 1
        c = row["pseudocode"]
        insist(row["decompile_success"] is True and not row["error"] and c.strip() and "{" in c, "nonempty C-like body")
        stats["source_instructions"] += len(instructions)
        stats["listed_instructions"] += len(listed)
        stats["fully_listed"] += len(listed) == len(instructions)
        stats["warning_bodies"] += "WARNING:" in c
        stats["c_like"] += 1
        record = worker_records[n - 1]
        if n in sample:
            insist(record["index"] == n and record["source_body_sha256"] == sha and record["size_bytes"] == size, "ordinary worker/source record")
            insist(record["source_capstone_instructions"] == len(instructions) and record["ghidra_listed_instructions"] == len(listed), "ordinary coverage record")
            insist(record["ghidra_c_like_characters"] == len(c) and record["ghidra_c_warning_present"] == ("WARNING:" in c), "ordinary C record")
    expected = {"source_instructions": worker["source_capstone_instructions"], "listed_instructions": worker["ghidra_listed_source_aligned_instructions"], "fully_listed": worker["ghidra_fully_listed_bodies"], "warning_bodies": worker["c_bodies_with_warnings"], "c_like": worker["ghidra_c_like_bodies_recovered"]}
    insist(dict(stats) == expected, "worker summary metrics")
    insist(dict(transfers) == {k: v for k, v in worker["ghidra_flow_transfer_source_opcode_counts"].items() if v}, "flow summary")
    insist(completed["source_bodies_rehashed"] == 1231 and completed["c_like_bodies_recovered"] == 1231, "manifest metrics")
    insist(digest(completed_path) == first_complete_hash, "stable manifest snapshot")
    print(json.dumps({"verdict": "INDEPENDENT_PROVENANCE_PASS", "manifest_sha256": first_complete_hash, "manifest_files": len(manifest_names), "code_files": len(completed["code_files"]), "report_bytes": report_size, "source_symbols": 1412, "unique_export_vas": 1231, "ghidra_chunks": 5, "ordinary_sample": len(sample), "metrics": dict(stats), "source_transfer_counts": dict(transfers), "caveat": "No internal-function or runtime-semantic verification"}, indent=2))


if __name__ == "__main__":
    main()
