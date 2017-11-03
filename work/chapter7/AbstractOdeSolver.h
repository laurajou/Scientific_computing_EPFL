//
// Created by Laura Jou Ferrer on 30.10.17.
//

#ifndef PCSC_EXERCISES_ABSTRACTODESOLVER_H
#define PCSC_EXERCISES_ABSTRACTODESOLVER_H


class AbstractOdeSolver {
protected:
    double stepSize;
    double initialTime;
    double finalTime;
    double initialValue;
public:
    AbstractOdeSolver();
    void SetStepSize(double h);
    void SetTimeInterval(double t0, double t1);
    void SetInitialValue(double y0);
    virtual double RightHandSide(double y, double t) = 0;
    virtual double SolveEquation() = 0;
};

class ForwardEuler: public AbstractOdeSolver {
public:
    ForwardEuler();
    double RightHandSide(double y, double t);
    double SolveEquation();
};

class RungeKutta: public AbstractOdeSolver {
public:
    RungeKutta();
    double RightHandSide(double y, double t);
    double SolveEquation();
};

#endif //PCSC_EXERCISES_ABSTRACTODESOLVER_H
