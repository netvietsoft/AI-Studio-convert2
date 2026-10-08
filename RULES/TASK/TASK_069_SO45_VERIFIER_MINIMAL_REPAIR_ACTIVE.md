# TASK069 - minimal SO45 verifier repair before any new baseline
STATUS: ACTIVE
ASSIGNEE: 7de71900-89f8-4633-97a9-3efaf42ea6b8
MODIFIED_TIME: 2026-10-08T06:55:18.583768+00:00

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_069",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "7de71900-89f8-4633-97a9-3efaf42ea6b8",
  "agent_id": "7de71900-89f8-4633-97a9-3efaf42ea6b8",
  "priority": "P0",
  "mode": "RESEARCH",
  "design_impact": "NONE",
  "dependencies": [
    {
      "task_id": "TASK_067",
      "revision": 3
    }
  ],
  "report_folder": "RULES/REPORT/TASK_069_REPORT_R1",
  "files_allowed": [
    "scripts/so45_verifier_v1/**",
    "RULES/REPORT/TASK_069_REPORT_R1/**"
  ],
  "files_forbidden": [
    "app/**",
    "lib-*/**",
    "RULES/TASK/**",
    "scripts/task063*/**",
    "scripts/task067*/**",
    "RULES/REPORT/TASK_063*/**",
    "RULES/REPORT/TASK_067*/**",
    ".ai/reconstruction/evidence/**",
    ".ai/reconstruction/reference_sources/**",
    ".ai/reconstruction/ledger.json",
    ".ai/ceo/**",
    ".ai/state.json",
    "AGENTS.md",
    "PROJECT_ERROR.md",
    "ACQUIREMENTS.md"
  ],
  "max_fix_cycles": 1,
  "max_minutes": 30,
  "authorization_reference": "Chairman Tony authorized SO45-to-V4 CEO coordination; separately recorded diagnostic-supported minimal verifier repair disposition",
  "native_session_id": "01a119f1-f400-7441-8b7a-26375ae0f459",
  "claim_binding_required": true,
  "execution_engine": "codex/gpt-6.1-sol",
  "baseline_replacement_authorized": false,
  "derived_from_review": ".ai/ceo/reviews/TASK_067_R3_c6c44e94_ACCEPTED.md",
  "execution_mode": "ONE_ACTUAL_CODEX_WORKER_UNDER_AGY_COORDINATION_WITH_REAL_INDEPENDENT_REVIEW"
}
```

Before assignment/resume READ IN FULL F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt; measured SHA25610968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F. Read AGENTS.md, Docs/rules.md, PROJECT_ERROR.md, ACQUIREMENTS.md, CEO plan, exact task, TASK067 R3 full report/review/raw/provenance and TASK063 R3 NEEDS_FIX review. Claim exactTASK069 R1 with privately supplied binding token and actual actor/native session. Record actual read path/hash/time and valid lease/fence in00_AUDIT_INDEX.md. Only JSON files_allowed writes. Task063 exhausted correction route and all old evidence/scripts remain immutable. One attempt, max30minutes from actual first claim, max_fix_cycles1; no budget reset or automatic new baseline.

## Scope — implement only diagnosed verifier modules
1. Build pure source-input classifier for actual STORED/flags0 local-header cases. One function must be used by both public module entry point and regression tests. Require bounded header/data coordinates, supported flags/method, consistent csize/usize, real payload-vs-disk bytes equality, exact sizes and complete CRC before EXACT_PAYLOAD_MATCH. For available partial tail require matching prefix and explicit declared/available/deficit sizes; full CRC/tail UNKNOWN. Changed partial CRC cannot prove corruption without tail. Reject unsupported ZIP compression/data descriptors and malformed/bounds cases honestly; no general ZIP support claim.
2. Build parser matching actual retained --no-show-raw-insn AArch64 address/mnemonic format. Keep text-line/instruction/arithmetic counts separate, record sample bounds, reject malformed/noninstruction examples. Unsupported syntax/opcodes must be explicit, never infer whole-library arithmetic absence from bounded zero. Expose pure parser API for the later baseline generator; do not modify old producer.
3. Build small command-receipt runner for authorized read-only tools: actual argv/cwd, input/tool path/size/hash, UTC start/end, exit, full retained stdout/stderr bytes and hashes, explicit retention/encoding/line policy. Prevent shell/script injection or unrelated writes. Preserve full raw command outputs before any sampled view; bind both complete raw and retained sample transformations. Do not invent receipt data for old commands. Demonstrate one actual lightweight llvm-readelf control with captured bytes/time/exit under own report; no heavy native analyses.
4. Build literal APK-asset evidence extractor with APK/entry/encrypted/decoded bytes/hashes and exact line anchors for C2 and exact asset/model listing. Literal quotations must originate from bytes, algebra outside quote. Manis symbol count separates defined_nonzero303 from keyword_hits288 on verified retained source; no runtime architecture/producer inference. Historical Ghidra0x2344e8 remains text identifier; image-base/ABI/body-to-current-native mappingUNKNOWN. Do not import/decompile or call pointers.

## Meaningful validation, not implementation-mirroring tests
Independently bind existing original raw fixtures before use. Reproduce all14 measured header/payload/CRC counterexamples and five real1500-line samples fromTASK067. Expected outcomes sourced independently from reviewed original bytes/diagnostic; module must reject actual corrupt complete payload, modified CRC/flags/method/size and partial-prefix corruption while preserving partial-fullCRC UNKNOWN. Include demonstrated seven malformed parser cases and truncated-header/data bounds. Verify exact decoded C2 literal bytes and NE.manis real path/hash; missing invented path stays absent. Check receipt capture by independently hashing actual control stdout/stderr and checking tool/input digests/actual timing/exit. Keep historical raw times honest. Do not import or invoke old mutating producers. Do not run full45SO baseline, lane regeneration, full objdump/decompile, app build/device tests or source/upstream code. No PhasePASS or baseline acceptance claim.

## Output and gate
Own source modules/tests/scripts only scripts/so45_verifier_v1/**. RULES/REPORT/TASK_069_REPORT_R1 contains00audit,01master, module contract/spec, actual validation commands/raw outputs/receipts, fixture/input/code hash bindings, PROGRESS milestones, COMPLETE2.1.2 frozen manifest and explicit untested/UNKNOWN limits. Initial links to raw/harness_history.txt must use real file; no missing alias. Full implementation and all critical checks need independent review after>=60s stable. No commit/push before CEO review; reviewed ownedbranch publication only, unrelated workspace untouched. Task69 acceptance is tooling gate ONLY: does not accept063 or satisfy064/065/066/V4 dependencies. A future fresh baseline needs separately explicitCEOrecoverytask/disposition; this task cannot self-open it. Return existing scanner after task or block; no duplicate heartbeat.
