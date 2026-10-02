$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$apk = "F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\build\outputs\apk\debug\app-debug.apk"

Write-Host ">>> 1. Getting connected devices..."
$devOutput = & $adb devices -l
Write-Host "$devOutput"

$target = $null
if ($devOutput -match "(\S+:\d+)\s+device") {
    $target = $matches[1]
} elseif ($devOutput -match "(adb-\S+)\s+device") {
    $target = $matches[1]
}

if (-not $target) {
    Write-Host ">>> Trying connect to 192.168.1.3:40333..."
    & $adb connect 192.168.1.3:40333
    $devOutput = & $adb devices -l
    if ($devOutput -match "(\S+:\d+)\s+device") {
        $target = $matches[1]
    }
}

if (-not $target) {
    Write-Host "❌ No connected device found!"
    exit 1
}

Write-Host ">>> 2. Target Device Identified: $target"

Write-Host ">>> 3. Installing APK ($apk)..."
$instResult = & $adb -s $target install -r -t -d $apk
Write-Host "INSTALL_RESULT: $instResult"

if ($instResult -match "Success") {
    Write-Host ">>> 4. Reversing port 9999 for backend connection..."
    & $adb -s $target reverse tcp:9999 tcp:9999

    Write-Host ">>> 5. Launching PhotoEditorActivity..."
    $launchResult = & $adb -s $target shell am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity
    Write-Host "LAUNCH_RESULT: $launchResult"

    Start-Sleep -Seconds 2
    $top = & $adb -s $target shell "dumpsys window | grep -E 'mCurrentFocus|mFocusedApp'"
    Write-Host "CURRENT_FOCUS: $top"

    $ps = & $adb -s $target shell "ps -A | grep mtxx"
    Write-Host "RUNNING_PROCESS: $ps"
} else {
    Write-Host "❌ Installation failed!"
}
