$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$apk = "F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\build\outputs\apk\debug\app-debug.apk"

Write-Host "1. Connecting to 192.168.1.3:40333..."
& $adb connect 192.168.1.3:40333
Start-Sleep -Milliseconds 500

$devs = & $adb devices -l
Write-Host "$devs"

Write-Host "2. Installing APK..."
$res = & $adb -s 192.168.1.3:40333 install -r -t -d $apk
Write-Host "Install output: $res"

if ($res -match "Success") {
    Write-Host "3. Reverse port 9999..."
    & $adb -s 192.168.1.3:40333 reverse tcp:9999 tcp:9999

    Write-Host "4. Starting PhotoEditorActivity..."
    & $adb -s 192.168.1.3:40333 shell am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity
    Start-Sleep -Seconds 2

    $top = & $adb -s 192.168.1.3:40333 shell "dumpsys window | grep -E 'mCurrentFocus|mFocusedApp'"
    Write-Host "Top activity: $top"
}
