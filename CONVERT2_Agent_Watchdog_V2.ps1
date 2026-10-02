param(
    [string]$RepoPath = (Get-Location).Path,
    [int]$IntervalSeconds = 180,
    [int]$PrintTimeoutMinutes = 45,
    [switch]$SafePermissions
)

$ErrorActionPreference = "Continue"

# -------------------------------------------------------------------
# CONVERT2 AGENT WATCHDOG V2
# Authority: Tony
#
# V2 change:
# - Headless Antigravity cannot prompt for command permissions.
# - Therefore autonomous mode uses --dangerously-skip-permissions by default.
# - Pass -SafePermissions only if permissions.allow has already been configured.
# -------------------------------------------------------------------

$TaskDrive = "https://drive.google.com/drive/u/0/folders/1T9_2fbCGa-q8N6kOZ69WAztLlGmJu60h"
$ReportDrive = "https://drive.google.com/drive/u/0/folders/13xDIqiI-vyP10pkypLI_6palmeJS-QRg"
$GitRepoUrl = "https://github.com/netvietsoft/AI-Studio-convert2"
$MasterDoc = "07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD"

$LogDir = Join-Path $RepoPath ".ai\watchdog"
$StateDir = Join-Path $RepoPath ".ai"
$WatchdogState = Join-Path $StateDir "watchdog_state.json"

New-Item -ItemType Directory -Force -Path $LogDir | Out-Null
New-Item -ItemType Directory -Force -Path $StateDir | Out-Null

$mutexName = "Global\CONVERT2_Agent_Watchdog"
$createdNew = $false
$mutex = New-Object System.Threading.Mutex($true, $mutexName, [ref]$createdNew)

if (-not $createdNew) {
    Write-Host "[WATCHDOG] Another CONVERT2 watchdog is already running." -ForegroundColor Yellow
    exit 2
}

function Write-WatchdogLog {
    param([string]$Message)
    $ts = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
    $line = "[$ts] $Message"
    Write-Host $line
    Add-Content -Path (Join-Path $LogDir "watchdog.log") -Value $line
}

function Save-WatchdogState {
    param(
        [string]$Status,
        [string]$LastExitCode = "",
        [string]$LastHead = "",
        [string]$LastRunLog = "",
        [string]$PermissionMode = ""
    )

    $obj = [ordered]@{
        status = $Status
        updated_at = (Get-Date).ToString("o")
        repo_path = $RepoPath
        interval_seconds = $IntervalSeconds
        last_exit_code = $LastExitCode
        last_head_sha = $LastHead
        last_run_log = $LastRunLog
        permission_mode = $PermissionMode
    }

    $obj | ConvertTo-Json -Depth 4 | Set-Content -Encoding UTF8 $WatchdogState
}

function Get-GitHead {
    try {
        $head = (& git -C $RepoPath rev-parse HEAD 2>$null).Trim()
        return $head
    } catch {
        return ""
    }
}

function Test-Prerequisites {
    if (-not (Test-Path $RepoPath)) {
        throw "RepoPath does not exist: $RepoPath"
    }

    if (-not (Get-Command agy -ErrorAction SilentlyContinue)) {
        throw "Cannot find 'agy' in PATH. Run 'agy --version' first."
    }

    if (-not (Get-Command git -ErrorAction SilentlyContinue)) {
        throw "Cannot find 'git' in PATH."
    }

    $isRepo = (& git -C $RepoPath rev-parse --is-inside-work-tree 2>$null)
    if ($LASTEXITCODE -ne 0 -or $isRepo.Trim() -ne "true") {
        throw "RepoPath is not a Git working tree: $RepoPath"
    }
}

$bootstrapPrompt = @"
CONVERT2 LONG-RUN AUTONOMOUS EXECUTION TURN

Authority: Tony.

This is one watchdog-triggered execution turn.
Do NOT ask whether you may begin.

Task Drive:
$TaskDrive

Report Drive:
$ReportDrive

Git repository:
$GitRepoUrl

Mandatory standard:
$MasterDoc

EXECUTION RULES

1. Read the canonical workflow documents, especially $MasterDoc.
2. Scan Task Drive immediately.
3. Select the highest-priority eligible STATUS=ACTIVE task that has not already been completed at its current revision.
4. If an ACTIVE task exists:
   - preflight;
   - execute immediately within authorized scope;
   - build/test/benchmark/validate as required;
   - commit and push source changes when required;
   - submit report/evidence;
   - update local task state.
