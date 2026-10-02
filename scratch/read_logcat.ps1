$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$target = "192.168.1.3:40333"

& $adb connect $target
Start-Sleep -Seconds 1

Write-Host ">>> Logcat for PhotoEditorActivity & MeituNativeEngine:"
& $adb -s $target logcat -d -s "PhotoEditorActivity:V" "MeituNativeEngine:V" "MeituReborn:V"
