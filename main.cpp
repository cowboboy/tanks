#include <iostream>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <cmath>
#include "Player.h"
#include "Enemy.h"
#include "Config.h"
#include "Map.h"
#include "Interface.h"
#include "pWindow.h"
#include "World.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(W, H), "Game");

	Interface i(W, H);
	Map m("map.png", W, H);

	std::vector<pWindow*> pWindows;

	Player* p = new Player("tank1.png", "player", sf::Vector2f(500, 500), 64, 48, 50, 50, 1);
	Player* p2 = new Player("tank1.png", "player", sf::Vector2f(800, 500), 64, 48, 50, 50, 2);

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