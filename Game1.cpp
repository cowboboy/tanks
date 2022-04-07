#include "Game1.h"

void Game1::Update(float gameTime)
{
	int k = 0;
	for (auto tank = tanks.begin(); tank != tanks.end();++tank)
	{
		if (aliveTanks == 1) {
			(*tank)->restart();
		}
		else if ((*tank)->getHitPoints() >= 0){
			++k;
		}
		(*tank)->Update(gameTime, tanks);
	}
	aliveTanks = k;
	fps.Update(gameTime);
}

void Game1::Draw()
{
	window.clear(sf::Color(128, 128, 128));
	for (auto tank : tanks) {
		tank->Draw(window);
	}
	fps.Draw(window);
	window.display();
}

Game1::Game1() : window(sf::VideoMode(W, H), "Game")
{
	window.setFramerateLimit(60);
	elapsedSeconds = 0;
	tanks.push_back(new Player(sf::Vector2f(200, 100), "p1", 0));
	tanks.push_back(new Player(sf::Vector2f(1000, 100), "p2", 1));
	tanks.push_back(new Player(sf::Vector2f(200, 700), "p3", 2));
	tanks.push_back(new Player(sf::Vector2f(1000, 700), "p4", 3));
	aliveTanks = tanks.size();
}

void Game1::Run()
{
	while (window.isOpen())
	{
		float elapsedSeconds = clock.restart().asSeconds();
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		World.Step(1 / 60.f, 8, 3);

		Update(elapsedSeconds);

		Draw();
	}
}
