//
// Created by Laura Jou Ferrer on 27.10.17.
//

#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF

#include <iostream>

class Matrix
{
private:
    double a;
    double b;
    double c;
    double d;
public:
    Matrix();
    Matrix(Matrix &A);
    Matrix(double a, double b, double c, double d);
    double CalculateDeterminant();
    double GetElementOne();
    Matrix CalculateInverse();
    Matrix& operator=(const Matrix& B);
    Matrix operator-() const;
    Matrix operator-(const Matrix&B) const;
    Matrix operator+(const Matrix&B) const;
    Matrix MultiplyByFloat(double x);
    friend std::ostream& operator<<(std::ostream& output,
                                    const Matrix& A);

};

#endif //MATRIXHEADERDEF
