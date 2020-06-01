/**
 * Copyright 2019 Bella Rose
 * 
 * An interactive Rock Paper Scissor game
 * where the user plays against computer
 */

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>

enum class RPS {ROCK='r', PAPER='p', SCISSORS='s'};

using namespace std;

RPS getHumanChoice();
RPS getComputerChoice();
void displayChoice(string s, RPS t);
void roundResults(RPS h, int &i, RPS c, int &j);
void gameResults(int round, int i, int j);

int main(int argc, char **argv) {
    string s;
    char a;
    RPS h, c;
    int i = 0;
    int j = 0;
    int round = 0;
    cout << "Welcome to CS 210 Rock, Paper, Scissors!\n" << endl;
    do {
        h = getHumanChoice();
        displayChoice("human", h);

        c = getComputerChoice();
        displayChoice("computer", c);

        roundResults(h, i, c, j);
        cout << "\nPlay another round? ";
        getline(cin, s);
        round++;
    } while (tolower(s[0]) == 'y');
    gameResults(round , i, j);
}

// get the user input
RPS getHumanChoice() {
    string s;
    char c;
    RPS t;
    do {
        cout << "Enter R(ock), P(aper), S(cissors) > ";
        getline(cin, s);
        if (s.length() != 1) {
            throw invalid_argument("please enter r, p, or s");
        }
        c = tolower(s[0]);
        if (c == 'p') t = RPS::PAPER;
        if (c == 'r') t = RPS::ROCK;
        if (c == 's') t = RPS::SCISSORS;  
    } while (c != 'p' && c != 's' && c != 'r');
    return t;
}

// determine the computer choice
RPS getComputerChoice() {
    static bool firstTime = true;
    int r;
    if (firstTime) {
        srand(time(0));
        firstTime = false;
    }
    r = rand() % 3;
    if (r == 0) return RPS::ROCK;
    if (r == 1) return RPS::PAPER;
    if (r == 2) return RPS::SCISSORS;
}

void displayChoice(string s, RPS t) {
    switch (t)
    {
    case RPS::ROCK:
        cout << "The " << s << " played rock." << endl;
        break;
    case RPS::PAPER:
        cout << "The " << s <<" played paper." << endl;
        break;
    case RPS::SCISSORS:
        cout << "The " << s << " played scissors." << endl;
        break;
    }
}

// determines the result of the current round
void roundResults(RPS h, int &i, RPS c, int &j) {
    switch(h)
    {
    case RPS::ROCK:
        switch (c)
        {
        case RPS::ROCK:
            cout << "The round ended in a tie." << endl;
            break;
        case RPS::PAPER:
            cout << "Rats! The computer won that round." << endl;
            j++;
            break;
        case RPS::SCISSORS:
            cout << "The human beat the computer!" << endl;
            i++;
            break;
        default:
            break;
        }
        break;
    case RPS::PAPER:
        switch (c)
        {
        case RPS::PAPER:
            cout << "The round ended in a tie." << endl;
            break;
        case RPS::SCISSORS:
            cout << "Rats! The computer won that round." << endl;
            j++;
            break;
        case RPS::ROCK:
            cout << "The human beat the computer!" << endl;
            i++;
            break;
        default:
            break;
        }
        break;
    case RPS::SCISSORS:
        switch (c)
        {
        case RPS::SCISSORS:
            cout << "The round ended in a tie." << endl;
            break;
        case RPS::ROCK:
            cout << "Rats! The computer won that round." << endl;
            j++;
            break;
        case RPS::PAPER:
            cout << "The human beat the computer!" << endl;
            i++;
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

// determines the result of the game
void gameResults(int round, int i, int j) {
    string winner = "";
    double percent = 0.0;
    printf("%s: %d\n","Total rounds played", round);
    printf("%19s: %d\n","Human wins", i);
    printf("%19s: %d\n","Computer wins", j);
    if (i > j) { 
        winner = "human";
        if (j==0) {
            percent = 100.0;
        } else {
            percent = static_cast<double>(i)/static_cast<double>(j) * 100.0;
        }
    }
    if (i < j) {
        winner = "computer";
        if (i==0) {
            percent = 100.0;
        } else {
            percent = static_cast<double>(j)/static_cast<double>(i) * 100.0;
        }
    }
    if (winner.compare("") != 0) {
        printf("The %s won %.1f%% of the rounds,\n", winner.c_str(), percent);
        printf("so the %s won the game!\n", winner.c_str());
        return;
    }
    printf("The game ended in tie.\n");
}