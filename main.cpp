#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Player.h"
#include "Enemy.h"
#include "Config.h"
// Проверка GitHub
int main() {
	sf::RenderWindow window(sf::VideoMode(W, H), "Game");
	Player p("tank.png", "player", sf::Vector2f(500, 500), 3, 0.5f, 2, 5.f);
	Enemy p2("tank.png", "enemy", sf::Vector2f(900, 200), 3, 0.5f, 2, 5.f);

	int framerate = 100;
	float elapsedMillisecondsExpected = 1000.f / framerate;

	while (window.isOpen())
	{
		sf::Clock clock;
		int elapsedMilliseconds = clock.restart().asMicroseconds();

		p.control(window);
		p2.rotateTurret(p.getCoords());

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		float sleepMilliseconds = elapsedMillisecondsExpected - elapsedMilliseconds;
		int frames = int(elapsedMilliseconds / elapsedMillisecondsExpected) + 1;
		for (int i = 0; i < frames; ++i) {
			p.Update(elapsedMillisecondsExpected);
			p2.Update(elapsedMillisecondsExpected);
		}

		window.clear();
		p.draw(window);
		p2.draw(window);
		window.display();
	}
	return 0;
}
