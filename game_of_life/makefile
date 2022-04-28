all: life.exe clean

life.exe: gol.o func.o
	gcc gol.o func.o -lncursesw -o life

gol.o: gol.c
	gcc -c gol.c -Wall -ansi -pedantic

func.o: func.c
	gcc -c func.c -Wall -ansi -pedantic

clean:
	del *.o