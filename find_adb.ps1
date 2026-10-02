$adbFound = $null

if (Get-Command adb -ErrorAction SilentlyContinue) {
    $adbFound = (Get-Command adb).Source
} else {
    $candidates = @(
        "$env:LOCALAPPDATA\Android\Sdk\platform-tools\adb.exe",
        "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe",
        "D:\Android\Sdk\platform-tools\adb.exe",
        "C:\platform-tools\adb.exe"
    )
    foreach ($c in $candidates) {
        if (Test-Path $c) {
            $adbFound = $c
            break
        }
    }
}

if (-not $adbFound) {
    # Search in user directory
    $searched = Get-ChildItem -Path "$env:LOCALAPPDATA\Android" -Recurse -Filter "adb.exe" -ErrorAction SilentlyContinue | Select-Object -First 1
    if ($searched) {
        $adbFound = $searched.FullName
    }
}

Write-Host "ADB_PATH: $adbFound"
if ($adbFound) {
    & $adbFound version
}
