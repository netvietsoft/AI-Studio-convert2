$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
$serial = "BQLN4XOZKRW4QCEM"

Write-Host ">>> Checking Redmi 9C (USB)..."
$state = & $adb -s $serial get-state
Write-Host "STATE: $state"

$model = & $adb -s $serial shell getprop ro.product.model
$brand = & $adb -s $serial shell getprop ro.product.brand
$androidVer = & $adb -s $serial shell getprop ro.build.version.release
$sdkVer = & $adb -s $serial shell getprop ro.build.version.sdk
$abi = & $adb -s $serial shell getprop ro.product.cpu.abi
$abiList = & $adb -s $serial shell getprop ro.product.cpu.abilist

Write-Host "BRAND: $brand"
Write-Host "MODEL: $model"
Write-Host "ANDROID_VER: $androidVer (API $sdkVer)"
Write-Host "PRIMARY_ABI: $abi"
Write-Host "ABI_LIST: $abiList"
