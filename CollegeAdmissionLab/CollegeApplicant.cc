/**
 * Copyright 2019 Bella Rose
 */

#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

#include "CollegeApplicant.h"

using namespace std;

CollegeApplicant::CollegeApplicant() {
    CollegeApplicant::setApplicationData();
}

void CollegeApplicant::setApplicationData() {
    int min, max;
    this->typeTest = getTestType();
    if (typeTest.compare("S") == 0 || typeTest.compare("s") == 0) {
        min = 200;
        max = 800;
        this->math = getValidScore("MATH", min, max);
        this->reading = getValidScore("READING", min, max);
        this->writing = getValidScore("WRITING", min, max);
    } else {
        min = 1;
        max = 36;
        this->english = getValidScore("ENGLISH", min, max);
        this->math = getValidScore("MATH", min, max);
        this->reading = getValidScore("READING", min, max);
        this->science = getValidScore("SCIENCE", min, max);
    }
    cout << "\tmax GPA? ";
    cin >> this->maxGPA;
    cout << "\toverall GPA? ";
    cin >> this->overallGPA;
    if (this->overallGPA < 0 || this->overallGPA > this->maxGPA) {
        cerr << "\tinvalid GPA. overall GPA must be between 0 and maxGPA" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "\tTranscript Multiplier? ";
    cin >> this->multi;
    if (this->multi < 0.8 || this->multi > 1) {
        cerr << "\tinvalid multiplier. Trasncript multiplier must be between 0.8 and 1" << endl;
        exit(EXIT_FAILURE);
    }
}

string CollegeApplicant::getTestType() {
    string type;
    cout << "\tDo you have (S)AT scores or (A)CT scores? ";
    cin >> type;
    if (type.compare("S") !=0 && type.compare("s")!=0 &&
        type.compare("A")!=0 && type.compare("a")!=0) {
            cerr << "\tinvalid type. Please type S, s, A or a" << endl;
            exit(EXIT_FAILURE);
        }

    return type;
}

int CollegeApplicant::getValidScore(std::string prompt, int minScore, int maxScore) {
    int score;
    cout << "\tEnter " << prompt << " score between " << minScore << " and " << maxScore << ": ";
    cin >> score;
    if (score > maxScore || score < minScore) {
        cerr << "\tinvalid score. Please enter a score between " << minScore << " and " 
            << maxScore << endl;
        exit(EXIT_FAILURE);
    }
    return score;
}

double CollegeApplicant::normalizedExamScore() {
    if (typeTest.compare("S") == 0 || typeTest.compare("s") == 0) {
        return ((2 * this->math + this->reading + this->writing) / 32.0);
    }
    return ((this->english + 2 * this->math + this->reading + this->science)/1.8);
}

double CollegeApplicant::normalizedGPA() {
    return (this->overallGPA * 100 * this->multi / this->maxGPA);
}

double CollegeApplicant::overallScore() {
    return normalizedGPA() + normalizedExamScore();
}