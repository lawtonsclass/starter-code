BINARIES=binaryVsLinear tryStack tryQueue tryPriorityQueue tryList tryMap

all: $(BINARIES)

binaryVsLinear: binaryVsLinear.cpp timer.cpp
	g++ -std=c++17 $^ -o $@

tryStack: tryStack.cpp
	g++ -std=c++17 $^ -o $@

tryQueue: tryQueue.cpp
	g++ -std=c++17 $^ -o $@

tryPriorityQueue: tryPriorityQueue.cpp
	g++ -std=c++17 $^ -o $@

tryList: tryList.cpp
	g++ -std=c++17 $^ -o $@

tryMap: tryMap.cpp
	g++ -std=c++17 $^ -o $@

clean:
	rm -f $(BINARIES)
