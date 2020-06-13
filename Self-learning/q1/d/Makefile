all: main

main: main.o libbasic.a
	gcc -o main main.o libbasic.a

main.o: main.c
	gcc -c main.c

libbasic.a: binarysearch.o linearsearch.o hashing.o
	ar rs libbasic.a linearsearch.o binarysearch.o hashing.o

linearsearch.o: linearsearch.c
	gcc -c linearsearch.c

binarysearch.o: binarysearch.c
	gcc -c binarysearch.c

hashing.o: hashing.c
	gcc -c hashing.c

clean:
	rm -rf *o main
