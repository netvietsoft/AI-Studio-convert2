$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$target = "192.168.1.3:40333"

& $adb connect $target
Start-Sleep -Seconds 1

Write-Host ">>> Unhiding and enabling package for user 0..."
& $adb -s $target shell "pm unhide --user 0 com.mt.mtxx.mtxx.convert"
& $adb -s $target shell "pm enable --user 0 com.mt.mtxx.mtxx.convert"
& $adb -s $target shell "pm default-state --user 0 com.mt.mtxx.mtxx.convert"
& $adb -s $target shell "pm unsuspend --user 0 com.mt.mtxx.mtxx.convert"

Write-Host ">>> Checking User 0 state:"
& $adb -s $target shell "dumpsys package com.mt.mtxx.mtxx.convert | grep 'User 0:'"

Write-Host ">>> Launching MainActivity..."
$am = & $adb -s $target shell "am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.MainActivity"
Write-Host "AM_START: $am"

Start-Sleep -Seconds 2
$top = & $adb -s $target shell "dumpsys window | grep -E 'mCurrentFocus|mFocusedApp'"
Write-Host "CURRENT_FOCUS:`n$top"

$ps = & $adb -s $target shell "ps -A | grep mtxx"
Write-Host "PROCESS:`n$ps"
