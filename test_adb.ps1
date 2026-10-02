$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
& $adb connect 192.168.1.3:40333
Start-Sleep -Seconds 1
& $adb devices -l
