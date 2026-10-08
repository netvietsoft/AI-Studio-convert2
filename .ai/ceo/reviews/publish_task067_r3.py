"""Reviewed TASK067 R3 diagnostic publication; only curated owned artifacts."""
from pathlib import Path
import hashlib,json,sys,subprocess,shutil
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'.ai/ceo'))
from controller import Controller,file_sha,iso
C=Controller(ROOT);WT=Path('F:/CONVERT_WORKTREES/ceo-so45-20261008');BRANCH='ceo/so45-v4-orchestration-20261008'
def git(*args):return subprocess.check_output(['git','-C',str(WT),*args])
C.scan()
with C.transaction() as(reg,state):
 task=C.tasks()['TASK_067'];v=state['tasks']['TASK_067']['verdict'];FP=state['tasks']['TASK_067']['fingerprint']
 assert task['revision']==3 and v['fingerprint']==FP and v['disposition']=='ACCEPTED'
 review=ROOT/v['review_file'];assert file_sha(review)==v['review_sha256']
 C.authorized(C.ceo_lease(reg),WT/'publication-scope')
 files=[ROOT/task['_path'],ROOT/'.ai/ceo/config.json',ROOT/'.ai/ceo/SO45_TO_V4_PLAN.md',review,Path(__file__).resolve(),ROOT/'.ai/ceo/receipts/TASK_067_R3_ROOT_PACKAGE_REVIEW.json',ROOT/'.ai/ceo/receipts/TASK_067_R3_DISPATCH.json',ROOT/'.ai/ceo/receipts/TASK_067_R3_INDEPENDENT_REVIEW.json']
 for folder in ['scripts/task067_package_r3','scripts/task067_diagnostic_r2','RULES/REPORT/TASK_067_REPORT_R2','RULES/REPORT/TASK_067_REPORT_R3']:
  files += [p for p in (ROOT/folder).rglob('*') if p.is_file() and '__pycache__' not in p.parts]
 hashes={p.relative_to(ROOT).as_posix():file_sha(p) for p in files}
 private=json.loads((ROOT/'.ai/ceo/receipts/TASK_067_DISPATCH_PRIVATE.json').read_text())['dispatch_token'].encode()
 for p in files:assert 'DISPATCH_PRIVATE' not in str(p) and private not in p.read_bytes()
assert git('branch','--show-current').decode().strip()==BRANCH
assert set(git('diff','--cached','--name-only').decode().splitlines())<=set(hashes)
for src in files:
 assert file_sha(src)==hashes[src.relative_to(ROOT).as_posix()]
 dest=WT/src.relative_to(ROOT);dest.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(src,dest)
rels=list(hashes)
for i in range(0,len(rels),40):git('-c','core.autocrlf=false','add','--',*rels[i:i+40])
changed=git('diff','--cached','--name-only').decode().splitlines();assert set(changed)<=set(rels)
if changed:
 lint=[p for p in changed if '/raw/' not in p]
 if lint:git('-c','core.whitespace=blank-at-eol,blank-at-eof,space-before-tab,cr-at-eol','diff','--cached','--check','--',*lint)
 git('commit','-m','docs(research): verify SO45 validator diagnostic and preserve historical provenance')
commit=git('rev-parse','HEAD').decode().strip()
for rel,sh in hashes.items():assert hashlib.sha256(git('show',commit+':'+rel)).hexdigest()==sh
with C.transaction() as(reg,state):assert state['tasks']['TASK_067']['verdict']['fingerprint']==FP;C.ceo_lease(reg)
git('push','origin',BRANCH);remote=git('ls-remote','origin','refs/heads/'+BRANCH).decode().split()[0];assert remote==commit
with C.transaction() as(reg,state):
 state['last_target_commit_sha']=commit
 data={'fingerprint':FP,'revision':3,'commit':commit,'remote_verified':remote,'scoped_blob_hashes':len(files),'observed_at':iso(C.clock()),'baseline_accepted':False,'curated_files':hashes}
 C.replace_json(ROOT/'.ai/ceo/receipts/TASK_067_R3_PUBLICATION.json',data,reg)
 C.event(state,'CEO_PUBLICATION_VERIFIED','TASK_067',revision=3,fingerprint=FP,commit=commit,scoped_blob_hashes=len(files),baseline_accepted=False)
print(json.dumps({k:v for k,v in data.items() if k!='curated_files'}))
