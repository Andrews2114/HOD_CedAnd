//
// Created by karak on 23/05/2024.
//

#include "MyGame.h"

MyGame::MyGame(int numPlayers, string path) : output(path) {
    Player tempP(board);
    for (int i = 1; i <= numPlayers; ++i) {
        tempP.setName(i);
        players_.emplace_back(tempP);
    }
}

MyGame::MyGame(const string path) : output(path) {
    Player tempP(board);
    for (int i = 1; i <= 2; ++i) {
        tempP.setName(i);
        players_.emplace_back(tempP);
    }
}

MyGame::MyGame(int
               numPlayers,
               int size,
               int snakes,
               int ladders,
               string path, Snake penalty1, Ladder reward1) : board(size, snakes, ladders), output(path),
                                                              penalty(penalty1),
                                                              reward(reward1) {
    Player tempP(0, board, reward, penalty);
    for (int i = 1; i <= numPlayers; ++i) {
        tempP.setName(i);
        players_.emplace_back(tempP);
    }
}

MyGame::MyGame(int size,
               int snakes,
               int ladders,
               string path, Snake penalty1, Ladder reward1) : board(size, snakes, ladders), output(path),
                                                              penalty(penalty1),
                                                              reward(reward1) {
    Player tempP(0, board, reward, penalty);
    for (int i = 1; i <= 2; ++i) {
        tempP.setName(i);
        players_.emplace_back(tempP);
    }
}

void MyGame::start(const string &option, int customTurns) {
    //if Manual is not specified, automatic is default, until someone wins or 100 turns is achieved
    if (option == "M") {
        srand(time(0));
        int turn = 0;
        bool gameWon = false;
        int currentPlayerIndex = 0;
        Player *currentPlayer = &players_[currentPlayerIndex];

        std::ifstream archivo(
                R"(C:\Users\4ndre\Downloads\POO2024\HW1CedAnd\src\Input.txt)");//Here goes the route of the input
        //Input file is harcoded due to specifications of the HW, need to be changed for manual usage

        if (!archivo.is_open()) {
            std::cerr << "Error opening file." << std::endl;
            return;
        }
        std::ofstream miarchivo;
        miarchivo.open(output);//Here goes the route of the outputs

        if (miarchivo.is_open()) {
            miarchivo << "Enter 'C' to continue or 'E' to end the game " << endl;
        }

        while (!gameWon) {
            char input;
            while (true) {
                if (!(archivo >> input)) {
                    archivo.close();
                    return;
                }
                if (input != 'C' && input != 'E' && input != 'c' && input != 'e') {
                    cout << "Invalid option, please press C to continue next turn or E to end the game" << endl;
                } else {
                    break;
                }
            }

            if (input == 'E' || input == 'e') {
                if (miarchivo.is_open()) {
                    miarchivo << "Thanks for playing." << std::endl;
                    miarchivo.close();
                }
                break;

            } else if (input == 'C' || input == 'c') {
                int roll = rand() % 6 + 1;
                if (miarchivo.is_open()) {
                    turn += 1;
                    int initialposition = currentPlayer->getPosition();
                    currentPlayer->move(roll);
                    int finalposition = currentPlayer->getPosition();
                    //Edit struct to use the operator overloading of << in the ofstream library
                    dummyPrint.turn = turn;
                    dummyPrint.name = currentPlayer->getName();
                    dummyPrint.initPos = initialposition;
                    dummyPrint.roll = roll;
                    dummyPrint.tile = board.getTile(currentPlayer->getOriginal());
                    dummyPrint.finalPos = finalposition;
                    miarchivo << dummyPrint;
                }

                if (currentPlayer->getPosition() >= static_cast<int>(board.getSize())) {
                    if (miarchivo.is_open()) {
                        miarchivo << "Player " << currentPlayer->getName() << " is the winner!" << std::endl;
                        miarchivo.close();
                    }
                    gameWon = true;
                } else {
                    // Switch players
                    currentPlayerIndex = (currentPlayerIndex + 1) % static_cast<int>(players_.size());
                    currentPlayer = &players_[currentPlayerIndex];
                }
            }
            if (turn >= customTurns) { break; }
        }
        if (turn == 100 || turn >= customTurns) {
            if (!gameWon) { miarchivo << endl << "Maximum turn limit exceeded" << endl; };
            miarchivo.close();
        }

    } else if (option == "A") {
        srand(time(0));
        int turn = 0;
        bool gameWon = false;
        int currentPlayerIndex = 0;
        Player *currentPlayer = &players_[currentPlayerIndex];

        std::ofstream miarchivo;
        miarchivo.open(output);//Here goes the route of the outputs

        while (!gameWon && turn < 100) {
            // sanity check of turn, past 100 turn, 50 each, the game ends with no winner, could be depricated
            int roll = rand() % 6 + 1;
            if (miarchivo.is_open()) {
                turn += 1;
                int initialposition = currentPlayer->getPosition();
                currentPlayer->move(roll);
                int finalposition = currentPlayer->getPosition();
                dummyPrint.turn = turn;
                dummyPrint.name = currentPlayer->getName();
                dummyPrint.initPos = initialposition;
                dummyPrint.roll = roll;
                dummyPrint.tile = board.getTile(currentPlayer->getOriginal());
                dummyPrint.finalPos = finalposition;
                miarchivo << dummyPrint;

                if (currentPlayer->getPosition() >= static_cast<int>(board.getSize())) {
                    if (miarchivo.is_open()) {
                        miarchivo << "Player " << currentPlayer->getName() << " is the winner!" << std::endl;
                        miarchivo.close();
                    }
                    gameWon = true;
                } else {
                    // Switch players
                    currentPlayerIndex = (currentPlayerIndex + 1) % static_cast<int>(players_.size());
                    currentPlayer = &players_[currentPlayerIndex];
                }
            }
            if (turn >= customTurns) { break; }
        }
        if (turn == 100 || turn >= customTurns) {
            if (!gameWon) { miarchivo << endl << "Maximum turn limit exceeded" << endl; };
            miarchivo.close();
        }
    } else { cout << "Error in game mode" << endl; }
    logDisplay();
}
