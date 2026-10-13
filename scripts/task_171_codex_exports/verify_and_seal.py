"""Independently audit five original ELF/Ghidra export maps and seal TASK_171."""
from __future__ import annotations

import hashlib
import json
import math
import re

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile

from common import (FENCE, LEASE_ID, LIBRARIES, NEW_LIBRARIES, REPORT,
                    REUSED_LIBRARIES, ROOT, SCRIPTS, SOURCE_DIR,
                    STANDARD_SHA, TASK_SHA, atomic_bytes, check_lease,
                    now, sha256, write_json)
from prepare import verify_historical

MAX_REPORT_BYTES = 134217728

def spread_indices(count: int) -> list[int]:
    take = math.ceil(count * .10)
    if take <= 1:
        return [1] if count == 1 else [1, count]
    return sorted({1 + round(i * (count - 1) / (take - 1)) for i in range(take)})

def load_reused(name: str, prior_task: str, index: dict, archive: dict) -> tuple[dict[int, dict], dict]:
    verify_historical(name, LIBRARIES[name][0], prior_task)
    stored = archive["sources"].get(name)
    if stored is None or stored["prior_task"] != prior_task:
        raise RuntimeError("historical archive identity invalid: " + name)
    folder = REPORT / name / "historical_raw"
    for filename, record in stored["copied_raw_files"].items():
        if (sha256(folder / filename) != record["sha256"] or
                sha256(ROOT / record["original"]) != record["sha256"]):
            raise RuntimeError("historical raw copy/original changed: " + name + ":" + filename)
    prior_seal = json.loads((folder / "COMPLETE.json").read_text(encoding="utf-8"))
    if (prior_seal.get("task_id") != prior_task or prior_seal.get("status") != "COMPLETE" or
            sha256(folder / "COMPLETE.json") != stored["seal_sha256"]):
        raise RuntimeError("historical seal identity changed: " + name)
    receipt = json.loads((folder / "ghidra_command.json").read_text(encoding="utf-8"))
    raw_file = folder / "ghidra_raw.json"
    command = receipt["command"]
    if (receipt.get("task_id") != prior_task or receipt.get("library") != name or
            receipt.get("source_sha256") != LIBRARIES[name][0] or
            receipt.get("status") != "OUTPUT_READY" or receipt.get("exit_code") != 0 or
            receipt.get("elapsed_seconds", 901) > 900 or "-import" not in command or
            command[4] != str(SOURCE_DIR / name) or
            receipt.get("target_tsv_sha256") != sha256(folder / "targets.tsv") or
            receipt.get("result_sha256") != sha256(raw_file) or
            receipt.get("stdout_sha256") != sha256(folder / "ghidra_stdout.log") or
            receipt.get("stderr_sha256") != sha256(folder / "ghidra_stderr.log")):
        raise RuntimeError("historical raw Ghidra receipt invalid: " + name)
    raw = json.loads(raw_file.read_text(encoding="utf-8"))
    if raw.get("task_id") != prior_task or raw.get("program_name") != name or len(raw["targets"]) != len(index["targets"]):
        raise RuntimeError("historical raw Ghidra rows invalid: " + name)
    historical_index = json.loads((folder / "target_index.json").read_text(encoding="utf-8"))
    if historical_index.get("source_sha256") != LIBRARIES[name][0]:
        raise RuntimeError("historical source index identity invalid: " + name)
    rows = {}
    for position, row in enumerate(raw["targets"], 1):
        if row["index"] != position:
            raise RuntimeError("historical row ordering invalid: " + name)
        rows[position] = {"row": row, "image_base": int(raw["image_base"], 16),
                          "raw_path": (folder / "ghidra_raw.json").relative_to(REPORT).as_posix(),
                          "mode": prior_task + "_HISTORICAL"}
    return rows, {"historical_task": prior_task, "historical_status": receipt["status"],
                  "historical_elapsed_seconds": receipt["elapsed_seconds"],
                  "historical_raw_result_sha256": sha256(raw_file)}

