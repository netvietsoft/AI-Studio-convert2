"""CEO reviewed revision handoff; preserves all R1 bytes and unrelated leases."""
from pathlib import Path
import sys, re, json, datetime, hashlib, shutil
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from controller import Controller, file_sha, iso

r = Path(__file__).resolve().parents[3]
c = Controller(r)
task = r / 'RULES/TASK/TASK_063_SO45_INPUT_TRUTH_AND_RESEARCH_DISPATCH_ACTIVE.md'
review = r / '.ai/ceo/reviews/TASK_063_R1_417dbf52_NEEDS_FIX.md'
with c.transaction() as (registry, state):
    current = c.tasks()['TASK_063']
    assert current['revision'] == 1
    verdict = state['tasks']['TASK_063']['verdict']
    assert verdict['disposition'] == 'NEEDS_FIX'
    assert verdict['fingerprint'] == '417dbf529ca775eafb93011c61a302f5a4f700fc444e3d15ff8c0ad83fa071f0'
    assert verdict['review_sha256'] == file_sha(review)
    assert c.report_snapshot(current)['fingerprint'] == verdict['fingerprint']
    archive = r / 'RULES/REPORT/CEO_SO45_ORCHESTRATION/TASK_063_R1_SNAPSHOT'
    assert not archive.exists(), 'R1 already archived; inspect instead of overwriting'
    c.authorized(c.ceo_lease(registry), archive / 'R1_TASK.md')
    archive.mkdir(parents=True)
    shutil.copy2(task, archive / 'R1_TASK.md')
    shutil.copy2(review, archive / 'CEO_REVIEW.md')
    shutil.copytree(r / 'RULES/REPORT/TASK_063_REPORT', archive / 'report')
    shutil.copytree(r / 'scripts/task063', archive / 'scripts')
    raw = task.read_text(encoding='utf-8-sig')
    match = re.search(r'^```json\s*\n(.*?)\n```', raw, re.S | re.M)
    meta = json.loads(match[1])
    meta.update(revision=2, report_folder='RULES/REPORT/TASK_063_REPORT_R2',
                files_allowed=['scripts/task063_r2/**', '.ai/reconstruction/evidence/TASK_063_R2/**',
                               'RULES/REPORT/TASK_063_REPORT_R2/**', 'F:/TOOLS/ghidra_projects/TASK_063_R2/**'],
                files_forbidden=meta['files_forbidden'] + ['scripts/task063/**',
                                                         'RULES/REPORT/TASK_063_REPORT/**'],
                correction_review='.ai/ceo/reviews/TASK_063_R1_417dbf52_NEEDS_FIX.md',
                supersedes_revision=1, max_fix_cycles=3)
    raw = raw[:match.start(1)] + json.dumps(meta, indent=2, ensure_ascii=False) + raw[match.end(1):]
    raw = re.sub(r'^MODIFIED_TIME:.*$', 'MODIFIED_TIME: ' + iso(c.clock()), raw, flags=re.M)
    raw = raw.replace('scripts/task063/**', 'scripts/task063_r2/**') if False else raw
    # Human report-path references are updated separately from JSON to retain forbidden R1 scope.
    fence_end = raw.index('\n```', raw.index('```json')) + len('\n```')
    raw = raw[:fence_end] + raw[fence_end:].replace('RULES/REPORT/TASK_063_REPORT/', 'RULES/REPORT/TASK_063_REPORT_R2/')
    raw += '''

## Revision 2 — CEO correction order (ACTIVE / execution authorized)

R1 is NEEDS_FIX. Read the full original canonical standard again before this revision and every resume/worker; record actual measured SHA/path/time/identity/new lease fence in 00_AUDIT_INDEX.md. Also read `.ai/ceo/reviews/TASK_063_R1_417dbf52_NEEDS_FIX.md`, `TASK_063_CRITICAL_ANCHOR_ADVISORY.md` and `TASK_063_INPUT_ADVISORY_20261008.md`. Work only in the revision2 JSON scopes. R1 reports/scripts stay frozen; its archive is RULES/REPORT/CEO_SO45_ORCHESTRATION/TASK_063_R1_SNAPSHOT. Do not reuse R1 fencing1009 in R2 metadata. Claim the current TASK_063 revision2 using the controller; it creates a new lease/fence. No permission question to Tony.

Fix the eight numbered CEO findings with real retained commands/raw output. Reuse valid original measurements/body exports; do not rerun all Ghidra inputs just to make counts. Required corrections:

1. Parse actual bounded XAPK local headers and every available SO payload. Preserve container SHA/size, header/data offsets, flags/compression, declared/available bounds, payload SHA/CRC versus extracted file, missing tail and status. Prove44 matches by actual bytes, not filename/size or literals. For mfx preserve actual prefix comparison and missing581084 evidence if verified. Label whole container PARTIAL; missing libmtImageKit is absent only in observed set, incomplete tail UNKNOWN. Distinguish app-debug rebuilt47SO from original vendor inputs. Preserve absence/source inference limits.
2. Per-library evidence table: actual symbol/JNI/address inventory, exact old body/disassembly/log hashes, relevant operation/address anchors, tool exit and sample coverage. Drop hardcoded generic catalog/quality/role/function names. Use NOT_CHECKED/UNKNOWN where unfinished. List real exported/internal targets and caller/asset searches, scoped relevant stop conditions and gap counts derived from actual records. Verified standard/runtime boundaries need justified identity/wrapper consumers, not mandatory full pixel arithmetic.
3. Reproduce original XOR-decoded shader bytes with original/decoded hashes, real decoder command/raw receipt and line anchors. C1 red channel and alpha=val OBSERVED; upstream exclusion semantic producer UNKNOWN unless traced. C2 literal piecewise formula and alpha1; no unsupported W3C/Photoshop equivalence. Include counterexamples and decoded binary-tail/compile/runtime limitations.
4. C3 independently dump actual weights/hex/H+V offsets, explain file/RVA/Ghidra base, body load->uniform->shader consumer and units. Distinguish SoftHair versus Aurora blur; document actual defaults/consumer gaps as UNKNOWN. All printed float hex must match bytes. C4 preserve actual SoftHair stage order but keep dye-material config/order/defaults UNKNOWN until real JNI/config/native anchors. Correct function entry versus callsite address.
5. C5 retain exact performed scan scope and raw model/JNI/loader/asset search results. No architecture/model-runtime/confidence conclusion from strings or a missing name. UNKNOWN is a valid baseline result with precise next targets. Explicitly resolve T3 and prior reviewer001/003/004 findings or carry concrete open gaps; preserve superseded059/060 and NEEDS_FIX062 truth.
6. Actual command/start/end/exit/tool/input/output hashes for every used proof; timestamps must reflect actual measured actions. Invoke version/help or hash-bind earlier real Ghidra launch log; folder existence is not invocation. Retain real stdout/stderr for inspected symbols/disassembly; intentionally limited output is PARTIAL, not whole-library FALSE. Progress counters derived from measurements; no arbitrary gaps/completion scores or assumed library matches.

Deliver R2 00_AUDIT_INDEX.md,01_MASTER_REPORT.md,02_SO45_INPUT_MANIFEST.csv,03_EXISTING_EVIDENCE_AUDIT.csv,04_SO45_LANE_ASSIGNMENTS.csv,05_CRITICAL_CLAIM_CHECKS.md,06_TOOLCHAIN_AND_HEARTBEAT_RECEIPTS.json,raw/, scripts, PROGRESS.json and COMPLETE.json using revision2. Manifest covers all frozen artifacts and actual code hashes. No product PASS or V4 readiness. CEO checks all critical claims and >=10% ordinary records again after stable >=60s packaging. TASK_064A..G stay PLANNED until acceptance. Submit REVIEW_CANDIDATE_AWAITING_CEO before commit/push and return to minute scanner.
'''
    c.authorized(c.ceo_lease(registry), task)
    # State/registry guards prevent concurrent controller claims during the handoff.
    tmp = r / '.ai/locks.ceo.task063r2.tmp'
    tmp.write_text(raw, encoding='utf-8')
    assert file_sha(task) == current['_task_sha']
    tmp.replace(task)
    updated = json.loads(json.dumps(registry))
    old = next(x for x in updated['active_locks'] if x['lease_id'] == 'LEASE-CEO-WORKER-TASK_063-R1')
    assert old['agent_id'] == 'ace29908-a2b0-4777-a070-6bd100509738' and old['fencing_token'] == 1009
    old.update(status='REVOKED', expiry=iso(c.clock()), released_at=iso(c.clock()),
               release_reason='R1 NEEDS_FIX; immutable snapshot retained; revised disjoint R2 scope')
    updated['revision'] = registry.get('revision', 0) + 1
    c.replace_json(c.registry, updated, registry)
    registry.clear(); registry.update(updated)
    state['claims']['TASK_063:r1'].update(expiry=0, status='REVOKED', closure='R2_CORRECTION_HANDOFF')
    c.event(state, 'CEO_TASK_REVISION_ISSUED', 'TASK_063', revision=2,
            task_file=current['_path'], report_folder=meta['report_folder'],
            previous_fingerprint=verdict['fingerprint'], review_file=verdict['review_file'])
    files = {p.relative_to(archive).as_posix(): file_sha(p) for p in sorted(archive.rglob('*')) if p.is_file()}
    (archive / 'SNAPSHOT_MANIFEST.json').write_text(json.dumps(files, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({'task_id':'TASK_063','revision':2,'status':'ACTIVE',
                      'task_sha':file_sha(task),'archive':str(archive),'old_lease':'REVOKED',
                      'report_folder':meta['report_folder']}))
