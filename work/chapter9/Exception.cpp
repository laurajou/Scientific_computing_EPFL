//
// Created by Laura Jou Ferrer on 13.11.17.
//

#include <iostream>
#include "Exception.h"

Exception::Exception(std::string tagString, std::string probString) {

    mTag = tagString;
    mProblem = probString;
}
void Exception::PrintDebug() const {
    std::cerr << "** Error ("<<mTag<<") **\n";
    std::cerr << "Problem: " << mProblem << "\n\n";
}

Exception::Exception() {}


OutOfRangeException::OutOfRangeException(std::string tagString) {
    mTag = tagString;
    mProblem = "The index is out of range";
}

FileNotOpenException::FileNotOpenException(std::string tagString) {
    mTag = tagString;
    mProblem = "The file you are trying to access is not open";
}