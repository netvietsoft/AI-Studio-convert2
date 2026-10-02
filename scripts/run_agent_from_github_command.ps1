param(
    [Parameter(Mandatory = $true)]
    [string]$RepoPath,

    [string]$CommandFile = ".ai\commands\NEXT_COMMAND.json",

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
if (-not (Get-Command agy -ErrorAction SilentlyContinue)) { Fail "agy is not available in PATH." }

$isRepo = (& git rev-parse --is-inside-work-tree 2>$null)
if ($LASTEXITCODE -ne 0 -or $isRepo.Trim() -ne "true") { Fail "RepoPath is not a Git working tree." }

$resolvedCommandPath = Join-Path $RepoPath $CommandFile
if (-not (Test-Path $resolvedCommandPath)) { Fail "Command file not found: $CommandFile" }

try {
    $command = Get-Content -Raw -Path $resolvedCommandPath | ConvertFrom-Json
} catch {
    Fail "Command file is not valid JSON: $($_.Exception.Message)"
}

$required = @("protocol","command_id","action","task_id","task_url","issued_for_sha")
foreach ($field in $required) {
    if (-not ($command.PSObject.Properties.Name -contains $field)) {
        Fail "Missing required command field: $field"
    }
}

if ($command.protocol -ne "CONVERT2_COMMAND_V1") { Fail "Unsupported protocol: $($command.protocol)" }

if ($command.action -ne "EXECUTE_TASK") {
    Write-RunnerLog "No execution requested. action=$($command.action)"
    exit 0
}

if ([string]::IsNullOrWhiteSpace($command.command_id)) { Fail "command_id is empty." }
if ([string]::IsNullOrWhiteSpace($command.task_id)) { Fail "task_id is empty." }
if ($command.task_id -notmatch '^TASK_[A-Z0-9_]+$') { Fail "task_id format invalid: $($command.task_id)" }

$taskUri = $null
if (-not [Uri]::TryCreate([string]$command.task_url, [UriKind]::Absolute, [ref]$taskUri)) {
    Fail "task_url is not a valid absolute URL."
}
if ($taskUri.Scheme -ne "https") { Fail "task_url must use HTTPS." }

$allowedHosts = @("docs.google.com","drive.google.com")
if ($allowedHosts -notcontains $taskUri.Host.ToLowerInvariant()) {
    Fail "task_url host is not authorized: $($taskUri.Host)"
}

$runnerDir = Join-Path $RepoPath ".ai\runner"
New-Item -ItemType Directory -Force -Path $runnerDir | Out-Null

$processedFile = Join-Path $runnerDir "processed_commands.json"
$processed = @()
if (Test-Path $processedFile) {
    try {
        $loaded = Get-Content -Raw $processedFile | ConvertFrom-Json
        if ($loaded) { $processed = @($loaded) }
    } catch {
        Write-RunnerLog "WARNING: processed_commands.json unreadable."
    }
}

$antiDupKey = if ($command.anti_duplicate_key) { [string]$command.anti_duplicate_key } else { "$($command.task_id):$($command.command_id)" }

if ($processed -contains [string]$command.command_id -or $processed -contains $antiDupKey) {
    Write-RunnerLog "Duplicate command ignored: $antiDupKey"
    exit 0
}

# Validation: reject stale command/task mismatch against local completed state
$stateFile = Join-Path $RepoPath ".ai\state.json"
if (Test-Path $stateFile) {
    try {
        $stateObj = Get-Content -Raw $stateFile | ConvertFrom-Json
        if ($stateObj.last_completed_task_id -and $stateObj.last_completed_task_id -eq $command.task_id) {
            $lastMod = $stateObj.last_completed_task_modified_time
            if ($command.issued_at -and $lastMod -and ([DateTime]$command.issued_at -le [DateTime]$lastMod)) {
                Write-RunnerLog "REJECTED: Stale command for already completed task: $($command.task_id) (last_completed=$lastMod)"
                exit 0
            }
        }
    } catch {
        Write-RunnerLog "Notice: state.json check skipped: $($_.Exception.Message)"
    }
}

$prompt = @"
CONVERT2 AUTONOMOUS EXECUTION

Authority: Tony.
Protocol: CONVERT2_COMMAND_V1.

Execute this Task:
Task ID: $($command.task_id)
Task URL: $($command.task_url)

Mandatory rules:
1. Read the Task from the canonical Task Drive URL above.
2. Execute only if the Task itself is STATUS=ACTIVE.
3. The Task document is the authorization source of truth.
4. Read 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD.
5. Do not ask routine permission already granted by STATUS=ACTIVE.
6. Respect frozen scopes, credentials, destructive-action and production-release gates.
7. Build/test/benchmark/validate as required.
8. Commit and push source/evidence checkpoints.
9. When checkpoint/final report is ready, emit CONVERT2_EVENT_V1 through the persistent control PR according to docs/CONVERT2_EVENT_PROTOCOL.md.
10. Update .ai/state.json truthfully.
11. Never call CPU fallback GPU success.
12. Do not start P7 unless an ACTIVE Task explicitly authorizes it.
13. End this one execution turn after handoff. The command bus wakes the next turn.
"@

$processed += [string]$command.command_id
$processed | ConvertTo-Json | Set-Content -Encoding UTF8 $processedFile

Write-RunnerLog "Starting command_id=$($command.command_id) task_id=$($command.task_id)"

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

$head = (& git rev-parse HEAD).Trim()

@{
    protocol = "CONVERT2_RUNNER_STATE_V1"
    command_id = [string]$command.command_id
    task_id = [string]$command.task_id
    finished_at = (Get-Date).ToString("o")
    exit_code = $rc
    final_head_sha = $head
} | ConvertTo-Json -Depth 5 | Set-Content -Encoding UTF8 (Join-Path $runnerDir "last_run.json")

Write-RunnerLog "Agent turn finished. Exit=$rc HEAD=$head"

if ($rc -ne 0) { throw "agy exited with code $rc" }
