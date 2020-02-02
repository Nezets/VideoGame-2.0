//
// Created by Michael Ivanov on 2/1/2020.
//

#include "SnakeBoss.h"

SnakeBoss::SnakeBoss() {
    setTexture(TextureManager::GetTexture("snakehead"));
    setOrigin(100.0/2, 100.0/2);
    setPosition(150, 200);
    tails.resize(3);
    alive = false;
    hp = 100;
    count = 0;
    direction = "east";

}

void SnakeBoss::update() {
    sf::Vector2f topRight;
    topRight.x = 1100;
    topRight.y = 150;

    sf::Vector2f botRight;
    botRight.x = 1100;
    botRight.y = 750;

    sf::Vector2f botLeft;
    botLeft.x = 100;
    botLeft.y = 750;

    sf::Vector2f topLeft;
    topLeft.x = 100;
    topLeft.y = 150;

    if (count < 500){
        count++;
        if (count > 100/3 && tails[0].direction != "south"){
            tails[0].direction = "east";
        }
        if (count > 200/3 && tails[0].direction != "south")
            tails[1].direction = "east";
        if (count > 300/3 && tails[0].direction != "south")
            tails[2].direction = "east";
    }
    if(this->getGlobalBounds().contains(topRight)){
        direction = "south";
    } else if(this->getGlobalBounds().contains(botRight)){
        direction = "west";
    }else if(this->getGlobalBounds().contains(botLeft)){
        direction = "north";
    }else if(this->getGlobalBounds().contains(topLeft)){
        direction = "east";
    }
    if(direction == "south"){
        move(0,3);
    } else if(direction == "east"){
        move(3,0);
    } else if(direction == "west"){
        move(-3,0);
    } else if(direction == "north"){
        move(0,-3);
    }
    for (auto &tail : tails) {
        if(tail.getGlobalBounds().contains(topRight)){
            tail.direction = "south";
        }
        if(tail.getGlobalBounds().contains(botRight)){
            tail.direction = "west";
        }
        if(tail.getGlobalBounds().contains(botLeft)){
            tail.direction = "north";
        }
        if(tail.getGlobalBounds().contains(topLeft) && count > 400){
            tail.direction = "east";
        }
        if(tail.direction == "south"){
            tail.move(0,3);
        }
        if(tail.direction == "east"){
            tail.move(3,0);
        }
        if(tail.direction == "west"){
            tail.move(-3,0);
        }
        if(tail.direction == "north"){
            tail.move(0,-3);
        }
    }


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
    direction = "";
}