5. Do NOT request routine confirmation already granted by STATUS=ACTIVE.
6. If a real confirmation gate is encountered:
   - record CONFIRMATION_REQUIRED with decision, options, recommendation, risk and impact;
   - do not invent authority.
7. If no eligible ACTIVE task exists:
   - make no code changes;
   - return NO_ACTIVE_TASK.
8. Do not start P7 unless an explicit ACTIVE task authorizes it.
9. Never call CPU fallback a successful GPU implementation.
10. Git commit/source is the source of truth for code claims.
11. End this headless turn after completing one selected task or determining that no eligible task exists.
12. Do NOT sleep inside the Agent. The external watchdog owns the 3-minute scan cadence.

STATUS=ACTIVE = authorization within declared scope.
TASK COMPLETE != PROJECT COMPLETE.
"@

try {
    Test-Prerequisites
    Set-Location $RepoPath

    $permissionMode = if ($SafePermissions) { "SAFE_CONFIGURED_ALLOW_RULES" } else { "AUTONOMOUS_SKIP_PERMISSIONS" }

    Write-WatchdogLog "Started V2. Repo=$RepoPath Interval=${IntervalSeconds}s Timeout=${PrintTimeoutMinutes}m"
    Write-WatchdogLog "PermissionMode=$permissionMode"

    if (-not $SafePermissions) {
        Write-WatchdogLog "WARNING: Autonomous headless mode is using --dangerously-skip-permissions."
        Write-WatchdogLog "Use only on a trusted development machine/repository."
    }

    Save-WatchdogState -Status "RUNNING" -PermissionMode $permissionMode

    while ($true) {
        $start = Get-Date
        $stamp = $start.ToString("yyyyMMdd_HHmmss")
        $runLog = Join-Path $LogDir "agent_run_$stamp.log"
        $headBefore = Get-GitHead

        Write-WatchdogLog "Launching Antigravity turn. HEAD(before)=$headBefore"

        Save-WatchdogState `
            -Status "AGENT_RUNNING" `
            -LastHead $headBefore `
            -LastRunLog $runLog `
            -PermissionMode $permissionMode

        $agyArgs = @(
            "-p", $bootstrapPrompt,
            "--output-format", "text",
            "--effort", "high",
            "--mode", "accept-edits",
            "--print-timeout", ("{0}m" -f $PrintTimeoutMinutes)
        )

        # IMPORTANT:
        # accept-edits does NOT allow shell/command tool usage in headless mode.
        # For unattended autonomous execution we must skip interactive permission prompts,
        # unless the operator has explicitly configured permissions.allow.
        if (-not $SafePermissions) {
            $agyArgs += "--dangerously-skip-permissions"
        }

        try {
            & agy @agyArgs 2>&1 | Tee-Object -FilePath $runLog
            $exitCode = $LASTEXITCODE
        } catch {
            $exitCode = -1
            $_ | Out-String | Add-Content -Path $runLog
            Write-WatchdogLog "Agent invocation exception: $($_.Exception.Message)"
        }

        $headAfter = Get-GitHead
        $elapsed = [int]((Get-Date) - $start).TotalSeconds

        Write-WatchdogLog "Agent turn finished. Exit=$exitCode Elapsed=${elapsed}s HEAD(after)=$headAfter"

        if ($headAfter -ne $headBefore -and $headAfter) {
            Write-WatchdogLog "New commit detected: $headAfter"
        }

        Save-WatchdogState `
            -Status "IDLE_WAIT_FOR_NEXT_SCAN" `
            -LastExitCode "$exitCode" `
            -LastHead $headAfter `
            -LastRunLog $runLog `
            -PermissionMode $permissionMode

        Write-WatchdogLog "Sleeping ${IntervalSeconds}s before next Task Drive scan..."
        Start-Sleep -Seconds $IntervalSeconds
    }
}
finally {
    Save-WatchdogState -Status "STOPPED"
    if ($mutex) {
        try { $mutex.ReleaseMutex() | Out-Null } catch {}
        $mutex.Dispose()
    }
    Write-WatchdogLog "Stopped."
}
