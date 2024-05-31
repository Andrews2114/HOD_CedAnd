//
// Created by 4ndre on 17/05/2024.
//

#include "../HW1CedAnd/src/MyGame.h"

using namespace std;

int main() {
    //manual example, input .txt file required and hardcoded due to HW specifications
    string out = R"(C:\Users\4ndre\Downloads\POO2024\HW1CedAnd\src\Output.txt)";
    MyGame g(out);
    g.start("M");

    //Default automatic game with two players, default board
    string out2 = R"(C:\Users\4ndre\Downloads\POO2024\HW1CedAnd\src\Output2.txt)";
    MyGame g2(out2);
    g2.start();

    //Default automatic game with customized board
    string out3 = R"(C:\Users\4ndre\Downloads\POO2024\HW1CedAnd\src\Output3.txt)";
    MyGame g3(20,2,3,out3);
    g3.start();

    //Multiplayer automatic game with default board
    string out4 = R"(C:\Users\4ndre\Downloads\POO2024\HW1CedAnd\src\Output4.txt)";
    MyGame g4(3, out4);
    g4.start();

    //Multiplayer automatic with customized board
    string out5 = R"(C:\Users\4ndre\Downloads\POO2024\HW1CedAnd\src\Output5.txt)";
    MyGame g5(3, 20,2,3,out5);
    g5.start();

//    MyGame g2(15, 2,2);
//    g2.start();

    return 0;
}