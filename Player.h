#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Player : public Entity
{
public:
	Player(std::string f, std::string n, float speedRotate, float maxSpeedMovement, float speedRotateTurret, float acceleration, float x, float y);
	void Update(float time);
	void control(sf::RenderWindow& w);
	void draw(sf::RenderWindow& w);
	sf::Vector2f getCoords();
	void rotateTurret();
	bool m_moveForward, m_moveBack, m_rotateRight, m_rotateLeft;
	float m_speedMovement;
private:
	float m_speedRotate, m_speedRotateTurret, m_maxSpeedMovement, m_acceleration, m_anglePlayer, m_angleTargetTurret, m_angleTurret;
	sf::Vector2f m_coords, m_targetPos;
};

