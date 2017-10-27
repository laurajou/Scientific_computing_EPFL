//
// Created by Laura Jou Ferrer on 27.10.17.
//

#include "Matrix.h"
#include <cmath>
#include <cassert>

//overriden constructor that sets values to zero
Matrix::Matrix() {
    a = 0.0;
    b = 0.0;
    c = 0.0;
    d = 0.0;
}

//overriden copy constructor
Matrix::Matrix(Matrix &A) {
    a = A.a;
    b = A.b;
    c = A.c;
    d = A.d;
}

//constructor that specifies values on four entries
Matrix::Matrix(double a, double b, double c, double d) {
    this -> a = a;
    this -> b = b;
    this -> c = c;
    this -> d = d;
}

//calculate the determinant of the matrix
double Matrix::CalculateDeterminant() {
    return a*d - c*b;
}

//calculate the inverse of the matrix if it exists
Matrix Matrix::CalculateInverse() {
    assert (abs(CalculateDeterminant() - 0) > 0.0001);
    return Matrix(d, -b, -c, a);
}

//overload assignment operator
Matrix& Matrix::operator=(const Matrix &B) {
    a = B.a;
    b = B.b;
    c = B.c;
    d = B.d;
    return *this;
}

//print the matrix
std::ostream& operator<<(std::ostream& output,
                         const Matrix& A)
{
    // Format as a b
    //           c d
    output << "\n";
    output << A.a << " " << A.b << "\n";
    output << A.c << " " << A.c ;
    output << "\n";

    return output;
}

//return first element
double Matrix::GetElementOne() {
    return a;
}

//overload unary operator -
Matrix Matrix::operator-() const {
    Matrix B;
    B.a = -a;
    B.b = -b;
    B.c = -c;
    B.d = -d;

    return B;
}

//overload binary operator -
Matrix Matrix::operator-(const Matrix &B) const {
    Matrix C;
    C.a = a - B.a;
    C.b = b - B.b;
    C.c = c - B.c;
    C.d = d - B.d;

    return C;
}

//overload binary operator +
Matrix Matrix::operator+(const Matrix &B) const {
    Matrix C;
    C.a = a + B.a;
    C.b = b + B.b;
    C.c = c + B.c;
    C.d = d + B.d;

    return C;
}

//multipication by a float

Matrix Matrix::MultiplyByFloat(double x) {

    a = a * x;
    b = b * x;
    c = c * x;
    d = d * x;

    return *this;

}