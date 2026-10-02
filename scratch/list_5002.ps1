$root = "F:\CONVERT\Material Image Editor\Mitu\material\5002"
$dirs = Get-ChildItem -Path $root -Directory
foreach ($d in $dirs) {
    $cfg = Join-Path $d.FullName "config.json"
    if (Test-Path $cfg) {
        $json = Get-Content $cfg -Raw | ConvertFrom-Json
        Write-Host "$($d.Name): name=$($json.name), hex=$($json.hexColor), alpha=$($json.alpha), defAlpha=$($json.defaultAlpha)"
    }
}
