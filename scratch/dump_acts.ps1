$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$target = "192.168.1.3:40333"

& $adb connect $target
Start-Sleep -Seconds 1

Write-Host ">>> Dumping all activities in com.mt.mtxx.mtxx.convert..."
$acts = & $adb -s $target shell "dumpsys package com.mt.mtxx.mtxx.convert | grep -A 20 'Activities:'"
Write-Host "$acts"

Write-Host ">>> Starting com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.MainActivity..."
$res = & $adb -s $target shell am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.MainActivity
Write-Host "AM_START: $res"

Start-Sleep -Seconds 2
$top = & $adb -s $target shell "dumpsys window | grep -E 'mCurrentFocus|mFocusedApp'"
Write-Host "CURRENT_FOCUS:`n$top"
