#include "Game.h"

Game::Game(void): isDeadSound("loser.wav"), menuSound("menu.wav"), isFinishSound("winner.wav"), wasPaused(false), inMenu(true), inGame(true)
{
	//������� �����������
	settings.antialiasingLevel = 16;

	//������� ����
	window.create(sf::VideoMode(800, 600), "Arkanoid 1.0", sf::Style::None, settings);
	window.setFramerateLimit(60);//�������� ����!!!

	//������������ ��������� ���� ��� �������
	state = GameState::START;

	//������������� �������
	rects.initialize();
}

Game::~Game()
{
}

void Game::run() //������ ����
{
	while (window.isOpen())
	{
		processIvents();
		update();
		render();
		music();
	}
}

void Game::processIvents() //��������� �������
{
	while (window.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
			window.close();

		else if (ev.type == sf::Event::KeyPressed)
		{
			if (state == GameState::START)
			{
				//���� ���� ��������, �� ���� ������ ������, �� ���� ��������
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					state = GameState::RUNNING;
				}

				//���� ���� ��������, �� ����� �� ���� �� ������� ������
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					window.close();
				}
			}

			else if (state == GameState::RUNNING)
			{
				//���� ���� ��������, �� ����� �� ������� ������
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					state = GameState::PAUSED;
				}
			}

			else if (state == GameState::PAUSED)
			{
				//���� �� �����, �� ��� ������� ������� ����� � ����
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					state = GameState::RUNNING;
				}

				//���� �� �����, �� �� ������� ������� � ������� ����
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

void Game::update()//���������
{
	if (state == GameState::PAUSED)

		return;

	if (state == GameState::RUNNING)
	{
		//��������� � ������������
		player.update(window);
		ball.update(window);
		score.update(rects);

		//������������ ���� � �������
		for (auto i = 0; i < rects.rects.size(); ++i)
		{
			ball.collisionsWithRect(rects, ball, i);
		}

		//������������ ���� � ������
		ball.collisionWithPlayer(player, ball);

		//Finish the game
		if (score.getScore() == rects.getRectNum())
		{
			//std::cout << "Finish the game!\n";

			//��������� ���� ���� �� START(������� � ����)
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

			//��������� ���� ���� �� START(������� � ����)
			state = GameState::START;
			inGame = true;
			isDeadSound.play();
			MessageBox(0, "GAME OVER!", "Arkanoid game: ", 0);
			reset();
		}
	}
}

void Game::render() //���������
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

void Game::music() //����� � ������ ��� ������ � ����
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