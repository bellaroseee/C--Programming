AssassinManagerClient: AssassinManagerClient.o AssassinManager.o
	g++ -Wall -g -std=c++11 -o AssassinManagerClient AssassinManagerClient.o AssassinManager.o

AssassinManager.o: AssassinManager.h AssassinManager.cc
	g++ -Wall -g -std=c++11 -c AssassinManager.cc

AssassinManagerClient.o: AssassinManager.h AssassinManagerClient.cc
	g++ -Wall -g -std=c++11 -c AssassinManagerClient.cc

clean:
	rm -rf AssassinManagerClient *.o *~
	rm -rf AssassinManager *.o *~