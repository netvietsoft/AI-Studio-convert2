# TASK_180 R1 - MTGif two unresolved C-like exports

STATUS: ACTIVE
ASSIGNEE: /root/so45_pvg_renderer
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T09:17:48.417200Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_180",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/so45_pvg_renderer",
  "agent_id": "/root/so45_pvg_renderer",
  "priority": "P1",
  "dependencies": [
    {
      "task_id": "TASK_177",
      "revision": 1
    }
  ],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_180_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_180_REPORT_R1/**",
    "scripts/task_180_codex_exports/**",
    "RESEARCH_WORK/TASK_180_R1/**"
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
  "max_minutes": 70,
  "max_cpu": 1,
  "max_heap": "1G",
  "max_report_bytes": 134217728,
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_180-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libMTGif.so": {
      "sha256": "a896d526a7ee74611ffd9a611b797c65505e60b4c60ff27fab75ecabbe69a134",
      "expected_unique_export_vas": 104
    }
  },
  "target_exports": [
    {
      "elf_va": "0xa1f0",
      "size_bytes": 636,
      "symbol": "get_nearest_index",
      "source_body_sha256": "409a09257a0ff81ba16cd60d5f93a58e0c9958d80e64fecbfeff91961157c101"
    },
    {
      "elf_va": "0xaf70",
      "size_bytes": 1452,
      "symbol": "_ZN11CMTImageGif12DecreaseBpp2EPv",
      "source_body_sha256": "ddf810863bebba50608b23ed2ebd85303ea37db4386eb842f08d060b9a3ff3ab"
    }
  ],
  "authorization_reference": "Chairman Tony directs real Codex subagents in parallel to finish remaining SO45 functions without AGY",
  "created_at": "2026-10-13T09:17:48.417200Z",
  "budget_deadline_utc": "2026-10-13T10:27:48.417200+00:00"
}
```

Recover only the two pinned libMTGif.so exports lacking C-like after TASK_177 and the unsuccessful TASK_154 normalize pass. First verify original SO, ELF symbol/body/PT_LOAD hashes and exact historical raw failure. Use a genuinely different bounded method, such as source-anchored CFG/p-code decomposition and at most one synthetic-region decompiler attempt per target in a hash-verified copied analyzed project. Run heavy Ghidra processes sequentially with one CPU and 1 GiB, <=180 seconds per process. Preserve entry-register context limitations. If no whole-original C-like is recovered, report exact verified fragments and unresolved semantic edges as PARTIAL. Do not reprocess the other 102 MTGif exports or call a synthetic fragment whole-function C-like.

Before any write, fully read the F: root canonical Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt and verify SHA-256 10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F. Read AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task, config/state, locks, END flag, and git status. Claim this exact ACTIVE revision using your assignee ID and expected lease before writing. Write only files_allowed. Keep original SOs, prior reports and analyzed projects read-only. Report 00_AUDIT_INDEX, 01_MASTER_REPORT, exact raw source/command/log/result evidence, PROGRESS and sealed COMPLETE.json with a complete byte-hash manifest. Check every critical claim and >=10% spread ordinary provenance. Distinguish source-byte, assembly, Ghidra C-like and verified behavior coverage. No AGY, further subagents, P0/product edits, Phase PASS, V4/P7, self-review, commit or push before independent CEO review. Stop at the absolute deadline and mark PARTIAL truthfully if a gap remains.
