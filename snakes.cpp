//
// Created by 4ndre on 17/05/2024.
//

#include <iostream>
#include "../HW1CedAnd/src/MyGame.h"
#include "../HW1CedAnd/src/Dice.h"

using namespace std;

int main() {

    MyGame g;
    g.start();
    double a;
    for (int i = 5; i > 0; i--) {
        cout << endl << "Dice: " << Dice::roll();
    }
    return 0;
}