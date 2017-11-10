//
// Created by Laura Jou Ferrer on 10.11.17.
//

#include <cassert>
#include <cmath>
#include <iostream>
#include "RainVector.h"
#include "AbsoluteValue.h"


int main() {

    // for Rain Vector exercise (8.1)
    RainVector<2> v1;
    v1[0] = 0.9;
    v1[1] = 0.78;
    v1.checkAndChangeValues(v1);
    std::cout << v1[0] << " " << v1[1] << "\n";

    //for Absolute Value exercise (8.2)
    int a = 5;
    int abs_a = getAbsoluteValue(a);
    std::cout << abs_a ;

    return 0;
}


