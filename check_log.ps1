$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$target = "192.168.1.18:40159"
& $adb connect $target
Start-Sleep -Milliseconds 300
& $adb -s $target logcat -d | Select-String "BiSeNet|bisenet|hair_matting|PhotoEditorActivity" | Select-Object -Last 40
