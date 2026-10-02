$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$target = "192.168.1.18:34335"

# Ensure connected
& $adb connect $target | Out-Null

if ($args.Count -eq 0) {
    & $adb -s $target devices
} else {
    & $adb -s $target @args
}

