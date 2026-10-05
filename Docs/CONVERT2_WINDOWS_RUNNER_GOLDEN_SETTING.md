# CONVERT2 Windows Self-Hosted Runner — Golden Setting & Recovery Runbook

**Status:** ACTIVE OPERATIONS STANDARD  
**Machine/runner:** CONVERT2-WINDOWS-01  
**Last verified:** 2026-10-05 (Asia/Ho_Chi_Minh)  
**Purpose:** Preserve the known-good Windows self-hosted runner configuration and provide a deterministic recovery procedure after PATH, Git ownership, service-account, or workspace failures.

> This file contains operational settings only. Do not store GitHub tokens, API keys, session cookies, passwords, or other secrets here.

## 1. Golden configuration

### GitHub Actions runner installation

```text
Runner root:
C:\actions-runner

Windows service:
actions.runner.netvietsoft-AI-Studio-convert2.CONVERT2-WINDOWS-01

Service executable:
C:\actions-runner\bin\RunnerService.exe

Service account:
LocalSystem

Required service state:
Running
```

The runner is intentionally installed under `C:\actions-runner`, which is accessible to Windows system accounts.

### CONVERT2 working repository

```text
C:\actions-runner\convert2\AI-Studio-convert2\AI-Studio-convert2
```

This is the real Git repository. The following directories are **not** the repository root:

```text
C:\Windows\System32
C:\actions-runner
C:\actions-runner\convert2
C:\actions-runner\convert2\AI-Studio-convert2
```

Always verify before running Git operations:

```powershell
$repo = "C:\actions-runner\convert2\AI-Studio-convert2\AI-Studio-convert2"
Set-Location $repo
git rev-parse --show-toplevel
Test-Path "$repo\.git"
```

Expected repository root:

```text
C:/actions-runner/convert2/AI-Studio-convert2/AI-Studio-convert2
```

### AGY

Verified AGY binary:

```text
C:\Users\PC.DESKTOP-81LIH38\AppData\Local\agy\bin\agy.exe
```

Verified version at recovery:

```text
1.2.16
```

Because the GitHub Actions runner runs as **LocalSystem**, a PATH entry that exists only in the interactive user profile is insufficient.

Required AGY directory in **Machine PATH**:

```text
C:\Users\PC.DESKTOP-81LIH38\AppData\Local\agy\bin
```

After changing Machine PATH, restart the GitHub Actions runner service so the service process receives the new environment.

### Other observed tools

At the time of recovery:

```text
Git:
D:\SetupC\Git\cmd\git.exe

Python:
C:\Python314\python.exe
```

Do not assume these remain valid forever. Worker preflight must verify them on every infrastructure recovery.

## 2. Required Git system configuration

The runner uses a Windows system account, so repository trust must be configured at system scope:

```powershell
$repo = "C:\actions-runner\convert2\AI-Studio-convert2\AI-Studio-convert2"

git config --system --add safe.directory "$repo"
git config --system user.name "convert2-worker[bot]"
git config --system user.email "convert2-worker@netviet.internal"
```

Reason: a previous Worker failed because the workspace ownership and service identity differed, causing Git `dubious ownership` failures.

## 3. Canonical recovery procedure

Run PowerShell **as Administrator**.

```powershell
$repo    = "C:\actions-runner\convert2\AI-Studio-convert2\AI-Studio-convert2"
$agyDir  = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\agy\bin"
$service = "actions.runner.netvietsoft-AI-Studio-convert2.CONVERT2-WINDOWS-01"

# A. Verify physical paths.
Test-Path $repo
Test-Path "$repo\.git"
Test-Path "$agyDir\agy.exe"

# All three results MUST be True.

# B. Configure Git for the LocalSystem runner.
git config --system --add safe.directory "$repo"
git config --system user.name "convert2-worker[bot]"
git config --system user.email "convert2-worker@netviet.internal"

# C. Ensure AGY is visible through Machine PATH.
$machinePath = [Environment]::GetEnvironmentVariable("Path", "Machine")
if (($machinePath -split ';') -notcontains $agyDir) {
    $newPath = $machinePath.TrimEnd(';') + ";" + $agyDir
    [Environment]::SetEnvironmentVariable("Path", $newPath, "Machine")
}

# D. Enter the REAL repository.
Set-Location $repo

# E. Non-destructive Git preflight.
git rev-parse --show-toplevel
git rev-parse HEAD
git status --short
git remote -v

# F. Direct AGY verification.
& "$agyDir\agy.exe" --version

# G. Restart service AFTER Machine PATH changes.
Restart-Service -Name $service -Force
Start-Sleep -Seconds 5
Get-Service -Name $service | Format-Table Status,Name -AutoSize
```

