#include "Menu.h"

Menu::Menu():menu("menu.png", 0, 0, 800, 600)
{
}

Menu::~Menu()
{
}

void Menu::inRect(sf::RenderWindow &window)
{
	if(sf::IntRect(300, 280, 189, 73).contains(sf::Mouse::getPosition(window)))
	{
		menu.setColorSprite(128, 255, 128);
	}

	else if(sf::IntRect(304, 394, 189, 73).contains(sf::Mouse::getPosition(window)))
	{
		menu.setColorSprite(255, 128, 128);
	}

	else menu.setColorSprite(255, 255, 255);
}

void Menu::processEvents(sf::Event &ev, sf::RenderWindow &window, GameState &gameState)
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
				window.close();
			}
		}
}

void Menu::show(sf::RenderWindow &window)
{
	window.draw(menu.getSprite());
}