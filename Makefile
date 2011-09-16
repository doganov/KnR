SHELL = /bin/sh
CC = gcc
CFLAGS = -Wall -std=c99
LIBS =
SRC=$(wildcard *.c)
OBJ=$(basename $(SRC))

.PHONY: clean

all: $(OBJ)

clean:
	rm -fv $(OBJ)

%.o: %c
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
