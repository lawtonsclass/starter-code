# the programs we want to use to compile our stuff
CXX=g++
CXXFLAGS=-g
CC=gcc
CCFLAGS=-g
AS=as
ASFLAGS=-g
LD=ld

# what we want to build when we just say "make"
BINARIES=testALU
all: $(BINARIES)

# how to compile each different kind of .o file
%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $^
%.o : %.c
	$(CC) $(CCFLAGS) -c $^
%.o : %.s
	$(AS) $(ASFLAGS) $^ -o $@

testALU: testALU.o alu.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(BINARIES) *.o
