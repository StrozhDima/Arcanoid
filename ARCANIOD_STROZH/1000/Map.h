#pragma once
#include "Entity.h"

class Map
{
public:
	Map();
	void draw(sf::RenderWindow &window);

private:
	Entity map;
};

