all: main

main: main.o libsort.a
	g++ -o main main.o libsort.a

main.o: main.cpp
	g++ -c main.cpp

libsort.a: ms.o qs.o 
	ar rs libsort.a ms.o qs.o 

qs.o: qs.cpp
	g++ -c qs.cpp

mergesort.o: mergesort.cpp
	g++ -c mergesort.cpp

clean:
	rm -rf *o main
