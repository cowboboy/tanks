#pragma once
#include <SFML/Graphics.hpp>
#include <Button.h>
#include "Config.h"

class Menu
{
	sf::RectangleShape darkScreen;
	Button buttonStart2;
	Button buttonStart3;
	Button buttonStart4;
	sf::Image imageButtonStart2;
	sf::Image imageButtonStart3;
	sf::Image imageButtonStart4;
public:
	Menu();
	void Update(float gameTime, sf::RenderWindow& w);
	void Draw(sf::RenderWindow& w);
	int isGame();
};

