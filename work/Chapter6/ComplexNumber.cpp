#include "ComplexNumber.hpp"
#include <cmath>

// Override default constructor
// Set real and imaginary parts to zero
ComplexNumber::ComplexNumber()
{
   mRealPart = 0.0;
   mImaginaryPart = 0.0;
}

// Constructor that sets complex number z=x+iy
ComplexNumber::ComplexNumber(double x, double y)
{
   mRealPart = x;
   mImaginaryPart = y;
}

// Method for computing the modulus of a
// complex number
double ComplexNumber::CalculateModulus() const
{
   return sqrt(mRealPart*mRealPart+
               mImaginaryPart*mImaginaryPart);
}

// Method for computing the argument of a
// complex number
double ComplexNumber::CalculateArgument() const
{
   return atan2(mImaginaryPart, mRealPart);
}

// Method for raising complex number to the power n
// using De Moivre's theorem - first complex
// number must be converted to polar form
ComplexNumber ComplexNumber::CalculatePower(double n) const
{
   double modulus = CalculateModulus();
   double argument = CalculateArgument();
   double mod_of_result = pow(modulus, n);
   double arg_of_result = argument*n;
   double real_part = mod_of_result*cos(arg_of_result);
   double imag_part = mod_of_result*sin(arg_of_result);
   ComplexNumber z(real_part, imag_part); 
   return z; 
}

// Overloading the = (assignment) operator
ComplexNumber& ComplexNumber::
               operator=(const ComplexNumber& z)
{
   mRealPart = z.mRealPart;
   mImaginaryPart = z.mImaginaryPart;
   return *this;
}

// Overloading the unary - operator
ComplexNumber ComplexNumber::operator-() const
{
   ComplexNumber w;
   w.mRealPart = -mRealPart;
   w.mImaginaryPart = -mImaginaryPart;
   return w;
}

// Overloading the binary + operator
ComplexNumber ComplexNumber::
              operator+(const ComplexNumber& z) const
{
   ComplexNumber w;
   w.mRealPart = mRealPart + z.mRealPart;
   w.mImaginaryPart = mImaginaryPart + z.mImaginaryPart;
   return w;
}

// Overloading the binary - operator
ComplexNumber ComplexNumber::
              operator-(const ComplexNumber& z) const
{
   ComplexNumber w;
   w.mRealPart = mRealPart - z.mRealPart;
   w.mImaginaryPart = mImaginaryPart - z.mImaginaryPart;
   return w;
}

// Overloading the insertion << operator
std::ostream& operator<<(std::ostream& output, 
                         const ComplexNumber& z)
{
   // Format as "(a + bi)" or as "(a - bi)"
   output << "(" << z.mRealPart << " ";
   if (z.mImaginaryPart >= 0.0)
   {
      output << "+ " << z.mImaginaryPart << "i)";
   }
   else
   {
      // z.mImaginaryPart < 0.0
      // Replace + with minus sign 
      output << "- " << -z.mImaginaryPart << "i)";
   }
   return output;
}
//Code from Chapter06.tex line 779 save as ComplexNumber.cpp

ComplexNumber ComplexNumber::
operator*(const ComplexNumber& z) const
{
   ComplexNumber w;
   w.mRealPart = mRealPart * z.mRealPart - mImaginaryPart * z.mImaginaryPart;
   w.mImaginaryPart = 2 * mImaginaryPart * z.mImaginaryPart;
   return w;
}

ComplexNumber ComplexNumber::
operator/(const int& x) const
{
   ComplexNumber w;
   w.mRealPart = mRealPart/x;
   w.mImaginaryPart = mImaginaryPart/x;
   return w;
}

double ComplexNumber::GetRealPart() const
{
   return mRealPart;
}

double ComplexNumber::GetImaginaryPart() const {
   return mImaginaryPart;
}

double RealPart(ComplexNumber & number)
{
   return number.mRealPart;
}

double ImaginaryPart(ComplexNumber & number)
{
   return number.mImaginaryPart;
}

ComplexNumber::ComplexNumber(const ComplexNumber &number)
{
   mRealPart = number.GetRealPart();
   mImaginaryPart = number.GetImaginaryPart();
}

ComplexNumber::ComplexNumber(double num)
{
   mRealPart = num;
   mImaginaryPart = 0.0;
}

ComplexNumber ComplexNumber::CalculateConjugate() const
{
   return ComplexNumber(mRealPart, -mImaginaryPart);
}

void ComplexNumber::SetConjugate()
{
   mImaginaryPart = -mImaginaryPart;
}

ComplexNumber** ComplexNumber::CreateMatrix(ComplexNumber array[9])
{
   ComplexNumber *p_a = new ComplexNumber[3 * 3];

   ComplexNumber **A  = new ComplexNumber*[3];
   for (int i = 0; i<3; ++i) {
      A[i] = &p_a[i * 3];
   }

   for (int i=0; i<3; ++i) {
      for(int j=0; j<3; ++j) {
         A[i][j] = array[i*3 + j];
      }
   }
   return A;

}

ComplexNumber** ComplexNumber::CopyMatrix(ComplexNumber **A)
{
   ComplexNumber *p_a = new ComplexNumber[3 * 3];

   ComplexNumber **copy_A  = new ComplexNumber*[3];
   for (int i = 0; i<3; ++i) {
      copy_A[i] = &p_a[i * 3];
   }

   for (int i=0; i<3; ++i) {
      for(int j=0; j<3; ++j) {
         copy_A[i][j] = A[i][j];
      }
   }
   return copy_A;
}

ComplexNumber** ComplexNumber::CreateZeroMatrix()
{
   ComplexNumber *p_a = new ComplexNumber[3 * 3];

   ComplexNumber **A  = new ComplexNumber*[3];
   for (int i = 0; i<3; ++i) {
      A[i] = &p_a[i * 3];
   }

   for (int i=0; i<3; ++i) {
      for(int j=0; j<3; ++j) {
         A[i][j] = ComplexNumber(0.0, 0.0);
      }
   }
   return A;
}

ComplexNumber** ComplexNumber::CalculateExponential(ComplexNumber** A, int max_iter)
{
   ComplexNumber **sum = CreateZeroMatrix();
   for (int n=0; n<max_iter; ++n) {

      // create new copies of A
      ComplexNumber **const copy_A = CopyMatrix(A);
      ComplexNumber **B = CopyMatrix(A);

      //multiply as many timed as required (n)
      for (int multiplications = 0; multiplications < n; ++multiplications) {
         for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
               for (int k = 0; k < 3; ++k) {
                  B[i][j] = B[i][k] * copy_A[k][j];
               }
            }
         }
         //divide all members of matrix by n
         for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
               B[i][j] = B[i][j] / n;
            }
         }
      }
      //update total sum
      for (int i = 0; i < 3; ++i) {
         for (int j = 0; j < 3; ++j) {
            sum[i][j] = sum[i][j] + B[i][j];
         }
      }
   }
   return sum;
}