#include "Entity.h"

Entity::Entity(std::string f, std::string n) : m_name(n)
{
	m_image.loadFromFile("images/" + f);
	m_texture.loadFromImage(m_image);
	m_sprite.setTexture(m_texture);
	m_spriteTurret.setTexture(m_texture);
}
