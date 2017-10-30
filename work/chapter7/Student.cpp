//
// Created by Laura Jou Ferrer on 30.10.17.
//

#include "Student.h"

// calculate total money owed by student
double Student::TotalMoneyOwed() {
    return library_fines + tuition_fees;
}

// constructor with all parameters specified
Student::Student(std::string name, double library_fines, double tuition_fees) {
    this->name = name;
    this->tuition_fees = tuition_fees;
    this->library_fines = library_fines;
}

// constructor that sets library and tuition debt to 0.0 by default
Student::Student(std::string name) {
    this->name = name;
    tuition_fees = 0.0;
    library_fines = 0.0;
}

// copy constructor
Student::Student(Student &someone) {
    name = someone.name;
    library_fines = someone.library_fines;
    tuition_fees = someone.tuition_fees;

}

// set library fines to non negative amount
void Student::SetLibraryFines(double amount) {
    if (amount >= 0.0) {
        library_fines = amount;
    }
    else {std::cout << "impossible amount for a library fine";}
}

// get library fines
double Student::GetLibraryFines() {
    return library_fines;
}


// constructor for child GradutateStudent
GraduateStudent::GraduateStudent(std::string name, double library_fines, double tuition_fees, bool full_time)
    :Student(name, 0.0, tuition_fees),
             FullTime(full_time) {
}

double GraduateStudent::TotalMoneyOwed() {
    return library_fines;
}

// constructor for PhDStudent
PhdStudent::PhdStudent(std::string name, double library_fines, double tuition_fees, bool full_time)
    :GraduateStudent(name, 0.0, 0.0, full_time) {
}

// get total debt for phd
double PhdStudent::TotalMoneyOwed() {
    return library_fines + tuition_fees;
}