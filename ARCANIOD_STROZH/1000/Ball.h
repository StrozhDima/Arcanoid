#pragma once
#include "Player.h"
#include "Rects.h"
#include "Sound.h"

class Ball
{
private:
	bool isDead;
	const float ballRadius;
	float ballVelocity;

	sf::CircleShape ballShape;
	sf::Vector2f position;
	sf::Vector2f velocity;

	Entity ball;
	Sound crashSound;

public:
	Ball();
	~Ball();

	bool getIsDead(){ return isDead; }
	void collisionsWithRect(Rects &rect, Ball &ball, int index); //������������� ������ � �������
	void collisionWithPlayer(Player &player, Ball &ball); //������������� ������ � ����������
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void reset();

private:
	float x()		{ return ballShape.getPosition().x; }
	float y()		{ return ballShape.getPosition().y; }
	float left()	{ return x() - ballShape.getRadius(); }
	float right()	{ return x() + ballShape.getRadius(); }
	float top()		{ return y() - ballShape.getRadius(); }
	float bottom()	{ return y() + ballShape.getRadius(); }

	bool intersectionWithRect(Rects &rect, Ball &ball, int index);//������������� � ��������
	bool intersectionWithPlayer(Player &player, Ball &ball);//������������� � ����������
};

