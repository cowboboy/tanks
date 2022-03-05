#include "Player.h"
#include <iostream>
#include "Config.h"

Player::Player(std::string f, float speedRotate, float speedMovement, float speedRotateTurret, float x, float y) : 
	m_speedRotate(speedRotate), m_speedMovement(speedMovement), m_coords(x, y), m_speedRotateTurret(speedRotateTurret),
	m_anglePlayer(0), m_angleTurret(0), m_angleTargetTurret(0)
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
	m_moveForward = m_moveBack = false;
}

sf::Vector2f Player::getCoords()
{
	return m_coords;
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
	if (m_moveForward)
		m_coords += m_speedMovement * time * sf::Vector2f(cos(m_anglePlayer * DEGTORAD) / lenght, sin(m_anglePlayer * DEGTORAD) / lenght) * 0.01f;
	if (m_moveBack)
		m_coords += m_speedMovement * time * sf::Vector2f(-cos(m_anglePlayer * DEGTORAD) / lenght, -sin(m_anglePlayer * DEGTORAD) / lenght) * 0.01f;
	if (m_rotateLeft) {
		m_anglePlayer += -0.001f * time * m_speedRotate;
	}
	if (m_rotateRight) {
		m_anglePlayer += 0.001f * time * m_speedRotate;
	}
	
	if (m_angleTurret < m_angleTargetTurret) { // positive direction
		m_angleTurret += 0.001f * time * m_speedRotate * 0.01;
		m_spriteTurret.setRotation(m_angleTurret * RADTODEG);
	}
	if (m_angleTurret > m_angleTargetTurret) { // negative direction
		m_angleTurret += -0.001f * time * m_speedRotate * 0.01;
		m_spriteTurret.setRotation(m_angleTurret * RADTODEG);
	}

	m_spritePlayer.setRotation(m_anglePlayer);
	m_spritePlayer.setPosition(m_coords);
	m_spriteTurret.setPosition(m_coords);
	m_moveForward = m_moveBack = m_rotateLeft = m_rotateRight = false;
}

void Player::rotateTurret()
{
	float dX = m_targetPos.x - m_coords.x;
	float dY = m_targetPos.y - m_coords.y;
	m_angleTargetTurret = atan2(dY, dX);
}

void Player::Control(sf::RenderWindow& w)
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(w);
	m_targetPos = w.mapPixelToCoords(pixelPos);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_rotateLeft = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_rotateRight = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		m_moveForward = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		m_moveBack = true;
	}
}
