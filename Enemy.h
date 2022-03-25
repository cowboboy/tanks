#pragma once
#include "Entity.h"
class Enemy : public Entity
{
public:
	Enemy(std::string f, std::string n, sf::Vector2f c, float maxSM, float a, float sR, float sRT);
	void Update(float time);
	void draw(sf::RenderWindow& w);
	sf::Vector2f getCoords();
	float getSpeedMovement();
	void getDistance(sf::Vector2f c);
	void rotateTurret(sf::Vector2f c);
private:
	sf::Vector2f m_targetPos;
	float m_distance;
};

