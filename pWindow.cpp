#include "pWindow.h"

pWindow::pWindow(std::string text, int x, int y, int w, int h) : X(x), Y(y), W(w), H(h)
{
	rec.setSize(sf::Vector2f(w, h));
	rec.setOrigin(W / 2, H / 2);
	rec.setPosition(x, y);
	rec.setFillColor(sf::Color(0, 0, 255));
	font.loadFromFile("fonts/Samson.ttf");
	InfoText.setString("You lose!");
	InfoText.setFillColor(sf::Color(0, 0, 0));
	InfoText.setFont(font);
	InfoText.setCharacterSize(100);
	sf::FloatRect textRect = InfoText.getLocalBounds();
	InfoText.setOrigin(textRect.width / 2, textRect.height / 2);
	InfoText.setPosition(x, y);
}

void pWindow::draw(sf::RenderWindow& w)
{
	w.draw(rec);
	w.draw(InfoText);
}
