CXX=g++
CXXFLAGS=-std=c++17 -g

BINARIES=hashTableTests

all: $(BINARIES)

testing.o : testing.cpp
	$(CXX) $(CXXFLAGS) -c $^

hashTableTests.o: hashTableTests.cpp hashTable.h
	$(CXX) $(CXXFLAGS) -c hashTableTests.cpp

hashTableTests: hashTableTests.o testing.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(BINARIES) *.o
