"""Read-only independent CEO audit of sealed TASK_178 R1."""
import csv
import hashlib
import json
import math
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_178_REPORT_R1"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libdexvmp.so")

def digest(data):
    return hashlib.sha256(data).hexdigest()

def number(value):
    return int(value, 16) if isinstance(value, str) else int(value)

seal_bytes = (REPORT / "COMPLETE.json").read_bytes()
seal = json.loads(seal_bytes)
assert seal["task_id"] == "TASK_178" and seal["revision"] == 1
assert seal["status"] == "COMPLETE" and not seal["ghidra_c_like_whole_function"]
assert not seal["behavior_verified"] and not seal["phase_pass"]
assert digest((ROOT / "RULES/TASK/TASK_178_SO45_CODEX_GAP_RECOVERY_ACTIVE.md").read_bytes()) == seal["task_sha256"]
assert digest((ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt").read_bytes()) == seal["standard_sha256"]
assert {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file() and p.name not in {"COMPLETE.json", "PROGRESS.json"}} == set(seal["files"])
for relative, expected in seal["files"].items():
    assert digest((REPORT / relative).read_bytes()) == expected, relative
for relative, expected in seal["code_files"].items():
    assert digest((ROOT / relative).read_bytes()) == expected, relative
source = SOURCE.read_bytes()
assert digest(source) == seal["source_sha256"]
start, size = 0x29cd4, 224440
end = start + size
with SOURCE.open("rb") as stream:
    elf = ELFFile(stream)
    assert elf["e_machine"] == "EM_AARCH64"
    sym = elf.get_section_by_name(".dynsym")
    matches = [s for s in sym.iter_symbols() if s["st_info"]["type"] == "STT_FUNC"
               and int(s["st_value"]) == start and int(s["st_size"]) == size
               and s["st_shndx"] != "SHN_UNDEF"]
    assert len(matches) >= 1
    loads = [(int(p["p_vaddr"]), int(p["p_offset"]), int(p["p_filesz"]))
             for p in elf.iter_segments() if p["p_type"] == "PT_LOAD"]
    covering = [(va, off) for va, off, span in loads if va <= start and end <= va + span]
    assert len(covering) == 1
    va, off = covering[0]
    body = source[off + start - va:off + end - va]
assert len(body) == size and digest(body) == seal["body_sha256"]
assert (REPORT / "source_body.bin").read_bytes() == body

with (REPORT / "instruction_stream.tsv").open(encoding="utf-8", newline="") as stream:
    words = list(csv.DictReader(stream, delimiter="\t"))
assert len(words) == size // 4 == 56110
decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
undecoded = 0
for i, row in enumerate(words):
    address = start + 4 * i
    op = body[4 * i:4 * i + 4]
    assert number(row["elf_va"]) == address
    assert number(row["file_offset"]) == off + address - va
    assert row["word_hex_le"] == op.hex()
    ins = next(iter(decoder.disasm(op, address, count=1)), None)
    if ins is None:
        undecoded += 1
        assert row["mnemonic"] == "UNDECODED_WORD"
    else:
        assert (ins.mnemonic, ins.op_str) == (row["mnemonic"], row["op_str"])
assert undecoded == 13

blocks = [json.loads(line) for line in (REPORT / "candidate_blocks.jsonl").read_text(encoding="utf-8").splitlines()]
assert len(blocks) == 5821
lookup = {}
cursor = start
for i, block in enumerate(blocks):
    a, z = number(block["start_va"]), number(block["end_va_exclusive"])
    assert block["id"] == i and a == cursor and a < z <= end
    assert (z - a) // 4 == block["instruction_words"]
    assert digest(body[a - start:z - start]) == block["source_sha256"]
    assert number(block["tail_va"]) == z - 4
    for target in range(a, z, 4):
        lookup[target] = i
    cursor = z
assert cursor == end
with (REPORT / "edge_inventory.tsv").open(encoding="utf-8", newline="") as stream:
    edges = list(csv.DictReader(stream, delimiter="\t"))
assert len(edges) == 10241
for edge in edges:
    source_block = int(edge["source_block"])
    assert 0 <= source_block < len(blocks)
    assert number(edge["source_tail_va"]) == number(blocks[source_block]["tail_va"])
    if edge["target_block"]:
        assert lookup.get(number(edge["target_va"])) == int(edge["target_block"])

table_count = 0
tables = json.loads((REPORT / "jump_tables.json").read_text(encoding="utf-8"))["tables"]
assert {(number(t["table_va"]), t["entries"]) for t in tables} == {(0x6098c, 1800), (0x63574, 1023)}
for table in tables:
    base, count = number(table["table_va"]), table["entries"]
    seg = [(v, o) for v, o, span in loads if v <= base and base + 4 * count <= v + span]
    assert len(seg) == 1
    v, o = seg[0]
    raw = source[o + base - v:o + base - v + 4 * count]
    assert raw == (REPORT / f"jump_table_{base:x}.bin").read_bytes()
    assert digest(raw) == table["table_sha256"]
    assert len(table["entries_detail"]) == count
    for i, entry in enumerate(table["entries_detail"]):
        rel = int.from_bytes(raw[4 * i:4 * i + 4], "little", signed=True)
        target = base + rel
        assert entry["index"] == i and entry["signed_relative_32"] == rel
        assert number(entry["target_va"]) == target and start <= target < end and target % 4 == 0
        assert entry["target_block"] == lookup[target]
        table_count += 1
assert table_count == 2823
guard_words = {0x2a7f0: ("cmp", "w9, #0x707"), 0x2a7f4: ("b.ls", "#0x2a810"),
               0x2a81c: ("ldrsw", "x8, [x9, x8, lsl #2]"), 0x2a844: ("br", "x8"),
               0x4e09c: ("sub", "w9, w8, #0x708"), 0x4e0a0: ("cmp", "w9, #0x3fe"),
               0x4e0a4: ("b.hi", "#0x503f0"), 0x4e0b4: ("ldrsw", "x8, [x10, x9, lsl #2]"),
               0x4e0c4: ("br", "x8")}
for address, expected in guard_words.items():
    assert (words[(address-start)//4]["mnemonic"], words[(address-start)//4]["op_str"]) == expected
anchors = json.loads((REPORT / "ghidra_anchor_audit.json").read_text(encoding="utf-8"))["anchors"]
assert len(anchors) == 1692
for anchor in anchors:
    address = number(anchor["elf_va"])
    assert start <= address < end and (address - start) % 4 == 0
    assert anchor["source_word_hex_le"] == body[address-start:address-start+4].hex()
sample = json.loads((REPORT / "spread_block_sample.json").read_text(encoding="utf-8"))
assert sample["sample_count"] == len(sample["samples"]) >= math.ceil(len(blocks) / 10)
for entry in sample["samples"]:
    block = blocks[entry["block_id"]]
    a, z = number(block["start_va"]), number(block["end_va_exclusive"])
    assert (entry["start_va"], entry["end_va_exclusive"], entry["sha256"]) == (block["start_va"], block["end_va_exclusive"], digest(body[a-start:z-start]))
    assert entry["first_word_hex_le"] == body[a-start:a-start+4].hex()
summary = json.loads((REPORT / "inventory_summary.json").read_text(encoding="utf-8"))
assert (summary["words"], summary["undecoded_words"], summary["candidate_basic_blocks"], summary["candidate_edges"], summary["byte_proven_guarded_jump_table_entries"]) == (56110, 13, 5821, 10241, 2823)
assert summary["other_indirect_jump_sites_unresolved"] == 386
historical = json.loads((REPORT / "historical_raw/task159_huge_ghidra_raw.json").read_text(encoding="utf-8"))
assert "timeout" in str(historical).lower()
print(json.dumps({"task":"TASK_178","result":"PASS","seal_sha256":digest(seal_bytes),"source_words":len(words),"blocks":len(blocks),"edges":len(edges),"guarded_table_entries":table_count,"historical_anchors":len(anchors),"spread_sample":len(sample["samples"]),"unresolved_indirect_jumps":386},sort_keys=True))
