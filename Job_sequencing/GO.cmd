if .%USERDOMAIN% == .DINOPC goto :savasPC
rem MIF kompiuteris
path C:\PROGRA~2\Dev-Cpp\MinGW64\bin\;%path%
mingw32-make.exe
goto :run

:savasPC
make

:run

rem Testas 1
echo 4 > test1.txt
echo 2 3 100 >> test1.txt
echo 1 1 10 >> test1.txt
echo 2 6 15 >> test1.txt
echo 1 4 27 >> test1.txt

main.exe test1.txt > result1.txt
type result1.txt

rem Testas 2
echo 3 > test2.txt
echo 1 1 3 >> test2.txt
echo 1 2 2 >> test2.txt
echo 1 3 7 >> test2.txt

main.exe test2.txt > result2.txt
type result2.txt

rem Testas 3
echo 3 > test3.txt
echo 1 3 0 >> test3.txt
echo 1 3 0 >> test3.txt
echo 1 2 10 >> test3.txt

main.exe test3.txt > result3.txt
type result3.txt

rem Testas 4
echo 4 > test4.txt
echo 2 1 3 >> test4.txt
echo 1 1 1 >> test4.txt
echo 3 5 2 >> test4.txt
echo 2 2 2 >> test4.txt

main.exe test4.txt -mode fullSearch -timeout 0.1 > result4.txt
type result4.txt