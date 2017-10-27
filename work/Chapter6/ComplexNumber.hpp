#ifndef COMPLEXNUMBERHEADERDEF
#define COMPLEXNUMBERHEADERDEF

#include <iostream>

class ComplexNumber
{
private:
    friend double RealPart(ComplexNumber &);
    friend double ImaginaryPart(ComplexNumber &);
    double mRealPart;
    double mImaginaryPart;

public:
    ComplexNumber();
    ComplexNumber(double x, double y);
    ComplexNumber(const ComplexNumber&);
    ComplexNumber(double num);
    double CalculateModulus() const;
    double CalculateArgument() const;
    double GetRealPart() const;
    double GetImaginaryPart() const;
    ComplexNumber CalculateConjugate() const;
    void SetConjugate();
    ComplexNumber** CreateMatrix(ComplexNumber array[9]);
    ComplexNumber** CalculateExponential(ComplexNumber** matrix, int max_iter);
    ComplexNumber** CopyMatrix(ComplexNumber** A);
    ComplexNumber** CreateZeroMatrix();
    ComplexNumber CalculatePower(double n) const;
    ComplexNumber& operator=(const ComplexNumber& z);
    ComplexNumber operator-() const;
    ComplexNumber operator* (const ComplexNumber& z) const;
    ComplexNumber operator/(const int& x) const;
    ComplexNumber operator+(const ComplexNumber& z) const;
    ComplexNumber operator-(const ComplexNumber& z) const;
    friend std::ostream& operator<<(std::ostream& output,
                                   const ComplexNumber& z);
};

#endif
//Code from Chapter06.tex line 746 save as ComplexNumber.hpp
