//
// Created by 4ndre on 31/05/2024.
//

#ifndef POO2024_GAMELAYOUT_H
#define POO2024_GAMELAYOUT_H

#include <iostream>

class GameLayout {

public:
    GameLayout() { std::cout << "Thanks for playing!"  <<std::endl; }

    virtual void logDisplay() = 0;
};


#endif //POO2024_GAMELAYOUT_H
