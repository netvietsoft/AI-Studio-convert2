$aapt = (Get-ChildItem -Path "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\build-tools" -Recurse -Filter "aapt.exe" | Select-Object -First 1).FullName
$apk = "F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\build\outputs\apk\debug\app-debug.apk"

Write-Host "AAPT: $aapt"
& $aapt dump badging $apk | Select-String -Pattern "package:|launchable-activity:|activity:" | Select-Object -First 20
