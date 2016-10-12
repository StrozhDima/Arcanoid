#pragma once
#include "Entity.h"
#include "GameState.h"

class Menu
{
public:
	Menu();
	~Menu();
	void processEvents(sf::Event &ev, sf::RenderWindow &window, GameState &gameState);
	void show(sf::RenderWindow &window);

private:
	Entity menu;
	void inRect(sf::RenderWindow &window);
};

