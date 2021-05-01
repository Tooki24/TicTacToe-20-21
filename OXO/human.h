#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"

class Human : public Player
{
public:
    Human(string name);
    void playHuman();
};

#endif // HUMAN_H
