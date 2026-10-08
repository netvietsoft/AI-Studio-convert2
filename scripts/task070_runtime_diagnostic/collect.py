"""Evidence-only own-thread runtime diagnostic. No cleanup commands executed."""
import datetime, hashlib, json, pathlib, re, subprocess, sys
ROOT=pathlib.Path(__file__).resolve().parents[2]
OUT=ROOT/'RULES/REPORT/TASK_070_REPORT_R1'
SESSION='01a119f1-f400-7441-8b7a-26375ae0f459'
ACTOR='7de71900-89f8-4633-97a9-3efaf42ea6b8'
def now(): return datetime.datetime.now(datetime.timezone.utc).isoformat()
def bind(p):
    b=p.read_bytes(); return {'path':str(p),'bytes':len(b),'sha256':hashlib.sha256(b).hexdigest()}
def safe(s):
    s=re.sub(r'(?i)[a-f0-9]{64}','[HEX64_REDACTED]',str(s))
    s=re.sub(r'(?i)(dispatch[_-]token\s*[=:]\s*)[^\s,;]+',r'\1[REDACTED]',s)
    return s
def guard():
    l=next(x for x in json.loads((ROOT/'.ai/locks.json').read_text(encoding='utf-8-sig'))['active_locks'] if x['lease_id']=='LEASE-CEO-WORKER-TASK_070-R1')
    assert l['status']=='ACTIVE' and l['fencing_token']==1019
    assert datetime.datetime.now(datetime.timezone.utc)<datetime.datetime.fromisoformat(l['acquired_at'])+datetime.timedelta(minutes=20)
    return l
def write(p,b):
    guard(); assert p.is_relative_to(OUT); p.parent.mkdir(parents=True,exist_ok=True); p.write_bytes(b)
def jout(p,d): write(p,json.dumps(d,ensure_ascii=False,indent=2).encode())
def progress(m,status='TASK_EXECUTING'):
    jout(OUT/'PROGRESS.json',{'schema_version':'2.1.2','task_id':'TASK_070','revision':1,'status':status,'milestone':m,
         'updated_at':now(),'agent_id':ACTOR,'native_session_id':SESSION,'internal_role':'/root','fencing_token':1019,
         'lease_id':'LEASE-CEO-WORKER-TASK_070-R1','attempt':1})
