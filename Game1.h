#pragma once
#include <SFML/Graphics.hpp>
#include <FPS.h>
#include <list>
#include "Player.h"
#include "World.h"
#include "Config.h"
#include <iostream>
#include "ToxicSmoke.h"
#include <Menu.h>
#include <map.h>
#include "BulletController.h"

class Game1
{
	sf::Image imageTank1;
	sf::Image imageTank2;
	sf::Image imageTank3;
	sf::Image imageTank4;

	sf::RenderWindow window;
	sf::Clock clock;
	FPS fps;

	sf::Image imageMap;
	sf::Texture textureMap;
	sf::Sprite spriteMap;

	Map map;

	Menu* menu;

	bool game, isGame;

	float elapsedSeconds;

	std::list<Player*> tanks;

	int aliveTanks;
protected:
	void startGame(int players);
	void endGame();
	void Update(float gameTime);
	void Draw();
public:
	Game1();
	void Run();
};

