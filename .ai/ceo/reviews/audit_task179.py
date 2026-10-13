"""Read-only independent CEO audit of sealed TASK_179 R1."""
import hashlib
import json
import math
import re
from collections import Counter
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_179_REPORT_R1"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libglide-webp.so")

def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

seal = json.loads((REPORT / "COMPLETE.json").read_text(encoding="utf-8"))
assert (seal["task_id"], seal["revision"], seal["status"]) == ("TASK_179", 1, "COMPLETE")
assert seal["new_scalar_tail_c_like"] and not seal["new_whole_original_function_c_like"]
assert not seal["verified_behavior"]
assert sha(ROOT / "RULES/TASK/TASK_179_SO45_CODEX_GAP_RECOVERY_ACTIVE.md") == seal["task_sha256"]
assert sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") == seal["standard_sha256"]
assert {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file() and p.name not in {"COMPLETE.json", "PROGRESS.json"}} == set(seal["files"])
for relative, expected in seal["files"].items():
    assert sha(REPORT / relative) == expected, relative
for relative, expected in seal["code_files"].items():
    assert sha(ROOT / relative) == expected, relative
assert sha(SOURCE) == seal["source_sha256"]
start, size = 0x328dc, 624
with SOURCE.open("rb") as stream:
    elf = ELFFile(stream)
    assert elf["e_machine"] == "EM_AARCH64"
    sym = elf.get_section_by_name(".dynsym")
    matches = [s for s in sym.iter_symbols() if s.name == "WebPConvertRGBA32ToUV_C"
               and s["st_info"]["type"] == "STT_FUNC" and s["st_shndx"] != "SHN_UNDEF"
               and int(s["st_value"]) == start and int(s["st_size"]) == size]
    assert len(matches) == 1
    loads = [(int(p["p_vaddr"]), int(p["p_offset"]), int(p["p_filesz"]))
             for p in elf.iter_segments() if p["p_type"] == "PT_LOAD"]
cover = [(va, off) for va, off, span in loads if va <= start and start + size <= va + span]
assert len(cover) == 1
va, off = cover[0]
offset = off + start - va
body = SOURCE.read_bytes()[offset:offset+size]
assert len(body) == size and hashlib.sha256(body).hexdigest() == seal["original_body_sha256"]
proof = json.loads((REPORT / "source_proof.json").read_text(encoding="utf-8"))
assert (proof["symbol"], proof["elf_va"], proof["size_bytes"], proof["file_offset"]) == ("WebPConvertRGBA32ToUV_C", hex(start), size, hex(offset))
assert proof["source_body_sha256"] == seal["original_body_sha256"]

historical = json.loads((REPORT / "historical_TASK_155_target.json").read_text(encoding="utf-8"))
histrow = historical["target_row"]
assert sha(ROOT / "RULES/REPORT/TASK_155_REPORT_R1/libglide-webp.so/ghidra_raw.json") == historical["historical_raw_sha256"]
assert histrow["expected_source_sha256"] == seal["original_body_sha256"]
assert not histrow["decompile_success"] and "Unable to find unique hash" in histrow["error"]
normal = json.loads((REPORT / "historical_TASK_175_normalize_raw.json").read_text(encoding="utf-8"))
assert normal["source_sha256"] == seal["source_sha256"]
assert normal["original_source_body_sha256"] == seal["original_body_sha256"]
assert normal["decompile_completed"] and not normal["c_like_nonempty"] and not normal["c_like"]

evidence = json.loads((REPORT / "instruction_evidence.json").read_text(encoding="utf-8"))
rows = evidence["rows"]
assert len(rows) == size // 4 == 156
decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
decoded = list(decoder.disasm(body, start))
assert len(decoded) == len(rows) and decoded[-1].address == start + size - 4
for i, (row, ins) in enumerate(zip(rows, decoded)):
    address = start + 4 * i
    assert row["index"] == i and int(row["elf_va"], 16) == address
    assert int(row["source_file_offset"], 16) == offset + 4 * i
    assert row["source_word_hex"] == body[4*i:4*i+4].hex()
    assert ins.address == address and row["capstone"] == (ins.mnemonic + " " + ins.op_str).strip()
    assert int(row["historical_ghidra"].split(":", 1)[0], 16) == 0x100000 + address
    assert row["historical_ghidra"] == histrow["instructions"][i]
