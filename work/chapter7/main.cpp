//
// Created by Laura Jou Ferrer on 30.10.17.
//

#include <iostream>
#include "Student.h"

int main() {
        auto Laura = PhdStudent("Laura", 10.0, 500.0, true);
        std::cout<< Laura.name << " " << Laura.TotalMoneyOwed() << " " << Laura.tuition_fees;
        return 0;
}
