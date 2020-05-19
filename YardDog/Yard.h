/**
 * Copyright 2019 Bella Rose
 */

#ifndef YARD_H_
#define YARD_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <random>
#include <ctime>

class Yard {
	public:
		static const int MIN_ROWS = 10;
		static const int MIN_COLUMNS = 15;
		static const int MAX_ROWS = 25;
		static const int MAX_COLUMNS = 50;
		static const std::vector<char> BONES;
		
		Yard(int numRows, int numCols);
		Yard(); //Default constructor
		
		int getNumRows() const, getNumColumns() const;
        void showYard() const;
		void yardWork();
		char& operator() (int row, int col);  //overload operator()
        
		
	private:
		//Data
		char yard[MAX_ROWS][MAX_COLUMNS];
		int numRows;
		int numColumns;
		
		//Member Functions
		void buryBones();	
		
		// std::default_random_engine engine; 
    	// std::uniform_int_distribution<int> randomRInt;
    	// std::uniform_int_distribution<int> randomCInt;
}; //end Yard class

#endif

