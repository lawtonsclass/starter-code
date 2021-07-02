# the programs we want to use to compile our stuff
CXX=g++
CXXFLAGS=-std=c++17 -g
CC=gcc
CCFLAGS=-g
AS=as
ASFLAGS=-g
LD=ld
LDFLAGS=

# what we want to build when we just say "make"
BINARIES=compiler
all: $(BINARIES)

# how to compile each different kind of .o file
%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $^
%.o : %.c
	$(CC) $(CCFLAGS) -c $^
%.o : %.s
	$(AS) $(ASFLAGS) $^ -o $@

compiler: compiler.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(BINARIES) *.o a.out assembly.s
