$root = "F:\CONVERT\Material Image Editor\Mitu\material"
$folders = Get-ChildItem -Path $root -Directory

foreach ($f in $folders) {
    Write-Host "============================================="
    Write-Host "FOLDER: $($f.Name)"
    $subDirs = Get-ChildItem -Path $f.FullName -Directory
    Write-Host "Subdirectories count: $($subDirs.Count)"
    if ($subDirs.Count -gt 0) {
        $sampleSub = ($subDirs | Select-Object -First 10 -ExpandProperty Name) -join ", "
        Write-Host "Sample subdirs: $sampleSub"
    }
    
    # Check common material file types
    $files = Get-ChildItem -Path $f.FullName -File -Recurse -ErrorAction SilentlyContinue
    $extGroups = $files | Group-Object Extension | Sort-Object Count -Descending | Select-Object -First 8
    $extStr = ($extGroups | ForEach-Object { "$($_.Name): $($_.Count)" }) -join " | "
    Write-Host "File types: $extStr"

    # Search for config files like json, plist, xml, lua, etc.
    $configs = $files | Where-Object { $_.Extension -in ".json", ".plist", ".xml", ".lua", ".ini" } | Select-Object -First 5
    foreach ($c in $configs) {
        Write-Host "  Config sample: $($c.FullName.Substring($root.Length))"
    }
}
