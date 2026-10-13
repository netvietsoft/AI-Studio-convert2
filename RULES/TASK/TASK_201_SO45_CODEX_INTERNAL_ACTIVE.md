# TASK_201 R2 - correct remaining MTFilter candidate count only

STATUS: ACTIVE
ASSIGNEE: /root/so45_mtfilter_next
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T13:19:31.265196Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_201",
  "revision": 2,
  "status": "ACTIVE",
  "assignee": "/root/so45_mtfilter_next",
  "agent_id": "/root/so45_mtfilter_next",
  "priority": "P1",
  "dependencies": [
    {
      "task_id": "TASK_197",
      "revision": 1
    }
  ],
  "mode": "RESEARCH_CORRECTION",
  "report_folder": "RULES/REPORT/TASK_201_REPORT_R2",
  "files_allowed": [
    "RULES/REPORT/TASK_201_REPORT_R2/**",
    "scripts/task_201_codex_correction_r2/**"
  ],
  "files_forbidden": [
    "RULES/TASK/**",
    "RULES/REPORT/TASK_201_REPORT_R1/**",
    "RESEARCH_WORK/**",
    "SOURCE/**",
    ".ai/**",
    "app/**",
    "apps/**",
    "lib-*/**",
    "Backend/**",
    "services/**",
    "packages/**"
  ],
  "max_minutes": 15,
  "max_cpu": 1,
  "max_heap": "1G",
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_201-R2",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libMTFilterKernel.so": {
      "sha256": "f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4",
      "defined_nonzero_export_vas": 2362
    }
  },
  "target_manifest_path": ".ai/ceo/reviews/TASK_201_R2_internal_targets.json",
  "target_manifest_sha256": "4f1f0e38460ef8d32d0e0d15de56feadc050d6e097cf385c4e9a41dca7f7932a",
  "target_candidate_count": 62,
  "correction_of": {
    "task_revision": 1,
    "task_sha256": "5caebf855c995650171dd848e46aa4699e06475b3e29945a8108df04ab6a243a",
    "manifest_sha256": "3523ec8697b80bace822a7367bdcc226e984eb328b5b3a7f6d4a95128dbe5746",
    "report_folder": "RULES/REPORT/TASK_201_REPORT_R1",
    "complete_sha256": "c1ed5968c93cc30bb4e1caa8e991dac870dbaeae084e78b8866959199e5933db",
    "worker_verification_sha256": "8c8c4ca1e82ada63b54de414ee6624d9d1b99a139a051c4f8e520ec3259ee0e1",
    "ceo_review_fingerprint": "3aa9e79e3edebe13205ab0a1be1682e7c957aaa99dafe7e1c53f0c2247de5599",
    "ceo_review_sha256": "592a92628e96f1537dc98ff82b55166a35b38d60bbd6fe1b860de2bd20dfabd6",
    "ceo_replay_summary_sha256": "1f0cc23cffcadb4395a4979c287819979e3059c350f51cff2ed54ad8de54d76b"
  },
  "created_at": "2026-10-13T13:19:31.265196Z",
  "modified_time": "2026-10-13T13:19:31.265196Z",
  "budget_deadline_utc": "2026-10-13T14:25:58.997082+00:00",
  "authorization_reference": "Chairman Tony direct Codex SO45 decoding; CEO R1 NEEDS_FIX review"
}
```

CEO R1 review `.ai/ceo/reviews/TASK_201-3aa9e79e3edebe13205ab0a1be1682e7c957aaa99dafe7e1c53f0c2247de5599.md` has NEEDS_FIX for one census error. The five exact accepted/sealed MTFilter manifests select 128+64+60+62+62 = 376 distinct targets out of 511 nonexport FDE candidates. The unselected total is **135**, comprising tail indices 384..510 (127) plus eight prior/current exclusions [201, 211, 216, 235, 293, 304, 349, 362]. R1 mistakenly says 129 because it omits six earlier exclusions. R2 manifest `.ai/ceo/reviews/TASK_201_R2_internal_targets.json` SHA-256 `4f1f0e38460ef8d32d0e0d15de56feadc050d6e097cf385c4e9a41dca7f7932a` preserves all 62 target rows and original body hashes; only census metadata changes. The older TASK_197 residual count is also historical and inaccurate; do not edit its sealed artifact.

Before any write fully reread `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`, AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, config/state/locks/END, this exact ACTIVE R2 task and manifest. Claim TASK_201 revision 2 as `/root/so45_mtfilter_next` via `LEASE-CEO-WORKER-TASK_201-R2`. The original absolute deadline 2026-10-13T14:25:58.997082+00:00 persists and this correction is capped at 15 minutes from claim. R1 task archive, report, source/assembly, code, project and CEO replay are read-only; write only `RULES/REPORT/TASK_201_REPORT_R2/**` and `scripts/task_201_codex_correction_r2/**`.

Independently recompute the union of the five manifest target indices and exclusions. Produce `00_AUDIT_INDEX.md` with canonical path/hash, `01_MASTER_REPORT.md` with exact 376/511/135 arithmetic and limits, `CORRECTION_DELTA.json` proving the new manifest's 62 targets match R1 byte-for-byte after JSON parsing and identifying only changed census metadata, `PROGRESS.json`, and SHA-256 sealed `COMPLETE.json` for all R2 report/code files. Explicitly cite immutable R1 COMPLETE, original task/manifest and CEO review/replay hashes. Do not rerun Ghidra, alter R1, original SO, product code or P0, claim complete unique functions or behavior, product Phase PASS, V4/P7, all 45 SOs, or commit/push before CEO independent review.
