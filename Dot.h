#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "World.h"
#include "Config.h"
#include <BulletController.h>

class Dot
{
	sf::Image imageDot;
	sf::Texture textureDot;
	sf::Sprite spriteDot;

	sf::Vector2f position;
	float rotation;
	int speedRotate;

	int widthSprite, heightSprite;

	b2PolygonShape shape;
	b2BodyDef bdef;
	b2Body* body;

	BulletController bombing;
public:
	Dot(sf::Vector2f _position);
	void Update(float gameTime, std::list<Player*> tanks, std::list<Object*> objects);
	void draw(sf::RenderWindow& w);
};

