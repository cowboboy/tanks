#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

const int W = 1200;
const int H = 800;

int main() {
	sf::RenderWindow window(sf::VideoMode(W, H), "Game");
	Player p("tank.png", 12.4, 10.5, 10, 500, 500);
	//p.getTurret().settings("tank.png", 10.0f);

	int framerate = 100;
	float elapsedMillisecondsExpected = 1000.f / framerate;

	while (window.isOpen())
	{
		sf::Clock clock;
		float elapsedMilliseconds = clock.restart().asMicroseconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			p.setAngle(-0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			p.setAngle(0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			p.m_move = true;
		}

		float sleepMilliseconds = elapsedMillisecondsExpected - elapsedMilliseconds;
		int frames = int(elapsedMilliseconds / elapsedMillisecondsExpected) + 1;
		for (int i = 0; i < frames; ++i) p.Update(elapsedMillisecondsExpected);

		std::cout << p.getCoords().x << " " << p.getCoords().y << std::endl;

		window.clear();
		window.draw(p.getSprite());
		window.draw(p.getSpriteTurret());
		window.display();
	}
	return 0;
}