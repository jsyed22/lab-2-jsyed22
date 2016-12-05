CC=gcc
CFLAGS=-g -Wall

all: main

lab2: main

main: util.o search.o sort.o main.o
	$(CC) main.o search.o sort.o util.o -o lab2

main.o: main.c search.h sort.h util.h
	$(CC) $(CFLAGS) -c main.c

search.o: search.c search.h
	$(CC) $(CFLAGS) -c search.c

sort.o: sort.c sort.h
		$(CC) $(CFLAGS) -c sort.c

util.o: util.c util.h
		$(CC) $(CFLAGS) -c util.c

clean:
	rm -f *.o *~ lab2

debug: all
	cgdb lab2

ddd: all
	ddd lab2
