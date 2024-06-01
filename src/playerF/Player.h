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
    int position = 0;
    const Board &board;
    int reward = 3;
    int penalty = 3;
    int playerNumber = 0;
    int original = 0;

public:
    explicit Player(const Board &b1) : board(b1) {};

    Player(int name, const Board &board) : playerNumber(name), board(board) {}

    Player(int name, const Board &board, int reward, int penalty) : playerNumber(name), board(board),
                                                                    reward(reward), penalty(penalty) {}

    int getName() const { return playerNumber; };

    void setName(int n) {playerNumber = n;};

    void move(int roll);

    int getPosition() const;

    int getOriginal() const;
};


#endif //POO2024_PLAYER_H
