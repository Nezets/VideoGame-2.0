#pragma once
#include <SFML/Audio.hpp>

#include <SFML/Graphics.hpp>
#include <iostream>
#include "TextureManager.h"
class Character : public sf::Sprite {
	//Combat Stats
	float maxHp;
	float curHp;
	float damage;
	float ms;
	float atkSpd;

	sf::Vector2f curVelocity;
	//Position
	float curX;
	float curY;
	float angle;

	//Flags
	bool alive;
	bool moving;

	bool invincible;
	bool hidden;
	//Take Damage
	bool isInvincible();
	int invulnTime;


	int counter;

	//sound stuff
	sf::SoundBuffer buffer;
	sf::Sound sound;


public:
	//Constructors
	Character();

	//Getter Functions
	float getCurHp();
	float getMaxHp();
	float getDamage();
	float getMs();
	float getAtkSpd();

	float getCurX();
	float getCurY();
	float getAngle();
	sf::Vector2f getCurVelocity();
	int getCounter();

	bool isHidden();

	//Setters
	void setHidden(bool x);
	void setMs(float x);
	void setDamage(float x);

	//Counter
	void incrementCounter();
	void resetCounter();

	//HP Functions
	void takeDamage(int dmgTaken);
	void heal(int healthGain);

	//Position Functions
	void updatePosition(float x, float y);
	void updateAngle(float x);

	void pointMouseCursor(sf::RenderWindow& win);
	void moveTowardMouse(sf::RenderWindow& win);
	void moveToPos(sf::RenderWindow& window, sf::Vector2f pos);
	void moveToPos(float x, float y);

	//End Game Functions
	void death();
};