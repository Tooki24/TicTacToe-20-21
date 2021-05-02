#include "player.h"


Player::Player(string name, Type type, State state)
{
    itsName=name;
    itsType=type;
    itsState=state;
}
void Player::setItsName(string name){
    itsName=name;
}

void Player::setItsType(Type aType){
    itsType=aType;
}

void Player::setItsState(State aState){
    itsState=aState;
}

string Player::getItsName(){
    return itsName;
}
State Player::getItsState(){
    return itsState;
}

Type Player::getItsType(){
    return itsType;
}
