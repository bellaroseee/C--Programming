# Copyright 2020 Bella Rose

CC = g++
CXXFLAGS = -Wall -g -std=c++11

all: DiceGame

DiceGame: DiceGame.o
	$(CC) $(CXXFLAGS) -o DiceGame $<

%.o : %.cc
	$(CC) $(CXXFLAGS) -c $<

clean:
	rm -rf DiceGame *.o *~