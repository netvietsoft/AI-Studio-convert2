# TASK_184 R1 - VERenderer 141 nonexport unwind candidates

STATUS: ACTIVE
ASSIGNEE: /root/so45_dexvmp_correction
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T09:42:37.448604Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_184",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/so45_dexvmp_correction",
  "agent_id": "/root/so45_dexvmp_correction",
  "priority": "P1",
  "dependencies": [
    {
      "task_id": "TASK_158",
      "revision": 1
    }
  ],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_184_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_184_REPORT_R1/**",
    "scripts/task_184_codex_internal/**",
    "RESEARCH_WORK/TASK_184_R1/**"
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
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_184-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libVERenderer.so": {
      "sha256": "2da896556822804506871c47fadda3fadf8537952e38642e6c496ccbbab8ca46",
      "defined_nonzero_export_vas": 886
    }
  },
  "target_manifest_path": ".ai/ceo/reviews/TASK_184_internal_targets.json",
  "target_manifest_sha256": "0b11084f86a80398343bd576843dfdabf7f697b7d8a31aa652ad452c6d071a0b",
  "target_candidate_count": 141,
  "authorization_reference": "Chairman Tony directs real Codex subagents in parallel to finish remaining SO45 functions without AGY",
  "created_at": "2026-10-13T09:42:37.448604Z",
  "budget_deadline_utc": "2026-10-13T11:12:37.448604+00:00"
}
```

Process only the 141 exact source-byte-backed ELF VA/FDE rows in `.ai/ceo/reviews/TASK_184_internal_targets.json` (SHA-256 `0b11084f86a80398343bd576843dfdabf7f697b7d8a31aa652ad452c6d071a0b`) from original `libVERenderer.so`. They are unwind FDE starts absent from the defined nonzero-size `.dynsym` function export starts; do not call that a complete internal-function census or guaranteed function boundary. Confirm each FDE and PT_LOAD body against the original source before using a byte-verified copied or fresh analyzed Ghidra project. Use one CPU and 1 GiB, one import at most, sequential heavy processing, <=20 minutes per headless process and <=10 seconds per candidate decompilation; stop at the 90-minute absolute deadline. If Ghidra has no function at a pinned VA, create temporary metadata only in the owned copy, record exact range/entry assumptions, and do not invent bytes or signatures. Record one row per pinned candidate with original/copy body SHA, instruction and p-code coverage, C-like text/hash or exact failure/timeout; retain raw Ghidra logs and per-candidate output. Classify overlap or boundary ambiguity explicitly, never silently skip. Verify every original body hash and >=10% spread instruction words independently. Report a bounded PARTIAL if the batch is incomplete, and never infer behavior/pixel parity or all 45-SO completion. Do not rerun prior export decompilation; this is a new nonexport FDE candidate batch.

Before any write, fully read the F: root canonical Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt and verify SHA-256 10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F. Read AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task, its exact target manifest, config/state, locks, END flag and git status. Claim this exact ACTIVE revision using your assignee ID and expected lease before any write. Write only files_allowed; treat all original SOs, earlier reports and analyzed projects as read-only. Report 00_AUDIT_INDEX, 01_MASTER_REPORT, raw command/log/result evidence, PROGRESS and sealed COMPLETE.json with a complete byte-hash manifest. Independently check all critical target bodies and at least 10% spread ordinary instruction provenance. Distinguish source-byte/assembly/p-code/Ghidra C-like/verified behavior coverage. No AGY, further subagents, P0/product edits, Phase PASS, V4/P7, self-review, commit or push before independent CEO review. Stop at the absolute deadline and mark PARTIAL truthfully if a gap remains.
