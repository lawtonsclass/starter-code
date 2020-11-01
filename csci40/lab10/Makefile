sqrtTest: sqrtTest.o sqrt.o testing.o
	g++ -std=c++17 sqrtTest.o sqrt.o testing.o -o sqrtTest

sqrtTest.o: sqrtTest.cpp
	g++ -std=c++17 -c sqrtTest.cpp

sqrt.o: sqrt.cpp
	g++ -std=c++17 -c sqrt.cpp

testing.o: testing.cpp
	g++ -std=c++17 -c testing.cpp

clean:
	rm -f *.o sqrtTest