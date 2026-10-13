# TASK_179 R1 - glide-webp unresolved conversion export

STATUS: ACTIVE
ASSIGNEE: /root/so45_ai_model_search
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T08:55:57.657908Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_179",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/so45_ai_model_search",
  "agent_id": "/root/so45_ai_model_search",
  "priority": "P1",
  "dependencies": [
    {
      "task_id": "TASK_175",
      "revision": 1
    }
  ],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_179_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_179_REPORT_R1/**",
    "scripts/task_179_codex_exports/**",
    "RESEARCH_WORK/TASK_179_R1/**"
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
  "max_minutes": 60,
  "max_cpu": 1,
  "max_heap": "1G",
  "max_report_bytes": 134217728,
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_179-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libglide-webp.so": {
      "sha256": "2f7f38acc0d294a3333069aa8a3c07e69d4bc0a64f162215578bd55dbe1a4486",
      "expected_unique_export_vas": 230
    }
  },
  "authorization_reference": "Chairman Tony directs real Codex subagents in parallel to finish remaining SO45 functions without AGY",
  "created_at": "2026-10-13T08:55:57.657908Z",
  "budget_deadline_utc": "2026-10-13T09:55:57.657908+00:00",
  "target_export": {
    "elf_va": "0x328dc",
    "size_bytes": 624,
    "symbol": "WebPConvertRGBA32ToUV_C",
    "source_body_sha256": "fc4cf89d6b719a3d8d73009a57a1e755ca9ce11dda3bdd03da45c5b869053404"
  }
}
```

Research only WebPConvertRGBA32ToUV_C at ELF VA 0x328dc in the original libglide-webp.so. TASK_175 accepted 229/230 C-like export bodies and a failed isolated normalize attempt for this 624-byte target; do not repeat the same failed normalize command or reimport/reprocess the other 229. Verify original SO/body SHA and prior raw attempt. Use a different bounded, source-grounded path: inspect all original instructions, Ghidra p-code and basic-block edges and, only if useful, one isolated alternative decompiler pass <=180 seconds/1 CPU/1 GiB. Preserve exact command/stdout/stderr/raw output and line-to-instruction provenance. If C-like remains unavailable, provide clearly labeled register-level or block-level pseudocode and an explicit remaining gap; never claim recovered whole-function C-like or verified behavior without evidence.

Before any write, fully read the F: root canonical Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt and verify SHA-256 10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F. Read AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task, config/state, locks, END flag, and git status. Claim this exact ACTIVE revision using your assignee ID and expected lease before writing. Write only files_allowed. Keep original SOs and prior reports/projects read-only. Report 00_AUDIT_INDEX, 01_MASTER_REPORT, source/command/log/raw-result evidence, PROGRESS, and sealed COMPLETE.json with hashes. Check every critical claim and >=10% spread ordinary provenance. Distinguish source-byte, assembly, Ghidra C-like, and verified-behavior coverage. No AGY, further subagents, P0/product edits, Phase PASS, V4/P7, self-review, commit, or push before independent CEO review. Stop at the absolute deadline and mark PARTIAL truthfully if a gap remains.
