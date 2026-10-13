# TASK_178 R1 - dexvmp oversized export block analysis

STATUS: ACTIVE
ASSIGNEE: /root/so45_dexvmp_correction
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T08:55:57.657908Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_178",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/so45_dexvmp_correction",
  "agent_id": "/root/so45_dexvmp_correction",
  "priority": "P1",
  "dependencies": [
    {
      "task_id": "TASK_159",
      "revision": 1
    }
  ],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_178_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_178_REPORT_R1/**",
    "scripts/task_178_codex_exports/**",
    "RESEARCH_WORK/TASK_178_R1/**"
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
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_178-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libdexvmp.so": {
      "sha256": "b4a46520ec989fef5346833db8f9a1bd6a6690902731414ed26f65cc529cc06e",
      "expected_unique_export_vas": 284
    }
  },
  "authorization_reference": "Chairman Tony directs real Codex subagents in parallel to finish remaining SO45 functions without AGY",
  "created_at": "2026-10-13T08:55:57.657908Z",
  "budget_deadline_utc": "2026-10-13T10:25:57.657908+00:00",
  "target_export": {
    "elf_va": "0x29cd4",
    "size_bytes": 224440,
    "source_body_sha256": "ffe6c5558f71b31ead9ce7055ecea778379cccd409978b5502c9cb39ff272654"
  }
}
```

Research only the previously unresolved 224,440-byte libdexvmp.so export at ELF VA 0x29cd4. TASK_159 accepted 283/284 C-like export bodies; do not reimport/redecompile those 283, or repeat an unbounded whole-function timeout. Verify original SO/body SHA and historical raw failure first. Reuse a byte-verified copy of the analyzed project read-only or create one isolated scratch copy. Derive a reproducible basic-block/edge inventory from original bytes plus Ghidra or Capstone, process bounded blocks/chunks sequentially with one 1-CPU/1-GiB heavy process at a time, <=900 seconds/process. Preserve exact instruction provenance, unresolved edges, commands and raw logs. If no complete C-like can be produced, deliver truthful assembly/p-code or block-level pseudocode marked PARTIAL; do not label it Ghidra C-like or semantic equivalence.

Before any write, fully read the F: root canonical Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt and verify SHA-256 10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F. Read AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task, config/state, locks, END flag, and git status. Claim this exact ACTIVE revision using your assignee ID and expected lease before writing. Write only files_allowed. Keep original SOs and prior reports/projects read-only. Report 00_AUDIT_INDEX, 01_MASTER_REPORT, source/command/log/raw-result evidence, PROGRESS, and sealed COMPLETE.json with hashes. Check every critical claim and >=10% spread ordinary provenance. Distinguish source-byte, assembly, Ghidra C-like, and verified-behavior coverage. No AGY, further subagents, P0/product edits, Phase PASS, V4/P7, self-review, commit, or push before independent CEO review. Stop at the absolute deadline and mark PARTIAL truthfully if a gap remains.
