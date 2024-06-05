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
#include "GameLayout.h"
#include "Features/Ladder.h"
#include "Features/Snake.h"

using namespace std;

//Struct made to organize items in the writing process, better than classes due to the properties of their attributes
//Struct replaces Turns() class
struct Printing {
    int turn;
    int name;
    int initPos;
    int roll;
    string tile;
    int finalPos;

    friend std::ofstream &operator<<(std::ofstream &ofs, const Printing &game) {
        ofs << game.turn << " " << game.name << " " << game.initPos << " " << game.roll
            << " " << game.tile << " " << game.finalPos << endl;
        return ofs;
    }
};

class MyGame : GameLayout {
private:
    Board board;
    vector<Player> players_;
    string output;
    Snake penalty;
    Ladder reward;
    Printing dummyPrint;

public:

    explicit MyGame(string path);

    MyGame(int numPlayers, string path);

    MyGame(int numPlayers, int size, int snakes, int ladders, string path, Snake penalty1, Ladder reward1);

    MyGame(int size, int snakes, int ladders, string path, Snake penalty1, Ladder reward1); // default 2 players

    void start(const string &option = "M", int customTurns = 100); //default 100 turns

    // display method to thank in each specific game
    void logDisplay() override { cout << "This was snakes and ladders !" << endl; };


};


#endif //POO2024_MYGAME_H
