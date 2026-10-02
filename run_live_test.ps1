$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$target = "192.168.1.18:40159"

Write-Host ">>> Connecting to $target..."
& $adb connect $target
Start-Sleep -Milliseconds 500

Write-Host ">>> 1. Delivering Intent to trigger Rose Gold Hair Dye (80%)..."
& $adb -s $target shell "am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity --es target_category cat_hair --es tool_id tool_hair_rose_gold --ei intensity 80"

Start-Sleep -Seconds 3

Write-Host ">>> 2. Capturing live screenshot from Samsung SM-A075F..."
& $adb -s $target shell "screencap -p /sdcard/evidence_galaxy_a50_0_dyed.png"
& $adb -s $target pull /sdcard/evidence_galaxy_a50_0_dyed.png evidence_galaxy_a50_0_dyed.png

Write-Host ">>> 3. Fetching C++ Native Logs from device..."
$logs = & $adb -s $target logcat -d | Select-String -Pattern "PhotoEditorActivity|BiSeNet|HairMattingEngine|HairStrandDye|MeituNativeEngine" | Select-Object -Last 25
Write-Host "$logs"
