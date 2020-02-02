//
// Created by Michael Ivanov on 1/31/2020.
//

#include "Room.h"

Room::Room() {
    setTexture(TextureManager::GetTexture("floor"));
    this->scale(1.3,1.3);
    this->setOrigin(800.0/2, 512.0/2);
    this->move(1200.0/2, 900.0/2);
    doorAmount = 0;
    roomID = "";
    bossRoom = false;
    doorsLocked = false;
    doors.resize(4);
    setDoorPos();
    placeEnemies();

}

int Room::getDoorAmount() const {
    return doorAmount;
}

string Room::getRoomId() {
    return roomID;
}

bool Room::isBossRoom() const {
    return bossRoom;
}

bool Room::isDoorsLocked() const {
    return doorsLocked;
}

void Room::incrementDoorAmount() {
    Room::doorAmount++;
}

void Room::setRoomId(string roomId) {
    roomID = roomId;
}

vector<Door> &Room::getDoors() {
    return doors;
}

void Room::setDoorPos() {
    for (int i = 0; i < 4; ++i) {
        doors[i].setOrigin(96.0/2,96.0/2);
    }
    doors[1].rotate(270);
    doors[2].rotate(90);
    doors[3].rotate(180);

    doors[0].move(1200.0/2, 96);
    doors[1].move(60, 450);
    doors[2].move(1200-60, 450);
    doors[3].move(1200.0/2, 800);
}

void Room::setBossRoom(bool bossRoom) {
    Room::bossRoom = bossRoom;
}

void Room::placeEnemies() {
    Enemies.resize((rand() % 5) + 1);
    Enemies[0].setPosition(300, 400);
}

vector<Enemy> &Room::getEnemies() {
    return Enemies;
}

void Room::setDoorsLocked(bool doorsLocked) {
    Room::doorsLocked = doorsLocked;
    for (int i = 0; i < 4; ++i) {
        doors[i].setLocked(true);
    }
}

