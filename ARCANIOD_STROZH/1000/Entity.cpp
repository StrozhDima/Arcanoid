#include "Entity.h"

Entity::Entity (sf::String F, float X, float Y, float W, float H)
{
	file = F;
	w = W; h = H;

	if(!image.loadFromFile("images/" + file)) //��������� �����������
		return;

	texture.loadFromImage(image);//��������� ����������� � ��������
	texture.setSmooth(true);
	sprite.setTexture(texture);//�������� ������ ���������
	x = X; y = Y;//���������� ��������� �������
	sprite.setTextureRect(sf::IntRect(0.f, 0.f, w, h));//�������� ������ ��� ����
	sprite.setPosition(x,y); //��������� ��������� �� ����������� �,�
}

void Entity::setOrigInCentr() //��������� �������������� �������
{	
	sprite.setOrigin(w/2, h/2);
}

void Entity::setColorSprite(int r, int g, int b)
{
	sprite.setColor(sf::Color::Color(r, g, b));
}

void Entity::setPosition(const sf::Vector2f& pos) 
{ 
	sprite.setPosition(pos); 
}

sf::Sprite Entity::getSprite() 
{ 
	return sprite; 
}