all:dicionarios.o
	gcc dicionarios.o -o dicionarios.out
dicionarios.o:dicionarios.c
	gcc -c dicionarios.c

clear:
	rm $(shell *.out)
	rm $(shell *.o)