BINARIES=testLogic

CC=g++
CCFLAGS=-std=c++17 -g

all: $(BINARIES)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $^

testLogic: testLogic.o logic.o testing.o
	$(CC) $(CCFLAGS) $^ -o $@

clean:
	rm -f *.o $(BINARIES)
