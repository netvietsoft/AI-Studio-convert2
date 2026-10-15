"""TASK_210: source-anchored AArch64 evidence for seven oversized FDEs."""
from __future__ import annotations

import datetime as dt
import hashlib
import json
import os
from pathlib import Path
import tempfile

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile


ROOT = Path(__file__).resolve().parents[2]
REPORT = ROOT / "RULES/REPORT/TASK_210_REPORT_R1"
SOURCE = ROOT.parent / "SOURCE/extracted_native_libs/lib/arm64-v8a/libMTFilterKernel.so"
TARGETS = ROOT / ".ai/ceo/reviews/TASK_209_internal_targets.json"
TASK = ROOT / "RULES/TASK/TASK_210_SO45_CEO_MT_OVERSIZED_ACTIVE.md"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
SOURCE_SHA = "f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4"
TARGETS_SHA = "df650a1801177d429fa60948e023deae985579cd29319fb76b93d7a0561f3a01"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
FENCE = 1248


def sha(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def check_lease() -> None:
    locks = json.loads((ROOT / ".ai/locks.json").read_text(encoding="utf-8"))
    matches = [x for x in locks["active_locks"] if x["lease_id"] == "LEASE-CEO-WORKER-TASK_210-R1"]
    if len(matches) != 1:
        raise RuntimeError("worker lease missing")
    lease = matches[0]
    expiry = dt.datetime.fromisoformat(lease["expiry"].replace("Z", "+00:00"))
    if (lease["agent_id"] != "Codex_CEO" or lease["fencing_token"] != FENCE
            or lease["status"] != "ACTIVE" or expiry <= dt.datetime.now(dt.timezone.utc)
            or lease["task_sha"] != sha(TASK)):
        raise RuntimeError("worker lease invalid")


def write_json(path: Path, value: object) -> None:
    check_lease()
    path.parent.mkdir(parents=True, exist_ok=True)
    data = (json.dumps(value, ensure_ascii=False, indent=2) + "\n").encode("utf-8")
    with tempfile.NamedTemporaryFile(dir=path.parent, prefix=".tmp-", delete=False) as stream:
        tmp = Path(stream.name)
        stream.write(data)
        stream.flush()
        os.fsync(stream.fileno())
    os.replace(tmp, path)


def main() -> None:
    check_lease()
    if sha(STANDARD) != STANDARD_SHA or sha(SOURCE) != SOURCE_SHA or sha(TARGETS) != TARGETS_SHA:
        raise RuntimeError("pinned input mismatch")
    manifest = json.loads(TARGETS.read_text(encoding="utf-8"))
    if [t["global_nonexport_fde_index"] for t in manifest["targets"]] != [211, 216, 235, 293, 304, 349, 362]:
        raise RuntimeError("target set mismatch")
    audit = ("# TASK_210 R1 audit index\n\n"
             f"Canonical Standard fully read: `{STANDARD}`; SHA-256 `{STANDARD_SHA}`.\n"
             f"Read timestamp UTC: {dt.datetime.now(dt.timezone.utc).isoformat()}. "
             f"Actor `Codex_CEO`; lease `LEASE-CEO-WORKER-TASK_210-R1`, fence `{FENCE}`.\n"
             f"Task SHA-256 `{sha(TASK)}`; target SHA-256 `{TARGETS_SHA}`; "
             f"original SO SHA-256 `{SOURCE_SHA}`.\n\n"
             "Original-byte/FDE/Capstone evidence only; function and semantic boundaries remain unproven.\n")
    REPORT.mkdir(parents=True, exist_ok=True)
    check_lease()
    (REPORT / "00_AUDIT_INDEX.md").write_text(audit, encoding="utf-8")
    cs = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    results = []
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        if elf["e_machine"] != "EM_AARCH64":
            raise RuntimeError("wrong ISA")
        all_fdes = [(int(e["initial_location"]), int(e["address_range"]))
                    for e in elf.get_dwarf_info().EH_CFI_entries() if isinstance(e, FDE)]
        dyn = elf.get_section_by_name(".dynsym")
        exports = {int(s["st_value"]) for s in dyn.iter_symbols()
                   if s["st_info"]["type"] == "STT_FUNC" and s["st_shndx"] != "SHN_UNDEF"
                   and int(s["st_value"]) > 0 and int(s["st_size"]) > 0}
        candidates = sorted(f for f in all_fdes if f[0] not in exports)
        if (len(all_fdes), len(exports), len(candidates)) != (2873, 2362, 511):
            raise RuntimeError("FDE/export census changed")
        loads = [(int(p["p_vaddr"]), int(p["p_filesz"]), int(p["p_offset"]))
                 for p in elf.iter_segments() if p["p_type"] == "PT_LOAD"]
        for target in manifest["targets"]:
            check_lease()
            index = target["global_nonexport_fde_index"]
            va, size = candidates[index]
            if (va, size) != (int(target["elf_va"], 16), target["size_bytes"]):
                raise RuntimeError(f"FDE {index} mismatch")
            offsets = [off + va - base for base, length, off in loads
                       if base <= va and va + size <= base + length]
            if len(offsets) != 1 or offsets[0] != int(target["file_offset"], 16):
                raise RuntimeError(f"PT_LOAD {index} mismatch")
            stream.seek(offsets[0])
            body = stream.read(size)
            body_sha = hashlib.sha256(body).hexdigest()
            if body_sha != target["body_sha256"] or len(body) != size or size % 4:
                raise RuntimeError(f"original body {index} mismatch")
            instructions, branches, calls = [], [], []
            for offset in range(0, size, 4):
                word = body[offset:offset+4]
                one = list(cs.disasm(word, va + offset, count=1))
                ins = one[0] if one and one[0].size == 4 else None
                mnemonic = ins.mnemonic if ins else None
                row = {"elf_va": f"0x{va+offset:x}", "word_hex": word.hex(),
                       "assembly": f"{mnemonic} {ins.op_str}".strip() if ins else None}
                instructions.append(row)
                if mnemonic and (mnemonic.startswith("b") or mnemonic in {"cbz", "cbnz", "tbz", "tbnz"}):
                    branches.append(row)
                if mnemonic in {"bl", "blr", "blraa", "blrab", "blraaz", "blrabz"}:
                    calls.append(row)
            evidence = {"task_id": "TASK_210", "revision": 1, "index": index,
                        "elf_va": f"0x{va:x}", "size_bytes": size,
                        "file_offset": f"0x{offsets[0]:x}", "body_sha256": body_sha,
                        "instruction_slots": size // 4,
                        "capstone_decoded_slots": sum(x["assembly"] is not None for x in instructions),
                        "branch_sites": branches, "call_sites": calls,
                        "boundary_classification": "FDE_CANDIDATE_NOT_PROVEN_FUNCTION",
                        "instructions": instructions}
            path = REPORT / "source_assembly" / f"{index}_{va:x}.json"
            write_json(path, evidence)
            results.append({"index": index, "elf_va": f"0x{va:x}", "size_bytes": size,
                            "source_sha256": body_sha, "instruction_slots": size // 4,
                            "decoded_slots": evidence["capstone_decoded_slots"],
                            "branches": len(branches), "calls": len(calls),
                            "evidence_path": str(path.relative_to(ROOT)).replace("\\", "/"),
                            "evidence_sha256": sha(path)})
    write_json(REPORT / "source_index.json", {"task_id": "TASK_210", "revision": 1,
                                              "source_path": str(SOURCE), "source_sha256": SOURCE_SHA,
                                              "target_manifest_sha256": TARGETS_SHA,
                                              "all_fde_count": 2873, "export_starts": 2362,
                                              "nonexport_candidates": 511, "selected": results})
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_210", "revision": 1,
                                           "status": "SOURCE_ANCHORED_OUTPUT_READY",
                                           "generated_at": dt.datetime.now(dt.timezone.utc).isoformat(),
                                           "selected_count": len(results), "original_bytes": sum(x["size_bytes"] for x in results),
                                           "decompiled_count": 0,
                                           "note": "Static source evidence complete; private Ghidra step pending"})
    print(json.dumps({"count": len(results), "bytes": sum(x["size_bytes"] for x in results),
                      "slots": sum(x["instruction_slots"] for x in results),
                      "decoded": sum(x["decoded_slots"] for x in results)}, indent=2))


if __name__ == "__main__":
    main()
