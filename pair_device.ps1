$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"

Write-Host ">>> Executing adb pair 192.168.1.3:37307 639993..."
$pairResult = & $adb pair 192.168.1.3:37307 639993
Write-Host "Pair Result: $pairResult"

Write-Host ">>> Checking adb devices..."
$devices = & $adb devices
Write-Host "$devices"
