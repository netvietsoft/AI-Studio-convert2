$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"

Write-Host ">>> Checking adb devices..."
$devs = & $adb devices -l
Write-Host "$devs"

# Try connecting to Samsung if needed
& $adb connect 192.168.1.3:37307
& $adb connect 192.168.1.3:37821
& $adb connect 192.168.1.3:45907

$devs = & $adb devices -l
Write-Host "UPDATED_DEVICES:`n$devs"

# Find online target
$target = $null
if ($devs -match "(192\.168\.1\.3:\d+)\s+device") {
    $target = $matches[1]
} elseif ($devs -match "(adb-[^\s]+)\s+device") {
    $target = $matches[1]
}

Write-Host "TARGET: $target"
if ($target) {
    Write-Host ">>> Grabbing crash logcat..."
    $crashLog = & $adb -s $target logcat -d -b crash -v time
    Write-Host "CRASH_LOG:`n$crashLog"

    Write-Host ">>> Grabbing AndroidRuntime / mtxx logs..."
    $appLog = & $adb -s $target logcat -d -v time -s "AndroidRuntime:E" "AndroidRuntime:F" "MtxxApplication:*" "MeituNativeLoader:*"
    Write-Host "APP_LOG:`n$appLog"
} else {
    Write-Host "Device offline, trying all cached logcats..."
}

