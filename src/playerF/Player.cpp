//
// Created by 4ndre on 24/05/2024.
//

#include "Player.h"

void Player::move(int roll) {
    position += roll;
    if (position >= board.getSize()) {
        position = 29;  // Ensure player does not exceed the board limit
        return;
    }

    original = position;

    string tile = board.getTile(position);
    if (tile == "S") {
        position -= 3;
        if (position < 0) position = 0;
    } else if (tile == "L") {
        position += 3;
        if (position >= board.getSize()) position = 29;
    }
}

int Player::getPosition() const {
    int pos = position;
    pos += 1;
    return pos;
}

int Player::getOriginal() const {
    int pos = original;
    return pos;
}

