#pragma once
#include <SFML/Graphics.hpp>
class ProgressBar
{
private:
	sf::RectangleShape bar;
	sf::RectangleShape background;
	float locX;
	float locY;
	float percentage;
public:
	ProgressBar(sf::RenderWindow& window);
	void setPercentage(float perc);
	void setColor(const sf::Color barColor);
	void draw(sf::RenderWindow& window);
	void Pos(float x, float y);

};

