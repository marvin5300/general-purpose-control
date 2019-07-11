REM change windeployqt path to suit your compiler path
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
C:\Qt\5.11.2\msvc2017_64\bin\windeployqt.exe --release release\bin\keithley-control.exe
pause