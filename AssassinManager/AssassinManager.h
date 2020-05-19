/**
 * Copyright 2019 Bella Rose
 */

#ifndef ASSASSIN_MANAGER_H_
#define ASSASSIN_MANAGER_H_

#include <vector>

class AssassinManager {
private:
    class AssassinNode {
    public:
        std::string player;  // node's player name
        std::string killer;  // node's player's killer
        AssassinNode *next;

        AssassinNode(std::string name) {
            this->player = name;
            this->killer = "";
            this->next = nullptr;
        }
    };

    AssassinNode *killring;
    AssassinNode *graveyard;
public:
    AssassinManager(const std::vector<std::string> &);  // constructor
    ~AssassinManager();                                 // destructor
    
    void printKillRing() const;
    void printGraveyard() const;

    bool killRingContains(const std::string&) const;
    bool graveyardContains(const std::string&) const;
    bool gameOver() const;
    std::string winner() const;

    void kill(const std::string&);
};

#endif  // ASSASSIN_MANAGER_H_