CC = gcc
CFLAGS = -Wall -g

all: kitboom

kitboom: main.o input.o logic.o timer.o
	$(CC) $(CFLAGS) -o kitboom main.o input.o logic.o timer.o

main.o: main.c config.h
	$(CC) $(CFLAGS) -c main.c

input.o: input.c config.h
	$(CC) $(CFLAGS) -c input.c

logic.o: logic.c config.h
	$(CC) $(CFLAGS) -c logic.c

timer.o: timer.c config.h
	$(CC) $(CFLAGS) -c timer.c

clean:
	rm -f *.o kitboom
