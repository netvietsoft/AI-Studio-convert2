# 01. ROOT CAUSE ANALYSIS & INCIDENT POST-MORTEM
**Task ID:** `TASK_021_TRUE_MULTI_AGENT_MULTI_TASK_DISPATCHER_RUNNER_POOL_ACTIVE`  
**Command ID:** `TASK_021_TRUE_MULTI_AGENT_MULTI_TASK_20261003T074500+0700`  
**Date:** 2026-10-03  
**Status:** COMPLETE & RESOLVED

---

## 1. INCIDENT BACKGROUND
On 2026-10-03 at approximately 08:10+07:00, an independent system audit of CONVERT2 evaluated the claim of "True Multi-Agent / Multi-Task Concurrency". The audit revealed that while tasks were structured into multiple files, the runtime execution layer failed to provide true concurrent execution. Instead, the architecture exhibited severe failure modes that collapsed parallel workflows, queued tasks linearly, and created race conditions.

---

## 2. DETAILED ROOT CAUSE BREAKDOWN

### 2.1 Concurrency Group Collapse (`cancel-in-progress: true`)
- **Vulnerability:** In `.github/workflows/convert2-command-bus.yml`, the workflow concurrency was defined as:
  ```yaml
  concurrency:
    group: convert2-command-bus
    cancel-in-progress: true
  ```
- **Consequence:** Whenever an active agent or developer committed and pushed changes to `main`, GitHub Actions immediately evaluated `group: convert2-command-bus` as already active. Because `cancel-in-progress: true` was set, GitHub Actions forcibly killed the actively running agent job mid-execution.
- **Impact:** Long-running tasks (e.g. Vulkan shader benchmarks, physical device test suites, or large model weight downloads) were repeatedly terminated whenever any commit landed on `main`.

### 2.2 Single Physical Runner Bottleneck
- **Vulnerability:** The repository was bound to only a single registered self-hosted runner: `CONVERT2-WINDOWS-01` (`worker-1`).
- **Consequence:** Regardless of how many tasks were queued or dispatched, GitHub Actions could only place one job on the single runner at any given time. All other dispatched workflows were placed in `queued` state.
- **Impact:** There was zero wall-clock parallelism. Tasks were executed in strict sequence, masquerading as a multi-agent system while running on a single sequential worker.

### 2.3 Implicit Worker Binding & Race Conditions
- **Vulnerability:** The legacy command runner script (`run_agent_from_github_command.ps1`) did not require an explicit command ID. If no command ID was passed, it scanned the directory and picked `NEXT_COMMAND.json` or whatever file was first in alphabetical order.
- **Consequence:** If multiple runners had been connected, they would have raced to read the same `NEXT_COMMAND.json` or claim the same pending file simultaneously, causing duplicate execution, corrupted leases, or conflicting branch commits.

### 2.4 Unsafe Local Reservation vs Remote Repository Visibility
- **Vulnerability:** In the legacy design, command claiming occurred purely in the local workspace of the runner during execution. The remote GitHub repository had no awareness of a command being "reserved" until the runner pushed its `running/` state update.
- **Consequence:** A secondary runner or dispatcher polling the repository saw the command as still `PENDING`, leading to double-dispatching and race conditions.

### 2.5 Direct-to-Main Pushes & Push Rejection Cascades
- **Vulnerability:** Workers executed tasks directly on `main` and pushed directly to `origin main`.
- **Consequence:** If Worker A finished slightly before Worker B, Worker A's push succeeded. Worker B's subsequent push to `origin main` was rejected with `[rejected - non-fast-forward]`. Worker B either crashed or had to execute unpredictable pull/merge loops in an unmonitored script environment.

---

## 3. REMEDIATION ARCHITECTURE SUMMARY
To permanently eliminate these failure modes, the system was refactored into a Tripartite Architecture:

| Failure Mode | Root Cause | Solution Implemented |
| :--- | :--- | :--- |
| **Push Cancellation** | Shared workflow concurrency group | Split into Dispatcher, Worker, Integrator with per-command worker groups (`convert2-worker-${{ inputs.command_id }}`) |
| **Sequential Bottleneck** | 1 single Windows runner | Provisioned and registered 3 Windows runners (`CONVERT2-WINDOWS-01`, `02`, `03`) on host `OSIN` |
| **Implicit Claim Races** | Workers claiming `NEXT_COMMAND.json` | Explicit `-CommandId` binding enforced; runner crashes with `BLOCKED_BINDING_MISMATCH` if mismatch |
| **Invisible Reservation** | Local-only state change | Atomic remote reservation: moves to `.ai/commands/reserved/` and pushes to `main` before worker dispatch |
| **Push Rejection** | Multiple workers pushing to `main` | Workers push strictly to isolated branches `agent/<command_id>`; Serial Integrator reconciles to `main` |

---

## 4. VERIFICATION
All root causes have been systematically addressed and verified through live GitHub Actions execution of acceptance tasks (`CMD_ACCEPT_001`, `CMD_ACCEPT_002`, `CMD_ACCEPT_003`) running concurrently across `CONVERT2-WINDOWS-02` and `CONVERT2-WINDOWS-03` while `CONVERT2-WINDOWS-01` was concurrently active.
