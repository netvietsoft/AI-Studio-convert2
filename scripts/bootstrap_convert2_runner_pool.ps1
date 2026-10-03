<#
.SYNOPSIS
    Provisions, configures, validates, and manages the CONVERT2 Windows Runner Pool.
.DESCRIPTION
    Task ID: TASK_021_TRUE_MULTI_AGENT_MULTI_TASK_DISPATCHER_RUNNER_POOL
    Authority: Tony
    Protocol: CONVERT2_COMMAND_V2
    Target Capacity: 3 concurrent self-hosted Windows runners:
      - CONVERT2-WINDOWS-01 (C:\actions-runner)
      - CONVERT2-WINDOWS-02 (C:\actions-runner-02)
      - CONVERT2-WINDOWS-03 (C:\actions-runner-03)
#>

[CmdletBinding()]
param(
    [switch]$StatusOnly,
    [switch]$EnsureRunning,
    [switch]$ForceReconfigure,
    [string]$RepoUrl = "https://github.com/netvietsoft/AI-Studio-convert2",
    [string]$RepoApi = "repos/netvietsoft/AI-Studio-convert2"
)

$ErrorActionPreference = "Stop"

function Write-BootstrapLog {
    param([string]$Message, [string]$Level = "INFO")
    $ts = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
    Write-Host "[$ts] [$Level] $Message"
}

Write-BootstrapLog "=========================================================="
Write-BootstrapLog "CONVERT2 RUNNER POOL BOOTSTRAP & VALIDATION"
Write-BootstrapLog "=========================================================="

# 1. Check Tool Dependencies
Write-BootstrapLog "Validating tool dependencies..."
$missingTools = @()

$gitCmd = Get-Command git -ErrorAction SilentlyContinue
if (-not $gitCmd) { $missingTools += "git" } else { Write-BootstrapLog "  [OK] git: $($gitCmd.Source)" }

$pyCmd = Get-Command python -ErrorAction SilentlyContinue
if (-not $pyCmd) { $missingTools += "python" } else { Write-BootstrapLog "  [OK] python: $($pyCmd.Source)" }

$agyCmd = Get-Command agy -ErrorAction SilentlyContinue
if (-not $agyCmd) { $missingTools += "agy" } else { Write-BootstrapLog "  [OK] agy: $($agyCmd.Source)" }

$adbCmd = Get-Command adb -ErrorAction SilentlyContinue
if (-not $adbCmd) {
    # Check fallback path
    $adbFallback = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
    if (Test-Path $adbFallback) {
        $env:Path = "$env:Path;C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools"
        Write-BootstrapLog "  [OK] adb (auto-resolved from Sdk): $adbFallback"
    } else {
        $missingTools += "adb"
    }
} else {
    Write-BootstrapLog "  [OK] adb: $($adbCmd.Source)"
}

$ghCmd = Get-Command gh -ErrorAction SilentlyContinue
if (-not $ghCmd) { $missingTools += "gh" } else { Write-BootstrapLog "  [OK] gh: $($ghCmd.Source)" }

if ($missingTools.Count -gt 0) {
    Write-BootstrapLog "BLOCKED_DEPENDENCY: Missing tools: $($missingTools -join ', ')" "ERROR"
    exit 1
}

# 2. Check GitHub API Authentication & Runner Administration Permission
Write-BootstrapLog "Checking GitHub authentication and runner registration privileges..."
try {
    $authStatus = & gh auth status 2>&1
    Write-BootstrapLog "  [OK] gh authenticated."
} catch {
    Write-BootstrapLog "BLOCKED_RUNNER_REGISTRATION: gh is not authenticated." "ERROR"
    Write-BootstrapLog "Tony must run: gh auth login" "ERROR"
    exit 1
}

