all: main

main:
	g++ main.cpp -o main.o -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f *.o

