# 09. FAILURES, ROOT CAUSES & VERIFIED RETESTS
**Task ID:** `TASK_021_TRUE_MULTI_AGENT_MULTI_TASK_DISPATCHER_RUNNER_POOL_ACTIVE`  
**Command ID:** `TASK_021_TRUE_MULTI_AGENT_MULTI_TASK_20261003T074500+0700`  
**Date:** 2026-10-03  
**Status:** PASS & VERIFIED (Zero Unresolved Failures)

---

## 1. EVIDENCE-BASED DISCLOSURE
In accordance with `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` and Project CONVERT2 core rules, all failures encountered during the engineering and validation of the multi-agent multi-task infrastructure are disclosed transparently below, alongside their root cause analysis and empirical retest verification.

---

## 2. DETAILED FAILURE LOG

### 2.1 Failure 1: GitHub Actions Git Push Credential Refusal (403)
- **Symptom:** Worker workflows attempting to push task branches (`agent/<command_id>`) failed with:
  ```text
  fatal: unable to access 'https://github.com/netvietsoft/AI-Studio-convert2/': The requested URL returned error: 403
  ```
- **Root Cause:** By default, `actions/checkout` injects a local git config header:
  `http.https://github.com/.extraheader`
  containing the ephemeral Actions installation token. Even when `gh auth setup-git` was executed with a Personal Access Token (`AI_STUDIO_TOKEN`), Git prioritized the `.extraheader` authorization, which lacked write or workflow permissions.
- **Resolution:** Added an explicit cleanup step in `.github/workflows/convert2-worker.yml` prior to pushing:
  ```yaml
  - name: Configure Git for Task Branch Push
    env:
      GH_TOKEN: ${{ secrets.AI_STUDIO_TOKEN || github.token }}
    run: |
      git config --local --unset-all http.https://github.com/.extraheader || true
      gh auth setup-git
  ```
- **Retest Result:** **PASS**. Worker pushed `agent/CMD_ACCEPT_001_...` cleanly without error.

---

### 2.2 Failure 2: PowerShell Variable Colon Drive-Letter Expansion Error
- **Symptom:** Worker script crashed during task state recording with:
  ```text
  InvalidVariableReferenceWithDrive: The variable cannot be validated because the drive TaskId does not exist.
  ```
- **Root Cause:** In PowerShell, `$TaskId: COMPLETED` is interpreted as variable `$COMPLETED` on the drive `$TaskId:`.
- **Resolution:** Fixed syntax across acceptance scripts by wrapping variable references in subexpressions:
  `$($TaskId): COMPLETED` (committed in `8dc4fe2`).
- **Retest Result:** **PASS**. State updates executed cleanly.

---

### 2.3 Failure 3: Native Stderr Triggering Fatal `RemoteException`
- **Symptom:** Acceptance task script crashed when running `agy --help 2>&1`:
  ```text
  RemoteException: usage: agy [-h] ...
  ```
- **Root Cause:** Scripts configured with `$ErrorActionPreference = "Stop"` treat any native stderr stream output as an unhandled PowerShell terminating exception.
- **Resolution:** Temporarily set `$ErrorActionPreference = "Continue"` during CLI version queries.
- **Retest Result:** **PASS**. Toolchain versions reported properly.

---

### 2.4 Failure 4: Path Gate Logic Flaw in `command_bus_orchestrator.py`
- **Symptom:** The Serial Integrator rejected valid task branches with:
  ```text
  BLOCKED_SCOPE_VIOLATION: File modified outside allowed paths: .ai/commands/running/...
  ```
- **Root Cause:** `verify_branch()` invoked `paths_conflict()`. That function was designed for pairwise task conflict checking (returning `False` when paths do not overlap). Applying it to branch file verification inverted the logic on shared tracking directories.
- **Resolution:** Implemented dedicated `file_matches_allowed_path(file_path, allowed_paths)` and added `is_shared_reconciled_path()` to whitelist command bus state files and logs (`.ai/commands/**`, `.ai/state/**`, `TASK_LOG.md`) (committed in `e38b2db`).
- **Retest Result:** **PASS**. Integrator verified `CMD_ACCEPT_001` cleanly.

---

### 2.5 Failure 5: Merge Conflicts on Derived Tracking Index (`index.json`)
- **Symptom:** Concurrently completing branches produced git merge conflicts on `.ai/commands/index.json`:
  ```text
  CONFLICT (content): Merge conflict in .ai/commands/index.json
  Automatic merge failed; fix conflicts and then commit the result.
  ```
- **Root Cause:** Multiple tasks updating their statuses simultaneously touched the same index dictionary lines.
- **Resolution:** Added auto-reconciliation in `.github/workflows/convert2-integrator.yml`:
  1. Check `git status --porcelain` for conflicted files.
  2. If conflicts are limited to derived state files (e.g. `.ai/commands/index.json`), check out the branch version.
  3. Execute `python scripts/command_bus_orchestrator.py rebuild-index` to reconstruct the complete index from disk truth.
  4. Commit the resolved index and push (committed in `5981299`).
  5. If true source code files conflict, abort with `BLOCKED_MERGE_CONFLICT`.
- **Retest Result:** **PASS**. Integrator runs `37089986174` and `37089992350` auto-reconciled and merged both branches cleanly.

---

## 3. VERDICT
**VERDICT: PASS**  
Every intermediate failure was systematically analyzed, permanently resolved in code, and verified via end-to-end execution. Zero regressions or bypasses exist.
