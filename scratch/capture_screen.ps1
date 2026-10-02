$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$target = "192.168.1.3:40333"

& $adb connect $target | Out-Null
& $adb -s $target shell screencap -p /sdcard/screen_temp.png
& $adb -s $target pull /sdcard/screen_temp.png screen_current.png
Write-Host "PULLED_SUCCESS"
