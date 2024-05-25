//
// Created by karak on 23/05/2024.
//

#include "MyGame.h"

void MyGame::start() {
    srand(time(0));
    int turns = 0;
    bool gameWon = false;
    Player *currentPlayer = &player1;

    std::ifstream archivo(
            R"(C:\Users\4ndre\Downloads\POO2024\HW1CedAnd\src\Input.txt)");//Here goes the route of the inputs

    if (!archivo.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    std::ofstream miarchivo;
    miarchivo.open(R"(C:\Users\4ndre\Downloads\POO2024\HW1CedAnd\src\Output.txt)");//Here goes the route of the outputs

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
                turns += 1;
                int initialposition = currentPlayer->getPosition();
                currentPlayer->move(roll);
                int finalposition = currentPlayer->getPosition();
                miarchivo << turns << " " << currentPlayer->getName() << " " << initialposition << " " << roll << " "
                          << board.getTile(currentPlayer->getOriginal()) << " " << finalposition << endl;
            }

            if (currentPlayer->getPosition() >= 30) {
                if (miarchivo.is_open()) {
                    miarchivo << "Player " << currentPlayer->getName()  << " is the winner!"  << std::endl;
                    miarchivo.close();
                }
                gameWon = true;
            } else {
                // Switch players
                currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
            }
        }

    }
}

