//
// Created by 4ndre on 02/06/2024.
//

#ifndef POO2024_LADDER_H
#define POO2024_LADDER_H

#include "Item.h"

class Ladder : Item {
public:

    Ladder() : Item() {};

    explicit Ladder(int v) : Item(v) {};

    int getValue() override { return value; }

    void setValue(int v) override { value = v; }

    Ladder operator+(Ladder &val) {
        Ladder temp(0);
        temp.setValue(value + val.getValue());
        return temp;
    };
};

#endif //POO2024_LADDER_H
