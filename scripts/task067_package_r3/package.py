"""TASK067 R3: package existing R2 bytes, never execute diagnostic producers."""
import ast, datetime, hashlib, json, pathlib, subprocess, sys
ROOT=pathlib.Path(__file__).resolve().parents[2]
OLD=ROOT/'RULES/REPORT/TASK_067_REPORT_R2'
OUT=ROOT/'RULES/REPORT/TASK_067_REPORT_R3'
STD='10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f'
TASKSHA='12e3175f230c16533aa6c34d3c801bb1750db7d1f6d207584ee40bdc71c0fcbe'
ACTOR='7de71900-89f8-4633-97a9-3efaf42ea6b8'
SESSION='01a119f1-f400-7441-8b7a-26375ae0f459'
def now(): return datetime.datetime.now(datetime.timezone.utc).isoformat()
def digest(p):
    h=hashlib.sha256()
    with open(p,'rb') as f:
        for b in iter(lambda:f.read(1048576),b''): h.update(b)
    return h.hexdigest()
def bind(p): return {'path':str(p),'sha256':digest(p),'bytes':p.stat().st_size}
def guard():
    ls=json.loads((ROOT/'.ai/locks.json').read_text(encoding='utf-8-sig'))['active_locks']
    l=next(x for x in ls if x['lease_id']=='LEASE-CEO-WORKER-TASK_067-R3')
    assert l['status']=='ACTIVE' and l['fencing_token']==1016
    start=datetime.datetime.fromisoformat(l['acquired_at'])
    assert datetime.datetime.now(datetime.timezone.utc)<start+datetime.timedelta(minutes=15)
    return l
def write(p,b):
    guard(); assert p.is_relative_to(OUT); p.parent.mkdir(parents=True,exist_ok=True); p.write_bytes(b)
def jout(p,d): write(p,json.dumps(d,ensure_ascii=False,indent=2).encode())
def progress(status,milestone):
    jout(OUT/'PROGRESS.json',{'schema_version':'2.1.2','task_id':'TASK_067','revision':3,'status':status,
        'agent_id':ACTOR,'native_session_id':SESSION,'internal_role':'/root','lease_id':'LEASE-CEO-WORKER-TASK_067-R3',
        'fencing_token':1016,'updated_at':now(),'correction_cycle':1,'milestone':milestone})
