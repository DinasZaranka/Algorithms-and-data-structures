dfs.exe: main.o graph.o
	gcc -std=c99 -Wall -o dfs.exe main.o graph.o

main.o: main.c graph.h
	gcc -std=c99 -Wall -c main.c

graph.o: graph.c graph.h
	gcc -std=c99 -Wall -c graph.c

clean:
	del *.o *.exe rezultatai.txt
