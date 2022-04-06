#include <iostream>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <cmath>
#include "Player.h"
#include "Config.h"
#include "Map.h"
#include "Interface.h"
#include "pWindow.h"
#include "World.h"
#include "Emitter.h"
#include <FPS.h>


int main() {
	sf::RenderWindow window(sf::VideoMode(W, H), "Game");

	sf::Image imageParticle;
	imageParticle.loadFromFile("images/particle.png");
	sf::Image imageBullet;
	imageBullet.loadFromFile("images/bullet.png");

	std::list<Player*> tanks;

	Interface i(W, H);
	Map m("images/particle.png", W, H);

	std::vector<pWindow*> pWindows;

	Player* p = new Player(sf::Vector2f(700, 300), "p1", 0);
	Player* p2 = new Player(sf::Vector2f(500, 500), "p2", 1);
	tanks.push_back(p);
	tanks.push_back(p2);

	Emitter* smoke = new Emitter(imageParticle, imageParticle);

	sf::Clock clock;
	window.setFramerateLimit(60);

	FPS fps;

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

		for (auto tank : tanks) {
			tank->Update(elapsedSeconds, tanks);
		}

		smoke->EngineSmoke(sf::Vector2f(500, 500));
		smoke->Update(elapsedSeconds * 1000);

		if (i.getTime() <= 0 && pWindows.size() == 0) {
			pWindows.push_back(new pWindow("a", W / 2, H / 2));
			//delete p;
			//p = nullptr;
		}

		m.Update(elapsedSeconds);
		i.Update(elapsedSeconds);
		m.draw(window);

		fps.Update(elapsedSeconds);
		std::cout << fps.getFPS() << std::endl;
		
		for (auto tank : tanks) {
			tank->Draw(window);
		}

		smoke->Draw(window);
		i.draw(window);
		for (auto& a : pWindows) {
			a->draw(window);
		}
		window.display();
	}
	return 0;
}