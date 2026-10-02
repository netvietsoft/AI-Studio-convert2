$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$target = "192.168.1.3:40333"
$apk = "F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\build\outputs\apk\debug\app-debug.apk"

Write-Host "=== 1. Connect Device ==="
& $adb connect $target
& $adb -s $target get-state

Write-Host "=== 2. Install APK ==="
& $adb -s $target install -r -t -d $apk

Write-Host "=== 3. Clear Logcat ==="
& $adb -s $target logcat -c

Write-Host "=== 4. Launch PhotoEditorActivity ==="
& $adb -s $target shell am start -S -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity --es tool_id tool_ear_buddha --ei intensity 90

Write-Host "=== 5. Wait for Rendering ==="
Start-Sleep -Seconds 4

Write-Host "=== 6. Capture Screen ==="
& $adb -s $target shell screencap -p /sdcard/screen_buddha_verified.png
& $adb -s $target pull /sdcard/screen_buddha_verified.png F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\screen_buddha_verified.png

Write-Host "=== 7. Dump Relevant Logcat ==="
& $adb -s $target logcat -d -s PhotoEditorActivity:I TeethEarEngine:I EarAnatomy:I -t 50
