"""Publish only scoped CEO artifacts; verify immutable evidence Git blobs."""
from pathlib import Path
import ast, hashlib, json, shutil, subprocess, sys
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from controller import Controller, file_sha, iso
r = Path(__file__).resolve().parents[3]
c = Controller(r)
out = r/'RULES/REPORT/CEO_SO45_ORCHESTRATION'
review_names = ['TASK_063_R2_79d93b4f_NEEDS_FIX.md','TASK_063_CEO_SOFTLIGHT_NUMERIC_ADDENDUM.md',
                'verify_task063_r2_critical.py','issue_task063_r3.py','publish_task063_r3.py']
with c.transaction() as (registry,state):
    task = c.tasks()['TASK_063']
    assert task['revision']==3
    for name in review_names:
        if name.endswith('.py'): ast.parse((r/'.ai/ceo/reviews'/name).read_text(encoding='utf-8'))
    dest=out/'TASK_063_R2_REVIEW_AND_R3_DISPATCH.md'
    c.authorized(c.ceo_lease(registry),dest)
    dest.write_text('''# TASK_063 R2 review and R3 dispatch

R2 is NEEDS_FIX, bound to fingerprint79d93b4fdea4875bbdb5826ba9d1958ccad718cbe3208a5b708010b837b38c00. Review was acknowledged2026-10-08T04:51:19Z, SHA dbf941f8fe7793652d5b16a261dd999268b9fd745eb476ceaa07c2f9a033d42a. Frozen task/report/script/review package: TASK_063_R2_SNAPSHOT,112 files with actual SHA manifest.

Validated: 45 actual SO,44 complete container payload/declared-size/CRC matches, mfx prefix773652 and deficit581084; both original APK shader decodes; all native blur float/hex words; separate Aurora disassembly exit0; correct exact W3C counterexample0.134765625. The earlier CEO numeric error is corrected by a separate addendum; immutable R1 audit remains historical. Five ordinary SO reruns confirm all20 selected targets were imported UND functions with value0. Lane partition45 exactly once is valid.

Remaining defects: mfx self-comparison; incomplete header integrity enforcement; discarded tool errors and sample evidence; imported symbols mislabeled body targets; capped-symbol gap counts; wrong LayerFlow body hash/linecount; callsite mislabeled entry; broad architecture/runtime conclusions from symbol keyword counts; absent per-proof command/input/output receipts. See .ai/ceo/reviews/TASK_063_R2_79d93b4f_NEEDS_FIX.md for exact locations and corrections.

TASK_063 R3 is ACTIVE at RULES/TASK/TASK_063_SO45_INPUT_TRUTH_AND_RESEARCH_DISPATCH_ACTIVE.md, writing only scripts/task063_r3, evidenceTASK_063_R3, RULES/REPORT/TASK_063_REPORT_R3 and separate Ghidra project. R2 lease1010 revoked under atomic guards. Worker must read full canonical Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt, SHA10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F, every revision/resume and claim its new lease. R3 reuses valid measurements and bodies, with focused corrections and no broad repeated decompilation. Issuance is not proof of claim/completion.

Runtime: existing native CEO/AGY schedules remain active and deliver fresh wakes. API/CLI schedule listing is empty while native schedule files update. Recent AGY receipts are failed due stream timeout; CEO receipts include daemon restarts. AGY was running at dispatch, so no duplicate prompt was sent. Do not claim uninterrupted successful60s execution. Execution is one actual AGY lead; independent CEO read-only reviews do not count as seven AGY lane workers.

TASK_064A..G remain PLANNED and V4 is gated. P0/production are outside this research scope. No main merge or product PASS. CEO tooling syntax and scoped document consistency checked; build/device tests not required for this research handoff. Durable memory follow-up remains in review because global memory files are outside CEO lease.
''',encoding='utf-8')
    receipt_root=out/'receipts'
    shutil.copytree(r/'.ai/ceo/receipts/TASK_063_R2_critical',receipt_root/'TASK_063_R2_critical',dirs_exist_ok=True)
    shutil.copy2(r/'.ai/ceo/receipts/TASK_063_softlight_exact_fraction_check.json',receipt_root/'TASK_063_softlight_exact_fraction_check.json')
    # Native receipt snapshots are data, not evidence of successful execution by registration alone.
    schedules=Path.home()/'.paseo/schedules'
    for sid in ['068c797c','9ed2909e']:
        data=json.loads((schedules/(sid+'.json')).read_text(encoding='utf-8-sig'))
        summary={'observed_at':iso(c.clock()),'id':sid,'status':data.get('status'),'target':data.get('target'),
                 'runs':[{k:run.get(k) for k in ['id','scheduledFor','startedAt','endedAt','status','error']} for run in data.get('runs',[])[-3:]]}
        (receipt_root/('task063-r3-heartbeat-'+sid+'.json')).write_text(json.dumps(summary,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    manifest='\n'.join(f'{file_sha(p)}  {p.relative_to(out).as_posix()}' for p in sorted(out.rglob('*')) if p.is_file() and p.name!='06_MANIFEST.sha256')+'\n'
    (out/'06_MANIFEST.sha256').write_text(manifest,encoding='utf-8')
    c.event(state,'CEO_MATERIAL_PROGRESS_NOTIFIED','TASK_063',revision=3,milestone='R2 NEEDS_FIX; focused R3 ACTIVE issued',
            review_file='.ai/ceo/reviews/TASK_063_R2_79d93b4f_NEEDS_FIX.md',report_folder=task['report_folder'])
wt=Path('F:/CONVERT_WORKTREES/ceo-so45-20261008')
def git(*args): return subprocess.check_output(['git','-C',str(wt),*args])
assert git('branch','--show-current').decode().strip()=='ceo/so45-v4-orchestration-20261008'
files=[r/'RULES/TASK/TASK_063_SO45_INPUT_TRUTH_AND_RESEARCH_DISPATCH_ACTIVE.md']
files += [p for p in out.rglob('*') if p.is_file()]
files += [r/'.ai/ceo/reviews'/n for n in review_names]
rels=[]
for p in files:
    rel=p.relative_to(r);dest=wt/rel;dest.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(p,dest);rels.append(rel.as_posix())
git('-c','core.autocrlf=false','add','--',*rels)
changed=git('diff','--cached','--name-only').decode().splitlines()
assert changed and set(changed)<=set(rels)
lint=[p for p in changed if 'SNAPSHOT/' not in p and '/receipts/' not in p]
git('-c','core.whitespace=blank-at-eol,blank-at-eof,space-before-tab,cr-at-eol','diff','--cached','--check','--',*lint)
git('commit','-m','docs(ceo): review TASK_063 R2 and issue focused R3')
commit=git('rev-parse','HEAD').decode().strip()
archive=out/'TASK_063_R2_SNAPSHOT'
hashes=json.loads((archive/'SNAPSHOT_MANIFEST.json').read_text())
for rel,expected in hashes.items():
    path=(archive/rel).relative_to(r).as_posix()
    assert hashlib.sha256(git('show',commit+':'+path)).hexdigest()==expected
git('push','origin','ceo/so45-v4-orchestration-20261008')
remote=git('ls-remote','origin','refs/heads/ceo/so45-v4-orchestration-20261008').decode().split()[0]
assert remote==commit
with c.transaction() as (registry,state):
    state['last_target_commit_sha']=commit
    c.event(state,'CEO_PUBLICATION_VERIFIED','TASK_063',revision=3,commit=commit,archive_byte_hashes=len(hashes))
    c.replace_json(r/'.ai/ceo/receipts/task063-r3-publication.json',{'commit':commit,'remote':remote,'archive_files_verified':len(hashes),'changed_paths':len(changed),'observed_at':iso(c.clock())},registry)
print(json.dumps({'commit':commit,'remote_verified':remote,'archive_files_verified':len(hashes),'changed_scoped_paths':len(changed)}))
