#include "Bullet.h"

Bullet::Bullet(float damage_) {
	damage = damage_;
	speed = 10;
	setTexture(TextureManager::GetTexture("Bullet"));
	setOrigin(160, 160);
	setScale(0.5f, 0.5f);

}



int Bullet::getDamage()
{
	return damage;
}

int Bullet::getSpeed()
{
	return speed;
}