# 3. Define Runner Pool Instances
$runnerZipPath = "C:\actions-runner\actions-runner-win-x64-2.337.0.zip"
$poolConfig = @(
    @{
        Name = "CONVERT2-WINDOWS-01"
        Path = "C:\actions-runner"
        Work = "convert2"
        Label = "worker-1"
        ServiceBased = $true
    },
    @{
        Name = "CONVERT2-WINDOWS-02"
        Path = "C:\actions-runner-02"
        Work = "_work"
        Label = "worker-2"
        ServiceBased = $false
    },
    @{
        Name = "CONVERT2-WINDOWS-03"
        Path = "C:\actions-runner-03"
        Work = "_work"
        Label = "worker-3"
        ServiceBased = $false
    }
)

function Get-FreshRegistrationToken {
    try {
        $json = & gh api -X POST "$RepoApi/actions/runners/registration-token" 2>&1
        $obj = $json | ConvertFrom-Json
        if ($obj.token) {
            return $obj.token
        }
        throw "No token in response: $json"
    } catch {
        Write-BootstrapLog "BLOCKED_RUNNER_REGISTRATION: Failed to generate runner registration token." "ERROR"
        Write-BootstrapLog "Error: $($_.Exception.Message)" "ERROR"
        Write-BootstrapLog "Tony must ensure the token has 'admin:org' or repo administration write access." "ERROR"
        exit 1
    }
}

# 4. Process Each Runner
foreach ($r in $poolConfig) {
    Write-BootstrapLog "Checking runner: $($r.Name) in $($r.Path)..."
    
    # Ensure directory
    if (-not (Test-Path $r.Path)) {
        New-Item -ItemType Directory -Path $r.Path -Force | Out-Null
    }

    $configFile = Join-Path $r.Path "config.cmd"
    $runnerConfigFile = Join-Path $r.Path ".runner"

    # If not extracted, extract from zip
    if (-not (Test-Path $configFile)) {
        if (-not (Test-Path $runnerZipPath)) {
            Write-BootstrapLog "BLOCKED_MISSING_PACKAGE: Cannot find runner zip at $runnerZipPath" "ERROR"
            exit 1
        }
        Write-BootstrapLog "  Extracting runner binary package to $($r.Path)..."
        Expand-Archive -Path $runnerZipPath -DestinationPath $r.Path -Force
    }

    # Configure runner if not configured or if ForceReconfigure is specified
    $isConfigured = Test-Path $runnerConfigFile
    if (-not $isConfigured -or $ForceReconfigure) {
        Write-BootstrapLog "  Registering runner $($r.Name) with GitHub..."
        $regToken = Get-FreshRegistrationToken
        
        $cfgArgs = @(
            "/c", "config.cmd",
            "--url", $RepoUrl,
            "--token", $regToken,
            "--name", $r.Name,
            "--work", $r.Work,
            "--labels", "self-hosted,Windows,X64,convert2,$($r.Label)",
            "--unattended",
            "--replace"
        )
        
        Push-Location $r.Path
        $cfgOut = & cmd.exe @cfgArgs 2>&1
        $cfgCode = $LASTEXITCODE
        Pop-Location

        if ($cfgCode -ne 0) {
            Write-BootstrapLog "  Configuration failed for $($r.Name): $cfgOut" "ERROR"
            exit 1
        }
        Write-BootstrapLog "  [OK] Successfully configured $($r.Name)"
    } else {
        Write-BootstrapLog "  [OK] $($r.Name) is already configured."
    }

    # Ensure Labels via GitHub API
    try {
        $runnersJson = & gh api "$RepoApi/actions/runners" | ConvertFrom-Json
        $matched = $runnersJson.runners | Where-Object { $_.name -eq $r.Name }
        if ($matched) {
            $existingLabels = $matched.labels | ForEach-Object { $_.name }
            if ($existingLabels -notcontains $r.Label) {
                Write-BootstrapLog "  Adding custom label '$($r.Label)' to $($r.Name)..."
                & gh api -X POST "$RepoApi/actions/runners/$($matched.id)/labels" -f "labels[]=$($r.Label)" | Out-Null
            }
        }
    } catch {
        Write-BootstrapLog "  Label sync warning: $($_.Exception.Message)" "WARN"
    }

    # Ensure Runner Process is Running
    if (-not $StatusOnly) {
        $activeListeners = Get-CimInstance Win32_Process | Where-Object {
            $_.Name -eq "Runner.Listener.exe" -and $_.ExecutablePath -like "$($r.Path)*"
        }

        if (-not $activeListeners) {
            Write-BootstrapLog "  Runner $($r.Name) is not currently running. Launching detached listener..."
            $runCmd = "cmd.exe /c $($r.Path)\run.cmd"
            $res = Invoke-CimMethod -ClassName Win32_Process -MethodName Create -Arguments @{
                CommandLine = $runCmd
                CurrentDirectory = $r.Path
            }
            if ($res.ReturnValue -ne 0) {
                Write-BootstrapLog "  Failed to launch listener for $($r.Name), return value: $($res.ReturnValue)" "ERROR"
            } else {
                Write-BootstrapLog "  [OK] Launched $($r.Name) (PID: $($res.ProcessId))"
            }
        } else {
            Write-BootstrapLog "  [OK] $($r.Name) listener is active (PID: $($activeListeners.ProcessId))"
        }
    }
}

