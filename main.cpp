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
#include "Scene.h"
#include "Emitter.h"


int main() {
	sf::RenderWindow window(sf::VideoMode(W, H), "Game");

	sf::Image imageParticle;
	imageParticle.loadFromFile("images/particle.png");
	sf::Image imageBullet;
	imageBullet.loadFromFile("images/bullet.png");

	
	


	Interface i(W, H);
	Map m("images/particle.png", W, H);

	std::vector<pWindow*> pWindows;
	Scene* lvl = new Scene();

	Player* p = new Player("tank1.png", "player1", sf::Vector2f(500, 500), lvl, 64, 48, 10, 20, 1, imageBullet);
	lvl->players.push_back(p);
	Player* p2 = new Player("tank1.png", "player2", sf::Vector2f(800, 500), lvl, 64, 48, 10, 20, 2, imageBullet);
	lvl->players.push_back(p2);

	Emitter* smoke = new Emitter(imageParticle, imageParticle);;

	int framerate = 100;
	float elapsedMillisecondsExpected = 1.f / framerate;
	sf::Clock clock;

	while (window.isOpen())
	{
		float elapsedMilliseconds = clock.restart().asSeconds();
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		World.Step(1 / 60.f, 8, 3);

		float sleepMilliseconds = elapsedMillisecondsExpected - elapsedMilliseconds;
		
		int frames = int(elapsedMilliseconds / elapsedMillisecondsExpected) + 1;
		if (p) {
			for (int i = 0; i < frames; ++i) {
				p->Update(elapsedMillisecondsExpected);
				p2->Update(elapsedMillisecondsExpected);
			}
		}

		smoke->EngineSmoke(sf::Vector2f(500, 500));
		smoke->Update(elapsedMilliseconds * 1000);

		for (auto p : lvl->players) {
			if (p->m_life <= 0) {
				smoke->EngineSmoke(p->m_coords);
			}
		}

		if (i.getTime() <= 0 && pWindows.size() == 0) {
			pWindows.push_back(new pWindow("a", W / 2, H / 2));
			delete p;
			p = nullptr;
		}

		m.Update(elapsedMilliseconds);
		i.Update(elapsedMilliseconds);
		m.draw(window);
		
		if (p) {
			p->draw(window);
		}
		if (p2) {
			p2->draw(window);
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