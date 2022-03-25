#include "Entity.h"

Entity::Entity(std::string f, std::string n, sf::Vector2f c, float w, float h, int s, float sR)
{
	m_coords = c;
	m_image.loadFromFile("images/" + f);
	m_texture.loadFromImage(m_image);
	m_sprite.setTexture(m_texture);
	m_spriteTurret.setTexture(m_texture);
	m_name = n;
	m_speed = s;
	m_speedRotate = sR;
	m_angle = 0;
}
