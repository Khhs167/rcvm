# ReCT Virtual Machine buildfile

C_SRC:=$(wildcard src/*.c) $(wildcard src/lists/*.c)
H_SRC:=$(wildcard include/*.h)

C_OBJ:=$(patsubst %.c,%.o,$(C_SRC))

CC:=gcc
CFLAGS:=-g -Wall -Iinclude -Ivendor/include

LD:=gcc
LDFLAGS:=-g
LIB:=

RM:=rm -rf

LAUNCH_OPTIONS:=
EXE:=rcvm

%.o: %.c ${H_SRC}
	$(CC) -c $< $(CFLAGS) -o $@

.PHONY: bin
bin: ${C_OBJ}
	$(LD) $(LDFLAGS) $^ -o $(EXE) $(LIB)

run: bin
	./$(EXE)  ${LAUNCH_OPTIONS}

clean:
	$(RM) ${C_OBJ}

cleandist:
	$(RM) $(EXE)

cleanall: clean cleandist

.PHONY: all
all: bin
