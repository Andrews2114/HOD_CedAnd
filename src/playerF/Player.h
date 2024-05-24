//
// Created by 4ndre on 21/05/2024.
//

#ifndef POO2024_PLAYER_H
#define POO2024_PLAYER_H

#include <iostream>
#include "../boardF/Board.h"

using namespace std;

class Player {
private:
    int position;
    const Board &board;
    int playerNumber;
    int original = 0;

public:
    Player(int name, const Board &board) : playerNumber(name), position(0), board(board) {}

    int getName() const { return playerNumber; };

    void move(int roll);

    int getPosition() const;

    int getOriginal() const;
};


#endif //POO2024_PLAYER_H
