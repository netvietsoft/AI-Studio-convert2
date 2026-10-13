"""Independently verify TASK_181 raw provenance and seal a truthful partial candidate."""

from __future__ import annotations

import hashlib
import json
import math
import re
from datetime import datetime, timezone
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

from run import (ROOT, REPORT, SCRATCH, SCRIPT, SOURCE, SOURCE_SHA, TASK, TASK_SHA,
                 TARGETS, HIST_MANIFEST, LEASE, DEADLINE, digest, require_lease, write_json)


def spread_indices(length: int, fraction: float = 0.11) -> list[int]:
    count = max(1, math.ceil(length * fraction))
    return sorted({round(i * (length - 1) / (count - 1)) for i in range(count)}) if count > 1 else [0]


def main() -> None:
    lock = require_lease()
    if digest(SOURCE) != SOURCE_SHA or digest(TASK) != TASK_SHA:
        raise RuntimeError("source/task changed before seal")
    manifest = json.loads((REPORT / "project_copy_manifest.json").read_text(encoding="utf-8"))
    if manifest["historical_manifest_sha256"] != digest(HIST_MANIFEST):
        raise RuntimeError("historical project manifest changed")
    for row in manifest["files"]:
        if digest(SCRATCH / "ghidra_project" / row["relative_path"]) != row["sha256"]:
            raise RuntimeError("Ghidra copied project file changed after two read-only runs")
    source_receipt = json.loads((REPORT / "source_verification.json").read_text(encoding="utf-8"))
    by_index = {row["index"]: row for row in source_receipt["targets"]}
    if set(by_index) != set(TARGETS):
        raise RuntimeError("target receipt set changed")
    sampled = []
    all_rows = []
    fragment_results = []
    decomp_count = 0
    dis = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        for index, item in TARGETS.items():
            info = by_index[index]
            offset = int(info["source_file_offset"], 16)
            stream.seek(offset)
            body = stream.read(item["size"])
            if hashlib.sha256(body).hexdigest() != item["sha"]:
                raise RuntimeError(f"original body mismatch index {index}")
            actual = [f"0x{x.address:x}: {x.mnemonic} {x.op_str}".rstrip() for x in dis.disasm(body, item["va"])]
            stored = (REPORT / f"source_assembly_{index}.txt").read_text(encoding="utf-8").splitlines()
            if actual != stored or len(actual) != item["size"] // 4:
                raise RuntimeError(f"full Capstone assembly replay differs index {index}")
            all_rows.extend((index, i, line) for i, line in enumerate(actual))
            raw = json.loads((REPORT / f"fragment_{index}_raw.json").read_text(encoding="utf-8"))
            command = json.loads((REPORT / f"attempt_{index}_command.json").read_text(encoding="utf-8"))
            if (command["exit_code"] != 0 or command["status"] != "OUTPUT_READY"
                    or command["result_sha256"] != digest(REPORT / f"fragment_{index}_raw.json")
                    or command["script_sha256"] != digest(SCRIPT)
                    or command["fencing_token"] != lock["fencing_token"]
                    or "-noanalysis" not in command["command"] or "-readOnly" not in command["command"]
                    or command["command"][command["command"].index("-max-cpu") + 1] != "1"):
                raise RuntimeError(f"command provenance fails index {index}")
            stdout = (REPORT / f"attempt_{index}_stdout.log").read_text(encoding="utf-8", errors="replace")
            if (command["stdout_sha256"] != digest(REPORT / f"attempt_{index}_stdout.log")
                    or command["stderr_sha256"] != digest(REPORT / f"attempt_{index}_stderr.log")
                    or "Processing read-only project file: /libffmpeg.so" not in stdout
                    or "Discarding changes to the following read-only file" not in stdout):
                raise RuntimeError(f"read-only Ghidra log evidence fails index {index}")
            fstart, fend = item["fragment_start"], item["fragment_end"]
            fragment = body[fstart-item["va"]:fend-item["va"]+4]
            if raw["original_body_sha256"] != item["sha"] or raw["copied_memory_body_sha256"] != item["sha"]:
                raise RuntimeError(f"copied body mismatch index {index}")
            if raw["fragment_sha256"] != hashlib.sha256(fragment).hexdigest():
                raise RuntimeError(f"fragment bytes mismatch index {index}")
            if raw["fragment_size_bytes"] != len(fragment) or raw["fragment_instruction_count"] != len(fragment)//4:
                raise RuntimeError(f"fragment dimensions mismatch index {index}")
            g_lines = raw["fragment_instructions"]
            if len(g_lines) != len(fragment)//4:
                raise RuntimeError(f"fragment instruction rows mismatch index {index}")
            for pos, line in enumerate(g_lines):
                m = re.match(r"^([0-9a-fA-F]+):\s+(\S+)", line)
                if not m or int(m.group(1), 16) != 0x100000 + fstart + 4*pos:
                    raise RuntimeError(f"Ghidra instruction PC mismatch index {index}, row {pos}")
            for op in raw["fragment_raw_pcode"]:
                m = re.match(r"^([0-9a-fA-F]+):", op)
                if not m or not (0x100000+fstart <= int(m.group(1),16) <= 0x100000+fend):
                    raise RuntimeError(f"raw p-code PC outside fragment index {index}")
            if index == 2283:
                if not raw["decompile_completed"] or not raw["fragment_c_like"].strip():
                    raise RuntimeError("2283 fragment C-like unexpectedly absent")
                c_like = raw["fragment_c_like"]
                if "TASK_181_fragment_2283" not in c_like or "return" not in c_like:
                    raise RuntimeError("2283 fragment C-like malformed")
                header = ("/* TASK_181 static Ghidra C-like for *synthetic fragment only*.\n"
                          " * Original export: x264_8_deblock_h_luma_intra_neon at ELF VA 0x658fe8.\n"
                          " * Original-byte fragment: 0x659200..0x6592c4; 200/736 bytes.\n"
                          " * Synthetic entry registers are undefined outside original preceding context.\n"
                          " * This is not the whole original function or behavior/pixel-equivalence evidence.\n */\n\n")
                (REPORT / "fragment_2283_synthetic.c").write_text(header + c_like, encoding="utf-8")
                decomp_count += 1
            else:
                if raw["decompile_completed"] or raw["fragment_c_like"].strip() or "Unable to find unique hash for varnode" not in raw["error"]:
                    raise RuntimeError("2330 outcome changed from observed decompiler failure")
            fragment_results.append({"index": index, "elf_va": hex(item["va"]), "original_body_bytes": item["size"],
                                     "original_instruction_rows": len(actual), "fragment_elf_start": hex(fstart),
                                     "fragment_elf_end": hex(fend), "fragment_bytes": len(fragment),
                                     "fragment_instruction_rows": len(g_lines), "fragment_raw_pcode_ops": len(raw["fragment_raw_pcode"]),
                                     "ghidra_c_like_fragment": bool(raw["fragment_c_like"].strip()),
                                     "whole_original_ghidra_c_like": False, "decompiler_error": raw["error"],
                                     "wall_seconds": command["wall_seconds"]})
    for pos in spread_indices(len(all_rows)):
        index, row, assembly = all_rows[pos]
        sampled.append({"global_ordinal": pos, "target_index": index, "target_ordinal": row,
                        "elf_va": hex(TARGETS[index]["va"] + 4*row), "direct_redecoded_assembly": assembly,
                        "stored_assembly_exact_match": True})
    if len(sampled) < math.ceil(len(all_rows)*0.10):
        raise RuntimeError("ordinary spread sample under 10 percent")
    result = {"schema_version": "2.1.2", "task_id": "TASK_181", "revision": 1,
              "verified_at": datetime.now(timezone.utc).isoformat(), "result": "PARTIAL_STATIC_FRAGMENT_ONLY",
              "source_sha256": SOURCE_SHA, "original_export_vas": source_receipt["unique_export_vas"],
              "original_instruction_rows_fully_redecoded": len(all_rows),
              "ordinary_spread_sample_count": len(sampled), "ordinary_spread_sample_fraction": len(sampled)/len(all_rows),
              "project_copy_file_hashes_checked": len(manifest["files"]), "alternative_processes": len(fragment_results),
              "max_observed_process_wall_seconds": max(x["wall_seconds"] for x in fragment_results),
              "ghidra_c_like_fragment_count": decomp_count, "whole_original_c_like_count": 0,
              "behavior_equivalence_tested": False, "product_phase_pass": False,
              "targets": fragment_results, "ordinary_spread_sample": sampled}
    write_json(REPORT / "verification.json", result)
    (REPORT / "00_AUDIT_INDEX.md").write_text(
        "# TASK_181 R1 audit index\n\n"
        "- Agent: `/root/so45_ai_model_search`; lease `LEASE-CEO-WORKER-TASK_181-R1`, fence `1211`.\n"
        "- Fully read canonical `F:\\CONVERT\\com.mt.mtxx.mtxx\\CONVERT2\\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`; SHA-256 `10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F`.\n"
        "- Exact task SHA-256 `be4d2d6bee8698f9920a24cc14e5657669649f536a7f885679d01b7eab638dbd`.\n"
        "- Original source `libffmpeg.so` SHA-256 `d8df8c5cb7a6b5a7eb771782d74a38e0b8d3cfacd1fbef1ae67a96171e3325c9`.\n"
        "- Primary raw records: `source_verification.json`, `source_assembly_2283.txt`, `source_assembly_2330.txt`, `project_copy_manifest.json`, `fragment_2283_raw.json`, `fragment_2330_raw.json`, both `attempt_*_command.json`, stdout/stderr, `verification.json`.\n"
        "- Readable synthetic-fragment output: `fragment_2283_synthetic.c`. Original bytes and historical project remained read-only.\n"
        "- No product build/device test was applicable to this static research task; no Phase PASS or V4 readiness claim. CEO independent review pending.\n",
        encoding="utf-8")
    (REPORT / "01_MASTER_REPORT.md").write_text(
        "# TASK_181 R1 — bounded FFmpeg NEON fragment correction\n\n"
        "**Disposition:** PARTIAL static research candidate. One original-byte, synthetic-entry fragment of target 2283 produced Ghidra C-like; both whole-original exported functions still lack C-like.\n\n"
        "The pinned original `libffmpeg.so` is byte-identical to the task hash. Direct `.dynsym`/PT_LOAD checks found 2,461 unique defined function-export VAs and both exact body hashes. Independent Capstone replay matched all 242 original instruction rows. The copied analyzed Ghidra project matched all nine historical file hashes before execution and still matched after two read-only processes.\n\n"
        "| Index | Export / ELF VA | Original bytes | Isolated fragment | Result |\n"
        "|---:|---|---:|---|---|\n"
        "| 2283 | `x264_8_deblock_h_luma_intra_neon` / `0x658fe8` | 736 | `0x659200..0x6592c4`, 200 bytes/50 instructions | Ghidra `decompile` C-like for the fragment only; synthetic entry registers lack original preceding context. |\n"
        "| 2330 | `x264_8_frame_init_lowres_core_neon` / `0x65aea8` | 232 | `0x65af24..0x65af8c`, 108 bytes/27 instructions | Original-byte fragment verified; decompiler returned `Unable to find unique hash for varnode`, no C-like. |\n\n"
        "The historical TASK_173 `normalize` pass was not repeated. Each target had one new isolated-fragment `decompile` process with `-noanalysis -readOnly -max-cpu 1`, `GHIDRA_HEADLESS_MAXMEM=1G`, and a 180-second decompiler cap. Actual process wall times are in command receipts. `fragment_2283_synthetic.c` is Ghidra output, not a standalone implementation or proof of the original full function. It begins at a synthetic entry with input vector registers that were initialized by omitted instructions. Target 2330 retains exact source assembly and the historical raw/normalized p-code under TASK_173; this task also records the attempted fragment's raw p-code.\n\n"
        "Critical SHA/source/lease/project/process claims and 27 spread ordinary instruction provenance rows were independently checked in `verification.json` (27/242 = 11.16%). No pixel/behavior equivalence test, physical-device validation, product build, Phase PASS, V4 or P7 authorization is implied. The unresolved whole-body gap remains 2/2.\n",
        encoding="utf-8")
    report_files = [p for p in REPORT.rglob("*") if p.is_file() and p.name not in {"COMPLETE.json", "PROGRESS.json"}]
    report_files.sort(key=lambda p: p.relative_to(REPORT).as_posix())
    files = {p.relative_to(REPORT).as_posix(): digest(p) for p in report_files}
    code_paths = [ROOT / "scripts/task_181_codex_exports/Fragment181.java", ROOT / "scripts/task_181_codex_exports/run.py",
                  ROOT / "scripts/task_181_codex_exports/verify_and_seal.py"]
    code_files = {p.relative_to(ROOT).as_posix(): digest(p) for p in code_paths}
    complete = {"schema_version": "2.1.2", "task_id": "TASK_181", "revision": 1,
                "status": "COMPLETE", "research_disposition": "PARTIAL_STATIC_FRAGMENT_ONLY",
                "review_status": "REVIEW_CANDIDATE_AWAITING_CEO", "generated_at": datetime.now(timezone.utc).isoformat(),
                "agent_id": "/root/so45_ai_model_search", "lease_id": LEASE, "fencing_token": lock["fencing_token"],
                "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
                "task_sha256": TASK_SHA, "original_so_sha256": SOURCE_SHA, "target_original_va_count": 2,
                "ghidra_fragment_c_like_count": decomp_count, "whole_original_c_like_count": 0,
                "files": files, "code_files": code_files, "product_phase_pass": False, "behavior_equivalence_tested": False,
                "commit_sha": None, "push_receipt": None}
    write_json(REPORT / "COMPLETE.json", complete)
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_181", "revision": 1, "status": "SEALED_PARTIAL_AWAITING_CEO",
               "updated_at": datetime.now(timezone.utc).isoformat(), "lease_id": LEASE,
               "fencing_token": lock["fencing_token"], "complete_sha256": digest(REPORT / "COMPLETE.json"),
               "whole_original_c_like_count": 0, "fragment_c_like_count": decomp_count})
    print(json.dumps({"sealed": True, "complete_sha256": digest(REPORT / "COMPLETE.json"),
                      "ordinary_sample": len(sampled), "whole_original_c_like": 0,
                      "fragment_c_like": decomp_count}), flush=True)


if __name__ == "__main__":
    main()
