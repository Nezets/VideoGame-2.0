//
// Created by Michael Ivanov on 1/31/2020.
//

#ifndef ROUGEGAME_ROOM_H
#define ROUGEGAME_ROOM_H


#include <SFML/Graphics/Sprite.hpp>
#include "TextureManager.h"
#include "Door.h"
#include "EnemyList.h"

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



class Room : public sf::Sprite {
    //Rooms have up to 4 doors, and must have at least one
    int doorAmount;
    // Look above for context on room IDs
    string roomID;
    bool bossRoom;
    int pcPos;
    // All doors will be locked when player enters a room, they open when all enemies are gone
    bool doorsLocked;
    void setDoorPos();
    vector<Enemy> Enemies;

    vector<Door> doors;
    /*      0
     * 1          2
     *      3
     */

public:
    Room();
    int getDoorAmount() const;
    void placeEnemies();

    EnemyList &getList();

    vector<Door> &getDoors();

    void incrementDoorAmount();

    string getRoomId();

    void setRoomId(string roomId);

    void setBossRoom(bool bossRoom);

    bool isBossRoom() const;

    bool isDoorsLocked() const;

    void setDoorsLocked(bool doorsLocked);

    vector<Enemy> &getEnemies();


};


#endif //ROUGEGAME_ROOM_H
