#include "Entity.h"
#include "Config.h"
#include "World.h"

Entity::Entity(std::string f, std::string n, sf::Vector2f c, float w, float h, int s, float sR)
{
	// physics
	shape.SetAsBox(w / (SCALE * 2), h / (SCALE * 2));
	bdef.type = b2_dynamicBody;
	bdef.position.Set(c.x / SCALE, c.y / SCALE);
	body = World.CreateBody(&bdef);
	body->CreateFixture(&shape, 10);
	//
	m_coords = c;
	m_image.loadFromFile("images/" + f);
	m_texture.loadFromImage(m_image);
	m_sprite.setTexture(m_texture);
	m_spriteTurret.setTexture(m_texture);
	m_name = n;
	m_speed = s;
	m_speedRotate = sR;
	m_angle = 0;
	life = 100;
}
