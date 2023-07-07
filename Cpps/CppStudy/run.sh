
# cd e: && cd E:/Codes/CodesOnWin/CodesOnWin/Cpps/CppStudy && bash ./run.sh


echo "Build starts.."
cd build
cmake ..
cmake --build .
./main.exe
cd ..
