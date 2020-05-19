# Copyright 2020 Bella Rose

#default target
test: TestHealthProfile.o
	g++ -Wall -g -std=c++11 -o test TestHealthProfile.o

#individual source file
TestHealthProfile.o: HealthProfile.h TestHealthProfile.cpp
	g++ -Wall -g -std=c++11 -c TestHealthProfile.cpp

#delete built files
clean:
	rm -rf test *.o *~
	rm -rf TestHealthProfile *o *~