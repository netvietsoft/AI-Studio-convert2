"""Independently validate TASK_155's two pinned SO export results against original ELF bytes."""

from __future__ import annotations

import hashlib
import json
import math
import re

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

from common import (FENCE, HISTORICAL, HISTORICAL_SCRIPT, LEASE_ID, LIBRARIES,
                    REPORT, SOURCE_DIR, STANDARD, STANDARD_SHA, TASK_SHA,
                    atomic_bytes, check_lease, now, sha256, write_json)


def mapped_bytes(elf: ELFFile, stream, va: int, size: int) -> tuple[bytes, int]:
    matches = []
    for segment in elf.iter_segments():
        if segment["p_type"] != "PT_LOAD":
            continue
        base = int(segment["p_vaddr"])
        available = int(segment["p_filesz"])
        if base <= va and va + size <= base + available:
            offset = int(segment["p_offset"]) + va - base
            stream.seek(offset)
            body = stream.read(size)
            if len(body) == size:
                matches.append((body, offset))
    if len(matches) != 1:
        raise RuntimeError(f"PT_LOAD mapping is not unique: 0x{va:x}+{size}")
    return matches[0]


def main() -> None:
    check_lease()
    if REPORT.exists():
        raise RuntimeError("TASK_175 report already exists")
    historical_seal_path = HISTORICAL / "COMPLETE.json"
    historical_seal = json.loads(historical_seal_path.read_text(encoding="utf-8"))
    if (historical_seal["task_id"] != "TASK_155" or historical_seal["revision"] != 1 or
            historical_seal["status"] != "COMPLETE"):
        raise RuntimeError("historical seal identity changed")
    for relative, expected in historical_seal["files"].items():
        if sha256(HISTORICAL / relative) != expected:
            raise RuntimeError("historical TASK_155 manifest mismatch: " + relative)
    if sha256(HISTORICAL_SCRIPT) != historical_seal["code_files"][
            "scripts/task155_direct_four_mixedlibs/ExportSmallLib155.java"]:
        raise RuntimeError("historical Ghidra exporter changed")
    cap = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    source_index = []
    summaries = []
    record_rows = []
    sampled = []
    historical_c = 0
    for name, (expected_sha, expected_vas) in LIBRARIES.items():
        check_lease()
        source = SOURCE_DIR / name
        if sha256(source) != expected_sha:
            raise RuntimeError("original source SHA changed: " + name)
        folder = HISTORICAL / name
        index = json.loads((folder / "target_index.json").read_text(encoding="utf-8"))
        raw = json.loads((folder / "ghidra_raw.json").read_text(encoding="utf-8"))
        receipt = json.loads((folder / "ghidra_command.json").read_text(encoding="utf-8"))
        if (index["task_id"] != "TASK_155" or index["source_sha256"] != expected_sha or
                index["unique_export_vas"] != expected_vas or
                len(index["targets"]) != expected_vas or
                raw["task_id"] != "TASK_155" or raw["program_name"] != name or
                len(raw["targets"]) != expected_vas):
            raise RuntimeError("historical source/index/raw identity mismatch: " + name)
        if (receipt["status"] != "OUTPUT_READY" or receipt["exit_code"] != 0 or
                receipt["library"] != name or receipt["source_sha256"] != expected_sha or
                receipt["script_sha256"] != sha256(HISTORICAL_SCRIPT) or
                receipt["target_tsv_sha256"] != sha256(folder / "targets.tsv") or
                receipt["result_sha256"] != sha256(folder / "ghidra_raw.json") or
                receipt["stdout_sha256"] != sha256(folder / "ghidra_stdout.log") or
                receipt["stderr_sha256"] != sha256(folder / "ghidra_stderr.log") or
                receipt["command"][3:7] != ["-import", str(source), "-max-cpu", "1"] or
                receipt["command"][7:9] != ["-analysisTimeoutPerFile", "480"] or
                receipt["elapsed_seconds"] > 900):
            raise RuntimeError("historical command/hash/log mismatch: " + name)
        stdout = (folder / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace")
        if "Import succeeded" not in stdout or f"[TASK_155] processed {expected_vas}/{expected_vas}" not in stdout:
            raise RuntimeError("historical Ghidra completion log missing: " + name)
        image_base = int(raw["image_base"], 16)
        if image_base < 0 or image_base > 0x100000000:
            raise RuntimeError("historical image base out of bounds: " + name)
        with source.open("rb") as stream:
            elf = ELFFile(stream)
            dynsym = elf.get_section_by_name(".dynsym")
            if dynsym is None:
                raise RuntimeError("original .dynsym missing: " + name)
            by_va: dict[int, list[tuple[str, int]]] = {}
            for symbol in dynsym.iter_symbols():
                if (symbol["st_info"]["type"] != "STT_FUNC" or
                        symbol["st_shndx"] == "SHN_UNDEF" or
                        int(symbol["st_size"]) <= 0 or int(symbol["st_value"]) <= 0):
                    continue
                by_va.setdefault(int(symbol["st_value"]), []).append(
                    (symbol.name, int(symbol["st_size"])))
            if len(by_va) != expected_vas or sum(map(len, by_va.values())) != index[
                    "defined_nonzero_function_symbols"]:
                raise RuntimeError("independent .dynsym census mismatch: " + name)
            recovered = 0
            full_source = 0
            full_listing = 0
            warnings = 0
            for n, (target, row) in enumerate(zip(index["targets"], raw["targets"]), 1):
                va = int(target["elf_va"], 16)
                aliases = sorted(by_va.get(va, []), key=lambda item: (-item[1], item[0]))
                if (target["index"] != n or row["index"] != n or
                        (target["symbol"], target["size_bytes"]) != aliases[0] or
                        target["aliases"] != [alias for alias, _ in aliases]):
                    raise RuntimeError(f"original export identity differs: {name}#{n}")
                body, offset = mapped_bytes(elf, stream, va, target["size_bytes"])
                digest = hashlib.sha256(body).hexdigest()
                if target["source_body_sha256"] != digest or target["file_offset"] != f"0x{offset:x}":
                    raise RuntimeError(f"original PT_LOAD body mismatch: {name}#{n}")
                if (row["symbol"] != target["symbol"] or row["elf_va"] != target["elf_va"] or
                        row["database_va"] != f"0x{va + image_base:x}" or
                        row["size_bytes"] != target["size_bytes"] or
                        row["expected_source_sha256"] != digest or
                        row["ghidra_memory_sha256"] != digest or row["source_bytes_match"] is not True):
                    raise RuntimeError(f"historical Ghidra memory/body mismatch: {name}#{n}")
                decoded = list(cap.disasm(body, va))
                address_map = {instruction.address: instruction for instruction in decoded}
                source_complete = sum(instruction.size for instruction in decoded) == len(body)
                full_source += source_complete
                listed = row["instructions"]
                if len(listed) != row["instruction_count_observed"]:
                    raise RuntimeError(f"historical Ghidra instruction count mismatch: {name}#{n}")
                listed_addresses = []
                for line in listed:
                    match = re.match(r"^([0-9a-fA-F]+):\s+", line)
                    if match is None:
                        raise RuntimeError(f"historical listing malformed: {name}#{n}")
                    address = int(match.group(1), 16) - image_base
                    if address not in address_map:
                        raise RuntimeError(f"historical listing not source aligned: {name}#{n}")
                    listed_addresses.append(address)
                if listed_addresses != sorted(set(listed_addresses)):
                    raise RuntimeError(f"historical listing duplicates/order: {name}#{n}")
                full_listing += bool(source_complete and len(listed) == len(decoded))
                for call in row["calls"]:
                    match = re.match(r"^([0-9a-fA-F]+)\s+->\s+", call)
                    if match is None:
                        raise RuntimeError(f"historical transfer malformed: {name}#{n}")
                    address = int(match.group(1), 16) - image_base
                    if address not in address_map or address_map[address].mnemonic not in ("bl", "blr", "b", "br"):
                        raise RuntimeError(f"historical transfer not source opcode: {name}#{n}")
                c_good = bool(row["decompile_success"] is True and row["pseudocode"].strip() and not row["error"])
                recovered += c_good
                historical_c += c_good
                warnings += "WARNING:" in row["pseudocode"]
                if row["decompile_success"] is True and not c_good:
                    raise RuntimeError(f"historical C claim malformed: {name}#{n}")
                item = {"library": name, "index": n, "elf_va": target["elf_va"],
                        "symbol": target["symbol"], "size_bytes": len(body),
                        "file_offset": f"0x{offset:x}", "source_body_sha256": digest,
                        "historical_ghidra_memory_sha256": row["ghidra_memory_sha256"],
                        "historical_c_like_recovered": c_good,
                        "historical_error": row["error"], "source_instructions": len(decoded),
                        "source_fully_decoded": source_complete,
                        "historical_ghidra_instructions": len(listed),
                        "historical_ghidra_fully_listed": source_complete and len(listed) == len(decoded)}
                record_rows.append(item)
                source_index.append({key: item[key] for key in (
                    "library", "index", "elf_va", "symbol", "size_bytes", "file_offset", "source_body_sha256")})
            sample_count = math.ceil(expected_vas * 0.1)
            sample_positions = sorted({round(i * (expected_vas - 1) / (sample_count - 1))
                                       for i in range(sample_count)})
            if len(sample_positions) < sample_count:
                raise RuntimeError("spread ordinary sample too small: " + name)
            for zero_index in sample_positions:
                target = index["targets"][zero_index]
                body, _ = mapped_bytes(elf, stream, int(target["elf_va"], 16), target["size_bytes"])
                digest = hashlib.sha256(body).hexdigest()
                if digest != target["source_body_sha256"] or digest != record_rows[
                        len(record_rows) - expected_vas + zero_index]["source_body_sha256"]:
                    raise RuntimeError(f"spread ordinary re-read differs: {name}#{zero_index + 1}")
                sampled.append({"library": name, "index": zero_index + 1, "source_body_sha256": digest})
        summaries.append({"library": name, "source_path": str(source), "source_sha256": expected_sha,
                          "defined_nonzero_function_symbols": sum(map(len, by_va.values())),
                          "unique_export_vas": expected_vas, "historical_c_like_recovered": recovered,
                          "source_fully_decoded": full_source,
                          "historical_ghidra_fully_listed": full_listing,
                          "historical_c_warning_bodies": warnings,
                          "historical_result_sha256": sha256(folder / "ghidra_raw.json"),
                          "historical_command_sha256": sha256(folder / "ghidra_command.json")})
    if len(record_rows) != 427 or historical_c != 426:
        raise RuntimeError("historical aggregate result does not match 426/427")
    failures = [item for item in record_rows if not item["historical_c_like_recovered"]]
    if len(failures) != 1 or failures[0]["library"] != "libglide-webp.so" or failures[0][
            "index"] != 144 or failures[0]["elf_va"] != "0x328dc":
        raise RuntimeError("historical failure is not the assigned one")
    # Copy the raw historical inputs verbatim into our review package, preserving provenance.
    selected = ("target_index.json", "targets.tsv", "ghidra_command.json",
                "ghidra_stdout.log", "ghidra_stderr.log", "ghidra_raw.json")
    for name in LIBRARIES:
        for filename in selected:
            source = HISTORICAL / name / filename
            atomic_bytes(REPORT / "historical_TASK_155_R1" / name / filename, source.read_bytes())
    atomic_bytes(REPORT / "historical_TASK_155_R1" / "COMPLETE.json", historical_seal_path.read_bytes())
    atomic_bytes(REPORT / "historical_TASK_155_R1" / "ExportSmallLib155.java", HISTORICAL_SCRIPT.read_bytes())
    write_json(REPORT / "source_index.json", {"task_id": "TASK_175", "revision": 1,
        "generated_at": now(), "original_export_vas": 427, "libraries": summaries,
        "targets": source_index})
    write_json(REPORT / "historical_revalidation.json", {"task_id": "TASK_175", "revision": 1,
        "generated_at": now(), "historical_task_id": "TASK_155",
        "historical_complete_sha256": sha256(historical_seal_path),
        "historical_exporter_sha256": sha256(HISTORICAL_SCRIPT),
        "source_bodies_rehashed": 427, "historical_ghidra_memory_bodies_rehashed": 427,
        "historical_c_like_bodies_recovered": historical_c,
        "missing_historical_c_like": failures,
        "spread_ordinary_source_records_re_read": len(sampled),
        "spread_ordinary_records": sampled, "libraries": summaries, "records": record_rows,
        "runtime_semantics_proven": False, "internal_nonexported_functions_covered": False})
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_175", "revision": 1,
        "status": "HISTORICAL_427_REVALIDATED_ONE_GAP_PENDING", "generated_at": now(),
        "lease_id": LEASE_ID, "fencing_token": FENCE,
        "historical_c_like_bodies_recovered": historical_c,
        "source_bodies_rehashed": 427, "independent_review_pending": True})
    print(json.dumps({"status": "HISTORICAL_REVALIDATED", "source_vas": 427,
                      "historical_c_like": historical_c, "gap": failures[0]["elf_va"],
                      "spread_sample": len(sampled), "summaries": summaries}))


if __name__ == "__main__":
    main()
