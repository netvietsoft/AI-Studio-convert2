$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$target = "192.168.1.18:40159"

Write-Host ">>> Connecting to $target..."
& $adb connect $target
Start-Sleep -Milliseconds 500

Write-Host ">>> Pushing 0.jpg to /sdcard/user_portrait.jpg..."
& $adb -s $target push scratch/0.jpg /sdcard/user_portrait.jpg

Write-Host ">>> Overwriting internal storage user_portrait.jpg via run-as..."
& $adb -s $target shell "run-as com.mt.mtxx.mtxx.convert cp /sdcard/user_portrait.jpg /data/data/com.mt.mtxx.mtxx.convert/files/user_portrait.jpg"

Write-Host ">>> Verifying internal storage file size..."
$check = & $adb -s $target shell "run-as com.mt.mtxx.mtxx.convert ls -l /data/data/com.mt.mtxx.mtxx.convert/files/user_portrait.jpg"
Write-Host "$check"

Write-Host ">>> Restarting PhotoEditorActivity with Rose Gold tool..."
& $adb -s $target shell am force-stop com.mt.mtxx.mtxx.convert
Start-Sleep -Milliseconds 500

& $adb -s $target shell "am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity --es target_category cat_hair --es tool_id tool_hair_rose_gold --ei intensity 80"

Start-Sleep -Seconds 3

Write-Host ">>> Capturing live screenshot of 0.jpg dyed on Samsung SM-A075F..."
& $adb -s $target shell "screencap -p /sdcard/evidence_0_jpg_dyed.png"
& $adb -s $target pull /sdcard/evidence_0_jpg_dyed.png evidence_device_0_jpg_rose_gold.png

Write-Host ">>> Checking Native Logs..."
$logs = & $adb -s $target logcat -d | Select-String -Pattern "PhotoEditorActivity|BiSeNet|HairMatting|HairStrandDye" | Select-Object -Last 15
Write-Host "$logs"
