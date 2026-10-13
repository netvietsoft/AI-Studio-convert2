# TASK_159 R1 - libdexvmp oversized-target correction

STATUS: ACTIVE
ASSIGNEE: /root/so45_dexvmp_correction
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T06:27:56.338034Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_159",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/so45_dexvmp_correction",
  "agent_id": "/root/so45_dexvmp_correction",
  "priority": "P1",
  "dependencies": [],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_159_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_159_REPORT_R1/**",
    "scripts/task159_codex_dexvmp_correction/**",
    "RESEARCH_WORK/TASK_159_R1/**"
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
    "packages/**",
    "RULES/REPORT/TASK_156_REPORT_R1/**"
  ],
  "max_minutes": 90,
  "max_cpu": 1,
  "max_heap": "1G",
  "max_report_bytes": 33554432,
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_159-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libdexvmp.so": {
      "sha256": "b4a46520ec989fef5346833db8f9a1bd6a6690902731414ed26f65cc529cc06e",
      "expected_unique_export_vas": 284
    }
  },
  "authorization_reference": "Chairman Tony explicitly requested Codex subagents and multi-lane 45-SO acceleration; AGY excluded",
  "created_at": "2026-10-13T06:27:56.338034Z",
  "budget_deadline_utc": "2026-10-13T07:57:56.338034+00:00"
}
```

Chairman authorizes a real Codex subagent, not AGY, to recover all 284 defined nonzero-size `.dynsym` STT_FUNC export VAs from the pinned original SO files only. Recheck each full source SHA-256, ELF/PT_LOAD mapping, VA and body hash. One fresh Ghidra import per source maximum; sequential bounded chunks of <=100 unique VAs plus one isolated 224,440-byte target at ELF VA 0x29cd4; one 1-CPU/1-GiB process at a time, <=15s per function, <=900s per process, <=3600s aggregate. No duplicate imports or retry within this revision. The TASK_156 report/project are READ-ONLY inputs; retain its failed log and distinguish source-body coverage from C-like coverage. Record raw command, stdout/stderr, result, C-like body and assembly evidence for each target. Stop at deadline and seal truthful PARTIAL on timeout/failure; preserve all verified source provenance.

Before any write, fully read `Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` at the F: root and verify its SHA-256 above; read AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task, config/state, locks, END flag and git status. Claim this exact ACTIVE revision with your assignee ID and lease. Write only files_allowed. Report 00_AUDIT_INDEX, 01_MASTER_REPORT, per-source raw logs/receipts, source/C manifests, PROGRESS and COMPLETE hash map. Recheck all critical claims and >=10% spread ordinary provenance. Distinguish exported-function static output from internal functions and validated behavior. No P0/product changes, Phase PASS, V4/P7, self-review, or commit/push before independent CEO review. Do not launch an AGY worker or another subagent.
