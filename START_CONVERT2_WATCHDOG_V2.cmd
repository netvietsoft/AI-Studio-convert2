@echo off
setlocal
cd /d "%~dp0"

echo ============================================================
echo CONVERT2 AGENT WATCHDOG V2 - AUTONOMOUS MODE
echo ============================================================
echo.
echo This mode enables:
echo   --dangerously-skip-permissions
echo.
echo Use only on the trusted CONVERT2 development machine.
echo.

set "REPO=%CD%"

powershell.exe -NoProfile -ExecutionPolicy Bypass ^
  -File "%~dp0CONVERT2_Agent_Watchdog_V2.ps1" ^
  -RepoPath "%REPO%" ^
  -IntervalSeconds 180 ^
  -PrintTimeoutMinutes 45

pause
