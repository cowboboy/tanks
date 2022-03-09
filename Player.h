#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity.h"

class Player : public Entity
{
public:
	Player(std::string f, std::string n, sf::Vector2f c, float maxSM, float a, float sR, float sRT);
	void Update(float time);
	void control(sf::RenderWindow& w);
	void draw(sf::RenderWindow& w);
	sf::Vector2f getCoords();
	float getSpeedMovement();
	void rotateTurret();
private:
	bool m_moveForward, m_moveBack, m_rotateRight, m_rotateLeft;
	sf::Vector2f m_targetPos;
};

