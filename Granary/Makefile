main.exe: main.o queue.o stack.o granary.o
	gcc -std=c99 -o main.exe main.o queue.o stack.o granary.o

main.o: main.c granary.h
	gcc -std=c99 -c main.c

queue.o: queue.c queue.h
	gcc -std=c99 -c queue.c

stack.o: stack.c stack.h
	gcc -std=c99 -c stack.c

granary.o: granary.c granary.h queue.h stack.h
gcc -std=c99 -c granary.c
