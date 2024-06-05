//
// Created by 4ndre on 17/05/2024.
//

#include "../HW1CedAnd/src/MyGame.h"

using namespace std;

int main() {
    // Turns class was simplified into a struct that overloads the corresponding operator

    //Polymorphism and operator overloading examples
    Snake snake(3);
    Ladder ladder(2);

    cout << snake.getValue() << endl;
    cout << ladder.getValue() << endl;

    Square square(5);

    square = square + ladder;
    cout << square.getValue() << endl;


    square = square + snake;
    cout << square.getValue() << endl;

    ladder = ladder + ladder;
    cout << ladder.getValue() << endl;

    snake = snake + snake;
    cout << snake.getValue() << endl;

    square = square + snake;
    cout << square.getValue() << endl;

    /* Games implemented*/

    //turns should be specified in the start method of the game

    //manual example, input .txt file required and hardcoded due to HW specifications
    string out = R"(C:\Users\4ndre\Downloads\POO2024\HW1CedAnd\src\Output.txt)";
    MyGame g(out);
    g.start();

    //Default automatic game with two players, default board
    string out2 = R"(C:\Users\4ndre\Downloads\POO2024\HW1CedAnd\src\Output2.txt)";
    MyGame g2(out2);
    g2.start("A");

    //Default automatic game with customized board
    string out3 = R"(C:\Users\4ndre\Downloads\POO2024\HW1CedAnd\src\Output3.txt)";
    MyGame g3(20,2,3,out3,snake, ladder);
    g3.start("A");

    //Multiplayer automatic game with default board
    string out4 = R"(C:\Users\4ndre\Downloads\POO2024\HW1CedAnd\src\Output4.txt)";
    MyGame g4(3, out4);
    g4.start("A");

    //Multiplayer automatic with customized board
    string out5 = R"(C:\Users\4ndre\Downloads\POO2024\HW1CedAnd\src\Output5.txt)";
    MyGame g5(4, 40,8,10,out5, snake , ladder);
    g5.start("A");

    return 0;
}