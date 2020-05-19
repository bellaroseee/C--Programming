/**
 * Copyright 2019 Bella Rose
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

    const int getHandSize();                // accessor
    const int getHandID();                  // accessor
    int at(int index);
    int *getHand();
    void showHand();

    void rollDice();
    void reroll(int index);
    void setSize(int newSize);

    int *faceCounts();
    int compare(DiceHand &);

    DiceHand & operator=(const DiceHand &); // override assignment operator
    friend std::ostream & operator <<(std::ostream &os, DiceHand &dice_hand);
        // override << operator

    static std::string handValue(int counts[]);
    static int const DEFAULT_NUMBER_DICE = 2;
};

#endif  // DICEHAND_H