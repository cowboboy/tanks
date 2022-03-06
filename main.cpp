#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Player.h"
#include "Config.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(W, H), "Game");
	Player p("tank.png", "player", 5.4, 3, 5, 0.1, 500, 500);

	int framerate = 100;
	float elapsedMillisecondsExpected = 1000.f / framerate;

	while (window.isOpen())
	{
		sf::Clock clock;
		float elapsedMilliseconds = clock.restart().asMicroseconds();

		p.control(window);
		p.rotateTurret();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		float sleepMilliseconds = elapsedMillisecondsExpected - elapsedMilliseconds;
		int frames = int(elapsedMilliseconds / elapsedMillisecondsExpected) + 1;
		for (int i = 0; i < frames; ++i) p.Update(elapsedMillisecondsExpected);

		std::cout << p.m_speedMovement << std::endl;

		window.clear();
		p.draw(window);
		window.display();
	}
	return 0;
}