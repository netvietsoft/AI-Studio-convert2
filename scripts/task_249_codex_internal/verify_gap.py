#!/usr/bin/env python3
"""Rebuild the TASK_249 source-byte, branch, Ghidra-membership and no-body evidence."""
from pathlib import Path
import hashlib, json, collections
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile
from elftools.dwarf.callframe import FDE
ROOT=Path(__file__).resolve().parents[2]
SOURCE=Path(r'F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libPVGCodec.so')
TASK=ROOT/'RULES/TASK/TASK_249_SO45_PVGCODEC_GAP_RECOVERY_ACTIVE.md'
MANIFEST=ROOT/'.ai/ceo/reviews/TASK_249_internal_targets.json'
STANDARD=ROOT/'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt'
REPORT=ROOT/'RULES/REPORT/TASK_249_REPORT_R1'; SOURCE_OUT=REPORT/'source'
START,END,FDE_START,FDE_END=0xaf040,0xaf688,0xa8b08,0xaf68c
EXPECTED={'standard':'10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f',
 'task':'4f5ec07747c381257116461979fa5fced279911b19a0f2f3aa0e5348e339ae0e',
 'manifest':'29890e85a5c7677cabf51a20dcbc3fe34b9531fc12ceadb1e25476d9b81c1f27',
 'source':'4fa5f275c8ddecf7caa960c812108ec9e801365bfe5bc9cf38598233bc449ffc',
 'gap':'f825653da2ed819fd5334f4103037f4466fcf8655080e5ec84c56a684569c54b'}
def sha(b): return hashlib.sha256(b).hexdigest()
def file_sha(p): return sha(p.read_bytes())
def dump(path,obj): path.write_text(json.dumps(obj,indent=2,ensure_ascii=False)+'\n',encoding='utf-8')
def direct_target(i):
 if i.mnemonic in ('b','bl') or i.mnemonic.startswith(('b.','cbz','cbnz','tbz','tbnz')):
  try:return int(i.op_str.split(',')[0].strip().lstrip('#'),0)
  except ValueError:return None
 return None
def uleb(buf,pos):
 v=0;shift=0
 while True:
  b=buf[pos];pos+=1;v|=(b&0x7f)<<shift
  if not b&0x80:return v,pos
  shift+=7

