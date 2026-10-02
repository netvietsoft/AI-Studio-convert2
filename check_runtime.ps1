$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"

Write-Host ">>> Setting up adb reverse tcp:9999 tcp:9999..."
$revOut = & $adb reverse tcp:9999 tcp:9999
Write-Host "REVERSE_RESULT: $revOut"

Write-Host ">>> Getting Host IP Address..."
$ip = (Get-NetIPAddress -AddressFamily IPv4 | Where-Object { $_.InterfaceAlias -match "Wi-Fi|Ethernet" -and $_.IPAddress -like "192.168.*" }).IPAddress
Write-Host "HOST_LAN_IP: $ip"

Write-Host ">>> Checking Running App on Device..."
$appStatus = & $adb shell "dumpsys activity activities | grep -E 'mResumedActivity|mFocusedActivity'"
Write-Host "ACTIVITY_STATUS: $appStatus"
