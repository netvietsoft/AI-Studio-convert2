$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$target = "192.168.1.18:34335"
& $adb connect $target | Out-Null
& $adb -s $target shell am force-stop com.mt.mtxx.mtxx.convert
Start-Sleep -Milliseconds 500
& $adb -s $target logcat -c
& $adb -s $target shell "am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity --es tool_id tool_hair_rose_gold --ei intensity 70 --es auto_save_path test_hair_fresh.png"
Start-Sleep -Seconds 3
& $adb -s $target logcat -d | Select-String -Pattern "PhotoEditorActivity|HairStrandDye|HairMattingEngine|MeituNativeEngine|FaceDetector106"
