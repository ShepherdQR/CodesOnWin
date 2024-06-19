
:: rmdir build
:: mkdir build
@echo off
cls
cd build
@REM cmake -G "MSYS Makefiles" ..
cmake -G "MinGW Makefiles" ..
cmake --build .

@REM cmake -G "MinGW Makefiles" ..
@REM mingw32-make

::cmake -G "NMake Makefiles" ..
::nmake
cd bin
main.exe
cd ..
cd ..