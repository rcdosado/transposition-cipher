@echo off

REM This batch file allows your code to be 
REM compiled as binary


set dcpp=D:\Dev-Cpp\bin
for /R %%f in (*.c) do %dcpp%\g++.exe "%%f" -o "%%f"
rem for /R %%f in (*.c) do echo "%%f"
del *.obj
echo "all files compiled master.."
pause
