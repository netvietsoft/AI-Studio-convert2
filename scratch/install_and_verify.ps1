$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$apk = "F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\build\outputs\apk\debug\app-debug.apk"
$target = "192.168.1.3:40333"

Write-Host ">>> Step 1: Connecting to target $target..."
& $adb connect $target
Start-Sleep -Seconds 1

Write-Host ">>> Step 2: Installing APK ($apk)..."
$inst = & $adb -s $target install -r -t -d $apk
Write-Host "INSTALL_STATUS: $inst"

if ($inst -match "Success") {
    Write-Host ">>> Step 3: Setting up reverse port 9999..."
    & $adb -s $target reverse tcp:9999 tcp:9999

    Write-Host ">>> Step 4: Launching PhotoEditorActivity..."
    $am = & $adb -s $target shell am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity
    Write-Host "LAUNCH_STATUS: $am"

    Start-Sleep -Seconds 3

    Write-Host ">>> Step 5: Verifying top activity & focus..."
    $top = & $adb -s $target shell "dumpsys window | grep -E 'mCurrentFocus|mFocusedApp'"
    Write-Host "FOCUSED_ACTIVITY:`n$top"

    Write-Host ">>> Step 6: Verifying process..."
    $ps = & $adb -s $target shell "ps -A | grep mtxx"
    Write-Host "RUNNING_PROCESS:`n$ps"
}
