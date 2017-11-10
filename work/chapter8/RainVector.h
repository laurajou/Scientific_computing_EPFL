//
// Created by Laura Jou Ferrer on 10.11.17.
//

#ifndef PCSC_EXERCISES_RAINVECTOR_H
#define PCSC_EXERCISES_RAINVECTOR_H

#include <cassert>
#include <cmath>
#include <iostream>

template <unsigned int dim> class RainVector {
public:

    double &operator[](int index) {
        assert(index < dim);
        assert(index > -1);
        return(value[index]); }

    void checkAndChangeValues(RainVector v1) {
        for (int i = 0; i < dim; ++i) {
            assert((v1[i] > pow(-10.0, -6.0) and v1[i] < 0.0) or (v1[i] < 1 + pow(10.0, -6.0) and v1[i] > 1) or
                           (v1[i] < 1.0 and v1[i] > 0.0));
            if (v1[i] > pow(-10.0, -6.0) and v1[i] < 0.0) {
                v1[i] = 0.0;
            } else if (v1[i] < 1 + pow(10.0, -6.0) and v1[i] > 1) {
                v1[i] = 1.0 ;
            }
        }
    }
    friend std::ostream& operator<<(std::ostream &stream, const RainVector<dim>& v1);

private:
    double value[dim];
};

template <unsigned int dim>
std::ostream &operator<<(std::ostream &stream, const RainVector<dim>& v1) {

    stream << "[";
    for (int d = 0; d < dim; ++d) {
        if (d != 0) {
            stream << ", ";
            stream << v1[d];
        }
    }
    stream << "]";
    return stream; }


#endif //PCSC_EXERCISES_RAINVECTOR_H
