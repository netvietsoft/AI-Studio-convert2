$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$target = "192.168.1.3:40333"

& $adb connect $target
Start-Sleep -Seconds 1

Write-Host ">>> Checking package state:"
& $adb -s $target shell "dumpsys package com.mt.mtxx.mtxx.convert | grep -E 'userId=|pkg=|codePath=|versionCode=|User 0:' -A 5"

Write-Host ">>> Trying pm enable:"
& $adb -s $target shell "pm enable com.mt.mtxx.mtxx.convert"

Write-Host ">>> Trying start via Action VIEW or intent filter:"
& $adb -s $target shell "am start -a android.intent.action.MAIN -c android.intent.category.LAUNCHER -p com.mt.mtxx.mtxx.convert"
