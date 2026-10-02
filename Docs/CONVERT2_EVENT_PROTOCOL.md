# CONVERT2 EVENT PROTOCOL V1

**Status:** Canonical message-bus contract  
**Authority:** Chủ tịch Tony  
**Repository:** `netvietsoft/AI-Studio-convert2`

## Architecture

```text
Antigravity Agent
→ persistent GitHub control PR
→ ChatGPT Work Auditor
→ .ai/commands/NEXT_COMMAND.json
→ GitHub Actions self-hosted runner
→ Antigravity Agent
→ ...
```

Tony only participates for real human-decision gates.

## Source of truth

- Task Drive = authorization/scope.
- GitHub source/commit = code truth.
- Report Drive = canonical evidence handoff.
- PR event = wake-up signal for Auditor.
- `.ai/commands/NEXT_COMMAND.json` = wake-up signal for Agent.
- ChatGPT Work = Auditor/planner.
- Antigravity = executor.
- Self-hosted runner = local wake-up bridge.

A signal never expands authorization.

## Agent → Auditor message

Agent comments on one persistent control PR:

```text
CONVERT2_EVENT_V1
type: REPORT_READY
event_id: TASK_003:<HEAD_SHA>
task_id: TASK_003_HCE_V1_GPU_EVIDENCE_INTEGRITY_AND_PHYSICAL_RERUN
head_sha: <FULL_40_HEX_SHA>
report_path: .ai/reports/TASK_003_HCE_V1_GPU_EVIDENCE_INTEGRITY_AND_PHYSICAL_RERUN_REPORT/
agent_verdict: COMPLETED
```

Checkpoint event:

```text
CONVERT2_EVENT_V1
type: CHECKPOINT_READY
event_id: TASK_003:<HEAD_SHA>:RAW_HARDWARE
task_id: TASK_003_HCE_V1_GPU_EVIDENCE_INTEGRITY_AND_PHYSICAL_RERUN
phase: RAW_HARDWARE
head_sha: <FULL_40_HEX_SHA>
report_path: .ai/reports/TASK_003_HCE_V1_GPU_EVIDENCE_INTEGRITY_AND_PHYSICAL_RERUN_REPORT/
```

Rules:
- `event_id` must be unique.
- `head_sha` must resolve on GitHub.
- Auditor ignores previously processed `event_id`.
- Agent never emits `CONVERT2_COMMAND_V1`.

## Auditor → Agent command

Auditor creates/updates:

`.ai/commands/NEXT_COMMAND.json`

Example:

```json
{
  "protocol": "CONVERT2_COMMAND_V1",
  "command_id": "AUDIT_TASK_003_0001",
  "audit_verdict": "NEEDS_FIX",
  "action": "EXECUTE_TASK",
  "task_id": "TASK_003A_HCE_EVIDENCE_CORRECTION",
  "task_url": "https://docs.google.com/document/d/<DOCUMENT_ID>/edit",
  "issued_for_sha": "<AUDITED_HEAD_SHA>",
  "issued_at": "2026-10-02T14:00:00+07:00"
}
```

Allowed `action`:
- `EXECUTE_TASK`
- `WAITING_TONY`
- `NO_ACTION`

The local runner executes only `EXECUTE_TASK`.

## Security

The JSON command is a wake-up signal, not authorization.

Before Agent work:
1. task URL must be HTTPS.
2. Host must be `docs.google.com` or `drive.google.com`.
3. Task ID must be valid.
4. Agent must read the actual Task document.
5. Task must contain `STATUS: ACTIVE`.
6. Scope comes from Task Drive.
7. Destructive actions, new credentials/costs, frozen-scope changes and production release still require their normal gates.

## ChatGPT Work Auditor prompt

Use this as the Work instruction:

```text
You are the CONVERT2 Autonomous Auditor.

Repository:
netvietsoft/AI-Studio-convert2

Canonical Task Drive:
https://drive.google.com/drive/u/0/folders/1T9_2fbCGa-q8N6kOZ69WAztLlGmJu60h

Canonical Report Drive:
https://drive.google.com/drive/u/0/folders/13xDIqiI-vyP10pkypLI_6palmeJS-QRg

Trigger only for PR activity containing CONVERT2_EVENT_V1.

Ignore CONVERT2_COMMAND_V1 and previously processed event_id values.

For CHECKPOINT_READY or REPORT_READY:
1. Resolve head_sha.
2. Fetch source/diff.
3. Read .ai/state.json.
4. Read declared report/evidence.
5. Check Report Drive.
6. Check Task Drive.
7. Audit using:
   source commit > raw runtime evidence > raw CSV/benchmark >
   manifest/freeze > Tester/Reviewer > executive report.
8. Decide PASS / NEEDS_FIX / BLOCKED.
9. Never accept prose over contradictory source/raw evidence.
10. If autonomous continuation is possible, create the next STATUS=ACTIVE Task in Task Drive.
11. Create/update .ai/commands/NEXT_COMMAND.json with protocol CONVERT2_COMMAND_V1 and action EXECUTE_TASK.
12. Commit the command file to main.
13. If Tony must decide, set action WAITING_TONY.
14. Never process your own command commit as an Agent report.
15. P7 remains blocked unless a canonical ACTIVE Task explicitly authorizes it.
```

## One-time setup

1. Commit:
   - `.github/workflows/convert2-command-bus.yml`
   - `scripts/run_agent_from_github_command.ps1`
   - `docs/CONVERT2_EVENT_PROTOCOL.md`
2. Create initial `.ai/commands/NEXT_COMMAND.json` with `action: NO_ACTION`.
3. Register a Windows GitHub Actions self-hosted runner with labels:
   `self-hosted`, `Windows`, `convert2`.
4. Keep the runner service online.
5. Create one persistent control PR.
6. Configure ChatGPT Work trigger on PR activity.
7. Use the Auditor prompt above.
8. Keep V3 watchdog as low-frequency fallback.
