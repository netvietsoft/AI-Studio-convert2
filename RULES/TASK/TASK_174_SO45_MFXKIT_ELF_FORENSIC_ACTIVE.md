# TASK_174 R1 - original libmfxkit.so ELF forensics

STATUS: ACTIVE
ASSIGNEE: /root/so45_dexvmp_correction
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T08:20:34.762261Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_174",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/so45_dexvmp_correction",
  "agent_id": "/root/so45_dexvmp_correction",
  "priority": "P1",
  "dependencies": [],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_174_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_174_REPORT_R1/**",
    "scripts/task_174_codex_exports/**",
    "RESEARCH_WORK/TASK_174_R1/**"
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
  "max_minutes": 75,
  "max_cpu": 1,
  "max_heap": "1G",
  "max_report_bytes": 33554432,
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_174-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libmfxkit.so": {
      "sha256": "78923a90997d34c5dd51215a6cd2bc26c9731806fd9037e4aa71fd3873d3bb4f",
      "original_file_bytes": 773652,
      "export_count": "UNKNOWN_MALFORMED_SECTION_TABLE"
    }
  },
  "known_parser_failure": "ELFParseError Reading section 0 at offset 1352944 past EOF 773652",
  "authorization_reference": "Chairman Tony direct Codex recovery of remaining 45-SO functions; malformed input gap",
  "created_at": "2026-10-13T08:20:34.762261Z",
  "budget_deadline_utc": "2026-10-13T09:35:34.762261+00:00"
}
```

Investigate only the pinned original `libmfxkit.so` (773,652 bytes). The ELF header reports AArch64, 9 program headers and a 28-entry section table beginning at offset 1,352,944, past EOF. Treat a normal `.dynsym` census as UNKNOWN, never zero. Independently parse the bounded ELF/program-header/dynamic bytes without altering the original, looking for valid PT_DYNAMIC, DT_SYMTAB/STRTAB, DT_HASH or DT_GNU_HASH and PT_LOAD mappings. If a provable export census/body set can be recovered, preserve exact offsets, byte hashes and raw tool receipts. Attempt one bounded Ghidra import of a scratch-only, explicitly labeled repair copy only if structurally justified; keep one CPU/1 GiB, <=900 seconds process, <=15 seconds per decompile and <=60 minutes overall. No synthetic symbol records or claimed C-like bodies without matching original PT_LOAD bytes. If original is truncated and census cannot be proven, seal PARTIAL/BLOCKED with the precise boundary, not a false 45/45 claim.

Before any write, fully re-read the F: root canonical Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt and verify its SHA-256, plus AGENTS.md, Docs/rules.md, the SO45 plan, PROJECT_ERROR.md, ACQUIREMENTS.md, config/state, locks, END flag, exact task and git status. Claim exact ACTIVE R1 under your own lease. Write only the three files_allowed scopes. Report 00_AUDIT_INDEX, 01_MASTER_REPORT, raw input/provenance/parse evidence, PROGRESS and sealed COMPLETE hash map. Rerun every critical claim and >=10% ordinary recovered records if any. No AGY or further subagents, P0/product edits, Phase PASS/V4/P7, self-review, commit or push.
