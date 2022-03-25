#pragma once
#include <SFML/Graphics.hpp>
class pWindow // pop-up window
{
	int W, H, X, Y;
	sf::RectangleShape rec;
	sf::Font font;
	sf::Text InfoText;
public:
	pWindow(std::string text, int x, int y, int w = 800, int h = 400);
	void draw(sf::RenderWindow& w);
};

