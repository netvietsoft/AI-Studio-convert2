"""Aggregate three independently source-checked TASK_166 export packages."""

from __future__ import annotations

import hashlib
import json
import math
from pathlib import Path

from elftools.elf.elffile import ELFFile

from common import (BASE_REPORT, FENCE, LEASE_ID, MAX_REPORT_BYTES,
                    ROOT, SCRIPTS, SOURCE_ROOT, SOURCES, STANDARD,
                    STANDARD_SHA, TASK_SHA, atomic_bytes, check_lease,
                    now, sha256, write_json)


def source_body(elf: ELFFile, source: Path, va: int, size: int) -> bytes:
    for segment in elf.iter_segments():
        if segment["p_type"] != "PT_LOAD":
            continue
        base = int(segment["p_vaddr"])
        end = base + int(segment["p_filesz"])
        if base <= va and va + size <= end:
            off = int(segment["p_offset"]) + va - base
            with source.open("rb") as f:
                f.seek(off)
                body = f.read(size)
            if len(body) == size:
                return body
    raise RuntimeError(f"unmapped source body {source.name}:0x{va:x}+{size}")


def check_source(name: str, expected_sha: str, expected_count: int) -> dict:
    source = SOURCE_ROOT / name
    if sha256(source) != expected_sha:
        raise RuntimeError(f"original source changed: {name}")
    folder = BASE_REPORT / source.stem
    index = json.loads((folder / "target_index.json").read_text(encoding="utf-8"))
    verified = json.loads((folder / "worker_source_verification.json").read_text(encoding="utf-8"))
    sealed = json.loads((folder / "SOURCE_COMPLETE.json").read_text(encoding="utf-8"))
    batch = json.loads((folder / "batch_run_receipt.json").read_text(encoding="utf-8"))
    if (index["source_name"] != name or index["source_sha256"] != expected_sha or
            index["unique_export_vas"] != expected_count or
            len(index["targets"]) != expected_count or
            verified["source_name"] != name or verified["source_sha256"] != expected_sha or
            verified["source_bodies_rehashed"] != expected_count or
            sealed["source_name"] != name or sealed["source_sha256"] != expected_sha or
            sealed["source_bodies_rehashed"] != expected_count or
            batch["task_id"] != "TASK_166"):
        raise RuntimeError(f"source package identity/count mismatch: {name}")
    for relative, expected in sealed["files"].items():
        path = folder / relative
        if not path.is_file() or sha256(path) != expected:
            raise RuntimeError(f"source manifest file mismatch: {name}/{relative}")
    for relative, expected in sealed["code_files"].items():
        path = ROOT / relative
        if not path.is_file() or sha256(path) != expected:
            raise RuntimeError(f"code hash changed: {relative}")
    with source.open("rb") as f:
        elf = ELFFile(f)
        dynsym = elf.get_section_by_name(".dynsym")
        by_va: dict[int, list[tuple[str, int]]] = {}
        for symbol in dynsym.iter_symbols():
            if (symbol["st_info"]["type"] != "STT_FUNC" or
                    symbol["st_shndx"] == "SHN_UNDEF" or
                    int(symbol["st_size"]) <= 0 or int(symbol["st_value"]) <= 0):
                continue
            by_va.setdefault(int(symbol["st_value"]), []).append((symbol.name, int(symbol["st_size"])))
        if len(by_va) != expected_count:
            raise RuntimeError(f"independent ELF VA census changed: {name}")
        if [int(x["elf_va"], 16) for x in index["targets"]] != sorted(by_va):
            raise RuntimeError(f"target VA set/order differs from original .dynsym: {name}")
        for target in index["targets"]:
            va = int(target["elf_va"], 16)
            aliases = sorted(by_va[va], key=lambda x: (-x[1], x[0]))
            if (target["symbol"], target["size_bytes"]) != aliases[0]:
                raise RuntimeError(f"symbol mismatch: {name}:0x{va:x}")
            body = source_body(elf, source, va, target["size_bytes"])
            if hashlib.sha256(body).hexdigest() != target["source_body_sha256"]:
                raise RuntimeError(f"original PT_LOAD hash mismatch: {name}:0x{va:x}")
    rows: dict[int, dict] = {}
    for meta in index["chunks"]:
        folder_chunk = folder / f"chunk_{meta['chunk']:02d}"
        raw_path = folder_chunk / "ghidra_raw.json"
        if not raw_path.is_file():
            continue
        raw = json.loads(raw_path.read_text(encoding="utf-8"))
        if raw.get("task_id") != "TASK_166" or raw.get("program_name") != name:
            raise RuntimeError(f"raw Ghidra program identity mismatch: {name}")
        for row in raw["targets"]:
            n = row["index"]
            if n in rows or n < 1 or n > expected_count:
                raise RuntimeError(f"raw Ghidra duplicate/out-of-range row: {name}:{n}")
            target = index["targets"][n - 1]
            if (row["elf_va"] != target["elf_va"] or
                    row["ghidra_memory_sha256"] != target["source_body_sha256"] or
                    row["source_bytes_match"] is not True):
                raise RuntimeError(f"raw Ghidra/source body mismatch: {name}:{n}")
            rows[n] = row
    if len(rows) != verified["ghidra_memory_bodies_rehashed"]:
        raise RuntimeError(f"raw row count mismatch: {name}")
    sample_count = math.ceil(expected_count / 10)
    spread = sorted({round(i * (expected_count - 1) / (sample_count - 1)) + 1
                     for i in range(sample_count)})
    if len(spread) < sample_count:
        raise RuntimeError(f"spread sample too small: {name}")
    c_in_sample = sum(bool(rows.get(n, {}).get("pseudocode", "").strip()) for n in spread)
    return {"source_name": name, "source_sha256": expected_sha,
            "defined_nonzero_export_symbols": sum(map(len, by_va.values())),
            "unique_export_vas": expected_count,
            "source_bodies_rehashed": expected_count,
            "ghidra_memory_bodies_rehashed": len(rows),
            "c_like_bodies_recovered": verified["ghidra_c_like_bodies_recovered"],
            "c_bodies_with_warnings": verified["c_bodies_with_warnings"],
            "ghidra_fully_listed_bodies": verified["ghidra_fully_listed_bodies"],
            "spread_sampled": len(spread), "sample_with_nonempty_c": c_in_sample,
            "chunks_output_ready": verified["chunks_output_ready"],
            "chunks_total": len(index["chunks"]),
            "source_complete_sha256": sha256(folder / "SOURCE_COMPLETE.json")}


