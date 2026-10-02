$root = "F:\CONVERT\Material Image Editor\Mitu\material"

Write-Host "=== APPLE CAMERA FILTER 15 PRO ==="
Get-ChildItem -Path "$root\apple_camera_filter\15pro_1" -Recurse | Select-Object Name, Length, Extension

Write-Host "=== 4001 LIP TEXTURE SAMPLE ==="
Get-ChildItem -Path "$root\4001\40010071" -Recurse | Select-Object Name, Length

Write-Host "=== 2155 BEAUTY PRESET SAMPLE ==="
Get-ChildItem -Path "$root\2155\2155001" -Recurse | Select-Object Name, Length
if (Test-Path "$root\2155\2155001\config.json") {
    Get-Content "$root\2155\2155001\config.json" -Raw
}
