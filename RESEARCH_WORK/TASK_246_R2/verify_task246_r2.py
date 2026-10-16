import hashlib, json, pathlib, sys
ROOT = pathlib.Path(r'F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2')
REPORT = ROOT / 'RULES/REPORT/TASK_246_REPORT_R1'
OUT = ROOT / 'RULES/REPORT/TASK_246_REPORT_R2'
MANIFEST = ROOT / '.ai/ceo/reviews/TASK_246_internal_targets.json'
TASK = ROOT / 'RULES/TASK/TASK_246_SO45_INTERNAL_CONTINUATION_ACTIVE.md'
STANDARD = ROOT / 'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt'
SOURCE_ORIGINAL = pathlib.Path(r'F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libPVGImageCodec.so')
SOURCE_REPO = ROOT / 'lib-core-graphics/src/main/jniLibs/arm64-v8a/libPVGImageCodec.so'
EXPECTED = {
    'standard_sha256':'10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f',
    'task_sha256':'ef8a602ebd36ca5d624998b730f42b322467473c3271a1dc31eb7b6cb4e46b10',
    'manifest_sha256':'ada323831163d1d0ef90d3cf6d6596ddee49b98006ddee2e34b53f4c75b9ae96',
    'source_sha256':'7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b',
}
def sha(b): return hashlib.sha256(b).hexdigest()
def file_sha(p): return sha(p.read_bytes())
def readj(p): return json.loads(p.read_text(encoding='utf-8'))
def must(ok,msg):
    if not ok: raise AssertionError(msg)

