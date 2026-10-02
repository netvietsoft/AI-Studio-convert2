param(
    [Parameter(Mandatory = $true)]
    [string]$RepoPath,

    [string]$CommandId = "",

    [string]$CommandFile = ".ai\commands\NEXT_COMMAND.json",

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

if (-not (Test-Path $RepoPath)) { throw "RepoPath does not exist: $RepoPath" }

Set-Location $RepoPath

if (-not (Get-Command git -ErrorAction SilentlyContinue)) { Fail "git is not available in PATH." }
if (-not (Get-Command python -ErrorAction SilentlyContinue)) { Fail "python is not available in PATH." }
if (-not (Get-Command agy -ErrorAction SilentlyContinue)) { Fail "agy is not available in PATH." }

$isRepo = (& git rev-parse --is-inside-work-tree 2>$null)
if ($LASTEXITCODE -ne 0 -or $isRepo.Trim() -ne "true") { Fail "RepoPath is not a Git working tree." }

$runnerDir = Join-Path $RepoPath ".ai\runner"
New-Item -ItemType Directory -Force -Path $runnerDir | Out-Null

# Step 1: Migrate legacy NEXT_COMMAND.json if present
Write-RunnerLog "Checking for legacy command migrations..."
try {
    & python "scripts\command_bus_orchestrator.py" migrate | Out-Null
} catch {
    Write-RunnerLog "Migration notice: $($_.Exception.Message)"
}

# Step 2: Recover any stale leases
Write-RunnerLog "Checking for stale lease recoveries..."
try {
    & python "scripts\command_bus_orchestrator.py" recover | Out-Null
} catch {
    Write-RunnerLog "Recovery notice: $($_.Exception.Message)"
}

# Step 3: Resolve target Command ID
$targetCmdId = $CommandId

if ([string]::IsNullOrWhiteSpace($targetCmdId)) {
    # Check if CommandFile was explicitly provided and exists
    $resolvedCommandPath = Join-Path $RepoPath $CommandFile
    if (Test-Path $resolvedCommandPath) {
        try {
            $rawCmd = Get-Content -Raw -Path $resolvedCommandPath | ConvertFrom-Json
            if ($rawCmd.migrated_to_command_id) {
                $targetCmdId = [string]$rawCmd.migrated_to_command_id
            } elseif ($rawCmd.command_id) {
                $targetCmdId = [string]$rawCmd.command_id
            }
        } catch {}
    }
}

if ([string]::IsNullOrWhiteSpace($targetCmdId)) {
    # Query orchestrator for highest-priority ready command
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
        # Fallback to checking pending directory
        $pendingDir = Join-Path $RepoPath ".ai\commands\pending"
        $pendingFiles = @(Get-ChildItem -Path $pendingDir -Filter "*.json" -ErrorAction SilentlyContinue)
        if ($pendingFiles.Count -eq 0) {
            Write-RunnerLog "No pending or ready commands found. Runner standing down cleanly."
            exit 0
        }
        $firstPending = Get-Content -Raw -Path $pendingFiles[0].FullName | ConvertFrom-Json
        $targetCmdId = [string]$firstPending.command_id
    }
}

Write-RunnerLog "Selected Command ID: $targetCmdId"

# Find command JSON file
$cmdFile = Join-Path $RepoPath ".ai\commands\pending\$targetCmdId.json"
if (-not (Test-Path $cmdFile)) {
    # Could be in claimed or running or already completed
    $found = Get-ChildItem -Path (Join-Path $RepoPath ".ai\commands") -Recurse -Filter "$targetCmdId.json" | Select-Object -First 1
    if ($found) {
        Write-RunnerLog "Notice: Command $targetCmdId located in $($found.Directory.Name)"
        $cmdFile = $found.FullName
    } else {
        Fail "Command file not found for $targetCmdId"
    }
}

$command = Get-Content -Raw -Path $cmdFile | ConvertFrom-Json

# Anti-duplicate & Status check
if ($command.status -eq "COMPLETED") {
    Write-RunnerLog "Command $targetCmdId is already COMPLETED. Idempotent skip."
    exit 0
}

# Step 4: Claim command atomically
$runnerId = if ($env:GITHUB_RUN_ID) { "GITHUB_ACTIONS_$($env:GITHUB_RUN_ID)" } else { "LOCAL_WATCHDOG_$([Environment]::MachineName)" }
Write-RunnerLog "Claiming command $targetCmdId for $runnerId..."

$claimOut = & python "scripts\command_bus_orchestrator.py" claim --command-id "$targetCmdId" --runner "$runnerId" 2>&1
$claimExitCode = $LASTEXITCODE
$claimText = ($claimOut | Out-String)
if ($claimExitCode -ne 0 -or $claimText -notmatch "\[OK\]\s+CLAIMED") {
    exit 0
}

# Extract lease token from claimed file
$claimedFile = Join-Path $RepoPath ".ai\commands\claimed\$targetCmdId.json"
if (-not (Test-Path $claimedFile)) { Fail "Claimed file not found after claim: $claimedFile" }
$claimedData = Get-Content -Raw -Path $claimedFile | ConvertFrom-Json
$leaseToken = [string]$claimedData.lease.lease_token

# Step 5: Transition to RUNNING with execution identity
$headSha = (& git rev-parse HEAD).Trim()
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

if ($LASTEXITCODE -ne 0) {
    Fail "Failed to transition $targetCmdId to RUNNING: $startOut"
}

# Step 6: Formulate prompt and invoke agy turn
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
"@

Write-RunnerLog "Launching agy for command_id=$targetCmdId task_id=$($command.task_id)"

$rc = 0
try {
    & agy `
      --dangerously-skip-permissions `
      --mode=accept-edits `
      --print-timeout ("{0}m" -f $PrintTimeoutMinutes) `
      -p $prompt
    $rc = $LASTEXITCODE
} catch {
    $rc = -1
    Write-RunnerLog "agy exception: $($_.Exception.Message)"
}

$finalHead = (& git rev-parse HEAD).Trim()
Write-RunnerLog "agy turn finished. ExitCode=$rc HEAD=$finalHead"

# Step 7: Record runner state
@{
    protocol = "CONVERT2_RUNNER_STATE_V2"
    command_id = $targetCmdId
    task_id = [string]$command.task_id
    finished_at = (Get-Date).ToString("o")
    exit_code = $rc
    dispatch_head_sha = $headSha
    final_head_sha = $finalHead
} | ConvertTo-Json -Depth 5 | Set-Content -Encoding UTF8 (Join-Path $runnerDir "last_run.json")

# Step 8: Complete or Fail Command in Command Bus
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

# Fallback: check global state.json if task state hasn't populated report_folder
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
    Write-RunnerLog "Completing command $targetCmdId in orchestrator..."
    & python "scripts\command_bus_orchestrator.py" complete `
        --command-id "$targetCmdId" `
        --lease-token "$leaseToken" `
        --target-sha "$targetSha" `
        --report "$reportFolder" `
        --manifest-hash "$evidenceHash" | Out-Null
    Write-RunnerLog "Command $targetCmdId completed successfully."
} elseif ($rc -ne 0) {
    Write-RunnerLog "Failing command $targetCmdId in orchestrator..."
    & python "scripts\command_bus_orchestrator.py" fail `
        --command-id "$targetCmdId" `
        --lease-token "$leaseToken" `
        --error "agy execution exited with error code $rc" | Out-Null
    throw "agy exited with code $rc"
}
