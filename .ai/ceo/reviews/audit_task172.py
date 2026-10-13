"""Independent source/Ghidra/provenance audit of TASK_172 static exports."""

import hashlib
import json
import math
import re
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile

ROOT = Path("F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2")
REPORT = ROOT / "RULES/REPORT/TASK_172_REPORT_R1"
TASK = ROOT / "RULES/TASK/TASK_172_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libc++_shared.so")
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
TASK_SHA = "3775de89c39f68ee6ff5f3c5c3f38517f48fb537f58dcffaa103fc4769a65bb9"
SOURCE_SHA = "4397241b4bd20a8e579bfb41d21107857e12985f6a01ca0c2a5f83380d1270b4"


def sha(path):
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1 << 20), b""):
            h.update(block)
    return h.hexdigest()


def read(path):
    return json.loads(path.read_text(encoding="utf-8"))


def ck(ok, description):
    if not ok:
        raise AssertionError(description)


def stamp(value):
    return datetime.fromisoformat(value.replace("Z", "+00:00"))


def main():
    ck((sha(STANDARD), sha(TASK), sha(SOURCE)) == (STANDARD_SHA, TASK_SHA, SOURCE_SHA),
       "pinned canonical/task/source")
    seal_path = REPORT / "COMPLETE.json"
    ck((datetime.now(timezone.utc) - datetime.fromtimestamp(seal_path.stat().st_mtime, timezone.utc)).total_seconds() >= 60,
       "seal must be stable for sixty seconds")
    before = sha(seal_path)
    seal = read(seal_path)
    ck((seal["task_id"], seal["revision"], seal["status"], seal["semantic_disposition"],
        seal["fencing_token"], seal["execution_mode"]) ==
       ("TASK_172", 1, "COMPLETE", "BOUNDED_RESEARCH_CANDIDATE", 1201,
        "REAL_CODEX_SUBAGENT_NO_AGY") and seal["standard_sha256"] == STANDARD_SHA and
       seal["task_sha256"] == TASK_SHA and seal["source_sha256"] == SOURCE_SHA and
       seal["internal_nonexported_functions_covered"] is False and
       seal["runtime_or_pixel_semantics_proven"] is False, "bounded seal identity")
    files = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()}
    files -= {"COMPLETE.json", "PROGRESS.json"}
    ck(files == set(seal["files"]) and len(files) == 39 and len(seal["code_files"]) == 5,
       "manifest extent")
    ck(sum((REPORT / rel).stat().st_size for rel in files) <= 134217728, "report byte budget")
    for rel, expected in seal["files"].items():
        ck(sha(REPORT / rel) == expected, "report hash " + rel)
    code_text = {}
    for rel, expected in seal["code_files"].items():
        path = ROOT / rel
        ck(sha(path) == expected, "code hash " + rel)
        code_text[rel] = path.read_text(encoding="utf-8")
    java = next(value for key, value in code_text.items() if key.endswith(".java"))
    ck("currentProgram.getMemory().getBytes(address, raw)" in java and
       "actualSha.equalsIgnoreCase(target.expectedSha)" in java and
       "decomp.decompileFunction(function, 15, monitor)" in java and
       "targets.size() > 256" in java, "referenced exporter source inspected")
    audit = (REPORT / "00_AUDIT_INDEX.md").read_text(encoding="utf-8").lower()
    master = (REPORT / "01_MASTER_REPORT.md").read_text(encoding="utf-8")
    ck(STANDARD_SHA in audit and TASK_SHA in audit and SOURCE_SHA in audit and
       "1,376" in master and "internal" in master.lower(), "full audit/master report")
    index = read(REPORT / "target_index.json")
    batch = read(REPORT / "batch_run_receipt.json")
    verifier = read(REPORT / "worker_source_verification.json")
    project = read(REPORT / "project_inventory.json")
    imp = read(REPORT / "ghidra_import_command.json")
    ck(index["unique_export_vas"] == len(index["targets"]) == 1376 and
       index["defined_nonzero_function_symbols"] == 1582 and
       len(index["chunks"]) == len(batch["chunks"]) == 6 and
       batch["status"] == "OUTPUT_READY" and batch["elapsed_seconds"] <= 6600 and
       verifier["source_bodies_rehashed"] == 1376 and len(verifier["records"]) == 1376,
       "report index/batch/verifier")
    ck(imp["status"] == "PROJECT_READY" and imp["exit_code"] == 0 and
       imp["source_sha256"] == SOURCE_SHA and imp["fencing_token"] == 1201 and
       imp["command"].count("-import") == 1 and
       imp["command"][imp["command"].index("-max-cpu") + 1] == "1" and
       imp["command"][imp["command"].index("-import") + 1].replace("\\", "/") == SOURCE.as_posix() and
       "REPORT: Import succeeded" in (REPORT / "ghidra_import_stdout.log").read_text(encoding="utf-8", errors="replace"),
       "one fresh original-source import")
    for filename, key in (("ghidra_import_stdout.log", "stdout_sha256"),
                          ("ghidra_import_stderr.log", "stderr_sha256")):
        ck(sha(REPORT / filename) == imp[key], "import log hash")
    project_root = Path(project["project_root"])
    for rel, expected in project["files"].items():
        ck(sha(project_root / rel) == expected, "analyzed project bytes " + rel)
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        ck(elf["e_machine"] == "EM_AARCH64", "original AArch64")
        by_va = {}
        for sym in elf.get_section_by_name(".dynsym").iter_symbols():
            if sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF" and \
                    int(sym["st_value"]) and int(sym["st_size"]):
                by_va.setdefault(int(sym["st_value"]), []).append((sym.name, int(sym["st_size"])))
        loads = [(int(seg["p_vaddr"]), int(seg["p_offset"]), int(seg["p_filesz"]))
                 for seg in elf.iter_segments() if seg["p_type"] == "PT_LOAD"]
    ck(len(by_va) == 1376 and sum(map(len, by_va.values())) == 1582 and
       [int(t["elf_va"], 16) for t in index["targets"]] == sorted(by_va),
       "independent original .dynsym census")
    raw_rows = {}
    previous_end = stamp(imp["ended_at"])
    bases = set()
    script_sha = sha(ROOT / "scripts/task_172_codex_exports/ExportCppSharedChunk172.java")
    for meta in index["chunks"]:
        number = meta["chunk"]
        chunk = REPORT / f"chunk_{number:02d}"
        receipt = read(chunk / "ghidra_command.json")
        raw = read(chunk / "ghidra_raw.json")
        outcome = batch["chunks"][number]
        ck(meta["count"] <= 256 and meta["last_index"] - meta["first_index"] + 1 == meta["count"] and
           number == outcome["chunk"] == receipt["chunk"] and
           outcome["status"] == receipt["status"] == "OUTPUT_READY" and
           receipt["exit_code"] == outcome["exit_code"] == 0 and
           receipt["source_sha256"] == SOURCE_SHA and receipt["script_sha256"] == script_sha and
           receipt["target_tsv_sha256"] == meta["target_tsv_sha256"] and
           receipt["fencing_token"] == 1201 and 0 < receipt["elapsed_seconds"] <= 900 and
           stamp(receipt["started_at"]) >= previous_end,
           f"bounded sequential chunk {number}")
        previous_end = stamp(receipt["ended_at"])
        cmd = receipt["command"]
        ck("-process" in cmd and "-readOnly" in cmd and "-noanalysis" in cmd and
           "-import" not in cmd and cmd[cmd.index("-max-cpu") + 1] == "1" and
           cmd[cmd.index("-postScript") + 1] == "ExportCppSharedChunk172.java", "read-only chunk command")
        for filename, key in (("targets.tsv", "target_tsv_sha256"),
                              ("ghidra_raw.json", "result_sha256"),
                              ("ghidra_stdout.log", "stdout_sha256"),
                              ("ghidra_stderr.log", "stderr_sha256")):
            ck(sha(chunk / filename) == receipt[key], f"chunk {number} {filename}")
        log = (chunk / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace")
        ck(f"[TASK_172] processed {meta['count']}/{meta['count']}" in log, "Ghidra progress log")
        ck(raw["task_id"] == "TASK_172" and raw["program_name"] == "libc++_shared.so" and
           [r["index"] for r in raw["targets"]] == list(range(meta["first_index"], meta["last_index"] + 1)),
           "raw result extent")
        bases.add(int(raw["image_base"], 16))
        subset = index["targets"][meta["first_index"] - 1:meta["last_index"]]
        tsv = (chunk / "targets.tsv").read_text(encoding="utf-8").splitlines()
        ck(len(tsv) == len(subset), "TSV count")
        for target, row, line in zip(subset, raw["targets"], tsv):
            ck(line.split("\t", 4) == [str(target["index"]), target["elf_va"],
               str(target["size_bytes"]), target["source_body_sha256"], target["symbol"]] and
               row["index"] not in raw_rows, "TSV/raw target")
            raw_rows[row["index"]] = row
    ck(len(bases) == 1 and set(raw_rows) == set(range(1, 1377)), "all raw rows one image base")
    base = next(iter(bases))
    cap = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    original = SOURCE.read_bytes()
    totals = Counter()
    independent_records = []
    spread = {1 + round(i * 1375 / 137) for i in range(138)}
    ck(len(spread) == 138, "spread ordinary sample size")
    for position, target in enumerate(index["targets"], 1):
        va, size = int(target["elf_va"], 16), target["size_bytes"]
        aliases = sorted(by_va[va], key=lambda pair: (-pair[1], pair[0]))
        ck(target["index"] == position and (target["symbol"], size) == aliases[0] and
           target["aliases"] == [name for name, _ in aliases], f"source symbol {position}")
        offsets = [offset + va - start for start, offset, file_size in loads
                   if start <= va and va + size <= start + file_size]
        ck(len(offsets) == 1 and target["file_offset"] == f"0x{offsets[0]:x}",
           f"PT_LOAD mapping {position}")
        body = original[offsets[0]:offsets[0] + size]
        digest = hashlib.sha256(body).hexdigest()
        ck(len(body) == size and digest == target["source_body_sha256"], f"source body {position}")
        decoded = list(cap.disasm(body, va))
        ck(sum(instruction.size for instruction in decoded) == size, f"complete source decode {position}")
        opcode_by_address = {instruction.address: instruction.mnemonic for instruction in decoded}
        row = raw_rows[position]
        ck(row["index"] == position and row["elf_va"] == target["elf_va"] and
           row["symbol"] == target["symbol"] and row["size_bytes"] == size and
           int(row["database_va"], 16) == base + va and row["source_bytes_match"] is True and
           row["expected_source_sha256"] == row["ghidra_memory_sha256"] == digest and
           row["decompile_success"] is True and bool(row["pseudocode"].strip()) and
           not row["error"] and 0 <= row["elapsed_ms"] <= 15000,
           f"Ghidra memory/decompile {position}")
        addresses = []
        for item in row["instructions"]:
            match = re.match(r"^([0-9a-fA-F]+):\s+", item)
            ck(match is not None, "Ghidra instruction syntax")
            addresses.append(int(match.group(1), 16) - base)
        ck(addresses and addresses == sorted(set(addresses)) and
           len(addresses) == row["instruction_count_observed"] and
           all(address in opcode_by_address for address in addresses),
           f"Ghidra-listed source instructions {position}")
        for item in row["calls"]:
            match = re.match(r"^([0-9a-fA-F]+)\s+->\s+", item)
            ck(match is not None, "Ghidra call syntax")
            call_va = int(match.group(1), 16) - base
            ck(opcode_by_address.get(call_va) in ("bl", "blr", "b", "br"),
               f"Ghidra-listed call source opcode {position}")
        record = {"index": position, "elf_va": target["elf_va"], "symbol": target["symbol"],
                  "size_bytes": size, "source_body_sha256": digest,
                  "source_capstone_instructions": len(decoded), "source_fully_decoded": True,
                  "ghidra_listed_instructions": len(addresses),
                  "ghidra_flow_transfers_source_verified": len(row["calls"]),
                  "ghidra_c_like_recovered": True,
                  "ghidra_c_like_characters": len(row["pseudocode"]),
                  "ghidra_c_warning_present": "WARNING:" in row["pseudocode"]}
        ck(record == verifier["records"][position - 1], f"independent verifier record {position}")
        independent_records.append(record)
        totals["instructions"] += len(decoded)
        totals["listed"] += len(addresses)
        totals["fully_listed"] += len(decoded) == len(addresses)
        totals["warnings"] += record["ghidra_c_warning_present"]
        totals["calls"] += len(row["calls"])
        if position in spread:
            with SOURCE.open("rb") as stream:
                stream.seek(offsets[0])
                ck(hashlib.sha256(stream.read(size)).hexdigest() == digest ==
                   row["ghidra_memory_sha256"], f"second source read {position}")
    ck(totals["instructions"] == verifier["source_capstone_instructions"] == 61395 and
       totals["listed"] == verifier["ghidra_listed_source_aligned_instructions"] == 56503 and
       totals["fully_listed"] == verifier["ghidra_fully_listed_bodies"] == 1033 and
       totals["warnings"] == verifier["c_bodies_with_warnings"] == 317 and
       totals["calls"] == sum(verifier["ghidra_flow_transfer_source_opcode_counts"].values()),
       "independent aggregate totals")
    ck(seal["source_bodies_rehashed"] == seal["c_like_bodies_recovered"] == 1376 and
       seal["unrecovered_c_like_vas"] == [] and
       seal["ordinary_records_independently_rechecked"] == 138 and
       seal["ordinary_records_total"] == 1376, "seal coverage claims")
    ck(sha(seal_path) == before, "stable final fingerprint")
    print(json.dumps({"status": "INDEPENDENT_AUDIT_PASS", "task": "TASK_172",
                      "fingerprint": before, "source_bodies": 1376,
                      "c_like_bodies": 1376, "spread_rechecks": len(spread),
                      "fully_listed": totals["fully_listed"], "partial_listings": 1376 - totals["fully_listed"],
                      "c_warnings": totals["warnings"], "report_files": len(files),
                      "code_files": len(code_text)}, ensure_ascii=False))


if __name__ == "__main__":
    main()
