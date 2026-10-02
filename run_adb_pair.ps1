$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"

Write-Host "Killing adb server..."
& $adb kill-server

Start-Sleep -Seconds 1

Write-Host "Starting adb server..."
& $adb start-server

Write-Host "Attempting adb pair 192.168.1.3:37307 639993..."
$pairOut = & $adb pair 192.168.1.3:37307 639993
Write-Host "PAIR_OUTPUT: $pairOut"

Start-Sleep -Seconds 2

Write-Host "Checking adb devices..."
$devOut = & $adb devices -l
Write-Host "DEVICES_OUTPUT:`n$devOut"
