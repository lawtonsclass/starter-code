BINARIES=testRelation

CC=g++
CCFLAGS=-g

all: $(BINARIES)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $^

testRelation: testRelation.o relation.o testing.o
	$(CC) $(CCFLAGS) $^ -o $@

clean:
	rm -f *.o $(BINARIES)
