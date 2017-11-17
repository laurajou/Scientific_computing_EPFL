//
// Created by Laura Jou Ferrer on 13.11.17.
//


#ifndef EXCEPTIONDEF
#define EXCEPTIONDEF
#include <string>
class Exception {
protected:
    std::string mTag, mProblem;
public:
    Exception(std::string tagString, std::string probString);
    Exception();
    void PrintDebug() const;
};

class OutOfRangeException: public Exception {
public:
    OutOfRangeException(std::string probString);
};

class FileNotOpenException: public Exception {
public:
    FileNotOpenException(std::string probString);
};


#endif //EXCEPTIONDEF