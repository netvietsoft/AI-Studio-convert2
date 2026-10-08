"""Final bounded verification/supplement and immutable review manifest."""
import datetime, hashlib, json, pathlib
from collect import ROOT, OUT, ACTOR, SESSION, guard, write, jout, bind, now, progress, safe
guard(); assert not (OUT/'COMPLETE.json').exists()
base=pathlib.Path('C:/Users/PC.DESKTOP-81LIH38/AppData/Roaming/npm/node_modules/@getpaseo/cli/node_modules/@getpaseo')
sources=[(base/'plugin/dist/server/process.js',1,74),(base/'server/dist/server/builtin-plugins/antigravity-provider/server/internal/process.ts',182,218)]
extra=[]
for p,lo,hi in sources:
    ls=p.read_text(encoding='utf-8').splitlines()
    extra.append({'source':bind(p),'lines':[{'line':i,'literal':ls[i-1]} for i in range(lo,min(hi,len(ls))+1)]})
jout(OUT/'raw/additional_cleanup_source.json',extra)
obs=json.loads((OUT/'raw/outer_tool_observations.json').read_text())
obs['later_lookup'].update({'completion_status':'COMPLETED','final_chunk_id':'a1eedc','exit_code':0,
    'summary':'Returned dated fatal/exit/restart adjacency, signalGroup call anchors and installed execCommand windowsHide:true locations'})
jout(OUT/'raw/outer_tool_observations.json',obs)
master=(OUT/'01_MASTER_REPORT.md').read_text()
master+='''
## Final observed supplements

Lookup unified session25347 completed with final chunka1eedc/exit0; no pending lookup is claimed at submission. Actual daemon.log line6306 fatal at07:36:20.756Z is followed by line6307 IPC disconnected07:36:21.001Z, line6308 Worker exited(code1)07:36:21.156Z, line6309 Worker crashed/Restarting and line6310 Spawning worker07:36:21.157Z. Mixed numeric epoch and ISO string timestamps explain why the first numeric-only120s selector did not include those supervisor rows; line-adjacency supplement preserves them. This07:36 event is later than the07:09 TASK069 turn_aborted and cannot by itself explain the earlier abort. Other possible event/caller linkage remains UNKNOWN.

Installed plugin/dist/server/process.js execCommand already sets windowsHide:true(line48), uses promisified execFile and propagates rejection; no hidden-window patch is needed at this helper. Its separate terminateProcess also invokes taskkill.exe, catches only128 and rethrows other failures. Thus the log command/error alone does not uniquely identify the Antigravity killTree caller. Antigravity probe's termination promise has a rejection callback; fail also sinks rejection, while stop awaits cleanup. Precise asynchronous owner losing rejection is still UNKNOWN. Additional exact source/hash anchors are in raw/additional_cleanup_source.json. Do not remove global daemon fatal handler or swallow255 wholesale.

No live provider/session restart was attempted. Two subprocess controls verified current fixture behavior only; tests do not prove task069 can resume, process-tree cleanup works or the daemon has recovered. Runtime patch/new implementation would need separate scope, tests and CEO disposition.
'''
write(OUT/'01_MASTER_REPORT.md',master.encode())
p=(OUT/'03_RECOVERY_PROPOSAL.md').read_text()
p=p.replace('2. Proposed signals.ts change: add windowsHide:true to the existing shell:false command options if the actual installed execCommand supports it; verify that API first.',
    '2. Installed execCommand already sets windowsHide:true; preserve it, no window-visibility change is proposed. Proposed minimal handling change: add a structured cleanup-failure outcome/catch at the verified async owner, after instrumenting that owner.')
p+='\nInstalled terminateProcess provides another128-only catch/rethrow path; retained logs cannot uniquely attribute which cleanup caller rejected. Probe and fail already install rejection handlers. Investigate actual stop/lifecycle owner before choosing the precise patch site. Historical07:36 fatal/restart does not explain earlier07:09 abort.\n'
write(OUT/'03_RECOVERY_PROPOSAL.md',p.encode())
# Independently verify every retained control binding before manifest; no subprocess rerun.
cs=json.loads((OUT/'03_CONTROL_RECEIPTS.json').read_text())
verified=[]
for c in cs:
    for k in ['stdout','stderr','tool']:
        current=bind(pathlib.Path(c[k]['path'])); assert current['sha256']==c[k]['sha256']; verified.append(current)
assert [c['exit_code'] for c in cs]==[0,7]
codes=[ROOT/'scripts/task070_runtime_diagnostic'/n for n in ['collect.py','finalize.py','freeze.py']]
audit=(OUT/'00_AUDIT_INDEX.md').read_text()
audit+='\nControl/execution receipts:03_CONTROL_RECEIPTS.json and raw/collection_execution.json. Native/lifecycle privacy: selected metadata only with source snapshot hashes/line anchors; no whole private transcript copied. Current package is candidate, independent>=60s gate pending. Outer sessions85823 and25347 were collected to finalexit0. No extra heartbeat, native hooks/schedules preserved. Proposed memory updates only in03_RECOVERY_PROPOSAL.md; canonical memory files remain read-only.\n'
write(OUT/'00_AUDIT_INDEX.md',audit.encode())
jout(OUT/'raw/freeze_verification.json',{'schema_version':'2.1.2','task_id':'TASK_070','revision':1,'verified_at':now(),
    'control_bindings':verified,'code_bindings':[bind(p) for p in codes],'two_controls_only':True,'current_sessions_polled':[85823,25347],
    'causal_069_abort_reason':'UNKNOWN','host_recovery_success':'NOT_ESTABLISHED','fencing_token':1019})
progress('FROZEN_REVIEW_CANDIDATE_RETURNING_TO_SCANNER','REVIEW_CANDIDATE_AWAITING_CEO')
files={p.relative_to(OUT).as_posix():bind(p)['sha256'] for p in sorted(OUT.rglob('*')) if p.is_file() and p.name not in ['PROGRESS.json','COMPLETE.json']}
jout(OUT/'COMPLETE.json',{'schema_version':'2.1.2','task_id':'TASK_070','revision':1,'status':'COMPLETE',
    'disposition':'REVIEW_CANDIDATE_AWAITING_CEO','standard_sha256':'10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f',
    'task_sha256':'29e6a46aa60b34f317038f6a624b74550979ddf3e12444fc4ecf7c96012b69d8','agent_id':ACTOR,
    'native_session_id':SESSION,'internal_role':'/root','lease_id':'LEASE-CEO-WORKER-TASK_070-R1','fencing_token':1019,
    'completed_at':now(),'files':files,'code_files':[p.relative_to(ROOT).as_posix() for p in codes],
    'code_sha256':{p.relative_to(ROOT).as_posix():bind(p)['sha256'] for p in codes},'attempt':1,
    'host_recovery_accepted':False,'baseline_or_v4_accepted':False,'task069_retry_reset':False,'commit':None,'push':False})
assert all(bind(OUT/rel)['sha256']==h for rel,h in files.items())
print(json.dumps({'status':'REVIEW_CANDIDATE_AWAITING_CEO','manifest_files':len(files),'complete_sha256':bind(OUT/'COMPLETE.json')['sha256']}))
