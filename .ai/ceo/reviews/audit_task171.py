"""Independent CEO audit of TASK_171's five historical raw SO export maps."""

import hashlib
import json
import math
import re
from collections import Counter
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile

ROOT = Path("F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2")
REPORT = ROOT / "RULES/REPORT/TASK_171_REPORT_R1"
TASK = ROOT / "RULES/TASK/TASK_171_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
SOURCE_DIR = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a")
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
TASK_SHA = "e85eb5e0d2c82135f8af7e2c500e365a346630c9aa4c7bddcdd2fed5413cc6f5"
SOURCES = {
    "libARSPM.so": ("ec420f2eec97cf2debbf4778045cfd0ac08b78eae656a4f90e282d49b3ef0114", 56, "TASK_155"),
    "libPVGLive.so": ("e443f6a16cb8137d74a1583529666eb02bf4859b372175e2b4c226f6e188484c", 20, "TASK_149"),
    "libCtaApiLib.so": ("4a91ccac45408daa30e8dd60f7c6eee68aeffbdd66e1e9b6e435b1aa3377fcd5", 146, "TASK_153"),
    "libKKMusicFX.so": ("cd876a2e49a129b1bcefdc4aca42047faa4aaf954c6c1286edb80209ac38031d", 57, "TASK_153"),
    "libffavc.so": ("1e214164a6c153f74f25018c1625f3e71d1d5ba601f6592c4dd89385dcc4b0bc", 2, "TASK_149"),
}


def sha(path):
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1 << 20), b""):
            h.update(block)
    return h.hexdigest()


def read(path):
    return json.loads(path.read_text(encoding="utf-8"))


def ck(ok, message):
    if not ok:
        raise AssertionError(message)


def spread(count):
    take = math.ceil(count * .1)
    if take <= 1:
        return {1, count} if count > 1 else {1}
    return {1 + round(i * (count - 1) / (take - 1)) for i in range(take)}


