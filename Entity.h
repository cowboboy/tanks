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
	Entity(std::string f, std::string n);
};

