#pragma once
#include "Character.h"
class Enemy : public Character{
	//Constructors for enemy types
	/* List of Enemies here?
	* 
	* 1 = Bomb Melee Dude
	* 2 = Ranged Dude
	*/

	bool meleeRange;
	short enemyType;
public:
	Enemy(short x);
	
	short getType();
	void moveTowardPoint(float x, float y);
};

