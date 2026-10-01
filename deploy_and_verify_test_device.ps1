$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$apk = "F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\build\outputs\apk\debug\app-debug.apk"
$screenPath = "F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\test_device_verification.png"

Write-Host ">>> Step 1: Starting ADB server..."
& $adb start-server
Start-Sleep -Seconds 3

Write-Host ">>> Step 2: Discovering attached devices..."
$devs = & $adb devices -l
Write-Host "ATTACHED DEVICES:`n$devs"

$target = $null
foreach ($line in $devs) {
    if ($line -match "^\s*(adb-[^\s]+|\d+\.\d+\.\d+\.\d+:\d+|[A-Z0-9]+)\s+device\b") {
        $target = $matches[1]
        break
    }
}

if (-not $target) {
    # Fallback to direct discovered name
    $target = "adb-R83L80E1LXX-HyWueN._adb-tls-connect._tcp"
}

Write-Host ">>> TARGET DEVICE: $target"

Write-Host ">>> Step 3: Installing APK onto device..."
$inst = & $adb -s $target install -r -t -d $apk
Write-Host "INSTALL_RESULT: $inst"

Write-Host ">>> Step 4: Setting up reverse port 9999 for backend comms..."
$rev = & $adb -s $target reverse tcp:9999 tcp:9999
Write-Host "REVERSE_RESULT: $rev"

Write-Host ">>> Step 5: Launching app MainActivity..."
$launch = & $adb -s $target shell am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.MainActivity
Write-Host "LAUNCH_RESULT: $launch"

Start-Sleep -Seconds 3

Write-Host ">>> Step 6: Verifying focused window & process..."
$focus = & $adb -s $target shell "dumpsys window | grep -E 'mCurrentFocus|mFocusedApp'"
Write-Host "CURRENT_FOCUS:`n$focus"

$ps = & $adb -s $target shell "ps -A | grep mtxx"
Write-Host "PROCESS_INFO:`n$ps"

Write-Host ">>> Step 7: Capturing physical device screenshot..."
& $adb -s $target exec-out screencap -p > $screenPath
if (Test-Path $screenPath) {
    $len = (Get-Item $screenPath).Length
    Write-Host "SCREENSHOT_SUCCESS: $screenPath ($len bytes)"
}

Write-Host ">>> Step 8: Checking Native Library Logcat..."
$logs = & $adb -s $target logcat -d -v time -s "MeituNativeLoader:*" "MtxxApplication:*" "AndroidRuntime:E" "AndroidRuntime:F" | Select-Object -Last 30
Write-Host "LOGCAT_SNIPPET:`n$logs"

