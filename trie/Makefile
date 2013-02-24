PREFIX=/opt/bliksem
CC = gcc
CFLAGS=-Wall -O0 -ggdb -I$(PREFIX)/include
LDFLAGS=-L$(PREFIX)/lib -Wl,-rpath,$(PREFIX)/lib


all: haltes

objs: trie.c haltes.c
	$(CC) -c $(CFLAGS) $<

haltes: trie.o haltes.o
	$(CC) -o $@ $(CFLAGS) trie.o haltes.o $(LDFLAGS)

clean:
	rm *.o haltes
