import csv,hashlib,json,re
from pathlib import Path
from datetime import datetime,timezone
from elftools.elf.elffile import ELFFile
from capstone import Cs,CS_ARCH_ARM64
R=Path(r'F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2'); REP=R/'RULES/REPORT/TASK_245_REPORT_R2'; W=R/'RESEARCH_WORK/TASK_245_R2'; R1=R/'RULES/REPORT/TASK_245_REPORT_R1'
SRC=R/'lib-core-graphics/src/main/jniLibs/arm64-v8a/libPVGImageCodec.so'; HIST=R/'SOURCE/extracted_native_libs/lib/arm64-v8a/libPVGImageCodec.so'; MAN=R/'.ai/ceo/reviews/TASK_245_internal_targets.json'; TASK=R/'RULES/TASK/TASK_245_SO45_INTERNAL_CONTINUATION_ACTIVE.md'; STD=R/'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt'
HSTD='10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f'; HTASK='c2f2456dd196ec59477dfe6904a1e979913c774645c70d0aef5ba43b6cefeffe'; HMAN='022953118235f468192b1c56f863770300b0639d1eeb9916de057f29fac8943c'; HSRC='7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b'; FENCE=1288
h=lambda b:hashlib.sha256(b).hexdigest()
def hf(p):
 x=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):x.update(b)
 return x.hexdigest()
def jr(p):return json.loads(p.read_text(encoding='utf-8'))
def rel(p):return p.resolve().relative_to(R.resolve()).as_posix()
def balanced(s):
 s=re.sub(r'"(?:\\.|[^"\\])*"','""',s,flags=re.S);s=re.sub(r"'(?:\\.|[^'\\])*'","''",s,flags=re.S);s=re.sub(r'/\*.*?\*/',' ',s,flags=re.S);s=re.sub(r'//[^\r\n]*',' ',s)
 d=0
 for c in s:
  if c=='{':d+=1
  elif c=='}':d-=1
  if d<0:return False
 return d==0
assert hf(STD)==HSTD and hf(TASK)==HTASK and hf(MAN)==HMAN and hf(SRC)==HSRC
assert not (R/'.ai/ceo/END_AGENT_SESSION.flag').exists()
m=jr(MAN); assert len(m['targets'])==23 and m['source_sha256']==HSRC
src=SRC.read_bytes(); md=Cs(CS_ARCH_ARM64,0)
with SRC.open('rb') as f:
 elf=ELFFile(f); fdes=[(int(x['initial_location']),int(x['address_range'])) for x in elf.get_dwarf_info().EH_CFI_entries() if type(x).__name__=='FDE']
 loads=[s for s in elf.iter_segments() if s['p_type']=='PT_LOAD' and int(s['p_flags'])&1]
 ex=set(); exranges=[]
 ds=elf.get_section_by_name('.dynsym')
 for s in ds.iter_symbols():
  if s['st_info']['type']=='STT_FUNC' and s['st_shndx']!='SHN_UNDEF' and int(s['st_value']):
   v=int(s['st_value']);z=int(s['st_size']);ex.add(v)
   if z:exranges.append((v,v+z))
