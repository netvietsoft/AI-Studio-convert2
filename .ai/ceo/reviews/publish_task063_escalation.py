"""Publish scoped CEO escalation artifacts and verify immutable R3 Git bytes."""
import ast, hashlib, json, pathlib, shutil, subprocess, sys
sys.path.insert(0,str(pathlib.Path(__file__).resolve().parents[1]))
from controller import Controller, file_sha, iso
root=pathlib.Path(__file__).resolve().parents[3]
c=Controller(root)
out=root/'RULES/REPORT/CEO_SO45_ORCHESTRATION'
review_names=['TASK_063_R3_2041a6a2_NEEDS_FIX.md','verify_task063_r3_critical.py','verify_task063_r3_inputs.py',
              'verify_task063_r3_additional.py','escalate_task063_r3.py','publish_task063_escalation.py']
receipt_paths=[root/'.ai/ceo/receipts/TASK_063_R3_input_validation.json',root/'.ai/ceo/receipts/TASK_063_R3_additional_validation.json']
receipt_paths += [p for rel in ['TASK_063_R3_critical','TASK_063_R3_samples'] for p in (root/'.ai/ceo/receipts'/rel).rglob('*') if p.is_file()]
with c.transaction() as(registry,state):
    assert c.tasks()['TASK_063']['status']=='BLOCKED'
    assert c.tasks()['TASK_067']['status']=='ACTIVE'
    for name in review_names:
        if name.endswith('.py'): ast.parse((root/'.ai/ceo/reviews'/name).read_text(encoding='utf-8'))
    for src in receipt_paths:
        dest=out/'receipts'/src.relative_to(root/'.ai/ceo/receipts')
        c.authorized(c.ceo_lease(registry),dest)
        dest.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(src,dest)
    manifest=out/'06_MANIFEST.sha256'
    c.authorized(c.ceo_lease(registry),manifest)
    manifest.write_text(''.join(f'{file_sha(p)}  {p.relative_to(out).as_posix()}\n' for p in sorted(out.rglob('*')) if p.is_file() and p!=manifest),encoding='utf-8')
    c.event(state,'CEO_MATERIAL_PROGRESS_NOTIFIED','TASK_063',revision=3,milestone='R3 NEEDS_FIX; BLOCKED escalation; distinct TASK067 diagnostic issued',
        review_file='.ai/ceo/reviews/TASK_063_R3_2041a6a2_NEEDS_FIX.md')
wt=pathlib.Path('F:/CONVERT_WORKTREES/ceo-so45-20261008')
def git(*args):return subprocess.check_output(['git','-C',str(wt),*args])
assert git('branch','--show-current').decode().strip()=='ceo/so45-v4-orchestration-20261008'
assert not git('diff','--cached','--name-only').strip()
files=[root/'RULES/TASK/TASK_063_SO45_INPUT_TRUTH_AND_RESEARCH_DISPATCH_ACTIVE.md',
       root/'RULES/TASK/TASK_067_VALIDATOR_FAILURE_DIAGNOSTIC_ACTIVE.md',root/'.ai/ceo/config.json',root/'.ai/ceo/SO45_TO_V4_PLAN.md']
files += [root/'.ai/ceo/reviews'/n for n in review_names]+receipt_paths
files += [p for p in out.rglob('*') if p.is_file()]
rels=[]
for src in files:
    rel=src.relative_to(root); dest=wt/rel
    dest.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(src,dest);rels.append(rel.as_posix())
for offset in range(0,len(rels),60):
    git('-c','core.autocrlf=false','add','--',*rels[offset:offset+60])
changed=git('diff','--cached','--name-only').decode().splitlines()
assert changed and set(changed)<=set(rels)
lint=[p for p in changed if 'SNAPSHOT/' not in p and '/receipts/' not in p]
git('-c','core.whitespace=blank-at-eol,blank-at-eof,space-before-tab,cr-at-eol','diff','--cached','--check','--',*lint)
git('commit','-m','docs(ceo): escalate TASK063 R3 and assign bounded TASK067 diagnostic')
commit=git('rev-parse','HEAD').decode().strip()
archive=out/'TASK_063_R3_SNAPSHOT'
hashes=json.loads((archive/'SNAPSHOT_MANIFEST.json').read_text())
for rel,expected in hashes.items():
    assert hashlib.sha256(git('show',commit+':'+(archive/rel).relative_to(root).as_posix())).hexdigest()==expected
for src in receipt_paths:
    assert hashlib.sha256(git('show',commit+':'+src.relative_to(root).as_posix())).hexdigest()==file_sha(src)
git('push','origin','ceo/so45-v4-orchestration-20261008')
remote=git('ls-remote','origin','refs/heads/ceo/so45-v4-orchestration-20261008').decode().split()[0]
assert remote==commit
with c.transaction() as(registry,state):
    state['last_target_commit_sha']=commit
    c.event(state,'CEO_PUBLICATION_VERIFIED','TASK_063',revision=3,kind_detail='LOOP_GUARD_ESCALATION',commit=commit,archive_byte_hashes=len(hashes))
    c.replace_json(root/'.ai/ceo/receipts/task063-r3-escalation-publication.json',{'commit':commit,'remote':remote,'archive_files_verified':len(hashes),
        'proof_receipts_verified':len(receipt_paths),'changed_paths':len(changed),'observed_at':iso(c.clock())},registry)
print(json.dumps({'commit':commit,'remote_verified':remote,'archive_files_verified':len(hashes),'proof_receipts_verified':len(receipt_paths),'changed_paths':len(changed)}))
