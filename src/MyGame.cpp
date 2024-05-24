//
// Created by 4ndre on 17/05/2024.
//

#include "MyGame.h"

void MyGame::start() {
    srand(time(0));
    bool gameWon = false;
    Player *currentPlayer = &player1; // Esta implementacion la vas a cambiar, pero
    // quedate con lo de los pointers de player que esta útil

    std::ifstream archivo("C:\\Users\\karak\\OneDrive\\Escritorio\\Proyectos Clion\\SerpientesyEscaleras\\Input.txt");//Here goes the route of the inputs

    if (!archivo.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    std::ofstream miarchivo;
    miarchivo.open("C:\\Users\\karak\\OneDrive\\Escritorio\\Proyectos Clion\\SerpientesyEscaleras\\Output.txt");//Here goes the route of the outputs

    if(miarchivo.is_open()) {
        miarchivo << "Enter 'C' to continue or 'E' to end the game " << endl;
            //std::cout << "Enter 'C' to continue or 'E' to end the game " << endl;
    }

    while (!gameWon) {
        char input;

        while(true) {
            if (!(archivo >> input)) {
                archivo.close();
                return;
            }

            if(input != 'C' && input != 'E' && input != 'c' && input != 'e') {
                cout << "Invalid option, please press C to continue next turn or E to end the game" << endl;
            }else {
                break;
            }
        }

        if (input == 'E' || input == 'e') {
            if(miarchivo.is_open()) {
                miarchivo << "Game ended by user." << std::endl;
                miarchivo.close();
                //std::cout << "Game ended by user." << std::endl;
            }

            break;
        } else if (input == 'C' || input == 'c') {
            int roll = rand() % 6 + 1;
            if (miarchivo.is_open()) {
                miarchivo << currentPlayer->getName() << " rolls a " << roll << std::endl; // Escribir en el archivo
                //std::cout << currentPlayer->getName() << " rolls a " << roll << std::endl;
                currentPlayer->move(roll);
                miarchivo << currentPlayer->getName() << " is now on tile " << currentPlayer->getPosition() << std::endl;
                //std::cout << currentPlayer->getName() << " is now on tile " << currentPlayer->getPosition()
                //<< std::endl;
            }

            if (currentPlayer->getPosition() == 29) {
                if (miarchivo.is_open()) {
                    miarchivo << currentPlayer->getName() << " wins!" << std::endl;
                    miarchivo.close();
                    //std::cout << currentPlayer->getName() << " wins!" << std::endl;
                }
                gameWon = true;
            } else {
                // Switch players
                currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
            }
        } /*else {
            if(miarchivo.is_open()) {
                miarchivo << "Invalid input. Please enter 'C' to continue or 'E' to end the game." << std::endl;
                //std::cout << "Invalid input. Please enter 'C' to continue or 'E' to end the game." << std::endl;
            }*/

        }
    }