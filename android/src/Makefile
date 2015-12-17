CC=/opt/android-toolchain/arm-linux-androideabi/bin/gcc
CFLAGS = -pie -FPIE
BIN=../bin/

SRCS = $(wildcard energy-test_*.c)
PROGS = $(patsubst %.c,%,$(SRCS))
CLEAN = $(patsubst %.c,$(BIN)%,$(SRCS))

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $(BIN)$@ $<

clean:
	rm -f $(CLEAN)