Required results:

```text
Test-Path repo       = True
Test-Path .git       = True
Test-Path agy.exe    = True
AGY version          = 1.2.16 (or an explicitly approved newer version)
Runner service       = Running
git status --short   = empty before a clean smoke run
```

## 4. Service-account verification

Never assume the account used by an interactive PowerShell session is the account used by GitHub Actions.

```powershell
Get-CimInstance Win32_Service |
Where-Object { $_.Name -like "actions.runner.netvietsoft-AI-Studio-convert2*" } |
Select-Object Name,State,StartName,PathName |
Format-List
```

Golden result:

```text
StartName : LocalSystem
PathName  : "C:\actions-runner\bin\RunnerService.exe"
State     : Running
```

If `StartName` changes, re-audit PATH visibility, file permissions, Git ownership, AGY availability, and credentials before dispatching production work.

## 5. Worker preflight gate

Before a long-running Agent/SO45/Hair task, the Worker must prove:

```powershell
whoami
Get-Location
git rev-parse --show-toplevel
git status --porcelain
Get-Command git
Get-Command python
Get-Command agy
agy --version
```

Required behavior:

1. Correct repository root.
2. No `dubious ownership`.
3. Git available.
4. Python available.
5. AGY available to the **service process**, not merely the desktop user.
6. No unexplained dirty working tree.
7. Command-bus CLAIM/lease/execution identity is durably visible before long Agent execution.

Failure of any required preflight item means **BLOCKED_INFRA**. Do not start SO45/Hair production work.

## 6. Command-bus safety

The expected lifecycle is:

```text
PENDING/QUEUED
  -> RESERVED
  -> CLAIMED
  -> RUNNING
  -> Worker result
  -> Integrator
  -> COMPLETED
```

A Worker must durably publish CLAIM/lease/RUNNING identity before long-running Agent work.

Do not report a task as running merely because a command file exists.

Do not report physical multi-runner concurrency from local thread/process counts alone. Physical lanes require distinct GitHub Actions run/job/runner evidence.

## 7. Dirty-worktree rule

Before `git pull --rebase`:

```powershell
git status --porcelain
```

If output is non-empty, **do not blindly pull/rebase**.

Determine whether the changes are:

- command-bus state that must be committed transactionally,
- expected Worker output,
- an interrupted previous run,
- or unauthorized/unexpected modifications.

The Dispatcher must not execute `git pull --rebase` on an unexplained dirty working tree.

## 8. Commands forbidden while a Worker is active

Do **not** manually run these against the active workspace while a Worker/Integrator is using it:

```text
git reset --hard
git clean -fd / git clean -fdx
git checkout <other branch>
git switch <other branch>
git pull --rebase
git push
manual deletion of .ai command/state files
manual deletion of Worker evidence/artifacts
```

First verify that no active Worker/Integrator owns the workspace.

## 9. Incident that established this baseline

Observed failure chain:

1. GitHub Actions Worker ran as `LocalSystem`.
2. AGY existed only under the interactive user's profile PATH.
3. Interactive PowerShell could execute `agy`, but the Worker could not.
4. Worker failed with `agy is not available in PATH`.
5. A separate Git ownership mismatch produced `dubious ownership`.
6. Dispatcher rollback/rebase behavior also encountered dirty-worktree failures.

Recovery applied:

- confirmed the real repository path;
- configured Git `safe.directory` at system scope;
- configured system Git bot identity;
- added AGY directory to Machine PATH;
- restarted the GitHub Actions runner service;
- verified repository, AGY 1.2.16, clean working tree, remote, and service state;
- reran the failed Worker as a real validation run.

## 10. Post-recovery acceptance

Infrastructure is not considered fixed merely because commands work in an Administrator terminal.

Final acceptance requires a real GitHub Actions run proving:

```text
Dispatcher
 -> Worker receives command
 -> AGY preflight succeeds under service account
 -> durable CLAIM/RUNNING is visible
 -> Worker succeeds
 -> Integrator succeeds
 -> command reaches COMPLETED
 -> no false rollback to PENDING
```

Only then mark the runner recovery **PASS**.

## 11. Preservation rule

Do not remove the old CONVERT/CONVERT2 architecture merely to repair runner infrastructure. Existing architecture remains available as rollback unless an explicitly approved correction decommissions only a specific automatic trigger.

---

When this machine is rebuilt, the service account changes, AGY is upgraded/moved, or the runner directory changes, update this document and re-run the full smoke acceptance before resuming long-running tasks.
