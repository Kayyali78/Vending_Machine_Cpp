//
// Created by scarl on 10/2/2023.
//

#include "State.h"

State::State() {
    nickel = 10; dime = 10; quarter = 10; value = 0;
    change = false;
}

void State::setNickel(int nick) {this->nickel = nick;}
void State::setDime(int dime) {this->dime = dime;}
void State::setQuarter(int quarter) {this->quarter = quarter;}
void State::setValue(int value) {this->value = value;}
void State::setChange(bool flag){this->change = flag;}
int State::getNickel(){return nickel;}
int State::getDime(){return dime;}
int State::getQuarter(){return quarter;}
int State::getValue(){return value;}
bool State::getChange(){return change;}