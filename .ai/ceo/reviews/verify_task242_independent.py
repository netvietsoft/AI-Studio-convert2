"""Independently verify sealed TASK_242 source and Ghidra provenance."""
import hashlib
import json
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile

R = Path(__file__).resolve().parents[3]
P = R / 'RULES/REPORT/TASK_242_REPORT_R1'
sha = lambda b: hashlib.sha256(b).hexdigest()
C = json.loads((P / 'COMPLETE.json').read_text(encoding='utf8'))
S = json.loads((P / 'source_index.json').read_text(encoding='utf8'))
V = json.loads((P / 'verification.json').read_text(encoding='utf8'))
M = R / '.ai/ceo/reviews/TASK_242_internal_targets.json'
T = R / 'RULES/TASK/TASK_242_SO45_INTERNAL_CONTINUATION_ACTIVE.md'
manifest = json.loads(M.read_text(encoding='utf8'))
assert C['task_id'] == 'TASK_242' and C['revision'] == 1 and C['status'] == 'COMPLETE'
assert sha(T.read_bytes()) == C['task_sha256']
assert sha(M.read_bytes()) == C['target_manifest_sha256']
assert manifest['selected_count'] == S['selected'] == 505
assert [r['global_index'] for r in manifest['skipped_in_slice']] == [5144, 5145, 5146, 5147, 5148, 5149, 5150]
for rel, expected in C['files'].items():
    path = P / rel
    assert path.exists() and sha(path.read_bytes()) == expected, rel
for rel, expected in C['code_files'].items():
    path = R / rel
    assert path.exists() and sha(path.read_bytes()) == expected, rel
source = R.parent / 'SOURCE/extracted_native_libs/lib/arm64-v8a/libPVGImageCodec.so'
data = source.read_bytes()
assert sha(data) == C['source_sha256'] == S['source_sha256']
with source.open('rb') as fp:
    elf = ELFFile(fp)
    fdes = {(e.header['initial_location'], e.header['address_range']) for e in elf.get_dwarf_info().EH_CFI_entries() if isinstance(e, FDE)}
    loads = [e for e in elf.iter_segments() if e['p_type'] == 'PT_LOAD']
assembly = [json.loads(line) for line in (P / 'assembly.ndjson').read_text(encoding='utf8').splitlines()]
assert len(assembly) == len(S['rows']) == len(V['rows']) == 505
cmd = json.loads((P / 'ghidra/command.json').read_text(encoding='utf8'))
assert cmd['exit_code'] == 0 and cmd['max_cpu'] == 1 and cmd['max_heap'] == '1G'
dis = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
total_bytes = total_slots = listed = pcode_slots = pcode_ops = full = missing = warnings = 0
for row, target, asm, verified in zip(S['rows'], manifest['targets'], assembly, V['rows']):
    i = row['index']
    assert row['global_index'] == target['global_index'] and i == verified['index'] == asm['index']
    va, n, off = int(row['elf_va'], 16), row['size_bytes'], int(row['file_offset'], 16)
    assert va == int(target['elf_va'], 16) and n == target['size_bytes'] and off == int(target['file_offset'], 16)
    assert (va, n) in fdes
    assert any(seg['p_vaddr'] <= va and va+n <= seg['p_vaddr']+seg['p_filesz'] and off == seg['p_offset']+va-seg['p_vaddr'] for seg in loads)
    body = data[off:off+n]
    assert sha(body) == row['body_sha256'] == target['body_sha256'] == asm['body_sha256'] == verified['body_sha256']
    ins = list(dis.disasm(body, va))
    assert len(ins) == row['instruction_slots'] == len(asm['instructions'])
    for x, y in zip(ins, asm['instructions']):
        assert x.address == int(y['va'], 16) and x.bytes.hex() == y['word_le']
        assert x.mnemonic == y['mnemonic'] and x.op_str == y['operands']
    raw_path = P / f'ghidra/candidates/candidate_{i:03d}.json'
    assert sha(raw_path.read_bytes()) == verified['raw_sha256']
    raw = json.loads(raw_path.read_text(encoding='utf8'))
    assert raw['index'] == i and raw['elf_va'] == row['elf_va'] and raw['size_bytes'] == n
    assert raw['owned_project_memory_sha256'] == sha(body) and raw['source_bytes_match']
    assert raw['decompile_success'] and raw['pseudocode'].strip()
    assert sha(raw['pseudocode'].encode()) == raw['pseudocode_sha256'] == verified['c_like_sha256']
    assert raw['body_extra_bytes_outside_fde'] == 0 and raw['body_member_bytes_within_fde'] <= n
    assert raw['instruction_count'] == len(ins) and raw['missing_instruction_slots'] == 0
    total_bytes += n; total_slots += len(ins); listed += raw['instruction_count']
    pcode_slots += raw['pcode_instruction_slots']; pcode_ops += raw['pcode_op_count']
    full += raw['body_member_bytes_within_fde'] == n
    missing += n - raw['body_member_bytes_within_fde']
    warnings += 'WARNING:' in raw['pseudocode']
assert (total_bytes, total_slots, listed, pcode_slots, pcode_ops, full, missing, warnings) == (188240, 47060, 47060, 46828, 148171, 505, 0, 164)
sample = V['ordinary_spread_sample']
assert len(sample) == 51 >= 505 // 10
for item in sample:
    row = S['rows'][item['index']-1]
    raw_path = P / f"ghidra/candidates/candidate_{item['index']:03d}.json"
    assert sha(raw_path.read_bytes()) == item['raw_sha256']
    assert row['body_sha256'] == item['body_sha256']
assert V['original_project_before_and_after_hashes_match']
print(json.dumps({'task': 'TASK_242', 'manifest_files': len(C['files']), 'code_files': len(C['code_files']), 'source_bodies': 505, 'source_bytes': total_bytes, 'source_slots': total_slots, 'spread_records': len(sample), 'full_fde': full, 'partial': 505-full, 'warning_texts': warnings, 'pcode_ops': pcode_ops}))
