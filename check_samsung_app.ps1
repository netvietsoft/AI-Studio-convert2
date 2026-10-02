$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$target = "192.168.1.3:37307"

& $adb connect $target
Start-Sleep -Seconds 1

Write-Host ">>> Launching App..."
$am = & $adb -s $target shell "am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.MainActivity"
Write-Host "START: $am"

Start-Sleep -Seconds 2

Write-Host ">>> Checking App Process..."
$ps = & $adb -s $target shell "ps -A | grep mtxx"
Write-Host "PROCESS: $ps"
