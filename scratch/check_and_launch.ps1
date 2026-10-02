$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$target = "192.168.1.3:40333"

Write-Host ">>> Connecting to $target..."
& $adb connect $target
Start-Sleep -Seconds 1

Write-Host ">>> Checking installed packages..."
$pkgs = & $adb -s $target shell "pm list packages | grep -E 'mtxx|reborn'"
Write-Host "INSTALLED_PACKAGES:`n$pkgs"

Write-Host ">>> Checking Activities in com.mt.mtxx.mtxx.convert..."
$dumpAct = & $adb -s $target shell "pm dump com.mt.mtxx.mtxx.convert | grep -A 10 'Activity Resolver Table:'"
Write-Host "DUMP_ACTIVITIES:`n$dumpAct"

Write-Host ">>> Launching MainActivity of com.mt.mtxx.mtxx.convert..."
$l1 = & $adb -s $target shell "monkey -p com.mt.mtxx.mtxx.convert -c android.intent.category.LAUNCHER 1"
Write-Host "MONKEY_LAUNCH:`n$l1"

Start-Sleep -Seconds 2
$top = & $adb -s $target shell "dumpsys window | grep -E 'mCurrentFocus|mFocusedApp'"
Write-Host "CURRENT_FOCUS:`n$top"
