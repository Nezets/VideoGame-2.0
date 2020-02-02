//
// Created by Michael Ivanov on 2/1/2020.
//

#include "SnakeBoss.h"

SnakeBoss::SnakeBoss() {
    setTexture(TextureManager::GetTexture("snakehead"));
    setOrigin(100.0/2, 100.0/2);
    setPosition(150, 200);
    tails.resize(5);
    alive = false;
    hp = 100;

}

void SnakeBoss::update() {
    move(5,0);
}

bool SnakeBoss::isAlive() {
    return alive;
}

void SnakeBoss::setAlive(bool alive) {
    SnakeBoss::alive = alive;
}

vector<SnakeBoss::tail> &SnakeBoss::getTails() {
    return tails;
}

SnakeBoss::tail::tail() {
    setTexture(TextureManager::GetTexture("snakebody"));
    setOrigin(100.0/2, 100.0/2);
    setPosition(150, 200);
}
