//
// Created by 4ndre on 21/05/2024.
//

#include "Board.h"

Board::Board() {
    board1.resize(size, "N");
    srand(time(0));
    unordered_set<int> usedPositions;
    int placedSnakes = 0;
    int placedLadders = 0;

    while (placedSnakes < 3) {
        int snakePos = rand() % size;
        if (snakePos != 0 && snakePos != size - 1 && usedPositions.find(snakePos) == usedPositions.end()) {
            board1[snakePos] = "S";
            usedPositions.insert(snakePos);
            placedSnakes++;
        }
    }

    while (placedLadders < 3) {
        int ladderPos = rand() % size;
        if (ladderPos != 0 && ladderPos != size - 1 && usedPositions.find(ladderPos) == usedPositions.end()) {
            board1[ladderPos] = "L";
            usedPositions.insert(ladderPos);
            placedLadders++;
        }
    }

}

Board::Board(int size, int snakes, int ladders) : size(size) {
    board1.resize(size, "N");
    if (snakes > size || ladders > size) {
        cout << "Invalid game settings\n";
    } else {
        srand(time(0));
        unordered_set<int> usedPositions;
        int placedSnakes = 0;
        int placedLadders = 0;

        while (placedSnakes < snakes) {
            int snakePos = rand() % size;
            if (snakePos != 0 && snakePos != size - 1 && usedPositions.find(snakePos) == usedPositions.end()) {
                board1[snakePos] = "S";
                usedPositions.insert(snakePos);
                placedSnakes++;
            }
        }

        while (placedLadders < ladders) {
            int ladderPos = rand() % size;
            if (ladderPos != 0 && ladderPos != size - 1 && usedPositions.find(ladderPos) == usedPositions.end()) {
                board1[ladderPos] = "L";
                usedPositions.insert(ladderPos);
                placedLadders++;
            }
        }
    }
}

