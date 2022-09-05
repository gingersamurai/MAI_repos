main : main.o io.o
	gcc main.o io.o -o main

io.o : io.c
	gcc -c io.c -o io.o

main.o : main.c
	gcc -c main.c -o main.o

clean :
	rm -rf main.o io.o main
	
