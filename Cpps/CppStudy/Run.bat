
:: rmdir build
:: mkdir build
@echo off
cls
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
::cmake -G "NMake Makefiles" ..
::nmake
main.exe
cd ..