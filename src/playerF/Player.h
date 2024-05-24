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
    int reward = 3;
    int penalty = 3;
    int playerNumber;
    int original = 0;

public:
    Player(int name, const Board &board) : playerNumber(name), position(0), board(board) {}

    Player(int name, const Board &board, int reward, int penalty) : playerNumber(name), position(0), board(board),
                                                                    reward(reward), penalty(penalty) {}

    int getName() const { return playerNumber; };

    void move(int roll);

    int getPosition() const;

    int getOriginal() const;
};


#endif //POO2024_PLAYER_H
