import hashlib,json
from pathlib import Path
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile
from elftools.dwarf.callframe import FDE

R=Path(__file__).resolve().parents[3]; P=R/'RULES/REPORT/TASK_228_REPORT_R1'
T=R/'RULES/TASK/TASK_228_SO45_INTERNAL_CONTINUATION_ACTIVE.md'
M=R/'.ai/ceo/reviews/TASK_228_internal_targets.json'
C=json.loads((P/'COMPLETE.json').read_text(encoding='utf8'))
S=json.loads((P/'source_project_index.json').read_text(encoding='utf8'))
V=json.loads((P/'evidence_summary.json').read_text(encoding='utf8'))
SRC=Path(S['source_path']); sha=lambda b:hashlib.sha256(b).hexdigest()
assert C['task_id']=='TASK_228' and C['revision']==1 and C['status']=='COMPLETE'
assert sha(T.read_bytes())==C['task_sha256']
assert sha(M.read_bytes())==C['target_manifest_sha256']==S['target_manifest_sha256']
data=SRC.read_bytes(); assert sha(data)==C['original_so_sha256']==S['source_sha256']
for group,base in [('files',P),('code_files',R),('scratch_files',R)]:
    items=C.get(group,{})
    if isinstance(items,list):
        for rel in items: assert (base/rel).exists(),rel
    else:
        for rel,h in items.items():
            f=base/rel; assert f.exists(),rel; assert sha(f.read_bytes())==h,rel
with SRC.open('rb') as fp:
    elf=ELFFile(fp); fde={(e.header['initial_location'],e.header['address_range']) for e in elf.get_dwarf_info().EH_CFI_entries() if isinstance(e,FDE)}
    load=[e for e in elf.iter_segments() if e['p_type']=='PT_LOAD']
rows=S['selected_candidate_rows']; assert len(rows)==512
raw={}; fresh={}; corr={}
for batch in range(1,17):
    paths=list((P/f'ghidra_raw_batch{batch}').glob('*.json')); assert len(paths)==32
    for f in paths:
        x=json.loads(f.read_text(encoding='utf8')); assert x['index'] not in raw; raw[x['index']]=x
for directory,dest in [(f'ghidra_fresh_batch{b}',fresh) for b in range(1,17)]+[('ghidra_correction',corr)]:
    for f in (P/directory).glob('*.json'):
        x=json.loads(f.read_text(encoding='utf8')); dest[x['index']]=x
assert len(fresh)==512 and len(corr)==247
dis=Cs(CS_ARCH_ARM64,CS_MODE_ARM)
slots=bytes_=listed=missing=pcode=full=missingbody=0
for r in rows:
    i=r['index']; va=int(r['elf_va'],16); n=r['size_bytes']; off=int(r['file_offset'],16)
    assert (va,n) in fde
    assert any(seg['p_vaddr']<=va and va+n<=seg['p_vaddr']+seg['p_filesz'] and off==seg['p_offset']+va-seg['p_vaddr'] for seg in load)
    body=data[off:off+n]; assert sha(body)==r['source_body_sha256']
    asm=json.loads((P/f"source_assembly/{i}_{va:x}.json").read_text(encoding='utf8'))
    ins=list(dis.disasm(body,va)); assert len(ins)==r['instruction_slots']==len(asm['instructions'])
    for x,y in zip(ins,asm['instructions']):
        assert x.address==int(y['elf_va'],16) and x.bytes.hex()==y['word_hex'] and f'{x.mnemonic} {x.op_str}'.strip()==y['assembly']
    q=raw[i]; assert q['ghidra_memory_sha256']==sha(body) and q['size_bytes']==n and q['c_like_nonempty'] and q['c_like_text'].strip()
    assert q['extra_body_address_count']==0
    assert q['other_function_byte_count']==0
    if i in fresh:
        f=fresh[i]; assert f['ghidra_memory_sha256']==q['ghidra_memory_sha256'] and f['fde_byte_membership_count']==q['fde_byte_membership_count']
    if i in corr:
        h=corr[i]; assert q['fde_byte_membership_count']<n and h['memory_sha256']==sha(body) and h['c_like_nonempty'] and h['corrected_function_fde_membership_count']==n and h['memory_unchanged_after_rollback']
    slots+=len(ins); bytes_+=n; listed+=q['ghidra_instruction_count']; missing+=q['missing_analyzed_instruction_count']; pcode+=q['ghidra_pcode_ops']; full+=q['fde_byte_membership_count']==n; missingbody+=n-q['fde_byte_membership_count']
assert slots==V['original_instruction_words_verified']==42990
assert bytes_==V['original_bytes_verified']==171960
assert full==V['preexisting_full_body_ranges']==265 and 512-full==V['partial_raw_membership_ranges']==247
assert missing==V['raw_missing_listing_slots']==10448
assert missingbody==V['raw_missing_body_bytes']==41792
assert pcode==V['ghidra_pcode_operations_recorded']==111111
spread=json.loads((P/'source_spread_recheck.json').read_text(encoding='utf8'))
assert len(spread['rows'])>=52
for sample in spread['rows']:
    i=sample['r1_style_one_based_row']; r=next(x for x in rows if x['index']==i); off=int(r['file_offset'],16)
    assert sample['source_body_sha256']==sha(data[off:off+r['size_bytes']])
    va=int(r['elf_va'],16)
    assert sample['source_assembly_sha256']==sha((P/f'source_assembly/{i}_{va:x}.json').read_bytes())
    batch=(i-1026)//32+1
    assert sample['raw_sha256']==sha((P/f'ghidra_raw_batch{batch}/{i}_{va:x}.json').read_bytes())
assert V['project_file_hashes_unchanged'] and V['transient_correction_same_session_metadata_restored']==0
print(json.dumps({'task':'TASK_228','report_files':len(C['files']),'code_files':len(C['code_files']),'source_bodies':512,'source_bytes':bytes_,'source_slots':slots,'full_fde':full,'raw_partial':512-full,'missing_listing_slots':missing,'transient_full_fde':len(corr),'fresh_session':len(fresh),'sample':len(spread['rows'])}))
