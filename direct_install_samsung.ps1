$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$apk = "F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\build\outputs\apk\debug\app-debug.apk"
$target = "192.168.1.3:37307"

Write-Host ">>> Installing APK onto Samsung Galaxy A50s ($target)..."
$inst = & $adb -s $target install -r -t -d $apk
Write-Host "INSTALL_RESULT: $inst"

Write-Host ">>> Setting up adb reverse tcp:9999 tcp:9999..."
$rev = & $adb -s $target reverse tcp:9999 tcp:9999
Write-Host "REVERSE_RESULT: $rev"

Write-Host ">>> Launching MainActivity..."
$am = & $adb -s $target shell am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.MainActivity
Write-Host "LAUNCH_RESULT: $am"

Start-Sleep -Seconds 2
$focus = & $adb -s $target shell "dumpsys window | grep -E 'mCurrentFocus|mFocusedApp'"
Write-Host "FOCUSED_WINDOW:`n$focus"
