import pathlib,json,csv,io,importlib.util,sys
sp=importlib.util.spec_from_file_location('m',pathlib.Path(__file__).with_name('search.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m);claim=m.guard()
a=json.loads((m.REPORT/'02_CANDIDATES.json').read_text());b=json.loads((m.REPORT/'06_RETAINED_HEADER_DISCOVERY.json').read_text());inv=json.loads((m.REPORT/'03_INVENTORY.json').read_text());v=json.loads((m.REPORT/'07_VERIFICATION.json').read_text())
allc=a['candidates']+b['candidates'];sources={r['path']:r for r in inv if 'sha256_before' in r}
for r in b['sources']:sources[r['path']]=dict(r,size=pathlib.Path(r['path']).stat().st_size)
for c in allc:
 p=c['container'] or c['source_path'];sr=sources[p];c.update(source_bytes=sr['size'],source_sha256_before=sr['sha256_before'],source_sha256_after=sr['sha256_after'],role='ORIGINAL_COMPARISON' if p.startswith('F:\\CONVERT') else 'BOUNDED_SEARCH_CANDIDATE',app_version='UNKNOWN; filename is not version evidence')
counts=dict(files=sum(r['kind'] not in ('directory','reparse') and 'size' in r for r in inv),directories=sum(r['kind']=='directory' for r in inv),physical_archives=sum(r['kind']=='archive' and 'size' in r for r in inv),readable_archive_directories=sum(r.get('status')=='directory_read' for r in inv),archive_entries=a['archive_entry_count'],reparse_exclusions=sum(r['kind']=='reparse' for r in inv))
summary=dict(schema_version='2.1.2',task_id='TASK_073',revision=1,agent_id=m.ACTOR,native_session_id=m.NATIVE,fencing_token=1021,task_sha256=m.TASKSHA,diagnostic_status='BOUNDED_DIAGNOSTIC_COMPLETE',conclusion='NO_COMPATIBLE_INPUT_IN_OBSERVED_CONTENT',coverage_status='INCOMPLETE_CONTAINER_COVERAGE',coverage_complete=False,candidates=allc,unique_payloads=len({c['payload_sha256'] for c in allc}),original=a['original'],declared_original=v['original_local_header'],errors=a['errors'],limitations=['Damaged XAPK lacks readable central directory; missing tail contents UNKNOWN.','Outer stored APK local headers use data descriptors; sequential parser explicitly stops. Supplementary signature discovery records physical offsets, not whole nested ZIP membership.','No app version inferred from filenames; no full positive same-build input.','Only task container extensions inspected; depth cap8 and payload cap1GiB not hit.'],counts=counts,finalized_at=m.now(),review_status='REVIEW_CANDIDATE_AWAITING_CEO')
m.js(m.REPORT/'08_FINAL_RESULTS.json',summary)
fields=['id','role','source_path','container','entry','source_bytes','source_sha256_before','source_sha256_after','payload_bytes','payload_sha256','payload_crc32','classification','all_retained_prefix_equal','original_declared_size_match','original_declared_crc_match']
out=io.StringIO();w=csv.DictWriter(out,fields,extrasaction='ignore');w.writeheader();w.writerows(allc);m.write(m.REPORT/'08_FINAL_CANDIDATES.csv',out.getvalue())
std=m.ROOT/'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt';assert m.filehash(std)==m.STANDARD
rules=['AGENTS.md','Docs/rules.md','.ai/ceo/SO45_TO_V4_PLAN.md','.ai/ceo/config.json','RULES/TASK/TASK_073_MFXKIT_COMPLETE_INPUT_SEARCH_ACTIVE.md','PROJECT_ERROR.md','ACQUIREMENTS.md']
m.js(m.REPORT/'09_PROVENANCE.json',dict(schema_version='2.1.2',task_id='TASK_073',revision=1,actor=m.ACTOR,native=m.NATIVE,fence=1021,claim=claim,canonical=dict(path=str(std),sha256=m.filehash(std),lines=len(std.read_text(encoding='utf-8-sig').splitlines()),full_read_ack=True,read_at=claim['standard_read_ack']['acknowledged_at']),rule_hashes={p:m.filehash(m.ROOT/p) for p in rules},python=dict(path=sys.executable,sha256=m.filehash(sys.executable)),execution_mode='ONE_ACTUAL_CODEX_WORKER_UNDER_AGY_COORDINATION',original_source_unchanged=m.filehash(m.ORIGINAL)==a['original']['sha256_before'],input_sources=sources))
audit=f'''# TASK_073 R1 audit index

Status: REVIEW_CANDIDATE_AWAITING_CEO. Diagnostic only; no product/phase PASS.

Actual actor: {m.ACTOR}. Native CODEX_THREAD_ID: {m.NATIVE}. Real Codex fallback under CEO/AGY coordination; Antigravity unavailable as dispatch states. No simulated agents or heartbeat.

Entire canonical read again during intake, all3953 lines, before claim:
`{std}`
SHA-256: `{m.STANDARD}`.
Full-read acknowledgment: {claim['standard_read_ack']['acknowledged_at']}.
Task SHA: `{m.TASKSHA}`. Lease LEASE-CEO-WORKER-TASK_073-R1, fence1021, first acquisition2026-10-09T02:07:38.810192Z, deadline2026-10-09T02:27:38.810166Z. Config/native/lease/hash checked before owned writes. Private token absent from artifacts.

Read AGENTS.md, Docs/rules.md, SO45_TO_V4_PLAN.md, config and operational state; relevant original diagnostic/review context; searched PROJECT_ERROR/ACQUIREMENTS mfx/truncation/CRC with no matches. Hashes in09_PROVENANCE.json. Branch preexisting agent/agy/TASK_062; no branch mutation, staging or commit. Unrelated existing deletions left untouched.

Evidence:08_FINAL_RESULTS.json and08_FINAL_CANDIDATES.csv consolidated;03_INVENTORY.json enumerated paths;04_ARCHIVE_ENTRIES.json readable entries;05_LOCAL_ZIP_RECORDS.json explicit parser limits;06_RETAINED_HEADER_DISCOVERY.json physical header offsets;07_VERIFICATION.json direct remeasurement/negative controls;09_PROVENANCE.json input hashes; raw/ actual argv/cwd/time/exit/stdout/stderr/tool/script hashes; evidence/ three partial payload provenance copies; COMPLETE.json frozen manifest.

Reproduction (same live exact lease required; expired/revoked writes rejected): python -X utf8 -B scripts/task073_mfx_search/run_logged.py SCRIPT, with SCRIPT sequentially search.py,local_zip.py,retained_headers.py,verify.py,package.py. Then python -X utf8 -B scripts/task073_mfx_search/seal.py. No old generator executed.

Unchanged completed revision must not rerun. CEO stable fingerprint review pending; task output was not committed/pushed. Return to authorized task intake after report; never copy another actor identity/lease.
'''
m.write(m.REPORT/'00_AUDIT_INDEX.md',audit)
master=f'''# TASK_073 R1 bounded input search

No complete compatible libmfxkit.so found in observed content under F:/APP/Image/com.mt.mtxx.mtxx. Filesystem/readable archive search finished; damaged XAPK coverage remains incomplete. Completed bounded diagnostic does not establish exhaustive absence in missing archive bytes.

Loose search library and search XAPK local payload equal original773652-byte source prefix SHA-25678923a90997d34c5dd51215a6cd2bc26c9731806fd9037e4aa71fd3873d3bb4f. Original SOURCE XAPK comparison yields same bytes. Three provenance records, one unique payload; two search hits plus one comparison.

Direct original header at348392052, payload348402156: declared1354736 bytes/CRC0x4302c04c, retained773652 bytes/observedCRC0x6ffdb5ff, deficit581084. All773652 prefix bytes compared. Partial CRC cannot prove full declared CRC. No SAME_BUILD_FULL_PREFIX_AND_CRC_MATCH classification.

ELF64 little-endian machine183 AArch64. Program table retained but five file-backed segments exceed available bytes; section table offset1352944 size1792 absent. All candidates PARTIAL. Build-id/SONAME, safely available values, and every program/section bound in JSON. No different-build/other ABI candidate observed; versions cannot be mixed. App version UNKNOWN, not inferred from filename.

Coverage counts: {json.dumps(counts)}. These describe scope only. Task extensions APK/ZIP/APKS/XAPK/AAB and nested readable archives inspected. Reparse paths excluded without following. Both XAPK files349175808 bytes/hashdc896b5429cc3265c3d2639a38d4e76bbff3cf819cfe3b63b006048a7712c0d7; missing central directory triggers actual BadZipFile. Outer stored APK headers use data descriptors; sequential parser stops. Supplementary signature-header discovery measures exact target at physical offset, cannot prove whole nested ZIP membership or missing-tail contents. Caps depth8/1GiB did not limit readable directory coverage. Non-container files were name-inspected only.

Verification07: actual payload/hash/CRC/prefix and source-local-header assertions, bad-magic/truncated-header/mutated-prefix controls all held. llvm-readelf failure on original truncated input retained raw, never labeled success. Original SHA unchanged before/after; all hashed search inputs unchanged. Script syntax checked. First packaging command had Python quoting error before script creation; failure remains in the actual task tool response (no durable failed-command receipt), subsequently corrected within this same bounded attempt, no task budget/reset.

Build/device/UI/design gates not_required: diagnostic only, no production changes. Independent CEO review pending. No source replacement/download/native execution/decompile/Ghidra/product/P0/config changes/heartbeat/legacy runner/staging/unreviewed commit. PROJECT_ERROR/ACQUIREMENTS write forbidden; existing missing-input result repeated, no validated remedy to add.

Residual: complete authorized arm64 split or same-build library would need later task. Full bytes alone do not cure verifier bugs, libmtImageKit UNKNOWN, exhausted063/069, planned064/065/066, TASK062 real-device gate or V4. No acceptance or task reset.
'''
m.write(m.REPORT/'01_MASTER_REPORT.md',master);m.progress('Diagnostic packaged; CEO review pending',status='REVIEW_CANDIDATE_AWAITING_CEO',conclusion=summary['conclusion'],coverage_status=summary['coverage_status']);print(json.dumps(dict(conclusion=summary['conclusion'],counts=counts),indent=2))
