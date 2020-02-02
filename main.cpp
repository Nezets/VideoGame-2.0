#pragma once
#include <iostream>
#include "TextureManager.h"
#include "DungeonFloor.h"
#include "PC.h"
#include "Bullet.h"
#include "BulletManager.h"
#include "ProgressBar.h"
#include "UI.h"
#include "Enemy.h"
#include "EnemyList.h"

int main() {
	//SFML Stuff
	sf::RenderWindow window(sf::VideoMode(800, 600), "Rouge Dungeon");
	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);
	//Objects
	DungeonFloor floor1;
	PC pc;
	pc.setPosition(300, 300);
	BulletManager bullets = BulletManager();
	sf::Sprite crosshair;

	
	crosshair.setTexture(TextureManager::GetTexture("Crosshair"));
	crosshair.setOrigin(crosshair.getTexture()->getSize().x/2, crosshair.getTexture()->getSize().y/2);
	UI ui;
	


	EnemyList enemyList;
	Enemy* testGuy =new Enemy(1);
	testGuy->setOrigin(160,160);
	enemyList.add(*testGuy);
	testGuy->setPosition(300, 300);

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		Bullet newBullet(pc.getDamage());
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed && (pc.getCounter() > 59)) {
				Bullet* newBullet = new Bullet(pc.getDamage());
				newBullet->setPosition(pc.getPosition());
				newBullet->rotate(pc.getAngle());
				bullets.addBullet(newBullet);
				pc.resetCounter();
			}
			pc.incrementCounter();

			
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
			pc.move(-10.f, 0.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			pc.move(0.f,-10.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			pc.move(0.f, 10.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
			pc.move(10.f, 0.f);
		}

		window.clear();
		ui.draw(window, &pc);
		bullets.updateBullets(window);
		//Stuff to upload because mess
		window.draw(pc);
		pc.pointMouseCursor(window);
		crosshair.setPosition(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y);
		window.draw(crosshair);
		testGuy->moveTowardPoint(pc.getPosition().x, pc.getPosition().y);
		window.draw(*testGuy);
		window.display();

	}

	return 0;
}