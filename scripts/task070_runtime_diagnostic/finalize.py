"""Freeze diagnostic report from measured controls and sanitized evidence."""
import datetime, hashlib, json, pathlib
from collect import ROOT, OUT, ACTOR, SESSION, guard, write, jout, bind, now, progress, safe
guard(); assert not (OUT/'COMPLETE.json').exists()
native=json.loads((OUT/'02_SANITIZED_NATIVE_TRACE.json').read_text())
controls=json.loads((OUT/'03_CONTROL_RECEIPTS.json').read_text())
assert len(controls)==2 and all(x['expectation_matched'] for x in controls)
checks=[]
for c in controls:
    for k in ['stdout','stderr','tool']:
        b=bind(pathlib.Path(c[k]['path'])); assert b['sha256']==c[k]['sha256']; checks.append(b)
    assert c['shell'] is False and c['windows_hidden'] and c['timeout_seconds']==15
    assert datetime.datetime.fromisoformat(c['ended_at'])>=datetime.datetime.fromisoformat(c['started_at'])
assert (OUT/'raw/sentinel.stdout').read_bytes()==b'TASK070_READ_ONLY_SENTINEL\r\n'
assert (OUT/'raw/stderr_nonzero.stderr').read_bytes()==b'TASK070_CONTROLLED_STDERR\r\n'
assert (OUT/'raw/sentinel.stderr').read_bytes()==b'' and (OUT/'raw/stderr_nonzero.stdout').read_bytes()==b''
logpath=pathlib.Path('C:/Users/PC.DESKTOP-81LIH38/.paseo/daemon.log')
blob=logpath.read_bytes(); ls=blob.splitlines(); adjacent=[]
for i,line in enumerate(ls,1):
    try:r=json.loads(line)
    except ValueError:continue
    if 'Unhandled promise rejection' in str(r.get('msg')) and 'taskkill' in str(r.get('err')):
        window=[]
        for j in range(i,min(i+16,len(ls))+1):
            try:q=json.loads(ls[j-1])
            except ValueError:continue
            msg=str(q.get('msg',''))
            # Retain only lifecycle message whitelist; no arbitrary user content.
            if any(w in msg.lower() for w in ['worker','daemon','supervisor','restart','bootstrap','listening']):
                window.append({'line':j,'time':q.get('time'),'pid':q.get('pid'),'module':q.get('module'),
                    'message':safe(msg)[:180],'exit_code':q.get('exitCode',q.get('code'))})
        adjacent.append({'fatal_line':i,'next_16_line_lifecycle':window})
jout(OUT/'raw/lifecycle_adjacency.json',{'snapshot_path':str(logpath),'snapshot_sha256':hashlib.sha256(blob).hexdigest(),
    'snapshot_bytes':len(blob),'observed_at':now(),'selected_last_five':adjacent[-5:],
    'interpretation':'Adjacent lifecycle observations; not proof of async cleanup caller or TASK069 turn-abort causation.'})
