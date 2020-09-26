CXX=g++
CXXFLAGS=-std=c++17 -g

BINARIES=hashTableTests autocomplete

all: $(BINARIES)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $^

hashTableTests: hashTableTests.o testing.o hashTable.h
	$(CXX) $(CXXFLAGS) hashTableTests.o testing.o -o $@

clean:
	rm -f $(BINARIES) *.o
