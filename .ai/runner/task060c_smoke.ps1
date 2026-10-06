[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)][string]$CommandId,
    [Parameter(Mandatory = $true)][string]$TaskId,
    [Parameter(Mandatory = $true)][string]$RepoPath,
    [string]$ExecutionLane = "task060c-service-smoke"
)

$ErrorActionPreference = "Stop"
$startedAt = [DateTimeOffset]::UtcNow
$elapsed = [Diagnostics.Stopwatch]::StartNew()
$exitCode = 49
$status = "UNEXPECTED_HOST_FAILURE"
$evidenceDirectory = $null
$scratchDirectory = $null
$evidence = [ordered]@{
    protocol = "CONVERT2_TASK060C_SERVICE_SMOKE_V1"
    upstream_source = "REAL"
    command_id = $CommandId
    task_id = $TaskId
    execution_lane = $ExecutionLane
    github_run_id = $env:GITHUB_RUN_ID
    started_at = $startedAt.ToString("o")
    task_pass = $false
    review_required = $true
    parent_dependencies_must_remain_blocked = $true
    ack_scope = "Hosting script deterministic read and normalized hash; no semantic AGY or independent-agent acknowledgment"
    tool_free_execution_enforcement = "UNPROVEN: installed CLI has no disable-all-tools flag"
    rules_ack = @()
    tools = @()
    probe = $null
}

function Get-NormalizedText {
    param([string]$Path)
    $text = [IO.File]::ReadAllText($Path, [Text.UTF8Encoding]::new($false, $true))
    if ($text.Length -gt 0 -and $text[0] -eq [char]0xFEFF) { $text = $text.Substring(1) }
    return $text.Replace("`r`n", "`n").Replace("`r", "`n")
}

function Get-TextSha256 {
    param([string]$Text)
    $hasher = [Security.Cryptography.SHA256]::Create()
    try {
        return [BitConverter]::ToString($hasher.ComputeHash([Text.Encoding]::UTF8.GetBytes($Text))).Replace("-", "").ToLowerInvariant()
    } finally { $hasher.Dispose() }
}

function Resolve-PacketDocumentPath {
    param([string]$Repository, [string]$RelativePath)
    if ([string]::IsNullOrWhiteSpace($RelativePath) -or [IO.Path]::IsPathRooted($RelativePath) -or $RelativePath -match ':|(?:^|[\\/])\.\.(?:[\\/]|$)') { throw "PACKET_PATH_INVALID" }
    $documentPath = [IO.Path]::GetFullPath((Join-Path $Repository $RelativePath))
    if (-not $documentPath.StartsWith($Repository + [IO.Path]::DirectorySeparatorChar, [StringComparison]::OrdinalIgnoreCase)) { throw "PACKET_PATH_OUTSIDE_REPOSITORY" }
    # Packet paths are relative to RepoPath, including repository governance files.
    # Reject reparse points so a lexically contained path cannot escape via a link.
    $cursor = $documentPath
    while ($cursor -ne $Repository) {
        $item = Get-Item -LiteralPath $cursor -Force
        if (($item.Attributes -band [IO.FileAttributes]::ReparsePoint) -ne 0) { throw "PACKET_REPARSE_POINT_REJECTED" }
        $cursor = [IO.Path]::GetDirectoryName($cursor)
    }
    return $documentPath
}

function Assert-LiveStateBinding {
    param($State, [string]$ExpectedCommandId, [string]$ExpectedTaskId, [string]$ExpectedRunId)
    $taskMatch = [regex]::Match($ExpectedTaskId, '^(TASK_[0-9A-Za-z]+)')
    if (-not $taskMatch.Success) { throw "LIVE_STATE_TASK_PREFIX_INVALID" }
    $statusKey = $taskMatch.Groups[1].Value + "_STATUS"
    if ($State.current_command_id -cne $ExpectedCommandId -or $State.current_task_id -cne $ExpectedTaskId -or [string]$State.provenance.github_run_id -cne $ExpectedRunId -or $State.task_lifecycle.PSObject.Properties[$statusKey].Value -cne "RUNNING") { throw "LIVE_STATE_BINDING_INVALID" }
}

