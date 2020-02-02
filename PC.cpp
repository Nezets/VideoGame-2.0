#include "PC.h"
//Constructors
PC::PC() {
	exp = 0;
	dmgLevel = 1;
	msLevel = 1;
	atkSpdLevel = 1;
	maxExp = 10;
	setTexture(TextureManager::GetTexture("PC"));

	setOrigin(157.0/2 + 5, 117.0/2);
	setScale(0.5f, 0.5f);
}

//Getter Functions
int PC::getExp()
{
	return exp;
}
int PC::getLevel()
{
	return level;
}

int PC::getDmgLevel()
{
	return dmgLevel;
}

int PC::getMsLevel()
{
	return msLevel;
}

int PC::getAtkSpdLevel()
{
	return atkSpdLevel;
}



//Level Functions
void PC::expGain(int expGained) {
	exp += expGained;

}

void PC::upgradeLevel(short type)
{

}

int PC::getMaxExp() {
    return 0;
}
