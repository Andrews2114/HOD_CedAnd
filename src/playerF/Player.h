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
    string name;
    int reward = 3;
    int penalty = 3;


public:
    Player(const string &name, const Board &board) : name(name), position(0), board(board) {}

    Player(const string &name, const Board &board, int reward, int penalty) : name(name), position(0), board(board),
                                                                              reward(reward), penalty(penalty) {}

    string getName() { return name; };

    void move(int roll) {
        position += roll;
        if (position >= board.getSize()) {
            position = 29;  // Ensure player does not exceed the board limit
            return;
        }
        string tile = board.getTile(position);
        if (tile == "S") {
            position -= penalty;
            if (position < 0) position = 0;
        } else if (tile == "L") {
            position += reward;
            if (position >= board.getSize()) position = 29;
        }
    }

    int getPosition() const {
        return position;
    }

};


#endif //POO2024_PLAYER_H
