"""Publish exact reviewed CEO artifacts in isolated worktree, never primary changes."""
from pathlib import Path
import sys, json, datetime, hashlib, shutil, subprocess
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from controller import Controller, file_sha
r = Path(__file__).resolve().parents[3]
c = Controller(r)
out = r / 'RULES/REPORT/CEO_SO45_ORCHESTRATION'
now = datetime.datetime.now(datetime.timezone.utc).isoformat()
with c.transaction() as (registry, state):
    claim = state['claims']['TASK_063:r2']
    assert claim['fencing_token'] == 1010
    assert c.tasks()['TASK_063']['revision'] == 2
    c.event(state, 'CEO_MATERIAL_PROGRESS_NOTIFIED', 'TASK_063', revision=2,
            milestone='R1 NEEDS_FIX; R2 issued and actually claimed', fencing_token=1010,
            report_folder='RULES/REPORT/TASK_063_REPORT_R2')
    body = f'''# TASK_063 R1 audit and R2 dispatch

Updated {now}; CEO lease token1007. Canonical standard read in full on wake, SHA-25610968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F.

R1 verdict NEEDS_FIX is bound to fingerprint417dbf529ca775eafb93011c61a302f5a4f700fc444e3d15ff8c0ad83fa071f0 and immutable CEO review .ai/ceo/reviews/TASK_063_R1_417dbf52_NEEDS_FIX.md. Frozen task/report/scripts and their actual hashes are retained in TASK_063_R1_SNAPSHOT. Stable manifest is packaging evidence, not algorithm or product approval.

Independent read-only reviewers audited input and all critical claims; CEO reproduced original shader decode/hash checks, native float arrays, all44 complete payload size/CRC/byte matches, and sampled5/45 ordinary libraries with actual llvm-readelf output/exit receipts. All45 extracted size/SHA agree input CSV. libmfxkit header348392052,payload348402156,declared1354736,available773652,missing581084; prefixCRC6ffdb5ff differs complete-declaredCRC4302c04c. Missing original tail/input_full prevents complete-package absence claims. Transport cause remains inferred.

Blocking defects: hardcoded input matches instead of validation; discarded partial disassembly output; generic unproved JNI/role/target/gap claims; asset-to-SO provenance conflation; mask semantics/model runtime/confidence inference; missing sampling offsets/address convention; SoftHair stages conflated with dye configuration; wrong printed hex for all5 blur weights; inadequate measured command/time/read receipts. Detailed correction order is in the review and active revised task. W3C equivalence comparison uses primary [Compositing spec](https://www.w3.org/TR/compositing-1/#blendingsoftlight); exact recovered shader variants must remain distinct.

TASK_063 revision2 is ACTIVE in RULES/TASK/TASK_063_SO45_INPUT_TRUTH_AND_RESEARCH_DISPATCH_ACTIVE.md. Same AGY runtime ace29908-a2b0-4777-a070-6bd100509738 actually claimed LEASE-CEO-WORKER-TASK_063-R2, token1010, at {claim['standard_read_ack']['acknowledged_at']}. No duplicate task prompt was sent while AGY was busy. R1 lease1009 revoked; R2 writes only scripts/task063_r2, evidenceTASK_063_R2, reportTASK_063_REPORT_R2 and separate Ghidra project. Every worker/resume must read full canonical file and record true path/hash/read time/identity/new fence.

Heartbeat remains active every60s. Native AGY receipts show a Google stream connection timeout and daemon restart before a scheduled run completed; subsequent runtime is running. Busy/failed ticks are not completion. R2 is executing/awaiting evidence, not accepted. TASK_064A..G remain PLANNED; P0 and production unchanged; V4 closed.
'''
    p = out / 'TASK_063_R1_REVIEW_AND_R2_DISPATCH.md'
    c.authorized(c.ceo_lease(registry), p)
    p.write_text(body, encoding='utf-8')
    receipt = {'observed_at':now,'task_id':'TASK_063','revision':2,'claim':claim,
               'r1_disposition':'NEEDS_FIX','task_sha':c.tasks()['TASK_063']['_task_sha'],
               'report_folder':'RULES/REPORT/TASK_063_REPORT_R2'}
    (out/'receipts/task063-r2-dispatch.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8')
    for rel in ['TASK_063_R1_input_validation.json','TASK_063_preliminary_shader_native_checks.json']:
        shutil.copy2(r/'.ai/ceo/receipts'/rel, out/'receipts'/rel)
    shutil.copytree(r/'.ai/ceo/receipts/TASK_063_R1_ordinary', out/'receipts/TASK_063_R1_ordinary', dirs_exist_ok=True)
    manifest=[f'{file_sha(p)}  {p.relative_to(out).as_posix()}' for p in sorted(out.rglob('*')) if p.is_file() and p.name!='06_MANIFEST.sha256']
    (out/'06_MANIFEST.sha256').write_text('\n'.join(manifest)+'\n',encoding='utf-8')

wt = Path('F:/CONVERT_WORKTREES/ceo-so45-20261008')
assert subprocess.check_output(['git','-C',str(wt),'branch','--show-current'],text=True).strip()=='ceo/so45-v4-orchestration-20261008'
files=[r/'RULES/TASK/TASK_063_SO45_INPUT_TRUTH_AND_RESEARCH_DISPATCH_ACTIVE.md']
files += [p for p in out.rglob('*') if p.is_file()]
for n in ['TASK_063_R1_417dbf52_NEEDS_FIX.md','TASK_063_CRITICAL_ANCHOR_ADVISORY.md',
          'TASK_063_INPUT_ADVISORY_20261008.md','issue_task063_r2.py',
          'verify_task063_r1_inputs.py','publish_task063_r2.py']:
    files.append(r/'.ai/ceo/reviews'/n)
rels=[]
for p in files:
    rel=p.relative_to(r);dest=wt/rel;dest.parent.mkdir(parents=True,exist_ok=True)
    shutil.copy2(p,dest);rels.append(rel.as_posix())
# Preserve exact evidence bytes in Git objects; no global Git settings are changed.
subprocess.run(['git','-C',str(wt),'-c','core.autocrlf=false','add','--',*rels],check=True)
names=subprocess.check_output(['git','-C',str(wt),'diff','--cached','--name-only'],text=True).splitlines()
assert names and set(names)<=set(rels)
lint_paths = ['RULES/TASK/TASK_063_SO45_INPUT_TRUTH_AND_RESEARCH_DISPATCH_ACTIVE.md']
lint_paths += [p for p in rels if p.startswith('.ai/ceo/reviews/')]
lint_paths += ['RULES/REPORT/CEO_SO45_ORCHESTRATION/TASK_063_R1_REVIEW_AND_R2_DISPATCH.md']
# Frozen R1/raw evidence retains original bytes, including Markdown hardbreak spaces.
# Check the current task/CEO code prose with Windows CRLF explicitly recognized.
check = subprocess.run(['git','-C',str(wt),'-c','core.whitespace=blank-at-eol,blank-at-eof,space-before-tab,cr-at-eol',
                        'diff','--cached','--check','--',*lint_paths],text=True,capture_output=True)
if check.returncode:
    print(check.stdout[:3000], check.stderr[:1000])
    raise RuntimeError('Current task/CEO source whitespace check failed')
subprocess.run(['git','-C',str(wt),'commit','-m','Audit TASK_063 evidence and issue scoped correction revision 2'],check=True)
print(json.dumps({'commit':subprocess.check_output(['git','-C',str(wt),'rev-parse','HEAD'],text=True).strip(),
                  'changed_scoped_paths':len(names),'claim_fence':1010}))
