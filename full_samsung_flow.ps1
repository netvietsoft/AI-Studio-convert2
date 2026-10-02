$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$apk = "F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\build\outputs\apk\debug\app-debug.apk"
$target = "192.168.1.3:37307"

Write-Host ">>> Connecting to $target..."
& $adb connect $target

Write-Host ">>> Verifying devices..."
$devs = & $adb devices
Write-Host "$devs"

Write-Host ">>> Installing APK ($apk)..."
$inst = & $adb -s $target install -r -t -d $apk
Write-Host "INSTALL_RESULT: $inst"

Write-Host ">>> Reversing Backend port 9999..."
& $adb -s $target reverse tcp:9999 tcp:9999

Write-Host ">>> Starting MainActivity..."
$am = & $adb -s $target shell am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.MainActivity
Write-Host "LAUNCH: $am"

Start-Sleep -Seconds 2
$focus = & $adb -s $target shell "dumpsys window | grep -E 'mCurrentFocus|mFocusedApp'"
Write-Host "TOP_WINDOW:`n$focus"
