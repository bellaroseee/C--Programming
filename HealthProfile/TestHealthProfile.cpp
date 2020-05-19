/**
 * Copyright 2019 Bella Rose
 */

#include <iostream>
#include <string>
#include "HealthProfile.h"

using namespace std;

int main(){
    string theName;
    int age{0};
    int wt{0};
    int ht{0};
    
    cout << "What is patient's name? ";  
    getline(cin, theName);
    cout << "What is patient's age? ";
    cin >> age;
    cout << "What is patient's weight in lbs? ";
    cin >> wt;
    cout << "What is patient's height in inches? ";
    cin >> ht;
    
    HealthProfile healthProfile1{theName, age, wt, ht};
    
    cout << "Patient's Profile:";
    healthProfile1.displayProfile();  
    
    cout << "\nEnter new name for patient: ";
    getline(cin, theName);
    getline(cin, theName);
    healthProfile1.setName(theName);
    
    cout << "Enter new age for patient: ";
    cin >> age;
    healthProfile1.setAge(age);

    cout << "Patient's new profile: ";
    healthProfile1.displayProfile();  

    cout << "\nMaximum Heart Rate: " << healthProfile1.maxHeartRate();
    cout << "\nLow target (50% of max): " << healthProfile1.lowTargetRate();
    cout << "\nHigh target (85% of max): " << healthProfile1.highTargetRate();
    healthProfile1.showBMI();

    cout << "\nBirthday : " << healthProfile1.birthday() << endl;

    return EXIT_SUCCESS;    
}