function ConvertTo-NativeArguments {
    param([string[]]$Arguments)
    return (($Arguments | ForEach-Object {
        # Windows native argument quoting; no command shell evaluates this text.
        $quoted = [regex]::Replace($_, '(\\*)"', '$1$1\"')
        $quoted = [regex]::Replace($quoted, '(\\+)$', '$1$1')
        '"' + $quoted + '"'
    }) -join " ")
}

function Stop-OwnedProcessTree {
    param([Diagnostics.Process]$Process)
    if ($Process.HasExited) { return }
    # Only the process object created by this script supplies the PID. Never
    # discover or stop another runner, AGY session, or service by name.
    $killer = [Diagnostics.Process]::new()
    try {
        $killer.StartInfo.FileName = Join-Path $env:SystemRoot "System32\taskkill.exe"
        $killer.StartInfo.Arguments = "/PID $($Process.Id) /T /F"
        $killer.StartInfo.UseShellExecute = $false
        $killer.StartInfo.CreateNoWindow = $true
        $killer.StartInfo.WindowStyle = [Diagnostics.ProcessWindowStyle]::Hidden
        $killer.StartInfo.RedirectStandardOutput = $true
        $killer.StartInfo.RedirectStandardError = $true
        if ($killer.Start()) {
            $killOut = $killer.StandardOutput.ReadToEndAsync()
            $killErr = $killer.StandardError.ReadToEndAsync()
            if (-not $killer.WaitForExit(4000)) { $killer.Kill() }
        }
        if (-not $Process.HasExited) { $Process.Kill() }
        $Process.WaitForExit(1000) | Out-Null
    } finally { $killer.Dispose() }
}

function Invoke-BoundedNative {
    param([string]$FilePath, [string[]]$Arguments, [string]$WorkingDirectory, [int]$TimeoutSeconds)
    # Leave a five-second termination/evidence margin inside the 90-second budget.
    $remaining = [math]::Floor(85 - $elapsed.Elapsed.TotalSeconds)
    $limit = [math]::Min($TimeoutSeconds, $remaining)
    if ($limit -lt 1) { throw "SMOKE_DEADLINE_EXHAUSTED" }
    $process = [Diagnostics.Process]::new()
    $processStarted = $false
    try {
        $process.StartInfo.FileName = $FilePath
        $process.StartInfo.Arguments = ConvertTo-NativeArguments $Arguments
        $process.StartInfo.WorkingDirectory = $WorkingDirectory
        $process.StartInfo.UseShellExecute = $false
        $process.StartInfo.CreateNoWindow = $true
        $process.StartInfo.WindowStyle = [Diagnostics.ProcessWindowStyle]::Hidden
        $process.StartInfo.RedirectStandardInput = $true
        $process.StartInfo.RedirectStandardOutput = $true
        $process.StartInfo.RedirectStandardError = $true
        $process.StartInfo.StandardOutputEncoding = [Text.Encoding]::UTF8
        $process.StartInfo.StandardErrorEncoding = [Text.Encoding]::UTF8
        if (-not $process.Start()) { throw "NATIVE_START_FAILED" }
        $processStarted = $true
        $ownedPid = $process.Id
        $process.StandardInput.Close()
        # Drain both streams concurrently; no raw transcript is written to disk.
        $stdoutTask = $process.StandardOutput.ReadToEndAsync()
        $stderrTask = $process.StandardError.ReadToEndAsync()
        $timedOut = -not $process.WaitForExit([int]($limit * 1000))
        if ($timedOut) { Stop-OwnedProcessTree $process }
        [Threading.Tasks.Task]::WaitAll([Threading.Tasks.Task[]]@($stdoutTask, $stderrTask), 500) | Out-Null
        $stdout = if ($stdoutTask.Status -eq [Threading.Tasks.TaskStatus]::RanToCompletion) { $stdoutTask.Result } else { "" }
        $stderr = if ($stderrTask.Status -eq [Threading.Tasks.TaskStatus]::RanToCompletion) { $stderrTask.Result } else { "" }
        $nativeExit = if ($process.HasExited) { $process.ExitCode } else { $null }
        return [pscustomobject]@{
            Pid = $ownedPid; NativeExitCode = $nativeExit; TimedOut = $timedOut
            TimeoutSeconds = $limit; Stdout = $stdout; Stderr = $stderr
            CaptureComplete = ($stdoutTask.Status -eq [Threading.Tasks.TaskStatus]::RanToCompletion -and $stderrTask.Status -eq [Threading.Tasks.TaskStatus]::RanToCompletion)
        }
    } finally {
        if ($processStarted -and -not $process.HasExited) { Stop-OwnedProcessTree $process }
        $process.Dispose()
    }
}

