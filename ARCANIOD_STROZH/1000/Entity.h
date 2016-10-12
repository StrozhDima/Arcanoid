#pragma once
#include <SFML/Graphics.hpp>

class Entity
{

private:
	float x, y, w, h; //координаты х и у, высота, ширина, ускорение (по х и по у)
	sf::String file; //файл с расширением
	sf::Image image;//сфмл изображение
	sf::Texture texture;//сфмл текстура
	sf::Sprite sprite;//сфмл спрайт

public:
	Entity (sf::String F, float X, float Y, float W, float H);
	void setOrigInCentr();
	void setColorSprite(int r, int g, int b);
	void setPosition(const sf::Vector2f& pos);
	sf::Sprite getSprite();
};