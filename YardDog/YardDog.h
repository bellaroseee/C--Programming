/**
 * Copyright 2019 Bella Rose
 */

#ifndef YARDDOG_H_
#define YARDDOG_H_

#include <iostream>
#include "Yard.h"

class YardDog : public Yard {
	public:
		static const char DEFAULT_DIG_SYMBOL = '.'; //CLASS CONSTANT
		
		//Member Functions
        YardDog();
		YardDog(const int, const int, const char);
		void setYard();
        int findBone();
        friend std::ostream& operator<<(std::ostream &out, Yard y);
		
	private:
		Yard yard; //The object containing a 2-D array with a fence and the 3 bones, in which the dog will dig while looking for a bone. 
		int dogRow, dogCol; //dog’s current location in the yard
		char symbol; //show that a hole has been dug at a certain position in the yard. 
		
		//Member Functions
		bool boneFound (int row, int col);
};

#endif  // YARDDOG_H_
