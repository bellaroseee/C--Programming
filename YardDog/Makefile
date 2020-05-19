# Copyright 2020 Bella Rose

CC = g++
CXXFLAG = -Wall -g -std=c++11

all: YardDogClient

YardDogClient: YardDogClient.o YardDog.o Yard.o
	$(CC) $(CXXFLAG) -o YardDogClient YardDogClient.o YardDog.o Yard.o

YardDog.o : YardDog.cc YardDog.h Yard.h
	$(CC) $(CXXFLAGS) -c YardDog.cc

Yard.o : Yard.cc Yard.h
	$(CC) $(CXXFLAGS) -c Yard.cc

clean:
	rm -rf YardDogClient *.o *~