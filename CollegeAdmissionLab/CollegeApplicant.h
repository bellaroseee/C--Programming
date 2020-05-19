/**
 *  definition of College Applicant Class
 **/

#include <stdlib.h>
#include <iostream>
#include <string>

//using namespace std;

class CollegeApplicant {
public:
    // constructor
    CollegeApplicant();

    // This function will eventually be responsible for generating 
    // the indented lines 3-9 and 14-21 of the sample I/O session shown above. 
    // For the checkpoint it should simply assign the typeTest data member 
    // the value returned by the getTestType() function described next
    void setApplicationData();

    /*
    * Calculates the normalized exam score
    * 
    * Returns:
    *   - normalized exam score
    */
    double normalizedExamScore();


    /*
    * Calculates the normalized GPA
    *
    * Returns:
    *   - normalized GPA
    */
    double normalizedGPA();

    /*
    * Calculates the overall score
    * 
    * Returns:
    *   - overall score
    */
    double overallScore();

private:
    std::string typeTest;  // hold "S", "s", "A", or "a"
    double math;
    double reading;
    double writing;
    double english;
    double science;
    double maxGPA;
    double overallGPA;
    double multi;

    // produces the first indented line of I/O
    // if user doesn't enter S, s, A or a, display appropriate error message
    // and terminate program execution
    // if user input a valid score type, return that value to calling function
    std::string getTestType();

    int getValidScore(std::string prompt, int minScore, int maxScore);
};