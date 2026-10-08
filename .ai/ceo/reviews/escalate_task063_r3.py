"""Fenced CEO escalation: freeze exhausted baseline; assign one distinct diagnostic."""
import json, os, pathlib, re, shutil, sys
sys.path.insert(0, str(pathlib.Path(__file__).resolve().parents[1]))
from controller import Controller, file_sha, iso

root = pathlib.Path(__file__).resolve().parents[3]
c = Controller(root)
worker = '7de71900-89f8-4633-97a9-3efaf42ea6b8'
fp = '2041a6a220c14965c37a6f9634e160f7ef5ac5ef91675fd134fb0ded9c2e0f10'

def text_write(path, content, registry, expected=None):
    c.authorized(c.ceo_lease(registry), path)
    temp = root/'.ai/locks.ceo.escalation.tmp'
    c.authorized(c.ceo_lease(registry), temp)
    path.parent.mkdir(parents=True, exist_ok=True)
    with temp.open('w', encoding='utf-8', newline='\n') as out:
        out.write(content); out.flush(); os.fsync(out.fileno())
    if expected is not None:
        assert file_sha(path) == expected
    else:
        assert not path.exists()
    os.replace(temp, path)

with c.transaction() as (registry, state):
    task = c.tasks()['TASK_063']
    assert task['revision'] == 3 and task['status'] == 'ACTIVE'
    verdict = state['tasks']['TASK_063']['verdict']
    assert verdict['disposition'] == 'NEEDS_FIX' and verdict['fingerprint'] == fp
    assert c.report_snapshot(task)['fingerprint'] == fp
    review = root/verdict['review_file']
    assert file_sha(review) == verdict['review_sha256']
    archive = root/'RULES/REPORT/CEO_SO45_ORCHESTRATION/TASK_063_R3_SNAPSHOT'
    assert not archive.exists()
    c.authorized(c.ceo_lease(registry), archive/'R3_TASK.md')
    archive.mkdir(parents=True)
    shutil.copy2(root/task['_path'], archive/'R3_TASK.md')
    shutil.copy2(review, archive/'CEO_REVIEW.md')
    shutil.copytree(root/task['report_folder'], archive/'report')
    shutil.copytree(root/'scripts/task063_r3', archive/'scripts')
    hashes = {p.relative_to(archive).as_posix(): file_sha(p) for p in sorted(archive.rglob('*')) if p.is_file()}
    (archive/'SNAPSHOT_MANIFEST.json').write_text(json.dumps(hashes,indent=2)+'\n',encoding='utf-8')
    now = iso(c.clock())
    raw = (root/task['_path']).read_text(encoding='utf-8-sig')
    match = re.search(r'^```json\s*\n(.*?)\n```', raw, re.S|re.M)
    meta = json.loads(match[1])
    meta.update(status='BLOCKED', escalation_status='ESCALATION_REQUIRED',
        blocked_reason='Final bounded R3 correction NEEDS_FIX; no retry-budget increase',
        blocked_at=now, blocked_review=verdict['review_file'], blocked_fingerprint=fp,
        diagnostic_task='TASK_067')
    raw = raw[:match.start(1)]+json.dumps(meta,ensure_ascii=False,indent=2)+raw[match.end(1):]
    raw = re.sub(r'^STATUS:.*$', 'STATUS: BLOCKED', raw, flags=re.M)
    raw = re.sub(r'^MODIFIED_TIME:.*$', 'MODIFIED_TIME: '+now, raw, flags=re.M)
    raw += '\n\n## CEO escalation override — '+now+'\n\nSTATUS BLOCKED supersedes prior ACTIVE prose. R3 write lease revoked. Original max_fix_cycles3 and full attempt history retained. No further R3/R4 repair, baseline rewrite or commit is authorized. TASK067 is a separate bounded causal diagnostic only; it cannot accept this task, satisfy TASK064 dependencies, reset its budget or reopen V4. Campaign scanners continue. A separately recorded CEO disposition after independent diagnostic review is required to decide recovery.\n'
    text_write(root/task['_path'], raw, registry, task['_task_sha'])
    updated = json.loads(json.dumps(registry))
    old = next(x for x in updated['active_locks'] if x['lease_id']=='LEASE-CEO-WORKER-TASK_063-R3')
    assert old['fencing_token'] == 1011
    old.update(status='REVOKED', expiry=now, released_at=now, release_reason='R3 NEEDS_FIX; loop-guard escalation; immutable snapshot')
    updated['revision'] = registry.get('revision',0)+1
    c.replace_json(c.registry,updated,registry)
    registry.clear(); registry.update(updated)
    state['claims']['TASK_063:r3'].update(expiry=0,status='REVOKED',closure='LOOP_GUARD_ESCALATION')
    state['tasks']['TASK_063']['escalation'] = {'status':'BLOCKED','reason':'ESCALATION_REQUIRED',
        'attempts_retained':[1,2,3],'original_max_fix_cycles':3,'diagnostic_task':'TASK_067',
        'verdict':verdict,'snapshot':archive.relative_to(root).as_posix(),'blocked_at':now}
    state.setdefault('escalations',{})['TASK_063:r3'] = state['tasks']['TASK_063']['escalation']
    cfg = json.loads((root/'.ai/ceo/config.json').read_text(encoding='utf-8-sig'))
    assert 'TASK_067' not in cfg['task_ids']
    cfg['task_ids'].append('TASK_067')
    cfg.setdefault('worker_ids',[]).append(worker)
    c.replace_json(root/'.ai/ceo/config.json',cfg,registry)
    dmeta = {'schema_version':'2.1.2','task_id':'TASK_067','revision':1,'status':'ACTIVE',
        'assignee':worker,'agent_id':worker,'priority':'P0','mode':'DIAGNOSTIC','design_impact':'NONE',
        'dependencies':[],'report_folder':'RULES/REPORT/TASK_067_REPORT',
        'files_allowed':['scripts/task067_diagnostic/**','.ai/reconstruction/evidence/TASK_067/**','RULES/REPORT/TASK_067_REPORT/**'],
        'files_forbidden':['app/**','lib-*/**','RULES/TASK/**','scripts/task063*/**','RULES/REPORT/TASK_063*/**',
            '.ai/reconstruction/evidence/TASK_061/**','.ai/ceo/**','.ai/state.json','AGENTS.md','PROJECT_ERROR.md','ACQUIREMENTS.md'],
        'max_fix_cycles':1,'max_minutes':45,'authorization_reference':'Chairman Tony SO45-to-V4 CEO coordination; canonical loop-guard Orchestrator diagnostic escalation',
        'escalated_from':{'task_id':'TASK_063','revision':3,'fingerprint':fp,'review_file':verdict['review_file']},
        'execution_engine':'codex/gpt-6.1-sol','baseline_replacement_authorized':False}
    body = '''
## Mandatory preflight and exact lease

Before every dispatch/resume READ IN FULL F:\\CONVERT\\com.mt.mtxx.mtxx\\CONVERT2\\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt. Expected SHA25610968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F. Record actual path/hash/read timestamp/identity/fence in00_AUDIT_INDEX.md. Read AGENTS.md, Docs/rules.md, PROJECT_ERROR.md, ACQUIREMENTS.md, .ai/ceo/SO45_TO_V4_PLAN.md, TASK063 R3 review and CEO escalation report. Claim this exact revision through controller before any writes, using your actual assigned ID and measured lowercase standard hash. Renew while working. Only JSON files_allowed are writable; SOURCE, R1/R2/R3 scripts/reports, historical source and CEO state are read-only. Do not ask Tony to reconfirm ACTIVE authorization.

## Distinct purpose and stop gate

TASK063 is BLOCKED after its final bounded correction. This task diagnoses why its verifier made unsupported claims. It does NOT regenerate a45-SO baseline, inventory, seven-lane assignments or another polished TASK063 report. One bounded diagnostic attempt, at most45 minutes; on an unresolved diagnostic/tool failure publish the concrete blocker and stop task writes, return to scanner. Do not increase the budget or create/reopen tasks.

TASK067 acceptance validates diagnostic evidence only. It neither accepts TASK063 nor satisfies downstream baseline dependencies. TASK063 remains BLOCKED pending a separately recorded CEO disposition based on independently verified diagnostic results. No retry-budget increase, baseline replacement, dependent-task activation or V4 implementation is authorized by this task.

## Three bounded investigations

1. Reproduce the input-status failure in the actual R3 classification logic, without importing/executing its mutating main. Extract the minimal pure fragment using source/AST anchors. Use one complete real SO and the actual mfx prefix as positive controls; mutate only in-memory copies (payload byte, declared CRC, flags/method/size). Show exactly which original checks/statuses accept invalid inputs. A small diagnostic reference classifier may contrast the intended behavior, with the SAME function exercised by all positive/negative cases. This reference is diagnostic, not an installed production/baseline fix. Record container/input hashes, header/data coordinates, actual prefix/CRC distinctions and source-fragment hash. Never modify original binaries or containers.
2. Reproduce the actual retained-objdump format/parser mismatch. Recount five existing1500-line raw samples: libaicodec, libaidetectionplugin, libPVGColorFunctions, libMTLReportTool and libManis. Retain hashes, representative literal lines, parsed address/mnemonic and instruction versus text counts. Validate parser against actual no-raw-insn format and malformed/noninstruction lines. No broad decompilation or full disassembly needed. Rerun lightweight readelf for the15 selected FUNC targets if needed, preserving command/start/end/exit/input/tool/stdout/stderr hashes. Explain full-output versus retained-output binding and propose a concrete durable command-receipt schema without manufacturing missing historical timestamps.
3. Reproduce exact critical-provenance mismatches: original APK C2 literal SoftLight_Fcn versus R3 invented verbatim block; actual NE.manis APK path/hash versus nonexistent reported path; actual Manis-name288 versus total defined303. Preserve raw results and causal source anchors. Check the independently verified CEO SoftLight69/512 math,30 blur float words and stage entry0x2344e8 as known-good controls through explicitly hash-bound reuse; no need repeat all critical math/decompilation. Do not infer model architecture/runtime/producer/defaults from names. Tool metadata/version and actual native heartbeat run-status receipts may be reused with measured current hashes and missing-receipt limits explicit.

## Deliverables and independent review

In RULES/REPORT/TASK_067_REPORT:00_AUDIT_INDEX.md,01_MASTER_REPORT.md (causes/counterexamples/repair recommendation/limits),02_DIAGNOSTIC_RESULTS.json (cases and measured old/reference outcomes),03_REMEDIATION_RECOMMENDATION.md (minimal proposed diff/steps only, not applied to R3),raw/ actual stdout/stderr/proof logs,PROGRESS.json andCOMPLETE.json. Scripts only scripts/task067_diagnostic/**; supplementary evidence only .ai/reconstruction/evidence/TASK_067/**. Use a small meaningful regression check for these demonstrated failures, not test-green theatre. No full45 inventory/lane CSV deliverables. COMPLETE follows2.1.2 protocol: exact task/revision/status COMPLETE/standard_sha256, files relative report-path SHA map excluding COMPLETE/volatile PROGRESS, code_files list of actually executed repo-relative scripts. Every observed result binds original input -> actual command or pure computation -> retained output -> anchor, with OBSERVED/INFERRED/UNKNOWN separated.

PROGRESS only on actual milestone, approximately60s while a long command runs. Identify yourself honestly as Codex diagnostic worker in the AGY coordination team; Antigravity lead is a separate session with unstable connectivity. No simulated agents/PID claims. Existing CEO native heartbeat supervises this worker; do not create another heartbeat. Submit REVIEW_CANDIDATE_AWAITING_CEO before commit/push; only independently reviewed exact snapshot may authorize task-owned branch publication. Preserve unrelated primary-workspace changes. After submission return to eligible exact task scanner; no modifications to blocked063 or PLANNED064–066.
'''
    task_path = root/'RULES/TASK/TASK_067_VALIDATOR_FAILURE_DIAGNOSTIC_ACTIVE.md'
    text_write(task_path,'# TASK_067 — bounded causal diagnostic of SO45 verifier failures\nSTATUS: ACTIVE\nASSIGNEE: '+worker+'\nPRIORITY: P0\nMODIFIED_TIME: '+now+'\n\n```json\n'+json.dumps(dmeta,ensure_ascii=False,indent=2)+'\n```\n'+body,registry)
    summary = '# TASK063 R3 review and CEO escalation\n\nTimestamp: '+now+'\n\nR3 NEEDS_FIX: '+fp+'. Independent review '+verdict['review_file']+' (SHA '+verdict['review_sha256']+').44 complete SO matches and the581084-byte mfx deficit independently verified. Five ordinary target reruns pass15 defined functions; all44 intact disassembly counts were incorrectly zero. C2 literal quote, NE.manis path and Manis288-vs303 claims require correction; per-command proof receipts remain incomplete.\n\nTASK063 now BLOCKED/ESCALATION_REQUIRED. Immutable R3 task/report/code/review snapshot retained at '+archive.relative_to(root).as_posix()+'. Original max_fix_cycles3/history preserved; R3 token1011 revoked. TASK064A..G/065/066 remain PLANNED, V4 closed.\n\nTASK067 revision1 ACTIVE is a distinct one-attempt/45-minute causal diagnostic, assigned to actual Codex worker '+worker+'; no baseline rewrite, retry reset or downstream gate bypass. File RULES/TASK/TASK_067_VALIDATOR_FAILURE_DIAGNOSTIC_ACTIVE.md; reports RULES/REPORT/TASK_067_REPORT; scope scripts/task067_diagnostic/**, .ai/reconstruction/evidence/TASK_067/** and report folder. At issuance the worker has only a read-only boot prompt; task execution dispatch/claim is a separate actual event to verify.\n\nRuntime: CEO daemon processes and native wakes observed alive. Recent CEO run restart failures and AGY connectivity/provider failures mean continuous successful60-second scans are not proven. Provider availability changes; Antigravity currently listed available again but recent run receipts still fail. New persistent Codex session is an actual fallback diagnostic engine, not a simulated AGY clone. Initial create against stale workspace ID failed; root status supplied current workspace wks_4ed49b4b5b9607c2 and actual creation then succeeded. Existing heartbeats retained; no duplicate registration.\n\nNo product code/P0 modifications authorized. Research candidate packaging is not research or product acceptance. Campaign scanner continues.\n'
    text_write(root/'RULES/REPORT/CEO_SO45_ORCHESTRATION/TASK_063_R3_REVIEW_AND_ESCALATION.md',summary,registry)
    c.event(state,'CEO_LOOP_GUARD_ESCALATED','TASK_063',revision=3,fingerprint=fp,review_file=verdict['review_file'],diagnostic_task='TASK_067',original_max_fix_cycles=3)
    c.event(state,'CEO_TASK_ISSUED','TASK_067',revision=1,task_file=task_path.relative_to(root).as_posix(),agent_id=worker,engine='codex/gpt-6.1-sol',purpose='BOUNDED_CAUSAL_DIAGNOSTIC_ONLY')
    print(json.dumps({'task063':'BLOCKED','old_lease1011':'REVOKED','snapshot_files':len(hashes),'task067':'ACTIVE','worker':worker,'task067_sha256':file_sha(task_path)}))
