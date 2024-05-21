//
// Created by 4ndre on 21/05/2024.
//

#ifndef POO2024_BOARD_H
#define POO2024_BOARD_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Board {
public:
    Board();

    vector<string> getBoard() { return board1; };

    void printBoard() { for (int i = 0; i < 30; i++) { cout << board1.at(i) << " "; }}

private:
    vector<string> board1;
};


#endif //POO2024_BOARD_H
