# TASK_204 R2 - correct nonempty p-code coverage labels only

STATUS: ACTIVE
ASSIGNEE: /root/so45_mtfilter_next
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T14:00:56.641437Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_204",
  "revision": 2,
  "status": "ACTIVE",
  "assignee": "/root/so45_mtfilter_next",
  "agent_id": "/root/so45_mtfilter_next",
  "priority": "P1",
  "dependencies": [
    {
      "task_id": "TASK_201",
      "revision": 2
    }
  ],
  "mode": "RESEARCH_CORRECTION",
  "report_folder": "RULES/REPORT/TASK_204_REPORT_R2",
  "files_allowed": [
    "RULES/REPORT/TASK_204_REPORT_R2/**",
    "scripts/task_204_codex_correction_r2/**"
  ],
  "files_forbidden": [
    "RULES/TASK/**",
    "RULES/REPORT/TASK_204_REPORT_R1/**",
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
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_204-R2",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libMTFilterKernel.so": {
      "sha256": "f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4",
      "defined_nonzero_export_vas": 2362
    }
  },
  "target_manifest_path": ".ai/ceo/reviews/TASK_204_internal_targets.json",
  "target_manifest_sha256": "548a3f83bf498b047d34dd77e707c00d3644d1c8780eef4e71d8e43802874793",
  "target_candidate_count": 127,
  "correction_of": {
    "task_revision": 1,
    "task_sha256": "a175e7b87e7e257d6623d4f650201ba091868794d54cd2d77ca7a3ebaf9d43ee",
    "manifest_sha256": "548a3f83bf498b047d34dd77e707c00d3644d1c8780eef4e71d8e43802874793",
    "report_folder": "RULES/REPORT/TASK_204_REPORT_R1",
    "complete_sha256": "edbbc77985569a49089745f51c672b807cc428bab307566c697551e49de7b710",
    "ceo_review_fingerprint": "21d00b2a2cba642f907fc577b233fda1a8c89b8df4e239dd5e9ed5e99c590d4b",
    "ceo_review_sha256": "c41315ed4cd882867982b3de7f16f832d3ef5b343ad26ed05c4769fca0b4d391"
  },
  "created_at": "2026-10-13T14:00:56.641437Z",
  "modified_time": "2026-10-13T14:00:56.641437Z",
  "budget_deadline_utc": "2026-10-13T15:09:28.505005+00:00",
  "authorization_reference": "Chairman Tony direct Codex SO45 decoding; CEO R1 NEEDS_FIX review"
}
```

CEO R1 review `.ai/ceo/reviews/TASK_204-21d00b2a2cba642f907fc577b233fda1a8c89b8df4e239dd5e9ed5e99c590d4b.md` found a material coverage-label error. Immutable R1 raw Ghidra evidence has 10,943/10,943 instruction listings, but 197 listings have `pcode_ops: []`: 24 NOP, 96 BTI, 29 PACIASP, 46 AUTIASP, one AUTIB1716 and one AUTIA1716. Only 10,746 positions have at least one p-code operation; total operations remain 37,532. BTI/PAC/AUT semantics are not proven by their empty p-code lists or by C-like text alone. R1 report/code/raw/private project and exact original manifest `.ai/ceo/reviews/TASK_204_internal_targets.json` SHA-256 `548a3f83bf498b047d34dd77e707c00d3644d1c8780eef4e71d8e43802874793` stay immutable.

Before any write fully reread `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`, AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, config/state/locks/END, this exact ACTIVE R2 task and manifest. Claim TASK_204 revision 2 as `/root/so45_mtfilter_next` via `LEASE-CEO-WORKER-TASK_204-R2`. The original absolute deadline 2026-10-13T15:09:28.505005+00:00 persists, and this correction is capped at 15 minutes from claim. R1 task archive, report/code/project, original SO and CEO review are read-only. Write only `RULES/REPORT/TASK_204_REPORT_R2/**` and `scripts/task_204_codex_correction_r2/**`.

Independently parse all 127 immutable R1 effective Ghidra instruction/p-code records and the four correction overlays. Recheck 10,943 listings, 10,746 nonempty-p-code positions, 197 empty-list positions and 37,532 total operations. Publish `CORRECTED_COVERAGE.json` with separately named metrics, per-candidate empty counts and opcode categories; `R1_TO_R2_DELTA.json` with every corrected claim/field and proof that all other critical source, C-like, boundary, project and call/branch counts remain unchanged. Produce `00_AUDIT_INDEX.md` with canonical read and pinned R1 hashes, `01_MASTER_REPORT.md` stating PARTIAL research and corrected coverage/PAC-BTI limit, `PROGRESS.json`, and SHA-256-sealed `COMPLETE.json` with exact report/code inventory. An overlay is sufficient; do not rewrite R1 files. No Ghidra rerun, original SO/product/P0 edit, functional/parity/complete-function claim, product Phase PASS, V4/P7, all-45-SO completion, commit or push before CEO independent review.
