/**
 * Copyright 2019 Bella Rose
 */

#include <iostream>
#include "Yard.h"
#include "YardDog.h"

YardDog::YardDog() : YardDog{Yard::MIN_ROWS, Yard::MIN_COLUMNS, YardDog::DEFAULT_DIG_SYMBOL} {}

YardDog::YardDog(const int rows, const int col, const char ch) {
	Yard yard{rows, col}; //use initializer list to invoke Yard constructor with first 2 parameter
	this->dogRow = Yard::MIN_ROWS;
	this->dogCol = Yard::MIN_COLUMNS;
	this->symbol = YardDog::DEFAULT_DIG_SYMBOL;
	setYard();
}

void YardDog::setYard() {
	dogRow = yard.getNumRows()/2;
	dogCol = yard.getNumColumns()/2;
	yard.Yard::yardWork();
}

//this thing can be improved
bool YardDog::boneFound(int row, int col) {
    // for (char bone: Yard::BONES) {
    //     if (yard(row, col) == bone) return true;
    // }
	for (char ch = 'A'; ch<= 'C'; ch++) {
        if (yard(row, col)==ch && yard(row-1, col)==' ' && yard(row+1, col)==' '
                && yard (row, col-1) == ' ' && yard(row, col+1)==' ') {
            return true;
        } else if (yard(row,col)==' ' && yard(row,col+1) == ch) {
            return true;
        } else if (yard(row,col) == ' ' && yard(row,col-1) == ch) {
            return true;
        } else if (yard(row,col) == ch && (yard(row+1,col)=='-' || yard(row-1,col)=='-')) {
            return true; 
        } else if (yard(row,col) == ch && (yard(row,col-1)=='|' || yard(row,col+1)=='|')) {
            return true; 
        } else if (yard(row,col) == ' ' && yard(row+1,col)== ch ) {
            return true; 
        } else if (yard(row,col) == ' ' && yard(row-1,col)==ch) {
            return true; 
        } else if (yard(row,col) == ch && yard(row,col) == ch++) {
            return true;
        }
    }
    return false;
} 

std::ostream& operator<<(std::ostream &out, Yard y) {
    for(int r=0; r<y.getNumRows(); r++) {
		for(int c=0; c<y.getNumColumns(); c++) {
			out << y(r,c);
		}
		out << std::endl;
	}
    return out;
}

int YardDog::findBone() {
    int holeCount = 1;
    std::string s;
    std::cout << yard;
    while(!boneFound(dogRow, dogCol)) {
        //std::cout << "the symbol is: " << symbol << std::endl;
        yard(dogRow, dogCol) = symbol;
        //std::cout << "test : " << yard(dogRow, dogCol) << std::endl;
        //std::cout << std::to_string(dogRow) << " " << std::to_string(dogCol) << std::endl;
        std::cout << yard; 
        
        std::cout << "Move dog N, S, E or W? ";
        getline(std::cin, s);
        // if (tolower(s[0]) != 'n' && tolower(s[0]) != 's' && tolower(s[0]) != 'e' && tolower(s[0]) != 'w') {

        // }
        if (tolower(s[0]) == 'n') {
            dogRow--;
        } else if (tolower(s[0]) == 's') {
            dogRow++;
        } else if (tolower(s[0]) == 'e') {
            dogCol++;
        } else /*if (tolower(s[0]) == 'w')*/ {
            dogCol--;
        }
        holeCount++;
    }
    yard(dogRow, dogCol) = 'H';
    std::cout << yard;
    return holeCount;
}