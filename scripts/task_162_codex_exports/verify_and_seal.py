"""Recompute critical provenance and >=10% spread assembly samples; seal candidate."""
from __future__ import annotations

import hashlib
import json
import math
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile

from common import (FENCE, LEASE_ID, LIBRARIES, REPORT, ROOT, SCRIPTS,
                    SOURCE_DIR, STANDARD, STANDARD_SHA, TASK_SHA,
                    atomic_bytes, check_lease, now, sha256, write_json)

MAX_REPORT_BYTES = 134217728

def spread_indices(count: int) -> list[int]:
    sample_count = math.ceil(count * .10)
    return sorted({1 + round(i * (count - 1) / (sample_count - 1)) for i in range(sample_count)})

def main() -> None:
    check_lease()
    if (REPORT / "COMPLETE.json").exists():
        raise RuntimeError("candidate already sealed")
    batch = json.loads((REPORT / "batch_run_receipt.json").read_text(encoding="utf-8"))
    if batch.get("task_id") != "TASK_162" or batch.get("status") not in ("OUTPUT_READY", "PARTIAL"):
        raise RuntimeError("Ghidra batch not finished")
    steps = batch["steps"]
    total_elapsed = float(batch["elapsed_seconds"])
    if total_elapsed > 6600:
        raise RuntimeError("aggregate Ghidra cap exceeded")
    script_sha = sha256(SCRIPTS / "ExportSo162.java")
    assembly_decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    assembly_decoder.skipdata = True
    results = []
    critical_rehashed = 0
    ordinary_samples = []
    unresolved = []
    for name, (expected_sha, expected_count) in LIBRARIES.items():
        source = SOURCE_DIR / name
        raw_source = source.read_bytes()
        if hashlib.sha256(raw_source).hexdigest() != expected_sha:
            raise RuntimeError("source SHA changed: " + name)
        index = json.loads((REPORT / name / "source_index.json").read_text(encoding="utf-8"))
        if (index.get("task_id") != "TASK_162" or index.get("task_sha256") != TASK_SHA or
                index.get("standard_sha256") != STANDARD_SHA or index.get("lease_id") != LEASE_ID or
                index.get("fencing_token") != FENCE or index.get("source_sha256") != expected_sha or
                len(index["targets"]) != expected_count):
            raise RuntimeError("source index identity changed: " + name)
        with source.open("rb") as f:
            elf = ELFFile(f)
            dynsym = elf.get_section_by_name(".dynsym")
            by_va = {}
            for symbol in dynsym.iter_symbols():
                if symbol["st_info"]["type"] == "STT_FUNC" and symbol["st_shndx"] != "SHN_UNDEF" and int(symbol["st_size"]) > 0:
                    by_va.setdefault(int(symbol["st_value"]), []).append((symbol.name, int(symbol["st_size"])))
            if len(by_va) != expected_count:
                raise RuntimeError("dynsym changed: " + name)
            segments = [(i, int(p["p_vaddr"]), int(p["p_offset"]), int(p["p_filesz"]))
                        for i, p in enumerate(elf.iter_segments()) if p["p_type"] == "PT_LOAD"]
        source_assembly = [json.loads(x) for x in (REPORT / name / "source_assembly.ndjson").read_text(encoding="utf-8").splitlines()]
        if len(source_assembly) != expected_count:
            raise RuntimeError("source assembly row count changed: " + name)
        targets = index["targets"]
        sampled = set(spread_indices(expected_count))
        for position, t in enumerate(targets, 1):
            va, size = int(t["elf_va"], 16), t["size_bytes"]
            aliases = sorted(by_va.get(va, []), key=lambda x: (-x[1], x[0]))
            mapping = [(i, off + va - base) for i, base, off, length in segments
                       if base <= va and va + size <= base + length]
            if (t["index"] != position or len(mapping) != 1 or not aliases or
                    aliases[0] != (t["symbol"], size) or
                    mapping[0] != (t["pt_load_segment_index"], int(t["file_offset"], 16))):
                raise RuntimeError(f"critical ELF mapping changed {name}:{position}")
            body = raw_source[mapping[0][1]:mapping[0][1] + size]
            if len(body) != size or hashlib.sha256(body).hexdigest() != t["source_body_sha256"]:
                raise RuntimeError(f"critical source body hash changed {name}:{position}")
            asm = source_assembly[position - 1]
            if asm["index"] != position or asm["elf_va"] != t["elf_va"] or asm["source_bytes_hex"] != body.hex():
                raise RuntimeError(f"critical source assembly bytes changed {name}:{position}")
            critical_rehashed += 1
            if position in sampled:
                independent_assembly = [f"0x{i.address:x}: {i.mnemonic} {i.op_str}".rstrip()
                                        for i in assembly_decoder.disasm(body, va)]
                if independent_assembly != asm["capstone_source_assembly"]:
                    raise RuntimeError(f"ordinary spread assembly sample changed {name}:{position}")
                ordinary_samples.append({"library": name, "index": position,
                                         "elf_va": t["elf_va"], "source_body_sha256": t["source_body_sha256"]})
        ghidra_by_index = {}
        import_steps = [x for x in steps if x.get("library") == name and "chunk" not in x]
        if len(import_steps) != 1:
            raise RuntimeError("missing/duplicate import step: " + name)
        import_receipt_path = REPORT / name / "import/ghidra_command.json"
        import_receipt = json.loads(import_receipt_path.read_text(encoding="utf-8"))
        import_command = import_receipt["command"]
        if (import_receipt.get("lease_id") != LEASE_ID or import_receipt.get("fencing_token") != FENCE or
                import_receipt.get("source_sha256") != expected_sha or
                import_receipt.get("fresh_import_attempt_number") != 1 or
                import_command.count("-import") != 1 or import_command[4] != str(source) or
                "-max-cpu" not in import_command or
                import_receipt["stdout_sha256"] != sha256(import_receipt_path.parent / "ghidra_stdout.log") or
                import_receipt["stderr_sha256"] != sha256(import_receipt_path.parent / "ghidra_stderr.log") or
                import_receipt["elapsed_seconds"] > 900):
            raise RuntimeError("import receipt invalid: " + name)
        successful_chunks = 0
        for meta in index["chunks"]:
            folder = REPORT / meta["folder"]
            tsv = folder / "targets.tsv"
            if sha256(tsv) != meta["target_tsv_sha256"] or meta["count"] > 128:
                raise RuntimeError("chunk TSV changed: " + name)
            expected_indices = [int(x.split("\t", 1)[0]) for x in tsv.read_text(encoding="utf-8").splitlines()]
            if (len(expected_indices) != meta["count"] or expected_indices[0] != meta["first_index"] or
                    expected_indices[-1] != meta["last_index"]):
                raise RuntimeError("chunk TSV indexes changed: " + name)
            chunk_steps = [x for x in steps if x.get("library") == name and x.get("chunk") == meta["chunk"]]
            if len(chunk_steps) != 1:
                raise RuntimeError("missing/duplicate chunk step: " + name)
            if chunk_steps[0]["status"] != "OUTPUT_READY":
                continue
            receipt = json.loads((folder / "ghidra_command.json").read_text(encoding="utf-8"))
            result_path = folder / "ghidra_raw.json"
            command = receipt["command"]
            if (receipt.get("status") != "OUTPUT_READY" or receipt.get("exit_code") != 0 or
                    receipt.get("lease_id") != LEASE_ID or receipt.get("fencing_token") != FENCE or
                    receipt.get("target_tsv_sha256") != meta["target_tsv_sha256"] or
                    receipt.get("script_sha256") != script_sha or receipt.get("result_sha256") != sha256(result_path) or
                    receipt.get("stdout_sha256") != sha256(folder / "ghidra_stdout.log") or
                    receipt.get("stderr_sha256") != sha256(folder / "ghidra_stderr.log") or
                    receipt.get("elapsed_seconds", 901) > 900 or "-import" in command or
                    command[3:9] != ["-process", name, "-noanalysis", "-readOnly", "-max-cpu", "1"]):
                raise RuntimeError(f"Ghidra chunk receipt invalid {name}:{meta['chunk']}")
            result = json.loads(result_path.read_text(encoding="utf-8"))
            rows = result["targets"]
            if result.get("task_id") != "TASK_162" or result.get("program_name") != name or len(rows) != meta["count"]:
                raise RuntimeError("Ghidra raw result identity changed: " + name)
            if [x["index"] for x in rows] != expected_indices:
                raise RuntimeError("Ghidra row order changed: " + name)
            image_base = int(result["image_base"], 16)
            for row in rows:
                position = row["index"]
                if position in ghidra_by_index:
                    raise RuntimeError("duplicate Ghidra VA: " + name)
                t = targets[position - 1]
                if (row["elf_va"] != t["elf_va"] or row["size_bytes"] != t["size_bytes"] or
                        row["expected_source_sha256"] != t["source_body_sha256"] or
                        int(row["database_va"], 16) != image_base + int(t["elf_va"], 16)):
                    raise RuntimeError(f"Ghidra/source target mismatch {name}:{position}")
                ghidra_by_index[position] = row
            successful_chunks += 1
        memory_matched = sum(x.get("source_bytes_match") is True and
                             x.get("ghidra_memory_sha256") == targets[i - 1]["source_body_sha256"]
                             for i, x in ghidra_by_index.items())
        c_like = sum(x.get("source_bytes_match") is True and x.get("decompile_success") is True and
                     bool(x.get("pseudocode", "").strip()) for x in ghidra_by_index.values())
        instruction_rows = sum(x.get("source_bytes_match") is True and
                               x.get("instruction_count_observed", 0) > 0 for x in ghidra_by_index.values())
        for t in targets:
            row = ghidra_by_index.get(t["index"])
            if row is None or row.get("source_bytes_match") is not True or row.get("decompile_success") is not True:
                unresolved.append({"library": name, "index": t["index"], "elf_va": t["elf_va"],
                                   "reason": "CHUNK_NOT_AVAILABLE" if row is None else row.get("error", "NO_C_OUTPUT")})
        results.append({"library": name, "pinned_source_sha256": expected_sha,
                        "source_export_vas": expected_count, "ghidra_result_rows": len(ghidra_by_index),
                        "ghidra_memory_matched": memory_matched, "c_like_export_bodies": c_like,
                        "instruction_rows": instruction_rows, "chunks_output_ready": successful_chunks,
                        "chunks_total": len(index["chunks"]), "autoanalysis_timed_out":
                        import_receipt.get("autoanalysis_timed_out")})
    if critical_rehashed != 1670 or len(ordinary_samples) < 167:
        raise RuntimeError("source critical/ordinary coverage below required floor")
    total_c = sum(x["c_like_export_bodies"] for x in results)
    total_memory = sum(x["ghidra_memory_matched"] for x in results)
    full = total_memory == 1670 and total_c == 1670 and all(x["chunks_output_ready"] == x["chunks_total"] for x in results)
    status = "COMPLETE_CANDIDATE" if full else "PARTIAL_CANDIDATE"
    write_json(REPORT / "independent_verification.json", {"task_id": "TASK_162", "revision": 1,
        "verified_at": now(), "critical_original_body_hashes_recomputed": critical_rehashed,
        "ordinary_spread_source_assembly_samples": len(ordinary_samples),
        "ordinary_samples": ordinary_samples, "libraries": results,
        "total_ghidra_memory_matched": total_memory, "total_c_like_export_bodies": total_c,
        "total_unresolved": len(unresolved), "status": status})
    write_json(REPORT / "unresolved.json", {"task_id": "TASK_162", "revision": 1,
        "rows": unresolved})
    lines = ["# TASK_162 R1 — static export recovery candidate", "",
             f"Status: **{status}**. Independent CEO review pending.", "",
             "| Original SO | Pinned export VAs | Ghidra memory matched | C-like bodies | Chunk outputs |",
             "|---|---:|---:|---:|---:|"]
    for row in results:
        lines.append(f"| `{row['library']}` | {row['source_export_vas']} | {row['ghidra_memory_matched']} | "
                     f"{row['c_like_export_bodies']} | {row['chunks_output_ready']}/{row['chunks_total']} |")
    lines += ["", f"All {critical_rehashed} original ELF/PT_LOAD bodies were rehashed; "
              f"{len(ordinary_samples)} evenly spread source-assembly samples were independently regenerated.",
              "", "These are static Ghidra C-like export bodies, not a count of all internal functions. "
              "No runtime behavior, product Phase PASS, V4 or P7 has been validated.",
              "", "Raw source bytes/assembly, original-to-Ghidra body hashes, commands, logs and results "
              "are retained per library and chunk. See `unresolved.json` for any missing C-like output.",
              ""]
    atomic_bytes(REPORT / "01_MASTER_REPORT.md", ("\n".join(lines)).encode("utf-8"))
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_162", "revision": 1,
        "generated_at": now(), "status": status, "lease_id": LEASE_ID, "fencing_token": FENCE,
        "source_bodies_rehashed": critical_rehashed, "ghidra_memory_matched": total_memory,
        "c_like_export_bodies": total_c, "independent_review_pending": True})
    manifest = {}
    report_bytes = 0
    for path in sorted(REPORT.rglob("*")):
        if path.is_file() and path.name != "COMPLETE.json":
            rel = path.relative_to(REPORT).as_posix()
            manifest[rel] = sha256(path)
            report_bytes += path.stat().st_size
    if report_bytes > MAX_REPORT_BYTES:
        raise RuntimeError(f"report exceeds 128 MiB cap: {report_bytes}")
    write_json(REPORT / "COMPLETE.json", {"task_id": "TASK_162", "revision": 1,
        "status": status, "generated_at": now(), "lease_id": LEASE_ID,
        "fencing_token": FENCE, "task_sha256": TASK_SHA, "standard_sha256": STANDARD_SHA,
        "source_export_vas": 1670, "ghidra_memory_matched": total_memory,
        "c_like_export_bodies": total_c, "ordinary_provenance_sample_count": len(ordinary_samples),
        "report_bytes_excluding_complete": report_bytes, "file_sha256": manifest,
        "independent_ceo_review_pending": True, "commit_push_pending": True})
    print(json.dumps({"status": status, "source_vas": 1670, "memory_matched": total_memory,
                      "c_like": total_c, "ordinary_samples": len(ordinary_samples),
                      "unresolved": len(unresolved), "report_bytes": report_bytes}), flush=True)

if __name__ == "__main__":
    main()
