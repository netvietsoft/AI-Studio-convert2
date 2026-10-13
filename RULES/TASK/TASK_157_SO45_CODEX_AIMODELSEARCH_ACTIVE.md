# TASK_157 R1 - AIModelSearchKit exported-function recovery

STATUS: ACTIVE
ASSIGNEE: /root/so45_ai_model_search
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T06:23:47.155592Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_157",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/so45_ai_model_search",
  "agent_id": "/root/so45_ai_model_search",
  "priority": "P1",
  "dependencies": [],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_157_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_157_REPORT_R1/**",
    "scripts/task157_codex_aimodelsearch/**",
    "RESEARCH_WORK/TASK_157_R1/**"
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
  "max_minutes": 120,
  "max_cpu": 1,
  "max_heap": "1G",
  "max_report_bytes": 67108864,
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_157-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libAIModelSearchKit.so": {
      "sha256": "20233f05b4b010280d16e728103a0995ca2580697b5f9c708fa333e9ff8d1899",
      "expected_unique_export_vas": 1231
    }
  },
  "authorization_reference": "Chairman Tony explicitly requested Codex subagents and multi-lane 45-SO acceleration; AGY excluded",
  "created_at": "2026-10-13T06:23:47.155592Z",
  "budget_deadline_utc": "2026-10-13T08:23:47.155592+00:00"
}
```

Chairman authorizes a real Codex subagent, not AGY, to recover all 1231 defined nonzero-size `.dynsym` STT_FUNC export VAs from the pinned original SO files only. Recheck each full source SHA-256, ELF/PT_LOAD mapping, VA and body hash. One fresh Ghidra import per source maximum; sequential bounded chunks of <=300 unique VAs, one 1-CPU/1-GiB process at a time, <=15s per function, <=900s per process, <=6600s aggregate. No duplicate imports or retry within this revision. Record raw command, stdout/stderr, result, C-like body and assembly evidence for each target. Stop at deadline and seal truthful PARTIAL on timeout/failure; preserve all verified source provenance.

Before any write, fully read `Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` at the F: root and verify its SHA-256 above; read AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task, config/state, locks, END flag and git status. Claim this exact ACTIVE revision with your assignee ID and lease. Write only files_allowed. Report 00_AUDIT_INDEX, 01_MASTER_REPORT, per-source raw logs/receipts, source/C manifests, PROGRESS and COMPLETE hash map. Recheck all critical claims and >=10% spread ordinary provenance. Distinguish exported-function static output from internal functions and validated behavior. No P0/product changes, Phase PASS, V4/P7, self-review, or commit/push before independent CEO review. Do not launch an AGY worker or another subagent.
