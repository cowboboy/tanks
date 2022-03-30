#include "Enemy.h"
#include <iostream>
#include "Config.h"
#include "Bullet.h"

Enemy::Enemy(std::string f, std::string n, sf::Vector2f c, float w, float h, int s, float sR) :
	Entity(f, n, c, w, h, s, sR)
{
	//body->SetUserData("enemy");
	freezeTime = 0;
	m_sprite.setTextureRect(sf::IntRect(0, 0, w, h));
	m_sprite.setOrigin(w / 2, h / 2);
	m_sprite.setPosition(m_coords);
	
}

sf::Vector2f Enemy::getCoords()
{
	return m_coords;
}

void Enemy::shoot()
{
	if (bullets.size() == 0) {
		Bullet* B = new Bullet("", "bull", getCoords(), 100, m_angle);
		bullets.push_back(B);
	}
}

void Enemy::isPlayer(sf::Vector2f c)
{
	int targetAngle = atan((c.y - m_coords.y) / (c.x - m_coords.x)) * RADTODEG;
	if ((int)m_angle % 360 < targetAngle + 2 && (int)m_angle % 360 > targetAngle - 2) {
		shoot();
	}
}

void Enemy::Update(float time)
{
	body->SetAngularVelocity(time * m_speedRotate);

	for (auto& b : bullets) {
		b->Update(time);
		if (b->timer <= 0) { delete b; bullets.erase(bullets.begin()); }
	}
	b2Vec2 pos = body->GetPosition();
	float angle = body->GetAngle();
	m_sprite.setPosition(pos.x * SCALE, pos.y * SCALE);
	m_sprite.setRotation(angle * RADTODEG);
	//m_sprite.setRotation(m_angle);
	//m_sprite.setPosition(m_coords);
}

void Enemy::draw(sf::RenderWindow& w)
{
	w.draw(m_sprite);
	for (auto& b : bullets) {
		b->draw(w);
	}
}