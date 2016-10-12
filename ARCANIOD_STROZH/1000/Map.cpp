#include "Map.h"

Map::Map():map("map.png", 0, 0, 800, 600)
{
}

void Map::draw(sf::RenderWindow &window)
{
	window.draw(map.getSprite());
}