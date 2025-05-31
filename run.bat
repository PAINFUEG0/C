@echo off
setlocal

set "SRC=%~1"
set "NAME=%~n1"
set "EXE=./dist/%NAME%.exe"

gcc "%SRC%" -o "%EXE%"

if errorlevel 1 (
    exit /b 1
)

"%EXE%"

pause
