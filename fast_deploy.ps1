$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$apk = "F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\build\outputs\apk\debug\app-debug.apk"
$ip = "192.168.1.3"
$code = "153652"

Write-Host ">>> Step 1: Trying adb pair with port 45907..."
$pair1 = & $adb pair "${ip}:45907" $code
Write-Host "PAIR_45907: $pair1"

if ($pair1 -notmatch "Successfully paired") {
    Write-Host ">>> Trying adb pair with port 37307..."
    $pair2 = & $adb pair "${ip}:37307" $code
    Write-Host "PAIR_37307: $pair2"
}

Start-Sleep -Seconds 1

Write-Host ">>> Step 2: Connecting via ADB..."
& $adb connect "${ip}:37307"
& $adb connect "${ip}:45907"

Start-Sleep -Seconds 1
$devs = & $adb devices -l
Write-Host "DEVICES:`n$devs"

# Find target device ID
$target = $null
if ($devs -match "(192\.168\.1\.3:\d+)\s+device") {
    $target = $matches[1]
} elseif ($devs -match "(adb-[^\s]+)\s+device") {
    $target = $matches[1]
}

if (-not $target) {
    Write-Host "ERROR: Could not find online device for Samsung A50s!"
    exit 1
}

Write-Host ">>> Target Device: $target"
Write-Host ">>> Step 3: Installing APK ($apk)..."
$inst = & $adb -s $target install -r -t -d $apk
Write-Host "INSTALL_RESULT: $inst"

Write-Host ">>> Step 4: Reverse port 9999 for Backend communication..."
& $adb -s $target reverse tcp:9999 tcp:9999

Write-Host ">>> Step 5: Launching MainActivity on Samsung screen..."
$am = & $adb -s $target shell am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.MainActivity
Write-Host "LAUNCH_RESULT: $am"

Start-Sleep -Seconds 2
$topAct = & $adb -s $target shell "dumpsys window | grep -E 'mCurrentFocus|mFocusedApp'"
Write-Host "FOCUSED_ACTIVITY:`n$topAct"
