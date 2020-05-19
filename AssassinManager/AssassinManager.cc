/**
 * Copyright 2019 Bella Rose
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include "AssassinManager.h"

using namespace std;

AssassinManager::AssassinManager(const vector<string> &vector) {
    if (vector.size() == 0) {
        throw runtime_error("empty vector.");
    }
    killring = nullptr;
    graveyard = nullptr;

    killring = new AssassinNode(vector[0]);
    AssassinNode *current = killring;
    uint16_t i;
    for (i = 1; i < vector.size() ; i++) {
        AssassinNode *temp = new AssassinNode(vector[i]);
        current->next = temp;
        current = current->next;
    }
}

AssassinManager::~AssassinManager() {
    AssassinNode *current = killring;
    while (current != nullptr) {
        delete current;
        current = current->next;
    }
    current = graveyard;
    while (current != nullptr) {
        delete current;
        current = current->next;
    }
}

void AssassinManager::printKillRing() const {
    AssassinNode *current = killring;
    while (current != nullptr) {
        cout << "\t";
        cout << current->player << " is stalking " ;
        if (current->next == nullptr) {
            cout << killring->player << endl;
            return;
        }
        cout << current->next->player << endl;
        current = current->next;
    }
}

void AssassinManager::printGraveyard() const {
    AssassinNode *current = graveyard;
    while (current != nullptr) {
        cout << "\t" << current->player << " was killed by ";
        cout << current->killer << endl;
        current = current->next;
    }
}

bool AssassinManager::killRingContains(const string& name) const {
    AssassinNode *current = killring;
    while (current != nullptr) {
        string name1, name2;
        transform(current->player.begin(), current->player.end(), name1.begin(), ::tolower);
        transform(name.begin(), name.end(), name2.begin(), ::tolower);
        if (name1.compare(name2) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}

bool AssassinManager::graveyardContains(const std::string& name) const {
    AssassinNode *current = graveyard;
    while (current != nullptr) {
        string name1, name2;
        transform(current->player.begin(), current->player.end(), name1.begin(), ::tolower);
        transform(name.begin(), name.end(), name2.begin(), ::tolower);
        if (name1.compare(name2) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}

bool AssassinManager::gameOver() const {
    if (killring->next == nullptr) {
        return true;
    }
    return false;
}

string AssassinManager::winner() const {
    if (gameOver()) {
        return killring->player;
    }
    return "";
}

void AssassinManager::kill(const string & name) {
    if (!killRingContains(name)) {
        throw runtime_error(name + "is not in killring");
    }
    AssassinNode *killed = killring;
    // if first person killed is at the beginning of the list
    if (killed->player.compare(name) == 0) {
        AssassinNode *back = killring;
        while (back->next != nullptr) {
            back = back->next;
        }
        killed->killer = back->player;
        killring = killed->next;
        if (graveyard == nullptr) {
            graveyard = killed;
            graveyard->next = nullptr;
        } else {
            AssassinNode *temp = graveyard;
            graveyard = killed;
            graveyard->next = temp;
        }
        return;
    }
    // if person killed is in the middle of the list
    while (killed->next != nullptr) {
        if (killed->next->player.compare(name) == 0) {
            killed->next->killer = killed->player;
            AssassinNode *temp = killed->next->next;
            if (graveyard == nullptr) {
                graveyard = killed->next;
                graveyard->next = nullptr;
            } else {
                AssassinNode *graveyard_cpy = graveyard;
                graveyard = killed->next;
                graveyard->next = graveyard_cpy;
            }
            killed->next = temp;
            return;
        }
        killed = killed->next;
    }
}