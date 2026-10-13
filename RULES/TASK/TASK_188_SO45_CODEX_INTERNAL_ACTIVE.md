# TASK_188 R1 - MTLReportTool all 117 nonexport unwind candidates

STATUS: ACTIVE
ASSIGNEE: /root/so45_mtl_report
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T10:57:35.597536Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_188",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/so45_mtl_report",
  "agent_id": "/root/so45_mtl_report",
  "priority": "P1",
  "dependencies": [
    {
      "task_id": "TASK_177",
      "revision": 1
    }
  ],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_188_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_188_REPORT_R1/**",
    "scripts/task_188_codex_internal/**",
    "RESEARCH_WORK/TASK_188_R1/**"
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
  "max_minutes": 80,
  "max_cpu": 1,
  "max_heap": "1G",
  "max_report_bytes": 134217728,
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_188-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libMTLReportTool.so": {
      "sha256": "c34587e543305b8e92fe3156a424f86251667c363d1758be61917d1ef1f1152c",
      "defined_nonzero_export_vas": 30
    }
  },
  "target_manifest_path": ".ai/ceo/reviews/TASK_188_internal_targets.json",
  "target_manifest_sha256": "2a6d89cda113f81a3f1ef7353d4404dbc90bd8b469fde8584acc10925f402810",
  "target_candidate_count": 117,
  "authorization_reference": "Chairman Tony directs direct remaining SO45 decoding with real Codex subagents and no AGY",
  "created_at": "2026-10-13T10:57:35.597536Z",
  "budget_deadline_utc": "2026-10-13T12:17:35.597536+00:00"
}
```

Process only the 117 exact source-byte-backed nonexport FDE candidates in `.ai/ceo/reviews/TASK_188_internal_targets.json` SHA-256 `2a6d89cda113f81a3f1ef7353d4404dbc90bd8b469fde8584acc10925f402810`, original `libMTLReportTool.so` SHA-256 `c34587e543305b8e92fe3156a424f86251667c363d1758be61917d1ef1f1152c`. Prior TASK_177 export research and its analyzed project `RESEARCH_WORK/TASK_177_R1/libMTLReportTool.so/ghidra_project` are read-only potential provenance; verify every original project/copy/source SHA before use. No overlap with TASK_186/187 source libraries. An unwind FDE is a candidate range, not proof of a complete or unique function. Verify each original FDE/PT_LOAD range, source body and SHA before using a byte-verified owned Ghidra copy. Use one CPU and 1 GiB, at most one new import, sequential headless processes <=20 minutes each and <=10 seconds per decompile, with the absolute deadline. Record one result per candidate: source/project body hash, instruction and p-code coverage, C-like text/hash or exact failure, and **every FDE byte** of Ghidra function-body membership plus total body address count. Classify internal gaps/extra/missing ranges explicitly. Preserve raw commands/logs/output. Independently check all critical source/body hashes and >=10% spread ordinary source instruction slots. If incomplete, seal truthful PARTIAL. Do not infer all internal functions, behavior/pixel parity, product Phase PASS, V4/P7 or all-45-SO completion.

Before any write, fully read `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`, verify SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`, and read AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task/manifest, config/state/locks/END and git status. Claim exact ACTIVE TASK_188 revision 1 as `/root/so45_mtl_report`, expected lease `LEASE-CEO-WORKER-TASK_188-R1`, before any write. Write only `RULES/REPORT/TASK_188_REPORT_R1/**`, `scripts/task_188_codex_internal/**`, `RESEARCH_WORK/TASK_188_R1/**`; source SO, TASK_177 and other lanes are read-only. Report 00_AUDIT_INDEX.md with canonical read receipt, 01_MASTER_REPORT.md, raw command/log/result evidence, PROGRESS and sealed COMPLETE.json with complete SHA-256 manifest. No AGY or further subagents, self-review, commit/push before independent CEO review. Stop at 2026-10-13T12:17:35.597536+00:00.
