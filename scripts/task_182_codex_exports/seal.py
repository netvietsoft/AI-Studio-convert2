"""Seal TASK_182 vector-only static research without self-review or product claims."""

from __future__ import annotations

import hashlib
import json
from pathlib import Path

from run import (BODY_SHA, FENCE, LEASE, PROJECT, REPORT, ROOT, SCRIPTS, SOURCE,
                 SOURCE_SHA, STD_SHA, TASK_SHA, atomic, file_hash, guard, hashes,
                 now, write_json)


def main() -> None:
    guard()
    body = SOURCE.read_bytes()[0x328DC:0x328DC + 624]
    if hashlib.sha256(body).hexdigest() != BODY_SHA:
        raise RuntimeError("source body changed")
    if (REPORT / "source_body.bin").read_bytes() != body:
        raise RuntimeError("report body differs from original")
    evidence = json.loads((REPORT / "vector_source_evidence.json").read_text(encoding="utf-8"))
    verification = json.loads((REPORT / "simd_landmark_verification.json").read_text(encoding="utf-8"))
    probe = json.loads((REPORT / "vector_probe_raw.json").read_text(encoding="utf-8"))
    command = json.loads((REPORT / "vector_probe_command.json").read_text(encoding="utf-8"))
    if (evidence["simd_instruction_count"], evidence["historical_pcode_ops"],
            verification["key_instruction_landmarks_verified"],
            verification["spread_sample_count"], probe["vector_instruction_count"],
            probe["vector_pcode_ops"]) != (90, 999, 23, 10, 90, 999):
        raise RuntimeError("SIMD evidence counts changed")
    if (probe["copied_project_memory_sha256"], probe["decompile_completed"],
            probe["vector_fragment_c_like_nonempty"], command["timed_out"],
            command["exit_code"], command["historical_project_unchanged"]) != (
            BODY_SHA, False, False, False, 0, True):
        raise RuntimeError("new bounded Ghidra result changed")
    if command["elapsed_seconds"] > 180 or command["fresh_imports"] != 0:
        raise RuntimeError("resource bounds changed")
    raw_result = REPORT / "vector_probe_raw.json"
    if file_hash(raw_result) != command["result_sha256"]:
        raise RuntimeError("raw result hash changed")
    if file_hash(REPORT / "vector_probe_stdout.log") != command["stdout_sha256"]:
        raise RuntimeError("raw stdout hash changed")
    if file_hash(REPORT / "vector_probe_stderr.log") != command["stderr_sha256"]:
        raise RuntimeError("raw stderr hash changed")
    if hashes(PROJECT) != command["copied_project_files_sha256_after"]:
        raise RuntimeError("scratch project changed after pass")
    audit = f"""# TASK_182 R1 audit index

Canonical standard fully read: `F:\\CONVERT\\com.mt.mtxx.mtxx\\CONVERT2\\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` SHA-256 `{STD_SHA}`. Exact TASK_182 R1 SHA-256 `{TASK_SHA}`. Lease `{LEASE}`, fencing token `{FENCE}`. Real Codex worker `/root/so45_dexvmp_correction`, no AGY.

Original `F:\\CONVERT\\com.mt.mtxx.mtxx\\SOURCE\\extracted_native_libs\\lib\\arm64-v8a\\libglide-webp.so` SHA-256 `{SOURCE_SHA}`; original export `WebPConvertRGBA32ToUV_C` ELF VA `0x328dc`, size 624 bytes, body SHA-256 `{BODY_SHA}`. Original source, historical TASK_175 p-code/TASK_179 scalar-tail receipt and original TASK_155 analyzed project were read-only. The source project was copied by exact file hash to `RESEARCH_WORK/TASK_182_R1`; no fresh import.

One bounded vector-only Ghidra command, raw stdout/stderr/result, exact project copy hashes and elapsed time are in `vector_probe_command.json` and adjacent log/result files. `vector_source_evidence.json` records all 90 source words, `historical_vector_pcode.txt` the 999 prior source-aligned p-code operations, and `simd_landmark_verification.json` 23 instruction anchors plus 10 spread source-word rechecks. C-like/behavior conclusions are explicitly limited in the master report.
"""
    atomic(REPORT / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    detail = """# TASK_182 R1 - source-anchored SIMD correction

**Classification: static register/block analysis, not recovered C.** The only new Ghidra pass replaced original function metadata in a byte-verified read-only project copy with a synthetic `0x3294c..0x32ab4` vector region. It did not modify original bytes. The `decompile` style returned `Recoverable Error: Unable to find unique hash for varnode` in 67.70 ms, with no C-like fragment. `VectorProbe182.java` verified the whole original 624-byte memory SHA, all 90 instructions and 999 p-code ops before that result. The historical source project hashes remained unchanged.

## Entry state, required for interpreting the fragment

The synthetic vector function is entered only after the original path at `0x328dc..0x32948`. `w3` passed signed `>=1` and unsigned `>=9` checks; `x8` received the zero-extended `w3` count at `0x328e8`. `x0` is the source pointer and `x1`/`x2` are destination pointers by observed loads/stores, without a verified calling-context contract. Three unsigned-address overlap tests must branch **not taken** before `0x3294c`; their address arithmetic and gate are visible in the original instruction/p-code records. Source and destinations are assumed valid only for static interpretation. No runtime path feasibility, pointer aliasing beyond that gate, or pixel contract was tested.

## Byte-anchored vector operations

The original `ld4 {v16.8h,v17.8h,v18.8h,v19.8h},[x0],#64` at `0x329a8` reads eight 8-byte records and deinterleaves four 16-bit lanes. The fourth lane is loaded but is not referenced by the weighted sums in this loop. Setup instructions `0x32958..0x32998` replicate signed 32-bit coefficients `-9719`, `-19081`, `-24116`, `-4684`; unsigned halfword coefficient `28800`, bias `0x02020000`, comparison constant `256`, and saturation mask `0xff` per 32-bit lane. These are decoded immediates, not values inferred from the export name.

For each lane, register operations `mul/mla/umull/umlal` at `0x329b0..0x32a28` implement two 32-bit sums under the recorded entry-state assumption:

```text
s1 = -9719*c0 - 19081*c1 + 28800*c2 + 0x02020000
s2 = 28800*c0 - 24116*c1 - 4684*c2 + 0x02020000
```

Here `c0/c1/c2` are the first three unsigned 16-bit source lanes. Lower and upper groups of four lanes use `ushll/ushll2` and `ext`; destination 1 uses `v22/v21 -> v18/v17`, destination 2 uses `v28/v20 -> v16/v19`. For any 16-bit lane values, each unrounded weighted sum lies between `-1,887,408,000` and `1,887,408,000`; adding the bias keeps it within signed 32-bit, so the vector arithmetic does not require a wider type for these sums.

`sshr ...,#0x12` at `0x32a04/0x32a14/0x32a28/0x32a3c` performs signed arithmetic shift by 18. `cmlt` tests negative pre-shift sums, and `cmhi` checks whether unsigned shifted values are below 256. The `mvn/bic/and/orr` mask sequence at `0x32a20..0x32a94` yields zero for negative sums, the shifted value for the range 0..255, and 255 for higher nonnegative sums. `xtn/xtn2` at `0x32a80..0x32aa8` narrows 32→16→8 bits after clamping. `str d17,[x13],#8` at `0x32aa0` and `str d16,[x12],#8` at `0x32aac` write eight bytes to each destination; `b.ne 0x329a8` repeats after `subs x11,x11,#8`. The metadata-only C-like failure means this source-anchored register interpretation is the delivered SIMD evidence, not whole-function decompilation.

## Limitations

TASK_179's scalar-tail C-like was not rerun. The TASK_182 vector-only Ghidra pass is the sole corrective heavy pass (1 CPU, 1 GiB, 19.24 seconds, zero fresh imports). Its C-like coverage is **0/90 vector instructions** and **0/156 whole-original instructions**. Source-byte and assembly coverage of this vector interval is 90/90; historical Ghidra p-code alignment is 999/999; neither establishes observed runtime path coverage or image/pixel equivalence. No product, P0, phase, V4 or P7 status changes follow from this report.
"""
    atomic(REPORT / "02_SIMD_SOURCE_ANALYSIS.md", detail.encode("utf-8"))
    master = f"""# TASK_182 R1 - WebP SIMD-path corrective research

**Verdict: PARTIAL, awaiting independent CEO review.** The original `WebPConvertRGBA32ToUV_C` SIMD interval `0x3294c..0x32ab4` is source-byte mapped to 90/90 ARM64 instructions and 999/999 historical p-code operations. A single bounded vector-only Ghidra pass in a verified project copy failed with `Unable to find unique hash for varnode`; no vector C-like or whole-original C-like is claimed.

The source-anchored register analysis in `02_SIMD_SOURCE_ANALYSIS.md` identifies two weighted 16-bit-lane sums, signed shift by 18, clamp to 0..255, 32→16→8 narrowing, and eight-byte stores to each destination. It states the entry-state and overlap-gate assumptions. The exact original 624-byte body and 90 instruction records are retained; 23 critical SIMD instruction anchors and 10 spread ordinary source words (11.1%) were checked. The prior scalar-tail pass was not repeated.

Raw Ghidra command, logs and result are preserved, including the negative decompiler result. The source project is unchanged, zero fresh imports occurred, and no AGY, product/P0 edit, self-review, commit or push occurred. Runtime behavior and pixel parity remain unverified. PROJECT_ERROR.md and ACQUIREMENTS.md were reviewed but are outside this task's write scope.
"""
    atomic(REPORT / "01_MASTER_REPORT.md", master.encode("utf-8"))
    write_json(REPORT / "PROGRESS.json", {
        "schema_version": "2.1.2", "task_id": "TASK_182", "revision": 1,
        "state": "FINAL_CANDIDATE", "generated_at": now(), "lease_id": LEASE,
        "fencing_token": FENCE, "source_sha256": SOURCE_SHA, "body_sha256": BODY_SHA,
        "simd_source_instructions": 90, "historical_simd_pcode_ops": 999,
        "new_vector_fragment_c_like": False, "whole_original_function_c_like": False,
        "limitation": "Ghidra vector decompiler unique-varnode-hash failure"})
    files = {p.relative_to(REPORT).as_posix(): file_hash(p) for p in sorted(REPORT.rglob("*"))
             if p.is_file() and p.name not in ("PROGRESS.json", "COMPLETE.json")}
    codes = {p.relative_to(ROOT).as_posix(): file_hash(p) for p in sorted(SCRIPTS.rglob("*")) if p.is_file()}
    research = {p.relative_to(ROOT).as_posix(): file_hash(p) for p in sorted(PROJECT.rglob("*")) if p.is_file()}
    total = sum((REPORT / name).stat().st_size for name in files)
    if total > 134217728:
        raise RuntimeError("report cap exceeded")
    complete = {"schema_version": "2.1.2", "task_id": "TASK_182", "revision": 1,
                "status": "COMPLETE", "semantic_disposition": "PARTIAL_SIMD_SOURCE_RECOVERY_NO_C_LIKE",
                "generated_at": now(), "standard_sha256": STD_SHA,
                "task_sha256": TASK_SHA, "source_sha256": SOURCE_SHA, "body_sha256": BODY_SHA,
                "lease_id": LEASE, "fencing_token": FENCE,
                "execution_mode": "REAL_CODEX_SUBAGENT_NO_AGY",
                "review_state": "AWAITING_INDEPENDENT_CEO_REVIEW",
                "simd_source_instruction_count": 90, "historical_simd_pcode_ops": 999,
                "critical_instruction_landmarks": 23, "spread_source_words": 10,
                "new_ghidra_vector_c_like": False, "whole_original_c_like": False,
                "behavior_verified": False, "phase_pass": False,
                "fresh_imports": 0, "ghidra_processes": 1,
                "ghidra_elapsed_seconds": command["elapsed_seconds"],
                "report_bytes_excluding_seal_and_progress": total,
                "files": files, "code_files": codes, "research_files": research}
    write_json(REPORT / "COMPLETE.json", complete)
    print("TASK_182 SEALED PARTIAL", file_hash(REPORT / "COMPLETE.json"),
          "report_files", len(files), "code_files", len(codes), "research_files", len(research))


if __name__ == "__main__":
    main()
