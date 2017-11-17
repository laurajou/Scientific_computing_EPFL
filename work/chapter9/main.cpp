//
// Created by Laura Jou Ferrer on 13.11.17.
//

#include <iostream>
#include "Exception.h"

int main() {

    double vector[3];
    int index;
    std::string tagString = "This is a generic error string";
    std::string probString = "Error: An exception has been raised";


    try {
        double  element = vector[index];
        std::cout << element << std::endl;
    } catch (Exception &e) {
        std::cout << e.what() << std::endl;
    }


    return 0;
}