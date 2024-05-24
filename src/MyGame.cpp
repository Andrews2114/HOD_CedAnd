//
// Created by 4ndre on 17/05/2024.
//

#include "MyGame.h"

void MyGame::start() {
    srand(time(0));
    bool gameWon = false;
    Player *currentPlayer = &player1; // Esta implementacion la vas a cambiar, pero
                                    // quedate con lo de los pointers de player que esta útil

    while (!gameWon) {
"Joly christamas"
        std::cout << "Enter 'C' to continue or 'E' to end the game: ";
        char input;
        std::cin >> input;

        if (input == 'E' || input == 'e') {
            std::cout << "Game ended by user." << std::endl;
            break;
        } else if (input == 'C' || input == 'c') {
            int roll = rand() % 6 + 1;
            std::cout << currentPlayer->getName() << " rolls a " << roll << std::endl;
            currentPlayer->move(roll);
            std::cout << currentPlayer->getName() << " is now on tile " << currentPlayer->getPosition()
                      << std::endl;

            if (currentPlayer->getPosition() == 29) {
                std::cout << currentPlayer->getName() << " wins!" << std::endl;
                gameWon = true;
            } else {
                // Switch players
                currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
            }
        } else {
            std::cout << "Invalid input. Please enter 'C' to continue or 'E' to end the game." << std::endl;
        }
    }
}
