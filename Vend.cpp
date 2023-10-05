//
// Created by scarl on 10/2/2023.
//

#include "Vend.h"
#include <iostream>

Vend::Vend() {
    s = new State();
    turnCounts = new int[5];
    std::fill(turnCounts,turnCounts+5,0);
    outCounts = new int[3];
    std::fill(outCounts,outCounts+3,0);
}

void Vend::vend() {
    while (true) {
        std::cout << "Input: " << std::endl;
        std::string text;
        std::cin >> text;

        if (text == "exit"){
            std::cout << "Exiting vending machine" << std::endl;
            break;
        }

        this->processInputs(text);
        this->lambda();
        this->delta();
    }
}

void Vend::processInputs(std::string text) {
    for (int i = 0; i < text.length(); i++) {
        for (int j = 0; j < 5; j++) {
            if (text[i] == chars[j]) {
                turnCounts[j]++;
            }
        }
    }

}

void Vend::lambda() {
    std::cout << "Value at beginning of lambda is: " << s->getValue() << std::endl;
    if (s->getValue() >= 100) {
        dispenseCoffee();
    } else {
        if (s->getChange()){
            change();
        } else {
            std::cout << "Output:  Nothing" << std::endl;
        }
    }
}

void Vend::dispenseCoffee() {
    int numCoff = (int)(s->getValue()/100);
    std::cout << "Number of coffees to dispense is " << numCoff << std::endl;
    if (numCoff > 0) {
        std::cout << "Output: Coffee * " << numCoff << std::endl;
        s->setValue(s->getValue()-(numCoff*100));
    }
}

void Vend::change() {
    while (s->getValue()>0) {
        if (s->value >= 25 && s->quarter !=0) {
            s->value -= 25;
            s->quarter -= 1;
            outCounts[2] ++;
        } else if (s->value >= 10 && s->dime != 0) {
            s->value -= 10;
            s->dime -= 1;
            outCounts[1] ++;
        } else if (s->value >= 5 && s->nickel != 0) {
            s->value -= 5;
            s->nickel -= 1;
            outCounts[0] ++;
        } else {
            std::cout << "We don't have the right change, sorry" << std::endl;
            break;
        }
    }
    std::cout << "Change is: " << std::endl;
    std::cout << "Quarters: " <<  outCounts[2] << std::endl;
    std::cout << "Dimes: " << outCounts[1] << std::endl;
    std::cout << "Nickels: " << outCounts[0] << std::endl;

    s->setChange(false);
    s->setValue(0);
    std::fill(turnCounts,turnCounts+5,0);
    std::fill(outCounts,outCounts+3,0);
}

void Vend::delta() {
    int newValue = s->getValue();
    if (turnCounts[0] != 0){
        int tempNick = turnCounts[0];
        int temp = s->getNickel()+tempNick;
        s->setNickel(temp);
        newValue += (tempNick*5);
    }
    if (turnCounts[1] != 0){
        int tempDime = turnCounts[1];
        int temp = s->getDime()+tempDime;
        s->setDime(temp);
        newValue += (tempDime*10);
    }
    if (turnCounts[2] != 0){
        int tempQuarter = turnCounts[2];
        int temp = s->getQuarter() + tempQuarter;
        s->setQuarter(temp);
        newValue += (tempQuarter*25);
    }
    if (turnCounts[3] != 0){
        s->setChange(true);
        turnCounts[3] = 0;
    }

    s->setValue(newValue);
    std::cout << "Value after delta is: " << s->getValue() << std::endl;
    std::fill(turnCounts,turnCounts+5,0);
}