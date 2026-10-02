$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$apk = "F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\build\outputs\apk\debug\app-debug.apk"

$target = "192.168.1.3:40333"

Write-Host ">>> Connecting to $target..."
$c = & $adb connect $target
Write-Host "$c"

Start-Sleep -Seconds 1
$devs = & $adb devices -l
Write-Host "$devs"

Write-Host ">>> Installing APK onto Samsung A50s ($target)..."
$inst = & $adb -s $target install -r -t -d $apk
Write-Host "INSTALL_STATUS: $inst"

Write-Host ">>> Launching MainActivity..."
$act = & $adb -s $target shell am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.MainActivity
Write-Host "LAUNCH_STATUS: $act"

Write-Host ">>> Reverse port 9999 for Backend communication..."
& $adb -s $target reverse tcp:9999 tcp:9999
