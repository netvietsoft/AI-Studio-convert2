import hashlib, json
from pathlib import Path
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile
from elftools.dwarf.callframe import FDE

R=Path(__file__).resolve().parents[3]
P=R/'RULES/REPORT/TASK_238_REPORT_R1'
T=R/'RULES/TASK/TASK_238_SO45_INTERNAL_CONTINUATION_ACTIVE.md'
M=R/'.ai/ceo/reviews/TASK_238_internal_targets.json'
C=json.loads((P/'COMPLETE.json').read_text(encoding='utf8'))
S=json.loads((P/'source_index.json').read_text(encoding='utf8'))
V=json.loads((P/'verification_summary.json').read_text(encoding='utf8'))
SRC=Path(S['source_path'])
sha=lambda b:hashlib.sha256(b).hexdigest()
assert C['task_id']=='TASK_238' and C['revision']==1 and C['status']=='COMPLETE'
assert sha(T.read_bytes())==C['task_sha256']
assert sha(M.read_bytes())==C['target_manifest_sha256']==S['target_manifest_sha256']
data=SRC.read_bytes(); assert sha(data)==C['original_so_sha256']==S['source_sha256']
for group,base in [('files',P),('code_files',R),('scratch_files',R)]:
    for rel,h in C.get(group,{}).items():
        f=base/rel; assert f.exists(),rel; assert sha(f.read_bytes())==h,rel
with SRC.open('rb') as fp:
    elf=ELFFile(fp)
    fde={(e.header['initial_location'],e.header['address_range']) for e in elf.get_dwarf_info().EH_CFI_entries() if isinstance(e,FDE)}
    load=[e for e in elf.iter_segments() if e['p_type']=='PT_LOAD']
rows=S['selected']; assert len(rows)==506
allraw={}
for batch in range(1,17):
    paths=list((P/f'ghidra_raw_batch{batch}').glob('*.json'))
    assert len(paths)==(26 if batch==16 else 32),(batch,len(paths))
    receipt=json.loads((P/f'ghidra_batch{batch}_command.json').read_text(encoding='utf8'))
    assert '0' in str(receipt.get('returncode',receipt.get('exit_code',0)))
    for f in paths:
        x=json.loads(f.read_text(encoding='utf8')); assert x['index'] not in allraw; allraw[x['index']]=x
dis=Cs(CS_ARCH_ARM64,CS_MODE_ARM)
slots=bytes_=listed=missing=pcode=full=0
for row in rows:
    idx=row['global_index']; va=int(row['elf_va'],16); size=row['size_bytes']; off=int(row['file_offset'],16)
    assert (va,size) in fde
    assert any(seg['p_vaddr']<=va and va+size<=seg['p_vaddr']+seg['p_filesz'] and off==seg['p_offset']+va-seg['p_vaddr'] for seg in load)
    body=data[off:off+size]; assert sha(body)==row['source_body_sha256']
    asmfile=P/row['source_evidence']; assert sha(asmfile.read_bytes())==row['source_evidence_sha256']
    a=json.loads(asmfile.read_text(encoding='utf8')); ins=list(dis.disasm(body,va))
    assert len(ins)==row['decoded_slots']==row['instruction_slots']==len(a['instructions'])
    for x,y in zip(ins,a['instructions']):
        assert x.address==int(y['elf_va'],16) and x.bytes.hex()==y['word_hex']
    raw=allraw[idx]
    assert raw['elf_va']==row['elf_va'] and raw['size_bytes']==size
    assert raw['ghidra_memory_sha256']==sha(body) and raw['c_like_nonempty'] and raw['c_like_text'].strip()
    assert raw['instruction_slots']==len(ins)
    assert raw['fde_byte_membership_count']<=size and raw['extra_body_address_count']==0
    if idx in (3588,3590):
        assert raw['other_function_byte_count']==(12 if idx==3588 else 92)
    else:
        assert raw['other_function_byte_count']==0
    slots+=len(ins); bytes_+=size; listed+=raw['ghidra_instruction_count']; missing+=raw['missing_analyzed_instruction_count']; pcode+=raw['ghidra_pcode_ops']; full+=raw['fde_byte_membership_count']==size
assert slots==V['original_instruction_words_verified']==48116
assert bytes_==V['original_bytes_verified']==192464
assert listed==V['ghidra_listing_positions']==48036
assert missing==V['ghidra_missing_listing_positions']==80
assert pcode==V['ghidra_pcode_operations']==145757
assert full==V['full_fde_body_membership_rows']==496
spread=json.loads((P/'source_spread_recheck.json').read_text(encoding='utf8'))
assert len(spread['samples'])==spread['checked_slots']>=slots//10
for q in spread['samples']:
    r=next(x for x in rows if x['global_index']==q['index']); off=int(r['file_offset'],16)+q['slot']*4
    assert data[off:off+4].hex()==q['word_hex']
    ins=list(dis.disasm(data[off:off+4],int(q['elf_va'],16))); assert len(ins)==1
    assert f'{ins[0].mnemonic} {ins[0].op_str}'.strip()==q['assembly']
assert V['spread_provenance_mismatches']==0 and V['project_files_unchanged']
assert V['other_function_overlap_rows']==2
report=(P/'01_MASTER_REPORT.md').read_text(encoding='utf8')
assert '504 C-like candidate rows lack this specific overlap' in report
assert 'none is independently decoded or behavior-equivalent source code' in report
assert '[3867, 3877, 4025, 4051, 4052, 4066]' in report
assert '[450, 499, 555, 2293, 2775, 2776, 3106, 3132, 3134, 3285, 3523]' in report
assert '[1542, 1586, 1620, 1623, 1626, 1830, 1912]' in report
print(json.dumps({'task':'TASK_238','report_files':len(C['files']),'code_files':len(C['code_files']),'scratch_files':len(C['scratch_files']),'source_bodies':506,'source_slots':slots,'source_bytes':bytes_,'sample_slots':len(spread['samples']),'full_fde':full,'missing_listing_slots':missing,'pcode_ops':pcode}))
