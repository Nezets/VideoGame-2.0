//
// Created by Michael Ivanov on 1/31/2020.
//

#include "DungeonFloor.h"
#include <iostream>
std::mt19937 random_mt(time(nullptr));

DungeonFloor::DungeonFloor() {
    setTexture(TextureManager::GetTexture("walls"));
    currPos = "C3";
    randomizeRooms();
    setDoorAmounts();
}
/*
 * A0 B0 C0 D0 E0 F0
 * A1 B1 C1 D1 E1 F1
 * A2 B2 C2 D2 E2 F2
 * A3 B3 C3 D3 E3 F3
 * A4 B4 C4 D4 E4 F4
 * A5 B5 C5 D5 E5 F5
 *
 * Dungeon floor will comprise of a 6 by 6
 * out of these, only 6 will be rooms, rest will not exist
 * These rooms have to be connected and one room is a Boss Room
 * Boss room will only have one entrance
 *
 */
/*      0
 * 1          2
 *      3
 */
void DungeonFloor::randomizeRooms() {
    Room room;
    rooms.emplace(currPos, room);
    int doorPos;
    string tempCurrent = currPos;

    while(rooms.size() != 6){
        doorPos = random(0,3);
        if((tempCurrent[0] == 'A' && doorPos == 1) || (tempCurrent[0] == 'F' && doorPos == 2)){
            continue;
        }
        if((tempCurrent[1] == '0' && doorPos == 0) || (tempCurrent[1] == '5' && doorPos == 3)){
            continue;
        }
        switch (doorPos){
            case 0:
                tempCurrent[1]--;
                break;
            case 1:
                tempCurrent[0]--;
                break;
            case 2:
                tempCurrent[0]++;
                break;
            case 3:
                tempCurrent[1]++;
                break;
            default:
                // Hopefully never gets to here ;(
                break;
        }
        rooms.emplace(tempCurrent, room);
        rooms[tempCurrent].setRoomId(tempCurrent);
        if(rooms.size() == 6){
            rooms[tempCurrent].setBossRoom(true);
            rooms[tempCurrent].setTexture(TextureManager::GetTexture("bossfloor"));
            for (int i = 0; i < 4; ++i) {
                rooms[tempCurrent].getDoors()[i].setTexture(TextureManager::GetTexture("bossdoor"));
            }
        }
    }
}

map<string, Room> &DungeonFloor::getRooms() {
    return rooms;
}

int DungeonFloor::random(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(random_mt);
}

// This fuction sets the door amounts and sets the visable tag for the door if it exists
void DungeonFloor::setDoorAmounts(){
    for(auto &room : rooms){
        char ID_X = room.first[0];
        char ID_Y = room.first[1];
        /*      0
        * 1          2
        *      3
        */
        // Find if room above exists
        ID_Y--;
        if(rooms.find(string() + ID_X + ID_Y) != rooms.end()){
            room.second.incrementDoorAmount();
            room.second.getDoors()[0].setVisable(true);
            if(rooms[string() + ID_X + ID_Y].isBossRoom()){
                room.second.getDoors()[0].setTexture(TextureManager::GetTexture("bossdoor"));
            }
        }
        // Find if room below exists
        ID_Y += 2;
        if(rooms.find(string() + ID_X + ID_Y) != rooms.end()){
            room.second.incrementDoorAmount();
            room.second.getDoors()[3].setVisable(true);
            if(rooms[string() + ID_X + ID_Y].isBossRoom()){
                room.second.getDoors()[3].setTexture(TextureManager::GetTexture("bossdoor"));
            }
        }
        // Find if left room exists
        ID_Y -= 1;
        ID_X--;
        if(rooms.find(string() + ID_X + ID_Y) != rooms.end()){
            room.second.incrementDoorAmount();
            room.second.getDoors()[1].setVisable(true);
            if(rooms[string() + ID_X + ID_Y].isBossRoom()){
                room.second.getDoors()[1].setTexture(TextureManager::GetTexture("bossdoor"));
            }
        }
        ID_X += 2;
        if(rooms.find(string() + ID_X + ID_Y) != rooms.end()){
            room.second.incrementDoorAmount();
            room.second.getDoors()[2].setVisable(true);
            if(rooms[string() + ID_X + ID_Y].isBossRoom()){
                room.second.getDoors()[2].setTexture(TextureManager::GetTexture("bossdoor"));
            }
        }
    }
}

void DungeonFloor::moveRoom(string direction) {
    auto currDoors = rooms[currPos].getDoors();
    if (direction == "north"){
        if(currDoors[0].isVisable() && !currDoors[0].isLocked()){
            currPos[1]--;
        }
    } else if (direction == "west"){
        if(currDoors[1].isVisable() && !currDoors[1].isLocked()){
            currPos[0]--;
        }
    } else if (direction == "east"){
        if(currDoors[2].isVisable() && !currDoors[2].isLocked()){
            currPos[0]++;
        }
    } else if (direction == "south"){
        if(currDoors[3].isVisable() && !currDoors[3].isLocked()){
            currPos[1]++;
        }
    }
    std::cout << currPos << std::endl;
}
string &DungeonFloor::getCurrPos() {
    return currPos;
}

void DungeonFloor::setCurrPos(const string &currPos) {
    DungeonFloor::currPos = currPos;
}
