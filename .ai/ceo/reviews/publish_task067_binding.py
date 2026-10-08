"""Publish only curated non-secret actor handoff and CEO controller corrections."""
import ast,hashlib,json,pathlib,shutil,subprocess,sys
sys.path.insert(0,str(pathlib.Path(__file__).resolve().parents[1]))
from controller import Controller,file_sha,iso
root=pathlib.Path(__file__).resolve().parents[3];c=Controller(root)
out=root/'RULES/REPORT/CEO_SO45_ORCHESTRATION'
names=['TASK_067_IDENTITY_INCIDENT.json','TASK_067_WRONG_ACTOR_ACTIVITY.json','TASK_067_R2_DISPATCH.json']
receipts=[root/'.ai/ceo/receipts'/n for n in names]
ceo=['controller.py','test_controller.py','config.json','TOOLING_HANDOFF.md','SO45_TO_V4_PLAN.md','AGY_SCAN_PROMPT.txt',
     'reviews/rebind_task067.py','reviews/record_task067_identity_receipts.py','reviews/publish_task067_binding.py']
with c.transaction() as(registry,state):
    task=c.tasks()['TASK_067'];assert task['revision']==2 and task['status']=='ACTIVE'
    assert state['claims']['TASK_067:r1']['status']=='REVOKED'
    for rel in ceo:
        if rel.endswith('.py'):ast.parse((root/'.ai/ceo'/rel).read_text(encoding='utf-8'))
    for src in receipts:
        dest=out/'receipts'/src.name;c.authorized(c.ceo_lease(registry),dest)
        dest.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(src,dest)
    manifest=out/'06_MANIFEST.sha256';c.authorized(c.ceo_lease(registry),manifest)
    manifest.write_text(''.join(f'{file_sha(p)}  {p.relative_to(out).as_posix()}\n' for p in sorted(out.rglob('*')) if p.is_file() and p!=manifest),encoding='utf-8')
wt=pathlib.Path('F:/CONVERT_WORKTREES/ceo-so45-20261008')
def git(*args):return subprocess.check_output(['git','-C',str(wt),*args])
assert git('branch','--show-current').decode().strip()=='ceo/so45-v4-orchestration-20261008'
# A failed lint may leave only this helper's scoped paths staged; checked below.
files=[root/task['_path']]+[root/'.ai/ceo'/p for p in ceo]+receipts
files += [out/p for p in ['TASK_067_IDENTITY_REBIND.md','TASK_067_R2_ACTUAL_DISPATCH.md','06_MANIFEST.sha256']]
files += [p for p in (out/'TASK_067_R1_IDENTITY_INCIDENT').rglob('*') if p.is_file()]
files += [out/'receipts'/n for n in names]
rels=[]
private=json.loads((root/'.ai/ceo/receipts/TASK_067_DISPATCH_PRIVATE.json').read_text())['dispatch_token'].encode()
for src in files:
    assert 'DISPATCH_PRIVATE' not in str(src)
    assert private not in src.read_bytes(),f'Private dispatch material leaked: {src}'
    rel=src.relative_to(root);dest=wt/rel;dest.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(src,dest);rels.append(rel.as_posix())
for offset in range(0,len(rels),50):git('-c','core.autocrlf=false','add','--',*rels[offset:offset+50])
changed=git('diff','--cached','--name-only').decode().splitlines()
assert changed and set(changed)<=set(rels)
lint=[p for p in changed if '/receipts/' not in p and '/TASK_067_R1_IDENTITY_INCIDENT/' not in p]
git('-c','core.whitespace=blank-at-eol,blank-at-eof,space-before-tab,cr-at-eol','diff','--cached','--check','--',*lint)
git('commit','-m','fix(ceo): fence revoked claims and bind TASK067 actual worker dispatch')
commit=git('rev-parse','HEAD').decode().strip()
for src in files:
    assert hashlib.sha256(git('show',commit+':'+src.relative_to(root).as_posix())).hexdigest()==file_sha(src)
git('push','origin','ceo/so45-v4-orchestration-20261008')
remote=git('ls-remote','origin','refs/heads/ceo/so45-v4-orchestration-20261008').decode().split()[0];assert remote==commit
with c.transaction() as(registry,state):
    state['last_target_commit_sha']=commit
    c.event(state,'CEO_PUBLICATION_VERIFIED','TASK_067',revision=2,commit=commit,actor_binding_control_tests=29,scoped_blob_hashes=len(files))
    c.replace_json(root/'.ai/ceo/receipts/task067-binding-publication.json',{'commit':commit,'remote':remote,'scoped_blob_hashes':len(files),
        'changed_paths':len(changed),'private_dispatch_material_published':False,'observed_at':iso(c.clock())},registry)
print(json.dumps({'commit':commit,'remote_verified':remote,'scoped_blob_hashes':len(files),'changed_paths':len(changed),'private_material_published':False}))