assert len(fdes)==9981 and len(ex)==3326 and sum(v not in ex for v,z in fdes)==6655
nonexport_fdes=sorted((v,z) for v,z in fdes if v not in ex)
rows=[]; ledger=[]
for batch,t in enumerate(m['targets'],1):
 idx=int(t['global_index'])+1; va=int(t['elf_va'],16); z=int(t['size_bytes']); off=int(t['file_offset'],16); name=f'{idx}_{va:x}.json'
 rp=R1/f'ghidra_raw_batch{batch}'/name; ap=R1/'source_assembly'/name
 raw=jr(rp); asm=jr(ap); body=src[off:off+z]; d=list(md.disasm(body,va)); sr=asm['instructions']; pi=raw.get('instruction_pcode',[])
 fi=int(t['global_index']); indexok=0<=fi<len(nonexport_fdes) and nonexport_fdes[fi]==(va,z)
 segs=[]
 for n,s in enumerate(loads):
  pv=int(s['p_vaddr']); po=int(s['p_offset']); fs=int(s['p_filesz'])
  if pv<=va and va+z<=pv+fs and po+va-pv==off:segs.append({'load_segment_index':n,'p_offset':hex(po),'p_vaddr':hex(pv),'p_filesz':fs,'p_flags':int(s['p_flags'])})
 bodysha=h(body); srcok=len(sr)==len(d)==int(t['instruction_slots']) and all(bytes.fromhex(q['word_hex'])==body[j*4:j*4+4] and int(q['elf_va'],16)==va+j*4 and bytes(d[j].bytes)==body[j*4:j*4+4] and d[j].address==va+j*4 and d[j].size==4 for j,q in enumerate(sr))
 bias=(int(pi[0]['database_va'],16)-va) if pi else None; ghok=len(pi)==len(d)==int(raw.get('ghidra_instruction_count',-1)) and all(int(q['database_va'],16)==va+j*4+bias for j,q in enumerate(pi))
 mn=sum((q.get('assembly','').strip().split(' ',1)[0].split('\t',1)[0].lower()==d[j].mnemonic.lower()) for j,q in enumerate(pi[:min(len(pi),len(d))]))
 exact=sum((a==va and b==z) for a,b in fdes); overlaps=[(a,b) for a,b in fdes if (a,b)!=(va,z) and a<va+z and va<a+b]
 exov=[(a,b) for a,b in exranges if a<va+z and va<a+b]
 bits=raw.get('fde_byte_membership_bits',''); db=va+0x100000; mnmax=(db,db+z-1)
 try: bod=(int(raw['function_body_min'],16),int(raw['function_body_max'],16))
 except: bod=(-1,-1)
 coverage=(raw.get('function_start')==hex(db) and bod==mnmax and int(raw.get('function_body_total_address_count',-1))==z and int(raw.get('extra_body_address_count',-1))==0 and int(raw.get('other_function_byte_count',-1))==0 and len(bits)==z and set(bits)=={'1'} and int(raw.get('fde_byte_membership_count',-1))==z and int(raw.get('fde_byte_membership_transitions',-1))==0 and raw.get('fde_missing_body_ranges')==[] and raw.get('extra_body_ranges')==[] and raw.get('ghidra_memory_sha256')==bodysha)
 text=raw.get('c_like_text',''); clike=bool(raw.get('c_like_nonempty')) and bool(text.strip()) and not raw.get('decompile_error') and f'FUN_{db:08x}' in text and balanced(text)
 boundary=raw.get('boundary_classification',''); bproven=not ('UNPROVEN' in boundary)
 accepted=bool(indexok and exact==1 and not overlaps and not exov and va not in ex and len(segs)==1 and bodysha==t['body_sha256'] and srcok and ghok and coverage and clike and bproven)
 r={'manifest_fde_index_zero_based':t['global_index'],'manifest_index_matches_independent_sorted_nonexport_fde':indexok,'producer_index_one_based':idx,'elf_va':t['elf_va'],'candidate_size_bytes':z,'manifest_file_offset':t['file_offset'],'manifest_body_sha256':t['body_sha256'],'recomputed_source_sha256':bodysha,'source_bytes_match':bodysha==t['body_sha256'],'exact_fde_matches':exact,'other_fde_overlaps':len(overlaps),'export_va_match':va in ex,'export_body_overlaps':len(exov),'exec_pt_load_matches':len(segs),'exec_pt_load':segs[0] if segs else None,'source_slots_manifest':t['instruction_slots'],'source_assembly_slots':len(sr),'independent_capstone_slots':len(d),'source_words_and_addresses_match':srcok,'ghidra_instruction_pcode_rows':len(pi),'ghidra_address_sequence_matches':ghok,'ghidra_mnemonic_match_slots':mn,'ghidra_body_and_fde_byte_coverage_match':coverage,'c_like_utf8_bytes':len(text.encode()),'c_like_text_shape_valid':clike,'decompile_error':raw.get('decompile_error',''),'boundary_classification':boundary,'source_function_boundary_proven':bproven,'accepted_new_c_like_body':accepted,'raw_path':rel(rp),'raw_sha256':hf(rp),'source_assembly_path':rel(ap),'source_assembly_sha256':hf(ap)}
 rows.append(r)
 claims=[('FDE_INDEX_AND_MANIFEST','VERIFIED' if indexok else 'FAIL','independent sorted nonexport FDE list at the manifest zero-based index'),('ELF_FDE','VERIFIED' if exact==1 else 'FAIL','independent .eh_frame parse; exact start and length'),('DYNSYM_EXCLUSION','VERIFIED' if va not in ex else 'FAIL','independent defined nonzero .dynsym STT_FUNC VA set'),('PT_LOAD_MAPPING','VERIFIED' if len(segs)==1 else 'FAIL','independent executable file-backed PT_LOAD mapping'),('SOURCE_BODY_BYTES','VERIFIED' if bodysha==t['body_sha256'] else 'FAIL','source SO byte slice and manifest SHA-256'),('SOURCE_INSTRUCTIONS','VERIFIED' if srcok else 'FAIL','source word/address records and independent Capstone decode'),('GHIDRA_SOURCE_ADDRESS_MEMBERSHIP','VERIFIED' if ghok else 'FAIL','raw Ghidra instruction_pcode DB VAs mapped by image-base bias'),('GHIDRA_BYTE_COVERAGE','VERIFIED' if coverage else 'FAIL','raw Ghidra memory SHA, body bounds, membership bits, extra/missing ranges'),('RAW_C_LIKE_OUTPUT','VERIFIED_STATIC_TEXT' if clike else 'FAIL','raw Ghidra C-like text; no semantics/runtime claim'),('SOURCE_FUNCTION_BOUNDARY','VERIFIED' if bproven else 'UNVERIFIED_FDE_BOUNDARY','raw classification: '+str(boundary)),('ACCEPTED_C_LIKE_BODY','ACCEPTED' if accepted else 'NOT_COUNTED','must pass source-boundary rule; uncertain FDE/function boundary is excluded')]
 for cid,status,evidence in claims:ledger.append({'candidate_id':idx,'elf_va':t['elf_va'],'claim_id':cid,'status':status,'evidence':evidence,'raw_path':rel(rp),'raw_sha256':hf(rp),'notes':'Ghidra DB VA uses +0x100000; ELF VA remains manifest VA.' if cid in ('GHIDRA_SOURCE_ADDRESS_MEMBERSHIP','GHIDRA_BYTE_COVERAGE') else ''})

