//
// Created by 4ndre on 02/06/2024.
//

#ifndef POO2024_TURNS_H
#define POO2024_TURNS_H


class Turns {
private:
    int turnNumber;
    std::string playerName;
    int diceRoll;
    int startSquare;
    int endSquare;
public:
    Turn(int tn, std::string pn, int dr, int ss, int es) : turnNumber(tn), playerName(pn), diceRoll(dr),
                                                           startSquare(ss), endSquare(es) {}

    friend std::ostream &operator<<(std::ostream &os, const Turn &t);
};

std::ostream &operator<<(std::ostream &os, const Turn &t) {
    os << "Turn " << t.turnNumber << ": " << t.playerName << " rolled a " << t.diceRoll << " and moved from square "
       << t.startSquare << " to square " << t.endSquare;
    return os;
};


#endif //POO2024_TURNS_H
