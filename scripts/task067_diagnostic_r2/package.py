"""Verify existing measurements and freeze R2 review package; no diagnostic rerun."""
import datetime, hashlib, json, pathlib, os
from diagnose import ROOT, OUT, RAW, STANDARD, guard, write, jwrite, binding, now

guard()
assert not (OUT/'COMPLETE.json').exists(), 'Frozen package exists; do not overwrite'
d=json.loads((OUT/'02_DIAGNOSTIC_RESULTS.json').read_text())
assert now()<'2026-10-08T06:25:47+00:00'
cache={}; verified=[]
def verify(obj):
    if isinstance(obj,dict):
        if all(k in obj for k in ['path','sha256']):
            p=pathlib.Path(obj['path'])
            if p.exists():
                if str(p) not in cache: cache[str(p)]=binding(p)
                assert cache[str(p)]['sha256']==obj['sha256'], str(p)
                verified.append({'path':str(p),'sha256':obj['sha256']})
        for v in obj.values(): verify(v)
    elif isinstance(obj,list):
        for v in obj: verify(v)
verify(d)
assert all(d['regression_checks'].values())
write(RAW/'harness_initial_failure.txt',b'''Session-tool transcript copied during packaging (not original captured process bytes).
Command: python -X utf8 -B scripts/task067_diagnostic_r2/diagnose.py
Initial invocation exit_code: 1
At guard(), JSON lookup ['leases'] raised KeyError: 'leases'.
No diagnostic computation or artifact write occurred before this guard failure.
Correction: use actual registry key ['active_locks']; same task attempt, no baseline retry.
Exact start/end times and initial script SHA were not captured: UNKNOWN.
Successful corrected invocation: exit_code 0 observed in session tool result; measured
internal interval 2026-10-08T05:44:12.063849+00:00 to 2026-10-08T05:44:16.907461+00:00.
Parent-process stdout was displayed in session, not persisted as original raw bytes.
Actual child readelf stdout/stderr bytes and command times are retained separately.
''')
write(OUT/'01_MASTER_REPORT.md',b'''# TASK067 R2 causal diagnostic review candidate

The measured R3 failures arise from an unenforced status gate, a disassembly-format mismatch and static proof text that is not derived from the cited original inputs. This diagnostic demonstrates those causes without modifying TASK063 or accepting its baseline.

## Input-status cause and counterexamples

The actual AST-extracted R3 `byte_match` assignment and `if ce['complete']` branch are compiled independently; mutating main is never imported or executed. `raw/source_anchors.json` binds each original line range and extracted fragment to SHA256. The original parser is executed with BytesIO over exact local header/payload slices. Slices rebase header offset to zero; original container coordinates and header hex remain in `raw/input_cases.json`.

For the complete real libaicodec control, old and reference statuses are EXACT_PAYLOAD_MATCH. Changing a payload byte, declared CRC, flags, method or compressed size still produces old EXACT_PAYLOAD_MATCH. The same reference function rejects each. A changed declared size yields old PARTIAL_CONTAINER_TRUNCATED, whereas the reference rejects stored-size inconsistency. Thus old classification does not enforce its calculated byte_match or header/CRC constraints.

For actual mfx, both inputs contain only 773652 bytes of declared 1354736, deficit 581084. Original container prefix and disk agree; full-file declared CRC cannot be checked. Old partial status and its generated note remain unchanged even when the prefix is corrupted; reference rejects the payload mismatch. Changing only mfx declared CRC intentionally stays partial/UNKNOWN in the reference: there is no full tail against which to validate that CRC. This case is not presented as a corruption detector. Flags/method/size inconsistencies are rejected by the same reference function. Reference only supports flags0/stored-method0 for these measured controls, not a general ZIP validator. Header/data bounds and prefix/CRC distinctions are explicit in JSON.

## Retained-format cause

R3 INS_RE requires an eight-hex instruction word while its objdump command uses --no-show-raw-insn. All five old counts are zero. Measured retained instruction/arithmetic counts are libaicodec1470/8, libaidetectionplugin1464/0, libPVGColorFunctions1450/0, libMTLReportTool1466/0 and libManis1494/0. Each file contains1500 retained text lines. Literal examples, line anchors, address/mnemonic/operands and text-versus-instruction counts are in raw/parser_cases.json.

Malformed checks reject nonhex addresses, labels, question-mark mnemonics, raw-word format, unaligned addresses, headings and empty lines. This parser validates the demonstrated no-raw-insn syntax, not every AArch64 opcode. Zero arithmetic in a bounded sample says nothing about the rest of that library. No new full disassembly/decompilation was run.

R3 captures full-output receipts transiently, retains only the first1500 lines, and does not serialize per-SO receipt objects. A full-output hash cannot independently identify the retained bytes. Historical per-SO command start/end/exit remain UNKNOWN; no file-mtime reconstruction was used. Existing hashes bind the present retained samples; they do not retroactively prove original command execution. A fresh lightweight libManis readelf execution has real tool/input/start/end/exit/stdout/stderr hashes in raw/critical_cases.json.

## Critical-provenance causes and controls

Original APK C2 bytes were actually read and XOR decoded during this attempt. Decoded source contains SoftLight_Fcn and does not contain blendColor, whereas R3 labels its rewritten blendColor block verbatim. Literal decoded bytes and SHA256 are retained in raw/C2.decoded.fs; original encrypted entry bytes are retained too. Equivalent algebra, if established separately, would not make that block a literal quotation.

Original APK contains assets/vlaimodel/libmtskinphone/Models/NE.manis; the claimed libmtface/models/NE.manis path is absent. Actual entry hash/size are in results. Fresh libManis readelf gives303 defined nonzero symbol records, of which288 names contain case-insensitive manis. The cause is conflating total defined records with keyword hits. All hit lines are retained with actual readelf output.

Known-good controls are explicitly reused from CEO critical_source_reproduction.json with measured current receipt/input hashes: SoftLight69/512 versus5/32, difference11/512;30 native float words; stage entry0x002344e8 and historical body anchors. These are hash-bound historical reuse, not a claim this worker reran the CEO math/decompilation/spirv command. Ghidra current application.properties is hashed with literal version/build lines. Historical heartbeat receipts are reused with their actual statuses; current provider availability and continuous successful delivery remain UNKNOWN.

## Execution and limits

Initial harness guard used nonexistent leases key and exited1 before measurement/writes. Correcting it to active_locks allowed the same bounded attempt to execute successfully. Initial exact timing/script hash and original parent stdout byte capture are UNKNOWN; a labeled session-transcript summary is in raw/harness_initial_failure.txt. Successful script SHA matches02_DIAGNOSTIC_RESULTS.json and current file. Actual child stdout/stderr are preserved. Eleven meaningful diagnostic assertions passed; this is neither Phase PASS nor independent acceptance.

No15-target readelf rerun was needed: target correctness was not disputed by the CEO review; this task investigates counts and provenance. No product build/device QA is required for isolated diagnostic artifacts; no product PASS is claimed. PROJECT_ERROR/ACQUIREMENTS were read, but durable-memory edits are outside this lease; reusable findings are proposed for CEO disposition only. Model architecture, runtime loader/producer, confidence, material defaults, missing mfx tail and truncation cause remain UNKNOWN.

Only R2 script/report scope was written. Original SOURCE, R3, production/P0 and CEO state were not edited. Existing unrelated workspace changes were preserved. No baseline/lane regeneration, downstream activation, commit/push or duplicate heartbeat occurred. Submit REVIEW_CANDIDATE_AWAITING_CEO; TASK063 remains blocked pending separate CEO disposition.
''')
write(OUT/'03_REMEDIATION_RECOMMENDATION.md',b'''# Proposed minimal remediation; not applied

1. Extract one explicit input classifier used by real manifest generation and all regression cases. Before claiming exact match, require supported header flags/method, bounded header/data coordinates, consistent stored compressed/declared size, actual payload equality, disk/available size equality and complete CRC equality. For partial input require prefix equality, retain declared/available sizes and mark tail/full CRC UNKNOWN. Never derive a matching claim from completeness alone. General compressed/data-descriptor ZIP support requires a separate supported policy; fail closed otherwise.
2. Match the actual retained no-raw-insn address/mnemonic format. Keep sample boundary and text/instruction counts distinct. Add the five real hashed samples plus malformed/noninstruction cases demonstrated here. Never promote zero sampled arithmetic to whole-library absence.
3. Serialize command receipts immediately, with schema_version, task/revision/fence, argv, cwd, input path/size/hash, tool path/hash/version provenance, UTC started_at/ended_at, exit_code, raw stdout/stderr paths/bytes/hashes and retention policy. If truncating, bind full stdout hash AND retained byte hash separately, with line range/encoding/newline transformation. Example retention: first1500 splitlines, join LF, trailing LF when nonempty. Mark absent historical timestamps UNKNOWN; do not synthesize them.
4. Generate critical quotation blocks from actual original decoded bytes with APK/entry/raw/decoded hashes, decoder script hash and literal line anchors. Put algebraic explanations outside literal blocks. Derive literal model paths from original entry lists and exact keyword counts from defined nonzero symbol records; store numerator288 and denominator303 separately. Names do not prove runtime architecture or producer semantics.
5. Keep CEO known-good controls as explicit hash-bound historical reuse until an authorized recovery task requires rerun. Parse real application.properties metadata. Preserve native heartbeat failed/busy/missing delivery distinctions; registration alone is insufficient. No duplicate heartbeat.

Recommended review order: independently inspect payload/CRC/header counterexamples; compare all five raw parser examples; compare original C2 and model bytes; recount fresh Manis output; verify reuse input hashes and unknown limits. Then CEO records a separate baseline recovery disposition. TASK067 acceptance must not accept TASK063, reset its exhausted attempts, satisfy064 dependencies or authorize V4.

Proposed durable error entry: unenforced classification and source-format assumptions can create false proof even when calculated evidence is correct. Proposed acquirement: one executable classifier, actual-format fixtures and durable per-command/retention receipts. Memory files remain untouched because they are outside TASK067 R2 lease.
''')
receipt={'schema_version':'2.1.2','task_id':'TASK_067','revision':2,'command':'python -X utf8 -B scripts/task067_diagnostic_r2/package.py',
         'verified_at':now(),'bindings_checked':verified,'diagnostic_script_unchanged':True,'regression_checks':d['regression_checks'],
         'package_script':binding(pathlib.Path(__file__)),'fencing_token':1013,'purpose':'Verify existing result bindings; no heavy rerun'}
