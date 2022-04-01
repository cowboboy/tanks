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
#include <Scene.h>

int main() {
	sf::RenderWindow window(sf::VideoMode(W, H), "Game");

	Interface i(W, H);
	Map m("map.png", W, H);

	std::vector<pWindow*> pWindows;
	Scene* lvl = new Scene();

	Player* p = new Player("tank1.png", "player1", sf::Vector2f(500, 500), lvl, 64, 48, 50, 20, 1);
	Player* p2 = new Player("tank1.png", "player2", sf::Vector2f(800, 500), lvl, 64, 48, 50, 20, 2);

	lvl->players.push_back(p);
	lvl->players.push_back(p2);

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
		i.draw(window);
		for (auto& a : pWindows) {
			a->draw(window);
		}
		window.display();
	}
	return 0;
}