pcodes = normal["pcode"]
assert len(pcodes) == 1307 == sum(row["historical_pcode_ops"] for row in rows)
counts = Counter(int(op.split(":", 1)[0], 16) for op in pcodes)
for row in rows:
    assert counts[0x100000 + int(row["elf_va"], 16)] == row["historical_pcode_ops"]
assert sum(counts.values()) == len(pcodes)
samples = evidence["spread_sample"]
assert len(samples) >= math.ceil(len(rows) / 10)
for sample in samples:
    i = sample["index"]
    assert sample == rows[i]
    assert sample["source_word_hex"] == body[i*4:i*4+4].hex()

cfg = json.loads((REPORT / "cfg_evidence.json").read_text(encoding="utf-8"))
branches = cfg["branch_and_return_edges"]
assert len(branches) == 8 and len(cfg["basic_blocks"]) == 11
for edge in branches:
    address = int(edge["from"], 16)
    ins = decoded[(address-start)//4]
    assert (ins.mnemonic, ins.op_str) == (edge["mnemonic"], edge["operand"])
    if edge["target"]:
        assert int(edge["target"], 16) in [x.address for x in decoded]
cursor = start
for block in cfg["basic_blocks"]:
    a, z = int(block["entry"], 16), int(block["end_exclusive"], 16)
    assert a == cursor and a < z <= start + size
    assert (z-a)//4 == block["instruction_count"]
    assert block["last_instruction"] == (decoded[(z-start)//4-1].mnemonic + " " + decoded[(z-start)//4-1].op_str).strip()
    cursor = z
assert cursor == start + size

command = json.loads((REPORT / "probe_command.json").read_text(encoding="utf-8"))
assert command["status"] == "OUTPUT_READY" and command["exit_code"] == 0 and not command["timed_out"]
assert command["elapsed_seconds"] < 180 and command["decompile_passes"] == 1
assert command["max_cpu"] == 1 and command["GHIDRA_HEADLESS_MAXMEM"] == "1G"
args = command["command"]
assert "-process" in args and "-noanalysis" in args and "-readOnly" in args and "-max-cpu" in args
assert "-import" not in args and "ScalarTailProbe179.java" in args
assert sha(ROOT / "scripts/task_179_codex_exports/ScalarTailProbe179.java") == command["script_sha256"]
assert sha(REPORT / "probe_stdout.log") == command["stdout_sha256"]
assert sha(REPORT / "probe_stderr.log") == command["stderr_sha256"]
assert sha(REPORT / "scalar_tail_probe_raw.json") == command["result_sha256"]
stdout = (REPORT / "probe_stdout.log").read_text(errors="replace")
assert "scalar-tail-only probe completed=true c_like_nonempty=true" in stdout
assert "Discarding changes to the following read-only file" in stdout
before = command["historical_project_files_sha256_before"]
assert before == command["copied_project_files_sha256_before"]
assert before == command["historical_project_files_sha256_after"]
historical_project = ROOT / "RESEARCH_WORK/TASK_155_R1/libglide-webp.so/ghidra_project"
assert {p.relative_to(historical_project).as_posix(): sha(p) for p in historical_project.rglob("*") if p.is_file()} == before
assert command["copied_project_files_sha256_after"]["SmallLib155.rep/idata/00/~00000000.db/db.1.gbf"] == before["SmallLib155.rep/idata/00/~00000000.db/db.1.gbf"]
probe = json.loads((REPORT / "scalar_tail_probe_raw.json").read_text(encoding="utf-8"))
assert probe["source_body_sha256"] == seal["original_body_sha256"] == probe["copied_project_memory_sha256"]
assert probe["synthetic_tail_elf_va"] == "0x32ab8" and probe["synthetic_tail_end_elf_va"] == "0x32b48"
assert probe["decompile_completed"] and probe["scalar_tail_c_like_nonempty"]
assert not probe["whole_original_function_decompiled"]
scalar = probe["scalar_tail_c_like"]
assert "TASK_179_scalar_tail_probe" in scalar and "in_x9" in scalar
for coefficient in ("-0x4a89", "-0x25f7", "0x7080", "-0x5e34", "-0x124c"):
    assert coefficient in scalar
print(json.dumps({"task":"TASK_179","result":"PASS","seal_sha256":sha(REPORT / "COMPLETE.json"),"original_bytes":len(body),"instructions":len(decoded),"pcode_ops":len(pcodes),"blocks":len(cfg["basic_blocks"]),"spread_sample":len(samples),"scalar_tail_only":True},sort_keys=True))
