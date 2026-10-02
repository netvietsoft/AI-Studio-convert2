$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$target = "192.168.1.18:40159"

Write-Host ">>> Connecting to $target..."
& $adb connect $target
Start-Sleep -Milliseconds 500

Write-Host "`n>>> 1. Pushing customer original image 0.jpg to /sdcard/user_portrait.jpg..."
& $adb -s $target push scratch/0.jpg /sdcard/user_portrait.jpg

Write-Host "`n>>> 2. Clearing previous logcat..."
& $adb -s $target logcat -c

Write-Host "`n>>> 3. Force-stopping and restarting PhotoEditorActivity with Rose Gold tool..."
& $adb -s $target shell am force-stop com.mt.mtxx.mtxx.convert
Start-Sleep -Milliseconds 500

& $adb -s $target shell "am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity --es target_category cat_hair --es tool_id tool_hair_rose_gold --ei intensity 80"

Start-Sleep -Seconds 3

Write-Host "`n>>> 4. Capturing live screenshot from Samsung SM-A075F..."
& $adb -s $target shell "screencap -p /sdcard/evidence_customer_0_rose_gold.png"
& $adb -s $target pull /sdcard/evidence_customer_0_rose_gold.png evidence_device_customer_0_dyed.png

Write-Host "`n>>> 5. Reading C++ Native Logcat..."
$logs = & $adb -s $target logcat -d | Select-String -Pattern "PhotoEditorActivity|BiSeNet|HairMatting|HairStrandDye|MeituNativeEngine" | Select-Object -Last 30
Write-Host "$logs"
