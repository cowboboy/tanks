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
	m_angle = m_angleTurret = 0;
}

sf::Vector2f Enemy::getCoords()
{
	return m_coords;
}

float Enemy::getSpeedMovement()
{
	return m_speedMovement;
}

void Enemy::Update(float time)
{
	if (m_angleTurret < m_angleTargetTurret) { // positive direction
		m_angleTurret += 0.001f * time * m_speedRotateTurret * 0.01;
		m_spriteTurret.setRotation(m_angleTurret * RADTODEG);
	}
	if (m_angleTurret > m_angleTargetTurret) { // negative direction
		m_angleTurret += -0.001f * time * m_speedRotateTurret * 0.01;
		m_spriteTurret.setRotation(m_angleTurret * RADTODEG);
	} 

	m_sprite.setRotation(m_angle);
	m_sprite.setPosition(m_coords);
	m_spriteTurret.setPosition(m_coords);
}

void Enemy::rotateTurret(sf::Vector2f c)
{
	float dX = c.x - m_coords.x;
	float dY = c.y - m_coords.y;
	m_angleTargetTurret = atan2(dY, dX);
} 

void Enemy::draw(sf::RenderWindow& w)
{
	w.draw(m_sprite);
	w.draw(m_spriteTurret);
}