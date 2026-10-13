"""Recheck TASK_175 evidence and seal a truthful bounded partial research package."""

from __future__ import annotations

import hashlib
import json
import math
import re

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

from common import (FENCE, HISTORICAL, HISTORICAL_PROJECT, LEASE_ID, LIBRARIES,
                    REPORT, ROOT, SCRIPTS, SOURCE_DIR, STANDARD, STANDARD_SHA,
                    TASK_SHA, atomic_bytes, check_lease, now, sha256, write_json)
from revalidate import mapped_bytes
from run_attempt import PROJECT, SCRIPT, tree_hashes


def main() -> None:
    check_lease()
    if (REPORT / "COMPLETE.json").exists():
        raise RuntimeError("TASK_175 already sealed")
    history = json.loads((REPORT / "historical_revalidation.json").read_text(encoding="utf-8"))
    index = json.loads((REPORT / "source_index.json").read_text(encoding="utf-8"))
    copy = json.loads((REPORT / "project_copy_inventory.json").read_text(encoding="utf-8"))
    attempt = json.loads((REPORT / "attempt_command.json").read_text(encoding="utf-8"))
    raw_path = REPORT / "alternative_normalize_raw.json"
    raw = json.loads(raw_path.read_text(encoding="utf-8"))
    if (history["source_bodies_rehashed"] != 427 or
            history["historical_ghidra_memory_bodies_rehashed"] != 427 or
            history["historical_c_like_bodies_recovered"] != 426 or
            len(history["records"]) != 427 or len(index["targets"]) != 427 or
            len(history["missing_historical_c_like"]) != 1 or
            history["missing_historical_c_like"][0]["elf_va"] != "0x328dc"):
        raise RuntimeError("historical result identity/count changed")
    if (copy["source_files_sha256"] != copy["copied_files_sha256_before_attempt"] or
            copy["source_files_sha256"] != tree_hashes(HISTORICAL_PROJECT)):
        raise RuntimeError("historical analyzed project changed or copied incorrectly")
    if attempt["copied_project_files_sha256_after_attempt"] != tree_hashes(PROJECT):
        raise RuntimeError("copied project post-attempt inventory changed")
    historical_seal_path = HISTORICAL / "COMPLETE.json"
    historical_seal = json.loads(historical_seal_path.read_text(encoding="utf-8"))
    if history["historical_complete_sha256"] != sha256(historical_seal_path):
        raise RuntimeError("historical TASK_155 complete seal changed")
    for name in LIBRARIES:
        for filename in ("target_index.json", "targets.tsv", "ghidra_command.json",
                         "ghidra_stdout.log", "ghidra_stderr.log", "ghidra_raw.json"):
            relative = f"{name}/{filename}"
            copied = REPORT / "historical_TASK_155_R1" / relative
            if sha256(copied) != sha256(HISTORICAL / relative):
                raise RuntimeError("historical raw copy changed: " + relative)
            if historical_seal["files"].get(relative) != sha256(copied):
                raise RuntimeError("historical manifest/raw copy differs: " + relative)
    if (sha256(REPORT / "historical_TASK_155_R1/COMPLETE.json") != sha256(historical_seal_path) or
            sha256(REPORT / "historical_TASK_155_R1/ExportSmallLib155.java") !=
            history["historical_exporter_sha256"]):
        raise RuntimeError("historical seal/exporter copy differs")
    if (attempt["task_id"] != "TASK_175" or attempt["revision"] != 1 or
            attempt["lease_id"] != LEASE_ID or attempt["fencing_token"] != FENCE or
            attempt["status"] != "OUTPUT_READY" or attempt["exit_code"] != 0 or
            attempt["fresh_imports"] != 0 or attempt["decompile_target_count"] != 1 or
            attempt["decompile_target_elf_va"] != "0x328dc" or
            attempt["decompile_timeout_seconds"] != 15 or
            attempt["max_cpu"] != 1 or attempt["GHIDRA_HEADLESS_MAXMEM"] != "1G" or
            attempt["elapsed_seconds"] > 900 or
            attempt["script_sha256"] != sha256(SCRIPT) or
            attempt["stdout_sha256"] != sha256(REPORT / "alternative_ghidra_stdout.log") or
            attempt["stderr_sha256"] != sha256(REPORT / "alternative_ghidra_stderr.log") or
            attempt["result_sha256"] != sha256(raw_path)):
        raise RuntimeError("one bounded alternative attempt command/hash mismatch")
    command = attempt["command"]
    if (command[3:9] != ["-process", "libglide-webp.so", "-noanalysis",
                          "-readOnly", "-max-cpu", "1"] or
            "-import" in command or command[-2:] != [SCRIPT.name, str(raw_path)]):
        raise RuntimeError("alternative command does not preserve no-import single-VA scope")
    stdout = (REPORT / "alternative_ghidra_stdout.log").read_text(
        encoding="utf-8", errors="replace")
    if ("Processing read-only project file: /libglide-webp.so" not in stdout or
            "[TASK_175] isolated normalize attempt" not in stdout):
        raise RuntimeError("alternative Ghidra read-only/completion log missing")
    source = SOURCE_DIR / "libglide-webp.so"
    if sha256(source) != LIBRARIES[source.name][0]:
        raise RuntimeError("original glide source SHA changed")
    with source.open("rb") as stream:
        elf = ELFFile(stream)
        body, offset = mapped_bytes(elf, stream, 0x328dc, 624)
    gap_digest = hashlib.sha256(body).hexdigest()
    gap_body_bytes = len(body)
    if gap_digest != "fc4cf89d6b719a3d8d73009a57a1e755ca9ce11dda3bdd03da45c5b869053404":
        raise RuntimeError("original glide gap PT_LOAD body SHA changed")
    cap = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    decoded = list(cap.disasm(body, 0x328dc))
    addresses = [item.address for item in decoded]
    if len(decoded) != 156 or sum(item.size for item in decoded) != 624:
        raise RuntimeError("original glide gap assembly not fully decoded")
    if (raw["task_id"] != "TASK_175" or raw["revision"] != 1 or
            raw["program_name"] != source.name or raw["source_sha256"] != LIBRARIES[source.name][0] or
            raw["symbol"] != "WebPConvertRGBA32ToUV_C" or raw["elf_va"] != "0x328dc" or
            raw["size_bytes"] != 624 or raw["original_source_body_sha256"] != gap_digest or
            raw["copied_ghidra_memory_sha256"] != gap_digest or
            raw["database_va"] != f"0x{int(raw['image_base'], 16) + 0x328dc:x}" or
            raw["analysis_style"] != "normalize" or raw["analysis_style_supported"] is not True or
            raw["instruction_count"] != 156 or len(raw["instructions"]) != 156 or
            raw["decompile_elapsed_ms"] > 15000):
        raise RuntimeError("alternative source/Ghidra/timeout identity mismatch")
    parsed_addresses = []
    for line in raw["instructions"]:
        match = re.match(r"^([0-9a-fA-F]+):\s+", line)
        if match is None:
            raise RuntimeError("alternative listing parse failed")
        parsed_addresses.append(int(match.group(1), 16) - int(raw["image_base"], 16))
    if parsed_addresses != addresses:
        raise RuntimeError("alternative Ghidra assembly not fully source aligned")
    if not raw["pcode"]:
        raise RuntimeError("alternative p-code evidence absent")
    pcode_addresses = []
    for line in raw["pcode"]:
        match = re.match(r"^([0-9a-fA-F]+):\s+", line)
        if match is None:
            raise RuntimeError("alternative p-code parse failed")
        pcode_addresses.append(int(match.group(1), 16) - int(raw["image_base"], 16))
    if not set(pcode_addresses) <= set(addresses):
        raise RuntimeError("alternative p-code address is outside source instruction range")
    # Repeat the full original ELF/PT_LOAD hash check and a second spread sample read.
    refreshed = []
    sampled = []
    for name, (expected_sha, expected_vas) in LIBRARIES.items():
        path = SOURCE_DIR / name
        if sha256(path) != expected_sha:
            raise RuntimeError("original source changed before seal: " + name)
        records = [record for record in index["targets"] if record["library"] == name]
        if len(records) != expected_vas:
            raise RuntimeError("source index library count changed: " + name)
        with path.open("rb") as stream:
            elf = ELFFile(stream)
            dynsym = elf.get_section_by_name(".dynsym")
            vas = {int(sym["st_value"]) for sym in dynsym.iter_symbols()
                   if sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF"
                   and int(sym["st_size"]) > 0 and int(sym["st_value"]) > 0}
            if len(vas) != expected_vas:
                raise RuntimeError("source unique export census changed: " + name)
            for record in records:
                va = int(record["elf_va"], 16)
                if va not in vas:
                    raise RuntimeError("source index VA not exported: " + name)
                body, offset = mapped_bytes(elf, stream, va, record["size_bytes"])
                digest = hashlib.sha256(body).hexdigest()
                if digest != record["source_body_sha256"] or record["file_offset"] != f"0x{offset:x}":
                    raise RuntimeError("source body recensus differs: " + name)
                refreshed.append((name, va, digest))
            sample_count = math.ceil(expected_vas * 0.1)
            positions = sorted({round(i * (expected_vas - 1) / (sample_count - 1))
                                for i in range(sample_count)})
            if len(positions) < sample_count:
                raise RuntimeError("ordinary spread sample too small")
            for position in positions:
                record = records[position]
                body, _ = mapped_bytes(elf, stream, int(record["elf_va"], 16), record["size_bytes"])
                digest = hashlib.sha256(body).hexdigest()
                if digest != record["source_body_sha256"]:
                    raise RuntimeError("ordinary spread source re-read differs")
                sampled.append({"library": name, "index": record["index"],
                                "elf_va": record["elf_va"], "source_body_sha256": digest})
    if len(refreshed) != 427 or len(sampled) < math.ceil(427 * 0.1):
        raise RuntimeError("final all-critical/ordinary coverage below requirement")
    before_files = copy["copied_files_sha256_before_attempt"]
    after_files = attempt["copied_project_files_sha256_after_attempt"]
    copy_changes = {"removed": sorted(set(before_files) - set(after_files)),
                    "added": sorted(set(after_files) - set(before_files)),
                    "modified": sorted(path for path in set(before_files) & set(after_files)
                                       if before_files[path] != after_files[path])}
    c_new = bool(raw["decompile_completed"] is True and raw["c_like_nonempty"] is True and
                 raw["c_like"].strip() and not raw["error"])
    if c_new:
        raise RuntimeError("unexpected recovered C: manual classification required before sealing")
    if raw["c_like_nonempty"] or raw["c_like"].strip():
        raise RuntimeError("alternative C-like state is internally contradictory")
    write_json(REPORT / "final_verification.json", {
        "task_id": "TASK_175", "revision": 1, "generated_at": now(),
        "source_libraries_sha256": {name: digest for name, (digest, _) in LIBRARIES.items()},
        "original_unique_export_vas_recounted": 427,
        "original_PT_LOAD_bodies_rehashed_twice": 427,
        "historical_Ghidra_memory_bodies_source_matched": 427,
        "historical_C_like_bodies": 426, "new_C_like_bodies": 0,
        "remaining_without_C_like": [{"library": "libglide-webp.so", "index": 144,
                                      "elf_va": "0x328dc", "symbol": "WebPConvertRGBA32ToUV_C"}],
        "historical_project_source_unchanged": True,
        "alternative_fresh_imports": 0, "alternative_process_count": 1,
        "alternative_style": "normalize", "alternative_completed": raw["decompile_completed"],
        "alternative_C_like_nonempty": raw["c_like_nonempty"],
        "alternative_original_source_instructions": len(decoded),
        "alternative_original_bytes": gap_body_bytes,
        "alternative_source_aligned_Ghidra_instructions": len(parsed_addresses),
        "alternative_source_addressed_pcode_ops": len(pcode_addresses),
        "copied_project_cache_changes_after_read_only_process": copy_changes,
        "ordinary_source_records_spread_re_read": len(sampled),
        "ordinary_source_records_total": 427,
        "spread_sample": sampled,
        "runtime_or_pixel_semantics_proven": False,
        "internal_nonexported_functions_covered": False})
    audit = ("# TASK_175 R1 audit index\n\n"
             f"Canonical Standard fully read at `{now()}`: `{STANDARD}`; SHA-256 `{STANDARD_SHA}`.\n\n"
             f"Exact ACTIVE task SHA-256 `{TASK_SHA}`; lease `{LEASE_ID}`, fence `{FENCE}`. "
             "Real Codex subagent; AGY was not used.\n\n"
             "TASK_155 raw results/logs and exporter are retained verbatim under "
             "`historical_TASK_155_R1/`; those 426 bodies are historical, not new TASK_175 recoveries. "
             "The one new isolated attempt used a copied analyzed glide project, not a fresh import. "
             "See `attempt_command.json`, `alternative_normalize_raw.json`, and `final_verification.json`.\n")
    atomic_bytes(REPORT / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    master = f"""# TASK_175 R1 - fantasy/glide historical recovery revalidation

Status: **PARTIAL_RESEARCH_CANDIDATE awaiting independent CEO review**.

| Original SO | Defined nonzero `.dynsym` names | Unique export VAs | Historical TASK_155 C-like | New TASK_175 C-like |
|---|---:|---:|---:|---:|
| `libfantasy.so` | 197 | 197 | 197 | 0 |
| `libglide-webp.so` | 244 | 230 | 229 | 0 |

## Observed

- Both pinned original files were SHA-256 checked. All 427 selected function bodies were independently mapped to original PT_LOAD file ranges and rehashed twice. The TASK_155 Ghidra-memory/body digests and raw command/log/result hashes match all 427. A separate spread sample of {len(sampled)}/427 original body records was re-read. The historical raw result files contain the 426 C-like texts.
- Exactly one historical gap remains: `libglide-webp.so` export `WebPConvertRGBA32ToUV_C`, index 144, ELF VA `0x328dc`, 624 bytes, original body SHA-256 `{gap_digest}`. TASK_155's default decompiler returned `Unable to find unique hash for varnode`.
- One new Ghidra headless process ({attempt['elapsed_seconds']} s; 1 CPU, 1 GiB; read-only, no analysis, no fresh import) used a byte-identical copy of the existing analyzed glide project and targeted only that VA. The `normalize` simplification style completed in {raw['decompile_elapsed_ms']:.1f} ms but emitted no C-like text. It preserved {len(decoded)} source-aligned AArch64 instruction lines and {len(pcode_addresses)} source-addressed lifted p-code operations. The historical project source inventory is unchanged; copied-project cache backup changes are recorded in `final_verification.json`.

## Scope and limits

The 426 C-like bodies were recovered earlier under TASK_155 and are only revalidated here. Lifted p-code and disassembly at the remaining VA are useful static evidence but do not constitute a recovered whole-function C-like body. Internal/nonexported functions, runtime behavior, device output, hair-color formulas and product Phase PASS/V4/P7 remain unproven. TASK_063 and downstream 064A-G/065/066 gates are unchanged. No self-review, acceptance, commit or push occurred.
"""
    atomic_bytes(REPORT / "01_MASTER_REPORT.md", master.encode("utf-8"))
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_175", "revision": 1,
        "status": "PARTIAL_RESEARCH_REPORT_READY", "generated_at": now(),
        "lease_id": LEASE_ID, "fencing_token": FENCE,
        "source_bodies_rehashed": 427, "historical_c_like_bodies_revalidated": 426,
        "new_c_like_bodies_recovered": 0, "missing_c_like_vas": ["0x328dc"],
        "independent_review_pending": True, "phase_pass": False})
    files = {path.relative_to(REPORT).as_posix(): sha256(path)
             for path in sorted(REPORT.rglob("*")) if path.is_file() and
             path.relative_to(REPORT).as_posix() not in ("COMPLETE.json", "PROGRESS.json")}
    total = sum((REPORT / relative).stat().st_size for relative in files)
    if not files or total > 134_217_728:
        raise RuntimeError("TASK_175 report extent/cap invalid")
    code = {path.relative_to(ROOT).as_posix(): sha256(path)
            for path in sorted(SCRIPTS.iterdir()) if path.is_file() and path.suffix in (".py", ".java")}
    check_lease()
    write_json(REPORT / "COMPLETE.json", {"schema_version": "2.1.2",
        "task_id": "TASK_175", "revision": 1, "status": "COMPLETE",
        "semantic_disposition": "PARTIAL_RESEARCH_CANDIDATE",
        "generated_at": now(), "standard_sha256": STANDARD_SHA, "task_sha256": TASK_SHA,
        "lease_id": LEASE_ID, "fencing_token": FENCE,
        "execution_mode": "REAL_CODEX_SUBAGENT_NO_AGY",
        "review_state": "AWAITING_INDEPENDENT_REVIEW",
        "source_libraries_sha256": {name: digest for name, (digest, _) in LIBRARIES.items()},
        "source_bodies_rehashed": 427, "historical_c_like_bodies_revalidated": 426,
        "new_c_like_bodies_recovered": 0,
        "unrecovered_c_like": [{"library": "libglide-webp.so", "elf_va": "0x328dc"}],
        "critical_provenance_rechecked": True,
        "ordinary_records_independently_rechecked": len(sampled),
        "ordinary_records_total": 427,
        "internal_nonexported_functions_covered": False,
        "runtime_or_pixel_semantics_proven": False,
        "files": files, "code_files": code})
    print(json.dumps({"status": "PARTIAL_RESEARCH_CANDIDATE",
                      "source_vas": 427, "historical_c_like": 426,
                      "new_c_like": 0, "remaining_va": "0x328dc",
                      "source_aligned_instructions": len(decoded),
                      "pcode_ops": len(pcode_addresses),
                      "spread_sample": len(sampled), "report_files": len(files),
                      "report_bytes": total}))


if __name__ == "__main__":
    main()
