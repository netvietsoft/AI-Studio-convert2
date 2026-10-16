#!/usr/bin/env python3
"""Seal immutable TASK_249 report/code artifacts; COMPLETE.json excludes its own digest."""
from pathlib import Path
from datetime import datetime,timezone
import json,hashlib
ROOT=Path(__file__).resolve().parents[2]; REPORT=ROOT/'RULES/REPORT/TASK_249_REPORT_R1'
def sha(p): return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 std=ROOT/'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt'; task=ROOT/'RULES/TASK/TASK_249_SO45_PVGCODEC_GAP_RECOVERY_ACTIVE.md'; manifest=ROOT/'.ai/ceo/reviews/TASK_249_internal_targets.json'; src=Path(r'F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libPVGCodec.so')
 ledger=json.loads((REPORT/'source/word_edge_ledger.json').read_text(encoding='utf-8'))['summary']
 gh=json.loads((REPORT/'ghidra/gap_listing.json').read_text(encoding='utf-8'))['summary']
 lsda=json.loads((REPORT/'source/lsda_callsite_evidence.json').read_text(encoding='utf-8'))
 assert sha(std)=='10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f'
 assert sha(task)=='4f5ec07747c381257116461979fa5fced279911b19a0f2f3aa0e5348e339ae0e'
 assert sha(manifest)=='29890e85a5c7677cabf51a20dcbc3fe34b9531fc12ceadb1e25476d9b81c1f27'
 assert sha(src)=='4fa5f275c8ddecf7caa960c812108ec9e801365bfe5bc9cf38598233bc449ffc'
 assert gh=={'gap_words':402,'external_flow_references':0,'function_body_member_words':0,'instruction_defined_words':0,'both':0}
 assert ledger['aarch64_words']==402 and ledger['gap_sha256']=='f825653da2ed819fd5334f4103037f4466fcf8655080e5ec84c56a684569c54b'
 assert ledger['c_like_function_bodies_recovered']==0 and ledger['candidate_fde']['source_function_boundary_proven'] is False
 assert len(lsda['callsite_rows'])==184 and lsda['rows_with_landing_pad']==167 and lsda['unique_landing_pad_count']==128
 assert lsda['landing_pad_addresses_in_gap'] and lsda['raw_bytes_length']==1376
 files={p.relative_to(REPORT).as_posix():sha(p) for p in sorted(REPORT.rglob('*')) if p.is_file() and p.name!='COMPLETE.json'}
 code_root=ROOT/'scripts/task_249_codex_internal'; code_files={p.relative_to(ROOT).as_posix():sha(p) for p in sorted(code_root.rglob('*')) if p.is_file()}
 assert all(x.startswith(('00_','01_','ghidra/','source/')) for x in files)
 locks=json.loads((ROOT/'.ai/locks.json').read_text(encoding='utf-8'))
 lease=next(x for x in locks['active_locks'] if x['lease_id']=='LEASE-CEO-WORKER-TASK_249-R1')
 assert lease['agent_id']=='/root/pvg_gap_decode' and lease['task_sha']=='4f5ec07747c381257116461979fa5fced279911b19a0f2f3aa0e5348e339ae0e' and lease['fencing_token']==1289 and lease['status']=='ACTIVE'
 doc={'schema_version':'2.1.2','task_id':'TASK_249','revision':1,'status':'COMPLETE','semantic_disposition':'PARTIAL_GAP_DISASSEMBLED_NO_FUNCTION_RECOVERED',
  'generated_at':datetime.now(timezone.utc).isoformat(),'standard_path':str(std),'standard_sha256':sha(std),'task_path':str(task),'task_sha256':sha(task),
  'target_manifest_path':str(manifest),'target_manifest_sha256':sha(manifest),'lease_id':lease['lease_id'],'agent_id':lease['agent_id'],
  'fencing_token':lease['fencing_token'],'lease_expiry':lease['expiry'],'canonical_read_acknowledgment_utc':'2026-10-16T00:12:23.802078+00:00',
  'source_library':{'path':str(src),'sha256':sha(src),'bytes':src.stat().st_size},
  'candidate_fde':{'start_va':'0xa8b08','end_va_exclusive':'0xaf68c','size_bytes':27524,'sha256':ledger['fde_body_sha256'],'source_boundary_proven':False},
  'target_gap':{'start_va':'0xaf040','end_va_exclusive':'0xaf688','file_offset':'0xaf040','size_bytes':1608,'sha256':ledger['gap_sha256'],'arm64_words':402,'source_words_independently_decoded':402},
  'ghidra':{'version':'12.1.4','mode':'-noanalysis -readOnly; max CPU 1; heap cap 1G','exit_code':0,'defined_gap_instructions':gh['instruction_defined_words'],'function_body_member_words':gh['function_body_member_words'],'external_flow_references_into_gap':gh['external_flow_references'],'project_baseline_files_verified_unchanged':9},
  'control_flow':{'internal_direct_branch_sites':129,'direct_branch_sites_exiting_gap':1,'direct_call_sites':49,'direct_incoming_branch_sites_from_elsewhere_in_candidate_fde':len(ledger['direct_branch_edges_from_outside_gap_inside_candidate_fde']),'unresolved_indirect_edges':len(ledger['unresolved_indirect_edges']),'possible_return_continuation_from_0xaf03c':True},
  'lsda':{'callsite_rows':184,'rows_with_landing_pad':167,'unique_landing_pad_addresses':128,'landing_pads_inside_gap':True,'action_nonzero_rows':0,'raw_bytes_sha256':lsda['raw_bytes_sha256']},
  'c_like_bodies_recovered':0,'pcode_gap_addresses_mapped':0,'pcode_gap_words_absent_from_prior_optimized_ir':402,
  'ordinary_provenance_records_relied_on':0,'ordinary_records_rechecked':0,'targeted_words_rehashed_and_decoded':402,
  'review_state':'REVIEW_CANDIDATE_AWAITING_CEO','independent_ceo_review_required':True,'commit_performed':False,'push_performed':False,
  'limitations':['candidate FDE does not prove source function boundary','static cleanup/landing-pad interpretation only','no C-like body recovered','source behavior/runtime not tested','IR address absence is not reachability proof'],
  'files':files,'code_files':code_files,'complete_sha256_note':'COMPLETE.json is the sole report file excluded from files because self-hashing is undefined; all other report and code artifacts are SHA-256 bound.'}
 (REPORT/'COMPLETE.json').write_text(json.dumps(doc,indent=2,ensure_ascii=False)+'\n',encoding='utf-8')
 print(json.dumps({'status':doc['status'],'review_state':doc['review_state'],'report_files':len(files),'code_files':len(code_files),'fence':lease['fencing_token'],'gap_words':402,'c_like_bodies':0},indent=2))
if __name__=='__main__':main()

