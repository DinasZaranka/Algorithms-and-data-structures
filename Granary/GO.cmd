if .%USERDOMAIN% == .DINOPC goto :savasPC
rem MIF kompiuteris
path C:\PROGRA~2\Dev-Cpp\MinGW64\bin\;%path%
mingw32-make.exe
goto :toliau

:savasPC
make

:toliau
rem -- Pirmas testas: parametrai iš komandinės eilutės + nurodytas pseudo-atsitiktinių skaičių daviklis --
echo 365  pirkimo trukmė dienomis > params.txt
echo 100  kiekio norma (t) >> params.txt
echo 15   didžiausias kiekio nuokrypis (%%) >> params.txt
echo 200  kainos norma (Eur/toną) >> params.txt
echo 5   didžiausias kainos nuokrypis (%%) >> params.txt
echo 10   pardavimo antkainis (%%) >> params.txt
granary.exe params.txt -rnd 50 > result1.txt

rem -- Antras testas: parametrai nenurodyti (programa randa granary.cfg failą) --
echo 730  pirkimo trukmė dienomis > granary.cfg
echo 150  kiekio norma (t) >> granary.cfg
echo 25   didžiausias kiekio nuokrypis (%%) >> granary.cfg
echo 180  kainos norma (Eur/toną) >> granary.cfg
echo 10   didžiausias kainos nuokrypis (%%) >> granary.cfg
echo 40   pardavimo antkainis (%%) >> granary.cfg
granary.exe > result2.txt
