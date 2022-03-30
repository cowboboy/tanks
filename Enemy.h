#pragma once
#include "Entity.h"
#include "Bullet.h"
class Enemy : public Entity
{
public:
	float freezeTime;
	Enemy(std::string f, std::string n, sf::Vector2f c, float w, float h, int s, float sR);
	void Update(float time);
	void draw(sf::RenderWindow& w);
	std::vector<Bullet*> bullets;
	void shoot();
	sf::Vector2f getCoords();
	void isPlayer(sf::Vector2f c);
};

