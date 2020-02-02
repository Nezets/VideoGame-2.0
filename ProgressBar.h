#pragma once
#include <SFML/Graphics.hpp>
class ProgressBar
{
private:
	sf::RectangleShape bar;
	sf::RectangleShape background;
	
	float percentage;
public:
	ProgressBar();
	void setPercentage(float perc);
	void setColor(const sf::Color barColor);
	void draw(sf::RenderWindow& window);
	void Pos(float x, float y);

};

