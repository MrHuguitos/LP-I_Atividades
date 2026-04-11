main: main.o io.o
	g++ -o main main.o io.o

main.o: main.cpp io.h
	g++ -c main.cpp

io.o: io.cpp io.h
	g++ -c io.cpp

test: main
	./main

clean:
	rm -f *.o main