"""Independent, read-only CEO audit of TASK_175 original and historical evidence."""

from __future__ import annotations

import hashlib
import json
import math
import re
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile


ROOT = Path(__file__).resolve().parents[3]
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a")
REPORT = ROOT / "RULES/REPORT/TASK_175_REPORT_R1"
OLD = ROOT / "RULES/REPORT/TASK_155_REPORT_R1"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
TASK = ROOT / "RULES/TASK/TASK_175_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md"
SOURCES = {
    "libfantasy.so": ("fefb87a88745a4aa8e8dcc421c7ec46a91a648e7afef86a312d1a3776a8c7724", 197, 197),
    "libglide-webp.so": ("2f7f38acc0d294a3333069aa8a3c07e69d4bc0a64f162215578bd55dbe1a4486", 230, 229),
}


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def read(path: Path):
    return json.loads(path.read_text(encoding="utf-8"))


def main() -> None:
    seal_path = REPORT / "COMPLETE.json"
    seal_sha = sha(seal_path)
    seal = read(seal_path)
    assert (seal["task_id"], seal["revision"], seal["status"], seal["semantic_disposition"]) == ("TASK_175", 1, "COMPLETE", "PARTIAL_RESEARCH_CANDIDATE")
    assert seal["standard_sha256"] == sha(STANDARD) and seal["task_sha256"] == sha(TASK)
    assert seal["fencing_token"] == 1204 and seal["execution_mode"] == "REAL_CODEX_SUBAGENT_NO_AGY"
    assert seal["internal_nonexported_functions_covered"] is False and seal["runtime_or_pixel_semantics_proven"] is False
    actual = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()} - {"COMPLETE.json", "PROGRESS.json"}
    assert actual == set(seal["files"])
    for relative, digest in seal["files"].items():
        assert sha(REPORT / relative) == digest, relative
    for relative, digest in seal["code_files"].items():
        assert sha(ROOT / relative) == digest, relative
    assert len(seal["code_files"]) == 5 and len(actual) == 24
    audit_text = (REPORT / "00_AUDIT_INDEX.md").read_text(encoding="utf-8").lower()
    assert seal["standard_sha256"] in audit_text and seal["task_sha256"] in audit_text

    old_seal = read(OLD / "COMPLETE.json")
    assert old_seal["task_id"] == "TASK_155" and old_seal["revision"] == 1
    assert sha(REPORT / "historical_TASK_155_R1/COMPLETE.json") == sha(OLD / "COMPLETE.json")
    for relative, digest in old_seal["files"].items():
        assert sha(OLD / relative) == digest, relative
    old_script = ROOT / "scripts/task155_direct_four_mixedlibs/ExportSmallLib155.java"
    assert sha(old_script) == sha(REPORT / "historical_TASK_155_R1/ExportSmallLib155.java")

    index = read(REPORT / "source_index.json")
    verify = read(REPORT / "historical_revalidation.json")
    assert len(index["targets"]) == len(verify["records"]) == 427
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    c_like = 0
    sampled = 0
    missing = []
    for name, (source_sha, expected_count, expected_c) in SOURCES.items():
        assert sha(SOURCE / name) == source_sha
        history = REPORT / "historical_TASK_155_R1" / name
        for filename in ("target_index.json", "targets.tsv", "ghidra_command.json", "ghidra_stdout.log", "ghidra_stderr.log", "ghidra_raw.json"):
            assert sha(history / filename) == sha(OLD / name / filename)
        old_index = read(history / "target_index.json")
        raw = read(history / "ghidra_raw.json")
        command = read(history / "ghidra_command.json")
        assert command["status"] == "OUTPUT_READY" and command["exit_code"] == 0
        assert command["result_sha256"] == sha(history / "ghidra_raw.json")
        assert command["target_tsv_sha256"] == sha(history / "targets.tsv")
        assert command["stdout_sha256"] == sha(history / "ghidra_stdout.log")
        assert command["stderr_sha256"] == sha(history / "ghidra_stderr.log")
        assert "-import" in command["command"] and command["elapsed_seconds"] <= 900
        assert "Import succeeded" in (history / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace")
        image_base = int(raw["image_base"], 16)
        own_index = [r for r in index["targets"] if r["library"] == name]
        own_verify = [r for r in verify["records"] if r["library"] == name]
        assert len(own_index) == len(own_verify) == len(old_index["targets"]) == len(raw["targets"]) == expected_count
        with (SOURCE / name).open("rb") as stream:
            elf = ELFFile(stream)
            assert elf["e_machine"] == "EM_AARCH64"
            by_va = {}
            for symbol in elf.get_section_by_name(".dynsym").iter_symbols():
                if symbol["st_info"]["type"] == "STT_FUNC" and symbol["st_shndx"] != "SHN_UNDEF" and int(symbol["st_size"]) and int(symbol["st_value"]):
                    by_va.setdefault(int(symbol["st_value"]), []).append((symbol.name, int(symbol["st_size"])))
            assert len(by_va) == expected_count
            loads = [s for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
            bytes_ = (SOURCE / name).read_bytes()
        positions = sorted({round(i * (expected_count - 1) / (math.ceil(expected_count * .1) - 1)) for i in range(math.ceil(expected_count * .1))})
        assert len(positions) == math.ceil(expected_count * .1)
        lib_c = 0
        for pos, (target, old_target, row, verified) in enumerate(zip(own_index, old_index["targets"], raw["targets"], own_verify), 1):
            va = int(target["elf_va"], 16)
            aliases = sorted(by_va[va], key=lambda x: (-x[1], x[0]))
            assert (target["index"], target["symbol"], target["size_bytes"]) == (pos, aliases[0][0], aliases[0][1])
            assert old_target["aliases"] == [n for n, _ in aliases]
            for key in ("index", "elf_va", "symbol", "size_bytes", "file_offset", "source_body_sha256"):
                assert target[key] == old_target[key], (name, pos, key)
            mapped = [int(s["p_offset"]) + va - int(s["p_vaddr"]) for s in loads if int(s["p_vaddr"]) <= va and va + target["size_bytes"] <= int(s["p_vaddr"]) + int(s["p_filesz"])]
            assert len(mapped) == 1 and int(target["file_offset"], 16) == mapped[0]
            body = bytes_[mapped[0]:mapped[0] + target["size_bytes"]]
            digest = hashlib.sha256(body).hexdigest()
            assert digest == target["source_body_sha256"] == row["expected_source_sha256"] == row["ghidra_memory_sha256"] == verified["source_body_sha256"]
            assert row["source_bytes_match"] is True and int(row["database_va"], 16) == image_base + va
            assert row["index"] == pos and row["symbol"] == target["symbol"] and row["size_bytes"] == len(body)
            good = bool(row["decompile_success"] and row["pseudocode"].strip() and not row["error"])
            assert good == verified["historical_c_like_recovered"]
            lib_c += good
            c_like += good
            if not good:
                missing.append((name, pos, va, row["error"]))
            if pos - 1 in positions:
                decoded = list(decoder.disasm(body, va))
                assert sum(ins.size for ins in decoded) == len(body)
                observed = []
                for line in row["instructions"]:
                    match = re.match(r"^([0-9a-fA-F]+):\s+", line)
                    assert match is not None
                    observed.append(int(match.group(1), 16) - image_base)
                assert observed == sorted(set(observed)) and all(addr in {ins.address for ins in decoded} for addr in observed)
                sampled += 1
        assert lib_c == expected_c
    assert c_like == 426 and sampled == 43
    assert len(missing) == 1 and missing[0][:3] == ("libglide-webp.so", 144, 0x328dc)
    assert seal["source_bodies_rehashed"] == 427 and seal["historical_c_like_bodies_revalidated"] == 426
    assert seal["new_c_like_bodies_recovered"] == 0

    source = (SOURCE / "libglide-webp.so").read_bytes()
    body = source[0x328dc:0x328dc + 624]
    assert len(body) == 624 and hashlib.sha256(body).hexdigest() == "fc4cf89d6b719a3d8d73009a57a1e755ca9ce11dda3bdd03da45c5b869053404"
    decoded = list(decoder.disasm(body, 0x328dc))
    assert len(decoded) == 156 and sum(i.size for i in decoded) == len(body)
    alt = read(REPORT / "alternative_normalize_raw.json")
    receipt = read(REPORT / "attempt_command.json")
    assert receipt["status"] == "OUTPUT_READY" and receipt["exit_code"] == 0 and receipt["fresh_imports"] == 0
    assert receipt["decompile_target_count"] == 1 and receipt["decompile_target_elf_va"] == "0x328dc"
    assert "-readOnly" in receipt["command"] and "-import" not in receipt["command"]
    assert receipt["result_sha256"] == sha(REPORT / "alternative_normalize_raw.json")
    assert receipt["stdout_sha256"] == sha(REPORT / "alternative_ghidra_stdout.log")
    assert receipt["stderr_sha256"] == sha(REPORT / "alternative_ghidra_stderr.log")
    assert receipt["max_cpu"] == 1 and receipt["GHIDRA_HEADLESS_MAXMEM"] == "1G" and receipt["elapsed_seconds"] <= 900
    assert alt["copied_ghidra_memory_sha256"] == hashlib.sha256(body).hexdigest()
    assert alt["analysis_style"] == "normalize" and alt["analysis_style_supported"] is True
    assert alt["decompile_completed"] is True and alt["c_like_nonempty"] is False and not alt["c_like"].strip()
    assert len(alt["instructions"]) == 156 and alt["instruction_count"] == 156 and len(alt["pcode"]) == 1307
    addresses = [int(re.match(r"^([0-9a-fA-F]+):", line).group(1), 16) - int(alt["image_base"], 16) for line in alt["instructions"]]
    assert addresses == [ins.address for ins in decoded]
    pcode = [int(re.match(r"^([0-9a-fA-F]+):", line).group(1), 16) - int(alt["image_base"], 16) for line in alt["pcode"]]
    assert set(pcode) <= set(addresses)
    project = read(REPORT / "project_copy_inventory.json")
    source_project = ROOT / "RESEARCH_WORK/TASK_155_R1/libglide-webp.so/ghidra_project"
    assert project["source_files_sha256"] == {p.relative_to(source_project).as_posix(): sha(p) for p in source_project.rglob("*") if p.is_file()}
    assert sha(seal_path) == seal_sha
    print(json.dumps({"result": "PASS", "task": "TASK_175", "manifest_files": len(actual), "original_export_vas": 427, "historical_c_like": 426, "new_c_like": 0, "remaining_va": "0x328dc", "source_and_ghidra_hashes_checked": 427, "ordinary_spread_redecoded": sampled, "pcode_ops": len(pcode)}, sort_keys=True))


if __name__ == "__main__":
    main()
