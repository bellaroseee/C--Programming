/**
 * Copyright 2019 Bella Rose
 * 
 * a DiceHand object of a certain ID with a certain size 
 */

#ifndef DICEHAND_H
#define DICEHAND_H

#include <cstdlib>
#include <random>

class DiceHand {
private:
    int handSize;
    int *hand;
    int handID;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution;

    // keep track of the most recent ID assigned to DiceHand object
    // initialized to 0, incremented everytime new object is created
    static int lastID;
    
public:
    DiceHand(int=DEFAULT_NUMBER_DICE);      // default constructor
    DiceHand(const DiceHand &);             // copy constructor
    ~DiceHand();                            // default destructor

    // returns the size of hand
    const int getHandSize();
    // returns the ID of hand
    const int getHandID();
    // returns the hand value at index
    int at(int index);
    // returns the hand
    int *getHand();
    // prints ouf the hand
    void showHand();

    // rolls the dixe
    void rollDice();
    // re rolls the dice
    void reroll(int index);
    // set the size of the hand
    void setSize(int newSize);

    // counts the face value of the hand
    int *faceCounts();
    // comparing 2 dicehand object
    int compare(DiceHand &);

    DiceHand & operator=(const DiceHand &); // override assignment operator
    friend std::ostream & operator <<(std::ostream &os, DiceHand &dice_hand);
        // override << operator

    static std::string handValue(int counts[]);
    static int const DEFAULT_NUMBER_DICE = 2;
};

#endif  // DICEHAND_H