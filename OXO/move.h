#ifndef MOVE_H
#define MOVE_H

#include<iostream>

using namespace std;

class Move
{
    string itsCoord;
public:
    Move();
    bool verifCoord();
    void setCoord(string coord);
    string getCoord();
};

#endif // MOVE_H
