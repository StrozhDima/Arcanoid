#pragma once
#include <SFML/Graphics.hpp>

class Entity
{

private:
	float x, y, w, h; //���������� � � �, ������, ������, ��������� (�� � � �� �)
	sf::String file; //���� � �����������
	sf::Image image;//���� �����������
	sf::Texture texture;//���� ��������
	sf::Sprite sprite;//���� ������

public:
	Entity (sf::String F, float X, float Y, float W, float H);
	void setOrigInCentr();
	void setColorSprite(int r, int g, int b);
	void setPosition(const sf::Vector2f& pos);
	sf::Sprite getSprite();
};