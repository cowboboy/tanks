#include "Player.h"
#include <iostream>
#include "Config.h"
#include "Bullet.h"

Player::Player(std::string f, std::string n, sf::Vector2f c, float w, float h, int s, float sR) :
	Entity(f, n, c, w, h, s, sR)
{
	m_sprite.setTextureRect(sf::IntRect(0, 0, w, h));
	m_sprite.setOrigin(w / 2, h / 2);
	m_sprite.setPosition(m_coords);
	m_move = false;
	m_dir = true;
	m_changeDir = 1;
}

sf::Vector2f Player::getCoords()
{
	return m_coords;
}

void Player::shoot()
{
	Bullet* B = new Bullet("", "bull", getCoords(), 100, m_angle);
	bullets.push_back(B);
}

void Player::Update(float time)
{
	control();
	float lenght = sqrt(cos(m_angle * DEGTORAD) * cos(m_angle * DEGTORAD) + sin(m_angle * DEGTORAD) * sin(m_angle * DEGTORAD));
	if (m_move) {
		m_coords += m_speed * time * sf::Vector2f(cos(m_angle * DEGTORAD) / lenght, sin(m_angle * DEGTORAD) / lenght);
	}

	if (m_dir && !m_move) {
		m_angle += time * m_speedRotate;
	}
	if (!m_dir && !m_move) {
		m_angle += -time * m_speedRotate;
	}
	for (auto& b : bullets) {
		b->Update(time);
		if (b->timer <= 0) { delete b;  bullets.erase(bullets.begin()); }
	}


	m_sprite.setRotation(m_angle);
	m_sprite.setPosition(m_coords);
	m_move = false;
}

void Player::control()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		m_move = true;
		if (m_changeDir == 1) {
			m_dir = !m_dir;
			m_changeDir = 0;
			shoot();
		}
	}
	else {
		m_changeDir = 1;
	}
}

void Player::draw(sf::RenderWindow& w)
{
	w.draw(m_sprite);
	for (auto& b : bullets) {
		b->draw(w);
	}
}
