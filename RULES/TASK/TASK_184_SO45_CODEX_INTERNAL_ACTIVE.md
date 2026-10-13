# TASK_184 R2 - correct VERenderer body coverage classification

STATUS: ACTIVE
ASSIGNEE: /root/so45_dexvmp_correction
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T10:05:04.029552Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_184",
  "revision": 2,
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
  "report_folder": "RULES/REPORT/TASK_184_REPORT_R2",
  "files_allowed": [
    "RULES/REPORT/TASK_184_REPORT_R2/**",
    "scripts/task_184_codex_correction_r2/**",
    "RESEARCH_WORK/TASK_184_R2/**"
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
  "max_minutes": 45,
  "max_cpu": 1,
  "max_heap": "1G",
  "max_report_bytes": 134217728,
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_184-R2",
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
  "created_at": "2026-10-13T10:05:04.029552Z",
  "budget_deadline_utc": "2026-10-13T10:50:04.029552+00:00",
  "correction_of": {
    "revision": 1,
    "fingerprint": "59b10f33044972ea28b2442f8f5bbf4033401675b14ee2cc6d89e88f2527be43",
    "review_file": ".ai/ceo/reviews/TASK_184-59b10f33044972ea28b2442f8f5bbf4033401675b14ee2cc6d89e88f2527be43.md",
    "original_task_sha256": "1fbab2b3072b94c02d7684246d5c5280ab6fbc560b4a5c8cf98d062a2e808042",
    "original_task_archive": ".ai/ceo/reviews/TASK_184_R1_TASK_SNAPSHOT.md"
  }
}
```

This is the exact report-only correction of R1 fingerprint `59b10f33044972ea28b2442f8f5bbf4033401675b14ee2cc6d89e88f2527be43` after CEO NEEDS_FIX review `.ai/ceo/reviews/TASK_184-59b10f33044972ea28b2442f8f5bbf4033401675b14ee2cc6d89e88f2527be43.md`. Preserve all R1 files byte-for-byte. The 141 source-pinned rows in `.ai/ceo/reviews/TASK_184_internal_targets.json` and their raw C-like outputs remain useful static evidence; do not redo unrelated SOs or claim behavior.

Independent CEO Ghidra body-membership evidence in `.ai/ceo/reviews/TASK_184_CEO_REPLAY/body_ranges.ndjson` found 135 exact and six nonexact Ghidra function bodies, indices 8,14,17,46,95,96. Index 96, ELF VA `0x5d6e4`, has full FDE size 436 but Ghidra function body only 392 address bytes despite matching min/max endpoints. Recheck this directly on a byte-verified owned Ghidra-project copy, enumerate the 11 missing AArch64 instruction addresses and hashes, and correct the extractor to compare complete body membership, not just endpoints. Explicitly classify candidate 96's existing C-like as boundary-limited; correct all coverage totals, report statements and any output indexes that imply 136 exact / five ambiguous. If fresh read-only extraction is necessary, stay within one CPU, 1 GiB and 10s decompile per candidate. Do not edit the R1 report, source SO, P0 or product code.

Before any write, fully re-read `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` and verify SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`. Read AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact R2 task, target manifest, config/state, locks, END flag and git status. Claim TASK_184 revision 2 using `/root/so45_dexvmp_correction`, expected lease `LEASE-CEO-WORKER-TASK_184-R2`, before any write. Only write the R2 files_allowed. Put 00_AUDIT_INDEX.md, 01_MASTER_REPORT.md, raw command/log/body-membership evidence, PROGRESS, independently checked source/body and >=10% ordinary provenance, and sealed COMPLETE.json with a complete SHA-256 manifest in `RULES/REPORT/TASK_184_REPORT_R2`. State exact limitations, no behavior/pixel parity, Phase PASS, V4/P7 or all-45-SO claim. Stop by the absolute deadline and await independent CEO review; no commit/push or AGY.
