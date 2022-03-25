#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Config.h"
#include "Player.h"
Bullet::Bullet(std::string f, std::string n, sf::Vector2f c, int speed, float a) {
	m_coords = c;
	m_angle = a;
	timer = 30;
	bullet.setSize(sf::Vector2f(10, 5));
	bullet.setFillColor(sf::Color::Black);
	bullet.setRotation(m_angle);
	bullet.setPosition(c);
	
	m_speed = speed;
}

void Bullet::Update(float time)
{
	float lenght = sqrt(cos(m_angle * DEGTORAD) * cos(m_angle * DEGTORAD) + sin(m_angle * DEGTORAD) * sin(m_angle * DEGTORAD));
	m_coords += m_speed * time * sf::Vector2f(cos(m_angle * DEGTORAD) / lenght, sin(m_angle * DEGTORAD) / lenght);
	bullet.setPosition(m_coords);
	timer -= time;
}
void Bullet::draw(sf::RenderWindow& w) {
	w.draw(bullet);
}
