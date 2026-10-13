"""Independent read-only audit of TASK_165's static MTFilter export evidence."""

import hashlib
import json
import math
import re
from collections import Counter
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile


ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_165_REPORT_R1"
TASK = ROOT / "RULES/TASK/TASK_165_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libMTFilterKernel.so")
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
SOURCE_SHA = "f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4"
TASK_SHA = "5adff21b71d60d014f7e85b82fb8a22bd975f22f22fabb46dd0a7e2e4d1388a1"


def sha(path):
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def obj(path):
    return json.loads(path.read_text(encoding="utf-8"))


def require(condition, message):
    if not condition:
        raise AssertionError(message)


def check_command(receipt, task_id, target_file, raw_file, script_file, timeout=900):
    command = receipt["command"]
    require(receipt["task_id"] == task_id and receipt["status"] == "OUTPUT_READY"
            and receipt["exit_code"] == 0 and 0 < receipt["elapsed_seconds"] <= timeout,
            f"{task_id} command outcome")
    require(command[3:9] == ["-process", SOURCE.name, "-noanalysis", "-readOnly", "-max-cpu", "1"]
            and "-import" not in command and Path(command[-2]).name == target_file.name
            and Path(command[-1]).name == raw_file.name,
            f"{task_id} command mode/target")
    require(receipt["target_tsv_sha256"] == sha(target_file) and
            receipt["result_sha256"] == sha(raw_file) and
            receipt["script_sha256"] == sha(script_file), f"{task_id} command input/output hashes")
    for name, key in (("ghidra_stdout.log", "stdout_sha256"), ("ghidra_stderr.log", "stderr_sha256")):
        require(receipt[key] == sha(raw_file.parent / name), f"{task_id} {name} hash")
    log = (raw_file.parent / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace")
    require("Processing read-only project file" in log, f"{task_id} read-only log")


def inspect_row(row, target, body, decoded, image_base):
    va, size = int(target["elf_va"], 16), target["size_bytes"]
    body_sha = hashlib.sha256(body).hexdigest()
    require(row["elf_va"] == target["elf_va"] and row["symbol"] == target["symbol"]
            and row["size_bytes"] == size and int(row["database_va"], 16) == image_base + va
            and row["source_bytes_match"] is True
            and row["expected_source_sha256"] == row["ghidra_memory_sha256"] == body_sha,
            f"Ghidra/source body {target['index']}")
    lookup = {ins.address: ins for ins in decoded}
    require(len(lookup) == len(decoded), f"duplicate decoded instruction {target['index']}")
    addresses = []
    for text in row["instructions"]:
        match = re.match(r"^([0-9a-fA-F]+):\s+", text)
        require(match is not None, f"listing syntax {target['index']}")
        address = int(match.group(1), 16) - image_base
        require(address in lookup, f"listing outside original body {target['index']}")
        addresses.append(address)
    require(addresses and addresses == sorted(set(addresses)) and
            len(addresses) == row["instruction_count_observed"], f"listing count/order {target['index']}")
    flows = Counter()
    for text in row["calls"]:
        match = re.match(r"^([0-9a-fA-F]+)\s+->\s+", text)
        require(match is not None, f"flow syntax {target['index']}")
        address = int(match.group(1), 16) - image_base
        require(address in lookup and lookup[address].mnemonic in ("bl", "blr", "b", "br"),
                f"flow opcode absent from source {target['index']}")
        flows[lookup[address].mnemonic] += 1
    return len(addresses), flows


def main():
    require(sha(STANDARD) == STANDARD_SHA and sha(TASK) == TASK_SHA and sha(SOURCE) == SOURCE_SHA,
            "canonical/task/original SO identity")
    seal_path = REPORT / "COMPLETE.json"
    seal_sha = sha(seal_path)
    seal = obj(seal_path)
    require((seal["task_id"], seal["revision"], seal["status"], seal["fencing_token"]) ==
            ("TASK_165", 1, "COMPLETE", 1194), "seal identity")
    require((seal["standard_sha256"], seal["task_sha256"], seal["source_sha256"]) ==
            (STANDARD_SHA, TASK_SHA, SOURCE_SHA), "seal pinning")
    require(seal["internal_nonexported_functions_covered"] is False and
            seal["semantic_equivalence_proven"] is False and seal["phase_pass"] is False,
            "bounded static scope")
    actual = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()} - {
        "COMPLETE.json", "PROGRESS.json"}
    require(set(seal["files"]) == actual and len(actual) == 76, "exact sealed report inventory")
    for name, expected in seal["files"].items():
        require(sha(REPORT / name) == expected, "report byte hash " + name)
    require(len(seal["code_files"]) == 6, "generator inventory")
    for name, expected in seal["code_files"].items():
        require(sha(ROOT / name) == expected, "generator byte hash " + name)
    report_bytes = sum((REPORT / name).stat().st_size for name in actual)
    require(report_bytes == seal["report_bytes_excluding_seal_and_progress"] and
            report_bytes <= 134217728, "report aggregate byte cap")
    audit = (REPORT / "00_AUDIT_INDEX.md").read_text(encoding="utf-8").lower()
    require(STANDARD_SHA in audit and SOURCE_SHA in audit and TASK_SHA in audit, "audit index pins")

    archive = obj(REPORT / "archive_receipt.json")
    require(archive["fresh_imports_this_revision"] == 0 and
            archive["historical_commands_are_reused_evidence_not_current_execution"] is True and
            len(archive["copied_raw_files"]) == 64, "honest historical provenance")
    for rel, record in archive["copied_raw_files"].items():
        original = Path(record["original_path"])
        copied = REPORT / rel
        require(copied.stat().st_size == original.stat().st_size == record["bytes"] and
                sha(copied) == sha(original) == record["sha256"], "archived raw original " + rel)
    for n, expected in ((151, "c4249e17fcfb59f6101c4cd485d75e6cf3a3b398caea99635aa0704ea56d87f7"),
                        (152, "73a896c3644af66738fd82422d1ef659904df13be8ddf210cd4625b92f858a52")):
        historical = ROOT / f"RULES/REPORT/TASK_{n}_REPORT_R1"
        require(sha(historical / "COMPLETE.json") == sha(REPORT / f"historical_raw/TASK_{n}/COMPLETE.json")
                == expected, f"historical {n} seal identity")
        old_seal = obj(historical / "COMPLETE.json")
        for name, digest in old_seal["files"].items():
            require(sha(historical / name) == digest, f"historical {n} sealed report " + name)
        for name, digest in old_seal["code_files"].items():
            require(sha(ROOT / name) == digest, f"historical {n} sealed code " + name)
    prior_project = Path(archive["prior_project"])
    owned_project = Path(archive["owned_project"])
    require(set(archive["project_file_hashes"]) ==
            {p.relative_to(owned_project).as_posix() for p in owned_project.rglob("*") if p.is_file()},
            "Ghidra project inventory")
    for name, digest in archive["project_file_hashes"].items():
        require(sha(prior_project / name) == sha(owned_project / name) == digest,
                "Ghidra project provenance " + name)

    index = obj(REPORT / "source_index.json")
    old_index = obj(REPORT / "historical_raw/TASK_151/target_index.json")
    verify = obj(REPORT / "independent_verification.json")
    require(index["unique_export_vas"] == old_index["unique_export_vas"] == 2362 and
            index["defined_nonzero_function_symbols"] == 2634 and
            len(index["targets"]) == len(old_index["targets"]) == 2362 and
            len(index["audit_sample_positions"]) == 237 and
            len(verify["ordinary_spread_provenance"]) == 237, "index and spread census")
    sample = sorted({1 + round(i * 2361 / 236) for i in range(237)})
    require(index["audit_sample_positions"] == sample and len(sample) >= math.ceil(2362 * .1),
            "10% evenly spread positions")
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        require(elf["e_machine"] == "EM_AARCH64", "ELF architecture")
        by_va = {}
        for sym in elf.get_section_by_name(".dynsym").iter_symbols():
            if sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF" and int(sym["st_size"]) > 0:
                by_va.setdefault(int(sym["st_value"]), []).append((sym.name, int(sym["st_size"])))
        segments = [{"index": n, "va": int(s["p_vaddr"]), "offset": int(s["p_offset"]),
                     "file_size": int(s["p_filesz"]), "memory_size": int(s["p_memsz"])}
                    for n, s in enumerate(elf.iter_segments()) if s["p_type"] == "PT_LOAD"]
    require(len(by_va) == 2362 and sum(map(len, by_va.values())) == 2634 and
            segments == index["pt_load_segments"], "independent .dynsym/PT_LOAD census")
    source = SOURCE.read_bytes()
    old_rows = {}
    for meta in old_index["chunks"]:
        number = meta["chunk"]
        folder = REPORT / f"historical_raw/TASK_151/chunk_{number:02d}"
        receipt = obj(folder / "ghidra_command.json")
        raw_path = folder / "ghidra_raw.json"
        check_command(receipt, "TASK_151", folder / "targets.tsv", raw_path,
                      ROOT / "scripts/task151_direct_mtfilter/ExportMTFilterChunk151.java")
        require(f"[TASK_151] processed {meta['count']}/{meta['count']}" in
                (folder / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace"),
                "historical chunk completion")
        raw = obj(raw_path)
        require(raw["task_id"] == "TASK_151" and raw["program_name"] == SOURCE.name and
                raw["image_base"] == "0x100000" and len(raw["targets"]) == meta["count"],
                "historical raw chunk identity")
        require([row["index"] for row in raw["targets"]] ==
                list(range(meta["first_index"], meta["last_index"] + 1)), "historical chunk interval")
        tsv = (folder / "targets.tsv").read_text(encoding="utf-8").splitlines()
        require(len(tsv) == meta["count"], "historical target TSV length")
        for row, line in zip(raw["targets"], tsv):
            require(line.split("\t", 4) == [str(row["index"]), row["elf_va"], str(row["size_bytes"]),
                                              row["expected_source_sha256"], row["symbol"]],
                    "historical raw/TSV row")
            require(row["index"] not in old_rows, "historical duplicate row")
            old_rows[row["index"]] = row
    require(set(old_rows) == set(range(1, 2363)), "all 2362 historical rows")
    correction_dir = REPORT / "historical_raw/TASK_152"
    correction_receipt = obj(correction_dir / "ghidra_command.json")
    correction_path = correction_dir / "parseoldfilter_ghidra_raw.json"
    check_command(correction_receipt, "TASK_152", correction_dir / "target.tsv", correction_path,
                  ROOT / "scripts/task152_direct_mtfilter_timeout/ExportMTFilterTimeout152.java")
    correction_raw = obj(correction_path)
    require(correction_raw["task_id"] == "TASK_152" and len(correction_raw["targets"]) == 1 and
            old_rows[1781]["decompile_success"] is False and
            correction_raw["targets"][0]["elf_va"] == "0x1741e4" and
            correction_raw["targets"][0]["decompile_success"] is True and
            15000 < correction_raw["targets"][0]["elapsed_ms"] < 180000,
            "historical long-timeout exception")
    correction = correction_raw["targets"][0]
    require(hashlib.sha256(correction["pseudocode"].encode("utf-8")).hexdigest() ==
            sha(correction_dir / "parseoldfilter_pseudocode.c"), "historical exception C bytes")

    sample_folder = REPORT / "audit_sample"
    sample_receipt = obj(sample_folder / "ghidra_command.json")
    sample_path = sample_folder / "ghidra_raw.json"
    check_command(sample_receipt, "TASK_165", sample_folder / "targets.tsv", sample_path,
                  ROOT / "scripts/task_165_codex_exports/AuditMTFilter165.java")
    require(sample_receipt["fresh_imports_this_revision"] == 0 and
            sample_receipt["fencing_token"] == 1194 and
            sample_receipt["post_project_hashes"] == archive["project_file_hashes"],
            "fresh read-only process/project")
    sampled = obj(sample_path)
    require(sampled["task_id"] == "TASK_165" and sampled["program_name"] == SOURCE.name and
            sampled["image_base"] == "0x100000" and
            [r["index"] for r in sampled["targets"]] == sample, "fresh sample identity")
    sample_rows = {r["index"]: r for r in sampled["targets"]}
    tsv = (sample_folder / "targets.tsv").read_text(encoding="utf-8").splitlines()
    require(len(tsv) == 237, "fresh sample TSV count")
    for row, line in zip(sampled["targets"], tsv):
        require(line.split("\t", 4) == [str(row["index"]), row["elf_va"], str(row["size_bytes"]),
                                          row["expected_source_sha256"], row["symbol"]], "fresh raw/TSV")

    map_rows = [json.loads(line) for line in (REPORT / "export_map.ndjson").read_text(encoding="utf-8").splitlines()]
    require(len(map_rows) == 2362, "export map length")
    cap = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    metrics = Counter()
    for pos, target in enumerate(index["targets"], 1):
        va, size = int(target["elf_va"], 16), target["size_bytes"]
        aliases = sorted(by_va[va], key=lambda pair: (-pair[1], pair[0]))
        require(target["index"] == pos and (target["symbol"], size) == aliases[0] and
                target["aliases"] == [{"name": n, "size_bytes": z} for n, z in aliases],
                f"original symbol/alias {pos}")
        mapped = [(s["index"], s["offset"] + va - s["va"]) for s in segments
                  if s["va"] <= va and va + size <= s["va"] + s["file_size"]]
        require(mapped == [(target["pt_load_segment_index"], int(target["file_offset"], 16))],
                f"original PT_LOAD map {pos}")
        body = source[mapped[0][1]:mapped[0][1] + size]
        require(len(body) == size and hashlib.sha256(body).hexdigest() == target["source_body_sha256"],
                f"original body bytes {pos}")
        decoded = list(cap.disasm(body, va))
        require(sum(ins.size for ins in decoded) == size, f"original AArch64 decode {pos}")
        old = old_rows[pos]
        old_listed, _ = inspect_row(old, target, body, decoded, 0x100000)
        if pos == 1781:
            require(old["decompile_success"] is False and old["pseudocode"] == "", "only prior timeout")
            row = correction
        else:
            require(old["decompile_success"] is True and not old["error"] and old["pseudocode"].strip(),
                    f"historical C-like result {pos}")
            row = old
        listed, flows = inspect_row(row, target, body, decoded, 0x100000)
        c = row["pseudocode"]
        require(row["decompile_success"] is True and not row["error"] and c.strip() and "{" in c,
                f"consolidated C-like result {pos}")
        record = map_rows[pos - 1]
        raw_path = ("historical_raw/TASK_152/parseoldfilter_ghidra_raw.json" if pos == 1781 else
                    f"historical_raw/TASK_151/chunk_{(pos - 1)//256:02d}/ghidra_raw.json")
        c_hash = hashlib.sha256(c.encode("utf-8")).hexdigest()
        require(record["index"] == pos and record["elf_va"] == target["elf_va"] and
                record["symbol"] == target["symbol"] and record["aliases"] == target["aliases"] and
                record["source_body_sha256"] == record["ghidra_memory_sha256"] == target["source_body_sha256"] and
                record["c_like_utf8_sha256"] == c_hash and record["c_like_characters"] == len(c) and
                record["c_warning_present"] == ("WARNING:" in c) and
                record["source_aarch64_instructions"] == len(decoded) and
                record["ghidra_listed_instructions"] == listed and
                record["ghidra_listing_partial"] == (listed != len(decoded)) and
                record["source_aligned_flow_transfers"] == sum(flows.values()) and
                record["raw_ghidra_result"] == raw_path and
                record["historical_decompile_timeout_seconds"] == (180 if pos == 1781 else 15) and
                record["independently_ghidra_resampled_this_revision"] == (pos in sample_rows),
                f"export map provenance {pos}")
        metrics["source_instructions"] += len(decoded)
        metrics["listed_instructions"] += listed
        metrics["partial_listings"] += listed != len(decoded)
        metrics["warnings"] += "WARNING:" in c
        metrics["flow"] += sum(flows.values())
        metrics["C_like"] += 1
        if pos in sample_rows:
            fresh = sample_rows[pos]
            require(fresh["index"] == pos and fresh["decompile_success"] is True and
                    not fresh["error"] and 0 <= fresh["elapsed_ms"] <= 15000,
                    f"fresh bounded decompilation {pos}")
            fresh_listed, fresh_flows = inspect_row(fresh, target, body, decoded, 0x100000)
            require(hashlib.sha256(fresh["pseudocode"].encode("utf-8")).hexdigest() == c_hash,
                    f"fresh versus historical C hash {pos}")
            v = verify["ordinary_spread_provenance"][sample.index(pos)]
            require(v["index"] == pos and v["source_body_sha256"] == target["source_body_sha256"] and
                    v["fresh_ghidra_memory_sha256"] == target["source_body_sha256"] and
                    v["fresh_c_like_recovered"] is True and
                    v["fresh_listed_source_aligned_instructions"] == fresh_listed and
                    v["fresh_flow_transfers_source_aligned"] == sum(fresh_flows.values()) and
                    v["fresh_historical_c_utf8_equal"] is True, f"ordinary spread record {pos}")
            metrics["sample"] += 1
    require(metrics == Counter({"source_instructions": 170169, "listed_instructions": 161064,
                                "partial_listings": 422, "warnings": 678, "flow": 13975,
                                "C_like": 2362, "sample": 237}), "independent aggregate metrics")
    require(verify["original_aarch64_instructions"] == metrics["source_instructions"] and
            verify["historical_listed_source_aligned_instructions"] == metrics["listed_instructions"] and
            verify["historical_partial_instruction_listings"] == metrics["partial_listings"] and
            verify["historical_c_bodies_with_warnings"] == metrics["warnings"] and
            verify["historical_source_aligned_flow_transfers"] == metrics["flow"] and
            verify["consolidated_c_like_bodies"] == metrics["C_like"] and
            verify["current_task_spread_c_text_equal"] == metrics["sample"] and
            verify["current_task_fresh_imports"] == 0 and verify["unresolved_count"] == 0 and
            obj(REPORT / "unresolved.json")["rows"] == [], "verification claims")
    require(sha(seal_path) == seal_sha, "stable sealed snapshot")
    print(json.dumps({"verdict": "INDEPENDENT_STATIC_PROVENANCE_PASS", "seal_sha256": seal_sha,
                      "report_files": len(actual), "code_files": len(seal["code_files"]),
                      "report_bytes": report_bytes, "export_names": 2634, "export_vas": 2362,
                      "ordinary_sample": metrics["sample"], "metrics": dict(metrics),
                      "limitation": "historical 180s exception; 422 partial listings; 678 warnings; export-only"}, indent=2))


if __name__ == "__main__":
    main()