def main() -> None:
    check_lease()
    if (REPORT / "COMPLETE.json").exists():
        raise RuntimeError("TASK_171 already sealed")
    if NEW_LIBRARIES:
        raise RuntimeError("TASK_171 is historical-reuse-only; duplicate import prohibited")
    archive = json.loads((REPORT / "historical_archive_receipt.json").read_text(encoding="utf-8"))
    source_batch = json.loads((REPORT / "source_batch_index.json").read_text(encoding="utf-8"))
    if source_batch.get("total_export_vas") != 281:
        raise RuntimeError("batch original export count changed")
    capstone = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    capstone.skipdata = True
    libraries = []
    ordinary = []
    unresolved = []
    map_lines = []
    total_source = 0
    total_ghidra_memory = 0
    total_c = 0
    total_warnings = 0
    total_partial_listing = 0
    for name, (expected_sha, expected_count) in LIBRARIES.items():
        check_lease()
        source = SOURCE_DIR / name
        raw_source = source.read_bytes()
        if hashlib.sha256(raw_source).hexdigest() != expected_sha:
            raise RuntimeError("original source SHA changed: " + name)
        index = json.loads((REPORT / name / "source_index.json").read_text(encoding="utf-8"))
        if (index.get("task_id") != "TASK_171" or index.get("task_sha256") != TASK_SHA or
                index.get("standard_sha256") != STANDARD_SHA or index.get("lease_id") != LEASE_ID or
                index.get("fencing_token") != FENCE or index.get("source_sha256") != expected_sha or
                index.get("unique_export_vas") != expected_count or len(index["targets"]) != expected_count):
            raise RuntimeError("source index identity changed: " + name)
        with source.open("rb") as handle:
            elf = ELFFile(handle)
            by_va = {}
            for symbol in elf.get_section_by_name(".dynsym").iter_symbols():
                if (symbol["st_info"]["type"] == "STT_FUNC" and symbol["st_shndx"] != "SHN_UNDEF" and
                        int(symbol["st_size"]) > 0):
                    by_va.setdefault(int(symbol["st_value"]), []).append((symbol.name, int(symbol["st_size"])))
            segments = [{"index": i, "va": int(segment["p_vaddr"]),
                         "offset": int(segment["p_offset"]), "file_size": int(segment["p_filesz"]),
                         "memory_size": int(segment["p_memsz"])}
                        for i, segment in enumerate(elf.iter_segments()) if segment["p_type"] == "PT_LOAD"]
        if len(by_va) != expected_count or segments != index["pt_load_segments"]:
            raise RuntimeError("independent original .dynsym/PT_LOAD census differs: " + name)
        observed, mode_summary = load_reused(name, REUSED_LIBRARIES[name][2], index, archive)
        source_assembly = [json.loads(line) for line in (REPORT / name / "source_assembly.ndjson").read_text(encoding="utf-8").splitlines()]
        if len(source_assembly) != expected_count:
            raise RuntimeError("original assembly line count changed: " + name)
        samples = set(spread_indices(expected_count))
        matched, c_like, warning, partial_listing = 0, 0, 0, 0
        for position, target in enumerate(index["targets"], 1):
            va, size = int(target["elf_va"], 16), target["size_bytes"]
            aliases = sorted(by_va.get(va, []), key=lambda pair: (-pair[1], pair[0]))
            mapped = [(segment["index"], segment["offset"] + va - segment["va"])
                      for segment in segments if segment["va"] <= va and
                      va + size <= segment["va"] + segment["file_size"]]
            if (target["index"] != position or len(mapped) != 1 or not aliases or
                    aliases[0] != (target["symbol"], size) or mapped[0] !=
                    (target["pt_load_segment_index"], int(target["file_offset"], 16))):
                raise RuntimeError(f"independent original export mapping differs: {name}:{position}")
            body = raw_source[mapped[0][1]:mapped[0][1] + size]
            digest = hashlib.sha256(body).hexdigest()
            if len(body) != size or digest != target["source_body_sha256"]:
                raise RuntimeError(f"original body SHA differs: {name}:{position}")
            total_source += 1
            assembly = source_assembly[position - 1]
            if assembly["index"] != position or assembly["elf_va"] != target["elf_va"] or assembly["source_bytes_hex"] != body.hex():
                raise RuntimeError(f"original source assembly bytes differ: {name}:{position}")
            current = observed.get(position)
            row = current["row"] if current else None
            listing_count, c_digest, c_good, c_warning = 0, "", False, False
            if row is not None:
                if (row["index"] != position or row["elf_va"] != target["elf_va"] or
                        row["symbol"] != target["symbol"] or row["size_bytes"] != size or
                        int(row["database_va"], 16) != current["image_base"] + va or
                        row["expected_source_sha256"] != digest or row["ghidra_memory_sha256"] != digest or
                        row["source_bytes_match"] is not True):
                    raise RuntimeError(f"Ghidra/source body mismatch: {name}:{position}")
                matched += 1
                total_ghidra_memory += 1
                listing_count = len(row["instructions"])
                if listing_count != row["instruction_count_observed"]:
                    raise RuntimeError(f"Ghidra instruction count differs: {name}:{position}")
                c_good = bool(row["decompile_success"] is True and row["pseudocode"].strip() and not row["error"])
                c_digest = hashlib.sha256(row["pseudocode"].encode("utf-8")).hexdigest()
                c_warning = "WARNING:" in row["pseudocode"]
                c_like += c_good
                total_c += c_good
                warning += c_warning
                total_warnings += c_warning
            else:
                unresolved.append({"library": name, "index": position, "elf_va": target["elf_va"],
                                   "reason": "GHIDRA_CHUNK_ABSENT"})
            if row is not None and not c_good:
                unresolved.append({"library": name, "index": position, "elf_va": target["elf_va"],
                                   "reason": row.get("error") or "NO_C_LIKE_OUTPUT"})
            if position in samples:
                decoded = [f"0x{inst.address:x}: {inst.mnemonic} {inst.op_str}".rstrip()
                           for inst in capstone.disasm(body, va)]
                if decoded != assembly["capstone_source_assembly"]:
                    raise RuntimeError(f"spread ordinary source disassembly differs: {name}:{position}")
                valid_addresses = {int(line.split(":", 1)[0], 16) for line in decoded}
                if row is not None:
                    for line in row["instructions"]:
                        match = re.match(r"^([0-9a-fA-F]+):\s+", line)
                        if not match or int(match.group(1), 16) - current["image_base"] not in valid_addresses:
                            raise RuntimeError(f"spread Ghidra listing not original-aligned: {name}:{position}")
                    partial_listing += listing_count < len(decoded)
                    total_partial_listing += listing_count < len(decoded)
                ordinary.append({"library": name, "index": position, "elf_va": target["elf_va"],
                                 "source_body_sha256": digest,
                                 "source_instruction_count": len(decoded),
                                 "ghidra_memory_sha256": row["ghidra_memory_sha256"] if row else None,
                                 "ghidra_listed_instruction_count": listing_count,
                                 "c_like_recovered": c_good})
            map_lines.append(json.dumps({"library": name, "index": position,
                "elf_va": target["elf_va"], "symbol": target["symbol"], "aliases": target["aliases"],
                "size_bytes": size, "pt_load_segment_index": target["pt_load_segment_index"],
                "file_offset": target["file_offset"], "source_body_sha256": digest,
                "ghidra_memory_sha256": row["ghidra_memory_sha256"] if row else None,
                "c_like_recovered": c_good, "c_like_utf8_sha256": c_digest,
                "c_like_characters": len(row["pseudocode"]) if row else 0,
                "c_warning_present": c_warning, "ghidra_listed_instruction_count": listing_count,
                "raw_result": current["raw_path"] if current else None,
                "provenance_mode": current["mode"] if current else "UNRESOLVED"}, ensure_ascii=False))
        libraries.append({"library": name, "source_sha256": expected_sha,
                          "source_export_vas": expected_count, "ghidra_memory_matched": matched,
                          "c_like_export_bodies": c_like, "c_warning_bodies": warning,
                          "ordinary_spread_rechecked": len(samples),
                          "spread_partial_ghidra_listings": partial_listing, **mode_summary})
    if total_source != 281 or len(ordinary) < 30:
        raise RuntimeError("critical/original ordinary provenance floor not met")
    full = total_ghidra_memory == 281 and total_c == 281 and not unresolved
    disposition = "BOUNDED_EXPORT_CANDIDATE" if full else "PARTIAL_EXPORT_CANDIDATE"
    atomic_bytes(REPORT / "export_map.ndjson", ("\n".join(map_lines) + "\n").encode("utf-8"))
    write_json(REPORT / "unresolved.json", {"task_id": "TASK_171", "revision": 1, "rows": unresolved})
    write_json(REPORT / "independent_verification.json", {"task_id": "TASK_171", "revision": 1,
        "verified_at": now(), "disposition": disposition, "libraries": libraries,
        "original_pt_load_bodies_rehashed": total_source,
        "ghidra_memory_bodies_rehashed": total_ghidra_memory,
        "c_like_export_bodies": total_c, "c_warning_bodies": total_warnings,
        "ordinary_spread_assembly_and_memory_samples": len(ordinary),
        "ordinary_spread_partial_ghidra_listings": total_partial_listing,
        "ordinary_samples": ordinary, "unresolved_count": len(unresolved),
        "fresh_imports_this_task": len(NEW_LIBRARIES),
        "historical_raw_reuse_libraries": list(REUSED_LIBRARIES),
        "internal_nonexported_functions_covered": False,
        "semantic_equivalence_proven": False, "runtime_pixel_behavior_proven": False})
    lines = ["# TASK_171 R1 — five original SO export maps", "",
             f"Status: **{disposition}; independent CEO review pending**.", "",
             "| Original source | Export VAs | Ghidra memory matched | C-like bodies | Provenance |",
             "|---|---:|---:|---:|---|"]
    for row in libraries:
        mode = f"hash-verified historical {row['historical_task']} raw run"
        lines.append(f"| `{row['library']}` | {row['source_export_vas']} | {row['ghidra_memory_matched']} | "
                     f"{row['c_like_export_bodies']} | {mode} |")
    lines += ["", f"All {total_source} original ELF/PT_LOAD bodies were independently rehashed. "
              f"{len(ordinary)} evenly spread ordinary records (>=10% per source) had their source "
              "assembly regenerated and Ghidra memory SHA rechecked. The raw commands, logs, "
              "output JSON and source index are preserved per library.", "",
              f"{total_warnings} C-like bodies contain Ghidra `WARNING:` text; "
              f"{total_partial_listing} sampled records have partial Ghidra instruction listings. "
              f"{len(unresolved)} export VAs remain without verified C-like output; see `unresolved.json`.", "",
              "All five Ghidra outputs came from TASK_149/153/155 and were verified against "
              "original bytes, then archived unchanged. TASK_171 ran no new Ghidra import. "
              "These are static export-level C-like bodies, not all internal functions or validated "
              "runtime behavior. No product Phase PASS, V4, P7, self-review, commit or push is claimed.", ""]
    atomic_bytes(REPORT / "01_MASTER_REPORT.md", "\n".join(lines).encode("utf-8"))
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_171", "revision": 1,
        "status": disposition, "generated_at": now(), "lease_id": LEASE_ID,
        "fencing_token": FENCE, "ghidra_memory_matched": total_ghidra_memory,
        "c_like_export_bodies": total_c, "independent_ceo_review_pending": True})
    files = {path.relative_to(REPORT).as_posix(): sha256(path)
             for path in sorted(REPORT.rglob("*")) if path.is_file() and
             path != REPORT / "COMPLETE.json" and path.name != "PROGRESS.json"}
    total_bytes = sum((REPORT / rel).stat().st_size for rel in files)
    if not files or total_bytes > MAX_REPORT_BYTES:
        raise RuntimeError(f"report extent/cap invalid: {total_bytes}")
    code = {path.relative_to(ROOT).as_posix(): sha256(path)
            for path in sorted(SCRIPTS.iterdir()) if path.is_file() and path.suffix in (".py", ".java")}
    check_lease()
    write_json(REPORT / "COMPLETE.json", {"schema_version": "2.1.2", "task_id": "TASK_171",
        "revision": 1, "status": "COMPLETE", "semantic_disposition": disposition,
        "generated_at": now(), "standard_sha256": STANDARD_SHA, "task_sha256": TASK_SHA,
        "lease_id": LEASE_ID, "fencing_token": FENCE,
        "execution_mode": "CODEX_SUBAGENT_NO_AGY", "review_state": "AWAITING_INDEPENDENT_CEO_REVIEW",
        "original_export_vas": 281, "source_bodies_rehashed": total_source,
        "ghidra_memory_bodies_rehashed": total_ghidra_memory,
        "c_like_bodies_recovered": total_c,
        "ordinary_spread_provenance_samples": len(ordinary),
        "unresolved_export_vas": [f"{row['library']}:{row['elf_va']}" for row in unresolved],
        "fresh_imports": len(NEW_LIBRARIES), "historical_raw_reuse_libraries": list(REUSED_LIBRARIES),
        "report_bytes_excluding_seal_and_progress": total_bytes,
        "internal_nonexported_functions_covered": False,
        "semantic_equivalence_proven": False, "phase_pass": False,
        "files": files, "code_files": code})
    print(json.dumps({"disposition": disposition, "source_vas": total_source,
                      "ghidra_memory_matched": total_ghidra_memory,
                      "c_like_bodies": total_c, "ordinary_samples": len(ordinary),
                      "unresolved": len(unresolved), "report_files": len(files),
                      "report_bytes": total_bytes}), flush=True)

if __name__ == "__main__":
    main()
