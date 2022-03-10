#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity.h"

class Player : public Entity
{
public:
<<<<<<< HEAD
	Player(std::string f, std::string n, float speedRotate, float maxSpeedMovement, float speedRotateTurret, float acceleration, float x, float y);

=======
	Player(std::string f, std::string n, sf::Vector2f c, float maxSM, float a, float sR, float sRT);
>>>>>>> 32612ac126a4c8ad9c3432dd73d057c5921c3782
	void Update(float time);
	float getplayercoordinateX() {	//этим методом будем забирать координату Х	
		return x;
	}
	float getplayercoordinateY() {	//этим методом будем забирать координату Y 	
		return y;
	}
	void control(sf::RenderWindow& w);
	void draw(sf::RenderWindow& w);
	sf::Vector2f getCoords();
	float getSpeedMovement();
	void rotateTurret();
<<<<<<< HEAD
	bool m_moveForward, m_moveBack, m_rotateRight, m_rotateLeft;
	float m_speedMovement, w, h, dx, dy;
private:
	float m_speedRotate, m_speedRotateTurret, m_maxSpeedMovement, m_acceleration, m_anglePlayer, m_angleTargetTurret, m_angleTurret,x,y;
	sf::Vector2f m_coords, m_targetPos;
=======
private:
	bool m_moveForward, m_moveBack, m_rotateRight, m_rotateLeft;
	sf::Vector2f m_targetPos;
>>>>>>> 32612ac126a4c8ad9c3432dd73d057c5921c3782
};

