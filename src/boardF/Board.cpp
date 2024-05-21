//
// Created by 4ndre on 21/05/2024.
//

#include "Board.h"

Board::Board() {
    for (int i = 0; i < 30; i++) {
        board1.emplace_back("N");
    }
    for (int i = 0; i <= 6; i++) {
        if (i % 3 == 0) { board1.at(i) = "S"; }
    }

    for (int i = 14; i < 20; i++) {
        if (i % 2 == 0) { board1.at(i) = "L"; }
    }
}
