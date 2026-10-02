$ip = "192.168.1.18"
$ports = 30000..45000
foreach ($p in $ports) {
    $t = New-Object System.Net.Sockets.TcpClient
    $c = $t.BeginConnect($ip, $p, $null, $null)
    $success = $c.AsyncWaitHandle.WaitOne(25, $false)
    if ($success) {
        try {
            $t.EndConnect($c)
            Write-Output "OPEN_PORT:$p"
        } catch {}
    }
    $t.Close()
}
