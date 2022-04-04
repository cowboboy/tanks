#include "Player.h"
#include <iostream>
#include "Config.h"
#include "Bullet.h"
#include <Box2D/Box2D.h>
#include "World.h"

Player::Player(std::string f, std::string n, sf::Vector2f c, Scene* lvl, float w, float h, int s, float sR, int b, sf::Image& _imageBullet) :
	Entity(f, n, c, w, h, s, sR), bullet()
{
	m_sprite.setTextureRect(sf::IntRect(0, 0, w, h));
	m_sprite.setOrigin(w / 2, h / 2);
	m_sprite.setPosition(m_coords);
	m_move = false;
	m_dir = true;
	m_changeDir = 1;
	button = b;
	m_lvl = lvl;
	m_name = n;
	m_life = 100;

	m_shoot = false;
}

sf::Vector2f Player::getCoords()
{
	return m_coords;
}
/*
void Player::shoot()
{
	Bullet* B = new Bullet("", m_name, getCoords(), m_lvl, 100, m_angle);
	bullets.push_back(B);
}*/

void Player::Update(float time)
{
	control();
	float lenght = sqrt(cos(m_angle * DEGTORAD) * cos(m_angle * DEGTORAD) + sin(m_angle * DEGTORAD) * sin(m_angle * DEGTORAD));

	if (m_life && m_dir && !m_move) {
		body->SetAngularVelocity(time * m_speedRotate);
	}
	else if (m_life &&  !m_dir && !m_move) {
		body->SetAngularVelocity(-time * m_speedRotate);
	}
	else {
		body->SetAngularDamping(time * m_speedRotate);
	}
	if (!m_life) {
		m_sprite.setTextureRect(sf::IntRect(64, 0, 64, 48));
	}

	b2Vec2 pos = body->GetPosition();
    float angle = body->GetAngle();
	m_coords.x = pos.x * SCALE;
	m_coords.y = pos.y * SCALE;
	m_angle = angle * RADTODEG;

	if (m_life && m_move) {
		body->SetAngularVelocity(0);
		body->SetLinearVelocity(b2Vec2(m_speed * 0.1 * cos(angle) / lenght, m_speed * 0.1 * sin(angle) / lenght));
	}
	else {
		body->SetLinearDamping(m_speed);
	}

	m_sprite.setPosition(pos.x * SCALE, pos.y * SCALE);
	m_sprite.setRotation(angle * RADTODEG);
	m_move = false;

	bullet.Update(time, m_coords, m_angle, m_shoot);
	m_shoot = false;
}

void Player::control()
{
	switch (button) {
	case 1:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			m_move = true;
			if (m_life && m_changeDir == 1) {
				m_dir = !m_dir;
				m_changeDir = 0;
				m_shoot = !m_shoot;
				//shoot();
			}
		}
		else {
			m_changeDir = 1;
		}
		break;
	case 2:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			m_move = true;
			if (m_life && m_changeDir == 1) {
				m_dir = !m_dir;
				m_changeDir = 0;
				m_shoot = !m_shoot;
				//shoot();
			}
		}
		else {
			m_changeDir = 1;
		}
		break;
	}
}

bool Player::collisionBorder(sf::Vector2f c)
{
	if (c.x > 0 && c.x < W && c.y > 0 && c.y < H) return true;
	return false;
}

void Player::draw(sf::RenderWindow& w)
{
	w.draw(m_sprite);
	bullet.Draw(w);
	
}