jwrite(RAW/'package_verification.json',receipt)
audit=(OUT/'00_AUDIT_INDEX.md').read_text()
audit+='\nResume full UTF8 rule reread/hash verification: 2026-10-08T12:53:30.7413699+07:00; standard/task unchanged. Lease ACTIVE/fence1013; no diagnostic Python command running; no COMPLETE existed before packaging. Conservative attempt deadline06:25:47Z unchanged.\nResults and raw source anchors: 02_DIAGNOSTIC_RESULTS.json, raw/input_cases.json, raw/parser_cases.json, raw/critical_cases.json, raw/source_anchors.json. Existing result execution05:44:12Z..05:44:16Z reused with current executed-script SHA verified. Final package verification in raw/package_verification.json.\n'
write(OUT/'00_AUDIT_INDEX.md',audit.encode())
jwrite(OUT/'PROGRESS.json',{'schema_version':'2.1.2','task_id':'TASK_067','revision':2,'status':'REVIEW_CANDIDATE_AWAITING_CEO',
    'agent_state':'RETURNING_TO_SCANNER','updated_at':now(),'agent_id':'7de71900-89f8-4633-97a9-3efaf42ea6b8',
    'native_session_id':'01a119f1-f400-7441-8b7a-26375ae0f459','internal_role':'/root','fencing_token':1013,
    'lease_id':'LEASE-CEO-WORKER-TASK_067-R2','milestone':'MEASURED_RESULTS_VERIFIED_AND_REPORT_PACKAGED','attempt':1,
    'deadline':'2026-10-08T06:25:47Z','independent_acceptance':False})
