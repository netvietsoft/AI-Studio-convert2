"""Fenced correction handoff; freeze R2 and publish disjoint R3 task scope."""
from pathlib import Path
import json, os, re, shutil, sys
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from controller import Controller, file_sha, iso
r = Path(__file__).resolve().parents[3]
c = Controller(r)
with c.transaction() as (registry, state):
    current = c.tasks()['TASK_063']
    assert current['revision'] == 2
    verdict = state['tasks']['TASK_063']['verdict']
    assert verdict['disposition'] == 'NEEDS_FIX'
    assert verdict['fingerprint'] == '79d93b4fdea4875bbdb5826ba9d1958ccad718cbe3208a5b708010b837b38c00'
    review = r / verdict['review_file']
    assert file_sha(review) == verdict['review_sha256']
    assert c.report_snapshot(current)['fingerprint'] == verdict['fingerprint']
    task = r / current['_path']
    archive = r / 'RULES/REPORT/CEO_SO45_ORCHESTRATION/TASK_063_R2_SNAPSHOT'
    assert not archive.exists()
    c.authorized(c.ceo_lease(registry), archive / 'R2_TASK.md')
    archive.mkdir(parents=True)
    shutil.copy2(task, archive / 'R2_TASK.md')
    shutil.copy2(review, archive / 'CEO_REVIEW.md')
    shutil.copytree(r / current['report_folder'], archive / 'report')
    shutil.copytree(r / 'scripts/task063_r2', archive / 'scripts')
    hashes = {p.relative_to(archive).as_posix(): file_sha(p) for p in sorted(archive.rglob('*')) if p.is_file()}
    (archive/'SNAPSHOT_MANIFEST.json').write_text(json.dumps(hashes, indent=2)+'\n', encoding='utf-8')
    raw = task.read_text(encoding='utf-8-sig').split('\n## Revision 2 —')[0]
    match = re.search(r'^```json\s*\n(.*?)\n```', raw, re.S | re.M)
    meta = json.loads(match[1])
    meta.update(revision=3, report_folder='RULES/REPORT/TASK_063_REPORT_R3',
        files_allowed=['scripts/task063_r3/**','.ai/reconstruction/evidence/TASK_063_R3/**',
                       'RULES/REPORT/TASK_063_REPORT_R3/**','F:/TOOLS/ghidra_projects/TASK_063_R3/**'],
        correction_review=verdict['review_file'], supersedes_revision=2)
    meta['files_forbidden'] += ['scripts/task063_r2/**','RULES/REPORT/TASK_063_REPORT_R2/**',
                                '.ai/reconstruction/evidence/TASK_063_R2/**']
    raw = raw[:match.start(1)] + json.dumps(meta, ensure_ascii=False, indent=2) + raw[match.end(1):]
    end = raw.index('\n```', raw.index('```json')) + len('\n```')
    raw = raw[:end] + raw[end:].replace('TASK_063_REPORT_R2/', 'TASK_063_REPORT_R3/')
    raw = re.sub(r'^MODIFIED_TIME:.*$', 'MODIFIED_TIME: '+iso(c.clock()), raw, flags=re.M)
    raw += '''

## Revision 3 — focused CEO correction, ACTIVE

Read IN FULL F:\\CONVERT\\com.mt.mtxx.mtxx\\CONVERT2\\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt before work and every resume; expected SHA256 10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F. Also read AGENTS.md, Docs/rules.md, PROJECT_ERROR.md, ACQUIREMENTS.md, CEO plan, TASK_063_R2_79d93b4f_NEEDS_FIX.md and TASK_063_CEO_SOFTLIGHT_NUMERIC_ADDENDUM.md. Claim exact revision3 using controller before writes, record new lease/fence/read assertion honestly in 00_AUDIT_INDEX.md. R2 token1010 is revoked; R1/R2 scripts/reports frozen. Write only JSON R3 scopes; report RULES/REPORT/TASK_063_REPORT_R3. No product/P0 changes or permission reconfirmation.

Fix the six specific findings in the current review. Reuse valid original bytes and existing Ghidra bodies; do not rerun broad decompilation or attempt full lane recovery in this baseline task.

1. Enforce actual mfx prefix versus container, complete payload/declared size/CRC/flags/method checks; retain header and data bounds, payload hash/CRC and container identity in machine receipt. Current 44+prefix measurements are valid, but generator must actually check them. A small in-memory negative check must show a changed prefix or header CRC does not pass. Do not alter original inputs.
2. Capture command/start/end/exit, input/tool/output hashes and stdout/stderr for each proof. Keep ALL bytes used to derive bounded disassembly/arithmetic counts. Count instructions separately from text lines; intentional sample termination is PARTIAL. Failed readelf mfx is NOT_CHECKED with actual error, not an empty successful scan. Reuse R2 raw only with exact hash and explicit missing-receipt limits; rerun lightweight commands as needed. Hash Ghidra launcher; version comes from actual metadata/log.
3. Real own function target records require symbol/value/type/binding/Ndx, excluding UND imports, or a verified internal body entry with source anchor. Imports may be labeled external dependencies only. Choose bounded feature-relevant defined targets; where unresolved, say UNKNOWN and supply exact next caller/asset/loader search. Derive gap counts from enumerated gap records; no capped symbol count as gap total. Record actual historical body/log paths/hashes for all available SO, with NOT_CHECKED for uninspected relevance. Correct LayerFlow actual SHA def2dd35f987a96a336b84d53e9e09445a97194b480f0850560483d8ccc74ca2 /54954 lines. Preserve exact45 lane partition.
4. Critical proofs: actual APK XOR decoder output/hash/line receipt, exact rational SoftLight comparison, actual native float dumps and body consumers, Aurora raw disassembly. R2 W3C0.134765625 and printed float/hex are correct; do not change them to earlier wrong CEO value. Retain literal shader formula without unsupported named equivalence. CMTFilterSoftHair::FilterToFBO entry GhidraVA0x2344e8, not callsite0x234724. File/RVA/Ghidra address translation needs relevant ELF mapping, not universal fileoffset equivalence. Material defaults/order/producer remain UNKNOWN unless traced.
5. C5 exact scan scope/counts must derive from retained output. readelf symbol-name/text search is not entire-binary/model-architecture proof; failed inputs are NOT_CHECKED. Model asset presence is OBSERVED with actual hashes. Production loader/model/confidence execution graph UNKNOWN until recovered. Classify download-interruption cause INFERRED/UNKNOWN. Preserve superseded059/060 and NEEDS_FIX062; carry prior001/003/004 and T3 gaps precisely.
6. Reuse owned minute heartbeat; no duplicate registration. Record actual native run IDs/status/error/scan evidence, distinguish API/CLI listing mismatch, timeout/restart failures and busy ticks from successful scans. Continue authorized research when runtime works; report a real outage honestly.

Publish a coherent R3 package with the same deliverable names, measured provenance and current revision3 COMPLETE.json; PROGRESS.json only on real milestones. All critical claims and >=5/45 ordinary records will be independently reviewed. TASK_064A..G remain PLANNED pending acceptance. Submit REVIEW_CANDIDATE_AWAITING_CEO before owned-branch commit/push and return to60s scanner. This is the final bounded baseline correction within max_fix_cycles3; unresolved tool/input limits should be explicit, not concealed or retried endlessly.
'''
    tmp = r / '.ai/locks.ceo.task063r3.tmp'
    c.authorized(c.ceo_lease(registry), task)
    c.authorized(c.ceo_lease(registry), tmp)
    with tmp.open('w', encoding='utf-8', newline='\n') as stream:
        stream.write(raw); stream.flush(); os.fsync(stream.fileno())
    assert file_sha(task) == current['_task_sha']
    os.replace(tmp, task)
    updated = json.loads(json.dumps(registry))
    old = next(x for x in updated['active_locks'] if x['lease_id']=='LEASE-CEO-WORKER-TASK_063-R2')
    assert old['fencing_token']==1010
    old.update(status='REVOKED', expiry=iso(c.clock()), released_at=iso(c.clock()),
               release_reason='R2 NEEDS_FIX; snapshot retained; separate R3 correction scope')
    updated['revision'] = registry.get('revision',0)+1
    c.replace_json(c.registry, updated, registry)
    registry.clear(); registry.update(updated)
    state['claims']['TASK_063:r2'].update(expiry=0,status='REVOKED',closure='R3_CORRECTION_HANDOFF')
    c.event(state,'CEO_TASK_REVISION_ISSUED','TASK_063',revision=3,task_file=current['_path'],
            report_folder=meta['report_folder'],previous_fingerprint=verdict['fingerprint'],review_file=verdict['review_file'])
    print(json.dumps({'task':'TASK_063','revision':3,'task_sha256':file_sha(task),'archive_files':len(hashes),'old_lease':'REVOKED'}))
