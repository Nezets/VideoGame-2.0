#include "Enemy.h"
#include "PC.h"

Enemy::Enemy(short x) {
	enemyType = x;
	if (x == 1) {
		meleeRange = true;
		setTexture(TextureManager::GetTexture("bombv2"));
		setMs(1);
	}
	else if (x == 2) {
		meleeRange = false;
		setTexture(TextureManager::GetTexture("shooterv2"));
		setMs(0.f);
	}
	else {
		meleeRange = false;
	}
}

short Enemy::getType()
{
	return enemyType;
}
void Enemy::moveTowardPoint(float x, float y)
{
	float curX = getPosition().x;
	float curY = getPosition().y;

	float ms = 1;

	if (curX < x) {
		move(ms, 0);
	}
	else if (curX > x) {
		move(-ms, 0);
	}

	if (curY < y) {
		move(0, ms);
	}
	else if (curY > 10) {
		move(0, -ms);
	}
}
//void Enemy::death() override
//{
//
//}

