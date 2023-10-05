//
// Created by scarl on 10/2/2023.
//

#ifndef VENDING_MACHINE_CPP_STATE_H
#define VENDING_MACHINE_CPP_STATE_H


class State {
public:
    State();
    int nickel,dime,quarter,value;
    bool change;
    void setNickel(int);
    void setDime(int);
    void setQuarter(int);
    void setValue(int);
    void setChange(bool);
    int getNickel();
    int getDime();
    int getQuarter();
    int getValue();
    bool getChange();
};


#endif //VENDING_MACHINE_CPP_STATE_H
