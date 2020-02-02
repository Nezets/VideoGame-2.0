#include "Enemy.h"
Enemy::Enemy(short x) {
	enemyType = x;
	if (x == 1) {
		meleeRange = true;
		setTexture(TextureManager::GetTexture("shooterv2"));
	}
	else if (x == 2) {
        meleeRange = false;
        //setTexture
        setTexture(TextureManager::GetTexture("bombv2"));
        setMs(0.f);
	}
}

short Enemy::getType()
{
	return enemyType;
}

Enemy::Enemy() {
    int x = (rand() % 2) + 1;
    enemyType = x;
    if (x == 1) {
        meleeRange = true;
        setTexture(TextureManager::GetTexture("shooterv2"));
    }
    else if (x == 2) {
        meleeRange = false;
        //setTexture
        setTexture(TextureManager::GetTexture("bombv2"));
        setMs(0.f);
    }
}