def build():
    l=guard(); assert not (OUT/'COMPLETE.json').exists()
    write(OUT/'00_AUDIT_INDEX.md',f'''# TASK067 R3 audit index
Full UTF8 standard reread: 2026-10-08T13:34:33.9531829+07:00.
Path: {ROOT / 'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt'}
Measured SHA256: {STD}; unchanged from previously understood full text.
Exact R3 task: RULES/TASK/TASK_067_VALIDATOR_FAILURE_DIAGNOSTIC_ACTIVE.md; SHA256 {TASKSHA}.
Read AGENTS.md, Docs/rules.md, PROJECT_ERROR.md, ACQUIREMENTS.md, current CEO plan, original R2 task snapshot, TASK063 R3 NEEDS_FIX review and TASK068 ELF address finding.
External Paseo actor: {ACTOR}; native CODEX_THREAD_ID: {SESSION}; internal role: /root.
Actual engine: Codex diagnostic worker under AGY coordination; CEO task registry labels codex/gpt-6.1-sol. No Antigravity identity claim.
Lease: {l['lease_id']}; fence1016; actual first claim {l['acquired_at']}; controller dispatch binding verified.
One packaging correction only; deadline15min from this claim. Original diagnostic not rerun.
R2 original result interval05:44:12.063849Z..05:44:16.907461Z preserved unchanged as historical measured evidence.
No baseline/production/P0/source/CEO-state modifications, no heartbeat or Git publication. Unrelated workspace changes preserved.
'''.encode())
    progress('TASK_EXECUTING','R3_CLAIM_AND_AUDIT_RECORDED')
    d=json.loads((OLD/'02_DIAGNOSTIC_RESULTS.json').read_text())
    assert digest(pathlib.Path(d['script']['path']))==d['script']['sha256']
    assert all(d['regression_checks'].values())
    copies=[]
    for p in sorted(OLD.rglob('*')):
        if p.is_file() and (p.relative_to(OLD).parts[0]=='raw' or p.name=='02_DIAGNOSTIC_RESULTS.json'):
            dest=OUT/p.relative_to(OLD); b=p.read_bytes(); write(dest,b)
            assert digest(dest)==digest(p)
            copies.append({'origin':bind(p),'retained':bind(dest),'mode':'UNCHANGED_HISTORICAL_R2_BYTES'})
    oldscript=ROOT/'scripts/task067_diagnostic_r2/diagnose.py'
    write(OUT/'raw/origin_diagnose.py.txt',oldscript.read_bytes())
    # Check present immutable references; classify mutable schedules rather than demand equality.
    checked=[]; mutable=[]; cache={}
    def check(o):
        if isinstance(o,dict):
            if 'path' in o and 'sha256' in o:
                p=pathlib.Path(o['path']); recorded=o['sha256']
                if '.paseo' in str(p) and 'schedules' in str(p):
                    current=digest(p) if p.exists() else None
                    mutable.append({'path':str(p),'recorded_sha256':recorded,'current_sha256':current,'observed_at':now(),
                        'classification':'UNCHANGED_AT_OBSERVATION' if current==recorded else ('CHANGED_HISTORICAL_REFERENCE' if current else 'MISSING_CURRENT_REFERENCE'),
                        'current_provider_availability':'UNKNOWN','historical_original_bytes_retained':False})
                elif p.exists():
                    if str(p) not in cache: cache[str(p)]=digest(p)
                    assert cache[str(p)]==recorded,str(p)
                    checked.append({'path':str(p),'recorded_sha256':recorded,'current_sha256':cache[str(p)]})
                else: checked.append({'path':str(p),'recorded_sha256':recorded,'current_status':'MISSING_UNKNOWN'})
            for v in o.values(): check(v)
        elif isinstance(o,list):
            for v in o: check(v)
    check(d)
    # Read-only AST extraction of existing unexecuted report drafts; never call old producer.
    draft=ROOT/'scripts/task067_diagnostic_r2/package.py'
    tree=ast.parse(draft.read_text()); texts={}
    for n in ast.walk(tree):
        if isinstance(n,ast.Call) and isinstance(n.func,ast.Name) and n.func.id=='write' and len(n.args)==2:
            a=n.args[0]
            if isinstance(a,ast.BinOp) and isinstance(a.right,ast.Constant) and a.right.value in ['01_MASTER_REPORT.md','03_REMEDIATION_RECOMMENDATION.md']:
                texts[a.right.value]=ast.literal_eval(n.args[1]).decode()
    assert len(texts)==2
    master=texts['01_MASTER_REPORT.md'].replace('TASK067 R2 causal diagnostic review candidate','TASK067 R3 packaging correction of historical R2 diagnostic')
    master=master.replace('during this attempt','during the original R2 diagnostic')
    master=master.replace('Fresh libManis readelf','Original R2 libManis readelf').replace('A fresh lightweight libManis readelf execution','The original R2 lightweight libManis readelf execution')
    master=master.replace('stage entry0x002344e8 and historical body anchors','historical Ghidra FilterToFBO text identifier0x002344e8 and body-text anchors')
    master=master.replace('Only R2 script/report scope was written.','During R2 only its script/report scope was written; R3 writes only its own packaging script/report scope.')
    master+='''
## R3 packaging correction and superseding address limitation

R3 copied original R2 result/raw artifacts byte-for-byte without changing their revision2 labels, internal timestamps or hashes. These labels describe historical origin, not current R3 execution. R3 current task/fence and packaging execution are bound separately by COMPLETE and raw/package_execution.json. The copy-provenance table and current immutable-reference checks are in04_PROVENANCE.json. No diagnostic producer, original package producer, native tool or heavy analysis was executed in R3.

Historical external mutable schedule hashes are recorded alongside current observed hashes in04_PROVENANCE.json; changed/missing current files are historical references, not immutable-evidence failures. Original schedule bytes at historical receipt time are unavailable in this package; current provider availability and continuous successful delivery remain UNKNOWN. The prior R2 packaging assertion failed on a changed9ed2909e schedule; original R2 package remained incomplete until its deadline expired. That failure does not invalidate the independently verified diagnostic script/result/raw bindings.

Address0x2344e8 is a historical Ghidra FilterToFBO text identifier ONLY. Per the hash-bound TASK068 ELF finding, that literal address is not a file-backed executable address in the current arm64 ELF; current image-base/ABI/address correspondence is UNKNOWN. Neither the reused body text nor tables establish body-to-current-native correspondence, a runtime pointer, native function entry or native execution order. Any stronger wording inside unchanged historical JSON is superseded by this explicit limitation.

Initial R2 guard failure KeyError leases is disclosed; the harness was changed to actual active_locks before the successful diagnostic. Exact initial parent invocation times/script hash/original stdout bytes were not captured and remain UNKNOWN. No fabricated parent capture is supplied. R3 package_execution receipt captures actual packaging child argv/start/end/exit/stdout/stderr only.

This is REVIEW_CANDIDATE_AWAITING_CEO. Diagnostic assertions and package integrity do not constitute independent acceptance, TASK063 baseline acceptance,064 dependency satisfaction or V4/product PASS. No retry budget reset. Return to own-identity scanner under existing CEO supervision.
'''
    write(OUT/'01_MASTER_REPORT.md',master.encode())
    remediation=texts['03_REMEDIATION_RECOMMENDATION.md']+'''\nR3 clarification: classify mutable external schedule references with original recorded/current observed digest and observation time; do not assert historical equality or reconstruct missing original bytes. Current availability remains UNKNOWN. Treat0x2344e8 solely as historical Ghidra text identifier until a separate authorized body/ELF base/ABI mapping investigation establishes correspondence. Table/source hashes alone are insufficient. Never use this identifier as a native pointer. No recommendation is applied by this packaging task.\n'''
    write(OUT/'03_REMEDIATION_RECOMMENDATION.md',remediation.encode())
    finding=ROOT/'.ai/ceo/receipts/TASK_068_ELF_ADDRESS_FINDING.json'
    write(OUT/'raw/ELF_ADDRESS_FINDING.historical.json',finding.read_bytes())
    write(OUT/'raw/harness_history.txt',b'''Historical session account; not an original process capture.
R2 first diagnostic invocation exited1: KeyError 'leases' in guard, before computation/artifact writes.
Changed guard key to actual active_locks; successful result records05:44:12.063849Z..05:44:16.907461Z and unchanged executed-script hash.
R2 packaging invocation exited1 on mutable external schedule hash assertion (9ed2909e.json); no COMPLETE produced.
Initial parent command times/script digest/stdout raw bytes not captured: UNKNOWN.
R3 does not rerun these commands. Original result/raw bytes preserved unchanged.
''')
    jout(OUT/'04_PROVENANCE.json',{'schema_version':'2.1.2','task_id':'TASK_067','revision':3,'fence':1016,
        'observed_at':now(),'copies':copies,'original_executed_script':bind(oldscript),'report_draft_source':bind(draft),
        'immutable_reference_checks':checked,'mutable_historical_references':mutable,'ELF_finding':bind(finding),
        'original_result':bind(OLD/'02_DIAGNOSTIC_RESULTS.json'),'original_measurement_start':d['started_at'],
        'original_measurement_end':d['ended_at'],'current_diagnostics_rerun':False})
    print(json.dumps({'verified_copies':len(copies),'checked_bindings':len(checked),'mutable_references':len(mutable),'status':'PACKAGED_PENDING_MANIFEST'}))

