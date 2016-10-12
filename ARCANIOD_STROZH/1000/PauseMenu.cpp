#include "PauseMenu.h"


PauseMenu::PauseMenu(void):pauseMenu("pausemenu.png", 0, 0, 800, 600)
{
}

PauseMenu::~PauseMenu(void)
{
}

void PauseMenu::inRect(sf::RenderWindow &window)
{
	if(sf::IntRect(300, 280, 189, 73).contains(sf::Mouse::getPosition(window)))
	{
		pauseMenu.setColorSprite(128, 255, 128);
	}

	else if(sf::IntRect(304, 394, 189, 73).contains(sf::Mouse::getPosition(window)))
	{
		pauseMenu.setColorSprite(255, 128, 128);
	}

	else pauseMenu.setColorSprite(255, 255, 255);
}

void PauseMenu::processEvents(sf::Event &ev, sf::RenderWindow &window, GameState &gameState)
{
	inRect(window);

	if(ev.type == sf::Event::MouseButtonPressed && sf::IntRect(300, 280, 189, 73).contains(sf::Mouse::getPosition(window)))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			gameState = GameState::RUNNING;
		}
	}

	else if(ev.type == sf::Event::MouseButtonPressed && sf::IntRect(304, 394, 189, 73).contains(sf::Mouse::getPosition(window)))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			gameState = GameState::START;
		}
	}
}

void PauseMenu::show(sf::RenderWindow &window)
{
	window.draw(pauseMenu.getSprite());
}