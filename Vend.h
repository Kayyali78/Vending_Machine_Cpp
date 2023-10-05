//
// Created by scarl on 10/2/2023.
//

#ifndef VENDING_MACHINE_CPP_VEND_H
#define VENDING_MACHINE_CPP_VEND_H

#include <string>
#include "State.h"

class Vend {
public:
    State* s;
    char chars [5] = {'n','d','q','c','w'};
    int* turnCounts;
    int* outCounts;

    Vend();
    void vend();
    void processInputs(std::string);
    void lambda();
    void dispenseCoffee();
    void change();
    void delta();
};


#endif //VENDING_MACHINE_CPP_VEND_H
