all: main
	sudo mv libsort.so /usr/lib
	sudo ldconfig

main: main.o libsort.so
	g++ -o main main.o libsort.so

main.o: main.cpp
	g++ -c main.cpp

libsort.so: ms.o qs.o 
	g++ -shared -o libsort.so ms.o qs.o 

qs.o: qs.cpp
	g++ -fPIC -c qs.cpp

mergesort.o: mergesort.cpp
	g++ -fPIC -c mergesort.cpp

clean:
	rm -rf *o main
