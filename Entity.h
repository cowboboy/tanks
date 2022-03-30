#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
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
	int life;
	Entity(std::string f, std::string n, sf::Vector2f c, float w, float h, int s, float sR);
	sf::Vector2f virtual getCoords() = 0;
protected:
	b2PolygonShape shape;
	b2BodyDef bdef;
	b2Body* body;
};

