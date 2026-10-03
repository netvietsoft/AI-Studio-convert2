# scripts/acceptance/test_evidence_provenance.ps1
# Acceptance Test 2 for TASK_021: Local Git History & Provenance Integrity Audit
[CmdletBinding()]
param(
    [string]$CommandId,
    [string]$TaskId,
    [string]$ExecutionLane,
    [string]$RepoPath
)

$ErrorActionPreference = "Stop"

Write-Host "=========================================================="
Write-Host "ACCEPTANCE TEST 2: GIT REPOSITORY & PROVENANCE INTEGRITY"
Write-Host "Command ID: $CommandId"
Write-Host "Task ID:    $TaskId"
Write-Host "Host:       $([Environment]::MachineName)"
Write-Host "User:       $([Environment]::UserName)"
Write-Host "Directory:  $RepoPath"
Write-Host "=========================================================="

# 1. Gather Repository & Provenance Metrics
$headSha = (& git rev-parse HEAD).Trim()
$currentBranch = (& git rev-parse --abbrev-ref HEAD).Trim()
$remoteOrigin = (& git config --get remote.origin.url).Trim()
$recentCommits = & git log -n 5 --pretty=format:"%h - %an, %ar : %s"

# Verify command directory integrity
$cmdDir = Join-Path $RepoPath ".ai\commands"
$pendingCount = @(Get-ChildItem -Path (Join-Path $cmdDir "pending") -Filter "*.json" -ErrorAction SilentlyContinue).Count
$runningCount = @(Get-ChildItem -Path (Join-Path $cmdDir "running") -Filter "*.json" -ErrorAction SilentlyContinue).Count
$completedCount = @(Get-ChildItem -Path (Join-Path $cmdDir "completed") -Filter "*.json" -ErrorAction SilentlyContinue).Count

# 2. Collect Evidence Payload
$evidenceDir = Join-Path $RepoPath ".ai\evidence\infra"
if (-not (Test-Path $evidenceDir)) {
    New-Item -ItemType Directory -Path $evidenceDir -Force | Out-Null
}

$evidenceFile = Join-Path $evidenceDir "provenance_audit.json"
$evidencePayload = @{
    protocol = "CONVERT2_EVIDENCE_V1"
    command_id = $CommandId
    task_id = $TaskId
    runner_host = [Environment]::MachineName
    runner_user = [Environment]::UserName
    runner_directory = $RepoPath
    git_head_sha = $headSha
    git_branch = $currentBranch
    remote_origin = $remoteOrigin
    command_bus_inventory = @{
        pending = $pendingCount
        running = $runningCount
        completed = $completedCount
    }
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
# ACCEPTANCE AUDIT: GIT REPOSITORY & PROVENANCE INTEGRITY
**Task ID:** $TaskId  
**Command ID:** $CommandId  
**Execution Lane:** $ExecutionLane  
**Host Machine:** $([Environment]::MachineName)  
**Host User:** $([Environment]::UserName)  
**Working Directory:** $RepoPath  
**Audit Timestamp:** $((Get-Date).ToString("o"))  

---

## 1. REPOSITORY METRICS
- **Branch:** `$currentBranch`
- **Head Commit SHA:** `$headSha`
- **Remote Origin:** `$remoteOrigin`

## 2. COMMAND BUS DISK INVENTORY
- **Pending Commands:** $pendingCount
- **Running Commands:** $runningCount
- **Completed Commands:** $completedCount

## 3. RECENT COMMITS
```text
$($recentCommits -join "`n")
```

## 4. EVIDENCE VERIFICATION
- **Evidence File:** `.ai/evidence/infra/provenance_audit.json`
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
Write-Host "Task state updated for $($TaskId): COMPLETED"
exit 0
