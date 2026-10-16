# TASK_245 R2 — evidence closeout of stopped R1 static analysis

STATUS: ACTIVE
ASSIGNEE: /root/audit_245_r2
PRIORITY: P1
MODIFIED_TIME: 2026-10-15T23:43:05.037798+00:00

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_245",
  "revision": 2,
  "status": "ACTIVE",
  "assignee": "/root/audit_245_r2",
  "agent_id": "/root/audit_245_r2",
  "priority": "P1",
  "mode": "RESEARCH",
  "dependencies": [
    {
      "task_id": "TASK_239",
      "revision": 1
    }
  ],
  "report_folder": "RULES/REPORT/TASK_245_REPORT_R2",
  "files_allowed": [
    "RULES/REPORT/TASK_245_REPORT_R2/**",
    "RESEARCH_WORK/TASK_245_R2/**"
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
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_245-R2",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libPVGImageCodec.so": {
      "sha256": "7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b"
    }
  },
  "target_candidate_count": 23,
  "target_manifest_path": ".ai/ceo/reviews/TASK_245_internal_targets.json",
  "target_manifest_sha256": "022953118235f468192b1c56f863770300b0639d1eeb9916de057f29fac8943c",
  "prior_report_folder": "RULES/REPORT/TASK_245_REPORT_R1",
  "prior_revision_closeout": "R1 lease expired; actual agent errored; no task process was found; R1 has no COMPLETE.json. R1 files are preserved read-only.",
  "created_at": "2026-10-15T23:43:05.037798+00:00",
  "modified_time": "2026-10-15T23:43:05.037798+00:00",
  "budget_deadline_utc": "2026-10-16T01:43:05.037798+00:00"
}
```

Seal only the 23 existing TASK_245 R1 Ghidra candidates from the pinned libPVGImageCodec.so. Do not rerun Ghidra or add targets. Recheck the internal target manifest, exact source library SHA-256, each FDE/PT_LOAD mapping, source-body bytes, output/input membership and every raw C-like candidate against its source instructions. Preserve uncertain FDE/function boundaries as unverified and do not count those candidates. Produce a per-target evidence table and complete input hash inventory; classify any verified C-like text as static research only. Report the verified accepted-new C-like count separately from the number of R1 candidates and from prior accepted baseline; no semantic or runtime claims. If all 23 remain verifiable, a completed package may have outcome COMPLETE_PARTIAL with all 23 individually enumerated.

Before any write, fully read the canonical Development Workspace Standard at `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` and verify SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`, then read `AGENTS.md`, `Docs/rules.md`, `.ai/ceo/SO45_TO_V4_PLAN.md`, `.ai/ceo/config.json`, `.ai/ceo/state.json`, `.ai/locks.json`, END flag, this task and its exact target manifest. R1 report is read-only. Claim exact ACTIVE TASK_245 R2 as `/root/audit_245_r2` using `LEASE-CEO-WORKER-TASK_245-R2` before writing. Write only `files_allowed`; do not edit source, prior reports, tasks, app/product code, or CEO files. No AGY, child agents, commit/push, or self-review. Do not treat an FDE span as proven function boundary. Record the canonical path and SHA-256 in `00_AUDIT_INDEX.md`. Final report package must include `COMPLETE.json` with `status: COMPLETE`, `outcome: COMPLETE_PARTIAL` if any material gap remains, exact hashes of every other file in the R2 report folder, and an explicit count of newly accepted C-like bodies (zero if none meet all checks). Capture every claim in the evidence ledger. No product Phase PASS or V4/P7 authorization. Stop at absolute deadline `2026-10-16T01:43:05.037798+00:00`.
