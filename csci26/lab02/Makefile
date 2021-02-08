BINARIES=testRSA

CC=g++
CCFLAGS=-std=c++17 -g

all: $(BINARIES)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $^

testRSA: testRSA.o rsa.o testing.o
	$(CC) $(CCFLAGS) $^ -o $@

clean:
	rm -f *.o $(BINARIES)
