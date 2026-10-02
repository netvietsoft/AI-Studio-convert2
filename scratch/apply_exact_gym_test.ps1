$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
& $adb connect 192.168.1.3:40333
Start-Sleep -Milliseconds 500

Write-Host "1. Launching PhotoEditorActivity with exact gym image & Whiten +61%..."
& $adb -s 192.168.1.3:40333 shell am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity -e image_path "/sdcard/Pictures/Telegram/IMG_20260928_100951_897.jpg" -e target_category "cat_skin" -e tool_id "tool_skin_bright" --ei intensity 61
Start-Sleep -Seconds 3

Write-Host "2. Capturing screen..."
& $adb -s 192.168.1.3:40333 shell screencap -p /sdcard/hw_exact_gym_whiten61.png
& $adb -s 192.168.1.3:40333 pull /sdcard/hw_exact_gym_whiten61.png "C:\Users\PC.DESKTOP-81LIH38\.gemini\antigravity-ide\brain\56fd227d-6b4a-43e8-80a5-02015fa93579\scratch\hw_exact_gym_whiten61.png"

Write-Host "DONE"
