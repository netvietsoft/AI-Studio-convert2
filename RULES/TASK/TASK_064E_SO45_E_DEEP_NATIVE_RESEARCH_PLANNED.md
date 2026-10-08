# TASK_064E ? Video, audio and codec pipelines
STATUS: PLANNED
ASSIGNEE: AGY_TEAM
PRIORITY: HIGH
MODIFIED_TIME: 2026-10-08T03:46:59.445217+00:00

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_064E",
  "revision": 1,
  "status": "PLANNED",
  "assignee": "AGY_TEAM",
  "priority": "HIGH",
  "mode": "RESEARCH",
  "design_impact": "NONE",
  "dependencies": [
    {
      "task_id": "TASK_063",
      "revision": 1
    }
  ],
  "report_folder": "RULES/REPORT/TASK_064E_REPORT",
  "files_allowed": [
    "scripts/task064e/**",
    ".ai/reconstruction/evidence/TASK_064E/**",
    "RULES/REPORT/TASK_064E_REPORT/**",
    "F:/TOOLS/ghidra_projects/TASK_064E/**"
  ],
  "files_forbidden": [
    "app/**",
    "lib-*/**",
    "RULES/TASK/**",
    ".ai/state.json",
    "AGENTS.md",
    "RULES/REPORT/TASK_061_REPORT/**",
    "RULES/REPORT/TASK_062_REPORT/**"
  ],
  "input_libraries": [
    "libffmpeg.so",
    "libffmpegfilter.so",
    "libffavc.so",
    "libPVGVideoCodec.so",
    "libPVGCodec.so",
    "libPVGLive.so",
    "libKKMusicFX.so",
    "libaicodec.so"
  ],
  "max_fix_cycles": 3,
  "authorization_reference": "Chairman SO45-to-V4 instruction 2026-10-08; CEO activation after verified TASK_063"
}
```

## Gate and mandatory startup

PLANNED is NOT execution authorization. Only CEO changes this to exact ACTIVE after dependency audit. Then every dispatch/resume/worker MUST read IN FULL `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`; expected SHA-256 `10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F`. Record actual path/hash/read timestamp and worker/lease token in 00_AUDIT_INDEX.md. Read AGENTS.md, Docs/rules.md, PROJECT_ERROR.md, ACQUIREMENTS.md, .ai/ceo/SO45_TO_V4_PLAN.md and accepted TASK_063 inventory/targets. Claim exact task/revision via controller; obey files_allowed, P0 frozen. Other lanes own other outputs. Maximum three heavy Ghidra analyses across campaign, isolated project path, no fabricated agents/PIDs.

## Assigned physical inputs and objective

Inputs read-only: F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a; exactly 8 SO:
- libffmpeg.so
- libffmpegfilter.so
- libffavc.so
- libPVGVideoCodec.so
- libPVGCodec.so
- libPVGLive.so
- libKKMusicFX.so
- libaicodec.so

Recover actual filter/codec/frame/audio interop and buffers/timestamps, render/filter reuse paths and integration boundaries relevant to future video effects. Distinguish open-source FFmpeg exports from vendor wrappers; no unsupported 4K/FPS/feature claim.

## Required depth

For every assigned library: verify SHA/ELF integrity against TASK_063; classify implementation vs known dependency/runtime/open-source boundary. Select feature-relevant function targets with actual addresses and caller/callee/JNI/DEX/asset evidence. Export REAL full decompiled function bodies plus disassembly/xrefs and raw headless tool logs. Distinguish function/data/vtable/string; has_arithmetic requires actual operations, not size/name. Recover parameter origins/defaults and branch/type/range/unit/stride/alpha/color-space behavior only when bodies/assets show them. Trace cross-library calls from JNI entry through native stages to output; unresolved indirect/virtual dispatch stays UNKNOWN with performed searches. Verify key calls by disassembly and raw shader/model consumer evidence. Do not label mere inventory/call skeleton as L5 recovery. Quarantine decoded third-party raw source under .ai/reconstruction/evidence, not product. Reuse existing body-backed evidence with provenance instead of rerunning duplicate binaries.

For valid standard libraries a justified VERIFIED_DEPENDENCY_BOUNDARY is permitted with identity, licensing/upstream provenance and exact wrapper consumers; no claim of vendor pixel math inside irrelevant libraries. For incomplete/unavailable inputs write PARTIAL/BLOCKED_INPUT with missing byte/target/path proof, and continue other assigned targets. No guessing, no fake numeric completion/quality score, no performance/product PASS.

## Deliverables ? RULES/REPORT/TASK_064E_REPORT

00_AUDIT_INDEX.md (rule/input/tool/lease receipts), 01_MASTER_REPORT.md (per-library status, discoveries, residual blockers), 02_FUNCTION_COVERAGE.csv (library,address,size,type,body_path+hash,arithmetic evidence,used_claim_id,status), 03_CROSS_LIBRARY_GRAPH.json (real edges/provenance/confidence), 04_ALGORITHM_OR_BOUNDARY_SPEC.md (formulas/contract/defaults, OBSERVED/INFERRED/UNKNOWN, anchor per claim), 05_GAP_AND_NEXT_TARGETS.csv, raw/ command logs (command/start/end/exit/input/output hashes). Include actual reproducible scripts under assigned script folder. For relevant math include independent synthetic impulse/step/random/boundary/reference parity checks reporting max/mean error and failures, clearly offline math, not product. PROGRESS.json at actual milestones/about60s for long tools; COMPLETE.json frozen hash map excluding volatile progress and itself, code_files includes generator scripts. Final verdict only REVIEW_CANDIDATE_AWAITING_CEO.

## Independent audit and continuation

CEO checks every critical algorithm/interface/default/input-integrity claim and >=10% ordinary cited function/edge records. All assigned SO accounted for, all claims resolve input->command->raw->anchor; selected target closure and residual unknowns explicit. Decompiler output count or true hash alone is insufficient. Gate approval precedes scoped branch commit/push. Record actual commit after it exists; no blanket git add, no unrelated deletions/restore. Research acceptance is not phase acceptance; no app/lib edits, no V4 implementation. On completion return scanner. CEO may issue targeted correction/revision for gaps, then integrate accepted lanes through TASK_065.
