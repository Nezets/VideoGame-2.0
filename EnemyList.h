#pragma once
#include <iostream>
#include "Enemy.h"
#include "BulletManager.h"
class EnemyList
{
	vector<Enemy*> enemies;
	BulletManager enemyBullets;

public:
	EnemyList();

	void add(Enemy& enemy);
	void updateEnemies(sf::RenderWindow& window, sf::Vector2f pcPos);
};

