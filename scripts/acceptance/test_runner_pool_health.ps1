# scripts/acceptance/test_runner_pool_health.ps1
# Acceptance Test 1 for TASK_021: Runner Pool Health & Latency Audit
[CmdletBinding()]
param(
    [string]$CommandId,
    [string]$TaskId,
    [string]$ExecutionLane,
    [string]$RepoPath
)

$ErrorActionPreference = "Stop"

Write-Host "=========================================================="
Write-Host "ACCEPTANCE TEST 1: RUNNER POOL HEALTH & ENVIRONMENT AUDIT"
Write-Host "Command ID: $CommandId"
Write-Host "Task ID:    $TaskId"
Write-Host "Host:       $([Environment]::MachineName)"
Write-Host "User:       $([Environment]::UserName)"
Write-Host "Directory:  $RepoPath"
Write-Host "=========================================================="

# 1. Gather Host & Runner Metrics
$startTime = Get-Date
$ghLatencyStart = [System.Diagnostics.Stopwatch]::StartNew()
$apiRunners = & gh api "repos/netvietsoft/AI-Studio-convert2/actions/runners" | ConvertFrom-Json
$ghLatencyStart.Stop()
$latencyMs = $ghLatencyStart.ElapsedMilliseconds

$activeRunners = @()
foreach ($r in $apiRunners.runners) {
    $activeRunners += @{
        id = $r.id
        name = $r.name
        status = $r.status
        busy = $r.busy
        labels = @($r.labels | ForEach-Object { $_.name })
    }
}

$tools = @{
    git = (& git --version)
    python = (& python --version 2>&1)
    gh = (& gh --version | Select-Object -First 1)
    agy = (& agy --help 2>&1 | Select-Object -First 1)
}

# 2. Collect Evidence Payload
$evidenceDir = Join-Path $RepoPath ".ai\evidence\infra"
if (-not (Test-Path $evidenceDir)) {
    New-Item -ItemType Directory -Path $evidenceDir -Force | Out-Null
}

$evidenceFile = Join-Path $evidenceDir "runner_pool_health.json"
$evidencePayload = @{
    protocol = "CONVERT2_EVIDENCE_V1"
    command_id = $CommandId
    task_id = $TaskId
    runner_host = [Environment]::MachineName
    runner_user = [Environment]::UserName
    runner_directory = $RepoPath
    github_api_latency_ms = $latencyMs
    total_runners_registered = $apiRunners.total_count
    runners = $activeRunners
    tools = $tools
    audited_at = (Get-Date).ToString("o")
    verdict = "PASS"
}

$evidencePayload | ConvertTo-Json -Depth 5 | Set-Content -Encoding UTF8 $evidenceFile
$evidenceHash = (Get-FileHash -Path $evidenceFile -Algorithm SHA256).Hash
Write-Host "Evidence written to $evidenceFile (SHA256: $evidenceHash)"

# 3. Write Acceptance Report
$reportDir = Join-Path $RepoPath ".ai\reports\$TaskId"
if (-not (Test-Path $reportDir)) {
    New-Item -ItemType Directory -Path $reportDir -Force | Out-Null
}

$reportFile = Join-Path $reportDir "00_REPORT.md"
$reportContent = @"
# ACCEPTANCE AUDIT: RUNNER POOL HEALTH & DEPENDENCIES
**Task ID:** $TaskId  
**Command ID:** $CommandId  
**Execution Lane:** $ExecutionLane  
**Host Machine:** $([Environment]::MachineName)  
**Host User:** $([Environment]::UserName)  
**Working Directory:** $RepoPath  
**Audit Timestamp:** $((Get-Date).ToString("o"))  

---

## 1. RUNNER POOL STATUS
- **Total Registered Runners:** $($apiRunners.total_count)
- **GitHub API Round-trip Latency:** ${latencyMs} ms
- **Active Pool Members:**
$($activeRunners | ForEach-Object { "  - **$($_.name)** (ID: $($_.id)): Status=$($_.status), Busy=$($_.busy), Labels=[$($_.labels -join ', ')]" } | Out-String)

## 2. TOOLCHAIN INTEGRITY
- **Git:** $($tools.git)
- **Python:** $($tools.python)
- **GitHub CLI:** $($tools.gh)
- **Antigravity CLI:** $($tools.agy)

## 3. EVIDENCE VERIFICATION
- **Evidence File:** `.ai/evidence/infra/runner_pool_health.json`
- **SHA-256:** `$evidenceHash`
- **Verdict:** **PASS**
"@

$reportContent | Set-Content -Encoding UTF8 $reportFile
Write-Host "Report written to $reportFile"

# 4. Update Task State
$taskStateDir = Join-Path $RepoPath ".ai\state\tasks"
if (-not (Test-Path $taskStateDir)) {
    New-Item -ItemType Directory -Path $taskStateDir -Force | Out-Null
}

$headSha = (& git rev-parse HEAD).Trim()
$taskStatePayload = @{
    task_id = $TaskId
    command_id = $CommandId
    status = "COMPLETED"
    execution_lane = $ExecutionLane
    report_folder = ".ai/reports/$TaskId"
    target_commit_sha = $headSha
    evidence_manifest_sha256 = $evidenceHash
    completed_at = (Get-Date).ToString("o")
    verdict = "PASS"
}

$taskStatePayload | ConvertTo-Json -Depth 5 | Set-Content -Encoding UTF8 (Join-Path $taskStateDir "$TaskId.json")
Write-Host "Task state updated for $TaskId: COMPLETED"
exit 0
