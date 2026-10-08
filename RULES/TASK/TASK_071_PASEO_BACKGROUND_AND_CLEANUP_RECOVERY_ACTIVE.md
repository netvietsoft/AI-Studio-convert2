# TASK071 — bounded Paseo background-launch and cleanup rejection repair
STATUS: ACTIVE

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_071",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "Codex_CEO",
  "agent_id": "Codex_CEO",
  "priority": "P0",
  "mode": "HOST_TOOLING_REPAIR",
  "design_impact": "NONE",
  "dependencies": [],
  "report_folder": "RULES/REPORT/CEO_SO45_ORCHESTRATION/PASEO_RUNTIME_RECOVERY_20261008",
  "files_allowed": [
    "C:/Users/PC.DESKTOP-81LIH38/AppData/Roaming/npm/node_modules/@getpaseo/cli/node_modules/@getpaseo/server/dist/scripts/supervisor.js",
    "C:/Users/PC.DESKTOP-81LIH38/AppData/Roaming/npm/node_modules/@getpaseo/cli/node_modules/@getpaseo/server/dist/server/builtin-plugins/antigravity-provider/server/internal/session.ts",
    "RULES/REPORT/CEO_SO45_ORCHESTRATION/PASEO_RUNTIME_RECOVERY_20261008/**",
    ".ai/ceo/reviews/TASK071*",
    ".ai/ceo/receipts/TASK_071*",
    "C:/Users/PC.DESKTOP-81LIH38/AppData/Roaming/npm/node_modules/@getpaseo/cli/node_modules/@getpaseo/server/dist/scripts/.codex-task071.*.tmp",
    "C:/Users/PC.DESKTOP-81LIH38/AppData/Roaming/npm/node_modules/@getpaseo/cli/node_modules/@getpaseo/server/dist/server/builtin-plugins/antigravity-provider/server/internal/.codex-task071.*.tmp"
  ],
  "files_forbidden": [
    "app/**",
    "lib-*/**",
    "AGENTS.md",
    "PROJECT_ERROR.md",
    "ACQUIREMENTS.md"
  ],
  "max_fix_cycles": 1,
  "max_minutes": 20,
  "authorization_reference": "Chairman Tony direct request to check/fix repeatedly restarting visible Paseo daemon and reduce wake/token waste 2026-10-08",
  "native_session_id": "01a11984-0fa0-75c1-9aba-29bf21c79dae",
  "execution_engine": "Actual Codex CEO root; not simulated AGY",
  "no_active_agent_cancellation_authorized": true,
  "no_v4_or_baseline_authorized": true,
  "scope_refinement": "Atomic sibling temp files only; original attempt/deadline unchanged"
}
```

Read canonical Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt in full and verify SHA25610968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F; read AGENTS/rules/CEO plan before work. Exact host lease required.

Confirmed visible child console: supervisor spawn/fork omit windowsHide; initial launcher already hidden. Preserve current processes; add windowsHide:true to both worker launches only. Existing supervisor cache means activation needs a later controlled supervisor restart; no cancellation of unrelated agents. Hide current owned daemon console only after checking exact parent/command/title.

Confirmed source hole: Antigravity Session.retire uses void driver.stop(...).then(success) without rejection owner. Reproduce using actual bundled Session.prototype with fake disposable Driver rejection (no AGY, taskkill or native daemon). Add rejection handling at retire: emit structured runtime failure with original cleanup exit/message, preserve stopping state on failure and keep global fatal handler. No broad255 swallowing or false cleanup success. Unknown historical caller stays UNKNOWN.

Before/after actual-source fixture: success, exit128/255/general rejection, stale state; verify no unhandled rejection after fix and truthful runtime_failed outcome. node --check supervisor and compile actual TS module. Back up exact original bytes, write atomic under host lease, independent review current hashes. Do not restart/cancel daemon or active agents, install/update package, touch other projects, reopen063/069 or activate064/V4. Publish reviewed CEO tooling evidence on owned branch; no product PASS. One20min attempt from host lease acquired.
