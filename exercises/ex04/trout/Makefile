util.o: util.c util.h
	gcc -c util.c -Wall

trout.o: trout.h trout.c util.h
	gcc -c trout.c -Wall

main.o: main.c trout.h util.h
	gcc -c main.c -Wall

trout: util.o trout.o main.o
	gcc util.o trout.o main.o -o trout -Wall
