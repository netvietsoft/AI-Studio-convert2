# TASK_063 — SO45 input truth, evidence baseline and research dispatch
STATUS: ACTIVE
ASSIGNEE: AGY_LEAD
PRIORITY: P0
MODIFIED_TIME: 2026-10-08T10:45:00+07:00

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_063",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "AGY_LEAD",
  "agent_id": "ace29908-a2b0-4777-a070-6bd100509738",
  "priority": "P0",
  "mode": "RESEARCH",
  "design_impact": "NONE",
  "dependencies": [],
  "report_folder": "RULES/REPORT/TASK_063_REPORT",
  "files_allowed": ["scripts/task063/**", ".ai/reconstruction/evidence/TASK_063/**", "RULES/REPORT/TASK_063_REPORT/**", "F:/TOOLS/ghidra_projects/TASK_063/**"],
  "files_forbidden": ["app/**", "lib-*/**", "RULES/TASK/**", "RULES/REPORT/TASK_059_REPORT/**", "RULES/REPORT/TASK_060_REPORT/**", "RULES/REPORT/TASK_061_REPORT/**", "RULES/REPORT/TASK_062_REPORT/**", ".ai/state.json", "AGENTS.md"],
  "max_fix_cycles": 3,
  "related_error_ids": ["ERR-010", "ERR-013", "ERR-014"],
  "authorization_reference": "Chairman Tony appoints Codex CEO and authorizes AGY SO45 research toward V4, user instruction 2026-10-08"
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

## Deliverables — RULES/REPORT/TASK_063_REPORT/

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
