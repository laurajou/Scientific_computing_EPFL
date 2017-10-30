//
// Created by Laura Jou Ferrer on 30.10.17.
//

#ifndef PCSC_EXERCISES_STUDENT_H
#define PCSC_EXERCISES_STUDENT_H

#include <iostream>


class Student {
protected:
    double library_fines;
public:
    Student(std::string name, double library_fines, double tuition_fees);
    Student(std::string name);
    Student(Student&);
    std::string name;
    double tuition_fees;
    virtual double TotalMoneyOwed();
    void SetLibraryFines(double amount);
    double GetLibraryFines();
};


class GraduateStudent: public Student {
private:
    bool FullTime;
public:
    GraduateStudent(std::string name, double library_fines, double tuition_fees, bool full_time);
    virtual double TotalMoneyOwed();

};

class PhdStudent: public GraduateStudent {
public:
    PhdStudent(std::string name, double library_fines, double tuition_fees, bool full_time);
    double TotalMoneyOwed();
};
#endif //PCSC_EXERCISES_STUDENT_H
