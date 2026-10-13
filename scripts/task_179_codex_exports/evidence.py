"""TASK_179: source-byte and control-flow evidence for one original ARM64 export."""

from __future__ import annotations

import hashlib
import json
import math
import re
from datetime import datetime, timezone
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile


ROOT = Path(__file__).resolve().parents[2]
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libglide-webp.so")
REPORT = ROOT / "RULES/REPORT/TASK_179_REPORT_R1"
PRIOR = ROOT / "RULES/REPORT/TASK_175_REPORT_R1/alternative_normalize_raw.json"
TASK = ROOT / "RULES/TASK/TASK_179_SO45_CODEX_GAP_RECOVERY_ACTIVE.md"
LOCKS = ROOT / ".ai/locks.json"
LEASE = "LEASE-CEO-WORKER-TASK_179-R1"
FENCE = 1208
ELF_VA = 0x328DC
SIZE = 624
SOURCE_SHA = "2f7f38acc0d294a3333069aa8a3c07e69d4bc0a64f162215578bd55dbe1a4486"
BODY_SHA = "fc4cf89d6b719a3d8d73009a57a1e755ca9ce11dda3bdd03da45c5b869053404"
TASK_SHA = "21ecae3c8ccbe28a3bfd90b9bdcd6b49a4563f3bfa9ead87e6bce5e478d478d6"


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def utc_now() -> str:
    return datetime.now(timezone.utc).isoformat()


def check_lease() -> None:
    if sha256(TASK.read_bytes()) != TASK_SHA:
        raise RuntimeError("exact ACTIVE task SHA changed")
    task_text = TASK.read_text(encoding="utf-8")
    if "STATUS: ACTIVE" not in task_text:
        raise RuntimeError("task is no longer ACTIVE")
    locks = json.loads(LOCKS.read_text(encoding="utf-8"))
    matches = [item for item in locks["active_locks"] if item.get("lease_id") == LEASE]
    if len(matches) != 1:
        raise RuntimeError("exact lease missing or duplicated")
    lease = matches[0]
    expiry = datetime.fromisoformat(lease["expiry"].replace("Z", "+00:00"))
    if (lease.get("task_id") != "TASK_179" or lease.get("agent_id") != "/root/so45_ai_model_search"
            or lease.get("fencing_token") != FENCE or lease.get("status") != "ACTIVE"
            or expiry <= datetime.now(timezone.utc)):
        raise RuntimeError("TASK_179 lease/fence invalid")


