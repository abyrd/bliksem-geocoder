PREFIX=/opt/bliksem
CC = gcc
CFLAGS=-Wall -O0 -ggdb -I$(PREFIX)/include
LDFLAGS=-L$(PREFIX)/lib -Wl,-rpath,$(PREFIX)/lib
DEPS=trie.h
OBJS=trie.o haltes.o

all: haltes

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

haltes: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean:
	rm *.o haltes
