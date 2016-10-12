#include "Rects.h"

Rects::Rects(void):rectNum(96), position(60, 60)
{
}

Rects::~Rects(void)
{
}

sf::Color Rects::randomColor()
{
	int r, g, b;
	r = rand() % 255 + 100;
	g = rand() % 255 + 150;
	b = rand() % 255 + 50;

	return sf::Color(r, g, b, 255);
}

void Rects::initialize()
{
	rects.resize(rectNum);

	position.x = 60;
	position.y = 60;

	for(auto i = 0; i < rects.size(); i++)
	{
		rects[i].setFillColor(randomColor());
		rects[i].setSize(sf::Vector2f(780/18, 580/45));
		rects[i].setOrigin(rects[i].getSize().x/2.f, rects[i].getSize().y/2.f);
		rects[i].setPosition(position.x, position.y);

		if (i == 15 || i == 31 || i == 47 || i == 63 || i == 79 || i == 95)
		{
			position.y += rects[i].getSize().y + 2;
			position.x = 60;
		}

		else position.x += rects[i].getSize().x + 2;
	}
}

void Rects::reset()
{
	initialize();
}

void Rects::draw(sf::RenderWindow &window)
{
	for (auto i = 0; i < rects.size(); ++i)
		window.draw(rects[i]);
}

