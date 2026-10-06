param(
    [Parameter(Mandatory = $true)]
    [string]$RepoPath,

    [string]$CommandId = "",

    [string]$ReservationToken = "",

    [string]$CommandFile = "",

    [string]$ExecutionLane = "default",

    [int]$PrintTimeoutMinutes = 90
)

$ErrorActionPreference = "Stop"

function Write-RunnerLog {
    param([string]$Message)
    $runnerDir = Join-Path $RepoPath ".ai\runner"
    New-Item -ItemType Directory -Force -Path $runnerDir | Out-Null
    $ts = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
    $line = "[$ts] $Message"
    Write-Host $line
    Add-Content -Path (Join-Path $runnerDir "command_bus.log") -Value $line
}

function Fail {
    param([string]$Message)
    Write-RunnerLog "BLOCKED: $Message"
    throw $Message
}

function Invoke-RunnerGit {
    param([string]$WorkingTree, [string[]]$Arguments, [switch]$AllowFailure)
    # Windows PowerShell turns redirected native stderr into ErrorRecords. Preserve
    # the actual native exit code rather than treating harmless Git progress as failure.
    $savedPreference = $ErrorActionPreference
    try {
        $ErrorActionPreference = "Continue"
        $output = & git -C $WorkingTree @Arguments 2>$null
        $exitCode = $LASTEXITCODE
    } finally {
        $ErrorActionPreference = $savedPreference
    }
    if ($exitCode -ne 0 -and -not $AllowFailure) {
        throw "Git $($Arguments[0]) failed with exit code $exitCode"
    }
    return [pscustomobject]@{ ExitCode = $exitCode; Output = ($output | Out-String).Trim() }
}