# 5. Verify Pool Status via GitHub API or Local Process Inspection
Start-Sleep -Seconds 2
Write-BootstrapLog "=========================================================="
Write-BootstrapLog "CURRENT GITHUB ACTIONS RUNNER POOL INVENTORY"
Write-BootstrapLog "=========================================================="

$apiRunners = $null
try {
    $apiRunners = & gh api "$RepoApi/actions/runners" 2>$null | ConvertFrom-Json
} catch {
    $apiRunners = $null
}

$onlineCount = 0

if ($apiRunners -and $apiRunners.runners) {
    foreach ($runner in $apiRunners.runners) {
        $lbls = ($runner.labels | ForEach-Object { $_.name }) -join ", "
        $isOnline = ($runner.status -eq "online")
        if ($isOnline) { $onlineCount++ }
        $statusText = if ($isOnline) { "[ONLINE]" } else { "[OFFLINE]" }
        $busyText = if ($runner.busy) { "(BUSY)" } else { "(IDLE)" }
        Write-BootstrapLog "$statusText $($runner.name) (ID: $($runner.id)) $busyText - Labels: [$lbls]"
    }
    Write-BootstrapLog "----------------------------------------------------------"
    Write-BootstrapLog "Summary: $onlineCount / $($apiRunners.total_count) runners ONLINE (Capacity: $onlineCount)"
} else {
    Write-BootstrapLog "GitHub API runner query restricted or unavailable; checking local runner listeners on host..." "INFO"
    foreach ($r in $poolConfig) {
        $activeListeners = Get-CimInstance Win32_Process | Where-Object {
            $_.Name -eq "Runner.Listener.exe" -and $_.ExecutablePath -like "$($r.Path)*"
        }
        $activeWorkers = Get-CimInstance Win32_Process | Where-Object {
            $_.Name -eq "Runner.Worker.exe" -and $_.ExecutablePath -like "$($r.Path)*"
        }
        $isOnline = ($activeListeners -ne $null)
        if ($isOnline) { $onlineCount++ }
        $statusText = if ($isOnline) { "[ONLINE]" } else { "[OFFLINE]" }
        $busyText = if ($activeWorkers) { "(BUSY)" } else { "(IDLE)" }
        $pidText = if ($activeListeners) { "(PID: $($activeListeners.ProcessId))" } else { "" }
        Write-BootstrapLog "$statusText $($r.Name) $pidText $busyText - Work: $($r.Work), Label: $($r.Label)"
    }
    Write-BootstrapLog "----------------------------------------------------------"
    Write-BootstrapLog "Summary: $onlineCount / $($poolConfig.Count) local runners ONLINE (Capacity: $onlineCount)"
}

if ($onlineCount -lt 3) {
    Write-BootstrapLog "WARNING: Capacity ($onlineCount) is below target of 3 concurrent runners." "WARN"
    exit 2
} else {
    Write-BootstrapLog "SUCCESS: Full capacity (3/3) active and listening for jobs." "INFO"
    exit 0
}
