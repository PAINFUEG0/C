@REM This script was vibe coded using Claude Sonnet 4.0

@echo off
setlocal enabledelayedexpansion

set "SRC=%~1"
set "NAME=%~n1"
set "FULL_PATH=%~dp1"

REM Replace \src\ with \dist\ in the path
set "OUT_DIR=!FULL_PATH:\src\=\dist\!"

REM Create output directory
if not exist "!OUT_DIR!" md "!OUT_DIR!"

REM Set executable path
set "EXE=!OUT_DIR!\%NAME%.exe"

echo Compiling %SRC% to !EXE!

gcc "%SRC%" -o "!EXE!"

if errorlevel 1 (
    echo Compilation failed!
    pause
    exit /b 1
)

echo Compilation successful!
echo Running !EXE!
echo.

"!EXE!"