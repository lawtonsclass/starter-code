sqrtTest: sqrtTest.o sqrt.o testing.o
	g++ sqrtTest.o sqrt.o testing.o -o sqrtTest

sqrtTest.o: sqrtTest.cpp
	g++ -c sqrtTest.cpp

sqrt.o: sqrt.cpp
	g++ -c sqrt.cpp

testing.o: testing.cpp
	g++ -c testing.cpp

clean:
	rm -f *.o sqrtTest