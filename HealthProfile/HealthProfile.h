/**
 * Copyright 2019 Bella Rose
 */

#include <string>
#include <iostream>

using namespace std;

class HealthProfile {

public:
    // constructor
    HealthProfile(string name, int yearsOld, int wt, int ht)
        : patient{name} {
            
        weight = wt;
        height = ht; 
        if (yearsOld >= 18) {
            age = yearsOld;
        }    
    }
    

    std::string getName() const {
        return patient;
    }

    int getAge() const {
        return age;
    }

    int getWeight() const {
        return weight;
    }

    int getHeight() const {
        return height;
    }

    void setName(std::string newName) {
        patient = newName;
    }

    void setAge(int newAge) {
        if (newAge >= 18) {
            age = newAge;
        }
    }

    void setWeight(int newWeight) {
        weight = newWeight;
    }

    void displayProfile() {
        cout << "\nPatient\t: " << patient;
        cout << "\nAge\t: " << age;
        cout << "\nWeight\t: " << weight << "lbs";
        cout << "\nHeight\t: " << height/12 << "\'" << height%12 << "\"";  
    } 

    int maxHeartRate() {
        return 220-age;
    }

    double lowTargetRate() {
        return 0.5 * maxHeartRate();
    }

    double highTargetRate() {
        return 0.85 * maxHeartRate(); 
    }

    void showBMI() {
        double BMI = (weight*703.0) / (height*height);

        cout << "\nBMI is " << BMI;
        cout << "\nBMI VALUES";
        cout << "\nUnderweight : less than 18.5";
        cout << "\nNormal : between 18.5 and 24.9";
        cout << "\nOverweight : between 25 and 29.9";
        cout << "\nObese : 30 or greater";
    }

    int birthday() {
        return age + 1;
    }
    
private:
    string patient; 
    int age{18};
    int weight{0};
    int height{0};

};