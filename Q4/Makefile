CC = g++
CFLAGS = -std=c++11 -Wall -fprofile-arcs -ftest-coverage

all: dijkstra

dijkstra: dijkstra.cpp
	$(CC) $(CFLAGS) dijkstra.cpp -o dijkstra

clean:
	rm -f dijkstra
	rm -f *.gcno *.gcda

coverage: dijkstra
	./dijkstra < input.txt # Assuming you have an input file named input.txt
	gcov dijkstra.cpp

.PHONY: clean coverage

