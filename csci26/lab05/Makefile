BINARIES=testTicTacToe

CC=g++
CCFLAGS=-g

all: $(BINARIES)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $^

testTicTacToe: testTicTacToe.o tictactoe.o testing.o
	$(CC) $(CCFLAGS) $^ -o $@

clean:
	rm -f *.o $(BINARIES)
