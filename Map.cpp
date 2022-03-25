#include "Map.h"
#include <iostream>

Map::Map(std::string f, int w, int h) : W(w), H(h)
{
	map_image.loadFromFile("images/" + f);
	map.loadFromImage(map_image);
	s_map.setTexture(map);
}

void Map::Update(float time)
{
}

void Map::draw(sf::RenderWindow& w)
{
	w.clear(sf::Color(128, 128, 128));
}
