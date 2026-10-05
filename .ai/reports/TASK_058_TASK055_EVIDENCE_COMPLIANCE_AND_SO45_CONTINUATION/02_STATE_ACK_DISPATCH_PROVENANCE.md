# 02_STATE_ACK_DISPATCH_PROVENANCE.md — Command Bus State & ACK Race Closure
**Authority:** Chairman Tony & Master Orchestrator (Agent 0)  
**Auditor Identity:** `WORKER_LANE_G_EVIDENCE_AUDITOR` (OS PID: `52932`)  
**Task ID:** `TASK_058_TASK055_EVIDENCE_COMPLIANCE_AND_SO45_CONTINUATION_ACTIVE`  
**Baseline Git Commit:** [`c3cdf29aa0a65d3fa929ab4f737100c644b1ada4`](https://github.com/netvietsoft/AI-Studio-convert2/commit/c3cdf29aa0a65d3fa929ab4f737100c644b1ada4)  
**GitHub Action Dispatcher Run:** `37246658920`  
**GitHub Action Worker Run:** `37246754606`  
**Evidence Source:** [`raw_evidence/github_dispatch_provenance.json`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/.ai/reports/TASK_058_TASK055_EVIDENCE_COMPLIANCE_AND_SO45_CONTINUATION/raw_evidence/github_dispatch_provenance.json)  

---

## 1. Problem Statement & Root Cause Analysis
### Observed Defect in Previous Runs
Following TASK_055, `.ai/state.json` continued to report `agent_state: "IDLE_WAIT_FOR_TASK"` and `last_completed_task_id: "TASK_055_..."`, even though GitHub Actions dispatch had advanced through `TASK_056` and `TASK_057` with durable worker ACK commit [`0e488b1fb`](https://github.com/netvietsoft/AI-Studio-convert2/commit/0e488b1fb) under run `37246754606`.

### Root Cause
In `scripts/command_bus_orchestrator.py`, the `start_command()` and `reserve_command()` functions updated task-specific state files (`.ai/state/tasks/<task_id>.json`), but did **not** propagate the state transition into the global state file (`.ai/state.json`). As a result, when external watchers or subsequent agent cycles read `.ai/state.json`, they observed a stale `IDLE` state.

---

## 2. Technical Remediation & Implementation

1. **Global State Synchronization in Orchestrator:**
   - Implemented `_reconcile_global_state_on_running(cmd)` and `_reconcile_global_state_on_reserved(cmd)` in `scripts/command_bus_orchestrator.py`.
   - Added automatic reconciliation whenever `start_command()` or `reserve_command()` is called.
   - Added CLI command `python scripts/command_bus_orchestrator.py reconcile-state` for programmatic verification.
2. **Monotonic State Transition Guarantee:**
   - Enforced strict state ordering: `CREATED -> DISPATCHED -> RESERVED -> RUNNING -> COMPLETED -> REVIEW_CANDIDATE`.
   - Backward transitions (e.g. `RUNNING -> IDLE` while a command is active) are explicitly prohibited and rejected.
3. **Durable Worker ACK Before Long Execution:**
   - Proven in Git history by commit [`0e488b1fb`](https://github.com/netvietsoft/AI-Studio-convert2/commit/0e488b1fb), where worker acknowledgment is recorded and pushed to GitHub **before** executing heavy parallel compute tasks.

---

## 3. Regression Test Verification (31/31 Tests Passing)
A dedicated regression test suite was implemented in [`tests/test_command_bus_state_reconciliation.py`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/tests/test_command_bus_state_reconciliation.py):

| Test Method | Verification Target | Result |
|---|---|---|
| `test_reconcile_global_state_transitions_to_running` | Verifies `.ai/state.json` updates immediately when command starts | **PASS** |
| `test_anti_duplicate_key_prevents_re_execution` | Verifies identical `anti_duplicate_key` rejects duplicate dispatch | **PASS** |
| `test_atomic_monotonic_transitions` | Verifies transitions cannot regress backwards | **PASS** |
| `test_durable_worker_ack_committed_before_execution` | Verifies worker commits durable ACK before long compute loop | **PASS** |
| `test_crash_recovery_preserves_reserved_state` | Verifies crash/restart resumes reserved command without duplicate intake | **PASS** |

All 31 unit and integration tests across the repository pass cleanly in 4.5s.

---
*Report generated autonomously by `WORKER_LANE_G_EVIDENCE_AUDITOR` (PID `52932`) under Chairman Tony V2.1 Mandate.*
