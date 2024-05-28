//
// Created by 4ndre on 17/05/2024.
//

#ifndef POO2024_MYGAME_H
#define POO2024_MYGAME_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "../../HW1CedAnd/src/boardF/Board.h"
#include "../../HW1CedAnd/src/playerF/Player.h"

using namespace std;

class MyGame {
private:
    Board board;
    Player player1;
    Player player2;

public:
    MyGame() : player1(1, board), player2(2, board) {}


    void start();
};


#endif //POO2024_MYGAME_H