try {
    $repository = [IO.Path]::GetFullPath($RepoPath).TrimEnd('\', '/')
    if (-not (Test-Path -LiteralPath $repository -PathType Container)) { throw "REPOSITORY_MISSING" }
    $evidenceDirectory = Join-Path $repository (".ai\runner\TASK_060C_SMOKE\" + [guid]::NewGuid().ToString("N"))
    New-Item -ItemType Directory -Path $evidenceDirectory | Out-Null
    $evidence.repository_path = $repository
    $evidence.host_pid = $PID
    $identity = [Security.Principal.WindowsIdentity]::GetCurrent()
    try {
        $evidence.identity = [ordered]@{
            runner_name = $env:RUNNER_NAME; runner_os = $env:RUNNER_OS
            runner_arch = $env:RUNNER_ARCH; machine_name = [Environment]::MachineName
            account_name = $identity.Name; account_sid = $identity.User.Value
            powershell_version = $PSVersionTable.PSVersion.ToString()
        }
        $status = "SERVICE_IDENTITY_MISMATCH"; $exitCode = 48
        if ([Environment]::OSVersion.Platform -ne [PlatformID]::Win32NT -or $env:RUNNER_NAME -ne "CONVERT2-WINDOWS-01" -or $identity.User.Value -ne "S-1-5-20") { throw "SERVICE_IDENTITY_MISMATCH" }
    } finally { $identity.Dispose() }
    $status = "REAL_JOB_BINDING_MISSING"; $exitCode = 48
    if ($env:GITHUB_RUN_ID -notmatch '^\d+$' -or -not $env:GITHUB_WORKSPACE -or [IO.Path]::GetFullPath($env:GITHUB_WORKSPACE).TrimEnd('\', '/') -ne $repository) { throw "REAL_JOB_BINDING_MISSING" }

    $status = "RULES_PACKET_INVALID"; $exitCode = 46
    $manifestPath = Resolve-PacketDocumentPath $repository ".ai\runner\TASK_060C_INPUT\manifest.json"
    $manifestText = Get-NormalizedText $manifestPath
    $manifest = $manifestText | ConvertFrom-Json
    if ($manifest.task_id -ne $TaskId -or $manifest.hash_algorithm -ne "SHA256_UTF8_LF_NO_BOM" -or -not $manifest.task_revision) { throw "PACKET_BINDING_INVALID" }
    $evidence.packet = [ordered]@{
        task_revision = [string]$manifest.task_revision; parent_task_id = [string]$manifest.parent_task_id
        manifest_sha256 = Get-TextSha256 $manifestText; hash_algorithm = [string]$manifest.hash_algorithm
    }
    $requiredRoles = @("owner_law", "task_execution_standard", "evidence_report_standard", "git_audit_standard", "state_handoff_standard", "startup_checklist", "memory_bootstrap", "master_standard", "project_constitution", "project_rules", "workspace_standard", "error_memory", "knowledge_memory", "project_memory", "task_log", "durable_state", "parent_task", "active_task")
    $seenRoles = @{}
    foreach ($entry in $manifest.files) {
        if ($seenRoles.ContainsKey([string]$entry.role) -or $entry.sha256 -notmatch '^[0-9a-fA-F]{64}$' -or [IO.Path]::IsPathRooted([string]$entry.path)) { throw "PACKET_ENTRY_INVALID" }
        $documentPath = Resolve-PacketDocumentPath $repository ([string]$entry.path)
        $text = Get-NormalizedText $documentPath
        $actualHash = Get-TextSha256 $text
        $hashMatches = $actualHash -eq ([string]$entry.sha256).ToLowerInvariant()
        $runtimeObservation = $entry.role -eq "durable_state" -and $entry.hash_policy -eq "observe_runtime"
        if ($runtimeObservation) {
            $liveState = $text | ConvertFrom-Json
            Assert-LiveStateBinding $liveState $CommandId $TaskId $env:GITHUB_RUN_ID
        } elseif (-not $hashMatches) { throw "PACKET_HASH_MISMATCH" }
        if ($entry.role -eq "active_task" -and $text -notmatch '(?i)TASK_060C\s+ACTIVE') { throw "TASK_SNAPSHOT_NOT_ACTIVE" }
        $source = if ($entry.source) { [ordered]@{ path = [string]$entry.source.path; drive_id = [string]$entry.source.drive_id; modified_time = [string]$entry.source.modified_time } } else { $null }
        $evidence.rules_ack += [ordered]@{
            path = [string]$entry.path; role = [string]$entry.role
            expected_baseline_sha256 = [string]$entry.sha256; actual_sha256 = $actualHash
            hash_matches_baseline = $hashMatches; hash_policy = $(if ($runtimeObservation) { "observe_runtime" } else { "immutable_exact_match" })
            hosting_script_read_hash_ack = $true; semantic_agent_ack = $false; source = $source
        }
        $seenRoles[[string]$entry.role] = $true
    }
    foreach ($role in $requiredRoles) { if (-not $seenRoles.ContainsKey($role)) { throw "REQUIRED_RULE_ROLE_MISSING" } }

    $status = "TOOLCHAIN_NOT_READY"; $exitCode = 45
    $toolPaths = @{}
    foreach ($toolName in @("git", "python", "agy", "gh", "node", "adb", "java")) {
        $tool = Get-Command $toolName -CommandType Application -ErrorAction SilentlyContinue | Select-Object -First 1
        $path = if ($tool) { $tool.Source } else { $null }
        $evidence.tools += [ordered]@{ name = $toolName; executable_path = $path; present = [bool]$tool; required_for_this_probe = ($toolName -in @("git", "python", "agy")) }
        if ($tool) { $toolPaths[$toolName] = $path }
    }
    foreach ($requiredTool in @("git", "python", "agy")) { if (-not $toolPaths.ContainsKey($requiredTool)) { throw "REQUIRED_TOOL_MISSING" } }
    $evidence.paths = [ordered]@{ local_app_data = $env:LOCALAPPDATA; authorized_image_root = "F:\App\Image"; image_root_directory_visible = (Test-Path -LiteralPath "F:\App\Image" -PathType Container) }
    $head = Invoke-BoundedNative $toolPaths.git @("-C", $repository, "rev-parse", "HEAD") $repository 3
    if ($head.TimedOut -or $head.NativeExitCode -ne 0 -or $head.Stdout.Trim() -notmatch '^[0-9a-fA-F]{40}$') { throw "REPOSITORY_GIT_PREFLIGHT_FAILED" }
    $evidence.git_head_sha = $head.Stdout.Trim()
    $scratchDirectory = Join-Path ([IO.Path]::GetTempPath()) ("convert2-task060c-probe-" + [guid]::NewGuid().ToString("N"))
    New-Item -ItemType Directory -Path $scratchDirectory | Out-Null
    $version = Invoke-BoundedNative $toolPaths.agy @("--version") $scratchDirectory 10
    if ($version.TimedOut -or $version.NativeExitCode -ne 0 -or $version.Stdout.Trim() -notmatch '^\d+\.\d+\.\d+(?:[-+][A-Za-z0-9.-]+)?$') { throw "AGY_VERSION_PREFLIGHT_FAILED" }
    $evidence.agy_version = $version.Stdout.Trim()
    $marker = "TASK060C_PROBE_" + [guid]::NewGuid().ToString("N")
    $prompt = "Reply with exactly $marker and nothing else. Do not use tools, skills, slash commands, terminal commands, or read or write files. This is only a bounded authentication readiness probe."
    $arguments = @("--mode", "plan", "--sandbox", "--disable-slash-commands", "--output-format", "text", "--print-timeout", "75s", "-p", $prompt)
    $status = "AGY_PROBE_NATIVE_FAILURE"; $exitCode = 43
    $probe = Invoke-BoundedNative $toolPaths.agy $arguments $scratchDirectory 75
    $authFailureObserved = ($probe.Stdout + "`n" + $probe.Stderr) -match '(?i)authentication required|authentication (?:failed|timed out)|waiting for authentication|authorization code|accounts\.google\.com/o/oauth2|not (?:logged|signed) in'
    $markerExact = $probe.Stdout.Trim() -ceq $marker
    $evidence.probe = [ordered]@{
        owned_process_id = $probe.Pid; native_exit_code = $probe.NativeExitCode
        timed_out = $probe.TimedOut; timeout_seconds = $probe.TimeoutSeconds
        stdout_character_count = $probe.Stdout.Length; stderr_character_count = $probe.Stderr.Length
        capture_complete = $probe.CaptureComplete; auth_failure_indicator_observed = $authFailureObserved
        unique_marker = $marker; exact_stdout_marker_observed = $markerExact
        mode = "plan"; sandbox = $true; slash_command_expansion_disabled = $true
        raw_transcript_persisted = $false; auth_configuration_changed = $false
    }
    if ($probe.TimedOut) {
        $status = if ($authFailureObserved) { "AGY_AUTH_TIMEOUT" } else { "AGY_PROBE_TIMEOUT" }
        $exitCode = 44
    } elseif ($authFailureObserved) {
        $status = "AGY_AUTH_NOT_READY"; $exitCode = 43
    } elseif ($probe.NativeExitCode -ne 0) {
        $status = "AGY_PROBE_NATIVE_FAILURE"; $exitCode = 43
    } elseif (-not $probe.CaptureComplete -or -not $markerExact) {
        $status = "AGY_EXACT_MARKER_NOT_OBSERVED"; $exitCode = 47
    } else {
        # Native success proves only this bounded marker response. The deliberate
        # nonzero result prevents unsafe integration and preserves dependency gates.
        $status = "PROBE_SUCCESS_REVIEW_REQUIRED"; $exitCode = 42
    }
    $probe = $null; $version = $null; $head = $null
} catch {
    # Exception text and native output may contain auth URLs. Retain only the
    # predetermined status and exception type, never the raw message/transcript.
    $evidence.host_exception_type = $_.Exception.GetType().Name
} finally {
    if ($scratchDirectory -and (Test-Path -LiteralPath $scratchDirectory)) {
        # Delete only this owned directory if empty. Unexpected files remain outside
        # the repository; never copy them into evidence or recursively remove them.
        try { [IO.Directory]::Delete($scratchDirectory, $false); $evidence.scratch_cleanup = "OWNED_EMPTY_DIRECTORY_REMOVED" }
        catch { $evidence.scratch_cleanup = "OWNED_SCRATCH_RETAINED_OUTSIDE_REPOSITORY" }
    }
    $evidence.status = $status
    $evidence.deliberate_review_exit = ($status -eq "PROBE_SUCCESS_REVIEW_REQUIRED")
    $evidence.script_exit_code = $exitCode
    $evidence.finished_at = [DateTimeOffset]::UtcNow.ToString("o")
    $evidence.elapsed_seconds = [math]::Round($elapsed.Elapsed.TotalSeconds, 3)
    if ($evidenceDirectory) {
        $evidence | ConvertTo-Json -Depth 12 | Set-Content -Encoding UTF8 -LiteralPath (Join-Path $evidenceDirectory "sanitized_evidence.json")
        Write-Host "TASK060C_SMOKE status=$status exit_code=$exitCode sanitized_evidence=$evidenceDirectory"
    } else { Write-Host "TASK060C_SMOKE status=$status exit_code=$exitCode" }
}
exit $exitCode
