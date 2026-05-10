if .%USERDOMAIN% == .DINOPC goto :savasPC
rem MIF kompiuteris
path C:\PROGRA~2\Dev-Cpp\MinGW64\bin\;%path%
mingw32-make.exe
goto :toliau

:savasPC
make

:toliau
rem -- Pirmas testas: parametrai iš komandinės eilutės --
echo 6 virsuniu skaicius > params.txt
echo 0 1 1 0 0 0 >> params.txt
echo 1 0 1 1 0 0 >> params.txt
echo 1 1 0 0 1 0 >> params.txt
echo 0 1 0 0 1 1 >> params.txt
echo 0 0 1 1 0 1 >> params.txt
echo 0 0 0 1 1 0 >> params.txt
dfs.exe params.txt > result1.txt

rem -- Antras testas: parametrai nenurodyti (programa randa dfs.cfg failą) --
echo 8 virsuniu skaicius > dfs.cfg
echo 0 1 1 1 0 0 0 0 >> dfs.cfg
echo 1 0 1 0 1 0 0 0 >> dfs.cfg
echo 1 1 0 0 0 1 0 0 >> dfs.cfg
echo 1 0 0 0 1 0 1 0 >> dfs.cfg
echo 0 1 0 1 0 1 0 1 >> dfs.cfg
echo 0 0 1 0 1 0 0 1 >> dfs.cfg
echo 0 0 0 1 0 0 0 1 >> dfs.cfg
echo 0 0 0 0 1 1 1 0 >> dfs.cfg
dfs.exe > result2.txt
