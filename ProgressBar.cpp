#include "ProgressBar.h"

ProgressBar::ProgressBar()
{
	
	this->percentage = 50.f;
	background.setSize(sf::Vector2f(110, 40));
	background.setOutlineColor(sf::Color::Black);
	background.setFillColor(sf::Color::Black);
	background.setOutlineThickness(5);
	background.setPosition(10, 10);

	bar.setSize(sf::Vector2f(this->percentage, 30));
	bar.setOutlineColor(sf::Color::Transparent);
	bar.setFillColor(sf::Color::Green);
	bar.setOutlineThickness(5);
	bar.setPosition(10, 10);
	


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
	bar.setPosition(x, y);
	background.setPosition(x, y);

	
}
