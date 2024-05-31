//
// Created by 4ndre on 17/05/2024.
//

#ifndef POO2024_MYGAME_H
#define POO2024_MYGAME_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "../../HW1CedAnd/src/boardF/Board.h"
#include "../../HW1CedAnd/src/playerF/Player.h"

using namespace std;

class MyGame {
private:
    Board board;
    vector<Player> players_;
    string output;

public:

    explicit MyGame(string path);

    MyGame(int numPlayers,string path);

    MyGame(int numPlayers, int size, int snakes, int ladders,string path);

    MyGame(int size, int snakes, int ladders,string path); // default 2 players

    void start(const string &option = "A");

};


#endif //POO2024_MYGAME_H
