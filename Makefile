CC = g++
CFLAGS = -Wall
LIBS   = -lsfml-graphics -lsfml-window -lsfml-system
OBJ_FILES := $(wildcard bin/*.o)

all: main

main: physics
	$(CC) $(CFLAGS) main.cpp -o main.o $(LIBS) $(OBJ_FILES)

physics: $(patsubst %.cpp, %.o, $(wildcard Physics/*.cpp))
	$(CC) $(CFLAGS) $< $@ -c -lm

clean:
	rm -f bin/*.o
