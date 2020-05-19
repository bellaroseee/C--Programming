/**
 * Copyright 2019 Bella Rose
 */

#include <iostream>
#include <random>
#include <array>

using namespace std;

const int MAX_HANDSIZE = 10;
const int DEFAULT_HANDSIZE = 7;
const int COUNT = 0;
const int FACE = 1;

void rollDice(array<int, MAX_HANDSIZE> & human_hand,
    array<int, MAX_HANDSIZE> & computer_hand, int=DEFAULT_HANDSIZE);
void showHand(string, array<int, MAX_HANDSIZE>, int=DEFAULT_HANDSIZE);
void calculateScore(const array<int, MAX_HANDSIZE>&,
    array<int, 2>&, int=DEFAULT_HANDSIZE);
string scoreString(const array<int, 2>&);
int compare(const array<int,2> &, const array<int,2> &);

int main(int argc, char** argv) {
    string player, s;
    int human_win = 0;
    int comp_win = 0;
    int tie = 0;
    array<int, MAX_HANDSIZE> human_hand;
    array<int, MAX_HANDSIZE> computer_hand;
    array<int, 2> human_score;
    array<int, 2> comp_score;

    cout << "Welcome to CS 210 Dice Game!" << endl;
    cout << "What is your name? ";
    getline(cin, player);

    do {
        rollDice(human_hand, computer_hand, DEFAULT_HANDSIZE);
        showHand(player, human_hand, DEFAULT_HANDSIZE);
        showHand("Computer", computer_hand, DEFAULT_HANDSIZE);
        calculateScore(human_hand, human_score, DEFAULT_HANDSIZE);
        calculateScore(computer_hand, comp_score, DEFAULT_HANDSIZE);
        cout << player << "'s score: " << scoreString(human_score) << endl;
        cout <<  "Computer's score: " << scoreString(comp_score) << endl;
        switch (compare(human_score, comp_score)) 
        {
        case 1:
            cout << scoreString(human_score) << " beats " << scoreString(comp_score) << endl;
            cout << player << " wins the round!" << endl;
            human_win++;
            break;
        case -1:
            cout << scoreString(comp_score) << " beats " << scoreString(human_score) << endl;
            cout << "Computer wins the round!" << endl;
            comp_win++;
            break;
        case 0:
            cout << scoreString(human_score) << " ties with " << scoreString(comp_score) << endl;
            cout << "round ends in a tie!" << endl;
            tie++;
            break;
        }

        cout << "\nPlay another round? ";
        getline(cin, s);
    } while (tolower(s[0]=='y'));

    cout << "\nTotal wins by " << player << ": " << to_string(human_win);
    cout << "\nTotal wins by Computer: " << to_string(comp_win);
    cout << "\nTotal ties: " << to_string(tie) << endl;

    return EXIT_SUCCESS;
}

void rollDice(array<int, MAX_HANDSIZE> & human_hand,
    array<int, MAX_HANDSIZE> & computer_hand, int s) {
    
    static default_random_engine generator;
    static uniform_int_distribution<int> distribution(1, 6);

    for (int i = 0; i < s; i++) {
        human_hand[i] = distribution(generator);
        computer_hand[i] = distribution(generator);
    }
}

void showHand(string player, array<int, MAX_HANDSIZE> hand, int s){
    cout << player << "'s hand: ";
    for (int i = 0; i < s; i++) {
        cout << ((i!=s-1) ? (to_string(hand[i]) + " ") :
            (to_string(hand[i]) + "\n"));
    }
}

void calculateScore(const array<int, MAX_HANDSIZE>& hand,
    array<int, 2>& hand_score, int s) {
    int count[] = {0, 0, 0, 0, 0, 0, 0};
    int maxValue = 0;
    int maxCount = 0;
    for (int i = 0; i < s; i++) {
        if (hand[i] == 1) count[1]++;
        if (hand[i] == 2) count[2]++;
        if (hand[i] == 3) count[3]++;
        if (hand[i] == 4) count[4]++;
        if (hand[i] == 5) count[5]++;
        if (hand[i] == 6) count[6]++;
    }
    for (int i = 0; i < 7; i++) {
        if (maxCount < count[i]) {
            maxValue = i;
            maxCount = count[i];
        }
    }
    hand_score[COUNT] = maxCount;
    hand_score[FACE] = maxValue;
}

string scoreString(const array<int, 2>& hand_score) {
    string ret = to_string(hand_score[COUNT]) + " " + to_string(hand_score[FACE]);
    ret += ((hand_score[COUNT]==1) ? "" : "s");
    return ret; 
}

int compare(const array<int,2> &hand_1, const array<int,2> &hand_2) {
    if(hand_1[COUNT] > hand_2[COUNT]) {
        return 1;
    } else if(hand_1[COUNT] < hand_2[COUNT]) {
        return -1;
    } else if(hand_1[COUNT] == hand_2[COUNT]) {
        if (hand_1[FACE] > hand_2[FACE]) {
            return 1;
        } else if (hand_1[FACE] < hand_2[FACE]) {
            return -1;
        }
    }
    return 0;
}