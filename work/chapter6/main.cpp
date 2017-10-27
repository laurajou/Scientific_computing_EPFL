#include <iostream>
#include "ComplexNumber.hpp"

int main() {
    ComplexNumber a(3.4, 0.0);
    ComplexNumber b(a);
    ComplexNumber c(6.7);
    ComplexNumber d = a.CalculateConjugate();
    ComplexNumber e(6.8, 0.0);
    ComplexNumber f(5,3);
    ComplexNumber g(3.2, 0.0);
    ComplexNumber h(g.CalculateConjugate());
    ComplexNumber i(e.CalculateConjugate());
    ComplexNumber array[9] = {a, b, c, d, e, f, g, h, i};
    ComplexNumber** matrix = a.CreateMatrix(array);

    for (int k = 0; k < 3; ++k) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matrix[k][j] << " ";
        }
        std::cout << "\n";
    }


    ComplexNumber** exponential = a.CalculateExponential(matrix, 2);

    for (int k = 0; k < 3; ++k) {
        for (int j = 0; j < 3; ++j) {
            std::cout << exponential[k][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}