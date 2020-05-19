/**
 * Copyright 2019 Bella Rose
 */

#include <iostream>

#include "Yard.h"
#include "YardDog.h"

using namespace std;

int main() {
	YardDog fido;
	int numHoles = fido.findBone();
	cout << "Bone found after " << numHoles << " holes dug.\n";
	fido.setYard();
	cout << "after fido.setYard:\n";
	cout << fido;

    return EXIT_SUCCESS;
}