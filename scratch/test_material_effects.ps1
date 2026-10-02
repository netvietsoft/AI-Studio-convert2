$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$target = "192.168.1.3:40333"

& $adb connect $target
Start-Sleep -Seconds 1

Write-Host ">>> Testing tool_filter_apple_15p (iPhone 15 Pro Mộc Raw)..."
$test1 = & $adb -s $target shell "am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity --es targetCatId cat_filters --es targetToolId tool_filter_apple_15p --ei targetIntensity 80"
Write-Host "AM_TEST1: $test1"

Start-Sleep -Seconds 2
$log1 = & $adb -s $target logcat -d -s "PhotoEditorActivity:V" "ColorLutEngine:V" | Select-Object -Last 10
Write-Host "LOG1:`n$log1"

Write-Host ">>> Testing tool_lip_dudu_3d (Dudu Lips 3D)..."
$test2 = & $adb -s $target shell "am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity --es targetCatId cat_makeup --es targetToolId tool_lip_dudu_3d --ei targetIntensity 85"
Write-Host "AM_TEST2: $test2"

Start-Sleep -Seconds 2
$log2 = & $adb -s $target logcat -d -s "PhotoEditorActivity:V" "ColorLutEngine:V" | Select-Object -Last 10
Write-Host "LOG2:`n$log2"
