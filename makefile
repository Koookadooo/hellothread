CC=gcc
CFLAGS=-Wall -Wextra -Werror
LIBS=-lpthread

hellothread: hellothread.o
	$(CC) $(CFLAGS) -o hellothread hellothread.o $(LIBS)

hellothread.o: hellothread.c
	$(CC) $(CFLAGS) -c hellothread.c

clean:
	rm -f *.o hellothread
