#pragma once
#include "GameState.h"
#include "Entity.h"

class PauseMenu
{
public:
	PauseMenu(void);
	~PauseMenu(void);
	void processEvents(sf::Event &ev, sf::RenderWindow &window, GameState &gameState);
	void show(sf::RenderWindow &window);

private:
	Entity pauseMenu;
	void inRect(sf::RenderWindow &window);
};