def write_json(name: str, data: object) -> None:
    check_lease()
    REPORT.mkdir(parents=True, exist_ok=True)
    path = REPORT / name
    path.write_text(json.dumps(data, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")


def main() -> None:
    check_lease()
    source_bytes = SOURCE.read_bytes()
    if sha256(source_bytes) != SOURCE_SHA:
        raise RuntimeError("original SO SHA mismatch")
    prior_bytes = PRIOR.read_bytes()
    prior = json.loads(prior_bytes)
    if (prior.get("task_id") != "TASK_175" or prior.get("source_sha256") != SOURCE_SHA
            or prior.get("elf_va") != "0x328dc" or prior.get("size_bytes") != SIZE
            or prior.get("original_source_body_sha256") != BODY_SHA
            or prior.get("analysis_style") != "normalize"
            or prior.get("c_like_nonempty") is not False):
        raise RuntimeError("historical alternate-pass identity/result mismatch")
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        if elf["e_machine"] != "EM_AARCH64":
            raise RuntimeError("original source is not AArch64")
        dynsym = elf.get_section_by_name(".dynsym")
        aliases = [s for s in dynsym.iter_symbols() if s["st_info"]["type"] == "STT_FUNC"
                   and s["st_shndx"] != "SHN_UNDEF" and int(s["st_value"]) == ELF_VA
                   and int(s["st_size"]) > 0]
        if not any(s.name == "WebPConvertRGBA32ToUV_C" and int(s["st_size"]) == SIZE
                   for s in aliases):
            raise RuntimeError("pinned dynamic export missing")
        mappings = []
        for seg in elf.iter_segments():
            if seg["p_type"] != "PT_LOAD":
                continue
            lo = int(seg["p_vaddr"])
            if lo <= ELF_VA and ELF_VA + SIZE <= lo + int(seg["p_filesz"]):
                mappings.append(int(seg["p_offset"]) + ELF_VA - lo)
        if len(mappings) != 1:
            raise RuntimeError("original PT_LOAD body mapping ambiguous")
        offset = mappings[0]
        body = source_bytes[offset:offset + SIZE]
        if sha256(body) != BODY_SHA:
            raise RuntimeError("original function-body SHA mismatch")

    cap = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    decoded = list(cap.disasm(body, ELF_VA))
    if len(decoded) != 156 or sum(ins.size for ins in decoded) != SIZE:
        raise RuntimeError("original body is not 156 complete AArch64 words")
    if [ins.address for ins in decoded] != list(range(ELF_VA, ELF_VA + SIZE, 4)):
        raise RuntimeError("original instruction addresses not contiguous")
    image_base = int(prior["image_base"], 16)
    historical = prior["instructions"]
    if len(historical) != len(decoded):
        raise RuntimeError("historical Ghidra instruction count differs")
    pcode_by_va = {}
    for line in prior["pcode"]:
        match = re.match(r"^([0-9a-fA-F]+):\s+", line)
        if match is None:
            raise RuntimeError("historical p-code line lacks address")
        va = int(match.group(1), 16) - image_base
        if not ELF_VA <= va < ELF_VA + SIZE or (va - ELF_VA) % 4:
            raise RuntimeError("historical p-code address not original-instruction aligned")
        pcode_by_va[va] = pcode_by_va.get(va, 0) + 1
    rows = []
    for idx, (ins, line) in enumerate(zip(decoded, historical)):
        match = re.match(r"^([0-9a-fA-F]+):\s+", line)
        if match is None or int(match.group(1), 16) - image_base != ins.address:
            raise RuntimeError(f"historical Ghidra instruction #{idx} not source aligned")
        rows.append({"index": idx, "elf_va": f"0x{ins.address:x}",
                     "source_file_offset": f"0x{offset + idx * 4:x}",
                     "source_word_hex": ins.bytes.hex(),
                     "capstone": f"{ins.mnemonic} {ins.op_str}".strip(),
                     "historical_ghidra": line,
                     "historical_pcode_ops": pcode_by_va.get(ins.address, 0)})
    if sum(row["historical_pcode_ops"] for row in rows) != len(prior["pcode"]):
        raise RuntimeError("historical p-code op coverage differs")

    controls = []
    leaders = {ELF_VA}
    for ins in decoded:
        mnemonic = ins.mnemonic
        conditional = mnemonic.startswith("b.") or mnemonic in ("cbz", "cbnz", "tbz", "tbnz")
        unconditional = mnemonic == "b"
        if not (conditional or unconditional or mnemonic == "ret"):
            continue
        target = None
        if conditional or unconditional:
            match = re.search(r"0x([0-9a-fA-F]+)\s*$", ins.op_str)
            if match is None:
                raise RuntimeError(f"branch target not parsed at {ins.address:x}")
            target = int(match.group(1), 16)
            if ELF_VA <= target < ELF_VA + SIZE:
                leaders.add(target)
            if conditional and ins.address + 4 < ELF_VA + SIZE:
                leaders.add(ins.address + 4)
        controls.append({"from": f"0x{ins.address:x}", "mnemonic": mnemonic,
                         "operand": ins.op_str, "target": f"0x{target:x}" if target is not None else None,
                         "fallthrough": f"0x{ins.address + 4:x}" if conditional else None})
    lead = sorted(leaders)
    blocks = []
    for index, start in enumerate(lead):
        end = lead[index + 1] if index + 1 < len(lead) else ELF_VA + SIZE
        subset = [r for r in rows if start <= int(r["elf_va"], 16) < end]
        blocks.append({"entry": f"0x{start:x}", "end_exclusive": f"0x{end:x}",
                       "instruction_count": len(subset), "last_instruction": subset[-1]["capstone"]})
    sample_n = math.ceil(0.1 * len(rows))
    sample = [rows[round(i * (len(rows) - 1) / (sample_n - 1))] for i in range(sample_n)]
    for row in sample:
        position = int(row["elf_va"], 16) - ELF_VA
        if body[position:position + 4].hex() != row["source_word_hex"]:
            raise RuntimeError("spread sampled source word differs")
    source_proof = {
        "task_id": "TASK_179", "revision": 1, "generated_at": utc_now(),
        "source_path": str(SOURCE), "source_sha256": sha256(source_bytes),
        "source_bytes": len(source_bytes), "elf_machine": "EM_AARCH64",
        "symbol": "WebPConvertRGBA32ToUV_C", "defined_nonzero_dynsym": True,
        "elf_va": f"0x{ELF_VA:x}", "size_bytes": SIZE,
        "file_offset": f"0x{offset:x}", "source_body_sha256": sha256(body),
        "instruction_count": len(rows), "pcode_ops_in_historical_output": len(prior["pcode"]),
        "prior_TASK_175_raw_sha256": sha256(prior_bytes),
        "prior_normalize_c_like_nonempty": prior["c_like_nonempty"],
        "prior_normalize_decompile_completed": prior["decompile_completed"],
        "original_ghidra_memory_sha256_claim": prior["copied_ghidra_memory_sha256"],
        "spread_sample_count": len(sample), "spread_sample_indices": [r["index"] for r in sample],
        "runtime_behavior_verified": False,
    }
    write_json("source_proof.json", source_proof)
    write_json("instruction_evidence.json", {"task_id": "TASK_179", "revision": 1,
               "original_source_body_sha256": BODY_SHA, "rows": rows, "spread_sample": sample})
    write_json("cfg_evidence.json", {"task_id": "TASK_179", "revision": 1,
               "original_source_body_sha256": BODY_SHA, "branch_and_return_edges": controls,
               "basic_blocks": blocks, "source_grounded": True,
               "dynamic_edge_behavior_verified": False})
    write_json("PROGRESS.json", {"task_id": "TASK_179", "revision": 1,
               "status": "SOURCE_INSTRUCTION_CFG_VERIFIED", "generated_at": utc_now(),
               "lease_id": LEASE, "fencing_token": FENCE,
               "original_body_sha256": BODY_SHA, "source_instructions": len(rows),
               "historical_pcode_ops_address_aligned": len(prior["pcode"]),
               "independent_spread_instruction_sample": len(sample),
               "c_like_recovered": False, "independent_ceo_review_pending": True})
    print(json.dumps({"status": "SOURCE_INSTRUCTION_CFG_VERIFIED", "body_sha256": BODY_SHA,
                      "source_instructions": len(rows), "pcode_ops": len(prior["pcode"]),
                      "blocks": len(blocks), "spread_sample": len(sample)}))


if __name__ == "__main__":
    main()
