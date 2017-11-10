//
// Created by Laura Jou Ferrer on 10.11.17.
//

#ifndef PCSC_EXERCISES_ABSOLUTEVALUE_H
#define PCSC_EXERCISES_ABSOLUTEVALUE_H

template<typename T>
T getAbsoluteValue(const T&a) {
    if (a < 0.0) {
        return - a;
    }
    return a;
}
#endif //PCSC_EXERCISES_ABSOLUTEVALUE_H
