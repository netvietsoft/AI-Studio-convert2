"""R2 provenance clarification; preserve immutable R1 acquisition measurements."""
from pathlib import Path
import json,hashlib,sys,os,uuid
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'.ai/ceo'))
from controller import Controller,guard,iso
C=Controller(ROOT);OLD=ROOT/'RULES/REPORT/TASK_068_REPORT_R1';OUT=ROOT/'RULES/REPORT/TASK_068_REPORT_R2';DOCS=ROOT/'Docs/Reconstruction/References/storytold'
def sha(b):return hashlib.sha256(b).hexdigest()
def lease(path):
 reg=C.read_json(C.registry);v=[x for x in reg['active_locks'] if x['lease_id']=='LEASE-CEO-WORKER-TASK_068-R2'];assert len(v)==1
 v=v[0];assert C.lease_live(v) and v['fencing_token']==1015 and v['agent_id']=='c835368f-e9f9-41b6-88ee-8cd104245fa8' and v['task_sha']=='ef22cefda9c2f7cd3d62b5ba5b4506d1aacc847a77617bac6ba769e0c9627592'
 C.authorized(v,path)
def write(path,b):
 with guard(ROOT/'.ai/locks.registry.guard'):
  lease(path);path.parent.mkdir(parents=True,exist_ok=True);tmp=path.parent/('.task068-'+uuid.uuid4().hex+'.tmp');lease(tmp)
  with tmp.open('xb') as f:f.write(b);f.flush();os.fsync(f.fileno())
  lease(path);os.replace(tmp,path)
def jw(p,v):write(p,(json.dumps(v,ensure_ascii=False,indent=2)+'\n').encode())
standard=ROOT/'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt';text=standard.read_text(encoding='utf-8-sig');sh=sha(standard.read_bytes());assert sh=='10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f'
for rel in ['AGENTS.md','Docs/rules.md','.ai/ceo/SO45_TO_V4_PLAN.md','.ai/ceo/config.json','.ai/ceo/state.json','RULES/TASK/TASK_068_STORYTOLD_REFERENCE_ACQUISITION_ACTIVE.md']:(ROOT/rel).read_text(encoding='utf-8-sig')
assert not (OUT/'COMPLETE.json').exists()
prior=json.loads((OLD/'COMPLETE.json').read_text())
for rel,sh0 in prior['files'].items():
 b=(OLD/rel).read_bytes();assert sha(b)==sh0;write(OUT/rel,b)
m=json.loads((OUT/'02_SOURCE_MANIFEST.json').read_text());m.update(revision=2,historical_acquisition_origin={'folder':'RULES/REPORT/TASK_068_REPORT_R1','manifest_sha256':sha((OLD/'02_SOURCE_MANIFEST.json').read_bytes()),'meaning':'Original source downloads and24Git commands executed in R1; R2 reuses verified outputs, no rerun assertion'})
for s in m['sources']:
 for v in s['files']:
  b=(ROOT/s['path']/v['path']).read_bytes();assert sha(b)==v['sha256'] and hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()==v['git_blob']
jw(OUT/'02_SOURCE_MANIFEST.json',m)
old='native blur entry0x2344e8 theo CEO receipt';new='historical Ghidra FilterToFBO identifier0x2344e8 theo CEO receipt; current ELF address-space/base/ABI mapping UNKNOWN'
for p in [DOCS/'COMPARISON_MAP.md',OUT/'03_COMPARISON_MAP.md']:
 t=p.read_text(encoding='utf-8');assert old in t;t=t.replace(old,new);write(p,t.encode())
t=(DOCS/'README.md').read_text(encoding='utf-8').replace('TASK_068_REPORT_R1/02_SOURCE_MANIFEST.json','TASK_068_REPORT_R2/02_SOURCE_MANIFEST.json');write(DOCS/'README.md',t.encode())
jw(OUT/'04_INDEX_ARTIFACTS.json',{p.relative_to(ROOT).as_posix():sha(p.read_bytes()) for p in DOCS.iterdir() if p.is_file()})
audit='# TASK068 R2 audit index\nActual executor Codex CEO root c835368f-e9f9-41b6-88ee-8cd104245fa8.\nLease LEASE-CEO-WORKER-TASK_068-R2, fence1015.\nFull canonical read '+iso(C.clock())+'\nPath '+str(standard)+'\nSHA256 '+sh+'\nCharacters '+str(len(text))+'\nAGENTS/rules/plan/config/state/exact R2 task read.\nR1 immutable acquisition audit and raw Git times are historical origin, not R2 executed commands. No upstream scripts/builds/dependencies, production/P0/ledger writes.\n'
write(OUT/'00_AUDIT_INDEX.md',audit.encode())
write(OUT/'01_MASTER_REPORT.md',b'# TASK068 R2 reference acquisition provenance\n\nThree pinned upstream reference checkouts remain intact:2695tracked files,79949717bytes,0LFS pointers,0submodules. R2 rehashed all working files against R1SHA256 andGitblob identities.24Git acquisition command receipts are unchanged historical R1 outputs with original times; no claim those commands ran in R2. Current CEO root integrity rerun receipt is separate.\n\nOne correction:0x2344e8 labels the historical Ghidra FilterToFBO text identifier, not a proven current ELF pointer. Address-space/base/ABI correspondence UNKNOWN. Hash links retained; guided filter remains an external candidate, not recovered blur kernel or proven parity. SoftLight normalized channel algebra only, full alpha/render/Android parity UNKNOWN.\n\nIndex Docs/Reconstruction/References/storytold/README.md; source folders .ai/reconstruction/reference_sources/storytold. No source reacquisition or production/P0/ledger changes. Await independent R2 review; no publication yet. R1 NEEDS_FIX remains preserved.\n')
jw(OUT/'06_R2_REUSE_PROVENANCE.json',{'prior_complete_sha256':sha((OLD/'COMPLETE.json').read_bytes()),'prior_manifest_sha256':sha((OLD/'02_SOURCE_MANIFEST.json').read_bytes()),'raw_receipts_original_sha256':sha((OLD/'raw/command_receipts.json').read_bytes()),'correction_cycle':1,'r2_script_sha256':sha(Path(__file__).read_bytes()),'native_address_mapping':'UNKNOWN','historical_identifier':'Ghidra FilterToFBO0x2344e8','r1_download_scripts':'Historical chain acquire.py->finalize.py->correct_index.py; not reexecuted in R2'})
jw(OUT/'PROGRESS.json',{'schema_version':'2.1.2','task_id':'TASK_068','revision':2,'status':'REVIEW_CANDIDATE_AWAITING_CEO','milestone':'ADDRESS_PROVENANCE_CLARIFIED_AND_PINNED_SOURCES_REVERIFIED','updated_at':iso(C.clock()),'fencing_token':1015})
files={p.relative_to(OUT).as_posix():sha(p.read_bytes()) for p in OUT.rglob('*') if p.is_file() and p.name not in ['COMPLETE.json','PROGRESS.json']}
jw(OUT/'COMPLETE.json',{'schema_version':'2.1.2','task_id':'TASK_068','revision':2,'status':'COMPLETE','standard_sha256':sh,'files':files,'code_files':prior['code_files']+['scripts/task068_storytold_reference/clarify_address_r2.py']})
print('R2 clarified and frozen; all2695source identities reverified, R1 receipts preserved.')