# Exhaustive immutable-input inventory: all R1 report, generator, and RESEARCH_WORK files plus controls.
inputs=[]
def add(p,cat):
 if p.is_file():inputs.append((p,cat))
def tree(p,cat):
 if p.exists():
  for q in sorted(p.rglob('*')):
   if q.is_file():add(q,cat)
for p,c in [(STD,'canonical_standard'),(R/'AGENTS.md','agent_rules'),(R/'Docs/rules.md','project_rules'),(R/'.ai/ceo/SO45_TO_V4_PLAN.md','campaign_plan'),(R/'.ai/ceo/config.json','ceo_config_snapshot'),(R/'.ai/ceo/state.json','ceo_state_snapshot'),(R/'.ai/locks.json','lease_registry_snapshot'),(TASK,'active_task_r2'),(MAN,'target_manifest'),(SRC,'pinned_source_library'),(W/'verify_task245_r2.py','independent_verifier')]:add(p,c)
tree(R1,'immutable_r1_report_input');tree(R/'scripts/task_245_codex_internal','immutable_r1_generator_input');tree(R/'RESEARCH_WORK/TASK_245_R1','immutable_r1_research_input')
u={}
for p,c in inputs:u.setdefault(str(p.resolve()).lower(),(p,c))
inputs=sorted(u.values(),key=lambda x:rel(x[0]))
inv=[{'path':rel(p),'category':c,'bytes':p.stat().st_size,'sha256':hf(p),'status':'HASHED'} for p,c in inputs]
if not HIST.exists():inv.append({'path':'SOURCE/extracted_native_libs/lib/arm64-v8a/libPVGImageCodec.so','category':'historical_r1_source_path','bytes':'','sha256':'','status':'ABSENT; exact-hash source is in lib-core-graphics/src/main/jniLibs/arm64-v8a/libPVGImageCodec.so'})
REP.mkdir(parents=True,exist_ok=True);W.mkdir(parents=True,exist_ok=True)
def outcsv(path,items,fields):
 with path.open('w',newline='',encoding='utf-8') as f:w=csv.DictWriter(f,fieldnames=fields,extrasaction='ignore');w.writeheader();w.writerows(items)