function Set-CommandFailure {
    param([string]$WorkingTree, [string]$FailureMessage)
    if ($env:GITHUB_RUN_ID) {
        $canonicalPath = Join-Path $WorkingTree ".ai\commands\running\$targetCmdId.json"
        if (-not (Test-Path -LiteralPath $canonicalPath)) {
            throw "FAILED transition rejected for $targetCmdId; current canonical lease/status must match this worker"
        }
        $canonical = Get-Content -Raw -LiteralPath $canonicalPath | ConvertFrom-Json
        if ($canonical.lease.lease_token -ne $leaseToken -or $canonical.execution_identity.github_run_id -ne $env:GITHUB_RUN_ID) {
            throw "FAILED transition rejected for $targetCmdId; current canonical lease/status must match this worker"
        }
    }
    $orchestratorPath = Join-Path $RepoPath "scripts\command_bus_orchestrator.py"
    $failureOutput = & python $orchestratorPath --repo-root $WorkingTree fail `
        --command-id $targetCmdId --lease-token $leaseToken --error $FailureMessage 2>&1
    $failureExit = $LASTEXITCODE
    if ($failureExit -ne 0 -or ($failureOutput | Out-String) -notmatch "\[OK\]\s+FAILED") {
        # Do not print the lease or unfiltered subprocess output.
        throw "FAILED transition rejected for $targetCmdId; current canonical lease/status must match this worker"
    }
}

function Publish-CommandFailure {
    param([string]$FailureMessage)
    # Start from canonical main on every attempt. Never merge the task branch into
    # this control-plane update, and revalidate the lease after a concurrent push.
    for ($attempt = 1; $attempt -le 3; $attempt++) {
        $failureWorktree = Join-Path ([System.IO.Path]::GetTempPath()) ("convert2-failure-" + [guid]::NewGuid().ToString("N"))
        $createdWorktree = $false
        try {
            Invoke-RunnerGit $RepoPath @("fetch", "origin", "main") | Out-Null
            $baseSha = (Invoke-RunnerGit $RepoPath @("rev-parse", "refs/remotes/origin/main")).Output
            Invoke-RunnerGit $RepoPath @("worktree", "add", "--detach", "--no-checkout", $failureWorktree, $baseSha) | Out-Null
            $createdWorktree = $true
            # Only materialize lifecycle files; large source/evidence trees stay out.
            Invoke-RunnerGit $failureWorktree @("sparse-checkout", "set", "--no-cone", "/.ai/commands/", "/.ai/state/", "/.ai/state.json") | Out-Null
            Invoke-RunnerGit $failureWorktree @("checkout", "--detach", $baseSha) | Out-Null
            Set-CommandFailure $failureWorktree $FailureMessage
            Invoke-RunnerGit $failureWorktree @("add", "-A", "--", ".ai/commands", ".ai/state", ".ai/state.json", ":(exclude).ai/commands/.bus.lock") | Out-Null
            $changedPaths = (Invoke-RunnerGit $failureWorktree @("diff", "--cached", "--name-only")).Output -split "\r?\n"
            foreach ($changedPath in $changedPaths) {
                if ($changedPath -and $changedPath -notmatch '^\.ai/(commands/|state/|state\.json$)') {
                    throw "Refusing failure publication outside lifecycle metadata"
                }
            }
            Invoke-RunnerGit $failureWorktree @("commit", "-m", "chore(command-bus): durable FAILED for $targetCmdId [run $env:GITHUB_RUN_ID]") | Out-Null
            $push = Invoke-RunnerGit $failureWorktree @("push", "origin", "HEAD:main") -AllowFailure
            if ($push.ExitCode -eq 0) {
                Write-RunnerLog "Durable FAILED state published to remote main for $targetCmdId."
                # Remove only our generated, untracked advisory lock, then ask Git
                # to remove this self-created worktree without force or recursive deletion.
                $busLock = Join-Path $failureWorktree ".ai\commands\.bus.lock"
                $trackedLock = Invoke-RunnerGit $failureWorktree @("ls-files", "--", ".ai/commands/.bus.lock")
                if (-not $trackedLock.Output -and (Test-Path -LiteralPath $busLock)) {
                    Remove-Item -LiteralPath $busLock
                }
                $cleanup = Invoke-RunnerGit $RepoPath @("worktree", "remove", $failureWorktree) -AllowFailure
                if ($cleanup.ExitCode -ne 0) { Write-RunnerLog "Published failure worktree retained for inspection: $failureWorktree" }
                return
            }
            Write-RunnerLog "Failure publication attempt $attempt rejected; retained evidence worktree: $failureWorktree"
            Invoke-RunnerGit $RepoPath @("fetch", "origin", "main") | Out-Null
            $latestSha = (Invoke-RunnerGit $RepoPath @("rev-parse", "refs/remotes/origin/main")).Output
            if ($latestSha -eq $baseSha) {
                throw "FAILED publication push rejected without a concurrent main update (exit $($push.ExitCode))"
            }
        } catch {
            if ($createdWorktree) { Write-RunnerLog "Failure publication evidence preserved at $failureWorktree" }
            throw
        }
    }
    throw "FAILED publication did not succeed after 3 concurrent main updates; runtime was not retried"
}

if (-not (Test-Path $RepoPath)) { throw "RepoPath does not exist: $RepoPath" }

Set-Location $RepoPath

if (-not (Get-Command git -ErrorAction SilentlyContinue)) { Fail "git is not available in PATH." }
if (-not (Get-Command python -ErrorAction SilentlyContinue)) { Fail "python is not available in PATH." }

# Resolve AGY independently of the Windows service PATH.
$agyCommand = Get-Command agy -ErrorAction SilentlyContinue
$agyExe = if ($agyCommand) { $agyCommand.Source } else { $null }
if ([string]::IsNullOrWhiteSpace($agyExe)) {
    $agyCandidates = @(
        $env:AGY_EXE,
        "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\agy\bin\agy.exe"
    ) | Where-Object { -not [string]::IsNullOrWhiteSpace($_) }
    foreach ($candidate in $agyCandidates) {
        if (Test-Path $candidate) { $agyExe = $candidate; break }
    }
}
if ([string]::IsNullOrWhiteSpace($agyExe) -or -not (Test-Path $agyExe)) {
    Fail "agy executable not found. Checked service PATH, AGY_EXE, and known PC profile install path."
}
Write-RunnerLog "Resolved AGY executable: $agyExe"
try {
    $agyVersion = (& $agyExe --version 2>&1 | Out-String).Trim()
    if ($LASTEXITCODE -ne 0) { throw "AGY --version exited with code $LASTEXITCODE" }
    Write-RunnerLog "AGY executable preflight passed: $agyVersion"
} catch {
    Fail "agy executable exists but cannot run under runner service identity: $($_.Exception.Message)"
}

$isRepo = (& git rev-parse --is-inside-work-tree 2>$null)
if ($LASTEXITCODE -ne 0 -or $isRepo.Trim() -ne "true") { Fail "RepoPath is not a Git working tree." }

# Persistent self-hosted runner recovery: an interrupted merge/rebase can leave
# stage 1/2/3 entries in the Git index. That makes one lifecycle JSON appear
# three times to git ls-files --stage and causes false duplicate-command failures.
$unmerged = @(& git ls-files -u)
if ($unmerged.Count -gt 0) {
    Write-RunnerLog "Recovering stale unmerged Git index entries from previous runner turn..."
    & git merge --abort 2>$null
    & git rebase --abort 2>$null
    & git reset --hard HEAD
    if ($LASTEXITCODE -ne 0) {
        Fail "STALE_INDEX_RECOVERY_FAILED: unable to reset unmerged Git index to checked-out HEAD."
    }
    $stillUnmerged = @(& git ls-files -u)
    if ($stillUnmerged.Count -gt 0) {
        Fail "STALE_INDEX_RECOVERY_FAILED: unmerged index entries remain after reset."
    }
    Write-RunnerLog "Stale unmerged Git index cleared; lifecycle index is single-stage again."
}

# CI workspace recovery: a failed prior ACK rebase can leave .git/rebase-merge or
# .git/rebase-apply behind on a persistent self-hosted runner. actions/checkout
# cleans the worktree but does not remove an in-progress rebase under .git.
# Abort only an actual Git rebase before mutating command-bus state.
$gitDir = (& git rev-parse --git-dir).Trim()
$rebaseMerge = Join-Path $gitDir "rebase-merge"
$rebaseApply = Join-Path $gitDir "rebase-apply"
if ((Test-Path $rebaseMerge) -or (Test-Path $rebaseApply)) {
    Write-RunnerLog "Recovering stale Git rebase left by a previous failed runner turn..."
    & git rebase --quit 2>&1 | ForEach-Object { Write-Host $_ }
    if ($LASTEXITCODE -ne 0) {
        Fail "STALE_REBASE_RECOVERY_FAILED: Git reports stale rebase metadata but git rebase --quit failed."
    }
    Write-RunnerLog "Stale Git rebase metadata cleared with --quit; checked-out HEAD/worktree preserved."
}

$runnerDir = Join-Path $RepoPath ".ai\runner"
New-Item -ItemType Directory -Force -Path $runnerDir | Out-Null

# Step 1: Migrate legacy NEXT_COMMAND.json if present
Write-RunnerLog "Checking for legacy command migrations..."
try {
    & python "scripts\command_bus_orchestrator.py" migrate | Out-Null
} catch {
    Write-RunnerLog "Migration notice: $($_.Exception.Message)"
}

# Step 2: Recover any stale leases and reservations
Write-RunnerLog "Checking for stale lease recoveries..."
try {
    & python "scripts\command_bus_orchestrator.py" recover | Out-Null
} catch {
    Write-RunnerLog "Recovery notice: $($_.Exception.Message)"
}

# Step 3: Resolve target Command ID with strict explicit binding
$targetCmdId = $CommandId

if (-not [string]::IsNullOrWhiteSpace($targetCmdId)) {
    Write-RunnerLog "Explicit Command ID provided: $targetCmdId (Strict binding enforced)"
    
    # Locate command file strictly
    $cmdFile = $null
    foreach ($sub in @("reserved", "pending", "claimed", "running", "completed")) {
        $candidatePath = Join-Path $RepoPath ".ai\commands\$sub\$targetCmdId.json"
        if (Test-Path $candidatePath) {
            $cmdFile = $candidatePath
            Write-RunnerLog "Located command file in .ai\commands\$sub\$targetCmdId.json"
            break
        }
    }

    if (-not $cmdFile) {
        Fail "BLOCKED_BINDING_MISMATCH: Command file not found for explicit command_id '$targetCmdId'"
    }
} else {
    # Fallback ONLY when CommandId was not supplied (local watchdog / standalone mode)
    Write-RunnerLog "No explicit CommandId provided. Computing ready set from orchestrator..."
    $readyArgs = @("ready", "--json")
    if (-not [string]::IsNullOrWhiteSpace($ExecutionLane) -and $ExecutionLane -ne "default") {
        $readyArgs += @("--lane", $ExecutionLane)
    }
    $readyJson = & python "scripts\command_bus_orchestrator.py" @readyArgs 2>$null
    try {
        $readyList = $readyJson | ConvertFrom-Json
        if ($readyList -and $readyList.Count -gt 0) {
            $targetCmdId = [string]$readyList[0].command_id
        }
    } catch {}

    if ([string]::IsNullOrWhiteSpace($targetCmdId)) {
        Write-RunnerLog "No ready commands found. Runner standing down cleanly."
        exit 0
    }

    $cmdFile = Join-Path $RepoPath ".ai\commands\reserved\$targetCmdId.json"
    if (-not (Test-Path $cmdFile)) {
        $cmdFile = Join-Path $RepoPath ".ai\commands\pending\$targetCmdId.json"
    }
    if (-not (Test-Path $cmdFile)) {
        Fail "Command file not found for resolved command $targetCmdId"
    }
}

Write-RunnerLog "Selected Command ID: $targetCmdId"
$command = Get-Content -Raw -Path $cmdFile | ConvertFrom-Json

# Anti-duplicate & Status check
if ($command.status -eq "COMPLETED") {
    Write-RunnerLog "Command $targetCmdId is already COMPLETED. Idempotent skip."
    exit 0
}

# Step 4: Claim command atomically
$runnerId = if ($env:GITHUB_RUN_ID) { "GITHUB_ACTIONS_$($env:GITHUB_RUN_ID)" } else { "LOCAL_WATCHDOG_$([Environment]::MachineName)" }
Write-RunnerLog "Claiming command $targetCmdId for $runnerId..."

$claimArgs = @("claim", "--command-id", $targetCmdId, "--runner", $runnerId)
if (-not [string]::IsNullOrWhiteSpace($ReservationToken)) {
    $claimArgs += @("--reservation-token", $ReservationToken)
}

$claimOut = & python "scripts\command_bus_orchestrator.py" @claimArgs 2>&1
$claimExitCode = $LASTEXITCODE
$claimText = ($claimOut | Out-String)
if ($claimExitCode -ne 0 -or $claimText -notmatch "\[OK\]\s+CLAIMED") {
    if ($claimText -match "BLOCKED_BINDING_MISMATCH") {
        Fail "BLOCKED_BINDING_MISMATCH: $claimText"
    }
    Write-RunnerLog "Claim stood down or rejected: $claimText"
    exit 0
}

# Extract lease token from claimed file
$claimedFile = Join-Path $RepoPath ".ai\commands\claimed\$targetCmdId.json"
if (-not (Test-Path $claimedFile)) { Fail "Claimed file not found after claim: $claimedFile" }
$claimedData = Get-Content -Raw -Path $claimedFile | ConvertFrom-Json
$leaseToken = [string]$claimedData.lease.lease_token

# Step 5: Transition to RUNNING with execution identity
$headSha = (Invoke-RunnerGit $RepoPath @("rev-parse", "HEAD")).Output
$wfUrl = if ($env:GITHUB_SERVER_URL -and $env:GITHUB_REPOSITORY -and $env:GITHUB_RUN_ID) {
    "$($env:GITHUB_SERVER_URL)/$($env:GITHUB_REPOSITORY)/actions/runs/$($env:GITHUB_RUN_ID)"
} else { "local://$([Environment]::MachineName)/$targetCmdId" }

Write-RunnerLog "Transitioning $targetCmdId to RUNNING (head=$headSha, run_id=$env:GITHUB_RUN_ID)..."
$startOut = & python "scripts\command_bus_orchestrator.py" start `
    --command-id "$targetCmdId" `
    --lease-token "$leaseToken" `
    --dispatch-sha "$headSha" `
    --run-id "$($env:GITHUB_RUN_ID)" `
    --url "$wfUrl" 2>&1

$startExitCode = $LASTEXITCODE
if ($startExitCode -ne 0 -or ($startOut | Out-String) -notmatch "\[OK\]\s+RUNNING") {
    Fail "Failed to transition $targetCmdId to RUNNING: $startOut"
}

# Step 5A: Persist durable ACK/CLAIM/RUNNING state to main BEFORE long-running task work.
# Dispatcher polls remote main; without this push it cannot observe the worker lease/execution_identity
# and falsely rolls the command back to PENDING after the ACK timeout.
if ($env:GITHUB_RUN_ID) {
    Write-RunnerLog "Persisting durable worker ACK to remote main before task execution..."
    & git add ".ai/commands" ".ai/state" ".ai/state.json" ":(exclude).ai/commands/.bus.lock"
    if ($LASTEXITCODE -ne 0) { Fail "Failed to stage durable worker ACK for $targetCmdId" }
    & git commit -m "chore(command-bus): durable worker ACK for $targetCmdId [run $env:GITHUB_RUN_ID]" --allow-empty
    if ($LASTEXITCODE -ne 0) { Fail "Failed to commit durable worker ACK for $targetCmdId" }

    # Rebase once to preserve any dispatcher-side metadata written after this worker checkout.
    & git pull --rebase origin main
    if ($LASTEXITCODE -ne 0) { Fail "Failed to rebase durable worker ACK for $targetCmdId onto origin/main" }

    & git push origin HEAD:main
    if ($LASTEXITCODE -ne 0) { Fail "Failed to push durable worker ACK for $targetCmdId to origin/main" }
    Write-RunnerLog "Durable worker ACK is visible on remote main."
}

# Step 6: Isolated Task Branch Setup
$attemptIdentity = if ($env:GITHUB_RUN_ID) { "run-$env:GITHUB_RUN_ID" } else { "local-$([Environment]::MachineName)-$PID" }
$taskBranch = "agent/$targetCmdId-$attemptIdentity-$([guid]::NewGuid().ToString('N').Substring(0, 8))"
Write-RunnerLog "Setting up isolated task branch: $taskBranch..."
& git checkout -b "$taskBranch"
if ($LASTEXITCODE -ne 0) {
    Fail "Failed to checkout isolated task branch $taskBranch"
}

# Step 7: Formulate prompt and invoke agy turn
$prompt = @"
CONVERT2 AUTONOMOUS EXECUTION

Authority: Tony.
Protocol: CONVERT2_COMMAND_V2.

Execute this Task:
Command ID: $targetCmdId
Task ID: $($command.task_id)
Task URL: $($command.task_url)
Execution Lane: $ExecutionLane
Dispatch SHA: $headSha

Mandatory rules:
1. Read the Task from the canonical Task Drive URL above.
2. Execute only if the Task itself is STATUS=ACTIVE.
3. The Task document is the authorization source of truth.
4. Read 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD.
5. Do not ask routine permission already granted by STATUS=ACTIVE.
6. Respect frozen scopes, credentials, destructive-action and production-release gates.
7. Build/test/benchmark/validate as required.
8. Commit and push source/evidence checkpoints.
9. When checkpoint/final report is ready, update state truthfully.
10. Update .ai/state/tasks/$($command.task_id).json and .ai/state.json truthfully.
11. Never call CPU fallback GPU success.
12. Do not start P7 unless an ACTIVE Task explicitly authorizes it.
13. End this one execution turn after handoff.
14. Treat the command JSON instructions as mandatory execution requirements:
$([string]$command.instructions)
15. If the ACTIVE Task/command requires parallel lanes, execute substantive independent lanes concurrently where dependencies permit. Use distinct process/worker identity, timestamps, lane-specific raw evidence/output paths, and avoid concurrent writes to the same mutable file. Lane labels alone are not proof of concurrency.
16. On a single physical runner, prefer isolated per-lane workspaces/worktrees or read-only analysis lanes plus one integration writer. Do not misreport local lanes as distinct physical GitHub runners.
17. Preserve the existing architecture as rollback unless the ACTIVE Task explicitly authorizes decommissioning a specific trigger/component.
"@

$rc = 0
if ($command.execution_script -and (Test-Path (Join-Path $RepoPath $command.execution_script))) {
    $execScript = Join-Path $RepoPath $command.execution_script
    Write-RunnerLog "Executing command-specified execution_script: $execScript"
    try {
        & powershell.exe -NoProfile -ExecutionPolicy Bypass -File "$execScript" `
            -CommandId "$targetCmdId" `
            -TaskId "$($command.task_id)" `
            -ExecutionLane "$ExecutionLane" `
            -RepoPath "$RepoPath"
        $rc = $LASTEXITCODE
    } catch {
        $rc = -1
        Write-RunnerLog "execution_script exception: $($_.Exception.Message)"
    }
} else {
    Write-RunnerLog "Launching agy for command_id=$targetCmdId task_id=$($command.task_id)"
    try {
        & $agyExe `
          --dangerously-skip-permissions `
          --mode=accept-edits `
          --print-timeout ("{0}m" -f $PrintTimeoutMinutes) `
          -p $prompt
        $rc = $LASTEXITCODE
    } catch {
        $rc = -1
        Write-RunnerLog "agy exception: $($_.Exception.Message)"
    }
}

$finalHead = (Invoke-RunnerGit $RepoPath @("rev-parse", "HEAD")).Output
$currentBranch = (Invoke-RunnerGit $RepoPath @("rev-parse", "--abbrev-ref", "HEAD")).Output
Write-RunnerLog "Execution turn finished. ExitCode=$rc HEAD=$finalHead on branch $currentBranch"

if ($rc -ne 0) {
    $failureMessage = "Agent runtime execution exited with error code $rc"
    Write-RunnerLog "Persisting FAILED lifecycle before task-branch publication..."
    Set-CommandFailure $RepoPath $failureMessage
    if ($env:GITHUB_RUN_ID) { Publish-CommandFailure $failureMessage }
}

if ($currentBranch -eq "main" -or [string]::IsNullOrWhiteSpace($taskBranch) -or $currentBranch -ne $taskBranch) {
    # Direct main execution (e.g. initial bootstrapping or legacy runner)
    Write-RunnerLog "Direct main execution detected on branch $currentBranch."

    # Record runner state
    @{
        protocol = "CONVERT2_RUNNER_STATE_V2"
        command_id = $targetCmdId
        task_id = [string]$command.task_id
        task_branch = $currentBranch
        finished_at = (Get-Date).ToString("o")
        exit_code = $rc
        dispatch_head_sha = $headSha
        final_head_sha = $finalHead
    } | ConvertTo-Json -Depth 5 | Set-Content -Encoding UTF8 (Join-Path $runnerDir "last_run.json")

    # Complete or fail directly
    $taskStateFile = Join-Path $RepoPath ".ai\state\tasks\$($command.task_id).json"
    $targetSha = $finalHead
    $reportFolder = ""
    $evidenceHash = ""

    if (Test-Path $taskStateFile) {
        try {
            $tsObj = Get-Content -Raw -Path $taskStateFile | ConvertFrom-Json
            if ($tsObj.target_commit_sha) { $targetSha = [string]$tsObj.target_commit_sha }
            if ($tsObj.report_folder) { $reportFolder = [string]$tsObj.report_folder }
            if ($tsObj.evidence_manifest_sha256) { $evidenceHash = [string]$tsObj.evidence_manifest_sha256 }
        } catch {}
    }

    if ([string]::IsNullOrWhiteSpace($reportFolder)) {
        $gStateFile = Join-Path $RepoPath ".ai\state.json"
        if (Test-Path $gStateFile) {
            try {
                $gsObj = Get-Content -Raw -Path $gStateFile | ConvertFrom-Json
                if ($gsObj.last_report_folder) { $reportFolder = [string]$gsObj.last_report_folder }
            } catch {}
        }
    }

    if ($rc -eq 0 -and (-not [string]::IsNullOrWhiteSpace($reportFolder))) {
        Write-RunnerLog "Completing command $targetCmdId in orchestrator directly..."
        $completeOut = & python "scripts\command_bus_orchestrator.py" complete `
            --command-id "$targetCmdId" `
            --lease-token "$leaseToken" `
            --target-sha "$targetSha" `
            --report "$reportFolder" `
            --manifest-hash "$evidenceHash" 2>&1
        $completeExitCode = $LASTEXITCODE
        if ($completeExitCode -ne 0 -or ($completeOut | Out-String) -notmatch "\[OK\]\s+COMPLETED") {
            Fail "Failed to complete $targetCmdId; orchestrator did not acknowledge COMPLETED"
        }
        Write-RunnerLog "Command $targetCmdId completed successfully."
    } elseif ($rc -ne 0) {
        throw "agy exited with code $rc"
    }
} else {
    # Task branch execution
    Write-RunnerLog "Pushing task branch $taskBranch to remote..."
    Invoke-RunnerGit $RepoPath @("add", "-A", "--", ".", ":(exclude).ai/commands/.bus.lock") | Out-Null
    Invoke-RunnerGit $RepoPath @("commit", "-m", "feat($($command.task_id)): autonomous task execution for $targetCmdId", "--allow-empty") | Out-Null
    Invoke-RunnerGit $RepoPath @("push", "origin", $taskBranch) | Out-Null
    Write-RunnerLog "Task branch $taskBranch pushed successfully."

    # Record runner state
    @{
        protocol = "CONVERT2_RUNNER_STATE_V2"
        command_id = $targetCmdId
        task_id = [string]$command.task_id
        task_branch = $taskBranch
        finished_at = (Get-Date).ToString("o")
        exit_code = $rc
        dispatch_head_sha = $headSha
        final_head_sha = $finalHead
    } | ConvertTo-Json -Depth 5 | Set-Content -Encoding UTF8 (Join-Path $runnerDir "last_run.json")

    # Trigger Serial Integrator
    if ($rc -eq 0) {
        Write-RunnerLog "Triggering Serial Integrator for $taskBranch..."
        if ($env:GITHUB_RUN_ID -and (Get-Command gh -ErrorAction SilentlyContinue)) {
            try {
                & gh workflow run convert2-integrator.yml `
                    -f command_id="$targetCmdId" `
                    -f branch="$taskBranch" `
                    -f lease_token="$leaseToken" | Out-Null
                Write-RunnerLog "Dispatched convert2-integrator.yml for $targetCmdId."
            } catch {
                Write-RunnerLog "gh trigger notice: $($_.Exception.Message); running local integrator fallback..."
                & python "scripts\command_bus_orchestrator.py" integrate `
                    --command-id "$targetCmdId" `
                    --branch "$taskBranch" `
                    --lease-token "$leaseToken"
            }
        } else {
            # Standalone / local watchdog integration
            & python "scripts\command_bus_orchestrator.py" integrate `
                --command-id "$targetCmdId" `
                --branch "$taskBranch" `
                --lease-token "$leaseToken"
        }
        Write-RunnerLog "Command $targetCmdId processing completed."
    } else {
        throw "agy exited with code $rc"
    }
}
