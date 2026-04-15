main.exe: main.o algorithm.o
	gcc -std=c99 -o main.exe main.o algorithm.o

main.o: main.c algorithm.h
	gcc -std=c99 -c main.c

algorithm.o: algorithm.c algorithm.h
	gcc -std=c99 -c algorithm.c