if __name__=='__main__':
    if '--build' in sys.argv: build()
    else:
        guard(); started=now(); cmd=[sys.executable,'-X','utf8','-B',str(pathlib.Path(__file__).resolve()),'--build']
        proc=subprocess.run(cmd,capture_output=True); ended=now()
        write(OUT/'raw/package.stdout',proc.stdout); write(OUT/'raw/package.stderr',proc.stderr)
        jout(OUT/'raw/package_execution.json',{'schema_version':'2.1.2','task_id':'TASK_067','revision':3,
             'command':cmd,'started_at':started,'ended_at':ended,'exit_code':proc.returncode,'script':bind(pathlib.Path(__file__)),
             'python':bind(pathlib.Path(sys.executable)),'stdout':bind(OUT/'raw/package.stdout'),'stderr':bind(OUT/'raw/package.stderr'),
             'original_result':bind(OLD/'02_DIAGNOSTIC_RESULTS.json'),'fencing_token':1016})
        if proc.returncode:
            progress('BLOCKED','PACKAGING_FAILURE_NO_EXTENSION'); print(proc.stderr.decode(errors='replace')); sys.exit(proc.returncode)
        progress('REVIEW_CANDIDATE_AWAITING_CEO','FROZEN_REPORT_RETURNING_TO_OWN_SCANNER')
        files={p.relative_to(OUT).as_posix():digest(p) for p in sorted(OUT.rglob('*')) if p.is_file() and p.name not in ['PROGRESS.json','COMPLETE.json']}
        jout(OUT/'COMPLETE.json',{'schema_version':'2.1.2','task_id':'TASK_067','revision':3,'status':'COMPLETE',
            'disposition':'REVIEW_CANDIDATE_AWAITING_CEO','standard_sha256':STD,'task_sha256':TASKSHA,
            'agent_id':ACTOR,'native_session_id':SESSION,'internal_role':'/root','lease_id':'LEASE-CEO-WORKER-TASK_067-R3',
            'fencing_token':1016,'completed_at':now(),'files':files,'code_files':['scripts/task067_package_r3/package.py'],
            'code_sha256':{'scripts/task067_package_r3/package.py':digest(pathlib.Path(__file__))},'correction_cycle':1,
            'historical_origin_revision':2,'diagnostics_rerun':False,'baseline_accepted':False,'commit':None,'push':False})
        for rel,h in files.items(): assert digest(OUT/rel)==h
        print(json.dumps({'status':'REVIEW_CANDIDATE_AWAITING_CEO','manifest_files':len(files),'complete_sha256':digest(OUT/'COMPLETE.json')}))