def main():
 for path,key in ((STANDARD,'standard'),(TASK,'task'),(MANIFEST,'manifest'),(SOURCE,'source')):
  got=file_sha(path); assert got==EXPECTED[key],f'{key} hash mismatch: {got}'
 m=json.loads(MANIFEST.read_text(encoding='utf-8')); gap=m['target_gap']; raw=SOURCE.read_bytes()
 s=int(gap['start_va'],16);e=int(gap['end_va_exclusive'],16);off=int(gap['file_offset'],16);size=gap['size_bytes']
 assert (s,e,off,size)==(START,END,START,1608)
 assert gap['mapping']['segment_vaddr']==0 and gap['mapping']['segment_offset']==0
 assert file_sha(SOURCE)==m['source_sha256'] and len(raw)==1283760
 fde_raw=raw[FDE_START:FDE_END]; assert sha(fde_raw)==m['candidate_fde']['body_sha256']
 with SOURCE.open('rb') as stream:
  elf=ELFFile(stream); seg=next(ph for ph in elf.iter_segments() if ph['p_type']=='PT_LOAD' and ph['p_vaddr']<=s and e<=ph['p_vaddr']+ph['p_filesz'])
  assert off==seg['p_offset']+(s-seg['p_vaddr']) and off+size<=seg['p_offset']+seg['p_filesz']
 mapping={'p_vaddr':hex(seg['p_vaddr']),'p_offset':hex(seg['p_offset']),'p_filesz':seg['p_filesz'],'derived_file_offset':hex(seg['p_offset']+(s-seg['p_vaddr']))}
 original=raw[off:off+size]; assert sha(original)==EXPECTED['gap']
 gh=json.loads((REPORT/'ghidra/gap_listing.json').read_text(encoding='utf-8'))
 assert gh['summary']=={'gap_words':402,'external_flow_references':0,'function_body_member_words':0,'instruction_defined_words':0,'both':0}
 md=Cs(CS_ARCH_ARM64,CS_MODE_ARM);md.detail=True
 gap_ins=list(md.disasm(original,s));assert len(gap_ins)==402 and all(x.address==s+4*j and x.size==4 for j,x in enumerate(gap_ins))
 fde_ins=list(md.disasm(raw[FDE_START:FDE_END],FDE_START));assert len(fde_ins)==6881
 external=[]
 for i in fde_ins:
  tar=direct_target(i)
  if tar is not None and s<=tar<e and not s<=i.address<e:
   external.append({'source_va':hex(i.address),'mnemonic':i.mnemonic,'target_va':hex(tar)})
 before=[i for i in fde_ins if i.address==s-4];assert len(before)==1 and before[0].mnemonic=='bl'
 words=[];edges=[];mn=collections.Counter()
 for idx,(ins,record) in enumerate(zip(gap_ins,gh['word_membership'])):
  assert int(record['va'],16)==ins.address and not record['function_body_member'] and not record['instruction_defined']
  tar=direct_target(ins);kind=''
  if ins.mnemonic=='bl':kind='direct_call'
  elif ins.mnemonic=='blr':kind='indirect_call_unresolved'
  elif ins.mnemonic=='br':kind='indirect_branch_unresolved'
  elif ins.mnemonic in ('ret','eret'):kind='return'
  elif tar is not None:kind='direct_branch'
  mn[ins.mnemonic]+=1
  if kind:
   edges.append({'source_va':hex(ins.address),'mnemonic':ins.mnemonic,'kind':kind,'target_va':None if tar is None else hex(tar),
      'target_in_gap':False if tar is None else s<=tar<e,'target_in_fde':False if tar is None else FDE_START<=tar<FDE_END})
  words.append({'word_index':idx,'va':hex(ins.address),'file_offset':hex(off+ins.address-s),
    'word_le':f'0x{int.from_bytes(ins.bytes,"little"):08x}','bytes_le':ins.bytes.hex(),'mnemonic':ins.mnemonic,
    'operands':ins.op_str,'ghidra_instruction_defined':False,'ghidra_function_body_member':False,
    'edge_kind':kind,'direct_target_va':None if tar is None else hex(tar)})
 # The earlier accepted IR report is supplementary evidence only: no gap word was mapped.
 ir=json.loads((ROOT/'RULES/REPORT/TASK_248_REPORT_R1/ir_source_map.json').read_text(encoding='utf-8'))
 gapvas={hex(v) for v in range(s,e,4)}; mapped={r['elf_va'] for r in ir['mapped']}
 gap_absent=sorted(gapvas & set(ir['absent_original_word_vas']),key=lambda x:int(x,16))
 ir_raw_path=ROOT/'RULES/REPORT/TASK_248_REPORT_R1/register_ir/result.json'; ir_raw=json.loads(ir_raw_path.read_text(encoding='utf-8'))
 gap_ops=[op for op in ir_raw['ops'] if s<=int(op['elf_va'],16)<e]
 assert len(gapvas & mapped)==0 and len(gap_absent)==402 and len(gap_ops)==0
 # Inspect EH call-site metadata for this candidate FDE, without claiming it is source boundary.
 with SOURCE.open('rb') as stream:
  dwarf=ELFFile(stream).get_dwarf_info()
  fde=next(x for x in dwarf.EH_CFI_entries() if isinstance(x,FDE) and x['initial_location']==FDE_START)
  assert fde['address_range']==27524 and fde.lsda_pointer==0x4f004
 lsda=fde.lsda_pointer; p=lsda; lp=raw[p]; tt=raw[p+1];cs=raw[p+2];p+=3;table_bytes,p=uleb(raw,p);limit=p+table_bytes;rows=[]
 while p<limit:
  a,p=uleb(raw,p);b,p=uleb(raw,p);c,p=uleb(raw,p);d,p=uleb(raw,p);rows.append((a,b,c,d))
 assert p==limit
 pads=collections.Counter(row[2] for row in rows if row[2]);pad_vas=[FDE_START+x for x in pads]
 assert len(rows)==184 and sum(1 for x in rows if x[2])==167 and len(pads)==128 and all(s<=v<e for v in pad_vas)
 rows_json=[{'callsite_start_va':hex(FDE_START+a),'callsite_end_exclusive_va':hex(FDE_START+a+b),'fde_relative_start':a,'length':b,'landing_pad_va':None if not c else hex(FDE_START+c),'action':d} for a,b,c,d in rows]
 raw_lsda=raw[lsda:limit]; assert len(raw_lsda)==3+2+table_bytes
 # The call-site-table byte count excludes the 2-byte ULEB header; exact raw length is header+table.
 lsda_evidence={'source_sha256':file_sha(SOURCE),'fde_start_va':hex(FDE_START),'fde_length_bytes':FDE_END-FDE_START,'lsda_file_offset_or_vaddr':hex(lsda),'lsda_header_encodings':{'lp_start':hex(lp),'ttype':hex(tt),'call_site':hex(cs)},'callsite_table_bytes':table_bytes,'callsite_rows':len(rows),'rows_consumed_exactly':p==limit,'nonzero_action_rows':sum(1 for r in rows if r[3]!=0),'rows_with_landing_pad':sum(1 for r in rows if r[2]),'unique_landing_pad_count':len(pads),'landing_pad_addresses_in_gap':all(s<=v<e for v in pad_vas),'unique_landing_pads':[{'va':hex(FDE_START+x),'rows':cnt} for x,cnt in sorted(pads.items())],'callsite_rows':rows_json,'raw_bytes_hex':raw_lsda.hex(),'raw_bytes_length':len(raw_lsda),'raw_bytes_sha256':sha(raw_lsda),'interpretation_limit':'EH LSDA landing-pad references show exception edges into the byte gap, not source function boundary or C-like recovery.'}
 dump(REPORT/'source/lsda_callsite_evidence.json',lsda_evidence)
 summary={'source_sha256':file_sha(SOURCE),'source_size_bytes':len(raw),'gap_va':[hex(s),hex(e)],'gap_file_offset':hex(off),
  'gap_size_bytes':len(original),'gap_sha256':sha(original),'pt_load_mapping':mapping,'fde_body_sha256':sha(fde_raw),'aarch64_words':len(words),'source_decode_coverage':'402/402 words, contiguous 4-byte aligned',
  'ghidra_function_body_member_words':0,'ghidra_defined_instruction_words':0,'prior_high_ir_gap_words_mapped':0,'prior_high_ir_gap_words_absent':402,
  'mnemonic_counts':dict(sorted(mn.items())),'direct_branch_count':sum(1 for e1 in edges if e1['kind']=='direct_branch'),
  'direct_call_count':sum(1 for e1 in edges if e1['kind']=='direct_call'),'unresolved_indirect_edges':[],
  'direct_branch_edges_from_outside_gap_inside_candidate_fde':external,'preceding_candidate_fde_instruction':{'va':hex(before[0].address),
    'instruction':before[0].mnemonic+' '+before[0].op_str,'possible_return_continuation':'0xaf040'},
  'candidate_fde':{'start':hex(FDE_START),'end_exclusive':hex(FDE_END),'size_bytes':FDE_END-FDE_START,
    'body_sha256':m['candidate_fde']['body_sha256'],'source_function_boundary_proven':False},
  'lsda_eh_evidence':{'pointer':hex(lsda),'encoding':{'lp_start':hex(lp),'type_table':hex(tt),'callsite':hex(cs)},
    'rows':len(rows),'rows_with_landing_pad':sum(1 for x in rows if x[2]),'unique_landing_pad_addresses':len(pads),
    'all_nonzero_pads_inside_gap':all(s<=v<e for v in pad_vas),'action_fields_nonzero':sum(1 for x in rows if x[3])},
  'c_like_function_bodies_recovered':0,'disposition':'PARTIAL_GAP_DISASSEMBLED_NO_FUNCTION_RECOVERED'}
 dump(SOURCE_OUT/'word_edge_ledger.json',{'summary':summary,'words':words,'edges':edges})
 (SOURCE_OUT/'capstone_disassembly.txt').write_text('\n'.join(f'0x{i.address:06x}: {i.bytes.hex():<8} {i.mnemonic:<8} {i.op_str}' for i in gap_ins)+'\n',encoding='utf-8')
 dump(SOURCE_OUT/'incoming_fde_edges.json',{'direct_edges_from_outside_gap':external,'preceding_instruction':summary['preceding_candidate_fde_instruction'],
   'interpretation':'no direct branch targets the gap from elsewhere in this FDE; BL at 0xaf03c has possible return continuation at 0xaf040'})
 dump(SOURCE_OUT/'pcode_gap.json',{'disposition':'NO_RANGE_PCODE_AVAILABLE','source':'TASK_248 register HighFunction address map only',
    'task248_register_high_ir_ops':ir['high_ir_ops'],'task248_unique_original_instruction_addresses':ir['mapped_distinct_original_word_vas'],
    'task248_raw_high_ir_sha256':file_sha(ir_raw_path),'gap_addresses_mapped_to_ir':0,'gap_addresses_absent_from_ir':402,'gap_addresses':gap_absent,'operations':gap_ops,
    'meaning':'address-map absence in this prior optimized IR is not proof of unreachable source or lack of machine instructions'})
 dump(SOURCE_OUT/'c_like_gap.json',{'disposition':'NO_C_LIKE_OUTPUT','function_boundary_proven':False,'complete_function_body_proven':False,
    'c_like_function_bodies_recovered':0,'source_text':'','reason':'No source-like output was requested/generated because Ghidra defines no instruction or function body in the gap, so no complete independently bounded function exists to decompile.'})
 dump(SOURCE_OUT/'eh_lsda_summary.json',{'lsda_va':hex(lsda),'encodings':{'lp_start':hex(lp),'type_table':hex(tt),'callsite':hex(cs)},
   'callsite_table_bytes':table_bytes,'rows':len(rows),'rows_with_nonzero_landing_pad':sum(1 for x in rows if x[2]),
   'unique_landing_pad_addresses':[hex(x) for x in sorted(pads)],'all_pads_in_gap':all(s<=v<e for v in pad_vas),
   'action_nonzero_rows':sum(1 for x in rows if x[3]),'interpretation_limit':'exception metadata edges are evidence of landing-pad references, not source-function or C-like recovery'})
 print(json.dumps(summary,indent=2))
if __name__=='__main__': main()




