/**
 * Copyright 2019 Bella Rose
 * 
 * Client program for AssassinManager
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <regex>
#include "AssassinManager.h"

using namespace std;

int main(int argc, char **argv) {
    ifstream f;
    string filename;
    string temp;
    vector<string> players;
    cout << "Name of game players file? ";
    getline(cin, filename);
    f.open(filename);
    while(f.is_open() && getline(f, temp)) {
		regex rgx ("\r");
		temp = regex_replace(temp, rgx, "");
        players.push_back(temp);
    }
    f.close();

    AssassinManager assassin_manager(players);

    cout << "\nCurrent kill ring:" << endl;
    assassin_manager.printKillRing();
    cout << "Current graveyard:" << endl;
    assassin_manager.printGraveyard();

    while (!assassin_manager.gameOver()) {
        cout << "\nNext Victim? ";
        getline(cin, temp);
        assassin_manager.kill(temp);

        cout << "\nCurrent kill ring:" << endl;
        assassin_manager.printKillRing();
        cout << "Current graveyard:" << endl;
        assassin_manager.printGraveyard();
    }
    cout << "\nGame was won by " << assassin_manager.winner() << endl;
    cout << "Final graveyard is as follows:" << endl;
    assassin_manager.printGraveyard();
    cout << endl;

    return EXIT_SUCCESS;    
}
