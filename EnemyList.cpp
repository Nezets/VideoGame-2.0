#include "EnemyList.h"

EnemyList::EnemyList()
{
}

void EnemyList::add(Enemy& enemy)
{
	enemies.push_back(&enemy);
}

void EnemyList::updateEnemies(sf::RenderWindow& window, sf::Vector2f pcPos)
{
	for (auto* enemy : enemies) {
		if (enemy->getType() == 1) {
			enemy->moveToPos(window,pcPos);
		}
		else if (enemy->getType() == 2) {
			
			if (enemy->getCounter() >= 20) {
				Bullet* newBullet = new Bullet(enemy->getDamage());
				newBullet->setPosition(enemy->getPosition());
				enemyBullets.addBullet(newBullet);
				enemy->resetCounter();
			}
			else {
				enemy->incrementCounter();
			}
		}

		//enemyBullets.updateBullets(window,pcPos);
		window.draw(*enemy);
	}
	//enemyBullets.updateBullets();
}
