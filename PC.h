#pragma once
#include "Character.h"
class PC : public Character{
private:
	//Level Stats
	
	int exp;
	int dmgLevel;
	int msLevel;
	int atkSpdLevel;
	int level;
	int maxExp;
	//Flags
public:
	PC();

	


	//Exp Functions
	void expGain(int exp);
	void upgradeLevel(short type);

	int getExp();
	int getLevel();
	int getMaxExp();


	//Level Stuff
	int getDmgLevel();
	int getMsLevel();
	int getAtkSpdLevel();

};

