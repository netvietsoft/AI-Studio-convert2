$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$target = "192.168.1.18:40159"

Write-Host ">>> Ensuring connection to $target..."
& $adb connect $target
Start-Sleep -Milliseconds 500

Write-Host "=== STEP 1: Verify current window focus ==="
$focus = & $adb -s $target shell "dumpsys window | grep -E 'mCurrentFocus|mFocusedApp'"
Write-Host "$focus"

Write-Host "`n=== STEP 2: Read Model Initialization Logcat ==="
$logs = & $adb -s $target logcat -d | Select-String -Pattern "PhotoEditorActivity|BiSeNetFaceParser|HairMattingEngine|HairStrandDye|MeituNativeEngine" | Select-Object -Last 30
Write-Host "$logs"

Write-Host "`n=== STEP 3: Capture Baseline Screenshot from Samsung A50s ==="
& $adb -s $target shell "screencap -p /sdcard/editor_baseline.png"
& $adb -s $target pull /sdcard/editor_baseline.png evidence_device_editor_baseline.png

Write-Host "`n=== STEP 4: Launching Tool Hair Rose Gold (Preset 5, 80%) ==="
& $adb -s $target shell "am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity --es target_category cat_hair --es tool_id tool_hair_rose_gold --ei intensity 80"

Start-Sleep -Seconds 2

Write-Host "`n=== STEP 5: Capture Dyed Screenshot from Samsung A50s ==="
& $adb -s $target shell "screencap -p /sdcard/editor_dyed.png"
& $adb -s $target pull /sdcard/editor_dyed.png evidence_device_hair_rose_gold.png

Write-Host "`n=== STEP 6: Read Native Hair Dye Logs ==="
$dyeLogs = & $adb -s $target logcat -d | Select-String -Pattern "HairStrandDye|HairMattingEngine|BiSeNet" | Select-Object -Last 20
Write-Host "$dyeLogs"