def main() -> None:
    check_lease()
    if (BASE_REPORT / "COMPLETE.json").exists():
        raise RuntimeError("TASK_166 already sealed")
    summaries = [check_source(name, digest, count)
                 for name, (digest, count) in SOURCES.items()]
    source_total = sum(x["source_bodies_rehashed"] for x in summaries)
    c_total = sum(x["c_like_bodies_recovered"] for x in summaries)
    raw_total = sum(x["ghidra_memory_bodies_rehashed"] for x in summaries)
    sample_total = sum(x["spread_sampled"] for x in summaries)
    if source_total != 909 or sample_total < math.ceil(source_total / 10):
        raise RuntimeError("source or >=10% ordinary sample count changed")
    complete = all(x["c_like_bodies_recovered"] == x["unique_export_vas"] and
                   x["chunks_output_ready"] == x["chunks_total"] for x in summaries)
    disposition = "BOUNDED_RESEARCH_CANDIDATE" if complete else "PARTIAL_RESEARCH_CANDIDATE"
    audit = (f"# TASK_166 R1 audit index\n\nCanonical standard read at `{now()}`: "
             f"`{STANDARD}` SHA-256 `{STANDARD_SHA}`. Task SHA-256 `{TASK_SHA}`. "
             f"Lease `{LEASE_ID}` fence `{FENCE}`. Real Codex subagent, no AGY. "
             "All three original source SOs, every selected PT_LOAD body and per-source Ghidra raw result were rechecked. "
             "This is static export research awaiting independent CEO review.\n")
    atomic_bytes(BASE_REPORT / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    lines = ["# TASK_166 R1 - AI model, detection and hiai export map", "",
             f"Status: **{disposition} awaiting independent CEO review**.", "",
             "## Observed", ""]
    for x in summaries:
        lines.append(f"- `{x['source_name']}` SHA-256 `{x['source_sha256']}`: "
                     f"{x['defined_nonzero_export_symbols']:,} defined nonzero `.dynsym` names, "
                     f"{x['unique_export_vas']:,} distinct VAs; "
                     f"{x['source_bodies_rehashed']:,} source PT_LOAD body hashes, "
                     f"{x['ghidra_memory_bodies_rehashed']:,} Ghidra memory body hashes, "
                     f"{x['c_like_bodies_recovered']:,} C-like bodies, "
                     f"{x['chunks_output_ready']}/{x['chunks_total']} chunks, "
                     f"{x['ghidra_fully_listed_bodies']:,} fully listed bodies, "
                     f"{x['c_bodies_with_warnings']:,} C-warning bodies. "
                     f"{x['spread_sampled']} spread ordinary records checked.")
    lines.extend(["", "## Limits", "",
                  "Export C-like text and aligned assembly are static research evidence. "
                  "Non-exported functions, linked providers, model data, ABI semantics and real device outputs remain unverified. "
                  "Decompiler warnings and partial listings are enumerated in each worker_source_verification.json. "
                  "No product Phase PASS, V4/P7 authorization, self-review, commit or push.", ""])
    atomic_bytes(BASE_REPORT / "01_MASTER_REPORT.md", ("\n".join(lines)).encode("utf-8"))
    write_json(BASE_REPORT / "PROGRESS.json", {"task_id": "TASK_166", "revision": 1,
        "status": "REPORT_READY" if complete else "PARTIAL_REPORT_READY", "generated_at": now(),
        "lease_id": LEASE_ID, "fencing_token": FENCE,
        "sources": summaries, "source_bodies_rehashed": source_total,
        "ghidra_memory_bodies_rehashed": raw_total,
        "c_like_bodies_recovered": c_total,
        "independent_review_pending": True, "phase_pass": False})
    files = {p.relative_to(BASE_REPORT).as_posix(): sha256(p)
             for p in sorted(BASE_REPORT.rglob("*")) if p.is_file() and
             p.relative_to(BASE_REPORT).as_posix() not in ("COMPLETE.json", "PROGRESS.json")}
    total = sum((BASE_REPORT / name).stat().st_size for name in files)
    if total > MAX_REPORT_BYTES:
        raise RuntimeError("report exceeds 128 MiB task cap")
    code = {p.relative_to(ROOT).as_posix(): sha256(p)
            for p in sorted(SCRIPTS.iterdir()) if p.is_file() and p.suffix in (".py", ".java")}
    check_lease()
    write_json(BASE_REPORT / "COMPLETE.json", {
        "schema_version": "2.1.2", "task_id": "TASK_166", "revision": 1,
        "status": "COMPLETE", "semantic_disposition": disposition,
        "generated_at": now(), "standard_sha256": STANDARD_SHA,
        "task_sha256": TASK_SHA, "lease_id": LEASE_ID, "fencing_token": FENCE,
        "execution_mode": "REAL_CODEX_SUBAGENT_NO_AGY",
        "review_state": "AWAITING_INDEPENDENT_REVIEW", "source_summaries": summaries,
        "source_bodies_rehashed": source_total,
        "ghidra_memory_bodies_rehashed": raw_total,
        "c_like_bodies_recovered": c_total,
        "ordinary_records_spread_checked": sample_total,
        "ordinary_records_total": source_total,
        "internal_nonexported_functions_covered": False,
        "runtime_or_pixel_semantics_proven": False,
        "files": files, "code_files": code})
    print(json.dumps({"disposition": disposition, "source_bodies": source_total,
                      "ghidra_bodies": raw_total, "c_like_bodies": c_total,
                      "ordinary_samples": sample_total, "report_files": len(files),
                      "report_bytes": total}))


if __name__ == "__main__":
    main()
