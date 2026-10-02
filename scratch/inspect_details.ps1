$root = "F:\CONVERT\Material Image Editor\Mitu\material"

Write-Host "=== 1. DETAIL OF apple_camera_filter ==="
Get-ChildItem -Path "$root\apple_camera_filter" -Depth 2 | Select-Object -First 20 FullName

Write-Host "=== 2. DETAIL OF CameraOnlineMaterial ==="
Get-ChildItem -Path "$root\CameraOnlineMaterial" -Directory -Recurse | Select-Object -First 20 FullName

Write-Host "=== 3. DETAIL OF 5002 ==="
Get-ChildItem -Path "$root\5002\50020000" -File | Select-Object Name, Length
if (Test-Path "$root\5002\50020000\config.json") {
    Get-Content "$root\5002\50020000\config.json" -Raw | Select-Object -First 10
}

Write-Host "=== 4. DETAIL OF 201400013 aigcConfig.json ==="
if (Test-Path "$root\2014\201400013\aigcConfig.json") {
    Get-Content "$root\2014\201400013\aigcConfig.json" -Raw
}

Write-Host "=== 5. DETAIL OF 4001 (Lips) ==="
Get-ChildItem -Path "$root\4001" -Depth 2 -Filter "*.png" | Select-Object -First 10 Name

Write-Host "=== 6. DETAIL OF CameraOnlineMaterial light3D1 & beautyPart3 shaders ==="
Get-ChildItem -Path "$root\CameraOnlineMaterial" -Include "*.fs", "*.vs" -Recurse | Select-Object -First 15 FullName
