main: main.c vector.c vector.h
	gcc main.c vector.c -o main

run: main
	./main