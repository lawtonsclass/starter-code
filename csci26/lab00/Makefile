BINARIES=hello testPi testPrimes

CC=g++
CCFLAGS=-std=c++17 -g

all: $(BINARIES)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $^

hello: hello.o
	$(CC) $(CCFLAGS) $^ -o $@

testPi: testPi.o pi.o testing.o
	$(CC) $(CCFLAGS) $^ -o $@

testPrimes: testPrimes.o primes.o testing.o
	$(CC) $(CCFLAGS) $^ -o $@

clean:
	rm -f *.o $(BINARIES)
