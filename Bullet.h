#pragma once
#include "Character.h"
class Bullet : public Character
{
	int damage;
	int speed;
	//Add Sprite stuff
public:
	Bullet(float damage_);
	int getDamage();
	int getSpeed();

};

