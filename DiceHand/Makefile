# Copyright 2020 Bella Rose

TestDiceHand: TestDiceHand.o DiceHand.o
	g++ -Wall -g -std=c++11 -o TestDiceHand TestDiceHand.o DiceHand.o

TestDiceHand.o: DiceHand.h TestDiceHand.cc
	g++ -Wall -g -std=c++11 -c TestDiceHand.cc

DiceHand.o: DiceHand.h DiceHand.cc
	g++ -Wall -g -std=c++11 -c DiceHand.cc

clean:
	rm -rf DiceHand *.o *~
	rm -rf TestDiceHand *.o *~