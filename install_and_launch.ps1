$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$apk = "F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\build\outputs\apk\debug\app-debug.apk"

Write-Host ">>> Connecting to 192.168.1.3:37821..."
$connOut = & $adb connect 192.168.1.3:37821
Write-Host "CONNECT_RESULT: $connOut"

Write-Host ">>> Checking devices..."
$devs = & $adb devices -l
Write-Host "$devs"

# Determine target device serial
$targetDevice = "192.168.1.3:37821"
if ($devs -notmatch "192.168.1.3:37821") {
    # Fallback to the mDNS serial if present
    $match = [regex]::Match($devs, "(adb-[^\s]+)\s+device")
    if ($match.Success) {
        $targetDevice = $match.Groups[1].Value
    }
}

Write-Host ">>> Target Device: $targetDevice"
Write-Host ">>> Installing APK ($apk)..."
$installOut = & $adb -s $targetDevice install -r -t -d $apk
Write-Host "INSTALL_RESULT: $installOut"

if ($installOut -match "Success") {
    Write-Host ">>> Launching MainActivity..."
    $launchOut = & $adb -s $targetDevice shell am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.MainActivity
    Write-Host "LAUNCH_RESULT: $launchOut"

    Start-Sleep -Seconds 2
    Write-Host ">>> Checking app process status..."
    $psOut = & $adb -s $targetDevice shell "ps -A | grep mtxx"
    Write-Host "APP_PROCESS: $psOut"
}
