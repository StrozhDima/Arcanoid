#pragma once
#include "Map.h"
#include "Ball.h"
#include "Menu.h"
#include "PauseMenu.h"
#include "Score.h"
#include <Windows.h>

class Game
{
private:
	Rects rects;
	Player player;
	Ball ball;
	Map map;
	Menu menu;
	PauseMenu pauseMenu;
	GameState state;
	Score score;
	Sound isDeadSound;
	Sound isFinishSound;
	Sound menuSound;

	sf::RenderWindow window;
	sf::ContextSettings settings;
	sf::Event ev;

	bool wasPaused;
	bool inMenu;
	bool inGame;

public:
	Game();
	~Game();
	void run();

private:
	void processIvents();
	void update();
	void render();
	void reset();
	void music();

};

