#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
class Bullet {
public:
	float timer;
	int m_speed;
	float m_angle;
	Bullet(std::string f, std::string n, sf::Vector2f c, int speed, float angle);
	void Update(float time);
	void draw(sf::RenderWindow& w);
private:
	sf::Vector2f m_coords;
	sf::RectangleShape bullet;
};



