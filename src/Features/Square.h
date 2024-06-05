//
// Created by 4ndre on 02/06/2024.
//

#ifndef POO2024_SQUARE_H
#define POO2024_SQUARE_H

#include "Item.h"

class Square : Item {
public:

    Square() : Item() {};

    explicit Square(int v) : Item(v) {};

    Square operator+(Square &val) {
        Square temp(0);
        temp.setValue(value + val.getValue());
        return temp;
    };

    Square operator+(Snake &val) {
        Square temp(0);
        int disc = value - val.getValue();
        if (disc < 0) { disc = 0; }
        temp.setValue(disc);
        return temp;
    };

    Square operator+(Ladder &val) {
        Square temp(0);
        temp.setValue(value + val.getValue());
        return temp;
    };

    int getValue() override { return value; }

    void setValue(int v) override { value = v; }
};


#endif //POO2024_SQUARE_H
