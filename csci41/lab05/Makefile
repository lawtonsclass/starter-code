CXX=g++
CXXFLAGS=-std=c++17

BINARIES=testDeque testStack

all: $(BINARIES)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $^

testDeque: testDeque.o testing.o Deque.h
	$(CXX) $(CXXFLAGS) testDeque.o testing.o -o $@

testStack: testStack.o testing.o Deque.h Stack.h
	$(CXX) $(CXXFLAGS) testStack.o testing.o -o $@

clean:
	rm -f $(BINARIES) *.o
