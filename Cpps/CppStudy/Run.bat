
:: rmdir build
:: mkdir build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
::cmake -G "NMake Makefiles" ..
::nmake
main.exe
cd ..