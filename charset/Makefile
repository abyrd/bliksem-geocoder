PREFIX=/opt/bliksem
CC = gcc
CFLAGS=-Wall -O0 -ggdb -I$(PREFIX)/include
LDFLAGS=-L$(PREFIX)/lib -Wl,-rpath,$(PREFIX)/lib
OBJS=mapping.o utf8-read.o utf8.o
DEPS=utf8.h mapping.h

all: utf8-test

%.o: %.c $(DEPS) 
	$(CC) -c -o $@ $< $(CFLAGS)

utf8-test: $(OBJS)
	$(CC) -o $@ $(CFLAGS) $^ $(LDFLAGS)

clean:
	rm *.o haltes
