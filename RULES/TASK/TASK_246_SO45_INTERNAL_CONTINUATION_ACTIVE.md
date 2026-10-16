# TASK_246 R2 — evidence closeout of stopped R1 static analysis

STATUS: ACTIVE
ASSIGNEE: /root/audit_246_r2
PRIORITY: P1
MODIFIED_TIME: 2026-10-15T23:43:05.037798+00:00

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_246",
  "revision": 2,
  "status": "ACTIVE",
  "assignee": "/root/audit_246_r2",
  "agent_id": "/root/audit_246_r2",
  "priority": "P1",
  "mode": "RESEARCH",
  "dependencies": [
    {
      "task_id": "TASK_239",
      "revision": 1
    }
  ],
  "report_folder": "RULES/REPORT/TASK_246_REPORT_R2",
  "files_allowed": [
    "RULES/REPORT/TASK_246_REPORT_R2/**",
    "RESEARCH_WORK/TASK_246_R2/**"
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
  "max_minutes": 120,
  "max_cpu": 1,
  "max_heap": "1G",
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_246-R2",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libPVGImageCodec.so": {
      "sha256": "7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b"
    }
  },
  "target_candidate_count": 2,
  "target_manifest_path": ".ai/ceo/reviews/TASK_246_internal_targets.json",
  "target_manifest_sha256": "ada323831163d1d0ef90d3cf6d6596ddee49b98006ddee2e34b53f4c75b9ae96",
  "prior_report_folder": "RULES/REPORT/TASK_246_REPORT_R1",
  "prior_revision_closeout": "R1 lease expired; actual agent errored; no task process was found; R1 has no COMPLETE.json. R1 files are preserved read-only.",
  "created_at": "2026-10-15T23:43:05.037798+00:00",
  "modified_time": "2026-10-15T23:43:05.037798+00:00",
  "budget_deadline_utc": "2026-10-16T01:43:05.037798+00:00"
}
```

Seal only the two existing TASK_246 R1 candidates from pinned libPVGImageCodec.so. Do not rerun Ghidra, create new text, or count CFG/p-code/IR as recovered functions. Verify source membership, the 8,182 instruction slots, CFG coverage, mapped bytes and R1 receipt hashes. Report 0 newly verified C-like function bodies unless a complete, source-mapped C-like body already exists in the raw R1 output and passes the task boundary/provenance rules (the R1 progress says zero). Classify CFG/IR separately as static-analysis evidence only, with explicit gaps and outcome COMPLETE_PARTIAL.

Before any write, fully read the canonical Development Workspace Standard at `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` and verify SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`, then read `AGENTS.md`, `Docs/rules.md`, `.ai/ceo/SO45_TO_V4_PLAN.md`, `.ai/ceo/config.json`, `.ai/ceo/state.json`, `.ai/locks.json`, END flag, this task and its exact target manifest. R1 report is read-only. Claim exact ACTIVE TASK_246 R2 as `/root/audit_246_r2` using `LEASE-CEO-WORKER-TASK_246-R2` before writing. Write only `files_allowed`; do not edit source, prior reports, tasks, app/product code, or CEO files. No AGY, child agents, commit/push, or self-review. Do not treat an FDE span as proven function boundary. Record the canonical path and SHA-256 in `00_AUDIT_INDEX.md`. Final report package must include `COMPLETE.json` with `status: COMPLETE`, `outcome: COMPLETE_PARTIAL` if any material gap remains, exact hashes of every other file in the R2 report folder, and an explicit count of newly accepted C-like bodies (zero if none meet all checks). Capture every claim in the evidence ledger. No product Phase PASS or V4/P7 authorization. Stop at absolute deadline `2026-10-16T01:43:05.037798+00:00`.
