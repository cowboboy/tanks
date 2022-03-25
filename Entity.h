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
	float m_speed, m_speedRotate, m_angle;
	Entity(std::string f, std::string n, sf::Vector2f c, float w, float h, int s, float sR);
};