files={p.relative_to(OUT).as_posix():binding(p)['sha256'] for p in sorted(OUT.rglob('*')) if p.is_file() and p.name not in ['COMPLETE.json','PROGRESS.json']}
jwrite(OUT/'COMPLETE.json',{'schema_version':'2.1.2','task_id':'TASK_067','revision':2,'status':'COMPLETE',
    'disposition':'REVIEW_CANDIDATE_AWAITING_CEO','standard_sha256':STANDARD,'task_sha256':'9e1b65478a0bf9dfb1e30ab6feaa76bbe5e8a8a51c6b25559487cff697b9bd28',
    'agent_id':'7de71900-89f8-4633-97a9-3efaf42ea6b8','native_session_id':'01a119f1-f400-7441-8b7a-26375ae0f459','internal_role':'/root',
    'fencing_token':1013,'lease_id':'LEASE-CEO-WORKER-TASK_067-R2','completed_at':now(),'files':files,
    'code_files':['scripts/task067_diagnostic_r2/diagnose.py','scripts/task067_diagnostic_r2/package.py'],
    'code_sha256':{n:binding(ROOT/n)['sha256'] for n in ['scripts/task067_diagnostic_r2/diagnose.py','scripts/task067_diagnostic_r2/package.py']},
    'baseline_accepted':False,'commit':None,'push':False})
print(json.dumps({'status':'REVIEW_CANDIDATE_AWAITING_CEO','report_files':len(files),'bindings_verified':len(verified),'complete':binding(OUT/'COMPLETE.json')}))
