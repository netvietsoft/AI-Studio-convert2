# TASK_249 R1 - bounded libPVGCodec.so gap recovery at 0xAF040

STATUS: ACTIVE
ASSIGNEE: /root/pvg_gap_decode
PRIORITY: P1
MODIFIED_TIME: 2026-10-16T00:10:58.234061+00:00

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_249",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/pvg_gap_decode",
  "agent_id": "/root/pvg_gap_decode",
  "priority": "P1",
  "mode": "RESEARCH",
  "dependencies": [
    {
      "task_id": "TASK_248",
      "revision": 1
    }
  ],
  "report_folder": "RULES/REPORT/TASK_249_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_249_REPORT_R1/**",
    "scripts/task_249_codex_internal/**",
    "RESEARCH_WORK/TASK_249_R1/**"
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
  "max_per_decompile_seconds": 15,
  "max_report_bytes": 67108864,
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_249-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libPVGCodec.so": {
      "sha256": "4fa5f275c8ddecf7caa960c812108ec9e801365bfe5bc9cf38598233bc449ffc"
    }
  },
  "target_candidate_count": 1,
  "authorization_reference": "Chairman-approved continuation plan 2026-10-16: continue only already identified SO45 gaps; bounded static research, no AGY/P0/V4/P7",
  "created_at": "2026-10-16T00:10:58.234061+00:00",
  "modified_time": "2026-10-16T00:10:58.234061+00:00",
  "budget_deadline_utc": "2026-10-16T01:40:58.234061+00:00",
  "target_manifest_path": ".ai/ceo/reviews/TASK_249_internal_targets.json",
  "target_manifest_sha256": "29890e85a5c7677cabf51a20dcbc3fe34b9531fc12ceadb1e25476d9b81c1f27",
  "source_gap": {
    "start_va": "0xaf040",
    "end_va_exclusive": "0xaf688",
    "size_bytes": 1608,
    "instruction_words": 402,
    "file_offset": "0xaf040",
    "mapping": {
      "segment_vaddr": 0,
      "segment_offset": 0,
      "file_offset": 716864,
      "filesz": 1266000
    },
    "sha256": "f825653da2ed819fd5334f4103037f4466fcf8655080e5ec84c56a684569c54b"
  },
  "explicit_nonclaims": [
    "gap is not asserted to be a separate function",
    "static evidence is not runtime/behavior proof"
  ]
}
```

Scope is exactly the 1,608-byte / 402-word span VA [0xAF040,0xAF688) inside TASK_248's candidate FDE [0xA8B08,0xAF68C). Parent TASK_248 reported this span missing Ghidra body membership, with one branch 0xAF5F8 -> 0xAF688; it did not prove a separate source function. Reuse the existing TASK_248 Ghidra project and artifacts. Do not re-decompile the complete 27,524-byte FDE or relaunch the previous broad analysis. Inspect only this range and a small bounded context around each edge.

Before any write, fully read `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` (SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`), AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this task and its exact target manifest, config/state/locks/END. Claim exact ACTIVE TASK_249 R1 as `/root/pvg_gap_decode` using LEASE-CEO-WORKER-TASK_249-R1 via controller before writing; report actual new fencing token and canonical read acknowledgment. Write only files_allowed. Original SO and accepted TASK_248 evidence remain read-only. No AGY, no child agents, no self-review, no commit/push before CEO review.

Required work: rehash source and gap; verify VA/file-offset mapping and all 402 AArch64 words; inspect Ghidra listing/body membership for only this span and its boundary edges in the existing project; recover C-like text only if the tool returns a coherent complete function body whose exact function extent is independently supported (not merely inferred from FDE). Preserve exact commands, exit status, raw output, tool/project hashes, instruction addresses, branch targets, and coverage. Reconcile incoming/outgoing direct and indirect control-flow edges; explicitly list unresolved indirect edges. If this cannot be established, seal PARTIAL with 0 new C-like bodies and exact uncovered addresses. Do not count CFG, p-code, IR, fragments, or timeout output as functions. Recheck at least 10% ordinary provenance records if any are relied on.

Deliver 00_AUDIT_INDEX.md, 01_MASTER_REPORT.md, raw listing/p-code/C-like-or-empty outputs, machine-readable per-word coverage/branch ledger, code verifier(s), and COMPLETE.json with files/code_files hashes, standard/task/target-manifest/source hashes, lease fence, exact counts, and limitations. Freeze output at completion, set REVIEW_CANDIDATE_AWAITING_CEO, and wait for CEO review. No product PASS, runtime claim, P0, V4 readiness or P7. Stop at the 90-minute absolute deadline.
