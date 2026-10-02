$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$target = "192.168.1.3:37307"

Write-Host ">>> Launching Meitu Reborn into foreground..."
$amOut = & $adb -s $target shell "am start -W -a android.intent.action.MAIN -c android.intent.category.LAUNCHER -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.MainActivity"
Write-Host "$amOut"

Start-Sleep -Seconds 2

Write-Host ">>> Checking Running Tasks..."
$curApp = & $adb -s $target shell "dumpsys activity activities | grep -E 'ResumedActivity'"
Write-Host "RESUMED_ACTIVITY: $curApp"
