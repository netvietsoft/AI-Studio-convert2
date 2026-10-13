# TASK_177 R1 - eleven small SO historical export revalidation

STATUS: ACTIVE
ASSIGNEE: /root/so45_pvg_renderer
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T08:55:57.657908Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_177",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/so45_pvg_renderer",
  "agent_id": "/root/so45_pvg_renderer",
  "priority": "P1",
  "dependencies": [],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_177_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_177_REPORT_R1/**",
    "scripts/task_177_codex_exports/**",
    "RESEARCH_WORK/TASK_177_R1/**"
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
  "max_minutes": 100,
  "max_cpu": 1,
  "max_heap": "1G",
  "max_report_bytes": 134217728,
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_177-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libbuffer_pgl.so": {
      "sha256": "d416381c202993e4a03fd6ae0c5b407f1531f61fc45f518ad5b7f4620d5a2133",
      "expected_unique_export_vas": 12
    },
    "libbytehook.so": {
      "sha256": "1fa39f206cf1cb5863dc3770ec3a21339921364e647a3ab4dbb094eab83676d8",
      "expected_unique_export_vas": 20
    },
    "libfile_lock_pgl.so": {
      "sha256": "d14096b150b4b2f21263fdb4f1c61eea3fcd76804c776de2395b13dfbe1d8ca0",
      "expected_unique_export_vas": 6
    },
    "libfntvcrash.so": {
      "sha256": "91b4bfd158229e340d5c7f6722df9d1a1ab72b9e3a5dd72da903bad571fa7e11",
      "expected_unique_export_vas": 1
    },
    "libhiai_ir_build.so": {
      "sha256": "5357c178714545ba0ec715556f70252bf650dd53099170b3fe5519b6ec42cedd",
      "expected_unique_export_vas": 8
    },
    "libhttpelf.so": {
      "sha256": "26ca2ac83e64fe651c4cbc15cf124fc8d86a51f560d753a6fae7cc840dd3ea91",
      "expected_unique_export_vas": 1
    },
    "liblabdeviceinfo.so": {
      "sha256": "68ee1bc7a413742159a9375ff3dcc2d78c31f4259ab697e252acb4f2dfe90e5e",
      "expected_unique_export_vas": 3
    },
    "libMTARMPM.so": {
      "sha256": "a8cc628d8542ef953bcbea36252df569ff03efcea40c3e99a01a5d01489965b4",
      "expected_unique_export_vas": 27
    },
    "libMtlabSign.so": {
      "sha256": "6901812e71f57bd62614000ad735cafdf0dac5282dbeb766b818dd1f1d333cab",
      "expected_unique_export_vas": 17
    },
    "libMTGif.so": {
      "sha256": "a896d526a7ee74611ffd9a611b797c65505e60b4c60ff27fab75ecabbe69a134",
      "expected_unique_export_vas": 104
    },
    "libMTLReportTool.so": {
      "sha256": "c34587e543305b8e92fe3156a424f86251667c363d1758be61917d1ef1f1152c",
      "expected_unique_export_vas": 30
    }
  },
  "authorization_reference": "Chairman Tony directs real Codex subagents in parallel to finish remaining SO45 functions without AGY",
  "created_at": "2026-10-13T08:55:57.657908Z",
  "budget_deadline_utc": "2026-10-13T10:35:57.657908+00:00"
}
```

Recheck all 229 unique original defined nonzero-size .dynsym STT_FUNC export VAs across exactly the eleven listed SOs. TASK_149 and TASK_153 reports are historical unaccepted inputs, not proof. First reuse their raw results and project memory only after exact original SHA, ELF/PT_LOAD mapping, VA/body hash, original bytes, and raw Ghidra receipt checks. Isolate any absent/unverified VA; at most one new import per SO and only where genuinely needed, sequential 1-CPU/1-GiB processes, <=15 seconds/function and <=900 seconds/process. No duplicate extraction of source-verified C-like bodies. Inventory each SO's source/export/C-like counts and precise gaps; save bounded raw evidence and a provenance manifest. No claim of all internal functions or behavior.

Before any write, fully read the F: root canonical Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt and verify SHA-256 10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F. Read AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task, config/state, locks, END flag, and git status. Claim this exact ACTIVE revision using your assignee ID and expected lease before writing. Write only files_allowed. Keep original SOs and prior reports/projects read-only. Report 00_AUDIT_INDEX, 01_MASTER_REPORT, source/command/log/raw-result evidence, PROGRESS, and sealed COMPLETE.json with hashes. Check every critical claim and >=10% spread ordinary provenance. Distinguish source-byte, assembly, Ghidra C-like, and verified-behavior coverage. No AGY, further subagents, P0/product edits, Phase PASS, V4/P7, self-review, commit, or push before independent CEO review. Stop at the absolute deadline and mark PARTIAL truthfully if a gap remains.
