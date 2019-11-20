CC = g++
DEBUG = -g
WARNINGS = -Wno-unused-variable
LFLAGS = -Wno-unused-variable
CFLAGS = $(LFLAGS) -c $(DEBUG)

all: output

output: main.o Blackjack.o Hand.o Card.o
	$(CC) main.o Blackjack.o Hand.o Card.o -o blackjack

main.o: main.cc
	$(CC) $(CFLAGS) main.cc

Blackjack.o: Blackjack.cc Blackjack.h
	$(CC) $(CFLAGS) Blackjack.cc

Hand.o: Hand.cc Hand.h
	$(CC) $(CFLAGS) Hand.cc

Card.o: Card.cc Card.h
	$(CC) $(CFLAGS) Card.cc

clean:
	rm *.o blackjack

