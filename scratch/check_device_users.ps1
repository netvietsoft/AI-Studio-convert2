$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$target = "192.168.1.3:40333"

& $adb connect $target
Start-Sleep -Seconds 1

Write-Host ">>> Device Users:"
& $adb -s $target shell "pm list users"

Write-Host ">>> Packages for User 0:"
& $adb -s $target shell "pm list packages --user 0 | grep mtxx"

Write-Host ">>> Path of package com.mt.mtxx.mtxx.convert:"
& $adb -s $target shell "pm path com.mt.mtxx.mtxx.convert"

Write-Host ">>> Try starting with --user 0:"
& $adb -s $target shell "am start --user 0 -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.MainActivity"
