# TASK_063 — SO45 input truth, evidence baseline and research dispatch
STATUS: ACTIVE
ASSIGNEE: AGY_LEAD
PRIORITY: P0
MODIFIED_TIME: 2026-10-08T04:52:16.053278+00:00

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_063",
  "revision": 3,
  "status": "ACTIVE",
  "assignee": "AGY_LEAD",
  "agent_id": "ace29908-a2b0-4777-a070-6bd100509738",
  "priority": "P0",
  "mode": "RESEARCH",
  "design_impact": "NONE",
  "dependencies": [],
  "report_folder": "RULES/REPORT/TASK_063_REPORT_R3",
  "files_allowed": [
    "scripts/task063_r3/**",
    ".ai/reconstruction/evidence/TASK_063_R3/**",
    "RULES/REPORT/TASK_063_REPORT_R3/**",
    "F:/TOOLS/ghidra_projects/TASK_063_R3/**"
  ],
  "files_forbidden": [
    "app/**",
    "lib-*/**",
    "RULES/TASK/**",
    "RULES/REPORT/TASK_059_REPORT/**",
    "RULES/REPORT/TASK_060_REPORT/**",
    "RULES/REPORT/TASK_061_REPORT/**",
    "RULES/REPORT/TASK_062_REPORT/**",
    ".ai/state.json",
    "AGENTS.md",
    "scripts/task063/**",
    "RULES/REPORT/TASK_063_REPORT/**",
    "scripts/task063_r2/**",
    "RULES/REPORT/TASK_063_REPORT_R2/**",
    ".ai/reconstruction/evidence/TASK_063_R2/**"
  ],
  "max_fix_cycles": 3,
  "related_error_ids": [
    "ERR-010",
    "ERR-013",
    "ERR-014"
  ],
  "authorization_reference": "Chairman Tony appoints Codex CEO and authorizes AGY SO45 research toward V4, user instruction 2026-10-08",
  "correction_review": ".ai/ceo/reviews/TASK_063_R2_79d93b4f_NEEDS_FIX.md",
  "supersedes_revision": 2
}
```

## Mandatory startup — applies to every worker and resume

Read IN FULL `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`; SHA-256 must be `10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F`. Record path, measured hash, actual read timestamp, worker identity and lease fencing token in 00_AUDIT_INDEX.md. Also read AGENTS.md, Docs/rules.md, PROJECT_ERROR.md, ACQUIREMENTS.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, the project status audit and copied reviewer 001/003/004. Do not run work before understanding acceptance and obtaining the exact scope lease through CEO controller. ACTIVE means authorized; no reconfirmation to Tony.

## Purpose

Establish a trustworthy starting point for exhaustive, bounded research of the 45 native SO actually available on disk. Correct unsupported historical claims without altering historical evidence. Produce exact per-library assignments/targets so next lanes can recover bodies, pixel math, parameter sources and real cross-library edges. No production changes and no V4 PASS claim.

Inputs are read-only: `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\`; full package directory SOURCE/input_full if present; sibling APK/source files already authorized in TASK_061; `.ai/reconstruction/evidence/TASK_061`; older reports as historical sources. CEO supplied TASK_063_INPUT_BASELINE.csv is an independently measured comparison, not a substitute for re-reading binary bytes. No unofficial APK download or private vendor API/model fetch.

## Work

1. Re-enumerate 45 SO with canonical path, size, actual SHA-256, ELF class/machine, program/section bounds, tool exit status. Compare with full ZIP/APK central-directory declared sizes where the container is available. Identify truncation explicitly; libmfxkit.so is suspected truncated and must not be silently called valid. Check input_full and absent libmtImageKit.so/MTAiInterface/vlai without inventing missing symbols. If count differs, report actual set delta.
2. Verify installed Ghidra/JDK/LLVM/spirv tools by invoking version commands and recording executable paths/hashes. Reuse earlier real decompilation and logs with hash binding; classify legacy skeletons/generated placeholders as such. Do not rerun all libraries just to create counts.
3. Compare each library with previous coverage: true function bodies, disassembly, xrefs/JNI registration, shader/model assets, existing hashes. For every SO record current depth and precise remaining relevant targets. `has_arithmetic` must be based on actual body operations, never size/name. System/open-source libraries require verified identity/role/boundary, not fabricated vendor algorithms.
4. Inspect at least five critical existing claims: mask exclusion channel+output alpha, SoftLight formula, blur sampling offsets, hair material config->native ordering, confidence/segmentation source. Each claim needs actual path/hash + lib/address or asset offset + full reproducible command/raw log + OBSERVED/INFERRED/UNKNOWN. Reject unsupported defaults; missing T1 remains BLOCKED.
5. Provide seven non-overlapping lane input lists matching TASK_064A..G and selection of feature-relevant exported/internal functions for deep recovery. Selection should cover render/kernel/AI+NPU/color+LUT/image/video/runtime/security boundaries of all 45 SO; do not skip non-hair libraries silently. Give stop conditions, unresolved counts and next investigation per target.
6. Register or reuse an AGY minute heartbeat in this AGY session via `paseo heartbeat create --cron '* * * * *' --timezone Asia/Bangkok --name 'AGY SO45 task scanner' <prompt>` after checking existing owned heartbeat records; prompt is `.ai/ceo/AGY_SCAN_PROMPT.txt`. No max-runs/expiry unless Tony instructs. Record receipt ID/cadence/target/status and actual scan timestamps. Do not use reviewer heartbeat, busy ticks or Actions PID as successful AGY delivery. If runtime cannot register it, report exact error, continue research under CEO dispatch; CEO supplies a fallback supervisor.

## Deliverables — RULES/REPORT/TASK_063_REPORT_R3/

- 00_AUDIT_INDEX.md — rule receipt, input/tool hashes, commands, worker lease.
- 01_MASTER_REPORT.md — actual findings, corrections to 059/060/061/062 claims, residual blockers and readiness for each next lane.
- 02_SO45_INPUT_MANIFEST.csv — exactly actual library set; size/hash/ELF/container completeness and status.
- 03_EXISTING_EVIDENCE_AUDIT.csv — body/disassembly/xref/shader provenance per SO; quality and gap; no arbitrary completeness percentage.
- 04_SO45_LANE_ASSIGNMENTS.csv — exact one lane per library plus address/asset target list and priorities.
- 05_CRITICAL_CLAIM_CHECKS.md — five+ checks with evidence anchors and confidence.
- 06_TOOLCHAIN_AND_HEARTBEAT_RECEIPTS.json — actual commands/exits and scheduler receipt; scheduler registration and delivery distinguished.
- raw/ — unedited stdout/stderr command logs with start/end/exit and input hashes, generated by actual executions.
- PROGRESS.json — task_id/revision/agent_id/lease/stage/observed counts/last command/blockers; update at actual milestones, roughly 60s during long tools. Do not synthesize progress or promise an artificial ETA.
- COMPLETE.json — frozen artifact hash map plus scripts code_files as defined in the plan; status COMPLETE means review candidate, not acceptance.

## Acceptance / gates

All 45 actual inputs accounted for once; integrity failures and missing binaries explicit. Every observed claim resolves to actual input->command->raw output->anchor. Critical claim corrections independently reproducible. No placeholder/decompiler theatre, no false body arithmetic or unsupported percentages. CEO rechecks all critical claims and >=10% ordinary inventory/provenance before accepting this research baseline. Product/device acceptance is not required for this input/research task and must not be claimed. V4 remains gated.

Before write: `python -X utf8 -B .ai/ceo/controller.py claim --task-id TASK_063 --agent-id ace29908-a2b0-4777-a070-6bd100509738 --standard-sha <measured lowercase SHA>` (when controller is installed). Renew the same claim/lease during tools and at each resume. CEO owns global state/registry; do not directly edit legacy .ai/state.json. Publish REVIEW_CANDIDATE_AWAITING_CEO first; CEO audit then gives commit/push disposition. Commit only task-owned new paths on `agent/agy/TASK_063` or isolated research branch, never main; preserve all unrelated deletions/untracked evidence. After report, return immediately to exact task scanner; wait around 60s when no eligible task.



## Revision 3 — focused CEO correction, ACTIVE

Read IN FULL F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt before work and every resume; expected SHA256 10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F. Also read AGENTS.md, Docs/rules.md, PROJECT_ERROR.md, ACQUIREMENTS.md, CEO plan, TASK_063_R2_79d93b4f_NEEDS_FIX.md and TASK_063_CEO_SOFTLIGHT_NUMERIC_ADDENDUM.md. Claim exact revision3 using controller before writes, record new lease/fence/read assertion honestly in 00_AUDIT_INDEX.md. R2 token1010 is revoked; R1/R2 scripts/reports frozen. Write only JSON R3 scopes; report RULES/REPORT/TASK_063_REPORT_R3. No product/P0 changes or permission reconfirmation.

Fix the six specific findings in the current review. Reuse valid original bytes and existing Ghidra bodies; do not rerun broad decompilation or attempt full lane recovery in this baseline task.

1. Enforce actual mfx prefix versus container, complete payload/declared size/CRC/flags/method checks; retain header and data bounds, payload hash/CRC and container identity in machine receipt. Current 44+prefix measurements are valid, but generator must actually check them. A small in-memory negative check must show a changed prefix or header CRC does not pass. Do not alter original inputs.
2. Capture command/start/end/exit, input/tool/output hashes and stdout/stderr for each proof. Keep ALL bytes used to derive bounded disassembly/arithmetic counts. Count instructions separately from text lines; intentional sample termination is PARTIAL. Failed readelf mfx is NOT_CHECKED with actual error, not an empty successful scan. Reuse R2 raw only with exact hash and explicit missing-receipt limits; rerun lightweight commands as needed. Hash Ghidra launcher; version comes from actual metadata/log.
3. Real own function target records require symbol/value/type/binding/Ndx, excluding UND imports, or a verified internal body entry with source anchor. Imports may be labeled external dependencies only. Choose bounded feature-relevant defined targets; where unresolved, say UNKNOWN and supply exact next caller/asset/loader search. Derive gap counts from enumerated gap records; no capped symbol count as gap total. Record actual historical body/log paths/hashes for all available SO, with NOT_CHECKED for uninspected relevance. Correct LayerFlow actual SHA def2dd35f987a96a336b84d53e9e09445a97194b480f0850560483d8ccc74ca2 /54954 lines. Preserve exact45 lane partition.
4. Critical proofs: actual APK XOR decoder output/hash/line receipt, exact rational SoftLight comparison, actual native float dumps and body consumers, Aurora raw disassembly. R2 W3C0.134765625 and printed float/hex are correct; do not change them to earlier wrong CEO value. Retain literal shader formula without unsupported named equivalence. CMTFilterSoftHair::FilterToFBO entry GhidraVA0x2344e8, not callsite0x234724. File/RVA/Ghidra address translation needs relevant ELF mapping, not universal fileoffset equivalence. Material defaults/order/producer remain UNKNOWN unless traced.
5. C5 exact scan scope/counts must derive from retained output. readelf symbol-name/text search is not entire-binary/model-architecture proof; failed inputs are NOT_CHECKED. Model asset presence is OBSERVED with actual hashes. Production loader/model/confidence execution graph UNKNOWN until recovered. Classify download-interruption cause INFERRED/UNKNOWN. Preserve superseded059/060 and NEEDS_FIX062; carry prior001/003/004 and T3 gaps precisely.
6. Reuse owned minute heartbeat; no duplicate registration. Record actual native run IDs/status/error/scan evidence, distinguish API/CLI listing mismatch, timeout/restart failures and busy ticks from successful scans. Continue authorized research when runtime works; report a real outage honestly.

Publish a coherent R3 package with the same deliverable names, measured provenance and current revision3 COMPLETE.json; PROGRESS.json only on real milestones. All critical claims and >=5/45 ordinary records will be independently reviewed. TASK_064A..G remain PLANNED pending acceptance. Submit REVIEW_CANDIDATE_AWAITING_CEO before owned-branch commit/push and return to60s scanner. This is the final bounded baseline correction within max_fix_cycles3; unresolved tool/input limits should be explicit, not concealed or retried endlessly.
