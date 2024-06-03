//
// Created by 4ndre on 02/06/2024.
//

#ifndef POO2024_SNAKE_H
#define POO2024_SNAKE_H

#include "Item.h"

class Snake : Item {
public:

    explicit Snake(int v) : Item(v) {};

    int getValue() override { return value; }

    void setValue(int v) override { value; }
};


#endif //POO2024_SNAKE_H
