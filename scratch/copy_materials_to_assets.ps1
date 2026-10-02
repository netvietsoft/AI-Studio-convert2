$srcRoot = "F:\CONVERT\Material Image Editor\Mitu\material"
$dstAssets = "F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\src\main\assets\material"

New-Item -ItemType Directory -Force -Path "$dstAssets\apple_camera" | Out-Null
New-Item -ItemType Directory -Force -Path "$dstAssets\samsung_camera" | Out-Null
New-Item -ItemType Directory -Force -Path "$dstAssets\makeup" | Out-Null
New-Item -ItemType Directory -Force -Path "$dstAssets\5002" | Out-Null

Write-Host ">>> 1. Copying Apple Camera Filters..."
Copy-Item "$srcRoot\apple_camera_filter\4s_1\4s\ar\res\arp\512x512#MCPLut.png" "$dstAssets\apple_camera\lut_4s.png" -Force
Copy-Item "$srcRoot\apple_camera_filter\5s_1\5s\ar\res\arp\512x512#MCPLut.png" "$dstAssets\apple_camera\lut_5s.png" -Force
Copy-Item "$srcRoot\apple_camera_filter\6s_2\6s\ar\res\arp\512x512#MCPLut.png" "$dstAssets\apple_camera\lut_6s.png" -Force
Copy-Item "$srcRoot\apple_camera_filter\8p_1\8p\newCommon\ziran.webp" "$dstAssets\apple_camera\lut_8p.webp" -Force
Copy-Item "$srcRoot\apple_camera_filter\xr_1\xr\newCommon\ziran.webp" "$dstAssets\apple_camera\lut_xr.webp" -Force
Copy-Item "$srcRoot\apple_camera_filter\xsmax_1\xsmax\newCommon\ziran.webp" "$dstAssets\apple_camera\lut_xs.webp" -Force
Copy-Item "$srcRoot\apple_camera_filter\11pro_1\11p\newCommon\ziran.webp" "$dstAssets\apple_camera\lut_11p.webp" -Force
Copy-Item "$srcRoot\apple_camera_filter\13pro_1\13p\newCommon\ziran.webp" "$dstAssets\apple_camera\lut_13p.webp" -Force
Copy-Item "$srcRoot\apple_camera_filter\15pro_1\15p\newCommon\ziran.webp" "$dstAssets\apple_camera\lut_15p.webp" -Force
Copy-Item "$srcRoot\apple_camera_filter\16pro_1\16p\newCommon\ziran.webp" "$dstAssets\apple_camera\lut_16p.webp" -Force
Copy-Item "$srcRoot\apple_camera_filter\17pro_2\17pro\17pro\ar\res\arp\512x512#MCPLut.png" "$dstAssets\apple_camera\lut_17p.png" -Force

Write-Host ">>> 2. Copying Samsung Camera Filter..."
Copy-Item "$srcRoot\CameraOnlineMaterial\cameraSamsung1\samsung\ar\res\arp\512x512#MCPLut.png" "$dstAssets\samsung_camera\lut_samsung.png" -Force

Write-Host ">>> 3. Copying Makeup Textures..."
Copy-Item "$srcRoot\4001\40010071\400140000071\lip_mask.png" "$dstAssets\makeup\lip_mask.png" -Force
Copy-Item "$srcRoot\4001\40010071\400140000071\lip_lut.png" "$dstAssets\makeup\lip_lut.png" -Force
Copy-Item "$srcRoot\4008\400800001410\ar\res\arp\sh5-2.png" "$dstAssets\makeup\blush_sh5.png" -Force
Copy-Item "$srcRoot\4003\400301010\400310001010\ar\res\arp\yy-2.png" "$dstAssets\makeup\eyeshadow_yy.png" -Force
Copy-Item "$srcRoot\4004\400401010\400410001010\ar\res\arp\gg-2.png" "$dstAssets\makeup\eyelash_gg.png" -Force

Write-Host ">>> 4. Generating 5002 Hair Colors JSON..."
$hairList = @()
$dirs = Get-ChildItem -Path "$srcRoot\5002" -Directory | Sort-Object Name
foreach ($d in $dirs) {
    $cfgPath = Join-Path $d.FullName "config.json"
    if (Test-Path $cfgPath) {
        $raw = Get-Content $cfgPath -Raw | ConvertFrom-Json
        $hex = $raw.hexColor
        if (-not $hex) { $hex = "#888888" }
        $alpha = if ($raw.defaultAlpha) { [int]$raw.defaultAlpha } else { 60 }
        $hairList += [PSCustomObject]@{
            id = $d.Name
            hex = $hex
            defAlpha = $alpha
            isVip = ($d.Name -in "50020004", "50020006", "50020007", "50020010", "50020013", "50020015", "50020016", "50020017", "50020018", "50020020", "50020022")
        }
    }
}

$hairList | ConvertTo-Json -Depth 3 | Set-Content -Path "$dstAssets\5002\hair_colors.json" -Encoding UTF8

Write-Host ">>> SUCCESS! Listing copied assets:"
Get-ChildItem -Path $dstAssets -Recurse -File | Select-Object FullName, Length