def main():
    l=guard(); started=now()
    write(OUT/'00_AUDIT_INDEX.md',f'''# TASK070 R1 audit index
Full UTF8 standard read completed2026-10-08T14:53:11.4106872+07:00.
Path: {ROOT/'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt'}
Actual SHA25610968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f; full text unchanged from prior understood reads.
Read AGENTS.md, Docs/rules.md, PROJECT_ERROR.md, ACQUIREMENTS.md, CEO plan and exact TASK070.
TaskSHA29e6a46aa60b34f317038f6a624b74550979ddf3e12444fc4ecf7c96012b69d8.
External Paseo actor{ACTOR}; native CODEX_THREAD_ID{SESSION}; internal role/root. Actual engineCodex; CEO labels codex/gpt-6.1-sol.
Current lease{l['lease_id']}/fence1019 acquired{l['acquired_at']}; deadline20minutes from first claim, never reset.
TASK069 fence1018 revoked; no renewal or write in its scope. Scope only task070 script/report. No taskkill/kill/restart/cancel/install/schedule/global patch executed.
Private challenges only loaded in memory for claim; no transcript copies, nonce logs or private-file writes.
'''.encode())
    progress('PREFLIGHT_AND_VALID_LEASE_CONFIRMED')
    native=pathlib.Path('C:/Users/PC.DESKTOP-81LIH38/.codex/sessions/2026/10/08/rollout-2026-10-08T12-17-29-'+SESSION+'.jsonl')
    data=native.read_bytes(); rows=[]
    for i,line in enumerate(data.splitlines(),1):
        try: rows.append((i,json.loads(line)))
        except ValueError: pass
    trace=[]; pending=set(); last_call=None
    for i,r in rows:
        stamp=r.get('timestamp',''); p=r.get('payload',{}); typ=p.get('type')
        if '2026-10-08T07:07'<=stamp<'2026-10-08T07:52':
            if typ in ['custom_tool_call','custom_tool_call_output','turn_aborted','task_started','task_complete','thread_settings_applied']:
                item={'line':i,'timestamp':stamp,'record_type':r.get('type'),'event_type':typ,'call_id':p.get('call_id')}
                if typ=='custom_tool_call':
                    inp=str(p.get('input','')); item['tool_name']=p.get('name'); pending.add(p.get('call_id')); last_call=item
                    item['operation_summary']=('RULE_READ_AND_CLAIM_BINDING' if 'TASK_069_DISPATCH_PRIVATE' in inp else 'READ_ONLY_MNEMONICS_BRANCH_AND_C2_INSPECTION' if 'SoftLight' in inp or 'C2.decoded' in inp else 'OTHER_TOOL_METADATA_ONLY')
                    # Never retain actual input containing private dispatch challenge material.
                if typ=='custom_tool_call_output':
                    pending.discard(p.get('call_id')); output=str(p.get('output',''))
                    item['contains_script_running_marker']='Script running with cell ID' in output
                    item['contains_session_id_marker']='session_id' in output
                    item['contains_exit_zero']=('exit_code":0' in output.replace(' ','') or 'exit_code\": 0' in output or 'exit_code: 0' in output)
                    item['output_chars']=len(output)
                    if p.get('call_id')=='call_81e7bb4928d0418b93d55f68d885feeb':
                        item['sanitized_result_summary']='Returned mnemonic list, branch agent/agy/TASK_062 and literal SoftLight_Fcn shader text; no ongoing session ID visible in session-tool output.'
                trace.append(item)
    jout(OUT/'02_SANITIZED_NATIVE_TRACE.json',{'source_snapshot':{'path':str(native),'bytes':len(data),'sha256':hashlib.sha256(data).hexdigest()},
        'snapshot_at':now(),'session_id':SESSION,'window':'07:07Z..07:52Z','events':trace,'unmatched_calls_in_window':sorted(x for x in pending if x),
        'last_tool_call':last_call,'privacy':'Only own-thread metadata/whitelisted operation summaries; no reasoning/private prompt/body/nonce copied',
        'inference_limits':'turn_aborted observed; initiator/why, daemon-to-turn causation and scheduling latency UNKNOWN. Current process/session status not inferred from old PID.'})
    progress('OWN_THREAD_METADATA_BOUND')
    controls=[]
    for label,code,expected in [('sentinel',"print('TASK070_READ_ONLY_SENTINEL')",0),('stderr_nonzero',"import sys; sys.stderr.write('TASK070_CONTROLLED_STDERR\\n'); sys.exit(7)",7)]:
        cmd=[sys.executable,'-X','utf8','-B','-c',code]; start=now()
        try:
            p=subprocess.run(cmd,capture_output=True,timeout=15,shell=False,cwd=str(ROOT),creationflags=subprocess.CREATE_NO_WINDOW)
            status='COMPLETED'; stdout,stderr,exit=p.stdout,p.stderr,p.returncode
        except subprocess.TimeoutExpired as e:
            status='TIMEOUT'; stdout,stderr,exit=e.stdout or b'',e.stderr or b'',None
        end=now(); a=OUT/'raw'/f'{label}.stdout'; b=OUT/'raw'/f'{label}.stderr'; write(a,stdout); write(b,stderr)
        controls.append({'label':label,'argv':cmd,'cwd':str(ROOT),'tool':bind(pathlib.Path(sys.executable)),
            'input_code_sha256':hashlib.sha256(code.encode()).hexdigest(),'started_at':start,'ended_at':end,'exit_code':exit,
            'status':status,'expected_exit':expected,'expectation_matched':status=='COMPLETED' and exit==expected,
            'shell':False,'creationflags':subprocess.CREATE_NO_WINDOW,'windows_hidden':True,'timeout_seconds':15,
            'stdout':bind(a),'stderr':bind(b),'retention':'Full captured bytes, no transcoding or sampled truncation',
            'scope':'Executor fixture only; no SO/runtime recovery proof'})
    jout(OUT/'03_CONTROL_RECEIPTS.json',controls)
    base=pathlib.Path('C:/Users/PC.DESKTOP-81LIH38/AppData/Roaming/npm/node_modules/@getpaseo/cli/node_modules/@getpaseo/server/dist/server')
    specs=[(base/'builtin-plugins/antigravity-provider/server/internal/signals.ts',1,40),
           (base/'builtin-plugins/antigravity-provider/server/internal/process.ts',120,180),
           (base/'server/daemon-worker.js',267,289)]
    excerpts=[]
    for p,lo,hi in specs:
        ls=p.read_text(encoding='utf-8').splitlines(); selected=[{'line':i,'text':safe(ls[i-1])} for i in range(lo,min(hi,len(ls))+1)]
        excerpts.append({'source':bind(p),'start_line':lo,'end_line':min(hi,len(ls)),'lines':selected})
    jout(OUT/'04_CLEANUP_SOURCE_ANCHORS.json',excerpts)
    log=pathlib.Path('C:/Users/PC.DESKTOP-81LIH38/.paseo/daemon.log'); logbytes=log.read_bytes(); records=[]
    for i,line in enumerate(logbytes.splitlines(),1):
        try: records.append((i,json.loads(line)))
        except ValueError: pass
    fatals=[]; lifecycle=[]
    for i,r in records:
        msg=str(r.get('msg','')); err=r.get('err') or {}
        if 'Unhandled promise rejection' in msg and 'taskkill' in str(err):
            t=r.get('time'); utc=datetime.datetime.fromtimestamp(t/1000,datetime.timezone.utc).isoformat() if isinstance(t,(int,float)) else None
            fatals.append({'line':i,'time':t,'utc':utc,'daemon_pid':r.get('pid'),'message':msg,'error_type':err.get('type'),
                'exit_code':err.get('code'),'error_message':safe(err.get('message','')),'stack':safe(err.get('stack',''))[:1800],
                'cleanup_command_type':'taskkill; argv deliberately omitted','causal_caller':'UNKNOWN unless stack identifies installed caller'})
        if any(w in msg.lower() for w in ['supervisor','daemon worker','restarting','worker exited','daemon ready','starting daemon','started daemon']):
            lifecycle.append({'line':i,'time':r.get('time'),'pid':r.get('pid'),'message':safe(msg)[:250],
                              'module':r.get('module'),'exit_code':r.get('exitCode',r.get('code'))})
    selected=[]
    for f in fatals[-5:]:
        after=[x for x in lifecycle if isinstance(x['time'],(int,float)) and isinstance(f['time'],(int,float)) and f['time']<=x['time']<=f['time']+120000]
        selected.append({'fatal':f,'next_lifecycle_within_120s':after[:8],'correlation_is_not_caller_proof':True})
    jout(OUT/'05_SANITIZED_LIFECYCLE.json',{'source_snapshot':{'path':str(log),'bytes':len(logbytes),'sha256':hashlib.sha256(logbytes).hexdigest()},
        'snapshot_at':now(),'taskkill_unhandled_fatal_rows':len(fatals),'exit255_rows':sum(x['exit_code']==255 for x in fatals),
        'selected_last_five':selected,'lifecycle_row_count':len(lifecycle),'no_whole_log_retained':True,
        'limits':'Root earlier33 count is historical; current measured count may increase. Fatal handler exits1 after200ms by source; restart adjacency not TASK069 abort causation.'})
    budget=ROOT/'.ai/ceo/receipts/TASK_069_BUDGET_EXHAUSTION.json'
    jout(OUT/'06_BUDGET_BINDING.json',{'source':bind(budget),'record':json.loads(budget.read_text()),'lease070':{k:l[k] for k in ['lease_id','fencing_token','acquired_at','expiry','status']},
        'interpretation':'First-acquired task deadline differs from lease TTL; renewing TTL cannot reset TASK069 exhausted attempt.'})
    progress('TWO_HIDDEN_CONTROLS_AND_LIFECYCLE_SOURCE_BOUND')
    jout(OUT/'raw/collection_execution.json',{'command':'python -X utf8 -B scripts/task070_runtime_diagnostic/collect.py','started_at':started,
          'ended_at':now(),'exit_code':0,'script':bind(pathlib.Path(__file__)),'fencing_token':1019,'tiny_control_count':2})
    print(json.dumps({'control_exits':[x['exit_code'] for x in controls],'native_events':len(trace),'unmatched':sorted(x for x in pending if x),'taskkill_fatal_rows':len(fatals),'lifecycle_rows':len(lifecycle)}))
if __name__=='__main__': main()
