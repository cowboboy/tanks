#include "Player.h"
#include <iostream>
#include "Config.h"

Player::Player(std::string f, std::string n, sf::Vector2f c, float maxSM, float a, float sR, float sRT) :
	Entity(f, n, c, maxSM, a, sR, sRT)
{
	m_sprite.setTextureRect(sf::IntRect(0, 1, 300, 123));
	m_sprite.setPosition(m_coords);
	m_sprite.setOrigin(150, 123 / 2);
	m_spriteTurret.setTexture(m_texture);
	m_spriteTurret.setTextureRect(sf::IntRect(352, 1, 255, 123));
	m_spriteTurret.setOrigin(88, 123 / 2);
	m_moveForward = m_moveBack = m_rotateLeft = m_rotateRight = false;
	m_angle = m_angleTurret = 0;
}

sf::Vector2f Player::getCoords()
{
	return m_coords;
}

float Player::getSpeedMovement()
{
	return m_speedMovement;
}

void Player::Update(float time)
{
	float lenght = sqrt(cos(m_angle * DEGTORAD) * cos(m_angle * DEGTORAD) + sin(m_angle * DEGTORAD) * sin(m_angle * DEGTORAD));
	if (m_moveForward) {
		if (m_speedMovement < m_maxSpeedMovement) m_speedMovement += m_acceleration * time * 0.005;
	}
	if (m_moveBack) {
<<<<<<< HEAD
		if (m_speedMovement < m_maxSpeedMovement) m_speedMovement -= m_acceleration * time * 0.005;
=======
		if (abs(m_speedMovement) < m_maxSpeedMovement) m_speedMovement -= m_acceleration * time * 0.001;
>>>>>>> 32612ac126a4c8ad9c3432dd73d057c5921c3782
	}
	if (!m_moveForward && !m_moveBack || m_moveForward && m_moveBack)
		if (m_speedMovement - m_acceleration > 0) m_speedMovement -= m_acceleration * time * 0.005;
		else if (m_speedMovement + m_acceleration < 0) m_speedMovement += m_acceleration * time * 0.005;
		else m_speedMovement = 0;

<<<<<<< HEAD
	m_coords += m_speedMovement * time * sf::Vector2f(cos(m_anglePlayer * DEGTORAD) / lenght, sin(m_anglePlayer * DEGTORAD) / lenght) * 0.1f;

	if (m_rotateLeft) {
		m_anglePlayer += -0.005f * time * m_speedRotate;
	}
	if (m_rotateRight) {
		m_anglePlayer += 0.005f * time * m_speedRotate;
=======
	m_coords += m_speedMovement * time * sf::Vector2f(cos(m_angle * DEGTORAD) / lenght, sin(m_angle * DEGTORAD) / lenght) * 0.01f;

	if (m_rotateLeft) {
		m_angle += -0.001f * time * m_speedRotate;
	}
	if (m_rotateRight) {
		m_angle += 0.001f * time * m_speedRotate;
>>>>>>> 32612ac126a4c8ad9c3432dd73d057c5921c3782
	}

	rotateTurret();
	if (m_angleTurret < m_angleTargetTurret) { // positive direction
<<<<<<< HEAD
		m_angleTurret += 0.001f * time * m_speedRotate * 0.2;
		m_spriteTurret.setRotation(m_angleTurret * RADTODEG);
	}
	if (m_angleTurret > m_angleTargetTurret) { // negative direction
		m_angleTurret += -0.001f * time * m_speedRotate * 0.2;
=======
		m_angleTurret += 0.001f * time * m_speedRotateTurret * 0.01;
		m_spriteTurret.setRotation(m_angleTurret * RADTODEG);
	}
	if (m_angleTurret > m_angleTargetTurret) { // negative direction
		m_angleTurret += -0.001f * time * m_speedRotateTurret * 0.01;
>>>>>>> 32612ac126a4c8ad9c3432dd73d057c5921c3782
		m_spriteTurret.setRotation(m_angleTurret * RADTODEG);
	}

	m_sprite.setRotation(m_angle);
	m_sprite.setPosition(m_coords);
	m_spriteTurret.setPosition(m_coords);
	m_moveBack = m_moveForward = m_rotateLeft = m_rotateRight = false;
}

void Player::rotateTurret()
{
	float dX = m_targetPos.x - m_coords.x;
	float dY = m_targetPos.y - m_coords.y;
	m_angleTargetTurret = atan2(dY, dX);
}

void Player::control(sf::RenderWindow& w)
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

void Player::draw(sf::RenderWindow& w)
{
	w.draw(m_sprite);
	w.draw(m_spriteTurret);
}
