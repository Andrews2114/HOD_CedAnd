//
// Created by 4ndre on 17/05/2024.
//

#include <iostream>
#include "../HW1CedAnd/src/MyGame.h"
#include "../HW1CedAnd/src/boardF/Board.h"

using namespace std;

int main() {

    Board b{};
    MyGame g;
    g.start();
    cout << 0%3 << endl;
    b.printBoard();
    return 0;
}