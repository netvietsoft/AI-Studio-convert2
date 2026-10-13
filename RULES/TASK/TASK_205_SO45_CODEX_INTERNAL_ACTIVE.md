# TASK_205 R2 - correct nonempty p-code coverage labels only

STATUS: ACTIVE
ASSIGNEE: /root/so45_imagecodec_internal
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T13:58:25.465794Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_205",
  "revision": 2,
  "status": "ACTIVE",
  "assignee": "/root/so45_imagecodec_internal",
  "agent_id": "/root/so45_imagecodec_internal",
  "priority": "P1",
  "dependencies": [
    {
      "task_id": "TASK_202",
      "revision": 1
    }
  ],
  "mode": "RESEARCH_CORRECTION",
  "report_folder": "RULES/REPORT/TASK_205_REPORT_R2",
  "files_allowed": [
    "RULES/REPORT/TASK_205_REPORT_R2/**",
    "scripts/task_205_codex_correction_r2/**"
  ],
  "files_forbidden": [
    "RULES/TASK/**",
    "RULES/REPORT/TASK_205_REPORT_R1/**",
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
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_205-R2",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libPVGImageCodec.so": {
      "sha256": "7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b",
      "defined_nonzero_export_vas": 3326
    }
  },
  "target_manifest_path": ".ai/ceo/reviews/TASK_205_internal_targets.json",
  "target_manifest_sha256": "fb7fc5d6f7ef0bb067a0989263bffc60b75a1be40e3ac2c39b9c7759b8666d12",
  "target_candidate_count": 126,
  "correction_of": {
    "task_revision": 1,
    "task_sha256": "4eb23a8ff4eb3345be6a3bb61f353725377a45f5fdcf1c8070e402d2bf2906ac",
    "manifest_sha256": "fb7fc5d6f7ef0bb067a0989263bffc60b75a1be40e3ac2c39b9c7759b8666d12",
    "report_folder": "RULES/REPORT/TASK_205_REPORT_R1",
    "complete_sha256": "d1d03840795c96e092241be72ce9c3bf6d8939c44660898ceb39825384cc8fac",
    "ceo_review_fingerprint": "61976a1abb5c257fa3e159a8f0ee85bfc0d3182533bc85e509e5aa1389788cdf",
    "ceo_review_sha256": "c6800f28b63522d207cf9697e72de10569d2f17ce630ed4f66b56cd23ce1b776"
  },
  "created_at": "2026-10-13T13:58:25.465794Z",
  "modified_time": "2026-10-13T13:58:25.465794Z",
  "budget_deadline_utc": "2026-10-13T15:09:28.505005+00:00",
  "authorization_reference": "Chairman Tony direct Codex SO45 decoding; CEO R1 NEEDS_FIX review"
}
```

CEO R1 review `.ai/ceo/reviews/TASK_205-61976a1abb5c257fa3e159a8f0ee85bfc0d3182533bc85e509e5aa1389788cdf.md` found one material reporting overclaim. The immutable R1 raw Ghidra evidence has 6,246/6,246 instruction listings, but six `nop` rows have `pcode_ops: []`: candidate 380 at database VA `0x2db2ac`; candidate 381 at `0x2db538`, `0x2dbdd0`, `0x2dbe6c`; candidate 384 at `0x2dc3f0`, `0x2dc3fc`. Thus only 6,240 positions have at least one p-code operation; total p-code operations remain 25,604. The R1 master/audit and machine-readable verification/seal/progress unqualified 6,246-p-code-position claim is false under its ordinary meaning. R1 report/code/raw/private project and exact original manifest `.ai/ceo/reviews/TASK_205_internal_targets.json` SHA-256 `fb7fc5d6f7ef0bb067a0989263bffc60b75a1be40e3ac2c39b9c7759b8666d12` stay immutable.

Before any write fully reread `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`, AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, config/state/locks/END, this exact ACTIVE R2 task and manifest. Claim TASK_205 revision 2 as `/root/so45_imagecodec_internal` via `LEASE-CEO-WORKER-TASK_205-R2`. The original absolute deadline 2026-10-13T15:09:28.505005+00:00 persists, and this correction is capped at 15 minutes from claim. R1 task archive, report/code/project, original SO and CEO review are read-only. Write only `RULES/REPORT/TASK_205_REPORT_R2/**` and `scripts/task_205_codex_correction_r2/**`.

Independently parse all 126 immutable R1 effective Ghidra instruction/p-code records, identify the six exact empty-list NOPs, and recheck 6,246 listings, 6,240 nonempty-p-code positions and 25,604 total operations. Publish `CORRECTED_COVERAGE.json` with these separately named metrics and six exact candidate/source/database VAs; `R1_TO_R2_DELTA.json` with every corrected claim/field and proof that all other critical source, C-like, boundary, project and call/branch counts remain unchanged. Produce `00_AUDIT_INDEX.md` with canonical read and pinned R1 hashes, `01_MASTER_REPORT.md` stating PARTIAL research and corrected coverage, `PROGRESS.json`, and SHA-256-sealed `COMPLETE.json` with exact report/code file inventory. An overlay is sufficient; do not rewrite R1 files. No Ghidra rerun, original SO/product/P0 edit, functional/parity/complete-function claim, product Phase PASS, V4/P7, all-45-SO completion, commit or push before CEO independent review.
