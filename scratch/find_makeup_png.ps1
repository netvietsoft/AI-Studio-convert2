$root = "F:\CONVERT\Material Image Editor\Mitu\material"

Write-Host "4008 PNGs:"
Get-ChildItem -Path "$root\4008" -Recurse -Filter "*.png" | Select-Object -First 5 FullName

Write-Host "4003 PNGs:"
Get-ChildItem -Path "$root\4003" -Recurse -Filter "*.png" | Select-Object -First 5 FullName

Write-Host "4004 PNGs:"
Get-ChildItem -Path "$root\4004" -Recurse -Filter "*.png" | Select-Object -First 5 FullName
