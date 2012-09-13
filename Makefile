CC=gcc
CFLAGS=-Wall -O3 --std=gnu99 
LDFLAGS=-lm

dumblink: dumblink.c
	$(CC) $(CFLAGS) $(LDFLAGS) dumblink.c -o dumblink

clean:
	rm -f dumblink

all: dumblink
