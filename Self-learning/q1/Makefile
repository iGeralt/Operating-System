all: main

main: main.o libsearch.a
	g++ -o main main.o libsearch.a

main.o: main.cpp
	g++ -c main.cpp

libsearch.a: bs.o ls.o hashing.o
	ar rs libsearch.a ls.o bs.o hashing.o

ls.o: ls.cpp
	g++ -c ls.cpp

bs.o: bs.cpp
	g++ -c bs.cpp

hashing.o: hashing.cpp
	g++ -c hashing.cpp

clean:
	rm -rf *o main
