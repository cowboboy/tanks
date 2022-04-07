#pragma once
#include <SFML/Graphics.hpp>
#include <FPS.h>
#include <list>
#include "Player.h"
#include "World.h"
#include "Config.h"
#include <iostream>

class Game1
{
	sf::RenderWindow window;
	sf::Clock clock;
	FPS fps;

	float elapsedSeconds;

	std::list<Player*> tanks;

	int aliveTanks;
protected:
	void Update(float gameTime);
	void Draw();
public:
	Game1();
	void Run();
};

