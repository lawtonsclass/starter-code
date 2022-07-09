BINARIES=testGeneration

CC=g++
CCFLAGS=-g

all: $(BINARIES)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $^

testGeneration.o: testGeneration.cpp generation.h
	$(CC) $(CCFLAGS) -c $<

testGeneration: testGeneration.o testing.o
	$(CC) $(CCFLAGS) $^ -o $@

clean:
	rm -f *.o $(BINARIES)
