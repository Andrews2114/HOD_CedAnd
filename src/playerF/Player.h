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


public:
    Player(int name, const Board &board) : playerNumber(name), position(0), board(board) {}


  	int getName() const{return playerNumber;};

    void move(int roll) {
        position += roll;
        if (position >= 30) {
            position = 29;  // Ensure player does not exceed the board limit
            return;
        }
        string tile = board.getTile(position);
        if (tile == "S") {
            position -= 3;
            if (position < 0) position = 0;
        } else if (tile == "L") {
            position += 3;
            if (position >= 30) position = 29;
        }
    }

    int getPosition() const {
        return position;
    }

};


#endif //POO2024_PLAYER_H
