import hashlib,json
from pathlib import Path
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile
from elftools.dwarf.callframe import FDE

R=Path(__file__).resolve().parents[3]; P=R/'RULES/REPORT/TASK_231_REPORT_R1'
T=R/'RULES/TASK/TASK_231_SO45_INTERNAL_CONTINUATION_ACTIVE.md'
M=R/'.ai/ceo/reviews/TASK_231_internal_targets.json'
C=json.loads((P/'COMPLETE.json').read_text(encoding='utf8'))
S=json.loads((P/'source_project_index.json').read_text(encoding='utf8'))
V=json.loads((P/'evidence_summary.json').read_text(encoding='utf8'))
SRC=Path(S['source_path']); sha=lambda b:hashlib.sha256(b).hexdigest()
assert C['task_id']=='TASK_231' and C['revision']==1 and C['status']=='COMPLETE'
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
rows=S['selected_candidate_rows']; assert len(rows)==505
manifest=json.loads(M.read_text(encoding='utf8'))
assert len(manifest['targets'])==505
assert [r['selected_zero_index'] for r in rows]==[r['global_index'] for r in manifest['targets']]
assert [r['global_index'] for r in manifest['skipped_in_slice']]==[1542,1586,1620,1623,1626,1830,1912]
raw={}; fresh={}; corr={}
for batch in range(1,17):
    paths=list((P/f'ghidra_raw_batch{batch}').glob('*.json')); assert len(paths)==(25 if batch==16 else 32)
    receipt=json.loads((P/f'ghidra_batch{batch}_command.json').read_text(encoding='utf8'))
    assert receipt['exit_code']==0 and receipt['max_cpu']==1 and receipt['max_heap']=='1G'
    assert receipt['max_decompile_seconds_per_candidate']==15 and receipt['raw_result_files']==len(paths)
    for f in paths:
        x=json.loads(f.read_text(encoding='utf8')); assert x['index'] not in raw; raw[x['index']]=x
for name,n in [('ghidra_correction',144)]+[(f'ghidra_fresh_batch{b}',25 if b==16 else 32) for b in range(1,17)]:
    receipt=json.loads((P/f'{name}_command.json').read_text(encoding='utf8'))
    assert receipt['exit_code']==0 and receipt['output_files']==n
    assert receipt['max_cpu']==1 and receipt['max_heap']=='1G' and receipt['max_per_decompile_seconds']==15
    assert receipt['project_metadata_unchanged'] and receipt['project_files_before']==receipt['project_files_after']
for directory,dest in [(f'ghidra_fresh_batch{b}',fresh) for b in range(1,17)]+[('ghidra_correction',corr)]:
    for f in (P/directory).glob('*.json'):
        x=json.loads(f.read_text(encoding='utf8')); dest[x['index']]=x
assert len(fresh)==505 and len(corr)==144
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
assert slots==V['original_instruction_words_verified']==37904
assert bytes_==V['original_bytes_verified']==151616
assert full==V['preexisting_full_body_ranges']==361 and 505-full==V['partial_raw_membership_ranges']==144
assert missing==V['raw_missing_listing_slots']==2577
assert missingbody==V['raw_missing_body_bytes']==10348
assert pcode==V['ghidra_pcode_operations_recorded']==127699
spread=json.loads((P/'source_spread_recheck.json').read_text(encoding='utf8'))
assert len(spread['rows'])>=52
for sample in spread['rows']:
    i=sample['r1_style_one_based_row']; r=next(x for x in rows if x['index']==i); off=int(r['file_offset'],16)
    assert sample['source_body_sha256']==sha(data[off:off+r['size_bytes']])
    va=int(r['elf_va'],16)
    assert sample['source_assembly_sha256']==sha((P/f'source_assembly/{i}_{va:x}.json').read_bytes())
    batch=next(b for b in range(1,17) if (P/f'ghidra_raw_batch{b}/{i}_{va:x}.json').exists())
    assert sample['raw_sha256']==sha((P/f'ghidra_raw_batch{batch}/{i}_{va:x}.json').read_bytes())
assert V['project_file_hashes_unchanged'] and V['transient_correction_same_session_metadata_restored']==0
print(json.dumps({'task':'TASK_231','report_files':len(C['files']),'code_files':len(C['code_files']),'source_bodies':505,'source_bytes':bytes_,'source_slots':slots,'full_fde':full,'raw_partial':505-full,'missing_listing_slots':missing,'transient_full_fde':len(corr),'fresh_session':len(fresh),'sample':len(spread['rows'])}))
