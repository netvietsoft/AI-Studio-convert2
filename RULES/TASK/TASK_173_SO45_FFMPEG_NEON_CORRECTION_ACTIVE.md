# TASK_173 R1 - correct two unresolved FFmpeg NEON exports

STATUS: ACTIVE
ASSIGNEE: /root/so45_pvg_renderer
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T08:16:13.318038Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_173",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/so45_pvg_renderer",
  "agent_id": "/root/so45_pvg_renderer",
  "priority": "P1",
  "dependencies": [
    {
      "task_id": "TASK_170",
      "revision": 1
    }
  ],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_173_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_173_REPORT_R1/**",
    "scripts/task_173_codex_exports/**",
    "RESEARCH_WORK/TASK_173_R1/**"
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
    "RULES/REPORT/TASK_170_REPORT_R1/**"
  ],
  "max_minutes": 60,
  "max_cpu": 1,
  "max_heap": "1G",
  "max_report_bytes": 33554432,
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_173-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libffmpeg.so": {
      "sha256": "d8df8c5cb7a6b5a7eb771782d74a38e0b8d3cfacd1fbef1ae67a96171e3325c9",
      "original_unique_export_vas": 2461
    }
  },
  "target_export_vas": [
    {
      "index_in_TASK_170": 2283,
      "elf_va": "0x658fe8",
      "size_bytes": 736,
      "symbol": "x264_8_deblock_h_luma_intra_neon",
      "source_body_sha256": "94017dc1deb91f10d8a4fd18f131f5d7741d0512c73c533de6d9845fbe095cee"
    },
    {
      "index_in_TASK_170": 2330,
      "elf_va": "0x65aea8",
      "size_bytes": 232,
      "symbol": "x264_8_frame_init_lowres_core_neon",
      "source_body_sha256": "0b7e289d57ad0368923c5a802869b755b47eb70e43ff290fcd1096388ca46439"
    }
  ],
  "accepted_prior_report": "RULES/REPORT/TASK_170_REPORT_R1/COMPLETE.json",
  "authorization_reference": "Chairman Tony direct Codex recovery of remaining SO functions; CEO independent TASK_170 partial review",
  "created_at": "2026-10-13T08:16:13.318038Z",
  "budget_deadline_utc": "2026-10-13T09:16:13.318038+00:00"
}
```

Research **only the two exact target VAs** listed above. TASK_170's 2,459 recovered C-like bodies are accepted as partial research; do not re-run or re-import all 2,461. Fully verify the pinned original SO SHA, ELF/PT_LOAD body bytes and accepted prior raw failure rows. Reuse a byte-verified copy of the analyzed TASK_170 Ghidra project; never modify the prior project, report or original SO. Run at most one bounded, isolated alternative decompile attempt per target (<=180 seconds each) with one CPU/1 GiB and total <=45 minutes. If that fails, extract raw pcode/assembly and produce clearly labeled, register-level manual pseudocode with per-instruction evidence; never call it Ghidra C-like or verified semantic equivalence. Do not invent an output or claim recovered from a filename. Preserve exact commands/stdout/stderr/raw rows, original byte hashes and reason for any still-unresolved target. Seal truthful PARTIAL if C-like recovery is impossible.

Before any write, fully re-read the F: root canonical Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt and verify its SHA-256, plus AGENTS.md, Docs/rules.md, the SO45 plan, PROJECT_ERROR.md, ACQUIREMENTS.md, config/state, locks, END flag, exact task and git status. Claim exact ACTIVE R1 under your own lease. Write only the three files_allowed scopes. Report 00_AUDIT_INDEX, 01_MASTER_REPORT, raw receipts/results, PROGRESS and sealed COMPLETE hash map. Independently check both critical VAs and their full source instruction ranges. No AGY or further subagents, P0/product edits, Phase PASS/V4/P7, self-review, commit or push.
