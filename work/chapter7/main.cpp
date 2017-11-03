//
// Created by Laura Jou Ferrer on 30.10.17.
//

#include <iostream>
#include "Student.h"
#include "AbstractOdeSolver.h"


int main() {

    auto EulerSolver = ForwardEuler();
    auto RungeSolver = RungeKutta();

    RungeSolver.SetInitialValue(2.0);
    RungeSolver.SetTimeInterval(0.0, 3.0);
    RungeSolver.SetStepSize(0.0001);

    EulerSolver.SetInitialValue(2.0);
    EulerSolver.SetTimeInterval(0.0, 3.0);
    EulerSolver.SetStepSize(0.000001);


    double RungeSolution = RungeSolver.SolveEquation();
    std::cout << "The Runge-Kutta solution is: " << RungeSolution << "\n";

    double EulerSolution = EulerSolver.SolveEquation();
    std::cout << "The Euler solution is: " << EulerSolution << "\n";



        return 0;
}


// how do i check that my forward euler is correct?