//
// Created by Laura Jou Ferrer on 13.11.17.
//

#include <iostream>
#include "Exception.h"
//Constructor Exception::Exception(std::string tagString,

Exception::Exception(std::string tagString, std::string probString) {

    mTag = tagString;
    mProblem = probString;
}
void Exception::PrintDebug() const {
    std::cerr << "** Error ("<<mTag<<") **\n";
    std::cerr << "Problem: " << mProblem << "\n\n";
}

Exception::Exception() {}


OutOfRangeException::OutOfRangeException(std::string probString) {
    mTag = "The index is out of range";
    mProblem = probString;
}

FileNotOpenException::FileNotOpenException(std::string probString) {
    mTag = "The file is not open";
    mProblem = probString;
}