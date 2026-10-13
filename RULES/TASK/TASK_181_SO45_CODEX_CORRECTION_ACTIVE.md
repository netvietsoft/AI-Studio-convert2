# TASK_181 R1 - FFmpeg two unresolved NEON C-like exports

STATUS: ACTIVE
ASSIGNEE: /root/so45_ai_model_search
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T09:17:48.417200Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_181",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/so45_ai_model_search",
  "agent_id": "/root/so45_ai_model_search",
  "priority": "P1",
  "dependencies": [
    {
      "task_id": "TASK_173",
      "revision": 1
    }
  ],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_181_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_181_REPORT_R1/**",
    "scripts/task_181_codex_exports/**",
    "RESEARCH_WORK/TASK_181_R1/**"
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
  "max_minutes": 75,
  "max_cpu": 1,
  "max_heap": "1G",
  "max_report_bytes": 134217728,
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_181-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libffmpeg.so": {
      "sha256": "d8df8c5cb7a6b5a7eb771782d74a38e0b8d3cfacd1fbef1ae67a96171e3325c9",
      "original_unique_export_vas": 2461
    }
  },
  "target_exports": [
    {
      "elf_va": "0x658fe8",
      "source_body_sha256": "94017dc1deb91f10d8a4fd18f131f5d7741d0512c73c533de6d9845fbe095cee",
      "historical_index": 2283
    },
    {
      "elf_va": "0x65aea8",
      "source_body_sha256": "0b7e289d57ad0368923c5a802869b755b47eb70e43ff290fcd1096388ca46439",
      "historical_index": 2330
    }
  ],
  "authorization_reference": "Chairman Tony directs real Codex subagents in parallel to finish remaining SO45 functions without AGY",
  "created_at": "2026-10-13T09:17:48.417200Z",
  "budget_deadline_utc": "2026-10-13T10:32:48.417200+00:00"
}
```

Research only the two pinned libffmpeg.so NEON exports left without C-like by accepted TASK_173. Verify source/body/PT_LOAD and historical p-code/normalize receipts first. Do not repeat the same normalize pass or reprocess the other FFmpeg exports. Try a different bounded source-grounded route: isolate vector/basic-block fragments in a byte-verified copied project, at most one alternative decompiler pass per target <=180 seconds/process, one CPU/1 GiB, sequentially. Anchor every recovered fragment and remaining edge to original instruction VAs and label synthetic-context variables. If no whole-original C-like results, retain exact assembly/p-code and mark PARTIAL; never infer behavioral or pixel equivalence.

Before any write, fully read the F: root canonical Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt and verify SHA-256 10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F. Read AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task, config/state, locks, END flag, and git status. Claim this exact ACTIVE revision using your assignee ID and expected lease before writing. Write only files_allowed. Keep original SOs, prior reports and analyzed projects read-only. Report 00_AUDIT_INDEX, 01_MASTER_REPORT, exact raw source/command/log/result evidence, PROGRESS and sealed COMPLETE.json with a complete byte-hash manifest. Check every critical claim and >=10% spread ordinary provenance. Distinguish source-byte, assembly, Ghidra C-like and verified behavior coverage. No AGY, further subagents, P0/product edits, Phase PASS, V4/P7, self-review, commit or push before independent CEO review. Stop at the absolute deadline and mark PARTIAL truthfully if a gap remains.
