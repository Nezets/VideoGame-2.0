#include "UI.h"
#include "ProgressBar.h"
#include "PC.h"
UI::UI()
{
	healthBar = new ProgressBar();
	XPBar = new ProgressBar();
	healthBar->Pos(10, 10);
	XPBar->Pos(400, 10);
	healthBar->setColor(sf::Color::Green);
	XPBar->setColor(sf::Color::Cyan);



}
void UI::draw(sf::RenderWindow& window, PC* player)
{
	healthBar->setPercentage((float(player->getCurHp()) / float(player->getMaxHp())) * 100);
	XPBar->setPercentage((float(player->getExp() )/ float(player->getMaxExp())) * 100);

	healthBar->draw(window);
	XPBar->draw(window);
}
