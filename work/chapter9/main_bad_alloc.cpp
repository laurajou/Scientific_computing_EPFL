//
// Created by Laura Jou Ferrer on 17.11.17.
//

#include <iostream>

int main (){
    double* p_x;
    try {

        int len = 1000000000000000;
        p_x = new double[len];
    } catch (std::bad_alloc &ba) {
            std::cerr << "Error: bad memory allocation caught " << '\n';
        }


    delete p_x;
    return 0;
}