$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$apk = "F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\build\outputs\apk\debug\app-debug.apk"

$pairIp = "192.168.1.18:36295"
$connectIp = "192.168.1.18:40159"
$pairCode = "614752"

Write-Host "=== STEP 1: Attempting adb pair on $pairIp with code $pairCode ==="
$pair1 = & $adb pair $pairIp $pairCode
Write-Host "PAIR 1 RESULT: $pair1"

if ($pair1 -notmatch "Successfully paired") {
    Write-Host "=== Trying alternate pair port on $connectIp ==="
    $pair2 = & $adb pair $connectIp $pairCode
    Write-Host "PAIR 2 RESULT: $pair2"
}

Write-Host "`n=== STEP 2: Connecting to $connectIp ==="
$conn1 = & $adb connect $connectIp
Write-Host "CONNECT RESULT: $conn1"

Start-Sleep -Seconds 1
Write-Host "`n=== STEP 3: adb devices -l ==="
$devs = & $adb devices -l
Write-Host "$devs"

$connectedDevice = "192.168.1.18:40159"
Write-Host "`n>>> Active device target: $connectedDevice"

if ($connectedDevice) {
    Write-Host "`n=== STEP 4: Installing latest APK on $connectedDevice ==="
    $inst = & $adb -s $connectedDevice install -r -t -d $apk
    Write-Host "INSTALL RESULT: $inst"

    Write-Host "`n=== STEP 5: Launching PhotoEditorActivity ==="
    $am = & $adb -s $connectedDevice shell am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity
    Write-Host "LAUNCH RESULT: $am"

    Start-Sleep -Seconds 2
    $focus = & $adb -s $connectedDevice shell "dumpsys window | grep -E 'mCurrentFocus|mFocusedApp'"
    Write-Host "FOCUSED_WINDOW:`n$focus"

    Write-Host "`n=== STEP 6: Reading C++ Native Logcat ==="
    $logs = & $adb -s $connectedDevice logcat -d -s "PhotoEditorActivity:I" "HairStrandDye:I" "HairMattingEngine:I" "BiSeNetFaceParser:I" -t 30
    Write-Host "LOGCAT:`n$logs"
} else {
    Write-Host "`n[ERROR] Device not recognized in 'device' state. Please check wireless debugging prompt on phone."
}
