#include "Game.h"

Game::Game(void): isDeadSound("loser.wav"), menuSound("menu.wav"), isFinishSound("winner.wav"), wasPaused(false), inMenu(true), inGame(true)
{
	//уровень сглаживания
	settings.antialiasingLevel = 16;

	//создаем окно
	window.create(sf::VideoMode(800, 600), "Arkanoid 1.0", sf::Style::None, settings);
	window.setFramerateLimit(60);//скорость игры!!!

	//иницализация состояния игры при запуске
	state = GameState::START;

	//инициализация кубиков
	rects.initialize();
}

Game::~Game()
{
}

void Game::run() //запуск игры
{
	while (window.isOpen())
	{
		processIvents();
		update();
		render();
		music();
	}
}

void Game::processIvents() //обработка событий
{
	while (window.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
			window.close();

		else if (ev.type == sf::Event::KeyPressed)
		{
			if (state == GameState::START)
			{
				//если игра запущена, то если нажать пробел, то игра начнется
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					state = GameState::RUNNING;
				}

				//если игра запущена, то выход из игры по нажатию эскейп
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					window.close();
				}
			}

			else if (state == GameState::RUNNING)
			{
				//если игра началась, то пауза по нажатию эскейп
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					state = GameState::PAUSED;
				}
			}

			else if (state == GameState::PAUSED)
			{
				//если на паузе, то при нажатии пробела опять в игру
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					state = GameState::RUNNING;
				}

				//если на паузе, то по нажатию эскейпа в главное меню
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					//inGame = true;
					state = GameState::START;
					reset();
				}
			}
		}

		if(wasPaused)
			pauseMenu.processEvents(ev, window, state);
		else menu.processEvents(ev, window, state);
	}
}

void Game::update()//оживление
{
	if (state == GameState::PAUSED)

		return;

	if (state == GameState::RUNNING)
	{
		//оживление и столкновения
		player.update(window);
		ball.update(window);
		score.update(rects);

		//столкновения мяча и кубиков
		for (auto i = 0; i < rects.rects.size(); ++i)
		{
			ball.collisionsWithRect(rects, ball, i);
		}

		//столкновения мяча и игрока
		ball.collisionWithPlayer(player, ball);

		//Finish the game
		if (score.getScore() == rects.getRectNum())
		{
			//std::cout << "Finish the game!\n";

			//установим флаг игры на START(возврат в меню)
			state = GameState::START;
			inGame = true;
			isFinishSound.play();
			MessageBox(0, "CONGRATULATIONS!", "Arkanoid game: ", 0);
			reset();
		}

		//Game over 
		if (ball.getIsDead())
		{
			//std::cout << "Game over!\n";

			//установим флаг игры на START(возврат в меню)
			state = GameState::START;
			inGame = true;
			isDeadSound.play();
			MessageBox(0, "GAME OVER!", "Arkanoid game: ", 0);
			reset();
		}
	}
}

void Game::render() //отрисовка
{
	window.clear(sf::Color::Black);

	if (state == GameState::START)
	{
		wasPaused = false;
		menu.show(window);
	}

	else if (state == GameState::RUNNING)
	{
		wasPaused = false;
		map.draw(window);
		ball.draw(window);
		rects.draw(window);
		player.draw(window);
		score.draw(window);
	}

	else if (state == GameState::PAUSED)
	{
		wasPaused = true;
		pauseMenu.show(window);
	}

	window.display();
}

void Game::reset()
{
	player.reset();
	rects.reset();
	ball.reset();
	score.reset();
}

void Game::music() //танцы с бубном для музыки в меню
{
	if(state == GameState::START)
	{
		if(inGame)
		{
			menuSound.setLoop(true);
			menuSound.play();

			inGame = false;
			inMenu = true;
		}
	}

	if(state == GameState::RUNNING)
	{
		if(inMenu)
		{
			menuSound.stop();
			inMenu = false;
		}
	}

	if(state == GameState::PAUSED)
		inGame = true;
}