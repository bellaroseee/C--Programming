/**
 * Copyright 2019 Bella Rose
 * 
 * Client program for DiceHand
 */

#include <cstdlib>
#include <iostream>
#include "DiceHand.h"

using namespace std;

int main (int agrc, char** argv) {
    // TEST CONSTRUCTOR
    cout << "testing constructor:" << endl;
    DiceHand dice_1;
    cout << "Hand with default number of dice: " << dice_1 << endl;
    DiceHand dice_2(4);
    cout << "Hand with 4 dice: " << dice_2 << endl;

    // TEST ACCESSORS
    cout << "\ntesting accessors:" << endl;
    cout << "Hand " << dice_1.getHandID() << " is of size " << dice_1.getHandSize() << endl;
    cout << "\tfirst die is : " << dice_1.at(0) << endl;
    cout << "Hand " << dice_2.getHandID() << " is of size " << dice_2.getHandSize() << endl;
    cout << "\tfirst die is : " << dice_2.at(0) << endl;
    cout << "using showHand()" << endl;
    dice_1.showHand();
    dice_2.showHand();
    int *hand1 = dice_1.getHand();
    int *hand2 = dice_2.getHand();
    delete [] hand1;
    delete [] hand2;


    // TEST MUTATORS
    cout << "\ntesting mutators: " << endl;
    dice_1.rollDice();
    cout << "Rerolling Hand 1: " << dice_1 << endl;
    dice_2.rollDice();
    cout << "Rerolling Hand 2: " << dice_2 << endl;
    dice_1.setSize(6);
    dice_2.setSize(6);
    cout << "Resize both hands to 6:\n\t" << dice_1 << "\n\t" << dice_2 << endl;

    // TEST OTHERS
    // HANDVALUE & FACECOUNTS
    int * faceCount_1 = dice_1.faceCounts();
    int * faceCount_2 = dice_2.faceCounts();
    cout << "Hand 1 value is : " << DiceHand::handValue(faceCount_1);
    cout << "Hand 2 value is : " << DiceHand::handValue(faceCount_2);
    delete [] faceCount_1;
    delete [] faceCount_2;

    // TEST ASSIGNMENT
    cout << "\ntesting assignment:" << endl;
    DiceHand dice_2_cpy = dice_2;
    cout << dice_2_cpy << " is a copy of " << dice_2 << endl;

    // TEST COMPARE
    cout << "\ntesting compare:" << endl;
    cout << "comparing hand 1 and hand 2: " << dice_1.compare(dice_2) << endl;
    return EXIT_SUCCESS;
}