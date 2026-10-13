# TASK_203 R2 - correct whole-FDE C-like evidence labels only

STATUS: ACTIVE
ASSIGNEE: /root/so45_pvg_followon
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T13:26:51.728684Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_203",
  "revision": 2,
  "status": "ACTIVE",
  "assignee": "/root/so45_pvg_followon",
  "agent_id": "/root/so45_pvg_followon",
  "priority": "P1",
  "dependencies": [
    {
      "task_id": "TASK_200",
      "revision": 1
    }
  ],
  "mode": "RESEARCH_CORRECTION",
  "report_folder": "RULES/REPORT/TASK_203_REPORT_R2",
  "files_allowed": [
    "RULES/REPORT/TASK_203_REPORT_R2/**",
    "scripts/task_203_codex_correction_r2/**"
  ],
  "files_forbidden": [
    "RULES/TASK/**",
    "RULES/REPORT/TASK_203_REPORT_R1/**",
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
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_203-R2",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libPVGColorFunctions.so": {
      "sha256": "3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6",
      "defined_nonzero_export_vas": 81
    }
  },
  "target_manifest_path": ".ai/ceo/reviews/TASK_203_internal_targets.json",
  "target_manifest_sha256": "96936496c5edc481ace634698375d3ae72977f4916844fa2d581ebe1ac82d522",
  "target_candidate_count": 2,
  "correction_of": {
    "task_revision": 1,
    "task_sha256": "3491b85ad4935c7ae64cf940c97e8933186cbe3378f0321349d066cb37384089",
    "manifest_sha256": "96936496c5edc481ace634698375d3ae72977f4916844fa2d581ebe1ac82d522",
    "report_folder": "RULES/REPORT/TASK_203_REPORT_R1",
    "complete_sha256": "ffbb2a6d39b492aebd72f733235470dc8e4e89ddeb6af64f79d645d04b1d605e",
    "window_evidence_sha256": "756904e19cebd62782432a9ac380f7df200cebaf9fdf196bc40ca66362df025a",
    "ceo_review_fingerprint": "ca1e3a82782b329dc2bf93a516c0a588714927bf640938c8029dcbfb6622f7cb",
    "ceo_review_sha256": "28c2f06a2d61b402c5f2656e653dc17ce47e3382269708b414bd5eee8657c44c",
    "ceo_replay_summary_sha256": "26a3643c38e616b47f461ee6182bf7fe123583d262a93f6df23a7bd202808695"
  },
  "created_at": "2026-10-13T13:26:51.728684Z",
  "modified_time": "2026-10-13T13:26:51.728684Z",
  "budget_deadline_utc": "2026-10-13T14:30:13.240060+00:00",
  "authorization_reference": "Chairman Tony direct Codex SO45 decoding; CEO R1 NEEDS_FIX review"
}
```

CEO R1 review `.ai/ceo/reviews/TASK_203-ca1e3a82782b329dc2bf93a516c0a588714927bf640938c8029dcbfb6622f7cb.md` found a material semantic error. R1 `window_evidence.json` says `whole_fde_c_like_present: true` for both targets, although the original FDE #505 has a 96-byte Ghidra body gap at `0x3cd44..0x3cda3` and #556 has a 660-byte gap at `0x4e7e8..0x4ea7b`. The two Ghidra function objects have C-like output, but neither output covers its **whole original FDE**; `COMPLETE.json` correctly says `ghidra_exact_fde_c_like_count: 0`. R1 report and raw evidence stay immutable. The exact original target manifest `.ai/ceo/reviews/TASK_203_internal_targets.json` SHA-256 `96936496c5edc481ace634698375d3ae72977f4916844fa2d581ebe1ac82d522` still selects indices 505 and 556.

Before any write fully reread `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`, AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, config/state/locks/END, this exact ACTIVE R2 task and manifest. Claim TASK_203 revision 2 as `/root/so45_pvg_followon` via `LEASE-CEO-WORKER-TASK_203-R2`. Original absolute deadline 2026-10-13T14:30:13.240060+00:00 persists and this correction is capped at 15 minutes from claim. R1 task archive, report, code, private Ghidra project, original SO and CEO replay are read-only. Write only `RULES/REPORT/TASK_203_REPORT_R2/**` and `scripts/task_203_codex_correction_r2/**`.

Produce `window_evidence_corrected.json` as a full semantic copy of the immutable R1 window evidence: for both targets set `whole_fde_c_like_present` to **false**, set `whole_fde_c_like_failure` to a nonempty exact body-gap explanation, and add separately named `ghidra_function_c_like_present: true`. All other source/window measurements and gap contexts must compare equal after parsing. Publish a machine-readable R1-to-R2 delta proving only those semantic keys changed. Independently verify each original FDE body gap against R1 raw Ghidra body-membership records. Include `00_AUDIT_INDEX.md` canonical-read receipt and immutable R1 hashes, `01_MASTER_REPORT.md` with explicit PARTIAL limits, `PROGRESS.json`, and SHA-256 sealed `COMPLETE.json` for all R2 report/code files. No Ghidra rerun, R1 alteration, original SO/product/P0 edit, source-code/behavior/parity claim, product Phase PASS, V4/P7, all-45-SO completion, commit or push before CEO independent review.
