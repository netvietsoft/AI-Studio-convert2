"""Fence untrusted actor claim; bind fresh diagnostic revision to real Paseo dispatch."""
import hashlib,json,os,pathlib,re,secrets,shutil,sys
sys.path.insert(0,str(pathlib.Path(__file__).resolve().parents[1]))
from controller import Controller,file_sha,iso
root=pathlib.Path(__file__).resolve().parents[3]
c=Controller(root)
worker='7de71900-89f8-4633-97a9-3efaf42ea6b8'
native='01a119f1-f400-7441-8b7a-26375ae0f459'
with c.transaction() as(registry,state):
    old=c.tasks()['TASK_067'];assert old['revision']==1
    assert state['claims']['TASK_067:r1']['status']=='REVOKED'
    archive=root/'RULES/REPORT/CEO_SO45_ORCHESTRATION/TASK_067_R1_IDENTITY_INCIDENT'
    c.authorized(c.ceo_lease(registry),archive/'TASK_R1.md')
    assert not archive.exists();archive.mkdir(parents=True)
    shutil.copy2(root/old['_path'],archive/'TASK_R1.md')
    for name,src in [('untrusted_report',root/old['report_folder']),('untrusted_scripts',root/'scripts/task067_diagnostic')]:
        if src.exists():shutil.copytree(src,archive/name)
    hashes={p.relative_to(archive).as_posix():file_sha(p) for p in sorted(archive.rglob('*')) if p.is_file()}
    (archive/'MANIFEST.json').write_text(json.dumps(hashes,indent=2)+'\n',encoding='utf-8')
    token=secrets.token_hex(32)
    cfg=json.loads((root/'.ai/ceo/config.json').read_text(encoding='utf-8-sig'))
    cfg.setdefault('claim_bindings',{})[worker]={'task_id':'TASK_067','revision':2,
        'token_sha256':hashlib.sha256(token.encode()).hexdigest(),'native_session_id':native,
        'meaning':'CEO challenge delivered only to the verified persistent worker; no token in public task or results'}
    c.replace_json(root/'.ai/ceo/config.json',cfg,registry)
    path=root/old['_path'];raw=path.read_text(encoding='utf-8-sig')
    m=re.search(r'^```json\s*\n(.*?)\n```',raw,re.M|re.S);meta=json.loads(m[1])
    meta.update(revision=2,report_folder='RULES/REPORT/TASK_067_REPORT_R2',claim_binding_required=True,
        files_allowed=['scripts/task067_diagnostic_r2/**','.ai/reconstruction/evidence/TASK_067_R2/**','RULES/REPORT/TASK_067_REPORT_R2/**'],
        native_session_id=native,revision_reason='Actor identity handoff; no diagnostic attempt completed and no budget increase')
    meta['files_forbidden'] += ['scripts/task067_diagnostic/**','RULES/REPORT/TASK_067_REPORT/**','.ai/reconstruction/evidence/TASK_067/**']
    raw=raw[:m.start(1)]+json.dumps(meta,ensure_ascii=False,indent=2)+raw[m.end(1):]
    raw=re.sub(r'^MODIFIED_TIME:.*$','MODIFIED_TIME: '+iso(c.clock()),raw,flags=re.M)
    # Replace prose scope references only after JSON, preserving forbidden historical paths.
    end=raw.index('\n```',raw.index('```json'))+4
    raw=raw[:end]+raw[end:].replace('RULES/REPORT/TASK_067_REPORT','RULES/REPORT/TASK_067_REPORT_R2').replace('scripts/task067_diagnostic/','scripts/task067_diagnostic_r2/').replace('.ai/reconstruction/evidence/TASK_067/','.ai/reconstruction/evidence/TASK_067_R2/')
    raw += '\n\n## Revision2 actor binding, not another diagnostic retry\n\nR1 lease1012 was claimed by Antigravity lead using this worker ID; that assertion is invalid and revoked. Actual Codex read-only boot confirms no claim or writes. CEO independently binds external Paseo worker ID '+worker+' to actual CODEX_THREAD_ID '+native+'. These are different identifier types for the same verified persistent agent, not interchangeable IDs. Use the external Paseo ID for controller claim; record both. Task remains a single bounded diagnostic attempt, not a budget reset. Old paths/fence are forbidden. CEO-delivered dispatch token is required with --dispatch-token; it is not in this task. Do not infer/copy another identity from metadata or log the token in reports. Wait for the actual CEO assignment carrying the token before claim.\n'
    tmp=root/'.ai/locks.ceo.task067bind.tmp';c.authorized(c.ceo_lease(registry),tmp);c.authorized(c.ceo_lease(registry),path)
    with tmp.open('w',encoding='utf-8',newline='\n') as f:f.write(raw);f.flush();os.fsync(f.fileno())
    assert file_sha(path)==old['_task_sha'];os.replace(tmp,path)
    c.replace_json(root/'.ai/ceo/receipts/TASK_067_DISPATCH_PRIVATE.json',{'worker_id':worker,'native_session_id':native,'task_id':'TASK_067','revision':2,'task_sha256':file_sha(path),'dispatch_token':token,'meaning':'Local private dispatch binding; NEVER publish or copy into report/Git'},registry)
    incident={'observed_at':iso(c.clock()),'actual_actor':'ace29908-a2b0-4777-a070-6bd100509738','claimed_worker_id':worker,
        'native_session_id':native,'revoked_fence':1012,'untrusted_claim':'TASK_067:r1',
        'evidence':'Paseo AGY activity contains explicit claim command with different worker ID; new worker BOOT response confirms read-only/no claim',
        'corrected_revision':2,'budget_changed':False,'controller_checks':'29/29 offline governance tests PASS; includes revoked fence replay and dispatch/revision binding',
        'heartbeat_update':'MCP update_schedule068c797c not found; native heartbeat continues; no duplicate created'}
    c.replace_json(root/'.ai/ceo/receipts/TASK_067_IDENTITY_INCIDENT.json',incident,registry)
    prompt=root/'.ai/ceo/AGY_SCAN_PROMPT.txt'
    c.authorized(c.ceo_lease(registry),prompt)
    with prompt.open('a',encoding='utf-8') as f:f.write('\nACTOR IDENTITY CORRECTION: The existing lead is ONLY ace29908-a2b0-4777-a070-6bd100509738. Never claim by copying another task agent_id. TASK063 BLOCKED; TASK067 assigned different actual Codex worker7de71900-89f8-4633-97a9-3efaf42ea6b8. Invalid1012 revoked. Required dispatch binding cannot be inferred from public metadata. Only eligible ACTIVE tasks assigned to your own actual external Paseo ID may execute; otherwise return to60s scanner.\n')
    report=root/'RULES/REPORT/CEO_SO45_ORCHESTRATION/TASK_067_IDENTITY_REBIND.md'
    c.authorized(c.ceo_lease(registry),report)
    report.write_text('# TASK067 actor-identity correction\n\n'+json.dumps(incident,ensure_ascii=False,indent=2)+'\n\nExact R2 task: '+old['_path']+'\nReports: RULES/REPORT/TASK_067_REPORT_R2. Scopes: scripts/task067_diagnostic_r2/**, .ai/reconstruction/evidence/TASK_067_R2/**, reportR2/**. Live actual assignment is still required before claim. No token in this report. TASK063 remains BLOCKED;064–066 PLANNED; no V4 gate bypass.\n',encoding='utf-8')
    c.event(state,'CEO_TASK_REVISION_ISSUED','TASK_067',revision=2,reason='ACTOR_IDENTITY_REBIND_NOT_RETRY',task_file=old['_path'],agent_id=worker,native_session_id=native)
    print(json.dumps({'task067_revision':2,'task_sha256':file_sha(path),'untrusted_fence1012':'REVOKED','actual_worker':worker,'native_session':native,'attempt_budget':1}))
