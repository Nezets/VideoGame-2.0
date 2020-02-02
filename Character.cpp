#include "Character.h"
#include <SFML/Audio.hpp>

bool Character::isInvincible()
{
	return invincible;
}

//Constructors
Character::Character() {

	//Position
	curX = 0;
	curY = 0;
	angle = 0;

	//Starting stats
	maxHp = 100;
	curHp = 100;
	damage = 10;
	ms = 10;
	atkSpd = 10;

	//Level Stats
	curVelocity = sf::Vector2f(1, 1);
	//Flags
	alive = false;
	moving = false;
	hidden = false;

	counter = 0;
	//sound
	buffer.loadFromFile("sounds/boom.wav");
	sound.setBuffer(buffer);

}

float Character::getCurHp()
{
	return curHp;
}

float Character::getMaxHp()
{
	return maxHp;
}

float Character::getMs()
{
	return 0;
}
float Character::getAtkSpd()
{
	return atkSpd;
}

float Character::getDamage()
{
	return damage;
}

float Character::getCurX()
{
	return curX;
}

float Character::getCurY()
{
	return curY;
}

float Character::getAngle()
{
	return angle;
}

sf::Vector2f Character::getCurVelocity()
{
	return curVelocity;
}

int Character::getCounter()
{
	return counter;
}

bool Character::isHidden()
{
	return hidden;
}

void Character::setHidden(bool x)
{
	hidden = x;
}

void Character::setMs(float x)
{
	ms = x;
}

void Character::setDamage(float x)
{
	damage = x;
}

void Character::incrementCounter()
{
	counter++;
}

void Character::resetCounter()
{
	counter = 0;
}



//HP Functions
void Character::takeDamage(int dmgTaken) {
	sound.play();
	curHp -= dmgTaken;
	if (curHp <= 0) {
		death();
	}
}

void Character::heal(int healthGain) {
	curHp += healthGain;
	if (curHp > maxHp) {
		curHp = maxHp;
	}
}

void Character::updatePosition(float x, float y)
{
	curX = x;
	curY = y;
}

void Character::updateAngle(float x)
{
	angle = x;
}

void Character::pointMouseCursor(sf::RenderWindow& win)
{
	auto curPos = getPosition();
	auto position = sf::Mouse::getPosition(win);

	const float PI = 3.14159;

	float dx = curPos.x - position.x;
	float dy = curPos.y - position.y;

	setRotation(atan2(dy, dx) * 180 / PI);
}

void Character::moveTowardMouse(sf::RenderWindow& win)
{
	if (moving) {
		move(curVelocity * ms);
	}
	else {
		auto curPos = getPosition();
		auto position = sf::Mouse::getPosition(win);

		float dx = curPos.x - position.x;
		float dy = curPos.y - position.y;
		float mag = -1*sqrt(dx * dx + dy*dy);
		curVelocity = sf::Vector2f(dx/mag,dy/mag);
		moving = true;
	}
}

void Character::moveToPos(sf::RenderWindow& window,sf::Vector2f pos)
{
	/*if (moving) {
		move(curVelocity * ms);
	}
	else {*/
		auto curPos = getPosition();

		float dx = curPos.x - pos.x;
		float dy = curPos.y - pos.y;
		float mag = -1.f * sqrt(dx * dx + dy * dy);
		if(mag != 0)
			curVelocity = sf::Vector2f(dx / mag, dy / mag);
		moving = true;
		std::cout << dx << ", " << dy << std::endl;
		move(curVelocity * ms);
	//}
}

void Character::moveToPos(float x, float y)
{
	if (moving) {

		move(curVelocity * ms);
	}
	else {
		auto curPos = getPosition();

		float dx = curPos.x - x;
		float dy = curPos.y - y;
		float mag = -1 * sqrt(dx * dx + dy * dy);
		curVelocity = sf::Vector2f(dx / mag, dy / mag);
		moving = true;
	}
}

//End Game Functions
void Character::death() {


}