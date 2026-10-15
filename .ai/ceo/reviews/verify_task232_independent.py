import hashlib
import json
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile
from elftools.dwarf.callframe import FDE

ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / 'RULES/REPORT/TASK_232_REPORT_R1'
SOURCE = Path('F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libAIModelSearchKit.so')
TASK = ROOT / 'RULES/TASK/TASK_232_SO45_INTERNAL_CONTINUATION_ACTIVE.md'
TARGETS = ROOT / '.ai/ceo/reviews/TASK_232_internal_targets.json'
sha = lambda b: hashlib.sha256(b).hexdigest()
data = SOURCE.read_bytes()
c = json.loads((REPORT/'COMPLETE.json').read_text(encoding='utf-8'))
s = json.loads((REPORT/'source_index.json').read_text(encoding='utf-8'))
v = json.loads((REPORT/'verification.json').read_text(encoding='utf-8'))
t = json.loads(TARGETS.read_text(encoding='utf-8'))
assert c['task_id']=='TASK_232' and c['revision']==1 and c['status']=='COMPLETE'
assert sha(TASK.read_bytes())==c['task_sha256']
assert sha(TARGETS.read_bytes())==c['target_manifest_sha256']
assert sha(data)==c['source_sha256']==s['source_sha256']
for group,base in [('files',REPORT),('code_files',ROOT),('scratch_files',ROOT)]:
    for rel,h in c.get(group,{}).items():
        f=base/rel
        assert f.exists(),f
        assert sha(f.read_bytes())==h,(rel,'hash')
rows=s['rows']; vr=v['rows']; targets=json.loads(TARGETS.read_text(encoding='utf-8'))['targets']
assert len(rows)==len(vr)==2
with SOURCE.open('rb') as stream:
    e=ELFFile(stream)
    load=[p for p in e.iter_segments() if p['p_type']=='PT_LOAD']
    fde={(entry.header['initial_location'],entry.header['address_range']) for entry in e.get_dwarf_info().EH_CFI_entries() if isinstance(entry,FDE)}
    for r in rows:
        va=int(r['elf_va'],16); n=r['size_bytes']; off=int(r['file_offset'],16)
        assert (va,n) in fde,(va,n,'FDE')
        assert any(p['p_vaddr']<=va and va+n<=p['p_vaddr']+p['p_filesz'] and off==p['p_offset']+va-p['p_vaddr'] for p in load)
dis=Cs(CS_ARCH_ARM64,CS_MODE_ARM)
asm=[json.loads(line) for line in (REPORT/'assembly.ndjson').read_text(encoding='utf-8').splitlines()]
assert len(asm)==2
slots=0; exact=0; missing=0; pcode=0
for i,(r,q,a) in enumerate(zip(rows,vr,asm),1):
    assert r['index']==q['index']==a['index']==i
    assert r['global_index']==targets[i-1]['global_index']
    assert r['elf_va']==q['elf_va']==a['elf_va']
    va=int(r['elf_va'],16); off=int(r['file_offset'],16); body=data[off:off+r['size_bytes']]
    assert sha(body)==r['body_sha256']==q['body_sha256']==a['body_sha256']
    ins=list(dis.disasm(body,va)); assert len(ins)==r['instruction_slots']==len(a['instructions'])
    for x,y in zip(ins,a['instructions']):
        assert x.address==int(y['va'],16) and x.bytes.hex()==y['word_le'] and x.mnemonic==y['mnemonic'] and x.op_str==y['operands']
    rawpath=REPORT/f'ghidra/candidates/candidate_{i:03}.json'; raw=json.loads(rawpath.read_text(encoding='utf-8'))
    assert sha(rawpath.read_bytes())==q['raw_sha256']
    assert raw['expected_original_body_sha256']==sha(body)==raw['owned_project_memory_sha256']
    assert raw['source_bytes_match'] and raw['decompile_success']
    assert sha(raw['pseudocode'].encode('utf-8'))==raw['pseudocode_sha256']==q['c_like_sha256']
    assert raw['instruction_count']==len(ins) and raw['missing_instruction_slots']==0
    assert raw['body_member_bytes_within_fde']==q['body_member_bytes']
    assert raw['body_extra_bytes_outside_fde']==q['body_extra_bytes']==0
    assert q['body_exact_fde']==(q['body_member_bytes']==len(body))
    slots+=len(ins); exact+=q['body_exact_fde']; missing+=len(body)-q['body_member_bytes']; pcode+=raw['pcode_op_count']
assert slots==v['summary']['source_slots']==2533
assert exact==v['summary']['body_exact_fde']==2
assert missing==v['summary']['missing_body_bytes']==0
assert pcode==v['summary']['pcode_ops']==8048
assert len(v['ordinary_spread_sample'])==2
for item in v['ordinary_spread_sample']:
    i=item['index']; r=rows[i-1]; rawpath=REPORT/f'ghidra/candidates/candidate_{i:03}.json'
    assert item['body_sha256']==r['body_sha256'] and item['raw_sha256']==sha(rawpath.read_bytes())
    assert item['source_slots_redecoded']==r['instruction_slots']
assert v['original_project_before_and_after_hashes_match']
print(json.dumps({'task':'TASK_232','report_files':len(c['files']),'code_files':len(c['code_files']),'scratch_files':len(c.get('scratch_files',{})),'source_bodies':2,'source_slots':slots,'sample':len(v['ordinary_spread_sample']),'exact_fde':exact,'missing_body_bytes':missing,'pcode_ops':pcode}))
