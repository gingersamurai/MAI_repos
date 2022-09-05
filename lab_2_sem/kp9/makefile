run : main
	./main
main : sort.o main.o
	gcc main.o sort.o -o main
sort.o : sort.c
	gcc -c sort.c -o sort.o
main.o : main.c 
	gcc -c main.c -o main.o

clean : 
	rm -rf main main.o sort.o
