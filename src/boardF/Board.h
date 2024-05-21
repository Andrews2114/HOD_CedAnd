//
// Created by 4ndre on 21/05/2024.
//

#ifndef POO2024_BOARD_H
#define POO2024_BOARD_H

#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include <bits/stdc++.h>

using namespace std;

class Board {
public:
    Board();

    vector<string> getBoard() { return board1; };

    void printBoard() {for(const auto& board2 : board1) { cout << board2 << " "; } cout << endl;}

private:
    vector<string> board1;
};


#endif //POO2024_BOARD_H
