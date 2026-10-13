"""Source-byte and historical p-code audit of only the TASK_182 SIMD region."""

from __future__ import annotations

import hashlib
import json
import os
import shutil
import tempfile
from datetime import datetime, timezone
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile

from run import BODY_SHA, DEADLINE, REPORT, ROOT, SOURCE, SOURCE_SHA, guard, file_hash

PRIOR = ROOT / "RULES/REPORT/TASK_179_REPORT_R1"
START = 0x3294C
END = 0x32AB4
ORIGINAL = 0x328DC
SIZE = 624


def atomic(path: Path, data: bytes) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temp = tempfile.mkstemp(prefix=".task182-", dir=path.parent)
    try:
        with os.fdopen(fd, "wb") as stream:
            stream.write(data)
            stream.flush()
            os.fsync(stream.fileno())
        os.replace(temp, path)
    finally:
        if os.path.exists(temp):
            os.unlink(temp)


def jwrite(path: Path, obj: object) -> None:
    atomic(path, (json.dumps(obj, indent=2, ensure_ascii=False) + "\n").encode())


def main() -> None:
    guard()
    source = SOURCE.read_bytes()
    body = source[ORIGINAL:ORIGINAL + SIZE]
    if hashlib.sha256(body).hexdigest() != BODY_SHA:
        raise RuntimeError("original body SHA mismatch")
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        matches = [s for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"
                   and int(s["p_vaddr"]) <= ORIGINAL
                   and ORIGINAL + SIZE <= int(s["p_vaddr"] + s["p_filesz"])
                   and int(s["p_vaddr"]) - int(s["p_offset"]) == 0]
    if len(matches) != 1:
        raise RuntimeError("target original PT_LOAD offset not unique")
    prior_files = {
        "TASK_175_normalize_raw.json": PRIOR / "historical_TASK_175_normalize_raw.json",
        "TASK_179_probe_command.json": PRIOR / "probe_command.json",
        "TASK_179_scalar_tail_probe_raw.json": PRIOR / "scalar_tail_probe_raw.json",
        "TASK_179_instruction_evidence.json": PRIOR / "instruction_evidence.json",
    }
    for name, src in prior_files.items():
        atomic(REPORT / "historical_raw" / name, src.read_bytes())
    prior = json.loads((REPORT / "historical_raw/TASK_175_normalize_raw.json").read_text(encoding="utf-8"))
    previous = json.loads((REPORT / "historical_raw/TASK_179_instruction_evidence.json").read_text(encoding="utf-8"))
    if prior["original_source_body_sha256"] != BODY_SHA or previous["original_source_body_sha256"] != BODY_SHA:
        raise RuntimeError("historical body identity changed")
    probe = json.loads((REPORT / "vector_probe_raw.json").read_text(encoding="utf-8"))
    command = json.loads((REPORT / "vector_probe_command.json").read_text(encoding="utf-8"))
    if probe["copied_project_memory_sha256"] != BODY_SHA or probe["vector_instruction_count"] != 90:
        raise RuntimeError("new Ghidra vector scope/memory mismatch")
    if command["timed_out"] or command["elapsed_seconds"] > 180 or not command["historical_project_unchanged"]:
        raise RuntimeError("new Ghidra bounded-pass receipt failed")
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    rows = []
    prior_rows = {int(x["elf_va"], 16): x for x in previous["rows"]}
    for va in range(START, END, 4):
        word = source[va:va + 4]
        ins = list(decoder.disasm(word, va, count=1))
        if len(ins) != 1 or ins[0].size != 4:
            raise RuntimeError(f"source word not an instruction at {va:x}")
        prior_row = prior_rows[va]
        if prior_row["source_word_hex"] != word.hex():
            raise RuntimeError("historical opcode mismatch")
        rows.append({"elf_va": hex(va), "file_offset": hex(va), "source_word_hex_le": word.hex(),
                     "capstone": f"{ins[0].mnemonic} {ins[0].op_str}".strip(),
                     "historical_ghidra": prior_row["historical_ghidra"],
                     "historical_pcode_ops": prior_row["historical_pcode_ops"]})
    if len(rows) != 90:
        raise RuntimeError("vector instruction count")
    pcodes = [x for x in prior["pcode"] if START <= int(x.split(":", 1)[0], 16) - 0x100000 < END]
    if len(pcodes) != 999 or sum(r["historical_pcode_ops"] for r in rows) != 999 or probe["vector_pcode_ops"] != 999:
        raise RuntimeError("vector p-code count disagreement")
    atomic(REPORT / "source_body.bin", body)
    atomic(REPORT / "historical_vector_pcode.txt", ("\n".join(pcodes) + "\n").encode())
    jwrite(REPORT / "vector_source_evidence.json", {
        "task_id": "TASK_182", "revision": 1, "source_sha256": SOURCE_SHA,
        "source_body_sha256": BODY_SHA, "source_elf_va": hex(ORIGINAL),
        "source_body_size_bytes": SIZE, "simd_start_va": hex(START),
        "simd_end_exclusive_va": hex(END), "simd_instruction_count": len(rows),
        "historical_pcode_ops": len(pcodes), "pt_load_vaddr": hex(matches[0]["p_vaddr"]),
        "pt_load_file_offset": hex(matches[0]["p_offset"]),
        "rows": rows})
    landmarks = {
        0x32958: "mov w11, #-0x25f7", 0x3295C: "mov w12, #-0x4a89",
        0x32964: "mov w13, #0x7080", 0x32968: "mov w10, #0x2020000",
        0x32970: "mov w11, #-0x5e34", 0x32978: "mov w12, #-0x124c",
        0x32980: "movi v0.4s, #1, lsl #8", 0x32984: "movi v1.2d, #0x0000ff000000ff",
        0x329A8: "ld4 {v16.8h, v17.8h, v18.8h, v19.8h}, [x0], #64",
        0x329BC: "mul v22.4s, v22.4s, v2.4s",
        0x329C8: "mla v22.4s, v23.4s, v3.4s",
        0x329DC: "umlal v22.4s, v18.4h, v4.4h",
        0x329EC: "mla v28.4s, v23.4s, v6.4s",
        0x329FC: "mla v28.4s, v26.4s, v7.4s",
        0x32A04: "sshr v21.4s, v18.4s, #0x12",
        0x32A08: "cmlt v18.4s, v18.4s, #0",
        0x32A1C: "cmhi v26.4s, v0.4s, v21.4s",
        0x32A80: "xtn v18.4h, v18.4s",
        0x32A9C: "xtn v17.8b, v18.8h",
        0x32AA0: "str d17, [x13], #8",
        0x32AA8: "xtn v16.8b, v16.8h",
        0x32AAC: "str d16, [x12], #8",
        0x32AB0: "b.ne #0x329a8",
    }
    by_va = {int(r["elf_va"], 16): r for r in rows}
    for va, expected in landmarks.items():
        if by_va[va]["capstone"] != expected:
            raise RuntimeError(f"key SIMD instruction changed at {va:x}: {by_va[va]['capstone']}")
    sample_indices = [round(i * 89 / 9) for i in range(10)]
    samples = []
    for index in sample_indices:
        row = rows[index]
        va = int(row["elf_va"], 16)
        reread = SOURCE.read_bytes()[va:va + 4]
        if row["source_word_hex_le"] != reread.hex():
            raise RuntimeError("spread original word mismatch")
        samples.append({"index": index, "elf_va": hex(va), "source_word_hex_le": reread.hex(),
                        "capstone": row["capstone"]})
    if len(set(sample_indices)) < 9:
        raise RuntimeError("spread sample below 10%")
    jwrite(REPORT / "simd_landmark_verification.json", {
        "source_body_sha256": BODY_SHA, "source_instruction_count": 90,
        "source_instructions_reverified": 90, "key_instruction_landmarks":
            {hex(k): v for k, v in landmarks.items()},
        "key_instruction_landmarks_verified": len(landmarks),
        "historical_pcode_ops_verified": len(pcodes),
        "spread_sample_count": len(samples), "spread_sample_fraction": len(samples) / 90,
        "spread_samples": samples, "new_vector_probe_decompile_completed": probe["decompile_completed"],
        "new_vector_probe_c_like_nonempty": probe["vector_fragment_c_like_nonempty"],
        "new_vector_probe_error": probe["error"],
        "runtime_behavior_verified": False})
    print(f"TASK_182 SIMD source verified: instructions={len(rows)} pcode={len(pcodes)} "
          f"landmarks={len(landmarks)} spread={len(samples)} new_c_like={probe['vector_fragment_c_like_nonempty']}")


if __name__ == "__main__":
    main()
