//
// Created by Michael Ivanov on 2/1/2020.
//

#ifndef ROUGEGAME_SNAKEBOSS_H
#define ROUGEGAME_SNAKEBOSS_H


#include <SFML/Graphics/Sprite.hpp>
#include "TextureManager.h"

class SnakeBoss : public sf::Sprite {
    struct tail : public sf::Sprite{
        tail();
    };
    vector<tail> tails;
    bool alive;
    int hp;

public:
    SnakeBoss();
    void update();

    bool isAlive();

    vector<tail> &getTails();

    void setAlive(bool alive);
};


#endif //ROUGEGAME_SNAKEBOSS_H
