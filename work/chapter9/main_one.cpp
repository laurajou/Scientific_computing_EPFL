//
// Created by Laura Jou Ferrer on 13.11.17.
//

#include <iostream>
#include "Exception.h"
#include <fstream>



int main() {

    double myvector [3] = {6.7, 2.3, 4.5};
    int index = 9;
    std::string tagString = "An exception has been raised";
    std::string probString = "General problem";


    try {
        if (index > 3) {
            throw OutOfRangeException(tagString);
        }
    } catch (OutOfRangeException &e) {
        e.PrintDebug();
    }


    try {
        std::ifstream read_file("Output.dat");
        if (not read_file.is_open()) {
            throw FileNotOpenException(tagString);
        }
    } catch (FileNotOpenException &e) {
            e.PrintDebug();
        }


    return 0;
}