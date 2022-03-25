#include "Enemy.h"
#include <iostream>
#include "Config.h"

Enemy::Enemy(std::string f, std::string n, sf::Vector2f c, float maxSM, float a, float sR, float sRT) :
	Entity(f, n, c, maxSM, a, sR, sRT)
{
	m_sprite.setTextureRect(sf::IntRect(0, 1, 300, 123));
	m_image.createMaskFromColor(sf::Color(41, 33, 59));
	m_sprite.setPosition(m_coords);
	m_sprite.setOrigin(150, 123 / 2);
	m_spriteTurret.setTexture(m_texture);
	m_spriteTurret.setTextureRect(sf::IntRect(352, 1, 255, 123));
	m_spriteTurret.setOrigin(88, 123 / 2);
	m_angle = 0;
}

sf::Vector2f Enemy::getCoords()
{
	return m_coords;
}

float Enemy::getSpeedMovement()
{
	return m_speed;
}

void Enemy::getDistance(sf::Vector2f c)
{
	m_distance = sqrt((c.x - getCoords().x) * (c.x - getCoords().x) + (c.y - getCoords().y) * (c.y - getCoords().y));
}

void Enemy::Update(float time)
{
	
}

void Enemy::rotateTurret(sf::Vector2f c)
{
	
} 

void Enemy::draw(sf::RenderWindow& w)
{
	w.draw(m_sprite);
	w.draw(m_spriteTurret);
}