BINARIES=testHashMap

CC=g++
CCFLAGS=-g

all: $(BINARIES)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $^

testHashMap: testHashMap.o hashMap.o testing.o
	$(CC) $(CCFLAGS) $^ -o $@

clean:
	rm -f *.o $(BINARIES)
