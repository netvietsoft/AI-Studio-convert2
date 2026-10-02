$env:JAVA_HOME = "C:\Program Files\Microsoft\jdk-17.0.19.10-hotspot"
$env:PATH = "$env:JAVA_HOME\bin;" + $env:PATH
Set-Location -Path "F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2"
Write-Host "Starting Gradle assembleDebug for 8 modules integration..."
.\gradlew.bat --no-daemon :app:assembleDebug
