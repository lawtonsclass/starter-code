CXX=g++
CXXFLAGS=-std=c++17

BINARIES=testDeque testStack calculator

all: $(BINARIES)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $^

testDeque: testDeque.o testing.o Deque.h
	$(CXX) $(CXXFLAGS) $^ -o $@

testStack: testStack.o testing.o Deque.h Stack.h
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(BINARIES) *.o
