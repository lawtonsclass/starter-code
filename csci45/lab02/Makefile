# the programs we want to use to compile our stuff
CXX=g++
CXXFLAGS=-g -mfpu=neon -march=armv8-a
CC=gcc
CCFLAGS=-g -mfpu=neon -march=armv8-a
AS=as
ASFLAGS=-g -mfpu=neon -march=armv8-a
LD=ld
LDFLAGS=

# if this computer isn't running an ARM32 processor, use QEMU
UNAME=$(shell uname -m)
ifneq ($(UNAME), armv7l)
	CXX=arm-linux-gnueabihf-g++
	CC=arm-linux-gnueabihf-gcc
	AS=arm-linux-gnueabihf-as
	LD=arm-linux-gnueabihf-ld
	CXXFLAGS+= -static
	CCFLAGS+= -static
	LDFLAGS+= -static
endif

# what we want to build when we just say "make"
BINARIES=argv syscalls_easy syscalls_hard
all: $(BINARIES)

# how to compile each different kind of .o file
%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $^
%.o : %.c
	$(CC) $(CCFLAGS) -c $^
%.o : %.s
	$(AS) $(ASFLAGS) $^ -o $@

argv: argv.s
	$(CC) $(CCFLAGS) $^ -o $@

syscalls_easy: syscalls_easy.s
	$(CC) $(CCFLAGS) $^ -o $@

syscalls_hard: syscalls_hard.s
	$(CC) $(CCFLAGS) $^ -o $@

clean:
	rm -f $(BINARIES) *.o
