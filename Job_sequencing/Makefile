main.exe: main.o algorithm.o
	gcc -o main.exe main.o algorithm.o

main.o: main.c algorithm.h
	gcc -c main.c

algorithm.o: algorithm.c algorithm.h
	gcc -c algorithm.c
