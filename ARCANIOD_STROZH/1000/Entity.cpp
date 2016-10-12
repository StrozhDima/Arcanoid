#include "Entity.h"

Entity::Entity (sf::String F, float X, float Y, float W, float H)
{
	file = F;
	w = W; h = H;

	if(!image.loadFromFile("images/" + file)) //открываем изображение
		return;

	texture.loadFromImage(image);//загружаем изображение в текстуру
	texture.setSmooth(true);
	sprite.setTexture(texture);//заливаем спрайт текстурой
	x = X; y = Y;//координата появления спрайта
	sprite.setTextureRect(sf::IntRect(0.f, 0.f, w, h));//обрезаем спрайт как надо
	sprite.setPosition(x,y); //установка положения по координатам х,у
}

void Entity::setOrigInCentr() //получение прямоугольника спрайта
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