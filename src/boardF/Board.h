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

    Board(int size, int snakes, int ladders);


    vector<string> getBoard() { return board1; };

    void printBoard() {
        for (const auto &board2: board1) { cout << board2 << " "; }
        cout << endl;
        for (int i = 0; i < size; i++) {
            cout << i << " ";
        }
        cout << endl;
    }

    string getTile(int position) const {
        if (position < 0 || position >= size) return "I";
        return board1[position];
    }

    int getSize() const { return size; };

private:
    vector<string> board1;
    int size = 30;
};


#endif //POO2024_BOARD_H