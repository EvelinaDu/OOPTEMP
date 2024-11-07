cmake -S . -B Release -G "MinGW Makefiles"
cmake --install Release
cmake --build Release
cd Release
Students_analysis.exe
pause
