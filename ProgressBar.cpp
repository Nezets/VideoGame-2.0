#include "ProgressBar.h"

ProgressBar::ProgressBar()
{
	this->locX = 10;
	this->locY = 20;
	this->percentage = 50.f;
	background.setSize(sf::Vector2f(110, 40));
	background.setOutlineColor(sf::Color::Black);
	background.setFillColor(sf::Color::Black);
	background.setOutlineThickness(5);
	background.setPosition(this->locX, this->locY);

	bar.setSize(sf::Vector2f(this->percentage, 30));
	bar.setOutlineColor(sf::Color::Transparent);
	bar.setFillColor(sf::Color::Green);
	bar.setOutlineThickness(5);
	bar.setPosition(this->locX, this->locY);
	


}
void ProgressBar::setPercentage(float perc)
{
	this->percentage = perc;
}
void ProgressBar::draw(sf::RenderWindow& window)
{
	window.draw(this->background);
	window.draw(this->bar);
}
void ProgressBar::setColor(const sf::Color barColor)
{
	bar.setFillColor(barColor);
}
void ProgressBar::Pos(float x, float y)
{
	this->locX = x;
	this->locY = y;
}
