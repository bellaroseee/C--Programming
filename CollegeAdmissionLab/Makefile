# Copyright 2020 Bella Rose

CollegeAdmission: CollegeAdmissions.o CollegeApplicant.o
	g++ -Wall -g -std=c++11 -o CollegeAdmissions CollegeAdmissions.o CollegeApplicant.o

CollegeAdmissions.o: CollegeApplicant.h CollegeAdmissions.cc
	g++ -Wall -g -std=c++11 -c CollegeAdmissions.cc

CollegeApplicant.o: CollegeApplicant.h CollegeApplicant.cc
	g++ -Wall -g -std=c++11 -c CollegeApplicant.cc

clean:
	rm -rf CollegeApplicant *.o *~
	rm -rf CollegeAdmissions *.o *~