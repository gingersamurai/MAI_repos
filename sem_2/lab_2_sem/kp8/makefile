run : main
	./main
main : list.o main.o
	gcc main.o list.o -o main
list.o : list.c
	gcc -c list.c -o list.o
main.o : main.c 
	gcc -c main.c -o main.o

clean : 
	rm -rf main main.o list.o
