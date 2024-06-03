//
// Created by 4ndre on 02/06/2024.
//

#ifndef POO2024_ITEM_H
#define POO2024_ITEM_H


class Item {
protected:
    int value;
public:

    explicit Item(int v) : value(v) {}

    virtual int getValue() = 0;

    virtual void setValue(int v) = 0;
};


#endif //POO2024_ITEM_H
