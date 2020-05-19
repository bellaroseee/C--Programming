/**
 * Copyright 2019 Bella Rose
 *
 * Client Porgram for CollegeApplicant class
 */

#include <cstdlib>
#include <iostream>
#include "CollegeApplicant.h"
using namespace std;

int main(int argc, char ** argv) {
    double score_1, score_2;

    cout << "Welcome to Admission Applicant Comparsion System" << endl;
    cout << "Information for applicant #1: " << endl;
    CollegeApplicant applicant_1;
    printf("exam score = %.1f\n", applicant_1.normalizedExamScore());
    printf("GPA score = %.1f\n", applicant_1.normalizedGPA());

    cout << "\nInformation for applicant #2: " << endl;
    CollegeApplicant applicant_2;
    printf("exam score = %.1f\n", applicant_2.normalizedExamScore());
    printf("GPA score = %.1f\n", applicant_2.normalizedGPA());

    score_1 = applicant_1.overallScore();
    score_2 = applicant_2.overallScore();
    printf("\nFirst applicant overall score = %.1f\n", score_1);
    printf("Second applicant overall score = %.1f\n", score_2);
    if (score_1 > score_2) {
        cout << "The first applicant seems to be better" << endl;
    } else if (score_2 > score_1) {
        cout << "The second applicant seems to be better" << endl;
    } else {
        cout << "The two applicants seem to be equal" << endl;
    }

    return EXIT_SUCCESS;
}
