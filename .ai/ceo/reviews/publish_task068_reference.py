"""Publish the reviewed TASK068 reference metadata only on the owned CEO branch."""
from pathlib import Path
import hashlib,json,sys,subprocess,shutil
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'.ai/ceo'))
from controller import Controller,file_sha,iso
C=Controller(ROOT)
FP=None
WT=Path('F:/CONVERT_WORKTREES/ceo-so45-20261008')
BRANCH='ceo/so45-v4-orchestration-20261008'
def git(*args):
 return subprocess.check_output(['git','-C',str(WT),*args])
with C.transaction() as(reg,state):
 task=C.tasks()['TASK_068'];assert task['revision']==2; v=state['tasks']['TASK_068']['verdict'];FP=state['tasks']['TASK_068']['fingerprint']
 assert v['fingerprint']==FP and v['disposition']=='ACCEPTED'
 assert state['tasks']['TASK_068']['fingerprint']==FP
 review=ROOT/v['review_file'];assert file_sha(review)==v['review_sha256']
 C.authorized(C.ceo_lease(reg),WT/'publication-scope')
 files=[ROOT/task['_path'],ROOT/C.tasks()['TASK_067']['_path'],ROOT/'.ai/ceo/reviews/TASK_068_R1_670293d3_NEEDS_FIX.md',ROOT/'.ai/ceo/receipts/TASK_068_R2_CRITICAL_REVIEW.json',ROOT/'.ai/ceo/receipts/TASK_068_ELF_ADDRESS_FINDING.json',ROOT/'.ai/ceo/receipts/TASK_068_TASK_R1_VERIFIED_SNAPSHOT.md',ROOT/'.ai/ceo/config.json',ROOT/'.ai/ceo/SO45_TO_V4_PLAN.md',review,Path(__file__).resolve(),ROOT/'.ai/ceo/receipts/TASK_068_ROOT_SOURCE_REVIEW.json']
 for folder in ['RULES/REPORT/CEO_SO45_ORCHESTRATION/TASK_067_R2_PACKAGING_BLOCKER','scripts/task068_storytold_reference','Docs/Reconstruction/References/storytold','RULES/REPORT/TASK_068_REPORT_R1','RULES/REPORT/TASK_068_REPORT_R2']:
  files += [p for p in (ROOT/folder).rglob('*') if p.is_file() and '__pycache__' not in p.parts]
 assert all('.ai/reconstruction/reference_sources' not in p.relative_to(ROOT).as_posix() for p in files)
 source_hashes={p.relative_to(ROOT).as_posix():file_sha(p) for p in files}
 private=json.loads((ROOT/'.ai/ceo/receipts/TASK_067_DISPATCH_PRIVATE.json').read_text())['dispatch_token'].encode()
 for p in files:assert 'DISPATCH_PRIVATE' not in str(p) and private not in p.read_bytes()
assert git('branch','--show-current').decode().strip()==BRANCH
staged=git('diff','--cached','--name-only').decode().splitlines()
assert set(staged)<=set(source_hashes), 'Unrelated staged work must be preserved; stop publication'
for src in files:
 assert file_sha(src)==source_hashes[src.relative_to(ROOT).as_posix()]
 dest=WT/src.relative_to(ROOT);dest.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(src,dest)
rels=list(source_hashes)
for i in range(0,len(rels),40):git('-c','core.autocrlf=false','add','--',*rels[i:i+40])
changed=git('diff','--cached','--name-only').decode().splitlines();assert set(changed)<=set(rels)
if changed:
 lint=[p for p in changed if '/raw/' not in p]
 if lint:git('-c','core.whitespace=blank-at-eol,blank-at-eof,space-before-tab,cr-at-eol','diff','--cached','--check','--',*lint)
 git('commit','-m','docs(research): pin Storytold editor sources and compare with SO45 evidence')
commit=git('rev-parse','HEAD').decode().strip()
for rel,sh in source_hashes.items():assert hashlib.sha256(git('show',commit+':'+rel)).hexdigest()==sh
with C.transaction() as(reg,state):
 assert state['tasks']['TASK_068']['verdict']['fingerprint']==FP
 C.ceo_lease(reg)
git('push','origin',BRANCH)
remote=git('ls-remote','origin','refs/heads/'+BRANCH).decode().split()[0];assert remote==commit
with C.transaction() as(reg,state):
 assert state['tasks']['TASK_068']['verdict']['fingerprint']==FP
 state['last_target_commit_sha']=commit
 state['task068_publication']={'fingerprint':FP,'commit':commit,'remote_verified':remote,'scoped_blob_hashes':len(files),'source_clones_committed':False,'observed_at':iso(C.clock())}
 C.event(state,'CEO_PUBLICATION_VERIFIED','TASK_068',revision=2,fingerprint=FP,commit=commit,scoped_blob_hashes=len(files),source_clones_committed=False)
 C.replace_json(ROOT/'.ai/ceo/receipts/TASK_068_PUBLICATION.json',dict(state['task068_publication'],curated_files=source_hashes),reg)
print(json.dumps(state['task068_publication']))
