testBitOps: testBitOps.o bitOps.o testing.o
	g++ testBitOps.o bitOps.o testing.o -o testBitOps

testBitOps.o: testBitOps.cpp
	g++ -c testBitOps.cpp

bitOps.o: bitOps.cpp
	g++ -c bitOps.cpp

testing.o: testing.cpp
	g++ -c testing.cpp

clean:
	rm -f *.o testBitOps
