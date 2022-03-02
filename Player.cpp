#include "Player.h"
#include <iostream>

float DEGTORAD = 0.017453f;

Player::Player(std::string f, float speedRotate, float speedMovement, float speedRotateTurret, float x, float y) : 
	m_speedRotate(speedRotate), m_speedMovement(speedMovement), m_coords(x, y), m_speedRotateTurret(speedRotateTurret),
	m_anglePlayer(0)
{
	m_imagePlayer.loadFromFile("images/" + f);
	m_imagePlayer.createMaskFromColor(sf::Color(255, 255, 255));
	m_texturePlayer.loadFromImage(m_imagePlayer);
	m_spritePlayer.setTexture(m_texturePlayer);
	m_spritePlayer.setTextureRect(sf::IntRect(0, 1, 300, 123));
	m_spritePlayer.setPosition(m_coords);
	m_spritePlayer.setOrigin(150, 123 / 2);
	m_spriteTurret.setTexture(m_texturePlayer);
	m_spriteTurret.setTextureRect(sf::IntRect(352, 1, 255, 123));
	m_spriteTurret.setOrigin(88, 123 / 2);
	m_move = false;
}

sf::Vector2f Player::getCoords()
{
	return m_coords;
}

void Player::setAngle(float angle)
{
	m_anglePlayer += angle;
}

sf::Sprite Player::getSprite()
{
	return m_spritePlayer;
}

sf::Sprite Player::getSpriteTurret()
{
	return m_spriteTurret;
}


void Player::Update(float time)
{
	float lenght = sqrt(cos(m_anglePlayer * DEGTORAD) * cos(m_anglePlayer * DEGTORAD) + sin(m_anglePlayer * DEGTORAD) * sin(m_anglePlayer * DEGTORAD));
	if (m_move)
		m_coords += m_speedRotate * time * sf::Vector2f(cos(m_anglePlayer * DEGTORAD) / lenght, sin(m_anglePlayer * DEGTORAD) / lenght) * 0.01f;
	m_spritePlayer.setRotation(m_anglePlayer);
	m_spritePlayer.setPosition(m_coords);
	m_spriteTurret.setPosition(m_coords);
	m_move = false;
}

void Player::Control()
{
}
