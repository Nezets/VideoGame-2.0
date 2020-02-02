#pragma once
#include <vector>
#include "Bullet.h"
using std::vector;
class BulletManager
{
	vector<Bullet*> bullets;
public:
	BulletManager();
	~BulletManager();

	void addBullet(Bullet* bullet);
	void updateBullets(sf::RenderWindow& window);
	void updateBullets(sf::RenderWindow& window, sf::Vector2f pos);
	bool bulletCollision(Character& obj);
};
