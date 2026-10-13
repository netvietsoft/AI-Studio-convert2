# TASK_171 R1 - remaining AR, video and audio small export maps

STATUS: ACTIVE
ASSIGNEE: /root/so45_dexvmp_correction
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T08:07:29.141259Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_171",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/so45_dexvmp_correction",
  "agent_id": "/root/so45_dexvmp_correction",
  "priority": "P1",
  "dependencies": [],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_171_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_171_REPORT_R1/**",
    "scripts/task_171_codex_exports/**",
    "RESEARCH_WORK/TASK_171_R1/**"
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
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_171-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libARSPM.so": {
      "sha256": "ec420f2eec97cf2debbf4778045cfd0ac08b78eae656a4f90e282d49b3ef0114",
      "expected_unique_export_vas": 56
    },
    "libPVGLive.so": {
      "sha256": "e443f6a16cb8137d74a1583529666eb02bf4859b372175e2b4c226f6e188484c",
      "expected_unique_export_vas": 20
    },
    "libCtaApiLib.so": {
      "sha256": "4a91ccac45408daa30e8dd60f7c6eee68aeffbdd66e1e9b6e435b1aa3377fcd5",
      "expected_unique_export_vas": 146
    },
    "libKKMusicFX.so": {
      "sha256": "cd876a2e49a129b1bcefdc4aca42047faa4aaf954c6c1286edb80209ac38031d",
      "expected_unique_export_vas": 57
    },
    "libffavc.so": {
      "sha256": "1e214164a6c153f74f25018c1625f3e71d1d5ba601f6592c4dd89385dcc4b0bc",
      "expected_unique_export_vas": 2
    }
  },
  "authorization_reference": "Chairman Tony explicitly directed Codex subagents to finish remaining 45-SO functions in multiple lanes; AGY excluded",
  "created_at": "2026-10-13T08:07:29.141259Z",
  "budget_deadline_utc": "2026-10-13T10:07:29.141259+00:00"
}
```

Recover all 281 pinned original defined nonzero-size `.dynsym` STT_FUNC export VAs across the specified SOs. This extends earlier small pilots without accepting their unreviewed claims; do not repeat already recovered work within this revision. Check the full original SO SHA, ELF/PT_LOAD VA mapping, body SHA, and actual Ghidra memory for every target. At most one fresh Ghidra import per source; sequential chunks <=256 VAs, one 1-CPU/1-GiB Ghidra process at a time, <=15 seconds/function, <=900 seconds/process and <=6600 seconds aggregate. No retry or duplicate import in this revision. If a symbol body exceeds exporter bounds, isolate it and preserve source/assembly evidence; seal truthful PARTIAL rather than marking it recovered. Preserve raw Ghidra commands/stdout/stderr/results per source and per chunk. Stop at deadline.

Before any write, fully read the canonical `Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` at the F: root and verify its SHA-256 above; read AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task, config/state, locks, END flag and git status. Claim exact ACTIVE revision with your assignee ID and expected lease. Write only files_allowed. Report 00_AUDIT_INDEX, 01_MASTER_REPORT, PT_LOAD source index, per-source raw receipts/results, PROGRESS and sealed COMPLETE hash map. Independently rerun all critical claims and >=10% spread ordinary provenance. Distinguish static export C-like from all internal functions and validated behavior. No P0/product edit, Phase PASS, V4/P7, self-review, commit or push before independent CEO review. Do not launch AGY or another subagent.
