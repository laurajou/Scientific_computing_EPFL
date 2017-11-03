//
// Created by Laura Jou Ferrer on 30.10.17.
//

#include <iostream>
#include "AbstractOdeSolver.h"
#include <cmath>

// useless constructor
AbstractOdeSolver::AbstractOdeSolver() {
}

// set size of step for the solver
void AbstractOdeSolver::SetStepSize(double h) {
    stepSize = h;
}

// set time interval
void AbstractOdeSolver::SetTimeInterval(double t0, double t1) {
    initialTime = t0;
    finalTime = t1;
}

// set initial value for solver
void AbstractOdeSolver::SetInitialValue(double y0) {
    initialValue = y0;
}

// ---FORWARD EULER---

// constructor
ForwardEuler::ForwardEuler() {}

// set function on RHS of equation
double ForwardEuler::RightHandSide(double y, double t) {
    return 1 + t;
}

// apply forward Euler to solve differential equation
double ForwardEuler::SolveEquation() {
    double y = initialValue;
    double t = initialTime;
    while(t <= finalTime) {
        y = y + stepSize * RightHandSide(y, t);
        t = t + stepSize;
    }
    return y;
}

// ---RUNGE KUTTA---

// constuctor
RungeKutta::RungeKutta() {}

// set function on the RHS of Diff Equation
double RungeKutta::RightHandSide(double t, double y) {
    return 1 + t;
}

// solve using the Runge Kutta method
double RungeKutta::SolveEquation() {
    double y = initialValue;
    double t = initialTime;
    double h = stepSize;

    while(t <= finalTime) {
//        std::cout << "time " << t << std::endl;
        double k1 = h * RightHandSide(t, y);
        double k2 = h * RightHandSide(t + 0.5 * h, y + 0.5 * k1);
        double k3 = h * RightHandSide(t + 0.5 * h, y + 0.5 * k2);
        double k4 = h * RightHandSide(t + h, y + k3);
        y = y + (1./6.) * (k1 + 2 * k2 + 2 * k3 + k4);
        t = t + h;
    }

    return y;
}