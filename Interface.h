#pragma once
#include <SFML\Graphics.hpp>
class Interface
{
	int W, H;
	float timer;
	sf::Font font;
	sf::Text timerText;
	std::string clock(int time);
public:
	Interface(int w, int h);
	void Update(float time);
	void draw(sf::RenderWindow& w);
	int getTime();
};

