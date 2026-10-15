"""Independent bounded audit of TASK_233's immutable static-research package."""
import hashlib
import json
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile

R = Path(__file__).resolve().parents[3]
P = R / 'RULES/REPORT/TASK_233_REPORT_R1'
T = R / 'RULES/TASK/TASK_233_SO45_INTERNAL_CONTINUATION_ACTIVE.md'
M = R / '.ai/ceo/reviews/TASK_233_internal_targets.json'
sha = lambda b: hashlib.sha256(b).hexdigest()
C = json.loads((P / 'COMPLETE.json').read_text(encoding='utf8'))
S = json.loads((P / 'source_index.json').read_text(encoding='utf8'))
V = json.loads((P / 'verification_summary.json').read_text(encoding='utf8'))
manifest = json.loads(M.read_text(encoding='utf8'))
assert C['task_id'] == 'TASK_233' and C['revision'] == 1 and C['status'] == 'COMPLETE'
assert sha(T.read_bytes()) == C['task_sha256']
assert sha(M.read_bytes()) == C['target_manifest_sha256'] == S['target_manifest_sha256']
source = Path(S['source_path'])
data = source.read_bytes()
assert sha(data) == C['original_so_sha256'] == S['source_sha256']
for group, base in [('files', P), ('code_files', R), ('scratch_files', R)]:
    for rel, expected in C[group].items():
        f = base / rel
        assert f.exists() and sha(f.read_bytes()) == expected, rel
with source.open('rb') as fp:
    elf = ELFFile(fp)
    fde = {(e.header['initial_location'], e.header['address_range']) for e in elf.get_dwarf_info().EH_CFI_entries() if isinstance(e, FDE)}
    loads = [e for e in elf.iter_segments() if e['p_type'] == 'PT_LOAD']
selected = S['selected']
indices = [126, 177, 182, 186, 253, 283, 389, 449, 509, 567, 568]
assert len(selected) == len(manifest['targets']) == 11
assert [r['global_index'] for r in selected] == indices
raw = {}
for batch in range(1, 12):
    paths = list((P / f'ghidra_raw_batch{batch}').glob('*.json'))
    assert len(paths) == 1, (batch, len(paths))
    receipt = json.loads((P / f'ghidra_batch{batch}_command.json').read_text(encoding='utf8'))
    assert receipt['exit_code'] == 0 and receipt['max_cpu'] == 1 and receipt['max_heap'] == '1G'
    assert receipt['max_per_decompile_seconds'] == 15
    for f in paths:
        row = json.loads(f.read_text(encoding='utf8'))
        assert row['index'] not in raw
        raw[row['index']] = row
assert set(raw) == set(indices)
dis = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
bytes_ = slots = listed = missing = pcode = full = nonempty = 0
for row, target in zip(selected, manifest['targets']):
    idx, va, size, off = row['global_index'], int(row['elf_va'], 16), row['size_bytes'], int(row['file_offset'], 16)
    assert idx == target['global_index'] and size == target['size_bytes']
    assert (va, size) in fde
    assert any(seg['p_vaddr'] <= va and va + size <= seg['p_vaddr'] + seg['p_filesz'] and off == seg['p_offset'] + va - seg['p_vaddr'] for seg in loads)
    body = data[off:off + size]
    assert sha(body) == row['source_body_sha256'] == target['body_sha256']
    af = P / row['source_evidence']
    assert sha(af.read_bytes()) == row['source_evidence_sha256']
    assembly = json.loads(af.read_text(encoding='utf8'))['instructions']
    instructions = list(dis.disasm(body, va))
    assert len(instructions) == row['decoded_slots'] == row['instruction_slots'] == len(assembly)
    for actual, claimed in zip(instructions, assembly):
        assert actual.address == int(claimed['elf_va'], 16) and actual.bytes.hex() == claimed['word_hex']
    gh = raw[idx]
    assert gh['elf_va'] == row['elf_va'] and gh['size_bytes'] == size
    assert gh['ghidra_memory_sha256'] == sha(body)
    assert gh['instruction_slots'] == len(instructions)
    assert gh['fde_byte_membership_count'] <= size
    assert gh['extra_body_address_count'] == 0 and gh['other_function_byte_count'] == 0
    assert bool(gh['c_like_text'].strip()) == bool(gh['c_like_nonempty'])
    if idx == 253:
        assert not gh['c_like_nonempty'] and gh['decompile_error']
    else:
        assert gh['c_like_nonempty']
    bytes_ += size
    slots += len(instructions)
    listed += gh['ghidra_instruction_count']
    missing += gh['missing_analyzed_instruction_count']
    pcode += gh['ghidra_pcode_ops']
    full += gh['fde_byte_membership_count'] == size
    nonempty += bool(gh['c_like_nonempty'])
assert (bytes_, slots, listed, missing, pcode, full, nonempty) == (100288, 25072, 23892, 1180, 78758, 2, 10)
assert V['original_bytes_verified'] == bytes_ and V['original_instruction_words_verified'] == slots
assert V['ghidra_decompile_error_indices'] == [253] and V['nonempty_c_like_outputs'] == 10
spread = json.loads((P / 'source_spread_recheck.json').read_text(encoding='utf8'))
assert len(spread['samples']) == spread['checked_slots'] == 2512 >= slots // 10
by_index = {r['global_index']: r for r in selected}
for sample in spread['samples']:
    row = by_index[sample['index']]
    off = int(row['file_offset'], 16) + sample['slot'] * 4
    va = int(sample['elf_va'], 16)
    assert va == int(row['elf_va'], 16) + sample['slot'] * 4
    assert data[off:off + 4].hex() == sample['word_hex']
    instruction = list(dis.disasm(data[off:off + 4], va))
    assert len(instruction) == 1
    assert f'{instruction[0].mnemonic} {instruction[0].op_str}'.strip() == sample['assembly']
assert V['spread_provenance_mismatches'] == 0 and V['project_files_unchanged']
print(json.dumps({'task': 'TASK_233', 'report_files': len(C['files']), 'code_files': len(C['code_files']), 'scratch_files': len(C['scratch_files']), 'source_bodies': 11, 'source_slots': slots, 'source_bytes': bytes_, 'sample_slots': len(spread['samples']), 'c_like_outputs': nonempty, 'decompile_error_indices': [253], 'full_fde': full, 'missing_listing_slots': missing, 'pcode_ops': pcode}))
