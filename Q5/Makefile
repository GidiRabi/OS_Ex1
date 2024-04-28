CC=g++
CFLAGS=-std=c++11 -Wall -Wextra -Wpedantic -g -pg

.PHONY: all clean

all: Kadane Brute_Force Divide_and_Conquer

Kadane: Kadane.cpp
	$(CC) $(CFLAGS) -o Kadane Kadane.cpp

Brute_Force: Brute_Force.cpp
	$(CC) $(CFLAGS) -o Brute_Force Brute_Force.cpp

Divide_and_Conquer: Divide_and_Conquer.cpp
	$(CC) $(CFLAGS) -o Divide_and_Conquer Divide_and_Conquer.cpp

clean:
	rm -f Kadane Brute_Force Divide_and_Conquer *.txt


# ./Kadane <seed> <size>
# ./Brute_Force <seed> <size>
# ./Divide_and_Conquer <seed> <size>

