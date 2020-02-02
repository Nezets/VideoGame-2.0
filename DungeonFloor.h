//
// Created by Michael Ivanov on 1/31/2020.
//

#ifndef ROUGEGAME_DUNGEONFLOOR_H
#define ROUGEGAME_DUNGEONFLOOR_H

#include <random>
#include "Room.h"
#include "ctime"



class DungeonFloor : public sf::Sprite{
    map<string, Room> rooms;
    string currPos;
public:
    DungeonFloor();

    string &getCurrPos();


    void setCurrPos(const string &currPos);

    void randomizeRooms();
    void setDoorAmounts();
    void moveRoom(string direction);
    int random(int min, int max);
    map<string, Room> &getRooms();
};


#endif //ROUGEGAME_DUNGEONFLOOR_H
