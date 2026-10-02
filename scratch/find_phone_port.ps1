$ip = "192.168.1.3"
$adb = "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"

$portsToCheck = @(40333, 37307, 37821, 45907, 40303, 38888, 41111, 42222, 43333, 44444, 45555)

Write-Host "Scanning common ports on $ip..."
$foundPort = $null

foreach ($port in $portsToCheck) {
    try {
        $tcp = New-Object System.Net.Sockets.TcpClient
        $iar = $tcp.BeginConnect($ip, $port, $null, $null)
        $wait = $iar.AsyncWaitHandle.WaitOne(300, $false)
        if ($wait) {
            $tcp.EndConnect($iar)
            Write-Host "Port $port is OPEN!"
            $foundPort = $port
            $tcp.Close()
            break
        }
        $tcp.Close()
    } catch {
        # ignore
    }
}

if (-not $foundPort) {
    Write-Host "Scanning range 35000..45000..."
    for ($p = 35000; $p -le 45000; $p += 100) {
        try {
            $tcp = New-Object System.Net.Sockets.TcpClient
            $iar = $tcp.BeginConnect($ip, $p, $null, $null)
            $wait = $iar.AsyncWaitHandle.WaitOne(80, $false)
            if ($wait) {
                $tcp.EndConnect($iar)
                Write-Host "Range match port: $p"
                $foundPort = $p
                $tcp.Close()
                break
            }
            $tcp.Close()
        } catch {}
    }
}

if ($foundPort) {
    Write-Host "Connecting ADB to $ip`:$foundPort..."
    $conn = & $adb connect "$ip`:$foundPort"
    Write-Host "$conn"
    Start-Sleep -Seconds 1
    & $adb devices -l
} else {
    Write-Host "No open ADB port found on $ip yet."
    & $adb devices -l
}
