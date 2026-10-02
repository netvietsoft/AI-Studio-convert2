$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$target = "192.168.1.3:40333"

& $adb connect $target
Start-Sleep -Seconds 1

Write-Host ">>> 1. Testing tool_filter_apple_15p (iPhone 15 Pro Mộc Raw)..."
& $adb -s $target shell "am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity --es target_category cat_filters --es tool_id tool_filter_apple_15p --ei intensity 80"

Start-Sleep -Seconds 2
$log1 = & $adb -s $target logcat -d -s "PhotoEditorActivity:V" | Select-Object -Last 10
Write-Host "LOG_APPLE_15P:`n$log1"

Write-Host ">>> 2. Testing tool_lip_dudu_3d (Môi Căng Mọng Dudu Lips 3D)..."
& $adb -s $target shell "am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity --es target_category cat_makeup --es tool_id tool_lip_dudu_3d --ei intensity 85"

Start-Sleep -Seconds 2
$log2 = & $adb -s $target logcat -d -s "PhotoEditorActivity:V" | Select-Object -Last 10
Write-Host "LOG_DUDU_LIPS:`n$log2"

Write-Host ">>> 3. Testing tool_hair_5002_brick_red (Nhuộm Đỏ Gạch 5002)..."
& $adb -s $target shell "am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity --es target_category cat_hair --es tool_id tool_hair_5002_brick_red --ei intensity 75"

Start-Sleep -Seconds 2
$log3 = & $adb -s $target logcat -d -s "PhotoEditorActivity:V" | Select-Object -Last 10
Write-Host "LOG_HAIR_5002:`n$log3"
