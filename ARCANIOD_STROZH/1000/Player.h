#pragma once
#include "Entity.h"

class Player
{
private:
	const float playerWidth;
	const float playerHeight;
	const float playerVelocity;

	sf::RectangleShape playerShape;
	sf::Vector2f velocity;
	sf::Vector2f position;
	sf::Vector2f playerSize;

	Entity player;	

public:
	Player();
	void update(sf::RenderWindow &window);//функция "оживления" объекта класса.
	void draw(sf::RenderWindow &window); //отрисовка платформы
	void reset();

	float x()		{ return playerShape.getPosition().x; }
	float y()		{ return playerShape.getPosition().y; }
	float left()	{ return x() - playerShape.getSize().x / 2.f; }
	float right()	{ return x() + playerShape.getSize().x / 2.f; }
	float top()		{ return y() - playerShape.getSize().y / 2.f; }
	float bottom()	{ return y() + playerShape.getSize().y / 2.f; }
};

