$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$apk = "F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\build\outputs\apk\debug\app-debug.apk"
$serial = "BQLN4XOZKRW4QCEM"

Write-Host ">>> Installing APK onto Redmi 9C (USB: $serial)..."
$installResult = & $adb -s $serial install -r -t -d $apk
Write-Host "INSTALL_RESULT: $installResult"