def main():
    checks=[]
    for label,p,key in [('canonical standard',STANDARD,'standard_sha256'),('active task',TASK,'task_sha256'),('pinned target manifest',MANIFEST,'manifest_sha256'),('original source',SOURCE_ORIGINAL,'source_sha256'),('repo source copy',SOURCE_REPO,'source_sha256')]:
        got=file_sha(p); must(got==EXPECTED[key], f'{label} SHA mismatch {got}')
        checks.append({'check':label,'path':str(p),'sha256':got,'pass':True})
    manifest=readj(MANIFEST); must(manifest['task_id']=='TASK_246' and manifest['selected_count']==2,'manifest identity/count')
    source=SOURCE_ORIGINAL.read_bytes(); source_repo=SOURCE_REPO.read_bytes(); must(source==source_repo,'source copies differ')
    command=readj(REPORT/'ghidra/command.json'); progress=readj(REPORT/'PROGRESS.json')
    source_index=readj(REPORT/'source_index.json'); project=readj(REPORT/'project_copy_receipt.json')
    cfg_summary=readj(REPORT/'CFG_SUMMARY.json')
    java_script=ROOT/'scripts/task_246_codex_internal/ExtractInternal246.java'
    must(progress['candidate_files']==2 and progress['parseable_rows']==2,'progress candidate/parseable counts')
    must(progress['memory_hash_matched']==2 and progress['c_like_rows']==0,'progress memory/C-like counts')
    must(command['status']=='OUTPUT_READY' and command['exit_code']==0 and command['kill_receipt'] is None,'process receipt state')
    must(command['lease_id']=='LEASE-CEO-WORKER-TASK_246-R1' and command['fencing_token']==1284,'R1 command lease binding')
    must(command['source_sha256']==EXPECTED['source_sha256'],'command source hash')
    must(command['target_manifest_sha256']==EXPECTED['manifest_sha256'],'command manifest hash')
    must(file_sha(java_script)==command['java_script_sha256'],'Ghidra script receipt hash')
    must(file_sha(REPORT/'targets.tsv')==command['target_tsv_sha256'],'target TSV receipt hash')
    must(file_sha(REPORT/'ghidra/stdout.log')==command['stdout_sha256'],'stdout receipt hash')
    must(file_sha(REPORT/'ghidra/stderr.log')==command['stderr_sha256'],'stderr receipt hash')
    cfg_summary_hash=file_sha(REPORT/'CFG_SUMMARY.json')
    must(cfg_summary_hash==file_sha(REPORT/'CFG_SUMMARY.json'),'CFG summary hash self-consistency')
    must(command['observed']['candidate_files']==2 and command['observed']['parseable_rows']==2 and command['observed']['memory_hash_matched']==2,'command observed counts')
    must(command['observed']['c_like_rows']==0 and command['observed']['listing_slots']==8182 and command['observed']['pcode_slots']==8182,'command observed static counts')
    must(source_index['source_sha256']==EXPECTED['source_sha256'],'source index hash')
    must(len(source_index['rows'])==2 and source_index['instruction_slots']==8182,'source index counts')
    must(project['original_unchanged'] is True and project['file_count']==9,'project copy receipt assertions')
    project_dir=ROOT/'RESEARCH_WORK/TASK_246_R1/ghidra_project'
    project_actual={}
    for rel,expected in project['copied_hashes'].items():
        path=project_dir/pathlib.PurePosixPath(rel)
        got=file_sha(path)
        must(got==expected,f'project receipt mismatch: {rel}: {got} != {expected}')
        project_actual[rel]=got
    must(len(project_actual)==9,'project file receipt count')
    must(command['output_files']=={n:file_sha(REPORT/'ghidra/candidates'/n) for n in ('candidate_001.json','candidate_002.json')},'candidate output receipt hashes')
    # Independently parse ELF64 program headers and require executable file-backed mapping.
    import struct
    e_phoff=struct.unpack_from('<Q',source,32)[0]; e_phentsize=struct.unpack_from('<H',source,54)[0]; e_phnum=struct.unpack_from('<H',source,56)[0]
    loads=[]
    for i in range(e_phnum):
        off=e_phoff+i*e_phentsize
        p_type,p_flags,p_offset,p_vaddr,p_paddr,p_filesz,p_memsz,p_align=struct.unpack_from('<IIQQQQQQ',source,off)
        if p_type==1: loads.append({'flags':p_flags,'offset':p_offset,'vaddr':p_vaddr,'filesz':p_filesz,'memsz':p_memsz})
    must(any(s['flags'] & 1 for s in loads),'ELF has no executable PT_LOAD')
    assembly_lines=(REPORT/'assembly.ndjson').read_text(encoding='utf-8').splitlines()
    must(len(assembly_lines)==2,'assembly row count')
    assembly={json.loads(x)['index']:json.loads(x) for x in assembly_lines}
    must(set(assembly)=={1,2},'assembly indices')
    rows=[]; total_slots=0; recovered_clike=0
    for tgt in manifest['targets']:
        ix=1 if tgt['global_index']==3134 else 2 if tgt['global_index']==3285 else None
        must(ix is not None,'unexpected target index')
        cand=readj(REPORT/f'ghidra/candidates/candidate_{ix:03d}.json')
        asm=assembly[ix]
        cfg_path=REPORT/f'cfg_{tgt["global_index"]}.json'
        cfg=readj(cfg_path)
        cfg_receipt=next(x for x in cfg_summary['targets'] if x['global_index']==tgt['global_index'])
        must(file_sha(cfg_path)==cfg_receipt['cfg_sha256'],'CFG raw output receipt hash')
        must(cand['index']==ix and cand['elf_va']==tgt['elf_va'] and cand['size_bytes']==tgt['size_bytes'],'candidate identity')
        must(cand['original_file_offset']==tgt['file_offset'],'candidate file offset')
        body=source[int(tgt['file_offset'],16):int(tgt['file_offset'],16)+tgt['size_bytes']]
        foff=int(tgt['file_offset'],16); va=int(tgt['elf_va'],16)
        must(any((s['flags'] & 1) and s['offset']<=foff and foff+tgt['size_bytes']<=s['offset']+s['filesz'] and s['vaddr']+(foff-s['offset'])==va for s in loads),'target span is not in file-backed executable PT_LOAD')
        bh=sha(body)
        must(bh==tgt['body_sha256']==cand['expected_original_body_sha256']==cand['owned_project_memory_sha256']==asm['body_sha256'],'source membership body digest')
        slots=tgt['instruction_slots']
        must(len(cand['instructions'])==slots==len(cand['instruction_pcode'])==len(asm['instructions']),'candidate/assembly/pcode slot count')
        must(cand['instruction_count']==slots and cand['missing_instruction_slots']==0 and cand['pcode_instruction_slots']==slots,'candidate counts')
        must(cand['source_bytes_match'] is True,'candidate says source bytes mismatch')
        must(asm['elf_va']==tgt['elf_va'] and asm['body_sha256']==bh,'assembly body mapping')
        for i,ins in enumerate(asm['instructions']):
            word=body[i*4:i*4+4].hex()
            must(len(body[i*4:i*4+4])==4 and ins['word_le'].lower()==word,f'raw bytes mismatch index {ix} slot {i}')
            must(int(ins['va'],16)==int(tgt['elf_va'],16)+4*i,f'assembly address discontinuity index {ix} slot {i}')
            c_ins=cand['instructions'][i]
            must(c_ins.startswith(f'{int(ins["va"],16)+0x100000:08x}: '),f'candidate DB address mismatch index {ix} slot {i}')
            p_ins=cand['instruction_pcode'][i]
            must(p_ins.startswith(f'{int(ins["va"],16)+0x100000:08x}: '),f'pcode address mismatch index {ix} slot {i}')
        must(cfg['global_index']==tgt['global_index'] and cfg['elf_va']==tgt['elf_va'] and cfg['size_bytes']==tgt['size_bytes'],'CFG target mapping')
        must(cfg['source_body_sha256']==bh and cfg['source_instruction_coverage_slots']==slots,'CFG source mapping/coverage')
        must(cfg['undecoded_slots']==0 and cfg['uncovered_source_instruction_ranges']==[],'CFG instruction coverage gaps')
        seen=[]
        for b in cfg['blocks']:
            first,last,count=b['first_slot'],b['last_slot'],b['slot_count']
            must(last>=first and count==last-first+1,'CFG block slot arithmetic')
            must(int(b['start_va'],16)==int(tgt['elf_va'],16)+4*first,'CFG block start address')
            must(int(b['end_exclusive_va'],16)==int(tgt['elf_va'],16)+4*(last+1),'CFG block end address')
            seen.extend(range(first,last+1))
        must(len(seen)==slots and sorted(seen)==list(range(slots)),f'CFG block partition has overlap/gap index {ix}')
        must(len(cfg['blocks'])==cfg['block_count'],'CFG block count')
        must(cand['decompile_success'] is False and cand['pseudocode']=='' and not cand['pseudocode_sha256'],'unexpected C-like output')
        must(cand['boundary_ambiguity']=='GHIDRA_FUNCTION_BODY_DIFFERS_FROM_FDE_RANGE','boundary ambiguity classification')
        must(cand['function_origin']=='EXISTING_ENTRY','function origin classification')
        must(cand['decompile_error']=='FULL_FDE_NOT_REPEATED_AFTER_TASK_239_15_SECOND_TIMEOUT; CFG_AND_PCODE_METHOD','timeout/procedure classification')
        clike = bool(cand['decompile_success'] and cand['pseudocode'] and cand['pseudocode_sha256'])
        recovered_clike += int(clike)
        total_slots += slots
        rows.append({'index':ix,'global_index':tgt['global_index'],'elf_va':tgt['elf_va'],'bytes':tgt['size_bytes'],'body_sha256':bh,'instruction_slots':slots,'raw_words_verified':slots,'candidate_disassembly_slots':len(cand['instructions']),'pcode_slots':len(cand['instruction_pcode']),'cfg_blocks':len(cfg['blocks']),'cfg_partition_slots':len(seen),'function_body_member_bytes':cand['body_member_bytes_within_fde'],'fde_bytes':tgt['size_bytes'],'boundary_ambiguity':cand['boundary_ambiguity'],'decompile_success':cand['decompile_success'],'pseudocode_sha256':cand['pseudocode_sha256'],'decompile_error':cand['decompile_error'],'source_instruction_gaps':cfg['uncovered_source_instruction_ranges'],'uncovered_high_level_behavior':cfg['uncovered_high_level_behavior_range']})
    must(total_slots==8182 and progress['listing_slots']==8182 and progress['pcode_slots']==8182,'total slots')
    must(cfg_summary['source_slots']==8182 and cfg_summary['ordinary_spread_checked_slots']==819 and cfg_summary['verified_behavior_candidates']==0,'summary coverage/sample/behavior totals')
    must(cfg_summary['uncovered_source_instruction_ranges']==[] and cfg_summary['uncovered_high_level_behavior_indices']==[3134,3285],'summary gaps')
    # Independently validate the 819 sampled source-word anchors in CFG summary.
    sample_count=0
    for sample in cfg_summary['spread_samples']:
        ix=1 if sample['global_index']==3134 else 2 if sample['global_index']==3285 else None
        must(ix is not None,'spread sample target')
        asm=assembly[ix]['instructions']; slot=sample['slot']; must(0<=slot<len(asm),'spread sample slot range')
        source_row=asm[slot]
        must(sample['va']==source_row['va'] and sample['word_le'].lower()==source_row['word_le'].lower(),'spread sample bytes/address')
        must(sample['mnemonic']==source_row['mnemonic'] and sample['operands']==source_row['operands'],'spread sample decode')
        sample_count+=1
    must(sample_count==819,'spread sample count')
    # Hash the full preserved R1 evidence set for immutable reference in R2 ledger.
    r1_hashes={p.relative_to(REPORT).as_posix():file_sha(p) for p in sorted(REPORT.rglob('*')) if p.is_file()}
    must('COMPLETE.json' not in r1_hashes,'R1 unexpectedly has a final seal; inspect before closeout')
    result={
      'task_id':'TASK_246','revision':2,'prior_revision':1,'lease_id':'LEASE-CEO-WORKER-TASK_246-R2','fencing_token':1286,
      'canonical_standard_sha256':EXPECTED['standard_sha256'],'task_sha256':EXPECTED['task_sha256'],'target_manifest_sha256':EXPECTED['manifest_sha256'],
      'source':{'original_path':str(SOURCE_ORIGINAL),'repository_copy_path':str(SOURCE_REPO),'sha256':EXPECTED['source_sha256'],'copies_equal':True,'ELF_program_headers':loads,'each_target_in_file_backed_executable_PT_LOAD':True},
      'prior_receipts':{'R1_report_hashes':r1_hashes,'Ghidra_command':command,'Ghidra_script_path':str(java_script),'Ghidra_script_sha256':file_sha(java_script),'project_copy_hashes_verified':project_actual},
      'targets':rows,'total_instruction_slots':total_slots,'raw_source_words_verified':total_slots,'candidate_instruction_slots':total_slots,'pcode_instruction_slots':total_slots,'CFG_partitioned_slots':total_slots,'CFG_blocks_total':sum(r['cfg_blocks'] for r in rows),'ordinary_spread_samples_verified':sample_count,
      'newly_accepted_c_like_bodies':recovered_clike,'R1_reported_c_like_bodies':progress['c_like_rows'],'CFG_or_IR_counted_as_function_bodies':False,
      'status':'COMPLETE','outcome':'COMPLETE_PARTIAL','process_relaunched':False,
      'limits':['FDE spans remain candidates, not proven function boundaries.','Ghidra function bodies differ from FDE extents for both targets.','No source-mapped C-like body exists in R1 raw output.','CFG/p-code evidence is static only and does not establish runtime behavior.','Both targets have uncovered high-level behavior indices; no semantic completeness claim.'],
      'checks':checks
    }
    must(recovered_clike==0,'this R1 package should yield zero C-like bodies')
    OUT.mkdir(parents=True,exist_ok=True)
    (OUT/'evidence_ledger.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({'status':'VERIFIED','targets':rows,'total_slots':total_slots,'cfg_blocks_total':result['CFG_blocks_total'],'spread_samples':sample_count,'newly_accepted_c_like_bodies':recovered_clike,'r1_files_hashed':len(r1_hashes),'evidence_ledger':str(OUT/'evidence_ledger.json')},ensure_ascii=False,indent=2))

if __name__=='__main__': main()




