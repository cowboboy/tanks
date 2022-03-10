#pragma once
#include <SFML/Graphics.hpp>
class Entity
{
public:
	std::string m_name;
	sf::Image m_image;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Sprite m_spriteTurret;
	sf::Vector2f m_coords;
	float m_speedMovement, m_speedRotate, m_speedRotateTurret, m_maxSpeedMovement, m_acceleration, m_angle, m_angleTurret, m_angleTargetTurret;
	Entity(std::string f, std::string n, sf::Vector2f c, float maxSM, float a, float sR, float sRT);
};

