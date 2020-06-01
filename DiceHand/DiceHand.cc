/**
 * Copyright 2019 Bella Rose
 * 
 * implements DiceHand.h
 */

#include <cstdlib>
#include <random>
#include <stdexcept>
#include <iostream>
#include <string>
#include "DiceHand.h"

using namespace std;

//initialize static class member
int DiceHand::lastID = 0; //private

DiceHand::DiceHand(int number_dice) : distribution(1,6) {
    if (number_dice < 1) {
        throw invalid_argument(number_dice + " is not a valid hand size.");
    }
    this->handSize = number_dice;
    lastID++;
    this->handID = lastID;
    this->hand = new int [handSize];
    rollDice();
}

DiceHand::DiceHand(const DiceHand & dice_hand) {
    lastID++;
    this->handID = lastID;
    this->handSize = dice_hand.handSize;
    this->hand = new int [handSize];
    int i;
    for (i = 0; i < handSize; i++) {
        this->hand[i] = dice_hand.hand[i];
    }
}

DiceHand::~DiceHand() {
    cout << "hand with ID " << getHandID() << " being deleted" << endl;
    lastID--;
    delete [] this->hand;
}

const int DiceHand::getHandSize() {
    return this->handSize;
}

const int DiceHand::getHandID() {
    return this->handID;
}

void DiceHand::rollDice() {
    int i;
    for (i = 0; i < getHandSize(); i++) {
        this->hand[i] = distribution(generator);
    }
}

void DiceHand::showHand() {
    int i;
    printf("Hand #%d:", getHandID());
    for (i = 0; i < getHandSize(); i++) {
        // cout << (i == 0) ? ("Hand #" + getHandID() + ": " + this->hand[i]) : 
        //     (" " + this->hand[i]);
        printf(" %d", this->hand[i]);
    }
    cout << endl;
}

int DiceHand::at(int index) {
    if (index > getHandSize() || index < 0) {
        throw out_of_range(index + " is not valid index.");
    }
    return *(this->hand + index);
}

void DiceHand::reroll(int index) {
    if (index > getHandSize() || index < 0) {
        throw out_of_range(index + " is not valid index.");
    }
    *(this->hand + index) = distribution(generator);
}

void DiceHand::setSize(int newSize) {
    if (newSize < 1) {
        throw invalid_argument(newSize + " is not a valid hand size.");
    }
    delete [] hand;
    this->handSize = newSize;
    this->hand = new int [handSize];
    rollDice();
}

int* DiceHand::getHand() {
    int *copy = new int [this->handSize];
    int i;
    for (i = 0; i < handSize; i++) {
        copy[i] = this->hand[i];
    }
    return copy;
}

// this thing can be simplified again
int* DiceHand::faceCounts() {
    int *counters = new int [7];
    int i;
    for (i = 0; i < 7; i++) {
        counters[i] = 0;
    }
    for (i = 0; i < this->handSize; i++) {
        if (hand[i] == 1) {
            counters[1] += 1;
        } else if (hand[i] == 2) {
            counters[2] += 1;
        } else if (hand[i] == 3) {
            counters[3] += 1;
        } else if (hand[i] == 4) {
            counters[4] += 1;
        } else if (hand[i] == 5) {
            counters[5] += 1;
        } else if (hand[i] == 6) {
            counters[6] += 1;
        }
    }
    return counters;
}

DiceHand &DiceHand::operator=(const DiceHand & dice_hand) {
    if (this == &dice_hand) {
        return *this;
    }
    delete [] this->hand;
    this->handID = dice_hand.handID;
    this->handSize = dice_hand.handSize;
    this->hand = new int [handSize];
    int i;
    for (i = 0; i < handSize; i++) {
        hand[i] = dice_hand.hand[i];
    }
    return *this;
}

string DiceHand::handValue(int counts[]) {
    // check if input array is of the right size
    int maxValue = 0;
    int maxCount = 0;
    int i;
    for (i = 1; i < 7; i++) {
        if (maxCount < counts[i]) {
            maxCount = counts[i];
            maxValue = i;
        }
    }
    string str = to_string(maxCount) + " " + to_string(maxValue) + 
                ((maxCount != 1) ? "s\n" : "\n");
    return str;
}

int DiceHand::compare(DiceHand & dice_hand) {
    int ret;
    int *count_1 = faceCounts();
    int *count_2 = dice_hand.faceCounts();
    string this_handValue = handValue(count_1);
    string dh_handValue = handValue(count_2);
    if (this_handValue[0] > dh_handValue[0]) {
        ret = 1;
    } else if (this_handValue[0] < dh_handValue[0]) {
        ret = -1;
    } else if ((this_handValue[0] == dh_handValue[0]) && this_handValue[2] == '1') {
        ret = 1;
    } else {
        ret = 0;
    }
    delete [] count_1;
    delete [] count_2;
    return ret;
}

ostream & operator <<(ostream &os, DiceHand &dice_hand) {
    int i;
    string str;
    str = "Hand #" + to_string(dice_hand.getHandID()) + ":" ;
    for (i = 0; i < dice_hand.getHandSize(); i++) {
        str += " " + to_string(dice_hand.hand[i]);
    }
    os << str;
    return os;
}