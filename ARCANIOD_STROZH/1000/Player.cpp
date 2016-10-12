#include "Player.h"

Player::Player():player("platform.png", 0, 0, 128, 16), playerWidth(128), playerHeight(16), playerVelocity(10.f) //����������� ������ ��� ������
{
	player.setOrigInCentr();

	sf::Vector2f playerSize(sf::Vector2f (playerWidth, playerHeight));
	position = sf::Vector2f(800/2 , 600 - 28);
	playerShape.setSize(playerSize);
	playerShape.setPosition(position);
	playerShape.setOrigin(playerWidth/2.f, playerHeight/2.f);
	
}

void Player::update(sf::RenderWindow &window)//������� "���������" ������� ������. update - ����������. ��������� � ���� ����� SFML , ���������� ���� �������� ����������, ����� ��������� ��������.
{
	playerShape.move(velocity);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && left() > 20)
		velocity.x = -playerVelocity;

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && right() < 780)
		velocity.x = playerVelocity;

	else velocity.x = 0;
}


void Player::draw(sf::RenderWindow &window)
{
	player.setPosition(playerShape.getPosition()); //������� ������ � ������� x y , ����������.
	window.draw(player.getSprite());
}

void Player::reset()
{
	playerShape.setPosition(position);
}