CC = g++
DEBUG = -g
WARNINGS = -Wno-unused-variable
LFLAGS = -Wno-unused-variable
CFLAGS = $(LFLAGS) -c $(DEBUG)

all: output

output: main.o Blackjack.o Hand.o Card.o
	$(CC) main.o Blackjack.o Hand.o Card.o -o blackjack

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Blackjack.o: Blackjack.cpp Blackjack.h
	$(CC) $(CFLAGS) Blackjack.cpp

Hand.o: Hand.cpp Hand.h
	$(CC) $(CFLAGS) Hand.cpp

Card.o: Card.cpp Card.h
	$(CC) $(CFLAGS) Card.cpp

clean:
	rm *.o blackjack

