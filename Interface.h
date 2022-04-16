#pragma once
#include <SFML\Graphics.hpp>
#include "Config.h"

class Interface
{
	float timer;
	sf::Font font;
	sf::Text timerText;
	std::string clock(int time);
public:
	Interface();
	void Update(float time);
	void draw(sf::RenderWindow& w);
	int getTime();
};

