CC = g++
CFLAGS = -Wall -std=c++11 -fPIC
LIBS = -lm

all: ../Q2/libpoisson.so program

program: program.cpp ../Q2/libpoisson.so
	$(CC) $(CFLAGS) -o program program.cpp -I../Q2 -L../Q2 -lpoisson $(LIBS) -Wl,-rpath,../Q2

../Q2/libpoisson.so: ../Q2/poisson.cpp
	$(CC) $(CFLAGS) -shared -o ../Q2/libpoisson.so ../Q2/poisson.cpp $(LIBS)

clean:
	rm -f program ../Q2/libpoisson.so

