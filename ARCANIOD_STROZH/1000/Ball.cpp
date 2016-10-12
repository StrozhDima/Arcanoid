#include "Ball.h"

Ball::Ball():ball("ball.png", 0, 0, 20, 20), isDead(false), ballRadius(10.f), ballVelocity(7.0f), velocity(ballVelocity, -ballVelocity), crashSound("crash.wav")
{
	ball.setOrigInCentr();	
	position = sf::Vector2f(800 / 2, 562);
	ballShape.setRadius(ballRadius);
	ballShape.setPosition(position);
}

Ball::~Ball()
{
}

void Ball::update(sf::RenderWindow &window)
{
	ballShape.move(velocity);

	///////////����� ����� ������//////////////////////////
	if (ballShape.getPosition().y >= 580)
		isDead = true;

	else isDead = false;

	//////////������������ � ��������� �����///////////////
	if (left() < 20)
		velocity.x = ballVelocity;

	else if (right() > 780)
		velocity.x = -ballVelocity;

	else if (top() < 20)
		velocity.y = ballVelocity;
}

void Ball::collisionsWithRect(Rects &rect, Ball &ball, int index) //������������� ������ � �������
{
	if(intersectionWithRect(rect, ball, index))
	{
		if(ball.velocity.y == - ballVelocity) //���� ����� ����� �����
		{
			if(ball.velocity.x == ballVelocity || ball.velocity.x == - ballVelocity)//���� ����� ����� ������ ��� �����
				ball.velocity.y = ballVelocity; //������ �������� �� � �� ����
		}

		else if(ball.velocity.y == ballVelocity) //���� ����� ����� ����
		{
			if(ball.velocity.x == ballVelocity || ball.velocity.x == - ballVelocity)//���� ����� ����� ������ ��� �����
				ball.velocity.y = - ballVelocity; //������ �������� �� � �� �����
		}

		rect.rects.erase(rect.rects.begin() + index);
		crashSound.play();
	}
}

bool Ball::intersectionWithRect(Rects &rect, Ball &ball, int index)//������������ � ��������
{
	return (rect.right(index) >= ball.left() && rect.left(index) <= ball.right()
		&& rect.bottom(index) >= ball.top() && rect.top(index) <= ball.bottom());
}

void Ball::collisionWithPlayer(Player &player, Ball &ball)
{
	if (!(intersectionWithPlayer(player, ball)))
		return;

	ball.velocity.y = -ball.ballVelocity;

	if (ball.velocity.x == ball.ballVelocity)
		ball.velocity.x = ball.ballVelocity;

	else
		ball.velocity.x = -ball.ballVelocity;
}

bool Ball::intersectionWithPlayer(Player &player, Ball &ball)
{
	return player.right() >= ball.left() && player.left() <= ball.right()
		&& player.bottom() >= ball.top() && player.top() <= ball.bottom();
}


void Ball::draw(sf::RenderWindow &window) //��������� ������
{
	ball.setPosition(ballShape.getPosition());
	window.draw(ball.getSprite());
}

void Ball::reset()
{
	ballShape.setPosition(position);
}