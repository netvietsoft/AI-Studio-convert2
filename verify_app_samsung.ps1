$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$samsung = "adb-R58MA581ZZA-n4XnSK._adb-tls-connect._tcp"

Write-Host ">>> Reverse port 9999 on Samsung device..."
$rev = & $adb -s $samsung reverse tcp:9999 tcp:9999
Write-Host "REVERSE: $rev"

Write-Host ">>> Starting MainActivity on Samsung A50s..."
$am = & $adb -s $samsung shell am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.MainActivity
Write-Host "AM_START: $am"

Start-Sleep -Seconds 1
Write-Host ">>> Checking Current Focused Window..."
$focus = & $adb -s $samsung shell "dumpsys window | grep -E 'mCurrentFocus|mFocusedApp'"
Write-Host "$focus"

Write-Host ">>> Taking screenshot..."
$screenPath = "F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\samsung_screenshot.png"
& $adb -s $samsung exec-out screencap -p > $screenPath
if (Test-Path $screenPath) {
    Write-Host "SCREENSHOT_SAVED: $screenPath ($((Get-Item $screenPath).Length) bytes)"
}
