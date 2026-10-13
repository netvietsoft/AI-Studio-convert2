# TASK_187 R1 - MTFilterKernel first 128 nonexport unwind candidates

STATUS: ACTIVE
ASSIGNEE: /root/so45_pvg_renderer
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T10:08:12.772471Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_187",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/so45_pvg_renderer",
  "agent_id": "/root/so45_pvg_renderer",
  "priority": "P1",
  "dependencies": [
    {
      "task_id": "TASK_183",
      "revision": 1
    }
  ],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_187_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_187_REPORT_R1/**",
    "scripts/task_187_codex_internal/**",
    "RESEARCH_WORK/TASK_187_R1/**"
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
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_187-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libMTFilterKernel.so": {
      "sha256": "f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4",
      "defined_nonzero_export_vas": 2362
    }
  },
  "target_manifest_path": ".ai/ceo/reviews/TASK_187_internal_targets.json",
  "target_manifest_sha256": "cdca39d65d7a29d866b3e43264f687d147b549c43945e4f0c694fb8e73d56bf8",
  "target_candidate_count": 128,
  "authorization_reference": "Chairman Tony explicitly directs direct SO45 decoding without AGY and real Codex subagents in parallel lanes",
  "created_at": "2026-10-13T10:08:12.772471Z",
  "budget_deadline_utc": "2026-10-13T11:38:12.772471+00:00"
}
```

This is the first 128 MTFilterKernel nonexport FDE candidates; previous export work and source SO are read-only. Process only the 128 exact source-byte-backed ELF VA/FDE rows in `.ai/ceo/reviews/TASK_187_internal_targets.json` (SHA-256 `cdca39d65d7a29d866b3e43264f687d147b549c43945e4f0c694fb8e73d56bf8`) from original `libMTFilterKernel.so` SHA-256 `f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4`. These starts are absent from defined nonzero-size `.dynsym` STT_FUNC exports; an unwind FDE is a candidate range, not proof of a complete or unique function. Verify every original FDE/PT_LOAD body and SHA before using a byte-verified copied or fresh Ghidra project. Use one CPU and 1 GiB, one new import at most, sequential heavy processing, <=20 minutes per headless process, <=10 seconds decompile per candidate, and the absolute 90-minute deadline. Record one result per candidate: source/project body hash, instruction and p-code coverage, C-like text/hash or exact failure, and Ghidra function-body membership over **every FDE byte** (`contains` and address count), not merely min/max endpoints. Classify discontinuous/overlapping/missing body ranges explicitly, including C-like boundary limitations. Preserve raw tool logs and per-candidate results; verify all original critical body hashes and >=10% spread ordinary instruction provenance independently. If incomplete, seal a truthful bounded PARTIAL rather than extrapolate. No behavior/pixel parity, product Phase PASS, V4/P7 or all-45-SO completion claim.

Before any write, fully read `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` and verify SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`. Read AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task and target manifest, config/state/locks/END flag and git status. Claim exact ACTIVE TASK_187 revision 1 using `/root/so45_pvg_renderer` and expected lease `LEASE-CEO-WORKER-TASK_187-R1` before writing. Write only files_allowed; original SOs, earlier reports and projects are read-only. Report to `RULES/REPORT/TASK_187_REPORT_R1`: 00_AUDIT_INDEX.md with canonical read receipt, 01_MASTER_REPORT.md, raw command/log/result evidence, PROGRESS and sealed COMPLETE.json with complete SHA-256 manifest. No AGY, further subagents, P0/product edits, self-review, commit or push before independent CEO review. Stop at deadline and await review.
