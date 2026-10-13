# TASK_168 R1 - ARKernel interface, PVG color/video and ffmpeg filter export map

STATUS: ACTIVE
ASSIGNEE: /root/so45_dexvmp_correction
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T07:40:56.720945Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_168",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/so45_dexvmp_correction",
  "agent_id": "/root/so45_dexvmp_correction",
  "priority": "P1",
  "dependencies": [],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_168_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_168_REPORT_R1/**",
    "scripts/task_168_codex_exports/**",
    "RESEARCH_WORK/TASK_168_R1/**"
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
    "RULES/REPORT/TASK_156_REPORT_R1/**",
    "RULES/REPORT/TASK_157_REPORT_R1/**",
    "RULES/REPORT/TASK_158_REPORT_R1/**",
    "RULES/REPORT/TASK_159_REPORT_R1/**"
  ],
  "max_minutes": 120,
  "max_cpu": 1,
  "max_heap": "1G",
  "max_report_bytes": 134217728,
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_168-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libARKernelInterface.so": {
      "sha256": "594c5085475d8bb58baacb20293aec805211aa5ccc53b3542f3149196d354953",
      "expected_unique_export_vas": 635
    },
    "libPVGColorFunctions.so": {
      "sha256": "3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6",
      "expected_unique_export_vas": 81
    },
    "libPVGVideoCodec.so": {
      "sha256": "336cf1e8cdaaac1ad5bf77b96a03ae9ad90527e583c82aea44b05b25e5da4d26",
      "expected_unique_export_vas": 160
    },
    "libffmpegfilter.so": {
      "sha256": "f22a7ea6da3194d046ecbce5ce3b602bcb56edfd96444a6e29e1a3c3449cf981",
      "expected_unique_export_vas": 216
    }
  },
  "authorization_reference": "Chairman Tony explicitly directed Codex subagents to finish remaining 45-SO functions in multiple lanes; AGY excluded",
  "created_at": "2026-10-13T07:40:56.720945Z",
  "budget_deadline_utc": "2026-10-13T09:40:56.720945+00:00"
}
```

Recover all 1092 pinned original defined nonzero-size `.dynsym` STT_FUNC export VAs across the specified SOs. This extends earlier small pilots without accepting their unreviewed claims; do not repeat already recovered work within this revision. Check the full original SO SHA, ELF/PT_LOAD VA mapping, body SHA, and actual Ghidra memory for every target. At most one fresh Ghidra import per source; sequential chunks <=256 VAs, one 1-CPU/1-GiB Ghidra process at a time, <=15 seconds/function, <=900 seconds/process and <=6600 seconds aggregate. No retry or duplicate import in this revision. If a symbol body exceeds exporter bounds, isolate it and preserve source/assembly evidence; seal truthful PARTIAL rather than marking it recovered. Preserve raw Ghidra commands/stdout/stderr/results per source and per chunk. Stop at deadline.

Before any write, fully read the canonical `Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` at the F: root and verify its SHA-256 above; read AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task, config/state, locks, END flag and git status. Claim exact ACTIVE revision with your assignee ID and expected lease. Write only files_allowed. Report 00_AUDIT_INDEX, 01_MASTER_REPORT, PT_LOAD source index, per-source raw receipts/results, PROGRESS and sealed COMPLETE hash map. Independently rerun all critical claims and >=10% spread ordinary provenance. Distinguish static export C-like from all internal functions and validated behavior. No P0/product edit, Phase PASS, V4/P7, self-review, commit or push before independent CEO review. Do not launch AGY or another subagent.
