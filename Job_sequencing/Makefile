main.exe: main.o branchAndBound.o
	gcc -o main.exe main.o branchAndBound.o

main.o: main.c branchAndBound.h
	gcc -c main.c

branchAndBound.o: branchAndBound.c branchAndBound.h
	gcc -c branchAndBound.c
