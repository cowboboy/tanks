#include "Entity.h"

Entity::Entity(std::string f, std::string n, sf::Vector2f c, float maxSM, float a, float sR, float sRT)
{
	m_coords = c;
	m_image.loadFromFile("images/" + f);
	m_texture.loadFromImage(m_image);
	m_sprite.setTexture(m_texture);
	m_spriteTurret.setTexture(m_texture);
	m_name = n;
	m_maxSpeedMovement = maxSM;
	m_acceleration = a;
	m_speedRotate = sR;
	m_speedRotateTurret = sRT;
	m_speedMovement = 0;
}
