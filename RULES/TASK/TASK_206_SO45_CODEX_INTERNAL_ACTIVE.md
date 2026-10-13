# TASK_206 R1 - bounded libLayerFlow.so nonexport FDE research

STATUS: ACTIVE
ASSIGNEE: /root/so45_pvg_followon
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T13:39:28.505005Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_206",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/so45_pvg_followon",
  "agent_id": "/root/so45_pvg_followon",
  "priority": "P1",
  "dependencies": [],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_206_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_206_REPORT_R1/**",
    "scripts/task_206_codex_internal/**",
    "RESEARCH_WORK/TASK_206_R1/**"
  ],
  "files_forbidden": [
    "RULES/TASK/**",
    "SOURCE/**",
    ".ai/**",
    "app/**",
    "apps/**",
    "lib-*/**",
    "Backend/**",
    "services/**",
    "packages/**"
  ],
  "max_minutes": 90,
  "max_cpu": 1,
  "max_heap": "1G",
  "max_report_bytes": 134217728,
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_206-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libLayerFlow.so": {
      "sha256": "ef8d1581038778b72abca3ca8fd5046e49fd44e0465871b023647fe42a582262",
      "defined_nonzero_export_vas": 5082
    }
  },
  "target_manifest_path": ".ai/ceo/reviews/TASK_206_internal_targets.json",
  "target_manifest_sha256": "a36459181b71d193b2a73606a91e8d855c5ee32557ca211f4c9f7ea289fbb46d",
  "target_candidate_count": 128,
  "authorization_reference": "Chairman Tony direct Codex multi-lane remaining SO45 decoding without AGY",
  "created_at": "2026-10-13T13:39:28.505005Z",
  "modified_time": "2026-10-13T13:39:28.505005Z",
  "budget_deadline_utc": "2026-10-13T15:09:28.505005+00:00"
}
```

Process only the 128 exact zero-based nonexport FDE candidate indices in `.ai/ceo/reviews/TASK_206_internal_targets.json` SHA-256 `a36459181b71d193b2a73606a91e8d855c5ee32557ca211f4c9f7ea289fbb46d` from original `libLayerFlow.so` SHA-256 `ef8d1581038778b72abca3ca8fd5046e49fd44e0465871b023647fe42a582262`. Slice 0..127 contains 9,060 selected original bytes / 2,265 AArch64 instruction slots. No index in this slice exceeds 4,096 bytes. This is a new nonexport FDE lane on a different SO; no prior research gate is inferred. TASK_146 project is an UNREVIEWED technical cache only, never accepted evidence. Rehash all files and verify source/program identity before a private copy; if uncertain, use a fresh bounded headless import. No conclusion may rely on TASK_146 claims. Prior exclusions remain open. The cumulative selection is 128 of 3853 candidate starts, with 3725 unselected (3725 later indices plus 0 exclusions). This is a candidate-range census, not a count of recovered complete functions.

Use direct pyelftools/Capstone extraction for source mapping, all original bytes/instructions, branch sites and >=10% spread provenance. Use a bounded private Ghidra **headless** project with a persistent decompiler interface per Program where practical, not a GUI or bulk all-SO decompile. Rehash the `RESEARCH_WORK/TASK_146_R1/ghidra_project` technical input before a private copy; for TASK_206 it is unreviewed and a fresh bounded import is required if identity cannot be proven. Capture exact function-body membership, gaps/extra ranges, listing and p-code, C-like text/hash or failure, raw command/stdout/stderr and before/after project hashes. A C-like result or FDE start alone is not complete source/behavior. Mark ambiguous boundaries PARTIAL; transient correction only for proven nonoverlapping gaps, followed by fresh-session rollback and original memory proof. One CPU, 1 GiB heap, sequential <=20-minute headless jobs, <=10 seconds per decompile and the original deadline; seal truthful partial results if a row cannot be resolved. Do not claim all 45 SOs, functional/pixel parity, product Phase PASS, V4/P7 or a 3-minute daemon.

Before any write fully reread `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`, AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task/manifest, config/state/locks/END and git status. Claim exact ACTIVE TASK_206 R1 as `/root/so45_pvg_followon` via `LEASE-CEO-WORKER-TASK_206-R1` before any write. Write only `RULES/REPORT/TASK_206_REPORT_R1/**`, `scripts/task_206_codex_internal/**`, `RESEARCH_WORK/TASK_206_R1/**`; source SO, other research, P0 and product are read-only. Create `00_AUDIT_INDEX.md` canonical-read receipt, truthful `01_MASTER_REPORT.md`, raw per-candidate evidence, `PROGRESS.json`, and SHA-256 sealed `COMPLETE.json`. No AGY, further subagents, self-review, commit or push before CEO independent review. Stop by 2026-10-13T15:09:28.505005+00:00.
