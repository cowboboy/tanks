#pragma once
#include <SFML/Graphics.hpp>

class FPS
{
	int fps, frames;
	float timer;
	sf::Clock clock;
public:
	FPS();
	void Update(float gameTime);
	int getFPS();
};