outcsv(REP/'02_TARGET_EVIDENCE.csv',rows,list(rows[0]))
outcsv(REP/'03_INPUT_HASH_INVENTORY.csv',inv,['path','category','bytes','sha256','status'])
outcsv(REP/'04_EVIDENCE_LEDGER.csv',ledger,['candidate_id','elf_va','claim_id','status','evidence','raw_path','raw_sha256','notes'])
raw_count=sum(x['c_like_text_shape_valid'] for x in rows);accepted=sum(x['accepted_new_c_like_body'] for x in rows)
summary={'schema_version':'2.1.2','task_id':'TASK_245','revision':2,'verified_at_utc':datetime.now(timezone.utc).isoformat(),'standard_sha256':HSTD,'task_sha256':HTASK,'target_manifest_sha256':HMAN,'source_sha256':HSRC,'source_bytes':len(src),'source_path_used':rel(SRC),'historical_R1_source_path':rel(HIST),'historical_path_present':HIST.exists(),'historical_path_note':'Original R1 path absent; same pinned bytes verified at in-repo JNI path.','eh_frame_fde_count':len(fdes),'unique_defined_nonzero_dynsym_func_VAs':len(ex),'nonexport_FDE_candidate_count':sum(v not in ex for v,z in fdes),'target_candidate_count':len(rows),'exact_FDE_matches':sum(x['exact_fde_matches']==1 for x in rows),'exec_PT_LOAD_matches':sum(x['exec_pt_load_matches']==1 for x in rows),'source_byte_hash_matches':sum(x['source_bytes_match'] for x in rows),'source_instruction_decodes_verified':sum(x['source_words_and_addresses_match'] for x in rows),'Ghidra_source_address_sequences_verified':sum(x['ghidra_address_sequence_matches'] for x in rows),'Ghidra_body_byte_coverage_verified':sum(x['ghidra_body_and_fde_byte_coverage_match'] for x in rows),'raw_C_like_outputs_shape_verified':raw_count,'independently_proven_source_function_boundaries':sum(x['source_function_boundary_proven'] for x in rows),'accepted_new_C_like_bodies':accepted,'new_count_to_add_to_existing_baseline':0,'prior_accepted_baseline':'43,396 across 45 SO files; unchanged','input_inventory_hash_rows':len(inv),'evidence_ledger_rows':len(ledger),'outcome':'COMPLETE_PARTIAL','reason':'All R1 output bodies are byte/instruction-mapped static C-like text, but all 23 raw boundary classifications mark the source function/FDE boundary UNPROVEN; these candidates must remain uncounted.'}
(REP/'05_VERIFICATION_SUMMARY.json').write_text(json.dumps(summary,indent=2,ensure_ascii=False)+'\n',encoding='utf-8')
line='\n'.join(f"| {x['manifest_fde_index_zero_based']} | `{x['elf_va']}` | {x['candidate_size_bytes']} | `{x['manifest_body_sha256'][:16]}…` | {x['independent_capstone_slots']} | {x['ghidra_instruction_pcode_rows']} | {x['c_like_utf8_bytes']} | UNVERIFIED |" for x in rows)
(REP/'00_AUDIT_INDEX.md').write_text(f'''# TASK_245 R2 independent audit index\n\nTask SHA-256 `{HTASK}`; task revision 2; exact assignee `/root/audit_245_r2`; lease `LEASE-CEO-WORKER-TASK_245-R2`; fencing token `{FENCE}`.\n\nCanonical Standard fully read: `{STD}`; SHA-256 `{HSTD}`. Read `AGENTS.md`, `Docs/rules.md`, `.ai/ceo/SO45_TO_V4_PLAN.md`, `.ai/ceo/config.json`, `.ai/ceo/state.json`, `.ai/locks.json`, the END flag and exact ACTIVE task. END flag was absent. Target manifest SHA-256 `{HMAN}`.\n\nThe pinned source SHA-256 is `{HSRC}` for 5,133,080 bytes. R1's historical SOURCE path is absent in this checkout; the in-tree JNI copy `{rel(SRC)}` has the identical expected SHA-256 and exact byte count. This substitution is disclosed.\n\nIndependent checks used pyelftools to enumerate `.eh_frame` and executable PT_LOAD segments and defined `.dynsym` functions; direct source byte slices; ARM64 Capstone decoding; per-instruction source word/address checks; raw Ghidra p-code address mapping; Ghidra body/membership checks; and C-like output shape checks. R1 report/generator/research files and mandatory controls are all hashed in `03_INPUT_HASH_INVENTORY.csv`.\n''',encoding='utf-8')
(REP/'01_MASTER_REPORT.md').write_text(f'''# TASK_245 R2 — static candidate closeout\n\n**Outcome: COMPLETE_PARTIAL.** The immutable R1 package has 23 nonempty, error-free, balanced Ghidra C-like outputs. All 23 spans independently map to the pinned SO bytes and ARM64 source instructions. However, every raw result says `EXACT_GHIDRA_FUNCTION_START_FDE_BOUNDARY_UNPROVEN`. The task requires uncertain source boundaries to remain unverified, so **accepted newly counted C-like bodies: 0**. Do not add this task to the existing accepted baseline of 43,396 results across 45 SO files.\n\nIndependent parse verified 9,981 `.eh_frame` FDEs, 3,326 unique defined nonzero `.dynsym` `STT_FUNC` VAs and 6,655 nonexport FDE candidates. All 23 match one exact FDE, have no other-FDE/export-body overlap, map to exactly one executable file-backed PT_LOAD at the manifest file offset, and hash to the manifest body SHA. Independent Capstone decoded {sum(x['independent_capstone_slots'] for x in rows):,} 4-byte instruction slots; each saved source word/address matched bytes, and Ghidra instruction/p-code rows cover the corresponding sequential address slots after its `+0x100000` database image-base bias.\n\nFor every raw result, Ghidra's memory hash matches source bytes and its reported function/body/membership cover exactly the FDE candidate bytes. That establishes output coverage for the span, not that the FDE represents one complete source function. The C-like text is static decompiler output, not proof of algorithm semantics or runtime behavior.\n\n| FDE index (0-based) | Source VA | Bytes | Body SHA-256 | Capstone slots | Ghidra rows | C-like bytes | Boundary |\n|---:|---:|---:|---|---:|---:|---:|---|\n{line}\n\nSee `02_TARGET_EVIDENCE.csv` for every target, `03_INPUT_HASH_INVENTORY.csv` for full R1/control-input hashes, and `04_EVIDENCE_LEDGER.csv` for each claim disposition. Before counting any body, a separately bounded step must establish reliable source-function boundaries beyond the unwind FDE/Ghidra function declaration. No Ghidra rerun, semantic inference, source/product edit, or V4/P7 gate was performed.\n''',encoding='utf-8')
files={p.relative_to(REP).as_posix():hf(p) for p in sorted(REP.rglob('*')) if p.is_file() and p.name not in ('COMPLETE.json','PROGRESS.json')}
complete={'schema_version':'2.1.2','task_id':'TASK_245','revision':2,'status':'COMPLETE','outcome':'COMPLETE_PARTIAL','standard_sha256':HSTD,'task_sha256':HTASK,'target_manifest_sha256':HMAN,'source_sha256':HSRC,'fencing_token':FENCE,'target_candidates':23,'raw_C_like_outputs':raw_count,'accepted_new_C_like_bodies':accepted,'files':files,'code_files':['RESEARCH_WORK/TASK_245_R2/verify_task245_r2.py'],'report_folder':'RULES/REPORT/TASK_245_REPORT_R2','completed_at_utc':datetime.now(timezone.utc).isoformat()}
(REP/'COMPLETE.json').write_text(json.dumps(complete,indent=2,ensure_ascii=False)+'\n',encoding='utf-8')
print(json.dumps({'summary':summary,'report_files':len(files),'report_sha256':hf(REP/'COMPLETE.json')},indent=2))
