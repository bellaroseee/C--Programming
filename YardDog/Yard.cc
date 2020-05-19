/**
 * Copyright 2019 Bella Rose
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <random>
#include <ctime>
#include "Yard.h"

using namespace std;

const vector<char> Yard::BONES{'A','B','C'};

Yard::Yard() : Yard{MIN_ROWS, MIN_COLUMNS} {}

Yard::Yard(int numRows, int numCols) {
	if(numRows < MIN_ROWS || numRows > MAX_ROWS)
		throw invalid_argument(to_string(numRows) + " not between " + 
			to_string(MIN_ROWS) + " and " + to_string(MAX_ROWS));
	if(numCols < MIN_COLUMNS || numCols > MAX_COLUMNS)
		throw invalid_argument(to_string(numCols) + " not between " + 
			to_string(MIN_COLUMNS) + " and " + to_string(MAX_COLUMNS));
	this->numRows = numRows;
	this->numColumns = numCols;
    yardWork();
}

int Yard::getNumRows() const {
	return numRows;
}

int Yard::getNumColumns() const {
	return numColumns;
}

void Yard::yardWork() {
	for(int r = 0; r < numRows; r++) {
   	    for(int c = 0; c < numColumns; c++) {
            if (r == 0 || r == numRows - 1) {
                if (c == 0) {
                    yard[r][c] = '+';
                    continue;
                }
                if (c == numColumns-1) {
                    yard[r][c] = '+';
                    continue;
                }
                else {
                    yard[r][c] = '-';
                    continue;
                }
            } else {
                if (c == 0) {
                    yard[r][c] = '|';
                    continue;
                }
                if (c == (numColumns-1)) {
                    yard[r][c] = '|';
                    continue;
                }
                else {
                    yard[r][c] = ' ';
                    continue;
                }
            }
        }
    }
    buryBones();
}
	
void Yard::showYard() const {
	for(int r=0; r<numRows; r++) {
		for(int c=0; c<numColumns; c++) {
			std::cout << yard[r][c];
		}
		std::cout << std::endl;
	}
}

char& Yard::operator() (int row, int col) {
	//return the lvalue of character stored at yard[row][col] location
	if (row > getNumRows() || col > getNumColumns() ) {
		throw out_of_range("out of range");
	}
	return yard[row][col];	
}

void Yard::buryBones() {
    static bool firstTime = true;
    if (firstTime) {
        srand(time(0));
        firstTime = false;
    }
	for (char bone : BONES) {
		int boneRow{0}, boneCol{0};
		do {
			boneRow = rand() % (numRows-1);
			boneCol = rand() % (numColumns-1);
		} while (yard[boneRow][boneCol] != ' ');
		yard[boneRow][boneCol] = bone;
	}
}