write(OUT/'01_MASTER_REPORT.md',f'''# TASK070 execution-stall/runtime diagnostic candidate

Own native session proves TASK069 reached a successful claim and a completed read-only inspection, then the turn was aborted before implementation. It does not prove why that abort happened. Installed Windows cleanup code and dated fatal logs demonstrate a separate daemon rejection hazard; connecting that hazard to this exact abort remains UNKNOWN.

## Exact native evidence and task budget

02_SANITIZED_NATIVE_TRACE.json binds a byte-hashed snapshot of only native thread{SESSION}; it retains selected metadata/operation summaries with original JSONL line numbers, not whole private messages, tool inputs or reasoning. Claim tool call call_8dc4b39cd07a4b23a2db91ba94753343 started07:08:33.164Z and returned07:08:43.098Z. Last call call_81e7bb4928d0418b93d55f68d885feeb started07:08:58.938Z and returned07:09:06.716Z: real mnemonic listing, current branch and C2 source text. No ongoing-session marker is visible in that last output; no unmatched tool call remains in the selected window. The thread records turn_aborted07:09:24.340Z, followed by thread_settings_applied07:18:22.421Z. Abort initiator and reason, scheduling delay, provider cause and daemon-to-turn causation are UNKNOWN. A text substring session_id in earlier outputs may denote native-session metadata; it is not proof of an ongoing unified exec session.

The bound CEO budget-exhaustion receipt records first TASK069 claim07:08:39.662154Z, deadline07:38:39.662154Z and revocation of fence1018 observed07:42:30.758160Z with no source directory/COMPLETE. This matches the absence of writes in this worker's actual turn. A returned command is different from a pending command, an aborted turn, analysis time or an unavailable live-status query. Busy is not dead. Current root/Paseo provider state is not inferred from old process IDs.

## Two tiny hidden controls and actual unified execution handling

Only two Python subprocess controls were run, both with shell=False, CREATE_NO_WINDOW and individual15-second timeout. Full raw stdout/stderr bytes, actual argv/cwd/Python tool hash, input-code hash, UTC start/end and returned exit are in03_CONTROL_RECEIPTS.json. Sentinel exited0 with expected stdout. Controlled stderr exited7 with expected stderr. Finalizer independently rehashed these files and checked literal output, timing and exits. This tests current small subprocess execution only, not daemon recovery or native SO correctness. Timeout/nonreturn behavior was not exercised; the timeout policy is configured, not claimed experimentally verified.

Collection command returned unified exec session85823 with empty output, then polling collected actual exit0 and summary. No empty-output PASS was asserted. Its internal measured collection interval and script hash are in raw/collection_execution.json; that internal receipt is supplemented by the actual outer tool-result summary recorded below. A later read-only metadata lookup yielded session25347 and was polled; its eventual completion is recorded separately if available. Missing completion must remain UNKNOWN, not be silently converted to success. No unrelated session was closed.

## Installed cleanup source and lifecycle evidence

04_CLEANUP_SOURCE_ANCHORS.json binds actual installed @getpaseo/server source files with line ranges. signals.ts signalPlan selects taskkill /PID /T /F on win32; signalProcess returns killTree's promise. killTree awaits execCommand(shell=False), ignores only error.code128 and rethrows other codes. process.ts fail stores the promise and installs a rejection sink; Windows stop awaits cleanup and later awaits a newly issued cleanup promise. Therefore failure propagates through stop unless its actual caller handles the rejection. The exact unhandled caller is not identified by retained node:child_process stacks and remains UNKNOWN; no direct claim that this stop call caused TASK069 abort.

daemon-worker.js installs unhandledRejection fatal logging and calls exitAfterPinoFlush, which schedules process.exit(1) after200ms. Snapshot05_SANITIZED_LIFECYCLE.json measured35 taskkill-associated unhandled fatal rows (current count differs from root's earlier historical33); selected exit255 rows show operation-not-supported taskkill child failures. Error stacks expose generic Node child-process handling, not a causal application caller. The actual source has an explicit daemon-exit path, supporting rejection-to-daemon-crash mechanism. Source does not by itself prove which async caller lost the promise. Lifecycle adjacency is retained in raw/lifecycle_adjacency.json. Adjacent worker/supervisor restart messages are observations, never identity proof or proof of exact069 interruption. No taskkill reproduction was performed.

## Recovery decision and UNKNOWN limits

03_RECOVERY_PROPOSAL.md recommends smallest handling/instrumentation patch and regression contract as research text only. Any global host fix needs separate CEO authorization, then independent controlled validation. This task cannot patch runtime, restart/cancel processes or renew exhausted069. First-acquired deadline is immutable even if lease TTL is renewed. A new session may be useful if current session cannot reliably complete bounded execution, but two passing controls do not establish that a new session is necessary or that the current daemon is recovered. Preserve the actual thread and task provenance; only CEO can authorize a fresh implementation objective after resolving the host gate. No063 retry reset,064/V4 activation or SO45 baseline claim.

No code/config/source/taskkill/provider/schedule modification outside own scope occurred. No installs, app build/decompile/native analysis, heartbeat registration, commit or push. PROJECT_ERROR/ACQUIREMENTS were read; proposed reusable lesson stays in report because durable-memory writes are outside this lease. Controls passing and manifest integrity are tooling evidence only; independent review after>=60s stability is required. Status REVIEW_CANDIDATE_AWAITING_CEO.
'''.encode())
write(OUT/'03_RECOVERY_PROPOSAL.md',b'''# Minimal proposed recovery contract; research only, no patch applied

1. At the actual async owner of Windows tree cleanup, await or catch every cleanup promise. Keep fatal behavior for genuinely unexpected systemic faults, but contain an expected cleanup command failure to an agent/process-scoped diagnostic. Preserve code255/128, stdout/stderr, target identity and cleanup phase as structured evidence. Do not blindly swallow255 or classify it as already-exited; operation-not-supported does not prove the tree is gone.
2. Proposed signals.ts change: add windowsHide:true to the existing shell:false command options if the actual installed execCommand supports it; verify that API first. Return an explicit cleanup outcome with exit/error semantics or wrap the rejection at stop's verified owner. The current caller losing the promise is UNKNOWN, so no precise caller diff is justified yet. Add provenance at the call boundary to expose caller/agent/turn and lifecycle phase without private prompt/nonce.
3. Regression cases for a separately authorized host change: injected command executor resolves; rejects128; rejects255; unexpected error; cleanup rejects before stop, while stop awaits, and while provider fail owns cleanup. Assert every promise is owned, diagnostic retained and daemon survival where policy requires. Use mocked command results for lifecycle behavior; never claim they prove real OS tree cleanup. Real Windows child cleanup validation must use explicitly owned disposable process tree under separate authorization, not existing workers.
4. After host reliability gate, CEO separately assigns any future verifier implementation with fresh exact objective/scope/first-acquired deadline. TASK069 remains exhausted; neither renewal nor session migration resets its original30-minute/one-attempt limit. TASK063 exhausted history stays intact;064/V4 stay gated. No automatic runtime fix or task reopening.
5. Preserve ongoing unified exec session ID plus returned-empty-output observation, poll final completion within budget, and retain exit/timeout/error. On unavailable completion mark UNKNOWN/BLOCKED. Token-safe evidence includes argv allowlist and redacted native metadata, not whole private transcripts.
6. New worker session necessity is UNKNOWN. First investigate abort initiator and host caller instrumentation. If CEO chooses a new session, retain old thread/lease/report provenance and test only bounded read-only controls before separately authorized implementation. Two current control passes are not host recovery acceptance.
''')
jout(OUT/'raw/outer_tool_observations.json',{'source':'Actual current-session unified exec tool results; manually selected metadata, not fabricated original capture',
    'collection':{'initial_chunk_id':'c0a1d9','session_id':85823,'initial_output_empty':True,'initial_exit_code':None,
        'final_chunk_id':'30848a','final_exit_code':0,'final_summary':{'control_exits':[0,7],'native_events':11,'unmatched':[],'taskkill_fatal_rows':35,'lifecycle_rows':74}},
    'later_lookup':{'session_id':25347,'initial_chunk_id':'88b56c','initial_output_empty':True,'poll_chunks':['6af459','7b39b6'],
        'poll_output_empty':True,'completion_status':'PENDING_UNTIL_COLLECTED'},
    'times_not_captured':'Exact outer wallclock timestamps UNKNOWN; do not substitute script internal timestamps.'})
jout(OUT/'raw/final_verification.json',{'schema_version':'2.1.2','task_id':'TASK_070','revision':1,'verified_at':now(),
    'control_bindings':checks,'control_literal_output_and_exit_checks':True,'code':[bind(ROOT/'scripts/task070_runtime_diagnostic/collect.py'),bind(pathlib.Path(__file__))],
    'native_trace_unmatched_calls':native['unmatched_calls_in_window'],'fencing_token':1019})
print(json.dumps({'report_ready':True,'controls_verified':len(controls),'needs_lookup_completion':25347}))
