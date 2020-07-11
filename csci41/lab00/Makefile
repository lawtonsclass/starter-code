all: hello runBox testBox

hello: hello.cpp
	g++ -std=c++17 hello.cpp -o hello

box.o: box.cpp
	g++ -std=c++17 -c box.cpp

runBox.o: runBox.cpp
	g++ -std=c++17 -c runBox.cpp

runBox: runBox.o box.o
	g++ -std=c++17 runBox.o box.o -o runBox

testBox.o: testBox.cpp
	g++ -std=c++17 -c testBox.cpp

testBox: testBox.o box.o
	g++ -std=c++17 testBox.o box.o -o testBox

clean:
	rm -f hello runBox testBox *.o
