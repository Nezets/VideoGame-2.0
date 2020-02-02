#include "BulletManager.h"

BulletManager::BulletManager()
{
	
}

BulletManager::~BulletManager()
{
	for (Bullet* bullet : bullets) {
		delete bullet;
	}
}

void BulletManager::addBullet(Bullet* bullet)
{
	bullets.push_back(bullet);

}

void BulletManager::updateBullets(sf::RenderWindow& window)
{
	for (Bullet* bullet : bullets) {
		bullet->moveTowardMouse(window);
		
		if (bullet->getPosition().x < 0 || bullet->getPosition().x > window.getSize().x || bullet->getPosition().y < 0 || bullet->getPosition().y > window.getSize().y) {
			bullet->setHidden(true);
		}
		if(!bullet->isHidden()){
		window.draw(*bullet);
		}
	}
}

void BulletManager::updateBullets(sf::RenderWindow& window, sf::Vector2f pos)
{
	for (Bullet* bullet : bullets) {
		bullet->moveToPos(window,pos);

		if (bullet->getPosition().x < 0 || bullet->getPosition().x > window.getSize().x || bullet->getPosition().y < 0 || bullet->getPosition().y > window.getSize().y) {
			bullet->setHidden(true);
		}
		if (!bullet->isHidden()) {
			window.draw(*bullet);
		}
	}
}

bool BulletManager::bulletCollision(Character& obj)
{
	for (auto& bullet : bullets) {
		if (bullet->getGlobalBounds().intersects(obj.getGlobalBounds())) {
			return true;
		}
	}
	return false;
}
