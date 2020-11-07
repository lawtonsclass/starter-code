testBitOps: testBitOps.o bitOps.o testing.o
	g++ -std=c++17 testBitOps.o bitOps.o testing.o -o testBitOps

testBitOps.o: testBitOps.cpp
	g++ -std=c++17 -c testBitOps.cpp

bitOps.o: bitOps.cpp
	g++ -std=c++17 -c bitOps.cpp

testing.o: testing.cpp
	g++ -std=c++17 -c testing.cpp

clean:
	rm -f *.o testBitOps
