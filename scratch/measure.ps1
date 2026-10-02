$items = Get-ChildItem 'F:\CONVERT\Material Image Editor\Mitu\material' -Recurse -File
$sum = ($items | Measure-Object -Property Length -Sum).Sum / 1MB
Write-Host "Total Files: $($items.Count)"
Write-Host "Total Size (MB): $([math]::Round($sum, 2))"
