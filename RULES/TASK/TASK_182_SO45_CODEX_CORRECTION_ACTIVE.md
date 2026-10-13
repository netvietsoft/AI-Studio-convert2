# TASK_182 R1 - WebP SIMD-path corrective decompilation

STATUS: ACTIVE
ASSIGNEE: /root/so45_dexvmp_correction
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T09:17:48.417200Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_182",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/so45_dexvmp_correction",
  "agent_id": "/root/so45_dexvmp_correction",
  "priority": "P1",
  "dependencies": [
    {
      "task_id": "TASK_179",
      "revision": 1
    }
  ],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_182_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_182_REPORT_R1/**",
    "scripts/task_182_codex_exports/**",
    "RESEARCH_WORK/TASK_182_R1/**"
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
  "max_minutes": 70,
  "max_cpu": 1,
  "max_heap": "1G",
  "max_report_bytes": 134217728,
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_182-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libglide-webp.so": {
      "sha256": "2f7f38acc0d294a3333069aa8a3c07e69d4bc0a64f162215578bd55dbe1a4486",
      "expected_unique_export_vas": 230
    }
  },
  "target_exports": [
    {
      "elf_va": "0x328dc",
      "size_bytes": 624,
      "symbol": "WebPConvertRGBA32ToUV_C",
      "source_body_sha256": "fc4cf89d6b719a3d8d73009a57a1e755ca9ce11dda3bdd03da45c5b869053404"
    }
  ],
  "authorization_reference": "Chairman Tony directs real Codex subagents in parallel to finish remaining SO45 functions without AGY",
  "created_at": "2026-10-13T09:17:48.417200Z",
  "budget_deadline_utc": "2026-10-13T10:27:48.417200+00:00"
}
```

Research only the unresolved SIMD path of WebPConvertRGBA32ToUV_C. TASK_179 already source-anchored all 156 original instructions and recovered synthetic scalar-tail C-like; do not repeat that pass or reprocess 229 other exports. Verify original source, historical p-code and TASK_179 raw receipt. Use at most one different, bounded vector-only or whole-function corrective Ghidra pass in a byte-verified copied project, <=180 seconds/1 CPU/1 GiB, or derive rigorously source-anchored SIMD operations if a pass is not useful. Record exact command/log/raw result and all entry-state assumptions; compare coefficients, clamps, narrowing and stores against original ARM64. Any C-like from synthetic metadata is fragment-only; claim whole-original C-like only if the exact original function decompiles. No behavior/pixel claim.

Before any write, fully read the F: root canonical Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt and verify SHA-256 10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F. Read AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task, config/state, locks, END flag, and git status. Claim this exact ACTIVE revision using your assignee ID and expected lease before writing. Write only files_allowed. Keep original SOs, prior reports and analyzed projects read-only. Report 00_AUDIT_INDEX, 01_MASTER_REPORT, exact raw source/command/log/result evidence, PROGRESS and sealed COMPLETE.json with a complete byte-hash manifest. Check every critical claim and >=10% spread ordinary provenance. Distinguish source-byte, assembly, Ghidra C-like and verified behavior coverage. No AGY, further subagents, P0/product edits, Phase PASS, V4/P7, self-review, commit or push before independent CEO review. Stop at the absolute deadline and mark PARTIAL truthfully if a gap remains.