def main():
    ck(sha(STANDARD) == STANDARD_SHA and sha(TASK) == TASK_SHA, "standard/task")
    seal_path = REPORT / "COMPLETE.json"
    seal_sha = sha(seal_path)
    seal = read(seal_path)
    ck((seal["task_id"], seal["revision"], seal["status"], seal["semantic_disposition"],
        seal["fencing_token"], seal["execution_mode"]) ==
       ("TASK_171", 1, "COMPLETE", "BOUNDED_EXPORT_CANDIDATE", 1200,
        "CODEX_SUBAGENT_NO_AGY") and
       seal["standard_sha256"] == STANDARD_SHA and seal["task_sha256"] == TASK_SHA and
       seal["fresh_imports"] == 0 and seal["internal_nonexported_functions_covered"] is False and
       seal["semantic_equivalence_proven"] is False and seal["phase_pass"] is False,
       "bounded seal")
    files = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()}
    files -= {"COMPLETE.json", "PROGRESS.json"}
    ck(files == set(seal["files"]) and len(files) == 52 and len(seal["code_files"]) == 3,
       "manifest exact extent")
    for rel, expected in seal["files"].items():
        ck(sha(REPORT / rel) == expected, "report file " + rel)
    for rel, expected in seal["code_files"].items():
        ck(sha(ROOT / rel) == expected, "code file " + rel)
    ck(sum((REPORT / rel).stat().st_size for rel in files) ==
       seal["report_bytes_excluding_seal_and_progress"] == 4026055, "report byte count")
    audit = (REPORT / "00_AUDIT_INDEX.md").read_text(encoding="utf-8").lower()
    ck(STANDARD_SHA in audit and TASK_SHA in audit, "audit standard/task")
    archive = read(REPORT / "historical_archive_receipt.json")
    source_batch = read(REPORT / "source_batch_index.json")
    verify = read(REPORT / "independent_verification.json")
    export_map = [json.loads(line) for line in
                  (REPORT / "export_map.ndjson").read_text(encoding="utf-8").splitlines()]
    ck(archive["historical_commands_are_reused_evidence_not_current_execution"] is True and
       source_batch["total_export_vas"] == len(export_map) == 281 and
       len(source_batch["libraries"]) == 5, "five-source historical aggregate")
    cap = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    cap.skipdata = True
    expected_map = []
    samples = []
    totals = Counter()
    for name, (source_sha, count, prior_task) in SOURCES.items():
        source = SOURCE_DIR / name
        folder = REPORT / name
        index = read(folder / "source_index.json")
        old_folder = folder / "historical_raw"
        item = archive["sources"][name]
        old_seal = read(old_folder / "COMPLETE.json")
        ck(sha(source) == source_sha and
           index["source_sha256"] == source_sha and index["source_file_size"] == source.stat().st_size and
           index["unique_export_vas"] == len(index["targets"]) == count and
           item["prior_task"] == old_seal["task_id"] == prior_task and
           old_seal["status"] == "COMPLETE" and
           sha(old_folder / "COMPLETE.json") == item["seal_sha256"], name + " original/archive identity")
        historical_root = ROOT / "RULES/REPORT" / f"{prior_task}_REPORT_R1"
        ck(sha(historical_root / "COMPLETE.json") == item["seal_sha256"], name + " original old seal")
        for rel, expected in old_seal["files"].items():
            ck(sha(historical_root / rel) == expected, name + " old sealed file " + rel)
        for rel, expected in old_seal["code_files"].items():
            ck(sha(ROOT / rel) == expected, name + " old sealed code " + rel)
        for filename, meta in item["copied_raw_files"].items():
            ck(sha(old_folder / filename) == sha(Path(meta["original"])) == meta["sha256"] and
               (old_folder / filename).stat().st_size == meta["bytes"],
               name + " old raw copy " + filename)
        old_index = read(old_folder / "target_index.json")
        rec = read(old_folder / "ghidra_command.json")
        raw = read(old_folder / "ghidra_raw.json")
        ck(old_index["source_sha256"] == source_sha and len(old_index["targets"]) == count and
           rec["task_id"] == prior_task and rec["library"] == name and
           rec["source_sha256"] == source_sha and rec["status"] == "OUTPUT_READY" and
           rec["exit_code"] == 0 and rec["command"].count("-import") == 1 and
           rec["result_sha256"] == sha(old_folder / "ghidra_raw.json") and
           rec["target_tsv_sha256"] == sha(old_folder / "targets.tsv") and
           rec["stdout_sha256"] == sha(old_folder / "ghidra_stdout.log") and
           rec["stderr_sha256"] == sha(old_folder / "ghidra_stderr.log") and
           raw["task_id"] == prior_task and raw["program_name"] == name and
           len(raw["targets"]) == count, name + " original Ghidra receipt")
        with source.open("rb") as stream:
            elf = ELFFile(stream)
            ck(elf["e_machine"] == "EM_AARCH64", name + " architecture")
            by_va = {}
            for sym in elf.get_section_by_name(".dynsym").iter_symbols():
                if (sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF" and
                        int(sym["st_size"]) > 0 and int(sym["st_value"]) > 0):
                    by_va.setdefault(int(sym["st_value"]), []).append((sym.name, int(sym["st_size"])))
            loads = [{"index": n, "va": int(s["p_vaddr"]), "offset": int(s["p_offset"]),
                      "file_size": int(s["p_filesz"]), "memory_size": int(s["p_memsz"])}
                     for n, s in enumerate(elf.iter_segments()) if s["p_type"] == "PT_LOAD"]
        ck(len(by_va) == count and sum(map(len, by_va.values())) ==
           index["defined_nonzero_function_symbols"] and
           loads == index["pt_load_segments"], name + " original ELF census/PT_LOAD")
        assembly = [json.loads(line) for line in
                    (folder / "source_assembly.ndjson").read_text(encoding="utf-8").splitlines()]
        ck(len(assembly) == count, name + " source assembly extent")
        selected = spread(count)
        source_bytes = source.read_bytes()
        image_base = int(raw["image_base"], 16)
        for pos, (target, old_target, row, asm) in enumerate(
                zip(index["targets"], old_index["targets"], raw["targets"], assembly), 1):
            va, size = int(target["elf_va"], 16), target["size_bytes"]
            aliases = sorted(by_va[va], key=lambda pair: (-pair[1], pair[0]))
            ck(target["index"] == row["index"] == pos and
               (target["symbol"], size) == aliases[0] and
               target["aliases"] == [{"name": n, "size_bytes": sz} for n, sz in aliases] and
               all(target[key] == old_target[key] for key in
                   ("index", "elf_va", "size_bytes", "file_offset", "source_body_sha256", "symbol")),
               name + f" original/historical target {pos}")
            mapped = [(s["index"], s["offset"] + va - s["va"])
                      for s in loads if s["va"] <= va and va + size <= s["va"] + s["file_size"]]
            ck(len(mapped) == 1 and
               (target["pt_load_segment_index"], int(target["file_offset"], 16)) == mapped[0],
               name + f" PT_LOAD {pos}")
            body = source_bytes[mapped[0][1]:mapped[0][1] + size]
            body_sha = hashlib.sha256(body).hexdigest()
            ck(len(body) == size and body_sha == target["source_body_sha256"],
               name + f" source body {pos}")
            decoded = list(cap.disasm(body, va))
            canonical_asm = [f"0x{ins.address:x}: {ins.mnemonic} {ins.op_str}".rstrip()
                             for ins in decoded]
            ck(asm["index"] == pos and asm["elf_va"] == target["elf_va"] and
               asm["source_bytes_hex"] == body.hex() and
               asm["capstone_source_assembly"] == canonical_asm,
               name + f" original assembly {pos}")
            ck(row["elf_va"] == target["elf_va"] and row["symbol"] == target["symbol"] and
               row["size_bytes"] == size and int(row["database_va"], 16) == image_base + va and
               row["expected_source_sha256"] == row["ghidra_memory_sha256"] == body_sha and
               row["source_bytes_match"] is True and row["decompile_success"] is True and
               bool(row["pseudocode"].strip()) and not row["error"],
               name + f" Ghidra source/C {pos}")
            addresses = []
            valid = {ins.address: ins for ins in decoded}
            for line in row["instructions"]:
                match = re.match(r"^([0-9a-fA-F]+):\s+", line)
                ck(match is not None, name + f" listing parse {pos}")
                addresses.append(int(match.group(1), 16) - image_base)
            ck(addresses and addresses == sorted(set(addresses)) and
               len(addresses) == row["instruction_count_observed"] and
               all(addr in valid for addr in addresses), name + f" listed source instructions {pos}")
            for call in row["calls"]:
                match = re.match(r"^([0-9a-fA-F]+)\s+->\s+", call)
                ck(match is not None, name + f" call parse {pos}")
                call_va = int(match.group(1), 16) - image_base
                ck(call_va in valid and valid[call_va].mnemonic in ("bl", "blr", "b", "br"),
                   name + f" source transfer {pos}")
            c_hash = hashlib.sha256(row["pseudocode"].encode("utf-8")).hexdigest()
            c_warning = "WARNING:" in row["pseudocode"]
            expected_map.append({"library": name, "index": pos, "elf_va": target["elf_va"],
                                 "symbol": target["symbol"], "aliases": target["aliases"],
                                 "size_bytes": size,
                                 "pt_load_segment_index": target["pt_load_segment_index"],
                                 "file_offset": target["file_offset"],
                                 "source_body_sha256": body_sha, "ghidra_memory_sha256": body_sha,
                                 "c_like_recovered": True, "c_like_utf8_sha256": c_hash,
                                 "c_like_characters": len(row["pseudocode"]),
                                 "c_warning_present": c_warning,
                                 "ghidra_listed_instruction_count": len(addresses),
                                 "raw_result": f"{name}/historical_raw/ghidra_raw.json",
                                 "provenance_mode": prior_task + "_HISTORICAL"})
            if pos in selected:
                samples.append({"library": name, "index": pos, "elf_va": target["elf_va"],
                                "source_body_sha256": body_sha,
                                "source_instruction_count": len(decoded),
                                "ghidra_memory_sha256": body_sha,
                                "ghidra_listed_instruction_count": len(addresses),
                                "c_like_recovered": True})
                totals["sample_partial"] += len(addresses) < len(decoded)
            totals["warnings"] += c_warning
            totals["rows"] += 1
    ck(expected_map == export_map and samples == verify["ordinary_samples"],
       "full export map + spread sample join")
    ck(totals["rows"] == seal["original_export_vas"] == seal["source_bodies_rehashed"] ==
       seal["ghidra_memory_bodies_rehashed"] == seal["c_like_bodies_recovered"] == 281 and
       len(samples) == seal["ordinary_spread_provenance_samples"] == 31 and
       totals["warnings"] == verify["c_warning_bodies"] == 90 and
       totals["sample_partial"] == verify["ordinary_spread_partial_ghidra_listings"] == 9 and
       verify["fresh_imports_this_task"] == 0 and
       read(REPORT / "unresolved.json")["rows"] == seal["unresolved_export_vas"] == [],
       "recomputed totals/limitations")
    ck(sha(seal_path) == seal_sha, "stable seal")
    print(json.dumps({"verdict": "INDEPENDENT_HISTORICAL_STATIC_PROVENANCE_PASS",
                      "seal_sha256": seal_sha, "sources": len(SOURCES), "export_vas": totals["rows"],
                      "manifest_files": len(files), "code_files": len(seal["code_files"]),
                      "spread_ordinary": len(samples), "warnings": totals["warnings"],
                      "sample_partial_listings": totals["sample_partial"], "fresh_imports": 0,
                      "limitation": "TASK_149/153/155 historical evidence revalidated; no new decode"}, indent=2))


if __name__ == "__main__":
    main()
